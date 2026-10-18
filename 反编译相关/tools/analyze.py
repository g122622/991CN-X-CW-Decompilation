#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""解析 Ghidra 反编译输出，建立函数/全局/调用图索引。"""
import re, json, sys, os

SRC = sys.argv[1] if len(sys.argv) > 1 else '../反编译结果/991CN X.c'

FUNC_HDR = re.compile(r'^((?:[A-Za-z_][\w\* ]*?)\s+(\w+)\s*\(([^)]*)\))\r?\n\r?\n\{\r?$', re.M)

def parse(path):
    t = open(path, encoding='utf-8').read().replace('\r\n', '\n')
    ms = list(FUNC_HDR.finditer(t))
    funcs = []
    for i, m in enumerate(ms):
        end = ms[i+1].start() if i+1 < len(ms) else len(t)
        start = m.start()
        # include preceding comment block
        head = t.rfind('\n\n\n\n', 0, start)
        head = 0 if head < 0 else head + 4
        body = t[m.end():end].rstrip() + '\n'
        funcs.append(dict(name=m.group(2), args=m.group(3), ret=m.group(1)[:m.group(1).find(m.group(2))].strip(),
                          text=t[m.start():end], start=m.start(), end=end, head=head))
    return t, funcs

if __name__ == '__main__':
    t, funcs = parse(SRC)
    print(len(funcs))
    names = [f['name'] for f in funcs]
    import collections
    dup = [n for n, c in collections.Counter(names).items() if c > 1]
    print('dups', dup[:10])
    globs = sorted(set(re.findall(r'\b_?DAT_ram_([0-9a-fA-F]+)\b', t)))
    print('globals', len(globs))
    print('funcs not matching addr', [f['name'] for f in funcs if not re.match(r'(thunk_)?FUN_rom_[0-9a-f]{6}$', f['name'])][:40])

def index(funcs):
    import collections
    calls = {}
    for f in funcs:
        c = set(re.findall(r'\b((?:thunk_)?FUN_rom_[0-9a-fA-F]{6})\s*\(', f['text']))
        c |= set('FUN_rom_'+x for x in re.findall(r'\bFUN_ram_([0-9a-fA-F]{6})\s*\(', f['text']))
        c.discard('thunk_' + f['name']); c.discard(f['name'])
        calls[f['name']] = c
    return calls
