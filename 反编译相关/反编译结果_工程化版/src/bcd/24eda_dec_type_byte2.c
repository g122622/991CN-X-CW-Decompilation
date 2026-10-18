/*
 * BCD 浮点库 / 24eda_dec_type_byte2.c
 * 地址范围: 0x24EDA - 0x24EDA
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 返回 BCD 类型字节
 * @addr 0x24EDA
 * @module bcd
 * @proto byte dec_type_byte2(undefined2* p)
 * @confidence strong
 * @note 返回 BCD 类型字节：>0x0E 时取 p[1]。
 * @tag bcd
 */
byte dec_type_byte2(undefined2* p)

{
  byte bVar1;
  
  bVar1 = bcd_type(p);
  if (0xe < bVar1) {
    bVar1 = p[1];
  }
  return bVar1;
}

