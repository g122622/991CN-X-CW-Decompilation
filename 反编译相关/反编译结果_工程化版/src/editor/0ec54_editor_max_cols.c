/*
 * 输入编辑器 / 0ec54_editor_max_cols.c
 * 地址范围: 0x0EC54 - 0x0F3E4
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 返回当前显示行对应的最大列数（10 或 14）
 * @addr 0x0EC54
 * @module editor
 * @proto byte editor_max_cols(void)
 * @confidence strong
 * @note 返回当前显示行对应的最大列数（10 或 14）。
 * @tag editor
 */
byte editor_max_cols(void)

{
  undefined uVar1;
  
  uVar1 = 0xe;
  if (cur_line == '\n') {
    uVar1 = 10;
  }
  return uVar1;
}

/**
 * @brief 判断是否为变量名
 * @addr 0x0EC64
 * @module editor
 * @proto ushort is_var_token(byte* p)
 * @confidence likely
 * @note 判断是否为变量名。
 * @tag editor
 */
ushort is_var_token(byte* p)

{
  if (*p == 0x40) {
    return 1;
  }
  if (*p < 0x42) {
    return 0;
  }
  if (0x49 < *p) {
    return 0;
  }
  return 1;
}

/**
 * @brief 定位表达式结尾
 * @addr 0x0EC86
 * @module editor
 * @proto void skip_expr_end(byte* flag)
 * @confidence likely
 * @note 定位表达式结尾。
 * @tag editor
 */
int skip_expr_end(byte* flag)

{
  byte *pbVar1;
  char cVar2;
  char cVar3;
  byte *pbVar4;
  undefined2 uVar5;
  char cVar6;
  short unaff_ER14;
  
  pbVar4 = (byte *)frame_enter();
  cVar6 = '\x01';
  *(undefined *)(unaff_ER14 + -1) = 1;
  *flag = 0;
  pbVar1 = input_ptr;
  if (input_ptr != pbVar4) {
    for (pbVar4 = prev_char_ptr(input_ptr,pbVar4); pbVar4 != (byte *)0x0;
        pbVar4 = prev_char_ptr(pbVar1,pbVar4)) {
      uVar5 = token_class((char *)pbVar4);
      cVar2 = (char)uVar5;
      if ((cVar6 == '\x01') && (cVar2 == '\t')) {
        *(char *)(unaff_ER14 + -1) = *(char *)(unaff_ER14 + -1) + '\x01';
      }
      else if ((cVar6 == '\x01') && ((cVar2 == '\b' || (cVar2 == '\n')))) {
        *(char *)(unaff_ER14 + -1) = *(char *)(unaff_ER14 + -1) + -1;
        if (*(char *)(unaff_ER14 + -1) == '\0') {
          *flag = 1;
          break;
        }
      }
      else {
        cVar3 = is_frac_sep(cVar2);
        if (cVar3 == '\0') {
          cVar3 = is_v2_02(cVar2);
          if (cVar3 == '\0') {
            if ((cVar2 == '\x04') && (cVar6 == '\x01')) break;
          }
          else {
            cVar6 = cVar6 + -1;
            if (cVar6 == '\0') break;
          }
        }
        else {
          cVar6 = cVar6 + '\x01';
        }
      }
      if (pbVar4 == pbVar1) break;
    }
  }
  frame_leave();
  return 0;
}

/**
 * @brief 从 ROM 0xD84C 复制回编辑行（0xD180 或其影子缓冲），提示符模式下走 0xA…
 * @addr 0x0ED28
 * @module editor
 * @proto int restore_input_line(void)
 * @confidence likely
 * @note 从 ROM 0xD84C 复制回编辑行（0xD180 或其影子缓冲），提示符模式下走 0xADCE。
 * @tag editor
 */
int restore_input_line(void)

{
  int cVar1;
  byte **ppbVar2;
  byte *pbVar3;
  undefined *puVar4;
  
  ppbVar2 = (byte **)frame_enter();
  pbVar3 = (byte *)input_history_ptr();
  *ppbVar2 = pbVar3;
  puVar4 = (undefined *)0xd84c;
  strcpy_checked(&input_buf,(char *)0xd84c);
  cVar1 = is_math_io();
  if (cVar1 == '\0') {
    strcpy_checked((char *)*ppbVar2,&input_buf);
  }
  else {
    cVar1 = menu_layer(puVar4);
    if (cVar1 != '\0') {
      buffer_transfer(*ppbVar2);
    }
  }
  frame_leave();
  return 0;
}

/**
 * @brief 按 token 首字节高半字节分派绘制
 * @addr 0x0ED7C
 * @module editor
 * @proto int draw_tokens(byte* tok)
 * @confidence strong
 * @note 按 token 首字节高半字节分派绘制：0→0x20710、2/8→0x2B4FC、4→0xE698，并做换行/截断。
 * @tag editor
 */
int draw_tokens(byte* tok)

{
  int bVar1;
  char cVar2;
  undefined2 *puVar3;
  ushort uVar4;
  undefined uVar5;
  short unaff_ER14;
  
  puVar3 = (undefined2 *)frame_enter();
  uVar5 = 0;
  if ((_DAT_ram_d128 != '\0') && ((_DAT_ram_d166 & 2) != 0)) {
    uVar5 = 1;
  }
  bVar1 = *(byte *)tok >> 4;
  if (bVar1 == 0) {
LAB_rom_00edb8:
    draw_token_plain(tok,puVar3,*(byte *)(unaff_ER14 + 0x12),uVar5);
  }
  else {
    if (bVar1 == 2) {
LAB_rom_00edcc:
      cVar2 = token_to_text(tok);
      if (cVar2 == '\n') goto LAB_rom_00edb8;
    }
    else {
      if (bVar1 != 4) {
        if (bVar1 != 8) {
          *(undefined *)puVar3 = 0;
          goto LAB_rom_00edb4;
        }
        goto LAB_rom_00edcc;
      }
      editor_format((char *)puVar3);
    }
    bVar1 = skip_token_loops();
    uVar4 = strlen((char *)puVar3);
    if ((ushort)bVar1 + (ushort)*(byte *)(unaff_ER14 + 0x12) < uVar4) {
      draw_token_plain(tok,puVar3,*(byte *)(unaff_ER14 + 0x12),uVar5);
    }
  }
LAB_rom_00edb4:
  frame_leave();
  return 0;
}

/**
 * @brief 判断当前模式（0xD111）与状态（0xD114/0xD116）下是否允许回放历史记录
 * @addr 0x0F3A6
 * @module editor
 * @proto byte can_recall(void)
 * @confidence likely
 * @note 判断当前模式（0xD111）与状态（0xD114/0xD116）下是否允许回放历史记录。
 * @tag editor
 */
byte can_recall(void)

{
  if (((key_modifiers & 0x40) == 0) && ((edit_state2 & 0x80) == 0)) {
    if (calc_mode == '\x02') {
      return 1;
    }
    if (((calc_mode == '\x03') || (calc_mode == '\x06')) || (calc_mode == '\a')) {
      if ((edit_state2 & 0x10) == 0) {
        return 1;
      }
    }
    else {
      if (calc_mode == -0x77) {
        return 1;
      }
      if (calc_mode == -0x3f) {
        return 1;
      }
      if (calc_mode == -0x3c) {
        return 1;
      }
    }
  }
  return 0;
}

/**
 * @brief 以 er0 为源调用 0xC9F2（编辑行复制）
 * @addr 0x0F3E4
 * @module editor
 * @proto int copy_edit_line(undefined2 er0)
 * @confidence likely
 * @note 以 er0 为源调用 0xC9F2（编辑行复制）。
 * @tag editor
 */
int copy_edit_line(undefined2 er0)

{
  frame_enter();
  insert_word_at(er0);
  frame_leave();
  return 0;
}

