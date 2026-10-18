/*
 * 硬件抽象层 / 2082c_key_hist_hi.c
 * 地址范围: 0x2082C - 0x20DE2
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 返回 0xD118 的高 4 位（按键历史编码的高半字节）
 * @addr 0x2082C
 * @module hal
 * @proto byte key_hist_hi(void)
 * @confidence verified
 * @note 返回 0xD118 的高 4 位（按键历史编码的高半字节）。
 * @tag kbd
 */
byte key_hist_hi(void)

{
  return key_hist_a >> 4;
}

/**
 * @brief 返回 0xD118 的低 4 位（按键历史编码的低半字节）
 * @addr 0x20834
 * @module hal
 * @proto byte key_hist_lo(void)
 * @confidence verified
 * @note 返回 0xD118 的低 4 位（按键历史编码的低半字节）。
 * @tag kbd
 */
byte key_hist_lo(void)

{
  return key_hist_a & 0xf;
}

/**
 * @brief 0xD118 ← 0xD118 & 0x0F | v << 4（替换高半字节），并清 0xD…
 * @addr 0x2083C
 * @module hal
 * @proto void key_hist_set_hi(byte v)
 * @confidence verified
 * @note 0xD118 ← 0xD118 & 0x0F | v << 4（替换高半字节），并清 0xD148。
 * @tag kbd
 */
int key_hist_set_hi(byte v)

{
  key_hist_a = key_hist_a & 0xf | v << 4;
  return 0;
}

/**
 * @brief 0xD118 ← v | 0xD118 & 0xF0（替换低半字节），并清 0xD148
 * @addr 0x2084C
 * @module hal
 * @proto void key_hist_clear_lo(byte v)
 * @confidence verified
 * @note 0xD118 ← v | 0xD118 & 0xF0（替换低半字节），并清 0xD148。
 * @tag kbd
 */
int key_hist_clear_lo(byte v)

{
  key_hist_a = v | key_hist_a & 0xf0;
  key_hist_d = 0;
  return 0;
}

/**
 * @brief 0xD118 ← v，并清 0xD148
 * @addr 0x20860
 * @module hal
 * @proto void key_hist_write(byte v)
 * @confidence verified
 * @note 0xD118 ← v，并清 0xD148。
 * @tag kbd
 */
int key_hist_write(byte v)

{
  key_hist_a = v;
  key_hist_d = 0;
  return 0;
}

/**
 * @brief 若 0xD110 的 bit7 置位，则清 bit7 与 bit3
 * @addr 0x20DE2
 * @module hal
 * @proto void key_flag_clear_b7(void)
 * @confidence strong
 * @note 若 0xD110 的 bit7 置位，则清 bit7 与 bit3。
 * @tag kbd
 */
int key_flag_clear_b7(void)

{
  if ((status_bits & 0x80) != 0) {
    status_bits = status_bits + 0x80 & 0xf7;
  }
  return 0;
}

