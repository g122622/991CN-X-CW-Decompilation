/*
 * 输入编辑器 / 23e58_is_second_byte.c
 * 地址范围: 0x23E58 - 0x23E58
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief p 指向双字节字符的第二字节（p < 0xF0 且 p[-1] >= 0xF0）时返回 1
 * @addr 0x23E58
 * @module editor
 * @proto undefined2 is_second_byte(byte* p)
 * @confidence strong
 * @note p 指向双字节字符的第二字节（p < 0xF0 且 p[-1] >= 0xF0）时返回 1。
 * @tag editor
 */
undefined2 is_second_byte(byte* p)

{
  undefined2 uVar1;
  
  if ((char)((*p < 0xf0) << 7) < '\0') {
    uVar1 = 0;
    if (0xef < p[-1]) {
      uVar1 = 1;
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

