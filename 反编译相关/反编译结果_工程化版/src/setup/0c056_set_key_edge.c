/*
 * 设置与模式逻辑 / 0c056_set_key_edge.c
 * 地址范围: 0x0C056 - 0x0C726
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 按 flag 选择 0x20EC2 或 0x20F6E 设置按键边沿，返回 er0
 * @addr 0x0C056
 * @module setup
 * @proto undefined2 set_key_edge(undefined2 er0, char flag)
 * @confidence likely
 * @note 按 flag 选择 0x20EC2 或 0x20F6E 设置按键边沿，返回 er0。
 * @tag key
 */
undefined2 set_key_edge(undefined2 er0, char flag)

{
  if (flag == '\0') {
    str_emit_mode_tag();
  }
  else {
    str_emit_1B1A();
  }
  return er0;
}

/**
 * @brief 仅在 0x28576 为真且字符落在 0x1A..0x1F（变量 A-F）时返回 1
 * @addr 0x0C070
 * @module setup
 * @proto byte is_alpha_reg(byte ch)
 * @confidence likely
 * @note 仅在 0x28576 为真且字符落在 0x1A..0x1F（变量 A-F）时返回 1。
 * @tag key
 */
byte is_alpha_reg(byte ch)

{
  char cVar1;
  undefined uVar2;
  
  cVar1 = is_math_io();
  if (((cVar1 == '\0') || (ch < 0x1a)) || (0x1f < ch)) {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}

/**
 * @brief 等待键盘释放在 5 个 10ms 间隔内确认，并把当前扫描码低 8 位清零写入 out
 * @addr 0x0C090
 * @module setup
 * @proto byte wait_release(byte* out)
 * @confidence strong
 * @note 等待键盘释放在 5 个 10ms 间隔内确认，并把当前扫描码低 8 位清零写入 out。
 * @tag key
 */
byte wait_release(byte* _a1)

{
  byte bVar1;
  byte bVar2;
  byte *pbVar3;
  byte bVar4;
  
  pbVar3 = (byte *)frame_enter();
  bVar4 = 1;
  do {
    timer_wait(10);
    bVar1 = _DAT_ram_f040;
    kbd_ko = pbVar3[1];
    bVar2 = _DAT_ram_f040 ^ 0xff;
    kbd_ko_disable();
    if (((bVar1 ^ 0xff) & *pbVar3) != 0) {
      *pbVar3 = *pbVar3 & bVar2;
    }
    bVar4 = bVar4 + 1;
  } while (bVar4 < 6);
  frame_leave();
  return;
}

/**
 * @brief 取 key[0] 低 4 位查 ROM 0xA0 表，换算后写入 type 并返回 0
 * @addr 0x0C1FC
 * @module setup
 * @proto byte key_vartype(byte* key, byte* type)
 * @confidence likely
 * @note 取 key[0] 低 4 位查 ROM 0xA0 表，换算后写入 type 并返回 0。
 * @tag key
 */
byte key_vartype(byte* key, byte* type)

{
  undefined2 uVar1;
  
  uVar1 = mul16((ushort)(*key & 0xf),0xa0);
  *type = CONCAT11((char)((ushort)uVar1 >> 8) + -0x2d + (0x6d < (byte)uVar1),(byte)uVar1 + 0x92);
  return 0;
}

/**
 * @brief 当键值 0xD10E 为 0x04 或 0x20 时返回高位字节<<8|1，否则返回高位字节…
 * @addr 0x0C2E2
 * @module setup
 * @proto byte key_is_1a_04(void)
 * @confidence strong
 * @note 当键值 0xD10E 为 0x04 或 0x20 时返回高位字节<<8|1，否则返回高位字节<<8。
 * @tag key
 */
byte key_is_1a_04(void)

{
  byte bVar1;
  byte bVar2;
  
  bVar1 = (byte)input_key;
  bVar2 = (byte)((ushort)input_key >> 8);
  if ((bVar1 != 0x1c || (bool)(bVar2 + 4) != bVar1 < 0x1c) &&
     (bVar1 != 0x20 || (bool)(bVar2 + 4) != bVar1 < 0x20)) {
    return (ushort)bVar2 << 8;
  }
  return CONCAT11(bVar2,1);
}

/**
 * @brief 清屏后按 0xD163 起始行绘制统计矩阵单元（0x3950 表）并刷新屏幕
 * @addr 0x0C358
 * @module setup
 * @proto void stats_matrix_draw(void)
 * @confidence strong
 * @note 清屏后按 0xD163 起始行绘制统计矩阵单元（0x3950 表）并刷新屏幕。
 * @tag app
 */
int stats_matrix_draw(void)

{
  byte bVar1;
  ushort uVar2;
  short sVar3;
  byte bVar4;
  
  fill_screen(0x400);
  cur_line = 0xe;
  draw_target = 0;
  sVar3 = 0;
  do {
    uVar2 = CONCAT11((char)(((ushort)_DAT_ram_d163 << 2) >> 8),_DAT_ram_d163 << 2) + sVar3;
    draw_format_string((ushort)(byte)((char)sVar3 * '\x10' + 1) << 8, (uintptr_t)0)
                   *(char **)(CONCAT11((char)(((uVar2 & 0xff00) + (uVar2 & 0xff)) * 4 >> 8),
                                       (char)uVar2 << 2) + 0x3950));
    if ((short)(ushort)_DAT_ram_6798 <=
        CONCAT11((char)(((ushort)_DAT_ram_d163 << 2) >> 8),_DAT_ram_d163 << 2) + sVar3) break;
    sVar3 = sVar3 + 1;
    bVar4 = (byte)((ushort)sVar3 >> 8);
    bVar1 = bVar4 - ((byte)sVar3 < 4);
  } while ((byte)((byte)((bVar1 ^ bVar4) & ~bVar1) >> 7 ^ (char)bVar1 < '\0') == 1);
  fb_alt_flush();
  draw_target = 1;
  draw_cursor_box();
  return 0;
}

/**
 * @brief 从 1 开始按 3n+1 递增直到不小于 limit，返回下一个（或当前）值
 * @addr 0x0C3D0
 * @module setup
 * @proto ushort next_size_3n1(ushort limit)
 * @confidence strong
 * @note 从 1 开始按 3n+1 递增直到不小于 limit，返回下一个（或当前）值。
 * @tag util
 */
ushort next_size_3n1(ushort limit)

{
  short sVar1;
  
  for (sVar1 = 1;
      (byte)(SBORROW2(sVar1,(ushort)limit) ^ (short)(sVar1 - (ushort)limit) < 0) == 1;
      sVar1 = sVar1 * 3 + 1) {
  }
  return CONCAT11((char)((ushort)(sVar1 * 3) >> 8),(char)sVar1);
}

/**
 * @brief 矩阵模式按键处理（按 0xD114==0x12 与键值分派，0xCDE8 插入行等）
 * @addr 0x0C438
 * @module setup
 * @proto void matrix_mode_key(void)
 * @confidence likely
 * @note 矩阵模式按键处理（按 0xD114==0x12 与键值分派，0xCDE8 插入行等）。
 * @tag matrix
 */
int matrix_mode_key(uintptr_t _a2, int _a1)

{
  byte bVar1;
  int cVar2;
  undefined2 uVar3;
  ushort uVar4;
  undefined2 uVar5;
  ushort uVar6;
  byte bVar7;
  undefined uVar8;
  short unaff_ER14;
  
  uVar3 = frame_enter();
  uVar5 = uVar3;
LAB_rom_00c446:
  do {
    while( true ) {
      *(undefined2 *)(unaff_ER14 + -2) = uVar5;
      cVar2 = edit_loop();
      if (cVar2 != '\x01') break;
      bVar1 = (byte)*(undefined2 *)(unaff_ER14 + -2);
      uVar5 = uVar3;
      if (bVar1 != 4 ||
          (bool)((char)((ushort)*(undefined2 *)(unaff_ER14 + -2) >> 8) + '\x12') != bVar1 < 4)
      goto LAB_rom_00c44a;
    }
    if (cVar2 == '\x02') {
      cVar2 = (char)*(undefined2 *)(unaff_ER14 + -2);
      if (cVar2 == '\x01' &&
          (bool)((char)((ushort)*(undefined2 *)(unaff_ER14 + -2) >> 8) + '\x12') == (cVar2 == '\0'))
      {
        *(undefined2 *)(unaff_ER14 + -2) = 0xfc40;
      }
      input_key = *(undefined2 *)(unaff_ER14 + -2);
      goto LAB_rom_00c44a;
    }
    if (cVar2 != '\x03') goto LAB_rom_00c44a;
    uVar6 = *(ushort *)(unaff_ER14 + -2);
    bVar7 = (byte)(uVar6 >> 8);
    bVar1 = (byte)uVar6;
    if ((0xed00 < uVar6) &&
       (uVar4 = (bVar7 - 0xed) - (ushort)(bVar1 < 8),
       (uVar4 & 0x100) != 0 || bVar1 == 8 && (char)uVar4 == '\0')) {
      if ((_a1 == '\0') && (uVar4 = set_list_mode(), (char)uVar4 != '\0')) {
        sub_mode = *(char *)(unaff_ER14 + -2);
        stat_sel = 0;
        stat_rows = 0;
        stat_cols = 0;
        clear_replay_buf((undefined *)(uVar4 & 0xff00),uVar6);
LAB_rom_00c496:
        edit_state2 = '\x12';
        stat_table_reset();
      }
      goto LAB_rom_00c44a;
    }
    if (bVar1 == 0x14 && (bool)(bVar7 + 0x13) == bVar1 < 0x14) goto LAB_rom_00c496;
    if (bVar1 == 0x15 && (bool)(bVar7 + 0x13) == bVar1 < 0x15) {
      if (edit_state2 == '\x12') {
        key_mod_clear();
        table_insert_row();
        stat_sel = 0;
        stat_rows = 0;
        stat_cols = 0;
      }
      goto LAB_rom_00c44a;
    }
    if (bVar1 == 0x16 && (bool)(bVar7 + 0x13) == bVar1 < 0x16) {
      if (edit_state2 == '\x12') {
        key_mod_clear();
        cursor_home_ui();
      }
      goto LAB_rom_00c44a;
    }
    if (bVar1 == 0x17 && (bool)(bVar7 + 0x13) == bVar1 < 0x17) {
      if (sub_mode == '\x03') {
        uVar8 = 0x3c;
      }
      else {
        uVar8 = 0x3b;
      }
      uVar5 = CONCAT11(0xeb,uVar8);
      goto LAB_rom_00c446;
    }
    if (bVar1 == 0x1a && (bool)(bVar7 + 0x13) == bVar1 < 0x1a) {
      uVar5 = stat_table_page();
      cVar2 = (char)uVar5;
    }
    else if (bVar1 == 0x18 && (bool)(bVar7 + 0x13) == bVar1 < 0x18) {
      cVar2 = input_line_editor(uVar6);
    }
    else {
      if (bVar1 != 0x19 || (bool)(bVar7 + 0x13) != bVar1 < 0x19) goto LAB_rom_00c446;
      cVar2 = input_line_editor(uVar6);
    }
    uVar5 = uVar3;
    if (cVar2 != '\x02') {
LAB_rom_00c44a:
      frame_leave();
      return 0;
    }
  } while( true );
}

/**
 * @brief 返回当前表格/列表的行数（0x20E7A 句柄非空时遍历 0xB3DC）
 * @addr 0x0C640
 * @module setup
 * @proto byte table_row_count(void)
 * @confidence strong
 * @note 返回当前表格/列表的行数（0x20E7A 句柄非空时遍历 0xB3DC）。
 * @tag app
 */
byte table_row_count(void)

{
  char cVar1;
  char cVar2;
  undefined *puVar3;
  short sVar4;
  char cVar5;
  
  cVar2 = calc_mode;
  cVar5 = '\0';
  puVar3 = history_base_ptr();
  if ((((puVar3 != (undefined *)0x0) &&
       ((cVar2 != 'E' || (cVar1 = is_equation_mode(), cVar1 != '\0')))) &&
      ((cVar2 != 'J' || (cVar1 = is_mode_4a(), cVar1 != '\0')))) &&
     ((cVar2 != '\f' || (cVar2 = is_mode_0c(), cVar2 != '\0')))) {
    cVar5 = '\0';
    while (sVar4 = input_mark_hash(), sVar4 != 0) {
      cVar5 = cVar5 + '\x01';
    }
  }
  return cVar5;
}

/**
 * @brief 清屏后按 0xD163 起始行绘制统计表格（0x398E 表与行号 0x6474）并显示统计…
 * @addr 0x0C690
 * @module setup
 * @proto void stats_table_draw(void)
 * @confidence strong
 * @note 清屏后按 0xD163 起始行绘制统计表格（0x398E 表与行号 0x6474）并显示统计量。
 * @tag app
 */
int stats_table_draw(void)

{
  byte bVar1;
  ushort uVar2;
  short sVar3;
  byte bVar4;
  
  fill_screen(0x400);
  cur_line = 0xe;
  draw_target = 0;
  sVar3 = 0;
  do {
    uVar2 = CONCAT11((char)(((ushort)_DAT_ram_d163 << 2) >> 8),_DAT_ram_d163 << 2) + sVar3;
    bVar1 = (char)sVar3 * '\x10' + 1;
    draw_format_string(CONCAT11(bVar1,0x16), (uintptr_t)0)
                   *(char **)(CONCAT11((char)(((uVar2 & 0xff00) + (uVar2 & 0xff)) * 4 >> 8),
                                       (char)uVar2 << 2) + 0x398e));
    draw_char_fast((ushort)bVar1 << 8,*(byte *)(sVar3 + 0x6474));
    draw_char_fast(CONCAT11(bVar1,0xb),_DAT_ram_50be);
    if ((short)(ushort)_DAT_ram_5008 <=
        CONCAT11((char)(((ushort)_DAT_ram_d163 << 2) >> 8),_DAT_ram_d163 << 2) + sVar3) break;
    sVar3 = sVar3 + 1;
    bVar4 = (byte)((ushort)sVar3 >> 8);
    bVar1 = bVar4 - ((byte)sVar3 < 4);
  } while ((byte)((byte)((bVar1 ^ bVar4) & ~bVar1) >> 7 ^ (char)bVar1 < '\0') == 1);
  fb_alt_flush();
  draw_target = 1;
  draw_cursor_box();
  return 0;
}

/**
 * @brief 统计单元格按键（按 0xD112 列与 0xD136 类型分派）
 * @addr 0x0C726
 * @module setup
 * @proto int table_cell_key(void)
 * @confidence likely
 * @note 统计单元格按键（按 0xD112 列与 0xD136 类型分派）。
 * @tag app
 */
int table_cell_key(void)

{
  short sVar1;
  bool bVar2;
  undefined2 uVar3;
  ushort uVar4;
  byte bVar5;
  char cVar6;
  short unaff_ER14;
  
  uVar3 = frame_enter();
  bVar2 = true;
  sVar1 = (ushort)(byte)(sub_mode - 1) * 2;
  *(undefined2 *)(unaff_ER14 + -2) = *(undefined2 *)(sVar1 + 0x1af8);
  uVar4 = *(ushort *)(sVar1 + 0x66d4);
  *(ushort *)(unaff_ER14 + -4) = uVar4;
  bVar5 = (byte)uVar3;
  cVar6 = (char)((ushort)uVar3 >> 8);
  if (bVar5 == 0x1c && (bool)(cVar6 + '\x04') == bVar5 < 0x1c) {
    uVar4 = (ushort)list_col;
    if (1 < list_col) {
      list_col = list_col - 1;
      uVar4 = (ushort)list_col;
      bVar2 = false;
    }
  }
  else if (bVar5 == 0x1d && (bool)(cVar6 + '\x04') == bVar5 < 0x1d) {
    uVar4 = CONCAT11(*(byte *)(unaff_ER14 + -4),list_col);
    if (list_col < *(byte *)(unaff_ER14 + -4)) {
      if ((sub_mode == 5) && (list_row == 1)) {
        list_col = list_col + 1;
        bVar2 = false;
      }
      uVar4 = (ushort)sub_mode;
      if ((sub_mode == 6) &&
         ((uVar4 = (ushort)list_row, list_row == 1 || (list_row == 2)))) {
        list_col = list_col + 1;
        bVar2 = false;
      }
    }
  }
  else {
    if (bVar5 != 0x1e || (bool)(cVar6 + '\x04') != bVar5 < 0x1e) {
      if (bVar5 == 0x1f && (bool)(cVar6 + '\x04') == bVar5 < 0x1f) {
        if (list_row == 1) {
          uVar4 = (ushort)list_col;
          if (list_col != 1) {
            list_col = list_col - 1;
            list_row = *(byte *)(unaff_ER14 + -1);
            uVar4 = (ushort)list_row;
            bVar2 = false;
          }
        }
        else {
          list_row = list_row - 1;
          uVar4 = (ushort)list_row;
          bVar2 = false;
        }
        goto LAB_rom_00c76a;
      }
      if (bVar5 != 0x2d || (bool)(cVar6 + '\x04') != bVar5 < 0x2d) goto LAB_rom_00c76a;
    }
    if (list_row == 3) {
      uVar4 = CONCAT11(*(byte *)(unaff_ER14 + -4),list_col);
      if (list_col < *(byte *)(unaff_ER14 + -4)) {
        list_col = list_col + 1;
        uVar4 = 1;
        list_row = 1;
        bVar2 = false;
      }
    }
    else {
      uVar4 = (ushort)sub_mode;
      if (sub_mode == 4) {
        list_row = list_row + 1;
        bVar2 = false;
      }
      else {
        uVar4 = CONCAT11(*(byte *)(unaff_ER14 + -4),list_col);
        if (list_col == *(byte *)(unaff_ER14 + -4)) {
          uVar4 = (ushort)sub_mode;
          if ((sub_mode == 6) && (uVar4 = (ushort)list_row, list_row == 1)) {
            uVar4 = 2;
            list_row = 2;
            bVar2 = false;
          }
        }
        else {
          list_row = list_row + 1;
          bVar2 = false;
        }
      }
    }
  }
LAB_rom_00c76a:
  if (!bVar2) {
    key_hist_clear0((char)uVar4);
  }
  frame_leave();
  return 0;
}

