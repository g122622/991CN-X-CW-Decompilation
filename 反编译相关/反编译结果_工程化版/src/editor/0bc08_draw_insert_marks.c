/*
 * 输入编辑器 / 0bc08_draw_insert_marks.c
 * 地址范围: 0x0BC08 - 0x0C3EC
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 行内插入态标记
 * @addr 0x0BC08
 * @module editor
 * @proto void draw_insert_marks(char ch)
 * @confidence likely
 * @note 行内插入态标记：0xD015==1 时按光标列计算三处位置并调用 0x1F9D4/0xEA36 绘制插入符。
 * @tag editor
 */
int draw_insert_marks(char ch)

{
  char cVar1;
  short sVar2;
  short unaff_ER14;
  
  sVar2 = frame_enter();
  if (edit_state == '\x01') {
    cursor_column_calc((char *)(unaff_ER14 + -1));
    *(char *)(unaff_ER14 + -1) = *(char *)(unaff_ER14 + -1) + -2;
    cVar1 = *(char *)(unaff_ER14 + -2) + '\x02';
    *(char *)(unaff_ER14 + -2) = cVar1;
    draw_cell_at(sVar2 + 4,CONCAT11(*(undefined *)(unaff_ER14 + -1),cVar1));
    draw_cell_at(sVar2 + 5,CONCAT11(*(undefined *)(unaff_ER14 + -2),ch));
    draw_cell_at(sVar2 + 3,CONCAT11(*(undefined *)(unaff_ER14 + -1),ch));
    draw_insert_cursor(CONCAT11(1,*(undefined *)(unaff_ER14 + -2)));
    draw_insert_cursor((ushort)*(byte *)(unaff_ER14 + -1));
  }
  frame_leave();
  return 0;
}

/**
 * @brief 转换保护
 * @addr 0x0C002
 * @module editor
 * @proto int convert_guard(void)
 * @confidence likely
 * @note 转换保护：无比例键/历史时把编辑行转入极坐标（0x1D39E），成功后进入0x1FC30 的显示编辑器。
 * @tag editor
 */
int convert_guard(void)

{
  int cVar1;
  byte bVar2;
  char **ppcVar3;
  undefined2 uVar4;
  undefined2 *puVar5;
  short unaff_ER14;
  
  ppcVar3 = (char **)frame_enter();
  cVar1 = ratio_key_check();
  if (((cVar1 == '\0') && (bVar2 = key_hist_hi(), bVar2 == 0)) && (key_hist_d == '\0')) {
    puVar5 = (undefined2 *)ppcVar3[1];
    dec_copy_rev((undefined2 *)(unaff_ER14 + -0x14),puVar5);
    uVar4 = dec_cmp((undefined2 *)(unaff_ER14 + -10),puVar5);
    if (((char)uVar4 != '\x01') &&
       (cVar1 = dec_to_polar((ushort *)(unaff_ER14 + -0x14)), cVar1 != '\0')) {
      display_editor(ppcVar3);
    }
  }
  frame_leave();
  return 0;
}

/**
 * @brief 行内插入态标记（"h" 分支偏移 2/12）
 * @addr 0x0C0DA
 * @module editor
 * @proto void draw_insert_marks2(byte* p)
 * @confidence likely
 * @note 行内插入态标记（"h" 分支偏移 2/12）：0xBC08 的配套绘制。
 * @tag editor
 */
int draw_insert_marks2(byte* p)

{
  short *psVar1;
  short sVar2;
  short unaff_ER14;
  
  psVar1 = (short *)frame_enter();
  if (*(char *)(unaff_ER14 + 0x12) == 'h') {
    *(char *)(psVar1 + 1) = *(char *)(psVar1 + 1) + '\x02';
    sVar2 = *psVar1 + 0xc;
  }
  else {
    *(char *)(psVar1 + 1) = *(char *)(psVar1 + 1) + '\x03';
    sVar2 = *psVar1 + 0xe;
  }
  *psVar1 = sVar2;
  if (edit_state == '\x01') {
    cursor_column_calc((char *)(unaff_ER14 + -1));
    if (*(char *)(unaff_ER14 + 0x12) == 'h') {
      *(char *)(unaff_ER14 + -1) = *(char *)(unaff_ER14 + -1) + '\x01';
      cell_draw_pair(p + 2,*(undefined2 *)(unaff_ER14 + -2));
      cell_draw_pair((*psVar1 + p) - 3,*(undefined2 *)(unaff_ER14 + -2));
    }
    else {
      stat_edit_entry((*psVar1 + p) - 3);
      edit_value_pick(p + 6U);
      draw_cell_overlay(p + 6U,*(char *)(unaff_ER14 + -1) + 1);
      edit_value_pick(p + 4);
      edit_value_pick(p + 3);
    }
  }
  frame_leave();
  return 0;
}

/**
 * @brief token 平衡检查
 * @addr 0x0C1C6
 * @module editor
 * @proto void token_balance_check(void)
 * @confidence likely
 * @note token 平衡检查：类别 2 时求 0x1ECFA(0) 偏移后的串长，为 0 则调用0xD0AE 扫描括号平衡。
 * @tag editor
 */
int token_balance_check(void)

{
  char cVar1;
  byte bVar2;
  byte *pbVar3;
  undefined2 uVar4;
  
  pbVar3 = (byte *)frame_enter();
  cVar1 = get_token_class(pbVar3);
  if (cVar1 == '\x02') {
    bVar2 = token_scan(0);
    uVar4 = is_two_byte_char((char *)(pbVar3 + bVar2));
    if ((char)uVar4 == '\0') {
      check_balanced_expr();
    }
  }
  frame_leave();
  return 0;
}

/**
 * @brief 按当前键值/光标状态返回编辑行类型码（4 为普通行等）
 * @addr 0x0C2FA
 * @module editor
 * @proto ushort get_line_kind(void)
 * @confidence likely
 * @note 按当前键值/光标状态返回编辑行类型码（4 为普通行等）。
 * @tag editor
 */
ushort get_line_kind(void)

{
  char cVar1;
  undefined2 uVar2;
  int sVar3;
  undefined uVar4;
  
  cVar1 = '\0';
  uVar4 = 0;
  is_up_down((char)input_key,(char)((ushort)input_key >> 8));
  if ((((cVar1 == '\0') || (cVar1 = '\0', uVar4 = 0, is_line_start(), cVar1 == '\0')) ||
      (cVar1 = '\0', uVar4 = 0, is_modifier_3_5(), cVar1 == '\0')) || (key_hist_d == '\0')) {
    uVar2 = CONCAT11(uVar4,4);
  }
  else {
    key_flag_bit7();
    sVar3 = key_is_14_02();
    if ((char)sVar3 == '\0') {
      if (history_cursor == '\0') {
        sVar3 = key_flag_clear();
      }
      else {
        history_cursor = history_cursor + -1;
        sVar3 = CONCAT11((char)((ushort)sVar3 >> 8),history_cursor);
      }
    }
    else {
      history_cursor = history_cursor + '\x01';
    }
    uVar2 = CONCAT11((char)((ushort)sVar3 >> 8),3);
  }
  return uVar2;
}

/**
 * @brief 初始化 12 字节编辑上下文（0xD180/0xD16C/0xD111/0x29D94/0x…
 * @addr 0x0C3EC
 * @module editor
 * @proto void edit_ctx_init(byte* ctx)
 * @confidence strong
 * @note 初始化 12
 *       字节编辑上下文（0xD180/0xD16C/0xD111/0x29D94/0x28576/0xF716/0x20D10）。
 * @tag editor
 */
int edit_ctx_init(byte* ctx)

{
  undefined uVar1;
  
  memzero((undefined *)ctx,0xc);
  *(undefined *)(ctx + 2) = 1;
  *ctx = &input_buf;
  ctx[1] = 0xd16c;
  *(undefined *)(ctx + 3) = calc_mode;
  uVar1 = is_special_editing();
  *(undefined *)((short)ctx + 7) = uVar1;
  uVar1 = is_math_io();
  *(undefined *)(ctx + 4) = uVar1;
  uVar1 = is_line_start();
  *(undefined *)((short)ctx + 9) = uVar1;
  uVar1 = stat_view_event();
  *(undefined *)(ctx + 5) = uVar1;
  return 0;
}

