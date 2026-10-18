#ifndef _991CNX_TEXTLIB_H
#define _991CNX_TEXTLIB_H
#include "types.h"

/* 行打印与文本：多行文本、错误页、行显示（27 个函数） */

int draw_line_diag(char row, ushort str);
int table_edit_main(void);
int table_key_router(undefined2 k);
int stat_analysis(uintptr_t _a2, int _a1);
int stat_edit_entry(uintptr_t _a2, int _a1);
int menu_open(char which);
byte* memcpy_bytes(byte* dst, byte* src, ushort len);
int menu_edit_entry(undefined2 key);
int skip_token_loops(void);
int menu_enter_off(void);
int mode_switch_entry(char m, int _a2);
undefined2 set_window_visible(undefined2 er0, char flag);
int stat_func_call(uintptr_t _a2, int _a1);
byte is_noop_mode(undefined2 k);
int stat_cell_edit(int _a1);
ushort token_sym_code(ushort tok);
int table_calc_draw(uintptr_t _a2, int _a1);
uchar line_col_count(void);
int wizard_flow(void);
ushort kdf_chain_42ba(byte _a1);
int menu_layer(uintptr_t _a2, int _a1);
int mode_state_init(char m, char flag);
int table_commit(uintptr_t _a2, int _a1);
int key_28_handler(void);
int var_menu(void);
int refresh_list(undefined2 er0);
int call_246b4(undefined2 er0, undefined2 er2);

#endif
