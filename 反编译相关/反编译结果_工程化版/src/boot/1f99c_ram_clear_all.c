/*
 * 启动与主流程 / 1f99c_ram_clear_all.c
 * 地址范围: 0x1F99C - 0x1F99C
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 把 0xD000 起 0x13E4 字节清零并复位若干状态（整机 RAM 数据区清空）
 * @addr 0x1F99C
 * @module boot
 * @proto void ram_clear_all(void)
 * @confidence strong
 * @note 把 0xD000 起 0x13E4 字节清零并复位若干状态（整机 RAM 数据区清空）。
 * @tag boot
 */
int ram_clear_all(void)

{
  undefined *puVar1;
  short sVar2;
  
  sVar2 = 0x13e4;
  memzero(&dec_accum0,0x13e4);
  contrast = 0x14;
  output_fmt = 0x14;
  contrast_set(0x14);
  draw_target = 1;
  puVar1 = (undefined *)get_ram_base();
  base_addr = SUB21(puVar1,0);
  editor_init(puVar1,sVar2);
  cursor_stack_fill();
  return 0;
}

