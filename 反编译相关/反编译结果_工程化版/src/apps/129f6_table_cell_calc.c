/*
 * 应用模式 / 129f6_table_cell_calc.c
 * 地址范围: 0x129F6 - 0x129F6
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief TABLE 模式单元格计算（十进制运算调用）
 * @addr 0x129F6
 * @module apps
 * @proto int table_cell_calc(void)
 * @confidence likely
 * @note TABLE 模式单元格计算（十进制运算调用）。
 * @tag mode
 */
int table_cell_calc(void)

{
  char cVar1;
  byte extraout_R1;
  short sVar2;
  byte extraout_R1_00;
  ushort uVar3;
  undefined2 *puVar4;
  undefined2 *puVar5;
  byte bVar6;
  short unaff_ER14;
  
  puVar4 = (undefined2 *)(unaff_ER14 + -0x14);
  cVar1 = stat_table_base(puVar4);
  *(char *)(unaff_ER14 + -9) = cVar1;
  if (cVar1 == '\0') {
    uVar3 = dec_set_special((ushort *)(unaff_ER14 + -0x46),3);
    sVar2 = CONCAT11((char)(uVar3 >> 8),0xf0);
  }
  else if (var_list_open == '\0') {
    dec_set_from_fmt(unaff_ER14 + -0x46,CONCAT11((char)((ushort)puVar4 >> 8),cVar1));
    sVar2 = (ushort)extraout_R1 << 8;
  }
  else {
    stat_cell_addr_ex(0x102,(short *)(unaff_ER14 + -4));
    cVar1 = stat_table_width();
    *(char *)(unaff_ER14 + -10) = cVar1 * '\n';
    puVar4 = *(undefined2 **)(unaff_ER14 + -4);
    bVar6 = *(byte *)(unaff_ER14 + -10);
    cVar1 = *(char *)(unaff_ER14 + -9);
    dec_set_uint_small((ushort *)(unaff_ER14 + -0x1e),0);
    do {
      puVar5 = puVar4;
      dec_copy((undefined2 *)(unaff_ER14 + -0x14),puVar4);
      dec_bin_init((undefined2 *)(unaff_ER14 + -0x14),puVar5);
      dec_bin_div_core(unaff_ER14 + -0x1e,unaff_ER14 + -0x14);
      puVar4 = (undefined2 *)((short)puVar4 + (ushort)bVar6);
      cVar1 = cVar1 + -1;
    } while (cVar1 != '\0');
    dec_copy((undefined2 *)(unaff_ER14 + -0x46),(undefined2 *)(unaff_ER14 + -0x1e));
    sVar2 = (ushort)extraout_R1_00 << 8;
  }
  return sVar2;
}

