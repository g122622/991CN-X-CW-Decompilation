/*
 * 显示驱动 / 0b58e_addr_norm.c
 * 地址范围: 0x0B58E - 0x0BD52
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 把显示地址规范化
 * @addr 0x0B58E
 * @module display
 * @proto undefined* addr_norm(undefined* p)
 * @confidence strong
 * @note 把显示地址规范化：0xD139==0 时返回 0xF800 区地址，否则返回 0xDDD4 区地址。
 * @tag display
 */
undefined* addr_norm(undefined* p)

{
  undefined *puVar1;
  
  if (draw_target == '\0') {
    puVar1 = (undefined *)0xf800;
    if (0xf7ff < p) {
      return 0xf801;
    }
  }
  else {
    puVar1 = &screen_fb;
    if ((0xddd3 < p) && (puVar1 = (undefined *)0xe3d4, p < 0xe3d5)) {
      return 0xe301;
    }
  }
  return (ushort)puVar1 & 0xff00;
}



// 字符串长度计算 (is_two_byte_char)
// 地址: 0x26226

/**
 * @brief 把 0..99 的 n 转成显示串
 * @addr 0x0BD52
 * @module display
 * @proto void fmt_print_number(byte n)
 * @confidence strong
 * @note 把 0..99 的 n 转成显示串：十位前插 0xFB 符号，数字字符基址为 0x30（0xD137==0x0E 时为
 *       0x44）。
 * @tag ui display
 */
int fmt_print_number(byte n)

{
  char *pcVar1;
  char cVar2;
  byte bVar3;
  short unaff_ER14;
  
  pcVar1 = (char *)frame_enter();
  bVar3 = 0;
  cVar2 = '0';
  if (cur_line == '\x0e') {
    cVar2 = 'D';
  }
  if (n / 10 != 0) {
    *(undefined *)(unaff_ER14 + -8) = 0xfb;
    *(byte *)(unaff_ER14 + -7) = n / 10 + cVar2;
    bVar3 = 2;
  }
  *(undefined *)((ushort)bVar3 + unaff_ER14 + -8) = 0xfb;
  *(byte *)((ushort)(byte)(bVar3 + 1) + unaff_ER14 + -8) = n % 10 + 0x30;
  *(undefined *)((ushort)(byte)(bVar3 + 2) + unaff_ER14 + -8) = 0;
  strcat_checked(pcVar1,(char *)(unaff_ER14 + -8));
  frame_leave();
  return 0;
}

