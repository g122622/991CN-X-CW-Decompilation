/*
 * 硬件抽象层 / 239e6_key_hi_plus.c
 * 地址范围: 0x239E6 - 0x23EE0
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 返回 CONCAT11(k>>8 + 0xD143, 0xB5 < (0xD143 + k)…
 * @addr 0x239E6
 * @module hal
 * @proto ushort key_hi_plus(ushort k)
 * @confidence likely
 * @note 返回 CONCAT11(k>>8 + 0xD143, 0xB5 < (0xD143 + k))。
 * @tag kbd
 */
ushort key_hi_plus(ushort k)

{
  return CONCAT11((char)((ushort)_DAT_ram_d143 + (ushort)k >> 8),
                  0xb5 < (ushort)_DAT_ram_d143 + (ushort)k);
}

/**
 * @brief 0xD116 bit6 置位且 k 非 0/0x23 时返回 k，否则返回 CONCAT11…
 * @addr 0x23EE0
 * @module hal
 * @proto ushort key_filter_d116(ushort k)
 * @confidence likely
 * @note 0xD116 bit6 置位且 k 非 0/0x23 时返回 k，否则返回 CONCAT11(k>>8,1)。
 * @tag kbd
 */
ushort key_filter_d116(ushort k)

{
  char cVar1;
  
  cVar1 = (char)((ushort)k >> 8);
  if ((((key_modifiers & 0x40) == 0) ||
      ((byte)k != 0x23 || (bool)cVar1 != (byte)k < 0x23)) && (k != 0)) {
    return k & 0xff00;
  }
  return CONCAT11(cVar1,1);
}

