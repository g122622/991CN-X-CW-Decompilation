/*
 * 启动与主流程 / 22006_boot_key_scan.c
 * 地址范围: 0x22006 - 0x2250E
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 开机键扫描
 * @addr 0x22006
 * @module boot
 * @proto int boot_key_scan(undefined2 k)
 * @confidence strong
 * @note 开机键扫描：0xF046=1 后 0x2207E(5ms) 轮询，0xF040==0x7B 时调整键码。
 * @tag boot
 */
int boot_key_scan(undefined2 k)

{
  char cVar1;
  undefined2 uVar2;
  
  kbd_ko = 1;
  uVar2 = delay_1(CONCAT11((char)((ushort)k >> 8),5));
  if (_DAT_ram_f040 == '{') {
    uVar2 = CONCAT11((char)((ushort)uVar2 >> 8),(char)uVar2 + -1);
    do {
      uVar2 = delay_10(uVar2);
      if (_DAT_ram_f040 != '{') goto LAB_rom_02203a;
      cVar1 = (char)uVar2 + -1;
      uVar2 = CONCAT11((char)((ushort)uVar2 >> 8),cVar1);
    } while (cVar1 != '\0');
    last_key = 0x180;
  }
LAB_rom_02203a:
  kbd_ko_disable();
  return 0;
}

/**
 * @brief 上电时轮询键盘 3 次，若扫描到 0x18 位则走 0xD0F5 初始化序列
 * @addr 0x2250E
 * @module boot
 * @proto undefined2 boot_key_poll(void)
 * @confidence likely
 * @note 上电时轮询键盘 3 次，若扫描到 0x18 位则走 0xD0F5 初始化序列。
 * @tag boot
 */
undefined2 boot_key_poll(void)

{
  char cVar1;
  
  cVar1 = '\x03';
  while( true ) {
    if (_DAT_ram_f040 == 0) {
      return;
    }
    if ((_DAT_ram_f040 & 0x18) != 0) break;
    cVar1 = cVar1 + -1;
    if (cVar1 == '\0') {
      memcpy_sym(diag_status, 0, sizeof diag_status);
      _DAT_ram_dbd2 = 0;
      diag_mode = 1;
      diag_item();
      ram_clear_all();
      ui_state_init();
      return;
    }
  }
  return;
}

