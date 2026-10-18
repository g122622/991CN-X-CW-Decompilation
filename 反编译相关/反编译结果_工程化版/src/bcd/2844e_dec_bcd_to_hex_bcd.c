/*
 * BCD 浮点库 / 2844e_dec_bcd_to_hex_bcd.c
 * 地址范围: 0x2844E - 0x2844E
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 对 0xD05A 指向的 3 组 10 字节 BCD 依次转成十六进制
 * @addr 0x2844E
 * @module bcd
 * @proto int dec_bcd_to_hex_bcd(void)
 * @confidence likely
 * @note 对 0xD05A 指向的 3 组 10 字节 BCD 依次转成十六进制。
 * @tag bcd
 */
int dec_bcd_to_hex_bcd(void)

{
  undefined2 *puVar1;
  undefined2 *puVar2;
  short unaff_ER14;
  
  puVar1 = (undefined2 *)frame_enter();
  puVar2 = puVar1;
  dec_copy((undefined2 *)(unaff_ER14 + -10),puVar1);
  dec_entry_w(puVar1,puVar2);
  puVar2 = (undefined2 *)(unaff_ER14 + -10);
  dec_copy(puVar1 + 5,puVar2);
  dec_entry_z(puVar1 + 5,puVar2);
  puVar2 = (undefined2 *)(unaff_ER14 + -10);
  dec_copy(puVar1 + 10,puVar2);
  dec_entry_y(puVar1 + 10,puVar2);
  frame_leave();
  return 0;
}

