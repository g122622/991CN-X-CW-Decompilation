#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""直接读取 Ghidra 汇编文本的“原始指令 + 标签”视图（不经过 parse.parse_asm）。

parse.parse_asm 只收 `rom:rom:` 行；Ghidra 在以下几种情况会写别的行：
- 标签与代码同行：`PTR_FUN_rom_022b82_rom_00d860:;XREF[...]  rom:rom:00d860  ...`
- 共享指令后缀：`rom:rom:00d84c  011a02  addr  LAB_rom_021a00+1`（实际是 ADD/BC 的中间字节）
- 未定义字节：`rom:rom:0093ec  0f  ??  0Fh`（仍属于指令流）
本模块把这些行还原成 (地址, 字节串, 助记符, 操作数)，覆盖整段 0x0000..0x3FFFF。
"""
import re, os

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
RAW_ASM = os.path.join(ROOT, '原始反编译结果', '991CN X.汇编.txt')

LINE_RX = re.compile(r'(?:^|\s)rom:rom:([0-9a-f]{6})\s+([0-9a-f]+)\s+(\S+)\s*(.*)$')
REF = os.path.abspath(os.path.join(ROOT, '..', '参考-casio-main',
                                   '_disas_commented.txt'))
REF_RX = re.compile(r'^([0-9A-Fa-f]{6})   ([0-9A-Fa-f]{2}(?: [0-9A-Fa-f]{2})*)(\s.*)?$')

# 参考反汇编里被当成“数据行”的前缀；其余带助记符的行都视为指令
DATA_PRE = {'SECTION', 'ascii:', 'STR:', 'addr', 'byte', 'word', 'dword', 'ptr'}


def ref_lines(path=REF):
    """参考反汇编 -> {地址: (字节串, 助记符, 操作数)}，只收指令/数据行（标签注释不收）。"""
    if not os.path.exists(path):
        return {}
    out = {}
    for ln in open(path, 'rb').read().decode('utf-8', 'replace').split('\n'):
        m = REF_RX.match(ln)
        if not m:
            continue
        a = int(m.group(1), 16)
        b = ''.join(m.group(2).split())
        rest = (m.group(3) or '').split('//')[0].strip()
        if not rest:
            continue
        toks = rest.split()
        out[a] = (b, toks[0], ' '.join(toks[1:]))
    return out


def asm_lines(path=RAW_ASM):
    """-> [(addr, bytes_hex, mnemonic, operands, line_no)]；同地址的标签行取第一条。"""
    out = []
    seen = set()
    for k, lb in enumerate(open(path, 'rb')):
        ln = lb.decode('latin-1').rstrip('\r\n')
        m = LINE_RX.search(ln)
        if not m:
            continue
        a = int(m.group(1), 16)
        if a in seen:
            continue
        seen.add(a)
        out.append((a, m.group(2).lower(), m.group(3), m.group(4).rstrip(), k + 1))
    return out


def _is_junk(bs, mnem):
    """Ghidra 的“未解码字节 + 地址栏”行：单位数 `??`，或 `addr` 伪指令。"""
    return mnem in ('??', 'addr', 'undefined', 'undefined1', 'undefined2',
                    'undefined4')


def asm_view(path=RAW_ASM, ref=None):
    """合并后的指令视图：[{addr, bytes, mnemonic, ops, line}]（按地址排序、无重叠）。

    以 Ghidra 文本的逐行读数为底，用参考反汇编补齐写窄/写残的指令；
    参考缺失（未复制到参考-casio-main）时退化为原始读数。
    """
    ref = ref if ref is not None else ref_lines()
    rows, _n = fix_width(asm_lines(path), ref)
    return [dict(addr=a, bytes=b, mnemonic=mn, ops=op, line=ln)
            for a, b, mn, op, ln in rows]


def _extend_overlap(rows, ref):
    """用参考补齐 Ghidra 写窄/写残的指令，分三种：

    1. Ghidra 只写低 2 字节（`00 08` 而不是 `00 08 E3 50`），高字节另起一行
       `?? 08h` —— 加宽当前指令并丢弃被覆盖的残行；
    2. 单字节 `??`（如 0xD85E 的 `01`）—— 加宽为完整 4 字节；
    3. `addr` 行（`cef8  addr LAB_...`）—— Ghidra 把指令与其后紧邻的标签并成一行，
       以参考的编码/助记符为准。
    """
    drop = set()
    out = list(rows)
    for k, (a, bs, mn, op, ln) in enumerate(rows):
        r = ref.get(a)
        if not r or len(r[0]) <= len(bs):
            continue
        if mn != 'addr' and bs.lower() != r[0][:len(bs)].lower():
            continue
        if r[1] in DATA_PRE:
            continue
        out[k] = (a, r[0].lower(), r[1], r[2], ln)
        for j in range(k + 1, len(rows)):
            b = rows[j][0]
            if b < a + len(r[0]) // 2:
                drop.add(j)
            else:
                break
    return [r for k, r in enumerate(out) if k not in drop], len(drop)


def fix_width(rows, ref=None):
    """把 Ghidra 写窄的指令（例如 `08 E3` 只写了 `08`、`01 F2` 只写了 `01`）
    用参考反汇编的完整编码补齐，返回新的 rows。

    Ghidra 的两种情况：
    - 2 字节 `?? 08h` 后紧跟 `f2 82 2b ...` 的残行（0x9223、0x8101…）；
    - 4 字节 `BL` 被写成单字节 `01`（0x101F0、0xD85E…）。
    参考里能看到同地址的完整编码（2 或 4 字节），直接以它为准；
    只有参考与 Ghidra 在当前地址的字节前缀一致时才替换。
    """
    ref = ref if ref is not None else ref_lines()
    out = []
    i = 0
    rows = sorted(rows, key=lambda r: r[0])
    rows, dropped = _extend_overlap(rows, ref)
    fixed = dropped
    while i < len(rows):
        a, bs, mn, op, ln = rows[i]
        r = ref.get(a)
        if r and len(r[0]) > len(bs) and bs.lower() == r[0][:len(bs)].lower():
            # 参考在当前地址有更宽的完整编码
            out.append((a, r[0].lower(), r[1], r[2], ln))
            fixed += 1
            i += 1
            continue
        if _is_junk(bs, mn) and r is None:
            # 纯未定义字节：若参考把这里当数据，照样保留原始读数
            out.append(rows[i])
            i += 1
            continue
        out.append(rows[i])
        i += 1
    return out, fixed


def labels(path=RAW_ASM):
    """Ghidra 的标签定义行 -> {标签地址: [(类型, 名字)]}，类型 FUN/LAB/PTR_FUN/DAT/..."""
    out = {}
    rx = re.compile(r'^\s+([A-Z][A-Z0-9_]*?)_(?:rom_)?([0-9a-f]{6}):')
    for lb in open(path, 'rb'):
        ln = lb.decode('latin-1')
        m = rx.match(ln)
        if m:
            out.setdefault(int(m.group(2), 16), []).append(m.group(1))
    return out


if __name__ == '__main__':
    import sys
    sys.stdout.reconfigure(encoding='utf-8')
    a = asm_lines()
    print('指令行', len(a), '首', hex(a[0][0]), '末', hex(a[-1][0]))
    L = labels()
    print('标签数', len(L))
    for addr in (0x9d22, 0x9200, 0xd84c):
        print(hex(addr), L.get(addr))