/*
 * 硬件抽象层 / 252dc_key_decode.c
 * 地址范围: 0x252DC - 0x252DC
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 把 (KI 行位索引, KO 列位索引) 合并成表内偏移，返回键位映射表中对应的键码
 * @addr 0x252DC
 * @module hal
 * @proto ushort key_decode(byte* scancode, ushort table)
 * @confidence verified
 * @note 把 (KI 行位索引, KO 列位索引) 合并成表内偏移，返回键位映射表中对应的键码。
 * @tag kbd
 */
ushort key_decode(byte* scancode, ushort table)

{
  byte bVar1;
  byte bVar2;
  undefined2 uVar3;
  char cVar4;
  char cVar5;
  
  bVar1 = *scancode;
  bVar2 = scancode[1];
  if ((bVar2 == 0) || (bVar1 == 0)) {
    uVar3 = 0;
  }
  else {
    cVar4 = '\0';
    for (; bVar1 != 0; bVar1 = bVar1 >> 1) {
      cVar4 = cVar4 + '\x01';
    }
    cVar5 = '\0';
    for (; bVar2 != 0; bVar2 = bVar2 >> 1) {
      cVar5 = cVar5 + '\x01';
    }
    uVar3 = *(undefined2 *)((ushort)(byte)((cVar4 + -1) * '\b' + cVar5 + -1) * 2 + table);
  }
  return uVar3;
}

