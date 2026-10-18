/*
 * 硬件抽象层 / 2aa76_process_key.c
 * 地址范围: 0x2AA76 - 0x2AA76
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 主循环按键处理
 * @addr 0x2AA76
 * @module hal
 * @proto short process_key(short arg)
 * @confidence strong
 * @note 主循环按键处理：读键并处理 ON(0xFC24)/菜单(0xFC25)/普通键，更新 0xD113。
 * @tag kbd
 */
short process_key(short arg)

{
  ushort uVar1;
  byte bVar2;
  byte bVar3;
  int cVar4;
  ushort uVar5;
  
  bVar2 = frame_enter();
  stat_mode_entry();
  timer_base_restore();
  uVar5 = input_is_empty();
  bVar3 = (byte)uVar5;
  cVar4 = (char)(uVar5 >> 8);
  if (bVar3 == 0x24 && (bool)(cVar4 + '\x04') == bVar3 < 0x24) {
    input_layout = 1;
    stat_sel = 0;
    stat_rows = 0;
    stat_cols = 0;
    open_hex_view(arg);
  }
  else if (bVar3 == 0x25 && (bool)(cVar4 + '\x04') == bVar3 < 0x25) {
    if ((bVar2 & 0x20) != 0) goto LAB_rom_02aac6;
    input_layout = 2;
    stat_sel = 0;
    stat_rows = 0;
    stat_cols = 0;
    cVar4 = list_mode_main();
    if (cVar4 == '\x01') {
      key_hist_clear();
    }
  }
  else {
    if (((uVar5 < 0xfc01) ||
        (uVar1 = ((uVar5 >> 8) - 0xfc) - (ushort)(bVar3 < 7),
        (uVar1 & 0x100) == 0 && (bVar3 != 7 || (char)uVar1 != '\0'))) || ((bVar2 & 0x40) != 0))
    goto LAB_rom_02aac6;
    input_layout = 3;
    input_key = uVar5;
    table_nav_switch(0xfc03);
  }
  input_layout = 0;
LAB_rom_02aac6:
  frame_leave();
  return;
}

