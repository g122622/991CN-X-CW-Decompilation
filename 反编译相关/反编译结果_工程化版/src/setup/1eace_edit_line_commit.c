/*
 * 设置与模式逻辑 / 1eace_edit_line_commit.c
 * 地址范围: 0x1EACE - 0x1EB6E
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 编辑行提交（0x2682E 后按状态刷新，0x94DA/0xD3A2/0x2AA0A 调用）
 * @addr 0x1EACE
 * @module setup
 * @proto void edit_line_commit(void)
 * @confidence likely
 * @note 编辑行提交（0x2682E 后按状态刷新，0x94DA/0xD3A2/0x2AA0A 调用）。
 * @tag editor
 */
int edit_line_commit(uintptr_t _a2, int _a1)

{
  byte bVar1;
  char cVar2;
  byte bVar3;
  byte bVar4;
  byte *pbVar5;
  ushort uVar6;
  short unaff_ER14;
  
  pbVar5 = (byte *)frame_enter();
  draw_result_line();
  if (edit_state == '\x01') {
    cVar2 = input_cols2();
    bVar3 = *(char *)(unaff_ER14 + 0x10) - cVar2;
    *(byte *)(unaff_ER14 + 0x10) = bVar3;
    bVar4 = bVar3 - dec_regY_1;
    bVar1 = -(bVar3 < dec_regY_1);
    bVar3 = (bVar1 + 1) - (bVar4 < 0xf2);
    if (((byte)((byte)((bVar3 ^ bVar1) & (~bVar3 ^ 0xff)) >> 7 ^ (char)bVar3 < '\0') != 1) &&
       (bVar3 = bVar1 - (bVar4 < 0x3f),
       (byte)((byte)((bVar3 ^ bVar1) & ~bVar3) >> 7 ^ (char)bVar3 < '\0' |
             (bVar4 == 0x3f && bVar3 == 0)) != 0)) {
      bVar3 = line_col_count();
      do {
        uVar6 = editor_pos_limit();
        if (uVar6 <= _a1) {
          bVar3 = (byte)_a1 - (byte)dec_accum8;
          uVar6 = (ushort)(byte)(((char)((uint32_t)_a1 >> 8) - (char)((ushort)dec_accum8 >> 8)) -
                                ((byte)_a1 < (byte)dec_accum8)) - (ushort)(bVar3 < 0xbf);
          if ((uVar6 & 0x100) != 0 || bVar3 == 0xbf && (char)uVar6 == '\0') {
            draw_text4x(CONCAT11(bVar4,bVar3),pbVar5);
          }
          break;
        }
        _a1 = _a1 + bVar3;
        if (*pbVar5 == 4) {
          pbVar5 = pbVar5 + 1;
          _a1 = _a1 - 2;
        }
        pbVar5 = char_ptr_next(pbVar5);
      } while (*pbVar5 != 0);
    }
  }
  frame_leave();
  return 0;
}

/**
 * @brief 返回 (0xD114 & 0x10) == 0 && 0x20D10() == 0
 * @addr 0x1EB6E
 * @module setup
 * @proto char is_stat_edit3(void)
 * @confidence likely
 * @note 返回 (0xD114 & 0x10) == 0 && 0x20D10() == 0：STAT 编辑状态判断（另一个位）。
 * @tag stat
 */
char is_stat_edit3(void)

{
  int cVar1;
  
  if (((edit_state2 & 0x10) == 0) && (cVar1 = stat_view_event(), cVar1 == '\0')) {
    return 1;
  }
  return 0;
}

