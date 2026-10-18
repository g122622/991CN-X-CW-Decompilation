/*
 * 自检与诊断 / 26328_diag_entry_eb05.c
 * 地址范围: 0x26328 - 0x26328
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 以常量 0xEB05 调用 0x22DFE（自检入口）
 * @addr 0x26328
 * @module diag
 * @proto void diag_entry_eb05(void)
 * @confidence likely
 * @note 以常量 0xEB05 调用 0x22DFE（自检入口）。
 * @tag diag
 */
int diag_entry_eb05(void)

{
  menu_edit_entry(0xeb05);
  return 0;
}

