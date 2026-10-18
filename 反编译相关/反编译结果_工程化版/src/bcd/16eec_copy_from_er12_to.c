/*
 * BCD 浮点库 / 16eec_copy_from_er12_to.c
 * 地址范围: 0x16EEC - 0x16EFE
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 把 ER12 指向的 10 字节复制到 dst 并返回 dst
 * @addr 0x16EEC
 * @module bcd
 * @proto undefined2* copy_from_ER12_to(undefined2* dst)
 * @confidence verified
 * @note 把 ER12 指向的 10 字节复制到 dst 并返回 dst。
 * @tag bcd
 */
undefined2* copy_from_ER12_to(undefined2* dst)

{
  undefined2 *unaff_ER12;
  
  dec_copy(dst,unaff_ER12);
  return dst;
}

/**
 * @brief 把 src 的 10 字节复制到 ER12 指向处并返回 src
 * @addr 0x16EF4
 * @module bcd
 * @proto undefined2* copy_to_ER12(undefined2* src)
 * @confidence verified
 * @note 把 src 的 10 字节复制到 ER12 指向处并返回 src。
 * @tag bcd
 */
undefined2* copy_to_ER12(undefined2* src)

{
  undefined2 *unaff_ER12;
  
  dec_copy(unaff_ER12,src);
  return src;
}

/**
 * @brief 复制 10 字节 BCD 单元并返回 dst
 * @addr 0x16EFE
 * @module bcd
 * @proto undefined2* dec_copy_ret(undefined2* dst, undefined2* src)
 * @confidence verified
 * @note 复制 10 字节 BCD 单元并返回 dst。
 * @tag bcd
 */
undefined2* dec_copy_ret(undefined2* dst, undefined2* src)

{
  dec_copy(src,dst);
  return dst;
}

