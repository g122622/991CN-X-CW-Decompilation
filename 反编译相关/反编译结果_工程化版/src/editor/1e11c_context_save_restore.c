/*
 * 输入编辑器 / 1e11c_context_save_restore.c
 * 地址范围: 0x1E11C - 0x1E76E
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 编辑上下文保存/恢复（0x26A40 与 +7 标志）
 * @addr 0x1E11C
 * @module editor
 * @proto int context_save_restore(undefined2 p)
 * @confidence likely
 * @note 编辑上下文保存/恢复（0x26A40 与 +7 标志）。
 * @tag editor
 */
int context_save_restore(undefined2 p)

{
  char cVar1;
  byte extraout_R1;
  short sVar2;
  char *pcVar3;
  undefined extraout_R1_00;
  
  input_init();
  if (*(char *)((short)(uintptr_t)p + 7) == '\0') {
    expr_state_clear();
    if (*(char *)((uintptr_t)p + 3) == -0x78) {
      if (stat_state == '\0') {
        if ((history_recall == '\x01') && ((ratio_flags & 1) != 0)) {
          memzero((undefined *)0xd84c,200);
        }
        else {
          memzero((undefined *)0xd248,200);
        }
      }
      else {
        strcpy_checked(*p,(char *)0xd248);
        cVar1 = is_math_io();
        if ((cVar1 != '\0') && (pcVar3 = (char *)input_history_ptr(), pcVar3 != (char *)0x0)) {
          strcpy_checked(pcVar3,&input_buf);
        }
        stat_state = '\0';
      }
      clear_screen();
    }
    stat_state_reset();
    sVar2 = CONCAT11(extraout_R1_00,1);
  }
  else {
    key_mod_clear();
    render_editor_line((short)p[1]);
    *(undefined *)((uintptr_t)p + 2) = 1;
    sVar2 = (ushort)extraout_R1 << 8;
  }
  return sVar2;
}

/**
 * @brief 按 0xD015 状态修改/打印数值（0x2AC54 的正负号版本）
 * @addr 0x1E76E
 * @module editor
 * @proto void table_value_edit(undefined2 v)
 * @confidence likely
 * @note 按 0xD015 状态修改/打印数值（0x2AC54 的正负号版本）。
 * @tag editor
 */
int table_value_edit(undefined2 v)

{
  char cVar1;
  char cVar2;
  short sVar3;
  ushort uVar4;
  undefined2 uVar5;
  char cVar6;
  short unaff_ER14;
  
  sVar3 = frame_enter();
  cVar2 = (char)((ushort)v >> 8);
  uVar4 = 1;
  cVar6 = '\x01';
  if (cVar2 != '\0') {
    uVar4 = 0xffff;
    cVar6 = -1;
  }
  *(ushort *)(unaff_ER14 + -2) = sVar3 - 6U;
  uVar5 = mul16(uVar4,6);
  cVar1 = (char)uVar5 + (char)v;
  edit_value_pick(sVar3 - 6U);
  edit_value_pick(*(short *)(unaff_ER14 + -2) + 1);
  if (cVar2 != '\0') {
    edit_value_pick(*(short *)(unaff_ER14 + -2) + 2);
  }
  sVar3 = *(short *)(unaff_ER14 + -2);
  uVar4 = sVar3 + 0xc;
  stat_edit_entry(uVar4);
  if (cVar2 == '\0') {
    stat_edit_entry(uVar4);
  }
  cVar2 = cVar1 + cVar6 * -2;
  draw_cell_at(uVar4,CONCAT11(cVar2,cVar1));
  draw_cell_overlay(sVar3 + 0xb,cVar2 + cVar6);
  frame_leave();
  return 0;
}

