/*
 * 应用模式 / 281fc_cursor_step_repaint.c
 * 地址范围: 0x281FC - 0x288EE
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 光标步进一次并前后重绘（0x1F9D4 两次）
 * @addr 0x281FC
 * @module apps
 * @proto void cursor_step_repaint(byte v)
 * @confidence likely
 * @note 光标步进一次并前后重绘（0x1F9D4 两次）。
 * @tag ui
 */
int cursor_step_repaint(byte v)

{
  ushort uVar1;
  short unaff_ER14;
  
  uVar1 = frame_enter();
  draw_cell_at(uVar1,v);
  if (*(char *)(unaff_ER14 + 0x10) == '\0') {
    uVar1 = uVar1 + 1;
  }
  else {
    uVar1 = uVar1 - 1;
  }
  draw_cell_at(uVar1,v);
  frame_leave();
  return 0;
}

/**
 * @brief 返回 CONCAT11(c,c)
 * @addr 0x28224
 * @module apps
 * @proto undefined2 token_pair_class(byte* p)
 * @confidence likely
 * @note 返回 CONCAT11(c,c)：按 0xAF74 分类，若为 3 且下一字符 0x1A 则改为 7。
 * @tag eval
 */
undefined2 token_pair_class(byte* p)

{
  char cVar1;
  undefined2 uVar2;
  
  uVar2 = token_class(p);
  cVar1 = (char)uVar2;
  if ((cVar1 == '\x03') && (p[1] == '\x1a')) {
    cVar1 = '\a';
  }
  return CONCAT11(cVar1,cVar1);
}

/**
 * @brief 按三元组更新列表光标（0x8ED0 取条目地址、0x20C64/0x29D00 画选中项）
 * @addr 0x28294
 * @module apps
 * @proto void cursor_update_list(void)
 * @confidence strong
 * @note 按三元组更新列表光标（0x8ED0 取条目地址、0x20C64/0x29D00 画选中项）。
 * @tag ui
 */
int cursor_update_list(void)

{
  short sVar1;
  byte bVar2;
  char cVar3;
  short sVar4;
  undefined2 *puVar5;
  short sVar6;
  byte bVar7;
  byte bVar8;
  short unaff_ER14;
  
  bVar2 = frame_enter();
  memzero((undefined *)(unaff_ER14 + -0x20),0x20);
  cVar3 = list_page + -1;
  sVar4 = stat_cell_addr(CONCAT11(list_col + cVar3,bVar2),list_row);
  sVar1 = (ushort)bVar2 * 2;
  puVar5 = (undefined2 *)(sVar1 + -0x2f08);
  clear_screen();
  bVar7 = 1;
  if (calc_mode == '\x06') {
    for (; bVar7 <= *(byte *)puVar5; bVar7 = bVar7 + 1) {
      for (bVar8 = 1; bVar8 <= *(byte *)(sVar1 + -0x2f07); bVar8 = bVar8 + 1) {
        sVar6 = stat_cell_addr(CONCAT11(cVar3 + bVar7,bVar2),bVar8);
        *(short *)((ushort)bVar8 * 2 +
                   CONCAT11((char)(((ushort)bVar7 << 3) >> 8),bVar7 << 3) + unaff_ER14 + -0x2a) =
             sVar6;
      }
    }
  }
  else {
    for (; bVar7 <= *(byte *)puVar5; bVar7 = bVar7 + 1) {
      for (bVar8 = 1; bVar8 <= *(byte *)(sVar1 + -0x2f07); bVar8 = bVar8 + 1) {
        sVar6 = stat_cell_addr(CONCAT11(bVar7,bVar2),bVar8);
        *(short *)((ushort)bVar7 * 2 +
                   CONCAT11((char)(((ushort)bVar8 << 3) >> 8),bVar8 << 3) + unaff_ER14 + -0x2a) =
             sVar6;
      }
    }
  }
  render_sel_label(bVar2);
  if (calc_mode == '\x06') {
    draw_frame_edge_a(*puVar5,CONCAT11(list_row,list_col),unaff_ER14 + -0x20);
    set_col_areas();
  }
  else {
    draw_frame_edge_a(CONCAT11(*(undefined *)puVar5,*(undefined *)(sVar1 + -0x2f07)), (uintptr_t)0, (uintptr_t)0)
                   CONCAT11(list_col,list_row),unaff_ER14 + -0x20);
    set_col_areas();
  }
  cur_line = 0xe;
  render_editor_line(sVar4);
  frame_leave();
  return 0;
}

/**
 * @brief 按光标行列（R0 低/高字节）计算位置并画四角（0xBC-0xBF）光标框
 * @addr 0x283C6
 * @module apps
 * @proto void draw_cursor_box(void)
 * @confidence strong
 * @note 按光标行列（R0 低/高字节）计算位置并画四角（0xBC-0xBF）光标框。
 * @tag ui
 */
int draw_cursor_box(void)

{
  int cVar1;
  int bVar2;
  ushort uVar3;
  ushort uVar4;
  
  uVar3 = frame_enter();
  if (1 < (byte)uVar3) {
    draw_target = 0;
    uVar4 = mul16((uVar3 >> 8) - 1,0x3f);
    cVar1 = draw_spaced(uVar4,uVar3 & 0xff);
    uVar4 = mul16(uVar3 >> 8,0x3f);
    bVar2 = draw_spaced(uVar4,uVar3 & 0xff);
    draw_vline(CONCAT11(cVar1 + '\x02',0xbc),(ushort)(byte)(bVar2 - 1));
    draw_vline(CONCAT11(cVar1 + '\x01',0xbd),(ushort)bVar2);
    draw_vline(CONCAT11(cVar1 + '\x01',0xbe),(ushort)bVar2);
    draw_vline(CONCAT11(cVar1 + '\x02',0xbf),(ushort)(byte)(bVar2 - 1));
    fb_alt_flush();
    draw_target = 1;
  }
  frame_leave();
  return 0;
}

/**
 * @brief 列表光标移动
 * @addr 0x284EC
 * @module apps
 * @proto void list_cursor_move(void)
 * @confidence likely
 * @note 列表光标移动：按 0xC640 行数与 0xD154 当前位置更新。
 * @tag ui
 */
int list_cursor_move(uintptr_t _a2, int _a1)

{
  char cVar1;
  byte bVar2;
  byte bVar3;
  undefined2 uVar4;
  short unaff_ER14;
  
  frame_enter();
  cVar1 = table_row_count();
  bVar2 = cVar1 - menu_index;
  if ((char)((bVar2 < 2) << 7) < '\0') {
    bVar3 = 4;
    uVar4 = dec_cmp((undefined2 *)&stat_data,_a1);
    if ((char)uVar4 == '\x02') {
      bVar3 = 5;
    }
    strcpy_checked((char *)(unaff_ER14 + -0x12),*(char **)((ushort)bVar3 * 2 + 0x3646));
  }
  else {
    strcpy_checked((char *)(unaff_ER14 + -0x12),_DAT_ram_38fc);
    strcat_checked((char *)(unaff_ER14 + -0x12),"=0");
  }
  draw_format_string(0x100,(char *)(unaff_ER14 + -0x12));
  bVar3 = -bVar2 + 3;
  if ((cVar1 == '\x03') && (bVar2 == 2)) {
    bVar3 = -bVar2 + 4;
  }
  draw_string(0xf00,*(undefined2 *)((ushort)bVar3 * 2 + 0x3646));
  frame_leave();
  return 0;
}

/**
 * @brief Math 输入输出模式判断
 * @addr 0x28576
 * @module apps
 * @proto char is_math_io(void)
 * @confidence strong
 * @note Math 输入输出模式判断：0xD11E!=0 且 0xD111 bit7 时返回 1。
 * @tag ui
 */
char is_math_io(void)

{
  char cVar1;
  
  cVar1 = is_stat_edit3();
  if (((cVar1 != '\0') && (menu_io != '\0')) && ((calc_mode & 0x80) != 0)) {
    return 1;
  }
  return 0;
}

/**
 * @brief 矩阵模式循环的实现（调用 0x13368）
 * @addr 0x28594
 * @module apps
 * @proto void mode_4b_matrix_impl(void)
 * @confidence strong
 * @note 矩阵模式循环的实现（调用 0x13368）。
 * @tag mode
 */
int mode_4b_matrix_impl(uintptr_t _a2, int _a1)

{
  int cVar1;
  short sVar2;
  undefined2 uVar3;
  ushort uVar4;
  byte bVar5;
  
  do {
    edit_state2 = 0x18;
    key_modifiers = 3;
    matrix_cell_draw();
    fb_flush();
    while( true ) {
      sVar2 = process_key((short)_a1);
      set_input_key(sVar2);
      uVar3 = key_is_extended(sVar2);
      if ((char)uVar3 != '\0') break;
      bVar5 = (byte)sVar2;
      cVar1 = (char)((ushort)sVar2 >> 8);
      if ((bVar5 == 0x2d && (bool)(cVar1 + '\x04') == bVar5 < 0x2d) ||
         (bVar5 == 0x30 && (bool)(cVar1 + '\x04') == bVar5 < 0x30)) {
        uVar4 = apps_matrix_main(sVar2,_a1);
        if ((char)uVar4 == '\0') {
          stat_state = 2;
          table_cell_edit((short)_a1);
        }
        else {
          sVar2 = menu_get_key((char)uVar4);
          set_input_key(sVar2);
        }
        goto LAB_rom_028638;
      }
      if (bVar5 == 0x26 && (bool)(cVar1 + '\x04') == bVar5 < 0x26) {
        key_mod_clear();
        enter_mode_18();
        goto LAB_rom_028638;
      }
      cVar1 = is_arrow_key(bVar5,cVar1);
      if (cVar1 == '\0') {
        uVar3 = key_is_menu_key(sVar2);
        if ((char)uVar3 != '\0') {
          edit_ctx_check();
        }
        goto LAB_rom_028638;
      }
      key_flag_bit7();
      cVar1 = table_cell_key();
      if (cVar1 == '\0') goto LAB_rom_028638;
      key_flag_clear();
    }
    table_copy(_a1);
LAB_rom_028638:
    if ((byte)input_key == 0x24 &&
        (bool)((char)((ushort)input_key >> 8) + '\x04') == (byte)input_key < 0x24) {
      return 0;
    }
  } while( true );
}

/**
 * @brief 向导主流程（1.9KB，0x280B0 调用）
 * @addr 0x286D4
 * @module apps
 * @proto void wizard_main(void)
 * @confidence likely
 * @note 向导主流程（1.9KB，0x280B0 调用）。
 * @tag ui
 */
int wizard_main(void)

{
  byte bVar1;
  byte bVar2;
  short sVar3;
  short sVar4;
  ushort *puVar5;
  undefined2 *puVar6;
  byte bVar7;
  byte bVar8;
  undefined2 *puVar9;
  short unaff_ER14;
  
  frame_enter();
  bVar1 = sub_mode - 1;
  memzero((undefined *)(unaff_ER14 + -0x20),0x20);
  clear_screen();
  bVar2 = list_page - 1;
  *(undefined2 *)(unaff_ER14 + -0xc2) =
       *(undefined2 *)
        (CONCAT11((char)(((ushort)list_page << 5) >> 8),list_page << 5) +
         CONCAT11((char)(((ushort)list_col << 3) >> 8),list_col << 3) +
         (ushort)list_row * 2 + 0x59a8);
  for (bVar7 = 1; bVar7 <= *(byte *)((ushort)bVar1 * 2 + 0x1af8); bVar7 = bVar7 + 1) {
    for (bVar8 = 1; bVar8 <= *(byte *)((ushort)bVar1 * 2 + 0x1af9); bVar8 = bVar8 + 1) {
      puVar9 = *(undefined2 **)
                (CONCAT11((char)(((ushort)bVar2 << 5) >> 8),bVar2 * ' ') +
                 CONCAT11((char)(((ushort)bVar7 << 3) >> 8),bVar7 << 3) + (ushort)bVar8 * 2 + 0x59c8
                );
      sVar3 = mul16((ushort)bVar7,0x28);
      sVar4 = mul16((ushort)bVar8,10);
      puVar5 = (ushort *)
               (sVar4 + sVar3 + CONCAT11((char)((ushort)unaff_ER14 >> 8) + -1 +
                                         (0xbf < (byte)unaff_ER14),(byte)unaff_ER14 + 0x40) + -0x32)
      ;
      puVar6 = puVar9;
      dec_copy(puVar5,puVar9);
      dec_bin_result(puVar5,puVar6);
      *(ushort **)
       ((ushort)bVar8 * 2 + CONCAT11((char)(((ushort)bVar7 << 3) >> 8),bVar7 << 3) + unaff_ER14 +
       -0x2a) = puVar5;
      wizard_edit(puVar9);
    }
  }
  if (list_page == 1) {
    page2_triangle_redraw();
  }
  draw_frame_edge_b(*(undefined2 *)((ushort)bVar1 * 2 + 0x1af8),CONCAT11(list_row,list_col), (uintptr_t)0)
                 unaff_ER14 + -0x20);
  cur_line = 0xe;
  render_editor_line(*(short *)(unaff_ER14 + -0xc2));
  frame_leave();
  return 0;
}

/**
 * @brief 0xD114 bit4 置位且 0xD116 == 1 时返回 1
 * @addr 0x2880E
 * @module apps
 * @proto char is_edit_flag_16(void)
 * @confidence strong
 * @note 0xD114 bit4 置位且 0xD116 == 1 时返回 1。
 * @tag ui
 */
char is_edit_flag_16(void)

{
  if (((edit_state2 & 0x10) != 0) && (key_modifiers == '\x01')) {
    return 1;
  }
  return 0;
}

/**
 * @brief 统计行准备
 * @addr 0x28824
 * @module apps
 * @proto void stat_row_prep(void)
 * @confidence likely
 * @note 统计行准备：清 0x20 字节与缓冲，按 0xD134 取行偏移（0xDCFA 使用）。
 * @tag app
 */
int stat_row_prep(void)

{
  short sVar1;
  short unaff_ER14;
  
  frame_enter();
  memzero((undefined *)(unaff_ER14 + -0x20),0x20);
  clear_screen();
  sVar1 = *(short *)(CONCAT11((char)(((ushort)list_page << 5) >> 8),list_page << 5) +
                     CONCAT11((char)(((ushort)list_col << 3) >> 8),list_col << 3) +
                     (ushort)list_row * 2 + 0x59a8);
  draw_frame_edge_d(CONCAT11(_DAT_ram_1aff,_DAT_ram_1afe),CONCAT11(list_row,list_col), (uintptr_t)0)
                 CONCAT11((char)(((ushort)list_page << 5) >> 8),list_page << 5) + 0x59b2);
  draw_fraction_bars();
  cur_line = 0xe;
  render_editor_line(sVar1);
  frame_leave();
  return 0;
}

/**
 * @brief 调用 0x22DFE(0xEB42)（进入菜单/模式入口）
 * @addr 0x288C6
 * @module apps
 * @proto void mode_enter_eb42(void)
 * @confidence likely
 * @note 调用 0x22DFE(0xEB42)（进入菜单/模式入口）。
 * @tag menu
 */
int mode_enter_eb42(void)

{
  menu_edit_entry(0xeb42);
  return 0;
}

/**
 * @brief 列表模式主流程（2.6KB，0x2AA76 调用）
 * @addr 0x288EE
 * @module apps
 * @proto int list_mode_main(void)
 * @confidence likely
 * @note 列表模式主流程（2.6KB，0x2AA76 调用）。
 * @tag ui
 */
int list_mode_main(void)

{
  byte bVar1;
  char cVar2;
  byte bVar3;
  ushort uVar4;
  short sVar5;
  short sVar6;
  
  frame_enter();
  if ((key_modifiers & 0x40) == 0) {
    _DAT_ram_d163 = 0;
LAB_rom_028906:
    bVar1 = stats_cell_key();
    if ((bVar1 != 0xe) && (bVar1 != 0xf)) {
      if (bVar1 != 0xd) {
        if (bVar1 == 0xc) {
          fill_screen(0x400);
          draw_target = 0;
          draw_empty_line();
          fb_alt_flush();
          draw_target = 1;
        }
        else {
          sVar6 = mul16((ushort)bVar1,6);
          draw_text4x(*(ushort *)(sVar6 + 0x5e1a));
        }
        show_press_ac();
LAB_rom_028bba:
        do {
          sVar6 = input_is_empty();
        } while (sVar6 == 0);
        bVar3 = (byte)sVar6;
        cVar2 = (char)((ushort)sVar6 >> 8);
        if ((((bVar3 == 0x31 && (bool)cVar2 == bVar3 < 0x31) ||
             (bVar3 == 0x32 && (bool)cVar2 == bVar3 < 0x32)) ||
            (bVar3 == 0x33 && (bool)cVar2 == bVar3 < 0x33)) ||
           (bVar3 == 0x34 && (bool)cVar2 == bVar3 < 0x34)) {
          sVar5 = mul16((ushort)bVar1,6);
          bVar3 = *(byte *)(sVar5 + sVar6 + 0x5deb);
          if (bVar3 != 0) {
            if (((-(ushort)(bVar3 < 0x31) & 0x100) != 0 ||
                 bVar3 == 0x31 && (char)-(ushort)(bVar3 < 0x31) == '\0') &&
               ((-(ushort)(bVar3 < 3) & 0x100) == 0)) {
              uVar4 = bVar3 - 3;
                    // WARNING: Could not recover jumptable at 0x028990. Too many branches
                    // WARNING: Treating indirect jump as call
              ((void)0);
              return 0;
            }
            if (((((edit_state2 & 0x10) == 0) && (cVar2 = is_equation_mode(), cVar2 == '\0')) &&
                (cVar2 = is_mode_4a(), cVar2 == '\0')) &&
               ((cVar2 = editor_accept_ready(), cVar2 == '\0' &&
                (cVar2 = is_mode_0c(), cVar2 == '\0')))) {
              key_hist_swap_nibbles();
            }
            goto LAB_rom_0289c0;
          }
        }
        else {
          if (bVar3 == 0x1f && (bool)(cVar2 + '\x04') == bVar3 < 0x1f) goto LAB_rom_028906;
          if ((bVar3 == 0x25 && (bool)(cVar2 + '\x04') == bVar3 < 0x25) ||
             (bVar3 == 0x26 && (bool)(cVar2 + '\x04') == bVar3 < 0x26)) goto LAB_rom_0289c0;
        }
        beep();
        goto LAB_rom_028bba;
      }
      mode_paint();
    }
LAB_rom_0289c0:
    draw_target = 1;
    _DAT_ram_d163 = 0;
  }
  frame_leave();
  return 0;
}

