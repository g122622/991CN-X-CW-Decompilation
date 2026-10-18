/*
 * 启动与主流程 / 27d90_restart_loop.c
 * 地址范围: 0x27D90 - 0x27D90
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 清缓冲并从 ROM 0xD2xx 复制提示串后跳回 0xEE2A 主循环
 * @addr 0x27D90
 * @module boot
 * @proto int restart_loop(void)
 * @confidence likely
 * @note 清缓冲并从 ROM 0xD2xx 复制提示串后跳回 0xEE2A 主循环。
 * @tag boot
 */
int restart_loop(void)

{
  undefined extraout_R1;
  undefined extraout_R1_00;
  undefined uVar1;
  undefined uVar2;
  
  uVar2 = 3;
  clear_screen();
  strcpy_checked(&input_buf,(char *)0xd248);
  history_cursor = 0;
  _DAT_ram_d157 = 1;
  input_active = 0;
  history_dirty = 0;
  if (menu_io == '\0') {
    cur_line = prev_line;
    main_loop();
    uVar1 = extraout_R1_00;
    if (prev_line == '\n') {
      uVar2 = 5;
    }
  }
  else {
    uVar2 = 1;
    call_mode_ee2a();
    line_wrap('\x0e');
    uVar1 = extraout_R1;
  }
  return CONCAT11(uVar1,uVar2);
}

