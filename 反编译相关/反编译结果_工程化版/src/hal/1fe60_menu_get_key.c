/*
 * 硬件抽象层 / 1fe60_menu_get_key.c
 * 地址范围: 0x1FE60 - 0x1FE60
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 显示菜单（0x8CC0 设置行号）并循环 read_key，直到 key_is_value …
 * @addr 0x1FE60
 * @module hal
 * @proto short menu_get_key(char k)
 * @confidence strong
 * @note 显示菜单（0x8CC0 设置行号）并循环 read_key，直到 key_is_value
 *       判定为有效菜单键，返回键码。调用点 0x285E4/0x24B7E/0x28138 等。
 * @tag kbd
 */
short menu_get_key(char k)

{
  short sVar1;
  undefined2 uVar2;
  
  menu_draw(k);
  do {
    sVar1 = input_is_empty();
    uVar2 = key_is_value(sVar1);
  } while ((char)uVar2 == '\0');
  return sVar1;
}

