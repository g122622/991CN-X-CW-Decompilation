/*
 * 表达式求值 / 1cd2c_decm_round_entry.c
 * 地址范围: 0x1CD2C - 0x1D280
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 取整入口
 * @addr 0x1CD2C
 * @module eval
 * @proto void decm_round_entry(undefined2* a, undefined2* b)
 * @confidence strong
 * @note 取整入口：载入 X←*a；类型为 1/6（小整数/内部结果）时先清 X 再对齐相加，否则 0x19890 取负；最后写回
 *       *b。Ghidra 把紧随其后的 8 个操作码封装并入该函数体。
 * @tag float
 */
int decm_round_entry(undefined2* a, undefined2* b)

{
  char cVar1;
  
  dec_param_a = a;
  dec_param_b = b;
  dec_load_regs(a);
  if (dec_flags < 10) {
    cVar1 = (char)((ushort)dec_accum0 >> 8);
    if ((cVar1 == '\x01') || (cVar1 == '\x06')) {
      dec_set_Y_1e0();
      calc_state_a = 0;
      decc_add_align();
    }
    else {
      decc_zero_neg();
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
 * @brief 二元入口
 * @addr 0x1CDF6
 * @module eval
 * @proto void decm_bin_pow1(undefined2* a, undefined2* b)
 * @confidence verified
 * @note 二元入口：档位 2 + 乘方族（R4=2,R5=9）。调用点 0x14222。
 * @tag float
 */
int decm_bin_pow1(undefined2* a, undefined2* b)

{
  dec_param_a = a;
  dec_param_b = b;
  decm_arith((char)b, (uintptr_t)0);
  return 0;
}

/**
 * @brief 二元入口
 * @addr 0x1CE1A
 * @module eval
 * @proto void decm_bin_family8_3(undefined2* a, undefined2* b)
 * @confidence verified
 * @note 二元入口：档位 3 + 第 8 族（R4=3,R5=8）。调用点 0x167B6。
 * @tag float
 */
int decm_bin_family8_3(undefined2* a, undefined2* b)

{
  dec_param_a = a;
  dec_param_b = b;
  decm_arith((char)b, (uintptr_t)0);
  return 0;
}

/**
 * @brief 二元入口
 * @addr 0x1CE2C
 * @module eval
 * @proto int decm_bin_div2(undefined2* a, undefined2* b)
 * @confidence verified
 * @note 二元入口：档位 2 + 除法族（R4=2,R5=8）。调用点 0x16720、0x18F62。
 * @tag float
 */
int decm_bin_div2(undefined2* a, undefined2* b)

{
  dec_param_a = a;
  dec_param_b = b;
  decm_arith((char)b, (uintptr_t)0);
  return 0;
}

/**
 * @brief 加减法入口 ±
 * @addr 0x1CE3E
 * @module eval
 * @proto int decm_add(undefined2* save, byte angle)
 * @confidence verified
 * @note 【加减法入口 ±】保存现场到 save(*)、0xD05E=save，按 angle 设置角度模式（0 用
 *       0xD11D），装载 X←Y，再按 0xD01F 分派：<9 走 0x1AB54（+），==9 走
 *       0x1AC2C（−），>9 走 0x1A98A（特殊值加减）。
 * @tag float
 */
int decm_add(undefined2* save, byte angle)

{
  bool bVar1;
  undefined2 *puVar2;
  
  dec_param_a = save;
  dec_param_b = angle;
  puVar2 = (undefined2 *)dec_load_callee();
  dec_opcode = 0x801;
  angle_mode = (char)angle;
  if ((char)angle == '\0') {
    angle_mode = menu_sel_b;
  }
  dec_load_regs(puVar2);
  bVar1 = dec_check_nan_X();
  if (bVar1) {
    dec_zero_helper();
  }
  else {
    decc_int_entry();
    if (calc_state_b < 9) {
      decc_addinit();
    }
    else if (calc_state_b == 9) {
      decc_rounded_add();
    }
    else {
      decc_add_special();
    }
    dec_ieee_norm();
  }
  dec_store();
  dec_status_low();
  return 0;
}

/**
 * @brief 加减法入口
 * @addr 0x1CE4E
 * @module eval
 * @proto void decm_arith(byte angle, undefined2 saved_d01e)
 * @confidence strong
 * @note 【加减法入口】与 decm_add 相同但现场已由调用者压栈（0xD01E 通过 ER4 恢复），不写
 *       0xD05C/0xD05E。
 * @tag float
 */
int decm_arith(byte angle, undefined2 _a1)

{
  bool bVar1;
  undefined2 *puVar2;
  undefined2 unaff_ER4;
  
  puVar2 = (undefined2 *)dec_load_callee();
  if (angle == '\0') {
    angle = menu_sel_b;
  }
  dec_opcode = unaff_ER4;
  angle_mode = angle;
  dec_load_regs(puVar2);
  bVar1 = dec_check_nan_X();
  if (bVar1) {
    dec_zero_helper();
  }
  else {
    decc_int_entry();
    if (calc_state_b < 9) {
      decc_addinit();
    }
    else if (calc_state_b == 9) {
      decc_rounded_add();
    }
    else {
      decc_add_special();
    }
    dec_ieee_norm();
  }
  dec_store();
  dec_status_low();
  return 0;
}

/**
 * @brief 乘法入口 ×
 * @addr 0x1CEA4
 * @module eval
 * @proto int decm_mul(undefined2* save, undefined2* p)
 * @confidence verified
 * @note 【乘法入口 ×】载入 X←*p，调用 0x19A56（乘法核心），角度取 0xD11D，结果规格化并写回 *save。
 * @tag float
 */
int decm_mul(undefined2* save, undefined2* p)

{
  undefined2 uVar1;
  
  dec_param_a = save;
  dec_param_b = p;
  dec_bin_arith();
  dec_load(p);
  uVar1 = dec_check_nan_XY();
  if ((char)uVar1 == '\0') {
    decc_load_Y();
    angle_mode = menu_sel_b;
    dec_deg_rad_convert();
    dec_ieee_norm();
  }
  else {
    dec_zero_helper();
  }
  dec_store();
  dec_status_low();
  return 0;
}

/**
 * @brief 除法入口 ÷
 * @addr 0x1CEE8
 * @module eval
 * @proto void decm_div(undefined2* save, undefined2* p)
 * @confidence verified
 * @note 【除法入口 ÷】与 decm_mul 相同，但角度参数固定为 5（度，角度参数不参与乘除）。
 * @tag float
 */
int decm_div(undefined2* save, undefined2* p)

{
  undefined2 uVar1;
  
  dec_param_a = save;
  dec_param_b = p;
  dec_bin_arith();
  dec_load(p);
  uVar1 = dec_check_nan_XY();
  if ((char)uVar1 == '\0') {
    decc_load_Y();
    angle_mode = 5;
    dec_deg_rad_convert();
    dec_ieee_norm();
  }
  else {
    dec_zero_helper();
  }
  dec_store();
  dec_status_low();
  return 0;
}

/**
 * @brief ln
 * @addr 0x1CF0C
 * @module eval
 * @proto int decm_ln(undefined2* a, undefined2* b)
 * @confidence verified
 * @note 【ln】装载 X←*a 后直接调用 0x1A008（自然对数核心），写回 *b。
 * @tag float
 */
int decm_ln(undefined2* a, undefined2* b)

{
  dec_opcode = 0xf;
  dec_param_a = a;
  dec_param_b = b;
  dec_load(b);
  decc_ln_core();
  dec_store();
  dec_status_low();
  return 0;
}

/**
 * @brief log
 * @addr 0x1CF28
 * @module eval
 * @proto void decm_log10(undefined2* a, undefined2* b)
 * @confidence strong
 * @note 【log】先交换 X/Y（0x1AFB8）再调用 0x19FF8（常用对数核心），写回 *b。
 * @tag float
 */
int decm_log10(undefined2* a, undefined2* b)

{
  dec_opcode = 0xe;
  dec_param_a = a;
  dec_param_b = b;
  dec_load(b);
  dec_swap_XY();
  decc_log10_core();
  dec_store();
  dec_status_low();
  return 0;
}

/**
 * @brief tan
 * @addr 0x1D246
 * @module eval
 * @proto void decm_tan(undefined2* a, undefined2* b)
 * @confidence verified
 * @note 【tan】把操作码设为 2 并以 (a,b) 调用
 *       0x1D280。调用点：0x15C22（求值器运算符）、0x20318（格式化/化简路径）。
 * @tag float
 */
int decm_tan(undefined2* a, undefined2* b)

{
  dec_opcode = 2;
  dec_param_a = a;
  dec_param_b = b;
  decm_unary_dispatch(b);
  return 0;
}

/**
 * @brief 1/x
 * @addr 0x1D25A
 * @module eval
 * @proto void decm_recip(undefined2* a, undefined2* b)
 * @confidence strong
 * @note 【1/x】把操作码设为 1 并以 (a,b) 调用 0x1D280。调用点 0x10C9C、0x10E14 后均紧跟
 *       dec_div，即先求倒数再相乘实现除法。
 * @tag float
 */
int decm_recip(undefined2* a, undefined2* b)

{
  dec_opcode = 1;
  dec_param_a = a;
  dec_param_b = b;
  decm_unary_dispatch(b);
  return 0;
}

/**
 * @brief 一元求值入口
 * @addr 0x1D26E
 * @module eval
 * @proto void decm_unary(undefined2* a, undefined2* b)
 * @confidence likely
 * @note 【一元求值入口】操作码 0（按 0xD01D 子操作码：取负/取绝对值等）→ 0x19D76，负零判断用 X/Y 交换。
 * @tag float
 */
int decm_unary(undefined2* a, undefined2* b)

{
  bool bVar1;
  byte bVar2;
  byte extraout_R1;
  
  dec_opcode = 0;
  dec_param_a = a;
  dec_param_b = b;
  dec_load(b);
  dec_is_nan();
  bVar1 = dec_is_nan_Y();
  if (((((extraout_R1 | bVar1) == 0) && (dec_flags != '\0')) && (dec_flags_Y != '\0')) &&
     (bVar2 = decc_unary_sign(), bVar2 == 0)) {
    dec_swap_XY();
    bVar2 = decc_unary_sign();
    if (bVar2 == 0) {
      dec_swap_XY();
      bVar1 = dec_opcode == 1;
      if (dec_opcode != 0) {
        if (bVar1) {
          dec_arith_neg();
          dec_cmp_core();
          goto LAB_rom_01d2ea;
        }
        bVar1 = dec_opcode == 3;
        if (dec_opcode < 3) {
          dec_arith_dual();
          dec_swap_XY();
          goto LAB_rom_01d2ea;
        }
      }
      bVar2 = bVar1 << 6;
      base_submode();
      if ((bVar2 >> 6 & 1) == 1) {
        decc_arith_core();
      }
      goto LAB_rom_01d2ea;
    }
  }
  dec_zero_helper();
LAB_rom_01d2ea:
  dec_store();
  dec_status_low();
  return 0;
}

/**
 * @brief 一元三角函数/倒数分派
 * @addr 0x1D280
 * @module eval
 * @proto void decm_unary_dispatch(void)
 * @confidence likely
 * @note 一元三角函数/倒数分派：按 0xD01E（1=1/x，2=tan）改写为对应的二元运算后继续。
 * @tag float
 */
int decm_unary_dispatch(uintptr_t _a2, int _a1)

{
  byte bVar1;
  bool bVar2;
  
  dec_load(_a1);
  bVar1 = dec_is_nan();
  bVar2 = dec_is_nan_Y();
  if (((((bVar1 | bVar2) == 0) && (dec_flags != '\0')) && (dec_flags_Y != '\0')) &&
     (bVar1 = decc_unary_sign(), bVar1 == 0)) {
    dec_swap_XY();
    bVar1 = decc_unary_sign();
    if (bVar1 == 0) {
      dec_swap_XY();
      bVar2 = dec_opcode == 1;
      if (dec_opcode != 0) {
        if (bVar2) {
          dec_arith_neg();
          dec_cmp_core();
          goto LAB_rom_01d2ea;
        }
        bVar2 = dec_opcode == 3;
        if (dec_opcode < 3) {
          dec_arith_dual();
          dec_swap_XY();
          goto LAB_rom_01d2ea;
        }
      }
      bVar1 = bVar2 << 6;
      base_submode();
      if ((bVar1 >> 6 & 1) == 1) {
        decc_arith_core();
      }
      goto LAB_rom_01d2ea;
    }
  }
  dec_zero_helper();
LAB_rom_01d2ea:
  dec_store();
  dec_status_low();
  return 0;
}

