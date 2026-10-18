/*
 * BCD 浮点库 / 1eb9e_dec_pow_then_div.c
 * 地址范围: 0x1EB9E - 0x1EB9E
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief a 先复制到局部，与外部参数做 0x1CF90（乘方）再以 0x1CF54 收尾
 * @addr 0x1EB9E
 * @module bcd
 * @proto int dec_pow_then_div(undefined2* a)
 * @confidence likely
 * @note a 先复制到局部，与外部参数做 0x1CF90（乘方）再以 0x1CF54 收尾。
 * @tag bcd
 */
int dec_pow_then_div(undefined2* a)

{
  undefined2 *puVar1;
  short unaff_ER14;
  
  puVar1 = (undefined2 *)frame_enter();
  dec_copy((undefined2 *)(unaff_ER14 + -10),a);
  dec_bin_pow((undefined2 *)(unaff_ER14 + -10),*(undefined2 **)(unaff_ER14 + 0x10));
  dec_bin_mul(puVar1,(undefined2 *)(unaff_ER14 + -10));
  frame_leave();
  return 0;
}

