/*
 * 主界面与菜单 / 0b032_cursor_draw_list.c
 * 地址范围: 0x0B032 - 0x0B830
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 按 0xD134/0xD135/0xD136 绘制列表光标（0x8966 查字形、0x8B8…
 * @addr 0x0B032
 * @module ui
 * @proto void cursor_draw_list(void)
 * @confidence strong
 * @note 按 0xD134/0xD135/0xD136 绘制列表光标（0x8966 查字形、0x8B80/0x8D7E 画框）。
 * @tag ui
 */
int cursor_draw_list(void)

{
  byte bVar1;
  byte bVar2;
  ushort uVar3;
  undefined2 uVar4;
  ushort uVar5;
  byte bVar6;
  char cVar7;
  byte bVar8;
  byte bVar9;
  short unaff_ER14;
  
  frame_enter();
  memzero((undefined *)(unaff_ER14 + -0x20),0x20);
  bVar1 = var_scroll;
  bVar2 = stat_table_width();
  cVar7 = '\0';
  bVar8 = 0;
  while( true ) {
    uVar3 = bVar2 - 1;
    uVar5 = (ushort)bVar8;
    if ((byte)(SBORROW2(uVar5,uVar3) ^ (short)(uVar5 - uVar3) < 0 | uVar5 == uVar3) != 1) break;
    bVar9 = 0;
    for (bVar6 = list_page;
        (byte)(SBORROW2((ushort)bVar6,list_page + 4) ^
              (short)((ushort)bVar6 - (list_page + 4)) < 0) == 1; bVar6 = bVar6 + 1) {
      stat_cell_addr_ex(CONCAT11(bVar6,cVar7),(short *)(unaff_ER14 + -0x22));
      *(undefined2 *)
       ((ushort)bVar8 * 2 +
       CONCAT11((char)(((ushort)bVar9 << 3) >> 8),bVar9 << 3) + unaff_ER14 + -0x20) =
           *(undefined2 *)(unaff_ER14 + -0x22);
      bVar9 = bVar9 + 1;
    }
    if (calc_mode == '\f') {
      if (key_modifiers != '\x05') break;
    }
    else if (sub_mode == '\x01') {
      cVar7 = cVar7 + '\x01';
    }
    cVar7 = cVar7 + '\x01';
    bVar8 = bVar8 + 1;
  }
  uVar4 = key_is_menu_key(input_key);
  if ((char)uVar4 == '\0') {
    clear_screen();
    draw_menu_row_bg(list_page);
    stats_headers_draw();
    draw_frame_edge_a(CONCAT11(bVar2,4),CONCAT11(list_row,list_col),unaff_ER14 + -0x20);
    draw_column_labels(bVar2);
  }
  cur_line = 0xe;
  *(undefined2 *)(unaff_ER14 + -0x22) =
       *(undefined2 *)
        ((ushort)list_row * 2 +
         CONCAT11((char)(((ushort)list_col << 3) >> 8),list_col << 3) + unaff_ER14 + -0x2a);
  result_clear();
  if (bVar1 < list_col) {
    render_editor_line(0);
  }
  else {
    render_editor_line(*(short *)(unaff_ER14 + -0x22));
  }
  frame_leave();
  return 0;
}

/**
 * @brief 表格模式按键分派（按 0xD015 与 0xD144 行内容）
 * @addr 0x0B1EC
 * @module ui
 * @proto void table_key_dispatch(void)
 * @confidence likely
 * @note 表格模式按键分派（按 0xD015 与 0xD144 行内容）。
 * @tag app
 */
int table_key_dispatch(uintptr_t _a2, int _a1)

{
  char cVar1;
  byte bVar2;
  ushort uVar3;
  int sVar4;
  char cVar5;
  short unaff_ER14;
  
  uVar3 = frame_enter();
  bVar2 = edit_state;
  if ((2 < edit_state) || ((char)((char)uVar3 - input_ptr) == history_cursor)) {
    saved_line = cur_line;
    if (edit_state < 3) {
      dec_temp_a = _a1;
      if (edit_state < 2) {
        sVar4 = draw_input_prompt();
        dec_temp_a = dec_temp_a + sVar4;
      }
      dec_regY = *(undefined *)(unaff_ER14 + 0x14);
    }
    else {
      if ((dec_accum1 < uVar3) || ((char)((uVar3 < dec_accum0) << 7) < '\0'))
      goto LAB_rom_00b212;
      _a1 = dec_abs_diff(_a1);
      cVar1 = abs_col_diff(*(byte *)(unaff_ER14 + 0x14));
      *(char *)(unaff_ER14 + 0x14) = cVar1;
      if (((dec_accum0 == uVar3) ||
          ((char)((*(byte *)(unaff_ER14 + 0x14) < dec_regY_1) << 7) < '\0')) ||
         ((dec_regY_1 == *(byte *)(unaff_ER14 + 0x14) && (_a1 < dec_accum8)))) {
        dec_regY_1 = *(byte *)(unaff_ER14 + 0x14);
        dec_accum2 = uVar3;
        dec_accum8 = _a1;
      }
    }
    if (bVar2 == 1) {
      if ((key_modifiers == '\x01') && (history_dirty != '\0')) {
        cVar5 = (char)dec_accum8;
        *(byte *)(unaff_ER14 + 0x14) = *(char *)(unaff_ER14 + 0x14) - dec_regY_1;
        cVar1 = input_cols2();
        hl_col = *(char *)(unaff_ER14 + 0x14) - cVar1;
        hl_line = (char)_a1 - cVar5;
        redraw_line_syntax();
        hl_col2 = cur_line;
        hl_row2 = '\0';
        if ((10 < *(byte *)(unaff_ER14 + 0x12)) &&
           (((*(byte *)(unaff_ER14 + 0x12) != 0xe || (cur_line != '\x0e')) &&
            (input_disp_mode == '|')))) {
          bVar2 = ((char)*(undefined2 *)(unaff_ER14 + 0x13) +
                  (char)((ushort)*(undefined2 *)(unaff_ER14 + 0x13) >> 8)) - 2;
          hl_row2 = '\x01';
          if ((byte)(*(char *)(unaff_ER14 + 0x12) - 1U) < bVar2) {
            hl_row2 = (bVar2 - *(char *)(unaff_ER14 + 0x12)) + '\x02';
          }
          if (0x3f < bVar2) {
            bVar2 = 0x3f;
          }
          hl_col2 = bVar2 - (hl_row2 + -1);
        }
      }
    }
    else {
      display_dirty = 1;
    }
  }
LAB_rom_00b212:
  frame_leave();
  return 0;
}

/**
 * @brief 光标复位并立即重绘（0x96E8 的封装）
 * @addr 0x0B3AC
 * @module ui
 * @proto void cursor_home_ui(void)
 * @confidence likely
 * @note 光标复位并立即重绘（0x96E8 的封装）。
 * @tag ui
 */
int cursor_home_ui(void)

{
  if (calc_mode == '\x03') {
    var_scroll = 0;
    cursor_home();
    memzero((undefined *)0xd400,0x640);
    stat_sel = 0;
    stat_rows = 0;
    stat_cols = 0;
  }
  return 0;
}

/**
 * @brief 矩阵/表格单元绘制
 * @addr 0x0B434
 * @module ui
 * @proto void matrix_cell_draw(void)
 * @confidence strong
 * @note 矩阵/表格单元绘制：按 0xD112 行号、0xD134.. 列号定位并绘制单元格内容。
 * @tag matrix
 */
int matrix_cell_draw(void)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  char cVar7;
  short sVar4;
  short sVar5;
  ushort *puVar6;
  undefined2 *puVar8;
  byte bVar9;
  byte bVar10;
  undefined2 *puVar11;
  short unaff_ER14;
  
  frame_enter();
  bVar1 = sub_mode - 1;
  *(undefined *)(unaff_ER14 + -0xc1) = 3;
  memzero((undefined *)(unaff_ER14 + -0x20),0x20);
  bVar2 = (byte)unaff_ER14;
  cVar7 = (char)((ushort)unaff_ER14 >> 8);
  memzero((undefined *)CONCAT11(cVar7 + -1 + (0xbf < bVar2),bVar2 + 0x40),0xa0);
  clear_screen();
  bVar3 = list_page - 1;
  *(undefined2 *)(unaff_ER14 + -0xc4) =
       *(undefined2 *)
        (CONCAT11((char)(((ushort)list_page << 5) >> 8),list_page << 5) +
         CONCAT11((char)(((ushort)list_col << 3) >> 8),list_col << 3) +
         (ushort)list_row * 2 + 0x4a5a);
  for (bVar9 = 1; bVar9 <= *(byte *)((ushort)bVar1 * 2 + 0x1af8); bVar9 = bVar9 + 1) {
    for (bVar10 = 1; bVar10 <= *(byte *)(unaff_ER14 + -0xc1); bVar10 = bVar10 + 1) {
      puVar11 = *(undefined2 **)
                 (CONCAT11((char)(((ushort)bVar3 << 5) >> 8),bVar3 * ' ') +
                  CONCAT11((char)(((ushort)bVar9 << 3) >> 8),bVar9 << 3) + (ushort)bVar10 * 2 +
                 0x4a7a);
      sVar4 = mul16((ushort)bVar9,0x28);
      sVar5 = mul16((ushort)bVar10,10);
      puVar6 = (ushort *)
               (sVar5 + sVar4 + CONCAT11(cVar7 + -1 + (0xbf < bVar2),bVar2 + 0x40) + -0x32);
      puVar8 = puVar11;
      dec_copy(puVar6,puVar11);
      dec_bin_result(puVar6,puVar8);
      *(ushort **)
       ((ushort)bVar10 * 2 + CONCAT11((char)(((ushort)bVar9 << 3) >> 8),bVar9 << 3) + unaff_ER14 +
       -0x2a) = puVar6;
      draw_cursor(puVar11);
    }
    if (sub_mode == '\x05') {
      *(undefined *)(unaff_ER14 + -0xc1) = 1;
    }
    else if (sub_mode == '\x06') {
      *(undefined *)(unaff_ER14 + -0xc1) = 2;
    }
  }
  table_value_draw();
  page2_triangle_redraw();
  draw_frame_edge_c(*(undefined2 *)((ushort)bVar1 * 2 + 0x1af8),CONCAT11(list_row,list_col), (uintptr_t)0)
                 unaff_ER14 + -0x20);
  cur_line = 0xe;
  render_editor_line(*(short *)(unaff_ER14 + -0xc4));
  frame_leave();
  return 0;
}

/**
 * @brief 判断 p 处是否为双字节字符
 * @addr 0x0B5BA
 * @module ui
 * @proto char is_two_byte_char(char* p)
 * @confidence strong
 * @note 判断 p 处是否为双字节字符：首字节 0x19 后跟 0x1B/0x1C 时返回 1。原记录命名为
 *       byte_strlen，语义不符。
 * @tag charset
 */
char is_two_byte_char(char* p)

{
  byte bVar2;
  short sVar1;
  
  bVar2 = (byte)((ushort)p >> 8);
  if ((*p == '\x19') && ((p[1] == '\x1b' || (p[1] == '\x1c')))) {
    sVar1 = CONCAT11(bVar2,1);
  }
  else {
    sVar1 = (ushort)bVar2 << 8;
  }
  return sVar1;
}

/**
 * @brief 进入设置菜单项 E
 * @addr 0x0B822
 * @module ui
 * @proto void setup_enter_E(void)
 * @confidence likely
 * @note 进入设置菜单项 E：调用 0x251EC 初始化后置界面状态 0xD114=0x17。
 * @tag setup
 */
int setup_enter_E(void)

{
  stat_list_reset();
  edit_state2 = 0x17;
  return 0;
}

/**
 * @brief 当键值 0xD10E 为 0x14 或 0x22 时返回高位字节<<8|1，否则返回高位字节…
 * @addr 0x0B830
 * @module ui
 * @proto byte key_is_14_02(void)
 * @confidence strong
 * @note 当键值 0xD10E 为 0x14 或 0x22 时返回高位字节<<8|1，否则返回高位字节<<8。
 * @tag key
 */
byte key_is_14_02(void)

{
  byte bVar1;
  byte bVar2;
  
  bVar1 = (byte)input_key;
  bVar2 = (byte)((ushort)input_key >> 8);
  if ((bVar1 != 0x1e || (bool)(bVar2 + 4) != bVar1 < 0x1e) &&
     (bVar1 != 0x22 || (bool)(bVar2 + 4) != bVar1 < 0x22)) {
    return (ushort)bVar2 << 8;
  }
  return CONCAT11(bVar2,1);
}

