#ifndef _991CNX_DIAG_H
#define _991CNX_DIAG_H
#include "types.h"

/* 自检与诊断：DIAG 画面、LCD/RAM/按键自检（23 个函数） */

int diag_entry(void);
int diag_entry_c4(void);
ushort diag_main(ushort a);
undefined2 delay_1(undefined2 v);
undefined2 delay_10(undefined2 v);
int diag_test(byte b);
int diag_ram_test(void);
int diag_fill_55aa(void);
int diag_fill_pattern(byte b);
int draw_menu_aa(void);
int draw_menu_cancel(void);
int draw_menu_clear(void);
int draw_menu_status(void);
ushort diag_item(void);
int diag_print(void);
ushort diag_ram_sum(void);
byte diag_key_test(void);
char nibble_to_ascii(byte b);
int draw_hex_byte(byte b);
byte bit_reverse_index(byte b);
int diag_flush(void);
int diag_entry_eb05(void);
int self_test_display(void);

#endif
