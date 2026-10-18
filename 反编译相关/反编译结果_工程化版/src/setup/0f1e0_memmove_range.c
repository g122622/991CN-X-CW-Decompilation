/*
 * 设置与模式逻辑 / 0f1e0_memmove_range.c
 * 地址范围: 0x0F1E0 - 0x0F1E0
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 把 from..to 区间搬移（交换上下界后 0xF2C2 计算偏移），用于行/列移动
 * @addr 0x0F1E0
 * @module setup
 * @proto int memmove_range(ushort to)
 * @confidence likely
 * @note 把 from..to 区间搬移（交换上下界后 0xF2C2 计算偏移），用于行/列移动。
 * @tag util
 */
int memmove_range(ushort to)

{
  undefined uVar1;
  ushort uVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  short sVar5;
  ushort uVar6;
  byte bVar7;
  byte bVar8;
  short unaff_ER14;
  
  uVar2 = frame_enter();
  if (uVar2 != to) {
    uVar6 = uVar2;
    if (to < uVar2) {
      uVar1 = *(undefined *)(unaff_ER14 + 0x12);
      *(undefined *)(unaff_ER14 + 0x12) = *(undefined *)(unaff_ER14 + 0x10);
      *(undefined *)(unaff_ER14 + 0x10) = uVar1;
      uVar6 = to;
      to = uVar2;
    }
    bVar7 = *(byte *)(unaff_ER14 + 0x12);
    bVar8 = *(byte *)(unaff_ER14 + 0x10);
    uVar3 = mul16(CONCAT11(-(bVar7 < bVar8),bVar7 - bVar8),*(ushort *)(unaff_ER14 + 0x14));
    uVar4 = mul16(uVar6,(ushort)bVar7);
    sVar5 = mul16(to,(ushort)bVar8);
    uVar6 = CONCAT11(((char)(to >> 8) - (char)(uVar6 >> 8)) - ((byte)to < (byte)uVar6),
                     (byte)to - (byte)uVar6);
    uVar2 = mul16(2,uVar6);
    uVar1 = call_246b4((sVar5 + CONCAT11(((char)((ushort)uVar3 >> 8), (uintptr_t)0)
                                             (char)((ushort)uVar4 >> 8)) -
                                             ((byte)uVar3 < (byte)uVar4),(byte)uVar3 - (byte)uVar4))
                           * 2 + uVar6,uVar2);
    *(undefined *)(unaff_ER14 + 0x10) = uVar1;
  }
  frame_leave();
  return 0;
}

