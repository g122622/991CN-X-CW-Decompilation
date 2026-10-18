/*
 * 启动与主流程 / 13096_boot_splash.c
 * 地址范围: 0x13096 - 0x13096
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 开机画面
 * @addr 0x13096
 * @module boot
 * @proto void boot_splash(void)
 * @confidence strong
 * @note 开机画面：清屏、0x2A048(0x108) 绘制标识、延时 8000 后恢复 0xD137。
 * @tag boot
 */
int boot_splash(uintptr_t _a2, int _a1)

{
  undefined2 uVar1;
  
  cur_line = 0xe;
  cursor_visible = 0;
  draw_target = 0;
  fill_screen(0x400);
  draw_scaled_char(0x108, (uintptr_t)0);
  draw_target = 1;
  fb_alt_flush();
  timer_base_restore();
  uVar1 = timer_wait(8000);
  screen_mode_blank(uVar1);
  cur_line = prev_line;
  return _a1;
}

