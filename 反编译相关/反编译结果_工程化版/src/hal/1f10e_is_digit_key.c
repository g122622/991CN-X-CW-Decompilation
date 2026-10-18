/*
 * 硬件抽象层 / 1f10e_is_digit_key.c
 * 地址范围: 0x1F10E - 0x1F574
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief k 为 3、4、9、0x0B、0x0C 时返回 1（数字键盘的若干键）
 * @addr 0x1F10E
 * @module hal
 * @proto char is_digit_key(byte k)
 * @confidence likely
 * @note k 为 3、4、9、0x0B、0x0C 时返回 1（数字键盘的若干键）。
 * @tag kbd
 */
char is_digit_key(byte k)

{
  if ((((k != 9) && (k != 3)) && (k != 4)) && ((k < 0xb || (0xc < k)))
     ) {
    return 0;
  }
  return 1;
}

/**
 * @brief 阻塞等待按键（start/end 包裹，查 0x62E2 表），用于自检/诊断页的"按任意键…
 * @addr 0x1F230
 * @module hal
 * @proto void wait_any_key(void)
 * @confidence strong
 * @note 阻塞等待按键（start/end 包裹，查 0x62E2 表），用于自检/诊断页的"按任意键继续"。
 * @tag kbd
 */
int wait_any_key(void)

{
  undefined2 uVar1;
  short unaff_ER14;
  
  frame_enter();
  do {
    loop_read_key();
    uVar1 = key_decode((byte *)(unaff_ER14 + -2),0x62e2);
  } while ((byte)uVar1 != 0x29 || (bool)((char)((ushort)uVar1 >> 8) + '\x04') != (byte)uVar1 < 0x29)
  ;
  frame_leave();
  return 0;
}

/**
 * @brief 读键盘
 * @addr 0x1F574
 * @module hal
 * @proto ushort read_key(void)
 * @confidence verified
 * @note 读键盘：按 0xD110(扫描状态) 驱动 KO 编码，调用 key_decode 查模式相关的键位映射表（COMP
 *       0x775C / STAT 0x62E2 / TABLE 0x3668 / 复数线性 0x3BF2 / SHIFT
 *       0x0A10 / ALPHA 0x198E），返回 16 位键码（低字节 KI、高字节 KO）。
 * @tag kbd
 */
ushort input_is_empty(void)

{
  char cVar1;
  ushort uVar2;
  short sVar3;
  undefined2 uVar4;
  byte bVar5;
  short unaff_ER14;
  
  frame_enter();
  while( true ) {
    if (diag_mode == '\0') {
      if (input_layout == '\0') {
        status_bits_draw();
      }
      else {
        status_bits_init();
      }
    }
    loop_read_key();
    if ((status_bits & 4) == 0) {
      if ((status_bits & 1) == 0) {
        if ((status_bits & 8) == 0) {
          if ((calc_mode == '\x02') && (input_layout == '\0')) {
            sVar3 = 0x775c;
          }
          else {
            sVar3 = 0x62e2;
          }
          uVar2 = key_decode((byte *)(unaff_ER14 + -2),sVar3);
        }
        else {
          if (calc_mode == '\x02') {
            sVar3 = 0x3668;
          }
          else {
            sVar3 = 0x3bf2;
          }
          uVar2 = key_decode((byte *)(unaff_ER14 + -2),sVar3);
        }
      }
      else {
        uVar2 = key_decode((byte *)(unaff_ER14 + -2),0xa10);
      }
    }
    else {
      uVar2 = key_decode((byte *)(unaff_ER14 + -2),0x198e);
    }
    if (calc_mode == -0x3c) {
      bVar5 = (byte)uVar2;
      cVar1 = (char)(uVar2 >> 8);
      if (bVar5 == 0x38 && (bool)(cVar1 + '\x04') == bVar5 < 0x38) {
        uVar2 = 0x20;
      }
      else if (bVar5 == 0x39 && (bool)(cVar1 + '\x04') == bVar5 < 0x39) {
        uVar2 = 0xac;
      }
    }
    bVar5 = (byte)uVar2;
    cVar1 = (char)(uVar2 >> 8);
    if (bVar5 == 0x27 && (bool)(cVar1 + '\x04') == bVar5 < 0x27) {
      boot_lcd_init();
    }
    uVar4 = keycode_norm2(uVar2);
    if ((char)uVar4 == '\0') break;
    key_28_handler();
    cVar1 = is_idle_editing();
    if ((cVar1 != '\0') && (saved_line < hl_col2)) {
      fb_flush();
    }
  }
  key_28_handler();
  if (bVar5 == 7 && (bool)(cVar1 + '\x04') == bVar5 < 7) {
    uVar2 = 0;
  }
  if ((byte)uVar2 == 0xe9 && (bool)(char)(uVar2 >> 8) == (byte)uVar2 < 0xe9) {
    uVar2 = 0;
  }
  if (calc_mode != -0x3f) {
    bVar5 = (byte)uVar2;
    cVar1 = (char)(uVar2 >> 8);
    if ((bVar5 == 0xe9 && (bool)cVar1 == bVar5 < 0xe9) ||
       (bVar5 == 0x4a && (bool)cVar1 == bVar5 < 0x4a)) {
      uVar2 = 0;
    }
  }
  cVar1 = is_key_20_23((byte)uVar2,(char)(uVar2 >> 8));
  if ((cVar1 != '\0') && (cVar1 = is_modifier_1(), cVar1 != '\0')) {
    is_special_editing();
  }
  frame_leave();
  return;
}

