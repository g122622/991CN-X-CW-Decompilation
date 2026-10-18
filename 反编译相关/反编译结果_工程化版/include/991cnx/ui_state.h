#ifndef _991CNX_UI_STATE_H
#define _991CNX_UI_STATE_H
#include "types.h"

/* 界面状态机：按键过滤、界面状态、光标/模式判定（14 个函数） */

short return_zero(void);
char* input_variant(undefined* out);
byte return_false(void);
char is_ratio_mode(void);
short stat_cell_addr(ushort rc, char col);
undefined2 stat_cell_addr_ex(ushort rc, short* addr);
byte stat_table_base(ushort* out);
char stat_table_width(void);
undefined2 stat_table_clear(byte page);
int memzero(byte* dst, ushort len);
short var_get_value(byte idx, byte* dst);
ushort base_clear(ushort v, undefined* p);
ushort base_submode(void);
ushort stack_depth(void);

#endif
