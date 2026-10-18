/*
 * 显示驱动 / 1e27e_lcd_contrast_step.c
 * 地址范围: 0x1E27E - 0x1E27E
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 按 0xF310/0xD0F7 状态调整 0xF816 对比度寄存器并刷新
 * @addr 0x1E27E
 * @module display
 * @proto void lcd_contrast_step(void)
 * @confidence likely
 * @note 按 0xF310/0xD0F7 状态调整 0xF816 对比度寄存器并刷新。
 * @tag display
 */
int lcd_contrast_step(uintptr_t _a2, int _a1)

{
  if (diag_mode == '\0') {
    if ((int_ctrl4 & 0x10) == 0) {
      if (((display_ctrl & 1) != 0) && (display_ctrl = display_ctrl + 2, 7 < (display_ctrl & 0xf)))
      {
        lcd_refresh_req = 0;
        display_ctrl = display_ctrl & 0xf0;
      }
    }
    else {
      if ((display_ctrl & 1) == 0) {
        lcd_refresh_req = 1;
      }
      display_ctrl = display_ctrl & 0xf0 | 1;
    }
    if ((int_src_ctrl & 2) != 0) {
      int_src_ctrl = int_src_ctrl & 0xfd;
    }
    if (_a1 != '\0') {
      lcd_mode = 0x15;
    }
  }
  return 0;
}

