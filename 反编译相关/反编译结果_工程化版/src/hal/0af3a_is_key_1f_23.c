/*
 * 硬件抽象层 / 0af3a_is_key_1f_23.c
 * 地址范围: 0x0AF3A - 0x0AF3A
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 当前键 0xD10E 为 0x1F 或 0x23 时返回 1（高字节携带原键码）
 * @addr 0x0AF3A
 * @module hal
 * @proto ushort is_key_1f_23(void)
 * @confidence likely
 * @note 当前键 0xD10E 为 0x1F 或 0x23 时返回 1（高字节携带原键码）。
 * @tag kbd
 */
ushort is_key_1f_23(void)

{
  byte bVar1;
  byte bVar2;
  
  bVar1 = (byte)input_key;
  bVar2 = (byte)((ushort)input_key >> 8);
  if ((bVar1 != 0x1f || (bool)(bVar2 + 4) != bVar1 < 0x1f) &&
     (bVar1 != 0x23 || (bool)(bVar2 + 4) != bVar1 < 0x23)) {
    return (ushort)bVar2 << 8;
  }
  return CONCAT11(bVar2,1);
}

