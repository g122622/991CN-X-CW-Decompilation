#!/usr/bin/env python3
"""用 clang 对生成的源码做语法检查（-fsyntax-only）。
整数/指针隐式转换是 Ghidra 源码的固有特征，检查时关闭对应诊断。"""
import os, subprocess, sys, glob
ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
CLANG = r'D:\Program Files\Microsoft Visual Studio\18\Community\VC\Tools\Llvm\x64\bin\clang.exe'
flags = ['--target=x86_64-pc-windows-gnu', '-fsyntax-only', '-std=c11',
         '-Wno-int-conversion', '-Wno-incompatible-pointer-types',
         '-Wno-incompatible-function-pointer-types', '-Wno-bool-conversion',
         '-Wno-return-mismatch', '-Wno-return-type', '-Wno-implicit-function-declaration',
         '-I', os.path.join(ROOT, 'include')]
bad = []
files = sorted(glob.glob(os.path.join(ROOT, 'src', '**', '*.c'), recursive=True))
for f in files:
    r = subprocess.run([CLANG] + flags + [f], capture_output=True, text=True)
    errs = [l for l in r.stderr.splitlines() if 'error:' in l]
    if errs:
        bad.append((os.path.relpath(f, ROOT), errs))
print('checked %d files, %d with errors' % (len(files), len(bad))); [print('==', f) for f, _ in bad]
for f, errs in bad[:int(sys.argv[1]) if len(sys.argv) > 1 else 20]:
    print('==', f)
    for e in errs[:3]:
        print('  ', e)
