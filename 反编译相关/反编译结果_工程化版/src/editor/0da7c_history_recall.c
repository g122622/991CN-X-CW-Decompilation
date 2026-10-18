/*
 * 输入编辑器 / 0da7c_history_recall.c
 * 地址范围: 0x0DA7C - 0x0E21E
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 历史回调
 * @addr 0x0DA7C
 * @module editor
 * @proto undefined2 history_recall(byte n)
 * @confidence likely
 * @note 历史回调：取 0x26594 状态，必要时按 0xD144 偏移取历史条目。
 * @tag editor
 */
undefined2 history_recall(byte n)

{
  undefined2 uVar1;
  ushort uVar2;
  
  uVar1 = is_d015_1_3();
  if ((char)uVar1 == '\0') {
    uVar2 = CONCAT11((char)((ushort)uVar1 >> 8),_DAT_ram_d013);
  }
  else {
    uVar2 = find_table_row2(CONCAT11(input_ptr,n - input_ptr));
    _DAT_ram_d013 = (undefined)uVar2;
  }
  return uVar2;
}

/**
 * @brief 按参数模式（0/1/2/3）调整编辑值
 * @addr 0x0DAA4
 * @module editor
 * @proto void edit_value_adjust(byte* tok)
 * @confidence likely
 * @note 按参数模式（0/1/2/3）调整编辑值：模式 0 走 0x2A074，模式 1..3 用 0x1D550
 *       做常量加减，结果写回 token 缓冲。
 * @tag editor
 */
int edit_value_adjust(byte* tok)

{
  char cVar1;
  int bVar2;
  undefined2 *puVar3;
  byte *pbVar4;
  short sVar5;
  byte bVar7;
  ushort uVar6;
  undefined2 *puVar8;
  undefined uVar9;
  int cVar10;
  short unaff_ER14;
  
  puVar3 = (undefined2 *)frame_enter();
  cVar10 = '\0';
  *tok = '\0';
  if (puVar3 != (undefined2 *)0x0) {
    puVar8 = puVar3;
    dec_copy((undefined2 *)(unaff_ER14 + -10),puVar3);
    cVar1 = *(char *)(unaff_ER14 + 0x10);
    if (cVar1 == '\0') {
      matrix_set_value(*(byte *)(unaff_ER14 + 0x12));
    }
    else {
      uVar9 = (undefined)((ushort)puVar8 >> 8);
      if (cVar1 == '\x01') {
        cVar1 = *(char *)(unaff_ER14 + 0x12);
        if (cVar1 == '\0') {
          cVar1 = '\n';
        }
        dec_exp_shift((undefined2 *)(unaff_ER14 + -10),CONCAT11(uVar9,cVar1 + '\x01'));
      }
      else if ((cVar1 == '\x02') || (cVar1 == '\x03')) {
        dec_exp_shift((undefined2 *)(unaff_ER14 + -10),CONCAT11(uVar9,0xb));
      }
    }
    if ((*(byte *)(unaff_ER14 + -10) & 0xf0) != 0) {
      dec_copy((undefined2 *)(unaff_ER14 + -10),puVar3);
    }
    pbVar4 = dec_parse((byte *)(unaff_ER14 + -10),(byte **)(unaff_ER14 + -0x22));
    if ((char)pbVar4 != '\0') {
      *(undefined *)(unaff_ER14 + -0xe) = 10;
      *(undefined *)(unaff_ER14 + -0xd) = 1;
      if (*(char *)(unaff_ER14 + 0x14) != '\x01') {
        cVar10 = token_list_draw(CONCAT11(1,*(undefined *)(unaff_ER14 + 0x14)));
      }
      sVar5 = *(short *)(unaff_ER14 + -0x12);
      bVar7 = (byte)((ushort)sVar5 >> 8);
      bVar2 = (bVar7 + 1) - ((byte)sVar5 < 0xf1);
      if (((byte)((byte)((bVar2 ^ bVar7) & (~bVar2 ^ 0xff)) >> 7 ^ (char)bVar2 < '\0') == 1) ||
         (bVar2 = bVar7 - ((byte)sVar5 < 0x15),
         (byte)((byte)((bVar2 ^ bVar7) & ~bVar2) >> 7 ^ (char)bVar2 < '\0') != 1)) {
        if ((cVar10 == '\0') &&
           (uVar6 = mul_signed16(*(ushort *)(unaff_ER14 + -0x12),3), uVar6 != 0)) {
          key_hist_clear_lo(5);
        }
        cVar10 = *(char *)(unaff_ER14 + 0x10);
        if (cVar10 == '\0') {
          table_nav_row(tok);
        }
        else if (cVar10 == '\x01') {
          table_row_paint(tok);
        }
        else if ((cVar10 == '\x02') || (cVar10 == '\x03')) {
          table_calc_draw(tok);
        }
      }
      else {
        uVar6 = mul_signed16(sVar5 + 0xf,3);
        *(ushort *)(unaff_ER14 + -0x10) = *(short *)(unaff_ER14 + -0x10) + uVar6;
        bVar2 = draw_spaced(*(short *)(unaff_ER14 + -0x12) + 0xf,3);
        if (cVar10 != '\0') {
          draw_cell_value(unaff_ER14 + -0x22);
        }
        fmt_sci(unaff_ER14 + -0x22,tok);
        var_index_to_char((char *)(unaff_ER14 + -0x2c),bVar2);
        strcat_raw(tok,(char *)(unaff_ER14 + -0x2c));
      }
    }
  }
  frame_leave();
  return 0;
}

/**
 * @brief 按 flag 选择 0x20EDA 或 0x20F8C 设置行尾标记，返回 er0
 * @addr 0x0DC4C
 * @module editor
 * @proto undefined2 set_eol_marker(undefined2 er0, char flag)
 * @confidence likely
 * @note 按 flag 选择 0x20EDA 或 0x20F8C 设置行尾标记，返回 er0。
 * @tag ui
 */
undefined2 set_eol_marker(undefined2 er0, char flag)

{
  if (flag == '\0') {
    str_emit_minus();
  }
  else {
    str_emit_1D37();
  }
  return er0;
}

/**
 * @brief 清 0xD31A 起 0x6E 字节
 * @addr 0x0DC78
 * @module editor
 * @proto void edit_area_reset(void)
 * @confidence strong
 * @note 清 0xD31A 起 0x6E 字节；EQN/BASE 模式下再清表达式副本 0xD612（100 字节）。
 * @tag editor
 */
int edit_area_reset(void)

{
  byte bVar1;
  
  memzero((undefined *)0xd31a,0x6e);
  if ((calc_mode == -0x3c) || (calc_mode == 'E')) {
    memzero((undefined *)0xd612,100);
  }
  bVar1 = bcd_type((byte *)0xd16c);
  if (bVar1 != 0xd) {
    expr_state_clear();
  }
  return 0;
}

/**
 * @brief 按 0xD0F6 与当前显示行计算行表地址（mul16 ×10 − 0x2C00）
 * @addr 0x0DCB0
 * @module editor
 * @proto short line_index_calc(void)
 * @confidence likely
 * @note 按 0xD0F6 与当前显示行计算行表地址（mul16 ×10 − 0x2C00）。
 * @tag editor
 */
short line_index_calc(void)

{
  byte bVar1;
  byte bVar2;
  short sVar3;
  
  bVar1 = var_scroll;
  bVar2 = stat_table_width();
  sVar3 = mul16((ushort)bVar2 * (ushort)bVar1,10);
  return sVar3 + -0x2c00;
}

/**
 * @brief 若当前令牌为 1 且字符为 0xC8/0x18，调用 0x26924 处理插入
 * @addr 0x0DCD0
 * @module editor
 * @proto int token_insert_check(void)
 * @confidence likely
 * @note 若当前令牌为 1 且字符为 0xC8/0x18，调用 0x26924 处理插入。
 * @tag editor
 */
int token_insert_check(void)

{
  byte *pbVar1;
  undefined2 uVar2;
  
  pbVar1 = (byte *)frame_enter();
  uVar2 = token_class((char *)pbVar1);
  if (((char)uVar2 == '\x01') && ((*pbVar1 == 200 || (*pbVar1 == 0x18)))) {
    edit_word_insert(pbVar1);
  }
  frame_leave();
  return 0;
}

/**
 * @brief 统计/表格模式主循环
 * @addr 0x0DCFA
 * @module editor
 * @proto void table_loop(short arg)
 * @confidence strong
 * @note 统计/表格模式主循环：置
 *       0xD114=0x17、0xD116=3，读键（0x2AA76）后按0x2D/0x30/0x26/0x2E 等键处理，调用
 *       0x1323A/0x1FE60 更新表格。
 * @tag app
 */
int table_loop(short arg)

{
  byte bVar1;
  int cVar2;
  short sVar3;
  undefined2 uVar4;
  
  do {
    edit_state2 = 0x17;
    key_modifiers = 3;
    stat_row_prep();
    fb_flush();
    while( true ) {
      sVar3 = process_key((short)arg);
      set_input_key(sVar3);
      uVar4 = key_is_extended(sVar3);
      if ((char)uVar4 != '\0') break;
      bVar1 = (byte)sVar3;
      cVar2 = (char)((ushort)sVar3 >> 8);
      if ((bVar1 == 0x2d && (bool)(cVar2 + '\x04') == bVar1 < 0x2d) ||
         (bVar1 == 0x30 && (bool)(cVar2 + '\x04') == bVar1 < 0x30)) {
        bVar1 = table_load_row(sVar3);
        if (bVar1 == 0) {
          stat_state = 2;
          table_cell_edit((short)arg);
        }
        else {
          sVar3 = menu_get_key(bVar1);
          set_input_key(sVar3);
        }
        goto LAB_rom_00dd9e;
      }
      if (bVar1 == 0x26 && (bool)(cVar2 + '\x04') == bVar1 < 0x26) {
        key_mod_clear();
        setup_enter_E();
        goto LAB_rom_00dd9e;
      }
      cVar2 = is_arrow_key(bVar1,cVar2);
      if (cVar2 == '\0') {
        uVar4 = key_is_menu_key(sVar3);
        if ((char)uVar4 != '\0') {
          edit_ctx_check();
        }
        goto LAB_rom_00dd9e;
      }
      key_flag_bit7();
      cVar2 = table_edit_flow2();
      if (cVar2 == '\0') goto LAB_rom_00dd9e;
      key_flag_clear();
    }
    table_copy(arg);
LAB_rom_00dd9e:
    if ((byte)input_key == 0x24 &&
        (bool)((char)((ushort)input_key >> 8) + '\x04') == (byte)input_key < 0x24) {
      return 0;
    }
  } while( true );
}

/**
 * @brief 编辑器按键步进
 * @addr 0x0DDB0
 * @module editor
 * @proto int editor_key_step(byte flag)
 * @confidence likely
 * @note 编辑器按键步进：按令牌类型 1/8/9/0x0A 与 flag 决定光标处理。
 * @tag editor
 */
int editor_key_step(byte flag)

{
  char cVar1;
  char *pcVar2;
  undefined2 uVar3;
  
  pcVar2 = (char *)frame_enter();
  uVar3 = token_class(pcVar2);
  cVar1 = (char)uVar3;
  if (cVar1 == '\x01') goto LAB_rom_00ddce;
  if (cVar1 != '\b') {
    if (cVar1 == '\t') {
      if (flag == '\0') goto LAB_rom_00ddce;
    }
    else if (cVar1 != '\n') goto LAB_rom_00ddce;
  }
  is_stat_mode();
LAB_rom_00ddce:
  frame_leave();
  return 0;
}

/**
 * @brief 按行数 0xD676 逐行绘制列表项（0x9E4C），当前行用 0x20EE6/0x20EE…
 * @addr 0x0DDE8
 * @module editor
 * @proto void list_draw_rows(void)
 * @confidence strong
 * @note 按行数 0xD676 逐行绘制列表项（0x9E4C），当前行用 0x20EE6/0x20EEC 高亮，附加标记取自
 *       0xD677。
 * @tag ui
 */
int list_draw_rows(void)

{
  bool bVar1;
  byte bVar2;
  int cVar3;
  char cVar4;
  char *pcVar5;
  undefined2 uVar6;
  byte *pbVar7;
  byte bVar8;
  byte bVar9;
  
  pcVar5 = (char *)frame_enter();
  bVar1 = false;
  lcd_mode_16(pcVar5);
  cVar3 = list_build_rows();
  bVar2 = _DAT_ram_d676;
  for (bVar8 = 0; (char)((bVar8 < bVar2) << 7) < '\0'; bVar8 = bVar8 + 1) {
    if ((cVar3 != '\0') && (bVar2 - 1 == (ushort)bVar8)) {
      bVar1 = true;
    }
    if (bVar8 != 0) {
      str_emit_1D61();
    }
    if (bVar1) {
      str_emit_backtick();
    }
    uVar6 = mul16((ushort)bVar8,10);
    pbVar7 = (byte *)CONCAT11((char)((ushort)uVar6 >> 8) + -0x2a + (0x7b < (byte)uVar6),
                              (byte)uVar6 + 0x84);
    append_number_str(pbVar7);
    if (bVar1) {
      str_emit_1D3D();
    }
    bVar9 = (&_DAT_ram_d677)[bVar8];
    if (1 < bVar9) {
      cVar4 = is_math_io();
      if (cVar4 == '\0') {
        fmt_print_number(bVar9);
      }
      else {
        str_emit_1D4D();
        str_emit_1A(pcVar5,(char *)pbVar7);
        bcd_print_u8(bVar9);
        str_emit_1B();
      }
    }
  }
  frame_leave();
  return 0;
}

/**
 * @brief 根据光标位置绘制光标（并在模式行显示图标）
 * @addr 0x0DE96
 * @module editor
 * @proto void draw_cursor(ushort* pos)
 * @confidence strong
 * @note 根据光标位置绘制光标（并在模式行显示图标）。
 * @tag editor
 */
int draw_cursor(ushort* pos)

{
  char cVar1;
  ushort uVar2;
  undefined2 uVar3;
  char cVar4;
  byte bVar5;
  
  uVar2 = frame_enter();
  cur_line = 10;
  uVar3 = dec_cmp(pos,pos);
  cVar1 = (char)uVar3;
  cVar4 = (char)uVar2;
  bVar5 = (byte)(uVar2 >> 8);
  if (cVar1 == '\x02') {
    if (((list_col == cVar4) && (list_row == bVar5)) && (cursor_visible = 4, bVar5 != 1)) {
      draw_char_fast(CONCAT11(*(undefined *)((uVar2 & 0xff) + 0x3a27), (uintptr_t)0)
                              *(char *)(bVar5 + 0x3a23) + '\x06'),0x20);
      draw_char_fast(CONCAT11(*(undefined *)((uVar2 & 0xff) + 0x3a27), (uintptr_t)0)
                              *(char *)(bVar5 + 0x3a23) + '\f'),0x20);
    }
    draw_char_fast(CONCAT11(*(undefined *)((uVar2 & 0xff) + 0x3a27),*(undefined *)(bVar5 + 0x3a23)), (uintptr_t)0)
                   0x2d);
    if ((list_col == cVar4) && (list_row == bVar5)) {
      cursor_visible = 0;
    }
  }
  else if ((cVar1 == '\x04') || (cVar1 == '\x01')) {
    if ((list_col == cVar4) && ((list_row == bVar5 && (cursor_visible = 4, bVar5 != 1)))) {
      draw_char_fast(CONCAT11(*(undefined *)((uVar2 & 0xff) + 0x3a27), (uintptr_t)0)
                              *(char *)(bVar5 + 0x3a23) + '\x06'),0x20);
      draw_char_fast(CONCAT11(*(undefined *)((uVar2 & 0xff) + 0x3a27), (uintptr_t)0)
                              *(char *)(bVar5 + 0x3a23) + '\f'),0x20);
    }
    if (cVar4 == '\x01') {
      if (bVar5 == 1) {
        draw_char_fast(CONCAT11(*(undefined *)((uVar2 & 0xff) + 0x3a27),RAM8(0x3a24)),0x20);
      }
      else {
        draw_char_fast(CONCAT11(*(undefined *)((uVar2 & 0xff) + 0x3a27), (uintptr_t)0)
                                *(undefined *)(bVar5 + 0x3a23)),0x2b);
      }
    }
    else {
      draw_char_fast(CONCAT11(*(undefined *)((uVar2 & 0xff) + 0x3a27),*(undefined *)(bVar5 + 0x3a23, (uintptr_t)0)
                             ),0x2b);
    }
    if ((list_col == cVar4) && (list_row == bVar5)) {
      cursor_visible = 0;
    }
  }
  if (bVar5 == 1) {
    if (cVar4 == '\x01') {
      draw_char_fast(0xf33,0x78);
      if (sub_mode == '\x04') {
        draw_char_fast(0xf39,0xa2);
      }
      if (sub_mode == '\x05') {
        draw_char_fast(0xf39,0xa3);
      }
      if (sub_mode == '\x06') {
        draw_char_fast(0xf39,0xa4);
      }
    }
    else if (calc_mode == 'E') {
      if (sub_mode == '\x06') {
        draw_char_fast(0x1b33,0x78);
      }
    }
    else if (calc_mode == 'K') {
      if (sub_mode == '\x05') {
        if (ratio_unit == '\0') {
          draw_char_fast(0x1b40,0x3e);
        }
        else if (ratio_unit == '\x01') {
          draw_char_fast(0x1b40,0x3c);
        }
        else if (ratio_unit == '\x02') {
          draw_char_fast(0x1b40,0x96);
        }
        else if (ratio_unit == '\x03') {
          draw_char_fast(0x1b40,0x94);
        }
        draw_char_fast(0x1b4a,0x30);
      }
      if (sub_mode == '\x06') {
        draw_char_fast(0x1b33,0x78);
      }
    }
  }
  if (bVar5 == 2) {
    if (cVar4 == '\x01') {
      draw_char_fast(0xf71,0x78);
      if (sub_mode == '\x05') {
        draw_char_fast(0xf77,0xa2);
      }
      if (sub_mode == '\x06') {
        draw_char_fast(0xf77,0xa3);
      }
    }
    else if ((calc_mode == 'K') && (sub_mode == '\x06')) {
      if (ratio_unit == '\0') {
        draw_char_fast(0x1b7e,0x3e);
      }
      else if (ratio_unit == '\x01') {
        draw_char_fast(0x1b7e,0x3c);
      }
      else if (ratio_unit == '\x02') {
        draw_char_fast(0x1b7e,0x96);
      }
      else if (ratio_unit == '\x03') {
        draw_char_fast(0x1b7e,0x94);
      }
      draw_char_fast(0x1b88,0x30);
    }
  }
  if ((bVar5 == 3) && (cVar4 == '\x01')) {
    if (sub_mode != '\x04') {
      draw_char_fast(0xfaf,0x78);
    }
    if (sub_mode == '\x06') {
      draw_char_fast(0xfb5,0xa2);
    }
    if ((calc_mode == 'K') && (sub_mode == '\x04')) {
      if (ratio_unit == '\0') {
        draw_char_fast(0xfb1,0x3e);
      }
      else if (ratio_unit == '\x01') {
        draw_char_fast(0xfb1,0x3c);
      }
      else if (ratio_unit == '\x02') {
        draw_char_fast(0xfb1,0x96);
      }
      else if (ratio_unit == '\x03') {
        draw_char_fast(0xfb1,0x94);
      }
      draw_char_fast(0xfb9,0x30);
    }
  }
  frame_leave();
  return 0;
}

/**
 * @brief 更新光标坐标
 * @addr 0x0E1D4
 * @module editor
 * @proto ushort cursor_pos_update(ushort* pos, byte* flag)
 * @confidence likely
 * @note 更新光标坐标。
 * @tag editor
 */
ushort cursor_pos_update(ushort* pos, byte* flag)

{
  char cVar1;
  ushort uVar2;
  
  cVar1 = list_row + -1;
  uVar2 = CONCAT11(cVar1,calc_mode);
  if ((calc_mode == '\x03') && (uVar2 = CONCAT11(cVar1,edit_state2), edit_state2 == '\x12')) {
    uVar2 = CONCAT11(cVar1,sub_mode);
    if ((sub_mode == '\x01') && (cVar1 == '\x01')) {
      uVar2 = 0x200;
    }
    if (((char)(uVar2 >> 8) == '\x02') &&
       (uVar2 = dec_cmp(pos,flag), (char)uVar2 == '\x02')) {
      *flag = 3;
      return CONCAT11((char)(uVar2 >> 8),1);
    }
  }
  return uVar2 & 0xff00;
}

/**
 * @brief 编辑器输入循环
 * @addr 0x0E21E
 * @module editor
 * @proto int edit_loop(void)
 * @confidence strong
 * @note 编辑器输入循环：读键、插入/删除/移动、重绘。
 * @tag editor
 */
int edit_loop(void)

{
  ushort uVar1;
  byte bVar2;
  ushort *puVar3;
  ushort uVar4;
  undefined2 uVar5;
  short sVar6;
  ushort uVar7;
  short sVar8;
  byte bVar9;
  byte bVar10;
  char cVar11;
  ushort uVar12;
  short unaff_ER14;
  
  puVar3 = (ushort *)frame_enter();
  uVar4 = *puVar3;
  uVar12 = *puVar3;
  *(ushort *)(unaff_ER14 + -4) = uVar12;
  uVar5 = kdf_chain_42ba((uintptr_t)0);
  *(undefined2 *)(unaff_ER14 + -2) = uVar5;
  uVar5 = kdf_chain_42b8((uintptr_t)0);
  *(undefined2 *)(unaff_ER14 + -6) = uVar5;
LAB_rom_00e244:
  if (uVar12 != 0) {
    *(ushort *)(unaff_ER14 + -4) = uVar12;
    uVar4 = uVar12 & 0xff;
    cVar11 = (char)(((short)uVar12 >> 0xf) * -0x100 +
                    ((uVar12 & 0xff00) + (uVar12 & 0xff) >> 7 & 0xff) >> 1);
    menu_item_kind(*(ushort *)(unaff_ER14 + -2));
    kdf_chain_count((byte)uVar12);
    if ((cVar11 == -0x15) || (cVar11 == -0x13)) {
      sVar6 = mul16(uVar4,0x1a);
      draw_text4x(*(ushort *)(sVar6 + 0x42a6));
      draw_cursor_box();
      if (*(short *)(sVar6 + 0x42bc) != 0) {
        show_press_ac();
      }
    }
  }
  do {
    uVar12 = 0;
    uVar7 = input_is_empty();
  } while (uVar7 == 0);
  uVar5 = is_menu_range(uVar7);
  if ((char)uVar5 != '\0') {
    uVar7 = menu_code_map((byte)uVar7,(char)(uVar7 >> 8));
  }
  bVar9 = (byte)uVar7;
  bVar10 = (byte)(uVar7 >> 8);
  if (((bVar9 == 0x39 && (bool)bVar10 == bVar9 < 0x39) ||
      (bVar9 == 0x42 && (bool)bVar10 == bVar9 < 0x42)) ||
     (bVar9 == 0x43 && (bool)bVar10 == bVar9 < 0x43)) {
    bVar2 = (byte)*(undefined2 *)(unaff_ER14 + -4);
    cVar11 = (char)((ushort)*(undefined2 *)(unaff_ER14 + -4) >> 8);
    if ((bVar2 == 4 && (bool)(cVar11 + '\x15') == bVar2 < 4) ||
       (bVar2 == 0x45 && (bool)(cVar11 + '\x15') == bVar2 < 0x45)) {
      if (bVar9 == 0x39 && (bool)bVar10 == bVar9 < 0x39) {
        *puVar3 = _DAT_ram_6362;
      }
      else if (bVar9 == 0x42 && (bool)bVar10 == bVar9 < 0x42) {
        *puVar3 = _DAT_ram_6364;
      }
      else if (bVar9 == 0x43 && (bool)bVar10 == bVar9 < 0x43) {
        *puVar3 = _DAT_ram_6366;
      }
      goto LAB_rom_00e304;
    }
  }
  if ((uVar7 < 0x31) ||
     (uVar1 = (ushort)bVar10 - (ushort)(bVar9 < 0x38),
     (uVar1 & 0x100) == 0 && (bVar9 != 0x38 || (char)uVar1 != '\0'))) {
    if (bVar9 == 0x26 && (bool)(bVar10 + 4) == bVar9 < 0x26) {
      input_key = 0;
      goto LAB_rom_00e304;
    }
    sVar6 = mul16(uVar4,0x1a);
    if (*(ushort *)(sVar6 + 0x42be) == uVar7) {
      if (input_layout != '\x01') {
        if (*(short *)(sVar6 + 0x42be) == 0) goto LAB_rom_00e412;
        *puVar3 = uVar7;
        input_key = 0;
        goto LAB_rom_00e304;
      }
      goto LAB_rom_00e37a;
    }
    if (bVar9 == 0x1c && (bool)(bVar10 + 4) == bVar9 < 0x1c) {
      uVar12 = *(ushort *)(sVar6 + 0x42b8);
      if ((byte)uVar12 == 8 && (bool)((char)(uVar12 >> 8) + '\x12') == (byte)uVar12 < 8) {
        uVar12 = *(ushort *)(unaff_ER14 + -2);
      }
    }
    else if (bVar9 == 0x1d && (bool)(bVar10 + 4) == bVar9 < 0x1d) {
      uVar12 = *(ushort *)(sVar6 + 0x42ba);
      if ((byte)uVar12 == 7 && (bool)((char)(uVar12 >> 8) + '\x12') == (byte)uVar12 < 7) {
        uVar12 = *(ushort *)(unaff_ER14 + -6);
      }
    }
    else if (((bVar9 == 0x1f && (bool)(bVar10 + 4) == bVar9 < 0x1f) &&
             (uVar12 = *(ushort *)(sVar6 + 0x42bc), uVar12 != 0)) &&
            ((char)uVar12 != '\x01' ||
             (bool)((char)(uVar12 >> 8) + '\x15') != ((char)uVar12 == '\0'))) {
      uVar5 = kdf_chain_42ba((uintptr_t)0);
      *(undefined2 *)(unaff_ER14 + -2) = uVar5;
      uVar5 = kdf_chain_42b8((uintptr_t)0);
      *(undefined2 *)(unaff_ER14 + -6) = uVar5;
    }
  }
  else {
    sVar8 = mul16(uVar4,0x1a);
    sVar6 = uVar7 * 2;
    uVar12 = *(ushort *)(sVar8 + sVar6 + 0x4246);
    if (uVar12 == 0) {
      uVar12 = 0;
      goto LAB_rom_00e412;
    }
    cVar11 = (char)(((short)uVar12 >> 0xf) * -0x100 +
                    ((uVar12 & 0xff00) + (uVar12 & 0xff) >> 7 & 0xff) >> 1);
    if (cVar11 != -0x15) {
      if (cVar11 == -0x13) {
        *puVar3 = *(ushort *)(sVar8 + sVar6 + 0x4246);
      }
      else {
        *puVar3 = *(ushort *)(sVar8 + sVar6 + 0x4246);
      }
      goto LAB_rom_00e304;
    }
    uVar12 = *(ushort *)(sVar8 + sVar6 + 0x4246);
  }
LAB_rom_00e412:
  bVar9 = (byte)(uVar12 >> 8);
  if ((char)((ushort)(bVar9 >> 7) * 0x100 + ((uVar12 & 0xff00) + (uVar12 & 0xff) >> 7 & 0xff) >> 1)
      == -0x12) {
    if ((char)uVar12 == '\x01' && (bool)(bVar9 + 0x12) == ((char)uVar12 == '\0')) {
      input_key = 0xfc40;
    }
    else {
      *puVar3 = uVar12;
    }
LAB_rom_00e304:
    frame_leave();
    return 0;
  }
LAB_rom_00e37a:
  if (uVar12 == 0) {
    beep();
  }
  goto LAB_rom_00e244;
}

