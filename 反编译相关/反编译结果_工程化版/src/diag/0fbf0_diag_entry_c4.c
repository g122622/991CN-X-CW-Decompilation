/*
 * 自检与诊断 / 0fbf0_diag_entry_c4.c
 * 地址范围: 0x0FBF0 - 0x0FBF0
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 以常量 0xEB13 调用 0x22DFE（自检入口）
 * @addr 0x0FBF0
 * @module diag
 * @proto void diag_entry_c4(void)
 * @confidence likely
 * @note 以常量 0xEB13 调用 0x22DFE（自检入口）。
 * @tag diag
 */
int diag_entry_c4(void)

{
  menu_edit_entry(0xeb13);
  return 0;
}

