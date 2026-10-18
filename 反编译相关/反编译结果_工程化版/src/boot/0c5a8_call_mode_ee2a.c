/*
 * 启动与主流程 / 0c5a8_call_mode_ee2a.c
 * 地址范围: 0x0C5A8 - 0x0C5A8
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 直接跳入 0xEE2A（主循环）
 * @addr 0x0C5A8
 * @module boot
 * @proto void call_mode_ee2a(void)
 * @confidence strong
 * @note 直接跳入 0xEE2A（主循环）。
 * @tag boot
 */
int call_mode_ee2a(void)

{
  main_loop();
  return 0;
}

