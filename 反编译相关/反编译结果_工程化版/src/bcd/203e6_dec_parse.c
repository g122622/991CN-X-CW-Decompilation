/*
 * BCD 浮点库 / 203e6_dec_parse.c
 * 地址范围: 0x203E6 - 0x203E6
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 从缓冲区解析 10 字节 BCD 数值
 * @addr 0x203E6
 * @module bcd
 * @proto byte* dec_parse(byte* p, byte** out)
 * @confidence strong
 * @note 从缓冲区解析 10 字节 BCD 数值。
 * @tag bcd
 */
byte* dec_parse(byte* p, byte** out)

{
  bool bVar1;
  byte bVar3;
  byte *pbVar2;
  ushort uVar4;
  ushort uVar5;
  
  bVar3 = *p;
  pbVar2 = (byte *)((bVar3 & 0xf0) << 8);
  if ((bVar3 & 0xf0) == 0) {
    out[1] = (byte *)0x0;
    *out = pbVar2;
    out[3] = (byte *)0x0;
    out[2] = pbVar2;
    out[5] = (byte *)0x0;
    out[4] = pbVar2;
    out[7] = (byte *)0x0;
    out[6] = pbVar2;
    out[9] = (byte *)0x0;
    out[8] = pbVar2;
    out[0xb] = (byte *)0x0;
    out[10] = pbVar2;
    if (bVar3 != 0) {
      bVar3 = p[9];
      pbVar2 = (byte *)((ushort)(p[8] >> 4) * 10 + (ushort)(p[8] & 0xf));
      if ((bVar3 == 0) || (bVar3 == 5)) {
        pbVar2 = (byte *)CONCAT11((char)((ushort)pbVar2 >> 8) + -1 + (99 < (byte)pbVar2),
                                  (byte)pbVar2 + 0x9c);
      }
      out[8] = pbVar2;
      *(char *)((short)out + 0xf) = '\x01' - (bVar3 < 5);
      uVar4 = 0;
      bVar1 = true;
      uVar5 = 0;
      do {
        bVar1 = (bool)(bVar1 ^ 1);
        if (bVar1) {
          bVar3 = p[uVar4] >> 4;
        }
        else {
          bVar3 = p[uVar4] & 0xf;
          uVar4 = (ushort)(byte)((char)uVar4 + 1);
        }
        pbVar2 = (byte *)(uVar5 + (short)out);
        *pbVar2 = bVar3;
        bVar3 = (char)uVar5 + 1;
        uVar5 = (ushort)bVar3;
      } while ((char)((bVar3 < 0xf) << 7) < '\0');
    }
    pbVar2 = (byte *)CONCAT11((char)((ushort)pbVar2 >> 8),1);
  }
  return pbVar2;
}

