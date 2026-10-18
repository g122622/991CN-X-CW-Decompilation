/*
 * 启动与主流程 / 24e36_main.c
 * 地址范围: 0x24E36 - 0x24E36
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 程序主入口（由 reset_entry 跳转）
 * @addr 0x24E36
 * @module boot
 * @proto void main(byte* input)
 * @confidence verified
 * @note 程序主入口（由 reset_entry 跳转）。先初始化系统（0x9242）、RAM 有效性检查（0x90CE，失败则全清）
 *       、模式界面初始化（0x8CEE）、存储/显示初始化（0x8CE...）、自检与显示复位（0x2250E/0x22006/0x
 *       22040/0x10E9C），随后按 0xD111（模式字）无限分派各模式顶层循环。
 * @tag boot
 */
int fw_main(byte* input)

{
  undefined2 uVar1;
  
  hw_init();
  timer_wait(0x5c8);
  diag_mode = 0;
  uVar1 = ram_check();
  if ((char)uVar1 != '\0') {
    ram_clear_all();
  }
  ui_state_init();
  draw_ram_banner();
  timer_base_main();
  uVar1 = boot_key_poll();
  uVar1 = boot_key_scan(uVar1);
  if ((char)uVar1 == '\0') {
    diag_main(uVar1);
  }
  details_reset();
  do {
    while( true ) {
      while( true ) {
        while( true ) {
          while (calc_mode == '\x02') {
            mode_02_comp_loop((short)input);
          }
          if (calc_mode != '\x03') break;
          mode_03_table_loop(input);
        }
        if (calc_mode != '\x06') break;
        mode_06_stat_loop(input);
      }
      if (calc_mode == '\a') break;
      if (calc_mode == 'E') {
        mode_45_base_loop(input);
      }
      else if (calc_mode == 'J') {
        mode_4a_eqn_loop(input);
      }
      else if (calc_mode == 'K') {
        mode_4b_matrix_loop(input);
      }
      else if (calc_mode == -0x78) {
        mode_88_ratio_loop(input);
      }
      else if (calc_mode == -0x3c) {
        var_edit_loop(input);
      }
      else {
        mode_c4_disp_loop(input);
      }
    }
    hist_loop(input);
  } while( true );
}

