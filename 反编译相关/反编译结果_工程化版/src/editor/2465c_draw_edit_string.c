/*
 * 输入编辑器 / 2465c_draw_edit_string.c
 * 地址范围: 0x2465C - 0x24DB4
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 按 0xED7C 绘制编辑串
 * @addr 0x2465C
 * @module editor
 * @proto int draw_edit_string(char* s)
 * @confidence likely
 * @note 按 0xED7C 绘制编辑串；以 "=" 开头时调整列偏移（0x821E）。
 * @tag editor
 */
int draw_edit_string(char* s)

{
  undefined2 uVar1;
  char cVar2;
  short unaff_ER14;
  
  uVar1 = frame_enter();
  cVar2 = '\f';
  draw_text4x(uVar1,s);
  menu_gate();
  draw_tokens((undefined2 *)(unaff_ER14 + -10));
  if (*s == '=') {
    cVar2 = '\x06';
  }
  draw_text4x(CONCAT11((char)((ushort)uVar1 >> 8),cVar2 + (char)uVar1),unaff_ER14 + -0x32);
  frame_leave();
  return 0;
}

/**
 * @brief 变量编辑入口（1.2KB，0x26248/0x2950C 调用）
 * @addr 0x24728
 * @module editor
 * @proto void var_edit_entry(void)
 * @confidence likely
 * @note 变量编辑入口（1.2KB，0x26248/0x2950C 调用）。
 * @tag editor
 */
int var_edit_entry(uintptr_t _a2, int _a1)

{
  int cVar1;
  undefined2 uVar2;
  short sVar3;
  char cVar4;
  char *pcVar5;
  
  frame_enter();
  cVar4 = '\0';
  name_buffer_load();
  input_ptr = &input_buf;
  cVar1 = draw_input_line(_a1);
  if (cVar1 == '\0') {
    cVar1 = '\x02';
  }
  else {
    uVar2 = stat_table_calc((char)_a1);
    cVar1 = (char)uVar2;
    if (cVar1 == '\0') {
      pcVar5 = &_DAT_ram_d5ec;
      cVar1 = _DAT_ram_d5ec;
      while (cVar1 != -1) {
        cVar4 = cVar4 + '\x01';
        pcVar5 = pcVar5 + 1;
        cVar1 = *pcVar5;
      }
      if (cVar4 == '\0') {
        edit_state2 = 1;
        set_input_key(0xfc30);
      }
      else {
        key_modifiers = 3;
        var_editor();
        if ((byte)input_key == 0x26 &&
            (bool)((char)((ushort)input_key >> 8) + '\x04') == (byte)input_key < 0x26) {
          edit_state2 = 1;
        }
      }
      goto LAB_rom_0247ba;
    }
  }
  key_modifiers = 0x80;
  sVar3 = menu_get_key(cVar1);
  set_input_key(sVar3);
  clear_screen();
  edit_state2 = 1;
LAB_rom_0247ba:
  frame_leave();
  return 0;
}

/**
 * @brief 绘制空行缓冲（"1:" 前缀、0xD137=0xE）并刷新
 * @addr 0x24DB4
 * @module editor
 * @proto void draw_empty_line(void)
 * @confidence likely
 * @note 绘制空行缓冲（"1:" 前缀、0xD137=0xE）并刷新。
 * @tag editor
 */
int draw_empty_line(void)

{
  byte bVar1;
  short unaff_ER14;
  
  frame_enter();
  *(undefined *)(unaff_ER14 + -4) = 0x31;
  *(undefined *)(unaff_ER14 + -3) = 0x3a;
  *(undefined *)(unaff_ER14 + -2) = 0;
  cur_line = 0xe;
  bVar1 = 0;
  do {
    strcpy_checked((char *)(unaff_ER14 + -0x28),(char *)(unaff_ER14 + -4));
    strcat_checked((char *)(unaff_ER14 + -0x28),**(char ***)((ushort)bVar1 * 2 + 0x62a4));
    draw_text4x((ushort)(byte)(bVar1 * '\x10' + 1) << 8,unaff_ER14 + -0x28);
    *(char *)(unaff_ER14 + -4) = *(char *)(unaff_ER14 + -4) + '\x01';
    bVar1 = bVar1 + 1;
  } while (bVar1 < 2);
  frame_leave();
  return 0;
}

