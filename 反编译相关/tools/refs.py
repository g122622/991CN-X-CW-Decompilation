"""扫描 C 代码中的数字字面量引用，判断其是否落入某个函数的起始地址（不可直接调用，Ghidra 未识别）。"""
import json,re,collections,sys
fs=json.load(open('funcs.json'))
addr2name={}
for f in fs:
    if f['addr'] is None or f['name'].startswith('thunk'): continue
    addr2name[f['addr']]=f['name']
out=collections.Counter()
for f in fs:
    if f['addr'] is None: continue
    for m in re.finditer(r'\b(0x[0-9a-f]{4,5}|DAT_ram_[0-9a-f]{4}|FUN_rom_[0-9a-f]{6}|[>\s][0-9]{4,5})\b', f['text']):
        pass
# simpler: find hex literals in range 0x1000..0x2b000 that equal a function start
for f in fs:
    for m in re.finditer(r'\b0x([0-9a-f]{4,5})\b', f['text']):
        v=int(m.group(1),16)
        if v in addr2name:
            out[(addr2name[v])]+=1
for k,v in out.most_common(60):
    print(k, addr2name[int(k[8:],16)], v)
