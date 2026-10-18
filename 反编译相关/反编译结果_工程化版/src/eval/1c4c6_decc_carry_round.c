/*
 * 表达式求值 / 1c4c6_decc_carry_round.c
 * 地址范围: 0x1C4C6 - 0x1CBE0
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 进位后处理
 * @addr 0x1C4C6
 * @module eval
 * @proto void decc_carry_round(void)
 * @confidence strong
 * @note 进位后处理：Y 为正规数时对 X 的尾数按 DEC 加 5 并整理尾数（0x1C506）；否则 X→Y 搬移。
 * @tag float
 */
int decc_carry_round(void)

{
  undefined uVar1;
  
  if (dec_flags < 0xf0) {
    if ((char)((dec_flags_Y < 0xf0) << 7) < '\0') {
      uVar1 = daa((char)(dec_regY >> 8) + '\x05');
      dec_regY = CONCAT11(uVar1,(char)dec_regY) & 0xfff;
      dec_tail_round2();
      return 0;
    }
    dec_g_X_to_Y();
  }
  return 0;
}

/**
 * @brief 10^x
 * @addr 0x1C95E
 * @module eval
 * @proto void decm_exp10(undefined2* a, undefined2* b)
 * @confidence strong
 * @note 【10^x】设置操作码 0xF、装载 X←*a；0xD01E<0xE 时按 10 / 其他分支（0x19958 /
 *       0x19A72），否则 0x1B09C 处理大指数。
 * @tag float
 */
int decm_exp10(undefined2* a, undefined2* b)

{
  undefined2 uVar1;
  
  dec_opcode = 0xf;
  dec_param_a = a;
  dec_param_b = b;
  dec_load(b);
  uVar1 = dec_check_nan_XY();
  if ((char)uVar1 == '\0') {
    decc_load_Y();
    if (dec_opcode < 0xe) {
      if (dec_opcode == 10) {
        decc_dummy();
      }
      else {
        decc_log_path();
      }
    }
    else {
      calc_state_a = 0;
      if (dec_opcode != 0xe) {
        dec_swap_XY();
      }
      decc_exp_large();
    }
  }
  else {
    dec_zero_helper();
  }
  dec_store();
  dec_status_low();
  return 0;
}

/**
 * @brief 乘方入口 x^y
 * @addr 0x1CA7E
 * @module eval
 * @proto void decm_pow(undefined2* a, undefined2* b)
 * @confidence strong
 * @note 【乘方入口 x^y】设置操作码 0x13 后进入 0x1CAA6 的公共序列。
 * @tag float
 */
int decm_pow(undefined2* a, undefined2* b)

{
  bool bVar1;
  
  dec_opcode = 0x13;
  dec_param_a = a;
  dec_param_b = b;
  dec_load_regs(a);
  bVar1 = dec_check_nan_X();
  if (bVar1) {
    dec_zero_helper();
    goto LAB_rom_01cb9e;
  }
  decc_int_entry();
  calc_state_a = 0;
  if (dec_opcode == 0) {
    decc_add_align();
  }
  else if (dec_opcode == 1) {
    decc_sub();
  }
  else if (dec_opcode < 3) {
    dec_opcode = 6;
    calc_state_b = 10;
    decc_exp_path();
  }
  else if (dec_opcode == 3) {
    dec_opcode = 6;
    calc_state_b = 9;
    decc_sin_path();
  }
  else {
    if (dec_opcode != 4) {
      if (dec_opcode == 0x11) {
        stat_calc_proc();
        goto LAB_rom_01cb9e;
      }
      if (dec_opcode < 0x13) {
        dec_set_Y_1e0_x();
        goto LAB_rom_01cb9e;
      }
      if (dec_opcode == 0x13) {
        dec_g_X_to_Y_copy();
        goto LAB_rom_01cb9e;
      }
      if (dec_opcode < 0x15) {
        dec_unary_neg();
        goto LAB_rom_01cb9e;
      }
      if (dec_opcode == 0x15) {
        dec_set_ln();
        goto LAB_rom_01cb9e;
      }
    }
    decc_xln();
  }
  dec_ieee_norm();
LAB_rom_01cb9e:
  dec_store();
  dec_status_low();
  return 0;
}

/**
 * @brief 乘方根入口 x^(1/y)
 * @addr 0x1CA92
 * @module eval
 * @proto void decm_nroot(undefined2* a, undefined2* b)
 * @confidence likely
 * @note 【乘方根入口 x^(1/y)】设置操作码 0x12 后进入 0x1CAA6 的公共序列。
 * @tag float
 */
int decm_nroot(undefined2* a, undefined2* b)

{
  bool bVar1;
  
  dec_opcode = 0x12;
  dec_param_a = a;
  dec_param_b = b;
  dec_load_regs(a);
  bVar1 = dec_check_nan_X();
  if (bVar1) {
    dec_zero_helper();
    goto LAB_rom_01cb9e;
  }
  decc_int_entry();
  calc_state_a = 0;
  if (dec_opcode == 0) {
    decc_add_align();
  }
  else if (dec_opcode == 1) {
    decc_sub();
  }
  else if (dec_opcode < 3) {
    dec_opcode = 6;
    calc_state_b = 10;
    decc_exp_path();
  }
  else if (dec_opcode == 3) {
    dec_opcode = 6;
    calc_state_b = 9;
    decc_sin_path();
  }
  else {
    if (dec_opcode != 4) {
      if (dec_opcode == 0x11) {
        stat_calc_proc();
        goto LAB_rom_01cb9e;
      }
      if (dec_opcode < 0x13) {
        dec_set_Y_1e0_x();
        goto LAB_rom_01cb9e;
      }
      if (dec_opcode == 0x13) {
        dec_g_X_to_Y_copy();
        goto LAB_rom_01cb9e;
      }
      if (dec_opcode < 0x15) {
        dec_unary_neg();
        goto LAB_rom_01cb9e;
      }
      if (dec_opcode == 0x15) {
        dec_set_ln();
        goto LAB_rom_01cb9e;
      }
    }
    decc_xln();
  }
  dec_ieee_norm();
LAB_rom_01cb9e:
  dec_store();
  dec_status_low();
  return 0;
}

/**
 * @brief 乘方/开方公共序列
 * @addr 0x1CAA6
 * @module eval
 * @proto void decm_power_common(undefined2* a, undefined2* b)
 * @confidence strong
 * @note 乘方/开方公共序列：装载 X←*a，`xln x`（0x19B28）后按 0xD01F 选
 *       `e^x`（0x1B1E8）或乘方核心（0x1B1CA 等），结果写回 *b。
 * @tag float
 */
int decm_power_common(undefined2* a, undefined2* b)

{
  bool bVar1;
  
  dec_opcode = 0x11;
  dec_param_a = a;
  dec_param_b = b;
  dec_load_regs(a);
  bVar1 = dec_check_nan_X();
  if (bVar1) {
    dec_zero_helper();
    goto LAB_rom_01cb9e;
  }
  decc_int_entry();
  calc_state_a = 0;
  if (dec_opcode == 0) {
    decc_add_align();
  }
  else if (dec_opcode == 1) {
    decc_sub();
  }
  else if (dec_opcode < 3) {
    dec_opcode = 6;
    calc_state_b = 10;
    decc_exp_path();
  }
  else if (dec_opcode == 3) {
    dec_opcode = 6;
    calc_state_b = 9;
    decc_sin_path();
  }
  else {
    if (dec_opcode != 4) {
      if (dec_opcode == 0x11) {
        stat_calc_proc();
        goto LAB_rom_01cb9e;
      }
      if (dec_opcode < 0x13) {
        dec_set_Y_1e0_x();
        goto LAB_rom_01cb9e;
      }
      if (dec_opcode == 0x13) {
        dec_g_X_to_Y_copy();
        goto LAB_rom_01cb9e;
      }
      if (dec_opcode < 0x15) {
        dec_unary_neg();
        goto LAB_rom_01cb9e;
      }
      if (dec_opcode == 0x15) {
        dec_set_ln();
        goto LAB_rom_01cb9e;
      }
    }
    decc_xln();
  }
  dec_ieee_norm();
LAB_rom_01cb9e:
  dec_store();
  dec_status_low();
  return 0;
}

/**
 * @brief sin
 * @addr 0x1CACE
 * @module eval
 * @proto void decm_sin(undefined2* a, undefined2* b)
 * @confidence strong
 * @note 【sin】装载 X←*a，按 0xD01F（0..2 分别对应不同化简/象限路径）计算后写回 *b。
 * @tag float
 */
int decm_sin(undefined2* a, undefined2* b)

{
  bool bVar1;
  undefined2 *puVar2;
  
  dec_opcode = 2;
  dec_param_a = a;
  dec_param_b = b;
  puVar2 = (undefined2 *)dec_load_callee();
  dec_load_regs(puVar2);
  bVar1 = dec_check_nan_X();
  if (bVar1) {
    dec_zero_helper();
    goto LAB_rom_01cb9e;
  }
  decc_int_entry();
  calc_state_a = 0;
  if (dec_opcode == 0) {
    decc_add_align();
  }
  else if (dec_opcode == 1) {
    decc_sub();
  }
  else if (dec_opcode < 3) {
    dec_opcode = 6;
    calc_state_b = 10;
    decc_exp_path();
  }
  else if (dec_opcode == 3) {
    dec_opcode = 6;
    calc_state_b = 9;
    decc_sin_path();
  }
  else {
    if (dec_opcode != 4) {
      if (dec_opcode == 0x11) {
        stat_calc_proc();
        goto LAB_rom_01cb9e;
      }
      if (dec_opcode < 0x13) {
        dec_set_Y_1e0_x();
        goto LAB_rom_01cb9e;
      }
      if (dec_opcode == 0x13) {
        dec_g_X_to_Y_copy();
        goto LAB_rom_01cb9e;
      }
      if (dec_opcode < 0x15) {
        dec_unary_neg();
        goto LAB_rom_01cb9e;
      }
      if (dec_opcode == 0x15) {
        dec_set_ln();
        goto LAB_rom_01cb9e;
      }
    }
    decc_xln();
  }
  dec_ieee_norm();
LAB_rom_01cb9e:
  dec_store();
  dec_status_low();
  return 0;
}

/**
 * @brief cos
 * @addr 0x1CAE2
 * @module eval
 * @proto void decm_cos(undefined2* a, undefined2* b)
 * @confidence strong
 * @note 【cos】与 decm_sin 共用序列，仅 0xD01F 初值不同。
 * @tag float
 */
int decm_cos(undefined2* a, undefined2* b)

{
  bool bVar1;
  undefined2 *puVar2;
  
  dec_opcode = 1;
  dec_param_a = a;
  dec_param_b = b;
  puVar2 = (undefined2 *)dec_load_callee();
  dec_load_regs(puVar2);
  bVar1 = dec_check_nan_X();
  if (bVar1) {
    dec_zero_helper();
    goto LAB_rom_01cb9e;
  }
  decc_int_entry();
  calc_state_a = 0;
  if (dec_opcode == 0) {
    decc_add_align();
  }
  else if (dec_opcode == 1) {
    decc_sub();
  }
  else if (dec_opcode < 3) {
    dec_opcode = 6;
    calc_state_b = 10;
    decc_exp_path();
  }
  else if (dec_opcode == 3) {
    dec_opcode = 6;
    calc_state_b = 9;
    decc_sin_path();
  }
  else {
    if (dec_opcode != 4) {
      if (dec_opcode == 0x11) {
        stat_calc_proc();
        goto LAB_rom_01cb9e;
      }
      if (dec_opcode < 0x13) {
        dec_set_Y_1e0_x();
        goto LAB_rom_01cb9e;
      }
      if (dec_opcode == 0x13) {
        dec_g_X_to_Y_copy();
        goto LAB_rom_01cb9e;
      }
      if (dec_opcode < 0x15) {
        dec_unary_neg();
        goto LAB_rom_01cb9e;
      }
      if (dec_opcode == 0x15) {
        dec_set_ln();
        goto LAB_rom_01cb9e;
      }
    }
    decc_xln();
  }
  dec_ieee_norm();
LAB_rom_01cb9e:
  dec_store();
  dec_status_low();
  return 0;
}

/**
 * @brief 带角度参数的二元入口
 * @addr 0x1CBE0
 * @module eval
 * @proto void decm_bin_angle(undefined2* a, byte angle)
 * @confidence strong
 * @note 带角度参数的二元入口：载入角度模式（0xD11D）后按 0xD01E 选择加减/乘除/三角路径。
 * @tag float
 */
int decm_bin_angle(undefined2* a, byte angle)

{
  bool bVar1;
  byte bVar2;
  undefined2 *puVar3;
  
  dec_opcode = (byte)angle;
  dec_param_a = a;
  dec_param_b = angle;
  puVar3 = (undefined2 *)dec_load_callee();
  dec_load_regs(puVar3);
  bVar1 = dec_check_nan_X();
  if (bVar1) {
    dec_zero_helper();
    goto LAB_rom_01cc82;
  }
  decc_int_entry();
  if (menu_sel_b < 5) {
    if (dec_opcode < 5) {
      return 0;
    }
    if (dec_opcode != 5) {
      dec_set_Y_9e0();
      dec_int_convert();
      goto LAB_rom_01cc82;
    }
    dec_set_Y_1e0_b();
  }
  else {
    if (menu_sel_b == 5) {
      if (dec_opcode < 5) {
        dec_set_Y_1e0_b();
        dec_ieee_add();
        dec_g_X_to_Z2();
        dec_const_pi();
        dec_int_convert();
      }
      else {
        if (dec_opcode == 5) {
          return 0;
        }
        dec_set_Y_1e0_a();
        dec_ieee_add();
        dec_g_X_to_Z2();
        dec_const_pi();
        dec_int_convert();
      }
      goto LAB_rom_01cc82;
    }
    if (dec_opcode < 5) {
      dec_set_Y_one();
      dec_int_convert();
      goto LAB_rom_01cc82;
    }
    if (dec_opcode != 5) {
      return 0;
    }
    dec_set_Y_1e0_a();
  }
  dec_int_convert();
  dec_g_X_to_Z2();
  dec_const_pi();
  dec_fixup_types();
LAB_rom_01cc82:
  dec_store();
  bVar2 = dec_status_low();
  return bVar2;
}

