/*
 * 硬件抽象层 / 0c2cc_is_menu_key_80.c
 * 地址范围: 0x0C2CC - 0x0C2CC
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief k 为 0xC0/0xA7/0xA6（菜单导航相关扩展键）时返回 1
 * @addr 0x0C2CC
 * @module hal
 * @proto char is_menu_key_80(byte k)
 * @confidence likely
 * @note k 为 0xC0/0xA7/0xA6（菜单导航相关扩展键）时返回 1。
 * @tag kbd
 */
char is_menu_key_80(byte k)

{
  if (((k != -0x40) && (k != -0x59)) && (k != -0x5a)) {
    return 0;
  }
  return 1;
}

