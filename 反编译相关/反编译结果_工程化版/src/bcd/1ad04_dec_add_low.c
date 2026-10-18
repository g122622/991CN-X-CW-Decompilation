/*
 * BCD 浮点库 / 1ad04_dec_add_low.c
 * 地址范围: 0x1AD04 - 0x1B418
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief D009<0xF 时进入 0x1AD2E（低位加法路径）
 * @addr 0x1AD04
 * @module bcd
 * @proto void dec_add_low(void)
 * @confidence verified
 * @note D009<0xF 时进入 0x1AD2E（低位加法路径）。
 * @tag bcd
 */
int dec_add_low(void)

{
  if (0xef < dec_flags) {
    return 0;
  }
  dec_align_shift();
  return 0;
}

/**
 * @brief 按运算阶段 0xD01F（8/9/其它）与操作码 0xD01E 做尾数对齐/移位（1.8KB…
 * @addr 0x1AD2E
 * @module bcd
 * @proto void dec_align_shift(void)
 * @confidence likely
 * @note 按运算阶段 0xD01F（8/9/其它）与操作码 0xD01E 做尾数对齐/移位（1.8KB）。
 * @tag bcd
 */
int dec_align_shift(void)

{
  char cVar1;
  undefined8 uVar2;
  undefined2 uVar3;
  undefined uVar8;
  ushort uVar4;
  uint3 uVar5;
  byte bVar7;
  ulonglong uVar6;
  
  _DAT_ram_d02d = '\0';
  dec_ieee_add();
  if (8 < calc_state_b) {
    if (calc_state_b == 9) {
      dec_g_Y_to_Z();
      _DAT_ram_d02d = '\x05';
    }
    else if (dec_opcode == 2) {
      dec_g_W_to_X();
      dec_build_const();
      uVar2 = _DAT_ram_d052;
      uVar8 = daa((char)(dec_accum0 >> 8) + _DAT_ram_d02d);
      uVar4 = CONCAT11(uVar8,(char)dec_accum0) & 0xfff;
      _DAT_ram_d052 = dec_accum1;
      dec_accum1 = uVar2;
      dec_accum0 = dec_regW;
      dec_regW = uVar4;
      if (calc_state_b == 10) {
        dec_g_Z_to_Y();
        dec_tail_round();
      }
      else {
        dec_set_Y_1e0();
      }
      dec_g_Y_to_X();
      if (2 < dec_opcode) {
        return 0;
      }
      dec_int_convert();
      goto LAB_rom_01ad6e;
    }
  }
  dec_g_X_to_Y_copy();
  dec_set_Y_1e0();
  if (calc_state_b == 8) {
    return 0;
  }
LAB_rom_01ad6e:
  uVar3 = calc_state_g;
  uVar2 = calc_state_e;
  stat_calc_proc();
  calc_state_e = uVar2;
  calc_state_g = uVar3;
  dec_g_Z_to_Y();
  if (_DAT_ram_d02d != '\0') {
    dec_int_convert();
    dec_align_tmp = 0;
    _DAT_ram_d02b = 0;
    cVar1 = '\0';
    do {
      uVar8 = daa(cVar1 + '\x05');
      uVar5 = CONCAT12(uVar8,dec_accum0) & 0xfffff;
      cVar1 = (char)(uVar5 >> 0x10);
      bVar7 = daa((char)(uVar5 >> 8) + '\x05');
      dec_accum0 = CONCAT11(bVar7,(char)uVar5);
    } while ((char)((bVar7 < 0x10) << 7) < '\0');
    uVar6 = (ulonglong)CONCAT12(cVar1,dec_accum0) & 0xffffffffffff0fff;
    _DAT_ram_d02c = (undefined)(uVar6 >> 0x10);
    dec_accum0 = (ushort)uVar6;
  }
  return 0;
}

/**
 * @brief 舍入加法
 * @addr 0x1AE22
 * @module bcd
 * @proto void dec_round_add(void)
 * @confidence likely
 * @note 舍入加法：0x19C68 规整后 0x1C450 加 5 并按 D02D 处理进位（1.4KB）。
 * @tag bcd
 */
int dec_round_add(void)

{
  char cVar1;
  undefined2 uVar2;
  undefined8 uVar3;
  byte bVar6;
  undefined uVar7;
  uint3 uVar4;
  ulonglong uVar5;
  
  if (0xef < dec_flags) {
    return 0;
  }
  _DAT_ram_d02d = '\0';
  dec_g_W_to_X();
  dec_round_final();
  uVar3 = _DAT_ram_d052;
  uVar2 = dec_accum0;
  _DAT_ram_d052 = dec_accum1;
  dec_accum1 = uVar3;
  dec_accum0 = dec_regW;
  dec_regW = uVar2;
  if (calc_state_b == '\n') {
    dec_g_Z_to_Y();
    dec_tail_round();
  }
  else {
    dec_set_Y_1e0();
  }
  dec_g_Y_to_X();
  if (dec_opcode < 3) {
    dec_int_convert();
    uVar2 = calc_state_g;
    uVar3 = calc_state_e;
    stat_calc_proc();
    calc_state_e = uVar3;
    calc_state_g = uVar2;
    dec_g_Z_to_Y();
    if (_DAT_ram_d02d != '\0') {
      dec_int_convert();
      dec_align_tmp = 0;
      _DAT_ram_d02b = 0;
      cVar1 = '\0';
      do {
        uVar7 = daa(cVar1 + '\x05');
        uVar4 = CONCAT12(uVar7,dec_accum0) & 0xfffff;
        cVar1 = (char)(uVar4 >> 0x10);
        bVar6 = daa((char)(uVar4 >> 8) + '\x05');
        dec_accum0 = CONCAT11(bVar6,(char)uVar4);
      } while ((char)((bVar6 < 0x10) << 7) < '\0');
      uVar5 = (ulonglong)CONCAT12(cVar1,dec_accum0) & 0xffffffffffff0fff;
      _DAT_ram_d02c = (undefined)(uVar5 >> 0x10);
      dec_accum0 = (undefined2)uVar5;
    }
  }
  return 0;
}

/**
 * @brief 舍入保留
 * @addr 0x1AE3E
 * @module bcd
 * @proto void dec_round_keep(void)
 * @confidence likely
 * @note 舍入保留：按 D02A/D02B 对齐位置与前导尾数加 1/舍入处理（1.1KB）。
 * @tag bcd
 */
int dec_round_keep(void)

{
  byte bVar1;
  undefined uVar2;
  byte bVar3;
  char cVar4;
  undefined uVar5;
  
  if (0xef < dec_flags) {
    return 0;
  }
  if (4 < (byte)(dec_accum0 >> 8)) {
    dec_align_tmp = dec_align_tmp - 1 & 0xf;
  }
  if ((_DAT_ram_d02b & 1) != 0) {
    dec_align_tmp = dec_align_tmp + 2 & 0xf;
  }
  if (1 < dec_opcode) {
    if (dec_opcode != 2) {
      bVar1 = dec_align_tmp & 1;
      goto joined_s0x01ae80;
    }
    _DAT_ram_d02c = 0;
    dec_align_tmp = dec_align_tmp + 1 & 0xf;
  }
  bVar1 = dec_align_tmp & 2;
joined_s0x01ae80:
  if (bVar1 != 0) {
    bVar1 = daa(_DAT_ram_d02c + 5);
    _DAT_ram_d02c = bVar1 & 0xf;
  }
  do {
    dec_align_tmp = dec_align_tmp + 1 & 0xf;
    bVar3 = (byte)((dec_accum0 & 0xfff) >> 8);
    bVar1 = (byte)(dec_accum0 & 0xfff);
    cVar4 = das(bVar3 - 5);
    dec_accum0 = CONCAT11(cVar4,bVar1);
  } while ((char)((bVar3 < 5) << 7) < '\0');
  uVar2 = das(bVar1 - 2);
  uVar5 = das(cVar4 - (bVar1 < 2));
  dec_accum0 = CONCAT11(uVar5,uVar2) & 0xfff;
  dec_ieee_norm();
  return 0;
}

/**
 * @brief 比较前规整
 * @addr 0x1AF5A
 * @module bcd
 * @proto void dec_prepare_compare(void)
 * @confidence strong
 * @note 比较前规整：X 为特殊值时直接返回；尾数 ≥ 0x10 时先规格化（0x1C30C 加法/DAA）再调用 0x1C670。供
 *       0x1A1D0/0x1A232/0x1AB54/0x1D7B0 等比较路径调用。
 * @tag bcd
 */
int dec_prepare_compare(void)

{
  uint6 extraout_var;
  
  if (0xef < dec_flags) {
    return 0;
  }
  if ((char)((dec_accum1 < (ushort)(CONCAT13(0x99,CONCAT12(0x91,dec_accum1)) >> 0x10)) << 7) <
      '\0') {
    if (0xf < dec_accum1) goto LAB_rom_01af9e;
  }
  else {
    decc_add8((byte)dec_accum1,(byte)(dec_accum1 >> 8),(byte)(dec_accum1 >> 0x10), (uintptr_t)0)
                   (byte)(dec_accum1 >> 0x18));
    dec_accum1 = (ulonglong)extraout_var << 0x10;
  }
  dec_accum1 = dec_accum1 & 0xffffffffffff0000;
LAB_rom_01af9e:
  dec_ieee_norm();
  return 0;
}

/**
 * @brief X 尾数高位 >4 时加 5 并按 DAA 修订（尾数规整）
 * @addr 0x1AFA4
 * @module bcd
 * @proto void dec_fix_mant_hi(void)
 * @confidence verified
 * @note X 尾数高位 >4 时加 5 并按 DAA 修订（尾数规整）。
 * @tag bcd
 */
int dec_fix_mant_hi(void)

{
  byte bVar1;
  undefined uVar2;
  
  bVar1 = (byte)(dec_accum0 >> 8);
  if (4 < bVar1) {
    uVar2 = daa(bVar1 + 5);
    dec_accum0 = CONCAT11(uVar2,(char)dec_accum0) & 0xfff;
  }
  return 0;
}

/**
 * @brief 交换 X 与 Y（0xD000↔0xD010，0xD002↔0xD012 共 10 字节）
 * @addr 0x1AFB8
 * @module bcd
 * @proto void dec_swap_XY(void)
 * @confidence verified
 * @note 交换 X 与 Y（0xD000↔0xD010，0xD002↔0xD012 共 10 字节）。
 * @tag bcd
 */
int dec_swap_XY(void)

{
  undefined2 uVar1;
  undefined8 uVar2;
  
  uVar2 = dec_regY_mant;
  uVar1 = dec_accum0;
  dec_regY_mant = dec_accum1;
  dec_accum1 = uVar2;
  dec_accum0 = dec_regY;
  dec_regY = uVar1;
  return 0;
}

/**
 * @brief 交换 X 与 Z（0xD000↔0xD032，0xD002↔0xD032，共 10 字节）
 * @addr 0x1AFDE
 * @module bcd
 * @proto void dec_swap_XZ(void)
 * @confidence verified
 * @note 交换 X 与 Z（0xD000↔0xD032，0xD002↔0xD032，共 10 字节）。
 * @tag bcd
 */
int dec_swap_XZ(void)

{
  undefined2 uVar1;
  undefined8 uVar2;
  
  uVar2 = calc_state_f;
  uVar1 = dec_accum0;
  calc_state_f = dec_accum1;
  dec_accum1 = uVar2;
  dec_accum0 = calc_state_e;
  calc_state_e = uVar1;
  return 0;
}

/**
 * @brief 交换 X 与 W（0xD000↔0xD050，0xD002↔0xD052 共 10 字节）
 * @addr 0x1B004
 * @module bcd
 * @proto void dec_swap_XW(void)
 * @confidence verified
 * @note 交换 X 与 W（0xD000↔0xD050，0xD002↔0xD052 共 10 字节）。
 * @tag bcd
 */
int dec_swap_XW(void)

{
  undefined2 uVar1;
  undefined8 uVar2;
  
  uVar2 = _DAT_ram_d052;
  uVar1 = dec_accum0;
  _DAT_ram_d052 = dec_accum1;
  dec_accum1 = uVar2;
  dec_accum0 = dec_regW;
  dec_regW = uVar1;
  return 0;
}

/**
 * @brief 交换 X 与 P（0xD000<->0xD020）
 * @addr 0x1B02A
 * @module bcd
 * @proto void dec_swap_xp(void)
 * @confidence verified
 * @note 交换 X 与 P（0xD000<->0xD020）。
 * @tag bcd
 */
int dec_swap_xp(void)

{
  undefined2 uVar1;
  undefined8 uVar2;
  
  uVar2 = dec_regP_mant;
  uVar1 = dec_accum0;
  dec_regP_mant = dec_accum1;
  dec_accum1 = uVar2;
  dec_accum0 = calc_state_c;
  calc_state_c = uVar1;
  return 0;
}

/**
 * @brief 交换 Y 与 Z（0xD010↔0xD030，0xD012↔0xD032 共 10 字节）
 * @addr 0x1B050
 * @module bcd
 * @proto void dec_swap_YZ(void)
 * @confidence verified
 * @note 交换 Y 与 Z（0xD010↔0xD030，0xD012↔0xD032 共 10 字节）。
 * @tag bcd
 */
int dec_swap_YZ(void)

{
  undefined8 uVar1;
  undefined2 uVar2;
  
  uVar2 = calc_state_e;
  uVar1 = dec_regY_mant;
  dec_regY_mant = calc_state_f;
  calc_state_f = uVar1;
  calc_state_e = dec_regY;
  dec_regY = uVar2;
  return 0;
}

/**
 * @brief 交换 Y 与 W（0xD010<->0xD050）的低字节
 * @addr 0x1B076
 * @module bcd
 * @proto void dec_swap_xy(void)
 * @confidence verified
 * @note 交换 Y 与 W（0xD010<->0xD050）的低字节。
 * @tag bcd
 */
int dec_swap_xy(void)

{
  undefined8 uVar1;
  undefined2 uVar2;
  
  uVar2 = dec_regW;
  uVar1 = dec_regY_mant;
  dec_regY_mant = _DAT_ram_d052;
  _DAT_ram_d052 = uVar1;
  dec_regW = dec_regY;
  dec_regY = uVar2;
  return 0;
}

/**
 * @brief 若尾数低半字节非 0，调用 0x1C30C 取整规整
 * @addr 0x1B342
 * @module bcd
 * @proto void dec_fix_integral(void)
 * @confidence likely
 * @note 若尾数低半字节非 0，调用 0x1C30C 取整规整。
 * @tag bcd
 */
int dec_fix_integral(void)

{
  undefined2 uVar1;
  ulonglong uVar2;
  undefined6 extraout_var;
  
  dec_carry_fix();
  uVar2 = dec_accum1 & 0xfffffffffffffff0;
  if ((dec_accum1 & 0xf) != 0) {
    uVar1 = decc_add8((byte)uVar2,(byte)(uVar2 >> 8),(byte)(uVar2 >> 0x10), (uintptr_t)0)
                           (byte)(uVar2 >> 0x18));
    uVar2 = CONCAT62(extraout_var,uVar1);
  }
  dec_accum1 = uVar2;
  dec_ieee_norm();
  return 0;
}

/**
 * @brief 若尾数低半字节 >4，调用 0x1C30C 调整
 * @addr 0x1B35A
 * @module bcd
 * @proto void dec_fix_frac(void)
 * @confidence likely
 * @note 若尾数低半字节 >4，调用 0x1C30C 调整。
 * @tag bcd
 */
int dec_fix_frac(void)

{
  undefined2 uVar1;
  ulonglong uVar2;
  undefined6 extraout_var;
  
  dec_carry_fix();
  uVar2 = dec_accum1 & 0xfffffffffffffff0;
  if (4 < ((byte)dec_accum1 & 0xf)) {
    uVar1 = decc_add8((byte)uVar2,(byte)(uVar2 >> 8),(byte)(uVar2 >> 0x10), (uintptr_t)0)
                           (byte)(uVar2 >> 0x18));
    uVar2 = CONCAT62(extraout_var,uVar1);
  }
  dec_accum1 = uVar2;
  dec_ieee_norm();
  return 0;
}

/**
 * @brief 清除尾数低字节后调用 0x1C670
 * @addr 0x1B388
 * @module bcd
 * @proto void dec_fix_zero_frac(void)
 * @confidence verified
 * @note 清除尾数低字节后调用 0x1C670。
 * @tag bcd
 */
int dec_fix_zero_frac(void)

{
  dec_carry_fix();
  dec_accum1 = dec_accum1 & 0xffffffffffffff00;
  dec_ieee_norm();
  return 0;
}

/**
 * @brief X 类型高位非 0 且非 0x20 时返回 1（特殊值判断）
 * @addr 0x1B3A0
 * @module bcd
 * @proto byte dec_is_special(void)
 * @confidence verified
 * @note X 类型高位非 0 且非 0x20 时返回 1（特殊值判断）。
 * @tag bcd
 */
byte dec_is_special(void)

{
  undefined uVar1;
  
  if (((dec_flags & 0xf0) == 0) || ((dec_flags & 0xf0) == 0x20)) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}

/**
 * @brief 返回 0xD019 > 9
 * @addr 0x1B3B6
 * @module bcd
 * @proto bool dec_is_nan_Y(void)
 * @confidence verified
 * @note 返回 0xD019 > 9：Y 的类型为 E/F（特殊值）。
 * @tag bcd
 */
bool dec_is_nan_Y(void)

{
  return 9 < dec_flags_Y;
}

/**
 * @brief 返回 0xD009 > 9
 * @addr 0x1B3BE
 * @module bcd
 * @proto bool dec_is_nan(void)
 * @confidence verified
 * @note 返回 0xD009 > 9：X 的类型为 E/F（错误、无穷等特殊值），十进制数学库拒绝继续运算。
 * @tag bcd
 */
bool dec_is_nan(void)

{
  return 9 < dec_flags;
}

/**
 * @brief 若 X 为特殊值返回 1
 * @addr 0x1B3D0
 * @module bcd
 * @proto bool dec_check_nan_X(void)
 * @confidence verified
 * @note 若 X 为特殊值返回 1；否则清除 X 标志位 0x40（内部结果标志）并返回
 *       0。所有二元/一元入口（0x1CA7E、0x1CE3E 等）第一步都调用它。
 * @tag bcd
 */
bool dec_check_nan_X(void)

{
  bool bVar1;
  
  bVar1 = 0xef < dec_flags;
  if (!bVar1) {
    dec_flags = dec_flags & 0xbf;
  }
  return bVar1;
}

/**
 * @brief 检查 X 与 Y
 * @addr 0x1B3E4
 * @module bcd
 * @proto ushort dec_check_nan_XY(void)
 * @confidence strong
 * @note 检查 X 与 Y：返回值为高字节携带状态（非 0 表示特殊值/错误），同时把 0xD009、0xD019 的 0x40
 *       位搬进 LI 位。
 * @tag bcd
 */
ushort dec_check_nan_XY(void)

{
  char cVar2;
  ushort uVar1;
  byte bVar3;
  
  cVar2 = '\0';
  if (dec_flags_Y < 0xf0) {
    uVar1 = CONCAT11(dec_flags_Y,dec_flags_Y) & 0x40bf;
    dec_flags_Y = (byte)uVar1;
    cVar2 = (char)(uVar1 >> 8);
    if (dec_flags < 0xf0) {
      bVar3 = dec_flags & 0x40;
      dec_flags = dec_flags & 0xbf;
      return (ushort)(byte)(cVar2 + bVar3) << 8;
    }
  }
  return CONCAT11(cVar2,1);
}

/**
 * @brief D009<0xF 时调用 0x1B44C
 * @addr 0x1B418
 * @module bcd
 * @proto void dec_entry_ok(void)
 * @confidence verified
 * @note D009<0xF 时调用 0x1B44C。
 * @tag bcd
 */
int dec_entry_ok(void)

{
  if (0xef < dec_flags) {
    return 0;
  }
  decc_sub_align();
  return 0;
}

