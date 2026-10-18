/*
 * 输入编辑器 / 0f716_is_line_start.c
 * 地址范围: 0x0F716 - 0x0FB98
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 判断光标是否位于行首（宏键/输入状态相关）
 * @addr 0x0F716
 * @module editor
 * @proto byte is_line_start(void)
 * @confidence likely
 * @note 判断光标是否位于行首（宏键/输入状态相关）。
 * @tag editor
 */
byte is_line_start(void)

{
  char cVar1;
  byte bVar2;
  undefined uVar3;
  
  cVar1 = is_stat_edit3();
  if ((cVar1 == '\0') ||
     (((bVar2 = key_hist_lo(), bVar2 != 0xe && (bVar2 = key_hist_lo(), bVar2 != 0xf)) &&
      ((menu_io == '\0' || ((calc_mode & 0x40) == 0)))))) {
    uVar3 = 0;
  }
  else {
    uVar3 = 1;
  }
  return uVar3;
}

/**
 * @brief 把 token 转成可显示文本（0xD4C8），再按行缓冲排版并绘制
 * @addr 0x0FB98
 * @module editor
 * @proto int draw_token_text(byte* tok)
 * @confidence likely
 * @note 把 token 转成可显示文本（0xD4C8），再按行缓冲排版并绘制；复杂 token 走 0x2035C。
 * @tag editor
 */
int draw_token_text(byte* _a1)

{
  byte *pbVar1;
  ushort uVar2;
  undefined2 uVar3;
  short unaff_ER14;
  
  pbVar1 = (byte *)frame_enter();
  uVar2 = token_at(pbVar1);
  text_clear_panel(uVar2,(byte *)(unaff_ER14 + -0x22));
  uVar3 = token_class((char *)pbVar1);
  if ((char)uVar3 == '\x01') {
    font_class_of(*pbVar1);
  }
  frame_leave();
  return 0;
}

