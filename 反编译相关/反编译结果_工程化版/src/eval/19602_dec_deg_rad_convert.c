/*
 * 表达式求值 / 19602_dec_deg_rad_convert.c
 * 地址范围: 0x19602 - 0x19DD6
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 角度换算
 * @addr 0x19602
 * @module eval
 * @proto void dec_deg_rad_convert(void)
 * @confidence strong
 * @note 角度换算：按 0xD02F 的角度模式（弧度/度/ град）换算 X 与 Y；度模式直接装载 π 常量后归一化。
 * @tag float
 */
int dec_deg_rad_convert(void)

{
  undefined uVar1;
  
  if (((0xef < dec_flags) || (0xef < dec_flags_Y)) ||
     ((dec_flags == 0 && (dec_flags_Y == 0)))) {
    dec_zero_helper();
    return 0;
  }
  dec_g_X_to_Z();
  dec_g_X_to_W();
  if (angle_mode < 5) {
    dec_accum4 = 0x180;
  }
  else {
    if (angle_mode == 5) {
      dec_const_pi();
      goto LAB_rom_01965e;
    }
    dec_accum4 = 0x200;
  }
  dec_accum0 = 0x102;
LAB_rom_01965e:
  dec_g_X_to_Z4();
  dec_g_X_to_W2();
  if (_DAT_ram_d059 == '\0') {
    if ((char)(((byte)((ushort)calc_state_e >> 8) < 5) << 7) < '\0') {
      dec_accum0 = 0;
      dec_accum4 = 0;
    }
    else {
      dec_g_Z4_to_X();
    }
  }
  else {
    dec_accum0 = 0x100;
    dec_accum4 = 0x200;
    dec_g_Z4_to_Y();
    dec_fixup_types();
    dec_g_X_to_Z4();
    if (_DAT_ram_d039 != '\0') {
      dec_g_W_to_Y();
      dec_g_Z_to_Y();
      dec_ieee_add();
      if ((char)((dec_flags < 0xf0) << 7) < '\0') {
        _DAT_ram_d03c = CONCAT62(calc_state_f,calc_state_e);
        _DAT_ram_d044 = calc_state_g;
        dec_opcode = 0x903;
        decc_rounded_add();
        if ((byte)((ulonglong)_DAT_ram_d03c >> 8) < 5) {
          return 0;
        }
        dec_g_Q_to_Y();
        if (4 < (byte)((ushort)dec_regW >> 8)) {
          uVar1 = daa((char)(dec_regY >> 8) + '\x05');
          dec_regY = CONCAT11(uVar1,(char)dec_regY) & 0xfff;
        }
        dec_tail_round();
        return 0;
      }
      dec_g_Z4_to_X();
    }
    if (4 < (byte)((ushort)dec_regW >> 8)) {
      uVar1 = daa((char)(dec_accum0 >> 8) + '\x05');
      dec_accum0 =
           CONCAT62(dec_accum1,CONCAT11(uVar1,(char)dec_accum0)) & 0xffffffffffff0fff;
    }
  }
  return 0;
}

/**
 * @brief X ← ln(10) = 2.3025850929940456840
 * @addr 0x1972C
 * @module eval
 * @proto void dec_const_ln10(void)
 * @confidence verified
 * @note X ← ln(10) = 2.3025850929940456840。XREF：仅 0x01DA24（1DA02
 *       尾部的锁存函数）。
 * @tag float
 */
int dec_const_ln10(void)

{
  dec_accum0 = 0x8281828459040100;
  dec_accum4 = 0x271;
  return 0;
}

/**
 * @brief X ← π = 3.141592653589793238（0xD000=0x15926535…
 * @addr 0x1974A
 * @module eval
 * @proto void dec_const_pi(void)
 * @confidence verified
 * @note X ← π = 3.141592653589793238（0xD000=0x1592653589800100，指数
 *       0x0314）。XREF：0x1965A、0x1CC34、0x1DA3A（三角函数/对数的角度换算）。
 * @tag float
 */
int dec_const_pi(void)

{
  dec_accum0 = 0x1592653589800100;
  dec_accum4 = 0x314;
  return 0;
}

/**
 * @brief 乘方核心共用尾巴
 * @addr 0x197E0
 * @module eval
 * @proto void decc_pow_split(void)
 * @confidence likely
 * @note 乘方核心共用尾巴：0xD01F=9、0xD01C=0，把 A 拆成整数部分与小数部分，相似数消去后调用 0x1B558。
 * @tag float
 */
int decc_pow_split(void)

{
  byte bVar1;
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  undefined2 uVar5;
  undefined uVar8;
  undefined6 uVar7;
  undefined6 extraout_var;
  ulonglong uVar6;
  char cVar10;
  char cVar11;
  undefined uVar12;
  char cVar13;
  byte bVar14;
  byte bVar9;
  
  bVar1 = dec_flags;
  if (9 < dec_flags) {
    dec_zero_helper();
    return 0;
  }
  dec_opcode = 6;
  calc_state_b = 9;
  dec_stage = 0;
  dec_regP_mant = dec_accum1;
  calc_state_d = (ushort)(CONCAT17(dec_flags,CONCAT16(dec_accum4,dec_accum1)) >> 0x30);
  uVar2 = calc_state_d;
  uVar6 = (ulonglong)CONCAT14(5,(uint)dec_accum0);
  do {
    uVar6 = uVar6 & 0xffffffffffff0fff;
    uVar8 = das((char)(uVar6 >> 0x18) - (char)(uVar6 >> 0x20));
    uVar6 = CONCAT44((int)(uVar6 >> 0x20),CONCAT13(uVar8,(int3)uVar6)) & 0xffffffff0fffffff;
    bVar14 = (byte)(uVar6 >> 8);
    bVar9 = (byte)(uVar6 >> 0x20);
    uVar7 = (undefined6)(uVar6 >> 0x10);
    uVar8 = das(bVar14 - bVar9);
    uVar5 = CONCAT11(uVar8,(char)uVar6);
    uVar6 = CONCAT62(uVar7,uVar5);
  } while ((char)((bVar14 < bVar9) << 7) < '\0');
  uVar6 = CONCAT62(uVar7,uVar5) & 0xffffffffffff0fff;
  uVar4 = (ushort)uVar6;
  dec_scale = (undefined2)(uVar6 >> 0x10);
  dec_accum0 = uVar4;
  uVar3 = calc_state_c & 0xff;
  if ((dec_flags & 0xf) != 0) {
    cVar13 = '\x03';
    uVar6 = CONCAT62(dec_accum1,calc_state_c) & 0xffffffffffff00ff;
    dec_scale = 0;
    bVar14 = dec_scale;
    calc_state_c = calc_state_c & 0xff;
    while( true ) {
      cVar11 = (char)(uVar4 >> 8);
      cVar10 = (char)uVar4;
      if (cVar11 == '\0') break;
      cVar13 = cVar13 + -1;
      if (cVar13 == '\0') {
        bVar14 = bVar14 & 0xf | 0xe0;
        break;
      }
      uVar5 = decc_reload();
      uVar6 = CONCAT62(extraout_var,uVar5);
      uVar8 = das(cVar10 + -1);
      uVar12 = das(cVar11 - (cVar10 == '\0'));
      uVar4 = CONCAT11(uVar12,uVar8) & 0xfff;
      bVar14 = bVar1;
    }
    dec_scale = CONCAT11(DAT_ram_d01a_1,bVar14);
    uVar6 = CONCAT71((int7)(uVar6 >> 8),cVar10) & 0xfffffffffffff0ff;
    dec_accum0 = (ushort)uVar6;
    dec_accum1 = (undefined6)(uVar6 >> 0x10);
    dec_accum4 = (undefined)(uVar2 & 0xfff);
    dec_flags = (byte)((uVar2 & 0xfff) >> 8);
    uVar3 = calc_state_c;
  }
  calc_state_c = uVar3;
  decc_unpack();
  return 0;
}

/**
 * @brief 取负
 * @addr 0x19890
 * @module eval
 * @proto void decc_zero_neg(void)
 * @confidence strong
 * @note 取负：X←Z，以 0 减去 X（0xD01D=0，0x1B43A 对齐加法）后写回。
 * @tag float
 */
int decc_zero_neg(void)

{
  undefined uVar1;
  char cVar3;
  undefined2 uVar2;
  
  cVar3 = (char)(dec_accum0 >> 8);
  if (cVar3 == '\0') {
    dec_scale = 0;
    dec_regY_mant = 0;
    dec_regY = 0;
    display_dirty = 0;
    irq_pending_shadow = 0;
    dec_regY_tail = 0x100;
  }
  else {
    if (cVar3 != '\x05') {
      dec_zero_helper();
      return 0;
    }
    dec_g_X_to_Z();
    dec_set_Y_9e0();
    dec_regY = CONCAT11(5,dec_regY);
    dec_tmp_flag = 0;
    uVar2 = dec_special_check();
    dec_g_Z4_to_X2();
    if ((char)uVar2 == '\x02') {
      dec_set_Y_1e0();
      calc_state_a = 0;
      decc_add_align();
      return 0;
    }
    dec_g_X_to_Z();
    dec_set_Y_1e0();
    dec_g_X_to_Z2();
    dec_accum4 = calc_state_g;
    dec_scale = 0x500;
    uVar1 = daa((char)calc_state_e + '\x01');
    dec_accum0 = CONCAT71((int7)((ulonglong)calc_state_e >> 8),uVar1) & 0xffffffffffff00ff;
  }
  calc_state_a = 0;
  dec_stage = 3;
  decc_pack();
  dec_tail_round();
  uVar1 = daa((char)(dec_accum0 >> 8) + (char)((ushort)dec_scale >> 8));
  dec_accum0 = CONCAT62(dec_accum1,CONCAT11(uVar1,(char)dec_accum0)) & 0xffffffffffff0fff;
  return 0;
}

/**
 * @brief 空操作占位
 * @addr 0x19958
 * @module eval
 * @proto void decc_dummy(void)
 * @confidence likely
 * @note 空操作占位：依次做 X→W、X→Y（不动数值），被 0x1C95E 的 10^x 分支调用。
 * @tag float
 */
int decc_dummy(void)

{
  dec_g_X_to_W();
  calc_state_a = 0;
  decc_add_align();
  dec_swap_XW();
  calc_state_a = 0;
  decc_add_align();
  dec_g_Y_to_X();
  dec_ieee_add();
  return 0;
}

/**
 * @brief 把 Y（0xD010）载入运算暂存并做 DAA 进位整理，供乘法/除法核心使用
 * @addr 0x19A56
 * @module eval
 * @proto void decc_load_Y(void)
 * @confidence strong
 * @note 把 Y（0xD010）载入运算暂存并做 DAA 进位整理，供乘法/除法核心使用。
 * @tag float
 */
int decc_load_Y(void)

{
  dec_g_W_to_X();
  dec_g_X_to_Y();
  decc_int_entry();
  dec_swap_XW();
  decc_int_entry();
  dec_g_Y_to_X();
  return 0;
}

/**
 * @brief log/exp 小数分支的公共处理（0x1B09C 调用）
 * @addr 0x19A72
 * @module eval
 * @proto void decc_log_path(void)
 * @confidence likely
 * @note log/exp 小数分支的公共处理（0x1B09C 调用）。
 * @tag float
 */
int decc_log_path(void)

{
  byte bVar1;
  undefined2 uVar2;
  ushort uVar3;
  int sVar4;
  
  calc_state_b = 0xc;
  dec_g_X_to_Z();
  dec_g_X_to_W();
  dec_set_y1();
  dec_regY = 0x10;
  dec_tmp_flag = 0;
  uVar2 = dec_special_check();
  if ((char)uVar2 == '\x02') {
    dec_g_W_to_Y();
    dec_set_y1();
    dec_regY = 0x10;
    uVar2 = dec_special_check();
    if ((char)uVar2 == '\x02') {
      dec_g_Z4_to_X2();
      dec_g_Y_to_X();
      if ((dec_flags_Y == '\0') || (dec_regY_1 == '\x01')) {
        calc_state_c = dec_accum0;
        calc_state_d = dec_accum4;
        dec_g_X_to_W();
        decc_carry_round();
        if (dec_opcode == '\b') {
          dec_regY_mant = 0;
          dec_regY = 0;
          dec_regY_1 = '\0';
          display_dirty = 0;
          irq_pending_shadow = 0;
          dec_regY_tail = 0;
          dec_flags_Y = '\0';
          dec_g_X_to_W();
        }
        else {
          uVar3 = dec_g_Y_to_X();
          uVar3 = dec_tail_233(uVar3);
          if ((char)uVar3 != '\0') {
            dec_swap_XW();
          }
        }
        dec_swap_XZ();
        dec_accum0 = calc_state_c;
        dec_accum4 = calc_state_d;
LAB_rom_019b42:
        sVar4 = dec_ln_core();
        if ((char)sVar4 != '\0') {
LAB_rom_019be4:
          dec_zero_helper();
          return 0;
        }
        dec_set_y1();
        do {
          if (4 < (byte)((ulonglong)dec_accum0 >> 8)) goto LAB_rom_019be4;
          dec_swap_XY();
          bVar1 = (CONCAT11(dec_regY_1,dec_regY) < calc_state_e) << 7;
          if ((CONCAT11(dec_regY_1,dec_regY) == calc_state_e) &&
             (decc_sub8((byte)dec_regY_mant,(byte)((ushort)dec_regY_mant >> 8), (uintptr_t)0, (uintptr_t)0)
                             (byte)irq_pending_shadow,(byte)((ushort)irq_pending_shadow >> 8)),
             -1 < (char)bVar1)) {
            bVar1 = bVar1 & 0x9f;
            decc_sub8((byte)calc_state_f,(byte)((ulonglong)calc_state_f >> 8), (uintptr_t)0, (uintptr_t)0)
                           (byte)((ulonglong)calc_state_f >> 0x10),
                           (byte)((ulonglong)calc_state_f >> 0x18));
            if (-1 < (char)bVar1) goto LAB_rom_019bc0;
          }
          dec_int_convert();
          if (0xef < dec_flags) goto LAB_rom_019be4;
          dec_swap_XY();
          calc_state_c =
               CONCAT26(display_dirty,
                        CONCAT24(irq_pending_shadow,
                                 CONCAT22(dec_regY_mant,CONCAT11(dec_regY_1,dec_regY))));
          calc_state_d = CONCAT11(dec_flags_Y,dec_regY_tail);
          dec_build_const();
          dec_regY = (undefined)calc_state_c;
          dec_regY_1 = (char)((ulonglong)calc_state_c >> 8);
          dec_regY_mant = (undefined2)((ulonglong)calc_state_c >> 0x10);
          irq_pending_shadow = (undefined2)((ulonglong)calc_state_c >> 0x20);
          display_dirty = (undefined2)((ulonglong)calc_state_c >> 0x30);
          dec_regY_tail = (undefined)calc_state_d;
          dec_flags_Y = (char)((ushort)calc_state_d >> 8);
        } while( true );
      }
    }
  }
  dec_zero_helper();
  return 0;
LAB_rom_019bc0:
  bVar1 = calc_state_b - 10;
  if (calc_state_b < 10) {
    calc_state_b = bVar1;
    dec_g_Y_to_X();
    dec_fixup_types();
    return 0;
  }
  if (bVar1 == 0) {
    return 0;
  }
  calc_state_b = bVar1;
  dec_swap_XW();
  dec_regY_mant = 0;
  dec_regY = 0;
  dec_regY_1 = '\0';
  display_dirty = 0;
  irq_pending_shadow = 0;
  dec_regY_tail = 0;
  dec_flags_Y = '\0';
  dec_g_Y_to_Z();
  goto LAB_rom_019b42;
}

/**
 * @brief 计算 x·ln(x) 型中间量（乘方公共序列调用），结果写回运算寄存器
 * @addr 0x19B28
 * @module eval
 * @proto void decc_xln(void)
 * @confidence likely
 * @note 计算 x·ln(x) 型中间量（乘方公共序列调用），结果写回运算寄存器。
 * @tag float
 */
int decc_xln(void)

{
  byte bVar1;
  int sVar2;
  
  calc_state_b = 10;
LAB_rom_019b30:
  dec_regY_mant = 0;
  dec_regY = 0;
  display_dirty = 0;
  irq_pending_shadow = 0;
  dec_regY_tail = 0;
  dec_g_Y_to_Z();
  sVar2 = dec_ln_core();
  if ((char)sVar2 != '\0') {
LAB_rom_019be4:
    dec_zero_helper();
    return 0;
  }
  dec_set_y1();
  do {
    if (4 < (byte)((ushort)dec_accum0 >> 8)) goto LAB_rom_019be4;
    dec_swap_XY();
    bVar1 = (dec_regY < calc_state_e) << 7;
    if ((dec_regY == calc_state_e) &&
       (decc_sub8((byte)dec_regY_mant,(byte)((ushort)dec_regY_mant >> 8),(byte)irq_pending_shadow, (uintptr_t)0)
                       (byte)((ushort)irq_pending_shadow >> 8)), -1 < (char)bVar1)) {
      bVar1 = bVar1 & 0x9f;
      decc_sub8((byte)calc_state_f,(byte)((ulonglong)calc_state_f >> 8), (uintptr_t)0, (uintptr_t)0)
                     (byte)((ulonglong)calc_state_f >> 0x10),
                     (byte)((ulonglong)calc_state_f >> 0x18));
      if (-1 < (char)bVar1) break;
    }
    dec_int_convert();
    if (0xef < dec_flags) goto LAB_rom_019be4;
    dec_swap_XY();
    calc_state_c =
         CONCAT26(display_dirty,CONCAT24(irq_pending_shadow,CONCAT22(dec_regY_mant,dec_regY)));
    calc_state_d = dec_regY_tail;
    dec_build_const();
    dec_regY_tail = calc_state_d;
    dec_regY = (ushort)calc_state_c;
    dec_regY_mant = (undefined2)((ulonglong)calc_state_c >> 0x10);
    irq_pending_shadow = (undefined2)((ulonglong)calc_state_c >> 0x20);
    display_dirty = (undefined2)((ulonglong)calc_state_c >> 0x30);
  } while( true );
  bVar1 = calc_state_b - 10;
  if (calc_state_b < 10) {
    calc_state_b = bVar1;
    dec_g_Y_to_X();
    dec_fixup_types();
    return 0;
  }
  if (bVar1 == 0) {
    return 0;
  }
  calc_state_b = bVar1;
  dec_swap_XW();
  goto LAB_rom_019b30;
}

/**
 * @brief e^x 入口
 * @addr 0x19D14
 * @module eval
 * @proto void dec_exp_entry(void)
 * @confidence likely
 * @note e^x 入口：0xD01E=6 后调用 0x1A15A。
 * @tag float
 */
int dec_exp_entry(void)

{
  dec_opcode = 6;
  decc_dispatch();
  return 0;
}

/**
 * @brief 一元运算结果整理
 * @addr 0x19D76
 * @module eval
 * @proto byte decc_unary_sign(void)
 * @confidence likely
 * @note 一元运算结果整理：把 X、Y 统一成同号/取绝对值的中间态，失败返回非 0。
 * @tag float
 */
byte decc_unary_sign(void)

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
      if ((((char)((ushort)uVar2 >> 8) != '\0') && ((byte)uVar2 < 0x15)) &&
         (bVar3 = das('\x14' - (byte)uVar2), bVar3 <= bVar4)) {
        return 0;
      }
    }
    bVar3 = 1;
  }
  return bVar3;
}

/**
 * @brief 对数级数展开
 * @addr 0x19DD6
 * @module eval
 * @proto void decc_log_series(void)
 * @confidence likely
 * @note 对数级数展开：log 核心的公共近似段。
 * @tag float
 */
int decc_log_series(void)

{
  undefined8 uVar1;
  undefined2 uVar2;
  ushort uVar3;
  byte bVar4;
  
  uVar2 = dec_accum4;
  uVar1 = dec_accum0;
  dec_g_X_to_W();
  if ((4 < (byte)((ulonglong)dec_accum0 >> 8)) && ((dec_flags_Y & 0xf0) == 0x20)) {
    dec_g_X_to_Y();
    bVar4 = 0;
    dec_work_a = 0xf;
    decc_int_prep();
    base_submode();
    if ((bVar4 >> 6 & 1) != 1) {
      dec_g_X_to_Z();
      calc_state_c = dec_regY;
      calc_state_d = dec_regY_tail;
      dec_arith_dual();
      dec_accum0 = calc_state_c;
      dec_accum4 = calc_state_d;
      dec_ieee_add();
      dec_swap_XZ();
      dec_ieee_add();
      dec_g_Z_to_Y();
    }
    if (0xf < _DAT_ram_d05b) {
      dec_swap_XY();
    }
    dec_g_Y_to_Z();
    uVar3 = dec_y_exponent();
    if ((char)uVar3 == '\0') {
      dec_zero_helper();
      uVar1 = dec_accum0;
      uVar2 = dec_accum4;
    }
    else {
      dec_g_X_to_Z();
      uVar3 = dec_y_exponent();
      if ((char)uVar3 != '\0') {
        _DAT_ram_d05b = _DAT_ram_d05b + 5;
      }
      if (0xf < _DAT_ram_d05b) {
        dec_swap_XY();
      }
      dec_ieee_add();
      dec_g_X_to_Z2();
      dec_accum0 = uVar1;
      dec_accum4 = uVar2;
      dec_fix_mant_hi();
      uVar1 = dec_accum0;
      uVar2 = dec_accum4;
    }
  }
  dec_accum4 = uVar2;
  dec_accum0 = uVar1;
  return 0;
}

