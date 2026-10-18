/*
 * 硬件抽象层 / 0ccda_key_hist_swap_nibbles.c
 * 地址范围: 0x0CCDA - 0x0D2A4
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 把 0xD118 的高 4 位与低 4 位互换（回车后把“上/下”标志移到低半字节）
 * @addr 0x0CCDA
 * @module hal
 * @proto void key_hist_swap_nibbles(void)
 * @confidence strong
 * @note 把 0xD118 的高 4 位与低 4 位互换（回车后把“上/下”标志移到低半字节）。
 * @tag kbd
 */
int key_hist_swap_nibbles(void)

{
  key_hist_a = key_hist_a & 0xf0 | key_hist_a >> 4;
  return 0;
}

/**
 * @brief 等待按键松开（最多 10×10ms），超时清 0xD13A
 * @addr 0x0D2A4
 * @module hal
 * @proto char key_repeat_wait(void)
 * @confidence strong
 * @note 等待按键松开（最多 10×10ms），超时清 0xD13A。
 * @tag kbd
 */
char key_repeat_wait(void)

{
  bool bVar1;
  byte *pbVar2;
  byte bVar3;
  
  pbVar2 = (byte *)frame_enter();
  bVar1 = false;
  kbd_ko = pbVar2[1];
  bVar3 = 1;
  do {
    if (((_DAT_ram_f040 ^ 0xff) & *pbVar2) != 0) {
      bVar1 = true;
      break;
    }
    timer_wait(10);
    bVar3 = bVar3 + 1;
  } while (bVar3 < 0xb);
  kbd_ko = 0;
  if (!bVar1) {
    key_flag_clear();
  }
  frame_leave();
  return;
}

