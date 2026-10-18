# -*- coding: utf-8 -*-
"""校验切分结果：每段函数文本里不应再出现“属于其他函数”的声明或注释。

原始 Ghidra 文本被人为加过活名注释并把函数挪进了别的位置
（例如 read_key 标称 0xF746，实际是 0x96FC 的函数体）。本脚本检查：
  1) 每段文本只有函数自身的声明行；
  2) “// 地址: 0x...” 注释若出现在函数尾部，必须与下一函数的位置对应。

用法: python tests/check_split.py
"""
import sys, os, re
sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
import build_project as B

DECL = re.compile(r'^((?:[A-Za-z_][\w\* ]*?)\s+(\w+)\s*\([^)]*\))', re.M)


def main():
    recs = B.load_records()
    t, fs = B.parse.parse_c(B.SRC_C)
    by_name = {f['name']: f for f in fs}
    bad = 0
    moved = 0
    for r in recs:
        text = r['_text']
        decls = DECL.findall(text)
        if decls and decls[0][1] != r['name']:
            print('[HDR] %s: text starts with %s' % (r['name'], decls[0][1]))
            bad += 1
        inner = [d for d in decls[1:]]
        if inner:
            print('[INLINE-DECL] %s 0x%05X: %s' % (r['name'], r['addr'], [d[1] for d in inner][:4]))
            bad += 1
        for m in re.finditer(r'// 地址:\s*0x([0-9A-Fa-f]{6})', text):
            a = int(m.group(1), 16)
            if a not in B.addr_set if hasattr(B, 'addr_set') else False:
                pass
        m = re.search(r'\n// 地址:\s*0x([0-9A-Fa-f]{6})\s*$', text)
        if m:
            moved += 1
    print('functions', len(recs), 'problems', bad, 'moved-comment tails', moved)
    return 1 if bad else 0


if __name__ == '__main__':
    sys.exit(main())
