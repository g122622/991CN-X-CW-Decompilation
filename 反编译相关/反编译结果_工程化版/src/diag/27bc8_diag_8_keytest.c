/*
 * 自检与诊断 / 27bc8_diag_8_keytest.c
 * 地址范围: 0x27BC8 - 0x27BC8
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief LCD 自检
 * @addr 0x27BC8
 * @module diag
 * @proto void diag_8_keytest(void)
 * @confidence strong
 * @note LCD 自检：逐段点亮屏幕并绘制测试图，等待按键。
 * @tag diag
 */
int diag_8_keytest(void)

{
  char cVar1;
  short sVar2;
  byte bVar4;
  undefined2 uVar3;
  ushort uVar5;
  byte bVar6;
  byte bVar7;
  short unaff_ER14;
  
  frame_enter();
  diag_mode = 1;
  memzero(&diag_status,4);
  memset((undefined *)(unaff_ER14 + -8),0,8);
  cur_line = 10;
  clear_screen();
  uVar5 = 0;
  do {
    sVar2 = mul16(uVar5,0x14);
    draw_text4x(*(undefined2 *)(sVar2 + 0x3a4c),*(undefined2 *)(sVar2 + 0x3a4a));
    uVar5 = uVar5 + 1;
    bVar6 = (byte)(uVar5 >> 8);
    bVar4 = bVar6 - ((byte)uVar5 < 8);
  } while ((byte)((byte)((bVar4 ^ bVar6) & ~bVar4) >> 7 ^ (char)bVar4 < '\0') == 1);
  fb_flush();
  editor_action(4000);
  do {
    uVar5 = 0;
    do {
      sVar2 = mul16(uVar5,0x14);
      **(undefined **)(sVar2 + 0x3a54) = *(undefined *)(sVar2 + 0x3a52);
      editor_action(0x28);
      bVar4 = *(byte *)(sVar2 + 0x3a56);
      if ((**(byte **)(sVar2 + 0x3a58) | *(byte *)(sVar2 + 0x3a5a)) == bVar4) {
        *(undefined *)(unaff_ER14 + -9) = *(undefined *)(sVar2 + 0x3a4e);
        *(byte *)(unaff_ER14 + -10) = bVar4 ^ 0xff;
        kbd_ko_disable();
        cVar1 = wait_release((uintptr_t)0);
        if ((cVar1 != '\0') && (*(char *)(uVar5 + unaff_ER14 + -8) == '\0')) {
          cursor_visible = 4;
          draw_text4x(*(undefined2 *)(sVar2 + 0x3a4c),*(undefined2 *)(sVar2 + 0x3a4a));
          cursor_visible = 0;
          *(undefined *)(uVar5 + unaff_ER14 + -8) = 1;
          fb_flush();
        }
      }
      editor_action(0x28);
      uVar5 = uVar5 + 1;
      bVar6 = (byte)(uVar5 >> 8);
      bVar4 = bVar6 - ((byte)uVar5 < 8);
    } while ((bool)((byte)((bVar4 ^ bVar6) & ~bVar4) >> 7) != (char)bVar4 < '\0');
    bVar4 = *(byte *)(unaff_ER14 + -8);
    sVar2 = 1;
    do {
      bVar4 = bVar4 & *(byte *)(sVar2 + unaff_ER14 + -8);
      sVar2 = sVar2 + 1;
      bVar7 = (byte)((ushort)sVar2 >> 8);
      bVar6 = bVar7 - ((byte)sVar2 < 8);
    } while ((byte)((byte)((bVar6 ^ bVar7) & ~bVar6) >> 7 ^ (char)bVar6 < '\0') == 1);
  } while (bVar4 == 0);
  key_28_handler();
  cur_line = 0xe;
  do {
    if ((((int_ctrl4 & 0x10) == 0) && (editor_action(8), (int_ctrl4 & 0x10) == 0)) &&
       (editor_action(8), (int_ctrl4 & 0x10) == 0)) {
      draw_text4x(0x3200,0x7c98);
      fb_flush();
      goto LAB_rom_027d42;
    }
    uVar3 = kbd_wait_key();
  } while ((char)uVar3 == '\0');
  goto LAB_rom_027cea;
  while (uVar3 = kbd_wait_key(), (char)uVar3 == '\0') {
LAB_rom_027d42:
    if ((((int_ctrl4 & 0x10) != 0) && (editor_action(8), (int_ctrl4 & 0x10) != 0)) &&
       (editor_action(8), (int_ctrl4 & 0x10) != 0)) {
      clear_screen();
      draw_text4x(0x100,0x4d6c);
      fb_flush();
      do {
        uVar3 = kbd_wait_key();
      } while ((char)uVar3 == '\0');
      break;
    }
  }
LAB_rom_027cea:
  diag_mode = 0;
  *(undefined2 *)(unaff_ER14 + -0xc) = last_key;
  ram_clear_all();
  last_key = *(undefined2 *)(unaff_ER14 + -0xc);
  ui_state_init();
  frame_leave();
  return 0;
}

