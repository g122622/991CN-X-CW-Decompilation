/*
 * 表达式求值 / 1a98a_decc_add_special.c
 * 地址范围: 0x1A98A - 0x1B09C
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 加减法的特殊值分支（decm_add 在 0xD01F>9 时进入）
 * @addr 0x1A98A
 * @module eval
 * @proto void decc_add_special(void)
 * @confidence strong
 * @note 加减法的特殊值分支（decm_add 在 0xD01F>9 时进入）：处理零/特殊值/无穷的组合。
 * @tag float
 */
int decc_add_special(void)

{
  ushort uVar1;
  byte bVar2;
  undefined uVar3;
  
  calc_state_a = 0;
  dec_g_X_to_Z();
  if (dec_opcode != 2) {
    dec_regY = 0x98;
    dec_regY_mant = 0;
    irq_pending_shadow = 0;
    display_dirty = 0;
    dec_regY_tail = 0x130;
    uVar1 = dec_tail_233(0x130);
    if ((char)uVar1 != '\0') {
      dec_g_X_to_Y_copy();
      dec_g_W_to_X();
      dec_g_X_to_Y_copy();
      if (dec_opcode == 3) {
        if (calc_state_b == '\v') {
          dec_set_y1();
          dec_regY_tail = CONCAT11(5,dec_regY_tail);
          dec_ieee_add();
        }
        else {
          dec_set_y1();
          dec_regY_tail = 0x750;
          dec_ieee_add();
        }
        dec_swap_XW();
        dec_set_y1();
        dec_regY_tail = CONCAT11(3,dec_regY_tail);
        if (calc_state_b != '\v') {
          dec_regY = CONCAT11(6,dec_regY);
        }
      }
      else {
        if (calc_state_b == '\v') {
          dec_set_y1();
          dec_regY_tail = 0x750;
          dec_regY = 0x98;
          dec_int_convert();
        }
        else {
          dec_set_Y_1e0_b();
          dec_regY_tail = CONCAT11(dec_flags_Y,0x20);
          dec_ieee_add();
        }
        dec_swap_XW();
        dec_set_y1();
        dec_regY_tail = CONCAT11(6,dec_regY_tail);
        if (calc_state_b == '\v') {
          dec_regY = CONCAT11(6,dec_regY);
        }
      }
      dec_ieee_add();
      dec_set_Y_1e0();
      dec_g_Y_to_X();
      dec_tail_round();
      dec_g_Z_to_Y();
      dec_int_convert();
      return 0;
    }
  }
  if (calc_state_b != '\n') {
    dec_set_y1();
    if (dec_opcode < 2) {
      calc_state_a = 5;
      while( true ) {
        uVar3 = (undefined)dec_accum0;
        bVar2 = daa((char)(dec_accum0 >> 8) + '\x05');
        dec_accum0 = CONCAT11(bVar2,uVar3);
        if (0xf < bVar2) break;
        bVar2 = daa(calc_state_a + 5);
        calc_state_a = bVar2 & 0xf;
      }
      dec_accum0 = CONCAT11(bVar2,uVar3) & 0xfff;
      dec_g_X_to_Z();
    }
    else if (dec_opcode != 2) {
      dec_round_add();
      dec_ieee_add();
      stat_calc_proc();
      goto LAB_rom_01ab20;
    }
    decc_add_special2();
    dec_tail_round();
LAB_rom_01ab20:
    decc_sub();
    return 0;
  }
  calc_state_a = 5;
  while( true ) {
    uVar3 = (undefined)dec_accum0;
    bVar2 = daa((char)(dec_accum0 >> 8) + '\x05');
    dec_accum0 = CONCAT11(bVar2,uVar3);
    if (0xf < bVar2) break;
    bVar2 = daa(calc_state_a + 5);
    calc_state_a = bVar2 & 0xf;
  }
  dec_accum0 = CONCAT11(bVar2,uVar3) & 0xfff;
  decc_exp_path();
  dec_set_Y_1e0_x();
  if (dec_opcode < 2) {
    uVar3 = daa((char)(dec_accum0 >> 8) + '\x05');
    dec_accum0 = CONCAT11(uVar3,(char)dec_accum0) & 0xfff;
  }
  else {
    if (dec_opcode != 2) {
      dec_g_Y_to_Z();
      dec_round_add();
      dec_swap_XY();
      goto LAB_rom_01aaee;
    }
    calc_state_a = 0;
  }
  dec_tail_round();
  dec_set_y1();
  dec_regY_tail = CONCAT11(2,dec_regY_tail);
LAB_rom_01aaee:
  dec_ieee_add();
  uVar3 = daa((char)(dec_accum0 >> 8) + calc_state_a);
  dec_accum0 = CONCAT11(uVar3,(char)dec_accum0) & 0xfff;
  return 0;
}

/**
 * @brief 特殊值加法的第二段（0x1A98A 的后续分支）
 * @addr 0x1AD12
 * @module eval
 * @proto void decc_add_special2(void)
 * @confidence likely
 * @note 特殊值加法的第二段（0x1A98A 的后续分支）。
 * @tag float
 */
int decc_add_special2(void)

{
  char cVar1;
  undefined8 uVar2;
  undefined2 uVar3;
  ushort uVar4;
  uint3 uVar5;
  undefined uVar8;
  undefined8 in_QR0;
  byte bVar7;
  ulonglong uVar6;
  
  if (0xef < dec_flags) {
    return 0;
  }
  uVar4 = dec_tail_233((ushort)CONCAT71((int7)((ulonglong)in_QR0 >> 8),dec_flags));
  if ((char)uVar4 == '\0') {
    dec_swap_XY();
    _DAT_ram_d02d = '\x05';
  }
  else {
    _DAT_ram_d02d = '\0';
  }
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
 * @brief 按 0xD02F（角度模式
 * @addr 0x1AEC2
 * @module eval
 * @proto void dec_load_like_gnu(void)
 * @confidence likely
 * @note 按 0xD02F（角度模式：<5 为弧度派生值、==5 为度）装载 "9" 或 π/180 的常量块到 X。供
 *       0x1AB54/0x1AC2C 的加减法做角度换算。
 * @tag float
 */
int dec_load_like_gnu(void)

{
  undefined uVar1;
  byte bVar2;
  
  if (angle_mode < 5) {
    uVar1 = 1;
    bVar2 = 9;
  }
  else {
    if (angle_mode == 5) {
      dec_regY = 0x796326794900100;
      dec_regY_tail = 0x157;
      return 0;
    }
    uVar1 = 2;
    bVar2 = 1;
  }
  dec_regY = (ulonglong)CONCAT11(1,uVar1);
  dec_regY_tail = (ushort)bVar2 << 8;
  return 0;
}

/**
 * @brief 按 0xD02F 装载 "1" 或 180/π 的换算系数到 Y（度模式）
 * @addr 0x1AF14
 * @module eval
 * @proto void dec_load_deg_factor(void)
 * @confidence likely
 * @note 按 0xD02F 装载 "1" 或 180/π 的换算系数到 Y（度模式）。
 * @tag float
 */
int dec_load_deg_factor(void)

{
  if (angle_mode < 5) {
    dec_set_Y_one();
  }
  else if (angle_mode == 5) {
    dec_regY = 0x6197723675790101;
    dec_regY_tail = 0x636;
  }
  else {
    dec_regY = 0x100;
    dec_regY_tail = 0x100;
  }
  return 0;
}

/**
 * @brief e^x 大指数分支
 * @addr 0x1B09C
 * @module eval
 * @proto void decc_exp_large(void)
 * @confidence likely
 * @note e^x 大指数分支：按 0xD01C 分段，调用 0x1B1BC。
 * @tag float
 */
int decc_exp_large(void)

{
  bool bVar1;
  ulonglong uVar2;
  ushort uVar3;
  ushort uVar4;
  undefined uVar6;
  uint3 uVar5;
  
  if (dec_flags < 0xf0) {
    if ((char)((dec_flags_Y < 0xf0) << 7) < '\0') {
      dec_g_W_to_X();
      dec_g_Y_to_Z();
      dec_stage = '\0';
      dec_temp_a = 0;
      while (uVar4 = dec_log_core(), (char)uVar4 != '\0') {
        dec_opcode = dec_opcode - 1 | 2;
        bVar1 = 0x7f < dec_temp_a;
        dec_temp_a = dec_temp_a + 0x80;
        if ((char)(bVar1 << 7) < '\0') {
          dec_g_Z4_to_X2();
          calc_state_e = (ushort)dec_regW;
          calc_state_f = (undefined6)((ulonglong)dec_regW >> 0x10);
          calc_state_g = (undefined)dec_regW_tail;
          _DAT_ram_d039 = (byte)((ushort)dec_regW_tail >> 8);
          goto LAB_rom_01b156;
        }
        dec_set_Y_1e0_x();
      }
      dec_stage = '\x01';
      dec_g_W_to_X();
      uVar3 = calc_state_e;
      uVar4 = dec_accum0;
      uVar2 = CONCAT17(_DAT_ram_d039,CONCAT16(calc_state_g,calc_state_f));
      calc_state_f = (undefined6)dec_accum1;
      calc_state_g = (undefined)(dec_accum1 >> 0x30);
      _DAT_ram_d039 = (byte)(dec_accum1 >> 0x38);
      dec_accum0 = calc_state_e;
      calc_state_e = uVar4;
      dec_accum1 = uVar2;
      if (4 < (byte)(uVar3 >> 8)) {
        uVar5 = CONCAT12(dec_accum8,uVar3) & 0x1ffff;
        if ((char)(uVar5 >> 0x10) == '\0') {
          if (dec_opcode != 0xf) goto LAB_rom_01b156;
        }
        else {
          calc_state_a = '\x05';
        }
        uVar6 = daa((char)(uVar5 >> 8) + '\x05');
        dec_accum0 = CONCAT11(uVar6,(char)uVar5) & 0xfff;
      }
LAB_rom_01b156:
      if ((((dec_accum1 & 0xf00000000000000) != 0) || (4 < (byte)(calc_state_e >> 8))) ||
         ((_DAT_ram_d039 & 0xf) == 0)) {
        uVar4 = dec_log_core();
        if (((char)uVar4 != '\0') || ((dec_stage == '\x01' && (dec_opcode < 0xf)))) {
          dec_stage = '\0';
        }
        dec_entry_ok();
        dec_regY = dec_regW;
        dec_regY_tail = dec_regW_tail;
        decc_mul_path();
      }
      uVar6 = daa((char)(dec_accum0 >> 8) + calc_state_a);
      dec_accum0 = CONCAT11(uVar6,(char)dec_accum0) & 0xfff;
      return 0;
    }
    dec_g_X_to_Y();
  }
  return 0;
}

