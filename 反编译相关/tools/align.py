import analyze, parse_txt, re, json
t, cs = analyze.parse('../反编译结果/991CN X.c')
ts = parse_txt.parse_funcs()
print(len(cs), len(ts))
# C names as-is; map renamed ones back to FUN names for alignment
alias = {'fill_screen':'FUN_rom_007eac','buffer_clear':'FUN_rom_007f00','set_display_line':'FUN_rom_007f1a',
 'set_display_position':'FUN_rom_007f58','set_display_area':'FUN_rom_007fa0','char_print_1byte':'FUN_rom_0082ec',
 'char_print':'FUN_rom_0082f6','char_get_14':'FUN_rom_0084d8','char_get_l14':'FUN_rom_0085b8',
 'buf1_to_buf2':'FUN_rom_0086e0','render_e3d4':'FUN_rom_0086f8','flush_screen':'FUN_rom_008704',
 'line_print':'FUN_rom_02235a','smallprint':'FUN_rom_0221b2','line_print_col0':'FUN_rom_0220fe',
 'line_print_Col3':'FUN_rom_022108','memzero':'FUN_rom_008fb8','smart_strcpy':'FUN_rom_009462',
 'delay':'FUN_rom_00916a','smart_strcat':'FUN_rom_00959c','waitkey':'FUN_rom_0221c4',
 'read_key':'FUN_rom_00f746','memcpy':'FUN_rom_009d72','refresh_display':'FUN_rom_00a15a',
 'byte_strlen':'FUN_rom_00b5ba','strcpy':'FUN_rom_00d070','memset':'FUN_rom_00f1a8',
 'thunk_memzero':'thunk_memzero'}
# try sequential alignment greedily by name
i=j=0; pairs=[]; misses=[]
while i<len(cs) and j<len(ts):
    cn=cs[i]['name']; cn2=alias.get(cn,cn)
    tn=ts[j]['name']
    if cn2==tn or re.sub(r'^thunk_','',cn2)==re.sub(r'^thunk_','',tn) or (cn2.startswith('thunk_') and tn.startswith('thunk_') and cn2.split('_')[-1]==tn.split('_')[-1]):
        pairs.append((i,j)); i+=1; j+=1
    else:
        # search ahead in txt for cn2
        k=j
        while k<min(j+8,len(ts)) and ts[k]['name']!=cn2: k+=1
        if k<min(j+8,len(ts)):
            misses.append(('skip_txt',j,k,ts[j]['name'],cn2)); j=k
        else:
            misses.append(('missing_txt',i,j,cn,ts[j]['name'])); i+=1
print('pairs',len(pairs),'i',i,'j',j,'misses',len(misses))
for m in misses[:20]: print(m)
json.dump([(cs[i]['name'],ts[j]['addr'],ts[j]['name'],i,j) for i,j in pairs],open('align.json','w'),ensure_ascii=False)
# report monotonic
addrs=[ts[j]['addr'] for i,j in pairs]
bad=[(pairs[k],addrs[k-1],addrs[k]) for k in range(1,len(addrs)) if addrs[k]<=addrs[k-1]]
print('nonmonotonic',len(bad), bad[:5])
