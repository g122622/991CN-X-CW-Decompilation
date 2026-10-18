/*
 * BCD 浮点库 / 10ccc_dec_xy_pair_arith.c
 * 地址范围: 0x10CCC - 0x1141C
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 对 (a,b) 先做 0x10DC2 加法，再按 0x179F4 的操作数类型调用0x188…
 * @addr 0x10CCC
 * @module bcd
 * @proto void dec_xy_pair_arith(undefined2* a, undefined2* b)
 * @confidence likely
 * @note 对 (a,b) 先做 0x10DC2 加法，再按 0x179F4
 *       的操作数类型调用0x1887A/0x18858/0x1881C，最后以 0x179E2 做二进制/BCD 混合运算。
 * @tag bcd
 */
int dec_xy_pair_arith(undefined2* a, undefined2* b)

{
  int cVar1;
  undefined uVar2;
  ushort uVar3;
  undefined2 uVar4;
  undefined extraout_R1;
  undefined2 *puVar5;
  undefined2 *unaff_ER4;
  ushort *puVar7;
  ulonglong in_QR8;
  ulonglong uVar6;
  
  uVar6 = in_QR8 & 0xffffffffffff;
  dec_add_self(a,b);
  uVar2 = (undefined)((ushort)b >> 8);
  cVar1 = dec_load_strip_flag((undefined2 *)(uVar6 >> 0x10));
  uVar4 = CONCAT11(uVar2,cVar1);
  if (cVar1 == '\x01') {
    uVar4 = dec_add_slot(unaff_ER4,uVar4);
    return uVar4;
  }
  if (cVar1 == '\x02') {
    uVar4 = dec_xy_sub(unaff_ER4,uVar4);
    return uVar4;
  }
  if (cVar1 == '\x03') {
    uVar4 = dec_xy_add(unaff_ER4,uVar4);
    return uVar4;
  }
  dec_bin_op_d05c((short)(uVar6 >> 0x20),(short)(uVar6 >> 0x10));
  uVar3 = dec_type_of((undefined *)(uVar6 >> 0x20));
  if ((byte)uVar3 < 0x30) {
    uVar3 = dec_type_of((undefined *)(uVar6 >> 0x10));
    if ((byte)uVar3 < 0x30) {
      if (((byte)uVar3 != 0x20) &&
         (3 < (byte)((ushort)*(undefined2 *)((short)(uVar6 >> 0x20) + 8) >> 8))) {
        puVar5 = (undefined2 *)(uVar6 >> 0x10);
        dec_copy((undefined2 *)uVar6,puVar5);
        uVar4 = eval_recip2(puVar5);
        if ((char)uVar4 == '\0') {
          dec_copy((undefined2 *)(uVar6 >> 0x10),(undefined2 *)uVar6);
        }
      }
      uVar2 = decm_ln((short)(uVar6 >> 0x20),(undefined2 *)(uVar6 >> 0x10));
      puVar7 = (ushort *)(uVar6 >> 0x20);
      goto LAB_rom_010d38;
    }
  }
  puVar7 = (ushort *)(uVar6 >> 0x20);
  dec_set_special(puVar7,3);
  uVar2 = 0x30;
LAB_rom_010d38:
  dec_copy(unaff_ER4,puVar7);
  return CONCAT11(extraout_R1,uVar2);
}

/**
 * @brief 对 a、b 各复制一份并调用 0x1D780（BCD 加法核心）自加
 * @addr 0x10DC2
 * @module bcd
 * @proto void dec_add_self(undefined2* a, undefined2* b)
 * @confidence likely
 * @note 对 a、b 各复制一份并调用 0x1D780（BCD 加法核心）自加。
 * @tag bcd
 */
int dec_add_self(undefined2* a, undefined2* b)

{
  short unaff_ER14;
  
  dec_copy((undefined2 *)(unaff_ER14 + -10),a);
  dec_bin_init((undefined2 *)(unaff_ER14 + -10),a);
  dec_copy((undefined2 *)(unaff_ER14 + -0x14),b);
  dec_bin_init((undefined2 *)(unaff_ER14 + -0x14),b);
  return 0;
}

/**
 * @brief 把 r 复制到 0xB4 处调用块的参数槽
 * @addr 0x10F1A
 * @module bcd
 * @proto int dec_copy_to_slot(undefined2* r)
 * @confidence likely
 * @note 把 r 复制到 0xB4 处调用块的参数槽。
 * @tag bcd
 */
int dec_copy_to_slot(undefined2* r)

{
  short unaff_ER14;
  
  dec_cmp_ex((undefined2 *)(unaff_ER14 + -0xb4),r);
  return 0;
}

/**
 * @brief 按 10 字节/组把局部寄存器区复制到 0xD392 起的槽位
 * @addr 0x10F28
 * @module bcd
 * @proto int dec_copy_10_slot(void)
 * @confidence likely
 * @note 按 10 字节/组把局部寄存器区复制到 0xD392 起的槽位。
 * @tag bcd
 */
int dec_copy_10_slot(void)

{
  char cVar1;
  undefined8 *puVar2;
  undefined5 uVar3;
  undefined8 *puVar4;
  char cVar5;
  undefined8 in_QR8;
  
  uVar3 = CONCAT14(10,(int)CONCAT62(0xd392,(short)((ulonglong)in_QR8 >> 0x30) + -0xaa));
  do {
    puVar4 = (undefined8 *)((uint5)uVar3 >> 0x10);
    puVar2 = (undefined8 *)uVar3;
    *puVar2 = *puVar4;
    cVar1 = (char)((uint5)uVar3 >> 0x20);
    cVar5 = cVar1 + -1;
    uVar3 = CONCAT14(cVar5,(int)CONCAT32((int3)(CONCAT14(cVar1,CONCAT22(puVar4 + 1,puVar2)) >> 0x10)
                                         ,puVar2 + 1));
  } while (cVar5 != '\0');
  return 0;
}

/**
 * @brief 同 0x10F28，但先置 0xD142=1（带符号/激活标记）
 * @addr 0x10F3A
 * @module bcd
 * @proto int dec_copy_10_slot_ng(void)
 * @confidence likely
 * @note 同 0x10F28，但先置 0xD142=1（带符号/激活标记）。
 * @tag bcd
 */
int dec_copy_10_slot_ng(void)

{
  char cVar1;
  undefined8 *puVar2;
  undefined5 uVar3;
  undefined8 *puVar4;
  char cVar5;
  undefined8 in_QR8;
  
  stat_sel = 1;
  uVar3 = CONCAT14(10,CONCAT22((short)((ulonglong)in_QR8 >> 0x30) + -0xaa,&stat_data));
  do {
    puVar4 = (undefined8 *)((uint5)uVar3 >> 0x10);
    puVar2 = (undefined8 *)uVar3;
    *puVar2 = *puVar4;
    cVar1 = (char)((uint5)uVar3 >> 0x20);
    cVar5 = cVar1 + -1;
    uVar3 = CONCAT14(cVar5,(int)CONCAT32((int3)(CONCAT14(cVar1,CONCAT22(puVar4 + 1,puVar2)) >> 0x10)
                                         ,puVar2 + 1));
  } while (cVar5 != '\0');
  return 0;
}

/**
 * @brief 把 ROM 0x353A + idx*10 的 10 字节 BCD 常量复制到 0x3C 处…
 * @addr 0x11088
 * @module bcd
 * @proto void dec_copy_const(byte idx)
 * @confidence likely
 * @note 把 ROM 0x353A + idx*10 的 10 字节 BCD 常量复制到 0x3C 处调用块参数槽。
 * @tag bcd
 */
int dec_copy_const(byte idx)

{
  short unaff_ER14;
  
  dec_copy((undefined2 *)(unaff_ER14 + -0x3c),(undefined2 *)((idx & 0xff) * 10 + 0x353a));
  return 0;
}

/**
 * @brief 乘方/乘除混合序列 A
 * @addr 0x111BC
 * @module bcd
 * @proto int dec_op_pow_mul(void)
 * @confidence likely
 * @note 乘方/乘除混合序列 A：x^y 与乘积，结果写回局部 BCD 槽。
 * @tag bcd
 */
int dec_op_pow_mul(void)

{
  short sVar1;
  undefined2 *puVar2;
  undefined2 *puVar3;
  short unaff_ER14;
  
  puVar3 = (undefined2 *)(unaff_ER14 + -0x14);
  puVar2 = (undefined2 *)(unaff_ER14 + -0x1e);
  sVar1 = unaff_ER14 + -0x28;
  dec_op_pow_core();
  dec_copy(puVar3,(undefined2 *)(unaff_ER14 + -0xaa));
  dec_bin_pow_core(puVar3,unaff_ER14 + -0xb4);
  dec_copy(puVar2,(undefined2 *)(unaff_ER14 + -0x8c));
  dec_bin_pow_core(puVar2,unaff_ER14 + -0x96);
  dec_bin_mul_core(puVar3,puVar2);
  dec_bin_and_core(puVar3,sVar1);
  dec_cmp_ex(puVar3,sVar1);
  dec_copy((undefined2 *)(unaff_ER14 + -200),puVar3);
  bcd_type((byte *)puVar3);
  return 0;
}

/**
 * @brief 公共片段
 * @addr 0x11228
 * @module bcd
 * @proto void dec_op_pow_core(void)
 * @confidence likely
 * @note 公共片段：对 0xB4/0xA0 处操作数做 0x1C86C（乘方族）与 0x1CA7E（三角函数）运算。
 * @tag bcd
 */
int dec_op_pow_core(void)

{
  undefined2 *puVar1;
  undefined2 *unaff_ER8;
  undefined2 *unaff_ER12;
  short unaff_ER14;
  
  dec_copy(unaff_ER8,(undefined2 *)(unaff_ER14 + -0xb4));
  dec_bin_pow_core(unaff_ER8,unaff_ER14 + -0xa0);
  puVar1 = (undefined2 *)(unaff_ER14 + -0x96);
  dec_copy(unaff_ER12,puVar1);
  decm_pow(unaff_ER12,puVar1);
  dec_bin_mul_core(unaff_ER8,unaff_ER12);
  return 0;
}

/**
 * @brief 乘方/乘除混合序列 B
 * @addr 0x1125E
 * @module bcd
 * @proto int dec_op_pow_mul_b(void)
 * @confidence likely
 * @note 乘方/乘除混合序列 B：与 A 对称（交换 0x8C/0xAA 操作数）。
 * @tag bcd
 */
int dec_op_pow_mul_b(void)

{
  short sVar1;
  undefined2 *puVar2;
  undefined2 *puVar3;
  short unaff_ER14;
  
  puVar3 = (undefined2 *)(unaff_ER14 + -0x14);
  puVar2 = (undefined2 *)(unaff_ER14 + -0x1e);
  sVar1 = unaff_ER14 + -0x28;
  dec_op_pow_core();
  dec_copy(puVar3,(undefined2 *)(unaff_ER14 + -0x8c));
  dec_bin_pow_core(puVar3,unaff_ER14 + -0xa0);
  dec_copy(puVar2,(undefined2 *)(unaff_ER14 + -0xaa));
  dec_bin_pow_core(puVar2,unaff_ER14 + -0x96);
  dec_bin_mul_core(puVar3,puVar2);
  dec_bin_and_core(puVar3,sVar1);
  dec_cmp_ex(puVar3,sVar1);
  dec_copy((undefined2 *)(unaff_ER14 + -0xbe),puVar3);
  bcd_type((byte *)puVar3);
  return 0;
}

/**
 * @brief 混合运算序列
 * @addr 0x1141C
 * @module bcd
 * @proto int dec_op_mixed(void)
 * @confidence likely
 * @note 混合运算序列：以常数 2 与局部 BCD 槽做乘方并相加。
 * @tag bcd
 */
int dec_op_mixed(void)

{
  ushort *puVar1;
  undefined2 *puVar2;
  short unaff_ER14;
  
  puVar2 = (undefined2 *)(unaff_ER14 + -0x14);
  puVar1 = (ushort *)(unaff_ER14 + -0x1e);
  dec_copy(puVar2,(undefined2 *)(unaff_ER14 + -0xbe));
  dec_set_uint_small(puVar1,2);
  dec_bin_pow_core(puVar1,unaff_ER14 + -200);
  dec_bin_pow_core(puVar1,unaff_ER14 + -0x50);
  dec_bin_mul_core(puVar2,puVar1);
  dec_cmp_ex(puVar2,puVar1);
  dec_copy((undefined2 *)(unaff_ER14 + -0xbe),puVar2);
  bcd_type((byte *)puVar2);
  return 0;
}

