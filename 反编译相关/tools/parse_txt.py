import re
def parse_funcs(path='../反编译结果/991CN X.txt'):
    out=[]
    cur=None
    with open(path,'rb') as f:
        lines=f.readlines()
    i=0
    for idx,lb in enumerate(lines):
        if b'FUNCTION' in lb and lb.strip().startswith(b';*'):
            # next lines: ;decl then maybe params, then first code line
            j=idx+1
            decl=None
            while j<len(lines) and j<idx+30:
                l=lines[j].decode('latin-1').rstrip('\n')
                if l.lstrip().startswith(';') and not l.lstrip().startswith(';*'):
                    s=l.lstrip()[1:].strip()
                    if s and not s.startswith('param_') and not s.startswith('WARNING') and not s.startswith('XREF'):
                        decl=s
                        break
                j+=1
            # find first code line
            k=idx+1; addr=None; name=None
            while k<len(lines) and k<idx+80:
                l=lines[k].decode('latin-1')
                m=re.match(r'rom:rom:([0-9a-f]{6})\s+([0-9a-f]+)\s+(\S+)\s*(.*)',l)
                if m:
                    addr=int(m.group(1),16)
                    ins=m.group(3)
                    if ins in ('B',) and 'thunk' in (decl or ''):
                        name=(decl or '').split('(')[0].split()[-1]
                    break
                k+=1
            if addr is not None and decl:
                name=decl.split('(')[0].split()[-1]
                out.append(dict(addr=addr,decl=decl,name=name))
    return out
if __name__=='__main__':
    f=parse_funcs()
    print(len(f))
    print(f[:3]); print(f[300:303])
