/*
 * BCD 浮点库 / 13f3e_dec_pair_copy.c
 * 地址范围: 0x13F3E - 0x143B4
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 把 ER6+ER8 处的 BCD 复制到 ER4+ER8 处并调用 0x1D730 写回结果
 * @addr 0x13F3E
 * @module bcd
 * @proto void dec_pair_copy(void)
 * @confidence verified
 * @note 把 ER6+ER8 处的 BCD 复制到 ER4+ER8 处并调用 0x1D730 写回结果。
 * @tag bcd
 */
int dec_pair_copy(void)

{
  undefined2 *puVar1;
  short unaff_ER4;
  short unaff_ER6;
  short unaff_ER8;
  
  puVar1 = (undefined2 *)(unaff_ER4 + unaff_ER8);
  dec_copy((undefined2 *)(unaff_ER6 + unaff_ER8),puVar1);
  dec_inc5((undefined2 *)(unaff_ER6 + unaff_ER8),puVar1);
  return 0;
}

/**
 * @brief 调用 0x13B5E 转换后按 0x13CD8 返回结果标志
 * @addr 0x13FF2
 * @module bcd
 * @proto byte dec_convert_check(void)
 * @confidence likely
 * @note 调用 0x13B5E 转换后按 0x13CD8 返回结果标志。
 * @tag bcd
 */
byte dec_convert_check(void)

{
  byte bVar1;
  undefined8 in_QR8;
  
  bVar1 = call_13af0((byte *)((ulonglong)in_QR8 >> 0x10), (uintptr_t)0)
                         *(byte **)((short)((ulonglong)in_QR8 >> 0x30) + -8));
  if (bVar1 != 0) {
    bVar1 = dec_set_special_ret(bVar1);
    return bVar1;
  }
  return 0;
}

/**
 * @brief 把 ER4+R8 处 BCD 复制到 ER12 后执行两次 0x14028 移位
 * @addr 0x14008
 * @module bcd
 * @proto void dec_shift_ratio(void)
 * @confidence likely
 * @note 把 ER4+R8 处 BCD 复制到 ER12 后执行两次 0x14028 移位。
 * @tag bcd
 */
int dec_shift_ratio(void)

{
  short unaff_ER4;
  byte unaff_R8;
  undefined2 *unaff_ER12;
  
  dec_copy(unaff_ER12,(undefined2 *)(unaff_ER4 + (ushort)unaff_R8));
  copy_slot_via_14386();
  copy_slot_via_14386();
  return 0;
}

/**
 * @brief 通过 0x14386 把当前操作数复制到槽位
 * @addr 0x14028
 * @module bcd
 * @proto void copy_slot_via_14386(void)
 * @confidence likely
 * @note 通过 0x14386 把当前操作数复制到槽位。
 * @tag bcd
 */
int copy_slot_via_14386(void)

{
  pow_ER12_ER2();
  return 0;
}

/**
 * @brief 百分数换算核心（R8..R11 为四组比例常量）
 * @addr 0x14034
 * @module bcd
 * @proto int dec_percent_chain(void)
 * @confidence likely
 * @note 百分数换算核心（R8..R11 为四组比例常量）：复制 R8 偏移操作数并乘/加。
 * @tag bcd
 */
int dec_percent_chain(void)

{
  short unaff_ER4;
  short unaff_ER6;
  byte unaff_R10;
  undefined2 *unaff_ER12;
  
  dec_copy_step2();
  pow_ER6_ER2();
  dec_copy(unaff_ER12,(undefined2 *)(unaff_ER4 + (ushort)unaff_R10));
  copy_slot_via_14386();
  dec_bin_mul((undefined2 *)(unaff_ER6 + 10),unaff_ER12);
  return 0;
}

/**
 * @brief 调用 0x1CF90（乘方族）
 * @addr 0x14378
 * @module bcd
 * @proto void pow_ER6_ER2(void)
 * @confidence verified
 * @note 调用 0x1CF90（乘方族）：操作数 in_ER2。
 * @tag bcd
 */
int pow_ER6_ER2(void)

{
  undefined2 *in_ER2;
  undefined2 *unaff_ER6;
  
  dec_bin_pow(unaff_ER6,in_ER2);
  return 0;
}

/**
 * @brief 调用 0x1CF90（乘方族）
 * @addr 0x14380
 * @module bcd
 * @proto void pow_ER8_ER2(void)
 * @confidence verified
 * @note 调用 0x1CF90（乘方族）：操作数 in_ER2。
 * @tag bcd
 */
int pow_ER8_ER2(void)

{
  undefined2 *in_ER2;
  undefined2 *unaff_ER8;
  
  dec_bin_pow(unaff_ER8,in_ER2);
  return 0;
}

/**
 * @brief 调用 0x1CF90（乘方族）
 * @addr 0x14386
 * @module bcd
 * @proto void pow_ER12_ER2(void)
 * @confidence verified
 * @note 调用 0x1CF90（乘方族）：操作数 in_ER2。
 * @tag bcd
 */
int pow_ER12_ER2(void)

{
  undefined2 *in_ER2;
  undefined2 *unaff_ER12;
  
  dec_bin_pow(unaff_ER12,in_ER2);
  return 0;
}

/**
 * @brief BCD 单元复制（另一处薄封装）
 * @addr 0x1438E
 * @module bcd
 * @proto void dec_copy_b(undefined2* dst)
 * @confidence verified
 * @note BCD 单元复制（另一处薄封装）。
 * @tag bcd
 */
int dec_copy_b(undefined2* _a1)

{
  undefined2 *unaff_ER6;
  undefined2 *unaff_ER10;
  
  dec_copy(unaff_ER10,unaff_ER6);
  return 0;
}

/**
 * @brief 把 ER4 的 10 字节复制到 ER6
 * @addr 0x14396
 * @module bcd
 * @proto void copy_ER6_from_ER4(void)
 * @confidence verified
 * @note 把 ER4 的 10 字节复制到 ER6。
 * @tag bcd
 */
int copy_ER6_from_ER4(void)

{
  undefined2 *unaff_ER4;
  undefined2 *unaff_ER6;
  
  dec_copy(unaff_ER6,unaff_ER4);
  return 0;
}

/**
 * @brief BCD 单元复制一步（ER2 为源）
 * @addr 0x1439E
 * @module bcd
 * @proto void dec_copy_step2(void)
 * @confidence likely
 * @note BCD 单元复制一步（ER2 为源）。
 * @tag bcd
 */
int dec_copy_step2(void)

{
  undefined2 *in_ER2;
  undefined2 *unaff_ER6;
  
  dec_copy(unaff_ER6,in_ER2);
  return 0;
}

/**
 * @brief 把 ER2 的 10 字节复制到 ER8（活跃槽）
 * @addr 0x143A6
 * @module bcd
 * @proto void copy_from_ER2_to_ER8(void)
 * @confidence verified
 * @note 把 ER2 的 10 字节复制到 ER8（活跃槽）。
 * @tag bcd
 */
int copy_from_ER2_to_ER8(void)

{
  undefined2 *in_ER2;
  undefined2 *unaff_ER8;
  
  dec_copy(unaff_ER8,in_ER2);
  return 0;
}

/**
 * @brief 把 src 的 10 字节复制到调用块的活跃 BCD 槽（内联跳入 0x13A16 -> 0…
 * @addr 0x143AE
 * @module bcd
 * @proto void copy_to_slot3(undefined2* src)
 * @confidence verified
 * @note 把 src 的 10 字节复制到调用块的活跃 BCD 槽（内联跳入 0x13A16 -> 0x1DA02）。
 * @tag bcd
 */
int copy_to_slot3(undefined2* _a1)

{
  undefined2 *in_ER2;
  undefined2 *unaff_ER10;
  
  dec_copy(unaff_ER10,in_ER2);
  return 0;
}

/**
 * @brief 把 src 复制到 0x14 处槽位再复制到活跃 BCD 槽
 * @addr 0x143B4
 * @module bcd
 * @proto void copy_slot4_to_slot3(undefined2* src)
 * @confidence likely
 * @note 把 src 复制到 0x14 处槽位再复制到活跃 BCD 槽。
 * @tag bcd
 */
int copy_slot4_to_slot3(undefined2* _a1)

{
  undefined2 *in_ER0;
  undefined2 *unaff_ER4;
  
  dec_copy(in_ER0,unaff_ER4);
  return 0;
}

