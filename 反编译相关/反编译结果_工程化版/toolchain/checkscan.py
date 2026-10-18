#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""用 clang 扫描生成的源码，按错误类别统计（调试用）。"""
import collections
import glob
import os
import subprocess
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
CLANG = r'D:\Program Files\Microsoft Visual Studio\18\Community\VC\Tools\Llvm\x64\bin\clang.exe'
flags = ['--target=x86_64-pc-windows-gnu', '-fsyntax-only', '-std=c11',
         '-Wno-int-conversion', '-Wno-incompatible-pointer-types',
         '-Wno-incompatible-function-pointer-types', '-Wno-bool-conversion',
         '-Wno-return-mismatch', '-Wno-return-type', '-Wno-implicit-function-declaration',
         '-Wno-constant-conversion', '-Wno-shift-count-overflow',
         '-I', os.path.join(ROOT, 'include')]
cats = collections.Counter()
detail = []
only = sys.argv[1] if len(sys.argv) > 1 else None
for f in sorted(glob.glob(os.path.join(ROOT, 'src', '**', '*.c'), recursive=True)):
    if only and only not in f:
        continue
    r = subprocess.run([CLANG] + flags + [f], capture_output=True, text=True)
    for l in r.stderr.splitlines():
        if 'error:' in l:
            msg = l.split('error: ', 1)[1]
            cats[msg] += 1
            detail.append(l.replace(ROOT + os.sep, ''))
print('errors by kind:')
for k, v in cats.most_common(80):
    print('%4d  %s' % (v, k))
print('total:', sum(cats.values()))
if len(sys.argv) > 2:
    for d in detail:
        if sys.argv[2] in d:
            print(d)