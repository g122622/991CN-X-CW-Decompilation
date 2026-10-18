/*
 * BCD 浮点库 / 1a466_dec_arith_dual.c
 * 地址范围: 0x1A466 - 0x1AC2C
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 十进制算术变体（1.9KB，0x17A78/0x17D1A/0x19DD6 调用，双操作数）
 * @addr 0x1A466
 * @module bcd
 * @proto undefined2 dec_arith_dual(void)
 * @confidence likely
 * @note 十进制算术变体（1.9KB，0x17A78/0x17D1A/0x19DD6 调用，双操作数）。
 * @tag bcd
 */
undefined2 dec_arith_dual(void)

{
  short sVar1;
  undefined2 uVar2;
  byte bVar4;
  char cVar5;
  undefined6 extraout_var;
  undefined6 extraout_var_00;
  undefined8 uVar3;
  undefined uVar6;
  undefined uVar8;
  undefined8 uVar7;
  undefined6 extraout_var_01;
  
  if (0xef < dec_flags) {
    return;
  }
  if (dec_flags_Y < 0xf0) {
    bVar4 = (dec_accum0 < dec_regY) << 7;
    if (dec_accum0 >= dec_regY) goto LAB_rom_01a490;
    do {
      dec_swap_XY();
LAB_rom_01a490:
      bVar4 = bVar4 & 0x9f;
      uVar3 = dec_accum1;
      uVar7 = dec_regY_mant;
      while( true ) {
        do {
          uVar2 = decc_sub8((byte)uVar3,(byte)((ulonglong)uVar3 >> 8), (uintptr_t)0, (uintptr_t)0)
                                 (byte)((ulonglong)uVar3 >> 0x10),(byte)((ulonglong)uVar3 >> 0x18));
          uVar3 = CONCAT62(extraout_var,uVar2);
        } while (-1 < (char)bVar4);
        uVar2 = decc_add8((byte)uVar2,(byte)((ushort)uVar2 >> 8),(byte)extraout_var, (uintptr_t)0)
                               (byte)((uint6)extraout_var >> 8));
        dec_accum1 = CONCAT62(extraout_var_00,uVar2);
        dec_regY_mant = uVar7;
        if ((char)dec_accum0 == (char)dec_regY) break;
        uVar2 = dec_shift_left4((byte)uVar2,(byte)((ushort)uVar2 >> 8));
        uVar3 = CONCAT62(extraout_var_01,uVar2);
        uVar6 = das((char)dec_accum0 + -1);
        sVar1 = (dec_accum0 >> 8) - (ushort)((char)dec_accum0 == '\0');
        bVar4 = (char)((ushort)sVar1 >> 8) << 7;
        uVar8 = das((char)sVar1);
        dec_accum0 = CONCAT11(uVar8,uVar6);
        uVar7 = dec_regY_mant;
      }
      dec_ieee_norm();
      bVar4 = 0;
    } while (dec_flags != '\0');
    bVar4 = (byte)(dec_regY >> 8);
    cVar5 = das(bVar4 - 5);
    if (bVar4 < 5) {
      cVar5 = daa(cVar5 + '\x05');
    }
    dec_regY = CONCAT11(cVar5,(char)dec_regY) & 0xfff;
    return;
  }
  dec_zero_helper();
  return;
}

/**
 * @brief 整数路径（D008 类型 0x20）
 * @addr 0x1A4F6
 * @module bcd
 * @proto void decc_int_arith(void)
 * @confidence likely
 * @note 整数路径（D008 类型 0x20）：DAA 尾数运算（2.3KB），0x1D214 在 R4>=3 时调用。
 * @tag bcd
 */
int decc_int_arith(void)

{
  ulonglong uVar1;
  undefined uVar2;
  ushort uVar3;
  byte bVar4;
  
  if (((byte)(dec_accum4 >> 8) & 0xf0) != 0x20) {
    return 0;
  }
  calc_state_g = dec_accum4 & 0xfff;
  calc_state_e = dec_accum0;
  uVar1 = calc_state_e;
  calc_state_e = (byte)dec_accum0;
  if (0xf < calc_state_e) {
    calc_state_e = calc_state_e - 6;
  }
  dec_accum7 = '\x0f' - calc_state_e;
  calc_state_e = uVar1;
  decc_packZ();
  if (dec_work_a == '\x02') {
    uVar3 = decc_int_low_word();
    dec_accum7 = 0x10 - (char)uVar3;
    dec_scale_y();
    bVar4 = dec_accum7;
    if (9 < dec_accum7) {
      bVar4 = dec_accum7 + 6;
    }
    uVar2 = das('\x14' - bVar4);
    dec_accum0 =
         CONCAT26(RAM8(0xd036),CONCAT24(_DAT_ram_d034,CONCAT22(calc_state_f,(short)CONCAT71(1,uVar2))))
    ;
    dec_accum4 = calc_state_g & 0xfff;
  }
  else {
    uVar3 = decc_int_low_word();
    dec_accum7 = (byte)uVar3;
    decc_packZ();
    calc_state_e = calc_state_e & 0xffffffffffff0000;
    uVar3 = decc_int_low_word();
    bVar4 = (byte)uVar3;
    if (bVar4 == 0) {
      if (dec_work_a == '\0') {
        dec_accum0 = 0;
        dec_accum4 = 0;
      }
      else {
        dec_accum0 =
             CONCAT71((int7)(CONCAT62((int6)(calc_state_e >> 0x10),dec_accum0) >> 8),0x14);
        dec_accum4 = calc_state_g;
        dec_ieee_norm();
      }
    }
    else if (dec_work_a == '\x01') {
      dec_accum7 = 0x10 - bVar4;
      dec_scale_y();
      bVar4 = dec_accum7;
      if (9 < dec_accum7) {
        bVar4 = dec_accum7 + 6;
      }
      uVar2 = das('\x14' - bVar4);
      dec_accum0 =
           CONCAT26(RAM8(0xd036),CONCAT24(_DAT_ram_d034,
                                      CONCAT22(calc_state_f,
                                               (short)CONCAT21((short)(CONCAT12(bVar4,dec_accum0)
                                                                      >> 8),uVar2))));
      dec_accum4 = calc_state_g & 0xfff;
    }
    else {
      dec_accum7 = bVar4;
      decc_packZ();
      dec_accum0 =
           CONCAT71((int7)(CONCAT62((int6)(calc_state_e >> 0x10),dec_accum0) >> 8),0x14);
      dec_accum4 = calc_state_g;
      dec_ieee_norm();
    }
  }
  return 0;
}

/**
 * @brief 通用十进制运算
 * @addr 0x1A61A
 * @module bcd
 * @proto void decc_generic(void)
 * @confidence likely
 * @note 通用十进制运算：按 0xD01E 分派至 0x1C4EE/0x1C670 等，并处理指数修正。
 * @tag bcd
 */
int decc_generic(void)

{
  undefined uVar1;
  byte bVar2;
  
  bVar2 = (dec_opcode == 6) << 6;
  if (dec_opcode < 6) {
    base_submode();
    if ((bVar2 >> 6 & 1) == 0) {
      return 0;
    }
    dec_swap_xy();
    dec_int_convert();
    dec_swap_xy();
    dec_swap_XZ();
    dec_int_convert();
    dec_swap_XZ();
    dec_swap_XW();
    dec_int_convert();
    dec_swap_XW();
    dec_g_Z_to_Y();
    if (dec_opcode == 5) {
      decc_carry_round();
    }
    else {
      dec_tail_round();
    }
  }
  else {
    if (dec_opcode != 6) {
      dec_swap_xy();
      dec_int_convert();
      dec_swap_xy();
      dec_swap_XZ();
      dec_int_convert();
      dec_swap_XZ();
      dec_regY = calc_state_e;
      if ((char)((ulonglong)calc_state_e >> 8) != '\x01') {
        dec_regY =
             CONCAT62((int6)((ulonglong)calc_state_e >> 0x10),CONCAT11(1,(char)calc_state_e));
        uVar1 = daa((char)(dec_accum0 >> 8) + '\x05');
        dec_accum0 = CONCAT11(uVar1,(char)dec_accum0) & 0xfff;
      }
      dec_regY_tail = calc_state_g;
      return 0;
    }
    dec_swap_YZ();
    dec_int_convert();
    dec_swap_YZ();
    dec_swap_XW();
    dec_int_convert();
    dec_swap_XW();
  }
  dec_g_Y_to_X();
  return 0;
}

/**
 * @brief 以 0xD01E=7 调用 0x1A6F0 后进入运算分派（0x1D2FE 整数加法使用）
 * @addr 0x1A6C8
 * @module bcd
 * @proto void decc_entry_7(void)
 * @confidence likely
 * @note 以 0xD01E=7 调用 0x1A6F0 后进入运算分派（0x1D2FE 整数加法使用）。
 * @tag bcd
 */
int decc_entry_7(void)

{
  dec_opcode = 7;
  decc_set_state();
  if ((char)((dec_work_a < 0xb) << 7) < '\0') {
    dec_swap_YZ();
    dec_ieee_add();
  }
  else {
    decc_generic();
    decc_arith_core();
  }
  return 0;
}

/**
 * @brief 设置 0xD05A=5（或 0x0A/8 特殊路径）并按 0x19D76 判定，0x1A6C…
 * @addr 0x1A6F0
 * @module bcd
 * @proto void decc_set_state(void)
 * @confidence likely
 * @note 设置 0xD05A=5（或 0x0A/8 特殊路径）并按 0x19D76 判定，0x1A6C8 的初始化。
 * @tag bcd
 */
int decc_set_state(void)

{
  undefined8 uVar1;
  undefined2 uVar2;
  byte bVar3;
  
  dec_work_a = '\x05';
  if ((dec_flags & 0xf0) == 0x20) {
    dec_work_a = '\n';
  }
  else {
    bVar3 = decc_unary_sign();
    if (bVar3 == 0) {
      dec_work_a = dec_work_a + '\x03';
    }
  }
  dec_swap_XY();
  if ((dec_flags & 0xf0) == 0x20) {
    dec_work_a = dec_work_a + '\x05';
  }
  else {
    bVar3 = decc_unary_sign();
    if (bVar3 == 0) {
      dec_work_a = dec_work_a + '\x03';
    }
  }
  dec_g_X_to_W();
  decc_int_prep();
  uVar2 = dec_accum4;
  uVar1 = dec_accum0;
  dec_g_W_to_Y();
  dec_g_X_to_W();
  decc_int_prep();
  calc_state_e = uVar1;
  calc_state_g = uVar2;
  return 0;
}

/**
 * @brief 0x1A15A 的入口
 * @addr 0x1A6FA
 * @module bcd
 * @proto void decc_state_check(void)
 * @confidence likely
 * @note 0x1A15A 的入口：按 D009/D019 类型设置 0xD05A 并选择规整路径。
 * @tag bcd
 */
int decc_state_check(void)

{
  undefined8 uVar1;
  undefined2 uVar2;
  byte bVar3;
  
  dec_work_a = '\x05';
  if ((dec_flags < 10) && (dec_flags_Y < 10)) {
    dec_g_Y_to_Z();
  }
  else {
    if ((dec_flags & 0xf0) == 0x20) {
      dec_work_a = '\n';
    }
    else {
      bVar3 = decc_unary_sign();
      if (bVar3 == 0) {
        dec_work_a = dec_work_a + '\x03';
      }
    }
    dec_swap_XY();
    if ((dec_flags & 0xf0) == 0x20) {
      dec_work_a = dec_work_a + '\x05';
    }
    else {
      bVar3 = decc_unary_sign();
      if (bVar3 == 0) {
        dec_work_a = dec_work_a + '\x03';
      }
    }
    dec_g_X_to_W();
    decc_int_prep();
    uVar2 = dec_accum4;
    uVar1 = dec_accum0;
    dec_g_W_to_Y();
    dec_g_X_to_W();
    decc_int_prep();
    calc_state_e = uVar1;
    calc_state_g = uVar2;
  }
  return 0;
}

/**
 * @brief D05A=0 后调用 0x1A7A4
 * @addr 0x1A79A
 * @module bcd
 * @proto void decc_int_entry(void)
 * @confidence strong
 * @note D05A=0 后调用 0x1A7A4：先清 X/Y，再按操作码走 0x1C81A/0x1C18C；清 0xD05A 的入口。
 * @tag bcd
 */
int decc_int_entry(void)

{
  byte bVar1;
  undefined uVar2;
  ushort uVar3;
  uint3 uVar4;
  char cVar5;
  
  dec_work_a = 0;
  uVar4 = CONCAT12((char)(dec_accum4 >> 8),dec_accum4) & 0xf0ffff;
  cVar5 = (char)(uVar4 >> 0x10);
  if (cVar5 == '\0') {
    dec_regY = 0x100;
    dec_regY_tail = 0x100;
  }
  else {
    if (cVar5 == ' ') {
      calc_state_g = (ushort)uVar4 & 0xfff;
      calc_state_e = (byte)dec_accum0;
      RAM8(0xd031) = (undefined)((ushort)dec_accum0 >> 8);
      calc_state_f = (undefined2)dec_accum1;
      _DAT_ram_d034 = (undefined2)((uint6)dec_accum1 >> 0x10);
      RAM8(0xd036) = (undefined2)((uint6)dec_accum1 >> 0x20);
      bVar1 = calc_state_e;
      if (0xf < calc_state_e) {
        bVar1 = calc_state_e - 6;
      }
      dec_accum7 = '\x0f' - bVar1;
      decc_packZ();
      dec_accum1 = CONCAT24(RAM8(0xd036),CONCAT22(_DAT_ram_d034,calc_state_f));
      dec_accum4 = calc_state_g;
      uVar3 = decc_int_low_word();
      dec_accum7 = 0x10 - (char)uVar3;
      dec_scale_y();
      bVar1 = dec_accum7;
      if (9 < dec_accum7) {
        bVar1 = dec_accum7 + 6;
      }
      uVar2 = das('\x14' - bVar1);
      dec_regY =
           CONCAT26(RAM8(0xd036),CONCAT24(_DAT_ram_d034,CONCAT22(calc_state_f,(short)CONCAT71(1,uVar2))
                                     ));
      dec_regY_tail = calc_state_g & 0xfff;
      dec_g_X_to_Z();
      uVar3 = decc_int_low_word();
      dec_accum7 = (byte)uVar3;
      decc_packZ();
      calc_state_e = 0;
      RAM8(0xd031) = 0;
      uVar3 = decc_int_low_word();
      if ((char)uVar3 == '\0') {
        dec_accum1 = CONCAT24(RAM8(0xd036),CONCAT22(_DAT_ram_d034,calc_state_f));
        dec_accum0 =
             (undefined2)CONCAT71((int7)(CONCAT62(dec_accum1,dec_accum0) >> 8),0x14);
        dec_accum4 = calc_state_g;
        dec_ieee_norm();
      }
      else {
        dec_accum1 = CONCAT24(RAM8(0xd036),CONCAT22(_DAT_ram_d034,calc_state_f));
        dec_accum4 = calc_state_g;
        dec_accum7 = 0x10 - (char)uVar3;
        dec_scale_y();
        bVar1 = dec_accum7;
        if (9 < dec_accum7) {
          bVar1 = dec_accum7 + 6;
        }
        uVar2 = das('\x14' - bVar1);
        calc_state_c =
             CONCAT26(RAM8(0xd036),CONCAT24(_DAT_ram_d034,
                                        CONCAT22(calc_state_f,
                                                 (short)CONCAT21((short)(CONCAT12(bVar1,
                                                  dec_accum0) >> 8),uVar2))));
        calc_state_d = calc_state_g & 0xfff;
        dec_g_X_to_Z();
        uVar3 = decc_int_low_word();
        dec_accum7 = (byte)uVar3;
        decc_packZ();
        dec_accum1 = CONCAT24(RAM8(0xd036),CONCAT22(_DAT_ram_d034,calc_state_f));
        dec_accum0 =
             (undefined2)CONCAT71((int7)(CONCAT62(dec_accum1,dec_accum0) >> 8),0x14);
        dec_accum4 = calc_state_g;
        dec_ieee_norm();
        calc_state_e = (byte)calc_state_c;
        RAM8(0xd031) = (undefined)((ulonglong)calc_state_c >> 8);
        calc_state_f = (undefined2)((ulonglong)calc_state_c >> 0x10);
        _DAT_ram_d034 = (undefined2)((ulonglong)calc_state_c >> 0x20);
        RAM8(0xd036) = (undefined2)((ulonglong)calc_state_c >> 0x30);
        calc_state_g = calc_state_d;
        dec_int_convert();
        dec_swap_YZ();
        dec_tail_round();
        dec_swap_YZ();
      }
      if (dec_work_a < 0xb) {
        dec_ieee_add();
        dec_prepare_compare();
        dec_regY = 0x100;
        dec_regY_tail = 0x100;
      }
      return 0;
    }
    dec_zero_helper();
  }
  return 0;
}

/**
 * @brief 重载 X 并按 0xD008 类型为操作数准备 0xD000/0xD010
 * @addr 0x1A7A4
 * @module bcd
 * @proto void decc_int_prep(void)
 * @confidence strong
 * @note 重载 X 并按 0xD008 类型为操作数准备 0xD000/0xD010：0 与 0x20 两种初值。
 * @tag bcd
 */
int decc_int_prep(void)

{
  byte bVar1;
  undefined uVar2;
  ushort uVar3;
  uint3 uVar4;
  char cVar5;
  
  uVar4 = CONCAT12((char)(dec_accum4 >> 8),dec_accum4) & 0xf0ffff;
  cVar5 = (char)(uVar4 >> 0x10);
  if (cVar5 == '\0') {
    dec_regY = 0x100;
    dec_regY_tail = 0x100;
  }
  else {
    if (cVar5 == ' ') {
      calc_state_g = (ushort)uVar4 & 0xfff;
      calc_state_e = (byte)dec_accum0;
      RAM8(0xd031) = (undefined)((ushort)dec_accum0 >> 8);
      calc_state_f = (undefined2)dec_accum1;
      _DAT_ram_d034 = (undefined2)((uint6)dec_accum1 >> 0x10);
      RAM8(0xd036) = (undefined2)((uint6)dec_accum1 >> 0x20);
      bVar1 = calc_state_e;
      if (0xf < calc_state_e) {
        bVar1 = calc_state_e - 6;
      }
      dec_accum7 = '\x0f' - bVar1;
      decc_packZ();
      dec_accum1 = CONCAT24(RAM8(0xd036),CONCAT22(_DAT_ram_d034,calc_state_f));
      dec_accum4 = calc_state_g;
      uVar3 = decc_int_low_word();
      dec_accum7 = 0x10 - (char)uVar3;
      dec_scale_y();
      bVar1 = dec_accum7;
      if (9 < dec_accum7) {
        bVar1 = dec_accum7 + 6;
      }
      uVar2 = das('\x14' - bVar1);
      dec_regY =
           CONCAT26(RAM8(0xd036),CONCAT24(_DAT_ram_d034,CONCAT22(calc_state_f,(short)CONCAT71(1,uVar2))
                                     ));
      dec_regY_tail = calc_state_g & 0xfff;
      dec_g_X_to_Z();
      uVar3 = decc_int_low_word();
      dec_accum7 = (byte)uVar3;
      decc_packZ();
      calc_state_e = 0;
      RAM8(0xd031) = 0;
      uVar3 = decc_int_low_word();
      if ((char)uVar3 == '\0') {
        dec_accum1 = CONCAT24(RAM8(0xd036),CONCAT22(_DAT_ram_d034,calc_state_f));
        dec_accum0 =
             (undefined2)CONCAT71((int7)(CONCAT62(dec_accum1,dec_accum0) >> 8),0x14);
        dec_accum4 = calc_state_g;
        dec_ieee_norm();
      }
      else {
        dec_accum1 = CONCAT24(RAM8(0xd036),CONCAT22(_DAT_ram_d034,calc_state_f));
        dec_accum4 = calc_state_g;
        dec_accum7 = 0x10 - (char)uVar3;
        dec_scale_y();
        bVar1 = dec_accum7;
        if (9 < dec_accum7) {
          bVar1 = dec_accum7 + 6;
        }
        uVar2 = das('\x14' - bVar1);
        calc_state_c =
             CONCAT26(RAM8(0xd036),CONCAT24(_DAT_ram_d034,
                                        CONCAT22(calc_state_f,
                                                 (short)CONCAT21((short)(CONCAT12(bVar1,
                                                  dec_accum0) >> 8),uVar2))));
        calc_state_d = calc_state_g & 0xfff;
        dec_g_X_to_Z();
        uVar3 = decc_int_low_word();
        dec_accum7 = (byte)uVar3;
        decc_packZ();
        dec_accum1 = CONCAT24(RAM8(0xd036),CONCAT22(_DAT_ram_d034,calc_state_f));
        dec_accum0 =
             (undefined2)CONCAT71((int7)(CONCAT62(dec_accum1,dec_accum0) >> 8),0x14);
        dec_accum4 = calc_state_g;
        dec_ieee_norm();
        calc_state_e = (byte)calc_state_c;
        RAM8(0xd031) = (undefined)((ulonglong)calc_state_c >> 8);
        calc_state_f = (undefined2)((ulonglong)calc_state_c >> 0x10);
        _DAT_ram_d034 = (undefined2)((ulonglong)calc_state_c >> 0x20);
        RAM8(0xd036) = (undefined2)((ulonglong)calc_state_c >> 0x30);
        calc_state_g = calc_state_d;
        dec_int_convert();
        dec_swap_YZ();
        dec_tail_round();
        dec_swap_YZ();
      }
      if (dec_work_a < 0xb) {
        dec_ieee_add();
        dec_prepare_compare();
        dec_regY = 0x100;
        dec_regY_tail = 0x100;
      }
      return 0;
    }
    dec_zero_helper();
  }
  return 0;
}

/**
 * @brief 返回 X 尾数低 16 位并规整（0x1A4F6/0x1A79A 中对位数的提取）
 * @addr 0x1A920
 * @module bcd
 * @proto ushort decc_int_low_word(void)
 * @confidence verified
 * @note 返回 X 尾数低 16 位并规整（0x1A4F6/0x1A79A 中对位数的提取）。
 * @tag bcd
 */
ushort decc_int_low_word(void)

{
  byte *pbVar1;
  char cVar2;
  char cVar3;
  byte bVar4;
  char cVar5;
  
  cVar2 = '\0';
  cVar5 = '\b';
  pbVar1 = &calc_state_f;
  while ((cVar3 = cVar2, (*pbVar1 & 0xf) != 10 && (cVar3 = cVar2 + '\x01', *pbVar1 < 0xa0))) {
    cVar2 = cVar2 + '\x02';
    pbVar1 = pbVar1 + 1;
    cVar5 = cVar5 + -1;
    if (cVar5 == '\0') {
      return (ushort)pbVar1 & 0xff00;
    }
  }
  bVar4 = cVar3 + 1;
  if (0xe < bVar4) {
    bVar4 = 0;
  }
  return CONCAT11((char)((ushort)pbVar1 >> 8),bVar4);
}

/**
 * @brief 置 _D01E=0xE（ln）并初始化 Y=3、D01D=0
 * @addr 0x1A954
 * @module bcd
 * @proto void dec_set_ln(void)
 * @confidence strong
 * @note 置 _D01E=0xE（ln）并初始化 Y=3、D01D=0。
 * @tag bcd
 */
int dec_set_ln(void)

{
  dec_opcode = 0xe;
  dec_set_y1();
  dec_flags_Y = 3;
  dec_swap_XY();
  calc_state_a = 0;
  decc_exp_large();
  return 0;
}

/**
 * @brief 一元收尾（0x19C8C/0x1C152/0x19C7A/0x1C18C，即取负）
 * @addr 0x1A976
 * @module bcd
 * @proto void dec_unary_neg(void)
 * @confidence likely
 * @note 一元收尾（0x19C8C/0x1C152/0x19C7A/0x1C18C，即取负）。
 * @tag bcd
 */
int dec_unary_neg(void)

{
  dec_g_X_to_Z();
  dec_g_X_to_Y_copy();
  dec_g_Z_to_Y();
  dec_int_convert();
  return 0;
}

/**
 * @brief 加法/乘法尾数错位对齐（DAA 链调整 X 尾数与 0xD02C 对齐量），供 0x1CE4…
 * @addr 0x1AB54
 * @module bcd
 * @proto void decc_addinit(void)
 * @confidence strong
 * @note 加法/乘法尾数错位对齐（DAA 链调整 X 尾数与 0xD02C 对齐量），供 0x1CE4E 在阶段<9 时调用。
 * @tag bcd
 */
int decc_addinit(void)

{
  undefined uVar1;
  undefined uVar3;
  ushort uVar2;
  byte bVar4;
  
  _DAT_ram_d02c = 0;
  do {
    bVar4 = daa(_DAT_ram_d02c + 5);
    _DAT_ram_d02c = bVar4 & 0xf;
    uVar1 = (undefined)dec_accum0;
    bVar4 = daa((char)(dec_accum0 >> 8) + '\x05');
    dec_accum0 = CONCAT11(bVar4,uVar1);
  } while ((char)((bVar4 < 0x10) << 7) < '\0');
  dec_accum0 = CONCAT11(bVar4,uVar1) & 0xfff;
  dec_load_deg_factor();
  dec_g_W_to_X();
  uVar1 = das((byte)dec_regY - 2);
  uVar3 = das((char)(dec_regY >> 8) - ((byte)dec_regY < 2));
  dec_regY = CONCAT11(uVar3,uVar1);
  dec_int_convert();
  dec_prepare_compare();
  if (((char)(((byte)dec_accum0 < 8) << 7) < '\0') || ((char)(dec_accum0 >> 8) != '\x01')) {
    dec_neg_core();
    uVar2 = CONCAT11((char)((ushort)dec_regY_mant >> 8),(byte)dec_regY_mant >> 4) & 0xfff;
    dec_align_tmp = (byte)uVar2;
    _DAT_ram_d02b = (undefined)(uVar2 >> 8);
    dec_load_like_gnu();
    dec_int_convert();
    dec_prepare_compare();
    dec_g_Y_to_X();
    dec_core_div();
    dec_load_deg_factor();
    dec_int_convert();
    dec_prepare_compare();
    dec_round_keep();
    dec_round_big();
    if ((dec_align_tmp & 1) != 0) {
      dec_swap_XY();
    }
    if ((dec_opcode == '\x03') ||
       (((char)((dec_regY & 0xfff0) >> 8) == '\0' && ((byte)(dec_regY & 0xfff0) < 0x90))))
    {
      dec_fixup_types();
    }
    else {
      dec_add_low();
      dec_set_Y_1e0_x();
      stat_calc_proc();
    }
    uVar1 = daa((char)(dec_accum0 >> 8) + _DAT_ram_d02c);
    dec_accum0 = CONCAT11(uVar1,(char)dec_accum0) & 0xfff;
  }
  else {
    dec_zero_helper();
  }
  return 0;
}

/**
 * @brief 带舍入的加减法
 * @addr 0x1AC2C
 * @module bcd
 * @proto void decc_rounded_add(void)
 * @confidence strong
 * @note 带舍入的加减法：置 Y=1.0 后做尾数对齐与进位（DAA/SUBC 链），供 0x1CE4E 在阶段==9 时调用。
 * @tag bcd
 */
int decc_rounded_add(void)

{
  bool bVar1;
  byte bVar3;
  ushort uVar2;
  undefined uVar4;
  
  dec_g_X_to_Z();
  dec_regY = 0x100;
  dec_regY_mant = 0;
  irq_pending_shadow = 0;
  display_dirty = 0;
  dec_regY_tail = 0x100;
  if (dec_opcode != '\x03') {
    dec_round_add();
    dec_swap_XY();
  }
  calc_state_a = 5;
  while( true ) {
    uVar4 = (undefined)dec_accum0;
    bVar3 = daa((char)(dec_accum0 >> 8) + '\x05');
    dec_accum0 = CONCAT11(bVar3,uVar4);
    if (0xf < bVar3) break;
    bVar3 = daa(calc_state_a + 5);
    calc_state_a = bVar3 & 0xf;
  }
  dec_accum0 = CONCAT11(bVar3,uVar4) & 0xfff;
  uVar2 = dec_tail_233(dec_accum0);
  if ((char)uVar2 == '\0') {
    dec_swap_XY();
    dec_round_flag = 5;
  }
  else {
    dec_round_flag = 0;
  }
  dec_ieee_add();
  dec_regY_mant = 0;
  dec_regY = 0;
  display_dirty = 0;
  irq_pending_shadow = 0;
  dec_regY_tail = 0x100;
  decc_round();
  dec_load_like_gnu();
  dec_int_convert();
  dec_prepare_compare();
  if (dec_round_flag == 0) goto LAB_rom_01acde;
  dec_round_flag = 0;
  if (dec_opcode != '\x02') goto LAB_rom_01acd6;
  while( true ) {
    if ((dec_round_flag != 0x80) && ((char)((calc_state_a == 0) << 7) < '\0')) {
      return 0;
    }
LAB_rom_01acd6:
    dec_load_like_gnu();
    dec_round_final();
LAB_rom_01acde:
    bVar1 = 0x7f < dec_round_flag;
    dec_round_flag = dec_round_flag + 0x80;
    if ((char)(bVar1 << 7) < '\0') break;
    uVar4 = daa((char)(dec_accum0 >> 8) + calc_state_a);
    dec_accum0 = CONCAT11(uVar4,(char)dec_accum0);
    if (dec_opcode != '\x02') {
      return 0;
    }
  }
  return 0;
}

