/*
 * BCD 浮点库 / 1b56c_dec_round_big.c
 * 地址范围: 0x1B56C - 0x1BD08
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 舍入大流程（8.7KB）
 * @addr 0x1B56C
 * @module bcd
 * @proto void dec_round_big(void)
 * @confidence likely
 * @note 舍入大流程（8.7KB）：按精度与阶段做长尾数循环舍入。
 * @tag bcd
 */
int dec_round_big(void)

{
  bool bVar1;
  short sVar2;
  ushort uVar3;
  byte bVar4;
  undefined2 uVar5;
  undefined2 uVar6;
  ushort uVar7;
  undefined uVar12;
  undefined2 uVar8;
  byte bVar13;
  uint5 uVar9;
  undefined uVar14;
  undefined uVar15;
  undefined uVar16;
  undefined6 extraout_var;
  undefined6 extraout_var_00;
  ulonglong uVar10;
  undefined6 extraout_var_01;
  undefined6 extraout_var_02;
  undefined6 extraout_var_03;
  undefined8 uVar11;
  undefined uVar17;
  char cVar19;
  uint uVar18;
  undefined uVar20;
  undefined6 extraout_var_04;
  
  if (0xef < dec_flags) {
    return 0;
  }
  _DAT_ram_d00d = 10;
  calc_state_c = 0x10;
  uVar7 = calc_state_c;
  calc_state_c = 0x10;
  dec_regP_mant = 0;
  calc_state_d = 0;
  dec_temp_a = 0;
  das(RAM8(0xd001) + -1);
  sVar2 = (ushort)(byte)dec_accum1 - (ushort)(RAM8(0xd001) == '\0');
  das((char)sVar2);
  sVar2 = (ushort)(byte)((uint6)dec_accum1 >> 8) - (ushort)((byte)((ushort)sVar2 >> 8) & 1);
  das((char)sVar2);
  sVar2 = (ushort)(byte)((uint6)dec_accum1 >> 0x10) - (ushort)((byte)((ushort)sVar2 >> 8) & 1);
  das((char)sVar2);
  sVar2 = (ushort)(byte)((uint6)dec_accum1 >> 0x18) - (ushort)((byte)((ushort)sVar2 >> 8) & 1);
  das((char)sVar2);
  sVar2 = ((ushort)((uint6)dec_accum1 >> 0x20) & 0xff) - (ushort)((byte)((ushort)sVar2 >> 8) & 1)
  ;
  das((char)sVar2);
  sVar2 = (ushort)(byte)((uint6)dec_accum1 >> 0x28) - (ushort)((byte)((ushort)sVar2 >> 8) & 1);
  das((char)sVar2);
  sVar2 = (ushort)dec_accum4 - (ushort)((byte)((ushort)sVar2 >> 8) & 1);
  das((char)sVar2);
  uVar3 = (ushort)dec_flags - (ushort)((byte)((ushort)sVar2 >> 8) & 1);
  das((char)uVar3);
  if ((uVar3 & 0x100) != 0) {
LAB_rom_01b690:
    calc_state_c = uVar7;
    dec_regY_mant = 0;
    dec_regY = 0;
    display_dirty = 0;
    irq_pending_shadow = 0;
    dec_regY_tail = 0;
    dec_flags_Y = 0x10;
    _DAT_ram_d00d = _DAT_ram_d00d + 8 & 0xf;
    while( true ) {
      decc_carry_out();
      if (_DAT_ram_d00d < 2) goto LAB_rom_01b704;
      if (_DAT_ram_d00d == 2) goto LAB_rom_01b71a;
      _DAT_ram_d00f = 0;
      while( true ) {
        uVar9 = CONCAT14((char)(calc_state_c >> 8),(uint)calc_state_c) & 0xfffffffff;
        cVar19 = (char)(uVar9 >> 0x20);
        if ((char)((cVar19 == '\0') << 7) < '\0') break;
        uVar10 = (ulonglong)
                 CONCAT32((int3)(((uint5)(byte)(cVar19 - 1) << 0x20) >> 0x10),(short)uVar9) &
                 0xfffffffffffff0ff;
        calc_state_c = CONCAT11((byte)(uVar10 >> 8) | (byte)(uVar10 >> 0x20),(char)uVar10);
        decc_X_add_Y();
        if (1 < _DAT_ram_d00f) {
          dec_accum7 = _DAT_ram_d00f - 2;
          decc_packZ();
          if (_DAT_ram_d00d == 2) {
            decc_Y_sub_Z();
LAB_rom_01b71a:
            calc_state_e = CONCAT62(dec_accum1,CONCAT11(RAM8(0xd001),dec_accum0));
            calc_state_g = CONCAT11(dec_flags,dec_accum4);
          }
          else {
            decc_Y_add_Z();
LAB_rom_01b704:
            calc_state_e =
                 CONCAT26(display_dirty,
                          CONCAT24(irq_pending_shadow,CONCAT22(dec_regY_mant,dec_regY)));
            calc_state_g = CONCAT11(dec_flags_Y,dec_regY_tail);
          }
        }
      }
      calc_state_c =
           CONCAT71((int7)(CONCAT62(dec_regP_mant,(short)uVar9) >> 8),(char)uVar9 + -1) &
           0xfffffffffffff0ff;
      if ((char)(((char)uVar9 == '\0') << 7) < '\0') break;
      uVar8 = decc_nop();
      dec_accum0 = daa((char)uVar8 + '\x01');
      RAM8(0xd001) = (char)((ushort)uVar8 >> 8);
      dec_accum1 = extraout_var_01;
      calc_state_c = decc_nop();
      dec_regP_mant = extraout_var_02;
    }
    if ((CONCAT17(dec_flags,CONCAT16(dec_accum4,dec_accum1)) != 0) || (RAM8(0xd001) != '\0')) {
      uVar11 = CONCAT62(dec_accum1,CONCAT11(RAM8(0xd001),dec_accum0));
      uVar18 = (uint)CONCAT12(dec_accum0,CONCAT11(dec_flags,dec_accum4));
      while( true ) {
        while( true ) {
          uVar9 = CONCAT14((char)(uVar18 >> 8),uVar18) & 0xf0ffffffff;
          uVar18 = (uint)(uint3)(uVar9 >> 0x10);
          if ((char)(uVar9 >> 0x20) == '\0') break;
          uVar8 = decc_nop();
          uVar11 = CONCAT62(extraout_var_04,uVar8);
          bVar13 = (byte)(uVar18 >> 0x10);
          uVar12 = daa(bVar13 + 1);
          uVar20 = daa((char)(uVar18 >> 0x18) + (0xfe < bVar13));
          uVar18 = CONCAT13(uVar20,CONCAT12(uVar12,(short)uVar18));
        }
        uVar9 = CONCAT14((char)(uVar9 >> 8),(int)uVar9) & 0xfffffffff;
        uVar18 = (uint)(uint3)(uVar9 >> 0x10);
        if ((char)(uVar9 >> 0x20) != '\0') break;
        uVar8 = decc_reload();
        uVar11 = CONCAT62(extraout_var_03,uVar8);
        cVar19 = (char)(uVar18 >> 0x10);
        uVar12 = das(cVar19 + -1);
        uVar20 = das((char)(uVar18 >> 0x18) - (cVar19 == '\0'));
        uVar18 = CONCAT13(uVar20,CONCAT12(uVar12,(short)uVar18));
      }
      bVar13 = (byte)((ulonglong)uVar11 >> 8);
      daa(bVar13 + 0x50);
      uVar3 = (ushort)(byte)((ulonglong)uVar11 >> 0x10) + (ushort)(0xaf < bVar13);
      uVar12 = daa((char)uVar3);
      uVar3 = (ushort)(byte)((ulonglong)uVar11 >> 0x18) + (uVar3 >> 8);
      uVar20 = daa((char)uVar3);
      uVar3 = (ushort)(byte)((ulonglong)uVar11 >> 0x20) + (uVar3 >> 8);
      uVar14 = daa((char)uVar3);
      uVar3 = (ushort)(byte)((ulonglong)uVar11 >> 0x28) + (uVar3 >> 8);
      uVar15 = daa((char)uVar3);
      uVar3 = ((ushort)((ulonglong)uVar11 >> 0x30) & 0xff) + (uVar3 >> 8);
      uVar16 = daa((char)uVar3);
      uVar3 = (ushort)(byte)((ulonglong)uVar11 >> 0x38) + (uVar3 >> 8);
      uVar17 = daa((char)uVar3);
      dec_accum1 =
           CONCAT15(uVar17,CONCAT14(uVar16,CONCAT13(uVar15,CONCAT12(uVar14,CONCAT11(uVar20,uVar12)))
                                   ));
      sVar2 = (ushort)(byte)uVar9 + (uVar3 >> 8);
      dec_accum4 = daa((char)sVar2);
      dec_flags = daa((char)(uVar9 >> 8) - ((char)((char)((ushort)sVar2 >> 8) << 7) >> 7));
      dec_accum0 = (char)(uVar9 >> 0x10);
      RAM8(0xd001) = (char)(uVar9 >> 0x18);
    }
    dec_ieee_norm();
    uVar6 = display_dirty;
    uVar5 = irq_pending_shadow;
    uVar8 = dec_regY_mant;
    bVar4 = dec_flags;
    bVar13 = dec_accum4;
    cVar19 = RAM8(0xd001);
    uVar12 = dec_accum0;
    dec_regY_mant = (undefined2)dec_accum1;
    irq_pending_shadow = (undefined2)((uint6)dec_accum1 >> 0x10);
    display_dirty = (undefined2)((uint6)dec_accum1 >> 0x20);
    if (_DAT_ram_d00d < 8) {
      if (_DAT_ram_d00d == 0) {
        dec_regY_mant = uVar8;
        irq_pending_shadow = uVar5;
        display_dirty = uVar6;
        return 0;
      }
      dec_accum1 = CONCAT24(uVar6,CONCAT22(uVar5,uVar8));
      dec_accum4 = dec_regY_tail;
      dec_flags = dec_flags_Y;
      dec_accum0 = 0x99;
      RAM8(0xd001) = 0;
    }
    else {
      if (_DAT_ram_d00d != 8) {
        dec_regY_mant = uVar8;
        irq_pending_shadow = uVar5;
        display_dirty = uVar6;
        return 0;
      }
      dec_accum4 = 0;
      dec_accum0 = 0;
      RAM8(0xd001) = 1;
      dec_accum1 = 0;
      dec_flags = dec_scale;
    }
    dec_regY_tail = bVar13;
    dec_regY = CONCAT11(cVar19,uVar12);
    dec_flags_Y = bVar4;
    dec_ieee_norm();
    return 0;
  }
LAB_rom_01b5c6:
  decc_carry_out();
  do {
    cVar19 = (_DAT_ram_d00d < 2) << 7;
    if (_DAT_ram_d00d < 2) {
      calc_state_e =
           CONCAT26(display_dirty,CONCAT24(irq_pending_shadow,CONCAT22(dec_regY_mant,dec_regY)));
      calc_state_g = CONCAT11(dec_flags_Y,dec_regY_tail);
    }
    else if (_DAT_ram_d00d == 2) {
      calc_state_e = CONCAT62(dec_accum1,CONCAT11(RAM8(0xd001),dec_accum0));
      calc_state_g = CONCAT11(dec_flags,dec_accum4);
    }
    else {
      _DAT_ram_d00f = 0;
    }
    do {
      decc_X_sub_Y();
      uVar8 = calc_state_g;
      uVar11 = calc_state_e;
      if (cVar19 < '\0') {
        decc_X_add_Y();
        uVar7 = calc_state_c;
        if (_DAT_ram_d029 != '\0') goto LAB_rom_01b690;
        uVar8 = decc_reload();
        dec_accum0 = (char)uVar8;
        RAM8(0xd001) = (char)((ushort)uVar8 >> 8);
        dec_accum1 = extraout_var;
        calc_state_c = decc_reload();
        bVar1 = dec_accum0 == '\0';
        dec_accum0 = das(dec_accum0 + -1);
        dec_regP_mant = extraout_var_00;
        if (bVar1) {
          dec_temp_a = 8;
        }
        goto LAB_rom_01b5c6;
      }
      uVar12 = daa((char)(calc_state_c >> 8) + '\x01');
      calc_state_c = CONCAT11(uVar12,(char)calc_state_c);
      cVar19 = (_DAT_ram_d00f < 2) << 7;
    } while (cVar19 < '\0');
    dec_accum7 = _DAT_ram_d00f - 2;
    decc_packZ();
    decc_Y_add_Z();
    calc_state_e = uVar11;
    calc_state_g = uVar8;
  } while( true );
}

/**
 * @brief 把 R0..R7 整体右移 4 位（SRLC 链），操作数比 0x1B86C 多一个字节
 * @addr 0x1B846
 * @module bcd
 * @proto ushort dec_shift_right4(byte r0, byte r1, byte r2)
 * @confidence verified
 * @note 把 R0..R7 整体右移 4 位（SRLC 链），操作数比 0x1B86C 多一个字节。
 * @tag bcd
 */
ushort dec_shift_right4(byte r0, byte r1, byte r2)

{
  return CONCAT11((char)((ushort)r2 * 0x100 + (ushort)r1 >> 4),
                  (char)((ushort)r1 * 0x100 + (ushort)r0 >> 4));
}

/**
 * @brief 把 R0..R7 整体左移 4 位（SLLC 链）
 * @addr 0x1B86C
 * @module bcd
 * @proto ushort dec_shift_left4(byte r0, byte r1)
 * @confidence verified
 * @note 把 R0..R7 整体左移 4 位（SLLC 链）：尾数规格化/指数调整时使用。
 * @tag bcd
 */
ushort dec_shift_left4(byte r0, byte r1)

{
  return CONCAT11((char)(((ushort)r1 * 0x100 + (ushort)r0) * 0x10 >> 8),r0 << 4);
}

/**
 * @brief 按 R0 的位数 1..10 设置 Y 的尾数常量
 * @addr 0x1B9D0
 * @module bcd
 * @proto void dec_set_y_prec(void)
 * @confidence likely
 * @note 按 R0 的位数 1..10 设置 Y 的尾数常量。
 * @tag bcd
 */
int dec_set_y_prec(void)

{
  byte bVar1;
  short sVar2;
  undefined8 in_QR0;
  
  bVar1 = (byte)((ulonglong)in_QR0 >> 0x10);
  if ((bVar1 == 0) || (10 < bVar1)) {
    bVar1 = 10;
  }
  sVar2 = (ushort)(byte)(bVar1 - 1) * 10;
  dec_regY = CONCAT71((int7)((ulonglong)*(undefined8 *)(sVar2 + 0x1c7a) >> 8),dec_regY);
  dec_regY_tail = *(undefined2 *)(sVar2 + 0x1c82);
  return 0;
}

/**
 * @brief 按 D00B 移位缩放 Y（0xD030 区，1.4KB）
 * @addr 0x1BA86
 * @module bcd
 * @proto void dec_scale_y(void)
 * @confidence likely
 * @note 按 D00B 移位缩放 Y（0xD030 区，1.4KB）。
 * @tag bcd
 */
int dec_scale_y(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  undefined8 uVar5;
  undefined2 uVar6;
  undefined2 uVar7;
  undefined7 *puVar8;
  undefined2 uVar9;
  ulonglong uVar10;
  undefined6 extraout_var;
  undefined2 uVar11;
  
  uVar7 = _DAT_ram_d04e;
  uVar6 = _DAT_ram_d04c;
  uVar5 = _DAT_ram_d044;
  uVar4 = _DAT_ram_d042;
  uVar3 = _DAT_ram_d040;
  uVar2 = _DAT_ram_d03e;
  uVar1 = _DAT_ram_d03c;
  if (dec_accum7 != 0) {
    if (0x12 < dec_accum7) {
      dec_accum7 = 0x12;
    }
    _DAT_ram_d044 = calc_state_e & 0xffffffffffffff00;
    _DAT_ram_d04c = calc_state_g;
    _DAT_ram_d03c = 0;
    _DAT_ram_d03e = 0;
    _DAT_ram_d040 = 0;
    _DAT_ram_d042 = 0;
    puVar8 = (undefined7 *)CONCAT11(-0x30 - (0x45 < dec_accum7 >> 1),'E' - (dec_accum7 >> 1));
    uVar11 = *(undefined2 *)((short)puVar8 + 7);
    uVar10 = CONCAT71(*puVar8,dec_accum7) & 0xffffffffffffff01;
    if ((dec_accum7 & 1) != 0) {
      uVar9 = decc_reload();
      uVar10 = CONCAT62(extraout_var,uVar9);
    }
    calc_state_e = uVar10 & 0xffffffffffffff00;
    calc_state_g = uVar11;
  }
  _DAT_ram_d04e = uVar7;
  _DAT_ram_d04c = uVar6;
  _DAT_ram_d044 = uVar5;
  _DAT_ram_d03c = uVar1;
  _DAT_ram_d03e = uVar2;
  _DAT_ram_d040 = uVar3;
  _DAT_ram_d042 = uVar4;
  return 0;
}

/**
 * @brief 按 D00B 缩放 X/Y（1.2KB）
 * @addr 0x1BB1E
 * @module bcd
 * @proto void dec_scale_xy(void)
 * @confidence likely
 * @note 按 D00B 缩放 X/Y（1.2KB）。
 * @tag bcd
 */
int dec_scale_xy(void)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  undefined7 *puVar5;
  undefined2 uVar6;
  ulonglong uVar7;
  undefined6 extraout_var;
  undefined2 uVar8;
  
  uVar4 = _DAT_ram_d04e;
  uVar3 = _DAT_ram_d04c;
  uVar2 = _DAT_ram_d044;
  uVar1 = _DAT_ram_d03c;
  if (dec_accum7 != 0) {
    if (0x12 < dec_accum7) {
      dec_accum7 = 0x12;
    }
    _DAT_ram_d03c = CONCAT17((char)dec_regY_tail,(int7)((ulonglong)dec_regY >> 8));
    _DAT_ram_d044 = (ulonglong)(byte)((ushort)dec_regY_tail >> 8);
    _DAT_ram_d04c = 0;
    puVar5 = (undefined7 *)
             CONCAT11(-0x30 - ((char)((0xc3 < dec_accum7 >> 1) << 7) >> 7),
                      (dec_accum7 >> 1) + 0x3c);
    uVar8 = *(undefined2 *)((short)puVar5 + 7);
    uVar7 = CONCAT71(*puVar5,dec_accum7) & 0xffffffffffffff01;
    if ((dec_accum7 & 1) != 0) {
      uVar6 = decc_nop();
      uVar7 = CONCAT62(extraout_var,uVar6);
    }
    dec_regY = CONCAT71((int7)(uVar7 >> 8),dec_regY);
    dec_regY_tail = uVar8;
  }
  _DAT_ram_d04e = uVar4;
  _DAT_ram_d04c = uVar3;
  _DAT_ram_d044 = uVar2;
  _DAT_ram_d03c = uVar1;
  return 0;
}

/**
 * @brief 取绝对值核心（2.2KB，0x195EA/0x19980/0x1D8F0 调用）
 * @addr 0x1BBA8
 * @module bcd
 * @proto void dec_abs_core(void)
 * @confidence likely
 * @note 取绝对值核心（2.2KB，0x195EA/0x19980/0x1D8F0 调用）。
 * @tag bcd
 */
int dec_abs_core(void)

{
  short sVar1;
  ushort uVar2;
  byte bVar3;
  undefined uVar4;
  undefined uVar5;
  undefined uVar6;
  undefined uVar7;
  byte bVar8;
  byte bVar9;
  undefined uVar10;
  undefined uVar11;
  char cVar12;
  
  dec_tmp_flag = '\x01';
  if (0xef < dec_flags) {
    return 0;
  }
  bVar3 = (byte)(dec_accum0 >> 8);
  if ((char)((bVar3 < 4) << 7) < '\0') {
    bVar8 = 1;
  }
  else {
    bVar8 = 6;
  }
  bVar9 = (byte)dec_accum0;
  uVar10 = das(bVar9 - 0x13);
  uVar2 = ((ushort)bVar3 - (ushort)bVar8) - (ushort)(bVar9 < 0x13);
  uVar11 = das((char)uVar2);
  if ((uVar2 & 0x100) == 0) {
    if (CONCAT11(uVar11,uVar10) != 0) {
      dec_regY_mant = 0xc0;
      goto LAB_rom_01bc28;
    }
  }
  else {
    dec_accum7 = das('\x13' - bVar9);
    cVar12 = das((bVar8 - bVar3) - (0x13 < bVar9));
    if ((cVar12 != '\0') || (0x16 < dec_accum7)) {
      dec_accum7 = 0x16;
    }
    if (9 < dec_accum7) {
      dec_accum7 = dec_accum7 - 6;
    }
    dec_carry_fix();
  }
  if ((dec_tmp_flag == '\0') && (bVar3 = (byte)(dec_accum0 >> 0x10), 4 < (bVar3 & 0xf))) {
    uVar10 = daa(bVar3 + 0x10);
    uVar2 = (ushort)(byte)(dec_accum0 >> 0x18) + (ushort)(0xef < bVar3);
    uVar11 = daa((char)uVar2);
    uVar2 = (ushort)(byte)(dec_accum0 >> 0x20) + (uVar2 >> 8);
    uVar4 = daa((char)uVar2);
    uVar2 = (ushort)(byte)(dec_accum0 >> 0x28) + (uVar2 >> 8);
    uVar5 = daa((char)uVar2);
    uVar2 = ((ushort)(dec_accum0 >> 0x30) & 0xff) + (uVar2 >> 8);
    uVar6 = daa((char)uVar2);
    uVar2 = (ushort)(byte)(dec_accum0 >> 0x38) + (uVar2 >> 8);
    uVar7 = daa((char)uVar2);
    dec_accum0 =
         CONCAT17(uVar7,CONCAT16(uVar6,CONCAT15(uVar5,CONCAT14(uVar4,CONCAT13(uVar11,CONCAT12(uVar10
                                                  ,(short)dec_accum0))))));
    sVar1 = (dec_accum4 & 0xff) + (uVar2 >> 8);
    uVar10 = daa((char)sVar1);
    uVar11 = daa((char)(dec_accum4 >> 8) - ((char)((char)((ushort)sVar1 >> 8) << 7) >> 7));
    dec_accum4 = CONCAT11(uVar11,uVar10);
  }
  dec_accum0 = dec_accum0 & 0xfffffffffff0ffff;
  dec_regY_mant = (undefined2)(dec_accum0 >> 0x10);
LAB_rom_01bc28:
  dec_ieee_norm();
  return 0;
}

/**
 * @brief 取负核心（2.2KB，0x1AB54/0x1B1BC/0x1B1CA 调用）
 * @addr 0x1BBB2
 * @module bcd
 * @proto void dec_neg_core(void)
 * @confidence likely
 * @note 取负核心（2.2KB，0x1AB54/0x1B1BC/0x1B1CA 调用）。
 * @tag bcd
 */
int dec_neg_core(void)

{
  short sVar1;
  ushort uVar2;
  byte bVar3;
  undefined uVar4;
  undefined uVar5;
  undefined uVar6;
  undefined uVar7;
  byte bVar8;
  byte bVar9;
  undefined uVar10;
  undefined uVar11;
  char cVar12;
  
  dec_tmp_flag = '\0';
  if (0xef < dec_flags) {
    return 0;
  }
  bVar3 = (byte)(dec_accum0 >> 8);
  if ((char)((bVar3 < 4) << 7) < '\0') {
    bVar8 = 1;
  }
  else {
    bVar8 = 6;
  }
  bVar9 = (byte)dec_accum0;
  uVar10 = das(bVar9 - 0x13);
  uVar2 = ((ushort)bVar3 - (ushort)bVar8) - (ushort)(bVar9 < 0x13);
  uVar11 = das((char)uVar2);
  if ((uVar2 & 0x100) == 0) {
    if (CONCAT11(uVar11,uVar10) != 0) {
      dec_regY_mant = 0xc0;
      goto LAB_rom_01bc28;
    }
  }
  else {
    dec_accum7 = das('\x13' - bVar9);
    cVar12 = das((bVar8 - bVar3) - (0x13 < bVar9));
    if ((cVar12 != '\0') || (0x16 < dec_accum7)) {
      dec_accum7 = 0x16;
    }
    if (9 < dec_accum7) {
      dec_accum7 = dec_accum7 - 6;
    }
    dec_carry_fix();
  }
  if ((dec_tmp_flag == '\0') && (bVar3 = (byte)(dec_accum0 >> 0x10), 4 < (bVar3 & 0xf))) {
    uVar10 = daa(bVar3 + 0x10);
    uVar2 = (ushort)(byte)(dec_accum0 >> 0x18) + (ushort)(0xef < bVar3);
    uVar11 = daa((char)uVar2);
    uVar2 = (ushort)(byte)(dec_accum0 >> 0x20) + (uVar2 >> 8);
    uVar4 = daa((char)uVar2);
    uVar2 = (ushort)(byte)(dec_accum0 >> 0x28) + (uVar2 >> 8);
    uVar5 = daa((char)uVar2);
    uVar2 = ((ushort)(dec_accum0 >> 0x30) & 0xff) + (uVar2 >> 8);
    uVar6 = daa((char)uVar2);
    uVar2 = (ushort)(byte)(dec_accum0 >> 0x38) + (uVar2 >> 8);
    uVar7 = daa((char)uVar2);
    dec_accum0 =
         CONCAT17(uVar7,CONCAT16(uVar6,CONCAT15(uVar5,CONCAT14(uVar4,CONCAT13(uVar11,CONCAT12(uVar10
                                                  ,(short)dec_accum0))))));
    sVar1 = (dec_accum4 & 0xff) + (uVar2 >> 8);
    uVar10 = daa((char)sVar1);
    uVar11 = daa((char)(dec_accum4 >> 8) - ((char)((char)((ushort)sVar1 >> 8) << 7) >> 7));
    dec_accum4 = CONCAT11(uVar11,uVar10);
  }
  dec_accum0 = dec_accum0 & 0xfffffffffff0ffff;
  dec_regY_mant = (undefined2)(dec_accum0 >> 0x10);
LAB_rom_01bc28:
  dec_ieee_norm();
  return 0;
}

/**
 * @brief 末位超过 4 时的进位修正（1.3KB）
 * @addr 0x1BC64
 * @module bcd
 * @proto void dec_carry_fix(void)
 * @confidence likely
 * @note 末位超过 4 时的进位修正（1.3KB）。
 * @tag bcd
 */
int dec_carry_fix(void)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  undefined uVar5;
  undefined2 uVar6;
  undefined uVar8;
  byte bVar9;
  undefined6 extraout_var;
  undefined8 uVar7;
  
  uVar4 = _DAT_ram_d04e;
  uVar3 = _DAT_ram_d04c;
  uVar2 = _DAT_ram_d044;
  uVar1 = _DAT_ram_d03c;
  if (dec_accum7 != 0) {
    if (0x10 < dec_accum7) {
      dec_accum7 = 0x10;
    }
    _DAT_ram_d03c = dec_accum1;
    _DAT_ram_d044 = 0;
    uVar7 = *(undefined8 *)
             CONCAT11(-0x30 - ((char)((0xc3 < dec_accum7 >> 1) << 7) >> 7),
                      (dec_accum7 >> 1) + 0x3c);
    if ((dec_accum7 & 1) != 0) {
      uVar6 = dec_shift_right4((byte)uVar7,(byte)((ulonglong)uVar7 >> 8), (uintptr_t)0)
                             (byte)((ulonglong)uVar7 >> 0x10));
      uVar7 = CONCAT62(extraout_var,uVar6);
    }
    bVar9 = dec_accum7;
    if (9 < dec_accum7) {
      bVar9 = dec_accum7 + 6;
    }
    uVar5 = daa((byte)dec_accum0 + bVar9);
    uVar8 = daa((char)((ushort)dec_accum0 >> 8) -
                ((char)(CARRY1((byte)dec_accum0,bVar9) << 7) >> 7));
    dec_accum0 = CONCAT11(uVar8,uVar5);
    dec_accum1 = uVar7;
  }
  _DAT_ram_d04e = uVar4;
  _DAT_ram_d04c = uVar3;
  _DAT_ram_d044 = uVar2;
  _DAT_ram_d03c = uVar1;
  return 0;
}

/**
 * @brief ln 计算核心（3.9KB，0x19B28 的 x·ln x 路径）
 * @addr 0x1BD08
 * @module bcd
 * @proto int dec_ln_core(void)
 * @confidence likely
 * @note ln 计算核心（3.9KB，0x19B28 的 x·ln x 路径）。
 * @tag bcd
 */
int dec_ln_core(void)

{
  bool bVar1;
  short sVar2;
  ushort uVar3;
  char cVar4;
  undefined2 uVar5;
  byte extraout_R1;
  byte extraout_R1_00;
  byte bVar7;
  byte bVar8;
  undefined uVar9;
  byte bVar10;
  undefined uVar11;
  byte bVar12;
  undefined uVar13;
  undefined uVar14;
  undefined8 in_QR0;
  undefined8 uVar6;
  ushort uVar15;
  undefined uVar17;
  byte bVar18;
  byte bVar19;
  char cVar20;
  byte bVar21;
  byte bVar22;
  byte bVar16;
  
  uVar6 = CONCAT71((int7)((ulonglong)in_QR0 >> 8),dec_flags);
  if (0xef < dec_flags) {
    return (short)uVar6;
  }
  cVar20 = '\x10';
  dec_accum8 = 0;
  if ((char)(((byte)(dec_accum0 >> 8) < 4) << 7) < '\0') {
    bVar19 = 1;
  }
  else {
    bVar19 = 6;
  }
  do {
    bVar1 = cVar20 == '\0';
    cVar20 = cVar20 + -1;
    bVar7 = (byte)(dec_accum0 >> 0x10);
    bVar8 = (byte)(dec_accum0 >> 0x18);
    bVar18 = (byte)(dec_accum4 >> 8);
    bVar10 = (byte)(dec_accum0 >> 0x20);
    bVar12 = (byte)(dec_accum0 >> 0x28);
    bVar16 = (byte)(dec_accum0 >> 0x38);
    uVar15 = (ushort)(dec_accum0 >> 0x30);
    if ((char)(bVar1 << 7) < '\0') {
LAB_rom_01bd50:
      uVar5 = (undefined2)dec_accum0;
      if (4 < bVar7 >> 4) {
        uVar9 = daa(bVar8 + 1);
        uVar3 = (ushort)bVar10 + (ushort)(0xfe < bVar8);
        uVar11 = daa((char)uVar3);
        uVar3 = (ushort)bVar12 + (uVar3 >> 8);
        uVar13 = daa((char)uVar3);
        uVar15 = (uVar15 & 0xff) + (uVar3 >> 8);
        uVar14 = daa((char)uVar15);
        uVar15 = (ushort)bVar16 + (uVar15 >> 8);
        uVar17 = daa((char)uVar15);
        dec_accum0 =
             (ulonglong)CONCAT14(uVar17,CONCAT13(uVar14,CONCAT12(uVar13,CONCAT11(uVar11,uVar9)))) <<
             0x18;
        sVar2 = (dec_accum4 & 0xff) + (uVar15 >> 8);
        uVar9 = daa((char)sVar2);
        uVar11 = daa(bVar18 - ((char)((char)((ushort)sVar2 >> 8) << 7) >> 7));
        dec_accum4 = CONCAT11(uVar11,uVar9);
      }
      dec_accum0 =
           CONCAT26((short)(dec_accum0 >> 0x30),
                    CONCAT24((short)(dec_accum0 >> 0x20),
                             CONCAT22((short)(dec_accum0 >> 0x10),uVar5))) & 0xffffffffff00ffff;
      dec_ieee_norm();
      return (ushort)extraout_R1 << 8;
    }
    bVar21 = (byte)dec_accum0;
    bVar22 = (byte)(dec_accum0 >> 8);
    das(bVar21 - 0x12);
    uVar3 = ((ushort)bVar22 - (ushort)bVar19) - (ushort)(bVar21 < 0x12);
    cVar4 = (char)uVar3;
    das(cVar4);
    if ((uVar3 & 0x100) == 0) {
      if (((byte)(bVar21 - 0x12) != '\0' || cVar4 != '\0') || (bVar7 != 0)) {
LAB_rom_01bdb2:
        dec_ieee_norm();
        return (short)CONCAT71((uint7)extraout_R1_00,1);
      }
      dec_accum8 = bVar8 & 0xf;
      goto LAB_rom_01bd50;
    }
    if (bVar7 != 0) goto LAB_rom_01bdb2;
    sVar2 = dec_accum4 * 0x100;
    dec_accum4 =
         CONCAT11(bVar18 >> 4,(char)((ushort)bVar18 * 0x100 + (dec_accum4 & 0xff) >> 4));
    uVar9 = daa(bVar21 + 1);
    uVar11 = daa(bVar22 - ((char)((0xfe < bVar21) << 7) >> 7));
    dec_accum0 =
         CONCAT62(CONCAT15((char)(sVar2 + (ushort)bVar16 >> 4),
                           CONCAT14((char)((ushort)bVar16 * 0x100 + (uVar15 & 0xff) >> 4),
                                    CONCAT13((char)((ushort)(byte)(dec_accum0 >> 0x30) * 0x100 +
                                                    (ushort)bVar12 >> 4),
                                             CONCAT12((char)((ushort)bVar12 * 0x100 + (ushort)bVar10
                                                            >> 4),
                                                      CONCAT11((char)((ushort)bVar10 * 0x100 +
                                                                      (ushort)bVar8 >> 4),
                                                               bVar8 * '\x10'))))),
                  CONCAT11(uVar11,uVar9)) & 0xffffffffffff0fff;
  } while( true );
}

