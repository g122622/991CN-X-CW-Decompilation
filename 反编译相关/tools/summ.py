import analyze, sys
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
    elif n.startswith('thunk_FUN_ram_'): f['addr']=None
    else:
        try: f['addr']=int(n.split('_')[-1],16)
        except: f['addr']=None
lo,hi=int(sys.argv[1],16),int(sys.argv[2],16)
for f in fs:
    if f['addr'] is not None and lo<=f['addr']<=hi:
        ram=sorted(set(('_' if '_DAT' in f['text'] else '')+'DAT_ram_'+x for x in __import__('re').findall(r'DAT_ram_([0-9a-f]{4})',f['text'])))
        print('\n##### %06X %s %s(%s)'%(f['addr'],f['ret'],f['name'],f['args']))
        print(f['text'])
