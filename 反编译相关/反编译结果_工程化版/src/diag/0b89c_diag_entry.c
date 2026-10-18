/*
 * 自检与诊断 / 0b89c_diag_entry.c
 * 地址范围: 0x0B89C - 0x0B89C
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 以常量 0xEB42 调用 0x22DFE（自检入口）
 * @addr 0x0B89C
 * @module diag
 * @proto void diag_entry(void)
 * @confidence likely
 * @note 以常量 0xEB42 调用 0x22DFE（自检入口）。
 * @tag diag
 */
int diag_entry(void)

{
  menu_edit_entry(0xeb42);
  return 0;
}

