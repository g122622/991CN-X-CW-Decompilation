/*
 * 应用模式 / 09d94_mode_02_comp_loop.c
 * 地址范围: 0x09D94 - 0x09D94
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 0xD111==2，通常为 COMP 计算模式
 * @addr 0x09D94
 * @module apps
 * @proto void mode_02_comp_loop(short input)
 * @confidence strong
 * @note 【0xD111==2，通常为 COMP 计算模式】主循环：显示光标、编辑、回车触发计算并更新历史。
 * @tag mode
 */
int mode_02_comp_loop(short input)

{
  undefined2 uVar1;
  short sVar2;
  
  key_repeat_start();
  do {
    uVar1 = ui_update();
    set_dirty_flag(uVar1);
    fb_flush();
    sVar2 = process_key(input);
    sVar2 = key_filter_386c(sVar2);
    set_input_key(sVar2);
  } while ((byte)sVar2 != 0x24 || (bool)((char)((ushort)sVar2 >> 8) + '\x04') != (byte)sVar2 < 0x24)
  ;
  return 0;
}

