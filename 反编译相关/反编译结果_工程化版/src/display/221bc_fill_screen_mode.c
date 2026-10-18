/*
 * 显示驱动 / 221bc_fill_screen_mode.c
 * 地址范围: 0x221BC - 0x221BC
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 以 (1<<8)|mode 调用 fill_screen 后调用 0x22502 做后续处理
 * @addr 0x221BC
 * @module display
 * @proto void fill_screen_mode(byte mode)
 * @confidence likely
 * @note 以 (1<<8)|mode 调用 fill_screen 后调用 0x22502 做后续处理。
 * @tag display
 */
int fill_screen_mode(byte mode)

{
  fill_screen(CONCAT11(1,mode));
  diag_flush();
  return 0;
}

