/*
 * 硬件抽象层 / 0f1a8_memset.c
 * 地址范围: 0x0F1A8 - 0x0F932
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 标准 memset（返回 dst
 * @addr 0x0F1A8
 * @module hal
 * @proto byte* memset(byte* dst, byte value, ushort len)
 * @confidence verified
 * @note 标准 memset（返回 dst；len 由调用者压栈，位于 0x02[FP]）。与 Labels/memset.md
 *       一致。
 * @tag libc
 */
byte* memset(byte* dst, byte value, ushort len)

{
  undefined *puVar1;
  
  puVar1 = dst;
  for (; (char)((len != 0) << 7) < '\0'; len = len + -1) {
    *puVar1 = value;
    puVar1 = puVar1 + 1;
  }
  return dst;
}

/**
 * @brief 16 位无符号乘法（MUL 指令封装）
 * @addr 0x0F2C2
 * @module hal
 * @proto short mul16(ushort a, ushort b)
 * @confidence verified
 * @note 16 位无符号乘法（MUL 指令封装）。
 * @tag math
 */
short mul16(ushort a, ushort b)

{
  return b * a;
}

/**
 * @brief 取 token 的首字节查 0x37A4 表得类别
 * @addr 0x0F2EC
 * @module hal
 * @proto byte get_token_class(byte* tok)
 * @confidence strong
 * @note 取 token 的首字节查 0x37A4 表得类别；非单一 token 时返回 5。
 * @tag parser
 */
byte get_token_class(byte* tok)

{
  byte bVar1;
  undefined uVar2;
  undefined2 uVar3;
  
  uVar3 = token_class((char *)tok);
  if ((char)uVar3 == '\x01') {
    bVar1 = font_class_of(*tok);
    uVar2 = *(undefined *)(bVar1 + 0x37a4);
  }
  else {
    uVar2 = 5;
  }
  return uVar2;
}

/**
 * @brief 主循环的阻塞读键
 * @addr 0x0F746
 * @module hal
 * @proto bool loop_read_key(void)
 * @confidence strong
 * @note 主循环的阻塞读键：清当前输入、循环 read_key 直到有键；处理 SHIFT/ALPHA 等；返回是否有输入。
 * @tag kbd
 */
bool loop_read_key(void)

{
  char cVar1;
  undefined uVar2;
  char cVar3;
  bool bVar4;
  undefined2 *puVar5;
  ushort uVar6;
  byte bVar7;
  char cVar8;
  short unaff_ER14;
  
  puVar5 = (undefined2 *)frame_enter();
  *(undefined2 *)(unaff_ER14 + -4) = 0x4ab;
  if (menu_state_d == '\x01') {
    *(undefined2 *)(unaff_ER14 + -4) = 0x1c02;
  }
  cVar8 = '\n';
  cVar1 = key_flag_test3();
  if (cVar1 != '\0') {
    cVar8 = '2';
  }
  *(undefined2 *)(unaff_ER14 + -0x18a) = last_key;
  cVar1 = is_idle_editing();
  *(char *)(unaff_ER14 + -0xc) = cVar1;
  if (cVar1 != '\0') {
    cur_line = saved_line;
  }
  cursor_visible = 1;
  bVar7 = (byte)unaff_ER14;
  cVar1 = (char)((ushort)unaff_ER14 >> 8);
  uVar2 = table_shape_draw((char *)CONCAT11(cVar1 + -2 + (0x8a < bVar7),bVar7 + 0x75));
  *(undefined *)(unaff_ER14 + -2) = uVar2;
  calc_px_ptr(hl_line,*(byte *)(unaff_ER14 + -0x18b),(undefined2 *)(unaff_ER14 + -10));
  calc_fb_ptr(hl_line,*(byte *)(unaff_ER14 + -0x18b),(short *)(unaff_ER14 + -8));
  copy_result_hook(*(undefined **)(unaff_ER14 + -10));
  if (*(char *)(unaff_ER14 + -0xc) != '\0') {
    table_shape_draw((char *)CONCAT11(cVar1 + -2 + (0x8a < bVar7),bVar7 + 0x75));
  }
  copy_result_hook(*(undefined **)(unaff_ER14 + -10));
  cursor_visible = 0;
  *(undefined *)(unaff_ER14 + -0xd) = 0;
  *(undefined *)(unaff_ER14 + -6) = 0x28;
  *(undefined *)(unaff_ER14 + -5) = 1;
  draw_target = 0;
  do {
    cVar3 = key_repeat_wait();
    if (cVar3 == '\0') {
      *(undefined *)(unaff_ER14 + -6) = 4;
      *(undefined *)(unaff_ER14 + -5) = 1;
      *(undefined *)(unaff_ER14 + -0xd) = 0;
LAB_rom_00f8da:
      kbd_filter_on();
      kbd_ko_enable();
      do {
        timer_rearm();
        stat_matrix_rebuild();
        editor_action(1000);
        while (uVar6 = irq_pending(), (uVar6 & 2) != 0) {
          bVar4 = kbd_any_key();
          if (bVar4) {
            kbd_ko_disable();
            kbd_filter_off();
            editor_action(1);
            cVar8 = lcd_scan_keys((uintptr_t)0);
            if ((cVar8 == '\0') || (cVar8 = wait_release((uintptr_t)0), cVar8 == '\0')) goto LAB_rom_00f8da;
            *puVar5 = *(undefined2 *)(unaff_ER14 + -0x18e);
            goto LAB_rom_00f87c;
          }
          timer_clear_pending();
        }
        _DAT_ram_d318 = _DAT_ram_d318 + 1;
      } while( true );
    }
    stat_matrix_rebuild();
    if ((cVar8 == '\0') && (cVar3 = key_flag_test7(), cVar3 != '\0')) {
      statusbar_exit_mark(cVar3);
      *(undefined2 *)(unaff_ER14 + -0x18e) = *(undefined2 *)(unaff_ER14 + -0x18a);
      *puVar5 = *(undefined2 *)(unaff_ER14 + -0x18a);
LAB_rom_00f87c:
      draw_target = 1;
      kbd_ko_disable();
      last_key = *(undefined2 *)(unaff_ER14 + -0x18e);
      str_format_frac(CONCAT11(cVar1 + -1 + (0xc9 < bVar7),bVar7 + 0x36));
      frame_leave();
      return;
    }
    editor_action(0x62);
    cVar8 = cVar8 + -1;
  } while( true );
}

/**
 * @brief 按键分派
 * @addr 0x0F932
 * @module hal
 * @proto void key_dispatch_menu(void)
 * @confidence strong
 * @note 按键分派：满足条件时调用 0x20860 处理（菜单相关）。
 * @tag kbd
 */
int key_dispatch_menu(void)

{
  char cVar1;
  undefined uVar2;
  
  uVar2 = 0;
  cVar1 = is_line_start();
  if ((cVar1 != '\0') && (menu_state_c == '\0')) {
    uVar2 = 0xd;
  }
  key_hist_write(uVar2);
  return 0;
}

