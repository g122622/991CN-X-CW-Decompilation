/*
 * 键盘与菜单 / 1f1d6_draw_mode_header.c
 * 地址范围: 0x1F1D6 - 0x1F6C6
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 绘制模式标题
 * @addr 0x1F1D6
 * @module kbd_menu
 * @proto void draw_mode_header(void)
 * @confidence likely
 * @note 绘制模式标题：清 13 字节缓冲，置 0xD137=0xE，按 0x4D7C/0x5E10 绘制两段文本。
 * @tag ui
 */
int draw_mode_header(void)

{
  short unaff_ER14;
  
  frame_enter();
  memset((undefined *)(unaff_ER14 + -0xe),0,0xd);
  clear_screen();
  cur_line = 0xe;
  draw_text4x(0x100,0x4d7c);
  draw_text4x(0x3200,0x5e10);
  get_serial_num(unaff_ER14 + -0xe);
  draw_text4x(0x1812,unaff_ER14 + -0xe);
  fb_flush();
  wait_arrow_exit();
  frame_leave();
  return 0;
}

/**
 * @brief STAT 编辑光标移动
 * @addr 0x1F25A
 * @module kbd_menu
 * @proto void stat_edit_move(undefined2* v)
 * @confidence strong
 * @note STAT 编辑光标移动：0xD114==6 时载入数值并按 0xD115 切换编辑列。
 * @tag stat
 */
int stat_edit_move(undefined2* v)

{
  byte bVar1;
  undefined2 *puVar2;
  undefined extraout_R1;
  ushort uVar3;
  
  puVar2 = (undefined2 *)frame_enter();
  key_hist_clear0((char)puVar2);
  if (edit_state2 == '\x06') {
    dec_cmp_signed(puVar2,v);
    dec_copy_checked(*(undefined2 **)((ushort)stat_state * 2 + 0x1a28),puVar2);
    if (stat_state != 3) {
      stat_state = stat_state + 1;
    }
    goto LAB_rom_01f2b4;
  }
  if (edit_state2 == '\x12') {
    bVar1 = (list_col + list_page) - 1;
    uVar3 = (ushort)bVar1;
    if (var_scroll < bVar1) {
      table_insert_row();
    }
    if (calc_mode == '\f') {
      dec_cmp_signed(puVar2,uVar3);
    }
    list_entry_fetch((short)puVar2);
    if (calc_mode == -0x78) {
      base_clear(CONCAT11(extraout_R1,8),(undefined *)puVar2);
    }
    else {
      table_edit_flow();
    }
    stat_sel = 0;
    stat_rows = 0;
    stat_cols = 0;
    if (calc_mode == '\f') {
      input_key = 0;
    }
  }
  else if (edit_state2 == '\x13') {
    editor_backspace(CONCAT11(list_col,sub_mode));
    stat_row_edit(0x2d,-4);
  }
  else if (edit_state2 == '\x14') {
    editor_backspace(CONCAT11(list_col,sub_mode));
    edit_key_handler(0xfc2d);
  }
  else if (edit_state2 == '\x15') {
    if (sub_mode < 4) {
      dec_normalize2(puVar2,v);
LAB_rom_01f3d2:
      dec_copy_checked(*(undefined2 **, (uintptr_t)0)
                      (CONCAT11((char)(((ushort)list_page << 5) >> 8),list_page << 5) +
                       CONCAT11((char)(((ushort)list_col << 3) >> 8),list_col << 3) +
                       (ushort)list_row * 2 + 0x59a8),puVar2);
      table_edit_flow2();
    }
    else {
LAB_rom_01f396:
      dec_copy_checked(*(undefined2 **, (uintptr_t)0)
                      (CONCAT11((char)(((ushort)list_page << 5) >> 8),list_page << 5) +
                       CONCAT11((char)(((ushort)list_col << 3) >> 8),list_col << 3) +
                       (ushort)list_row * 2 + 0x4a5a),puVar2);
      table_cell_key();
    }
    stat_state = 1;
  }
  else {
    if (edit_state2 == '\x17') goto LAB_rom_01f3d2;
    if (edit_state2 == '\x18') goto LAB_rom_01f396;
    if ((edit_state2 == -0x60) || (edit_state2 == -0x40)) {
      base_clear((ushort)(byte)((&_DAT_ram_d5ec)[_DAT_ram_d5eb] - 0x40),(undefined *)puVar2);
      _DAT_ram_d5eb = _DAT_ram_d5eb + 1;
      goto LAB_rom_01f2b4;
    }
  }
  key_modifiers = 3;
LAB_rom_01f2b4:
  frame_leave();
  return 0;
}

/**
 * @brief 查 0x42B8 表的菜单项类型（8 为子菜单等）
 * @addr 0x1F45A
 * @module kbd_menu
 * @proto byte menu_item_kind(byte idx)
 * @confidence likely
 * @note 查 0x42B8 表的菜单项类型（8 为子菜单等）。
 * @tag ui
 */
byte menu_item_kind(byte idx)

{
  byte bVar1;
  ushort uVar2;
  short sVar3;
  char cVar4;
  
  uVar2 = frame_enter();
  cVar4 = '\n';
  uVar2 = uVar2 & 0xff;
  sVar3 = mul16(uVar2,0x1a);
  bVar1 = (byte)*(undefined2 *)(sVar3 + 0x42b8);
  if (bVar1 == 8 &&
      (bool)((char)((ushort)*(undefined2 *)(sVar3 + 0x42b8) >> 8) + '\x12') == bVar1 < 8) {
    uVar2 = idx & 0xff;
  }
  do {
    sVar3 = mul16(uVar2,0x1a);
    uVar2 = *(ushort *)(sVar3 + 0x42b8);
    if (((byte)uVar2 == 8 && (bool)((char)(uVar2 >> 8) + '\x12') == (byte)uVar2 < 8) || (uVar2 == 0)
       ) break;
    uVar2 = uVar2 & 0xff;
    cVar4 = cVar4 + -1;
  } while (cVar4 != '\0');
  frame_leave();
  return;
}

/**
 * @brief 统计/表格模式判定（0x29D94 或 0xD114 bit7 且非输入态）
 * @addr 0x1F4CA
 * @module kbd_menu
 * @proto byte is_stat_mode(void)
 * @confidence likely
 * @note 统计/表格模式判定（0x29D94 或 0xD114 bit7 且非输入态）。
 * @tag ui
 */
byte is_stat_mode(void)

{
  char cVar1;
  
  cVar1 = is_special_editing();
  if (cVar1 != '\0') {
    return 1;
  }
  if (((edit_state2 & 0x80) != 0) && (menu_io == '\0')) {
    return 1;
  }
  return 0;
}

/**
 * @brief 列表开关（0xEC04 判定后 0x2557A）
 * @addr 0x1F4EC
 * @module kbd_menu
 * @proto void list_toggle(void)
 * @confidence likely
 * @note 列表开关（0xEC04 判定后 0x2557A）。
 * @tag ui
 */
int list_toggle(void)

{
  char cVar1;
  undefined2 uVar2;
  ushort uVar3;
  
  cVar1 = editor_accept_ready();
  if (cVar1 == '\0') {
    uVar2 = list_mode_loop('\0');
  }
  else {
    uVar2 = list_mode_loop('\0');
  }
  if ((char)uVar2 == '\0') {
    input_key = 0;
    uVar3 = editor_accept_ready();
    if ((char)uVar3 != '\0') {
      uVar3 = 0xfc26;
      input_key = 0xfc26;
    }
    uVar3 = uVar3 & 0xff00;
  }
  else {
    uVar3 = CONCAT11((char)((ushort)uVar2 >> 8),1);
  }
  return uVar3;
}

/**
 * @brief 模式切换刷新（4.1KB，0x2452C/0x2557A/0x26332 等使用，含合并子入…
 * @addr 0x1F6C6
 * @module kbd_menu
 * @proto void mode_switch_refresh(void)
 * @confidence strong
 * @note 模式切换刷新（4.1KB，0x2452C/0x2557A/0x26332 等使用，含合并子入口）。
 * @tag ui
 */
int mode_switch_refresh(void)

{
  char cVar1;
  char cVar2;
  byte bVar3;
  undefined2 uVar4;
  undefined *puVar5;
  short sVar6;
  char cVar7;
  char cVar8;
  ushort uVar9;
  byte bVar10;
  byte bVar11;
  short unaff_ER14;
  short sVar12;
  
  uVar4 = frame_enter();
  cVar2 = sub_mode;
  cVar1 = calc_mode;
  uVar9 = 0;
  do {
    bVar10 = (byte)(uVar9 >> 8);
    bVar3 = bVar10 - ((byte)uVar9 < 3);
    if ((bool)((byte)((bVar3 ^ bVar10) & ~bVar3) >> 7) == (char)bVar3 < '\0') {
      puVar5 = *(undefined **)(uVar9 * 2 + 0x4a86);
    }
    else {
      puVar5 = *(undefined **)(uVar9 * 2 + 0x4a84);
    }
    sVar12 = 10;
    sVar6 = mul16(uVar9,10);
    memcpy_bytes((undefined *)(sVar6 + unaff_ER14 + -0x32),puVar5,sVar12);
    uVar9 = uVar9 + 1;
    bVar10 = (byte)(uVar9 >> 8);
    bVar3 = bVar10 - ((byte)uVar9 < 5);
  } while ((byte)((byte)((bVar3 ^ bVar10) & ~bVar3) >> 7 ^ (char)bVar3 < '\0') == 1);
  cVar7 = (char)((ushort)unaff_ER14 >> 8);
  bVar3 = (byte)unaff_ER14;
  if ((cVar1 == 'E') || (cVar1 == -0x3c)) {
    memcpy_bytes((undefined *)CONCAT11(cVar7 + -1 + (0x95 < bVar3),bVar3 + 0x6a), (uintptr_t)0, (uintptr_t)0)
                   (undefined *)0xd612,100);
  }
  cVar8 = (char)uVar4;
  if (calc_mode != cVar8) {
    stat_state = 0;
    memzero(&stat_data,0x83e);
  }
  key_mod_clear();
  sub_mode = (char)((ushort)uVar4 >> 8);
  calc_mode = cVar8;
  expr_state_clear();
  if (cVar8 == '\x03') {
    cursor_home_ui();
    edit_state2 = 0x12;
  }
  else {
    if (cVar8 == '\x06') {
      edit_state2 = 0x13;
    }
    else {
      if (cVar8 != '\a') {
        if (cVar8 == 'E') {
          if (sub_mode == '\0') {
            sub_mode = '\x01';
          }
          stat_list_reset();
        }
        else if (cVar8 == 'J') {
          if (sub_mode == '\0') {
            sub_mode = '\x01';
          }
          setup_enter_E();
        }
        else if (cVar8 == 'K') {
          if (sub_mode == '\0') {
            sub_mode = '\x04';
            ratio_unit = 0;
          }
          enter_mode_18();
          if ((cVar1 == 'K') && (sub_mode == cVar2)) {
            uVar9 = 0;
            do {
              bVar11 = (byte)(uVar9 >> 8);
              bVar10 = bVar11 - ((byte)uVar9 < 3);
              if ((bool)((byte)((bVar10 ^ bVar11) & ~bVar10) >> 7) == (char)bVar10 < '\0') {
                puVar5 = *(undefined **)(uVar9 * 2 + 0x4a86);
              }
              else {
                puVar5 = *(undefined **)(uVar9 * 2 + 0x4a84);
              }
              sVar12 = 10;
              sVar6 = mul16(uVar9,10);
              memcpy_bytes(puVar5,(undefined *)(sVar6 + unaff_ER14 + -0x32),sVar12);
              uVar9 = uVar9 + 1;
              bVar11 = (byte)(uVar9 >> 8);
              bVar10 = bVar11 - ((byte)uVar9 < 5);
            } while ((byte)((byte)((bVar10 ^ bVar11) & ~bVar10) >> 7 ^ (char)bVar10 < '\0') == 1);
          }
        }
        else if (cVar8 == -0x78) {
          dec_set_uint_small((ushort *)CONCAT11(cVar7 + -1 + (0x9f < bVar3),bVar3 + 0x60),1);
          dec_copy_checked(_DAT_ram_1a2a, (uintptr_t)0)
                         (undefined2 *)CONCAT11(cVar7 + -1 + (0x9f < bVar3),bVar3 + 0x60));
          dec_copy_checked(_DAT_ram_1a2e, (uintptr_t)0)
                         (undefined2 *)CONCAT11(cVar7 + -1 + (0x9f < bVar3),bVar3 + 0x60));
          dec_set_uint_small((ushort *)CONCAT11(cVar7 + -1 + (0x9f < bVar3),bVar3 + 0x60),5);
          dec_copy_checked(_DAT_ram_1a2c, (uintptr_t)0)
                         (undefined2 *)CONCAT11(cVar7 + -1 + (0x9f < bVar3),bVar3 + 0x60));
          ratio_reset();
          edit_state2 = 1;
          stat_state = 0;
        }
        else if (cVar8 == -0x3f) {
          memzero((undefined *)0xd37e,10);
        }
        goto LAB_rom_01f78e;
      }
      edit_state2 = 0x14;
    }
    if (cVar8 != cVar1) {
      menu_cursor_reset();
    }
  }
LAB_rom_01f78e:
  if (((cVar1 == 'E') && (cVar8 == -0x3c)) || ((cVar1 == -0x3c && (cVar8 == 'E')))) {
    memcpy_bytes((undefined *)0xd612, (uintptr_t)0, (uintptr_t)0)
                   (undefined *)CONCAT11(cVar7 + -1 + (0x95 < bVar3),bVar3 + 0x6a),100);
  }
  frame_leave();
  return 0;
}

