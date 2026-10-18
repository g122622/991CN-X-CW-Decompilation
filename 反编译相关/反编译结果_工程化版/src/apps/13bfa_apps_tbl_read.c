/*
 * 应用模式 / 13bfa_apps_tbl_read.c
 * 地址范围: 0x13BFA - 0x13CF2
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief TABLE 模式表格读取
 * @addr 0x13BFA
 * @module apps
 * @proto int apps_tbl_read(void)
 * @confidence likely
 * @note TABLE 模式表格读取。
 * @tag mode
 */
int apps_tbl_read(uintptr_t _a3, uintptr_t _a4, int _a1, int _a2)

{
  matrix_core_c(_a1,_a2);
  return 0;
}

/**
 * @brief 表格/矩阵按行计算（十进制累加）
 * @addr 0x13CF2
 * @module apps
 * @proto void apps_row_calc(void)
 * @confidence likely
 * @note 表格/矩阵按行计算（十进制累加）。
 * @tag mode
 */
int apps_row_calc(uintptr_t _a3, uintptr_t _a4, int _a1, int _a2)

{
  undefined2 *puVar1;
  byte extraout_R1;
  undefined extraout_R1_00;
  ushort uVar2;
  undefined extraout_R1_01;
  undefined extraout_R1_02;
  undefined2 *puVar3;
  undefined extraout_R1_03;
  undefined extraout_R1_04;
  undefined extraout_R1_05;
  undefined extraout_R1_06;
  undefined extraout_R1_07;
  byte extraout_R1_08;
  undefined extraout_R1_09;
  undefined extraout_R1_10;
  undefined extraout_R1_11;
  undefined extraout_R1_12;
  undefined2 uVar4;
  undefined extraout_R1_13;
  undefined extraout_R1_14;
  undefined extraout_R1_15;
  undefined extraout_R1_16;
  undefined uVar5;
  byte bVar6;
  undefined2 unaff_ER4;
  ushort *puVar7;
  char cVar8;
  char cVar13;
  int bVar16;
  undefined8 in_QR8;
  undefined8 uVar9;
  ulonglong uVar10;
  uint uVar14;
  byte bVar17;
  undefined4 uVar15;
  undefined8 uVar11;
  short sVar18;
  longlong lVar12;
  
  *(char *)((short)((ulonglong)in_QR8 >> 0x30) + -1) = (char)unaff_ER4;
  uVar9 = CONCAT44((int)((ulonglong)in_QR8 >> 0x20),CONCAT22(_a1,(short)in_QR8));
  bVar6 = *_a1;
  matrix_row_of((uintptr_t)0);
  uVar11 = uVar9;
  if ((char)((ushort)unaff_ER4 >> 8) == '\x06') {
    puVar1 = (undefined2 *)nop_return();
    sVar18 = (short)((ulonglong)uVar9 >> 0x30);
    uVar11 = CONCAT26(sVar18,CONCAT24(puVar1,(int)uVar9));
    uVar5 = (undefined)((ushort)_a2 >> 8);
    _a2 = (undefined2 *)CONCAT11(uVar5,9);
    cVar8 = (char)uVar9;
    if ((cVar8 == '\0') || (cVar13 = (char)((ulonglong)uVar9 >> 8), cVar13 == '\0'))
    goto LAB_rom_013cda;
    if (*(byte *)(sVar18 + -1) == 0) {
      *puVar1 = CONCAT11(cVar8,cVar13);
      uVar10 = 0;
LAB_rom_013d2c:
      do {
        uVar14 = (uint)(uVar10 >> 0x20);
        matrix_cell_index4();
        copy_from_ER2_to_ER8();
        lVar12 = (ulonglong)uVar14 << 0x20;
        dec_copy_step2();
        copy_to_slot3((uintptr_t)0);
        bVar16 = (char)((ulonglong)lVar12 >> 0x28) + 1;
        uVar10 = (ulonglong)CONCAT15(bVar16,(int5)lVar12);
        bVar6 = (byte)((ulonglong)lVar12 >> 0x20);
        if (bVar16 < bVar6) {
          if ((char)((bVar16 < 4) << 7) < '\0') goto LAB_rom_013d2c;
        }
        bVar6 = bVar6 + 1;
        uVar10 = (ulonglong)bVar6 << 0x20;
        if (3 < bVar6) {
          return (ushort)extraout_R1 << 8;
        }
      } while( true );
    }
    if (2 < *(byte *)(sVar18 + -1)) {
      bVar6 = matrix_ones(CONCAT11(uVar5,0xa0));
      return CONCAT11(extraout_R1_00,bVar6);
    }
    _a2 = (undefined2 *)CONCAT11(uVar5,9);
    if (cVar8 != cVar13) goto LAB_rom_013cda;
    *(undefined **)(sVar18 + -4) = (undefined *)(sVar18 + -0xbe);
    memzero_A0((undefined *)(sVar18 + -0xbe));
    uVar11 = CONCAT35((int3)((ulonglong)uVar11 >> 0x28),(uint5)(uint)uVar11);
    do {
      uVar11 = CONCAT26((short)((ulonglong)uVar11 >> 0x30),(uint6)(uint5)uVar11);
      do {
        uVar9 = uVar11;
        matrix_cell_index4();
        puVar1 = (undefined2 *)(*(short *)((short)((ulonglong)uVar9 >> 0x30) + -4) + (short)_a2)
        ;
        _a2 = (undefined2 *)((short)_a2 + (short)(&stat_data + (ushort)bVar6 * 0xa0));
        dec_copy(puVar1,_a2);
        dec_bin_init(puVar1,_a2);
        bVar16 = (puVar1 == (undefined2 *)0x0) << 6;
        eval_recip(puVar1);
        uVar2 = kbd_wait_key();
        if ((bVar16 >> 6 & 1) == 0) {
          _a2 = (undefined2 *)(uVar2 & 0xff);
          uVar11 = uVar9;
          goto LAB_rom_013cda;
        }
        sVar18 = (short)((ulonglong)uVar9 >> 0x30);
        bVar17 = (char)((ulonglong)uVar9 >> 0x28) + 1;
        uVar11 = CONCAT26(sVar18,CONCAT15(bVar17,(int5)uVar9));
        bVar16 = (byte)uVar9;
      } while ((char)((bVar17 < bVar16) << 7) < '\0');
      bVar17 = (char)((ulonglong)uVar9 >> 0x20) + 1;
      uVar11 = CONCAT35((int3)((ulonglong)uVar11 >> 0x28),CONCAT14(bVar17,(uint)uVar9));
    } while ((char)((bVar17 < bVar16) << 7) < '\0');
    *(undefined **)(sVar18 + -6) = &stat_data + (ushort)bVar6 * 0xa0;
    puVar7 = *(ushort **)(sVar18 + -4);
    puVar1 = (undefined2 *)(sVar18 + -0x28);
    uVar11 = CONCAT26(sVar18,(uint6)(uint)uVar9);
    if (bVar16 == 2) {
      uVar15 = (undefined4)((ulonglong)uVar11 >> 0x20);
      puVar1 = (undefined2 *)(sVar18 + -0x32);
      bVar16 = dec_percent_chain();
      uVar5 = (undefined)((ushort)_a2 >> 8);
      uVar11 = CONCAT62(CONCAT42(uVar15,(short)((ulonglong)uVar9 >> 0x10)),(short)uVar9);
      bVar6 = (bVar16 == 0) << 6;
      if (bVar16 != 0) {
        bVar6 = dec_set_special_ret(bVar16);
        return CONCAT11(extraout_R1_01,bVar6);
      }
      uVar4 = kbd_wait_key();
      if ((bVar6 >> 6 & 1) != 1) {
        bVar6 = dec_set_special_ret((byte)uVar4);
        return CONCAT11(extraout_R1_02,bVar6);
      }
    }
    else if (bVar16 == 3) {
      copy_ER6_from_ER4();
      pow_ER6_ER2();
      puVar7 = puVar7 + 0x32;
      pow_ER6_ER2();
      uVar15 = (undefined4)((ulonglong)uVar11 >> 0x20);
      puVar3 = (undefined2 *)dec_shift_ratio();
      dec_bin_div(puVar3,puVar7);
      bVar6 = 0;
      puVar3 = (undefined2 *)dec_shift_ratio();
      uVar11 = CONCAT62(CONCAT42(uVar15,(short)((ulonglong)uVar11 >> 0x10)),(short)uVar11);
      dec_bin_div(puVar3,puVar7);
      uVar4 = kbd_wait_key();
      if ((bVar6 >> 6 & 1) != 1) {
        bVar6 = dec_set_special_ret((byte)uVar4);
        return CONCAT11(extraout_R1_03,bVar6);
      }
      uVar15 = (undefined4)((ulonglong)uVar11 >> 0x20);
      puVar3 = (undefined2 *)dec_shift_ratio();
      dec_bin_mul(puVar3,puVar7);
      puVar3 = (undefined2 *)dec_shift_ratio();
      dec_bin_mul(puVar3,puVar7);
      puVar3 = (undefined2 *)dec_shift_ratio();
      uVar11 = CONCAT62(CONCAT42(uVar15,(short)((ulonglong)uVar11 >> 0x10)),(short)uVar11);
      bVar16 = dec_bin_mul(puVar3,puVar7);
      uVar5 = (undefined)((ushort)puVar7 >> 8);
      bVar6 = (bVar16 == 0) << 6;
      if (bVar16 != 0) {
        bVar6 = dec_set_special_ret(bVar16);
        return CONCAT11(extraout_R1_04,bVar6);
      }
      uVar4 = kbd_wait_key();
      if ((bVar6 >> 6 & 1) != 1) {
        bVar6 = dec_set_special_ret((byte)uVar4);
        return CONCAT11(extraout_R1_05,bVar6);
      }
    }
    else {
      if (3 < bVar16) {
        if (*(char *)(sVar18 + -1) != '\x01') {
          uVar2 = menu_numeric_from_table(4);
          return uVar2;
        }
        bVar16 = table_view_main(puVar7);
        bVar6 = (bVar16 == 0) << 6;
        if (bVar16 != 0) {
          bVar6 = dec_set_special_ret(bVar16);
          return CONCAT11(extraout_R1_06,bVar6);
        }
        uVar4 = kbd_wait_key();
        if ((bVar6 >> 6 & 1) != 1) {
          bVar6 = dec_set_special_ret((byte)uVar4);
          return CONCAT11(extraout_R1_07,bVar6);
        }
        goto LAB_rom_013ec0;
      }
      copy_ER6_from_ER4();
      uVar5 = (undefined)((ushort)_a2 >> 8);
    }
    if (*(char *)((short)((ulonglong)uVar11 >> 0x30) + -1) == '\x01') {
LAB_rom_013ec0:
      dec_copy_b((uintptr_t)0);
      return (ushort)extraout_R1_08 << 8;
    }
    _a2 = (undefined2 *)CONCAT11(uVar5,3);
    bVar6 = (puVar1 == (undefined2 *)0x0) << 6;
    int_to_dec(puVar1,_a2);
    if ((bVar6 >> 6 & 1) == 0) {
      sVar18 = (short)((ulonglong)uVar11 >> 0x30);
      *(undefined2 **)(sVar18 + -8) = puVar1;
      puVar7 = *(ushort **)(sVar18 + -6);
      cVar8 = (char)uVar11;
      if (cVar8 == '\x02') {
        dec_copy_step2();
        dec_pair_copy();
        dec_pair_copy();
        bVar6 = (puVar7 == (ushort *)0xffce) << 6;
        copy_slot4_to_slot3((uintptr_t)0);
        uVar4 = kbd_wait_key();
        if ((bVar6 >> 6 & 1) != 1) {
          bVar6 = dec_set_special_ret((byte)uVar4);
          return CONCAT11(extraout_R1_11,bVar6);
        }
        bVar6 = dec_convert_check();
        return CONCAT11(extraout_R1_12,bVar6);
      }
      if (cVar8 != '\x03') {
        if (cVar8 != '\x04') {
          dec_set_uint_small(puVar7,1);
          bVar6 = dec_convert_check();
          return CONCAT11(extraout_R1_09,bVar6);
        }
        uVar2 = menu_numeric_from_table((byte)_a2);
        if ((byte)uVar2 == 0) {
          return uVar2 & 0xff00;
        }
        bVar6 = dec_set_special_ret((byte)uVar2);
        return CONCAT11(extraout_R1_10,bVar6);
      }
      uVar15 = (undefined4)((ulonglong)uVar11 >> 0x20);
      dec_percent_chain();
      dec_percent_chain();
      bVar6 = 0;
      dec_percent_chain();
      lVar12 = (ulonglong)CONCAT42(uVar15,(short)((ulonglong)uVar11 >> 0x10)) << 0x10;
      uVar4 = kbd_wait_key();
      if ((bVar6 >> 6 & 1) != 1) {
        bVar6 = dec_set_special_ret((byte)uVar4);
        return CONCAT11(extraout_R1_13,bVar6);
      }
      uVar15 = (undefined4)((ulonglong)lVar12 >> 0x20);
      dec_percent_chain();
      dec_percent_chain();
      bVar6 = 0;
      dec_percent_chain();
      lVar12 = (ulonglong)CONCAT42(uVar15,(short)((ulonglong)lVar12 >> 0x10)) << 0x10;
      uVar4 = kbd_wait_key();
      if ((bVar6 >> 6 & 1) != 1) {
        bVar6 = dec_set_special_ret((byte)uVar4);
        return CONCAT11(extraout_R1_14,bVar6);
      }
      uVar15 = (undefined4)((ulonglong)lVar12 >> 0x20);
      dec_percent_chain();
      dec_percent_chain();
      bVar6 = 0;
      dec_percent_chain();
      lVar12 = (ulonglong)CONCAT42(uVar15,(short)((ulonglong)lVar12 >> 0x10)) << 0x10;
      uVar4 = kbd_wait_key();
      if ((bVar6 >> 6 & 1) != 1) {
        bVar6 = dec_set_special_ret((byte)uVar4);
        return CONCAT11(extraout_R1_15,bVar6);
      }
      uVar2 = call_13af0((byte *)((ulonglong)lVar12 >> 0x10), (uintptr_t)0)
                             *(byte **)((short)((ulonglong)lVar12 >> 0x30) + -8));
      if ((byte)uVar2 == 0) {
        return uVar2 & 0xff00;
      }
      bVar6 = dec_set_special_ret((byte)uVar2);
      return CONCAT11(extraout_R1_16,bVar6);
    }
  }
LAB_rom_013cda:
  uVar2 = dec_set_special((ushort *)((ulonglong)uVar11 >> 0x10),(byte)_a2);
  return CONCAT11((char)(uVar2 >> 8),(byte)_a2);
}

