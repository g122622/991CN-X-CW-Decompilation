#ifndef _991CNX_KBD_MENU_H
#define _991CNX_KBD_MENU_H
#include "types.h"

/* 键盘与菜单：键位映射、菜单循环、自检入口（19 个函数） */

int draw_mode_header(void);
int stat_edit_move(undefined2* v);
byte menu_item_kind(byte idx);
byte is_stat_mode(void);
int list_toggle(void);
int mode_switch_refresh(void);
int draw_prompt_pair(void);
int set_sel_mode(undefined2 v);
int str_emit_lparen_or_1D3D(undefined2 v, byte c);
int mode_paint(void);
int token_class_scan(byte* _a1);
int key_state_chain(void);
int menu_scroll(void);
int set_list_mode(void);
short memcpy160(byte* dst, byte* src);
int list_entry_fetch(uintptr_t _a2, int _a1);
char is_mode_high(void);
int enter_mode_18(void);
int index_wrap(byte v);

#endif
