/*
 * 启动与主流程 / 090ce_ram_check.c
 * 地址范围: 0x090CE - 0x09402
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief RAM 有效性检查
 * @addr 0x090CE
 * @module boot
 * @proto char ram_check(void)
 * @confidence verified
 * @note RAM 有效性检查：检查 0xDBD0 区、对比度范围、变量区与复数值区；检查失败返回 1（触发全清）。
 * @tag boot
 */
char ram_check(void)

{
  char cVar1;
  byte bVar2;
  char cVar4;
  undefined2 uVar3;
  byte bVar5;
  byte *pbVar6;
  char *pcVar7;
  
  pcVar7 = &diag_status;
  cVar1 = '\x0f';
  do {
    cVar4 = *pcVar7;
    uVar3 = CONCAT11(cVar4,cVar1);
    pcVar7 = pcVar7 + 1;
    if (cVar4 != cVar1) goto LAB_rom_00910c;
    cVar1 = cVar1 + -1;
  } while (cVar1 != '\0');
  uVar3 = CONCAT11(cVar4,contrast);
  if (((byte)(SBORROW1(contrast,'\x1f') ^ (char)(contrast + -0x1f) < '\0' |
             contrast == '\x1f') != 0) &&
     ((byte)(SBORROW1(contrast,'\v') ^ (char)(contrast + -0xb) < '\0') != 1)) {
    cVar1 = '\n';
    pbVar6 = (byte *)0xd31a;
    do {
      bVar2 = (pbVar6 == (byte *)0x0) << 6;
      uVar3 = is_simple_bcd(pbVar6);
      if ((bVar2 >> 6 & 1) == 0) goto LAB_rom_00910c;
      pbVar6 = pbVar6 + 10;
      cVar1 = cVar1 + -1;
    } while (cVar1 != '\0');
    uVar3 = CONCAT11((char)((ushort)uVar3 >> 8),base_addr);
    do {
      bVar2 = (byte)uVar3;
      bVar5 = (byte)((ushort)uVar3 >> 8);
      uVar3 = CONCAT11(bVar5,bVar2 * '\x02');
      if ((byte)(bVar2 * '\x02') == '\0') {
        return (ushort)bVar5 << 8;
      }
    } while (CARRY1(bVar2,bVar2) == false);
  }
LAB_rom_00910c:
  return CONCAT11((char)((ushort)uVar3 >> 8),1);
}

/**
 * @brief 上电 LCD 初始化
 * @addr 0x09118
 * @module boot
 * @proto void boot_lcd_init(void)
 * @confidence strong
 * @note 上电 LCD 初始化：0xD0F5 为 0 时清缓冲、0x8ACE 写
 *       0x1625/0x1680/0x560A时序参数、延时 0x1000 后配置 0xF031/0xF03D/0xF00A
 *       并启动显示。
 * @tag boot
 */
int boot_lcd_init(void)

{
  byte *pbVar1;
  
  if (diag_mode == '\0') {
    clear_screen();
    draw_list_scroller3((byte *)0x1625,0x1680,0x560a);
    fb_flush();
    editor_action(0x1000);
    lcd_mode = 3;
    port_h = 0;
    int_src_ctrl = 0;
    pbVar1 = (byte *)0x0;
    int_mask = 0;
    kbd_filter_off();
    kbd_ko_disable();
    timer_stop_wait();
    reset_vector(pbVar1);
    return 0;
  }
  return 0;
}

/**
 * @brief RESET 向量（中断向量表 [1]）
 * @addr 0x093FE
 * @module boot
 * @proto void reset_handler(void)
 * @confidence verified
 * @note RESET 向量（中断向量表 [1]）。BC AL, reset_entry：仅当
 *       C=0（硬复位）时进入启动代码；否则原地死循环。Ghidra 因无法理解 BC 的 C 标志语义，把它误认作普通函数。
 * @tag boot
 */
void reset_handler(void)

{
  /* ROM 0x093FE: BC AL,0x9402 —— 仅冷启动时进入 startup，
     否则原地死循环 */
  reset_entry((byte *)0);
  return;
}

/**
 * @brief 冷启动
 * @addr 0x09402
 * @module boot
 * @proto void reset_entry(void)
 * @confidence verified
 * @note 冷启动：以 0xBEE6 处的 {源:3B, 目标:3B, 长度:2B} 初始化表逐项把 ROM 数据块复制到
 *       RAM（0xFC05、0xFC46 等地址段），表以 0xFFFF 结束；随后 BL 0xB90A（仅 RT 的空函数）、清
 *       0xF000(DSR) 并跳转 main。原记录错误地把它命名为 thunk_FUN_rom_009402。
 * @tag boot
 */
int reset_entry(int _a1)

{
  undefined *puVar1;
  undefined2 *puVar2;
  ushort uVar3;
  ushort uVar4;
  ushort uVar5;
  
  uVar5 = 0xbee6;
  while( true ) {
    uVar3 = *(ushort *)(uint3)uVar5;
    if (((char)uVar3 == -1) && ((char)(uVar3 >> 8) == -1)) break;
    _a1 = *(byte **)(uint3)(uVar5 + 2);
    uVar4 = *(ushort *)(uint3)(uVar5 + 4);
    uVar5 = uVar5 + 8;
    if (uVar4 != 0) {
      if ((((ushort)_a1 & 1) == 0) && ((uVar4 & 1) == 0)) {
        do {
          puVar2 = (undefined2 *)(uint3)uVar3;
          uVar3 = uVar3 + 2;
          *(undefined2 *)ZEXT23(_a1) = *puVar2;
          _a1 = _a1 + 2;
          uVar4 = uVar4 - 2;
        } while (uVar4 != 0);
      }
      else {
        do {
          puVar1 = (undefined *)(uint3)uVar3;
          uVar3 = uVar3 + 1;
          *(undefined *)ZEXT23(_a1) = *puVar1;
          _a1 = _a1 + 1;
          uVar4 = uVar4 - 1;
        } while (uVar4 != 0);
      }
    }
  }
  nop_rt();
  _dsr = 0;
  fw_main(_a1);
  return 0;
}



// 智能字符串复制 (emit_xlt_by_mode)
// 地址: 0x203C8

