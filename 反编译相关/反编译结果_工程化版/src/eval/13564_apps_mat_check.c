/*
 * 表达式求值 / 13564_apps_mat_check.c
 * 地址范围: 0x13564 - 0x13C02
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 矩阵行列数校验
 * @addr 0x13564
 * @module eval
 * @proto void apps_mat_check(undefined2 arg)
 * @confidence likely
 * @note 矩阵行列数校验。
 * @tag matrix
 */
int apps_mat_check(undefined2 arg)

{
  dec_cmp((undefined2 *)&stat_data,arg);
  return 0;
}

/**
 * @brief 生成列表视图的行数据（清 0xD676/0xD677 计数），供 0xDDE8 逐行绘制
 * @addr 0x136F6
 * @module eval
 * @proto int list_build_rows(void)
 * @confidence likely
 * @note 生成列表视图的行数据（清 0xD676/0xD677 计数），供 0xDDE8 逐行绘制。
 * @tag ui
 */
int list_build_rows(void)

{
  undefined2 *puVar1;
  undefined2 uVar2;
  short sVar3;
  short extraout_ER2;
  undefined8 in_QR0;
  undefined2 *extraout_ER6;
  undefined4 extraout_XR4;
  char *pcVar4;
  char *extraout_ER6_00;
  char *extraout_ER6_01;
  byte bVar5;
  undefined uVar8;
  undefined2 *puVar9;
  undefined4 uVar10;
  char *pcVar11;
  ulonglong uVar7;
  undefined2 local_4c [10];
  undefined2 uStack_38;
  undefined local_2e [38];
  undefined2 uStack_8;
  undefined2 uStack_6;
  ulonglong uVar6;
  
  uStack_6 = (undefined2)((ulonglong)in_QR0 >> 0x30);
  uStack_8 = (undefined2)((ulonglong)in_QR0 >> 0x20);
  uVar10 = CONCAT22(local_2e,local_4c);
  uStack_38 = 0xdafe;
  puVar1 = dec_copy_ret((undefined2 *)0x1b76,local_4c);
  dec_copy_ret(puVar1,(undefined2 *)((short)((uint)uVar10 >> 0x10) + 0x14));
  dec_copy_ret(extraout_ER6,(undefined2 *)((short)uVar10 + 10));
  uVar6 = CONCAT44(uVar10,0x50400a8);
  _DAT_ram_d677 = 0;
  _DAT_ram_d676 = '\0';
  while( true ) {
    while( true ) {
      dec_copy_ret((undefined2 *)((short)(uVar6 >> 0x20) + 10),(undefined2 *)(uVar6 >> 0x30));
      dec_copy_ret((undefined2 *)(uVar6 >> 0x20),(undefined2 *)(extraout_ER2 + 10));
      dec_abs_wrap();
      pcVar11 = (char *)(uVar6 >> 0x30);
      pcVar4 = (char *)((uint)extraout_XR4 >> 0x10);
      puVar9 = (undefined2 *)(uVar6 >> 0x20);
      puVar1 = (undefined2 *)extraout_XR4;
      if (*pcVar11 != '\0') break;
      if (*pcVar4 == '\0') {
        dec_copy_ret(puVar9,puVar1);
        _DAT_ram_d676 = _DAT_ram_d676 + '\x01';
        pcVar4 = extraout_ER6_00;
      }
      *pcVar4 = *pcVar4 + '\x01';
      dec_copy_ret((undefined2 *)((short)(uVar6 >> 0x30) + 10), (uintptr_t)0)
                     (undefined2 *)((short)(uVar6 >> 0x20) + 10));
      if (*(char *)((short)(uVar6 >> 0x30) + 10) == '\0') {
        return 0;
      }
    }
    if (pcVar11[10] == '\0') {
      return 0;
    }
    if (*pcVar4 != '\0') {
      puVar1 = puVar1 + 5;
      pcVar4[1] = '\0';
    }
    bVar5 = (char)uVar6 - 1;
    uVar6 = CONCAT71((int7)(uVar6 >> 8),bVar5);
    if (bVar5 == 0) break;
    if ((char)((bVar5 < 0xa6) << 7) < '\0') {
      while( true ) {
        do {
          uVar7 = uVar6 ^ 0x60000;
          sVar3 = (short)(uVar6 >> 0x30);
          *(char *)(sVar3 + 0x14) = (char)(uVar7 >> 0x10);
          dec_bin_xor_core((short)(uVar6 >> 0x20),(undefined2 *)(sVar3 + 0x14));
          uVar8 = daa((char)(uVar7 >> 0x18) + (char)(uVar7 >> 0x10));
          uVar6 = CONCAT44((int)(uVar7 >> 0x20),CONCAT13(uVar8,(int3)uVar7)) & 0xffffffff0fffffff;
        } while ((char)(uVar6 >> 0x18) == '\x05');
        puVar1 = (undefined2 *)(uVar6 >> 0x20);
        uVar2 = *(undefined2 *)(uint3)(ushort)puVar1[10];
        if (((char)uVar2 != (char)((ushort)*puVar1 >> 8)) ||
           ((char)((ushort)uVar2 >> 8) != (char)*puVar1)) break;
        puVar1[10] = puVar1[10] + 2;
      }
    }
    else {
      *(byte *)puVar9 = (-0x59 - bVar5) * '\x02' + '\x03';
    }
  }
  dec_copy_ret(puVar9 + 5,puVar1);
  *extraout_ER6_01 = *extraout_ER6_01 + '\x01';
  _DAT_ram_d676 = _DAT_ram_d676 + '\x01';
  sVar3 = (short)(uVar6 >> 0x20) + 10;
  dec_to_string(sVar3,(undefined2 *)(CONCAT13(0x34,CONCAT12(0xf8,sVar3)) >> 0x10));
  return 0;
}

/**
 * @brief 32 位混合散列
 * @addr 0x13814
 * @module eval
 * @proto ushort hash_mix32(ushort a, ushort b)
 * @confidence likely
 * @note 32 位混合散列：对 a/b 做乘 0x20 与 0x1384A 异或折叠。
 * @tag util
 */
ushort hash_mix32(ushort a, ushort b)

{
  byte bVar2;
  ushort uVar1;
  
  bVar2 = (byte)(a >> 8);
  uVar1 = CONCAT11((char)(((ushort)b * 0x100 + (ushort)bVar2) * 0x20 >> 8),
                   (char)(((ushort)bVar2 * 0x100 + (a & 0xff)) * 0x20 >> 8));
  xor_words((ushort)(byte)((char)a << 5) << 8);
  uVar1 = xor_words(CONCAT11((byte)(uVar1 >> 9),(char)((uVar1 & 0xff00) + (uVar1 & 0xff) >> 1))
                        );
  xor_words(CONCAT11((char)(((uVar1 & 0xff00) + (uVar1 & 0xff)) * 0x20 >> 8),(char)uVar1 << 5))
  ;
  return;
}

/**
 * @brief 把 a 与 ER8 按 16 位异或并返回
 * @addr 0x1384A
 * @module eval
 * @proto ushort xor_words(ushort a)
 * @confidence verified
 * @note 把 a 与 ER8 按 16 位异或并返回。
 * @tag util
 */
ushort xor_words(ushort a)

{
  undefined2 unaff_ER8;
  
  return CONCAT11((byte)((ushort)a >> 8) ^ (byte)((ushort)unaff_ER8 >> 8),
                  (byte)a ^ (byte)unaff_ER8);
}

/**
 * @brief 把 p[8]=0x99（矩阵单元常量）
 * @addr 0x13910
 * @module eval
 * @proto void set_constant_99(byte* p)
 * @confidence verified
 * @note 把 p[8]=0x99（矩阵单元常量）。
 * @tag matrix
 */
int set_constant_99(byte* p)

{
  *(undefined2 *)(p + 8) = 0x99;
  return 0;
}

/**
 * @brief 空函数（仅 return）
 * @addr 0x13A8A
 * @module eval
 * @proto int nop_rt_2(void)
 * @confidence verified
 * @note 空函数（仅 return）。
 * @tag util
 */
int nop_rt_2(void)

{
  return 0;
}

/**
 * @brief 空函数（直接返回），作为调用轴上的占位
 * @addr 0x13A98
 * @module eval
 * @proto void nop_return(void)
 * @confidence verified
 * @note 空函数（直接返回），作为调用轴上的占位。
 * @tag util
 */
int nop_return(void)

{
  return 0;
}

/**
 * @brief R8/R9 都非 0 时返回 0xD392（变量区基址），否则原样返回 p
 * @addr 0x13AAC
 * @module eval
 * @proto undefined2* select_var_base(undefined2* p)
 * @confidence verified
 * @note R8/R9 都非 0 时返回 0xD392（变量区基址），否则原样返回 p。
 * @tag var
 */
undefined2* select_var_base(undefined2* p)

{
  char unaff_R8;
  char unaff_R9;
  
  if ((unaff_R8 != '\0') && (unaff_R9 != '\0')) {
    p = &stat_data;
  }
  return p;
}

/**
 * @brief 返回 (R12*4 + R13)*10 + ER4（4 列矩阵单元号）
 * @addr 0x13AC4
 * @module eval
 * @proto short matrix_cell_index4(void)
 * @confidence verified
 * @note 返回 (R12*4 + R13)*10 + ER4（4 列矩阵单元号）。
 * @tag matrix
 */
short matrix_cell_index4(void)

{
  short unaff_ER4;
  char unaff_R12;
  char unaff_R13;
  
  return (ushort)(byte)(unaff_R12 * '\x04' + unaff_R13) * 10 + unaff_ER4;
}

/**
 * @brief 返回 p[R6*2] 处的 16 位值
 * @addr 0x13AD4
 * @module eval
 * @proto undefined2 word_at(byte* p)
 * @confidence verified
 * @note 返回 p[R6*2] 处的 16 位值。
 * @tag util
 */
undefined2 word_at(byte* p)

{
  byte unaff_R6;
  
  return *(undefined2 *)(p + (ushort)unaff_R6 * 2);
}

/**
 * @brief 矩阵单元运算核心 A（2KB）
 * @addr 0x13AEA
 * @module eval
 * @proto void matrix_core_a(void)
 * @confidence likely
 * @note 矩阵单元运算核心 A（2KB）。
 * @tag matrix
 */
int matrix_core_a(int _a1, int _a2)

{
  bool bVar1;
  int bVar2;
  undefined2 uVar3;
  undefined2 *puVar4;
  undefined2 unaff_ER8;
  undefined2 *puVar8;
  char cVar9;
  ulonglong uVar5;
  undefined8 uVar6;
  ulonglong uVar7;
  byte bVar10;
  
  uVar5 = (ulonglong)CONCAT24(_a2,CONCAT22(_a1,unaff_ER8));
  bVar2 = 3;
  if (*_a2 >> 4 < 6) {
    bVar1 = *_a1 >> 4 == 9;
    if ((bVar1) || (bVar1 = *_a1 >> 4 == 6, bVar1)) {
      bVar10 = bVar1 << 6;
      bVar2 = 3;
      uVar3 = nop_return();
      select_var_base(uVar3);
      if ((bVar10 >> 6 & 1) != 1) {
        puVar8 = (undefined2 *)(uVar5 >> 0x20);
        uVar6 = CONCAT35((int3)(uVar5 >> 0x28),(uint5)(uint)uVar5);
        do {
          uVar7 = CONCAT26((short)((ulonglong)uVar6 >> 0x30),(uint6)(uint5)uVar6);
          do {
            puVar4 = (undefined2 *)matrix_cell_index4();
            cVar9 = (char)(uVar7 >> 0x30);
            if (cVar9 == '\x01') {
              bVar2 = dec_bin_and(puVar4,puVar8);
              uVar5 = uVar7;
            }
            else if (cVar9 == '\x02') {
              bVar2 = dec_int_add(puVar4,puVar8);
              uVar5 = uVar7;
            }
            else {
              bVar2 = dec_bin_pow(puVar4,puVar8);
              uVar5 = uVar7;
            }
            bVar10 = (bVar2 == 0) << 6;
            if (bVar2 != 0) goto LAB_rom_013a92;
            uVar3 = kbd_wait_key();
            bVar2 = (byte)uVar3;
            if ((bVar10 >> 6 & 1) == 0) goto LAB_rom_013a92;
            bVar2 = (char)(uVar5 >> 0x28) + 1;
            uVar7 = CONCAT26((short)(uVar5 >> 0x30),CONCAT15(bVar2,(int5)uVar5));
          } while ((char)((bVar2 < (byte)(uVar5 >> 8)) << 7) < '\0');
          bVar2 = (char)(uVar5 >> 0x20) + 1;
          uVar6 = CONCAT35((int3)(uVar7 >> 0x28),CONCAT14(bVar2,(int)uVar5));
          if ((byte)uVar5 <= bVar2) {
            bVar2 = nop_rt_2();
            return bVar2;
          }
        } while( true );
      }
    }
  }
LAB_rom_013a92:
  dec_set_special((ushort *)(uVar5 >> 0x10),bVar2);
  return bVar2;
}

/**
 * @brief 矩阵单元运算核心 B（2.2KB，0x13B5E 调用）
 * @addr 0x13AF0
 * @module eval
 * @proto void matrix_core_b(void)
 * @confidence likely
 * @note 矩阵单元运算核心 B（2.2KB，0x13B5E 调用）。
 * @tag matrix
 */
int matrix_core_b(uintptr_t _a3, uintptr_t _a4, int _a1, int _a2)

{
  bool bVar1;
  int bVar2;
  undefined2 uVar3;
  undefined2 *puVar4;
  undefined2 *puVar7;
  char cVar8;
  undefined8 in_QR8;
  undefined8 uVar5;
  undefined8 uVar6;
  byte bVar9;
  
  uVar5 = CONCAT26((short)((ulonglong)in_QR8 >> 0x30),
                   CONCAT24(_a2,CONCAT22(_a1,(short)in_QR8)));
  bVar2 = 3;
  if (*_a2 >> 4 < 6) {
    bVar1 = *_a1 >> 4 == 9;
    if ((bVar1) || (bVar1 = *_a1 >> 4 == 6, bVar1)) {
      bVar9 = bVar1 << 6;
      bVar2 = 3;
      uVar3 = nop_return();
      select_var_base(uVar3);
      if ((bVar9 >> 6 & 1) != 1) {
        puVar7 = (undefined2 *)((ulonglong)uVar5 >> 0x20);
        uVar6 = CONCAT35((int3)((ulonglong)uVar5 >> 0x28),(uint5)(uint)uVar5);
        do {
          uVar6 = CONCAT26((short)((ulonglong)uVar6 >> 0x30),(uint6)(uint5)uVar6);
          do {
            puVar4 = (undefined2 *)matrix_cell_index4();
            cVar8 = (char)((ulonglong)uVar6 >> 0x30);
            if (cVar8 == '\x01') {
              bVar2 = dec_bin_and(puVar4,puVar7);
              uVar5 = uVar6;
            }
            else if (cVar8 == '\x02') {
              bVar2 = dec_int_add(puVar4,puVar7);
              uVar5 = uVar6;
            }
            else {
              bVar2 = dec_bin_pow(puVar4,puVar7);
              uVar5 = uVar6;
            }
            bVar9 = (bVar2 == 0) << 6;
            if (bVar2 != 0) goto LAB_rom_013a92;
            uVar3 = kbd_wait_key();
            bVar2 = (byte)uVar3;
            if ((bVar9 >> 6 & 1) == 0) goto LAB_rom_013a92;
            bVar2 = (char)((ulonglong)uVar5 >> 0x28) + 1;
            uVar6 = CONCAT26((short)((ulonglong)uVar5 >> 0x30),CONCAT15(bVar2,(int5)uVar5));
          } while ((char)((bVar2 < (byte)((ulonglong)uVar5 >> 8)) << 7) < '\0');
          bVar2 = (char)((ulonglong)uVar5 >> 0x20) + 1;
          uVar6 = CONCAT35((int3)((ulonglong)uVar6 >> 0x28),CONCAT14(bVar2,(int)uVar5));
          if ((byte)uVar5 <= bVar2) {
            bVar2 = nop_rt_2();
            return bVar2;
          }
        } while( true );
      }
    }
  }
LAB_rom_013a92:
  dec_set_special((ushort *)((ulonglong)uVar5 >> 0x10),bVar2);
  return bVar2;
}

/**
 * @brief 矩阵单元运算核心 C（2.4KB，0x13BF2/0x13BFA 调用）
 * @addr 0x13B6C
 * @module eval
 * @proto void matrix_core_c(void)
 * @confidence likely
 * @note 矩阵单元运算核心 C（2.4KB，0x13BF2/0x13BFA 调用）。
 * @tag matrix
 */
int matrix_core_c(uintptr_t _a3, uintptr_t _a4, int _a1, int _a2)

{
  bool bVar1;
  char cVar2;
  undefined2 uVar3;
  ushort *puVar4;
  ushort uVar5;
  undefined2 unaff_ER4;
  undefined8 in_QR8;
  undefined8 uVar6;
  undefined8 uVar7;
  byte bVar8;
  
  uVar6 = CONCAT44((int)((ulonglong)in_QR8 >> 0x20),CONCAT22(_a1,(short)in_QR8));
  cVar2 = (char)((ushort)unaff_ER4 >> 8);
  matrix_row_of((uintptr_t)0);
  if (cVar2 == '\t') {
    cVar2 = (char)((ulonglong)uVar6 >> 0x30);
    bVar1 = cVar2 == '\0';
    if (!bVar1) {
      bVar1 = cVar2 == '\x03';
      goto joined_s0x013b86;
    }
  }
  else {
    bVar1 = cVar2 == '\x06';
joined_s0x013b86:
    if (!bVar1) goto LAB_rom_013a92;
  }
  bVar8 = bVar1 << 6;
  uVar3 = nop_return();
  select_var_base(uVar3);
  if ((bVar8 >> 6 & 1) != 1) {
    uVar6 = CONCAT35((int3)((ulonglong)uVar6 >> 0x28),(uint5)(uint)uVar6);
    do {
      uVar6 = CONCAT26((short)((ulonglong)uVar6 >> 0x30),(uint6)(uint5)uVar6);
      do {
        uVar7 = uVar6;
        puVar4 = (ushort *)matrix_cell_index4();
        cVar2 = (char)((ulonglong)uVar7 >> 0x30);
        if (cVar2 == '\x01') {
          uVar3 = dec_bin_result(puVar4,_a2);
          cVar2 = (char)uVar3;
        }
        else if (cVar2 == '\x02') {
          dec_bin_init(puVar4,_a2);
          eval_recip(puVar4);
          cVar2 = '\0';
        }
        else if (cVar2 == '\x03') {
          cVar2 = dec_cmp_ex(puVar4,_a2);
        }
        else {
          uVar6 = CONCAT26((short)((ulonglong)uVar7 >> 0x30),(uint6)(uint)uVar7);
          matrix_transpose_inplace((short)puVar4);
          uVar7 = CONCAT26((short)((ulonglong)uVar6 >> 0x30),
                           CONCAT24((short)((ulonglong)uVar7 >> 0x20),(int)uVar6));
          cVar2 = '\0';
        }
        if (cVar2 != '\0') {
          uVar5 = dec_round_word(cVar2);
          return uVar5;
        }
        bVar8 = (char)((ulonglong)uVar7 >> 0x28) + 1;
        uVar6 = CONCAT26((short)((ulonglong)uVar7 >> 0x30),CONCAT15(bVar8,(int5)uVar7));
      } while ((char)((bVar8 < (byte)((ulonglong)uVar7 >> 8)) << 7) < '\0');
      bVar8 = (char)((ulonglong)uVar7 >> 0x20) + 1;
      uVar6 = CONCAT35((int3)((ulonglong)uVar6 >> 0x28),CONCAT14(bVar8,(int)uVar7));
      if ((byte)uVar7 <= bVar8) {
        uVar5 = nop_rt_2();
        return uVar5;
      }
    } while( true );
  }
LAB_rom_013a92:
  uVar5 = dec_set_special((ushort *)((ulonglong)uVar6 >> 0x10),(byte)_a2);
  return CONCAT11((char)(uVar5 >> 8),(byte)_a2);
}

/**
 * @brief 矩阵单元运算核心 D（3.6KB，0x14C5E 调用）
 * @addr 0x13C02
 * @module eval
 * @proto int matrix_core_d(void)
 * @confidence likely
 * @note 矩阵单元运算核心 D（3.6KB，0x14C5E 调用）。
 * @tag matrix
 */
int matrix_core_d(uintptr_t _a3, uintptr_t _a4, int _a1, int _a2)

{
  undefined2 uVar1;
  char cVar5;
  short sVar2;
  undefined2 *puVar3;
  ushort uVar4;
  undefined uVar6;
  undefined2 unaff_ER4;
  int bVar7;
  undefined2 unaff_ER8;
  undefined2 uVar8;
  undefined *puVar9;
  byte bVar15;
  ulonglong uVar10;
  short sVar16;
  undefined8 uVar13;
  ulonglong uVar14;
  byte bVar17;
  undefined auStack_10 [12];
  ulonglong uVar11;
  undefined8 uVar12;
  
  uVar11 = CONCAT44((int)((ZEXT28(auStack_10) << 0x30) >> 0x20),CONCAT22(_a1,unaff_ER8));
  bVar15 = (byte)((ushort)unaff_ER4 >> 8);
  uVar6 = *_a1;
  bVar7 = *_a2;
  matrix_row_of((uintptr_t)0);
  if ((bVar15 == bVar7 >> 4) && (bVar15 == 6)) {
    uVar1 = nop_return();
    uVar10 = CONCAT26((short)(uVar11 >> 0x30),CONCAT24(uVar1,(int)uVar11));
    uVar1 = word_at((short)_a2);
    cVar5 = (char)(uVar10 >> 8);
    uVar11 = uVar10;
    if ((cVar5 == (char)uVar1) && (cVar5 != '\0')) {
      sVar2 = (short)(uVar10 >> 0x30);
      *(char *)(sVar2 + -1) = (char)uVar10;
      *(char *)(sVar2 + -2) = cVar5;
      cVar5 = (char)((ushort)uVar1 >> 8);
      *(char *)(sVar2 + -3) = cVar5;
      uVar8 = CONCAT11(cVar5,(char)uVar10);
      uVar11 = CONCAT62((int6)(uVar10 >> 0x10),uVar8);
      bVar17 = (cVar5 == '\0') << 6;
      *(undefined2 *)(uVar10 >> 0x20) = uVar8;
      sVar2 = select_var_base(uVar1);
      if ((bVar17 >> 6 & 1) != 1) {
        sVar16 = (short)(uVar11 >> 0x30);
        *(ushort *)(sVar16 + -6) = CONCAT11(bVar15,uVar6);
        *(ushort *)(sVar16 + -8) = (ushort)bVar7 * ((ushort)_a2 & 0xff) + sVar2;
        puVar9 = (undefined *)(sVar16 + -0xb4);
        uVar12 = CONCAT62((int6)(uVar11 >> 0x10),puVar9);
        *(undefined **)(sVar16 + -10) = puVar9;
        memzero_A0(puVar9);
        uVar13 = CONCAT35((int3)((ulonglong)uVar12 >> 0x28),(uint5)(uint)uVar12);
        do {
          uVar10 = CONCAT26((short)((ulonglong)uVar13 >> 0x30),(uint6)(uint5)uVar13);
          do {
            uVar14 = uVar10 & 0xffffffffffff0000;
            puVar3 = (undefined2 *)matrix_cell_index4();
            do {
              uVar11 = uVar14;
              dec_copy_step2();
              pow_ER6_ER2();
              bVar7 = dec_bin_div(puVar3,(undefined2 *)
                                            ((short)((ulonglong)uVar12 >> 0x30) + -0x14));
              bVar15 = (bVar7 == 0) << 6;
              if (bVar7 != 0) {
dec_set_special_ret:
                _a2 = (byte *)(ushort)bVar7;
                goto LAB_rom_013cda;
              }
              uVar1 = kbd_wait_key();
              bVar7 = (byte)uVar1;
              if ((bVar15 >> 6 & 1) == 0) goto dec_set_special_ret;
              bVar15 = (char)(uVar11 >> 8) + 1;
              uVar14 = (ulonglong)CONCAT61((int6)(uVar11 >> 0x10),bVar15) << 8;
              sVar2 = (short)(uVar11 >> 0x30);
            } while ((char)((bVar15 < *(byte *)(sVar2 + -2)) << 7) < '\0');
            bVar15 = (char)(uVar11 >> 0x28) + 1;
            uVar10 = CONCAT26(sVar2,CONCAT15(bVar15,(int5)uVar14));
          } while ((char)((bVar15 < *(byte *)(sVar2 + -3)) << 7) < '\0');
          bVar15 = (char)(uVar11 >> 0x20) + 1;
          uVar13 = CONCAT35((int3)(uVar10 >> 0x28),CONCAT14(bVar15,(int)uVar14));
          if (*(byte *)(sVar2 + -1) <= bVar15) {
            uVar4 = 0;
            memcpy_bytes(*(undefined **)(sVar2 + -6),*(undefined **)(sVar2 + -10),0xa0);
            return uVar4 & 0xff00;
          }
        } while( true );
      }
    }
  }
LAB_rom_013cda:
  bVar15 = (byte)_a2;
  uVar4 = dec_set_special((ushort *)(uVar11 >> 0x10),bVar15);
  return CONCAT11((char)(uVar4 >> 8),bVar15);
}

