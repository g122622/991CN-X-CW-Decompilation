/*
 * 表达式求值 / 1b9fc_decc_packz.c
 * 地址范围: 0x1B9FC - 0x1B9FC
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 把 Z 的 10 字节尾数按指数重新打包到 0xD03C 起的暂存区
 * @addr 0x1B9FC
 * @module eval
 * @proto void decc_packZ(void)
 * @confidence likely
 * @note 把 Z 的 10 字节尾数按指数重新打包到 0xD03C 起的暂存区。
 * @tag float
 */
int decc_packZ(void)

{
  undefined uVar1;
  undefined uVar2;
  undefined uVar3;
  undefined uVar4;
  undefined uVar5;
  undefined uVar6;
  undefined uVar7;
  undefined uVar8;
  undefined8 uVar9;
  undefined2 uVar10;
  undefined2 uVar11;
  undefined7 *puVar12;
  undefined2 uVar13;
  ulonglong uVar14;
  undefined6 extraout_var;
  undefined2 uVar15;
  
  uVar11 = _DAT_ram_d04e;
  uVar10 = _DAT_ram_d04c;
  uVar9 = _DAT_ram_d044;
  uVar8 = _DAT_ram_d043;
  uVar7 = _DAT_ram_d042;
  uVar6 = _DAT_ram_d041;
  uVar5 = _DAT_ram_d040;
  uVar4 = _DAT_ram_d03f;
  uVar3 = _DAT_ram_d03e;
  uVar2 = _DAT_ram_d03d;
  uVar1 = _DAT_ram_d03c;
  if (dec_accum7 != 0) {
    if (0x12 < dec_accum7) {
      dec_accum7 = 0x12;
    }
    _DAT_ram_d03c = (undefined)((ulonglong)calc_state_e >> 8);
    _DAT_ram_d03d = (undefined)((ulonglong)calc_state_e >> 0x10);
    _DAT_ram_d03e = (undefined)((ulonglong)calc_state_e >> 0x18);
    _DAT_ram_d03f = (undefined)((ulonglong)calc_state_e >> 0x20);
    _DAT_ram_d040 = (undefined)((ulonglong)calc_state_e >> 0x28);
    _DAT_ram_d041 = (undefined)((ulonglong)calc_state_e >> 0x30);
    _DAT_ram_d042 = (undefined)((ulonglong)calc_state_e >> 0x38);
    _DAT_ram_d043 = (undefined)calc_state_g;
    _DAT_ram_d044 = (ulonglong)(byte)((ushort)calc_state_g >> 8);
    _DAT_ram_d04c = 0;
    puVar12 = (undefined7 *)
              CONCAT11(-0x30 - ((char)((0xc3 < dec_accum7 >> 1) << 7) >> 7),
                       (dec_accum7 >> 1) + 0x3c);
    uVar15 = *(undefined2 *)((short)puVar12 + 7);
    uVar14 = CONCAT71(*puVar12,dec_accum7) & 0xffffffffffffff01;
    if ((dec_accum7 & 1) != 0) {
      uVar13 = decc_nop();
      uVar14 = CONCAT62(extraout_var,uVar13);
    }
    calc_state_e = CONCAT71((int7)(uVar14 >> 8),calc_state_e);
    calc_state_g = uVar15;
  }
  _DAT_ram_d04e = uVar11;
  _DAT_ram_d04c = uVar10;
  _DAT_ram_d044 = uVar9;
  _DAT_ram_d03c = uVar1;
  _DAT_ram_d03d = uVar2;
  _DAT_ram_d03e = uVar3;
  _DAT_ram_d03f = uVar4;
  _DAT_ram_d040 = uVar5;
  _DAT_ram_d041 = uVar6;
  _DAT_ram_d042 = uVar7;
  _DAT_ram_d043 = uVar8;
  return 0;
}

