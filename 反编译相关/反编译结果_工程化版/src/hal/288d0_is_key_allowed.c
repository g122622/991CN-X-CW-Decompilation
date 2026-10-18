/*
 * 硬件抽象层 / 288d0_is_key_allowed.c
 * 地址范围: 0x288D0 - 0x288D0
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief k 为 2、4、8、0x0A、0x0C 及 >= 0x0C 以外的值时返回 1（按键白名单）
 * @addr 0x288D0
 * @module hal
 * @proto char is_key_allowed(byte k)
 * @confidence likely
 * @note k 为 2、4、8、0x0A、0x0C 及 >= 0x0C 以外的值时返回 1（按键白名单）。
 * @tag kbd
 */
char is_key_allowed(byte k)

{
  if ((((k != 8) && (k != 10)) && (k != 2)) && ((k != 4 && (k < 0xc)))
     ) {
    return 0;
  }
  return 1;
}

