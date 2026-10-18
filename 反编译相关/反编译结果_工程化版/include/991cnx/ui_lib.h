#ifndef _991CNX_UI_LIB_H
#define _991CNX_UI_LIB_H
#include "types.h"

/* 界面辅助库：高地址段的菜单/编辑器辅助（21 个函数） */

int draw_list_item(byte* label);
int token_replace_all(char* s);
byte find_table_row2(char c);
int stat_edit_loop(uintptr_t _a2, int _a1);
int matrix_switch_cell(ushort sel);
int stat_cell_edit2(uintptr_t _a2, int _a1);
int mode_menu_draw(uintptr_t _a2, int _a1);
int draw_splash_32(void);
int stat_state_reset(void);
int matrix_cell_scale(undefined2 k);
int menu_cursor_reset(void);
short wait_valid_key(char mask);
int draw_item_by_mode(ushort i);
int var_list_draw(void);
int matrix_set_dims(byte n);
int table_row_paint(uintptr_t _a2, int _a1);
byte key_is_11_04(void);
int stat_edit_redraw(void);
byte is_ws_scan(byte* p);
byte token_scan(byte mode);
int var_slot_write(uintptr_t _a2, int _a1);

#endif
