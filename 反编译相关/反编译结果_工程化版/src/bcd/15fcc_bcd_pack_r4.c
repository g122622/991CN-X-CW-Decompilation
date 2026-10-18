/*
 * BCD 浮点库 / 15fcc_bcd_pack_r4.c
 * 地址范围: 0x15FCC - 0x1671C
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief BCD 打包
 * @addr 0x15FCC
 * @module bcd
 * @proto void bcd_pack_r4(void)
 * @confidence likely
 * @note BCD 打包：按 R4..R9 半字节组拼（0x15D72 使用）。
 * @tag bcd
 */
int bcd_pack_r4(void)

{
  byte bVar1;
  ushort uVar2;
  byte unaff_R4;
  byte unaff_R5;
  byte unaff_R6;
  byte unaff_R7;
  byte unaff_R8;
  byte bVar3;
  byte unaff_R9;
  byte *unaff_ER14;
  
  unaff_ER14[9] = unaff_R9;
  uVar2 = 0;
  *(undefined2 *)(unaff_ER14 + 6) = 0;
  if (unaff_R9 != 0) {
    uVar2 = 0xa00;
    bVar3 = unaff_R8;
    do {
      unaff_R8 = (byte)(((ushort)bVar3 * 0x100 + (ushort)unaff_R7) * 0x10 >> 8);
      unaff_R7 = (byte)(((ushort)unaff_R7 * 0x100 + (ushort)unaff_R6) * 0x10 >> 8);
      unaff_R6 = (byte)(((ushort)unaff_R6 * 0x100 + (ushort)unaff_R5) * 0x10 >> 8);
      unaff_R5 = (byte)(((ushort)unaff_R5 * 0x100 + (ushort)unaff_R4) * 0x10 >> 8);
      unaff_R4 = unaff_R4 << 4;
      bVar1 = bVar3 & 0xf0;
      uVar2 = CONCAT11((char)(uVar2 >> 8) + -1,bVar3) & 0xfff0;
      bVar3 = unaff_R8;
    } while (bVar1 == 0);
  }
  unaff_ER14[8] = (byte)(uVar2 >> 8);
  *unaff_ER14 = (byte)(uVar2 >> 4) & 0xf;
  unaff_ER14[1] = unaff_R8;
  unaff_ER14[2] = unaff_R7;
  unaff_ER14[3] = unaff_R6;
  unaff_ER14[4] = unaff_R5;
  unaff_ER14[5] = unaff_R4;
  return 0;
}

/**
 * @brief 以 ROM 0x315A 的 9 组 16 位常量做 BCD 乘法/进位链（按 R4..R8…
 * @addr 0x15FFC
 * @module bcd
 * @proto int bcd_mul_table(void)
 * @confidence likely
 * @note 以 ROM 0x315A 的 9 组 16 位常量做 BCD 乘法/进位链（按 R4..R8 半字节展开）。
 * @tag bcd
 */
int bcd_mul_table(void)

{
  bool bVar1;
  short sVar2;
  char cVar3;
  ushort uVar4;
  ushort uVar5;
  char cVar6;
  byte unaff_R4;
  byte unaff_R5;
  byte unaff_R6;
  byte unaff_R7;
  byte unaff_R8;
  char cVar7;
  char unaff_R10;
  ushort uVar8;
  ushort uVar9;
  ushort uVar10;
  ushort *puVar11;
  
  puVar11 = (ushort *)&_DAT_ram_315a;
  cVar7 = '\t';
  uVar4 = 0;
  uVar5 = 0;
  while( true ) {
    uVar8 = *puVar11;
    uVar10 = puVar11[1];
    while( true ) {
      bVar1 = unaff_R8 < 0x10;
      unaff_R8 = unaff_R8 - 0x10;
      cVar6 = (char)(uVar5 >> 8);
      cVar3 = (char)(uVar10 >> 8);
      if (bVar1) break;
      bVar1 = CARRY2(uVar4,uVar8);
      uVar4 = uVar4 + uVar8;
      sVar2 = (uVar5 & 0xff) + (uVar10 & 0xff) + (ushort)bVar1;
      uVar5 = CONCAT11((cVar6 + cVar3) - ((char)((char)((ushort)sVar2 >> 8) << 7) >> 7),(char)sVar2)
      ;
    }
    cVar7 = cVar7 + -1;
    if (cVar7 == '\0') break;
    puVar11 = puVar11 + 2;
    unaff_R8 = (byte)(((ushort)unaff_R8 * 0x100 + (ushort)unaff_R7) * 0x10 >> 8);
    unaff_R7 = (byte)(((ushort)unaff_R7 * 0x100 + (ushort)unaff_R6) * 0x10 >> 8);
    unaff_R6 = (byte)(((ushort)unaff_R6 * 0x100 + (ushort)unaff_R5) * 0x10 >> 8);
    unaff_R5 = (byte)(((ushort)unaff_R5 * 0x100 + (ushort)unaff_R4) * 0x10 >> 8);
    unaff_R4 = unaff_R4 << 4;
  }
  uVar9 = CONCAT11((char)(uVar8 >> 8),unaff_R8) & 0xff0f;
  uVar8 = uVar4 + uVar9;
  sVar2 = (uVar5 & 0xff) + (uVar10 & 0xff) + (ushort)CARRY2(uVar4,uVar9);
  if (sub_mode != '\x01') goto LAB_rom_016058;
  if (CONCAT11((cVar6 + cVar3) - ((char)((char)((ushort)sVar2 >> 8) << 7) >> 7),(char)sVar2) == 0) {
    if ((char)(uVar8 >> 8) == -0x80) {
      if ((unaff_R10 != '\0') && ((char)uVar8 == '\0')) goto LAB_rom_016058;
    }
    else if (uVar8 < 0x8000) {
LAB_rom_016058:
      if (unaff_R10 != '\0') {
        neg_u16(uVar8);
      }
      return 0;
    }
  }
  return 0;
}

/**
 * @brief 以 0x1CE3E 运算后按 5 位十进制调整（尾数字节 -5），再循环 0x16EF4/0…
 * @addr 0x16712
 * @module bcd
 * @proto void dec_add5_bcd(undefined2* a, undefined2 b)
 * @confidence likely
 * @note 以 0x1CE3E 运算后按 5 位十进制调整（尾数字节 -5），再循环 0x16EF4/0x1C858。
 * @tag bcd
 */
int dec_add5_bcd(undefined2* a, undefined2 b)

{
  int sVar1;
  undefined2 uVar2;
  byte bVar4;
  undefined2 *puVar3;
  byte extraout_R1;
  byte bVar5;
  undefined2 uVar6;
  undefined uVar8;
  undefined2 *puVar7;
  byte bVar11;
  undefined8 uVar9;
  char cVar12;
  undefined8 uVar10;
  undefined auStack_16 [10];
  undefined8 uStack_c;
  undefined6 uVar13;
  
  uStack_c._6_2_ = a;
  sVar1 = decm_add(a,b);
  if ((char)sVar1 != '\0') {
    return sVar1;
  }
  bVar5 = *(byte *)(uStack_c._6_2_ + 9);
  uVar6 = CONCAT11((char)((ushort)b >> 8),bVar5 - 5);
  if (4 < bVar5) {
    *(byte *)(uStack_c._6_2_ + 9) = bVar5 - 5;
  }
  uVar10 = CONCAT44(CONCAT22(uStack_c._6_2_,auStack_16),0x53326);
  do {
    uVar9 = uVar10;
    copy_to_ER12((short)uVar9,uVar6);
    uVar6 = (undefined2)((ulonglong)uVar9 >> 0x30);
    dec_bin_or_core((short)((ulonglong)uVar9 >> 0x20),uVar6);
    puVar3 = (undefined2 *)((ulonglong)uVar9 >> 0x20);
    uVar2 = puVar3[4];
    cVar12 = (char)((ushort)uVar2 >> 8);
    bVar11 = (byte)((ulonglong)uVar9 >> 0x10);
    if ((cVar12 != '\x01') && (cVar12 != '\x06')) {
      uVar8 = (undefined)((ushort)uVar6 >> 8);
      uVar6 = CONCAT11(uVar8,0x87);
      if (((char)((ulonglong)uVar9 >> 0x18) != '\0') && (2 < bVar11)) {
        uVar6 = CONCAT11(uVar8,0x88);
      }
      if ((byte)uVar2 < (byte)uVar6) {
LAB_rom_016788:
        cVar12 = is_edit_locked();
        uVar10 = uVar9;
        if (cVar12 != '\0') {
          uVar13 = (undefined6)((ulonglong)uVar9 >> 0x10);
          uVar10 = CONCAT62(uVar13,(short)uVar9 + 0x32);
          if ((char)((ulonglong)uVar9 >> 0x18) != '\0') {
            uVar10 = CONCAT62(uVar13,(short)uVar9 + 0x28);
          }
        }
        puVar7 = (undefined2 *)((ulonglong)uVar10 >> 0x30);
        puVar3 = dec_copy_ret((undefined2 *)uVar10,puVar7);
        bVar4 = (byte)((ushort)puVar3 >> 8);
        if (1 < bVar5) {
          dec_inc5((undefined2 *)((ulonglong)uVar10 >> 0x30), (uintptr_t)0)
                         CONCAT11((char)((ushort)puVar7 >> 8),bVar5));
          bVar4 = extraout_R1;
        }
        goto LAB_rom_016782;
      }
      if ((byte)uVar2 == (byte)uVar6) {
        uVar2 = *puVar3;
        if (((byte)uVar2 < 5) && (((byte)uVar2 < 4 || ((byte)((ushort)uVar2 >> 8) < 0x9a))))
        goto LAB_rom_016788;
      }
    }
    bVar4 = (byte)((ushort)uVar2 >> 8);
    cVar12 = bVar11 - 1;
    uVar10 = CONCAT53((int5)((ulonglong)uVar9 >> 0x18),CONCAT12(cVar12,(short)uVar9 + -10));
    if (cVar12 == '\0') {
      *(byte *)((short)((ulonglong)uVar9 >> 0x30) + 9) = bVar5;
LAB_rom_016782:
      return (ushort)bVar4 << 8;
    }
  } while( true );
}

/**
 * @brief 以 0x1CE2C 运算后的 5 位十进制调整版本（与 0x16712 对称）
 * @addr 0x1671C
 * @module bcd
 * @proto void dec_op5_bcd(undefined2* a, undefined2 b)
 * @confidence likely
 * @note 以 0x1CE2C 运算后的 5 位十进制调整版本（与 0x16712 对称）。
 * @tag bcd
 */
int dec_op5_bcd(undefined2* a, undefined2 b)

{
  int sVar1;
  undefined2 uVar2;
  byte bVar4;
  undefined2 *puVar3;
  byte extraout_R1;
  byte bVar5;
  undefined2 uVar6;
  undefined uVar8;
  undefined2 *puVar7;
  byte bVar11;
  undefined8 uVar9;
  char cVar12;
  undefined8 uVar10;
  undefined local_16 [10];
  undefined8 uStack_c;
  undefined6 uVar13;
  
  uStack_c._6_2_ = a;
  sVar1 = decm_bin_div2(a,b);
  if ((char)sVar1 != '\0') {
    return sVar1;
  }
  bVar5 = *(byte *)(uStack_c._6_2_ + 9);
  uVar6 = CONCAT11((char)((ushort)b >> 8),bVar5 - 5);
  if (4 < bVar5) {
    *(byte *)(uStack_c._6_2_ + 9) = bVar5 - 5;
  }
  uVar10 = CONCAT44(CONCAT22(uStack_c._6_2_,local_16),0x53326);
  do {
    uVar9 = uVar10;
    copy_to_ER12((short)uVar9,uVar6);
    uVar6 = (undefined2)((ulonglong)uVar9 >> 0x30);
    dec_bin_or_core((short)((ulonglong)uVar9 >> 0x20),uVar6);
    puVar3 = (undefined2 *)((ulonglong)uVar9 >> 0x20);
    uVar2 = puVar3[4];
    cVar12 = (char)((ushort)uVar2 >> 8);
    bVar11 = (byte)((ulonglong)uVar9 >> 0x10);
    if ((cVar12 != '\x01') && (cVar12 != '\x06')) {
      uVar8 = (undefined)((ushort)uVar6 >> 8);
      uVar6 = CONCAT11(uVar8,0x87);
      if (((char)((ulonglong)uVar9 >> 0x18) != '\0') && (2 < bVar11)) {
        uVar6 = CONCAT11(uVar8,0x88);
      }
      if ((byte)uVar2 < (byte)uVar6) {
LAB_rom_016788:
        cVar12 = is_edit_locked();
        uVar10 = uVar9;
        if (cVar12 != '\0') {
          uVar13 = (undefined6)((ulonglong)uVar9 >> 0x10);
          uVar10 = CONCAT62(uVar13,(short)uVar9 + 0x32);
          if ((char)((ulonglong)uVar9 >> 0x18) != '\0') {
            uVar10 = CONCAT62(uVar13,(short)uVar9 + 0x28);
          }
        }
        puVar7 = (undefined2 *)((ulonglong)uVar10 >> 0x30);
        puVar3 = dec_copy_ret((undefined2 *)uVar10,puVar7);
        bVar4 = (byte)((ushort)puVar3 >> 8);
        if (1 < bVar5) {
          dec_inc5((undefined2 *)((ulonglong)uVar10 >> 0x30), (uintptr_t)0)
                         CONCAT11((char)((ushort)puVar7 >> 8),bVar5));
          bVar4 = extraout_R1;
        }
        goto LAB_rom_016782;
      }
      if ((byte)uVar2 == (byte)uVar6) {
        uVar2 = *puVar3;
        if (((byte)uVar2 < 5) && (((byte)uVar2 < 4 || ((byte)((ushort)uVar2 >> 8) < 0x9a))))
        goto LAB_rom_016788;
      }
    }
    bVar4 = (byte)((ushort)uVar2 >> 8);
    cVar12 = bVar11 - 1;
    uVar10 = CONCAT53((int5)((ulonglong)uVar9 >> 0x18),CONCAT12(cVar12,(short)uVar9 + -10));
    if (cVar12 == '\0') {
      *(byte *)((short)((ulonglong)uVar9 >> 0x30) + 9) = bVar5;
LAB_rom_016782:
      return (ushort)bVar4 << 8;
    }
  } while( true );
}

