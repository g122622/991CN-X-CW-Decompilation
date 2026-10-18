/*
 * 输入编辑器 / 187e6_is_edit_locked.c
 * 地址范围: 0x187E6 - 0x187E6
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 判断是否处于只读/锁定编辑
 * @addr 0x187E6
 * @module editor
 * @proto byte is_edit_locked(void)
 * @confidence likely
 * @note 判断是否处于只读/锁定编辑：读取 0x3:0xFFD9 的值并检查 0xD114/0xD11E/0xD111/0xD13C。
 * @tag editor
 */
byte is_edit_locked(void)

{
  byte in_PSW;
  
  get_ptr_ffd8_1();
  if (((((in_PSW >> 6 & 1) != 0) && ((edit_state2 & 0x40) == 0)) && (menu_io != '\0')) &&
     (((calc_mode & 0x40) != 0 && ((_DAT_ram_d13c & 1) == 0)))) {
    return 1;
  }
  return 0;
}

