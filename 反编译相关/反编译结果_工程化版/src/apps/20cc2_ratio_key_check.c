/*
 * 应用模式 / 20cc2_ratio_key_check.c
 * 地址范围: 0x20CC2 - 0x20CC2
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief RATIO 模式（0xD111 == 0x88）的按键检查
 * @addr 0x20CC2
 * @module apps
 * @proto int ratio_key_check(void)
 * @confidence likely
 * @note RATIO 模式（0xD111 == 0x88）的按键检查：调用 0x1EB86 并按 0xD13E 分支。
 * @tag mode
 */
int ratio_key_check(void)

{
  char cVar1;
  undefined uVar2;
  
  uVar2 = 1;
  cVar1 = is_equation_mode();
  if (((calc_mode == -0x3c) || (cVar1 != '\0')) &&
     ((cVar1 == '\0' ||
      (((3 < sub_mode && (key_state_a != '\0')) && (cVar1 = is_matrix_list(), cVar1 != '\x01'))
      )))) {
    if (key_hist_b == '\x01') {
      uVar2 = 1;
    }
    else {
      uVar2 = _DAT_ram_d120;
      if (key_hist_b == '\x02') {
        uVar2 = 0;
      }
    }
  }
  return uVar2;
}

