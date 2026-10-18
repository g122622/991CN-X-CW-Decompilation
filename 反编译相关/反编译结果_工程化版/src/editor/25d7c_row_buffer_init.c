/*
 * 输入编辑器 / 25d7c_row_buffer_init.c
 * 地址范围: 0x25D7C - 0x2648E
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 行缓冲初始化（2.1KB，0x9DC8/0xEE2A/0x1DD68 使用）
 * @addr 0x25D7C
 * @module editor
 * @proto int row_buffer_init(short* p)
 * @confidence likely
 * @note 行缓冲初始化（2.1KB，0x9DC8/0xEE2A/0x1DD68 使用）。
 * @tag editor
 */
int row_buffer_init(short* p)

{
  undefined uVar1;
  byte bVar2;
  byte *pbVar3;
  ushort uVar4;
  undefined2 uVar5;
  short sVar6;
  short sVar7;
  short unaff_ER14;
  
  pbVar3 = (byte *)frame_enter();
  *(undefined2 *)(unaff_ER14 + -0xe) = *(undefined2 *)(unaff_ER14 + 0x10);
  uVar1 = is_stat_mode();
  *(undefined *)(unaff_ER14 + -0xc) = uVar1;
  uVar1 = is_d015_1_3();
  *(undefined *)(unaff_ER14 + -10) = uVar1;
  *(undefined *)(unaff_ER14 + -0xb) = irq_pending_shadow;
  if ((((char)((_DAT_ram_d013 < 0x3e) << 7) < '\0') &&
      (dec_regY_mant = dec_regY_mant + 1, dec_regY_mant < 0x1c)) &&
     (uVar4 = stack_depth(), ((uVar4 >> 8) - (ushort)((byte)uVar4 < 200) & 0x100) == 0)) {
    *p = 0;
    uVar1 = editor_max_cols();
    *(undefined *)(p + 1) = uVar1;
    uVar1 = input_cols();
    *(undefined *)((short)p + 3) = uVar1;
    uVar1 = line_col_count();
    *(undefined *)(unaff_ER14 + -0xf) = uVar1;
    sVar6 = *p;
    sVar7 = p[1];
    *(short *)(unaff_ER14 + -4) = sVar6;
    *(short *)(unaff_ER14 + -2) = sVar7;
    *(short *)(unaff_ER14 + -8) = sVar6;
    *(short *)(unaff_ER14 + -6) = sVar7;
    if (*(char *)(unaff_ER14 + -10) == '\0') {
      var_slot_write(*(undefined2 *)(unaff_ER14 + 0x10));
    }
    else {
      uVar5 = find_table_row((char)pbVar3);
      *(char *)(unaff_ER14 + -0xb) = (char)uVar5;
    }
    uVar4 = *p + *(short *)(unaff_ER14 + -0xe);
    *(ushort *)(unaff_ER14 + 0x10) = uVar4;
    table_key_dispatch(uVar4);
    token_at(pbVar3);
    uVar4 = token_class((char *)pbVar3);
    bVar2 = (byte)uVar4;
    if ((-(ushort)(bVar2 < 0xd) & 0x100) != 0 ||
        bVar2 == 0xd && (char)-(ushort)(bVar2 < 0xd) == '\0') {
                    // WARNING: Could not recover jumptable at 0x025e4c. Too many branches
                    // WARNING: Treating indirect jump as call
      ((void)0);
      return 0;
    }
  }
  if (*(char *)(unaff_ER14 + -10) == '\0') {
    var_scalar_addr(*(byte *)(unaff_ER14 + -0xb));
  }
  dec_regY_mant = dec_regY_mant - 1;
  frame_leave();
  return 0;
}

/**
 * @brief 编辑字段绘制（1.4KB，0x1F8C8 调用）
 * @addr 0x260AC
 * @module editor
 * @proto int edit_field_draw(void)
 * @confidence likely
 * @note 编辑字段绘制（1.4KB，0x1F8C8 调用）。
 * @tag editor
 */
int edit_field_draw(uintptr_t _a2, int _a1)

{
  int cVar1;
  byte bVar2;
  short *psVar3;
  short sVar4;
  ushort *puVar5;
  undefined2 uVar6;
  undefined uVar8;
  ushort uVar7;
  byte bVar9;
  short unaff_ER14;
  
  uVar8 = (undefined)((ushort)_a1 >> 8);
  psVar3 = (short *)frame_enter();
  uVar6 = CONCAT11(uVar8,6);
  sVar4 = (ushort)*(byte *)((short)psVar3 + 5) * 6;
  screen_mode_blank(sVar4);
  if (((*(char *)(psVar3 + 2) == '\x02') && (*(char *)((short)psVar3 + 5) == '\x01')) &&
     (stat_sel == '\0')) {
    cVar1 = complex_eval(unaff_ER14 + -10,uVar6);
    fill_screen(0x400);
    if (cVar1 == '\x01') {
      wait_valid_key('\x01');
      goto LAB_rom_0260f8;
    }
  }
  bVar9 = 0;
  do {
    bVar2 = (char)sVar4 + bVar9;
    puVar5 = (ushort *)(*psVar3 + CONCAT11((char)(((ushort)bVar2 << 2) >> 8),bVar2 * '\x04'));
    uVar7 = *puVar5;
    if (((char)uVar7 != '\0' || (char)(uVar7 >> 8) != '\0') || *(char *)(puVar5 + 1) != '\0') {
      uVar6 = mul16((ushort)bVar9,10);
      draw_string(CONCAT11((char)uVar6 + '\x01',0x24), (uintptr_t)0)
                     *(undefined2 *)(psVar3[1] + (ushort)bVar2 * 2));
      cVar1 = draw_edit_string("=");
      if (cVar1 == '\x01') {
        wait_valid_key('\x01');
        goto LAB_rom_0260f8;
      }
    }
    bVar9 = bVar9 + 1;
  } while ((char)((bVar9 < 6) << 7) < '\0');
  draw_cursor_box();
LAB_rom_0260f8:
  frame_leave();
  return 0;
}

/**
 * @brief 变量编辑循环（1.2KB）
 * @addr 0x26248
 * @module editor
 * @proto void var_edit_loop(void)
 * @confidence likely
 * @note 变量编辑循环（1.2KB）。
 * @tag editor
 */
int var_edit_loop(uintptr_t _a2, int _a1)

{
  char cVar1;
  bool bVar2;
  short sVar3;
  byte bVar4;
  char cVar5;
  
  cVar1 = calc_mode;
  key_repeat_start();
  do {
    ui_update();
    fb_flush();
    sVar3 = process_key((short)_a1);
    if (cVar1 == -0x3c) {
      sVar3 = key_filter_52e8(sVar3);
    }
    set_input_key(sVar3);
    cVar5 = (char)((ushort)sVar3 >> 8);
    bVar4 = (byte)sVar3;
    if (((edit_state2 & 0x80) == 0) ||
       (((bVar4 != 0x2d || (bool)(cVar5 + '\x04') != bVar4 < 0x2d &&
         (bVar4 != 0x30 || (bool)(cVar5 + '\x04') != bVar4 < 0x30)) || ((key_modifiers & 0x40) != 0))
       )) {
      if (bVar4 == 0x3c && (bool)(cVar5 + '\x04') == bVar4 < 0x3c) {
        bVar2 = input_is_empty();
        if (!bVar2) {
          edit_state_set(-0x60);
          goto LAB_rom_02953c;
        }
      }
      else if ((bVar4 == 0x3d && (bool)(cVar5 + '\x04') == bVar4 < 0x3d) &&
              (bVar2 = input_is_empty(), !bVar2)) {
        edit_state_set(-0x40);
        goto LAB_rom_02953c;
      }
    }
    else {
LAB_rom_02953c:
      var_edit_entry(_a1);
      sVar3 = input_key;
    }
    if ((byte)sVar3 == 0x24 && (bool)((char)((ushort)sVar3 >> 8) + '\x04') == (byte)sVar3 < 0x24) {
      return 0;
    }
  } while( true );
}

/**
 * @brief 按 token 类别计算插入位置并调用 0xC9F2/0x1F12E/0xD172
 * @addr 0x26362
 * @module editor
 * @proto byte token_insert_pos(byte* tok)
 * @confidence likely
 * @note 按 token 类别计算插入位置并调用 0xC9F2/0x1F12E/0xD172。
 * @tag editor
 */
byte token_insert_pos(byte* _a1)

{
  byte *pbVar1;
  char cVar2;
  byte bVar3;
  byte bVar4;
  bool bVar5;
  byte *pbVar6;
  undefined extraout_R1;
  char cVar7;
  byte bVar8;
  
  pbVar6 = (byte *)frame_enter();
  cVar2 = get_token_class(pbVar6);
  bVar3 = token_scan(0);
  if (bVar3 != 0) {
    cVar7 = '\x01';
    pbVar1 = pbVar6 + bVar3;
    if ((cVar2 == '\x02') || (cVar2 == '\x04')) {
      bVar8 = 0x1d;
      bVar4 = 0x1e;
    }
    else {
      bVar8 = 0x1a;
      bVar4 = 0x1b;
    }
    while (pbVar6 = pbVar1, bVar3 = *pbVar6, bVar3 != 0) {
      if (bVar3 == bVar8) {
        cVar7 = cVar7 + '\x01';
      }
      else if ((bVar3 == bVar4) && (cVar7 = cVar7 + -1, cVar7 == '\0')) break;
      bVar5 = is_neg_char(*pbVar6);
      pbVar1 = pbVar6 + 1;
      if (CONCAT11(extraout_R1,bVar5) != 0) {
        pbVar1 = pbVar6 + 2;
      }
    }
  }
  frame_leave();
  return;
}

/**
 * @brief token 删除/合并（1.7KB，0xD2E8 调用）
 * @addr 0x2648E
 * @module editor
 * @proto void token_del_merge(char* p)
 * @confidence likely
 * @note token 删除/合并（1.7KB，0xD2E8 调用）。
 * @tag editor
 */
int token_del_merge(char* _a1)

{
  bool bVar1;
  int cVar2;
  int cVar3;
  int bVar4;
  byte *pbVar5;
  byte *pbVar6;
  byte *pbVar7;
  undefined2 uVar8;
  
  cVar2 = frame_enter();
  pbVar5 = (byte *)CONCAT11((0x7f < history_cursor) + -0x2f,history_cursor + 0x80);
  pbVar7 = pbVar5;
  if (cVar2 == '\0') {
    pbVar6 = prev_char_ptr(&input_buf,pbVar5);
    if (pbVar6 == (byte *)0x0) {
      input_active = '\0';
      goto LAB_rom_026532;
    }
  }
  else {
    cVar3 = editor_key_step('\x01');
    if ((cVar3 != '\0') || (cVar3 = is_alpha_reg(*pbVar5), cVar3 != '\0')) {
      input_active = '\0';
    }
    pbVar6 = char_ptr_next(pbVar5);
  }
  while (pbVar5 = pbVar6, cVar3 = is_alpha_reg(*pbVar5), cVar3 != '\0') {
    if (cVar2 == '\0') {
      pbVar7 = prev_char_ptr(&input_buf,pbVar5);
      input_active = '\0';
    }
    uVar8 = token_class((char *)pbVar5);
    cVar3 = insert_var_line((char)uVar8);
    if ((cVar3 != '\0') && (*pbVar7 != 0x19)) break;
    input_active = '\0';
    pbVar6 = pbVar7;
    if (cVar2 != '\0') {
      pbVar6 = char_ptr_next(pbVar5);
      pbVar7 = pbVar5;
    }
  }
LAB_rom_026532:
  if (input_active != '\0') {
    bVar1 = false;
    if ((cVar2 == '\0') && (cVar3 = editor_key_step('\x01'), cVar3 != '\0')) {
      bVar1 = true;
    }
    if (bVar1) {
      input_active = '\0';
    }
    else {
      dec_accum3 = 0;
      dec_accum4 = 0;
      if (cVar2 == '\0') {
        cVar2 = draw_token_text((uintptr_t)0);
        dec_accum6 = CONCAT11(-(cVar2 != '\0'),-cVar2);
      }
      else {
        bVar4 = draw_token_text((uintptr_t)0);
        dec_accum6 = (ushort)bVar4;
      }
    }
  }
  history_cursor = (char)pbVar5 + -0x80;
  frame_leave();
  return 0;
}

