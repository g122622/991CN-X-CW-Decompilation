/*
 * 表达式求值 / 17e78_eval_result_init.c
 * 地址范围: 0x17E78 - 0x17F6A
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 用 0x17F6A 的结果初始化求值结果（16 字节结构填两处）
 * @addr 0x17E78
 * @module eval
 * @proto void eval_result_init(undefined2 v)
 * @confidence likely
 * @note 用 0x17F6A 的结果初始化求值结果（16 字节结构填两处）。
 * @tag eval
 */
int eval_result_init(undefined2 v)

{
  undefined2 uVar1;
  undefined4 unaff_XR4;
  undefined2 unaff_ER8;
  undefined8 *unaff_ER14;
  
  uVar1 = evaluator_abort();
  *unaff_ER14 = CONCAT44(unaff_XR4,CONCAT22(v,uVar1));
  unaff_ER14[1] = CONCAT44(unaff_XR4,CONCAT22(v,uVar1));
  *(undefined2 *)((short)unaff_ER14 + 0x12) = v;
  *(undefined2 *)(unaff_ER14 + 2) = uVar1;
  *(byte *)(uintptr_t)(ulonglong *)((short)unaff_ER14 + 0x14) =
       CONCAT44(unaff_XR4,CONCAT22(v,CONCAT11((char)((ushort)uVar1 >> 8),1)));
  *(undefined2 *)((short)unaff_ER14 + 0x1c) = unaff_ER8;
  return 0;
}

/**
 * @brief 按 R11 低半字节/R10 拆解操作数为 BCD 结果
 * @addr 0x17F1A
 * @module eval
 * @proto int unpack_nibbles(void)
 * @confidence likely
 * @note 按 R11 低半字节/R10 拆解操作数为 BCD 结果。
 * @tag eval
 */
int unpack_nibbles(void)

{
  byte unaff_R10;
  byte unaff_R11;
  byte bVar1;
  
  bVar1 = unaff_R11 & 0xf;
  if (bVar1 == 0) {
    if (unaff_R10 < 10) {
      evaluator_abort();
      bVar1 = unaff_R10;
    }
    else {
      bVar1 = (byte)(((ushort)unaff_R10 << 4) >> 8);
      evaluator_abort();
    }
  }
  else {
    evaluator_abort();
  }
  return bVar1;
}

/**
 * @brief R10<10 直接调用 0x17F6A，否则先左移 4 位再调用
 * @addr 0x17F4A
 * @module eval
 * @proto byte nibble_pair(void)
 * @confidence likely
 * @note R10<10 直接调用 0x17F6A，否则先左移 4 位再调用。
 * @tag eval
 */
byte nibble_pair(void)

{
  byte unaff_R10;
  
  if (unaff_R10 < 10) {
    evaluator_abort();
  }
  else {
    unaff_R10 = (byte)(((ushort)unaff_R10 << 4) >> 8);
    evaluator_abort();
  }
  return unaff_R10;
}

/**
 * @brief 求值器的失败出口（返回 0
 * @addr 0x17F6A
 * @module eval
 * @proto short evaluator_abort(void)
 * @confidence likely
 * @note 求值器的失败出口（返回 0；Ghidra 标注了多处不可达块）。
 * @tag eval
 */
short evaluator_abort(void)

{
  return 0;
}

