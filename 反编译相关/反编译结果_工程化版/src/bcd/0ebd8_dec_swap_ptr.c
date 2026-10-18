/*
 * BCD 浮点库 / 0ebd8_dec_swap_ptr.c
 * 地址范围: 0x0EBD8 - 0x0F250
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 交换输入区指针参数的 10 字节内容与临时单元（三步 dec_copy）
 * @addr 0x0EBD8
 * @module bcd
 * @proto void dec_swap_ptr(undefined2* p)
 * @confidence likely
 * @note 交换输入区指针参数的 10 字节内容与临时单元（三步 dec_copy）。
 * @tag bcd
 */
int dec_swap_ptr(undefined2* p)

{
  undefined2 *puVar1;
  short unaff_ER14;
  
  puVar1 = (undefined2 *)frame_enter();
  dec_copy((undefined2 *)(unaff_ER14 + -10),puVar1);
  dec_copy(puVar1,p);
  dec_copy(p,(undefined2 *)(unaff_ER14 + -10));
  frame_leave();
  return 0;
}

/**
 * @brief 18 点插值
 * @addr 0x0F250
 * @module bcd
 * @proto int interpolate_18(void)
 * @confidence likely
 * @note 18 点插值：循环 0x1D9A8 与倍乘（0x13858 开方迭代使用）。
 * @tag bcd
 */
int interpolate_18(void)

{
  int bVar1;
  undefined2 *puVar2;
  ushort uVar3;
  ushort uVar4;
  byte bVar5;
  short unaff_ER14;
  
  puVar2 = (undefined2 *)frame_enter();
  *(undefined2 *)(unaff_ER14 + -0xe) = 0;
  *(undefined2 *)(unaff_ER14 + -0xc) = 0;
  bVar5 = 0;
  do {
    if (bVar5 < 0x18) {
      dec_copy((undefined2 *)(unaff_ER14 + -10),(undefined2 *)0x1ba8);
      dec_abs_wrap();
    }
    bVar1 = dec_bin_to_bcd_ctx();
    uVar3 = (ushort)bVar1;
    uVar4 = 0;
    for (bVar1 = bVar5; bVar1 != 0; bVar1 = bVar1 - 1) {
      uVar4 = CONCAT11((char)(((uVar4 & 0xff00) + (uVar4 & 0xff)) * 2 >> 8),
                       (char)((uVar4 * 0x100 + (uVar3 >> 8)) * 2 >> 8));
      uVar3 = CONCAT11((char)(((uVar3 & 0xff00) + (uVar3 & 0xff)) * 2 >> 8),(byte)uVar3 << 1);
    }
    *(ushort *)(unaff_ER14 + -0xe) =
         CONCAT11((byte)((ushort)*(undefined2 *)(unaff_ER14 + -0xe) >> 8) | (byte)(uVar3 >> 8),
                  (byte)*(undefined2 *)(unaff_ER14 + -0xe) | (byte)uVar3);
    *(ushort *)(unaff_ER14 + -0xc) =
         CONCAT11((byte)((ushort)*(undefined2 *)(unaff_ER14 + -0xc) >> 8) | (byte)(uVar4 >> 8),
                  (byte)*(undefined2 *)(unaff_ER14 + -0xc) | (byte)uVar4);
    bVar5 = bVar5 + 8;
    dec_copy(puVar2,(undefined2 *)(unaff_ER14 + -10));
  } while (bVar5 < 0x19);
  frame_leave();
  return 0;
}

