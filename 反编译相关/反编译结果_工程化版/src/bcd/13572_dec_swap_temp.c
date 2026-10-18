/*
 * BCD 浮点库 / 13572_dec_swap_temp.c
 * 地址范围: 0x13572 - 0x13CD8
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 交换 0xD752 与 0xD6BC 两个 BCD 暂存单元
 * @addr 0x13572
 * @module bcd
 * @proto void dec_swap_temp(void)
 * @confidence strong
 * @note 交换 0xD752 与 0xD6BC 两个 BCD 暂存单元。
 * @tag bcd
 */
int dec_swap_temp(void)

{
  dec_copy_ret((undefined2 *)0xd752,(undefined2 *)0xd6bc);
  return 0;
}

/**
 * @brief 比较路径 2
 * @addr 0x13584
 * @module bcd
 * @proto void dec_cmp_path2(void)
 * @confidence likely
 * @note 比较路径 2：以 0xD752/0xD6BC 为操作数调用 0x1DA7A/0x1D620（0x1369A 的另一半）。
 * @tag bcd
 */
int dec_cmp_path2(void)

{
  undefined2 *puVar1;
  undefined2 uVar2;
  undefined2 *puVar3;
  undefined8 in_QR8;
  undefined8 uVar4;
  
  puVar1 = (undefined2 *)((ulonglong)in_QR8 >> 0x30);
  uVar4 = CONCAT62(CONCAT42(CONCAT22(puVar1,puVar1 + 5),puVar1 + 10),0xd6bc);
  puVar1 = dec_copy_ret((undefined2 *)0xd752,puVar1);
  puVar1 = dec_copy_ret(puVar1 + 0x14,(undefined2 *)((ulonglong)uVar4 >> 0x20));
  puVar3 = (undefined2 *)((ulonglong)uVar4 >> 0x10);
  dec_copy_ret(puVar1 + 0x14,puVar3);
  dec_cmp_signed((short)((ulonglong)uVar4 >> 0x30),puVar3);
  dec_cmp_signed((short)((ulonglong)uVar4 >> 0x20),puVar3);
  dec_cmp_signed((short)((ulonglong)uVar4 >> 0x10),puVar3);
  uVar2 = dec_to_string((short)((ulonglong)uVar4 >> 0x30),(undefined2 *)((ulonglong)uVar4 >> 0x20))
  ;
  puVar1 = (undefined2 *)((ulonglong)uVar4 >> 0x10);
  if ((char)uVar2 == '\x04') {
    uVar2 = dec_to_string((short)((ulonglong)uVar4 >> 0x20),puVar1);
    puVar1 = (undefined2 *)uVar4;
    if ((char)uVar2 == '\x02') {
      dec_copy_ret((undefined2 *)0xd77a,puVar1);
      uVar2 = dec_to_string((short)((ulonglong)uVar4 >> 0x30), (uintptr_t)0)
                             (undefined2 *)((ulonglong)uVar4 >> 0x10));
      if ((char)uVar2 == '\x02') {
        puVar1 = (undefined2 *)((short)uVar4 + 10);
        puVar3 = dec_copy_ret((undefined2 *)0xd752,puVar1);
        puVar3 = puVar3 + 0x28;
      }
      else {
        puVar1 = (undefined2 *)((short)uVar4 + 10);
        puVar3 = dec_copy_ret((undefined2 *)0xd7a2,puVar1);
        puVar3 = puVar3 + -0x28;
      }
    }
    else {
      puVar3 = dec_copy_ret((undefined2 *)0xd7a2,puVar1);
      puVar1 = puVar1 + 5;
      puVar3 = dec_copy_ret(puVar3 + -0x14,puVar1);
      puVar3 = puVar3 + -0x14;
    }
  }
  else {
    uVar2 = dec_to_string((short)((ulonglong)uVar4 >> 0x30),puVar1);
    puVar1 = (undefined2 *)uVar4;
    if ((char)uVar2 == '\x02') {
      dec_copy_ret((undefined2 *)0xd752,puVar1);
      uVar2 = dec_to_string((short)((ulonglong)uVar4 >> 0x20), (uintptr_t)0)
                             (undefined2 *)((ulonglong)uVar4 >> 0x10));
      puVar1 = (undefined2 *)uVar4;
      if ((char)uVar2 == '\x02') {
        puVar3 = dec_copy_ret((undefined2 *)0xd752,puVar1);
        puVar1 = puVar1 + 5;
        puVar3 = dec_copy_ret(puVar3 + 0x14,puVar1);
        puVar3 = puVar3 + 0x14;
      }
      else {
        puVar1 = puVar1 + 5;
        puVar3 = dec_copy_ret((undefined2 *)0xd7a2,puVar1);
        puVar3 = puVar3 + -0x14;
      }
    }
    else {
      puVar3 = dec_copy_ret((undefined2 *)0xd7a2,puVar1);
      puVar1 = puVar1 + 5;
      puVar3 = dec_copy_ret(puVar3 + -0x28,puVar1);
      puVar3 = puVar3 + 0x14;
    }
  }
  dec_copy_ret(puVar3,puVar1 + 5);
  return 0;
}

/**
 * @brief 比较路径 1
 * @addr 0x1369A
 * @module bcd
 * @proto void dec_cmp_path1(void)
 * @confidence likely
 * @note 比较路径 1：以 0xD752 与 0xD6BC 为操作数调用
 *       0x1DA7A/0x1D620，按结果调整操作数槽（0x13584 的另一半）。
 * @tag bcd
 */
int dec_cmp_path1(void)

{
  undefined2 *puVar1;
  undefined2 uVar2;
  undefined2 *puVar3;
  undefined8 in_QR8;
  undefined8 uVar4;
  
  puVar1 = (undefined2 *)((ulonglong)in_QR8 >> 0x30);
  uVar4 = CONCAT62(CONCAT42(CONCAT22(puVar1,puVar1 + 5),0xd6bc),0xd752);
  puVar1 = dec_copy_ret((undefined2 *)0xd752,puVar1);
  puVar3 = (undefined2 *)((ulonglong)uVar4 >> 0x20);
  dec_copy_ret(puVar1 + 0x14,puVar3);
  dec_cmp_signed((short)((ulonglong)uVar4 >> 0x30),puVar3);
  dec_cmp_signed((short)((ulonglong)uVar4 >> 0x20),puVar3);
  uVar2 = dec_to_string((short)((ulonglong)uVar4 >> 0x30),(undefined2 *)((ulonglong)uVar4 >> 0x20))
  ;
  puVar1 = (undefined2 *)((ulonglong)uVar4 >> 0x10);
  if ((char)uVar2 == '\x04') {
    puVar3 = dec_copy_ret((undefined2 *)uVar4 + 0x14,puVar1);
    puVar3 = puVar3 + -0x14;
  }
  else {
    puVar3 = dec_copy_ret((undefined2 *)uVar4,puVar1);
    puVar3 = puVar3 + 0x14;
  }
  dec_copy_ret(puVar3,puVar1 + 5);
  return 0;
}

/**
 * @brief 开方核心
 * @addr 0x13858
 * @module bcd
 * @proto void dec_nth_root(void)
 * @confidence likely
 * @note 开方核心：取 0xD310 常数（2）、按 0x1CF68 迭代试乘，成功后经 0xF250与 0x1E6D0 收尾。
 * @tag bcd
 */
int dec_nth_root(void)

{
  int cVar1;
  ushort uVar2;
  byte extraout_R1;
  undefined2 *puVar3;
  undefined2 uVar4;
  longlong lVar5;
  byte bVar6;
  ushort auStack_24 [4];
  byte local_1c;
  undefined2 auStack_1a [11];
  
  uVar4 = 0xd310;
  dec_copy(auStack_24,(undefined2 *)0xd310);
  lVar5 = (ulonglong)local_1c << 0x20;
  set_constant_99((short)auStack_24);
  do {
    puVar3 = auStack_1a;
    dec_set_from_fmt(puVar3,CONCAT11((char)((ushort)uVar4 >> 8),(char)((ulonglong)lVar5 >> 0x20)));
    set_constant_99((short)puVar3);
    cVar1 = dec_bin_div(auStack_24,puVar3);
    if (cVar1 == '\0') {
      bVar6 = (auStack_24 == (ushort *)0x0) << 6;
      int_to_dec(auStack_24,puVar3);
      if ((bVar6 >> 6 & 1) != 1) {
        set_constant_99((short)auStack_24);
        uVar4 = 0x33b2;
        pow_ER4_ER2();
        uVar2 = interpolate_18();
        hash_mix32(uVar2,(byte)uVar4);
        matrix_cell_scale(uVar4);
        uVar4 = 0x33b2;
        dec_bin_and(auStack_24,(undefined2 *)0x33b2);
        decm_round10(auStack_24,uVar4);
        copy_ER8_from_ER4();
        uVar4 = 3;
        dec_bcd_to_bin(auStack_24,3);
        dec_unary_cos(auStack_24,uVar4);
        dec_bcd_to_bin(auStack_24,0xfffd);
        dec_copy_a((uintptr_t)0);
        return (ushort)extraout_R1 << 8;
      }
    }
    uVar4 = CONCAT11((char)((ushort)puVar3 >> 8),1);
    dec_set_uint_small(auStack_24,1);
    set_constant_99((short)auStack_24);
  } while( true );
}

/**
 * @brief 开方的操作数准备
 * @addr 0x1391A
 * @module bcd
 * @proto ushort dec_root_prep(undefined2* a, undefined2 b)
 * @confidence likely
 * @note 开方的操作数准备：复制 a 到局部并按 0x1D900/0x1D620 处理符号/指数。
 * @tag bcd
 */
ushort dec_root_prep(undefined2* a, undefined2 b)

{
  undefined2 uVar1;
  undefined2 *puVar2;
  ushort uVar3;
  undefined2 *puVar4;
  longlong lVar5;
  ulonglong uVar6;
  undefined auStack_c [8];
  
  lVar5 = (ulonglong)CONCAT42((int)((ZEXT28(auStack_c) << 0x30) >> 0x20),a) << 0x10;
  uVar1 = dec_cmp(a,b);
  puVar2 = (undefined2 *)((short)((ulonglong)lVar5 >> 0x30) + -10);
  uVar6 = (ulonglong)CONCAT32((int3)(CONCAT14((char)uVar1,(int)lVar5) >> 0x10),puVar2);
  puVar4 = (undefined2 *)((ulonglong)lVar5 >> 0x10);
  dec_copy(puVar2,puVar4);
  uVar3 = dec_unary_cos((short)(uVar6 >> 0x10),puVar4);
  if (((char)(uVar6 >> 0x20) == '\x02') &&
     (uVar3 = dec_to_string((short)uVar6,(undefined2 *)(uVar6 >> 0x10)), (char)uVar3 != '\x01')) {
    uVar3 = dec_bin_or_core((short)(uVar6 >> 0x10),0x1b6c);
  }
  return uVar3 & 0xff00;
}

/**
 * @brief 调用 0x1CF90（乘方族）
 * @addr 0x139F2
 * @module bcd
 * @proto void pow_ER4_ER6(void)
 * @confidence verified
 * @note 调用 0x1CF90（乘方族）：ER4/ER6 操作数。
 * @tag bcd
 */
int pow_ER4_ER6(void)

{
  undefined2 *unaff_ER4;
  undefined2 *unaff_ER6;
  
  dec_bin_pow(unaff_ER4,unaff_ER6);
  return 0;
}

/**
 * @brief 调用 0x1CF90（乘方族）
 * @addr 0x139FA
 * @module bcd
 * @proto int pow_ER8_ER12(void)
 * @confidence verified
 * @note 调用 0x1CF90（乘方族）：ER8/ER12 操作数。
 * @tag bcd
 */
int pow_ER8_ER12(void)

{
  undefined2 *unaff_ER8;
  undefined2 *unaff_ER12;
  
  dec_bin_pow(unaff_ER8,unaff_ER12);
  return 0;
}

/**
 * @brief 调用 0x1CF90（乘方族）
 * @addr 0x13A06
 * @module bcd
 * @proto void pow_ER4_ER2(void)
 * @confidence verified
 * @note 调用 0x1CF90（乘方族）：操作数 in_ER2。
 * @tag bcd
 */
int pow_ER4_ER2(void)

{
  undefined2 *in_ER2;
  undefined2 *unaff_ER4;
  
  dec_bin_pow(unaff_ER4,in_ER2);
  return 0;
}

/**
 * @brief 把 ER4 的 10 字节复制到 ER8
 * @addr 0x13A0A
 * @module bcd
 * @proto void copy_ER8_from_ER4(void)
 * @confidence verified
 * @note 把 ER4 的 10 字节复制到 ER8。
 * @tag bcd
 */
int copy_ER8_from_ER4(void)

{
  undefined2 *unaff_ER4;
  undefined2 *unaff_ER8;
  
  dec_copy(unaff_ER8,unaff_ER4);
  return 0;
}

/**
 * @brief BCD 单元复制（0x1DA02 的薄封装）
 * @addr 0x13A12
 * @module bcd
 * @proto void dec_copy_a(undefined2* dst)
 * @confidence verified
 * @note BCD 单元复制（0x1DA02 的薄封装）。
 * @tag bcd
 */
int dec_copy_a(undefined2* _a1)

{
  undefined2 *unaff_ER4;
  undefined2 *unaff_ER10;
  
  dec_copy(unaff_ER10,unaff_ER4);
  return 0;
}

/**
 * @brief 整数转 BCD 单元
 * @addr 0x13A1E
 * @module bcd
 * @proto int int_to_dec(undefined2* dst, undefined2 v)
 * @confidence likely
 * @note 整数转 BCD 单元。
 * @tag bcd
 */
int int_to_dec(undefined2* dst, undefined2 v)

{
  dec_cmp(dst,v);
  return 0;
}

/**
 * @brief 调用 0x1D6A4 对当前操作数按 n 位舍入，返回 (高字节<<8)|n
 * @addr 0x13A90
 * @module bcd
 * @proto ushort dec_round_word(undefined n)
 * @confidence likely
 * @note 调用 0x1D6A4 对当前操作数按 n 位舍入，返回 (高字节<<8)|n。
 * @tag bcd
 */
ushort dec_round_word(undefined n)

{
  ushort uVar1;
  undefined8 in_QR8;
  
  uVar1 = dec_set_special((ushort *)((ulonglong)in_QR8 >> 0x10),n);
  return CONCAT11((char)(uVar1 >> 8),n);
}

/**
 * @brief 以原参数调用 0x13AF0
 * @addr 0x13B5E
 * @module bcd
 * @proto void call_13af0(undefined2 er0, undefined2 er2)
 * @confidence likely
 * @note 以原参数调用 0x13AF0。
 * @tag bcd
 */
int call_13af0(undefined2 er0, undefined2 er2)

{
  matrix_core_b(er0,er2);
  return 0;
}

/**
 * @brief 以原参数调用 0x13B6C
 * @addr 0x13BF2
 * @module bcd
 * @proto void call_13b6c(undefined2 er0, undefined2 er2)
 * @confidence likely
 * @note 以原参数调用 0x13B6C。
 * @tag bcd
 */
int call_13b6c(undefined2 er0, undefined2 er2)

{
  matrix_core_c(er0,er2);
  return 0;
}

/**
 * @brief 把 XR8 指向的单元设为特殊值并返回 v（0x1D6A4 的薄封装）
 * @addr 0x13CD8
 * @module bcd
 * @proto undefined2 dec_set_special_ret(byte v)
 * @confidence likely
 * @note 把 XR8 指向的单元设为特殊值并返回 v（0x1D6A4 的薄封装）。
 * @tag bcd
 */
undefined2 dec_set_special_ret(byte v)

{
  undefined8 in_QR8;
  
  dec_set_special((ushort *)((ulonglong)in_QR8 >> 0x10),v);
  return v;
}

