/*
 * BCD 浮点库 / 2a0ea_bcd_print_u8.c
 * 地址范围: 0x2A0EA - 0x2A0EA
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 把 8 位无符号数 n 转成十进制字符串（省略前导 0）写入 ER0 指向的显示串
 * @addr 0x2A0EA
 * @module bcd
 * @proto void bcd_print_u8(byte n)
 * @confidence strong
 * @note 把 8 位无符号数 n 转成十进制字符串（省略前导 0）写入 ER0 指向的显示串。
 * @tag bcd display
 */
int bcd_print_u8(byte n)

{
  bool bVar1;
  char *pcVar2;
  short unaff_ER14;
  
  pcVar2 = (char *)frame_enter();
  bVar1 = n / 10 != 0;
  if (bVar1) {
    *(byte *)(unaff_ER14 + -4) = n / 10 + 0x30;
  }
  *(byte *)((ushort)bVar1 + unaff_ER14 + -4) = n % 10 + 0x30;
  *(undefined *)((ushort)(byte)(bVar1 + 1) + unaff_ER14 + -4) = 0;
  strcat_checked(pcVar2,(char *)(unaff_ER14 + -4));
  frame_leave();
  return 0;
}

