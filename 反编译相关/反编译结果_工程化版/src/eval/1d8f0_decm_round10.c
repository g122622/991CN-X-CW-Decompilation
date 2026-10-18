/*
 * 表达式求值 / 1d8f0_decm_round10.c
 * 地址范围: 0x1D8F0 - 0x1D8F0
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief x10^x / Rnd 等一元辅助
 * @addr 0x1D8F0
 * @module eval
 * @proto int decm_round10(undefined2* a, undefined2* b)
 * @confidence likely
 * @note 【x10^x / Rnd 等一元辅助】按 0xD01E 选择 0x1BBA8 或 0x195EA，结果写回 *b。
 * @tag float
 */
int decm_round10(undefined2* a, undefined2* b)

{
  bool bVar1;
  undefined2 *puVar2;
  char cVar3;
  
  cVar3 = '\x01';
  dec_param_a = a;
  dec_param_b = b;
  puVar2 = (undefined2 *)dec_load_callee();
  dec_opcode = cVar3;
  dec_load_regs(puVar2);
  bVar1 = dec_check_nan_X();
  if (bVar1) {
    dec_zero_helper();
  }
  else {
    decc_int_entry();
    if (dec_opcode == '\0') {
      dec_abs_core();
    }
    else {
      dec_unary_abs();
    }
  }
  dec_store();
  dec_status_low();
  return 0;
}

