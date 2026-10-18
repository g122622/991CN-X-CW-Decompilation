/*
 * 应用模式 / 23088_base_mode_loop.c
 * 地址范围: 0x23088 - 0x23598
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 进制（BASE-N）编辑循环（1.1KB，0x14C5E 调用）
 * @addr 0x23088
 * @module apps
 * @proto void base_mode_loop(void)
 * @confidence likely
 * @note 进制（BASE-N）编辑循环（1.1KB，0x14C5E 调用）。
 * @tag mode
 */
int base_mode_loop(uintptr_t _a2, int _a1)

{
  int cVar1;
  int bVar2;
  ushort *puVar3;
  undefined2 uVar4;
  short unaff_ER14;
  
  puVar3 = (ushort *)frame_enter();
  cVar1 = append_until_ok();
  if ((cVar1 == '\0') && (cVar1 = append_until_ok(), cVar1 == '\0')) {
    *(undefined *)(unaff_ER14 + -1) = 0;
    bVar2 = expr_matrix_scan(puVar3);
    if (bVar2 == 0) {
      uVar4 = kbd_wait_key();
      if ((char)uVar4 == '\0') {
        bVar2 = mode_loop_common(puVar3);
        if (bVar2 != 0) {
          if (bVar2 == 0xb) {
            bVar2 = 3;
          }
          dec_round_to(_a1,bVar2);
          goto LAB_rom_0230ac;
        }
        uVar4 = kbd_wait_key();
        if ((char)uVar4 == '\0') {
          cVar1 = table_edit_main();
          if (cVar1 == '\0') {
            memcpy160((undefined *)puVar3,(undefined *)_a1);
            append_until_ok();
          }
          goto LAB_rom_0230ac;
        }
      }
      dec_round_to(_a1,1);
    }
    else {
      if (bVar2 == 0xb) {
        bVar2 = 3;
      }
      dec_round_to(_a1,bVar2);
    }
  }
LAB_rom_0230ac:
  frame_leave();
  return 0;
}

/**
 * @brief EQUA 模式判定
 * @addr 0x23598
 * @module apps
 * @proto char is_mode_E(void)
 * @confidence strong
 * @note EQUA 模式判定：0xD111 == 0x45（字符 E）时返回 1 或 0（依 0xD112 < 4），0xD111
 *       == 0xC4 时返回 1。
 * @tag mode
 */
char is_mode_E(void)

{
  if (calc_mode == 'E') {
    return '\x01' - (sub_mode < 4);
  }
  if (calc_mode != -0x3c) {
    return '\0';
  }
  return '\x01';
}

