#ifndef _991CNX_UI_H
#define _991CNX_UI_H
#include "types.h"

/* 主界面与菜单：主 UI 循环、菜单绘制、模式切换（17 个函数） */

int lcd_request_refresh(void);
int ui_update(void);
int cursor_draw_list(void);
int table_key_dispatch(uintptr_t _a2, int _a1);
int cursor_home_ui(void);
int matrix_cell_draw(void);
char is_two_byte_char(char* p);
int setup_enter_E(void);
byte key_is_14_02(void);
ushort cell_pos_calc(byte _a1, byte _a2);
int table_add_row(ushort _a1);
int nop_rt(void);
char stats_cell_key(void);
int table_count_update(byte delta);
int stats_head_draw(void);
undefined2 mul_signed16(undefined2 a, undefined2 b);
int draw_table_row(void);

#endif
