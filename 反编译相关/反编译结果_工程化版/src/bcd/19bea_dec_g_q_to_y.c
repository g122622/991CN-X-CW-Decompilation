/*
 * BCD 浮点库 / 19bea_dec_g_q_to_y.c
 * 地址范围: 0x19BEA - 0x1A36A
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief Y ← Q（0xD046/0xD04E → 0xD010/0xD018）
 * @addr 0x19BEA
 * @module bcd
 * @proto void dec_g_Q_to_Y(void)
 * @confidence verified
 * @note Y ← Q（0xD046/0xD04E → 0xD010/0xD018）。
 * @tag bcd
 */
int dec_g_Q_to_Y(void)

{
  dec_regY = _DAT_ram_d046;
  dec_regY_tail = _DAT_ram_d04e;
  return 0;
}

/**
 * @brief Q ← Y（0xD010/0xD018 → 0xD046/0xD04E）
 * @addr 0x19BFC
 * @module bcd
 * @proto void dec_g_Y_to_Q(void)
 * @confidence verified
 * @note Q ← Y（0xD010/0xD018 → 0xD046/0xD04E）。
 * @tag bcd
 */
int dec_g_Y_to_Q(void)

{
  _DAT_ram_d046 = dec_regY;
  _DAT_ram_d04e = dec_regY_tail;
  return 0;
}

/**
 * @brief W ← X 的重叠视图（0xD018 → 0xD038），取负结果搬移用
 * @addr 0x19C0E
 * @module bcd
 * @proto void dec_g_X_to_W2(void)
 * @confidence verified
 * @note W ← X 的重叠视图（0xD018 → 0xD038），取负结果搬移用。
 * @tag bcd
 */
int dec_g_X_to_W2(void)

{
  _DAT_ram_d046 = dec_accum0;
  _DAT_ram_d04e = dec_accum4;
  return 0;
}

/**
 * @brief X ← Z 的第 4 块（0xD03C/0xD044 → 0xD000/0xD008）
 * @addr 0x19C20
 * @module bcd
 * @proto void dec_g_Z4_to_X(void)
 * @confidence verified
 * @note X ← Z 的第 4 块（0xD03C/0xD044 → 0xD000/0xD008）。
 * @tag bcd
 */
int dec_g_Z4_to_X(void)

{
  dec_accum0 = _DAT_ram_d03c;
  dec_accum4 = _DAT_ram_d044;
  return 0;
}

/**
 * @brief Y ← Z 的第 4 个 8 字节块（0xD03C/0xD044 → 0xD010/0xD0…
 * @addr 0x19C32
 * @module bcd
 * @proto void dec_g_Z4_to_Y(void)
 * @confidence verified
 * @note Y ← Z 的第 4 个 8 字节块（0xD03C/0xD044 → 0xD010/0xD018）。
 * @tag bcd
 */
int dec_g_Z4_to_Y(void)

{
  dec_regY = _DAT_ram_d03c;
  dec_regY_tail = _DAT_ram_d044;
  return 0;
}

/**
 * @brief Z 的第 4 块 ← X（0xD03C/0xD044 ← 0xD000/0xD008）
 * @addr 0x19C44
 * @module bcd
 * @proto void dec_g_X_to_Z4(void)
 * @confidence verified
 * @note Z 的第 4 块 ← X（0xD03C/0xD044 ← 0xD000/0xD008）。
 * @tag bcd
 */
int dec_g_X_to_Z4(void)

{
  _DAT_ram_d03c = dec_accum0;
  _DAT_ram_d044 = dec_accum4;
  return 0;
}

/**
 * @brief X ← Y（0xD010 → 0xD000，含 0xD018 → 0xD008）
 * @addr 0x19C56
 * @module bcd
 * @proto int dec_g_Y_to_X(void)
 * @confidence verified
 * @note X ← Y（0xD010 → 0xD000，含 0xD018 → 0xD008）。与 0x19CB0 的 X←Y 为
 *       Ghidra 按 8 字节/2 字节拆分出的两个重叠视图。
 * @tag bcd
 */
int dec_g_Y_to_X(void)

{
  dec_regY = dec_regW;
  dec_regY_tail = dec_regW_tail;
  return 0;
}

/**
 * @brief X ← W（0xD050 → 0xD000，含 0xD058 → 0xD008）
 * @addr 0x19C68
 * @module bcd
 * @proto void dec_g_W_to_X(void)
 * @confidence verified
 * @note X ← W（0xD050 → 0xD000，含 0xD058 → 0xD008）。
 * @tag bcd
 */
int dec_g_W_to_X(void)

{
  dec_regW = dec_accum0;
  dec_regW_tail = dec_accum4;
  return 0;
}

/**
 * @brief Y ← Z（0xD030/0xD038 → 0xD010/0xD018）
 * @addr 0x19C7A
 * @module bcd
 * @proto void dec_g_Z_to_Y(void)
 * @confidence verified
 * @note Y ← Z（0xD030/0xD038 → 0xD010/0xD018）。
 * @tag bcd
 */
int dec_g_Z_to_Y(void)

{
  dec_regY = calc_state_e;
  dec_regY_tail = calc_state_g;
  return 0;
}

/**
 * @brief Z ← X（0xD000/0xD008 → 0xD030/0xD038）
 * @addr 0x19C8C
 * @module bcd
 * @proto void dec_g_X_to_Z(void)
 * @confidence verified
 * @note Z ← X（0xD000/0xD008 → 0xD030/0xD038）。
 * @tag bcd
 */
int dec_g_X_to_Z(void)

{
  calc_state_e = dec_accum0;
  calc_state_g = dec_accum4;
  return 0;
}

/**
 * @brief Z ← X 的重叠视图（0xD000/0xD008 → 0xD010/0xD018）
 * @addr 0x19C9E
 * @module bcd
 * @proto void dec_g_X_to_Z2(void)
 * @confidence verified
 * @note Z ← X 的重叠视图（0xD000/0xD008 → 0xD010/0xD018）。
 * @tag bcd
 */
int dec_g_X_to_Z2(void)

{
  dec_regY = dec_accum0;
  dec_regY_tail = dec_accum4;
  return 0;
}

/**
 * @brief Y ← X（0xD010/0xD018 ← 0xD000/0xD008）
 * @addr 0x19CB0
 * @module bcd
 * @proto void dec_g_X_to_Y(void)
 * @confidence verified
 * @note Y ← X（0xD010/0xD018 ← 0xD000/0xD008）。
 * @tag bcd
 */
int dec_g_X_to_Y(void)

{
  dec_accum0 = dec_regY;
  dec_accum4 = dec_regY_tail;
  return 0;
}

/**
 * @brief W ← X（0xD050/0xD058 ← 0xD010/0xD018）
 * @addr 0x19CC2
 * @module bcd
 * @proto void dec_g_X_to_W(void)
 * @confidence verified
 * @note W ← X（0xD050/0xD058 ← 0xD010/0xD018）。
 * @tag bcd
 */
int dec_g_X_to_W(void)

{
  dec_regW = dec_regY;
  dec_regW_tail = dec_regY_tail;
  return 0;
}

/**
 * @brief Y ← W（0xD010/0xD018 ← 0xD050/0xD058）
 * @addr 0x19CD4
 * @module bcd
 * @proto void dec_g_W_to_Y(void)
 * @confidence verified
 * @note Y ← W（0xD010/0xD018 ← 0xD050/0xD058）。
 * @tag bcd
 */
int dec_g_W_to_Y(void)

{
  dec_accum0 = dec_regW;
  dec_accum4 = dec_regW_tail;
  return 0;
}

/**
 * @brief X ← Z（0xD030/0xD038 → 0xD000/0xD008）
 * @addr 0x19CE6
 * @module bcd
 * @proto void dec_g_Z4_to_X2(void)
 * @confidence verified
 * @note X ← Z（0xD030/0xD038 → 0xD000/0xD008）。
 * @tag bcd
 */
int dec_g_Z4_to_X2(void)

{
  dec_accum0 = calc_state_e;
  dec_accum4 = calc_state_g;
  return 0;
}

/**
 * @brief Z ← Y（0xD030/0xD038 ← 0xD010/0xD018）
 * @addr 0x19CF8
 * @module bcd
 * @proto void dec_g_Y_to_Z(void)
 * @confidence verified
 * @note Z ← Y（0xD030/0xD038 ← 0xD010/0xD018）。
 * @tag bcd
 */
int dec_g_Y_to_Z(void)

{
  calc_state_e = dec_regY;
  calc_state_g = dec_regY_tail;
  return 0;
}

/**
 * @brief 扫描 0xD002 起尾数字节，返回首个非零半字节位置
 * @addr 0x19D4A
 * @module bcd
 * @proto byte dec_scan_digits(void)
 * @confidence likely
 * @note 扫描 0xD002 起尾数字节，返回首个非零半字节位置。
 * @tag bcd
 */
byte dec_scan_digits(void)

{
  byte *pbVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  
  cVar2 = '\0';
  cVar4 = '\b';
  pbVar1 = &dec_accum1;
  do {
    cVar3 = cVar2;
    if (((*pbVar1 & 0xf) != 0) || (cVar3 = cVar2 + '\x01', *pbVar1 != 0)) break;
    cVar2 = cVar2 + '\x02';
    pbVar1 = pbVar1 + 1;
    cVar4 = cVar4 + -1;
    cVar3 = cVar2;
  } while (cVar4 != '\0');
  return CONCAT11((char)((ushort)pbVar1 >> 8),cVar3);
}

/**
 * @brief 按 X 尾数首位非零半字节左移尾数（8 字节循环），返回移位数
 * @addr 0x19D6E
 * @module bcd
 * @proto byte dec_shift_mant(void)
 * @confidence likely
 * @note 按 X 尾数首位非零半字节左移尾数（8 字节循环），返回移位数。
 * @tag bcd
 */
byte dec_shift_mant(void)

{
  byte *pbVar1;
  undefined2 uVar2;
  byte bVar3;
  byte bVar4;
  char cVar5;
  
  bVar3 = dec_flags;
  if (dec_flags != 0) {
    if (dec_flags < 10) {
      bVar3 = 0;
      cVar5 = '\b';
      pbVar1 = &dec_accum1;
      do {
        bVar4 = bVar3;
        if (((*pbVar1 & 0xf) != 0) || (bVar4 = bVar3 + 1, *pbVar1 != 0)) break;
        bVar3 = bVar3 + 2;
        pbVar1 = pbVar1 + 1;
        cVar5 = cVar5 + -1;
        bVar4 = bVar3;
      } while (cVar5 != '\0');
      if (9 < bVar4) {
        bVar4 = bVar4 + 6;
      }
      bVar3 = (byte)((ushort)dec_accum0 >> 8);
      uVar2 = dec_accum0;
      if (4 < bVar3) {
        uVar2 = CONCAT11(bVar3 - 5,(char)dec_accum0);
      }
      if ((((char)((ushort)uVar2 >> 8) != '\0') && ((byte)uVar2 < 10)) &&
         (bVar3 = das('\x14' - (byte)uVar2), bVar3 <= bVar4)) {
        return 0;
      }
    }
    bVar3 = 1;
  }
  return bVar3;
}

/**
 * @brief 把 Y 指数（0xD039）调整到 0xD00B 并返回标志位
 * @addr 0x19EB2
 * @module bcd
 * @proto byte dec_y_exponent(void)
 * @confidence likely
 * @note 把 Y 指数（0xD039）调整到 0xD00B 并返回标志位。
 * @tag bcd
 */
byte dec_y_exponent(void)

{
  undefined extraout_R1;
  
  dec_accum7 = (byte)calc_state_e;
  if (0xf < dec_accum7) {
    dec_accum7 = dec_accum7 - 6;
  }
  dec_scale_y();
  return CONCAT11(extraout_R1,_DAT_ram_d039) & 0xff01;
}

/**
 * @brief 原始运算入口（0x19C9E + 0x19D14（e^x 入口））
 * @addr 0x19ECE
 * @module bcd
 * @proto void dec_raw_entry(void)
 * @confidence likely
 * @note 原始运算入口（0x19C9E + 0x19D14（e^x 入口））。
 * @tag bcd
 */
int dec_raw_entry(void)

{
  dec_g_X_to_Z2();
  dec_exp_entry();
  return 0;
}

/**
 * @brief 置 _D01E=0xF 后调用 0x19ECE，X 复制到 Y 再调用 0x19D14
 * @addr 0x19F7C
 * @module bcd
 * @proto void dec_exp_last(void)
 * @confidence likely
 * @note 置 _D01E=0xF 后调用 0x19ECE，X 复制到 Y 再调用 0x19D14。
 * @tag bcd
 */
int dec_exp_last(void)

{
  undefined8 uVar1;
  undefined2 uVar2;
  
  uVar2 = dec_accum4;
  uVar1 = dec_accum0;
  dec_opcode = 0xf;
  dec_raw_entry();
  dec_regY = uVar1;
  dec_regY_tail = uVar2;
  dec_exp_entry();
  return 0;
}

/**
 * @brief 小整数快速加法（两个操作数首字节都 <10 时）
 * @addr 0x19FBE
 * @module bcd
 * @proto byte dec_small_add(void)
 * @confidence likely
 * @note 小整数快速加法（两个操作数首字节都 <10 时）。
 * @tag bcd
 */
byte dec_small_add(void)

{
  byte bVar1;
  undefined uVar2;
  
  if ((dec_flags < 10) && (dec_flags_Y < 10)) {
    bVar1 = decc_unary_sign();
    if (bVar1 == 0) {
      dec_swap_XY();
      bVar1 = decc_unary_sign();
      if (bVar1 == 0) {
        dec_swap_XY();
        return 0;
      }
      dec_swap_XY();
    }
    uVar2 = 1;
  }
  else {
    uVar2 = 2;
  }
  return uVar2;
}

/**
 * @brief 十进制运算分派
 * @addr 0x1A15A
 * @module bcd
 * @proto void decc_dispatch(void)
 * @confidence strong
 * @note 十进制运算分派：0xD05A<12 时按 0xD01E 操作码选择核心（<5 0x1C4EE、5 0x1C4C6、6
 *       0x1C18C、7 0x1C042、8 0x1C4A6、>=9 0x1C478）；否则走 0x1A61A 的通用路径。由
 *       0x1CFA4 二进制核心在 0x1B3E4 后调用，0x19D14（e^x）也直接调用。
 * @tag bcd
 */
int decc_dispatch(void)

{
  bool bVar1;
  byte bVar2;
  
  decc_state_check();
  if ((char)((dec_work_a < 0xc) << 7) < '\0') {
    dec_swap_YZ();
    if (dec_opcode < 5) {
      dec_tail_round();
    }
    else if (dec_opcode == 5) {
      decc_carry_round();
    }
    else if (dec_opcode < 7) {
      dec_int_convert();
    }
    else if (dec_opcode == 7) {
      dec_ieee_add();
    }
    else if ((char)((dec_opcode < 9) << 7) < '\0') {
      dec_opcode = 4;
      dec_core_op8();
    }
    else {
      dec_opcode = 5;
      dec_core_op9();
    }
  }
  else {
    bVar1 = dec_opcode == 8;
    if (7 < dec_opcode) {
      dec_opcode = dec_opcode - 4;
      bVar1 = dec_opcode == 0;
    }
    bVar2 = bVar1 << 6;
    decc_generic();
    base_submode();
    if ((bVar2 >> 6 & 1) == 1) {
      decc_arith_core();
    }
  }
  return 0;
}

/**
 * @brief 十进制比较核心（DAA 链，2.1KB）
 * @addr 0x1A232
 * @module bcd
 * @proto undefined2 dec_cmp_core(void)
 * @confidence likely
 * @note 十进制比较核心（DAA 链，2.1KB）：P 寄存器与第 2 操作数逐位比较，由
 *       0x1A1D0/0x1D26E/0x1D280 调用。
 * @tag bcd
 */
undefined2 dec_cmp_core(void)

{
  undefined6 uVar1;
  char cVar2;
  byte bVar3;
  undefined2 uVar4;
  char cVar5;
  undefined uVar6;
  undefined6 extraout_var;
  undefined6 extraout_var_00;
  undefined8 *puVar7;
  
  uVar1 = dec_regP_mant;
  uVar6 = _DAT_ram_d021;
  cVar5 = calc_state_c;
  if (0xef < dec_flags) {
    return;
  }
  cVar2 = daa(dec_accum0 + dec_regY);
  bVar3 = daa(cVar2 + '\x03');
  if (_DAT_ram_d029 != 0) {
    cVar2 = daa(bVar3 + calc_state_c);
    bVar3 = daa(cVar2 + '\x02');
  }
  if (bVar3 < 0x11) {
    if (_DAT_ram_d029 == 0) {
      dec_regP_mant = (undefined6)dec_accum1;
      calc_state_d = (undefined)(dec_accum1 >> 0x30);
      calc_state_c = daa(dec_accum0 + '\x01');
      _DAT_ram_d029 = dec_flags;
    }
    else {
      dec_accum7 = daa(calc_state_c + '\x02');
      cVar5 = daa(dec_accum0 + '\x01');
      calc_state_c = daa(cVar5 + dec_accum7);
      calc_state_f = dec_accum1 | 0xa000000000000000;
      if (0xf < dec_accum7) {
        dec_accum7 = dec_accum7 - 6;
      }
      decc_packZ();
      puVar7 = (undefined8 *)&dec_regP_mant;
      uVar4 = or_words_r8((byte)dec_regP_mant,(byte)((uint6)dec_regP_mant >> 8));
      *puVar7 = CONCAT62(extraout_var,uVar4);
    }
    dec_accum7 = daa(calc_state_c + '\x01');
    cVar5 = daa(dec_regY + '\x01');
    uVar6 = daa(cVar5 + dec_accum7);
    dec_accum0 = CONCAT11((char)((ushort)dec_accum0 >> 8),uVar6);
    calc_state_f = CONCAT26(dec_regY_tail,dec_regY_mant) | 0xa000000000000000;
    if (0xf < dec_accum7) {
      dec_accum7 = dec_accum7 - 6;
    }
    decc_packZ();
    uVar4 = or_words_r8((byte)dec_regP_mant,(byte)((uint6)dec_regP_mant >> 8));
    dec_accum1 =
         CONCAT17((char)((uint6)extraout_var_00 >> 0x28),(int7)CONCAT62(extraout_var_00,uVar4)) |
         0x2000000000000000;
  }
  else {
    if (_DAT_ram_d029 == 0) {
      dec_ieee_add();
    }
    else {
      uVar4 = CONCAT11(_DAT_ram_d029,calc_state_d);
      dec_ieee_add();
      dec_regY = cVar5;
      dec_regY_1 = uVar6;
      dec_regY_mant = uVar1;
      dec_regY_tail = uVar4;
      dec_tail_round();
    }
    dec_prepare_compare();
  }
  return;
}

/**
 * @brief 返回 (param2|R9, param1|R8) 的按位或结果
 * @addr 0x1A356
 * @module bcd
 * @proto undefined2 or_words_r8(void)
 * @confidence verified
 * @note 返回 (param2|R9, param1|R8) 的按位或结果。
 * @tag util
 */
undefined2 or_words_r8(uintptr_t _a3, uintptr_t _a4, int _a1, int _a2)

{
  byte unaff_R8;
  byte unaff_R9;
  
  return CONCAT11(_a2 | unaff_R9,_a1 | unaff_R8);
}

/**
 * @brief 十进制算术变体（2.9KB，0x1A1D0/0x1CC9A/0x1D26E 调用，处理负号/…
 * @addr 0x1A36A
 * @module bcd
 * @proto undefined2 dec_arith_neg(void)
 * @confidence likely
 * @note 十进制算术变体（2.9KB，0x1A1D0/0x1CC9A/0x1D26E 调用，处理负号/补码）。
 * @tag bcd
 */
undefined2 dec_arith_neg(void)

{
  short sVar1;
  byte bVar2;
  char cVar8;
  undefined2 uVar3;
  uint3 uVar4;
  byte bVar7;
  undefined uVar9;
  undefined uVar10;
  ulonglong uVar5;
  undefined6 extraout_var;
  undefined6 extraout_var_00;
  undefined8 uVar6;
  undefined6 extraout_var_01;
  undefined8 *puVar11;
  
  if (0xef < dec_flags) {
    return;
  }
  uVar4 = CONCAT12(5,dec_accum0);
  while( true ) {
    cVar8 = (char)(uVar4 >> 0x10);
    bVar7 = daa((char)(uVar4 >> 8) + '\x05');
    uVar3 = CONCAT11(bVar7,(char)uVar4);
    if (0xf < bVar7) break;
    uVar9 = daa(cVar8 + '\x05');
    uVar4 = CONCAT12(uVar9,uVar3) & 0xfffff;
  }
  uVar5 = (ulonglong)CONCAT12(cVar8,uVar3) & 0xffffffffffff0fff;
  calc_state_a = (char)(uVar5 >> 0x10);
  dec_accum0 = (ushort)uVar5;
  calc_state_c = 0x114;
  _DAT_ram_d024 = 0;
  dec_regP_mant = 0;
  RAM8(0xd023) = 0;
  calc_state_d = 0;
  _DAT_ram_d029 = '\0';
  _DAT_ram_d026 = 0;
  do {
    bVar2 = das((byte)dec_accum0 - (byte)dec_regY);
    sVar1 = ((dec_accum0 >> 8) - (dec_regY >> 8)) -
            (ushort)((byte)dec_accum0 < (byte)dec_regY);
    bVar7 = (char)((ushort)sVar1 >> 8) << 7;
    cVar8 = das((char)sVar1);
    if (bVar7 != 0) {
LAB_rom_01a428:
      dec_ieee_norm();
      uVar9 = daa((char)(dec_accum0 >> 8) + calc_state_a);
      dec_accum0 = CONCAT11(uVar9,(char)dec_accum0) & 0xfff;
      dec_swap_xp();
      dec_ieee_norm();
      dec_swap_xp();
      if (_DAT_ram_d029 != '\0') {
        uVar9 = daa((char)(calc_state_c >> 8) + calc_state_a);
        calc_state_c = CONCAT11(uVar9,(char)calc_state_c) & 0xfff;
      }
      return;
    }
    if (_DAT_ram_d029 != '\0') {
      uVar9 = daa(bVar2 + 0x15);
      uVar10 = daa((cVar8 + '\x01') - ((char)((0xea < bVar2) << 7) >> 7));
      calc_state_c = CONCAT11(uVar10,uVar9) & 0xfff;
      goto LAB_rom_01a428;
    }
    puVar11 = (undefined8 *)&dec_regP_mant;
    uVar3 = dec_shift_left4(dec_regP_mant,RAM8(0xd023));
    *puVar11 = CONCAT62(extraout_var,uVar3);
    bVar7 = bVar7 & 0x9f;
    uVar6 = dec_accum1;
    while( true ) {
      uVar3 = decc_sub8((byte)uVar6,(byte)((ulonglong)uVar6 >> 8), (uintptr_t)0, (uintptr_t)0)
                             (byte)((ulonglong)uVar6 >> 0x10),(byte)((ulonglong)uVar6 >> 0x18));
      if ((char)bVar7 < '\0') break;
      bVar7 = (0xfe < dec_regP_mant) << 7;
      dec_regP_mant = dec_regP_mant + 1;
      uVar6 = CONCAT71((int7)(CONCAT62(extraout_var_00,uVar3) >> 8),(byte)uVar3);
    }
    uVar3 = decc_add8((byte)uVar3,(byte)((ushort)uVar3 >> 8),(byte)extraout_var_00, (uintptr_t)0)
                           (byte)((uint6)extraout_var_00 >> 8));
    uVar3 = dec_shift_left4((byte)uVar3,(byte)((ushort)uVar3 >> 8));
    dec_accum1 = CONCAT62(extraout_var_01,uVar3);
    uVar9 = das((char)dec_accum0 + -1);
    uVar10 = das((char)(dec_accum0 >> 8) - ((char)dec_accum0 == '\0'));
    dec_accum0 = CONCAT11(uVar10,uVar9) & 0xfff;
  } while( true );
}

