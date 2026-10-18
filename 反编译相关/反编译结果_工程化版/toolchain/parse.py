#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""解析 Ghidra 反编译输出（C 文本 + 反汇编文本），建立函数与数据的索引。"""
import re, os, json

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
RAW_C = os.path.join(ROOT, '原始反编译结果', '991CN X.ghidra原始.c')
RAW_ASM = os.path.join(ROOT, '原始反编译结果', '991CN X.汇编.txt')

FUNC_HDR = re.compile(r'^((?:[A-Za-z_][\w\* ]*?)\s+(\w+)\s*\(([^)]*)\))\n\n\{', re.M)
ASM_ENTRY_RX = re.compile(rb'^rom:rom:([0-9a-f]{6})\s+([0-9a-f]+)')


def _asm_entries(path=RAW_ASM):
    """反汇编中的函数入口：[(addr, name)]，按地址排序。
    无声明行的“拆分子函数”标签（声明行落在前一个函数体内）跳过。"""
    lines = open(path, 'rb').readlines()
    out = []
    for i, lb in enumerate(lines):
        if b'FUNCTION' not in lb or not lb.strip().startswith(b';*'):
            continue
        decl = None
        j = i + 1
        while j < len(lines) and j < i + 20:
            s = lines[j].decode('latin-1').strip()
            if s.startswith(';') and not s.startswith(';*'):
                t = s[1:].strip()
                if '(' in t and not t.startswith('param_') and not t.startswith('XREF'):
                    decl = t
                    break
            j += 1
        if not decl:
            continue
        if i + 1 < len(lines) and b'FUNCTION' in lines[i + 1] and lines[i + 1].strip().startswith(b';*'):
            continue
        if i + 2 < len(lines) and lines[i + 1].strip().startswith(b';') and b'FUNCTION' in lines[i + 2]:
            continue
        name = decl.split('(')[0].split()[-1]
        k = j - 1
        while k < len(lines) - 1 and k < i + 80:
            k += 1
            m = ASM_ENTRY_RX.match(lines[k])
            if m:
                out.append((int(m.group(1), 16), name))
                break
    return sorted(out)


LITERAL_RX = re.compile(r"'(\\(?:x[0-9a-fA-F]{2}|.)|[^\\'])'")


def _strip_literals(line):
    """去掉字符字面量（它们可能含 { 或 }），避免干扰花括号计数。"""
    return LITERAL_RX.sub("''", line)


def find_matching_brace(t, i):
    """从 t[i]（必须是 '{'）出发查找配对的 '}'，跳过字符字面量与注释。返回下标。"""
    n = len(t)
    d = 0
    j = i
    while j < n:
        ch = t[j]
        if ch == "'":
            m = LITERAL_RX.match(t, j)
            j = m.end() if m else j + 1
            continue
        if ch == '/' and j + 1 < n and t[j + 1] in '/*':
            if t[j + 1] == '/':
                k = t.find(chr(10), j)
                j = n if k < 0 else k + 1
            else:
                k = t.find('*/', j + 2)
                j = n if k < 0 else k + 2
            continue
        if ch == '{':
            d += 1
        elif ch == '}':
            d -= 1
            if d == 0:
                return j
        j += 1
    return -1


def header_at_top(t):
    """重新切分 Ghidra 文本：函数声明只在花括号深度为 0 时才算数，
    这样被错误合并进前一函数的子入口不会再被当成独立函数。"""
    ms = list(FUNC_HDR.finditer(t))
    out = []
    pos = 0
    funcs = []
    depth = 0
    skipped = 0
    for idx, m in enumerate(ms):
        seg = t[pos:m.start()]
        depth += _strip_literals(seg).count('{') - _strip_literals(seg).count('}')
        pos = m.start()
        if depth != 0:
            skipped += 1
            continue
        funcs.append(m)
    res = []
    for k, m in enumerate(funcs):
        end = funcs[k + 1].start() if k + 1 < len(funcs) else len(t)
        res.append(dict(name=m.group(2), ret=m.group(1)[:m.group(1).find(m.group(2))].strip(),
                        args=m.group(3), start=m.start(), end=end))
    return t, res


def _brace_depth_lines(lines):
    """逐行的花括号深度（忽略字符字面量里的括号）。"""
    out = []
    d = 0
    for ln in lines:
        out.append(d)
        s = _strip_literals(ln)
        d += s.count('{') - s.count('}')
    out.append(d)
    return out


def _balance_text(t):
    """Ghidra 在某些函数里把花括号写成 '\x7f' 之类的转义序列（如 != '\x7b' 实为 != '{'），
    或把 '{' / '}' 写成别的形式，使花括号计数失效。这里只把“被单引号包住”的括号
    还原成普通括号（引号外的内容一概不动）。"""
    def fix(mm):
        s = mm.group(1)
        if len(s) == 4 and s[0] == chr(92) and s[1] == 'x':
            v = int(s[2:], 16)
            if v == 0x7B:
                return "'{'"
            if v == 0x7D:
                return "'}'"
        return mm.group(0)
    return re.sub(r"'((?:" + chr(92) + "x[0-9a-fA-F]{2})|(?:[^'\\]))'", fix, t)


def _fix_function(t, header, insert_before):
    """在函数体内首个匹配行之前补回被丢弃的一个 '}'（缩进按当前深度）。"""
    i = t.index(header)
    lines = t[i:].split(chr(10))
    cand = [x for x, l in enumerate(lines) if l.startswith('  ' + insert_before)]
    k = cand[0]
    depths = _brace_depth_lines(lines)
    # 紧接其前几行是 "  }"（原函数封口）则补在其前，使 return 留在子函数内
    for x in cand[:2]:
        if x >= 2 and lines[x - 1].startswith('  }') and lines[x - 2].startswith('    '):
            k = x - 1
            break
    depth = depths[k]
    lines.insert(k, '  ' * max(1, depth - 1) + '}')
    return t[:i] + chr(10).join(lines)


def split_merged(path=RAW_C):
    """原样复制 Ghidra 反编译产物为 991CN X.chunksplit.c（当前不做括号修补）。"""
    out_path = os.path.join(ROOT, "原始反编译结果", "991CN X.chunksplit.c")
    open(out_path, "wb").write(open(path, "rb").read())
    return out_path


def parse_c(path=RAW_C):
    """切分 Ghidra 的 C 文本。函数体起点为声明后第一行只有 { 的行，终点为下一个函数声明处。
    函数声明只认花括号深度为 0 的位置（Ghidra 合并子入口时会写出深度>0 的假声明）。"""
    NL = chr(10)
    raw = open(path, "rb").read()
    t = raw.decode("utf-8", "replace").replace(chr(13) + NL, NL)
    ms = [m for m in header_at_top(t)[1]]
    funcs = []
    for i, m in enumerate(ms):
        end = ms[i+1]['start'] if i+1 < len(ms) else len(t)
        br = t.find(NL + "{", m['start'], m['start'] + 400)
        if br < 0:
            br = m['end'] - 1
        body = t[br + 1:end].rstrip(NL) + NL
        ret = m['ret']
        funcs.append(dict(name=m['name'], ret=ret, args=m['args'], body=body,
                          start=m['start'], end=end))
    return t, funcs


def parse_asm(path=RAW_ASM):
    """返回 [(addr, bytes, mnemonic, operands)]，按地址排序。"""
    out = []
    rx = re.compile(rb'^rom:rom:([0-9a-f]{6})\s+([0-9a-f]+)\s+(\S+)\s*(.*)$')
    for lb in open(path, 'rb'):
        if lb[:8] != b'rom:rom:':
            continue
        m = rx.match(lb.rstrip(b'\r\n'))
        if not m:
            continue
        out.append((int(m.group(1), 16), m.group(2).decode(), m.group(3).decode(),
                    m.group(4).decode('latin-1')))
    return out


def build_rom(asm, size=0x20000, path=None):
    img = bytearray(b'\xff' * size)
    covered = bytearray(size)
    for addr, bs, mn, op in asm:
        for i in range(len(bs)//2):
            a = addr + i
            if a < size:
                img[a] = int(bs[2*i:2*i+2], 16)
                covered[a] = 1
    if path:
        open(path, 'wb').write(img)
    return img, covered


if __name__ == '__main__':
    t, f = parse_c()
    a = parse_asm()
    print('C functions:', len(f), ' asm lines:', len(a))
    img, cov = build_rom(a)
    print('ROM covered bytes:', sum(cov))