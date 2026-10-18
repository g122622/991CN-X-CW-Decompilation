/*
 * 硬件抽象层 / 09376_buzzer_set.c
 * 地址范围: 0x09376 - 0x096BE
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief F815 = (on != 0)
 * @addr 0x09376
 * @module hal
 * @proto void buzzer_set(char on)
 * @confidence strong
 * @note F815 = (on != 0)。
 * @tag hw
 */
int buzzer_set(char on)

{
  if (on != '\0') {
    buzzer = 1;
    return 0;
  }
  buzzer = 0;
  return 0;
}

/**
 * @brief F042（键盘输入滤波）置 0xFF
 * @addr 0x09382
 * @module hal
 * @proto void kbd_filter_on(void)
 * @confidence verified
 * @note F042（键盘输入滤波）置 0xFF。
 * @tag kbd
 */
int kbd_filter_on(void)

{
  kbd_filter = 0xff;
  return 0;
}

/**
 * @brief F042 清 0
 * @addr 0x0938A
 * @module hal
 * @proto void kbd_filter_off(void)
 * @confidence verified
 * @note F042 清 0。
 * @tag kbd
 */
int kbd_filter_off(void)

{
  kbd_filter = 0;
  return 0;
}

/**
 * @brief F046（键盘输出 KO）置 0x7F
 * @addr 0x09392
 * @module hal
 * @proto void kbd_ko_enable(void)
 * @confidence verified
 * @note F046（键盘输出 KO）置 0x7F。
 * @tag kbd
 */
int kbd_ko_enable(void)

{
  kbd_ko = 0x7f;
  return 0;
}

/**
 * @brief F046 清 0
 * @addr 0x0939A
 * @module hal
 * @proto int kbd_ko_disable(void)
 * @confidence verified
 * @note F046 清 0。
 * @tag kbd
 */
int kbd_ko_disable(void)

{
  kbd_ko = 0;
  return 0;
}

/**
 * @brief 短延时后 F046=0x7F，读 F040(KI)
 * @addr 0x093A2
 * @module hal
 * @proto bool kbd_any_key(void)
 * @confidence verified
 * @note 短延时后 F046=0x7F，读 F040(KI)；有任一键按下返回 true。
 * @tag kbd
 */
bool kbd_any_key(void)

{
  char cVar1;
  
  cVar1 = '\x0f';
  do {
    cVar1 = cVar1 + -1;
  } while (cVar1 != '\0');
  kbd_ko = 0x7f;
  return _DAT_ram_f040 != -1;
}

/**
 * @brief 轮询等待按键
 * @addr 0x093BA
 * @module hal
 * @proto ushort kbd_wait_key(void)
 * @confidence strong
 * @note 轮询等待按键：检测到按键立即返回 0；5 次轮询后超时，0xD150=0x1004 并返回非 0。
 * @tag kbd
 */
ushort kbd_wait_key(void)

{
  undefined2 uVar1;
  char cVar2;
  
  kbd_ko = 0x10;
  uVar1 = 0;
  cVar2 = '\x05';
  do {
    if ((_DAT_ram_f040 & 4) != 0) {
LAB_rom_0093e2:
      uVar1 = kbd_ko_disable();
      return uVar1;
    }
    cVar2 = cVar2 + -1;
    if (cVar2 == '\0') {
      last_key = 0x1004;
      goto LAB_rom_0093e2;
    }
    uVar1 = delay_10(uVar1);
  } while( true );
}

/**
 * @brief 把 16 位键位坐标换算成表内偏移
 * @addr 0x096BE
 * @module hal
 * @proto ushort key_pos_offset(ushort pos)
 * @confidence verified
 * @note 把 16 位键位坐标换算成表内偏移：高字节 × 0x28 + 低字节 × 10。原记录命名为
 *       waitkey，实际与等待按键无关（真正的等待在 0x93BA/0x221B2）。
 * @tag kbd
 */
ushort key_pos_offset(ushort pos)

{
  frame_enter();
  mul16(pos & 0xff,0x28);
  mul16(pos >> 8,10);
  frame_leave();
  return;
}

