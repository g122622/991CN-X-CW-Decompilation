#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""校验：把 991CN X.汇编.txt 的全部行重组成 ROM 镜像，与参考 _disas_commented.txt 的
逐字节解码比对。用于确认本工程的汇编视图没有丢行、错位或误并。

判定规则（与 docs/casio-main符号对照.md §5 一致）：
- Ghidra 可能把参考中的“2 字节 + 紧跟的高字节”合并成一条 4 字节指令（例如
  `03e35092` = 参考的 `03 E3` + `50 92`），也可能只写低 2 字节
  （参考方向扫描把高字节再解成一条；Ghidra 之后又从下一地址重新同步）。
  这两种不算差异：比较时不看参考行，只比较“重组的字节流”。
- `??` 行仍属于指令流（参考里是 RTI/BRK 等 2 字节指令）。

运行：python tests/check_asm_parity.py
"""
import sys, os, re, collections

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(os.path.dirname(HERE))
sys.path.insert(0, os.path.join(ROOT, 'toolchain'))
sys.stdout.reconfigure(encoding='utf-8')

RAW = os.path.join(ROOT, '原始反编译结果', '991CN X.汇编.txt')
REF = os.path.abspath(os.path.join(ROOT, '..', '参考-casio-main', '_disas_commented.txt'))

# 逐行重组：同一地址只取第一次出现（标签行与指令行同地址时取指令行）
rom = {}
gaps = []
prev_end = None
for k, lb in enumerate(open(RAW, 'rb')):
    s = lb.decode('latin-1').rstrip('\r\n')
    m = re.search(r'(?:^|\s)rom:rom:([0-9a-f]{6})\s+([0-9a-f]+)\s+(\S+)', s)
    if not m:
        continue
    a = int(m.group(1), 16)
    bs = m.group(2)
    if a in rom:
        continue
    rom[a] = bs
    if prev_end is not None and a < prev_end:
        gaps.append(('重叠', a, prev_end))
    prev_end = max(prev_end or 0, a + len(bs) // 2)

# 参考解码
ref = []
for ln in open(REF, 'rb').read().decode('utf-8', 'replace').split('\n'):
    m = re.match(r'^([0-9A-Fa-f]{6})   ([0-9A-Fa-f]{2}(?: [0-9A-Fa-f]{2})*)(\s.*)?$', ln)
    if not m:
        continue
    rest = (m.group(3) or '').split('//')[0].strip()
    if rest:
        ref.append((int(m.group(1), 16), ''.join(m.group(2).split()), rest))

def covered(a, bs):
    """本工程在 a 处写的字节是否覆盖参考的 bs（前 N 字节）。"""
    got = rom.get(a, '')
    return got[:len(bs)].lower() == bs.lower()

same = 0
diff = []
for a, bs, r in ref:
    if covered(a, bs):
        same += 1
    else:
        diff.append((a, bs, rom.get(a), r))

print('参考条目 %d，本工程覆盖 %d（%.2f%%），未覆盖 %d'
      % (len(ref), same, 100.0 * same / len(ref), len(diff)))
print('本工程指令行 %d，重叠/倒序 %d' % (len(rom), len(gaps)))
# 预期差异：向量表（参考把前 4 字节当 SP）、参考方向扫描误判的 RTI、纯填充 FF
expect = [d for d in diff if d[0] < 0x22C or d[2] == 'ff' or d[1] == '0FFE'
          or d[1] == '8EF8' or d[1] == '8EF4' or d[2] == '0f' or d[1] == '011A']
rest = [d for d in diff if d not in expect]
print('其中可解释（向量/RTI/填充）%d，其它 %d' % (len(expect), len(rest)))
for d in rest[:40]:
    print('  %06x ref=%-16s ours=%-16s %s' % (d[0], d[1], d[2] or '-', d[3][:50]))
sys.exit(1 if rest else 0)