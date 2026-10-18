/*
 * 应用模式 / 1eb86_is_equation_mode.c
 * 地址范围: 0x1EB86 - 0x1EE58
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 返回 (0xD111 == 0x45) && (0xD114 == 1)
 * @addr 0x1EB86
 * @module apps
 * @proto char is_equation_mode(void)
 * @confidence verified
 * @note 返回 (0xD111 == 0x45) && (0xD114 == 1)：方程/函数（EQUA）模式的编辑状态判断。
 * @tag mode
 */
char is_equation_mode(void)

{
  if ((calc_mode == 'E') && (edit_state2 == '\x01')) {
    return 1;
  }
  return 0;
}

/**
 * @brief 0xD111==0x88，推测为比例模式
 * @addr 0x1EE58
 * @module apps
 * @proto void mode_88_ratio_loop(byte* input)
 * @confidence strong
 * @note 【0xD111==0x88，推测为比例模式】主循环：编辑比值表达式，处理 = 求值。
 * @tag mode
 */
int mode_88_ratio_loop(byte* input)

{
  char cVar1;
  short sVar2;
  char *pcVar3;
  byte bVar4;
  
  key_repeat_start();
  do {
    ui_update();
LAB_rom_01ee78:
    while( true ) {
      fb_flush();
      do {
        sVar2 = process_key((short)input);
        sVar2 = key_filter_582c(sVar2);
        set_input_key(sVar2);
        bVar4 = (byte)sVar2;
        cVar1 = (char)((ushort)sVar2 >> 8);
        if ((bVar4 != 0x2d || (bool)(cVar1 + '\x04') != bVar4 < 0x2d) &&
           (bVar4 != 0x30 || (bool)(cVar1 + '\x04') != bVar4 < 0x30)) goto LAB_rom_01ef56;
      } while (((ratio_flags & 1) == 0) && (input_buf == '\0'));
      name_buffer_load();
      if (history_recall != '\x01') break;
      if ((ratio_flags & 1) != 0) {
        ratio_flags = 0;
        if (input_buf == '\0') {
          ratio_flags = 0x80;
        }
        input = &input_buf;
        strcpy_checked((char *)0xd84c,&input_buf);
        goto LAB_rom_01ef26;
      }
      strcpy_checked((char *)0xd248,&input_buf);
      input_init();
      input = (byte *)0xd84c;
      strcpy_checked(&input_buf,(char *)0xd84c);
      cVar1 = is_math_io();
      if ((cVar1 != '\0') && (pcVar3 = (char *)input_history_ptr(), pcVar3 != (char *)0x0)) {
        input = &input_buf;
        strcpy_checked(pcVar3,&input_buf);
      }
      ratio_flags = 1;
      list_paint();
    }
    input = &input_buf;
    strcpy_checked((char *)0xd248,&input_buf);
LAB_rom_01ef26:
    stat_edit_loop(input);
    sVar2 = input_key;
    if (stat_state != '\x04') goto LAB_rom_01ef56;
    edit_ctx_check();
    if (edit_state2 != '\x12') {
      input_init();
      list_paint();
      goto LAB_rom_01ee78;
    }
    list_ui_loop(input);
    sVar2 = input_key;
LAB_rom_01ef56:
    if ((byte)sVar2 == 0x24 && (bool)((char)((ushort)sVar2 >> 8) + '\x04') == (byte)sVar2 < 0x24) {
      return 0;
    }
  } while( true );
}

