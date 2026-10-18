/*
 * BCD 浮点库 / 1cf54_dec_bin_mul.c
 * 地址范围: 0x1CF54 - 0x1D730
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 二元运算入口（opcode 9 = 乘法）
 * @addr 0x1CF54
 * @module bcd
 * @proto int dec_bin_mul(undefined2* a, undefined2* b)
 * @confidence verified
 * @note 二元运算入口（opcode 9 = 乘法）：存 *b 到 0xD05C 后进入 0x1CFA4。
 * @tag bcd
 */
int dec_bin_mul(undefined2* a, undefined2* b)

{
  dec_opcode = 9;
  dec_param_a = a;
  dec_param_b = b;
  dec_bin_dispatch(a,b);
  return 0;
}

/**
 * @brief 二元运算入口（opcode 8 = 除法）
 * @addr 0x1CF68
 * @module bcd
 * @proto int dec_bin_div(undefined2* a, undefined2* b)
 * @confidence verified
 * @note 二元运算入口（opcode 8 = 除法）。
 * @tag bcd
 */
int dec_bin_div(undefined2* a, undefined2* b)

{
  dec_opcode = 8;
  dec_param_a = a;
  dec_param_b = b;
  dec_bin_dispatch(a,b);
  return 0;
}

/**
 * @brief 二元运算入口（opcode 7 = 逻辑与，见 0x1C880 的分派表）
 * @addr 0x1CF7C
 * @module bcd
 * @proto int dec_bin_and(undefined2* a, undefined2* b)
 * @confidence likely
 * @note 二元运算入口（opcode 7 = 逻辑与，见 0x1C880 的分派表）。
 * @tag bcd
 */
int dec_bin_and(undefined2* a, undefined2* b)

{
  dec_opcode = 7;
  dec_param_a = a;
  dec_param_b = b;
  dec_bin_dispatch(a,b);
  return 0;
}

/**
 * @brief 二元运算入口（opcode 6 = 乘方 x^y）
 * @addr 0x1CF90
 * @module bcd
 * @proto int dec_bin_pow(undefined2* a, undefined2* b)
 * @confidence likely
 * @note 二元运算入口（opcode 6 = 乘方 x^y）。
 * @tag bcd
 */
int dec_bin_pow(undefined2* a, undefined2* b)

{
  dec_opcode = 6;
  dec_param_a = a;
  dec_param_b = b;
  dec_bin_dispatch(a,b);
  return 0;
}

/**
 * @brief 二元运算主分派
 * @addr 0x1CFA4
 * @module bcd
 * @proto void dec_bin_dispatch(undefined2* a, undefined2* b)
 * @confidence verified
 * @note 二元运算主分派：按 0xD01E 操作码（0..9）选择 0x1CA7E 起的 10 个入口之一，结果写回
 *       *a（0xD05C 保存 *b）。
 * @tag bcd
 */
int dec_bin_dispatch(undefined2* a, undefined2* b)

{
  undefined2 uVar1;
  char cVar3;
  ushort uVar2;
  undefined unaff_R4;
  byte bVar4;
  
  uVar2 = CONCAT11(*(undefined *)a,unaff_R4) & 0xf0ff;
  if (((char)(uVar2 >> 8) == -0x80) ||
     (uVar2 = CONCAT11(*(undefined *)b,(char)uVar2) & 0xf0ff, (char)(uVar2 >> 8) == -0x80)) {
    bVar4 = (byte)uVar2;
    if (bVar4 < 7) {
      matrix_scan_186a8(a,b);
      return 0;
    }
    if (bVar4 != 7) {
      if (bVar4 != 8) {
        matrix_scan_186a0(a);
        return 0;
      }
      matrix_scan_1865c(a,b);
      return 0;
    }
    matrix_scan_186ec(a,b);
    return 0;
  }
  dec_load(b);
  uVar1 = dec_check_nan_XY();
  if ((char)uVar1 == '\0') {
    cVar3 = (char)((ushort)uVar1 >> 8);
    decc_dispatch();
    if (cVar3 != '\0') {
      decc_int_entry();
      if ((char)((dec_opcode < 6) << 7) < '\0') {
        if (cVar3 != -0x80) goto LAB_rom_01cff8;
      }
      else if (cVar3 != '@') goto LAB_rom_01cff8;
      uVar2 = dec_load_union();
      if ((char)uVar2 == '\x02') {
        dec_flags = dec_flags | 0x40;
      }
    }
  }
  else {
    dec_zero_helper();
  }
LAB_rom_01cff8:
  dec_store();
  dec_status_low();
  return 0;
}

/**
 * @brief 以 0x179D2 的结果为左操作数调用 0x1D17E
 * @addr 0x1D02E
 * @module bcd
 * @proto void dec_call_0179d2(undefined2 a, undefined2 b)
 * @confidence likely
 * @note 以 0x179D2 的结果为左操作数调用 0x1D17E。
 * @tag bcd
 */
int dec_call_0179d2(undefined2 a, undefined2 b)

{
  dec_param_a = (undefined2 *)dec_normalize2(a,b);
  dec_param_b = b;
  dec_unary_dispatch(dec_param_a);
  return 0;
}

/**
 * @brief 以 0x17A48/0x179D2 的结果调用 0x1D17E（2.4KB 分派）
 * @addr 0x1D044
 * @module bcd
 * @proto void dec_call_17a48(void)
 * @confidence likely
 * @note 以 0x17A48/0x179D2 的结果调用 0x1D17E（2.4KB 分派）。
 * @tag bcd
 */
int dec_call_17a48(uintptr_t _a3, uintptr_t _a4, int _a1, int _a2)

{
  char cVar1;
  ushort uVar2;
  undefined extraout_R1;
  short sVar3;
  undefined extraout_R1_00;
  undefined2 *puVar4;
  undefined extraout_R1_01;
  undefined extraout_R1_02;
  undefined2 *puVar5;
  undefined2 uVar6;
  byte bVar7;
  undefined uVar8;
  
  uVar8 = (undefined)((ushort)_a2 >> 8);
  cVar1 = is_edit_locked();
  puVar4 = (undefined2 *)CONCAT11(uVar8,cVar1);
  if (cVar1 == '\0') goto LAB_rom_01d030;
  puVar4 = (undefined2 *)(CONCAT11(uVar8,*(byte *)_a1) & 0xfff0);
  if ((*(byte *)_a1 & 0xf0) == 0) {
    puVar4 = (undefined2 *)_a1[4];
    bVar7 = (byte)((ushort)puVar4 >> 8);
    if ((1 < bVar7) || ((bVar7 != 0 && (6 < (byte)puVar4)))) goto LAB_rom_01d030;
    uVar6 = eval_recip(_a1);
    puVar4 = (undefined2 *)CONCAT11((char)((ushort)puVar4 >> 8),(char)uVar6);
    if ((char)uVar6 != '\0') goto LAB_rom_01d030;
  }
  else if (((char)puVar4 != ' ') ||
          (puVar4 = (undefined2 *)
                    CONCAT11((char)((ushort)puVar4 >> 8),*(char *)((short)_a1 + 9)),
          *(char *)((short)_a1 + 9) != '\x01')) goto LAB_rom_01d030;
  uVar8 = (undefined)((ushort)puVar4 >> 8);
  dec_op_setup((uintptr_t)0, (uintptr_t)0);
  sVar3 = dec_ptr_by_idx(CONCAT11(extraout_R1,3));
  bVar7 = *(byte *)(sVar3 + 8);
  if ((bVar7 < 7) && (bVar7 = *(byte *)(sVar3 + 0x1c), bVar7 < 4)) {
    dec_arg_load(3);
    puVar4 = (undefined2 *)dec_ptr_by_idx(CONCAT11(extraout_R1_00,3));
    matrix_copy_ext(puVar4,puVar4 + -0xf);
    dec_arg_load(5);
    matrix_copy_ext(puVar4 + 10,puVar4 + -0xf);
    dec_unary_calc(0x604,4);
    dec_unary_calc(0x605,5);
    dec_arg_load(1);
    puVar4 = (undefined2 *)dec_ptr_by_idx(CONCAT11(extraout_R1_01,6));
    dec_copy(puVar4,_a1);
    uVar2 = dec_calc_main(0,extraout_R1_02,(char)_a1,(char)((ushort)_a1 >> 8));
    if ((char)uVar2 != '\0') {
      return uVar2;
    }
    puVar5 = (undefined2 *)(CONCAT11((char)((ushort)puVar4 >> 8),*(undefined *)puVar4) & 0xfff0);
    if ((((char)puVar5 != ' ') || (puVar5 = _a1, (*(byte *)_a1 & 0xf0) == 0x20)) ||
       ((*(byte *)_a1 & 0xf0) == 0x80)) {
      return (ushort)puVar5 & 0xff00;
    }
    dec_copy(_a1,puVar4);
  }
  else {
    puVar4 = (undefined2 *)CONCAT11(uVar8,bVar7);
  }
LAB_rom_01d030:
  dec_param_a = (undefined2 *)dec_normalize2(_a1,puVar4);
  dec_param_b = puVar4;
  uVar2 = dec_unary_dispatch(dec_param_a);
  return uVar2;
}

/**
 * @brief BCD 舍入/格式化辅助
 * @addr 0x1D134
 * @module bcd
 * @proto undefined2* dec_round(undefined2* a, undefined2 b)
 * @confidence likely
 * @note BCD 舍入/格式化辅助。
 * @tag format
 */
undefined2* dec_round(undefined2* a, undefined2 b)

{
  dec_call_17a48(a,b);
  return;
}

/**
 * @brief 设置 _D05C/_D05E 后以 0x17A48 结果调用 0x1D17E
 * @addr 0x1D13C
 * @module bcd
 * @proto void dec_call_1d17e_a(undefined2* a, undefined2* b)
 * @confidence likely
 * @note 设置 _D05C/_D05E 后以 0x17A48 结果调用 0x1D17E。
 * @tag bcd
 */
int dec_call_1d17e_a(undefined2* a, undefined2* b)

{
  undefined2 *puVar1;
  
  dec_param_a = a;
  dec_param_b = b;
  puVar1 = (undefined2 *)dec_load_callee();
  dec_unary_dispatch(puVar1);
  return 0;
}

/**
 * @brief 设置 _D05C/_D05E 后直接以 a 调用 0x1D17E
 * @addr 0x1D150
 * @module bcd
 * @proto void dec_call_1d17e_b(undefined2* a, undefined2* b)
 * @confidence likely
 * @note 设置 _D05C/_D05E 后直接以 a 调用 0x1D17E。
 * @tag bcd
 */
int dec_call_1d17e_b(undefined2* a, undefined2* b)

{
  dec_param_a = a;
  dec_param_b = b;
  dec_unary_dispatch(a);
  return 0;
}

/**
 * @brief 0x1D150 的变体（含不可达块，返回 0x1D17E 结果）
 * @addr 0x1D160
 * @module bcd
 * @proto void dec_call_1d17e_c(undefined2* a, undefined2* b)
 * @confidence likely
 * @note 0x1D150 的变体（含不可达块，返回 0x1D17E 结果）。
 * @tag bcd
 */
int dec_call_1d17e_c(undefined2* a, undefined2* b)

{
  dec_param_a = a;
  dec_param_b = b;
  dec_unary_dispatch(a);
  return 0;
}

/**
 * @brief 设置后 0x1C364 载入再按 0x1B3D0 选择 0x1C81A/0x19EDA 的入…
 * @addr 0x1D170
 * @module bcd
 * @proto int dec_call_1d17e_d(undefined2* a, undefined2* b)
 * @confidence likely
 * @note 设置后 0x1C364 载入再按 0x1B3D0 选择 0x1C81A/0x19EDA 的入口。
 * @tag bcd
 */
int dec_call_1d17e_d(undefined2* a, undefined2* b)

{
  bool bVar1;
  
  dec_param_a = a;
  dec_param_b = b;
  dec_load_regs(a);
  bVar1 = dec_check_nan_X();
  if (bVar1) {
    dec_zero_helper();
  }
  else {
    decc_neg_process();
  }
  dec_store();
  dec_status_low();
  return 0;
}

/**
 * @brief 一元运算分派
 * @addr 0x1D17E
 * @module bcd
 * @proto int dec_unary_dispatch(undefined2* a)
 * @confidence strong
 * @note 一元运算分派：0x1C364 载入后按 R4 选择 0x19EDA 等核心（0x1D02E..0x1D160 共用）。
 * @tag bcd
 */
int dec_unary_dispatch(undefined2* a)

{
  bool bVar1;
  byte unaff_R4;
  
  dec_load_regs(a);
  bVar1 = dec_check_nan_X();
  if (bVar1) {
    dec_zero_helper();
  }
  else if (unaff_R4 == 0) {
    decc_neg_process();
  }
  else if (unaff_R4 == 1) {
    dec_raw_entry();
  }
  else if (unaff_R4 < 3) {
    decc_abs_process();
  }
  else if (unaff_R4 == 3) {
    decm_log_entry();
  }
  else {
    dec_exp_last();
  }
  dec_store();
  dec_status_low();
  return 0;
}

/**
 * @brief 入口状态 3（D05A=3）
 * @addr 0x1D1C6
 * @module bcd
 * @proto void dec_entry_x(undefined2* a, undefined2* b)
 * @confidence strong
 * @note 入口状态 3（D05A=3）：0x1C364/0x1B3A0/0x1A79A 路径（get_* 系列调用）。
 * @tag bcd
 */
int dec_entry_x(undefined2* a, undefined2* b)

{
  char cVar1;
  
  dec_work_a = 3;
  dec_param_a = a;
  dec_param_b = b;
  dec_load_regs(a);
  cVar1 = dec_is_special();
  if (cVar1 == '\0') {
    decc_int_entry();
  }
  else {
    dec_zero_helper();
  }
  dec_store();
  dec_status_low();
  return 0;
}

/**
 * @brief 入口状态 2（D05A=2）
 * @addr 0x1D1DA
 * @module bcd
 * @proto void dec_entry_y(undefined2* a, undefined2* b)
 * @confidence strong
 * @note 入口状态 2（D05A=2）：0x1A4F6 整数路径（或 0x1A79A）。
 * @tag bcd
 */
int dec_entry_y(undefined2* a, undefined2* b)

{
  char cVar1;
  
  dec_work_a = 2;
  dec_param_a = a;
  dec_param_b = b;
  dec_load_regs(a);
  cVar1 = dec_is_special();
  if (cVar1 == '\0') {
    decc_int_arith();
  }
  else {
    dec_zero_helper();
  }
  dec_store();
  dec_status_low();
  return 0;
}

/**
 * @brief 入口状态 1（D05A=1）
 * @addr 0x1D1EE
 * @module bcd
 * @proto void dec_entry_z(undefined2* a, undefined2* b)
 * @confidence strong
 * @note 入口状态 1（D05A=1）：0x1A4F6 整数路径。
 * @tag bcd
 */
int dec_entry_z(undefined2* a, undefined2* b)

{
  char cVar1;
  
  dec_work_a = 1;
  dec_param_a = a;
  dec_param_b = b;
  dec_load_regs(a);
  cVar1 = dec_is_special();
  if (cVar1 == '\0') {
    decc_int_arith();
  }
  else {
    dec_zero_helper();
  }
  dec_store();
  dec_status_low();
  return 0;
}

/**
 * @brief 入口状态 0（D05A=0）
 * @addr 0x1D202
 * @module bcd
 * @proto void dec_entry_w(undefined2* a, undefined2* b)
 * @confidence strong
 * @note 入口状态 0（D05A=0）：0x1A4F6 整数路径。
 * @tag bcd
 */
int dec_entry_w(undefined2* a, undefined2* b)

{
  char cVar1;
  
  dec_work_a = 0;
  dec_param_a = a;
  dec_param_b = b;
  dec_load_regs(a);
  cVar1 = dec_is_special();
  if (cVar1 == '\0') {
    decc_int_arith();
  }
  else {
    dec_zero_helper();
  }
  dec_store();
  dec_status_low();
  return 0;
}

/**
 * @brief 整数加法
 * @addr 0x1D2FE
 * @module bcd
 * @proto int dec_int_add(undefined2* a, undefined2* b)
 * @confidence strong
 * @note 整数加法：0x1C35C 载入、0x1B3E4 判定后 0x1A6C8（D01E=7）。
 * @tag bcd
 */
int dec_int_add(undefined2* a, undefined2* b)

{
  undefined2 uVar1;
  
  dec_param_a = a;
  dec_param_b = b;
  dec_load(b);
  uVar1 = dec_check_nan_XY();
  if ((char)uVar1 == '\0') {
    decc_entry_7();
  }
  else {
    dec_zero_helper();
  }
  dec_store();
  dec_status_low();
  return 0;
}

/**
 * @brief 复制 a/b 到局部后调用 0x1D780
 * @addr 0x1D32E
 * @module bcd
 * @proto void dec_copy_pair(undefined2* a, undefined2* b)
 * @confidence likely
 * @note 复制 a/b 到局部后调用 0x1D780。
 * @tag bcd
 */
int dec_copy_pair(undefined2* a, undefined2* _a1)

{
  byte bVar1;
  undefined extraout_R1;
  ushort uVar2;
  undefined2 *puVar3;
  undefined2 auStack_16 [9];
  
  puVar3 = auStack_16;
  dec_copy(auStack_16,a);
  dec_bin_init(puVar3,a);
  bVar1 = dec_shift_mant();
  uVar2 = CONCAT11(extraout_R1,bVar1);
  if ((bVar1 == 0) && (uVar2 = dec_to_string(puVar3,(undefined2 *)0x1b76), (char)uVar2 != '\x02'))
  {
    uVar2 = uVar2 & 0xff00;
  }
  else {
    uVar2 = CONCAT11((char)(uVar2 >> 8),1);
  }
  return uVar2;
}

/**
 * @brief 0x1C364 载入后 0x19D6E 判定，若有效返回 0xF0
 * @addr 0x1D368
 * @module bcd
 * @proto byte dec_type_flag(undefined2* a, undefined2* b)
 * @confidence likely
 * @note 0x1C364 载入后 0x19D6E 判定，若有效返回 0xF0。
 * @tag bcd
 */
byte dec_type_flag(undefined2* a, undefined2* b)

{
  byte bVar1;
  
  dec_param_a = a;
  dec_param_b = b;
  dec_load_regs(a);
  bVar1 = dec_shift_mant();
  if (bVar1 != 0) {
    bVar1 = 0xf0;
  }
  return bVar1;
}

/**
 * @brief 比较 *a 与 b
 * @addr 0x1D37E
 * @module bcd
 * @proto byte dec_cmp_status(undefined2* a, undefined2 b)
 * @confidence strong
 * @note 比较 *a 与 b：装载 a 后调用 0x19D76 归一化，失败返回 0xF0。
 * @tag bcd
 */
byte dec_cmp_status(undefined2* a, undefined2 b)

{
  byte bVar1;
  
  dec_param_a = a;
  dec_param_b = b;
  dec_load_regs(a);
  bVar1 = decc_unary_sign();
  if (bVar1 != 0) {
    bVar1 = 0xf0;
  }
  return bVar1;
}

/**
 * @brief 直角坐标→极坐标
 * @addr 0x1D39E
 * @module bcd
 * @proto undefined dec_to_polar(ushort* p)
 * @confidence likely
 * @note 直角坐标→极坐标：把 *p 与 *(p+5) 两个 BCD 数转为模与辐角（用 0x1CF90/0x1D134 等）。
 * @tag complex
 */
undefined dec_to_polar(ushort* p)

{
  undefined uVar1;
  undefined2 *puVar2;
  short sVar3;
  undefined2 uVar4;
  undefined2 *puVar5;
  ushort *puVar6;
  undefined2 *puVar7;
  undefined2 auStack_1c [4];
  undefined2 uStack_14;
  undefined2 auStack_12 [4];
  undefined2 uStack_a;
  
  if ((0xef < *(byte *)p) ||
     (uVar4 = CONCAT11(*(byte *)(p + 5),*(byte *)p), 0xef < *(byte *)(p + 5))) {
    dec_set_special(p,3);
    return 0;
  }
  puVar5 = auStack_1c;
  puVar7 = auStack_1c;
  dec_bin_result(p,uVar4);
  dec_bin_result(p + 5,uVar4);
  uVar1 = 0;
  if (*(char *)(p + 5) == '\0') goto LAB_rom_01d4aa;
  if (*(char *)p == '\0') {
    dec_copy_ret(p + 5,p);
    uVar1 = 0;
    goto LAB_rom_01d4aa;
  }
  puVar2 = dec_copy_ret(p,auStack_1c);
  puVar5 = (undefined2 *)((short)puVar5 + 10);
  dec_copy_ret(puVar2 + 5,puVar5);
  sVar3 = dec_cmp_signed(auStack_1c,puVar5);
  dec_cmp_signed(sVar3 + 10,puVar5);
  if ((char)((ushort)uStack_14 >> 8) == '\x01') {
    if ((byte)uStack_14 < 0x49) {
LAB_rom_01d410:
      if ((char)((ushort)uStack_a >> 8) == '\x01') {
        if ((byte)uStack_a < 0x49) {
LAB_rom_01d420:
          dec_xy_sub(auStack_1c,uStack_a);
          dec_xy_sub(auStack_12,uStack_a);
          dec_bin_xor_core(auStack_1c,auStack_12);
          puVar6 = p;
          dec_copy_ret(auStack_1c,p);
          uVar1 = dec_round(p,puVar6);
          goto LAB_rom_01d4aa;
        }
      }
      else if (0x50 < (byte)uStack_a) goto LAB_rom_01d420;
    }
  }
  else if (0x50 < (byte)uStack_14) goto LAB_rom_01d410;
  uVar4 = dec_to_string(auStack_1c,auStack_12);
  if ((char)uVar4 == '\x04') {
    dec_copy_ret(p,p + 5);
    dec_copy_ret(auStack_12,p);
  }
  else {
    dec_copy_ret(auStack_1c,p);
    puVar7 = auStack_12;
  }
  dec_bin_and_core(p,puVar7);
  dec_xy_sub(p,puVar7);
  uVar4 = 0x1b6c;
  dec_bin_xor_core(p,(undefined2 *)0x1b6c);
  dec_call_0179d2(p,uVar4);
  uVar1 = dec_bin_pow(p,p + 5);
LAB_rom_01d4aa:
  dec_copy_ret((undefined2 *)0x1b62,p + 5);
  return uVar1;
}

/**
 * @brief 转换入口 A（0x1B3BE 后按低半字节 1..4 选择 0x1B342/0x1B35A/…
 * @addr 0x1D530
 * @module bcd
 * @proto int dec_to_bcd_a(undefined2 a, byte b)
 * @confidence likely
 * @note 转换入口 A（0x1B3BE 后按低半字节 1..4 选择 0x1B342/0x1B35A/0x1B388）。
 * @tag bcd
 */
int dec_to_bcd_a(undefined2 a, byte b)

{
  bool bVar1;
  byte bVar2;
  char cVar3;
  
  bVar2 = (byte)b;
  cVar3 = '\x02';
  dec_param_a = a;
  dec_param_b = b;
  dec_load_regs(a);
  bVar1 = dec_is_nan();
  if (bVar1) {
    dec_zero_helper();
  }
  else if (cVar3 == '\x02') {
    dec_neg_core();
  }
  else {
    dec_accum7 = '\x0f' - bVar2;
    if (0xf < bVar2) {
      dec_accum7 = '\0';
    }
    if ((char)((cVar3 == '\0') << 7) < '\0') {
      dec_fix_frac();
    }
    else {
      dec_fix_integral();
    }
    if (0xef < dec_flags) {
      dec_load_regs(dec_param_a);
      dec_fix_zero_frac();
    }
  }
  dec_store();
  dec_status_low();
  return 0;
}

/**
 * @brief 转换入口 B（与 A 对称，起始值 1）
 * @addr 0x1D540
 * @module bcd
 * @proto void dec_to_bcd_b(undefined2 a, byte b)
 * @confidence likely
 * @note 转换入口 B（与 A 对称，起始值 1）。
 * @tag bcd
 */
int dec_to_bcd_b(undefined2 a, byte b)

{
  bool bVar1;
  byte bVar2;
  char cVar3;
  
  bVar2 = (byte)b;
  cVar3 = '\x01';
  dec_param_a = a;
  dec_param_b = b;
  dec_load_regs(a);
  bVar1 = dec_is_nan();
  if (bVar1) {
    dec_zero_helper();
  }
  else if (cVar3 == '\x02') {
    dec_neg_core();
  }
  else {
    dec_accum7 = '\x0f' - bVar2;
    if (0xf < bVar2) {
      dec_accum7 = '\0';
    }
    if ((char)((cVar3 == '\0') << 7) < '\0') {
      dec_fix_frac();
    }
    else {
      dec_fix_integral();
    }
    if (0xef < dec_flags) {
      dec_load_regs(dec_param_a);
      dec_fix_zero_frac();
    }
  }
  dec_store();
  dec_status_low();
  return 0;
}

/**
 * @brief BCD 指数移位/缩放
 * @addr 0x1D550
 * @module bcd
 * @proto undefined2* dec_exp_shift(undefined2* a, ushort b)
 * @confidence likely
 * @note BCD 指数移位/缩放。
 * @tag bcd
 */
undefined2* dec_exp_shift(undefined2* a, ushort b)

{
  bool bVar1;
  ushort uVar2;
  char cVar3;
  
  uVar2 = b & 0xff;
  dec_param_a = a;
  dec_param_b = b;
  dec_load_regs(a);
  bVar1 = dec_is_nan();
  if (bVar1) {
    dec_zero_helper();
  }
  else {
    cVar3 = (char)(uVar2 >> 8);
    if (cVar3 == '\x02') {
      dec_neg_core();
    }
    else {
      dec_accum7 = '\x0f' - (byte)uVar2;
      if (0xf < (byte)uVar2) {
        dec_accum7 = '\0';
      }
      if ((char)((cVar3 == '\0') << 7) < '\0') {
        dec_fix_frac();
      }
      else {
        dec_fix_integral();
      }
      if (0xef < dec_flags) {
        dec_load_regs(dec_param_a);
        dec_fix_zero_frac();
      }
    }
  }
  dec_store();
  dec_status_low();
  return;
}

/**
 * @brief 比较 a 与 b
 * @addr 0x1D5B6
 * @module bcd
 * @proto undefined2 dec_cmp(undefined2* a, undefined2 b)
 * @confidence verified
 * @note 比较 a 与 b。
 * @tag bcd
 */
undefined2 dec_cmp(undefined2* a, undefined2 b)

{
  undefined extraout_R1;
  short sVar1;
  undefined2 uVar2;
  char cVar4;
  byte bVar5;
  byte extraout_R1_00;
  ushort uVar3;
  
  dec_param_a = a;
  dec_param_b = b;
  dec_load_regs(a);
  sVar1 = CONCAT11(extraout_R1,dec_flags);
  if (dec_flags == '\0') {
LAB_rom_01d5e4:
    uVar2 = CONCAT11((char)((ushort)sVar1 >> 8),1);
  }
  else {
    uVar3 = CONCAT11(extraout_R1,dec_flags) & 0xfff0;
    bVar5 = (byte)uVar3;
    if (bVar5 == 0x80) {
      cVar4 = (char)((ushort)dec_accum0 >> 8);
      if (cVar4 == '\0') {
        sVar1 = dec_accum0 << 8;
      }
      else {
        bVar5 = cVar4 + (char)dec_accum0;
        sVar1 = (ushort)bVar5 << 8;
        if (bVar5 == 7) {
          dec_core_17e8e((char)dec_param_a,(char)((ushort)dec_param_a >> 8),0, (uintptr_t)0)
                         (char)((ushort)b >> 8));
          uVar3 = dec_ptr_by_idx((ushort)extraout_R1_00 << 8);
          dec_load_and_run(uVar3 & 0xff00,uVar3);
          sVar1 = dec_accum0;
        }
      }
    }
    else {
      if (0x4f < bVar5) {
        return CONCAT11((char)(uVar3 >> 8),0xf0);
      }
      sVar1 = dec_accum0;
      if (dec_accum0 == 0) goto LAB_rom_01d5e4;
    }
    bVar5 = (byte)((ushort)sVar1 >> 8);
    if (bVar5 < 4) {
      uVar2 = CONCAT11(bVar5,4);
    }
    else {
      uVar2 = CONCAT11(bVar5,2);
    }
  }
  return uVar2;
}

/**
 * @brief 按格式把数值转为字符串
 * @addr 0x1D620
 * @module bcd
 * @proto undefined2 dec_to_string(undefined2 fmt, undefined2* out)
 * @confidence strong
 * @note 按格式把数值转为字符串。
 * @tag format
 */
undefined2 dec_to_string(undefined2 fmt, undefined2* out)

{
  bool bVar1;
  byte extraout_R1;
  undefined2 uVar2;
  
  dec_tmp_flag = 0;
  dec_param_a = fmt;
  dec_param_b = out;
  dec_load(out);
  dec_is_nan();
  bVar1 = dec_is_nan_Y();
  if ((extraout_R1 | bVar1) == 0) {
    uVar2 = dec_special_check();
  }
  else {
    uVar2 = CONCAT11(extraout_R1 | bVar1,0xf0);
  }
  return uVar2;
}

/**
 * @brief 带 0xD03A 缩放的舍入（0x1C35C/0x1B3BE 链）
 * @addr 0x1D654
 * @module bcd
 * @proto int dec_round_scaled(undefined2* a, undefined2* b)
 * @confidence likely
 * @note 带 0xD03A 缩放的舍入（0x1C35C/0x1B3BE 链）。
 * @tag bcd
 */
int dec_round_scaled(undefined2* a, undefined2* b)

{
  bool bVar1;
  byte extraout_R1;
  undefined2 uVar2;
  
  dec_tmp_flag = 1;
  dec_param_a = a;
  dec_param_b = b;
  dec_load(b);
  dec_is_nan();
  bVar1 = dec_is_nan_Y();
  if ((extraout_R1 | bVar1) == 0) {
    uVar2 = dec_special_check();
  }
  else {
    uVar2 = CONCAT11(extraout_R1 | bVar1,0xf0);
  }
  return uVar2;
}

/**
 * @brief 返回 BCD 单元类型字节
 * @addr 0x1D668
 * @module bcd
 * @proto undefined dec_type_of(undefined* p)
 * @confidence likely
 * @note 返回 BCD 单元类型字节。
 * @tag bcd
 */
undefined dec_type_of(undefined* p)

{
  return CONCAT11((char)((ushort)p >> 8),*p) & 0xfff0;
}

/**
 * @brief 把 dst 设为小整数 v（v<10 时存为 0x00v0 型小整数，否则置错误标记 0xF…
 * @addr 0x1D66E
 * @module bcd
 * @proto short dec_set_uint_small(ushort* dst, byte v)
 * @confidence verified
 * @note 把 dst 设为小整数 v（v<10 时存为 0x00v0 型小整数，否则置错误标记 0xF0）。
 * @tag bcd
 */
short dec_set_uint_small(ushort* dst, byte v)

{
  byte bVar2;
  short sVar1;
  ushort uVar3;
  
  bVar2 = (byte)((ushort)dst >> 8);
  if (v < 10) {
    uVar3 = 0x100;
    if (v == 0) {
      uVar3 = 0;
    }
    *dst = (ushort)v;
    dst[1] = 0;
    dst[2] = 0;
    dst[3] = 0;
    dst[4] = uVar3;
    sVar1 = (ushort)bVar2 << 8;
  }
  else {
    dst[1] = 0;
    *dst = 0;
    dst[3] = 0;
    dst[2] = 0;
    dst[4] = 0;
    sVar1 = CONCAT11(bVar2,0xf0);
  }
  return sVar1;
}

/**
 * @brief 把 dst 设为特殊值（v<0x10 时首字节 0xF0|v，否则 0xF3）
 * @addr 0x1D6A4
 * @module bcd
 * @proto ushort* dec_set_special(ushort* dst, byte v)
 * @confidence verified
 * @note 把 dst 设为特殊值（v<0x10 时首字节 0xF0|v，否则 0xF3）；用于错误/未定义结果。
 * @tag bcd
 */
ushort* dec_set_special(ushort* dst, byte v)

{
  ushort uVar1;
  
  if ((v < 0x10) && (v != 0)) {
    uVar1 = (ushort)(v | 0xf0);
  }
  else {
    uVar1 = 0xf3;
  }
  *dst = uVar1;
  dst[1] = 0;
  dst[2] = 0;
  dst[3] = 0;
  dst[4] = 0;
  return (ushort)dst & 0xff00;
}

/**
 * @brief 带特殊值处理的比较
 * @addr 0x1D6CA
 * @module bcd
 * @proto void dec_cmp_special(undefined2* a, undefined2* b)
 * @confidence likely
 * @note 带特殊值处理的比较：先 0x1C35C 载入 b，再按 D009/D019 的特殊标志分支。
 * @tag bcd
 */
int dec_cmp_special(undefined2* a, undefined2* b)

{
  undefined uVar1;
  
  dec_param_a = a;
  dec_param_b = b;
  dec_load(b);
  if (dec_flags < 0xf0) {
    if (dec_flags_Y < 0xf0) {
      if (dec_flags_Y == 0) {
        dec_accum1 = 0;
        dec_accum0 = 0;
        dec_accum3 = 0;
        dec_accum2 = 0;
        dec_accum4 = 0;
      }
      else {
        if (((char)(((byte)((ushort)dec_regY >> 8) < 5) << 7) < '\0') || (dec_flags == 0))
        goto LAB_rom_01d720;
        uVar1 = daa((char)(dec_accum0 >> 8) + '\x05');
        dec_accum0 = CONCAT11(uVar1,(char)dec_accum0) & 0xfff;
      }
    }
    else {
      dec_zero_helper();
    }
    dec_store();
  }
LAB_rom_01d720:
  dec_status_low();
  return 0;
}

/**
 * @brief BCD 运算后处理
 * @addr 0x1D730
 * @module bcd
 * @proto void dec_inc5(undefined2* a, undefined2 b)
 * @confidence strong
 * @note BCD 运算后处理：对结果做 5 的 DAA 进位修正。
 * @tag bcd
 */
int dec_inc5(undefined2* a, undefined2 b)

{
  undefined uVar1;
  
  dec_param_a = a;
  dec_param_b = b;
  dec_load_regs(a);
  if (((dec_flags == 0) || (0xef < dec_flags)) || (dec_flags == 0x40)) goto LAB_rom_01d766;
  if ((dec_flags & 0xf0) == 0x80) {
    uVar1 = daa((char)dec_accum0 + '\x05');
    dec_accum0 = CONCAT11((char)(dec_accum0 >> 8),uVar1) & 0xff0f;
    if ((char)(dec_accum0 >> 8) != '\0') goto LAB_rom_01d758;
  }
  else {
LAB_rom_01d758:
    uVar1 = daa((char)(dec_accum0 >> 8) + '\x05');
    dec_accum0 = CONCAT11(uVar1,(char)dec_accum0) & 0xfff;
  }
  dec_store();
LAB_rom_01d766:
  dec_status_low();
  return 0;
}

