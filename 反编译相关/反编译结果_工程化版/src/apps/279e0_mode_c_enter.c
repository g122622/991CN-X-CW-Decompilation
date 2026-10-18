/*
 * 应用模式 / 279e0_mode_c_enter.c
 * 地址范围: 0x279E0 - 0x280B0
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 调用 0x2B4FC
 * @addr 0x279E0
 * @module apps
 * @proto void mode_c_enter(undefined2 a)
 * @confidence likely
 * @note 调用 0x2B4FC；返回 0x0A 时再调用 0x9E4C（下一模式入口）。
 * @tag mode
 */
int mode_c_enter(undefined2 a)

{
  char cVar1;
  
  frame_enter();
  cVar1 = token_to_text(a);
  if (cVar1 == '\n') {
    append_number_str((byte *)a);
  }
  frame_leave();
  return 0;
}

/**
 * @brief 列表刷新
 * @addr 0x27A7A
 * @module apps
 * @proto void list_refresh(void)
 * @confidence likely
 * @note 列表刷新：0x20D10 检查后按 0xD114 状态重绘当前列表。
 * @tag ui
 */
int list_refresh(void)

{
  int cVar1;
  byte bVar2;
  undefined2 uVar3;
  
  frame_enter();
  cVar1 = stat_view_event();
  uVar3 = input_key;
  if ((cVar1 == '\0') && (edit_state2 == '\x01')) {
    cVar1 = is_math_io();
    if (cVar1 != '\0') {
      bVar2 = (byte)uVar3;
      cVar1 = (char)((ushort)uVar3 >> 8);
      if ((bVar2 == 200 && (bool)cVar1 == bVar2 < 200) ||
         (bVar2 == 0xca && (bool)cVar1 == bVar2 < 0xca)) {
        uVar3 = 0;
      }
    }
    uVar3 = reject_type_2_3_8(uVar3);
    if ((char)uVar3 != '\0') {
      if ((byte)input_key == 0xe9 &&
          (bool)(char)((ushort)input_key >> 8) == (byte)input_key < 0xe9) {
        history_cursor = var_slot_init((undefined2 *)&input_buf);
      }
      else {
        wrap_29614('\0');
      }
    }
  }
  frame_leave();
  return 0;
}

/**
 * @brief 按 0xD112 列号绘制表格数值（1.2KB）
 * @addr 0x27AF6
 * @module apps
 * @proto void table_value_draw(void)
 * @confidence likely
 * @note 按 0xD112 列号绘制表格数值（1.2KB）。
 * @tag app
 */
int table_value_draw(void)

{
  short sVar1;
  
  sVar1 = 0;
  cur_line = 10;
  if ((calc_mode == 'E') && (sub_mode != '\x04')) {
    if (sub_mode == '\x05') {
      sVar1 = 1;
    }
    else if (sub_mode == '\x06') {
      sVar1 = 2;
    }
  }
  if (calc_mode == 'K') {
    if (sub_mode == '\x04') {
      if (ratio_unit == '\0') {
        sVar1 = 3;
      }
      if (ratio_unit == '\x01') {
        sVar1 = 4;
      }
      if (ratio_unit == '\x02') {
        sVar1 = 5;
      }
      if (ratio_unit == '\x03') {
        sVar1 = 6;
      }
    }
    else if (sub_mode == '\x05') {
      if (ratio_unit == '\0') {
        sVar1 = 7;
      }
      if (ratio_unit == '\x01') {
        sVar1 = 8;
      }
      if (ratio_unit == '\x02') {
        sVar1 = 9;
      }
      if (ratio_unit == '\x03') {
        sVar1 = 10;
      }
    }
    else if (sub_mode == '\x06') {
      if (ratio_unit == '\0') {
        sVar1 = 0xb;
      }
      if (ratio_unit == '\x01') {
        sVar1 = 0xc;
      }
      if (ratio_unit == '\x02') {
        sVar1 = 0xd;
      }
      if (ratio_unit == '\x03') {
        sVar1 = 0xe;
      }
    }
  }
  draw_text4x(0x100,*(undefined2 *)(&_DAT_ram_38fc + sVar1 * 2));
  return 0;
}

/**
 * @brief 按 0x38A8 表取行数后绘制（内存/变量列表横幅）
 * @addr 0x27DEE
 * @module apps
 * @proto void draw_ram_banner(void)
 * @confidence likely
 * @note 按 0x38A8 表取行数后绘制（内存/变量列表横幅）。
 * @tag ui
 */
int draw_ram_banner(void)

{
  ushort uVar1;
  short sVar2;
  ushort uVar3;
  
  uVar1 = mul_signed16(mode_count + 1,4);
  uVar3 = uVar1 & 0xff;
  if ((char)uVar1 == '\0') {
    uVar3 = 4;
  }
  for (uVar1 = 0;
      (byte)(SBORROW2(uVar1,mode_count + 1) ^ (short)(uVar1 - (mode_count + 1)) < 0) == 1;
      uVar1 = uVar1 + 1) {
    sVar2 = mul16(uVar1,6);
    if (*(char *)(sVar2 + 0x668c) == calc_mode) {
      mode_index = (byte)uVar1;
    }
  }
  mode_group = mode_index >> 2;
  if (3 < mode_count) {
    uVar3 = uVar3 + mode_index;
    uVar1 = (ushort)mode_count;
    if ((byte)(SBORROW2(uVar3,uVar1) ^ (short)(uVar3 - uVar1) < 0 | uVar3 == uVar1) != 1) {
      mode_group = mode_group - 1;
    }
  }
  return 0;
}

/**
 * @brief 调用 0x27E84(0)（选择第 0 项/退出）
 * @addr 0x27E62
 * @module apps
 * @proto void mode_select_0(void)
 * @confidence likely
 * @note 调用 0x27E84(0)（选择第 0 项/退出）。
 * @tag mode
 */
int mode_select_0(void)

{
  sidebar_menu('\0');
  return 0;
}

/**
 * @brief 左侧菜单栏绘制（4.6KB，0x2319E/0x263C8 调用）
 * @addr 0x27E84
 * @module apps
 * @proto void sidebar_menu(void)
 * @confidence likely
 * @note 左侧菜单栏绘制（4.6KB，0x2319E/0x263C8 调用）。
 * @tag ui
 */
int sidebar_menu(uintptr_t _a2, int _a1)

{
  byte bVar1;
  int cVar2;
  undefined2 uVar3;
  undefined uVar4;
  undefined2 uVar5;
  byte bVar6;
  char cVar7;
  short unaff_ER14;
  
  uVar3 = frame_enter();
  cVar7 = '\0';
  bVar6 = 0;
  uVar5 = uVar3;
  if (_a1 == '\0') {
    if (calc_mode == '\x06') {
      cVar7 = '\x13';
    }
    else {
      cVar7 = '\x14';
    }
  }
  else {
    bVar1 = (byte)uVar3;
    cVar2 = (char)((ushort)uVar3 >> 8);
    if (bVar1 == 7 && (bool)(cVar2 + '\x15') == bVar1 < 7) {
      cVar7 = '\x13';
    }
    if (bVar1 == 0xd && (bool)(cVar2 + '\x15') == bVar1 < 0xd) {
      cVar7 = '\x14';
    }
  }
LAB_rom_027ebc:
  while( true ) {
    *(undefined2 *)(unaff_ER14 + -2) = uVar5;
    cVar2 = edit_loop();
    if (cVar2 != '\x01') break;
    bVar1 = (byte)*(undefined2 *)(unaff_ER14 + -2);
    cVar2 = (char)((ushort)*(undefined2 *)(unaff_ER14 + -2) >> 8);
    uVar5 = uVar3;
    if ((bVar1 != 2 || (bool)(cVar2 + '\x12') != bVar1 < 2) &&
       (bVar1 != 3 || (bool)(cVar2 + '\x12') != bVar1 < 3)) {
LAB_rom_02808c:
      if (_a1 != '\0') {
        if (cVar7 == '\x13') {
          mode_switch_refresh();
        }
        else {
          mode_switch_refresh();
        }
      }
      cVar2 = '\0';
      input_key = 0;
LAB_rom_027ec0:
      if ((_a1 != '\0') && (cVar2 == '\0')) {
        edit_state2 = '\x01';
      }
      frame_leave();
      return 0;
    }
  }
  if (cVar2 == '\x02') {
    cVar7 = (char)*(undefined2 *)(unaff_ER14 + -2);
    if (cVar7 == '\x01' &&
        (bool)((char)((ushort)*(undefined2 *)(unaff_ER14 + -2) >> 8) + '\x12') == (cVar7 == '\0')) {
      *(undefined2 *)(unaff_ER14 + -2) = 0xfc40;
    }
    input_key = *(undefined2 *)(unaff_ER14 + -2);
    cVar2 = '\x01';
    goto LAB_rom_027ec0;
  }
  if (cVar2 != '\x03') goto LAB_rom_02808c;
  bVar1 = (byte)*(undefined2 *)(unaff_ER14 + -2);
  cVar2 = (char)((ushort)*(undefined2 *)(unaff_ER14 + -2) >> 8);
  if ((((bVar1 == 2 && (bool)(cVar2 + '\x13') == bVar1 < 2) ||
       (bVar1 == 3 && (bool)(cVar2 + '\x13') == bVar1 < 3)) ||
      (bVar1 == 4 && (bool)(cVar2 + '\x13') == bVar1 < 4)) ||
     (bVar1 == 5 && (bool)(cVar2 + '\x13') == bVar1 < 5)) {
    bVar6 = *(char *)(unaff_ER14 + -2) - 2;
    if (_a1 != '\0') {
      mode_switch_refresh();
    }
    cVar2 = mode_menu_draw(cVar7);
    if (cVar2 == '\x02') {
      if (_a1 == '\0') {
        uVar4 = 0xb;
      }
      else {
        uVar4 = 7;
      }
      uVar5 = CONCAT11(0xeb,uVar4);
      goto LAB_rom_027ebc;
    }
  }
  else {
    if (((bVar1 == 6 && (bool)(cVar2 + '\x13') == bVar1 < 6) ||
        (bVar1 == 7 && (bool)(cVar2 + '\x13') == bVar1 < 7)) ||
       ((bVar1 == 8 && (bool)(cVar2 + '\x13') == bVar1 < 8 ||
        (bVar1 == 9 && (bool)(cVar2 + '\x13') == bVar1 < 9)))) {
      bVar6 = bVar1 - 6;
      if ((*(char *)((ushort)bVar6 * 2 + -0x2f08) == '\0') ||
         (*(char *)((ushort)bVar6 * 2 + -0x2f07) == '\0')) {
        cVar2 = mode_menu_draw(cVar7);
        if (cVar2 != '\x02') goto joined_s0x027f22;
        uVar5 = 0xeb0c;
        goto LAB_rom_027ebc;
      }
      goto LAB_rom_028032;
    }
    if (((bVar1 != 10 || (bool)(cVar2 + '\x13') != bVar1 < 10) &&
        (bVar1 != 0xb || (bool)(cVar2 + '\x13') != bVar1 < 0xb)) &&
       ((bVar1 != 0xc || (bool)(cVar2 + '\x13') != bVar1 < 0xc &&
        (bVar1 != 0xd || (bool)(cVar2 + '\x13') != bVar1 < 0xd)))) {
      if (((((bVar1 != 0xe || (bool)(cVar2 + '\x13') != bVar1 < 0xe) &&
            (bVar1 != 0xf || (bool)(cVar2 + '\x13') != bVar1 < 0xf)) &&
           (bVar1 != 0x10 || (bool)(cVar2 + '\x13') != bVar1 < 0x10)) &&
          (bVar1 != 0x11 || (bool)(cVar2 + '\x13') != bVar1 < 0x11)) ||
         ((bVar6 = bVar1 - 0xe, *(char *)((ushort)bVar6 * 2 + -0x2f08) != '\0' &&
          (*(char *)((ushort)bVar6 * 2 + -0x2f07) != '\0')))) goto LAB_rom_028032;
      cVar2 = mode_menu_draw(cVar7);
      if (cVar2 != '\x02') goto joined_s0x027f22;
      uVar5 = 0xeb12;
      goto LAB_rom_027ebc;
    }
    bVar6 = *(char *)(unaff_ER14 + -2) - 10;
    if (_a1 != '\0') {
      mode_switch_refresh();
    }
    cVar2 = mode_menu_draw(cVar7);
    if (cVar2 == '\x02') {
      if (_a1 == '\0') {
        uVar4 = 0x11;
      }
      else {
        uVar4 = 0xd;
      }
      uVar5 = CONCAT11(0xeb,uVar4);
      goto LAB_rom_027ebc;
    }
  }
joined_s0x027f22:
  if (cVar2 != '\x01') goto LAB_rom_027ec0;
LAB_rom_028032:
  sub_mode = bVar6;
  edit_state2 = cVar7;
  stat_table_reset();
  cVar2 = -1;
  goto LAB_rom_027ec0;
}

/**
 * @brief BASE-N 进制模式循环的实现（调用 0x14C5E）
 * @addr 0x280B0
 * @module apps
 * @proto void mode_45_base_impl(void)
 * @confidence strong
 * @note BASE-N 进制模式循环的实现（调用 0x14C5E）。
 * @tag mode
 */
int mode_45_base_impl(uintptr_t _a2, int _a1)

{
  int cVar1;
  short sVar2;
  undefined2 uVar3;
  ushort uVar4;
  byte bVar5;
  
  do {
    kbd_repeat = 0;
    edit_state2 = 0x15;
    key_modifiers = 3;
    if (sub_mode < 4) {
      wizard_main();
    }
    else {
      matrix_cell_draw();
    }
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
        uVar4 = apps_mode_main(sVar2);
        cVar1 = (char)uVar4;
        _a1 = (byte *)CONCAT11((char)((ushort)_a1 >> 8),cVar1);
        if (cVar1 == '\0') {
          if ((sub_mode == 4) &&
             (uVar3 = table_init_var(CONCAT11((char)(uVar4 >> 8),sub_mode)),
             (char)uVar3 == '\x03')) {
            sVar2 = menu_get_key('\x03');
            set_input_key(sVar2);
            return 0;
          }
          if (_DAT_ram_d14d == 4) {
            stat_state = 3;
          }
          else {
            stat_state = 2;
          }
          table_cell_edit((short)_a1);
        }
        else if (((cVar1 == '\x03') && (sub_mode != 0)) && (sub_mode < 4)) {
          _DAT_ram_d14d = matrix_entry_main();
          if (_DAT_ram_d14d == 3) {
            sVar2 = menu_get_key('\x03');
            set_input_key(sVar2);
          }
          else {
            stat_state = 3;
            table_cell_edit((short)_a1);
          }
        }
        else {
          sVar2 = menu_get_key(cVar1);
          set_input_key(sVar2);
        }
        goto LAB_rom_0281ea;
      }
      if (bVar5 == 0x26 && (bool)(cVar1 + '\x04') == bVar5 < 0x26) {
        key_mod_clear();
        stat_list_reset();
        goto LAB_rom_0281ea;
      }
      cVar1 = is_arrow_key(bVar5,cVar1);
      if (cVar1 == '\0') {
        uVar3 = key_is_menu_key(sVar2);
        if ((char)uVar3 != '\0') {
          edit_ctx_check();
        }
        goto LAB_rom_0281ea;
      }
      key_flag_bit7();
      if (sub_mode < 4) {
        cVar1 = table_edit_flow2();
      }
      else {
        cVar1 = table_cell_key();
      }
      if (cVar1 == '\0') goto LAB_rom_0281ea;
      key_flag_clear();
    }
    table_copy(_a1);
LAB_rom_0281ea:
    if ((byte)input_key == 0x24 &&
        (bool)((char)((ushort)input_key >> 8) + '\x04') == (byte)input_key < 0x24) {
      return 0;
    }
  } while( true );
}

