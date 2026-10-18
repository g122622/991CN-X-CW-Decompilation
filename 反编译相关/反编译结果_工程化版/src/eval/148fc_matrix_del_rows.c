/*
 * 表达式求值 / 148fc_matrix_del_rows.c
 * 地址范围: 0x148FC - 0x14F08
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 矩阵删除连续行
 * @addr 0x148FC
 * @module eval
 * @proto undefined2 matrix_del_rows(ushort y, ushort range)
 * @confidence strong
 * @note 矩阵删除连续行：按范围逐行搬移后续单元格（0x14B0A 寻址）。
 * @tag matrix
 */
undefined2 matrix_del_rows(ushort y, ushort range)

{
  undefined2 *puVar1;
  undefined2 uVar2;
  ushort uVar3;
  uint6 uVar4;
  char cVar7;
  ulonglong uVar5;
  undefined8 uVar6;
  
  cVar7 = (char)((ushort)range >> 8);
  if (cVar7 == '\x01') {
    uVar3 = y & 0xff00;
  }
  else {
    uVar4 = CONCAT33(0x10000,CONCAT12(cVar7 + -1,range));
    while (uVar5 = (ulonglong)uVar4, (byte)(uVar4 >> 0x28) < (byte)(uVar4 >> 0x10)) {
      puVar1 = (undefined2 *)matrix_cell_index();
      uVar2 = dec_cmp(puVar1,range);
      if ((char)uVar2 != '\x01') break;
      uVar4 = CONCAT15((char)(uVar5 >> 0x28) + '\x01',(int5)uVar5);
    }
    uVar3 = matrix_insert_rows(y,(short)uVar5,(byte)(uVar5 >> 0x28));
    if ((char)uVar3 == '\0') {
      uVar2 = CONCAT11((char)(uVar5 >> 8) - (char)(uVar5 >> 0x28),(char)uVar5);
      uVar6 = CONCAT62((int6)(uVar5 >> 0x10),uVar2);
      uVar3 = matrix_add_common((undefined *)y,uVar2);
      if ((char)uVar3 == '\0') {
        uVar3 = matrix_row_fill(y,(ushort)uVar6, (uintptr_t)0)
                               CONCAT11((char)(uVar3 >> 8),(char)((ulonglong)uVar6 >> 0x28)));
      }
    }
  }
  return uVar3;
}

/**
 * @brief 矩阵插入行
 * @addr 0x14966
 * @module eval
 * @proto undefined2 matrix_insert_rows(ushort y, ushort pos, char n)
 * @confidence strong
 * @note 矩阵插入行：把 pos 之后的单元格整体后移 n 行。
 * @tag matrix
 */
undefined2 matrix_insert_rows(ushort y, ushort pos, char n)

{
  bool bVar1;
  short sVar2;
  ushort uVar3;
  undefined2 *puVar5;
  char cVar6;
  ulonglong uVar4;
  byte bVar7;
  
  uVar3 = CONCAT11((char)((ushort)y >> 8),10);
  uVar4 = (ulonglong)CONCAT11((char)((ushort)pos >> 8) - n,(char)pos);
  do {
    if ((byte)uVar4 <= (byte)(uVar4 >> 0x20)) {
      return uVar3 & 0xff00;
    }
    sVar2 = matrix_cell_index();
    uVar4 = CONCAT44((int)(uVar4 >> 0x20),CONCAT22(sVar2,(short)uVar4));
    bVar1 = sVar2 == 0;
    while( true ) {
      bVar7 = bVar1 << 6;
      uVar3 = kbd_wait_key();
      if ((bVar7 >> 6 & 1) != 1) {
        return uVar3;
      }
      if ((byte)(uVar4 >> 8) <= (byte)(uVar4 >> 0x28)) break;
      puVar5 = (undefined2 *)(uVar4 >> 0x10);
      dec_copy(puVar5,puVar5 + (ushort)n * 5);
      cVar6 = (char)(uVar4 >> 0x28) + '\x01';
      uVar4 = (ulonglong)
              CONCAT15(cVar6,(int5)CONCAT44((int)(uVar4 >> 0x20),
                                            CONCAT22((short)(uVar4 >> 0x10) + 10,(short)uVar4)));
      bVar1 = cVar6 == '\0';
    }
    uVar4 = (ulonglong)CONCAT14((char)(uVar4 >> 0x20) + '\x01',(int)uVar4);
  } while( true );
}

/**
 * @brief 矩阵插入后填充空行（0x93BA 读键等待、逐单元清零）
 * @addr 0x149AE
 * @module eval
 * @proto undefined2 matrix_ins_fill(ushort pos, char n)
 * @confidence likely
 * @note 矩阵插入后填充空行（0x93BA 读键等待、逐单元清零）。
 * @tag matrix
 */
undefined2 matrix_ins_fill(ushort pos, char n)

{
  bool bVar1;
  ushort uVar2;
  undefined2 *puVar3;
  undefined2 *puVar4;
  char cVar6;
  undefined8 uVar5;
  short sVar7;
  byte bVar8;
  undefined auStack_10 [12];
  
  uVar5 = CONCAT35((int3)((ZEXT28(auStack_10) << 0x30) >> 0x28),
                   (uint5)CONCAT11((char)((ushort)pos >> 8) - n,(char)pos - n));
  bVar1 = true;
  while( true ) {
    bVar8 = bVar1 << 6;
    uVar2 = kbd_wait_key();
    if ((bVar8 >> 6 & 1) != 1) {
      return uVar2;
    }
    if ((byte)uVar5 <= (byte)((ulonglong)uVar5 >> 0x20)) break;
    uVar5 = CONCAT26((short)((ulonglong)uVar5 >> 0x30),(uint6)(uint5)uVar5);
    puVar3 = (undefined2 *)matrix_cell_index();
    *(undefined2 **)((short)((ulonglong)uVar5 >> 0x30) + -2) = puVar3;
    puVar4 = (undefined2 *)level_index_1();
    *(undefined2 **)((short)((ulonglong)uVar5 >> 0x30) + -4) = puVar4;
    for (; (byte)((ulonglong)uVar5 >> 0x28) < (byte)((ulonglong)uVar5 >> 8);
        uVar5 = CONCAT26(sVar7,CONCAT15((char)((ulonglong)uVar5 >> 0x28) + '\x01',(int5)uVar5))) {
      dec_copy(puVar3,puVar4);
      sVar7 = (short)((ulonglong)uVar5 >> 0x30);
      puVar3 = (undefined2 *)(*(short *)(sVar7 + -2) + 10);
      *(undefined2 **)(sVar7 + -2) = puVar3;
      puVar4 = (undefined2 *)(*(short *)(sVar7 + -4) + 10);
      *(undefined2 **)(sVar7 + -4) = puVar4;
    }
    cVar6 = (char)((ulonglong)uVar5 >> 0x20) + '\x01';
    uVar5 = CONCAT35((int3)((ulonglong)uVar5 >> 0x28),CONCAT14(cVar6,(int)uVar5));
    bVar1 = cVar6 == '\0';
  }
  return uVar2 & 0xff00;
}

/**
 * @brief 矩阵行区间填充
 * @addr 0x14A14
 * @module eval
 * @proto undefined2 matrix_row_fill(ushort pos, ushort range)
 * @confidence likely
 * @note 矩阵行区间填充：对范围内的行调用 0x14B0A 寻址并清理。
 * @tag matrix
 */
undefined2 matrix_row_fill(ushort pos, ushort range, int _a3)

{
  bool bVar1;
  short sVar2;
  ushort uVar3;
  undefined *puVar4;
  undefined2 *puVar6;
  char cVar7;
  ulonglong uVar5;
  byte bVar8;
  
  uVar5 = (ulonglong)range;
  do {
    if ((byte)uVar5 <= (byte)(uVar5 >> 0x20)) {
      return pos & 0xff00;
    }
    uVar5 = (ulonglong)CONCAT15((char)(uVar5 >> 8) + -1,(int5)uVar5);
    sVar2 = matrix_cell_index();
    cVar7 = (char)(uVar5 >> 0x28) + '\x01';
    uVar5 = (ulonglong)
            CONCAT15(cVar7,(int5)CONCAT44((int)(uVar5 >> 0x20),CONCAT22(sVar2,(short)uVar5)));
    bVar1 = cVar7 == '\0';
    do {
      bVar8 = bVar1 << 6;
      uVar3 = kbd_wait_key();
      if ((bVar8 >> 6 & 1) != 1) {
        return uVar3;
      }
      puVar6 = (undefined2 *)(uVar5 >> 0x10);
      dec_copy(puVar6 + (_a3 & 0xff) * 5,puVar6);
      cVar7 = (char)(uVar5 >> 0x28) + -1;
      uVar5 = (ulonglong)
              CONCAT15(cVar7,(int5)CONCAT44((int)(uVar5 >> 0x20),
                                            CONCAT22((short)(uVar5 >> 0x10) + -10,(short)uVar5)));
      bVar1 = cVar7 == '\0';
    } while (!bVar1);
    puVar4 = (undefined *)matrix_cell_index();
    pos = memzero(puVar4,(_a3 & 0xff) * 10);
    uVar5 = (ulonglong)CONCAT14((char)(uVar5 >> 0x20) + '\x01',(int)uVar5);
  } while( true );
}

/**
 * @brief 矩阵整体复制/整理（单位阵构造后的收尾步骤）
 * @addr 0x14A64
 * @module eval
 * @proto undefined2 matrix_copy(undefined * base, ushort idx)
 * @confidence likely
 * @note 矩阵整体复制/整理（单位阵构造后的收尾步骤）。
 * @tag matrix
 */
undefined2 matrix_copy(undefined * base, ushort idx)

{
  undefined2 *puVar1;
  ushort uVar2;
  undefined2 *puVar3;
  char cVar5;
  undefined8 uVar4;
  byte bVar6;
  undefined auStack_10 [12];
  
  uVar4 = CONCAT35((int3)((ZEXT28(auStack_10) << 0x30) >> 0x28),CONCAT14(1,(uint)idx));
  do {
    bVar6 = (byte)((ulonglong)uVar4 >> 0x20);
    if ((byte)uVar4 <= bVar6) {
      return base & 0xff00;
    }
    uVar4 = CONCAT26((short)((ulonglong)uVar4 >> 0x30),CONCAT15(bVar6,(int5)uVar4));
    while( true ) {
      if ((byte)((ulonglong)uVar4 >> 8) <= (byte)((ulonglong)uVar4 >> 0x28)) goto LAB_rom_014b06;
      puVar1 = (undefined2 *)matrix_cell_index();
      base = dec_cmp(puVar1,idx);
      if ((char)base != '\x01') break;
      uVar4 = CONCAT26((short)((ulonglong)uVar4 >> 0x30),
                       CONCAT15((char)((ulonglong)uVar4 >> 0x28) + '\x01',(int5)uVar4));
    }
    for (uVar4 = CONCAT53((int5)((ulonglong)uVar4 >> 0x18),(uint3)(ushort)uVar4);
        bVar6 = (byte)((ulonglong)uVar4 >> 0x10), bVar6 < (byte)((ulonglong)uVar4 >> 0x20);
        uVar4 = CONCAT53((int5)((ulonglong)uVar4 >> 0x18),
                         CONCAT12((char)((ulonglong)uVar4 >> 0x10) + '\x01',(short)uVar4))) {
      idx = CONCAT11((char)((ulonglong)uVar4 >> 0x28),bVar6);
      puVar1 = (undefined2 *)level_index_1();
      base = dec_cmp(puVar1,idx);
      if ((char)base != '\x01') {
        cVar5 = (char)((ulonglong)uVar4 >> 0x28) + '\x01';
        uVar4 = CONCAT44((int)((ulonglong)uVar4 >> 0x20),CONCAT13(cVar5,(int3)uVar4));
        while( true ) {
          bVar6 = (cVar5 == '\0') << 6;
          uVar2 = kbd_wait_key();
          if ((bVar6 >> 6 & 1) != 1) {
            return uVar2;
          }
          if ((byte)((ulonglong)uVar4 >> 8) <= (byte)((ulonglong)uVar4 >> 0x18)) break;
          dec_copy((undefined2 *)((short)((ulonglong)uVar4 >> 0x30) + -10),puVar1);
          puVar3 = (undefined2 *)level_index_1();
          dec_bin_pow((undefined2 *)((short)((ulonglong)uVar4 >> 0x30) + -10),puVar3);
          puVar3 = (undefined2 *)level_index_1();
          uVar2 = dec_bin_mul(puVar3,(undefined2 *)((short)((ulonglong)uVar4 >> 0x30) + -10));
          if ((char)uVar2 != '\0') {
            return uVar2;
          }
          cVar5 = (char)((ulonglong)uVar4 >> 0x18) + '\x01';
          uVar4 = CONCAT44((int)((ulonglong)uVar4 >> 0x20),CONCAT13(cVar5,(int3)uVar4));
        }
        idx = 0x1b62;
        base = dec_copy(puVar1,(undefined2 *)0x1b62);
      }
    }
LAB_rom_014b06:
    uVar4 = CONCAT35((int3)((ulonglong)uVar4 >> 0x28),
                     CONCAT14((char)((ulonglong)uVar4 >> 0x20) + '\x01',(int)uVar4));
  } while( true );
}

/**
 * @brief 返回矩阵单元格顺序号 = (R12*5 + R13)*10 + R4（R12/R13/R4 …
 * @addr 0x14B0A
 * @module eval
 * @proto short matrix_cell_index(void)
 * @confidence verified
 * @note 返回矩阵单元格顺序号 = (R12*5 + R13)*10 + R4（R12/R13/R4 为矩阵行列）。
 * @tag matrix
 */
short matrix_cell_index(void)

{
  short unaff_ER4;
  char unaff_R12;
  char unaff_R13;
  
  return (ushort)(byte)(unaff_R12 * '\x05' + unaff_R13) * 10 + unaff_ER4;
}

/**
 * @brief 调用 level_index(1,? 见 0x14B0A)
 * @addr 0x14B1A
 * @module eval
 * @proto void level_index_1(void)
 * @confidence likely
 * @note 调用 level_index(1,? 见 0x14B0A)。
 * @tag util
 */
int level_index_1(void)

{
  matrix_cell_index();
  return 0;
}

/**
 * @brief 向后复制 200 字节（0x22DC4）
 * @addr 0x14B2E
 * @module eval
 * @proto int memcpy100(byte* dst, byte* src)
 * @confidence verified
 * @note 向后复制 200 字节（0x22DC4）。
 * @tag libc
 */
int memcpy100(byte* dst, byte* src)

{
  memcpy_bytes(dst,src,200);
  return 0;
}

/**
 * @brief 向后复制 0x32 字节（0x22DC4）
 * @addr 0x14B42
 * @module eval
 * @proto void memcpy25(byte* dst, byte* src)
 * @confidence verified
 * @note 向后复制 0x32 字节（0x22DC4）。
 * @tag libc
 */
int memcpy25(byte* dst, byte* src)

{
  memcpy_bytes(dst,src,0x32);
  return 0;
}

/**
 * @brief 把 p 处 200 字节清零
 * @addr 0x14B56
 * @module eval
 * @proto void memzero_C8(undefined* p)
 * @confidence verified
 * @note 把 p 处 200 字节清零。
 * @tag util
 */
int memzero_C8(undefined* p)

{
  memzero(p,200);
  return 0;
}

/**
 * @brief 交换由 0x14B0A 计算的两个矩阵行的单元格（每行 R9 个 10 字节单元）
 * @addr 0x14B92
 * @module eval
 * @proto int matrix_swap_rows(void)
 * @confidence strong
 * @note 交换由 0x14B0A 计算的两个矩阵行的单元格（每行 R9 个 10 字节单元）。
 * @tag matrix
 */
int matrix_swap_rows(void)

{
  undefined2 *puVar1;
  undefined2 *puVar2;
  char unaff_R9;
  short unaff_ER14;
  
  puVar1 = (undefined2 *)matrix_cell_index();
  puVar2 = (undefined2 *)matrix_cell_index();
  do {
    dec_copy((undefined2 *)(unaff_ER14 + -0xe),puVar1);
    dec_copy(puVar1,puVar2);
    dec_copy(puVar2,(undefined2 *)(unaff_ER14 + -0xe));
    puVar1 = puVar1 + 5;
    puVar2 = puVar2 + 5;
    unaff_R9 = unaff_R9 + -1;
  } while (unaff_R9 != '\0');
  return 0;
}

/**
 * @brief 返回 R12*10 + ER6（矩阵行列编址）
 * @addr 0x14EFC
 * @module eval
 * @proto ushort matrix_index(void)
 * @confidence verified
 * @note 返回 R12*10 + ER6（矩阵行列编址）。
 * @tag matrix
 */
ushort matrix_index(void)

{
  short unaff_ER6;
  byte unaff_R12;
  
  return (ushort)unaff_R12 * 10 + unaff_ER6;
}

/**
 * @brief 返回 i-0xCC（ROM 常量 0xEC 区索引）
 * @addr 0x14F08
 * @module eval
 * @proto short const_idx_16(short i)
 * @confidence likely
 * @note 返回 i-0xCC（ROM 常量 0xEC 区索引）。
 * @tag util
 */
short const_idx_16(short i)

{
  return i + -0xcc;
}

