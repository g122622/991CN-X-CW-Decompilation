/*
 * 硬件抽象层 / 1e668_keycode_norm.c
 * 地址范围: 0x1E668 - 0x1EDCC
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 把扩展键码规范化
 * @addr 0x1E668
 * @module hal
 * @proto ushort keycode_norm(ushort k)
 * @confidence likely
 * @note 把扩展键码规范化：低于 0xFC10 或不在 0xFC19.. 区间时返回 0xFC00。
 * @tag kbd
 */
ushort keycode_norm(ushort k)

{
  ushort uVar1;
  undefined2 uVar2;
  
  if ((k < 0xfc10) ||
     (uVar1 = ((k >> 8) - 0xfc) - (ushort)((byte)k < 0x19),
     (uVar1 & 0x100) == 0 && ((byte)k != 0x19 || (char)uVar1 != '\0'))) {
    uVar2 = 0xfc00;
  }
  else {
    uVar2 = 0xfc01;
  }
  return uVar2;
}

/**
 * @brief k/k2 组合为 0x3E、0x1E、0x1F 时返回 1（方向/运算键判定）
 * @addr 0x1EDCC
 * @module hal
 * @proto char is_key_3e_1e_1f(byte k, byte k2)
 * @confidence likely
 * @note k/k2 组合为 0x3E、0x1E、0x1F 时返回 1（方向/运算键判定）。
 * @tag kbd
 */
char is_key_3e_1e_1f(byte k, byte k2)

{
  if (((k != 0x3e || (bool)(k2 + '\x04') != k < 0x3e) &&
      (k != 0x1e || (bool)(k2 + '\x04') != k < 0x1e)) &&
     (k != 0x1f || (bool)(k2 + '\x04') != k < 0x1f)) {
    return 0;
  }
  return 1;
}

