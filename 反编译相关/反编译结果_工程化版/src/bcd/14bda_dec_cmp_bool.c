/*
 * BCD 浮点库 / 14bda_dec_cmp_bool.c
 * 地址范围: 0x14BDA - 0x15320
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 复制 a 并比较（返回比较结果）
 * @addr 0x14BDA
 * @module bcd
 * @proto undefined2* dec_cmp_bool(undefined2* a)
 * @confidence strong
 * @note 复制 a 并比较（返回比较结果）。
 * @tag bcd
 */
undefined2* dec_cmp_bool(undefined2* a)

{
  undefined2 *puVar1;
  undefined2 *puVar2;
  uint uVar3;
  undefined2 auStack_1a [5];
  undefined auStack_10 [12];
  
  uVar3 = ZEXT24(auStack_10);
  dec_copy(auStack_1a,a);
  dec_cmp_signed(auStack_1a,a);
  puVar1 = (undefined2 *)((short)(uVar3 >> 0x10) + -0x14);
  puVar2 = (undefined2 *)uVar3;
  dec_copy(puVar1,puVar2);
  dec_cmp_signed(puVar1,puVar2);
  dec_to_string(auStack_1a,puVar1);
  return;
}

/**
 * @brief 以 a 与外部操作数做 0x1DA7A 比较，必要时交换并调用 0x1D654（带符号比较收…
 * @addr 0x14C1C
 * @module bcd
 * @proto undefined2 dec_cmp_swap(undefined2* a)
 * @confidence likely
 * @note 以 a 与外部操作数做 0x1DA7A 比较，必要时交换并调用 0x1D654（带符号比较收尾）。
 * @tag bcd
 */
undefined2 dec_cmp_swap(undefined2* a)

{
  undefined2 *puVar1;
  undefined2 *puVar2;
  uint uVar3;
  undefined2 auStack_1a [5];
  undefined auStack_10 [12];
  
  uVar3 = ZEXT24(auStack_10);
  dec_copy(auStack_1a,a);
  dec_cmp_signed(auStack_1a,a);
  puVar1 = (undefined2 *)((short)(uVar3 >> 0x10) + -0x14);
  puVar2 = (undefined2 *)uVar3;
  dec_copy(puVar1,puVar2);
  dec_cmp_signed(puVar1,puVar2);
  dec_round_scaled(auStack_1a,puVar1);
  return;
}

/**
 * @brief 对两个 BCD 槽执行 0x1CF68（除法）后收尾复制
 * @addr 0x1529E
 * @module bcd
 * @proto void dec_div_slots(void)
 * @confidence likely
 * @note 对两个 BCD 槽执行 0x1CF68（除法）后收尾复制。
 * @tag bcd
 */
int dec_div_slots(void)

{
  undefined2 *unaff_ER4;
  undefined2 *unaff_ER8;
  
  dec_bin_div(unaff_ER4,unaff_ER8);
  copy_from_ER2_to_ER8();
  return 0;
}

/**
 * @brief d 除以参数复制槽中的操作数（0x1CF68），再调用 0x1909A
 * @addr 0x152B2
 * @module bcd
 * @proto void dec_div_slot_const(undefined2* d)
 * @confidence likely
 * @note d 除以参数复制槽中的操作数（0x1CF68），再调用 0x1909A。
 * @tag bcd
 */
int dec_div_slot_const(undefined2* d)

{
  short unaff_ER6;
  undefined2 *unaff_ER8;
  
  dec_bin_div(unaff_ER8,d);
  dec_add_or_round(unaff_ER8,(undefined2 *)(unaff_ER6 + 0x1e));
  return 0;
}

/**
 * @brief 以 *p 与常量 1.0（0x1B76）比较，空操作返回
 * @addr 0x152C8
 * @module bcd
 * @proto void dec_cmp_Y_one(undefined2* p)
 * @confidence strong
 * @note 以 *p 与常量 1.0（0x1B76）比较，空操作返回。
 * @tag bcd
 */
int dec_cmp_Y_one(undefined2* p)

{
  dec_add_or_round(p,(undefined2 *)0x1b76);
  return 0;
}

/**
 * @brief 构造操作数 0x??1B 并调用 0x1CF90（乘方族）
 * @addr 0x152D4
 * @module bcd
 * @proto void dec_pow_slots(undefined2* a)
 * @confidence likely
 * @note 构造操作数 0x??1B 并调用 0x1CF90（乘方族）。
 * @tag bcd
 */
int dec_pow_slots(undefined2* a)

{
  undefined2 *unaff_ER4;
  undefined2 *unaff_ER8;
  
  dec_set_from_fmt(unaff_ER8,CONCAT11((char)((ushort)a >> 8),0x1b));
  dec_bin_pow(unaff_ER4,unaff_ER8);
  return 0;
}

/**
 * @brief 以 ROM 常量 0x1B76 调用 0x1CF90（乘方族）
 * @addr 0x152E4
 * @module bcd
 * @proto void dec_pow_const_1b76(void)
 * @confidence likely
 * @note 以 ROM 常量 0x1B76 调用 0x1CF90（乘方族）。
 * @tag bcd
 */
int dec_pow_const_1b76(void)

{
  undefined2 *unaff_ER12;
  
  dec_bin_pow(unaff_ER12,(undefined2 *)0x1b76);
  return 0;
}

/**
 * @brief 以槽位操作数调用 0x1CF90（乘方族）
 * @addr 0x152F0
 * @module bcd
 * @proto void dec_pow_slot_const(void)
 * @confidence likely
 * @note 以槽位操作数调用 0x1CF90（乘方族）。
 * @tag bcd
 */
int dec_pow_slot_const(void)

{
  short unaff_ER6;
  undefined2 *unaff_ER8;
  
  dec_bin_pow(unaff_ER8,(undefined2 *)(unaff_ER6 + 0x1e));
  return 0;
}

/**
 * @brief 调用二元乘方 0x1CF90（左操作数在 ER10，右操作数在 ER2）
 * @addr 0x152FA
 * @module bcd
 * @proto void dec_pow_ER10(void)
 * @confidence strong
 * @note 调用二元乘方 0x1CF90（左操作数在 ER10，右操作数在 ER2）。
 * @tag bcd
 */
int dec_pow_ER10(void)

{
  undefined2 *in_ER2;
  undefined2 *unaff_ER10;
  
  dec_bin_pow(unaff_ER10,in_ER2);
  return 0;
}

/**
 * @brief 把 src 复制到调用块 +0x28 的槽
 * @addr 0x15302
 * @module bcd
 * @proto void copy_to_slot28(undefined2* src)
 * @confidence verified
 * @note 把 src 复制到调用块 +0x28 的槽。
 * @tag bcd
 */
int copy_to_slot28(undefined2* _a1)

{
  undefined2 *in_ER2;
  short unaff_ER10;
  
  dec_copy((undefined2 *)(unaff_ER10 + 0x28),in_ER2);
  return 0;
}

/**
 * @brief 复制 dst 的下一个 10 字节单元（dst+10）
 * @addr 0x1530C
 * @module bcd
 * @proto void dec_copy_step(undefined2* dst)
 * @confidence verified
 * @note 复制 dst 的下一个 10 字节单元（dst+10）。
 * @tag bcd
 */
int dec_copy_step(undefined2* _a1)

{
  undefined2 *in_ER0;
  short unaff_ER6;
  
  dec_copy(in_ER0,(undefined2 *)(unaff_ER6 + 10));
  return 0;
}

/**
 * @brief X ← X × *p
 * @addr 0x15316
 * @module bcd
 * @proto int dec_mul_ER4(undefined2* p)
 * @confidence strong
 * @note X ← X × *p：以 ER4 中的左操作数调用二元乘法 0x1CF54。
 * @tag bcd
 */
int dec_mul_ER4(undefined2* p)

{
  undefined2 *unaff_ER4;
  
  dec_bin_mul(unaff_ER4,p);
  return 0;
}

/**
 * @brief a 与调用块 +0x3C 的槽做 0x1909A 运算
 * @addr 0x15320
 * @module bcd
 * @proto int call_1909a_slot(undefined2* a)
 * @confidence likely
 * @note a 与调用块 +0x3C 的槽做 0x1909A 运算。
 * @tag bcd
 */
int call_1909a_slot(undefined2* a)

{
  short unaff_ER6;
  
  dec_add_or_round(a,(undefined2 *)(unaff_ER6 + 0x3c));
  return 0;
}

