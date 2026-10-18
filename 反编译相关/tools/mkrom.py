import re
d={}
missing=set()
with open('../反编译结果/991CN X.txt','rb') as f:
    for lb in f:
        if lb[:8]!=b'rom:rom:': continue
        l=lb.decode('latin-1')
        m=re.match(r'rom:rom:([0-9a-f]{6})\s+([0-9a-f]+)',l)
        if not m: continue
        a=int(m.group(1),16); b=m.group(2)
        for i in range(len(b)//2):
            d[a+i]=int(b[2*i:2*i+2],16)
# build image
size=0x40000
img=bytearray([0xff])*size
for a,v in d.items():
    if a<size: img[a]=v
open('rom_rebuilt.bin','wb').write(img)
print('bytes',len(d),'missing pages', [hex(p) for p in (0xc000,0x14000,0x1b000,0x26000)])
print('sample 0x0000', img[:16].hex())
print('sample 0x2038', img[0x2030:0x2060].hex())
