/*
 * 表达式求值 / 19eda_decc_neg_process.c
 * 地址范围: 0x19EDA - 0x1A1D0
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 取负过程
 * @addr 0x19EDA
 * @module eval
 * @proto void decc_neg_process(void)
 * @confidence strong
 * @note 取负过程：0xD01E=0x0B，调用 0x1A7A4/0x19C68/0x1AFB8 后按 0xD01E 选择
 *       0x1BE46 与 0x1AF5A 分支。
 * @tag float
 */
int decc_neg_process(void)

{
  char cVar1;
  byte bVar2;
  
  dec_opcode = '\v';
  if ((dec_flags & 0xf0) == 0x20) {
    dec_work_a = 0xf;
    decc_int_prep();
    dec_g_W_to_X();
    dec_swap_XY();
    if (dec_opcode == '\r') {
      stat_calc_proc();
      dec_prepare_compare();
      dec_swap_XW();
      stat_calc_proc();
      dec_prepare_compare();
      dec_g_Y_to_X();
    }
    else {
      bVar2 = (byte)((ushort)dec_regY >> 8);
      if (4 < bVar2) {
        dec_regY = CONCAT11(bVar2 - 5,(char)dec_regY);
        dec_accum0 = CONCAT11((char)((ushort)dec_accum0 >> 8) + '\x05',(char)dec_accum0);
      }
    }
    cVar1 = dec_small_add();
    bVar2 = (cVar1 == '\0') << 6;
    if (cVar1 == '\0') {
      base_submode();
      if ((bVar2 >> 6 & 1) == 1) {
        decc_arith_core();
      }
    }
    else {
      dec_ieee_add();
    }
  }
  else {
    dec_set_Y_1e0_x();
  }
  return 0;
}

/**
 * @brief 取绝对值过程（与 0x19EDA 同构，0xD01E=0x0D）
 * @addr 0x19EE4
 * @module eval
 * @proto void decc_abs_process(void)
 * @confidence likely
 * @note 取绝对值过程（与 0x19EDA 同构，0xD01E=0x0D）。
 * @tag float
 */
int decc_abs_process(void)

{
  char cVar1;
  byte bVar2;
  
  dec_opcode = '\r';
  if ((dec_flags & 0xf0) == 0x20) {
    dec_work_a = 0xf;
    decc_int_prep();
    dec_g_W_to_X();
    dec_swap_XY();
    if (dec_opcode == '\r') {
      stat_calc_proc();
      dec_prepare_compare();
      dec_swap_XW();
      stat_calc_proc();
      dec_prepare_compare();
      dec_g_Y_to_X();
    }
    else {
      bVar2 = (byte)((ushort)dec_regY >> 8);
      if (4 < bVar2) {
        dec_regY = CONCAT11(bVar2 - 5,(char)dec_regY);
        dec_accum0 = CONCAT11((char)((ushort)dec_accum0 >> 8) + '\x05',(char)dec_accum0);
      }
    }
    cVar1 = dec_small_add();
    bVar2 = (cVar1 == '\0') << 6;
    if (cVar1 == '\0') {
      base_submode();
      if ((bVar2 >> 6 & 1) == 1) {
        decc_arith_core();
      }
    }
    else {
      dec_ieee_add();
    }
  }
  else {
    stat_calc_proc();
  }
  return 0;
}

/**
 * @brief log 入口
 * @addr 0x19F72
 * @module eval
 * @proto void decm_log_entry(void)
 * @confidence strong
 * @note log 入口：0xD01E=0x0E、Y←1，调整指数后调用 0x19FF8（log10 核心）。
 * @tag float
 */
int decm_log_entry(void)

{
  dec_opcode = 0xe;
  dec_set_y1();
  dec_regY_tail = CONCAT11(3,dec_regY_tail);
  decc_log10_core();
  return 0;
}

/**
 * @brief 常用对数核心
 * @addr 0x19FF8
 * @module eval
 * @proto void decc_log10_core(void)
 * @confidence strong
 * @note 常用对数核心：0xD01E=0x0E、0xD05B=0x10，调用 0x19DD6 做对数近似，再按 0xD009 &
 *       0xF0 == 0x20 分支（X 已是 10 的幂则直接取指数）。
 * @tag float
 */
int decc_log10_core(void)

{
  undefined6 uVar1;
  undefined uVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  undefined6 uVar5;
  undefined6 uVar6;
  undefined2 uVar7;
  undefined2 uVar8;
  byte bVar9;
  char cVar10;
  byte bVar12;
  undefined uVar13;
  ushort uVar11;
  
  dec_opcode = 0xe;
  _DAT_ram_d05b = '\x10';
  decc_log_series();
  if ((dec_flags & 0xf0) == 0x20) {
    dec_swap_XY();
    if (((dec_flags & 0xf0) == 0x20) || (bVar9 = decc_unary_sign(), bVar9 != 0)) {
      dec_swap_XY();
    }
    else {
      dec_swap_XY();
      dec_g_X_to_Z4();
      dec_g_Y_to_Q();
      dec_g_X_to_W();
      dec_work_a = 0xf;
      decc_int_prep();
      uVar7 = dec_regW_tail;
      uVar5 = _DAT_ram_d052;
      bVar9 = dec_flags_Y;
      uVar2 = dec_regY_tail;
      uVar1 = dec_regY_mant;
      cVar10 = RAM8(0xd001);
      uVar13 = dec_accum0;
      bVar12 = (byte)((ushort)dec_regW >> 8);
      if (4 < bVar12) {
        dec_regW = CONCAT11(bVar12 - 5,(char)dec_regW);
        dec_regY_mant = dec_accum1;
        dec_regY_tail = dec_accum4;
        dec_flags_Y = dec_flags;
        dec_accum1 = uVar1;
        dec_accum4 = uVar2;
        dec_flags = bVar9;
        dec_accum0 = dec_regY;
        dec_regY = uVar13;
      }
      uVar3 = dec_regW;
      bVar9 = dec_flags;
      uVar2 = dec_accum4;
      uVar1 = dec_accum1;
      uVar13 = dec_accum0;
      dec_g_W_to_Y();
      calc_state_a = 0;
      decc_exp_large();
      dec_prepare_compare();
      dec_g_W_to_X();
      uVar8 = dec_regW_tail;
      uVar6 = _DAT_ram_d052;
      uVar4 = dec_regW;
      dec_regY = uVar13;
      dec_regY_1 = cVar10;
      dec_regY_mant = uVar1;
      dec_regY_tail = uVar2;
      dec_flags_Y = bVar9;
      dec_accum0 = (undefined)uVar3;
      RAM8(0xd001) = (char)((ushort)uVar3 >> 8);
      dec_accum1 = uVar5;
      dec_accum4 = (undefined)uVar7;
      dec_flags = (byte)((ushort)uVar7 >> 8);
      calc_state_a = 0;
      decc_exp_large();
      dec_prepare_compare();
      dec_regY = (undefined)uVar4;
      dec_regY_1 = (char)((ushort)uVar4 >> 8);
      dec_regY_mant = uVar6;
      dec_regY_tail = (undefined)uVar8;
      dec_flags_Y = (byte)((ushort)uVar8 >> 8);
      if ((((dec_flags < 0xf0) && (dec_flags_Y < 0xf0)) &&
          (cVar10 = dec_small_add(), cVar10 == '\0')) &&
         (decc_arith_core(), (dec_flags & 0xf0) == 0x20)) {
        return 0;
      }
      dec_g_Z4_to_X();
      dec_g_Q_to_Y();
    }
  }
  dec_g_X_to_W();
  decc_int_entry();
  dec_swap_XW();
  decc_int_entry();
  dec_g_Y_to_X();
  calc_state_a = 0;
  decc_exp_large();
  uVar13 = daa(RAM8(0xd001) + _DAT_ram_d05b);
  uVar11 = CONCAT11(uVar13,dec_accum0) & 0xfff;
  dec_accum0 = (undefined)uVar11;
  RAM8(0xd001) = (char)(uVar11 >> 8);
  return 0;
}

/**
 * @brief 自然对数核心
 * @addr 0x1A008
 * @module eval
 * @proto void decc_ln_core(void)
 * @confidence strong
 * @note 自然对数核心：与 0x19FF8 同构，仅 0xD01E=0x0F、0xD05B=0（自然对数）。
 * @tag float
 */
int decc_ln_core(void)

{
  undefined6 uVar1;
  undefined uVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  undefined6 uVar5;
  undefined6 uVar6;
  undefined2 uVar7;
  undefined2 uVar8;
  byte bVar9;
  char cVar10;
  byte bVar12;
  undefined uVar13;
  ushort uVar11;
  
  dec_opcode = 0xf;
  _DAT_ram_d05b = '\0';
  decc_log_series();
  if ((dec_flags & 0xf0) == 0x20) {
    dec_swap_XY();
    if (((dec_flags & 0xf0) == 0x20) || (bVar9 = decc_unary_sign(), bVar9 != 0)) {
      dec_swap_XY();
    }
    else {
      dec_swap_XY();
      dec_g_X_to_Z4();
      dec_g_Y_to_Q();
      dec_g_X_to_W();
      dec_work_a = 0xf;
      decc_int_prep();
      uVar7 = dec_regW_tail;
      uVar5 = _DAT_ram_d052;
      bVar9 = dec_flags_Y;
      uVar2 = dec_regY_tail;
      uVar1 = dec_regY_mant;
      cVar10 = RAM8(0xd001);
      uVar13 = dec_accum0;
      bVar12 = (byte)((ushort)dec_regW >> 8);
      if (4 < bVar12) {
        dec_regW = CONCAT11(bVar12 - 5,(char)dec_regW);
        dec_regY_mant = dec_accum1;
        dec_regY_tail = dec_accum4;
        dec_flags_Y = dec_flags;
        dec_accum1 = uVar1;
        dec_accum4 = uVar2;
        dec_flags = bVar9;
        dec_accum0 = dec_regY;
        dec_regY = uVar13;
      }
      uVar3 = dec_regW;
      bVar9 = dec_flags;
      uVar2 = dec_accum4;
      uVar1 = dec_accum1;
      uVar13 = dec_accum0;
      dec_g_W_to_Y();
      calc_state_a = 0;
      decc_exp_large();
      dec_prepare_compare();
      dec_g_W_to_X();
      uVar8 = dec_regW_tail;
      uVar6 = _DAT_ram_d052;
      uVar4 = dec_regW;
      dec_regY = uVar13;
      dec_regY_1 = cVar10;
      dec_regY_mant = uVar1;
      dec_regY_tail = uVar2;
      dec_flags_Y = bVar9;
      dec_accum0 = (undefined)uVar3;
      RAM8(0xd001) = (char)((ushort)uVar3 >> 8);
      dec_accum1 = uVar5;
      dec_accum4 = (undefined)uVar7;
      dec_flags = (byte)((ushort)uVar7 >> 8);
      calc_state_a = 0;
      decc_exp_large();
      dec_prepare_compare();
      dec_regY = (undefined)uVar4;
      dec_regY_1 = (char)((ushort)uVar4 >> 8);
      dec_regY_mant = uVar6;
      dec_regY_tail = (undefined)uVar8;
      dec_flags_Y = (byte)((ushort)uVar8 >> 8);
      if ((((dec_flags < 0xf0) && (dec_flags_Y < 0xf0)) &&
          (cVar10 = dec_small_add(), cVar10 == '\0')) &&
         (decc_arith_core(), (dec_flags & 0xf0) == 0x20)) {
        return 0;
      }
      dec_g_Z4_to_X();
      dec_g_Q_to_Y();
    }
  }
  dec_g_X_to_W();
  decc_int_entry();
  dec_swap_XW();
  decc_int_entry();
  dec_g_Y_to_X();
  calc_state_a = 0;
  decc_exp_large();
  uVar13 = daa(RAM8(0xd001) + _DAT_ram_d05b);
  uVar11 = CONCAT11(uVar13,dec_accum0) & 0xfff;
  dec_accum0 = (undefined)uVar11;
  RAM8(0xd001) = (char)(uVar11 >> 8);
  return 0;
}

/**
 * @brief 加减法核心公共段
 * @addr 0x1A1D0
 * @module eval
 * @proto int decc_arith_core(void)
 * @confidence strong
 * @note 加减法核心公共段：按 X/Y 是否为零选择 0x1C042/0x1AF5A 或 0x19C8C..0x1B050
 *       的规范化路径。
 * @tag float
 */
int decc_arith_core(void)

{
  if (0xef < dec_flags) {
    return 0;
  }
  if ((dec_flags == 0) || (dec_flags_Y == 0)) {
    dec_ieee_add();
    dec_prepare_compare();
  }
  else {
    dec_g_X_to_Z();
    dec_g_X_to_W();
    dec_arith_dual();
    dec_g_W_to_Y();
    dec_ieee_add();
    dec_swap_XZ();
    dec_ieee_add();
    dec_swap_YZ();
    if ((dec_regY == '\0') && (dec_flags_Y < 2)) {
      dec_prepare_compare();
    }
    else {
      dec_arith_neg();
      dec_cmp_core();
    }
  }
  return 0;
}

