/*
 * BCD 浮点库 / 23a1c_dec_round_to.c
 * 地址范围: 0x23A1C - 0x23A1C
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief a 按 n 位舍入（n>=0xF 时按 0xF），调用 0x1D6A4
 * @addr 0x23A1C
 * @module bcd
 * @proto void dec_round_to(undefined2* a, undefined n)
 * @confidence likely
 * @note a 按 n 位舍入（n>=0xF 时按 0xF），调用 0x1D6A4。
 * @tag bcd
 */
int dec_round_to(undefined2* a, undefined n)

{
  ushort uVar1;
  undefined uVar2;
  
  if (n < 0xf) {
    uVar1 = dec_set_special(a,n);
    uVar2 = (undefined)(uVar1 >> 8);
  }
  else {
    uVar1 = dec_set_special(a,0xf);
    uVar2 = (undefined)(uVar1 >> 8);
    *(byte *)((short)a + 1) = n;
  }
  return CONCAT11(uVar2,n);
}

