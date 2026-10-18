/*
 * 应用模式 / 0d968_mode_06_stat_loop.c
 * 地址范围: 0x0D968 - 0x0DC66
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 0xD111==6，推测为 STAT 统计模式
 * @addr 0x0D968
 * @module apps
 * @proto void mode_06_stat_loop(byte* input)
 * @confidence strong
 * @note 【0xD111==6，推测为 STAT 统计模式】主循环；0xD115==3 时进入 0x22A8C 数据处理。
 * @tag mode
 */
int stat_analysis(byte* input)

{
  char cVar1;
  short sVar2;
  
  cVar1 = is_stat_running();
  if (cVar1 == '\0') {
    key_repeat_start();
  }
  do {
    cVar1 = is_stat_running();
    if (cVar1 == '\0') {
      ui_update();
      cVar1 = is_stat_running();
      if (cVar1 != '\0') goto LAB_rom_00d986;
      fb_flush();
      sVar2 = process_key((short)input);
      sVar2 = key_filter_lookup4(sVar2);
      set_input_key(sVar2);
    }
    else {
LAB_rom_00d986:
      stat_analysis(input);
      sVar2 = input_key;
    }
    if ((byte)sVar2 == 0x24 && (bool)((char)((ushort)sVar2 >> 8) + '\x04') == (byte)sVar2 < 0x24) {
      return 0;
    }
  } while( true );
}

/**
 * @brief 0xD111==0x45，推测为 BASE-N 进制模式
 * @addr 0x0DC66
 * @module apps
 * @proto void mode_45_base_loop(byte* input)
 * @confidence strong
 * @note 【0xD111==0x45，推测为 BASE-N 进制模式】主循环：调用 0x280B0 处理，直到退出键 0x24。
 * @tag mode
 */
int mode_45_base_loop(byte* input)

{
  do {
    mode_45_base_impl(input);
  } while ((byte)input_key != 0x24 ||
           (bool)((char)((ushort)input_key >> 8) + '\x04') != (byte)input_key < 0x24);
  return 0;
}

