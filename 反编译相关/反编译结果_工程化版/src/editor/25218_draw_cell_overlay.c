/*
 * 输入编辑器 / 25218_draw_cell_overlay.c
 * 地址范围: 0x25218 - 0x25218
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 编辑模式 1 时按 0x2ABEE 得到的行宽换算坐标，调用 0x848A 叠加绘制单元格字…
 * @addr 0x25218
 * @module editor
 * @proto void draw_cell_overlay(ushort pos, ushort code)
 * @confidence likely
 * @note 编辑模式 1 时按 0x2ABEE 得到的行宽换算坐标，调用 0x848A 叠加绘制单元格字符。
 * @tag editor
 */
int draw_cell_overlay(ushort pos, ushort code)

{
  ushort uVar1;
  byte bVar2;
  
  if ((((edit_state == '\x01') && (uVar1 = editor_pos_limit(), uVar1 <= pos)) &&
      (bVar2 = (byte)pos - (byte)dec_accum8,
      uVar1 = (ushort)(byte)(((char)(pos >> 8) - (char)((ushort)dec_accum8 >> 8)) -
                            ((byte)pos < (byte)dec_accum8)) - (ushort)(bVar2 < 0xbf),
      (uVar1 & 0x100) != 0 || bVar2 == 0xbf && (char)uVar1 == '\0')) &&
     ((dec_regY_1 <= code && ((byte)(code - dec_regY_1) < 0x40)))) {
    px_set(CONCAT11(code - dec_regY_1,bVar2));
  }
  return 0;
}

