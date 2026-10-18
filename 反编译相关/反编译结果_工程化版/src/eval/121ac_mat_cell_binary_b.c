/*
 * 表达式求值 / 121ac_mat_cell_binary_b.c
 * 地址范围: 0x121AC - 0x12832
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 矩阵单元二元运算 B（2.7KB）
 * @addr 0x121AC
 * @module eval
 * @proto int mat_cell_binary_b(void)
 * @confidence likely
 * @note 矩阵单元二元运算 B（2.7KB）。
 * @tag matrix
 */
int mat_cell_binary_b(void)

{
  byte bVar1;
  byte bVar2;
  undefined2 *puVar3;
  undefined2 *unaff_ER4;
  byte unaff_R6;
  char unaff_R7;
  undefined2 *unaff_ER8;
  byte unaff_R12;
  char unaff_R13;
  short unaff_ER14;
  
  stat_load_row_a();
  if (unaff_R7 == '\0') {
    dec_set_special((ushort *)(unaff_ER14 + -0x32),3);
    dec_set_special((ushort *)(unaff_ER14 + -0x3c),3);
  }
  else {
    unaff_R13 = '\0';
    if (((unaff_R12 & 0xf0) == 0) && ((stat_rows & 0x10) != 0)) {
      unaff_R13 = '\x01';
      var_load_to_reg((undefined2 *)(unaff_ER14 + -0x32),100);
    }
    else {
      dec_set_uint_small((ushort *)(unaff_ER14 + -0x32),0);
      dec_set_uint_small((ushort *)(unaff_ER14 + -0x3c),0);
      do {
        puVar3 = unaff_ER4;
        dec_copy((undefined2 *)(unaff_ER14 + -0x14),unaff_ER4);
        dec_bin_init((undefined2 *)(unaff_ER14 + -0x14),puVar3);
        if ((unaff_R12 & 0x10) != 0) {
          dec_bin_mul_core(unaff_ER14 + -0x14,unaff_ER14 + -0x50);
        }
        puVar3 = (undefined2 *)(unaff_ER14 + -0x14);
        dec_copy((undefined2 *)(unaff_ER14 + -0x28),puVar3);
        decm_pow((undefined2 *)(unaff_ER14 + -0x14),puVar3);
        dec_bin_pow_core(unaff_ER14 + -0x14,unaff_ER14 + -0x28);
        dec_bin_pow_core(unaff_ER14 + -0x28,unaff_ER14 + -0x14);
        if (var_list_open != '\0') {
          puVar3 = unaff_ER8;
          dec_copy((undefined2 *)(unaff_ER14 + -0x1e),unaff_ER8);
          dec_bin_init((undefined2 *)(unaff_ER14 + -0x1e),puVar3);
          dec_bin_pow_core(unaff_ER14 + -0x14,unaff_ER14 + -0x1e);
          dec_bin_pow_core(unaff_ER14 + -0x28,unaff_ER14 + -0x1e);
        }
        dec_bin_div_core(unaff_ER14 + -0x32,unaff_ER14 + -0x14);
        dec_bin_div_core(unaff_ER14 + -0x3c,unaff_ER14 + -0x28);
        bVar1 = bcd_type((byte *)(unaff_ER14 + -0x32));
        if ((bVar1 != 0) && (bVar1 = bcd_type((byte *)(unaff_ER14 + -0x3c)), bVar1 != 0))
        break;
        unaff_ER4 = (undefined2 *)((short)unaff_ER4 + (ushort)unaff_R6);
        unaff_ER8 = (undefined2 *)((short)unaff_ER8 + (ushort)unaff_R6);
        unaff_R7 = unaff_R7 + -1;
      } while (unaff_R7 != '\0');
    }
  }
  dec_copy((undefined2 *)(unaff_ER14 + -0x96),(undefined2 *)(unaff_ER14 + -0x32));
  dec_copy((undefined2 *)(unaff_ER14 + -0xa0),(undefined2 *)(unaff_ER14 + -0x3c));
  bVar1 = bcd_type((byte *)(unaff_ER14 + -0x32));
  if (bVar1 != 0) {
    bVar1 = 0xf;
  }
  bVar2 = bcd_type((byte *)(unaff_ER14 + -0x3c));
  if (bVar2 != 0) {
    bVar2 = 0xf0;
  }
  if ((unaff_R13 == '\0') && ((unaff_R12 & 0xf0) == 0)) {
    var_store_from_reg(100,(undefined2 *)(unaff_ER14 + -0x32));
    stat_rows = stat_rows | 0x10;
  }
  return CONCAT11(bVar1,bVar2 | bVar1);
}

/**
 * @brief STAT 模式的辅助计算（读 0xD164/0xD165 统计标志）
 * @addr 0x12316
 * @module eval
 * @proto undefined2 stat_aux(void)
 * @confidence likely
 * @note STAT 模式的辅助计算（读 0xD164/0xD165 统计标志）。
 * @tag stat
 */
undefined2 stat_aux(void)

{
  char cVar1;
  byte bVar2;
  byte bVar3;
  undefined2 *puVar4;
  short sVar5;
  undefined2 *unaff_ER4;
  byte unaff_R6;
  char unaff_R7;
  undefined2 *unaff_ER8;
  byte unaff_R12;
  short unaff_ER14;
  
  cVar1 = stat_table_base((undefined2 *)(unaff_ER14 + -0x14));
  if (cVar1 == '\0') {
    dec_set_special((ushort *)(unaff_ER14 + -0x14),3);
    dec_set_special((ushort *)(unaff_ER14 + -0x28),3);
    goto LAB_rom_01246e;
  }
  if ((unaff_R12 & 0xf0) == 0) {
    if ((unaff_R12 & 1) == 0) {
      bVar3 = 0;
      bVar2 = stat_rows;
    }
    else {
      bVar3 = 10;
      bVar2 = stat_cols;
    }
    if ((bVar2 & 4) == 0) goto LAB_rom_01236a;
    var_load_to_reg((undefined2 *)(unaff_ER14 + -0x28),bVar3);
    table_cell_calc();
  }
  else {
LAB_rom_01236a:
    stat_menu_blk();
    stat_load_row_a();
    dec_set_uint_small((ushort *)(unaff_ER14 + -0x28),0);
    do {
      puVar4 = unaff_ER4;
      dec_copy((undefined2 *)(unaff_ER14 + -0x14),unaff_ER4);
      dec_bin_init((undefined2 *)(unaff_ER14 + -0x14),puVar4);
      sVar5 = unaff_ER14 + -0x50;
      dec_bin_mul_core(unaff_ER14 + -0x14,sVar5);
      decm_pow((undefined2 *)(unaff_ER14 + -0x14),sVar5);
      if (var_list_open != '\0') {
        puVar4 = unaff_ER8;
        dec_copy((undefined2 *)(unaff_ER14 + -0x1e),unaff_ER8);
        dec_bin_init((undefined2 *)(unaff_ER14 + -0x1e),puVar4);
        dec_bin_pow_core(unaff_ER14 + -0x14,unaff_ER14 + -0x1e);
      }
      dec_bin_div_core(unaff_ER14 + -0x28,unaff_ER14 + -0x14);
      bVar2 = bcd_type((byte *)(unaff_ER14 + -0x28));
      if (bVar2 != 0) goto LAB_rom_01246e;
      unaff_ER4 = (undefined2 *)((short)unaff_ER4 + (ushort)unaff_R6);
      unaff_ER8 = (undefined2 *)((short)unaff_ER8 + (ushort)unaff_R6);
      unaff_R7 = unaff_R7 + -1;
    } while (unaff_R7 != '\0');
    if ((unaff_R12 & 0xf0) == 0) {
      if ((unaff_R12 & 1) == 0) {
        stat_rows = stat_rows | 4;
        bVar2 = 0;
      }
      else {
        stat_cols = stat_cols | 4;
        bVar2 = 10;
      }
      var_store_from_reg(bVar2,(undefined2 *)(unaff_ER14 + -0x28));
    }
  }
  dec_copy((undefined2 *)(unaff_ER14 + -0x14),(undefined2 *)(unaff_ER14 + -0x28));
  dec_copy((undefined2 *)(unaff_ER14 + -0x1e),(undefined2 *)(unaff_ER14 + -0x46));
  sVar5 = unaff_ER14 + -0x1e;
  dec_bin_and_core(unaff_ER14 + -0x14,sVar5);
  if ((unaff_R12 & 8) == 0) {
    decm_power_common((undefined2 *)(unaff_ER14 + -0x14),sVar5);
  }
  dec_set_uint_small((ushort *)(unaff_ER14 + -0x32),1);
  dec_bin_mul_core(unaff_ER14 + -0x1e,unaff_ER14 + -0x32);
  sVar5 = unaff_ER14 + -0x1e;
  dec_bin_and_core(unaff_ER14 + -0x28,sVar5);
  if ((unaff_R12 & 8) == 0) {
    decm_power_common((undefined2 *)(unaff_ER14 + -0x28),sVar5);
  }
LAB_rom_01246e:
  dec_copy((undefined2 *)(unaff_ER14 + -100),(undefined2 *)(unaff_ER14 + -0x14));
  dec_copy((undefined2 *)(unaff_ER14 + -0x6e),(undefined2 *)(unaff_ER14 + -0x28));
  bVar2 = bcd_type((byte *)(unaff_ER14 + -0x14));
  if (bVar2 != 0) {
    bVar2 = 0xf;
  }
  bVar3 = bcd_type((byte *)(unaff_ER14 + -0x28));
  if (bVar3 != 0) {
    bVar3 = 0xf0;
  }
  return CONCAT11(bVar2,bVar3 | bVar2);
}

/**
 * @brief 统计菜单块（0x129F6/0x12832 后按 R12 选择）
 * @addr 0x124AE
 * @module eval
 * @proto void stat_menu_blk(void)
 * @confidence likely
 * @note 统计菜单块（0x129F6/0x12832 后按 R12 选择）。
 * @tag app
 */
int stat_menu_blk(void)

{
  undefined uVar1;
  undefined2 uVar2;
  byte unaff_R12;
  short unaff_ER14;
  
  uVar2 = table_cell_calc();
  if ((char)uVar2 == '\0') {
    stat_sub_loop();
    if ((unaff_R12 & 1) == 0) {
      uVar1 = 0x9c;
    }
    else {
      uVar1 = 0x88;
    }
    dec_bin_and_core(CONCAT11(0xff,uVar1) + unaff_ER14,unaff_ER14 + -0x46);
    if ((unaff_R12 & 1) == 0) {
      uVar1 = 0x9c;
    }
    else {
      uVar1 = 0x88;
    }
    dec_copy((undefined2 *)(unaff_ER14 + -0x50), (uintptr_t)0)
                   (undefined2 *)(CONCAT11(0xff,uVar1) + unaff_ER14));
  }
  else {
    dec_set_special((ushort *)(unaff_ER14 + -0x50),3);
  }
  bcd_type((byte *)(unaff_ER14 + -0x50));
  return 0;
}

/**
 * @brief 单变量统计计算（Σx、Σx²、σ 等）
 * @addr 0x12506
 * @module eval
 * @proto int stat_1var_calc(void)
 * @confidence likely
 * @note 单变量统计计算（Σx、Σx²、σ 等）。
 * @tag stat
 */
int stat_1var_calc(void)

{
  byte bVar1;
  undefined2 uVar2;
  ushort uVar3;
  undefined2 *puVar4;
  undefined2 *unaff_ER4;
  byte unaff_R6;
  char unaff_R7;
  undefined2 *unaff_ER8;
  undefined2 *unaff_ER10;
  byte unaff_R12;
  char unaff_R13;
  short unaff_ER14;
  
  stat_load_row_b();
  if (unaff_R7 == '\0') {
    dec_set_special((ushort *)(unaff_ER14 + -0x28),3);
  }
  else {
    unaff_R13 = '\0';
    if (((unaff_R12 & 0xf2) == 0) && ((stat_rows & 0x20) != 0)) {
      var_load_to_reg((undefined2 *)(unaff_ER14 + -0x28),0x78);
      unaff_R13 = '\x01';
    }
    else {
      dec_set_uint_small((ushort *)(unaff_ER14 + -0x28),0);
      do {
        puVar4 = unaff_ER4;
        dec_copy((undefined2 *)(unaff_ER14 + -0x14),unaff_ER4);
        dec_bin_init((undefined2 *)(unaff_ER14 + -0x14),puVar4);
        if ((unaff_R12 & 0x20) != 0) {
          decm_nroot((undefined2 *)(unaff_ER14 + -0x14),puVar4);
        }
        if ((unaff_R12 & 0x40) != 0) {
          decm_cos(unaff_ER14 + -0x14,puVar4);
        }
        puVar4 = unaff_ER10;
        dec_copy((undefined2 *)(unaff_ER14 + -0x1e),unaff_ER10);
        dec_bin_init((undefined2 *)(unaff_ER14 + -0x1e),puVar4);
        if ((unaff_R12 & 0x80) != 0) {
          decm_cos(unaff_ER14 + -0x1e,puVar4);
        }
        if ((unaff_R12 & 0x10) != 0) {
          dec_bin_mul_core(unaff_ER14 + -0x14,unaff_ER14 + -0x50);
          dec_bin_mul_core(unaff_ER14 + -0x1e,unaff_ER14 + -0x5a);
        }
        if (var_list_open != '\0') {
          puVar4 = unaff_ER8;
          dec_copy((undefined2 *)(unaff_ER14 + -0x32),unaff_ER8);
          dec_bin_init((undefined2 *)(unaff_ER14 + -0x32),puVar4);
          dec_bin_pow_core(unaff_ER14 + -0x14,unaff_ER14 + -0x32);
        }
        dec_bin_pow_core(unaff_ER14 + -0x14,unaff_ER14 + -0x1e);
        dec_bin_div_core(unaff_ER14 + -0x28,unaff_ER14 + -0x14);
        bVar1 = bcd_type((byte *)(unaff_ER14 + -0x28));
        if (bVar1 != 0) break;
        if (((unaff_R12 & 2) != 0) && (uVar2 = kbd_wait_key(), (char)uVar2 != '\0')) {
          dec_set_special((ushort *)(unaff_ER14 + -0x28),1);
          break;
        }
        uVar3 = (ushort)unaff_R6;
        unaff_ER4 = (undefined2 *)((short)unaff_ER4 + uVar3);
        unaff_ER8 = (undefined2 *)((short)unaff_ER8 + uVar3);
        unaff_ER10 = (undefined2 *)((short)unaff_ER10 + uVar3);
        unaff_R7 = unaff_R7 + -1;
      } while (unaff_R7 != '\0');
    }
  }
  dec_copy((undefined2 *)(unaff_ER14 + -0x8c),(undefined2 *)(unaff_ER14 + -0x28));
  bVar1 = bcd_type((byte *)(unaff_ER14 + -0x28));
  if ((unaff_R13 == '\0') && ((unaff_R12 & 0xf2) == 0)) {
    var_store_from_reg(0x78,(undefined2 *)(unaff_ER14 + -0x28));
    stat_rows = stat_rows | 0x20;
  }
  return bVar1;
}

/**
 * @brief STAT 表格编辑循环（调用 0x16EF0 系列表格函数）
 * @addr 0x12650
 * @module eval
 * @proto int stat_table_loop(void)
 * @confidence likely
 * @note STAT 表格编辑循环（调用 0x16EF0 系列表格函数）。
 * @tag stat
 */
int stat_table_loop(void)

{
  bool bVar1;
  undefined uVar2;
  char cVar3;
  byte bVar4;
  ushort uVar5;
  undefined2 uVar6;
  short *psVar7;
  undefined2 *puVar8;
  undefined2 *puVar9;
  byte bVar10;
  byte unaff_R10;
  byte unaff_R11;
  byte unaff_R12;
  char unaff_R13;
  short unaff_ER14;
  
  bVar1 = false;
  uVar2 = stat_table_base((undefined2 *)(unaff_ER14 + -0x14));
  *(undefined *)(unaff_ER14 + -9) = uVar2;
  psVar7 = (short *)(unaff_ER14 + -4);
  stat_cell_addr_ex(CONCAT11(1,unaff_R12 & 1),psVar7);
  puVar9 = *(undefined2 **)(unaff_ER14 + -4);
  cVar3 = stat_table_width();
  *(char *)(unaff_ER14 + -10) = cVar3 * '\n';
  bVar10 = *(byte *)(unaff_ER14 + -10);
  cVar3 = *(char *)(unaff_ER14 + -9);
  if (cVar3 == '\0') {
    dec_set_special((ushort *)(unaff_ER14 + -0x1e),3);
  }
  else {
    unaff_R13 = '\0';
    if ((unaff_R12 & 0x70) == 0) {
      if ((unaff_R12 & 1) == 0) {
        unaff_R11 = 0x14;
        bVar4 = stat_rows;
      }
      else {
        unaff_R11 = 0x28;
        bVar4 = stat_cols;
      }
      if ((unaff_R12 & 0x80) == 0) {
        unaff_R10 = 1;
      }
      else {
        unaff_R10 = 2;
        unaff_R11 = unaff_R11 + 10;
      }
      if ((bVar4 & unaff_R10) != 0) {
        var_load_to_reg((undefined2 *)(unaff_ER14 + -0x1e),unaff_R11);
        unaff_R13 = '\x01';
        goto LAB_rom_0127a4;
      }
    }
    if ((var_list_open != '\0') && ((unaff_R12 & 0x70) == 0)) {
      bVar1 = true;
    }
    if (bVar1) {
      do {
        uVar5 = (ushort)(byte)(bVar10 - 10);
        if ((unaff_R12 & 1) != 0) {
          uVar5 = uVar5 - 10;
        }
        uVar6 = dec_cmp((undefined2 *)(uVar5 + (short)puVar9),psVar7);
        if ((char)uVar6 != '\x01') goto LAB_rom_012706;
        puVar9 = (undefined2 *)((short)puVar9 + (ushort)bVar10);
        cVar3 = cVar3 + -1;
      } while (cVar3 != '\0');
      dec_set_special((ushort *)(unaff_ER14 + -0x1e),3);
    }
    else {
LAB_rom_012706:
      puVar8 = puVar9;
      dec_copy((undefined2 *)(unaff_ER14 + -0x1e),puVar9);
      dec_bin_init((undefined2 *)(unaff_ER14 + -0x1e),puVar8);
      dec_entry_x(unaff_ER14 + -0x1e,puVar8);
      if ((unaff_R12 & 0x20) != 0) {
        decm_nroot((undefined2 *)(unaff_ER14 + -0x1e),puVar8);
      }
      do {
        if (bVar1) {
          uVar5 = (ushort)(byte)(bVar10 - 10);
          if ((unaff_R12 & 1) != 0) {
            uVar5 = uVar5 - 10;
          }
          uVar6 = dec_cmp((undefined2 *)(uVar5 + (short)puVar9),puVar8);
          if ((char)uVar6 != '\x01') goto LAB_rom_012748;
        }
        else {
LAB_rom_012748:
          puVar8 = puVar9;
          dec_copy((undefined2 *)(unaff_ER14 + -0x14),puVar9);
          dec_bin_init((undefined2 *)(unaff_ER14 + -0x14),puVar8);
          dec_entry_x(unaff_ER14 + -0x14,puVar8);
          if ((unaff_R12 & 0x20) != 0) {
            decm_nroot((undefined2 *)(unaff_ER14 + -0x14),puVar8);
          }
          puVar8 = (undefined2 *)(unaff_ER14 + -0x14);
          uVar6 = dec_to_string(unaff_ER14 + -0x1e,puVar8);
          if ((unaff_R12 & 0x80) == 0) {
            if ((char)uVar6 == '\x04') {
LAB_rom_012782:
              puVar8 = (undefined2 *)(unaff_ER14 + -0x14);
              dec_copy((undefined2 *)(unaff_ER14 + -0x1e),puVar8);
            }
          }
          else if ((char)uVar6 == '\x02') goto LAB_rom_012782;
        }
        puVar9 = (undefined2 *)((short)puVar9 + (ushort)bVar10);
        cVar3 = cVar3 + -1;
      } while (cVar3 != '\0');
      if ((unaff_R12 & 0x40) != 0) {
        decm_cos(unaff_ER14 + -0x1e,puVar8);
      }
    }
  }
LAB_rom_0127a4:
  if ((unaff_R12 & 1) == 0) {
    dec_copy((undefined2 *)(unaff_ER14 + -0x50),(undefined2 *)(unaff_ER14 + -0x1e));
    uVar2 = 100;
  }
  else {
    dec_copy((undefined2 *)(unaff_ER14 + -0x5a),(undefined2 *)(unaff_ER14 + -0x1e));
    uVar2 = 0x65;
  }
  if (((unaff_R12 & 0x70) == 0) && (unaff_R13 == '\0')) {
    var_store_from_reg(unaff_R11,(undefined2 *)(unaff_ER14 + -0x1e));
    *(byte *)CONCAT11(0xd1,uVar2) = *(byte *)CONCAT11(0xd1,uVar2) | unaff_R10;
  }
  bcd_type((byte *)(unaff_ER14 + -0x1e));
  return 0;
}

/**
 * @brief 把变量槽 (idx<<3)+0xDBE6 的 BCD 载入 dst
 * @addr 0x127FA
 * @module eval
 * @proto void var_load_to_reg(undefined2* dst, byte idx)
 * @confidence likely
 * @note 把变量槽 (idx<<3)+0xDBE6 的 BCD 载入 dst。
 * @tag var
 */
int var_load_to_reg(undefined2* dst, byte idx)

{
  short sVar1;
  undefined2 *puVar2;
  char unaff_R13;
  
  puVar2 = (undefined2 *)((uintptr_t)idx + 0xdbe8);
  sVar1 = dec_copy(dst,puVar2);
  if (unaff_R13 != '\0') {
    dec_copy((undefined2 *)(sVar1 + -10),puVar2 + 5);
  }
  return 0;
}

/**
 * @brief 把 src 存入变量槽 (idx<<3)+0xDBE6
 * @addr 0x12816
 * @module eval
 * @proto void var_store_from_reg(byte idx, undefined2* src)
 * @confidence likely
 * @note 把 src 存入变量槽 (idx<<3)+0xDBE6。
 * @tag var
 */
int var_store_from_reg(byte idx, undefined2* src)

{
  short sVar1;
  char unaff_R13;
  
  sVar1 = dec_copy((undefined2 *)((uintptr_t)idx + 0xdbe8),src);
  if (unaff_R13 != '\0') {
    dec_copy((undefined2 *)(sVar1 + 10),src + -5);
  }
  return 0;
}

/**
 * @brief STAT 子模式主循环（读键 + 十进制运算分派）
 * @addr 0x12832
 * @module eval
 * @proto int stat_sub_loop(void)
 * @confidence likely
 * @note STAT 子模式主循环（读键 + 十进制运算分派）。
 * @tag stat
 */
int stat_sub_loop(void)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  undefined2 uVar4;
  undefined uVar5;
  undefined2 *puVar6;
  undefined2 *unaff_ER4;
  byte unaff_R6;
  char unaff_R7;
  undefined2 *unaff_ER8;
  byte unaff_R12;
  char unaff_R13;
  short unaff_ER14;
  
  stat_load_row_a();
  if (unaff_R7 == '\0') {
    dec_set_special((ushort *)(unaff_ER14 + -0x32),3);
    dec_set_special((ushort *)(unaff_ER14 + -0x3c),3);
  }
  else {
    unaff_R13 = '\0';
    if ((unaff_R12 & 0xf2) == 0) {
      if ((unaff_R12 & 1) == 0) {
        bVar2 = 0x3c;
        bVar1 = stat_rows;
      }
      else {
        bVar2 = 0x50;
        bVar1 = stat_cols;
      }
      if ((bVar1 & 8) != 0) {
        unaff_R13 = '\x01';
        var_load_to_reg((undefined2 *)(unaff_ER14 + -0x32),bVar2);
        goto LAB_rom_012962;
      }
    }
    dec_set_uint_small((ushort *)(unaff_ER14 + -0x32),0);
    dec_set_uint_small((ushort *)(unaff_ER14 + -0x3c),0);
    do {
      puVar6 = unaff_ER4;
      dec_copy((undefined2 *)(unaff_ER14 + -0x14),unaff_ER4);
      dec_bin_init((undefined2 *)(unaff_ER14 + -0x14),puVar6);
      if ((unaff_R12 & 0x20) != 0) {
        decm_nroot((undefined2 *)(unaff_ER14 + -0x14),puVar6);
      }
      if ((unaff_R12 & 0x40) != 0) {
        decm_cos(unaff_ER14 + -0x14,puVar6);
      }
      if ((unaff_R12 & 0x10) != 0) {
        if ((unaff_R12 & 1) == 0) {
          uVar5 = 0xb0;
        }
        else {
          uVar5 = 0xa6;
        }
        dec_bin_mul_core(unaff_ER14 + -0x14,CONCAT11(0xff,uVar5) + unaff_ER14);
      }
      puVar6 = (undefined2 *)(unaff_ER14 + -0x14);
      dec_copy((undefined2 *)(unaff_ER14 + -0x28),puVar6);
      decm_pow((undefined2 *)(unaff_ER14 + -0x28),puVar6);
      if (var_list_open != '\0') {
        puVar6 = unaff_ER8;
        dec_copy((undefined2 *)(unaff_ER14 + -0x1e),unaff_ER8);
        dec_bin_init((undefined2 *)(unaff_ER14 + -0x1e),puVar6);
        dec_bin_pow_core(unaff_ER14 + -0x14,unaff_ER14 + -0x1e);
        dec_bin_pow_core(unaff_ER14 + -0x28,unaff_ER14 + -0x1e);
      }
      dec_bin_div_core(unaff_ER14 + -0x32,unaff_ER14 + -0x14);
      dec_bin_div_core(unaff_ER14 + -0x3c,unaff_ER14 + -0x28);
      bVar1 = bcd_type((byte *)(unaff_ER14 + -0x32));
      if ((bVar1 != 0) && (bVar1 = bcd_type((byte *)(unaff_ER14 + -0x3c)), bVar1 != 0)) break;
      if (((unaff_R12 & 2) != 0) && (uVar4 = kbd_wait_key(), (char)uVar4 != '\0')) {
        dec_set_special((ushort *)(unaff_ER14 + -0x32),1);
        dec_set_special((ushort *)(unaff_ER14 + -0x3c),1);
        break;
      }
      unaff_ER4 = (undefined2 *)((short)unaff_ER4 + (ushort)unaff_R6);
      unaff_ER8 = (undefined2 *)((short)unaff_ER8 + (ushort)unaff_R6);
      unaff_R7 = unaff_R7 + -1;
    } while (unaff_R7 != '\0');
  }
LAB_rom_012962:
  if ((unaff_R12 & 1) == 0) {
    uVar5 = 0x9c;
  }
  else {
    uVar5 = 0x88;
  }
  dec_copy((undefined2 *)(CONCAT11(0xff,uVar5) + unaff_ER14), (uintptr_t)0)
                 (undefined2 *)(unaff_ER14 + -0x32));
  if ((unaff_R12 & 1) == 0) {
    uVar5 = 0x92;
  }
  else {
    uVar5 = 0x7e;
  }
  dec_copy((undefined2 *)(CONCAT11(0xff,uVar5) + unaff_ER14), (uintptr_t)0)
                 (undefined2 *)(unaff_ER14 + -0x3c));
  bVar1 = bcd_type((byte *)(unaff_ER14 + -0x32));
  if (bVar1 != 0) {
    if (bVar1 == 1) {
      return 1;
    }
    bVar1 = 0xf;
  }
  bVar2 = bcd_type((byte *)(unaff_ER14 + -0x3c));
  if (bVar2 != 0) {
    bVar2 = 0xf0;
  }
  if (((unaff_R12 & 0xf2) == 0) && (unaff_R13 == '\0')) {
    if ((unaff_R12 & 1) == 0) {
      bVar3 = 0x3c;
      stat_rows = stat_rows | 8;
    }
    else {
      bVar3 = 0x50;
      stat_cols = stat_cols | 8;
    }
    var_store_from_reg(bVar3,(undefined2 *)(unaff_ER14 + -0x32));
  }
  return bVar2 | bVar1;
}

