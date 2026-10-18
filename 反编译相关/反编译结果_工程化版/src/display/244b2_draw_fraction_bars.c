/*
 * 显示驱动 / 244b2_draw_fraction_bars.c
 * 地址范围: 0x244B2 - 0x244B2
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 按 0xD112 绘制分数/等号结构（0x152D/0x155D/0x158D 等固定位置）
 * @addr 0x244B2
 * @module display
 * @proto void draw_fraction_bars(void)
 * @confidence likely
 * @note 按 0xD112 绘制分数/等号结构（0x152D/0x155D/0x158D 等固定位置）。
 * @tag display
 */
int draw_fraction_bars(void)

{
  cur_line = 10;
  draw_char_fast(0x152d,0x3a);
  draw_char_fast(0x155d,0x3d);
  draw_char_fast(0x158d,0x3a);
  if (sub_mode == '\x01') {
    draw_char_fast(0x1587,0x58);
    draw_hline_animated(0x1f93,0x1fb6);
  }
  else if (sub_mode == '\x02') {
    draw_char_fast(0x15b1,0x58);
    draw_hline_animated(0x1f69,0x1f8c);
  }
  draw_hline_animated(0x1f09,0x1f2c);
  draw_hline_animated(0x1f33,0x1f56);
  return 0;
}

