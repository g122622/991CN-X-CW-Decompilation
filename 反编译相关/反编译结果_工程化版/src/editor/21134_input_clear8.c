/*
 * 输入编辑器 / 21134_input_clear8.c
 * 地址范围: 0x21134 - 0x21134
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 以键值 8 调用 0x9060（清输入缓冲），返回
 * @addr 0x21134
 * @module editor
 * @proto void input_clear8(undefined2 k, undefined* p)
 * @confidence strong
 * @note 以键值 8 调用 0x9060（清输入缓冲），返回。
 * @tag editor
 */
int input_clear8(undefined2 k, undefined* p)

{
  base_clear(CONCAT11((char)((ushort)k >> 8),8),p);
  return 0;
}

