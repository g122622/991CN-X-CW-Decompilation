/*
 * 应用模式 / 2b00a_list_ui_loop.c
 * 地址范围: 0x2B00A - 0x2B4FC
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 列表式界面主循环（0xD116 状态、调用 0xB032 画光标、process_key 读…
 * @addr 0x2B00A
 * @module apps
 * @proto void list_ui_loop(byte* input)
 * @confidence strong
 * @note 列表式界面主循环（0xD116 状态、调用 0xB032 画光标、process_key 读键）。
 * @tag ui
 */
int list_ui_loop(byte* input)

{
  byte bVar1;
  int cVar2;
  undefined uVar3;
  ushort uVar4;
  undefined2 uVar5;
  short sVar6;
  char cVar7;
  
LAB_rom_02b01a:
  do {
    if (key_modifiers != '\x05') {
      key_modifiers = '\x03';
    }
    cursor_draw_list();
    fb_flush();
    do {
      while( true ) {
        uVar4 = process_key((short)input);
        set_input_key(uVar4);
        uVar5 = key_is_extended(uVar4);
        if ((char)uVar5 != '\0') {
          if (calc_mode == -0x78) goto LAB_rom_02b01a;
          if (calc_mode == '\f') {
            if ((list_row == '\x02') || (sVar6 = key_filter_mode(uVar4), sVar6 == 0))
            goto LAB_rom_02b01a;
            if (key_modifiers == '\x05') {
              key_modifiers = '\x03';
            }
            cursor_draw_list();
          }
          table_copy(input);
          uVar4 = input_key;
          bVar1 = (byte)input_key;
          cVar2 = (char)(input_key >> 8);
          if (((bVar1 == 0x2d && (bool)(cVar2 + '\x04') == bVar1 < 0x2d) ||
              (bVar1 == 0x30 && (bool)(cVar2 + '\x04') == bVar1 < 0x30)) && (calc_mode == -0x78))
          {
            table_edit_enter(input);
          }
          goto LAB_rom_02b09a;
        }
        uVar5 = key_is_menu_key(uVar4);
        if ((char)uVar5 != '\0') break;
        bVar1 = (byte)uVar4;
        cVar7 = (char)(uVar4 >> 8);
        cVar2 = is_arrow_key(bVar1,cVar7);
        if (cVar2 == '\0') {
          if (bVar1 == 0x3e && (bool)(cVar7 + '\x04') == bVar1 < 0x3e) {
            if (calc_mode != -0x78) {
              uVar3 = table_cell_addr();
              key_hist_clear0(uVar3);
              stat_sel = 0;
              stat_rows = 0;
              stat_cols = 0;
              if (calc_mode == '\f') {
                list_row = '\x01';
                key_modifiers = '\x03';
              }
            }
          }
          else if ((bVar1 == 0x26 && (bool)(cVar7 + '\x04') == bVar1 < 0x26) ||
                  (bVar1 == 0x40 && (bool)(cVar7 + '\x04') == bVar1 < 0x40)) {
            if (calc_mode != '\f') {
              edit_state2 = 1;
              return 0;
            }
            list_page = 1;
            list_row = '\x01';
            list_col = 1;
            if (key_modifiers == '\x05') {
              key_modifiers = '\x03';
            }
          }
          else {
            uVar5 = keycode_norm(uVar4);
            if (((char)uVar5 == '\0') || (calc_mode != '\f')) {
              if ((bVar1 == 1 && (bool)(cVar7 + '\x04') == (bVar1 == 0)) && (calc_mode == '\f'))
              {
                return 0;
              }
            }
            else {
              menu_scroll();
            }
          }
          goto LAB_rom_02b09a;
        }
        key_flag_bit7();
        cVar2 = table_edit_flow();
        if (cVar2 == '\0') goto LAB_rom_02b09a;
        key_flag_clear();
      }
      bVar1 = bcd_type((byte *)0xd16c);
    } while (bVar1 != 0);
    edit_ctx_check();
LAB_rom_02b09a:
    if ((byte)uVar4 == 0x24 && (bool)((char)(uVar4 >> 8) + '\x04') == (byte)uVar4 < 0x24) {
      return 0;
    }
  } while( true );
}

/**
 * @brief 矩阵计算主流程（6.8KB，0x256E0 调用）
 * @addr 0x2B198
 * @module apps
 * @proto void matrix_calc_main(void)
 * @confidence likely
 * @note 矩阵计算主流程（6.8KB，0x256E0 调用）。
 * @tag matrix
 */
int matrix_calc_main(uintptr_t _a2, int _a1)

{
  bool bVar1;
  char cVar2;
  byte bVar3;
  byte bVar4;
  short sVar5;
  short sVar6;
  ushort uVar7;
  char cVar10;
  undefined2 uVar8;
  undefined2 uVar9;
  byte bVar11;
  ushort uVar12;
  undefined2 *puVar13;
  short sVar14;
  short unaff_ER14;
  
  sVar5 = frame_enter();
  bVar4 = 0;
  *(undefined *)(unaff_ER14 + -0x65) = 0;
  do {
    if (bVar4 == 0) {
      uVar12 = 8;
      sVar6 = sVar5;
      sVar14 = unaff_ER14;
      do {
        *(undefined2 *)(sVar14 + -0x2a) = *(undefined2 *)(sVar6 + 8);
        sVar6 = sVar6 + -2;
        sVar14 = sVar14 + -2;
        bVar1 = 1 < uVar12;
        uVar12 = uVar12 - 2;
      } while ((char)(bVar1 << 7) < '\0');
    }
    else {
      uVar12 = 8;
      sVar6 = sVar5;
      sVar14 = unaff_ER14;
      do {
        *(undefined2 *)(sVar14 + -0x2a) = *(undefined2 *)(sVar6 + 0x12);
        sVar6 = sVar6 + -2;
        sVar14 = sVar14 + -2;
        bVar1 = 1 < uVar12;
        uVar12 = uVar12 - 2;
      } while ((char)(bVar1 << 7) < '\0');
    }
    sVar14 = mul16((ushort)*(byte *)(unaff_ER14 + -0x65),10);
    sVar14 = sVar14 + unaff_ER14;
    uVar12 = 8;
    sVar6 = unaff_ER14;
    do {
      *(undefined2 *)(sVar14 + -0x3e) = *(undefined2 *)(sVar6 + -0x2a);
      sVar6 = sVar6 + -2;
      sVar14 = sVar14 + -2;
      bVar1 = 1 < uVar12;
      uVar12 = uVar12 - 2;
    } while ((char)(bVar1 << 7) < '\0');
    uVar7 = dec_type_of((undefined *)(unaff_ER14 + -0x32));
    cVar2 = (char)uVar7;
    cVar10 = (char)((ushort)unaff_ER14 >> 8);
    bVar3 = (byte)unaff_ER14;
    if (cVar2 == ' ') {
LAB_rom_02b268:
      dec_bcd_to_hex_bcd();
      bVar4 = 2;
    }
    else if (cVar2 == -0x80) {
      matrix_scan_1874a((undefined *)(unaff_ER14 + -0x32),uVar12);
      bVar4 = 4;
    }
    else {
      if (cVar2 == -0x10) goto LAB_rom_02b306;
      sVar6 = mul16((ushort)*(byte *)(unaff_ER14 + -0x65),10);
      eval_recip((undefined2 *)(sVar6 + CONCAT11(cVar10 + -1 + (0x45 < bVar3),bVar3 + 0xba)));
      sVar14 = mul16((ushort)*(byte *)(unaff_ER14 + -0x65),10);
      sVar14 = sVar14 + unaff_ER14;
      uVar12 = 8;
      sVar6 = unaff_ER14;
      do {
        *(undefined2 *)(sVar6 + -0x2a) = *(undefined2 *)(sVar14 + -0x3e);
        sVar14 = sVar14 + -2;
        sVar6 = sVar6 + -2;
        bVar1 = 1 < uVar12;
        uVar12 = uVar12 - 2;
      } while ((char)(bVar1 << 7) < '\0');
      uVar12 = dec_type_of((undefined *)(unaff_ER14 + -0x32));
      if ((char)uVar12 == ' ') goto LAB_rom_02b268;
      uVar12 = 8;
      sVar6 = unaff_ER14;
      do {
        uVar9 = *(undefined2 *)(sVar6 + -0x2a);
        *(undefined2 *)(sVar6 + -0x48) = uVar9;
        sVar6 = sVar6 + -2;
        bVar1 = 1 < uVar12;
        uVar12 = uVar12 - 2;
      } while ((char)(bVar1 << 7) < '\0');
      decm_round10(CONCAT11(cVar10 + -1 + (0x4f < bVar3),bVar3 + 0xb0),uVar9);
      uVar8 = dec_cmp((undefined2 *)CONCAT11(cVar10 + -1 + (0x4f < bVar3),bVar3 + 0xb0),uVar)
                            );
      if ((char)uVar8 != '\x01') goto LAB_rom_02b306;
      uVar12 = dec_unary_sin((undefined2 *)(unaff_ER14 + -0x32),uVar9);
      bVar11 = (byte)(uVar12 >> 8);
      bVar4 = bVar11 - ((byte)uVar12 < 9);
      if ((byte)((byte)((bVar4 ^ bVar11) & ~bVar4) >> 7 ^ (char)bVar4 < '\0' |
                ((byte)uVar12 == 9 && bVar4 == 0)) == 0) goto LAB_rom_02b306;
      dec_copy((undefined2 *)(unaff_ER14 + -0x1e),(undefined2 *)0x1b6c);
      bVar4 = 2;
    }
    sVar6 = mul16((ushort)bVar4,10);
    sVar14 = mul16((ushort)*(byte *)(unaff_ER14 + -0x65),10);
    dec_copy((undefined2 *)(sVar14 + CONCAT11(cVar10 + -1 + (99 < bVar3),bVar3 + 0x9c)), (uintptr_t)0)
                   (undefined2 *)(sVar6 + unaff_ER14 + -0x32));
    *(char *)(unaff_ER14 + -0x65) = *(char *)(unaff_ER14 + -0x65) + '\x01';
    bVar4 = *(byte *)(unaff_ER14 + -0x65);
  } while (bVar4 < 2);
  puVar13 = (undefined2 *)CONCAT11(cVar10 + -1 + (0x59 < bVar3),bVar3 + 0xa6);
  bVar4 = matrix_func_ext(CONCAT11(cVar10 + -1 + (99 < bVar3),bVar3 + 0x9c),puVar13);
  if ((bVar4 == 0) &&
     (uVar12 = dec_fmt_1b6c(CONCAT11(cVar10 + -1 + (99 < bVar3),bVar3 + 0x9c),puVar13),
     (uVar12 & 1) == 0)) {
    dec_copy(_a1,(undefined2 *)CONCAT11(cVar10 + -1 + (99 < bVar3),bVar3 + 0x9c));
    bVar4 = 0;
    *(undefined *)(unaff_ER14 + -0x65) = 0;
    do {
      sVar6 = mul16((ushort)bVar4,10);
      dec_bin_pow((undefined2 *)(sVar6 + CONCAT11(cVar10 + -1 + (0x45 < bVar3),bVar3 + 0xba)), (uintptr_t)0)
                     _a1);
      sVar6 = mul16((ushort)*(byte *)(unaff_ER14 + -0x65),10);
      uVar12 = dec_type_of((undefined *)
                              (sVar6 + CONCAT11(cVar10 + -1 + (0x45 < bVar3),bVar3 + 0xba)));
      cVar2 = (char)uVar12;
      if (cVar2 == ' ') goto LAB_rom_02b306;
      if (cVar2 != -0x80) {
        if (cVar2 == -0x10) goto LAB_rom_02b306;
        sVar14 = mul16((ushort)*(byte *)(unaff_ER14 + -0x65),10);
        sVar14 = sVar14 + unaff_ER14;
        uVar12 = 8;
        sVar6 = unaff_ER14;
        do {
          *(undefined2 *)(sVar6 + -0x48) = *(undefined2 *)(sVar14 + -0x3e);
          sVar14 = sVar14 + -2;
          sVar6 = sVar6 + -2;
          bVar1 = 1 < uVar12;
          uVar12 = uVar12 - 2;
        } while ((char)(bVar1 << 7) < '\0');
        decm_round10(CONCAT11(cVar10 + -1 + (0x4f < bVar3),bVar3 + 0xb0),uVar12);
        uVar9 = dec_cmp((undefined2 *)CONCAT11(cVar10 + -1 + (0x4f < bVar3),bVar3 + 0xb0), (uintptr_t)0)
                               uVar12);
        if ((char)uVar9 != '\x01') goto LAB_rom_02b306;
        sVar6 = mul16((ushort)*(byte *)(unaff_ER14 + -0x65),10);
        sVar14 = CONCAT11(cVar10 + -1 + (0x45 < bVar3),bVar3 + 0xba);
        uVar12 = dec_unary_sin((undefined2 *)(sVar6 + sVar14),sVar14);
        bVar11 = (byte)(uVar12 >> 8);
        bVar4 = bVar11 - ((byte)uVar12 < 9);
        if ((byte)((byte)((bVar4 ^ bVar11) & ~bVar4) >> 7 ^ (char)bVar4 < '\0' |
                  ((byte)uVar12 == 9 && bVar4 == 0)) == 0) goto LAB_rom_02b306;
      }
      *(char *)(unaff_ER14 + -0x65) = *(char *)(unaff_ER14 + -0x65) + '\x01';
      bVar4 = *(byte *)(unaff_ER14 + -0x65);
    } while (bVar4 < 2);
    uVar12 = 8;
    sVar6 = sVar5;
    sVar14 = unaff_ER14;
    do {
      *(undefined2 *)(sVar6 + 8) = *(undefined2 *)(sVar14 + -0x3e);
      sVar14 = sVar14 + -2;
      sVar6 = sVar6 + -2;
      bVar1 = 1 < uVar12;
      uVar12 = uVar12 - 2;
    } while ((char)(bVar1 << 7) < '\0');
    uVar12 = 8;
    do {
      *(undefined2 *)(sVar5 + 0x12) = *(undefined2 *)(unaff_ER14 + -0x34);
      unaff_ER14 = unaff_ER14 + -2;
      sVar5 = sVar5 + -2;
      bVar1 = 1 < uVar12;
      uVar12 = uVar12 - 2;
    } while ((char)(bVar1 << 7) < '\0');
  }
LAB_rom_02b306:
  frame_leave();
  return 0;
}

/**
 * @brief 矩阵存储（1.7KB，无外部调用者）
 * @addr 0x2B434
 * @module apps
 * @proto void matrix_store(void)
 * @confidence likely
 * @note 矩阵存储（1.7KB，无外部调用者）。
 * @tag matrix
 */
int matrix_store(void)

{
  byte bVar1;
  byte bVar2;
  int sVar3;
  char cVar4;
  ushort uVar5;
  
LAB_rom_02b438:
  stats_table_draw();
  do {
    sVar3 = input_is_empty();
    bVar1 = _DAT_ram_d163;
    bVar2 = (byte)sVar3;
    cVar4 = (char)((ushort)sVar3 >> 8);
    if ((((bVar2 == 0x31 && (bool)cVar4 == bVar2 < 0x31) ||
         (bVar2 == 0x32 && (bool)cVar4 == bVar2 < 0x32)) ||
        (bVar2 == 0x33 && (bool)cVar4 == bVar2 < 0x33)) ||
       (bVar2 == 0x34 && (bool)cVar4 == bVar2 < 0x34)) {
      uVar5 = CONCAT11((char)(((ushort)_DAT_ram_d163 << 2) >> 8),_DAT_ram_d163 << 2) + sVar3 + -0x31;
      if ((ushort)(CONCAT11((char)(((ushort)_DAT_ram_d163 << 2) >> 8),_DAT_ram_d163 << 2) +
                  sVar3 + -0x31) <= (ushort)_DAT_ram_5008) {
        return *(undefined *)
                (CONCAT11((char)(((uVar5 & 0xff00) + (uVar5 & 0xff)) * 4 >> 8),(char)uVar5 << 2) +
                0x398c);
      }
    }
    else {
      if (bVar2 == 3 && (bool)(cVar4 + '\x04') == bVar2 < 3) {
        return 9;
      }
      if (bVar2 == 0x1c && (bool)(cVar4 + '\x04') == bVar2 < 0x1c) {
        if (_DAT_ram_d163 == 0) {
          _DAT_ram_d163 = _DAT_ram_5008 >> 2;
        }
        else {
          _DAT_ram_d163 = _DAT_ram_d163 - 1;
        }
        goto LAB_rom_02b438;
      }
      if (bVar2 == 0x1d && (bool)(cVar4 + '\x04') == bVar2 < 0x1d) break;
      if (bVar2 == 0x26 && (bool)(cVar4 + '\x04') == bVar2 < 0x26) {
        return 9;
      }
    }
    beep();
  } while( true );
  uVar5 = (ushort)_DAT_ram_d163;
  sVar3 = draw_spaced((ushort)_DAT_ram_5008,4);
  if ((short)uVar5 < sVar3) {
    _DAT_ram_d163 = bVar1 + 1;
  }
  else {
    _DAT_ram_d163 = 0;
  }
  goto LAB_rom_02b438;
}

/**
 * @brief 把 token 转成可显示文本（9KB，0xED7C/0x23780 使用）
 * @addr 0x2B4FC
 * @module apps
 * @proto char token_to_text(byte* tok)
 * @confidence strong
 * @note 把 token 转成可显示文本（9KB，0xED7C/0x23780 使用）。
 * @tag parser
 */
char token_to_text(byte* tok)

{
  bool bVar1;
  bool bVar2;
  char cVar3;
  char cVar4;
  char *pcVar5;
  ushort uVar6;
  undefined2 uVar7;
  undefined2 uVar8;
  byte bVar9;
  undefined2 *puVar10;
  undefined uVar12;
  byte bVar13;
  byte *pbVar11;
  int cVar14;
  short unaff_ER14;
  
  pcVar5 = (char *)frame_enter();
  cVar14 = '\0';
  uVar6 = dec_type_of((undefined *)tok);
  cVar4 = (char)uVar6;
  if (cVar4 != -0x10) {
    puVar10 = tok;
    dec_copy((undefined2 *)(unaff_ER14 + -0x32),tok);
    puVar10 = (undefined2 *)((ushort)puVar10 & 0xff00);
    *pcVar5 = '\0';
    if (*(char *)(unaff_ER14 + 0x16) == '\x0f') {
      list_draw_rows();
    }
    else {
      uVar7 = base_submode();
      if (((char)uVar7 == '\0') || (cVar4 != ' ')) {
        decm_round10(unaff_ER14 + -0x32,puVar10);
        uVar7 = dec_cmp((undefined2 *)(unaff_ER14 + -0x32),puVar10);
        if ((char)uVar7 == '\x01') goto LAB_rom_02b53a;
        puVar10 = tok;
        uVar7 = dec_copy((undefined2 *)(unaff_ER14 + -0x32),tok);
      }
      lcd_mode_16(uVar7);
      if (cVar4 == ' ') {
        cVar14 = dec_bcd_to_hex_bcd();
      }
      else {
        if (cVar4 == -0x80) {
          if (((*(char *)(unaff_ER14 + 0x12) == '\0') && (*(char *)(unaff_ER14 + 0x14) == '\0')) ||
             (*(char *)(unaff_ER14 + 0x16) != '\r')) {
            dec_cmp_signed(tok,puVar10);
          }
          else {
            matrix_scan_1874a((undefined *)(unaff_ER14 + -0x32),puVar10);
            uVar7 = dec_cmp((undefined2 *)(unaff_ER14 + -0x1e),puVar10);
            cVar4 = (char)uVar7;
            uVar7 = dec_cmp((undefined2 *)(unaff_ER14 + -0x32),puVar10);
            cVar14 = (char)uVar7;
            uVar7 = dec_fmt_1b6c(unaff_ER14 + -10,puVar10);
            uVar12 = (undefined)((ushort)puVar10 >> 8);
            bVar1 = (char)uVar7 == '\x01';
            cVar3 = is_equation_mode();
            puVar10 = (undefined2 *)CONCAT11(uVar12,cVar3);
            bVar2 = false;
            if ((cVar3 != '\0') || (cVar3 = editor_accept_ready(), cVar3 != '\0')) {
              bVar2 = true;
            }
            if (cVar14 == '\x02') {
              if (cVar4 == '\x01') {
                dec_bin_result((ushort *)(unaff_ER14 + -0x32),puVar10);
                cVar14 = '\x04';
                puVar10 = (undefined2 *)
                          CONCAT11((char)((ushort)puVar10 >> 8),*(char *)(unaff_ER14 + 0x12));
                editor_selection(pcVar5,*(char *)(unaff_ER14 + 0x12));
              }
              else if (((!bVar2) && (cVar4 == '\x02')) &&
                      ((*(char *)(unaff_ER14 + 0x10) != '\0' || (!bVar1)))) {
                dec_bin_result((ushort *)(unaff_ER14 + -0x32),puVar10);
                dec_bin_result((ushort *)(unaff_ER14 + -0x1e),puVar10);
                cVar14 = '\x04';
                cVar4 = '\x04';
                puVar10 = (undefined2 *)
                          CONCAT11((char)((ushort)puVar10 >> 8),*(char *)(unaff_ER14 + 0x12));
                editor_selection(pcVar5,*(char *)(unaff_ER14 + 0x12));
              }
            }
            uVar12 = (undefined)((ushort)puVar10 >> 8);
            if (bVar1) {
              if ((*(char *)(unaff_ER14 + 0x10) != '\0') && (cVar4 != '\x01')) {
                puVar10 = (undefined2 *)CONCAT11(uVar12,*(char *)(unaff_ER14 + 0x12));
                emit_hint(pcVar5,*(char *)(unaff_ER14 + 0x12));
              }
            }
            else if (*(char *)(unaff_ER14 + 0x12) == '\0') {
              if (cVar4 != '\x01') {
                puVar10 = (undefined2 *)CONCAT11(uVar12,*(char *)(unaff_ER14 + 0x12));
                emit_hint(pcVar5,*(char *)(unaff_ER14 + 0x12));
              }
            }
            else {
              str_emit_1D31();
            }
            if (cVar14 == '\x02') {
              puVar10 = (undefined2 *)
                        CONCAT11((char)((ushort)puVar10 >> 8),*(char *)(unaff_ER14 + 0x12));
              editor_selection(pcVar5,*(char *)(unaff_ER14 + 0x12));
              dec_bin_result((ushort *)(unaff_ER14 + -0x32),puVar10);
            }
            uVar6 = dec_fmt_1b6c(unaff_ER14 + -0x28,puVar10);
            bVar13 = (byte)((ushort)puVar10 >> 8);
            puVar10 = (undefined2 *)CONCAT11(bVar13,1);
            if ((uVar6 & 1) == 0) {
              puVar10 = (undefined2 *)((ushort)bVar13 << 8);
            }
            cVar14 = (char)puVar10;
            uVar7 = dec_fmt_1b6c(unaff_ER14 + -0x32,puVar10);
            uVar12 = (undefined)((ushort)puVar10 >> 8);
            if (((char)uVar7 != '\x01') || (cVar14 != '\0')) {
              pbVar11 = (byte *)(unaff_ER14 + -0x32);
              append_number_str(pbVar11);
              uVar12 = (undefined)((ushort)pbVar11 >> 8);
            }
            if (cVar14 == '\0') {
              pbVar11 = (byte *)(unaff_ER14 + -0x28);
              draw_list_item(pbVar11);
              uVar12 = (undefined)((ushort)pbVar11 >> 8);
            }
            if (cVar4 != '\x01') {
              if (cVar4 == '\x02') {
                puVar10 = (undefined2 *)CONCAT11(uVar12,*(char *)(unaff_ER14 + 0x12));
                set_eol_marker(pcVar5,*(char *)(unaff_ER14 + 0x12));
              }
              else {
                puVar10 = (undefined2 *)CONCAT11(uVar12,*(char *)(unaff_ER14 + 0x12));
                set_cursor_visible(pcVar5,*(char *)(unaff_ER14 + 0x12));
              }
              dec_bin_result((ushort *)(unaff_ER14 + -0x1e),puVar10);
              uVar7 = dec_fmt_1b6c(unaff_ER14 + -0x1e,puVar10);
              if ((char)uVar7 != '\x01') {
                append_number_str((byte *)(unaff_ER14 + -0x1e));
              }
              draw_list_item((byte *)(unaff_ER14 + -0x14));
            }
            if (bVar1) {
              if ((*(char *)(unaff_ER14 + 0x10) != '\0') && (cVar4 != '\x01')) {
                str_emit_lparen_or_1D3D(pcVar5,*(char *)(unaff_ER14 + 0x12));
              }
            }
            else {
              if ((*(char *)(unaff_ER14 + 0x12) == '\0') && (cVar4 != '\x01')) {
                str_emit_lparen_or_1D3D(pcVar5,'\0');
              }
              wrap_9e4c((byte *)(unaff_ER14 + -10));
            }
          }
          goto LAB_rom_02b53a;
        }
        uVar6 = dec_unary_sin(tok,puVar10);
        bVar9 = (byte)(uVar6 >> 8);
        bVar13 = bVar9 - ((byte)uVar6 < 9);
        if ((byte)((byte)((bVar13 ^ bVar9) & ~bVar13) >> 7 ^ (char)bVar13 < '\0' |
                  ((byte)uVar6 == 9 && bVar13 == 0)) != 1) goto LAB_rom_02b53a;
        if (10 < *(byte *)(unaff_ER14 + 0x16)) {
          uVar6 = fmt_check((undefined2 *)(unaff_ER14 + -0x32));
          cVar14 = (char)uVar6;
        }
      }
      if (cVar14 == '\x01') {
        cVar4 = '\x01';
      }
      else {
        cVar4 = get_ptr_ffd8_1();
        if ((cVar4 != '\0') || (*(byte *)(unaff_ER14 + 0x16) < 0xd)) goto LAB_rom_02b53a;
        uVar6 = dec_unary_sin(tok,puVar10);
        bVar9 = (byte)(uVar6 >> 8);
        bVar13 = (bVar9 + 1) - ((byte)uVar6 < 0xf9);
        if (((bool)((byte)((bVar13 ^ bVar9) & (~bVar13 ^ 0xff)) >> 7) != (char)bVar13 < '\0') ||
           (*(char *)(unaff_ER14 + 0x12) == '\0')) goto LAB_rom_02b53a;
        uVar7 = draw_token_rich(unaff_ER14 + -0x32,puVar10);
        cVar4 = (char)uVar7;
        if (cVar4 == '\0') goto LAB_rom_02b53a;
      }
      uVar7 = dec_cmp((undefined2 *)(unaff_ER14 + -0x28),puVar10);
      if ((char)uVar7 == '\x01') {
        if (cVar4 != -1) goto LAB_rom_02b53a;
        append_number_str((byte *)(unaff_ER14 + -0x32));
      }
      else {
        dec_bin_result((ushort *)(unaff_ER14 + -0x32),puVar10);
        dec_bin_result((ushort *)(unaff_ER14 + -0x28),puVar10);
        bVar2 = false;
        uVar8 = dec_cmp((undefined2 *)(unaff_ER14 + -0x32),puVar10);
        bVar1 = (char)uVar8 == '\x01';
        cVar14 = *(char *)(unaff_ER14 + 0x16);
        if (cVar14 == '\f') {
          bVar2 = true;
        }
        else if (((cVar14 == '\0') || (cVar14 == '\r')) && (_DAT_ram_d11f != '\0')) {
          bVar2 = true;
        }
        if ((char)uVar7 == '\x02') {
          editor_selection(pcVar5,*(char *)(unaff_ER14 + 0x12));
        }
        if ((!bVar2) && (!bVar1)) {
          dec_bin_pow_core(unaff_ER14 + -0x32,unaff_ER14 + -0x1e);
          dec_bin_xor_core(unaff_ER14 + -0x28,(undefined2 *)(unaff_ER14 + -0x32));
        }
        if ((!bVar2) || (bVar1)) {
          if (*(char *)(unaff_ER14 + 0x12) != '\0') {
            str_emit_1D31();
          }
        }
        else {
          if (*(char *)(unaff_ER14 + 0x12) != '\0') {
            str_emit_181F1D1A();
          }
          append_number_str((byte *)(unaff_ER14 + -0x32));
          set_key_edge(pcVar5,*(char *)(unaff_ER14 + 0x12));
        }
        append_number_str((byte *)(unaff_ER14 + -0x28));
        wrap_9e4c((byte *)(unaff_ER14 + -0x1e));
      }
      if (cVar4 == -1) {
        parse_number_str(pcVar5,'\"');
      }
    }
  }
LAB_rom_02b53a:
  frame_leave();
  return;
}

