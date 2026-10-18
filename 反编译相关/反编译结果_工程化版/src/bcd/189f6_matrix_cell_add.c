/*
 * BCD 浮点库 / 189f6_matrix_cell_add.c
 * 地址范围: 0x189F6 - 0x1916C
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 矩阵单元相加（0x1D730/0x1D780 链）
 * @addr 0x189F6
 * @module bcd
 * @proto undefined2 matrix_cell_add(undefined2* a, undefined2* b)
 * @confidence likely
 * @note 矩阵单元相加（0x1D730/0x1D780 链）。
 * @tag matrix
 */
undefined2 matrix_cell_add(undefined2* a, undefined2* b)

{
  byte bVar1;
  undefined2 uVar2;
  undefined2 *unaff_ER4;
  undefined2 *unaff_ER6;
  undefined8 in_QR8;
  undefined8 uVar3;
  short sVar4;
  undefined auStack_c [8];
  
  uVar3 = CONCAT26(auStack_c,(int6)in_QR8);
  uVar2 = compare_bcd_slots(a,b);
  if ((char)uVar2 == '\0') {
    dec_bin_div(unaff_ER6,(undefined2 *)((short)((ulonglong)uVar3 >> 0x30) + -10));
    dec_bin_div((undefined2 *)uVar3,(undefined2 *)((short)((ulonglong)uVar3 >> 0x30) + -0x14));
    dec_copy_rev((undefined2 *)((short)((ulonglong)uVar3 >> 0x30) + -0x3c),(undefined2 *)uVar3);
    bVar1 = special_flag_or();
    sVar4 = (short)((ulonglong)uVar3 >> 0x30);
    if (bVar1 == 0) goto LAB_rom_018a2e;
  }
  sVar4 = (short)((ulonglong)uVar3 >> 0x30);
  set_ops_3_0();
LAB_rom_018a2e:
  dec_copy_rev(unaff_ER4,(undefined2 *)(sVar4 + -0x3c));
  bcd_type((byte *)(sVar4 + -0x3c));
  return;
}

/**
 * @brief 矩阵单元是否为零/空（0x17B4E 检查）
 * @addr 0x18A26
 * @module bcd
 * @proto byte matrix_cell_is_zero(void)
 * @confidence likely
 * @note 矩阵单元是否为零/空（0x17B4E 检查）。
 * @tag matrix
 */
byte matrix_cell_is_zero(void)

{
  byte bVar1;
  undefined2 *unaff_ER4;
  undefined8 in_QR8;
  short sVar2;
  
  sVar2 = (short)((ulonglong)in_QR8 >> 0x30);
  bVar1 = special_flag_or();
  if (bVar1 != 0) {
    set_ops_3_0();
  }
  dec_copy_rev(unaff_ER4,(undefined2 *)(sVar2 + -0x3c));
  bcd_type((byte *)(sVar2 + -0x3c));
  return;
}

/**
 * @brief 矩阵单元除法（0x18B8C 比较后 0x1CF68）
 * @addr 0x18A72
 * @module bcd
 * @proto undefined2 matrix_div(undefined2* a, undefined2* b)
 * @confidence likely
 * @note 矩阵单元除法（0x18B8C 比较后 0x1CF68）。
 * @tag matrix
 */
undefined2 matrix_div(undefined2* a, undefined2* b)

{
  byte bVar1;
  undefined2 uVar2;
  undefined2 *unaff_ER4;
  undefined2 *unaff_ER6;
  short sVar4;
  undefined8 in_QR8;
  undefined8 uVar3;
  undefined auStack_c [8];
  
  uVar3 = CONCAT26(auStack_c,(int6)in_QR8);
  uVar2 = compare_bcd_slots(a,b);
  if ((char)uVar2 == '\0') {
    dec_inc5((undefined2 *)((short)((ulonglong)uVar3 >> 0x30) + -0x14),b);
    dec_inc5((undefined2 *)((short)((ulonglong)uVar3 >> 0x30) + -10),b);
    dec_bin_div(unaff_ER6,(undefined2 *)((short)((ulonglong)uVar3 >> 0x30) + -10));
    dec_bin_div((undefined2 *)uVar3,(undefined2 *)((short)((ulonglong)uVar3 >> 0x30) + -0x14));
    dec_copy_rev((undefined2 *)((short)((ulonglong)uVar3 >> 0x30) + -0x3c),(undefined2 *)uVar3);
    bVar1 = special_flag_or();
    sVar4 = (short)((ulonglong)uVar3 >> 0x30);
    if (bVar1 == 0) goto LAB_rom_018a2e;
  }
  sVar4 = (short)((ulonglong)uVar3 >> 0x30);
  set_ops_3_0();
LAB_rom_018a2e:
  dec_copy_rev(unaff_ER4,(undefined2 *)(sVar4 + -0x3c));
  bcd_type((byte *)(sVar4 + -0x3c));
  return;
}

/**
 * @brief 矩阵单元乘方（0x18B8C 比较后 0x1CF90 链，用于矩阵幂）
 * @addr 0x18A96
 * @module bcd
 * @proto undefined2 matrix_pow(undefined2* a, undefined2* b)
 * @confidence likely
 * @note 矩阵单元乘方（0x18B8C 比较后 0x1CF90 链，用于矩阵幂）。
 * @tag matrix
 */
undefined2 matrix_pow(undefined2* a, undefined2* b)

{
  undefined2 uVar1;
  short sVar2;
  undefined2 *puVar3;
  undefined2 *unaff_ER4;
  undefined2 *unaff_ER6;
  undefined8 in_QR8;
  undefined8 uVar4;
  short sVar5;
  undefined auStack_c [8];
  
  uVar4 = CONCAT26(auStack_c,(int6)in_QR8);
  uVar1 = compare_bcd_slots(a,b);
  if ((char)uVar1 != '\0') {
    set_ops_3_0();
    sVar2 = (short)((ulonglong)uVar4 >> 0x30);
    dec_copy_rev(unaff_ER4,(undefined2 *)(sVar2 + -0x3c));
    bcd_type((byte *)(sVar2 + -0x3c));
    return;
  }
  sVar2 = (short)((ulonglong)uVar4 >> 0x30);
  if (*(char *)(undefined2 *)uVar4 == '\0') {
    if (*(char *)(sVar2 + -0x14) == '\0') {
      dec_add_or_round(unaff_ER6,(undefined2 *)(sVar2 + -10));
      sVar5 = (short)((ulonglong)uVar4 >> 0x30);
      dec_copy((undefined2 *)(sVar5 + -0x3c),unaff_ER6);
      sVar2 = -0x32;
      goto LAB_rom_018b6c;
    }
    if (*(char *)(sVar2 + -10) != '\0') goto LAB_rom_018aba;
    dec_add_or_round(unaff_ER6,(undefined2 *)(sVar2 + -0x14));
  }
  else {
LAB_rom_018aba:
    if ((*(char *)unaff_ER6 != '\0') || (*(char *)(sVar2 + -0x14) != '\0')) {
      dec_copy((undefined2 *)((ulonglong)uVar4 >> 0x20),(undefined2 *)(sVar2 + -0x14));
      puVar3 = (undefined2 *)((ulonglong)uVar4 >> 0x20);
      dec_bin_pow(puVar3,puVar3);
      sVar2 = (short)((ulonglong)uVar4 >> 0x30);
      dec_copy((undefined2 *)(sVar2 + -0x28),(undefined2 *)(sVar2 + -10));
      sVar2 = (short)((ulonglong)uVar4 >> 0x30);
      dec_bin_pow((undefined2 *)(sVar2 + -0x28),(undefined2 *)(sVar2 + -0x28));
      dec_bin_div((undefined2 *)((short)((ulonglong)uVar4 >> 0x30) + -0x28), (uintptr_t)0)
                     (undefined2 *)((ulonglong)uVar4 >> 0x20));
      dec_div_slots_local();
      dec_bin_mul((undefined2 *)((ulonglong)uVar4 >> 0x20), (uintptr_t)0)
                     (undefined2 *)((ulonglong)uVar4 >> 0x10));
      dec_add_or_round((undefined2 *)((ulonglong)uVar4 >> 0x20), (uintptr_t)0)
                     (undefined2 *)((short)((ulonglong)uVar4 >> 0x30) + -0x28));
      dec_copy((undefined2 *)((short)((ulonglong)uVar4 >> 0x30) + -0x32), (uintptr_t)0)
                     (undefined2 *)((ulonglong)uVar4 >> 0x20));
      dec_div_slots_local_b();
      dec_bin_div((undefined2 *)((ulonglong)uVar4 >> 0x10), (uintptr_t)0)
                     (undefined2 *)((ulonglong)uVar4 >> 0x20));
      dec_add_or_round((undefined2 *)((ulonglong)uVar4 >> 0x10), (uintptr_t)0)
                     (undefined2 *)((short)((ulonglong)uVar4 >> 0x30) + -0x28));
      dec_copy((undefined2 *)((short)((ulonglong)uVar4 >> 0x30) + -0x3c), (uintptr_t)0)
                     (undefined2 *)((ulonglong)uVar4 >> 0x10));
      matrix_cell_is_zero();
      return;
    }
    puVar3 = (undefined2 *)(sVar2 + -10);
    dec_add_or_round((undefined2 *)uVar4,puVar3);
    dec_inc5((undefined2 *)uVar4,puVar3);
    unaff_ER6 = (undefined2 *)uVar4;
  }
  sVar5 = (short)((ulonglong)uVar4 >> 0x30);
  dec_copy((undefined2 *)(sVar5 + -0x32),unaff_ER6);
  sVar2 = -0x3c;
LAB_rom_018b6c:
  dec_set_uint_small((ushort *)(sVar2 + sVar5),0);
  matrix_cell_is_zero();
  return;
}

/**
 * @brief 比较两个 BCD 槽
 * @addr 0x18B8C
 * @module bcd
 * @proto byte compare_bcd_slots(undefined2* a, undefined2* b)
 * @confidence likely
 * @note 比较两个 BCD 槽：任一方为特殊值（首字节 >= 0xF0）时按特殊规则返回标志。
 * @tag bcd
 */
byte compare_bcd_slots(undefined2* a, undefined2* b)

{
  byte *pbVar1;
  undefined2 *puVar2;
  short unaff_ER14;
  
  puVar2 = (undefined2 *)(unaff_ER14 + -0x50);
  dec_copy_rev((undefined2 *)(unaff_ER14 + -0x14),b);
  pbVar1 = (byte *)dec_copy_rev(puVar2,a);
  if (*(byte *)puVar2 < 0xf0) {
    *(byte *)puVar2 = *(byte *)puVar2 & 0xbf;
    pbVar1 = (byte *)(unaff_ER14 - 0x14);
    if (*pbVar1 < 0xf0) {
      *pbVar1 = *pbVar1 & 0xbf;
      return (ushort)pbVar1 & 0xff00;
    }
  }
  return CONCAT11((char)((ushort)pbVar1 >> 8),1);
}

/**
 * @brief 两槽首个操作数都不是特殊值时返回 0，否则返回其标志字节
 * @addr 0x18BD8
 * @module bcd
 * @proto byte special_flag_or(void)
 * @confidence likely
 * @note 两槽首个操作数都不是特殊值时返回 0，否则返回其标志字节。
 * @tag bcd
 */
byte special_flag_or(void)

{
  byte bVar1;
  short unaff_ER14;
  
  bVar1 = *(byte *)(unaff_ER14 + -0x3c);
  if ((bVar1 < 0xf0) && (bVar1 = *(byte *)(unaff_ER14 + -0x32), bVar1 < 0xf0)) {
    bVar1 = 0;
  }
  return bVar1;
}

/**
 * @brief 把 +0x3C 槽设为 3、+0x32 槽设为 0
 * @addr 0x18BF2
 * @module bcd
 * @proto void set_ops_3_0(void)
 * @confidence likely
 * @note 把 +0x3C 槽设为 3、+0x32 槽设为 0。
 * @tag bcd
 */
int set_ops_3_0(void)

{
  short unaff_ER14;
  
  dec_set_special((ushort *)(unaff_ER14 + -0x3c),3);
  dec_set_uint_small((ushort *)(unaff_ER14 + -0x32),0);
  return 0;
}

/**
 * @brief 对局部 BCD 槽执行 0x1CF90/0x1CF68 除法序列
 * @addr 0x18C0A
 * @module bcd
 * @proto void dec_div_slots_local(void)
 * @confidence likely
 * @note 对局部 BCD 槽执行 0x1CF90/0x1CF68 除法序列。
 * @tag bcd
 */
int dec_div_slots_local(void)

{
  undefined2 *unaff_ER8;
  undefined2 *unaff_ER10;
  undefined2 *unaff_ER12;
  short unaff_ER14;
  
  dec_copy_rev(unaff_ER10,unaff_ER8);
  dec_bin_pow(unaff_ER12,(undefined2 *)(unaff_ER14 + -0x14));
  dec_bin_pow(unaff_ER10,(undefined2 *)(unaff_ER14 + -10));
  return 0;
}

/**
 * @brief 同 0x18C0A 的对称变体
 * @addr 0x18C2A
 * @module bcd
 * @proto void dec_div_slots_local_b(void)
 * @confidence likely
 * @note 同 0x18C0A 的对称变体。
 * @tag bcd
 */
int dec_div_slots_local_b(void)

{
  undefined2 *unaff_ER8;
  undefined2 *unaff_ER10;
  undefined2 *unaff_ER12;
  short unaff_ER14;
  
  dec_copy_rev(unaff_ER10,unaff_ER8);
  dec_bin_pow(unaff_ER12,(undefined2 *)(unaff_ER14 + -10));
  dec_bin_pow(unaff_ER10,(undefined2 *)(unaff_ER14 + -0x14));
  return 0;
}

/**
 * @brief 求 1.0 与 a 的幂（0x1CF90 乘方族并调用 0x1898E），返回结果标志
 * @addr 0x18C4A
 * @module bcd
 * @proto ushort dec_pow_int_ratio(undefined2* a)
 * @confidence likely
 * @note 求 1.0 与 a 的幂（0x1CF90 乘方族并调用 0x1898E），返回结果标志。
 * @tag bcd
 */
ushort dec_pow_int_ratio(undefined2* a)

{
  undefined uVar1;
  undefined extraout_R1;
  ushort auStack_1a [5];
  ushort auStack_10 [6];
  
  dec_set_uint_small(auStack_1a,1);
  dec_set_uint_small(auStack_10,0);
  uVar1 = matrix_pow(auStack_1a,a);
  dec_copy_rev(a,auStack_1a);
  return CONCAT11(extraout_R1,uVar1);
}

/**
 * @brief a 与副本互相调用 0x1898E（求商/比例）
 * @addr 0x18C8A
 * @module bcd
 * @proto int dec_div_ratio(undefined2* a)
 * @confidence likely
 * @note a 与副本互相调用 0x1898E（求商/比例）。
 * @tag bcd
 */
int dec_div_ratio(undefined2* a)

{
  undefined2 auStack_1a [11];
  
  dec_copy_rev(auStack_1a,a);
  dec_ratio_core(auStack_1a,a);
  dec_ratio_core(a,auStack_1a);
  return 0;
}

/**
 * @brief 对 a 原地调用 0x1898E（求倒数）
 * @addr 0x18CB6
 * @module bcd
 * @proto int dec_inv_inplace(undefined2* a)
 * @confidence likely
 * @note 对 a 原地调用 0x1898E（求倒数）。
 * @tag bcd
 */
int dec_inv_inplace(undefined2* a)

{
  dec_ratio_core(a,a);
  return 0;
}

/**
 * @brief 按 b[5] 与 0x179F4 的结果分派求值
 * @addr 0x18CC0
 * @module bcd
 * @proto ushort dec_func_dispatch(undefined2* a, undefined2* b)
 * @confidence likely
 * @note 按 b[5] 与 0x179F4 的结果分派求值：1 走 0x18C4A，2 走 0x18CB6，其他走 0x18C8A。
 * @tag bcd
 */
ushort dec_func_dispatch(undefined2* a, undefined2* b)

{
  int cVar1;
  undefined2 uVar2;
  
  if (*(char *)(b + 5) == '\0') {
    cVar1 = dec_load_strip_flag(b);
    if (cVar1 == '\x01') {
      uVar2 = dec_pow_int_ratio(a);
    }
    else if (cVar1 == '\x02') {
      uVar2 = dec_inv_inplace(a);
    }
    else if (cVar1 == '\x03') {
      uVar2 = dec_div_ratio(a);
    }
    else {
      uVar2 = vec_compute(a,b);
    }
  }
  else {
    dec_set_special(a,3);
    uVar2 = dec_set_uint_small(a + 5,0);
    uVar2 = CONCAT11((char)((ushort)uVar2 >> 8),3);
  }
  return uVar2;
}

/**
 * @brief 向量/复数运算过程
 * @addr 0x18D16
 * @module bcd
 * @proto undefined2 vec_compute(void)
 * @confidence strong
 * @note 向量/复数运算过程：大量调用 decm_pow/decm_sin/decm_cos 等十进制数学入口。
 * @tag matrix
 */
undefined2 vec_compute(uintptr_t _a3, uintptr_t _a4, int _a1, int _a2)

{
  byte bVar1;
  undefined2 uVar2;
  ushort *puVar3;
  undefined uVar4;
  char cVar5;
  undefined2 uVar6;
  undefined2 *puVar7;
  short sVar8;
  short sVar12;
  ulonglong uVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined auStack_4c [10];
  undefined auStack_42 [10];
  undefined auStack_38 [52];
  char cVar13;
  
  uVar9 = (ulonglong)CONCAT42(CONCAT22(auStack_4c,auStack_42),auStack_38);
  puVar7 = _a2;
  dec_cmp_signed(_a1,_a2);
  dec_cmp_signed(_a1 + 5,puVar7);
  puVar7 = _a2;
  dec_copy_rev((undefined2 *)uVar9,_a2);
  dec_cmp_signed((short)uVar9,puVar7);
  puVar3 = _a1;
  dec_copy_rev((undefined2 *)(uVar9 >> 0x20),_a1);
  uVar2 = dec_cmp((undefined2 *)uVar9,puVar3);
  if ((char)uVar2 == '\x01') {
    dec_set_uint_small(_a1,1);
    puVar3 = _a1 + 5;
LAB_rom_018e1e:
    dec_set_uint_small(puVar3,0);
  }
  else {
    uVar6 = 0x1b6c;
    uVar2 = dec_to_string((short)uVar9,(undefined2 *)0x1b6c);
    if ((char)uVar2 != '\x01') {
      bVar1 = ((undefined2 *)uVar9 == (undefined2 *)0x0) << 6;
      dec_type_flag((undefined2 *)uVar9,uVar6);
      if ((bVar1 >> 6 & 1) != 1) goto LAB_rom_018fb6;
      uVar2 = dec_cmp(_a1,uVar6);
      if ((char)uVar2 == '\x01') {
        uVar2 = dec_cmp((undefined2 *)uVar9,uVar6);
        puVar7 = (undefined2 *)uVar9;
        uVar10 = CONCAT53((int5)(uVar9 >> 0x18),CONCAT12((char)uVar2,puVar7));
        dec_xy_pair_arith(_a1 + 5,puVar7);
        uVar2 = CONCAT11((char)((ushort)puVar7 >> 8),4);
        dec_set_uint_small((ushort *)((short)((ulonglong)uVar10 >> 0x20) + 0x28),4);
        dec_bin_result((ushort *)uVar10,uVar2);
        dec_mul_via_bcd((short)uVar10,(undefined2 *)((short)((ulonglong)uVar10 >> 0x20) + 0x28));
        cVar5 = *(char *)((short)((ulonglong)uVar10 >> 0x20) + 0x28);
        if (cVar5 == '\0') {
          puVar3 = dec_copy_ret(_a1 + 5,_a1);
        }
        else if ((cVar5 == '\x01') || (cVar5 != '\x02')) {
          puVar3 = _a1;
          if ((char)((ulonglong)uVar10 >> 0x10) == '\x02') {
            uVar4 = daa((char)(_a1[9] >> 8) + '\x05');
            _a1[9] = CONCAT11(uVar4,(char)_a1[9]) & 0xfff;
          }
        }
        else {
          puVar3 = _a1;
          dec_copy_ret(_a1 + 5,_a1);
          uVar4 = daa((char)(puVar3[4] >> 8) + '\x05');
          puVar3[4] = CONCAT11(uVar4,(char)puVar3[4]) & 0xfff;
          puVar3 = _a1 + 5;
        }
        goto LAB_rom_018e1e;
      }
      uVar2 = dec_cmp(_a2,uVar6);
      if ((char)uVar2 == '\x02') {
        uVar9 = CONCAT17(1,(int7)uVar9);
      }
      else {
        uVar9 = uVar9 & 0xffffffffffffff;
      }
      sVar8 = (short)(uVar9 >> 0x20);
      puVar7 = (undefined2 *)(sVar8 + 0x28);
      dec_copy_ret((undefined2 *)(sVar8 + 0x14),puVar7);
      dec_bin_result((ushort *)((short)(uVar9 >> 0x20) + 0x28),puVar7);
      uVar6 = 0x3420;
      uVar2 = dec_to_string((short)(uVar9 >> 0x20) + 0x28,(undefined2 *)0x3420);
      if ((char)uVar2 == '\x04') {
        uVar9 = uVar9 & 0xffffffffffff;
        dec_bin_result((ushort *)(uVar9 >> 0x20),uVar6);
        dec_bin_result((ushort *)((short)(uVar9 >> 0x20) + 10),uVar6);
        sVar8 = (short)(uVar9 >> 0x20);
        uVar2 = dec_to_string(sVar8,(undefined2 *)(sVar8 + 10));
        puVar7 = (undefined2 *)(uVar9 >> 0x20);
        if ((char)uVar2 == '\x04') {
          dec_copy_ret(puVar7,puVar7 + -5);
          dec_copy_ret((undefined2 *)(uVar9 >> 0x10), (uintptr_t)0)
                         (undefined2 *)((short)(uVar9 >> 0x20) + -0x14));
        }
        else {
          dec_copy_ret((undefined2 *)(uVar9 >> 0x10),puVar7 + -5);
          puVar7 = (undefined2 *)(uVar9 >> 0x20);
          dec_copy_ret(puVar7,puVar7 + -10);
        }
        sVar8 = (short)(uVar9 >> 0x20);
        dec_copy_ret((undefined2 *)(sVar8 + -0x14),(undefined2 *)(sVar8 + -0x1e));
        sVar12 = (short)(uVar9 >> 0x20);
        sVar8 = sVar12 + -10;
        dec_bin_and_core(sVar12 + -0x1e,sVar8);
        decm_pow((undefined2 *)((short)(uVar9 >> 0x20) + -0x1e),sVar8);
        set_radians_mode((undefined2 *)((short)(uVar9 >> 0x20) + -0x1e),sVar8);
        uVar2 = 0x1b76;
        dec_bin_and_core((short)(uVar9 >> 0x20) + -0x1e,0x1b76);
        decm_cos((short)(uVar9 >> 0x20) + -10,uVar2);
        sVar8 = (short)(uVar9 >> 0x20);
        dec_bin_div_core(sVar8 + -10,sVar8 + -0x1e);
        sVar8 = (short)(uVar9 >> 0x20);
        dec_copy_ret((undefined2 *)(sVar8 + -10),(undefined2 *)(sVar8 + 0x28));
        decm_div(_a1,_a1 + 5);
        dec_copy_ret(_a1,(undefined2 *)((short)(uVar9 >> 0x20) + 0x32));
        dec_ratio_core((undefined2 *)((short)(uVar9 >> 0x20) + 0x28),(undefined2 *)uVar9);
        sVar8 = (short)(uVar9 >> 0x20);
        puVar7 = (undefined2 *)(sVar8 + -10);
        dec_copy_ret((undefined2 *)(sVar8 + 0x32),puVar7);
        decm_sin(sVar8 + 0x28,puVar7);
        uVar2 = CONCAT11((char)((ushort)puVar7 >> 8),5);
        decm_bin_div2(sVar8 + 0x32,uVar2);
        decm_add(sVar8 + -10,CONCAT11((char)((ushort)uVar2 >> 8),5));
        dec_bin_pow((undefined2 *)(sVar8 + 0x32),(undefined2 *)(sVar8 + 0x28));
        dec_bin_pow((undefined2 *)(sVar8 + -10),(undefined2 *)(sVar8 + 0x28));
        dec_copy_ret((undefined2 *)(sVar8 + 0x32),_a1);
        dec_copy_ret((undefined2 *)(sVar8 + -10),_a1 + 5);
      }
      else {
        uVar4 = dec_bin_to_bcd_ctx();
        uVar10 = CONCAT17((char)(uVar9 >> 0x38),CONCAT16(uVar4,(int6)uVar9));
        while( true ) {
          cVar13 = (char)((ulonglong)uVar10 >> 0x38);
          cVar5 = (char)((ulonglong)uVar10 >> 0x30) + -1;
          uVar11 = CONCAT17(cVar13,CONCAT16(cVar5,(int6)uVar10));
          puVar7 = (undefined2 *)((ulonglong)uVar10 >> 0x20);
          if (cVar5 == '\0') break;
          dec_ratio_core(puVar7,_a1);
          uVar10 = uVar11;
        }
        if (cVar13 != '\0') {
          dec_pow_int_ratio(puVar7);
        }
        dec_copy_rev(_a1,(undefined2 *)((ulonglong)uVar11 >> 0x20));
      }
    }
  }
  bVar1 = bcd_type((byte *)_a1);
  if ((bVar1 == 0) && (bVar1 = bcd_type((byte *)_a1), bVar1 == 0)) {
    return 0;
  }
LAB_rom_018fb6:
  dec_set_special(_a1,3);
  dec_set_uint_small(_a1 + 5,0);
  return 3;
}

/**
 * @brief 0x1CD2C 归一化后以常量 0x3416（弧度模式值）调用 0x1C86C
 * @addr 0x18FD2
 * @module bcd
 * @proto void set_radians_mode(undefined2* a, undefined2* b)
 * @confidence likely
 * @note 0x1CD2C 归一化后以常量 0x3416（弧度模式值）调用 0x1C86C。
 * @tag bcd
 */
int set_radians_mode(undefined2* a, undefined2* b)

{
  decm_round_entry(a,b);
  dec_bin_pow_core(a,0x3416);
  return 0;
}

/**
 * @brief 取 p 处的小整数（必要时归一化，失败返回 3）
 * @addr 0x19052
 * @module bcd
 * @proto byte dec_get_small(ushort* p, undefined2 b)
 * @confidence strong
 * @note 取 p 处的小整数（必要时归一化，失败返回 3）。
 * @tag bcd
 */
byte dec_get_small(ushort* p, undefined2 b)

{
  char cVar1;
  byte bVar2;
  undefined2 uVar3;
  
  bVar2 = *(byte *)p;
  uVar3 = CONCAT11((char)((ushort)b >> 8),bVar2);
  if (bVar2 < 0xf0) {
    cVar1 = dec_cmp_ex(p,uVar3);
    if ((cVar1 == '\0') && (cVar1 = dec_cmp_ex(p + 5,uVar3), cVar1 == '\0')) {
      bVar2 = 0;
    }
    else {
      dec_set_special(p,3);
      dec_set_uint_small(p + 5,0);
      bVar2 = 3;
    }
  }
  else {
    bVar2 = bVar2 & 0xf;
  }
  return bVar2;
}

/**
 * @brief 两操作数首字节都 < 10 时调用 0x1D2FE（整数加法），否则 0x1CF7C（混合运…
 * @addr 0x1909A
 * @module bcd
 * @proto int dec_add_or_round(undefined2* a, undefined2* b)
 * @confidence verified
 * @note 两操作数首字节都 < 10 时调用 0x1D2FE（整数加法），否则 0x1CF7C（混合运算）。
 * @tag bcd
 */
int dec_add_or_round(undefined2* a, undefined2* b)

{
  if ((*(byte *)a < 10) && (*(byte *)b < 10)) {
    dec_int_add(a,b);
  }
  else {
    dec_bin_and(a,b);
  }
  return 0;
}

/**
 * @brief 统计表单元格计算（按 0xD0F6 行与 0xD121 标志取值后换算）
 * @addr 0x190B8
 * @module bcd
 * @proto undefined2 table_calc_cell(void)
 * @confidence likely
 * @note 统计表单元格计算（按 0xD0F6 行与 0xD121 标志取值后换算）。
 * @tag app
 */
undefined2 table_calc_cell(void)

{
  undefined2 in_ER0;
  undefined2 uVar1;
  undefined2 *puVar2;
  undefined4 uVar3;
  uint6 uVar4;
  ulonglong uVar5;
  undefined2 auStack_16 [9];
  char cVar6;
  
  uVar3 = 0;
  if (var_scroll != '\0') {
    if (var_list_open == '\0') {
LAB_rom_01910c:
      return (ushort)(byte)((uint)uVar3 >> 0x10) << 8;
    }
    uVar4 = (uint6)CONCAT21(0xd40a,var_scroll) << 0x18;
    while( true ) {
      uVar5 = (ulonglong)uVar4;
      puVar2 = (undefined2 *)(uVar4 >> 0x20);
      dec_copy(auStack_16,puVar2);
      in_ER0 = dec_cell_normalize(auStack_16,puVar2);
      if (((char)in_ER0 == '\0') ||
         (in_ER0 = decm_round10(auStack_16,puVar2), (char)in_ER0 != '\0')) break;
      uVar1 = dec_cmp(auStack_16,puVar2);
      if ((char)uVar1 != '\x01') {
        uVar5 = CONCAT53((int5)(uVar5 >> 0x18),0x10000);
      }
      cVar6 = (char)(uVar5 >> 0x18) + -1;
      uVar3 = CONCAT13(cVar6,(int3)uVar5);
      if (cVar6 == '\0') goto LAB_rom_01910c;
      uVar4 = CONCAT24((short)(uVar5 >> 0x20) + 0x14,uVar3);
    }
  }
  return CONCAT11((char)((ushort)in_ER0 >> 8),3);
}

/**
 * @brief 单元格归一化
 * @addr 0x1911A
 * @module bcd
 * @proto undefined2 dec_cell_normalize(undefined2* a, undefined2* b)
 * @confidence likely
 * @note 单元格归一化：按 0x1D5B6/0x1D668 类型分派。
 * @tag bcd
 */
undefined2 dec_cell_normalize(undefined2* a, undefined2* b)

{
  char cVar1;
  ushort uVar2;
  
  uVar2 = dec_cmp(a,b);
  if ((char)uVar2 == '\x02') {
LAB_rom_019162:
    uVar2 = uVar2 & 0xff00;
  }
  else {
    if ((char)uVar2 != '\x01') {
      uVar2 = dec_type_of((undefined *)a);
      cVar1 = (char)uVar2;
      if (cVar1 != '\0') {
        if (cVar1 == ' ') {
          dec_entry_x(a,b);
        }
        else {
          if (cVar1 != '@') goto LAB_rom_019162;
          dec_bin_init(a,b);
        }
      }
      uVar2 = dec_unary_sin(a,b);
      if (((byte)(SBORROW2(uVar2,-9) ^ (short)(uVar2 + 9) < 0) == 1) ||
         ((byte)(SBORROW2(uVar2,9) ^ (short)(uVar2 - 9) < 0 | uVar2 == 9) == 0))
      goto LAB_rom_019162;
    }
    uVar2 = CONCAT11((char)(uVar2 >> 8),1);
  }
  return uVar2;
}

/**
 * @brief 复数运算包
 * @addr 0x1916C
 * @module bcd
 * @proto int complex_eval(void)
 * @confidence likely
 * @note 复数运算包：用 0x678 字节栈帧保存实部/虚部，调用十进制乘除与 0x1D37E 比较后输出。
 * @tag complex
 */
int complex_eval(uintptr_t _a3, uintptr_t _a4, int _a1, int _a2)

{
  char unaff_1000015a;
  int cVar1;
  byte bVar2;
  undefined2 uVar3;
  char cVar5;
  byte *pbVar4;
  undefined2 uVar6;
  undefined2 *puVar7;
  short sVar8;
  int unaff_R6;
  undefined4 uVar9;
  byte bVar15;
  longlong lVar10;
  longlong lVar11;
  undefined8 uVar12;
  ulonglong uVar13;
  ulonglong uVar14;
  undefined auStack_678 [1594];
  undefined2 uStack_3e;
  undefined2 uStack_3c;
  undefined uStack_3a;
  undefined auStack_38 [52];
  undefined6 uVar16;
  
  uVar12 = CONCAT26(auStack_38,1);
  uStack_3a = 1;
  uStack_3e = 0;
  uStack_3c = _a1;
  if (stat_sel != '\0') {
LAB_rom_019204:
    sVar8 = (short)((ulonglong)uVar12 >> 0x30);
    bVar2 = *(byte *)(sVar8 + -2);
    pbVar4 = (byte *)dec_copy(*(undefined2 **)(sVar8 + -4), (uintptr_t)0)
                                    (undefined2 *)
                                    ((ushort)bVar2 * (CONCAT11(10,bVar2) >> 8) + -0x2396));
    bcd_type(pbVar4);
    return 0;
  }
  lVar10 = (ulonglong)CONCAT22(auStack_38,_a1) << 0x20;
  uVar3 = table_calc_cell();
  lVar11 = lVar10;
  if ((char)uVar3 == '\0') {
    cVar5 = (char)((ushort)uVar3 >> 8);
    eval_to_bcd_slot(_a2);
    uVar3 = dec_cmp((undefined2 *)((ulonglong)lVar10 >> 0x30),_a2);
    lVar11 = lVar10;
    if ((char)uVar3 != '\x01') {
      sVar8 = -0x640;
      lVar11 = (ulonglong)CONCAT42((int)((ulonglong)lVar10 >> 0x20),auStack_678) << 0x10;
      *(undefined **)((short)((ulonglong)lVar10 >> 0x30) + -6) = auStack_678;
      cVar1 = table_add_row((uintptr_t)0);
      if (cVar1 == '\0') {
        stat_sel = '\x01';
        uVar12 = CONCAT71((int7)((ulonglong)lVar11 >> 8),3);
LAB_rom_0191e6:
        if ((char)uVar12 != '\0') {
          eval_to_bcd_slot(sVar8);
          sVar8 = (short)((ulonglong)uVar12 >> 0x30);
          uVar13 = CONCAT44(CONCAT22(sVar8,(short)(CONCAT35((int3)(CONCAT26(sVar8,0xdc0000000000) >>
                                                                  0x28),0x6a00000000) >> 0x20) +
                                           (ushort)(byte)uVar12 * 10),
                            CONCAT22(*(undefined2 *)(sVar8 + -6),(short)uVar12));
          dec_set_uint_small((ushort *)(sVar8 + 10),1);
          if (cVar5 == '\0') {
            uVar6 = 0x1b6c;
            uVar3 = dec_to_string((short)(uVar13 >> 0x30),(undefined2 *)0x1b6c);
            if ((char)uVar3 == '\x01') goto LAB_rom_0192d6;
            unaff_R6 = dec_from_integer((undefined2 *)(uVar13 >> 0x30),uVar6);
            unaff_1000015a = unaff_R6;
            if (unaff_R6 != '\0') {
              dec_bin_xor_core((short)(uVar13 >> 0x30),(undefined2 *)0x1b6c);
            }
          }
          if ((char)uVar13 == '\x02') {
            dec_bin_pow_core((short)(uVar13 >> 0x30),0x1b76);
          }
          if ((char)uVar13 == '\x03') {
            dec_bin_pow_core((short)(uVar13 >> 0x30),0x1b80);
          }
          uVar3 = 0x1b8a;
          dec_bin_and_core((short)(uVar13 >> 0x30),0x1b8a);
          if (cVar5 != '\0') goto LAB_rom_0192d6;
          puVar7 = (undefined2 *)(uVar13 >> 0x30);
          if ((char)uVar13 == '\x02') {
            if (unaff_R6 == '\0') {
              dec_set_uint_small(puVar7 + 5,2);
              uVar13 = uVar13 | 0x80;
            }
            goto LAB_rom_0192d6;
          }
          bVar2 = dec_cmp_status(puVar7,uVar3);
          sVar8 = (short)(uVar13 >> 0x30);
          unaff_1000015a = unaff_R6;
          if (unaff_R6 == '\0') {
            if (bVar2 == 0) goto LAB_rom_0192c4;
            uVar3 = 0x1b6c;
            dec_bin_xor_core(sVar8,(undefined2 *)0x1b6c);
          }
          else {
            if (bVar2 == 0) goto LAB_rom_0192d6;
LAB_rom_0192c4:
            uVar3 = CONCAT11((char)((ushort)uVar3 >> 8),2);
            dec_set_uint_small((ushort *)(sVar8 + 10),2);
            uVar13 = uVar13 | 0x80;
          }
          dec_unary_cos((short)(uVar13 >> 0x30),uVar3);
LAB_rom_0192d6:
          unaff_R6 = unaff_1000015a;
          dec_copy((undefined2 *)(uVar13 >> 0x20),(undefined2 *)0x1b62);
          uVar16 = (undefined6)(uVar13 >> 0x10);
          uVar14 = CONCAT62(uVar16,CONCAT11(10,(char)uVar13));
          if (var_list_open != '\0') {
            uVar14 = CONCAT62(uVar16,CONCAT11(0x14,(char)uVar13));
          }
LAB_rom_0192ea:
          do {
            if (var_list_open == '\0') {
              uVar3 = 0x1b6c;
            }
            else {
              uVar3 = (undefined2)(uVar14 >> 0x10);
            }
            dec_bin_or_core((short)(uVar14 >> 0x30),uVar3);
            while( true ) {
              uVar3 = dec_cmp((undefined2 *)(uVar14 >> 0x30),uVar3);
              if ((char)uVar3 == '\x04') break;
              puVar7 = (undefined2 *)((short)(uVar14 >> 0x10) + -10);
              dec_bin_xor_core((short)(uVar14 >> 0x20),puVar7);
              if (cVar5 != '\0') {
                uVar13 = uVar14;
                if ((char)uVar3 == '\x01') goto LAB_rom_019322;
LAB_rom_01934c:
                sVar8 = (short)(uVar13 >> 0x30) + 10;
                dec_bin_and_core((short)(uVar13 >> 0x20),sVar8);
                uVar12 = CONCAT71((int7)((uVar13 & 0xffffffffffffff03) >> 8),
                                  (char)(uVar13 & 0xffffffffffffff03) + -1);
                unaff_1000015a = unaff_R6;
                goto LAB_rom_0191e6;
              }
              uVar13 = uVar14 & 0xffffffffffffff7f;
              if ((uVar14 & 0x80) == 0) goto LAB_rom_01934c;
              uVar3 = 0x1b6c;
              dec_bin_xor_core((short)(uVar14 >> 0x30),(undefined2 *)0x1b6c);
              uVar14 = uVar13;
            }
            bVar2 = (byte)(uVar14 >> 8);
            bVar15 = (byte)(uVar14 >> 0x10);
            uVar14 = CONCAT44((int)(uVar14 >> 0x20),
                              CONCAT13((char)(uVar14 >> 0x18) -
                                       ((char)(CARRY1(bVar15,bVar2) << 7) >> 7),
                                       CONCAT12(bVar15 + bVar2,(short)uVar14)));
          } while( true );
        }
        goto LAB_rom_019204;
      }
      bVar2 = 1;
      goto LAB_rom_019360;
    }
  }
  bVar2 = 3;
LAB_rom_019360:
  dec_set_special((ushort *)((ulonglong)lVar11 >> 0x20),bVar2);
  return 0;
LAB_rom_019322:
  do {
    bVar2 = (byte)(uVar14 >> 8);
    bVar15 = (byte)(uVar14 >> 0x10);
    uVar9 = CONCAT13((char)(uVar14 >> 0x18) - ((char)(CARRY1(bVar15,bVar2) << 7) >> 7),
                     CONCAT12(bVar15 + bVar2,(short)uVar14));
    uVar14 = CONCAT44((int)(uVar14 >> 0x20),uVar9);
    uVar3 = dec_cmp((undefined2 *)((uint)uVar9 >> 0x10),puVar7);
  } while ((char)uVar3 == '\x01');
  dec_set_uint_small((ushort *)((short)(uVar14 >> 0x30) + 10),2);
  goto LAB_rom_0192ea;
}

