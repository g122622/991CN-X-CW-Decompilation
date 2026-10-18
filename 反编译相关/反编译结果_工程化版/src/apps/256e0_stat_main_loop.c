/*
 * 应用模式 / 256e0_stat_main_loop.c
 * 地址范围: 0x256E0 - 0x256E0
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 统计数据主循环（12KB，0x975A/0xA16E 调用）
 * @addr 0x256E0
 * @module apps
 * @proto void stat_main_loop(void)
 * @confidence strong
 * @note 统计数据主循环（12KB，0x975A/0xA16E 调用）。
 * @tag app
 */
int stat_main_loop(void)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  byte bVar4;
  int cVar5;
  undefined uVar6;
  char cVar7;
  byte bVar8;
  byte bVar9;
  int cVar10;
  byte bVar11;
  undefined2 *puVar12;
  char *pcVar13;
  undefined2 uVar14;
  ushort uVar15;
  ushort uVar16;
  ushort *puVar17;
  char cVar18;
  short unaff_ER14;
  
  puVar12 = (undefined2 *)frame_enter();
  *(undefined *)(unaff_ER14 + -0xa4) = 0;
  *(undefined *)(unaff_ER14 + -0xad) = 2;
  *(undefined *)(unaff_ER14 + -0xa3) = 0;
  *(ushort *)(unaff_ER14 + -2) = (ushort)_DAT_ram_d157;
  *(undefined *)(unaff_ER14 + -0xa1) = calc_mode;
  cVar18 = '\0';
  *(undefined *)(unaff_ER14 + -0xa6) = 0;
  bVar4 = key_history_flags;
  cVar5 = ratio_key_check();
  uVar6 = is_math_io();
  *(undefined *)(unaff_ER14 + -0xa2) = uVar6;
  cVar7 = is_line_start();
  bVar3 = false;
  if ((cVar7 != '\0') || (cVar7 = is_math_io(), cVar7 != '\0')) {
    bVar3 = true;
  }
  pcVar13 = (char *)input_history_ptr();
  if ((pcVar13 == (char *)0x0) || (!bVar3)) {
    pcVar13 = (char *)(unaff_ER14 + -0x2a);
  }
  *(undefined *)(unaff_ER14 + -0x52) = 0;
  *(undefined *)(unaff_ER14 + -0x5a) = 0;
  bVar8 = key_hist_lo();
  if ((*(char *)(unaff_ER14 + -0xa1) == -0x77) && (bVar3)) {
    bVar8 = 10;
  }
  *(byte *)(unaff_ER14 + -0xa8) = bVar8;
  bVar2 = false;
  if ((((bVar8 == 0) && (menu_state_c != '\0')) ||
      ((byte)input_key == 0x2d &&
       (bool)((char)((ushort)input_key >> 8) + '\x04') == (byte)input_key < 0x2d)) &&
     (bVar4 != 0x15)) {
    bVar8 = 10;
    key_hist_clear_lo(10);
  }
  if ((bVar4 & 0x10) != 0) {
    if (((bVar4 == 0x13) || (!bVar3)) && (bVar4 != 0x15)) {
      key_hist_write(10);
    }
    bVar8 = key_hist_lo();
    bVar2 = true;
  }
  cVar7 = (char)((ushort)unaff_ER14 >> 8);
  bVar9 = (byte)unaff_ER14;
  if (bVar4 == 0x15) {
    bVar1 = false;
    if ((menu_state_e != '\0') && ((_DAT_ram_d166 & 1) != 0)) {
      bVar1 = true;
    }
    if (bVar1) {
      key_history_flags = 0;
      dec_copy((undefined2 *)CONCAT11(cVar7 + -1 + (0x6d < bVar9),bVar9 + 0x92),puVar12);
      puVar12 = (undefined2 *)((ushort)puVar12 & 0xff00);
      dec_set_uint_small((ushort *)CONCAT11(cVar7 + -1 + (99 < bVar9),bVar9 + 0x9c),0);
      bVar2 = false;
    }
    else {
      dec_copy((undefined2 *)CONCAT11(cVar7 + -1 + (99 < bVar9),bVar9 + 0x9c),puVar12);
      puVar12 = puVar12 + 5;
      dec_copy((undefined2 *)CONCAT11(cVar7 + -1 + (0x6d < bVar9),bVar9 + 0x92),puVar12);
    }
  }
  else {
    dec_copy_rev((undefined2 *)CONCAT11(cVar7 + -1 + (0x6d < bVar9),bVar9 + 0x92),puVar12);
  }
  if (bVar3) {
    if ((bVar8 != 10) || (key_hist_d != '\0')) {
      cVar18 = '\x01';
      disp_mode = '\x01';
    }
    if (key_hist_d == '\0') goto LAB_rom_025846;
    dec_accum3 = 0;
    dec_accum4 = 0;
    dec_accum6 = 0;
LAB_rom_025d2a:
    if (((bVar8 == 0xe) || (bVar8 == 0xf)) && (*(char *)(unaff_ER14 + -0xa2) == '\0')) {
      fb_clear_rows(*(byte *)(unaff_ER14 + -2));
      key_hist_c = *(char *)(unaff_ER14 + -2) - 1;
      *(undefined *)(unaff_ER14 + -0xad) = 3;
    }
    history_dirty = 1;
    *(char **)(unaff_ER14 + -0xb0) = input_ptr;
    input_ptr = pcVar13;
    main_loop();
    input_ptr = *(char **)(unaff_ER14 + -0xb0);
    disp_mode = '\0';
    goto LAB_rom_025d74;
  }
LAB_rom_025846:
  *pcVar13 = '\0';
  history_cursor = 0;
  input_active = 0;
  uVar14 = dec_cmp((undefined2 *)CONCAT11(cVar7 + -1 + (0x6d < bVar9),bVar9 + 0x92),puVar12);
  *(char *)(unaff_ER14 + -0xaa) = (char)uVar14;
  uVar14 = dec_cmp((undefined2 *)CONCAT11(cVar7 + -1 + (99 < bVar9),bVar9 + 0x9c),puVar12);
  *(char *)(unaff_ER14 + -0xa9) = (char)uVar14;
  *(undefined *)(unaff_ER14 + -0xa7) = 0;
  if (((cVar5 == '\0') &&
      ((cVar5 = '\x01', *(char *)(unaff_ER14 + -0xaa) != '\x01' ||
       (*(char *)(unaff_ER14 + -0xa9) != '\x01')))) &&
     ((cVar10 = editor_mark_dirty(), cVar10 == '\0' ||
      ((*(char *)(unaff_ER14 + -0xa9) != '\x01' || (*(char *)(unaff_ER14 + -0xaa) != '\x04')))))) {
    puVar17 = (ushort *)CONCAT11(cVar7 + -1 + (99 < bVar9),bVar9 + 0x9c);
    matrix_cell_cmp((ushort *)CONCAT11(cVar7 + -1 + (0x6d < bVar9),bVar9 + 0x92),puVar17);
    uVar14 = dec_cmp((undefined2 *)CONCAT11(cVar7 + -1 + (0x6d < bVar9),bVar9 + 0x92),puVar1)
                           );
    *(char *)(unaff_ER14 + -0xaa) = (char)uVar14;
    uVar14 = dec_cmp((undefined2 *)CONCAT11(cVar7 + -1 + (99 < bVar9),bVar9 + 0x9c),puVar17);
    *(char *)(unaff_ER14 + -0xa9) = (char)uVar14;
    if ((char)uVar14 != '\x01') {
      cVar5 = '\0';
      *(undefined *)(unaff_ER14 + -0xa7) = 6;
    }
  }
  *(undefined *)(unaff_ER14 + -0xa5) = cur_line;
  if ((*(char *)(unaff_ER14 + -0xa1) == '\x02') && (sub_mode == '\x01')) {
    *(undefined *)(unaff_ER14 + -0xa4) = 1;
    bcd_compare_print(*(char *)(unaff_ER14 + -0xaa));
    *(undefined *)(unaff_ER14 + -0xaa) = 4;
    *(undefined *)(unaff_ER14 + -0xa9) = 4;
  }
  if (((*(char *)(unaff_ER14 + -0xa2) == '\0') && (*(char *)(unaff_ER14 + -0xa1) != 'E')) &&
     (*(char *)(unaff_ER14 + -0xa1) != 'J')) {
    if ((*(char *)(unaff_ER14 + -0xa8) == '\0') || ((key_modifiers & 0x20) != 0)) {
      _DAT_ram_d157 = key_hist_c;
      *(ushort *)(unaff_ER14 + -2) = (ushort)key_hist_c;
      input_reset();
      draw_cursor_line();
    }
    bVar11 = _DAT_ram_d157;
    *(ushort *)(unaff_ER14 + -2) = (ushort)_DAT_ram_d157;
    fb_clear_rows(bVar11);
  }
  else if (cVar18 == '\0') {
    if (((*(char *)(unaff_ER14 + -0xaa) != '\x01') && (*(char *)(unaff_ER14 + -0xa9) != '\x01')) ||
       ((bVar2 || (*(char *)(unaff_ER14 + -0xa4) != '\0')))) {
      cVar10 = '\x02';
    }
    else {
      cVar10 = '\x01';
    }
    bVar11 = cVar10 * *(char *)(unaff_ER14 + -0xa5);
    *(byte *)(unaff_ER14 + -0xab) = bVar11;
    *(ushort *)(unaff_ER14 + -2) = CONCAT11(-(0x40 < bVar11),'@' - bVar11);
  }
  *(char **)(unaff_ER14 + -0xb0) = pcVar13;
  if (bVar2) {
    *(ushort *)(unaff_ER14 + -0xb0) = CONCAT11(cVar7 + -1 + (0x51 < bVar9),bVar9 + 0xae);
  }
  *(undefined2 *)(unaff_ER14 + -0xb2) = 0;
  if (((((cVar18 != '\0') && (cVar10 = is_equation_mode(), cVar10 != '\0')) &&
       (*(char *)(unaff_ER14 + -0xa9) != '\x01')) && ((cVar5 != '\0' && (_DAT_ram_d11f == '\0')))) &&
     (*(char *)(unaff_ER14 + -0xaa) != '\x01')) {
    if ((menu_state_e != '\0') && ((_DAT_ram_d166 & 1) != 0)) {
      *(undefined2 *)(unaff_ER14 + -0xb2) = 1;
    }
    if ((*(short *)(unaff_ER14 + -0xb2) == 0) && (bVar8 == 0xd)) {
      uVar6 = matrix_calc_main((undefined2 *)CONCAT11(cVar7 + -1 + (0x77 < bVar9),bVar9 + 0x88));
      *(undefined *)(unaff_ER14 + -0xa3) = uVar6;
    }
  }
  *(char *)(unaff_ER14 + -0xac) = *(char *)(unaff_ER14 + -0xaa);
  if (((*(char *)(unaff_ER14 + -0xaa) != '\x01') || (*(char *)(unaff_ER14 + -0xa9) == '\x01')) ||
     (bVar2)) {
    mixed_fraction = 0;
    *(undefined *)(unaff_ER14 + -0xa6) = 1;
    if (*(char *)(unaff_ER14 + -0xa3) == '\0') {
      uVar6 = edit_render_content(*(undefined2 **)(unaff_ER14 + -0xb0));
    }
    else {
      uVar6 = mode_c_enter((undefined2 *)CONCAT11(cVar7 + -1 + (0x6d < bVar9),bVar9 + 0x92));
    }
    *(undefined *)(unaff_ER14 + -0xaa) = uVar6;
  }
  else {
    *(undefined *)(unaff_ER14 + -0xaa) = 0xf0;
    *(undefined *)(unaff_ER14 + -0x52) = 0;
  }
  if (bVar2) {
    matrix_edit_hook('\0',pcVar13);
    if (cVar18 == '\0') {
      strcpy_checked((char *)CONCAT11(cVar7 + -1 + (0x59 < bVar9),bVar9 + 0xa6),pcVar13);
      strcpy_checked(pcVar13,(char *)CONCAT11(cVar7 + -1 + (0x51 < bVar9),bVar9 + 0xae));
    }
    else {
      strcat_checked(pcVar13,(char *)CONCAT11(cVar7 + -1 + (0x51 < bVar9),bVar9 + 0xae));
    }
  }
  if ((*(char *)(unaff_ER14 + -0xa9) != '\x01') || (bVar2)) {
    if (*(char *)(unaff_ER14 + -0xa3) != '\0') {
      copy_prefixed(pcVar13);
      *pcVar13 = '\0';
      str_emit_1D31();
      strcat_checked(pcVar13,(char *)CONCAT11(cVar7 + -1 + (0x9f < bVar9),bVar9 + 0x60));
    }
    if (*(char *)(unaff_ER14 + -0xa6) == '\0') {
      if (*(char *)(unaff_ER14 + -0xa9) == '\x02') {
        *(undefined *)(unaff_ER14 + -0xa7) = 3;
      }
      else {
        *(undefined *)(unaff_ER14 + -0xa7) = 4;
      }
    }
    else {
      *(undefined *)(unaff_ER14 + -0xa7) = 1;
      if (cVar5 == '\0') {
        if (*(char *)(unaff_ER14 + -0xa9) == '\x02') {
          uVar6 = 2;
        }
        else {
          uVar6 = 5;
        }
        *(undefined *)(unaff_ER14 + -0xa7) = uVar6;
      }
    }
    mixed_fraction = 0;
    if (*(char *)(unaff_ER14 + -0xa3) == '\0') {
      uVar6 = edit_render_content((undefined2 *)CONCAT11(cVar7 + -1 + (0x9f < bVar9),bVar9 + 0x60));
    }
    else {
      uVar6 = mode_c_enter((undefined2 *)CONCAT11(cVar7 + -1 + (99 < bVar9),bVar9 + 0x9c));
    }
    *(undefined *)(unaff_ER14 + -0xa9) = uVar6;
    if (cVar18 == '\0') {
      cVar10 = -0x80;
    }
    else {
      cVar10 = ' ';
    }
    if (((cVar5 != '\0') && (!bVar2)) && (*(char *)(unaff_ER14 + -0xa4) == '\0')) {
      parse_number_str((char *)CONCAT11(cVar7 + -1 + (0x9f < bVar9),bVar9 + 0x60),cVar10);
    }
    matrix_edit_hook('\x01',(undefined *)CONCAT11(cVar7 + -1 + (0x51 < bVar9),bVar9 + 0xae));
    if ((!bVar2) && (*(char *)(unaff_ER14 + -0xa4) == '\0')) {
      if (cVar5 == '\0') {
        fmt_buf_init((undefined *)CONCAT11(cVar7 + -1 + (0x51 < bVar9),bVar9 + 0xae));
      }
      else if (*(char *)(unaff_ER14 + -0xa6) != '\0') {
        if (*(char *)(unaff_ER14 + -0xa0) == -0x40) {
          *(undefined *)(unaff_ER14 + -0xa0) = 0xa7;
        }
        else if ((*(char *)(unaff_ER14 + -0xa0) == '`') && (disp_mode == '\0')) {
          *(undefined *)(unaff_ER14 + -0xa0) = 0x2d;
        }
        else {
          set_cursor_visible(CONCAT11(cVar7 + -1 + (0x51 < bVar9),bVar9 + 0xae),cVar18);
        }
      }
    }
    if (bVar8 != 0) {
      uVar14 = edit_normalize_pos(*(undefined2 *)(unaff_ER14 + -0xaa));
      *(char *)(unaff_ER14 + -0xaa) = (char)uVar14;
      key_hist_set_hi((char)uVar14);
    }
    if ((cVar18 != '\0') || (!bVar2)) {
      strcat_checked((char *)CONCAT11(cVar7 + -1 + (0x51 < bVar9),bVar9 + 0xae), (uintptr_t)0)
                     (char *)CONCAT11(cVar7 + -1 + (0x9f < bVar9),bVar9 + 0x60));
    }
LAB_rom_025c22:
    if (cVar18 != '\0') {
      if ((bVar2) && (*(char *)(unaff_ER14 + -0x52) != '\0')) {
        prompt_string(pcVar13);
      }
      strcat_checked(pcVar13,(char *)CONCAT11(cVar7 + -1 + (0x51 < bVar9),bVar9 + 0xae));
      if (*(char *)(unaff_ER14 + -0xa3) != '\0') {
        wrap_9e4c((byte *)CONCAT11(cVar7 + -1 + (0x77 < bVar9),bVar9 + 0x88));
      }
      goto LAB_rom_025d2a;
    }
  }
  else {
    key_hist_set_hi(*(char *)(unaff_ER14 + -0xaa));
    if (cVar18 != '\0') goto LAB_rom_025c22;
    strcpy_checked((char *)CONCAT11(cVar7 + -1 + (0x51 < bVar9),bVar9 + 0xae),pcVar13);
    *pcVar13 = '\0';
  }
  stored_a = 0;
  stored_b = 0;
  if (bVar3) {
    if (!bVar2) {
      uVar15 = draw_result_line();
      uVar16 = draw_result_line();
      uVar15 = max_u16(uVar15,uVar16);
      uVar14 = key_hi_plus((byte)uVar15);
      if ((char)uVar14 == '\0') goto LAB_rom_025c66;
    }
    line_wrap(*(char *)(unaff_ER14 + -0xab));
  }
LAB_rom_025c66:
  if (*pcVar13 != '\0') {
    if (bVar2) {
      draw_string((ushort)*(byte *)(unaff_ER14 + -2) << 8, (uintptr_t)0)
                     CONCAT11(cVar7 + -1 + (0x59 < bVar9),bVar9 + 0xa6));
    }
    draw_item_by_mode(*(byte *)(unaff_ER14 + -2));
    if (*(char *)(unaff_ER14 + -0xa2) == '\0') {
      if ((*(char *)(unaff_ER14 + -0xac) != '\x01') || (bVar2)) {
        draw_row_scroll();
      }
    }
    else {
      *(ushort *)(unaff_ER14 + -2) =
           *(short *)(unaff_ER14 + -2) + (ushort)*(byte *)(unaff_ER14 + -0xa5);
    }
  }
  if (bVar2) {
    draw_string((ushort)*(byte *)(unaff_ER14 + -2) << 8, (uintptr_t)0)
                   CONCAT11(cVar7 + -1 + (0x51 < bVar9),bVar9 + 0xae));
    strcpy_checked((char *)CONCAT11(cVar7 + -1 + (0x51 < bVar9),bVar9 + 0xae), (uintptr_t)0)
                   (char *)CONCAT11(cVar7 + -1 + (0x9f < bVar9),bVar9 + 0x60));
  }
  draw_item_by_mode(*(byte *)(unaff_ER14 + -2));
  if (*(char *)(unaff_ER14 + -0xa2) == '\0') {
    *(ushort *)(unaff_ER14 + -2) =
         *(short *)(unaff_ER14 + -2) + (ushort)*(byte *)(unaff_ER14 + -0xa5);
    key_hist_c = *(byte *)(unaff_ER14 + -2);
  }
LAB_rom_025d74:
  key_history_flags = bVar4;
  frame_leave();
  return 0;
}

