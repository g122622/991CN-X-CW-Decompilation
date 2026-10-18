/*
 * BCD 浮点库 / 0f672_bcd_compare_print.c
 * 地址范围: 0x0F672 - 0x0F672
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 比较两个 BCD 并打印结果
 * @addr 0x0F672
 * @module bcd
 * @proto void bcd_compare_print(char mode)
 * @confidence likely
 * @note 比较两个 BCD 并打印结果：0x2A428 构造格式、0x1C894/0x1D620 比较。
 * @tag bcd
 */
int bcd_compare_print(char mode)

{
  undefined2 *puVar1;
  ushort uVar2;
  short unaff_ER14;
  
  puVar1 = (undefined2 *)frame_enter();
  dec_copy_rev((undefined2 *)(unaff_ER14 + -0x14),puVar1);
  format_pattern_b((undefined *)(unaff_ER14 + -0x1e));
  if (mode == '\x02') {
    dec_bin_xor_core(unaff_ER14 + -0x14,(undefined2 *)(unaff_ER14 + -0x1e));
  }
  dec_copy((undefined2 *)(unaff_ER14 + -10),(undefined2 *)(unaff_ER14 + -0x14));
  var_unit_init((undefined *)(unaff_ER14 + -0x14));
  dec_abs_wrap();
  format_pattern_a((undefined *)(unaff_ER14 + -0x1e));
  var_unit_init((undefined *)(unaff_ER14 + -0x28));
  uVar2 = dec_to_string(unaff_ER14 + -0x14,(undefined2 *)(unaff_ER14 + -0x1e));
  if ((uVar2 & 4) != 0) {
    dec_bin_or_core(unaff_ER14 + -0x14,unaff_ER14 + -0x28);
  }
  uVar2 = dec_to_string(unaff_ER14 + -10,(undefined2 *)(unaff_ER14 + -0x1e));
  if ((uVar2 & 4) != 0) {
    dec_bin_or_core(unaff_ER14 + -10,unaff_ER14 + -0x28);
  }
  dec_copy_rev(puVar1,(undefined2 *)(unaff_ER14 + -0x14));
  frame_leave();
  return 0;
}

