/*
 * 显示驱动 / 1ee0c_draw_cursor_line.c
 * 地址范围: 0x1EE0C - 0x1EE0C
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 按行缓冲与 0xD137 光标位置绘制行/列指示
 * @addr 0x1EE0C
 * @module display
 * @proto void draw_cursor_line(void)
 * @confidence likely
 * @note 按行缓冲与 0xD137 光标位置绘制行/列指示。
 * @tag display
 */
int draw_cursor_line(void)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  short *psVar4;
  byte bVar5;
  
  psVar4 = (short *)frame_enter();
  bVar3 = cur_line;
  bVar1 = (byte)((ushort)cur_line + *psVar4);
  bVar5 = (byte)((ushort)cur_line + *psVar4 >> 8);
  bVar2 = bVar5 - (bVar1 < 0x41);
  if ((byte)((byte)((bVar2 ^ bVar5) & ~bVar2) >> 7 ^ (char)bVar2 < '\0' |
            (bVar1 == 0x41 && bVar2 == 0)) != 1) {
    scroll_screen(cur_line);
    bVar2 = (byte)*psVar4;
    *psVar4 = CONCAT11((char)((ushort)*psVar4 >> 8) - (bVar2 < bVar3),bVar2 - bVar3);
    _DAT_ram_d157 = _DAT_ram_d157 - bVar3;
  }
  if ((calc_mode == '\x02') &&
     (bVar3 = (byte)*psVar4, bVar1 = (byte)((ushort)*psVar4 >> 8), bVar2 = bVar1 - (bVar3 < 0xf),
     (byte)((byte)((bVar2 ^ bVar1) & ~bVar2) >> 7 ^ (char)bVar2 < '\0' |
           (bVar3 == 0xf && bVar2 == 0)) != 0)) {
    *psVar4 = 0xf;
  }
  frame_leave();
  return 0;
}

