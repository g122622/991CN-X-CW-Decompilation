/*
 * 行打印与文本 / 23518_is_noop_mode.c
 * 地址范围: 0x23518 - 0x23CCE
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 判断当前模式是否无需处理（0xD117 bit4 / 0x1EB86）
 * @addr 0x23518
 * @module textlib
 * @proto byte is_noop_mode(undefined2 k)
 * @confidence likely
 * @note 判断当前模式是否无需处理（0xD117 bit4 / 0x1EB86）。
 * @tag ui
 */
byte is_noop_mode(undefined2 k)

{
  char cVar1;
  byte bVar3;
  short sVar2;
  
  bVar3 = (byte)((ushort)k >> 8);
  if ((((*(char *)((uintptr_t)k + 6) == -0x3c) || ((key_history_flags & 0x10) != 0)) ||
      (cVar1 = '\0', bVar3 = 0, is_equation_mode(), cVar1 != '\0')) ||
     (cVar1 = '\0', bVar3 = 0, editor_accept_ready(), cVar1 != '\0')) {
    sVar2 = CONCAT11(bVar3,1);
  }
  else {
    sVar2 = (ushort)bVar3 << 8;
  }
  return sVar2;
}

/**
 * @brief 统计表单元格编辑
 * @addr 0x235B8
 * @module textlib
 * @proto void stat_cell_edit(void)
 * @confidence likely
 * @note 统计表单元格编辑：按 0xD169 与 0xDDB0 状态调用 0xFB98/0xD806/0xDDB0。
 * @tag app
 */
int stat_cell_edit(int _a1)

{
  int cVar1;
  bool bVar2;
  int bVar3;
  byte *pbVar4;
  
  pbVar4 = (byte *)frame_enter();
  cVar1 = editor_key_step('\x01');
  if (cVar1 != '\0') {
    input_active = '\0';
  }
  if (input_active != '\0') {
    bVar2 = is_neg_char(*pbVar4);
    dec_accum3 = CONCAT11(-((char)(bVar2 + '\x01') != '\0'),-(bVar2 + '\x01'));
    cVar1 = draw_token_text((uintptr_t)0);
    dec_accum4 = CONCAT11(-(cVar1 != '\0'),-cVar1);
    dec_accum6 = dec_accum4;
    if (_a1 == '\0') {
      bVar3 = draw_token_text((uintptr_t)0);
      dec_accum6 = dec_accum6 + (ushort)bVar3;
    }
  }
  frame_leave();
  return 0;
}

/**
 * @brief token 首字节 0x2E..0x33 等映射为固定双字节符号码（0xFB1A 等）
 * @addr 0x23626
 * @module textlib
 * @proto ushort token_sym_code(ushort tok)
 * @confidence likely
 * @note token 首字节 0x2E..0x33 等映射为固定双字节符号码（0xFB1A 等）。
 * @tag parser
 */
ushort token_sym_code(ushort tok)

{
  byte bVar1;
  char cVar2;
  
  bVar1 = (byte)tok;
  cVar2 = (char)((ushort)tok >> 8);
  if (bVar1 == 0x2e && (bool)(cVar2 + '\x04') == bVar1 < 0x2e) {
    return 0xfb1a;
  }
  if (bVar1 == 0x2f && (bool)(cVar2 + '\x04') == bVar1 < 0x2f) {
    return 0xfb1b;
  }
  return *(undefined2 *)(tok * 2 + 0x1086);
}

/**
 * @brief 表格计算与绘制（3.1KB，0xDAA4/0x23780 使用）
 * @addr 0x23648
 * @module textlib
 * @proto void table_calc_draw(void)
 * @confidence likely
 * @note 表格计算与绘制（3.1KB，0xDAA4/0x23780 使用）。
 * @tag app
 */
int table_calc_draw(uintptr_t _a2, int _a1)

{
  byte bVar1;
  int cVar2;
  char cVar3;
  byte bVar4;
  undefined2 *puVar5;
  short sVar6;
  byte *pbVar7;
  byte bVar9;
  short sVar8;
  undefined2 *puVar10;
  short unaff_ER14;
  
  puVar5 = (undefined2 *)frame_enter();
  *_a1 = '\0';
  if (puVar5 != (undefined2 *)0x0) {
    if (*(char *)(unaff_ER14 + 0x10) == '\x02') {
      sVar6 = -2;
    }
    else {
      sVar6 = -9;
    }
    puVar10 = puVar5;
    dec_copy((undefined2 *)(unaff_ER14 + -10),puVar5);
    cVar2 = dec_exp_shift((undefined2 *)(unaff_ER14 + -10), (uintptr_t)0)
                           CONCAT11((char)((ushort)puVar10 >> 8),0xb));
    if (cVar2 != '\0') {
      dec_copy((undefined2 *)(unaff_ER14 + -10),puVar5);
    }
    pbVar7 = dec_parse((byte *)(unaff_ER14 + -10),(byte **)(unaff_ER14 + -0x22));
    if ((char)pbVar7 != '\0') {
      *(undefined2 *)(unaff_ER14 + -0x10) = 0;
      cVar2 = token_list_draw(CONCAT11(*(undefined *)(unaff_ER14 + 0x14))
                                      *(undefined *)(unaff_ER14 + 0x12)));
      cVar3 = *(char *)(unaff_ER14 + 0x12);
      if (((cVar3 == '\x01') || (cVar3 == '\x03')) || (cVar3 == '\x02')) {
        bVar4 = (byte)*(undefined2 *)(unaff_ER14 + -0x12);
        bVar9 = (byte)((ushort)*(undefined2 *)(unaff_ER14 + -0x12) >> 8);
        bVar1 = bVar9 - (bVar4 < 9);
        if ((((byte)((byte)((bVar1 ^ bVar9) & ~bVar1) >> 7 ^ (char)bVar1 < '\0' |
                    (bVar4 == 9 && bVar1 == 0)) == 0) ||
            (bVar1 = (bVar9 + 1) - (bVar4 < 0xf7),
            (bool)((byte)((bVar1 ^ bVar9) & (~bVar1 ^ 0xff)) >> 7) != (char)bVar1 < '\0')) &&
           (((cVar2 == '\0' && (*(char *)(unaff_ER14 + -0x19) != '\0')) ||
            ((cVar2 != '\0' &&
             (bVar4 = (byte)((ushort)*(undefined2 *)(unaff_ER14 + -0x10) >> 8),
             bVar1 = bVar4 - ((byte)*(undefined2 *)(unaff_ER14 + -0x10) < 9),
             (bool)((byte)((bVar1 ^ bVar4) & ~bVar1) >> 7) != (char)bVar1 < '\0')))))) {
          table_row_paint(_a1);
          goto LAB_rom_02365c;
        }
      }
      *(undefined *)(unaff_ER14 + -0xd) = 1;
      sVar8 = *(short *)(unaff_ER14 + -0x12);
      if ((((byte)(SBORROW2(sVar8,sVar6) ^ sVar8 - sVar6 < 0) == 1) ||
          (bVar4 = (byte)((ushort)sVar8 >> 8), bVar1 = bVar4 - ((byte)sVar8 < 10),
          (bool)((byte)((bVar1 ^ bVar4) & ~bVar1) >> 7) == (char)bVar1 < '\0')) || (cVar2 != '\0'))
      {
        fmt_number(unaff_ER14 + -0x22,(char *)(unaff_ER14 + -0x2c));
        *(undefined *)(unaff_ER14 + -0xe) = 0xb;
        if (cVar2 != '\0') {
          edit_clamp_offset(unaff_ER14 + -0x22);
        }
        fmt_sci(unaff_ER14 + -0x22,_a1);
        strcat_checked(_a1,(char *)(unaff_ER14 + -0x2c));
      }
      else {
        *(short *)(unaff_ER14 + -0x10) = sVar8;
        if (*(short *)(unaff_ER14 + -0x12) < 0) {
          cVar2 = *(char *)(unaff_ER14 + -0x12) + '\f';
        }
        else {
          cVar2 = '\n';
        }
        *(char *)(unaff_ER14 + -0xe) = cVar2;
        fmt_sci(unaff_ER14 + -0x22,_a1);
      }
    }
  }
LAB_rom_02365c:
  frame_leave();
  return 0;
}

/**
 * @brief 按当前行（0xD137）返回可用列数（10 或 6）
 * @addr 0x23A0C
 * @module textlib
 * @proto uchar line_col_count(void)
 * @confidence strong
 * @note 按当前行（0xD137）返回可用列数（10 或 6）。
 * @tag text
 */
uchar line_col_count(void)

{
  undefined uVar1;
  
  uVar1 = 0xb;
  if (cur_line == '\n') {
    uVar1 = 6;
  }
  return uVar1;
}

/**
 * @brief 向导流程（1.5KB，无外部调用者）
 * @addr 0x23A3E
 * @module textlib
 * @proto void wizard_flow(void)
 * @confidence likely
 * @note 向导流程（1.5KB，无外部调用者）。
 * @tag ui
 */
int wizard_flow(void)

{
  byte *pbVar1;
  int bVar2;
  int cVar3;
  byte *pbVar4;
  ushort uVar5;
  undefined2 uVar6;
  byte bVar7;
  byte *pbVar8;
  short unaff_ER14;
  
  frame_enter();
  cVar3 = _DAT_ram_d15b;
  bVar7 = _DAT_ram_d15a;
  if (_DAT_ram_d15a != 0) {
    bVar2 = line_col_count();
    pbVar1 = input_ptr;
    bVar2 = draw_spaced(CONCAT11(-(0xc0 < history_key),-0x40 - history_key),(ushort)bVar2);
    *(byte **)(unaff_ER14 + -2) = input_ptr + bVar7;
    bVar7 = 0;
    if (cVar3 != '\0') {
      pbVar4 = prev_char_ptr(pbVar1,*(byte **)(unaff_ER14 + -2));
      *(byte **)(unaff_ER14 + -2) = pbVar4;
      bVar7 = cVar3 - 1;
    }
    do {
      pbVar8 = *(byte **)(unaff_ER14 + -2);
      pbVar4 = prev_char_ptr(pbVar1,pbVar8);
      *(byte **)(unaff_ER14 + -2) = pbVar4;
      if (pbVar4 == (byte *)0x0) {
        _DAT_ram_d15b = '\0';
        _DAT_ram_d15a = 0;
        goto LAB_rom_023a52;
      }
      uVar5 = token_at(*(byte **)(unaff_ER14 + -2));
      uVar6 = key_is_23(uVar5);
      if ((char)uVar6 != '\0') {
        list_view_main();
        goto LAB_rom_023a52;
      }
      cVar3 = text_clear_panel(uVar5,(byte *)(unaff_ER14 + -0x24));
      bVar7 = bVar7 + cVar3;
    } while ((char)((bVar7 < bVar2) << 7) < '\0');
    if (bVar2 == bVar7) {
      _DAT_ram_d15a = *(char *)(unaff_ER14 + -2) - (char)pbVar1;
      _DAT_ram_d15b = '\0';
    }
    else {
      _DAT_ram_d15a = (char)pbVar8 - (char)pbVar1;
      _DAT_ram_d15b = (bVar7 - bVar2) + '\x01';
    }
  }
LAB_rom_023a52:
  frame_leave();
  return 0;
}

/**
 * @brief 沿 0x42BA 表遍历（最多 10 步），返回终止项值
 * @addr 0x23B70
 * @module textlib
 * @proto ushort kdf_chain_42ba(byte idx)
 * @confidence likely
 * @note 沿 0x42BA 表遍历（最多 10 步），返回终止项值。
 * @tag setup
 */
ushort kdf_chain_42ba(byte _a1)

{
  byte bVar1;
  short sVar2;
  ushort uVar3;
  char cVar4;
  
  bVar1 = frame_enter();
  cVar4 = '\n';
  uVar3 = (ushort)bVar1;
  do {
    sVar2 = mul16(uVar3,0x1a);
    uVar3 = *(ushort *)(sVar2 + 0x42ba);
    if (((byte)uVar3 == 7 && (bool)((char)(uVar3 >> 8) + '\x12') == (byte)uVar3 < 7) || (uVar3 == 0)
       ) break;
    uVar3 = uVar3 & 0xff;
    cVar4 = cVar4 + -1;
  } while (cVar4 != '\0');
  frame_leave();
  return;
}

/**
 * @brief 菜单层处理（1.7KB，0x9972/0xED28 调用，含合并子入口）
 * @addr 0x23BD6
 * @module textlib
 * @proto int menu_layer(void)
 * @confidence strong
 * @note 菜单层处理（1.7KB，0x9972/0xED28 调用，含合并子入口）。
 * @tag ui
 */
int menu_layer(uintptr_t _a2, int _a1)

{
  short sVar1;
  char cVar2;
  int bVar3;
  bool bVar4;
  char cVar5;
  byte *pbVar6;
  undefined2 uVar7;
  undefined extraout_R1;
  short sVar8;
  char *pcVar9;
  char cVar10;
  byte *pbVar11;
  short unaff_ER14;
  
  pbVar6 = (byte *)frame_enter();
  sVar1 = input_ptr;
  cVar2 = '\0';
  while (pbVar11 = pbVar6, cVar10 = cVar2, cVar2 = history_cursor, *pbVar11 != 0) {
    uVar7 = token_class((char *)pbVar11);
    cVar5 = (char)uVar7;
    cVar2 = cVar10;
    if ((cVar5 == '\b') || (cVar5 == '\n')) {
      bVar3 = menu_close((char)_a1);
      if ((pbVar11[bVar3] == 0x1b) || (pbVar11[bVar3] == 0x1c)) break;
    }
    else if (cVar5 == '\t') {
      _a1 = (undefined *)(unaff_ER14 + -1);
      sVar8 = skip_expr_end(_a1);
      if ((*(char *)(unaff_ER14 + -1) == '\0') && (sVar8 != sVar1)) break;
    }
    else if (cVar5 == '\f') {
      if (*pbVar11 == 0x2c) {
        _a1 = (undefined *)(unaff_ER14 + -1);
        pcVar9 = (char *)skip_expr_end(_a1);
        if ((*(char *)(unaff_ER14 + -1) != '\0') &&
           (((((cVar5 = *pcVar9, cVar5 == '}' || (cVar5 == '~')) || (cVar5 == '\x7f')) ||
             ((cVar5 == -0x79 || (cVar5 == -0x76)))) ||
            ((cVar5 == -0x78 || ((cVar5 == -0x77 || (cVar5 == -0x6d)))))))) goto LAB_rom_023c18;
      }
      _a1 = (undefined *)(unaff_ER14 + -1);
      sVar8 = table_paste(_a1);
      if (sVar8 != 0) break;
    }
LAB_rom_023c18:
    bVar4 = is_neg_char(*pbVar11);
    cVar2 = cVar10 + '\x01';
    pbVar6 = pbVar11 + 1;
    if (CONCAT11(extraout_R1,bVar4) != 0) {
      cVar2 = cVar10 + '\x02';
      pbVar6 = pbVar11 + 2;
    }
  }
  history_cursor = cVar2;
  frame_leave();
  return 0;
}

/**
 * @brief 按模式 m 初始化 0xD012..0xD017/0xD138/0xD169 状态并设置 0…
 * @addr 0x23CCE
 * @module textlib
 * @proto void mode_state_init(char m, char flag)
 * @confidence strong
 * @note 按模式 m 初始化 0xD012..0xD017/0xD138/0xD169 状态并设置 0xD137。
 * @tag ui
 */
int mode_state_init(char m, char flag)

{
  char cVar1;
  
  cur_line = 0xe;
  edit_state = m;
  if ((flag == '\x03') || ((cVar1 = is_stat_edit4(), cVar1 != '\0' && (menu_io == '\0'))))
  {
    cur_line = prev_line;
  }
  display_dirty = 0;
  irq_pending_shadow = 0;
  _DAT_ram_d013 = 1;
  if ((m == '\0') || (m == '\x02')) {
    input_active = 0;
  }
  _DAT_ram_d017 = 0;
  cursor_visible = 0;
  dec_regY_mant = 0;
  return 0;
}

