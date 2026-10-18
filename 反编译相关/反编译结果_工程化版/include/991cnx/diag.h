#ifndef _991CNX_DIAG_H
#define _991CNX_DIAG_H
#include "types.h"

/* 自检与诊断：DIAG 画面、LCD/RAM/按键自检（24 个函数） */

int diag_entry(void);
int diag_entry_c4(void);
int get_serial_num(short er0);
ushort diagnostic_mode(ushort a);
undefined2 delay_1(undefined2 v);
undefined2 delay_10(undefined2 v);
int diagnostic(byte b);
int diag_check_key(void);
int diag_fill_55aa(void);
int diag_fill_pattern(byte b);
int diag_scr_ckb2_ws(void);
int diag_scr_version(void);
int diag_print_ver(void);
int diag_print_pd(void);
ushort diag_checksum(void);
int store_reg_to_stack(void);
ushort diag_calc_checksum(void);
byte diag_key_test(void);
char hex_byte(byte b);
int draw_hex_byte(byte b);
byte bit_reverse_index(byte b);
int diag_flush(void);
int diag_entry_eb05(void);
int diag_8_keytest(void);

#endif
