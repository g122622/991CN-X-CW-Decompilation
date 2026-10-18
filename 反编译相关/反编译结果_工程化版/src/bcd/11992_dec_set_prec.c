/*
 * BCD 浮点库 / 11992_dec_set_prec.c
 * 地址范围: 0x11992 - 0x11992
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 设置 BCD 精度
 * @addr 0x11992
 * @module bcd
 * @proto void dec_set_prec(byte n)
 * @confidence likely
 * @note 设置 BCD 精度：n 不为 1 时取 3，随后调用 0x1D6A4/0x1D800 归一化。
 * @tag bcd
 */
int dec_set_prec(byte n)

{
  ushort *unaff_ER12;
  
  if (n != 1) {
    n = 3;
  }
  dec_set_special(unaff_ER12,n);
  bcd_type((byte *)unaff_ER12);
  return 0;
}

