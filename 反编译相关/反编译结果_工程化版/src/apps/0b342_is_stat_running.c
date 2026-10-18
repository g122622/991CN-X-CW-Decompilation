/*
 * 应用模式 / 0b342_is_stat_running.c
 * 地址范围: 0x0B342 - 0x0B810
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief STAT 模式 0xD114 为 0x13/0x14 时返回 1
 * @addr 0x0B342
 * @module apps
 * @proto char is_stat_running(void)
 * @confidence strong
 * @note STAT 模式 0xD114 为 0x13/0x14 时返回 1。
 * @tag mode
 */
char is_stat_running(void)

{
  if ((edit_state2 != '\x13') && (edit_state2 != '\x14')) {
    return 0;
  }
  return 1;
}

/**
 * @brief RATIO 模式（0xD111 == 0x88）下恢复输入区
 * @addr 0x0B7D6
 * @module apps
 * @proto void ratio_input_restore(void)
 * @confidence likely
 * @note RATIO 模式（0xD111 == 0x88）下恢复输入区：保存 0xD180 到 0xD248、按 Math
 *       设置拷贝历史。
 * @tag mode
 */
int ratio_input_restore(void)

{
  char cVar1;
  char *pcVar2;
  
  if (calc_mode == -0x78) {
    input_init();
    strcpy_checked(&input_buf,(char *)0xd248);
    cVar1 = is_math_io();
    if ((cVar1 != '\0') && (pcVar2 = (char *)input_history_ptr(), pcVar2 != (char *)0x0)) {
      strcpy_checked(pcVar2,&input_buf);
    }
    ratio_reset();
  }
  return 0;
}

/**
 * @brief 把 p 拷贝到输入区 0xD180 并调用 0x25258（回放保存）
 * @addr 0x0B800
 * @module apps
 * @proto void ratio_input_save(char* p)
 * @confidence strong
 * @note 把 p 拷贝到输入区 0xD180 并调用 0x25258（回放保存）。
 * @tag mode
 */
int ratio_input_save(char* p)

{
  byte in_PSW;
  
  if ((in_PSW >> 6 & 1) != 1) {
    strcpy_checked(p,&input_buf);
  }
  ratio_reset();
  return 0;
}

/**
 * @brief 0xD111==0x4A，推测为方程/函数模式
 * @addr 0x0B810
 * @module apps
 * @proto void mode_4a_eqn_loop(byte* input)
 * @confidence strong
 * @note 【0xD111==0x4A，推测为方程/函数模式】主循环：反复调用 0xDCFA 直到退出键 0x24。
 * @tag mode
 */
int mode_4a_eqn_loop(byte* input)

{
  do {
    table_loop(input);
  } while ((byte)input_key != 0x24 ||
           (bool)((char)((ushort)input_key >> 8) + '\x04') != (byte)input_key < 0x24);
  return 0;
}

