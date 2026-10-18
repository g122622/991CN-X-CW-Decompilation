import analyze, re, json, collections
t, fs = analyze.parse('../反编译结果/991CN X.c')
tab = {'memset':0x0f1a8,'memzero':0x08fb8,'strcpy':0x0d070,'memcpy':0x09d72,'smart_strcpy':0x203c8,
       'smart_strcat':0x203d6,'byte_strlen':0x0b5ba,'fill_screen':0x07eac,'buffer_clear':0x07f00,
       'set_display_line':0x07f1a,'set_display_position':0x07f58,'set_display_area':0x07fa0,
       'buf1_to_buf2':0x086e0,'render_e3d4':0x086f8,'flush_screen':0x08704,'refresh_display':0x0a15a,
       'char_print_1byte':0x082ec,'char_print':0x082f6,'char_get_14':0x084d8,'char_get_l14':0x085b8,
       'line_print':0x2235a,'smallprint':0x221b2,'line_print_col0':0x220fe,'line_print_Col3':0x22108,
       'waitkey':0x221c4,'read_key':0x0f746,'delay':0x0916a}
for f in fs:
    n=f['name']
    if n in tab: f['addr']=tab[n]
    else:
        try: f['addr']=int(n.split('_')[-1],16)
        except: f['addr']=None
        if n.startswith('thunk_memzero') or n.startswith('thunk_FUN_ram'): f['addr']=None
calls={}; callers=collections.defaultdict(set)
for f in fs:
    cs=set(re.findall(r'\b((?:thunk_)?FUN_rom_[0-9a-f]{6})\s*\(',f['text']))
    calls[f['name']]=cs
    for c in cs: callers[c].add(f['name'])
for f in fs:
    f['ncalls']=len(calls[f['name']]); f['ncallers']=len([c for c in callers.get(f['name'],())])
    f['globs']=sorted(set(re.findall(r'_?DAT_ram_([0-9a-f]{4})',f['text'])))
    f['lits']=sorted(set(re.findall(r'\b(0x[0-9a-f]{3,5})\b',f['text'])))[:8]
json.dump(fs,open('funcs.json','w'),ensure_ascii=False)
print(len(fs))
# address regions histogram
regions=collections.Counter()
for f in fs:
    if f['addr'] is None: regions['none']+=1
    else: regions['%04x'%(f['addr']>>8<<8)]+=1
for k in sorted(regions): print(k, regions[k])
