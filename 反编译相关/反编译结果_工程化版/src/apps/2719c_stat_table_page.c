/*
 * 应用模式 / 2719c_stat_table_page.c
 * 地址范围: 0x2719C - 0x278B6
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 绘制统计表格页
 * @addr 0x2719C
 * @module apps
 * @proto int stat_table_page(void)
 * @confidence strong
 * @note 绘制统计表格页：清屏、0xBC7A 表头、按 0xD163 分页。
 * @tag app
 */
int stat_table_page(void)

{
  byte bVar1;
  ushort uVar2;
  undefined2 uVar3;
  byte bVar4;
  
  cur_line = 10;
  fill_screen(0x400);
  show_press_ac();
  draw_target = 0;
  uVar2 = stats_head_draw();
  if ((char)uVar2 == '\0') {
    fb_alt_flush();
    draw_target = 1;
    timer_base_restore();
    show_press_ac();
    while( true ) {
      uVar3 = input_is_empty();
      bVar1 = (byte)uVar3;
      bVar4 = (byte)((ushort)uVar3 >> 8);
      if (bVar1 == 1 && (bool)(bVar4 + 4) == (bVar1 == 0)) break;
      if (bVar1 == 0x1f && (bool)(bVar4 + 4) == bVar1 < 0x1f) {
        return CONCAT11(bVar4,2);
      }
      if (bVar1 == 0x26 && (bool)(bVar4 + 4) == bVar1 < 0x26) break;
      beep();
    }
    uVar2 = (ushort)bVar4 << 8;
  }
  else {
    draw_target = 1;
    uVar2 = uVar2 & 0xff00;
  }
  return uVar2;
}

/**
 * @brief 计算变量槽地址 (idx<<3)+0xDBE6 并与 0xD144 比较/取用
 * @addr 0x27250
 * @module apps
 * @proto void var_scalar_addr(byte idx)
 * @confidence likely
 * @note 计算变量槽地址 (idx<<3)+0xDBE6 并与 0xD144 比较/取用。
 * @tag var
 */
int var_scalar_addr(byte idx)

{
  char cVar1;
  short sVar2;
  undefined2 uVar3;
  short unaff_ER14;
  
  cVar1 = frame_enter();
  *(char *)(CONCAT11((char)(((ushort)idx << 3) >> 8),idx << 3) + -0x2419) =
       cVar1 - input_ptr;
  sVar2 = CONCAT11((char)(((ushort)idx << 3) >> 8),idx << 3);
  uVar3 = *(undefined2 *)(unaff_ER14 + 0x12);
  *(undefined2 *)(sVar2 + -0x2420) = *(undefined2 *)(unaff_ER14 + 0x10);
  *(undefined2 *)(sVar2 + -0x241e) = uVar3;
  frame_leave();
  return 0;
}

/**
 * @brief 表格编辑主流程（9.4KB，0x2781C 等调用）
 * @addr 0x27284
 * @module apps
 * @proto void table_edit_main2(void)
 * @confidence strong
 * @note 表格编辑主流程（9.4KB，0x2781C 等调用）。
 * @tag app
 */
int table_edit_main2(void)

{
  bool bVar1;
  char cVar2;
  int bVar3;
  int bVar4;
  byte bVar5;
  int cVar6;
  int bVar7;
  bool bVar8;
  byte *pbVar9;
  ushort uVar10;
  short sVar11;
  undefined extraout_R1;
  undefined2 uVar12;
  byte bVar13;
  byte bVar14;
  bool bVar15;
  byte bVar16;
  short unaff_ER14;
  
  frame_enter();
  *(undefined *)(unaff_ER14 + -2) = 0x20;
  *(undefined *)(unaff_ER14 + -1) = 0;
  *(undefined *)(unaff_ER14 + -3) = 0;
  *(undefined *)(unaff_ER14 + -4) = 0;
  *(char *)(unaff_ER14 + -0xa6) = cur_line;
  *(undefined *)(unaff_ER14 + -0xa4) = 0;
  *(undefined *)(unaff_ER14 + -0xab) = 0;
  cVar6 = calc_mode;
  *(undefined **)(unaff_ER14 + -0xa0) = &input_buf;
  bVar16 = 0xb;
  *(undefined *)(unaff_ER14 + -0xa2) = 4;
  if (cur_line == '\n') {
    bVar16 = 6;
    *(undefined *)(unaff_ER14 + -0xa2) = 6;
  }
  cVar2 = is_ratio_input();
  if (cVar2 != '\0') {
    history_key = bVar16 * '\x05';
    *(undefined *)(unaff_ER14 + -0xab) = 1;
  }
  *(byte *)(unaff_ER14 + -0xa3) = history_key;
  bVar3 = draw_spaced(CONCAT11(-(0xc0 < history_key),-0x40 - history_key),(ushort)bVar16);
  if ((key_history_flags & 0x20) == 0) {
    if ((key_modifiers & 0x20) != 0) {
      clear_screen();
      scroll_init();
    }
  }
  else {
    _DAT_ram_d15a = 0;
    _DAT_ram_d15b = '\0';
  }
  *(ushort *)(unaff_ER14 + -6) = (ushort)_DAT_ram_d157;
  draw_cursor_line();
  bVar4 = draw_spaced(*(short *)(unaff_ER14 + -6) - 1,(ushort)*(byte *)(unaff_ER14 + -0xa6));
  *(undefined2 *)(unaff_ER14 + -8) = *(undefined2 *)(unaff_ER14 + -6);
  bVar14 = history_cursor;
  bVar1 = cVar6 == '\x02';
  *(byte *)(unaff_ER14 + -0xa1) = history_cursor;
  bVar15 = bVar14 < _DAT_ram_d15a;
  *(undefined *)(unaff_ER14 + -0x6a) = 0;
  *(undefined *)(unaff_ER14 + -0xaa) = 1;
  bVar5 = (byte)unaff_ER14;
  cVar2 = (char)((ushort)unaff_ER14 >> 8);
  memzero((undefined *)CONCAT11(cVar2 + -1 + (0x71 < bVar5),bVar5 + 0x8e),7);
  memzero((undefined *)CONCAT11(cVar2 + -1 + (0x79 < bVar5),bVar5 + 0x86),7);
  bVar14 = 0;
  if (!bVar15) {
    bVar14 = _DAT_ram_d15a;
  }
  if (bVar14 != 0) {
    bVar4 = cVar6 == '\x02';
    if ((bool)bVar4) {
      *(undefined2 *)(unaff_ER14 + -6) = 0xf;
    }
    if (_DAT_ram_d15b != '\0') {
      pbVar9 = prev_char_ptr(*(byte **)(unaff_ER14 + -0xa0),*(byte **)(unaff_ER14 + -0xa0) + bVar1)
                             );
      uVar10 = token_at(pbVar9);
      *(ushort *)(unaff_ER14 + -0xa8) = uVar10;
      text_clear_panel(uVar10,(byte *)CONCAT11(cVar2 + -1 + (0x9b < bVar5),bVar5 + 100));
      mat_cell_apply((byte *)CONCAT11(cVar2 + -1 + (0x9b < bVar5),bVar5 + 100));
    }
  }
  *(undefined *)(unaff_ER14 + -0xa9) = 0;
  sVar11 = is_key_1f_23();
  if (((char)sVar11 == '\0') && (sVar11 = key_is_14_02(), (char)sVar11 == '\0')) {
    bVar7 = (byte)input_key;
    cVar6 = (char)((ushort)input_key >> 8);
    if ((bVar7 != 0x25 || (bool)(cVar6 + '\x04') != bVar7 < 0x25) &&
       ((((bVar7 != 0x30 || (bool)(cVar6 + '\x04') != bVar7 < 0x30 &&
          (bVar7 != 0x2d || (bool)(cVar6 + '\x04') != bVar7 < 0x2d)) &&
         (bVar7 != 0x42 || (bool)(cVar6 + '\x04') != bVar7 < 0x42)) &&
        ((bVar7 != 0xe9 || (bool)cVar6 != bVar7 < 0xe9 &&
         (bVar7 != 7 || (bool)(cVar6 + '\x04') != bVar7 < 7)))))) goto LAB_rom_02742a;
  }
  *(undefined *)(unaff_ER14 + -0xa9) = 1;
LAB_rom_02742a:
  do {
    sVar11 = input_char_count((byte *)CONCAT11(cVar2 + -1 + (0x69 < bVar5),bVar5 + 0x96));
    bVar13 = (byte)sVar11;
    *(byte *)(unaff_ER14 + -0xa5) = bVar14;
    pbVar9 = (byte *)((ushort)bVar14 + *(short *)(unaff_ER14 + -0xa0));
    bVar7 = bVar13;
    do {
      if (bVar3 <= bVar13) goto LAB_rom_027450;
      if (*(char *)(unaff_ER14 + -0xa1) == *(char *)(unaff_ER14 + -0xa5)) {
        *(byte *)(unaff_ER14 + -3) = bVar16 * bVar13 + *(char *)(unaff_ER14 + -0xa3);
        *(undefined *)(unaff_ER14 + -4) = *(undefined *)(unaff_ER14 + -6);
        *(undefined *)(unaff_ER14 + -0xa9) = 1;
      }
      uVar10 = token_at(pbVar9);
      *(ushort *)(unaff_ER14 + -0xa8) = uVar10;
      bVar7 = text_clear_panel(uVar10,(byte *)CONCAT11(cVar2 + -1 + (0x9b < bVar5),bVar5 + 100));
      if (bVar7 == 0) goto LAB_rom_027450;
      bVar13 = bVar13 + bVar7;
      strcat_checked((char *)CONCAT11(cVar2 + -1 + (0x69 < bVar5),bVar5 + 0x96), (uintptr_t)0)
                     (char *)CONCAT11(cVar2 + -1 + (0x9b < bVar5),bVar5 + 100));
      bVar8 = is_neg_char(*pbVar9);
      if (CONCAT11(extraout_R1,bVar8) == 0) {
        cVar6 = *(char *)(unaff_ER14 + -0xa5) + '\x01';
      }
      else {
        cVar6 = *(char *)(unaff_ER14 + -0xa5) + '\x02';
      }
      *(char *)(unaff_ER14 + -0xa5) = cVar6;
      pbVar9 = char_ptr_next(pbVar9);
      uVar12 = key_is_23(*(short *)(unaff_ER14 + -0xa8));
    } while ((char)uVar12 == '\0');
    if (*(char *)(unaff_ER14 + -0xa1) == *(char *)(unaff_ER14 + -0xa5)) {
      *(undefined *)(unaff_ER14 + -0xa9) = 1;
    }
LAB_rom_027450:
    if ((bVar3 <= bVar13) && (*(char *)(unaff_ER14 + -0xa1) == *(char *)(unaff_ER14 + -0xa5))) {
      *(undefined *)(unaff_ER14 + -0xa9) = 1;
    }
    bVar14 = *(byte *)(unaff_ER14 + -0xa5);
    if (bVar4 < *(byte *)(unaff_ER14 + -0xa2)) {
      bVar4 = bVar4 + 1;
    }
    *(byte *)((ushort)bVar4 + unaff_ER14 + -0x72) = bVar14;
    *(undefined *)((ushort)bVar4 + unaff_ER14 + -0x7a) = 0;
    if (bVar3 < bVar13) {
      mat_cell_apply((byte *)CONCAT11(cVar2 + -1 + (0x69 < bVar5),bVar5 + 0x96));
      *(byte *)(unaff_ER14 + -0xac) = bVar7;
      sVar11 = input_char_count((byte *)CONCAT11(cVar2 + -1 + (0x9b < bVar5),bVar5 + 100));
      *(char *)((ushort)bVar4 + unaff_ER14 + -0x7a) =
           (*(char *)(unaff_ER14 + -0xac) - (char)sVar11) + '\x01';
    }
    else {
      *(undefined *)(unaff_ER14 + -0x9c) = 0;
      uVar10 = input_char_count((byte *)CONCAT11(cVar2 + -1 + (0x69 < bVar5),bVar5 + 0x96));
      while (*(byte *)(unaff_ER14 + -0xa5) = (byte)uVar10, (byte)uVar10 <= bVar3) {
        strcat_checked((char *)CONCAT11(cVar2 + -1 + (0x69 < bVar5),bVar5 + 0x96), (uintptr_t)0)
                       (char *)(unaff_ER14 + -2));
        uVar10 = (ushort)(byte)(*(char *)(unaff_ER14 + -0xa5) + 1);
      }
    }
    if (*(char *)(unaff_ER14 + -0xa9) != '\0') {
      draw_string(CONCAT11(*(undefined *)(unaff_ER14 + -6),*(undefined *)(unaff_ER14 + -0xa3)), (uintptr_t)0)
                     CONCAT11(cVar2 + -1 + (0x69 < bVar5),bVar5 + 0x96));
    }
    if ((bVar7 == 0) && (bVar3 != bVar13)) goto LAB_rom_0275c4;
    if ((bVar15) && (*(byte *)((ushort)bVar1 + unaff_ER14 + -0x71) == _DAT_ram_d15a)) {
      bVar15 = false;
      if (*(char *)(unaff_ER14 + -0xa4) != '\0') {
LAB_rom_0275c4:
        if (bVar15) {
          while ((bVar4 = bVar4 - 1, bVar1 < bVar4 &&
                 (cVar6 = table_menu_flow((undefined2 *)(unaff_ER14 + -8)), cVar6 != '\0'))) {
            uVar10 = 0;
            while (*(byte *)(unaff_ER14 + -0xa5) = (byte)uVar10,
                  (char)(((byte)uVar10 < *(byte *)(unaff_ER14 + -0xa2)) << 7) < '\0') {
              *(undefined *)(uVar10 + unaff_ER14 + -0x72) =
                   *(undefined *)(uVar10 + unaff_ER14 + -0x71);
              *(undefined *)(uVar10 + unaff_ER14 + -0x7a) =
                   *(undefined *)(uVar10 + unaff_ER14 + -0x79);
              uVar10 = (ushort)(byte)(*(char *)(unaff_ER14 + -0xa5) + 1);
            }
            *(undefined *)(unaff_ER14 + -0xa4) = 1;
          }
          if (*(char *)(unaff_ER14 + -0xa4) == '\0') {
            _DAT_ram_d15a = 0;
            _DAT_ram_d15b = '\0';
          }
        }
        sVar11 = *(short *)(unaff_ER14 + -6) + (ushort)*(byte *)(unaff_ER14 + -0xa6);
        *(short *)(unaff_ER14 + -6) = sVar11;
        bVar3 = (byte)((ushort)sVar11 >> 8);
        bVar16 = bVar3 - ((byte)sVar11 < 0x3f);
        if ((bool)((byte)((bVar16 ^ bVar3) & ~bVar16) >> 7) != (char)bVar16 < '\0') {
          draw_string(CONCAT11(*(undefined *)(unaff_ER14 + -6),*(undefined *)(unaff_ER14 + -0xa3, (uintptr_t)0)
                                 ),0x576a);
        }
        error_set_location(*(undefined *)(unaff_ER14 + -3),*(undefined *)(unaff_ER14 + -4));
        _DAT_ram_d157 = *(undefined *)(unaff_ER14 + -8);
        if (*(char *)(unaff_ER14 + -0xa4) != '\0') {
          _DAT_ram_d15a = *(byte *)((ushort)bVar1 + unaff_ER14 + -0x72);
          _DAT_ram_d15b = *(char *)((ushort)bVar1 + unaff_ER14 + -0x7a);
        }
        key_hist_c = *(undefined *)(unaff_ER14 + -6);
        if ((*(char *)(unaff_ER14 + -0xab) != '\0') && (_DAT_ram_d15a == 0)) {
          draw_status_cell(1);
        }
        frame_leave();
        return 0;
      }
      _DAT_ram_d15a = 0;
      _DAT_ram_d15b = '\0';
    }
    cVar6 = stat_mode_main((ushort *)(unaff_ER14 + -8));
    if (cVar6 == '\0') goto LAB_rom_0275c4;
    if (*(char *)(unaff_ER14 + -0x9d) != '\0') {
      uVar10 = 0;
      while (*(byte *)(unaff_ER14 + -0xa5) = (byte)uVar10,
            (char)(((byte)uVar10 < *(byte *)(unaff_ER14 + -0xa2)) << 7) < '\0') {
        *(undefined *)(uVar10 + unaff_ER14 + -0x72) = *(undefined *)(uVar10 + unaff_ER14 + -0x71);
        *(undefined *)(uVar10 + unaff_ER14 + -0x7a) = *(undefined *)(uVar10 + unaff_ER14 + -0x79);
        uVar10 = (ushort)(byte)(*(char *)(unaff_ER14 + -0xa5) + 1);
      }
      *(undefined *)(unaff_ER14 + -0xa4) = 1;
    }
    copy_prefixed((char *)CONCAT11(cVar2 + -1 + (0x9b < bVar5),bVar5 + 100));
    *(char *)(unaff_ER14 + -0xaa) = *(char *)(unaff_ER14 + -0xaa) + '\x01';
  } while( true );
}

/**
 * @brief 统计模式入口（0x2AA76 调用）
 * @addr 0x27742
 * @module apps
 * @proto void stat_mode_entry(void)
 * @confidence likely
 * @note 统计模式入口（0x2AA76 调用）。
 * @tag app
 */
int stat_mode_entry(void)

{
  short unaff_ER14;
  
  frame_enter();
  *(undefined *)(unaff_ER14 + -0x24) = 0;
  if ((((input_buf == '\0') && (edit_state2 == '\x01')) && (key_modifiers == '\x01')) &&
     (_DAT_ram_d157 == '\x01')) {
    fb_to_lcd();
    draw_target = 0;
    cur_line = 0xe;
    if (calc_mode == '\x03') {
      input_read_str((char *)(unaff_ER14 + -0x24));
      draw_scaled_char(0x24, (uintptr_t)0);
      if (sub_mode == 1) {
        input_read_str((char *)(unaff_ER14 + -0x24));
      }
      else {
        strcpy_checked((char *)(unaff_ER14 + -0x24),*(char **)((ushort)sub_mode * 2 + 0x7d2a));
      }
    }
    else if (calc_mode == '\x06') {
      input_read_str((char *)(unaff_ER14 + -0x24));
    }
    else if (calc_mode == '\a') {
      input_read_str((char *)(unaff_ER14 + -0x24));
    }
    else if (calc_mode == -0x77) {
      input_read_str((char *)(unaff_ER14 + -0x24));
    }
    if (*(char *)(unaff_ER14 + -0x24) != '\0') {
      draw_scaled_char(0x32, (uintptr_t)0);
      fb_alt_flush();
    }
    draw_target = 1;
  }
  frame_leave();
  return 0;
}

/**
 * @brief 列表绘制（按 0xD114/0xD115/0xD116 状态与 0x28576）
 * @addr 0x2781C
 * @module apps
 * @proto void list_paint(void)
 * @confidence likely
 * @note 列表绘制（按 0xD114/0xD115/0xD116 状态与 0x28576）。
 * @tag ui
 */
int list_paint(void)

{
  byte bVar1;
  byte bVar2;
  char cVar3;
  char cVar4;
  
  bVar2 = key_modifiers;
  bVar1 = edit_state2;
  cVar4 = is_math_io();
  cVar3 = cur_line;
  if ((bVar1 == 0xc0) && (stat_state == '@')) {
    cur_line = '\x0e';
    echo_input();
    if (cVar4 == '\0') {
      key_hist_c = _DAT_ram_d157 + cur_line;
      cur_line = cVar3;
    }
  }
  else {
    if (bVar2 == 1) {
      history_dirty = 1;
    }
    else {
      history_dirty = 0;
      history_cursor = 0;
      if ((((bVar1 != 1) && (bVar1 != 6)) && (bVar1 != 9)) &&
         (cur_line = cVar3, (edit_state2 & 0x80) == 0)) goto LAB_rom_027890;
    }
    if (cVar4 == '\0') {
      if (((bVar2 == 1) || ((bVar2 & 0x20) != 0)) ||
         (cur_line = cVar3, (key_history_flags & 0x20) != 0)) {
        table_edit_main2();
      }
    }
    else {
      key_flag_clear_b7();
      call_mode_ee2a();
    }
  }
LAB_rom_027890:
  key_history_flags = key_history_flags & 0xdf;
  return 0;
}

/**
 * @brief 表格视图主流程（2KB，0x13CF2 调用）
 * @addr 0x278B6
 * @module apps
 * @proto int table_view_main(void)
 * @confidence likely
 * @note 表格视图主流程（2KB，0x13CF2 调用）。
 * @tag app
 */
int table_view_main(uintptr_t _a2, int _a1)

{
  byte bVar1;
  int bVar2;
  ushort *puVar3;
  char cVar6;
  undefined2 uVar4;
  undefined2 *puVar5;
  undefined uVar8;
  ushort *puVar7;
  short unaff_ER14;
  
  puVar3 = (ushort *)frame_enter();
  bVar1 = (byte)unaff_ER14;
  cVar6 = (char)((ushort)unaff_ER14 >> 8);
  memset((undefined *)CONCAT11(cVar6 + -1 + (0x9f < bVar1),bVar1 + 0x60),0,0xa0);
  *(undefined *)(unaff_ER14 + -0xa1) = 0;
  bVar2 = expr_matrix_scan(_a1);
  if (bVar2 == 0) {
    bVar2 = mode_loop_common(_a1);
    uVar8 = (undefined)((ushort)_a1 >> 8);
    if (bVar2 == 0) {
      uVar4 = kbd_wait_key();
      if ((char)uVar4 == '\0') {
        puVar5 = (undefined2 *)CONCAT11(uVar8,1);
        dec_set_uint_small((ushort *)CONCAT11(cVar6 + -1 + (0xab < bVar1),bVar1 + 0x54),1);
        for (bVar2 = 0; (char)((bVar2 < *(byte *)(unaff_ER14 + 0x10)) << 7) < '\0';
            bVar2 = bVar2 + 1) {
          puVar5 = (undefined2 *)key_pos_offset(CONCAT11(bVar2,bVar2));
          dec_bin_pow((undefined2 *)CONCAT11(cVar6 + -1 + (0xab < bVar1),bVar1 + 0x54),puVar5);
        }
        dec_set_from_fmt(CONCAT11(cVar6 + -1 + (0xb5 < bVar1),bVar1 + 0x4a), (uintptr_t)0)
                       CONCAT11((char)((ushort)puVar5 >> 8),*(undefined *)(unaff_ER14 + -0xa1)));
        dec_set_uint_small(puVar3,2);
        puVar7 = puVar3;
        dec_abs_wrap();
        bVar2 = index_wrap
                          ((undefined2 *)CONCAT11(cVar6 + -1 + (0xb5 < bVar1),bVar1 + 0x4a));
        if ((bVar2 & 6) != 0) {
          dec_inc5((undefined2 *)CONCAT11(cVar6 + -1 + (0xab < bVar1),bVar1 + 0x54),puVar7);
        }
        dec_copy(puVar3,(undefined2 *)CONCAT11(cVar6 + -1 + (0xab < bVar1),bVar1 + 0x54));
        dec_type_byte2((byte *)puVar3);
        goto LAB_rom_027912;
      }
      bVar2 = 1;
    }
    else if (bVar2 == 0xb) {
      dec_set_uint_small(puVar3,0);
      goto LAB_rom_027912;
    }
  }
  else if (bVar2 == 0xb) {
    dec_set_uint_small(puVar3,0);
    goto LAB_rom_027912;
  }
  dec_round_to(puVar3,bVar2);
LAB_rom_027912:
  frame_leave();
  return 0;
}

