#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""把 Ghidra C 函数与反汇编函数入口一一对齐。"""
import re, os
import parse

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
CUR = os.path.join(ROOT, '原始反编译结果', '991CN X.ghidra原始.c')

# rename_functions.py 中的 31 个改名 -> 原函数名
ALIAS = {
 'memset':'FUN_rom_00f1a8','memzero':'FUN_rom_008fb8','strcpy':'FUN_rom_00d070',
 'memcpy':'FUN_rom_009d72','smart_strcpy':'FUN_rom_009462','smart_strcat':'FUN_rom_00959c',
 'byte_strlen':'FUN_rom_00b5ba','fill_screen':'FUN_rom_007eac','buffer_clear':'FUN_rom_007f00',
 'set_display_line':'FUN_rom_007f1a','set_display_position':'FUN_rom_007f58',
 'set_display_area':'FUN_rom_007fa0','buf1_to_buf2':'FUN_rom_0086e0',
 'render_e3d4':'FUN_rom_0086f8','flush_screen':'FUN_rom_008704','refresh_display':'FUN_rom_00a15a',
 'char_print_1byte':'FUN_rom_0082ec','char_print':'FUN_rom_0082f6','char_get_14':'FUN_rom_0084d8',
 'char_get_l14':'FUN_rom_0085b8','line_print':'FUN_rom_008c4a','smallprint':'FUN_rom_008c6c',
 'line_print_col0':'FUN_rom_008c88','line_print_Col3':'FUN_rom_008c90','waitkey':'FUN_rom_0096be',
 'read_key':'FUN_rom_0096fc','delay':'FUN_rom_0094da',
 'thunk_memset':'thunk_FUN_rom_00f1a8','thunk_memzero':'thunk_FUN_rom_008fb8',
 'thunk_strcpy':'thunk_FUN_rom_00d070','thunk_memcpy':'thunk_FUN_rom_009d72',
}

def c_funcs(path):
    return parse.parse_c(path)[1]

def asm_func_entries():
    out = []
    lines = open(os.path.join(ROOT, '原始反编译结果', '991CN X.汇编.txt'), 'rb').readlines()
    rx_code = re.compile(rb'^rom:rom:([0-9a-f]{6})\s+([0-9a-f]+)')
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
            # 无声明行的拆分子函数标签：Ghidra 不把它当作函数，跳过
            continue
        if i + 2 < len(lines) and lines[i + 1].strip().startswith(b";") and b"FUNCTION" in lines[i + 2]:
            # 声明行落在前一个函数体内（Ghidra 把子入口合并进了前一函数）：跳过
            continue
        if i > 0 and b"FUNCTION" in lines[i - 1] and lines[i - 1].strip().startswith(b";*"):
            # 紧跟在函数尾部的“拆分子函数”标签：其声明行落在前一个函数体内，跳过
            continue
        name = decl.split('(')[0].split()[-1]
        k = j
        while k < len(lines) and k < i + 80:
            m = rx_code.match(lines[k])
            if m:
                out.append((int(m.group(1), 16), name, k))
                break
            k += 1
    return out


def asm_numbered(path=None):
    """给没有 Ghidra 声明行的汇编入口补名字：FUN_rom_XXXXXX，并过滤花括号不平衡
    函数体内落入的块标签（引用 self 的标签不属于函数入口）。"""
    path = path or os.path.join(ROOT, '原始反编译结果', '991CN X.汇编.txt')
    lines = open(path, 'rb').readlines()
    rx_code = re.compile(rb'^rom:rom:([0-9a-f]{6})\s+([0-9a-f]+)')
    heads = []          # (声明地址, 名字)
    code = []           # (地址, 行号)
    fn = None
    for k, lb in enumerate(lines):
        m = rx_code.match(lb)
        if m:
            code.append((int(m.group(1), 16), k))
        if b'FUNCTION' in lb and lb.strip().startswith(b';*'):
            fn = (k, None)
        if fn and lb.strip().startswith(b';') and not lb.strip().startswith(b';*'):
            s = lb.decode('latin-1').strip()[1:].strip()
            if '(' in s and not s.startswith(('param_', 'XREF')) and fn[1] is None:
                fn = (fn[0], s.split('(')[0].split()[-1])
    # 逐 FUNCTION 头块记录 (函数体首个代码地址, 声明名)
    k = 0
    n = len(lines)
    entries = []
    while k < n:
        lb = lines[k]
        if b'FUNCTION' in lb and lb.strip().startswith(b';*'):
            start = k + 1
            decl = None
            while start < n and start < k + 20:
                s = lines[start].decode('latin-1').strip()
                if s.startswith(';') and not s.startswith(';*'):
                    t = s[1:].strip()
                    if '(' in t and not t.startswith(('param_', 'XREF')):
                        decl = t.split('(')[0].split()[-1]
                        break
                start += 1
            e = start
            while e < n:
                m = rx_code.match(lines[e])
                if m:
                    entries.append((int(m.group(1), 16), decl, k, e))
                    break
                e += 1
            k = e + 1
        else:
            k += 1
    # 对每个入口计算它到下一个入口之间被引用的本地 LAB 地址
    addr_line = {a: ln for a, ln in code}
    selfref = {}
    for idx, (a, decl, k0, k1) in enumerate(entries):
        end = entries[idx + 1][3] if idx + 1 < len(entries) else n
        refs = set()
        for ln in range(k1 + 1, end):
            s = lines[ln]
            if s[:8] != b'rom:rom:':
                continue
            t = s.decode('latin-1')
            for mm in re.finditer(r'(?:FUN_rom|LAB_rom)_([0-9a-f]{6})', t):
                v = int(mm.group(1), 16)
                if v > a:
                    refs.add(v)
        selfref[a] = refs
    # 入口标签某地址若是“落在前一个函数体内、且不在任何函数体开头位置”的块标签，则剔除
    names = []
    seen = set()
    for idx, (a, decl, k0, k1) in enumerate(entries):
        if decl is None or a in seen:
            continue
        seen.add(a)
        names.append((a, decl))
    return names, selfref


def asm_unlisted():
    """汇编中存在、但 Ghidra 文本中没有对应函数的入口（合并进前一函数的块）。"""
    names, _ = asm_numbered()
    cs = c_funcs(CUR)
    cnames = {ALIAS.get(f['name'], f['name']) for f in cs}
    return [(a, nm) for a, nm in names if nm not in cnames]


def align():
    cs = c_funcs(CUR)
    ts = asm_func_entries()
    pairs = []; i = j = 0; misses = []
    while i < len(cs) and j < len(ts):
        cn = ALIAS.get(cs[i]['name'], cs[i]['name']); tn = ts[j][1]
        if cn == tn or cn.replace('thunk_', '') == tn.replace('thunk_', ''):
            pairs.append((i, j)); i += 1; j += 1
        else:
            found = None
            for k in range(j, min(j + 12, len(ts))):
                if ts[k][1] == cn:
                    found = k; break
            if found is None:
                # Ghidra 把紧随其后的另一个入口一并算进了本函数：按更远处查找
                for k in range(j, min(j + 80, len(ts))):
                    if ts[k][1] == cn:
                        found = k; break
            if found is not None:
                misses.append(('skip_asm', j, found, cn, ts[j][1], hex(ts[j][0])))
                j = found
            else:
                # 可能 C 的该项在 asm 中不存在（伪函数/合并），跳过 C
                misses.append(('no_match', i, j, cn, tn, hex(ts[j][0])))
                i += 1
    while i < len(cs):
        misses.append(('tail_c', i, j, cs[i]['name'], None, None)); i += 1
    while j < len(ts):
        misses.append(('tail_asm', i, j, None, ts[j][1], hex(ts[j][0]))); j += 1
    return cs, ts, pairs, misses

if __name__ == '__main__':
    cs, ts, pairs, misses = align()
    print('C', len(cs), 'asm', len(ts), 'pairs', len(pairs), 'misses', len(misses))
    for m in misses: print(m)
    addrs = [ts[j][0] for _, j in pairs]
    print('monotonic strictly:', all(addrs[k] < addrs[k+1] for k in range(len(addrs)-1)))
