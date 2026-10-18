import json,re
fs=json.load(open('funcs.json'))
tab = {'FUN_rom_00f1a8':'memset','FUN_rom_008fb8':'memzero','FUN_rom_00d070':'strcpy','FUN_rom_009d72':'memcpy','FUN_rom_009462':'smart_strcpy','FUN_rom_00959c':'smart_strcat','FUN_rom_00b5ba':'byte_strlen','FUN_rom_007eac':'fill_screen','FUN_rom_007f00':'buffer_clear','FUN_rom_007f1a':'set_display_line','FUN_rom_007f58':'set_display_position','FUN_rom_007fa0':'set_display_area','FUN_rom_0086e0':'buf1_to_buf2','FUN_rom_0086f8':'render_e3d4','FUN_rom_008704':'flush_screen','FUN_rom_00a15a':'refresh_display','FUN_rom_0082ec':'char_print_1byte','FUN_rom_0082f6':'char_print','FUN_rom_0084d8':'char_get_14','FUN_rom_0085b8':'char_get_l14','FUN_rom_008c4a':'line_print','FUN_rom_008c6c':'smallprint','FUN_rom_008c88':'line_print_col0','FUN_rom_008c90':'line_print_Col3','FUN_rom_0096be':'waitkey','FUN_rom_0096fc':'read_key','FUN_rom_0094da':'delay'}
old={v:k for k,v in tab.items()}
by={}
for f in fs:
    if f['name'].startswith('thunk_'): continue
    if f['name'] in old:
        f=dict(f); f['name']=old[f['name']]
    by[f['name']]=f
import sys
for k in sys.argv[1:]:
    f=by.get(k)
    print('#'*10, k, '=>', tab.get(k,''), f['args'] if f else 'MISSING')
    if f: print(f['text'][:3000])
