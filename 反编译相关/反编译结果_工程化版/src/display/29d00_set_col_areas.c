/*
 * 显示驱动 / 29d00_set_col_areas.c
 * 地址范围: 0x29D00 - 0x29D00
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 按第 idx 列设置两个显示区域的起点（0xB11/0x0Bxx 与 0x30 列）
 * @addr 0x29D00
 * @module display
 * @proto void set_col_areas(void)
 * @confidence likely
 * @note 按第 idx 列设置两个显示区域的起点（0xB11/0x0Bxx 与 0x30 列）。
 * @tag display
 */
int set_col_areas(void)

{
  char cVar1;
  ushort uVar2;
  undefined2 uVar3;
  
  uVar2 = frame_enter();
  uVar3 = mul16(8,uVar2 & 0xff);
  cVar1 = (char)uVar3 + ((char)uVar2 + -1) * '\x02' + '\n';
  draw_vline2(0xb11,CONCAT11(0xc0,cVar1));
  draw_vline2(CONCAT11(0xb,(char)(uVar2 >> 8) * '*' + '\x14'),CONCAT11(0x30,cVar1));
  frame_leave();
  return 0;
}

