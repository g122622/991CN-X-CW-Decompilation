#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""用 casio-main 的 labels.txt / _disas_commented.txt 校准本工程的函数地址。

出处：参考-casio-main/（从 F:\\下载\\casio-main 复制）
- labels.txt：真实符号名（函数入口 + 数据标签），名字带 `__` 表示不确定；
- _disas_commented.txt：按真实地址逐条注释的反汇编，标签注释形如
  `///////////////名字   r0:...,er2:...`，**紧跟在它后一行的地址就是标签地址**。

注意：labels.txt 是由另一机型（注释里写 “ES PLUS”）的标签自动转换而来。检查发现
本 ROM 中 `0x821C`、`0x81A2` 处是函尾填充的 `0000`（MOV R0,#0，与函数脱节，
不是入口），因此 labels.txt 的地址只能作**类型参考**，本工程按结构核对后采用：

- `0x821E`：`line_print`（标签注释里带 `r0:col,r1:row,er2`，与本 ROM 一致）；
- `0x821C`：不是函数入口，只是 E3D4 上的“首列书写”填充 NOP，保留为子标签；
- `0x81A2`：是真实的 str_decompress_print 实现，但入口在其后 2 字节。

运行 `python calibrate.py` 会打印真实符号与本工程入口的对照表。
"""
import re, os, sys, json, collections

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
REF = os.path.abspath(os.path.join(ROOT, '..', '参考-casio-main'))

# 本 ROM 与 labels.txt 的已知差异（地址 -> 说明）
LABEL_ADDR_NOTES = {
    0x821C: '本 ROM 处为函尾填充 0000（MOV R0,#0），非入口；line_print 在 0x821E',
    0x81A2: '本 ROM 处为填充 0000，str_decompress_print 入口在 0x81A4',
    0x93EC: '本 ROM 处为 RTI（宏组件陷阱），不是例程',
}


def labels_table(path=None):
    """labels.txt -> {地址: (名字, 说明)}。只取顶格、以十六进制地址开头的行。"""
    path = path or os.path.join(REF, 'labels.txt')
    out = {}
    for ln in open(path, 'rb').read().decode('utf-8', 'replace').split('\n'):
        if not ln or ln[0] not in '0123456789abcdefABCDEF':
            continue
        m = re.match(r'^([0-9A-Fa-f]+)\s+([A-Za-z_.][\w.]*)\s*(#.*)?$', ln)
        if not m:
            continue
        addr = int(m.group(1), 16)
        out[addr] = (m.group(2), (m.group(3) or '').lstrip('# ').strip())
    return out


CAND_RX = re.compile(r'^/{3,}(\S+)(?:\s+(.*))?$')
CODE_RX = re.compile(r'^([0-9A-Fa-f]{6})   ')
DATA_RX = re.compile(r'^([0-9A-Fa-f]{6})   ((?:[0-9A-Fa-f]{2} )+)')


def _lines():
    path = os.path.join(REF, '_disas_commented.txt')
    return open(path, 'rb').read().decode('utf-8', 'replace').split('\n')


def asm_label_candidates(lines=None):
    """-> {地址: [(名字, 参数说明)]}，只收标签注释（`.foo` 成员与 `///loop` 不算）。"""
    lines = lines or _lines()
    out = collections.OrderedDict()
    for i, ln in enumerate(lines):
        m = CAND_RX.match(ln)
        if not m:
            continue
        name = m.group(1)
        if name.startswith('.') or name.startswith('/') or name == 'loop':
            continue
        j = i + 1
        while j < len(lines) and not lines[j].strip():
            j += 1
        cm = CODE_RX.match(lines[j]) if j < len(lines) else None
        if not cm:
            continue
        out.setdefault(int(cm.group(1), 16), []).append(
            (name, (m.group(2) or '').strip()))
    return out


def instr_sizes(lines=None):
    """-> {地址: 字节数}（数据行也算，用来判断某地址能否是指令/入口）。"""
    lines = lines or _lines()
    out = {}
    for ln in lines:
        m = DATA_RX.match(ln)
        if m:
            out[int(m.group(1), 16)] = len(m.group(2).split())
    return out


def data_table():
    """labels.txt 里的 `d_0Dxxx` 标签 -> {RAM 地址: (名字, 注释)}；同时带回 SFR 表。"""
    out = {}
    for a, (nm, c) in labels_table().items():
        if nm.startswith('d_'):
            out[a & 0xFFFF] = (nm[2:], c)
    return out


def our_table():
    """本工程的 地址 -> 名字（命名库为准；只收录对齐到的函数地址）。"""
    import align, naming_db
    cs, ts, pairs, misses = align.align()
    out = {}
    for i, j in pairs:
        a = ts[j][0]
        e = naming_db.FUNCS.get(a)
        out[a] = e['name'] if e else align.ALIAS.get(cs[i]['name'], cs[i]['name'])
    return out, misses


CELL = re.compile(r'^[+-]?-?[0-9A-F]{2}(?: [0-9A-F]{2})*$')


def align_check(path=None):
    """方位扫描核对：把参考反汇编与本工程汇编按地址逐字节比较。

    返回 (比较条数, 相同条数, 差异列表)。差异列表每项 (地址, 参考字节, 本工程字节, 参考文本)。
    只有参考中“指令/数据”行参与比较；`python calibrate.py` 末尾会打印摘要。
    """
    import rawasm
    path = path or os.path.join(REF, '_disas_commented.txt')
    ours = {a: b for a, b, mn, op, ln in rawasm.asm_lines()}
    same = 0
    diffs = []
    for ln in open(path, 'rb').read().decode('utf-8', 'replace').split('\n'):
        m = re.match(r'^([0-9A-Fa-f]{6})   ([0-9A-Fa-f]{2}(?: [0-9A-Fa-f]{2})*)(\s.*)?$', ln)
        if not m:
            continue
        rest = (m.group(3) or '').split('//')[0].strip()
        if not rest:
            continue
        a = int(m.group(1), 16)
        b = ''.join(m.group(2).split())
        if ours.get(a, '').lower() == b.lower():
            same += 1
        else:
            diffs.append((a, b, ours.get(a), rest))
    return same, len(diffs), diffs


def main():
    sys.stdout.reconfigure(encoding='utf-8')
    lab = labels_table()
    cands = asm_label_candidates()
    ours, misses = our_table()
    print('labels.txt:', len(lab), ' disas 标签:', len(cands),
          ' 本工程入口:', len(ours))
    print('align misses:', misses)
    print()
    print('%-8s %-26s %-26s %s' % ('地址', 'casio-main', '本工程', '判断'))

    def same(a, b):
        a = a.replace('.', '_').strip('_')
        b = b.replace('.', '_').strip('_')
        return a == b or a.startswith(b + '_') or b.startswith(a + '_')

    for a in sorted(set(lab) | set(cands)):
        nm = lab.get(a, (None, ''))[0]
        alt = [c[0] for c in cands.get(a, [])]
        names = [x for x in ([nm] if nm else []) + alt if x and not x.startswith('/')]
        on = ours.get(a)
        if not on:
            verdict = '<-- 本工程无此入口'
        elif any(same(x, on) for x in names):
            verdict = 'ok'
        else:
            verdict = '<-- 名称不同'
        if a in LABEL_ADDR_NOTES:
            verdict += '（' + LABEL_ADDR_NOTES[a] + '）'
        print('%-8s %-26s %-26s %s' % ('%06X' % a,
                                       (nm or '') + ('/' + ','.join(alt) if alt else ''),
                                       on or '-', verdict))
    json.dump({'labels': {('%06X' % a): v for a, v in lab.items()},
               'disas': {('%06X' % a): v for a, v in cands.items()},
               'notes': {('%06X' % a): v for a, v in LABEL_ADDR_NOTES.items()}},
              open(os.path.join(ROOT, 'toolchain', 'casio_labels.json'), 'w',
                   encoding='utf-8'), ensure_ascii=False, indent=1)


if __name__ == '__main__':
    main()
    sys.stdout.reconfigure(encoding='utf-8')
    same, nd, diffs = align_check()
    print()
    print('方位扫描核对：相同 %d 条，不同 %d 条' % (same, nd))
    for a, b, ob, r in diffs:
        print('  %06x ref=%-16s ours=%-16s %s' % (a, b, ob or '-', r[:48]))