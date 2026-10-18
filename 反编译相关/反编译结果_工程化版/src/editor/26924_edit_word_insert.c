/*
 * 输入编辑器 / 26924_edit_word_insert.c
 * 地址范围: 0x26924 - 0x26A40
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 把编辑词插入 0xD144 编辑行（0xAF74/0xD4C8/0x15E98/0x2A88…
 * @addr 0x26924
 * @module editor
 * @proto int edit_word_insert(byte* src)
 * @confidence likely
 * @note 把编辑词插入 0xD144 编辑行（0xAF74/0xD4C8/0x15E98/0x2A886/0x2A9EA 校验）。
 * @tag editor
 */
int edit_word_insert(byte* src)

{
  char cVar1;
  byte *pbVar2;
  undefined2 uVar3;
  byte *pbVar4;
  ushort uVar5;
  
  pbVar2 = prev_char_ptr(input_ptr,src);
  pbVar4 = pbVar2;
  if (pbVar2 != (byte *)0x0) {
    uVar3 = token_class((char *)pbVar2);
    cVar1 = (char)uVar3;
    pbVar4 = (byte *)is_frac_sep(cVar1);
    if (((char)pbVar4 != '\0') || (cVar1 == '\x06')) {
LAB_rom_026946:
      return CONCAT11((char)((ushort)pbVar4 >> 8),1);
    }
    pbVar4 = (byte *)is_list_render_ctx(cVar1);
    if ((char)pbVar4 == '\0') {
      uVar5 = token_at(pbVar2);
      pbVar4 = (byte *)token_is_complex(uVar5,src);
      if ((char)pbVar4 != '\0') goto LAB_rom_026946;
    }
  }
  return (ushort)pbVar4 & 0xff00;
}

/**
 * @brief 编辑器初始化
 * @addr 0x26A40
 * @module editor
 * @proto void input_init(void)
 * @confidence strong
 * @note 编辑器初始化：清修饰键状态、清输入区/历史游标、设置行号，调用 0x2BD42/0x7E7E。
 * @tag editor
 */
int input_init(void)

{
  bool bVar1;
  byte bVar2;
  char cVar3;
  undefined *puVar4;
  
  bVar2 = frame_enter();
  bVar1 = (bVar2 & 0x80) == 0;
  _DAT_ram_d13c = 0;
  key_modifiers = 1;
  key_history_flags = 0;
  if (bVar1) {
    memzero(&input_buf,200);
    history_cursor = 0;
    puVar4 = (undefined *)input_history_ptr();
    if (puVar4 != (undefined *)0x0) {
      *puVar4 = 0;
      input_saved = 0;
    }
  }
  history_key = 0;
  _DAT_ram_d157 = 1;
  cur_line = prev_line;
  cVar3 = is_special_editing();
  if (cVar3 == '\0') {
    if ((bVar2 & 0xf) != 0) {
      clear_screen();
      stored_a = 0;
      stored_b = 0;
    }
    input_reset();
  }
  else {
    cur_line = '\x0e';
    _DAT_ram_d157 = 0x32;
    cVar3 = is_edit_state_6_9();
    if (cVar3 == '\0') {
      fb_clear_rows(0x32);
    }
    else {
      cVar3 = is_stat_edit4();
      if (cVar3 == '\0') {
        if (edit_state2 == '\x06') {
          _DAT_ram_d157 = stat_state * '\x10' + 1;
        }
        else if (edit_state2 == '\t') {
          _DAT_ram_d157 = list_col * '\x10' + 1;
        }
      }
      else if (menu_io == '\0') {
        cur_line = prev_line;
        if (prev_line == '\n') {
          cVar3 = ((_DAT_ram_d5eb - list_page) + '\x01') * '\n';
        }
        else {
          cVar3 = ((_DAT_ram_d5eb - list_page) + '\x01') * '\x10';
        }
        _DAT_ram_d157 = cVar3 + 1;
      }
      if (bVar1) {
        cursor_visible = 3;
        draw_list_scroller2((ushort)_DAT_ram_d157 << 8,CONCAT11(cur_line,0xc0));
        cursor_visible = 0;
      }
    }
  }
  hl_line = 0;
  hl_col = 1;
  redraw_line_syntax();
  saved_line = cur_line;
  hl_col2 = cur_line;
  hl_row2 = 0;
  key_hist_clear0(0);
  disp_mode = 0;
  _DAT_ram_d15a = 0;
  _DAT_ram_d15b = 0;
  key_hist_c = 0;
  input_ptr = &input_buf;
  _DAT_ram_d166 = 3;
  input_active = 0;
  frame_leave();
  return 0;
}

