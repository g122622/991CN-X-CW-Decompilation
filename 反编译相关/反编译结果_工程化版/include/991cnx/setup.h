#ifndef _991CNX_SETUP_H
#define _991CNX_SETUP_H
#include "types.h"

/* 设置与模式逻辑：SETUP、显示格式、变量列表、模式相关逻辑（21 个函数） */

undefined2 set_key_edge(undefined2 er0, char flag);
byte is_alpha_reg(byte ch);
byte wait_release(byte* _a1);
byte key_vartype(byte* key, byte* type);
byte key_is_1a_04(void);
int stats_matrix_draw(void);
ushort next_size_3n1(ushort limit);
int matrix_mode_key(uintptr_t _a2, int _a1);
byte table_row_count(void);
int stats_table_draw(void);
int table_cell_key(void);
int table_nav_row(byte* p);
int copy_prefixed(char* src);
int menu_close(void);
undefined2 set_cursor_visible(undefined2 er0, char flag);
char is_display_busy(void);
int table_insert_row(void);
int input_key_filter(void);
int memmove_range(ushort to);
int edit_line_commit(uintptr_t _a2, int _a1);
char is_stat_edit3(void);

#endif
