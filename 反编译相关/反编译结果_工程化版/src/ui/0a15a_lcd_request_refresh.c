/*
 * 主界面与菜单 / 0a15a_lcd_request_refresh.c
 * 地址范围: 0x0A15A - 0x0A16E
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 刷新请求
 * @addr 0x0A15A
 * @module ui
 * @proto void lcd_request_refresh(void)
 * @confidence verified
 * @note 刷新请求：0xF816=1（当 0xD0F5==0 且 0xD0F7 bit0 置位）。
 * @tag gfx
 */
int lcd_request_refresh(void)

{
  if ((diag_mode == '\0') && ((display_ctrl & 1) != 0)) {
    lcd_refresh_req = 1;
  }
  return 0;
}

/**
 * @brief 主界面刷新
 * @addr 0x0A16E
 * @module ui
 * @proto int ui_update(void)
 * @confidence strong
 * @note 主界面刷新：处理当前键/输入（0xD10E）与显示光标，调用 0xD812 处理输入并刷新。Ghidra
 *       认为无返回值，但调用点把结果当作状态使用。
 * @tag ui
 */
int ui_update(void)

{
  int cVar1;
  undefined uVar2;
  byte bVar3;
  undefined2 uVar4;
  short unaff_ER14;
  
  cVar1 = frame_enter();
  input_key_filter();
  cur_line = prev_line;
  memzero((undefined *)(unaff_ER14 + -0xc),0xc);
  *(undefined *)(unaff_ER14 + -8) = 1;
  *(undefined **)(unaff_ER14 + -0xc) = &input_buf;
  *(undefined2 *)(unaff_ER14 + -10) = 0xd16c;
  *(undefined *)(unaff_ER14 + -6) = calc_mode;
  uVar2 = is_special_editing();
  *(undefined *)(unaff_ER14 + -5) = uVar2;
  uVar2 = is_math_io();
  *(undefined *)(unaff_ER14 + -4) = uVar2;
  uVar2 = is_line_start();
  *(undefined *)(unaff_ER14 + -3) = uVar2;
  uVar2 = stat_view_event();
  *(undefined *)(unaff_ER14 + -2) = uVar2;
  if ((key_modifiers & 0x60) == 0) {
    kbd_repeat = 0;
  }
  if (cVar1 == '\0') {
    bVar3 = (byte)input_key;
    cVar1 = (char)(input_key >> 8);
    if ((bVar3 != 0x42 || (bool)(cVar1 + '\x04') != bVar3 < 0x42) &&
       (bVar3 != 7 || (bool)(cVar1 + '\x04') != bVar3 < 7)) {
      uVar4 = key_is_extended(input_key);
      if ((char)uVar4 == '\0') {
        cVar1 = is_key_3e_1e_1f((byte)input_key,(char)(input_key >> 8));
        if (cVar1 == '\0') {
          input_active = 0;
        }
        uVar4 = key_state_chain();
        if ((char)uVar4 == '\0') {
          _DAT_ram_d15e = 0;
        }
        uVar4 = keycode_norm(input_key);
        if ((((char)uVar4 == '\0') &&
            ((((input_key >> 8) - 0xfc) - (ushort)((byte)input_key < 0x1c) & 0x100) != 0))
           || (cVar1 = menu_gate(), cVar1 == '\0')) goto LAB_rom_00a2f8;
        if (cVar1 == '\x01') goto LAB_rom_00a2d4;
        if (cVar1 == '\x02') goto LAB_rom_00a2da;
        if (cVar1 == '\x03') goto LAB_rom_00a2de;
      }
      else if ((0xfc4d < input_key) && (input_key < 0xfc60)) {
        uVar4 = key_code_lookup(input_key);
        set_input_key(uVar4);
        if (*(char *)(unaff_ER14 + -4) == '\0') {
          if ((byte)input_key == 0x18 &&
              (bool)(char)(input_key >> 8) == (byte)input_key < 0x18) {
            input_key = 0;
          }
        }
        else {
          *(undefined *)(unaff_ER14 + -7) = 1;
        }
      }
      if ((key_modifiers & 0x40) == 0) {
        if (((byte)input_key == 0x2f &&
             (bool)(char)(input_key >> 8) == (byte)input_key < 0x2f) &&
           (menu_io == '\0')) {
          input_key = 0;
        }
        if (input_key != 0) {
          uVar4 = key_is_extended(input_key);
          if ((char)uVar4 != '\0') {
            commit_line();
          }
          if (key_modifiers == 1) {
            wrap_29614(*(char *)(unaff_ER14 + -7));
            goto LAB_rom_00a2d4;
          }
        }
      }
      goto LAB_rom_00a2f8;
    }
  }
LAB_rom_00a2da:
  while( true ) {
    list_paint();
LAB_rom_00a2de:
    if (key_modifiers == 1) goto LAB_rom_00a2f8;
    cVar1 = convert_guard();
    if (cVar1 != '\x01') break;
LAB_rom_00a2d4:
    key_modifiers = 1;
  }
  stat_main_loop();
LAB_rom_00a2f8:
  if (((key_modifiers & 0x20) == 0) && (cVar1 = table_row_count(), cVar1 != '\0')) {
    kbd_repeat = 1;
  }
  frame_leave();
  return 0;
}

