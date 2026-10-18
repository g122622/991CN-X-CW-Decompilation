/*
 * BCD 浮点库 / 0d048_var_unit_init.c
 * 地址范围: 0x0D048 - 0x0D048
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 把 p 处 10 字节清零，再写入类型头 {0x06, 0x55, 0x36, …, 0x0…
 * @addr 0x0D048
 * @module bcd
 * @proto void var_unit_init(byte* p)
 * @confidence verified
 * @note 把 p 处 10 字节清零，再写入类型头 {0x06, 0x55, 0x36, …, 0x01, 0x04}（新的 BCD
 *       单元初值）。
 * @tag bcd
 */
int var_unit_init(byte* p, int _a2)

{
  memzero(p,10);
  *p = 6;
  p[1] = 0x55;
  p[2] = 0x36;
  *(undefined2 *)(p + 8) = 0x104;
  return 0;
}



// 字符串复制函数 (strcpy)
// 地址: 0xD070
// p: 目标地址
// _a2: 源地址
// 返回: 目标地址

