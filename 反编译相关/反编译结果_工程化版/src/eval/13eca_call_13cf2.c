/*
 * 表达式求值 / 13eca_call_13cf2.c
 * 地址范围: 0x13ECA - 0x146B8
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 以原参数调用 0x13CF2（矩阵运算）
 * @addr 0x13ECA
 * @module eval
 * @proto int call_13cf2(undefined2 er0, undefined2 er2)
 * @confidence likely
 * @note 以原参数调用 0x13CF2（矩阵运算）。
 * @tag matrix
 */
int call_13cf2(undefined2 er0, undefined2 er2)

{
  apps_row_calc(er0,er2);
  return 0;
}

/**
 * @brief 矩阵单元打印/求值
 * @addr 0x1406A
 * @module eval
 * @proto undefined2 matrix_print_elem(byte* expr, byte* dst)
 * @confidence strong
 * @note 矩阵单元打印/求值：单元类型 9（矩阵）时按行或元素循环调用 0x1CF68（除法）与 0x14196（乘加），得到 3 个
 *       10 字节单元写回 dst。
 * @tag matrix
 */
undefined2 matrix_print_elem(byte* expr, byte* dst)

{
  bool bVar1;
  ulonglong uVar2;
  byte bVar3;
  ushort uVar4;
  undefined2 uVar5;
  short sVar6;
  undefined extraout_R1;
  undefined extraout_R1_00;
  undefined extraout_R1_01;
  undefined extraout_R1_02;
  byte extraout_R1_03;
  undefined2 unaff_ER4;
  undefined2 *puVar7;
  int bVar8;
  undefined2 unaff_ER8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined auStack_10 [12];
  
  uVar9 = CONCAT44((int)((ZEXT28(auStack_10) << 0x30) >> 0x20),CONCAT22(expr,unaff_ER8));
  bVar3 = (byte)((ushort)unaff_ER4 >> 8);
  puVar7 = (undefined2 *)CONCAT11(bVar3,*expr);
  bVar8 = *dst;
  matrix_row_of((uintptr_t)0);
  if ((bVar3 == bVar8 >> 4) && (bVar3 == 9)) {
    uVar5 = nop_return();
    uVar9 = CONCAT26((short)((ulonglong)uVar9 >> 0x30),CONCAT24(uVar5,(int)uVar9));
    sVar6 = word_at((short)dst);
    bVar1 = sVar6 == (short)uVar9;
    bVar3 = bVar1 << 6;
    if ((bVar1) && (select_var_base(sVar6), (bVar3 >> 6 & 1) == 0)) {
      sVar6 = (short)((ulonglong)uVar9 >> 0x30);
      bVar3 = (byte)((ulonglong)uVar9 >> 8);
      if (*(char *)(sVar6 + -1) != '\x01') {
        if (*(char *)(sVar6 + -1) == '\x02') {
          uVar4 = matrix_elem_add();
          return uVar4;
        }
        uVar10 = CONCAT26(sVar6,CONCAT15(bVar3,(int5)uVar9));
        uVar10 = CONCAT35((int3)((ulonglong)uVar10 >> 0x28),
                          (uint5)(uint)CONCAT62((int6)((ulonglong)uVar10 >> 0x10),sVar6 + -10));
        dec_set_uint_small((ushort *)((ulonglong)uVar9 >> 0x10),0);
        do {
          copy_ER8_from_ER4();
          pow_ER8_ER2();
          uVar4 = dec_bin_div((undefined2 *)((ulonglong)uVar10 >> 0x10),(undefined2 *)uVar10);
          if ((byte)uVar4 != 0) {
            bVar3 = dec_set_special_ret((byte)uVar4);
            return CONCAT11(extraout_R1,bVar3);
          }
          bVar3 = (char)((ulonglong)uVar10 >> 0x20) + 1;
          uVar2 = (ulonglong)uVar10 >> 0x28;
          uVar10 = CONCAT35((int3)((ulonglong)uVar10 >> 0x28),CONCAT14(bVar3,(int)uVar10));
        } while ((char)((bVar3 < (byte)uVar2) << 7) < '\0');
        return uVar4 & 0xff00;
      }
      if ((char)((bVar3 < 4) << 7) < '\0') {
        memzero((undefined *)(sVar6 + -0x28),0x14);
        *(undefined2 *)((ulonglong)uVar9 >> 0x20) = 0x301;
        sVar6 = (short)((ulonglong)uVar9 >> 0x30);
        if ((char)((ulonglong)uVar9 >> 8) == '\x03') {
          bVar3 = 0;
          bVar8 = matrix_cell_mul_add(-0x28);
          if ((bVar3 >> 6 & 1) != 1) {
            bVar3 = dec_set_special_ret(bVar8);
            return CONCAT11(extraout_R1_00,bVar3);
          }
          bVar3 = 0x40;
          bVar8 = matrix_cell_mul_add(-0x1e);
          if ((bVar3 >> 6 & 1) != 1) {
            bVar3 = dec_set_special_ret(bVar8);
            return CONCAT11(extraout_R1_01,bVar3);
          }
        }
        bVar3 = 0;
        bVar8 = matrix_cell_mul_add(-0x14);
        if ((bVar3 >> 6 & 1) == 1) {
          dec_copy(puVar7,(undefined2 *)(sVar6 + -0x28));
          dec_copy(puVar7 + 5,(undefined2 *)(sVar6 + -0x1e));
          dec_copy(puVar7 + 10,(undefined2 *)(sVar6 + -0x14));
          return (ushort)extraout_R1_03 << 8;
        }
        bVar3 = dec_set_special_ret(bVar8);
        return CONCAT11(extraout_R1_02,bVar3);
      }
    }
  }
  uVar4 = dec_set_special((ushort *)((ulonglong)uVar9 >> 0x10),(byte)dst);
  return CONCAT11((char)(uVar4 >> 8),(byte)dst);
}

/**
 * @brief 矩阵单元累加
 * @addr 0x14196
 * @module eval
 * @proto int matrix_cell_mul_add(short off)
 * @confidence likely
 * @note 矩阵单元累加：载入两单元（0x1DA02）、乘（0x1CF90）后加（0x1CF54）。
 * @tag matrix
 */
int matrix_cell_mul_add(short off)

{
  undefined2 *puVar1;
  short unaff_ER4;
  short unaff_ER6;
  undefined2 *unaff_ER8;
  short unaff_ER10;
  short unaff_ER12;
  short unaff_ER14;
  
  puVar1 = (undefined2 *)(off + unaff_ER14);
  dec_copy(puVar1,(undefined2 *)(unaff_ER4 + unaff_ER10));
  dec_bin_pow(puVar1,(undefined2 *)(unaff_ER6 + unaff_ER12));
  copy_from_ER2_to_ER8();
  pow_ER8_ER2();
  dec_bin_mul(puVar1,unaff_ER8);
  return 0;
}

/**
 * @brief 把两个矩阵单元复制到局部后调用 0x1431C 做类型检查与 0x1406A 求值
 * @addr 0x141E0
 * @module eval
 * @proto undefined2 matrix_elem_add(void)
 * @confidence likely
 * @note 把两个矩阵单元复制到局部后调用 0x1431C 做类型检查与 0x1406A 求值。
 * @tag matrix
 */
undefined2 matrix_elem_add(void)

{
  undefined2 uVar1;
  undefined2 *puVar2;
  undefined2 *puVar3;
  undefined8 in_QR8;
  short sVar4;
  
  sVar4 = (short)((ulonglong)in_QR8 >> 0x30);
  puVar2 = (undefined2 *)((ulonglong)in_QR8 >> 0x10);
  uVar1 = dec_copy((undefined2 *)(sVar4 + -0x1e),puVar2);
  matrix_cell_check(uVar1,(byte)puVar2);
  puVar2 = *(undefined2 **)((short)((ulonglong)in_QR8 >> 0x30) + -4);
  uVar1 = dec_copy((undefined2 *)(sVar4 + -0x14),puVar2);
  matrix_cell_check(uVar1,(byte)puVar2);
  matrix_print_elem((undefined *)((ulonglong)in_QR8 >> 0x10), (uintptr_t)0)
                 *(byte **)((short)((ulonglong)in_QR8 >> 0x30) + -4));
  puVar3 = (undefined2 *)((ulonglong)in_QR8 >> 0x10);
  dec_bin_and(puVar3,(undefined2 *)(sVar4 + -0x14));
  puVar2 = (undefined2 *)(sVar4 + -0x1e);
  dec_bin_and(puVar3,puVar2);
  dec_cmp_ex(puVar3,puVar2);
  decm_bin_pow1(puVar3,(ushort)puVar2 & 0xff00);
  return;
}

/**
 * @brief 把 p 处 0xA0（160）字节清零（工作表）
 * @addr 0x14308
 * @module eval
 * @proto void memzero_A0(undefined* p)
 * @confidence verified
 * @note 把 p 处 0xA0（160）字节清零（工作表）。
 * @tag util
 */
int memzero_A0(undefined* p)

{
  memzero(p,0xa0);
  return 0;
}

/**
 * @brief R5 = t[0]>>4（矩阵/单元类型高位），R2 = 3
 * @addr 0x14314
 * @module eval
 * @proto undefined2 matrix_row_of(byte* t)
 * @confidence verified
 * @note R5 = t[0]>>4（矩阵/单元类型高位），R2 = 3。
 * @tag matrix
 */
undefined2 matrix_row_of(byte* _a1)

{
  return;
}

/**
 * @brief 矩阵单元类型检查（0x14314 得类型 9），对两个单元分别校验后再调用 0x1406A
 * @addr 0x1431C
 * @module eval
 * @proto byte matrix_cell_check(undefined2 a, byte b)
 * @confidence likely
 * @note 矩阵单元类型检查（0x14314 得类型 9），对两个单元分别校验后再调用 0x1406A。
 * @tag matrix
 */
byte matrix_cell_check(undefined2 a, byte b)

{
  bool bVar1;
  byte bVar2;
  undefined2 uVar3;
  undefined2 unaff_ER4;
  undefined2 unaff_ER8;
  undefined8 uVar4;
  short sVar7;
  longlong lVar5;
  undefined4 uVar6;
  undefined auStack_10 [12];
  
  uVar4 = CONCAT44((int)((ZEXT28(auStack_10) << 0x30) >> 0x20),CONCAT22(a,unaff_ER8));
  matrix_row_of((uintptr_t)0);
  bVar1 = (char)((ushort)unaff_ER4 >> 8) == '\t';
  bVar2 = bVar1 << 6;
  if (bVar1) {
    uVar3 = nop_return();
    select_var_base(uVar3);
    if ((bVar2 >> 6 & 1) == 0) {
      sVar7 = (short)((ulonglong)uVar4 >> 0x30);
      lVar5 = CONCAT35(CONCAT21(sVar7,(char)((ulonglong)uVar4 >> 8)),0x100000000);
      copy_ER6_from_ER4();
      do {
        uVar6 = (undefined4)((ulonglong)lVar5 >> 0x20);
        copy_ER8_from_ER4();
        bVar2 = dec_to_polar((ushort *)(sVar7 + -0x14));
        if (bVar2 != 0) {
          bVar2 = dec_set_special_ret(bVar2);
          return bVar2;
        }
        bVar2 = (char)uVar6 + 1;
        lVar5 = (ulonglong)CONCAT31((int3)((uint)uVar6 >> 8),bVar2) << 0x20;
      } while ((char)((bVar2 < (byte)((uint)uVar6 >> 8)) << 7) < '\0');
      dec_copy_b((uintptr_t)0);
      return 0;
    }
  }
  dec_set_special((ushort *)((ulonglong)uVar4 >> 0x10),b);
  return b;
}

/**
 * @brief 矩阵运算入口（R4=4）
 * @addr 0x143CC
 * @module eval
 * @proto undefined2 matrix_op(byte* expr, undefined2* dst)
 * @confidence strong
 * @note 矩阵运算入口（R4=4）：按 expr 首字节类型分派到 0x13CF2 的共享矩阵内核。
 * @tag matrix
 */
undefined2 matrix_op(byte* expr, undefined2* dst)

{
  apps_row_calc(expr,dst);
  return;
}

/**
 * @brief 把矩阵填充为单位阵
 * @addr 0x143DC
 * @module eval
 * @proto byte matrix_ones(ushort size)
 * @confidence strong
 * @note 把矩阵填充为单位阵：按行列循环 0x1D780（置位）与 0x10C4E（1=x/x），依次经
 *       0x144BC/0x14534/0x145D8/0x146B8/0x14A64 归一化。
 * @tag matrix
 */
byte matrix_ones(ushort size)

{
  undefined2 *puVar1;
  ushort uVar2;
  undefined *unaff_ER4;
  byte bVar5;
  undefined8 in_QR8;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined2 uVar6;
  
  *(undefined **)((short)((ulonglong)in_QR8 >> 0x30) + -0xc) = unaff_ER4;
  uVar2 = size & 0xff00;
  memmove_blocks(unaff_ER4,'\0');
  uVar3 = CONCAT35((int3)((ulonglong)in_QR8 >> 0x28),(uint5)(uint)in_QR8);
  do {
    uVar3 = CONCAT26((short)((ulonglong)uVar3 >> 0x30),(uint6)(uint5)uVar3);
    do {
      uVar4 = uVar3;
      puVar1 = (undefined2 *)matrix_cell_index();
      dec_bin_init(puVar1,uVar2);
      eval_recip(puVar1);
      uVar6 = (undefined2)((ulonglong)uVar4 >> 0x30);
      bVar5 = (char)((ulonglong)uVar4 >> 0x28) + 1;
      uVar3 = CONCAT26(uVar6,CONCAT15(bVar5,(int5)uVar4));
    } while ((char)((bVar5 < (byte)((ulonglong)uVar4 >> 8)) << 7) < '\0');
    bVar5 = (char)((ulonglong)uVar4 >> 0x20) + 1;
    uVar3 = CONCAT35((int3)((ulonglong)uVar3 >> 0x28),CONCAT14(bVar5,(uint)uVar4));
  } while ((char)((bVar5 < (byte)uVar4) << 7) < '\0');
  uVar3 = CONCAT26(uVar6,(uint6)(uint)uVar4);
  uVar2 = matrix_wait_map(0xd932,(short)uVar4);
  if ((byte)uVar2 != 0) {
    bVar5 = dec_set_special_ret((byte)uVar2);
    return bVar5;
  }
  uVar2 = matrix_row_scan(0xd932,(ushort)uVar3);
  if ((byte)uVar2 != 0) {
    bVar5 = dec_set_special_ret((byte)uVar2);
    return bVar5;
  }
  uVar2 = matrix_row_check(0xd932,(ushort)uVar3,'\0');
  if ((byte)uVar2 != 0) {
    bVar5 = dec_set_special_ret((byte)uVar2);
    return bVar5;
  }
  uVar2 = matrix_add_common((undefined *)0xd932,(short)uVar3);
  if ((byte)uVar2 != 0) {
    bVar5 = dec_set_special_ret((byte)uVar2);
    return bVar5;
  }
  if (*(char *)((short)((ulonglong)uVar3 >> 0x30) + -1) != '\x03') {
    uVar2 = matrix_copy(0xd932,(ushort)uVar3);
    if ((byte)uVar2 != 0) {
      bVar5 = dec_set_special_ret((byte)uVar2);
      return bVar5;
    }
  }
  memmove_blocks(*(undefined **)((short)((ulonglong)uVar3 >> 0x30) + -0xc),'\x01');
  return 0;
}

/**
 * @brief 把 0xD932 处的数据按 0x28 字节块上/下移动 param_2 块（矩阵行插入/删…
 * @addr 0x1447A
 * @module eval
 * @proto void memmove_blocks(byte* dst, char up)
 * @confidence strong
 * @note 把 0xD932 处的数据按 0x28 字节块上/下移动 param_2 块（矩阵行插入/删除）。
 * @tag matrix
 */
int memmove_blocks(byte* dst, char up)

{
  short sVar1;
  undefined *puVar2;
  char cVar4;
  ulonglong uVar3;
  
  puVar2 = (undefined *)0xd932;
  if (dst != (undefined *)0xd932) {
    if (up == '\0') {
      sVar1 = 0x32;
      uVar3 = CONCAT62((uint6)(uint3)(CONCAT14(4,ZEXT24(dst) << 0x10) >> 0x10),0x28);
    }
    else {
      sVar1 = 0x28;
      uVar3 = 0x4d9320032;
      puVar2 = dst;
    }
    while( true ) {
      memcpy_bytes(puVar2,(undefined *)(uVar3 >> 0x10),0x28);
      cVar4 = (char)(uVar3 >> 0x20) + -1;
      if (cVar4 == '\0') break;
      puVar2 = puVar2 + sVar1;
      uVar3 = (ulonglong)
              CONCAT14(cVar4,CONCAT22((short)(uVar3 >> 0x10) + (short)uVar3,(short)uVar3));
    }
  }
  return 0;
}

/**
 * @brief 矩阵按行扫描（0x93BA 读键等待），在矩阵数据中定位/映射单元
 * @addr 0x144BC
 * @module eval
 * @proto undefined2 matrix_wait_map(undefined * base, ushort idx)
 * @confidence likely
 * @note 矩阵按行扫描（0x93BA 读键等待），在矩阵数据中定位/映射单元。
 * @tag matrix
 */
undefined2 matrix_wait_map(undefined * base, ushort idx)

{
  bool bVar1;
  undefined2 *puVar2;
  char cVar5;
  byte bVar6;
  ulonglong uVar3;
  undefined3 uVar7;
  byte bVar8;
  char cVar4;
  
  uVar3 = (ulonglong)CONCAT21((short)(CONCAT12((char)idx,idx) >> 8),(char)idx + -1);
  do {
    cVar4 = (char)(uVar3 >> 0x10) + -1;
    uVar3 = CONCAT53((int5)(uVar3 >> 0x18),CONCAT12(cVar4,(short)uVar3));
    if (cVar4 == '\0') {
      return base & 0xff00;
    }
    for (; bVar8 = (byte)(uVar3 >> 8), bVar6 = (byte)(uVar3 >> 0x28), bVar1 = bVar6 == bVar8,
        bVar6 < bVar8; uVar3 = (ulonglong)CONCAT15((char)(uVar3 >> 0x28) + '\x01',(int5)uVar3)) {
      while( true ) {
        bVar8 = bVar1 << 6;
        base = kbd_wait_key();
        if ((bVar8 >> 6 & 1) != 1) {
          return base;
        }
        if ((byte)uVar3 <= (byte)(uVar3 >> 0x20)) goto LAB_rom_014516;
        puVar2 = (undefined2 *)matrix_cell_index();
        base = dec_cmp(puVar2,idx);
        if ((char)base != '\x01') goto LAB_rom_01451a;
        cVar4 = (char)uVar3 + -1;
        idx = CONCAT11((char)((ushort)idx >> 8),cVar4);
        cVar5 = (char)(uVar3 >> 0x20);
        uVar7 = (undefined3)(uVar3 >> 0x28);
        if (cVar5 == cVar4) break;
        cVar5 = cVar5 + '\x01';
        uVar3 = CONCAT35(uVar7,CONCAT14(cVar5,(uint)uVar3));
        bVar1 = cVar5 == '\0';
      }
      uVar3 = CONCAT35(uVar7,(uint5)(uint)uVar3);
      puVar2 = (undefined2 *)matrix_cell_index();
      base = dec_cmp(puVar2,idx);
      if ((char)base != '\x01') {
        uVar3 = uVar3 & 0xffffffff;
        goto LAB_rom_014522;
      }
      uVar3 = CONCAT35((int3)(uVar3 >> 0x28),
                       CONCAT14((char)uVar3 - (char)(uVar3 >> 0x10),(int)uVar3));
LAB_rom_014516:
    }
LAB_rom_01451a:
    cVar4 = (char)uVar3 - (char)(uVar3 >> 0x10);
    idx = CONCAT11((char)((ushort)idx >> 8),cVar4);
    if ((char)(uVar3 >> 0x20) != cVar4) {
LAB_rom_014522:
      base = matrix_swap_rows();
    }
    uVar3 = (ulonglong)CONCAT14(((char)uVar3 + '\x01') - (char)(uVar3 >> 0x10),(int)uVar3);
  } while( true );
}

/**
 * @brief 逐行比较矩阵单元（0x1D5B6）定位目标行
 * @addr 0x14534
 * @module eval
 * @proto undefined2 matrix_row_scan(undefined * base, ushort idx)
 * @confidence likely
 * @note 逐行比较矩阵单元（0x1D5B6）定位目标行。
 * @tag matrix
 */
undefined2 matrix_row_scan(undefined * base, ushort idx)

{
  undefined2 *puVar1;
  char cVar3;
  undefined8 uVar2;
  byte bVar4;
  undefined auStack_10 [12];
  
  uVar2 = CONCAT26(auStack_10,(uint6)idx);
  while( true ) {
    if ((byte)((ulonglong)uVar2 >> 8) <= (byte)((ulonglong)uVar2 >> 0x28)) goto LAB_rom_014474;
    puVar1 = (undefined2 *)matrix_cell_index();
    base = dec_cmp(puVar1,idx);
    if ((char)base != '\x01') break;
    uVar2 = CONCAT26((short)((ulonglong)uVar2 >> 0x30),
                     CONCAT15((char)((ulonglong)uVar2 >> 0x28) + '\x01',(int5)uVar2));
  }
  uVar2 = CONCAT53((int5)((ulonglong)uVar2 >> 0x18),(uint3)(ushort)uVar2);
LAB_rom_01455a:
  if ((byte)((ulonglong)uVar2 >> 0x10) < (byte)((char)uVar2 - 1U)) {
    do {
      uVar2 = CONCAT35((int3)((ulonglong)uVar2 >> 0x28),(uint5)(uint)uVar2);
      puVar1 = (undefined2 *)matrix_cell_index();
      dec_copy((undefined2 *)((short)((ulonglong)uVar2 >> 0x30) + -10),puVar1);
      dec_bin_result((ushort *)((short)((ulonglong)uVar2 >> 0x30) + -10),puVar1);
      cVar3 = (char)((ulonglong)uVar2 >> 0x10) + '\x01';
      uVar2 = CONCAT35((int3)((ulonglong)uVar2 >> 0x28),CONCAT14(cVar3,(int)uVar2));
      while( true ) {
        bVar4 = (cVar3 == '\0') << 6;
        base = kbd_wait_key();
        if ((bVar4 >> 6 & 1) != 1) {
          return base;
        }
        if ((byte)uVar2 <= (byte)((ulonglong)uVar2 >> 0x20)) {
          uVar2 = CONCAT53((int5)((ulonglong)uVar2 >> 0x18),
                           CONCAT12((char)((ulonglong)uVar2 >> 0x10) + '\x01',(short)uVar2));
          goto LAB_rom_01455a;
        }
        puVar1 = (undefined2 *)matrix_cell_index();
        dec_copy((undefined2 *)((short)((ulonglong)uVar2 >> 0x30) + -0x14),puVar1);
        base = dec_cmp((undefined2 *)((short)((ulonglong)uVar2 >> 0x30) + -0x14),puVar1);
        if ((char)base == '\x01') goto LAB_rom_014474;
        dec_bin_result((ushort *)((short)((ulonglong)uVar2 >> 0x30) + -0x14),puVar1);
        cVar3 = dec_cmp_bool((undefined2 *)((short)((ulonglong)uVar2 >> 0x30) + -10));
        if (cVar3 == '\x02') break;
        cVar3 = (char)((ulonglong)uVar2 >> 0x20) + '\x01';
        uVar2 = CONCAT35((int3)((ulonglong)uVar2 >> 0x28),CONCAT14(cVar3,(int)uVar2));
      }
      matrix_swap_rows();
      uVar2 = CONCAT26((short)((ulonglong)uVar2 >> 0x30),(uint6)(uint5)uVar2);
    } while( true );
  }
LAB_rom_014474:
  return base & 0xff00;
}

/**
 * @brief 矩阵行检查
 * @addr 0x145D8
 * @module eval
 * @proto undefined2 matrix_row_check(undefined * base, ushort idx)
 * @confidence likely
 * @note 矩阵行检查：对每个单元做 0x14668 有效性验证。
 * @tag matrix
 */
undefined2 matrix_row_check(undefined * base, ushort idx, int _a3)

{
  undefined2 uVar1;
  undefined2 *puVar2;
  short sVar3;
  ushort uVar4;
  char cVar7;
  undefined8 uVar5;
  undefined8 uVar6;
  byte bVar8;
  undefined auStack_10 [12];
  
  uVar5 = CONCAT35((int3)((ZEXT28(auStack_10) << 0x30) >> 0x28),(uint5)idx);
  do {
    if ((byte)uVar5 <= (byte)((ulonglong)uVar5 >> 0x20)) {
      return base & 0xff00;
    }
    uVar5 = CONCAT26((short)((ulonglong)uVar5 >> 0x30),(uint6)(uint5)uVar5);
    bVar8 = 0x40;
    while( true ) {
      base = kbd_wait_key();
      if ((bVar8 >> 6 & 1) != 1) {
        return base;
      }
      if ((byte)((ulonglong)uVar5 >> 8) <= (byte)((ulonglong)uVar5 >> 0x28)) goto LAB_rom_014664;
      uVar1 = matrix_elem_is_valid((short)((ulonglong)uVar5 >> 0x20),_a3);
      if ((char)uVar1 != '\x01') break;
      puVar2 = (undefined2 *)matrix_cell_index();
      dec_copy(puVar2,(undefined2 *)0x1b62);
      cVar7 = (char)((ulonglong)uVar5 >> 0x28) + '\x01';
      uVar5 = CONCAT26((short)((ulonglong)uVar5 >> 0x30),CONCAT15(cVar7,(int5)uVar5));
      bVar8 = (cVar7 == '\0') << 6;
    }
    puVar2 = (undefined2 *)matrix_cell_index();
    uVar6 = CONCAT44((int)((ulonglong)uVar5 >> 0x20),CONCAT22(puVar2,(short)uVar5));
    dec_copy((undefined2 *)((short)((ulonglong)uVar5 >> 0x30) + -10),puVar2);
    dec_copy((undefined2 *)((ulonglong)uVar6 >> 0x10),(undefined2 *)0x1b6c);
    cVar7 = (char)((ulonglong)uVar6 >> 0x28) + '\x01';
    uVar5 = CONCAT26((short)((ulonglong)uVar6 >> 0x30),CONCAT15(cVar7,(int5)uVar6));
    while( true ) {
      bVar8 = (cVar7 == '\0') << 6;
      base = kbd_wait_key();
      if ((bVar8 >> 6 & 1) != 1) {
        return base;
      }
      if ((byte)((ulonglong)uVar5 >> 8) <= (byte)((ulonglong)uVar5 >> 0x28)) break;
      sVar3 = matrix_cell_index();
      uVar4 = dec_int_add(sVar3,(undefined2 *)((short)((ulonglong)uVar5 >> 0x30) + -10));
      if ((char)uVar4 != '\0') {
        return uVar4;
      }
      cVar7 = (char)((ulonglong)uVar5 >> 0x28) + '\x01';
      uVar5 = CONCAT26((short)((ulonglong)uVar5 >> 0x30),CONCAT15(cVar7,(int5)uVar5));
    }
LAB_rom_014664:
    uVar5 = CONCAT35((int3)((ulonglong)uVar5 >> 0x28),
                     CONCAT14((char)((ulonglong)uVar5 >> 0x20) + '\x01',(int)uVar5));
  } while( true );
}

/**
 * @brief 矩阵单元有效性
 * @addr 0x14668
 * @module eval
 * @proto byte matrix_elem_is_valid(undefined2 a, char strict)
 * @confidence likely
 * @note 矩阵单元有效性：类型为 1 直接有效；strict 时再用 0x1CBB2/0x1D89E 检查指数范围。
 * @tag matrix
 */
byte matrix_elem_is_valid(undefined2 a, char strict)

{
  byte bVar1;
  undefined2 *puVar2;
  undefined2 uVar3;
  ushort uVar4;
  byte bVar5;
  undefined4 uVar7;
  longlong lVar6;
  short sVar8;
  undefined auStack_10 [12];
  
  uVar7 = (undefined4)((ZEXT28(auStack_10) << 0x30) >> 0x20);
  puVar2 = (undefined2 *)matrix_cell_index();
  lVar6 = (ulonglong)CONCAT42(uVar7,puVar2) << 0x10;
  uVar3 = dec_cmp(puVar2,a);
  if ((char)uVar3 == '\x01') {
LAB_rom_0146ac:
    uVar3 = 1;
  }
  else {
    if (strict != '\0') {
      puVar2 = (undefined2 *)((ulonglong)lVar6 >> 0x10);
      dec_copy((undefined2 *)((short)((ulonglong)lVar6 >> 0x30) + -10),puVar2);
      sVar8 = (short)((ulonglong)lVar6 >> 0x30);
      dec_bin_result((ushort *)(sVar8 + -10),puVar2);
      uVar4 = dec_unary_sin((undefined2 *)(sVar8 + -10),puVar2);
      bVar5 = (byte)(uVar4 >> 8);
      bVar1 = (bVar5 + 1) - ((byte)uVar4 < 0xf5);
      if ((byte)((byte)((bVar1 ^ bVar5) & (~bVar1 ^ 0xff)) >> 7 ^ (char)bVar1 < '\0' |
                ((byte)uVar4 == 0xf5 && bVar1 == 0)) != 0) goto LAB_rom_0146ac;
    }
    uVar3 = 0;
  }
  return uVar3;
}

/**
 * @brief 矩阵运算公共分派
 * @addr 0x146B8
 * @module eval
 * @proto int matrix_add_common(undefined * base, ushort idx)
 * @confidence likely
 * @note 矩阵运算公共分派：按操作数类型核对行列、单位阵/特殊阵并行调用0x149AE/0x148FC/0x14A14 等行操作。
 * @tag matrix
 */
int matrix_add_common(undefined * base, ushort idx)

{
  bool bVar1;
  undefined *puVar2;
  short sVar3;
  undefined2 *puVar4;
  undefined2 *puVar5;
  undefined2 uVar6;
  ushort uVar7;
  undefined *puVar8;
  undefined4 uVar9;
  uint5 uVar10;
  byte bVar13;
  char cVar14;
  undefined8 in_QR8;
  undefined8 uVar11;
  byte bVar15;
  undefined auStack_10 [12];
  ulonglong uVar12;
  
  uVar11 = CONCAT26(auStack_10,(uint6)(uint)CONCAT62((int6)((ulonglong)in_QR8 >> 0x10),idx));
  if ((char)((ushort)idx >> 8) == '\x01') {
    puVar5 = (undefined2 *)matrix_cell_index();
    uVar9 = CONCAT22(puVar5,(short)uVar11);
    uVar6 = dec_cmp(puVar5,idx);
    if ((char)uVar6 != '\x01') {
      dec_copy((undefined2 *)((uint)uVar9 >> 0x10),(undefined2 *)0x1b6c);
    }
    uVar10 = CONCAT14(1,uVar9);
    bVar1 = false;
    while( true ) {
      bVar15 = bVar1 << 6;
      uVar12 = (ulonglong)uVar10;
      uVar7 = kbd_wait_key();
      if ((bVar15 >> 6 & 1) != 1) break;
      if ((byte)uVar12 <= (byte)(uVar12 >> 0x20)) {
LAB_rom_014474:
        return uVar7 & 0xff00;
      }
      puVar5 = (undefined2 *)matrix_cell_index();
      dec_copy(puVar5,(undefined2 *)0x1b62);
      cVar14 = (char)(uVar12 >> 0x20) + '\x01';
      uVar10 = CONCAT14(cVar14,(int)uVar12);
      bVar1 = cVar14 == '\0';
    }
  }
  else {
    puVar5 = (undefined2 *)matrix_cell_index();
    uVar6 = dec_cmp(puVar5,idx);
    if ((char)uVar6 == '\x01') {
      uVar7 = matrix_del_rows((ushort)base,(ushort)uVar11);
    }
    else {
      uVar11 = CONCAT53((int5)((ulonglong)uVar11 >> 0x18),(uint3)(ushort)uVar11);
      bVar15 = 0x40;
      while (uVar7 = kbd_wait_key(), (bVar15 >> 6 & 1) == 1) {
        bVar15 = (char)uVar11 - 1;
        uVar7 = CONCAT11((char)(uVar7 >> 8),bVar15);
        bVar13 = (byte)((ulonglong)uVar11 >> 0x10);
        if ((bVar15 <= bVar13) || ((byte)((ulonglong)uVar11 >> 8) <= bVar13)) goto LAB_rom_014474;
        puVar2 = (undefined *)const_idx_16((short)((ulonglong)uVar11 >> 0x30));
        memcpy100(puVar2,base);
        cVar14 = (char)((ulonglong)uVar11 >> 0x10);
        if (cVar14 != '\0') {
          uVar6 = CONCAT11(cVar14,cVar14);
          puVar5 = (undefined2 *)level_index_1();
          uVar6 = dec_cmp(puVar5,uVar6);
          if ((char)uVar6 == '\x01') {
            uVar7 = matrix_ins_fill((short)uVar11,(char)((ulonglong)uVar11 >> 0x10));
            if ((char)uVar7 != '\0') {
              return uVar7;
            }
            cVar14 = (char)((ulonglong)uVar11 >> 0x10);
            uVar7 = matrix_del_rows((ushort)base, (uintptr_t)0)
                                   CONCAT11((char)((ulonglong)uVar11 >> 8) - cVar14,
                                            (char)uVar11 - cVar14));
            if ((char)uVar7 != '\0') {
              return uVar7;
            }
            cVar14 = (char)((ulonglong)uVar11 >> 0x10);
            uVar7 = matrix_row_fill((ushort)base, (uintptr_t)0, (uintptr_t)0)
                                   CONCAT11((char)((ulonglong)uVar11 >> 8) - cVar14,
                                            (char)uVar11 - cVar14),
                                   (ushort)((ulonglong)uVar11 >> 0x10));
            if ((char)uVar7 != '\0') {
              return uVar7;
            }
            uVar11 = CONCAT26((short)((ulonglong)uVar11 >> 0x30),(uint6)CONCAT14(1,(int)uVar11));
            bVar1 = true;
            while( true ) {
              bVar15 = bVar1 << 6;
              uVar7 = kbd_wait_key();
              if ((bVar15 >> 6 & 1) != 1) {
                return uVar7;
              }
              sVar3 = (short)((ulonglong)uVar11 >> 0x30);
              if ((byte)((char)uVar11 - (char)((ulonglong)uVar11 >> 0x10)) <=
                  (byte)((ulonglong)uVar11 >> 0x20)) break;
              const_idx_16(sVar3);
              puVar2 = (undefined *)level_index_1();
              puVar8 = (undefined *)matrix_cell_index();
              memcpy25(puVar2,puVar8);
              cVar14 = (char)((ulonglong)uVar11 >> 0x20) + '\x01';
              uVar11 = CONCAT35((int3)((ulonglong)uVar11 >> 0x28),CONCAT14(cVar14,(int)uVar11));
              bVar1 = cVar14 == '\0';
            }
            puVar2 = (undefined *)const_idx_16(sVar3);
            uVar7 = memcpy100(base,puVar2);
            goto LAB_rom_014474;
          }
        }
        uVar11 = CONCAT35((int3)((ulonglong)uVar11 >> 0x28),
                          CONCAT14((char)((ulonglong)uVar11 >> 0x10),(int)uVar11));
        while( true ) {
          bVar15 = (byte)((ulonglong)uVar11 >> 0x20);
          sVar3 = (short)((ulonglong)uVar11 >> 0x30);
          if ((byte)((char)uVar11 - 1U) <= bVar15) break;
          uVar11 = CONCAT35((int3)((ulonglong)uVar11 >> 0x28),CONCAT14(bVar15 + 1,(int)uVar11));
          sVar3 = const_idx_16(sVar3);
          sVar3 = const_idx_16(sVar3);
          puVar2 = (undefined *)(sVar3 + 4);
          memzero_C8(puVar2);
          cVar14 = (char)((ulonglong)uVar11 >> 0x10);
          uVar11 = CONCAT26((short)((ulonglong)uVar11 >> 0x30),CONCAT15(cVar14,(int5)uVar11));
          bVar1 = cVar14 == '\0';
          while( true ) {
            bVar15 = bVar1 << 6;
            uVar7 = kbd_wait_key();
            if ((bVar15 >> 6 & 1) != 1) {
              return uVar7;
            }
            cVar14 = (char)((ulonglong)uVar11 >> 8);
            bVar15 = (byte)((ulonglong)uVar11 >> 0x28);
            if ((byte)(cVar14 - 1U) <= bVar15) break;
            uVar11 = CONCAT26((short)((ulonglong)uVar11 >> 0x30),CONCAT15(bVar15 + 1,(int5)uVar11));
            puVar5 = (undefined2 *)level_index_1();
            puVar4 = (undefined2 *)level_index_1();
            dec_copy(puVar5,puVar4);
            puVar4 = (undefined2 *)level_index_1();
            dec_bin_pow(puVar5,puVar4);
            puVar4 = (undefined2 *)level_index_1();
            dec_copy((undefined2 *)(sVar3 + -6),puVar4);
            puVar4 = (undefined2 *)level_index_1();
            dec_bin_pow((undefined2 *)(sVar3 + -6),puVar4);
            uVar7 = dec_bin_mul(puVar5,(undefined2 *)(sVar3 + -6));
            bVar1 = (char)uVar7 == '\0';
            if (!bVar1) {
              return uVar7;
            }
          }
          uVar7 = matrix_row_check((ushort)puVar2,CONCAT11(cVar14,1),'\x01');
          if ((char)uVar7 != '\0') {
            return uVar7;
          }
          const_idx_16((short)((ulonglong)uVar11 >> 0x30));
          puVar8 = (undefined *)level_index_1();
          memcpy25(puVar8,puVar2);
        }
        if ((byte)((ulonglong)uVar11 >> 0x10) < (byte)((char)uVar11 - 2U)) {
          uVar7 = const_idx_16(sVar3);
          uVar7 = matrix_wait_map(uVar7,(short)uVar11);
          if ((char)uVar7 != '\0') {
            return uVar7;
          }
        }
        puVar2 = (undefined *)const_idx_16((short)((ulonglong)uVar11 >> 0x30));
        memcpy100(base,puVar2);
        cVar14 = (char)((ulonglong)uVar11 >> 0x10) + '\x01';
        uVar11 = CONCAT53((int5)((ulonglong)uVar11 >> 0x18),CONCAT12(cVar14,(short)uVar11));
        bVar15 = (cVar14 == '\0') << 6;
      }
    }
  }
  return uVar7;
}

