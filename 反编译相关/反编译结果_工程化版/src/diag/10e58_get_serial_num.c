/*
 * 自检与诊断 / 10e58_get_serial_num.c
 * 地址范围: 0x10E58 - 0x10E58
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 取机器序列号（casio-main 符号 get_serial_num，char* 输出）
 * @addr 0x10E58
 * @module diag
 * @proto void get_serial_num(short er0)
 * @confidence strong
 * @note 取机器序列号（casio-main 符号 get_serial_num，char* 输出）：从 0xFFF8 表逐项用
 *       0x22492 转成字符，共 6 项写入输出缓冲区 +0x0B 起。（早先误当作矩阵维度表。）
 * @tag diag
 */
int get_serial_num(short er0)

{
  byte *pbVar1;
  char cVar2;
  undefined extraout_R1;
  undefined2 *puVar3;
  char cVar4;
  ushort uVar5;
  
  puVar3 = (undefined2 *)((uintptr_t)er0 + 0xb);
  uVar5 = 0xfff8;
  cVar4 = '\x06';
  do {
    pbVar1 = (byte *)(uint3)uVar5;
    uVar5 = uVar5 + 1;
    cVar2 = hex_byte(*pbVar1);
    *puVar3 = CONCAT11(extraout_R1,cVar2);
    puVar3 = puVar3 + -1;
    cVar4 = cVar4 + -1;
  } while (cVar4 != '\0');
  return 0;
}

