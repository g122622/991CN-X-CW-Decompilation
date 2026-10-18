/*
 * 界面辅助库 / 1e058_draw_list_item.c
 * 地址范围: 0x1E058 - 0x1E842
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 绘制列表项
 * @addr 0x1E058
 * @module ui_lib
 * @proto void draw_list_item(byte* label)
 * @confidence likely
 * @note 绘制列表项：0x20F80/0x20F98 边框与 0x9E4C 文本，按标志高亮。
 * @tag ui
 */
int draw_list_item(byte* label)

{
  char *pcVar1;
  byte *pbVar2;
  short unaff_ER14;
  
  pcVar1 = (char *)frame_enter();
  if (*(char *)(unaff_ER14 + 0x10) == '\0') {
    str_emit_1D67();
    str_emit_lparen();
  }
  else {
    pbVar2 = label;
    str_emit_t();
    str_emit_1A(pcVar1,(char *)pbVar2);
  }
  append_number_str(label);
  if (*(char *)(unaff_ER14 + 0x10) == '\0') {
    str_emit_rparen();
  }
  else {
    str_emit_1B();
  }
  frame_leave();
  return 0;
}

/**
 * @brief 把编辑串中所有控制字节 3 的分量替换为 s（0x25388 查找、0x203C2/0x20…
 * @addr 0x1E0A0
 * @module ui_lib
 * @proto void token_replace_all(char* s)
 * @confidence likely
 * @note 把编辑串中所有控制字节 3 的分量替换为 s（0x25388 查找、0x203C2/0x203D6 复制）。
 * @tag strlib
 */
int token_replace_all(char* s)

{
  char *pcVar1;
  char *pcVar2;
  short unaff_ER14;
  
  pcVar1 = (char *)frame_enter();
  while (pcVar2 = strchr(pcVar1,'\x03'), pcVar2 != (char *)0x0) {
    *pcVar2 = '\0';
    strcpy_checked((char *)(unaff_ER14 + -0x24),pcVar2 + 1);
    strcat_checked(pcVar1,s);
    strcat_checked(pcVar1,(char *)(unaff_ER14 + -0x24));
  }
  frame_leave();
  return 0;
}

/**
 * @brief 在 0xD169 行表中查找字符 c（记录首次/再次命中）
 * @addr 0x1E0E2
 * @module ui_lib
 * @proto byte find_table_row2(char c)
 * @confidence likely
 * @note 在 0xD169 行表中查找字符 c（记录首次/再次命中）。
 * @tag app
 */
byte find_table_row2(char c)

{
  bool bVar1;
  undefined uVar2;
  byte bVar3;
  byte bVar4;
  
  uVar2 = (undefined)((ushort)c >> 8);
  bVar4 = 0;
  bVar1 = false;
  for (bVar3 = 1; (char)((bVar3 < input_active) << 7) < '\0'; bVar3 = bVar3 + 1) {
    uVar2 = (undefined)(((ushort)bVar3 << 3) >> 8);
    if (*(char *)(CONCAT11(uVar2,bVar3 << 3) + -0x241a) == (char)c) {
      bVar4 = bVar3;
      if (bVar1) break;
      bVar1 = true;
    }
  }
  return CONCAT11(uVar2,bVar4);
}

/**
 * @brief 统计编辑循环（0xD114=6、0xD115=1，0x1EBF8 刷新）
 * @addr 0x1E1B6
 * @module ui_lib
 * @proto void stat_edit_loop(void)
 * @confidence strong
 * @note 统计编辑循环（0xD114=6、0xD115=1，0x1EBF8 刷新）。
 * @tag app
 */
int stat_edit_loop(uintptr_t _a2, int _a1)

{
  char cVar1;
  short sVar2;
  undefined2 uVar3;
  byte bVar4;
  
  edit_state2 = 6;
  stat_state = '\x01';
  do {
    key_modifiers = 3;
    stat_edit_redraw();
    fb_flush();
    sVar2 = process_key((short)_a1);
    set_input_key(sVar2);
    uVar3 = key_is_extended(sVar2);
    if ((char)uVar3 == '\0') {
      bVar4 = (byte)sVar2;
      cVar1 = (char)((ushort)sVar2 >> 8);
      if (bVar4 == 0x1c && (bool)(cVar1 + '\x04') == bVar4 < 0x1c) {
        key_flag_bit7();
        if (stat_state == '\x01') {
          stat_state = '\x03';
        }
        else {
          stat_state = stat_state + -1;
          if (stat_state == '\x01') {
            key_flag_clear();
          }
        }
      }
      else if (bVar4 == 0x1d && (bool)(cVar1 + '\x04') == bVar4 < 0x1d) {
        key_flag_bit7();
        if (stat_state == '\x03') {
          stat_state = '\x01';
        }
        else {
          stat_state = stat_state + '\x01';
          if (stat_state == '\x03') {
            key_flag_clear();
          }
        }
      }
      else {
        if (bVar4 == 0x26 && (bool)(cVar1 + '\x04') == bVar4 < 0x26) {
          edit_state2 = 1;
          return 0;
        }
        if ((bVar4 == 0x2d && (bool)(cVar1 + '\x04') == bVar4 < 0x2d) ||
           (bVar4 == 0x30 && (bool)(cVar1 + '\x04') == bVar4 < 0x30)) {
          stat_state = 4;
          return 0;
        }
      }
    }
    else {
      table_copy(_a1);
      sVar2 = input_key;
    }
    if ((byte)sVar2 == 0x24 && (bool)((char)((ushort)sVar2 >> 8) + '\x04') == (byte)sVar2 < 0x24) {
      return 0;
    }
  } while( true );
}

/**
 * @brief 切换矩阵/统计单元
 * @addr 0x1E2D2
 * @module ui_lib
 * @proto void matrix_switch_cell(ushort sel)
 * @confidence likely
 * @note 切换矩阵/统计单元：0x1ECFA 后建立 0xD000 值并调用 0x1FC7C/0x25D7C/0x27250。
 * @tag matrix
 */
int matrix_switch_cell(ushort sel)

{
  byte bVar1;
  int bVar2;
  short sVar3;
  short unaff_ER14;
  
  bVar1 = (byte)((ushort)sel >> 8);
  sVar3 = frame_enter();
  bVar1 = token_scan(bVar1);
  if (bVar1 != 0) {
    dec_accum8 = 0;
    dec_regY_1 = 0;
    set_sel_mode('\x02');
    row_buffer_init((short *)(unaff_ER14 + -4));
    var_scalar_addr(0);
    input_active = _DAT_ram_d013;
    dec_accum0 = (ushort)bVar1 + sVar3;
    bVar2 = check_balanced_expr();
    dec_accum1 = (ushort)bVar2 + (ushort)bVar1 + sVar3;
    set_sel_mode('\x03');
    row_buffer_init((short *)(unaff_ER14 + -4));
    input_active = 0;
    history_cursor_rel(dec_accum2);
    restore_history_line();
  }
  frame_leave();
  return 0;
}

/**
 * @brief 统计单元格编辑（按 0x1EF72 的输入分派）
 * @addr 0x1E37C
 * @module ui_lib
 * @proto void stat_cell_edit2(void)
 * @confidence likely
 * @note 统计单元格编辑（按 0x1EF72 的输入分派）。
 * @tag app
 */
int stat_cell_edit2(uintptr_t _a2, int _a1)

{
  byte bVar1;
  undefined2 uVar2;
  byte bVar5;
  short sVar3;
  ushort uVar4;
  byte bVar6;
  byte bVar8;
  ushort uVar7;
  byte bVar9;
  short unaff_ER14;
  
  uVar2 = frame_enter();
  bVar8 = (byte)((ushort)_a1 >> 8);
  bVar1 = (byte)_a1;
  bVar5 = (byte)((ushort)uVar2 >> 8);
  if (bVar8 != bVar1) {
    bVar6 = (byte)uVar2;
    bVar9 = bVar1;
    if (bVar8 < bVar1) {
      bVar6 = bVar5;
      bVar5 = (byte)uVar2;
      bVar9 = bVar8;
      bVar8 = bVar1;
    }
    sVar3 = mul16(CONCAT11(-(bVar5 < bVar6),bVar5 - bVar6), (uintptr_t)0)
                           (ushort)*(byte *)(unaff_ER14 + 0x10));
    sVar3 = (ushort)bVar8 * (ushort)bVar6 + sVar3;
    bVar1 = (byte)sVar3;
    bVar6 = (byte)((ushort)bVar9 * (ushort)bVar5);
    uVar7 = CONCAT11(-(bVar8 < bVar9),bVar8 - bVar9);
    uVar4 = mul16(2,uVar7);
    call_246b4(CONCAT11(((char)((ushort)sVar3 >> 8) - (char)((ushort)bVar9 * (ushort)bVar5 >> 8, (uintptr_t)0)
                            ) - (bVar1 < bVar6),bVar1 - bVar6) * 2 + uVar7,uVar4);
  }
  frame_leave();
  return 0;
}

/**
 * @brief 模式菜单绘制（3.8KB，0x27E84 调用）
 * @addr 0x1E3E0
 * @module ui_lib
 * @proto int mode_menu_draw(void)
 * @confidence likely
 * @note 模式菜单绘制（3.8KB，0x27E84 调用）。
 * @tag ui
 */
int mode_menu_draw(uintptr_t _a2, int _a1)

{
  byte bVar1;
  undefined2 uVar2;
  char cVar3;
  char cVar4;
  ushort uVar5;
  ushort uVar6;
  char cVar7;
  char cVar8;
  
  uVar2 = frame_enter();
  uVar5 = 0;
  uVar6 = 0;
  cur_line = 0xe;
  cVar4 = (char)uVar2;
  cVar7 = (char)((ushort)uVar2 >> 8);
  if (_a1 == '\x13') {
LAB_rom_01e3fe:
    if (cVar4 == '\0') {
      uVar5 = 0x7dee;
    }
    else if (cVar4 == '\x01') {
      uVar5 = 0x7dfe;
    }
    else if (cVar4 == '\x02') {
      uVar5 = 0x7e20;
    }
    else if (cVar4 == '\x03') {
      uVar5 = 0x7e30;
    }
    draw_text4x(uVar5);
    show_press_ac();
    while( true ) {
      uVar2 = input_is_empty();
      bVar1 = (byte)uVar2;
      cVar8 = (char)((ushort)uVar2 >> 8);
      if (bVar1 == 0x31 && (bool)cVar8 == bVar1 < 0x31) break;
      if (bVar1 == 0x32 && (bool)cVar8 == bVar1 < 0x32) {
        cVar8 = '\x01';
        goto LAB_rom_01e47c;
      }
      if (bVar1 == 0x33 && (bool)cVar8 == bVar1 < 0x33) {
        cVar8 = '\x02';
        goto LAB_rom_01e47c;
      }
      if (bVar1 == 0x34 && (bool)cVar8 == bVar1 < 0x34) {
        cVar8 = '\x03';
        goto LAB_rom_01e47c;
      }
      if (bVar1 == 1 && (bool)(cVar8 + '\x04') == (bVar1 == 0)) {
        if (cVar7 == '\0') goto LAB_rom_01e586;
      }
      else if ((bVar1 == 0x1f && (bool)(cVar8 + '\x04') == bVar1 < 0x1f) ||
              (bVar1 == 0x26 && (bool)(cVar8 + '\x04') == bVar1 < 0x26)) goto LAB_rom_01e586;
      beep();
    }
    cVar8 = '\0';
LAB_rom_01e47c:
    if (cVar4 == '\0') {
      uVar6 = 0x671c;
    }
    else if (cVar4 == '\x01') {
      uVar6 = 0x672c;
    }
    else if (cVar4 == '\x02') {
      uVar6 = 0x673c;
    }
    else if (cVar4 == '\x03') {
      uVar6 = 0x679a;
    }
    draw_text4x(uVar6);
    show_press_ac();
    do {
      uVar2 = input_is_empty();
      bVar1 = (byte)uVar2;
      cVar3 = (char)((ushort)uVar2 >> 8);
      if (bVar1 == 0x31 && (bool)cVar3 == bVar1 < 0x31) {
        bVar1 = 0;
        goto LAB_rom_01e566;
      }
      if (bVar1 == 0x32 && (bool)cVar3 == bVar1 < 0x32) {
        bVar1 = 1;
        goto LAB_rom_01e566;
      }
      if (bVar1 == 0x33 && (bool)cVar3 == bVar1 < 0x33) {
        bVar1 = 2;
        goto LAB_rom_01e566;
      }
      if (bVar1 == 0x34 && (bool)cVar3 == bVar1 < 0x34) {
        bVar1 = 3;
        goto LAB_rom_01e566;
      }
      if (bVar1 == 1 && (bool)(cVar3 + '\x04') == (bVar1 == 0)) {
        if (cVar7 == '\0') goto LAB_rom_01e586;
      }
      else {
        if (bVar1 == 0x1f && (bool)(cVar3 + '\x04') == bVar1 < 0x1f) goto LAB_rom_01e3fe;
        if (bVar1 == 0x26 && (bool)(cVar3 + '\x04') == bVar1 < 0x26) goto LAB_rom_01e586;
      }
      beep();
    } while( true );
  }
  if (cVar4 == '\0') {
    uVar5 = 0x5adc;
  }
  else if (cVar4 == '\x01') {
    uVar5 = 0x5aec;
  }
  else if (cVar4 == '\x02') {
    uVar5 = 0x5b02;
  }
  else if (cVar4 == '\x03') {
    uVar5 = 0x55fa;
  }
  draw_text4x(uVar5);
  show_press_ac();
  do {
    uVar2 = input_is_empty();
    bVar1 = (byte)uVar2;
    cVar4 = (char)((ushort)uVar2 >> 8);
    if (bVar1 == 0x32 && (bool)cVar4 == bVar1 < 0x32) {
      cVar8 = '\0';
      bVar1 = 1;
LAB_rom_01e566:
      matrix_ensure_dims((char *)((ushort)bVar1 * 2 + (byte)(cVar8 << 3) + 0x3750));
LAB_rom_01e586:
      frame_leave();
      return 0;
    }
    if (bVar1 == 0x33 && (bool)cVar4 == bVar1 < 0x33) {
      cVar8 = '\0';
      bVar1 = 2;
      goto LAB_rom_01e566;
    }
    if (bVar1 == 1 && (bool)(cVar4 + '\x04') == (bVar1 == 0)) {
      if (cVar7 == '\0') goto LAB_rom_01e586;
    }
    else if ((bVar1 == 0x1f && (bool)(cVar4 + '\x04') == bVar1 < 0x1f) ||
            (bVar1 == 0x26 && (bool)(cVar4 + '\x04') == bVar1 < 0x26)) goto LAB_rom_01e586;
    beep();
  } while( true );
}

/**
 * @brief 清屏、0x821E(0x100,0x1AB4) 与 0x2A048(0x32) 绘制后刷新（…
 * @addr 0x1E680
 * @module ui_lib
 * @proto void draw_splash_32(void)
 * @confidence strong
 * @note 清屏、0x821E(0x100,0x1AB4) 与 0x2A048(0x32) 绘制后刷新（短路/提示画面）。
 * @tag ui
 */
int draw_splash_32(void)

{
  clear_screen();
  draw_string(0x100,0x1ab4);
  draw_scaled_char(0x32, (uintptr_t)0);
  _DAT_ram_ddda = 1;
  _DAT_ram_ddd9 = 1;
  _DAT_ram_dde6 = 1;
  fb_flush();
  wait_any_key();
  return 0;
}

/**
 * @brief 把统计/编辑状态复位
 * @addr 0x1E6B6
 * @module ui_lib
 * @proto void stat_state_reset(void)
 * @confidence strong
 * @note 把统计/编辑状态复位：0xD114=1、0xD115=0、0xD116=1、0xD117=0。
 * @tag stat
 */
int stat_state_reset(void)

{
  edit_state2 = 1;
  stat_state = 0;
  key_modifiers = 1;
  key_history_flags = 0;
  return 0;
}

/**
 * @brief 对矩阵单元按参数做逐字节缩放（0x13858 开方后的收尾）
 * @addr 0x1E6D0
 * @module ui_lib
 * @proto void matrix_cell_scale(undefined2 k)
 * @confidence likely
 * @note 对矩阵单元按参数做逐字节缩放（0x13858 开方后的收尾）。
 * @tag matrix
 */
int matrix_cell_scale(undefined2 k)

{
  ushort *puVar1;
  short sVar2;
  byte bVar3;
  byte bVar4;
  short unaff_ER14;
  
  bVar4 = (byte)((ushort)k >> 8);
  puVar1 = (ushort *)frame_enter();
  bVar3 = 0;
  do {
    *(undefined *)((ushort)bVar3 + unaff_ER14 + -4) = *(undefined *)(unaff_ER14 + 0x10);
    *(undefined2 *)(unaff_ER14 + 0x10) = *(undefined2 *)(unaff_ER14 + 0x11);
    *(ushort *)(unaff_ER14 + 0x12) = (ushort)*(byte *)(unaff_ER14 + 0x13);
    bVar3 = bVar3 + 1;
  } while ((char)((bVar3 < 4) << 7) < '\0');
  sVar2 = (ushort)bVar4 << 8;
  dec_set_uint_small(puVar1,0);
  bVar4 = 3;
  while( true ) {
    dec_set_from_fmt(unaff_ER14 + -0xe, (uintptr_t)0)
                   CONCAT11((char)((ushort)sVar2 >> 8),
                            *(undefined *)((ushort)bVar4 + unaff_ER14 + -4)));
    dec_bin_xor_core(puVar1,(undefined2 *)(unaff_ER14 + -0xe));
    if (bVar4 == 0) break;
    sVar2 = 0x1ba8;
    dec_bin_pow_core(puVar1,0x1ba8);
    bVar4 = bVar4 - 1;
  }
  frame_leave();
  return 0;
}

/**
 * @brief 菜单光标复位（0x96E8 的薄封装）
 * @addr 0x1E732
 * @module ui_lib
 * @proto void menu_cursor_reset(void)
 * @confidence likely
 * @note 菜单光标复位（0x96E8 的薄封装）。
 * @tag ui
 */
int menu_cursor_reset(void)

{
  cursor_home();
  memzero((undefined *)0xd0f8,0x16);
  memzero(&stat_data,0x3c0);
  return 0;
}

/**
 * @brief 先 0x8CC0 绘制菜单态，然后循环读键直到 0x8DF6 判定有效
 * @addr 0x1E750
 * @module ui_lib
 * @proto short wait_valid_key(char mask)
 * @confidence likely
 * @note 先 0x8CC0 绘制菜单态，然后循环读键直到 0x8DF6 判定有效。
 * @tag key
 */
short wait_valid_key(char mask)

{
  short sVar1;
  undefined2 uVar2;
  
  menu_draw(mask);
  do {
    sVar1 = input_is_empty();
    uVar2 = key_is_value(sVar1);
  } while ((char)uVar2 == '\0');
  return sVar1;
}

/**
 * @brief 按模式选择绘制
 * @addr 0x1E820
 * @module ui_lib
 * @proto void draw_item_by_mode(ushort i)
 * @confidence likely
 * @note 按模式选择绘制：0xD111 == 0x89（0xA7 取反）时调用 0x2A048，否则 0x266E0。
 * @tag ui
 */
int draw_item_by_mode(ushort i)

{
  if (calc_mode == -0x77) {
    draw_scaled_char((ushort)i, (uintptr_t)0);
  }
  else {
    draw_field_y(i);
  }
  return 0;
}

/**
 * @brief 变量列表绘制（1.9KB，0x23338 调用）
 * @addr 0x1E842
 * @module ui_lib
 * @proto void var_list_draw(void)
 * @confidence likely
 * @note 变量列表绘制（1.9KB，0x23338 调用）。
 * @tag ui
 */
int var_list_draw(void)

{
  byte bVar1;
  byte bVar2;
  bool bVar3;
  char cVar4;
  byte bVar5;
  char cVar6;
  byte bVar7;
  byte *pbVar8;
  short unaff_ER14;
  
  bVar1 = frame_enter();
  bVar7 = 0;
  cur_line = 0xe;
  if (menu_io == '\0') {
    if (prev_line == '\n') {
      cVar6 = '\n';
      cur_line = 10;
    }
    else {
      cVar6 = '\x10';
    }
    bVar5 = cVar6 + 1;
    fb_clear_rows(cur_line + 1);
  }
  else {
    cVar6 = '\0';
    bVar5 = 0x32;
    fb_clear_rows(0x32);
  }
  pbVar8 = (byte *)CONCAT11((0x13 < bVar1) + -0x2b,bVar1 - 0x14);
  do {
    *(undefined *)(unaff_ER14 + -0x28) = *(undefined *)(*pbVar8 + 0x7d60);
    *(undefined *)(unaff_ER14 + -0x27) = 0x20;
    *(undefined *)(unaff_ER14 + -0x26) = 0x3d;
    *(undefined *)(unaff_ER14 + -0x25) = 0;
    var_get_value(*pbVar8 - 0x40,(undefined *)(unaff_ER14 + -0x3c));
    cVar4 = (char)((ushort)unaff_ER14 >> 8);
    bVar2 = (byte)unaff_ER14;
    if (calc_mode == -0x3c) {
      stat_calc_main((undefined2 *)CONCAT11(cVar4 + -1 + (99 < bVar2),bVar2 + 0x9c));
    }
    else {
      draw_tokens((undefined2 *)(unaff_ER14 + -0x3c));
    }
    strcat_checked((char *)(unaff_ER14 + -0x28), (uintptr_t)0)
                   (char *)CONCAT11(cVar4 + -1 + (99 < bVar2),bVar2 + 0x9c));
    draw_string((ushort)bVar5 << 8,unaff_ER14 + -0x28);
    if ((ushort)_DAT_ram_d5eb == (ushort)bVar1 + (ushort)bVar7) {
      cursor_visible = 3;
      draw_list_scroller2((ushort)bVar5 << 8,CONCAT11(cur_line,0xc0));
      cursor_visible = 0;
    }
    bVar5 = bVar5 + cVar6;
    bVar7 = bVar7 + 1;
    pbVar8 = pbVar8 + 1;
  } while (((cVar6 != '\0') &&
           (bVar2 = (byte)((ushort)cur_line + (ushort)bVar5),
           bVar3 = SUB21((ushort)cur_line + (ushort)bVar5 >> 8,0),
           (char)(bVar3 - (bVar2 < 0x40)) < '\0' || bVar2 == 0x40 && bVar3 == bVar2 < 0x40)) &&
          (*pbVar8 != 0xff));
  frame_leave();
  return 0;
}

