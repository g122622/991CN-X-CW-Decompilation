/*
 * BCD 浮点库 / 08f9a_dec_copy_checked.c
 * 地址范围: 0x08F9A - 0x08F9A
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 空指针安全的两参 dec_copy（任一为空则跳过）
 * @addr 0x08F9A
 * @module bcd
 * @proto void dec_copy_checked(undefined2* dst, undefined2* src)
 * @confidence verified
 * @note 空指针安全的两参 dec_copy（任一为空则跳过）。
 * @tag bcd
 */
int dec_copy_checked(undefined2* dst, undefined2* src)

{
  if ((dst != (undefined2 *)0x0) && (src != (undefined2 *)0x0)) {
    dec_copy(dst,src);
  }
  return 0;
}

