#ifndef _991CNX_BOOT_H
#define _991CNX_BOOT_H
#include "types.h"

/* 启动与主流程：复位向量、启动代码、主循环与全局初始化（14 个函数） */

void reset_vector(void);
int bad_entry(void);
char ram_check(void);
int boot_lcd_init(void);
void reset_handler(void);
int reset_entry(int _a1);
int call_mode_ee2a(void);
int main_loop(int _a1, int _a2, int _a3);
int boot_splash(uintptr_t _a2, int _a1);
int ram_clear_all(void);
int boot_key_scan(undefined2 k);
undefined2 boot_key_poll(void);
int fw_main(byte* input);
int restart_loop(void);

#endif
