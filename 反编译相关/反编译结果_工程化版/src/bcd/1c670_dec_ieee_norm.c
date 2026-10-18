/*
 * BCD 浮点库 / 1c670_dec_ieee_norm.c
 * 地址范围: 0x1C670 - 0x1CDE4
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 浮点规格化/舍入核心
 * @addr 0x1C670
 * @module bcd
 * @proto void dec_ieee_norm(void)
 * @confidence strong
 * @note 浮点规格化/舍入核心。
 * @tag bcd
 */
int dec_ieee_norm(void)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  undefined2 uVar5;
  byte bVar11;
  undefined6 extraout_var;
  undefined8 uVar6;
  ulonglong uVar7;
  char cVar9;
  ulonglong uVar8;
  undefined uVar12;
  undefined uVar14;
  byte *pbVar13;
  byte bVar15;
  byte bVar10;
  undefined6 extraout_var_00;
  
  uVar4 = _DAT_ram_d04e;
  uVar3 = _DAT_ram_d04c;
  uVar2 = _DAT_ram_d044;
  uVar1 = _DAT_ram_d03c;
  if (0xef < dec_flags) {
    return 0;
  }
  if ((char)((dec_flags < 0x10) << 7) < '\0') {
    pbVar13 = &dec_flags;
    bVar15 = 0;
    if (dec_flags == 0) {
      bVar10 = 1;
      cVar9 = '\a';
      while( true ) {
        pbVar13 = (byte *)CONCAT11((char)((ushort)pbVar13 >> 8) - ((char)pbVar13 == '\0'),
                                   (char)pbVar13 + -1);
        bVar15 = bVar10;
        if ((0xe < *pbVar13) || (bVar15 = bVar10 + 1, *pbVar13 != 0)) break;
        bVar10 = bVar10 + 2;
        cVar9 = cVar9 + -1;
        if (cVar9 == '\0') {
          dec_accum0 = 0;
          dec_accum1 = 0;
          return 0;
        }
      }
    }
    dec_accum7 = bVar15;
    if (bVar15 != 0) {
      _DAT_ram_d044 = dec_accum1;
      _DAT_ram_d03c = 0;
      uVar6 = *(undefined8 *)CONCAT11(-0x30 - (0x44 < bVar15 >> 1),'D' - (bVar15 >> 1));
      if ((bVar15 & 1) != 0) {
        uVar5 = dec_shift_left4((byte)uVar6,(byte)((ulonglong)uVar6 >> 8));
        uVar6 = CONCAT62(extraout_var_00,uVar5);
      }
      bVar15 = dec_accum7;
      if (9 < dec_accum7) {
        bVar15 = dec_accum7 + 6;
      }
      uVar12 = das((byte)dec_accum0 - bVar15);
      uVar14 = das((char)((ushort)dec_accum0 >> 8) - ((byte)dec_accum0 < bVar15));
      dec_accum0 = CONCAT11(uVar14,uVar12);
      dec_accum1 = uVar6;
    }
  }
  else {
    uVar5 = dec_shift_right4((byte)dec_accum1,(byte)((ulonglong)dec_accum1 >> 8), (uintptr_t)0)
                           (byte)((ulonglong)dec_accum1 >> 0x10));
    uVar12 = daa((byte)dec_accum0 + 1);
    uVar14 = daa((char)((ushort)dec_accum0 >> 8) + (0xfe < (byte)dec_accum0));
    dec_accum0 = CONCAT11(uVar14,uVar12);
    dec_accum1 = CONCAT62(extraout_var,uVar5);
  }
  uVar8 = (ulonglong)CONCAT12(5,dec_accum0);
  do {
    uVar7 = uVar8 & 0xffffffffffff0fff;
    bVar15 = (byte)(uVar7 >> 8);
    bVar11 = (byte)(uVar7 >> 0x10);
    cVar9 = bVar15 - bVar11;
    bVar10 = das(cVar9);
    uVar8 = CONCAT62((int6)(uVar7 >> 0x10),CONCAT11(bVar10,(char)uVar7));
  } while (bVar15 < bVar11);
  if (cVar9 == '\0') {
    if ((char)uVar7 != '\0') {
      _DAT_ram_d03c = uVar1;
      _DAT_ram_d044 = uVar2;
      _DAT_ram_d04c = uVar3;
      _DAT_ram_d04e = uVar4;
      return 0;
    }
  }
  else {
    if (bVar10 == 2) {
      dec_zero_helper();
      _DAT_ram_d03c = uVar1;
      _DAT_ram_d044 = uVar2;
      _DAT_ram_d04c = uVar3;
      _DAT_ram_d04e = uVar4;
      return 0;
    }
    if (bVar10 < 2) {
      _DAT_ram_d03c = uVar1;
      _DAT_ram_d044 = uVar2;
      _DAT_ram_d04c = uVar3;
      _DAT_ram_d04e = uVar4;
      return 0;
    }
  }
  dec_accum1 = 0;
  dec_accum0 = 0;
  _DAT_ram_d04e = uVar4;
  _DAT_ram_d04c = uVar3;
  _DAT_ram_d044 = uVar2;
  _DAT_ram_d03c = uVar1;
  return 0;
}

/**
 * @brief 尾数修正
 * @addr 0x1C796
 * @module bcd
 * @proto ushort dec_tail_233(ushort x)
 * @confidence strong
 * @note 尾数修正：去掉尾数尾部，按 DAT_ram_d00a 的精度位数做 DAA/DAS 规范化，返回修正后的尾数。
 * @tag bcd
 */
ushort dec_tail_233(ushort x)

{
  short sVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  byte bVar8;
  ushort uVar5;
  undefined uVar9;
  uint uVar6;
  ulonglong uVar7;
  ushort uVar10;
  
  if ((0xef < dec_flags) || (0xef < dec_flags_Y)) {
    return x & 0xff00;
  }
  bVar8 = (byte)((ushort)dec_regY >> 8);
  if (bVar8 < 5) {
    uVar9 = daa(bVar8 + 5);
    uVar6 = CONCAT13(uVar9,(int3)CONCAT22(dec_regY,dec_accum0)) & 0xfffffff;
    uVar7 = (ulonglong)CONCAT14(6,uVar6);
    dec_regY = (undefined2)(uVar6 >> 0x10);
  }
  else {
    uVar7 = (ulonglong)CONCAT22(dec_regY,dec_accum0);
  }
  dec_accum6 = (char)(uVar7 >> 0x20);
  bVar8 = (byte)(uVar7 >> 0x10);
  cVar3 = (byte)uVar7 - bVar8;
  cVar4 = das(cVar3);
  uVar10 = ((ushort)(byte)(uVar7 >> 8) - (ushort)(byte)(uVar7 >> 0x18)) -
           (ushort)((byte)uVar7 < bVar8);
  cVar2 = (char)uVar10;
  uVar9 = das(cVar2);
  uVar5 = CONCAT11(uVar9,cVar4);
  uVar7 = (ulonglong)uVar5;
  if ((uVar10 & 0x100) == 0) {
    if ((cVar3 == '\0' && cVar2 == '\0') && (cVar4 == '\0')) {
      das((byte)dec_accum1 - (byte)dec_regY_mant);
      sVar1 = ((ushort)(byte)((uint7)dec_accum1 >> 8) - (ushort)(byte)((uint7)dec_regY_mant >> 8)
              ) - (ushort)((byte)dec_accum1 < (byte)dec_regY_mant);
      bVar8 = das((char)sVar1);
      sVar1 = ((ushort)(byte)((uint7)dec_accum1 >> 0x10) -
              (ushort)(byte)((uint7)dec_regY_mant >> 0x10)) -
              (ushort)((byte)((ushort)sVar1 >> 8) & 1);
      das((char)sVar1);
      sVar1 = ((ushort)(byte)((uint7)dec_accum1 >> 0x18) -
              (ushort)(byte)((uint7)dec_regY_mant >> 0x18)) -
              (ushort)((byte)((ushort)sVar1 >> 8) & 1);
      das((char)sVar1);
      sVar1 = ((ushort)(byte)((uint7)dec_accum1 >> 0x20) -
              (ushort)(byte)((uint7)dec_regY_mant >> 0x20)) -
              (ushort)((byte)((ushort)sVar1 >> 8) & 1);
      das((char)sVar1);
      sVar1 = ((ushort)(byte)((uint7)dec_accum1 >> 0x28) -
              (ushort)(byte)((uint7)dec_regY_mant >> 0x28)) -
              (ushort)((byte)((ushort)sVar1 >> 8) & 1);
      uVar10 = (ushort)(CONCAT17(dec_flags,dec_accum1) >> 0x30);
      das((char)sVar1);
      sVar1 = ((uVar10 & 0xff) - (ushort)(byte)((uint7)dec_regY_mant >> 0x30)) -
              (ushort)((byte)((ushort)sVar1 >> 8) & 1);
      das((char)sVar1);
      uVar10 = ((uVar10 >> 8) - (ushort)dec_flags_Y) - (ushort)((byte)((ushort)sVar1 >> 8) & 1);
      das((char)uVar10);
      uVar7 = (ulonglong)bVar8 << 8;
      uVar5 = (ushort)uVar7;
      if ((uVar10 & 0x100) != 0) goto LAB_rom_01c80e;
    }
    uVar5 = uVar5 & 0xff00;
  }
  else {
LAB_rom_01c80e:
    uVar5 = (ushort)CONCAT71((int7)(uVar7 >> 8),1);
  }
  return uVar5;
}

/**
 * @brief 清 0xD000..0xD009（运算寄存器）
 * @addr 0x1C81A
 * @module bcd
 * @proto void dec_zero_helper(void)
 * @confidence strong
 * @note 清 0xD000..0xD009（运算寄存器）。
 * @tag bcd
 */
int dec_zero_helper(void)

{
  dec_accum0 = 0;
  dec_accum1 = 0;
  dec_accum2 = 0;
  dec_accum3 = 0;
  dec_accum4 = 0;
  dec_flags = 0xf3;
  return 0;
}

/**
 * @brief opcode 9（乘法）核心入口
 * @addr 0x1C830
 * @module bcd
 * @proto int dec_bin_mul_core(undefined2 a, undefined2* b)
 * @confidence verified
 * @note opcode 9（乘法）核心入口：设 0xD01E=9 后跳到 0x1C8A6 公共尾部。
 * @tag bcd
 */
int dec_bin_mul_core(undefined2 a, undefined2* b)

{
  undefined2 uVar1;
  char cVar3;
  ushort uVar2;
  
  dec_opcode = 9;
  dec_param_a = a;
  dec_param_b = b;
  dec_load(b);
  uVar1 = dec_check_nan_XY();
  if ((char)uVar1 != '\0') {
    dec_zero_helper();
    goto LAB_rom_01c90e;
  }
  cVar3 = (char)((ushort)uVar1 >> 8);
  decc_load_Y();
  if (dec_opcode < 5) {
    dec_tail_round();
LAB_rom_01c8f6:
    if (cVar3 != -0x80) goto LAB_rom_01c90e;
  }
  else {
    if (dec_opcode == 5) {
      decc_carry_round();
      goto LAB_rom_01c8f6;
    }
    if (dec_opcode < 7) {
      dec_int_convert();
    }
    else {
      if (dec_opcode != 7) {
        if (dec_opcode < 9) {
          dec_core_op8();
        }
        else {
          if (dec_opcode != 9) goto LAB_rom_01c8ce;
          dec_core_op9();
        }
        goto LAB_rom_01c8f6;
      }
LAB_rom_01c8ce:
      dec_ieee_add();
    }
    if (cVar3 != '@') goto LAB_rom_01c90e;
  }
  uVar2 = dec_load_union();
  if ((char)uVar2 == '\x02') {
    dec_flags = dec_flags | 0x40;
  }
LAB_rom_01c90e:
  dec_store();
  dec_status_low();
  return 0;
}

/**
 * @brief opcode 8（除法）核心入口
 * @addr 0x1C844
 * @module bcd
 * @proto int dec_bin_div_core(undefined2 a, undefined2* b)
 * @confidence likely
 * @note opcode 8（除法）核心入口：设 0xD01E=8 后跳到 0x1C8A6 公共尾部。
 * @tag bcd
 */
int dec_bin_div_core(undefined2 a, undefined2* b)

{
  undefined2 uVar1;
  char cVar3;
  ushort uVar2;
  
  dec_opcode = 8;
  dec_param_a = a;
  dec_param_b = b;
  dec_load(b);
  uVar1 = dec_check_nan_XY();
  if ((char)uVar1 != '\0') {
    dec_zero_helper();
    goto LAB_rom_01c90e;
  }
  cVar3 = (char)((ushort)uVar1 >> 8);
  decc_load_Y();
  if (dec_opcode < 5) {
    dec_tail_round();
LAB_rom_01c8f6:
    if (cVar3 != -0x80) goto LAB_rom_01c90e;
  }
  else {
    if (dec_opcode == 5) {
      decc_carry_round();
      goto LAB_rom_01c8f6;
    }
    if (dec_opcode < 7) {
      dec_int_convert();
    }
    else {
      if (dec_opcode != 7) {
        if (dec_opcode < 9) {
          dec_core_op8();
        }
        else {
          if (dec_opcode != 9) goto LAB_rom_01c8ce;
          dec_core_op9();
        }
        goto LAB_rom_01c8f6;
      }
LAB_rom_01c8ce:
      dec_ieee_add();
    }
    if (cVar3 != '@') goto LAB_rom_01c90e;
  }
  uVar2 = dec_load_union();
  if ((char)uVar2 == '\x02') {
    dec_flags = dec_flags | 0x40;
  }
LAB_rom_01c90e:
  dec_store();
  dec_status_low();
  return 0;
}

/**
 * @brief opcode 5（逻辑或）核心入口
 * @addr 0x1C858
 * @module bcd
 * @proto int dec_bin_or_core(undefined2 a, undefined2* b)
 * @confidence likely
 * @note opcode 5（逻辑或）核心入口。
 * @tag bcd
 */
int dec_bin_or_core(undefined2 a, undefined2* b)

{
  undefined2 uVar1;
  char cVar3;
  ushort uVar2;
  
  dec_opcode = 5;
  dec_param_a = a;
  dec_param_b = b;
  dec_load(b);
  uVar1 = dec_check_nan_XY();
  if ((char)uVar1 != '\0') {
    dec_zero_helper();
    goto LAB_rom_01c90e;
  }
  cVar3 = (char)((ushort)uVar1 >> 8);
  decc_load_Y();
  if (dec_opcode < 5) {
    dec_tail_round();
LAB_rom_01c8f6:
    if (cVar3 != -0x80) goto LAB_rom_01c90e;
  }
  else {
    if (dec_opcode == 5) {
      decc_carry_round();
      goto LAB_rom_01c8f6;
    }
    if (dec_opcode < 7) {
      dec_int_convert();
    }
    else {
      if (dec_opcode != 7) {
        if (dec_opcode < 9) {
          dec_core_op8();
        }
        else {
          if (dec_opcode != 9) goto LAB_rom_01c8ce;
          dec_core_op9();
        }
        goto LAB_rom_01c8f6;
      }
LAB_rom_01c8ce:
      dec_ieee_add();
    }
    if (cVar3 != '@') goto LAB_rom_01c90e;
  }
  uVar2 = dec_load_union();
  if ((char)uVar2 == '\x02') {
    dec_flags = dec_flags | 0x40;
  }
LAB_rom_01c90e:
  dec_store();
  dec_status_low();
  return 0;
}

/**
 * @brief opcode 6（乘方）核心入口
 * @addr 0x1C86C
 * @module bcd
 * @proto int dec_bin_pow_core(undefined2 a, undefined2* b)
 * @confidence verified
 * @note opcode 6（乘方）核心入口：设 0xD01E=6 后跳到 0x1C8A6 公共尾部。
 * @tag bcd
 */
int dec_bin_pow_core(undefined2 a, undefined2* b)

{
  undefined2 uVar1;
  char cVar3;
  ushort uVar2;
  
  dec_opcode = 6;
  dec_param_a = a;
  dec_param_b = b;
  dec_load(b);
  uVar1 = dec_check_nan_XY();
  if ((char)uVar1 != '\0') {
    dec_zero_helper();
    goto LAB_rom_01c90e;
  }
  cVar3 = (char)((ushort)uVar1 >> 8);
  decc_load_Y();
  if (dec_opcode < 5) {
    dec_tail_round();
LAB_rom_01c8f6:
    if (cVar3 != -0x80) goto LAB_rom_01c90e;
  }
  else {
    if (dec_opcode == 5) {
      decc_carry_round();
      goto LAB_rom_01c8f6;
    }
    if (dec_opcode < 7) {
      dec_int_convert();
    }
    else {
      if (dec_opcode != 7) {
        if (dec_opcode < 9) {
          dec_core_op8();
        }
        else {
          if (dec_opcode != 9) goto LAB_rom_01c8ce;
          dec_core_op9();
        }
        goto LAB_rom_01c8f6;
      }
LAB_rom_01c8ce:
      dec_ieee_add();
    }
    if (cVar3 != '@') goto LAB_rom_01c90e;
  }
  uVar2 = dec_load_union();
  if ((char)uVar2 == '\x02') {
    dec_flags = dec_flags | 0x40;
  }
LAB_rom_01c90e:
  dec_store();
  dec_status_low();
  return 0;
}

/**
 * @brief opcode 7（逻辑与）核心入口
 * @addr 0x1C880
 * @module bcd
 * @proto int dec_bin_and_core(undefined2 a, undefined2* b)
 * @confidence verified
 * @note opcode 7（逻辑与）核心入口。
 * @tag bcd
 */
int dec_bin_and_core(undefined2 a, undefined2* b)

{
  undefined2 uVar1;
  char cVar3;
  ushort uVar2;
  
  dec_opcode = 7;
  dec_param_a = a;
  dec_param_b = b;
  dec_load(b);
  uVar1 = dec_check_nan_XY();
  if ((char)uVar1 != '\0') {
    dec_zero_helper();
    goto LAB_rom_01c90e;
  }
  cVar3 = (char)((ushort)uVar1 >> 8);
  decc_load_Y();
  if (dec_opcode < 5) {
    dec_tail_round();
LAB_rom_01c8f6:
    if (cVar3 != -0x80) goto LAB_rom_01c90e;
  }
  else {
    if (dec_opcode == 5) {
      decc_carry_round();
      goto LAB_rom_01c8f6;
    }
    if (dec_opcode < 7) {
      dec_int_convert();
    }
    else {
      if (dec_opcode != 7) {
        if (dec_opcode < 9) {
          dec_core_op8();
        }
        else {
          if (dec_opcode != 9) goto LAB_rom_01c8ce;
          dec_core_op9();
        }
        goto LAB_rom_01c8f6;
      }
LAB_rom_01c8ce:
      dec_ieee_add();
    }
    if (cVar3 != '@') goto LAB_rom_01c90e;
  }
  uVar2 = dec_load_union();
  if ((char)uVar2 == '\x02') {
    dec_flags = dec_flags | 0x40;
  }
LAB_rom_01c90e:
  dec_store();
  dec_status_low();
  return 0;
}

/**
 * @brief opcode 4（逻辑异或）核心入口
 * @addr 0x1C894
 * @module bcd
 * @proto int dec_bin_xor_core(undefined2 a, undefined2* b)
 * @confidence likely
 * @note opcode 4（逻辑异或）核心入口。
 * @tag bcd
 */
int dec_bin_xor_core(undefined2 a, undefined2* b)

{
  undefined2 uVar1;
  char cVar3;
  ushort uVar2;
  
  dec_opcode = 4;
  dec_param_a = a;
  dec_param_b = b;
  dec_load(b);
  uVar1 = dec_check_nan_XY();
  if ((char)uVar1 != '\0') {
    dec_zero_helper();
    goto LAB_rom_01c90e;
  }
  cVar3 = (char)((ushort)uVar1 >> 8);
  decc_load_Y();
  if (dec_opcode < 5) {
    dec_tail_round();
LAB_rom_01c8f6:
    if (cVar3 != -0x80) goto LAB_rom_01c90e;
  }
  else {
    if (dec_opcode == 5) {
      decc_carry_round();
      goto LAB_rom_01c8f6;
    }
    if (dec_opcode < 7) {
      dec_int_convert();
    }
    else {
      if (dec_opcode != 7) {
        if (dec_opcode < 9) {
          dec_core_op8();
        }
        else {
          if (dec_opcode != 9) goto LAB_rom_01c8ce;
          dec_core_op9();
        }
        goto LAB_rom_01c8f6;
      }
LAB_rom_01c8ce:
      dec_ieee_add();
    }
    if (cVar3 != '@') goto LAB_rom_01c90e;
  }
  uVar2 = dec_load_union();
  if ((char)uVar2 == '\x02') {
    dec_flags = dec_flags | 0x40;
  }
LAB_rom_01c90e:
  dec_store();
  dec_status_low();
  return 0;
}

/**
 * @brief 通过 0x17A1A 与 0x19A56 组合实现乘法（另一条乘法路径，返回状态）
 * @addr 0x1C9D8
 * @module bcd
 * @proto undefined2 dec_mul_via_bcd(undefined2* a, undefined2* b)
 * @confidence likely
 * @note 通过 0x17A1A 与 0x19A56 组合实现乘法（另一条乘法路径，返回状态）。
 * @tag bcd
 */
undefined2 dec_mul_via_bcd(undefined2* a, undefined2* b)

{
  undefined2 uVar1;
  
  dec_param_a = a;
  dec_param_b = b;
  dec_bin_arith();
  dec_load(b);
  uVar1 = dec_check_nan_XY();
  if ((char)uVar1 == '\0') {
    decc_load_Y();
    uVar1 = dec_normalize_x();
    if ((char)uVar1 != '\0') {
      dec_load(dec_param_b);
      dec_check_nan_XY();
      decc_load_Y();
      dec_ieee_add();
      dec_regY_mant = 0;
      dec_regY = 0;
      display_dirty = 0;
      irq_pending_shadow = 0;
      dec_regY_tail = 0x7000;
    }
    dec_store_result();
  }
  else {
    dec_zero_helper();
  }
  dec_store();
  dec_status_low();
  return;
}

/**
 * @brief 二元运算收尾
 * @addr 0x1CBB2
 * @module bcd
 * @proto ushort* dec_bin_result(ushort* a, undefined2 b)
 * @confidence strong
 * @note 二元运算收尾：把结果寄存器写回 *a 并清 0x40 标志位。
 * @tag bcd
 */
ushort* dec_bin_result(ushort* a, undefined2 b)

{
  char cVar1;
  undefined2 uVar2;
  ushort uVar3;
  byte bVar4;
  
  uVar2 = dec_cmp(a,b);
  cVar1 = (char)uVar2;
  if (cVar1 != -0x10) {
    bVar4 = *(byte *)a;
    *(byte *)a = bVar4 & 0xbf;
    if (cVar1 == '\x02') {
      a = (ushort *)dec_inc5(a,CONCAT11(bVar4,cVar1) & 0xbfff);
    }
    return (ushort)a & 0xff00;
  }
  uVar3 = dec_set_special(a,3);
  return CONCAT11((char)(uVar3 >> 8),3);
}

/**
 * @brief 取绝对值包装
 * @addr 0x1CC9A
 * @module bcd
 * @proto void dec_abs_wrap(void)
 * @confidence likely
 * @note 取绝对值包装：0x1A36A 后把 P 写回 X 并收尾（0x1C392/0x1C3B8/0x1C3C8）。
 * @tag bcd
 */
int dec_abs_wrap(void)

{
  undefined8 in_QR0;
  
  dec_param_b = (undefined2 *)((ulonglong)in_QR0 >> 0x10);
  dec_param_a = (undefined2)in_QR0;
  dec_load(dec_param_b);
  dec_arith_neg();
  dec_regY = calc_state_c;
  dec_regY_tail = calc_state_d;
  dec_store();
  dec_store_result();
  dec_status_low();
  return 0;
}

/**
 * @brief 十进制运算入口
 * @addr 0x1CDE4
 * @module bcd
 * @proto byte decc_op(undefined2* a, undefined2* b)
 * @confidence strong
 * @note 十进制运算入口：设置 _D05C/_D05E 后以操作码 (char)param_2 调用 0x1CE4E，返回是否成功。
 * @tag bcd
 */
byte decc_op(undefined2* a, undefined2* b)

{
  dec_param_a = a;
  dec_param_b = b;
  decm_arith((char)b, (uintptr_t)0);
  return;
}

