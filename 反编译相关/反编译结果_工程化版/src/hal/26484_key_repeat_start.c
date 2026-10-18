/*
 * 硬件抽象层 / 26484_key_repeat_start.c
 * 地址范围: 0x26484 - 0x26484
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 按键重复初始化（清重复计数）
 * @addr 0x26484
 * @module hal
 * @proto void key_repeat_start(void)
 * @confidence likely
 * @note 按键重复初始化（清重复计数）。
 * @tag kbd
 */
int key_repeat_start(void)

{
  edit_state2 = 1;
  input_init();
  return 0;
}

