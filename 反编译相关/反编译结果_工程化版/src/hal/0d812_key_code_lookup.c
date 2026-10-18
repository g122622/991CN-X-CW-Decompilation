/*
 * 硬件抽象层 / 0d812_key_code_lookup.c
 * 地址范围: 0x0D812 - 0x0D812
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 按扩展键码查 ROM 表（0xFC4E..0xFC5F 段）得到键值
 * @addr 0x0D812
 * @module hal
 * @proto undefined2 key_code_lookup(ushort k)
 * @confidence strong
 * @note 按扩展键码查 ROM 表（0xFC4E..0xFC5F 段）得到键值。
 * @tag kbd
 */
undefined2 key_code_lookup(ushort k)

{
  ushort uVar1;
  byte bVar2;
  byte bVar3;
  
  bVar2 = (byte)k;
  bVar3 = (byte)((ushort)k >> 8);
  if ((((bVar3 - 0xfc) - (ushort)(bVar2 < 0x4e) & 0x100) == 0) &&
     (uVar1 = (bVar3 - 0xfc) - (ushort)(bVar2 < 0x5f),
     (uVar1 & 0x100) != 0 || bVar2 == 0x5f && (char)uVar1 == '\0')) {
    return *(undefined2 *)(k * 2 + -0x7cce);
  }
  return 0;
}

