/*
 * 输入编辑器 / 2aa0a_finish_edit_line.c
 * 地址范围: 0x2AA0A - 0x2AC54
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 把编辑行转成文本（0x208F2）并按需截断，再调用 0x1EACE 收尾
 * @addr 0x2AA0A
 * @module editor
 * @proto int finish_edit_line(undefined2 er0)
 * @confidence likely
 * @note 把编辑行转成文本（0x208F2）并按需截断，再调用 0x1EACE 收尾。
 * @tag editor
 */
int finish_edit_line(undefined2 er0)

{
  int cVar1;
  ushort uVar2;
  short unaff_ER14;
  
  uVar2 = frame_enter();
  cVar1 = text_clear_panel(uVar2,(byte *)(unaff_ER14 + -0x22));
  if (*(char *)(unaff_ER14 + 0x12) != '\0') {
    *(undefined *)((ushort)(byte)(cVar1 - 1) + unaff_ER14 + -0x22) = 0;
  }
  edit_line_commit(er0);
  frame_leave();
  return 0;
}

/**
 * @brief 返回编辑行可容纳的字符数 = 0xD156 + 0xD00C
 * @addr 0x2ABEE
 * @module editor
 * @proto ushort editor_pos_limit(void)
 * @confidence likely
 * @note 返回编辑行可容纳的字符数 = 0xD156 + 0xD00C。
 * @tag editor
 */
ushort editor_pos_limit(void)

{
  return (ushort)history_key + dec_accum8;
}

/**
 * @brief 编辑模式下把数值 n 按正负号打印（-1 时打印 n-1 的补码）
 * @addr 0x2AC54
 * @module editor
 * @proto void print_signed(char n)
 * @confidence strong
 * @note 编辑模式下把数值 n 按正负号打印（-1 时打印 n-1 的补码）。
 * @tag editor
 */
int print_signed(char n)

{
  if (edit_state == '\x01') {
    table_value_edit(CONCAT11(1,n));
    table_value_edit((ushort)(byte)((uintptr_t)n - 1));
  }
  return 0;
}

