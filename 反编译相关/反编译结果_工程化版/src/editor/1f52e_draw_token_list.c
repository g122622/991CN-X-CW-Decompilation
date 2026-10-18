/*
 * 输入编辑器 / 1f52e_draw_token_list.c
 * 地址范围: 0x1F52E - 0x1FC30
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 按 token 类别（2/4 等）逐个绘制列表项
 * @addr 0x1F52E
 * @module editor
 * @proto void draw_token_list(byte* tok)
 * @confidence likely
 * @note 按 token 类别（2/4 等）逐个绘制列表项。
 * @tag editor
 */
int draw_token_list(byte* _a1)

{
  char cVar1;
  byte bVar2;
  byte *pbVar3;
  undefined2 uVar4;
  byte bVar5;
  byte bVar6;
  
  pbVar3 = (byte *)frame_enter();
  cVar1 = get_token_class(pbVar3);
  if ((cVar1 == '\x02') || (cVar1 == '\x04')) {
    bVar6 = 0;
    if (cVar1 == '\x04') {
      bVar6 = 2;
    }
    for (bVar5 = 0; bVar5 <= bVar6; bVar5 = bVar5 + 1) {
      bVar2 = token_scan(bVar5);
      uVar4 = is_two_byte_char((char *)(pbVar3 + bVar2));
      if ((char)uVar4 == '\0') break;
    }
  }
  frame_leave();
  return 0;
}

/**
 * @brief 输入行编辑器（1.6KB，0xC438 调用）
 * @addr 0x1F8C8
 * @module editor
 * @proto int input_line_editor(byte* p)
 * @confidence likely
 * @note 输入行编辑器（1.6KB，0xC438 调用）。
 * @tag editor
 */
int input_line_editor(byte* p)

{
  int cVar1;
  byte bVar2;
  undefined2 uVar3;
  short unaff_ER14;
  
  frame_enter();
  cVar1 = wrap_12d3a(p);
  *(undefined *)(unaff_ER14 + -1) = 0;
  if (cVar1 == '\0') {
    if (sub_mode == '\x01') {
      *(undefined *)(unaff_ER14 + -2) = 2;
      *(undefined2 *)(unaff_ER14 + -6) = 0x6598;
      *(undefined2 *)(unaff_ER14 + -4) = 0x64bc;
    }
    else {
      *(undefined *)(unaff_ER14 + -2) = 3;
      *(undefined2 *)(unaff_ER14 + -6) = 0x65e0;
      *(undefined2 *)(unaff_ER14 + -4) = 0x64d6;
    }
LAB_rom_01f914:
    cur_line = 10;
    fill_screen(0x400);
    show_press_ac();
    draw_target = 0;
    cVar1 = edit_field_draw(p);
    if (cVar1 != '\x01') {
      fb_alt_flush();
      draw_target = 1;
      timer_base_restore();
      show_press_ac();
      while( true ) {
        uVar3 = input_is_empty();
        bVar2 = (byte)uVar3;
        cVar1 = (char)((ushort)uVar3 >> 8);
        if (bVar2 == 1 && (bool)(cVar1 + '\x04') == (bVar2 == 0)) goto LAB_rom_01f8e6;
        if (bVar2 == 0x1c && (bool)(cVar1 + '\x04') == bVar2 < 0x1c) {
          decrement_field(unaff_ER14 + -6);
          goto LAB_rom_01f914;
        }
        if (bVar2 == 0x1d && (bool)(cVar1 + '\x04') == bVar2 < 0x1d) break;
        if ((bVar2 == 0x1f && (bool)(cVar1 + '\x04') == bVar2 < 0x1f) ||
           (bVar2 == 0x26 && (bool)(cVar1 + '\x04') == bVar2 < 0x26)) goto LAB_rom_01f8e6;
        beep();
      }
      edit_field_step(unaff_ER14 + -6);
      goto LAB_rom_01f914;
    }
    draw_target = 1;
  }
  else {
    wait_valid_key('\x03');
  }
LAB_rom_01f8e6:
  frame_leave();
  return 0;
}

/**
 * @brief 在 (pos, row) 处绘制单元格字符（0x2ABEE 行宽约束）
 * @addr 0x1F9D4
 * @module editor
 * @proto void draw_cell_at(ushort pos, ushort code)
 * @confidence strong
 * @note 在 (pos, row) 处绘制单元格字符（0x2ABEE 行宽约束）。
 * @tag editor
 */
int draw_cell_at(ushort pos, ushort code)

{
  ushort uVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  
  bVar5 = (byte)((ushort)code >> 8);
  bVar2 = (byte)code;
  if (((edit_state == '\x01') && (uVar1 = editor_pos_limit(), uVar1 <= pos)) &&
     (bVar3 = (byte)pos - (byte)dec_accum8,
     uVar1 = (ushort)(byte)(((char)(pos >> 8) - (char)((ushort)dec_accum8 >> 8)) -
                           ((byte)pos < (byte)dec_accum8)) - (ushort)(bVar3 < 0xbf),
     (uVar1 & 0x100) != 0 || bVar3 == 0xbf && (char)uVar1 == '\0')) {
    bVar4 = bVar2;
    if (bVar5 < bVar2) {
      bVar4 = bVar5;
      bVar5 = bVar2;
    }
    if (dec_regY_1 <= bVar5) {
      if (bVar4 < dec_regY_1) {
        bVar4 = 0;
      }
      else {
        bVar4 = bVar4 - dec_regY_1;
        if (0x3f < bVar4) {
          return 0;
        }
      }
      bVar5 = bVar5 - dec_regY_1;
      if (0x3f < bVar5) {
        bVar5 = 0x3f;
      }
      draw_vline(CONCAT11(bVar4,bVar3),(ushort)bVar5);
    }
  }
  return 0;
}

/**
 * @brief 0xD155 ← (char)p − 0xD144，返回 p（历史游标相对位置）
 * @addr 0x1FBD2
 * @module editor
 * @proto char history_cursor_rel(char p)
 * @confidence likely
 * @note 0xD155 ← (char)p − 0xD144，返回 p（历史游标相对位置）。
 * @tag editor
 */
char history_cursor_rel(char p)

{
  history_cursor = (char)p - input_ptr;
  return p;
}

/**
 * @brief 显示编辑器（0xD116=0x80，0xD9BC 后 0x20E5A 复制等）
 * @addr 0x1FC30
 * @module editor
 * @proto void display_editor(byte** p)
 * @confidence likely
 * @note 显示编辑器（0xD116=0x80，0xD9BC 后 0x20E5A 复制等）。
 * @tag editor
 */
int display_editor(byte** p)

{
  int cVar1;
  int sVar2;
  
  key_modifiers = 0x80;
  sVar2 = menu_get_key('\x03');
  set_input_key(sVar2);
  expr_state_clear();
  cVar1 = kbd_input_handle();
  if (cVar1 == '\x01') {
    history_cursor = strline_len(*p);
    sVar2 = input_history_ptr();
    if (sVar2 != 0) {
      sVar2 = CONCAT11((char)((ushort)sVar2 >> 8),history_cursor);
      input_saved = history_cursor;
    }
  }
  else {
    sVar2 = context_save_restore(p);
  }
  return CONCAT11((char)((ushort)sVar2 >> 8),1);
}

