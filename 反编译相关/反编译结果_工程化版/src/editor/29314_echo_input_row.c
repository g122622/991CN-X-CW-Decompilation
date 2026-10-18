/*
 * 输入编辑器 / 29314_echo_input_row.c
 * 地址范围: 0x29314 - 0x29614
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 在行 0x0E 回显输入区
 * @addr 0x29314
 * @module editor
 * @proto void echo_input_row(void)
 * @confidence strong
 * @note 在行 0x0E 回显输入区：清屏、绘制 0xD180 字符串、写按键历史 0x0D。
 * @tag editor
 */
int echo_input_row(void)

{
  char *pcVar1;
  
  pcVar1 = (char *)frame_enter();
  line_col_count();
  clear_screen();
  cur_line = 0xe;
  input_read_str(pcVar1);
  draw_scaled_char(0x32, (uintptr_t)0);
  key_hist_set_hi('\r');
  frame_leave();
  return 0;
}

/**
 * @brief 编辑器主流程（11KB，0xB1A4 调用），最大化/最小化子入口均在体内
 * @addr 0x29614
 * @module editor
 * @proto void editor_main(undefined2 a)
 * @confidence strong
 * @note 编辑器主流程（11KB，0xB1A4 调用），最大化/最小化子入口均在体内。
 * @tag editor
 */
int editor_main(undefined2 a)

{
  undefined uVar1;
  bool bVar2;
  char cVar3;
  byte bVar4;
  int bVar5;
  int cVar6;
  short sVar7;
  char *pcVar8;
  undefined2 uVar9;
  ushort uVar10;
  byte bVar11;
  undefined uVar13;
  int bVar14;
  byte *pbVar15;
  short unaff_ER14;
  ushort uVar12;
  
  sVar7 = frame_enter();
  *(undefined *)(unaff_ER14 + -0xf) = 0;
  *(undefined *)(unaff_ER14 + -0x10) = 0;
  bVar11 = history_cursor;
  uVar13 = 0xd1;
  *(byte *)(unaff_ER14 + -3) = history_cursor;
  uVar1 = is_math_io();
  *(undefined *)(unaff_ER14 + -4) = uVar1;
  bVar2 = disp_busy();
  *(byte *)(uintptr_t)(bool *)(unaff_ER14 + -6) = bVar2;
  if (*(char *)(unaff_ER14 + -4) != '\0') {
    key_flag_clear_b7();
  }
  if (sVar7 == 0) goto LAB_rom_02964a;
  uVar1 = input_max_len();
  *(undefined *)(unaff_ER14 + -7) = uVar1;
  *(undefined *)(unaff_ER14 + -0xc) = 1;
  bVar14 = 0;
  cVar6 = (char)((ushort)sVar7 >> 8);
  bVar4 = (byte)sVar7;
  if (cVar6 == '\0') {
    **(byte **)(unaff_ER14 + 0x10) = bVar4;
    *(undefined *)(*(short *)(unaff_ER14 + 0x10) + 1) = 0;
  }
  else {
    **(char **)(unaff_ER14 + 0x10) = cVar6;
    *(byte *)(*(short *)(unaff_ER14 + 0x10) + 1) = bVar4;
    *(undefined *)(*(short *)(unaff_ER14 + 0x10) + 2) = 0;
    *(undefined *)(unaff_ER14 + -0xc) = 2;
  }
  *(undefined **)(unaff_ER14 + -0x12) = &input_buf + *(byte *)(unaff_ER14 + -3);
  dec_accum3 = 0;
  dec_accum4 = 0;
  dec_accum6 = 0;
  if (*(char *)(unaff_ER14 + -4) == '\0') {
LAB_rom_0299a2:
    bVar4 = strline_len(*(char **)(unaff_ER14 + 0x10));
    *(byte *)(unaff_ER14 + -0xd) = bVar4;
    *(ushort *)(unaff_ER14 + -2) = CONCAT11(-(bVar4 < bVar14),bVar4 - bVar14);
    if ((((*(char *)(unaff_ER14 + -4) == '\0') && (*(char *)(unaff_ER14 + -6) == '\x01')) &&
        (pbVar15 = *(byte **)(unaff_ER14 + -0x12), *pbVar15 != 0)) ||
       ((pbVar15 = *(byte **)(unaff_ER14 + -0x12), *pbVar15 == 0x19 && (bVar14 == 0)))) {
      *(short *)(unaff_ER14 + -2) = *(short *)(unaff_ER14 + -2) + -1;
      bVar2 = is_neg_char(*pbVar15);
      *(byte *)(uintptr_t)(bool *)(unaff_ER14 + -0xb) = bVar2;
      if (bVar2) {
        *(short *)(unaff_ER14 + -2) = *(short *)(unaff_ER14 + -2) + -1;
      }
      uVar1 = draw_token_text((uintptr_t)0);
      *(undefined *)(unaff_ER14 + -0xf) = uVar1;
      uVar1 = draw_token_text((uintptr_t)0);
      *(undefined *)(unaff_ER14 + -0x10) = uVar1;
    }
    bVar4 = strline_len(&input_buf);
    if ((byte)(bVar4 + *(char *)(unaff_ER14 + -2)) <= (byte)(*(char *)(unaff_ER14 + -7) - 1U)) {
      if (input_active != '\0') {
        dec_accum3 = *(undefined2 *)(unaff_ER14 + -2);
        bVar5 = draw_token_text((uintptr_t)0);
        dec_accum4 =
             CONCAT11(-(bVar5 < *(byte *)(unaff_ER14 + -0xf)),bVar5 - *(byte *)(unaff_ER14 + -0xf));
        dec_accum6 = (ushort)*(byte *)(unaff_ER14 + -0x10) + dec_accum4;
      }
      *(byte *)(unaff_ER14 + -3) = bVar11;
      sVar7 = *(short *)(unaff_ER14 + -2);
      *(undefined **)(unaff_ER14 + -10) = &input_buf + sVar7;
      if (sVar7 < 0 || (char)sVar7 == '\0' && (char)((ushort)sVar7 >> 8) == '\0') {
        if (sVar7 != 0) {
          cVar6 = *(char *)(unaff_ER14 + -3);
          while( true ) {
            bVar11 = cVar6 + 1;
            *(byte *)(unaff_ER14 + -0xb) = bVar11;
            if (bVar4 < bVar11) break;
            *(undefined *)((ushort)bVar11 + *(short *)(unaff_ER14 + -10)) = (&input_buf)[bVar11];
            cVar6 = *(char *)(unaff_ER14 + -0xb);
          }
        }
      }
      else {
        *(byte *)(unaff_ER14 + -0xb) = bVar4;
        while( true ) {
          uVar10 = (ushort)bVar14 + (ushort)*(byte *)(unaff_ER14 + -3);
          bVar11 = *(byte *)(unaff_ER14 + -0xb);
          uVar12 = (ushort)bVar11;
          if ((byte)(SBORROW2(uVar12,uVar10) ^ (short)(uVar12 - uVar10) < 0 | uVar12 == uVar10) != 0
             ) break;
          *(undefined *)((ushort)bVar11 + *(short *)(unaff_ER14 + -10)) = (&input_buf)[bVar11];
          *(char *)(unaff_ER14 + -0xb) = *(char *)(unaff_ER14 + -0xb) + -1;
        }
        *(undefined *)((ushort)bVar11 + *(short *)(unaff_ER14 + -10)) = (&input_buf)[bVar11];
      }
      *(undefined **)(unaff_ER14 + -0x12) = &input_buf + *(byte *)(unaff_ER14 + -3);
      uVar10 = 0;
      while (*(byte *)(unaff_ER14 + -0xb) = (byte)uVar10,
            (char)(((byte)uVar10 < *(byte *)(unaff_ER14 + -0xd)) << 7) < '\0') {
        *(undefined *)(uVar10 + *(short *)(unaff_ER14 + -0x12)) =
             *(undefined *)(uVar10 + *(short *)(unaff_ER14 + 0x10));
        uVar10 = (ushort)(byte)(*(char *)(unaff_ER14 + -0xb) + 1);
      }
      history_cursor = *(char *)(unaff_ER14 + -0xc) + *(char *)(unaff_ER14 + -3);
      goto LAB_rom_02964a;
    }
  }
  else {
    pcVar8 = (char *)input_history_ptr();
    strcpy_checked(pcVar8,&input_buf);
    input_saved = *(undefined *)(unaff_ER14 + -3);
    _DAT_ram_d15e = sVar7;
    uVar9 = is_ws_scan(*(char **)(unaff_ER14 + -0x12));
    *(char *)(unaff_ER14 + -5) = (char)uVar9;
    if (a == '\0') {
      if (((char)uVar9 != '\0') ||
         (uVar9 = key_is_cmp(*(char **)(unaff_ER14 + -0x12)), (char)uVar9 != '\0')) {
        uVar9 = token_class(*(char **)(unaff_ER14 + 0x10));
        cVar6 = is_key_allowed((byte)uVar9);
        if (cVar6 != '\0') {
          str_emit_19();
        }
        input_active = '\0';
      }
      if ((input_active != '\0') && (cVar6 = editor_key_step('\x01'), cVar6 != '\0')) {
        input_active = '\0';
      }
      goto LAB_rom_0299a2;
    }
    input_active = '\0';
    if ((((*(char *)(unaff_ER14 + -6) == '\x01') || (bVar4 == 0xc9 && (bool)cVar6 == bVar4 < 0xc9))
        || (bVar4 == 0xca && (bool)cVar6 == bVar4 < 0xca)) ||
       ((bVar4 == 200 && (bool)cVar6 == bVar4 < 200 ||
        (bVar4 == 0x18 && (bool)cVar6 == bVar4 < 0x18)))) {
      sVar7 = (ushort)*(byte *)(unaff_ER14 + -6) << 8;
      bVar14 = copy_edit_line(sVar7);
      uVar13 = (undefined)((ushort)sVar7 >> 8);
    }
    *(undefined *)(unaff_ER14 + -0xc) = 2;
    if (cVar6 == '\0') {
      if (((bVar4 == 0xd5) || (bVar4 == 0xd6)) || (bVar4 == 0xd4)) {
        **(undefined **)(unaff_ER14 + 0x10) = 0xc9;
        bVar14 = 0;
        *(undefined *)(unaff_ER14 + -0xc) = 4;
        if (bVar4 == 0xd4) {
          *(undefined *)(unaff_ER14 + -0xc) = 5;
        }
      }
      else if (bVar4 == 0x76) {
        **(undefined **)(unaff_ER14 + 0x10) = 0xca;
      }
    }
    else {
      *(undefined *)(unaff_ER14 + -0xc) = 3;
    }
    bVar5 = 0;
    uVar1 = token_line_index(*(byte **)(unaff_ER14 + 0x10));
    *(undefined *)(unaff_ER14 + -0xb) = uVar1;
    pcVar8 = *(char **)(unaff_ER14 + 0x10);
    if ((*pcVar8 == -0x37) &&
       (uVar9 = push_edit_cache(*(byte **)(unaff_ER14 + -0x12)), (char)uVar9 != '\0')) {
      *pcVar8 = '\0';
      str_emit_19();
      str_emit_1D4D();
      *(undefined *)(unaff_ER14 + -0xc) = 0;
      bVar5 = 1;
    }
    uVar1 = *(undefined *)(*(byte *)(unaff_ER14 + -0xb) + 0xabe);
    pcVar8 = (char *)CONCAT11(uVar13,uVar1);
    *(undefined *)(unaff_ER14 + -0xe) = uVar1;
    if (*(byte *)(unaff_ER14 + -7) <=
        (byte)(*(char *)(*(byte *)(unaff_ER14 + -0xb) + 0xabe) + bVar14 + *(char *)(unaff_ER14 + -5)
              + bVar5)) goto LAB_rom_0297d4;
    cVar3 = *(char *)(unaff_ER14 + -0xb);
    if (cVar3 == '\0') {
      str_emit_1A(*(char **)(unaff_ER14 + 0x10),pcVar8);
      if (bVar4 == 0xd5 && (bool)cVar6 == bVar4 < 0xd5) {
        strcat_checked(*(char **)(unaff_ER14 + 0x10),"2");
      }
      else if (bVar4 == 0xd6 && (bool)cVar6 == bVar4 < 0xd6) {
        strcat_checked(*(char **)(unaff_ER14 + 0x10),"3");
      }
      else if (bVar4 == 0xd4 && (bool)cVar6 == bVar4 < 0xd4) {
        str_emit_1D4F();
      }
      else {
        append_call_token(*(byte *)(unaff_ER14 + -3),bVar14);
      }
      str_emit_1B();
      goto LAB_rom_0299a2;
    }
    if (cVar3 == '\x01') {
      str_emit_1A(*(char **)(unaff_ER14 + 0x10),pcVar8);
      if (bVar4 == 0x7d && (bool)cVar6 == bVar4 < 0x7d) {
        *(undefined *)(unaff_ER14 + -0xb) = 0;
      }
      else {
        *(byte *)(unaff_ER14 + -0xb) = bVar14;
      }
      append_call_token(*(byte *)(unaff_ER14 + -3),*(byte *)(unaff_ER14 + -0xb));
      str_emit_1C();
      if (bVar4 == 0x7d && (bool)cVar6 == bVar4 < 0x7d) {
        *(byte *)(unaff_ER14 + -0xb) = bVar14;
      }
      else {
        *(undefined *)(unaff_ER14 + -0xb) = 0;
      }
      append_call_token(*(byte *)(unaff_ER14 + -3),*(byte *)(unaff_ER14 + -0xb));
      str_emit_1B();
      goto LAB_rom_0299a2;
    }
    if (cVar3 != '\x02') {
      if (cVar3 == '\x03') {
        str_emit_1A(*(char **)(unaff_ER14 + 0x10),pcVar8);
        append_call_token(*(byte *)(unaff_ER14 + -3),bVar14);
        str_emit_1C19x2_1B();
      }
      else if (cVar3 == '\x04') {
        *(undefined *)(unaff_ER14 + -0xc) = 4;
        goto LAB_rom_0298f4;
      }
      goto LAB_rom_0299a2;
    }
    *(undefined *)(unaff_ER14 + -0xc) = 3;
    if (bVar4 == 0x76 && (bool)cVar6 == bVar4 < 0x76) {
LAB_rom_029888:
      str_emit_1D1A();
      if (bVar4 == 0x76 && (bool)cVar6 == bVar4 < 0x76) {
        strcat_checked(*(char **)(unaff_ER14 + 0x10),"3");
        *(undefined *)(unaff_ER14 + -0xc) = 6;
      }
      else {
        append_call_token(bVar11,bVar5);
      }
      str_emit_1B1A();
      append_call_token(*(byte *)(unaff_ER14 + -3),bVar14);
      str_emit_1B1E();
      bVar14 = bVar14 + bVar5;
      goto LAB_rom_0299a2;
    }
LAB_rom_0298f4:
    uVar9 = edit_word_insert(*(byte **)(unaff_ER14 + -0x12));
    if ((char)uVar9 == '\0') {
LAB_rom_029942:
      if (*(char *)(unaff_ER14 + -0xb) == '\x04') {
        str_emit_1F();
        str_emit_1D1A();
        append_call_token(bVar11,bVar5);
        str_emit_1B1A();
        *(undefined *)(unaff_ER14 + -0xb) = 0;
        if (*(byte *)(unaff_ER14 + -3) != bVar11) {
          *(byte *)(unaff_ER14 + -0xb) = bVar14;
        }
        append_call_token(*(byte *)(unaff_ER14 + -3),*(byte *)(unaff_ER14 + -0xb));
        str_emit_1B1A();
        *(undefined *)(unaff_ER14 + -0xb) = 0;
        if (*(byte *)(unaff_ER14 + -3) == bVar11) {
          *(byte *)(unaff_ER14 + -0xb) = bVar14;
        }
        append_call_token(*(byte *)(unaff_ER14 + -3),*(byte *)(unaff_ER14 + -0xb));
        str_emit_1B1E();
        bVar14 = bVar14 + bVar5;
        goto LAB_rom_0299a2;
      }
      goto LAB_rom_029888;
    }
    uVar9 = row_value_edit();
    *(undefined2 *)(unaff_ER14 + -10) = uVar9;
    bVar5 = (char)*(undefined2 *)(unaff_ER14 + -0x12) - (char)*(char **)(unaff_ER14 + -10);
    if (bVar5 != 0) {
      uVar9 = is_ws_scan(*(char **)(unaff_ER14 + -10));
      if ((char)(((byte)(*(char *)(unaff_ER14 + -5) + bVar14 + bVar5 + (char)uVar9 +
                        *(char *)(unaff_ER14 + -0xe)) < *(byte *)(unaff_ER14 + -7)) << 7) < '\0') {
        bVar11 = bVar11 - bVar5;
        *(byte *)(unaff_ER14 + -0xc) = *(char *)(unaff_ER14 + -0xc) + (char)uVar9 + bVar5 + '\x02';
        goto LAB_rom_029942;
      }
    }
  }
LAB_rom_0297d4:
  _DAT_ram_d15e = 0;
LAB_rom_02964a:
  frame_leave();
  return 0;
}

