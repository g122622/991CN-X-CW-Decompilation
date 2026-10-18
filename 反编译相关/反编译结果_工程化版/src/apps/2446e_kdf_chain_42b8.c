/*
 * 应用模式 / 2446e_kdf_chain_42b8.c
 * 地址范围: 0x2446E - 0x24A20
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 沿 0x42B8 表遍历（最多 10 步），返回终止项值
 * @addr 0x2446E
 * @module apps
 * @proto ushort kdf_chain_42b8(byte idx)
 * @confidence likely
 * @note 沿 0x42B8 表遍历（最多 10 步），返回终止项值。
 * @tag setup
 */
ushort kdf_chain_42b8(byte _a1)

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
    uVar3 = *(ushort *)(sVar2 + 0x42b8);
    if (((byte)uVar3 == 8 && (bool)((char)(uVar3 >> 8) + '\x12') == (byte)uVar3 < 8) || (uVar3 == 0)
       ) break;
    uVar3 = uVar3 & 0xff;
    cVar4 = cVar4 + -1;
  } while (cVar4 != '\0');
  frame_leave();
  return;
}

/**
 * @brief 以 0xEB40/0xEB3E 调用 0x26A1C 等（按 0x26892 选择）
 * @addr 0x2452C
 * @module apps
 * @proto void call_eb40(void)
 * @confidence likely
 * @note 以 0xEB40/0xEB3E 调用 0x26A1C 等（按 0x26892 选择）。
 * @tag ui
 */
int call_eb40(void)

{
  int cVar1;
  undefined uVar2;
  short unaff_ER14;
  
  frame_enter();
  cVar1 = is_mode_4a();
  if (cVar1 == '\0') {
    uVar2 = 0x40;
  }
  else {
    uVar2 = 0x3e;
  }
  *(ushort *)(unaff_ER14 + -2) = CONCAT11(0xeb,uVar2);
  cVar1 = edit_loop();
  if (cVar1 == '\x03') {
    input_key = 0;
    mode_switch_refresh();
    input_key = 0xfc26;
  }
  else if (cVar1 == '\x02') {
    input_key = *(undefined2 *)(unaff_ER14 + -2);
  }
  else {
    *(undefined2 *)(unaff_ER14 + -2) = 0;
  }
  frame_leave();
  return 0;
}

/**
 * @brief 统计矩阵重建（1KB，0xF746 调用）
 * @addr 0x24582
 * @module apps
 * @proto void stat_matrix_rebuild(void)
 * @confidence likely
 * @note 统计矩阵重建（1KB，0xF746 调用）。
 * @tag app
 */
int stat_matrix_rebuild(void)

{
  short sVar1;
  ushort uVar2;
  short sVar3;
  byte bVar4;
  
  sVar1 = frame_enter();
  *(char *)(sVar1 + 0x183) = *(char *)(sVar1 + 0x183) + -1;
  bVar4 = *(byte *)(sVar1 + 0x183);
  uVar2 = draw_spaced((ushort)*(byte *)(sVar1 + 0x182),4);
  uVar2 = mul_signed16((ushort)bVar4,uVar2);
  if (uVar2 == 0) {
    lcd_contrast_step('\x01');
  }
  if (*(char *)(sVar1 + 0x183) == '\0') {
    *(byte *)(sVar1 + 0x17b) = *(byte *)(sVar1 + 0x17b) ^ 1;
    *(undefined *)(sVar1 + 0x183) = *(undefined *)(sVar1 + 0x182);
    sVar3 = *(short *)(sVar1 + 0x184);
    *(short *)(sVar1 + 0x184) = sVar3 + -1;
    if (sVar3 == 0) {
      draw_target = 1;
      boot_lcd_init();
    }
    if (*(char *)(sVar1 + 0x17c) != '\0') {
      if (*(char *)(sVar1 + 0x17b) == '\0') {
        str_format_frac(CONCAT11((char)((ushort)sVar1 >> 8) + (0x41 < (byte)sVar1),(byte)sVar1 + 0xb)
                               ));
      }
      else {
        str_format_frac(sVar1);
      }
    }
  }
  frame_leave();
  return 0;
}

/**
 * @brief 双层循环把网格区域填充为 v（行 × 列）
 * @addr 0x24622
 * @module apps
 * @proto void fill_grid(char v)
 * @confidence likely
 * @note 双层循环把网格区域填充为 v（行 × 列）。
 * @tag ui
 */
int fill_grid(char v)

{
  char cVar1;
  short sVar2;
  short sVar3;
  byte bVar4;
  byte bVar5;
  short unaff_ER14;
  
  sVar2 = frame_enter();
  bVar5 = 0;
  do {
    bVar4 = 0;
    do {
      cVar1 = *(char *)(unaff_ER14 + 0x12);
      sVar3 = mul16((ushort)bVar5,*(ushort *)(unaff_ER14 + 0x10));
      draw_cell_overlay(sVar3 + sVar2,bVar4 * cVar1 + v);
      bVar4 = bVar4 + 1;
    } while (bVar4 < 2);
    bVar5 = bVar5 + 1;
  } while (bVar5 < 2);
  frame_leave();
  return 0;
}

/**
 * @brief 16 位无符号除法/取余（C 级 H 除法指令的软件封装）
 * @addr 0x246B4
 * @module apps
 * @proto undefined2 divmod_unsigned16(undefined2 a, undefined2 b)
 * @confidence strong
 * @note 16 位无符号除法/取余（C 级 H 除法指令的软件封装）。
 * @tag util
 */
undefined2 divmod_unsigned16(undefined2 a, undefined2 b)

{
  bool bVar1;
  ushort uVar2;
  char cVar3;
  ushort uVar4;
  short sVar5;
  char cVar6;
  ushort uVar7;
  byte bVar8;
  
  cVar3 = (char)(b >> 8);
  uVar4 = a;
  uVar7 = b;
  if (cVar3 == '\0') {
    if ((char)b != '\0') {
      a = a / (b & 0xff);
    }
  }
  else {
    do {
      uVar4 = CONCAT11((byte)(uVar4 >> 9),(char)((uVar4 & 0xff00) + (uVar4 & 0xff) >> 1));
      uVar2 = (uVar7 & 0xff00) + (uVar7 & 0xff) >> 1;
      cVar6 = (char)uVar2;
      bVar8 = (byte)(uVar7 >> 9);
      uVar7 = CONCAT11(bVar8,cVar6);
    } while (bVar8 != 0);
    if (cVar6 != '\0') {
      uVar4 = uVar4 / (uVar2 & 0xff);
    }
    sVar5 = (b & 0xff) * (uVar4 & 0xff);
    bVar1 = a < CONCAT11((char)((ushort)sVar5 >> 8) + cVar3 * (char)uVar4,(char)sVar5);
    a = uVar4 & 0xff;
    if (bVar1) {
      a = (ushort)(byte)((char)uVar4 - 1);
    }
  }
  return a;
}

/**
 * @brief 带符号除法
 * @addr 0x246F4
 * @module apps
 * @proto undefined2 divmod_signed16(undefined2 a, undefined2 b)
 * @confidence strong
 * @note 带符号除法：0x246B4 取绝对值做除/取余，再按符号修正。
 * @tag util
 */
undefined2 divmod_signed16(undefined2 a, undefined2 b)

{
  byte bVar2;
  ushort uVar1;
  byte bVar3;
  byte unaff_R12;
  
  bVar3 = (byte)(b >> 8);
  bVar2 = (byte)(a >> 8);
  if ((short)a < 0) {
    a = CONCAT11(-((char)a == -1) - bVar2,-(char)a);
  }
  if ((short)b < 0) {
    b = CONCAT11(-((char)b == -1) - bVar3,-(char)b);
  }
  uVar1 = divmod_unsigned16(a,b);
  if (((unaff_R12 & bVar3 ^ bVar2) & 0x80) != 0) {
    uVar1 = (uVar1 ^ 0xffff) + 1;
  }
  return uVar1;
}

/**
 * @brief 表格模式主循环（3.6KB，0x975A 调用）
 * @addr 0x247BE
 * @module apps
 * @proto void table_mode_main(void)
 * @confidence likely
 * @note 表格模式主循环（3.6KB，0x975A 调用）。
 * @tag app
 */
int table_mode_main(void)

{
  bool bVar1;
  byte bVar2;
  byte bVar3;
  char cVar4;
  byte bVar5;
  undefined uVar6;
  char *pcVar7;
  char cVar9;
  undefined2 uVar8;
  byte bVar10;
  byte bVar11;
  short unaff_ER14;
  
  frame_enter();
  bVar2 = app_work_area;
  if (app_work_area < 3) {
    clear_screen();
    cur_line = 0xe;
    input_read_str((char *)(unaff_ER14 + -0x24));
    draw_scaled_char(0x32, (uintptr_t)0);
    key_hist_set_hi('\r');
    goto LAB_rom_0247fa;
  }
  bVar3 = key_hist_lo();
  bVar1 = false;
  cVar4 = is_line_start();
  pcVar7 = (char *)input_history_ptr();
  cVar9 = (char)((ushort)unaff_ER14 >> 8);
  bVar5 = (byte)unaff_ER14;
  if ((pcVar7 == (char *)0x0) || (cVar4 == '\0')) {
    pcVar7 = (char *)CONCAT11(cVar9 + -1 + (0x4b < bVar5),bVar5 + 0xb4);
  }
  if (((bVar3 == 0) && (menu_state_c != '\0')) ||
     ((byte)input_key == 0x2d &&
      (bool)((char)((ushort)input_key >> 8) + '\x04') == (byte)input_key < 0x2d)) {
    bVar3 = 10;
    key_hist_clear_lo(10);
  }
  cur_line = 10;
  strcpy_checked((char *)CONCAT11(cVar9 + -1 + (0x4d < bVar5),bVar5 + 0xb2),"`");
  if (cVar4 == '\0') {
LAB_rom_0248ac:
    *pcVar7 = '\0';
    *(undefined *)(unaff_ER14 + -0x6e) = 0;
    history_cursor = 0;
    input_active = 0;
    clear_screen();
    table_key_router((ushort)bVar2 << 8);
    table_key_router((ushort)bVar2 << 8);
    bVar3 = 0xd;
    cVar4 = '\n';
    *(undefined *)(unaff_ER14 + -0x72) = _DAT_ram_d6b3;
    mixed_fraction = 0;
    *(undefined *)(unaff_ER14 + -0x71) = 0;
    if (bVar2 == 0x19) {
      *(undefined *)(unaff_ER14 + -0x71) = 1;
    }
    for (bVar10 = 1; bVar10 <= *(byte *)(unaff_ER14 + -0x72); bVar10 = bVar10 + 1) {
      bVar11 = bVar10;
      if (*(char *)(unaff_ER14 + -0x71) != '\0') {
        if (bVar10 == 2) {
          bVar11 = 3;
        }
        else if (bVar10 == 3) {
          bVar11 = 2;
        }
      }
      mul16((ushort)bVar11,10);
      uVar6 = edit_render_content((undefined2 *)(unaff_ER14 + -0x24));
      uVar8 = edit_normalize_pos(CONCAT11(uVar6,cVar4));
      cVar4 = (char)uVar8;
      strcpy_checked((char *)CONCAT11(cVar9 + -1 + (0x6f < bVar5),bVar5 + 0x90), (uintptr_t)0)
                     (char *)CONCAT11(cVar9 + -1 + (0x4d < bVar5),bVar5 + 0xb2));
      *(byte *)(unaff_ER14 + -0x70) = *(char *)(unaff_ER14 + -0x70) + bVar11;
      strcat_checked((char *)CONCAT11(cVar9 + -1 + (0x6d < bVar5),bVar5 + 0x92), (uintptr_t)0)
                     (char *)CONCAT11(cVar9 + -1 + (0x6f < bVar5),bVar5 + 0x90));
      *(undefined *)(unaff_ER14 + -0x4c) = 0;
      table_key_router(CONCAT11(bVar2,bVar10));
      table_key_router(CONCAT11(bVar2,bVar10));
      if (bVar1) {
        strcat_checked(pcVar7,(char *)(unaff_ER14 + -0x24));
        strcat_checked(pcVar7,(char *)CONCAT11(cVar9 + -1 + (0x4b < bVar5),bVar5 + 0xb4));
      }
      else {
        strcpy_checked(pcVar7,(char *)CONCAT11(cVar9 + -1 + (0x6f < bVar5),bVar5 + 0x90));
        strcat_checked(pcVar7,"=");
        draw_text4x((ushort)bVar3 << 8,pcVar7);
        draw_field_y(bVar3);
        bVar3 = bVar3 + 0xc;
      }
    }
    draw_text4x(0x100,CONCAT11(cVar9 + -1 + (0x6d < bVar5),bVar5 + 0x92));
    key_hist_set_hi(cVar4);
    if (!bVar1) goto LAB_rom_0247fa;
  }
  else {
    if ((bVar3 != 10) || (key_hist_d != '\0')) {
      bVar1 = true;
      disp_mode = 1;
      cur_line = 0xe;
    }
    if (key_hist_d == '\0') goto LAB_rom_0248ac;
    dec_accum3 = 0;
    dec_accum4 = 0;
    dec_accum6 = 0;
  }
  uVar8 = input_ptr;
  history_dirty = 1;
  input_ptr = pcVar7;
  call_mode_ee2a();
  disp_mode = 0;
  input_ptr = (char *)uVar8;
LAB_rom_0247fa:
  frame_leave();
  return 0;
}

/**
 * @brief v == 2 时返回 1
 * @addr 0x24A14
 * @module apps
 * @proto char is_v2_02(byte v)
 * @confidence verified
 * @note v == 2 时返回 1。
 * @tag util
 */
char is_v2_02(byte v)

{
  if (v == '\x02') {
    return 1;
  }
  return 0;
}

/**
 * @brief 统计矩阵主流程（6.4KB，无外部调用者）
 * @addr 0x24A20
 * @module apps
 * @proto void stat_matrix_main(void)
 * @confidence likely
 * @note 统计矩阵主流程（6.4KB，无外部调用者）。
 * @tag app
 */
int stat_matrix_main(int _a1)

{
  byte bVar1;
  int cVar2;
  char **ppcVar3;
  undefined2 uVar4;
  short sVar5;
  ushort uVar6;
  byte bVar7;
  undefined uVar8;
  char *pcVar9;
  int bVar10;
  byte *pbVar11;
  byte bVar12;
  short unaff_ER14;
  
  ppcVar3 = (char **)frame_enter();
  bVar12 = 0;
  bVar1 = key_modifiers & 0x40;
  if (((edit_state2 != 6) || (stat_state != '\x04')) && (**ppcVar3 == '\0')) goto LAB_rom_024b2e;
  cVar2 = can_recall();
  if (cVar2 != '\0') {
    name_buffer_load();
  }
  input_ptr = *ppcVar3;
  cVar2 = is_mode_high();
  if (cVar2 == '\0') {
    uVar4 = input_line_sync((undefined2 *)(unaff_ER14 + -2));
    cVar2 = (char)uVar4;
  }
  else {
    cVar2 = draw_input_line(_a1);
  }
  pbVar11 = *(byte **)(unaff_ER14 + -2);
  if (bVar1 != 0) {
    *(undefined2 *)(unaff_ER14 + -2) = input_end_ptr;
  }
  uVar4 = dec_copy_rev((undefined2 *)(unaff_ER14 + -0x16),(undefined2 *)ppcVar3[1]);
  if (cVar2 == '\0') {
    bVar10 = 2;
    cVar2 = history_cursor;
LAB_rom_024b6e:
    history_cursor = cVar2;
    if ((bVar10 != 0) && (bVar10 < 0x20)) {
      key_modifiers = 0x80;
      sVar5 = menu_get_key(bVar10);
      set_input_key(sVar5);
      expr_state_clear();
      if (*(char *)((short)ppcVar3 + 7) != '\0') {
        dec_copy_rev((undefined2 *)ppcVar3[1],(undefined2 *)(unaff_ER14 + -0x16));
      }
      cVar2 = kbd_input_handle();
      if (cVar2 != '\x01') {
        if (((calc_mode == -0x78) && (ratio_flags = 0, edit_state2 == 6)) &&
           (stat_state == '\x04')) {
          edit_state2 = 1;
        }
        context_save_restore(ppcVar3);
      }
      goto LAB_rom_024b2e;
    }
    if ((key_modifiers == 1) && (cVar2 = is_special_editing(), cVar2 == '\0')) {
      bVar12 = 0x20;
    }
    key_mod_clear();
    key_dispatch_menu();
    key_modifiers = 3;
    uVar6 = dec_type_of(ppcVar3[1]);
    cVar2 = (char)uVar6;
    if ((cVar2 != '`') && (cVar2 != -0x70)) {
      bVar7 = (byte)(uVar6 >> 8);
      if ((bVar10 == 0) || (bVar10 == 0x24)) {
        if ((edit_state2 == 0xc0) && (*(char *)(ppcVar3 + 5) == '\0')) {
          key_history_flags = 0x13;
          if (bVar10 == 0x24) {
            stat_state = '@';
          }
          else {
            stat_state = ' ';
          }
          uVar6 = CONCAT11(bVar7,stat_state);
        }
        else {
          uVar6 = CONCAT11(bVar7,*(char *)(ppcVar3 + 3));
          if (*(char *)(ppcVar3 + 3) != -0x3c) {
            uVar6 = dec_set_uint_small((ushort *)(ppcVar3[1] + 10),0);
          }
        }
      }
      else if (bVar10 == 0x22) {
        if (*(char *)(ppcVar3 + 3) == -0x3c) {
          key_hist_b = 2;
        }
        else {
          key_history_flags = 0x12;
        }
        uVar6 = (ushort)bVar7 << 8;
      }
      else if (bVar10 == 0x23) {
        if (*(char *)(ppcVar3 + 3) == -0x3c) {
          key_hist_b = 1;
        }
        else {
          key_history_flags = 0x11;
        }
        uVar6 = (ushort)bVar7 << 8;
      }
      else if (bVar10 == 0x25) {
        if (ppcVar3[1][10] == 'p') {
          uVar6 = dec_set_uint_small((ushort *)(ppcVar3[1] + 10),0);
        }
        else {
          uVar6 = CONCAT11(bVar7,0x14);
          key_history_flags = 0x14;
        }
      }
      else if (bVar10 == 0x26) {
        if (ppcVar3[1][10] == 'p') {
          uVar6 = dec_set_uint_small((ushort *)(ppcVar3[1] + 10),0);
        }
        else {
          uVar6 = CONCAT11(bVar7,0x15);
          key_history_flags = 0x15;
        }
      }
      uVar8 = (undefined)(uVar6 >> 8);
      if (*(char *)(ppcVar3 + 3) == -0x3f) {
        uVar8 = 0;
        dec_copy((undefined2 *)0xd37e,(undefined2 *)0xd324);
      }
      if ((key_history_flags & 0x10) == 0) {
        pcVar9 = ppcVar3[1];
        base_clear(CONCAT11(uVar8,1),pcVar9);
      }
      else {
        dec_copy((undefined2 *)(unaff_ER14 + -0x16),(undefined2 *)ppcVar3[1]);
        uVar4 = dec_set_uint_small((ushort *)(unaff_ER14 + -0xc),0);
        pcVar9 = (char *)(unaff_ER14 + -0x16);
        base_clear(CONCAT11((char)((ushort)uVar4 >> 8),1),pcVar9);
      }
      key_history_flags = key_history_flags | bVar12;
      if (edit_state2 != 0xc0) {
        if (*(char *)(*(short *)(unaff_ER14 + -2) + -1) == '#') {
          bVar1 = 1;
          key_modifiers = key_modifiers | 0x40;
          input_end_ptr = *(undefined2 *)(unaff_ER14 + -2);
        }
        else if (bVar1 != 0) {
          bVar1 = 0;
        }
        if (((bVar1 == 0) && ((edit_state2 & 0x80) != 0)) && (stat_state == '\x03')) {
          stat_state = '\x10';
        }
        append_history(pcVar9);
      }
      goto LAB_rom_024b2e;
    }
    if (cVar2 == '`') {
      edit_state2 = 0x13;
    }
    else {
      edit_state2 = 0x14;
    }
    mat_load_cell_ptr((byte *)ppcVar3[1]);
    sub_mode = 4;
    cursor_home();
  }
  else {
    lcd_mode_16(uVar4);
    if ((edit_state2 == 0xc0) && (stat_state == '\x04')) {
      uVar4 = eval_expr((byte **)(unaff_ER14 + -2),(undefined2 *)ppcVar3[1]);
      bVar10 = (byte)uVar4;
LAB_rom_024b40:
      cVar2 = history_cursor;
      if (((bVar10 != 0) && (bVar10 < 0x20)) &&
         (cVar2 = *(char *)(unaff_ER14 + -2) - (char)pbVar11, *(char *)(ppcVar3 + 4) != '\0')) {
        buffer_transfer(pbVar11);
        cVar2 = history_cursor;
      }
      goto LAB_rom_024b6e;
    }
    if ((*(char *)(ppcVar3 + 3) != -0x78) || (stat_state != '\x04')) {
      bVar10 = matrix_entry((undefined2 *)(unaff_ER14 + -2),(ushort)ppcVar3[1]);
      goto LAB_rom_024b40;
    }
    if (history_recall == '\x01') {
      uVar6 = stat_table_edit((undefined2 *)(unaff_ER14 + -2));
      bVar10 = (byte)uVar6;
      if (bVar10 != 0) goto LAB_rom_024b40;
      if ((ratio_flags & 0x80) == 0) {
        ratio_flags = 1;
        cVar2 = restore_input_line();
        pbVar11 = *(byte **)(unaff_ER14 + -2);
        if (cVar2 == '\0') {
          bVar10 = 2;
          cVar2 = history_cursor;
          goto LAB_rom_024b6e;
        }
        uVar6 = stat_table_edit((undefined2 *)(unaff_ER14 + -2));
        bVar10 = (byte)uVar6;
        if (bVar10 != 0) goto LAB_rom_024b40;
        ratio_flags = 0;
      }
      edit_state2 = 0x12;
      stat_table_reset();
    }
    else {
      uVar6 = stat_table_edit((undefined2 *)(unaff_ER14 + -2));
      bVar10 = (byte)uVar6;
      if (bVar10 != 0) goto LAB_rom_024b40;
      edit_state2 = 0x12;
      stat_table_reset();
    }
  }
  *(undefined *)(ppcVar3 + 2) = 0;
LAB_rom_024b2e:
  frame_leave();
  return 0;
}

