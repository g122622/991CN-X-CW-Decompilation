/*
 * 硬件抽象层 / 09cf6_wait_arrow_exit.c
 * 地址范围: 0x09CF6 - 0x0A014
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 等待按键直到方向键（0xFC2D/0xFC30）或取消（0xFC26/0xFC27）
 * @addr 0x09CF6
 * @module hal
 * @proto undefined wait_arrow_exit(void)
 * @confidence strong
 * @note 等待按键直到方向键（0xFC2D/0xFC30）或取消（0xFC26/0xFC27）。
 * @tag kbd
 */
undefined wait_arrow_exit(void)

{
  byte bVar1;
  char extraout_R1;
  
  do {
    bVar1 = input_is_empty();
    if ((bVar1 == 0x2d && (bool)(extraout_R1 + '\x04') == bVar1 < 0x2d) ||
       (bVar1 == 0x30 && (bool)(extraout_R1 + '\x04') == bVar1 < 0x30)) {
      return 1;
    }
  } while ((bVar1 != 0x26 || (bool)(extraout_R1 + '\x04') != bVar1 < 0x26) &&
          (bVar1 != 0x27 || (bool)(extraout_R1 + '\x04') != bVar1 < 0x27));
  return 0;
}

/**
 * @brief 键码 0x23 或 0 时返回 1
 * @addr 0x0A014
 * @module hal
 * @proto short key_is_23(short key)
 * @confidence verified
 * @note 键码 0x23 或 0 时返回 1。
 * @tag kbd
 */
short key_is_23(short key)

{
  char cVar1;
  
  cVar1 = (char)((ushort)key >> 8);
  if (((byte)key != 0x23 || (bool)cVar1 != (byte)key < 0x23) && (key != 0)) {
    return key & 0xff00;
  }
  return CONCAT11(cVar1,1);
}

