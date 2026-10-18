#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""构建完整函数索引：C 函数 -> 地址 / 汇编入口 / 调用 / RAM 引用。"""
import re, os, json, collections
import parse, align

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))

def build():
    cs, ts, pairs, misses = align.align()
    # 直接按名字中的地址补齐未匹配项
    amap = {i: ts[j][0] for i, j in pairs}
    for m in misses:
        if m[0] == 'no_match':
            i = m[1]
            name = cs[i]['name']
            mm = re.search(r'([0-9a-f]{6})$', name)
            if mm:
                amap[i] = int(mm.group(1), 16)
            else:
                amap[i] = None
    recs = []
    for i, f in enumerate(cs):
        addr = amap.get(i)
        calls = sorted(set(re.findall(r'\b(?:thunk_)?FUN_rom_([0-9a-f]{6})\s*\(', f['body'])))
        calls_named = sorted(set(re.findall(r'\b([A-Za-z_]\w*)\s*\(', f['body'])))
        globs = sorted(set(re.findall(r'\b_?DAT_ram_([0-9a-f]{4})\b', f['body'])))
        recs.append(dict(i=i, name=f['name'], addr=addr, ret=f['ret'], args=f['args'],
                         size=len(f['body']), calls=[int(c, 16) for c in calls],
                         callees=calls_named, globs=globs, body=f['body'],
                         existing_comment=extract_comment(cs[i]['body'])))
    return recs, cs, ts

def extract_comment(body):
    # 只保留 body 前面的手工注释（// 行）
    out = []
    for line in body.split('\n'):
        if line.strip().startswith('{'):
            break
        s = line.strip()
        if s.startswith('//') and not s.startswith('// WARNING'):
            out.append(s[2:].strip())
    return out[:12]

if __name__ == '__main__':
    recs, cs, ts = build()
    print('records', len(recs), 'with addr', sum(1 for r in recs if r['addr'] is not None))
    hist = collections.Counter()
    for r in recs:
        if r['addr'] is not None:
            hist[(r['addr'] >> 12) << 12] += 1
    for k in sorted(hist):
        print('%05x %d' % (k, hist[k]))
    with open(os.path.join(ROOT, 'toolchain', 'index.json'), 'w', encoding='utf-8') as f:
        json.dump(recs, f, ensure_ascii=False, indent=1)
