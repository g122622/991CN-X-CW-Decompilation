/*
 * BCD 浮点库 / 0b1c4_dec_abs_diff.c
 * 地址范围: 0x0B1C4 - 0x0B1C4
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 计算 |0xD00E - v|（16 位，DAS 链）
 * @addr 0x0B1C4
 * @module bcd
 * @proto undefined2 dec_abs_diff(undefined2 v)
 * @confidence strong
 * @note 计算 |0xD00E - v|（16 位，DAS 链）。
 * @tag bcd
 */
undefined2 dec_abs_diff(undefined2 v)

{
  ushort uVar1;
  
  uVar1 = dec_temp_a;
  if (dec_temp_a <= v) {
    uVar1 = v;
    v = dec_temp_a;
  }
  return CONCAT11(((char)(uVar1 >> 8) - (char)(v >> 8)) - ((byte)uVar1 < (byte)v),
                  (byte)uVar1 - (byte)v);
}

