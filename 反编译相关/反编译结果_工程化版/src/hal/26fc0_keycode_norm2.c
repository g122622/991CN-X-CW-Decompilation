/*
 * 硬件抽象层 / 26fc0_keycode_norm2.c
 * 地址范围: 0x26FC0 - 0x26FD8
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 低于 0xFC28 或超出 0xFC2C.. 时返回 0xFC00
 * @addr 0x26FC0
 * @module hal
 * @proto ushort keycode_norm2(ushort k)
 * @confidence likely
 * @note 低于 0xFC28 或超出 0xFC2C.. 时返回 0xFC00。
 * @tag kbd
 */
ushort keycode_norm2(ushort k)

{
  ushort uVar1;
  undefined2 uVar2;
  
  if ((k < 0xfc28) ||
     (uVar1 = ((k >> 8) - 0xfc) - (ushort)((byte)k < 0x2c),
     (uVar1 & 0x100) == 0 && ((byte)k != 0x2c || (char)uVar1 != '\0'))) {
    uVar2 = 0xfc00;
  }
  else {
    uVar2 = 0xfc01;
  }
  return uVar2;
}

/**
 * @brief p 以 0x19 开头且 0x1ECE2 判定为比较键时返回 CONCAT11(hi,1)
 * @addr 0x26FD8
 * @module hal
 * @proto ushort key_is_cmp(byte* p)
 * @confidence likely
 * @note p 以 0x19 开头且 0x1ECE2 判定为比较键时返回 CONCAT11(hi,1)。
 * @tag kbd
 */
ushort key_is_cmp(byte* p)

{
  ushort uVar1;
  
  uVar1 = CONCAT11((char)((ushort)p >> 8),*p);
  if ((*p == '\x19') && (uVar1 = is_ws_scan(p + 1), (char)uVar1 != '\0')) {
    uVar1 = CONCAT11((char)(uVar1 >> 8),1);
  }
  else {
    uVar1 = uVar1 & 0xff00;
  }
  return uVar1;
}

