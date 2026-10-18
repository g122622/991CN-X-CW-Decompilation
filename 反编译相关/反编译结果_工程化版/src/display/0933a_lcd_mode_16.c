/*
 * 显示驱动 / 0933a_lcd_mode_16.c
 * 地址范围: 0x0933A - 0x0933A
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 0xD114 的 bit4 未置位时把 LCD 模式 0xF031 置 0x16，再调用 0…
 * @addr 0x0933A
 * @module display
 * @proto undefined2 lcd_mode_16(undefined2 v)
 * @confidence strong
 * @note 0xD114 的 bit4 未置位时把 LCD 模式 0xF031 置 0x16，再调用 0x9358 清状态。
 * @tag display
 */
undefined2 lcd_mode_16(undefined2 v)

{
  if ((edit_state2 & 0x10) == 0) {
    lcd_mode = 0x16;
  }
  status_flags_clear();
  return v;
}

