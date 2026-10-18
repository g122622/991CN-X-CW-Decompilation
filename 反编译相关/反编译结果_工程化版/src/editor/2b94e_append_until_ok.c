/*
 * 输入编辑器 / 2b94e_append_until_ok.c
 * 地址范围: 0x2B94E - 0x2BD42
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 循环以 0..0xF 追加参数直到 0xFBFE 成功
 * @addr 0x2B94E
 * @module editor
 * @proto int append_until_ok(void)
 * @confidence likely
 * @note 循环以 0..0xF 追加参数直到 0xFBFE 成功。
 * @tag editor
 */
int append_until_ok(void)

{
  uintptr_t fp = 0;
  byte bVar1;
  char cVar2;
  short sVar3;
  byte bVar4;
  short unaff_ER14;
  undefined *puVar5;
  undefined2 *puVar6;
  
  puVar5 = &*(byte *)(uintptr_t)(fp + 0xfffc);
  frame_enter();
  sVar3 = 0;
  do {
    puVar5[-2] = *(undefined *)(unaff_ER14 + 0x12);
    puVar6 = (undefined2 *)(puVar5 + -4);
    puVar5 = puVar5 + -4;
    *puVar6 = *(undefined2 *)(unaff_ER14 + 0x10);
    cVar2 = menu_gate();
    if (cVar2 != '\0') break;
    sVar3 = sVar3 + 1;
    bVar4 = (byte)((ushort)sVar3 >> 8);
    bVar1 = bVar4 - ((byte)sVar3 < 0x10);
  } while ((byte)((byte)((bVar1 ^ bVar4) & ~bVar1) >> 7 ^ (char)bVar1 < '\0') == 1);
  frame_leave();
  return 0;
}

/**
 * @brief 输入编辑未锁定时清 D13E，并通过 0x20D48/0x20D76 复位待处理输入 D15…
 * @addr 0x2BD42
 * @module editor
 * @proto void input_reset(void)
 * @confidence likely
 * @note 输入编辑未锁定时清 D13E，并通过 0x20D48/0x20D76 复位待处理输入 D15C/D15D。
 * @tag editor
 */
int input_reset(void)

{
  char cVar1;
  
  if (((edit_state2 & 0x10) == 0) && (cVar1 = is_math_io(), cVar1 == '\0')) {
    history_dirty = 0;
    if (stored_a != '\0') {
      draw_cursor_field(stored_a);
    }
    if (stored_b != '\0') {
      draw_line_end(stored_b);
    }
    stored_a = '\0';
    stored_b = '\0';
  }
  return 0;
}

