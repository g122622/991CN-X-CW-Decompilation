/*
 * 输入编辑器 / 29dae_input_cols3.c
 * 地址范围: 0x29DAE - 0x29DAE
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 返回输入区可用列数（0xD133 == 10 时为 6，否则 0x0B）
 * @addr 0x29DAE
 * @module editor
 * @proto byte input_cols3(void)
 * @confidence strong
 * @note 返回输入区可用列数（0xD133 == 10 时为 6，否则 0x0B）。
 * @tag editor
 */
byte input_cols3(void)

{
  undefined uVar1;
  
  uVar1 = 0xb;
  if (saved_line == '\n') {
    uVar1 = 6;
  }
  return uVar1;
}

