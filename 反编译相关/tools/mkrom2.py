#!/usr/bin/env python3
"""从 Ghidra 反汇编文本 (991CN X.txt) 重建 128KB ROM 镜像。
反汇编文本只覆盖了代码区与部分数据区，缺失的页填充为 0xFF。
"""
import re, sys
SRC = sys.argv[1] if len(sys.argv) > 1 else '../反编译结果/991CN X.txt'
OUT = sys.argv[2] if len(sys.argv) > 2 else 'rom_rebuilt.bin'
SIZE = 0x20000
img = bytearray([0xFF]) * SIZE
covered = bytearray(SIZE)
with open(SRC, 'rb') as f:
    for lb in f:
        if lb[:8] != b'rom:rom:':
            continue
        m = re.match(rb'rom:rom:([0-9a-f]{6})\s+([0-9a-f]+)', lb)
        if not m:
            continue
        a = int(m.group(1), 16); b = m.group(2).decode()
        for i in range(len(b)//2):
            if a + i < SIZE:
                img[a+i] = int(b[2*i:2*i+2], 16)
                covered[a+i] = 1
open(OUT, 'wb').write(img)
print('wrote', OUT, 'covered bytes:', sum(covered), '/', SIZE)
