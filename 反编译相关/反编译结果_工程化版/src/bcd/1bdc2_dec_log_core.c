/*
 * BCD 浮点库 / 1bdc2_dec_log_core.c
 * 地址范围: 0x1BDC2 - 0x1C506
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief log 计算核心（1.6KB，0x1B09C 调用）
 * @addr 0x1BDC2
 * @module bcd
 * @proto int dec_log_core(void)
 * @confidence likely
 * @note log 计算核心（1.6KB，0x1B09C 调用）。
 * @tag bcd
 */
int dec_log_core(void)

{
  ushort uVar1;
  undefined8 in_QR0;
  undefined8 uVar2;
  char cVar4;
  byte bVar5;
  byte bVar6;
  byte bVar7;
  ulonglong uVar3;
  
  uVar2 = CONCAT71((int7)((ulonglong)in_QR0 >> 8),dec_flags);
  if (0xef < dec_flags) {
    return (ushort)uVar2;
  }
  dec_accum8 = 0;
  uVar3 = dec_accum0;
  if (dec_flags == 0) goto LAB_rom_01be04;
  cVar4 = daa((char)(dec_accum0 >> 8) * ' ');
  if (cVar4 == '\0') {
LAB_rom_01be42:
    uVar1 = (ushort)CONCAT71((int7)(uVar3 >> 8),1);
  }
  else {
    bVar5 = (byte)dec_accum0 >> 4;
    if (bVar5 == 0) {
      uVar1 = dec_ln_core();
      uVar3 = (ulonglong)uVar1;
      if ((char)uVar1 != '\0') goto LAB_rom_01be42;
    }
    else if (bVar5 == 1) {
      bVar5 = (byte)(dec_accum0 >> 0x10);
      bVar7 = bVar5 & 0xf;
      bVar6 = (byte)dec_accum0 & 0xf;
      if (bVar6 < 4) {
        if ((dec_accum0 & 0xf0000) != 0) goto LAB_rom_01be42;
        bVar7 = bVar5 >> 4;
        if (bVar6 != 3) {
          if (bVar7 != 0) goto LAB_rom_01be42;
          bVar5 = (byte)(dec_accum0 >> 0x18);
          bVar7 = bVar5 & 0xf;
          if (bVar6 != 2) {
            if ((dec_accum0 & 0xf000000) != 0) goto LAB_rom_01be42;
            bVar7 = bVar5 >> 4;
            if (bVar6 != 1) {
              if (bVar7 != 0) goto LAB_rom_01be42;
              bVar7 = (byte)(dec_accum0 >> 0x20) & 0xf;
            }
          }
        }
LAB_rom_01be34:
        dec_accum8 = bVar7;
      }
      else if (bVar6 == 4) goto LAB_rom_01be34;
    }
LAB_rom_01be04:
    uVar1 = (ushort)uVar3 & 0xff00;
  }
  return uVar1;
}

/**
 * @brief STAT 统计计算过程（大量十进制加减核心调用）
 * @addr 0x1BE46
 * @module bcd
 * @proto void stat_calc_proc(void)
 * @confidence likely
 * @note STAT 统计计算过程（大量十进制加减核心调用）。
 * @tag stat
 */
int stat_calc_proc(void)

{
  ushort uVar1;
  ushort uVar2;
  undefined2 uVar3;
  ushort uVar4;
  undefined2 uVar5;
  undefined2 extraout_ER2;
  undefined5 uVar6;
  byte bVar9;
  char cVar10;
  byte bVar11;
  undefined6 extraout_var;
  undefined6 extraout_var_00;
  byte bVar13;
  ulonglong uVar7;
  byte *pbVar12;
  undefined8 uVar8;
  undefined6 extraout_var_01;
  undefined6 extraout_var_02;
  undefined6 extraout_var_03;
  undefined uVar15;
  ushort uVar14;
  
  if (0xef < dec_flags) {
    return 0;
  }
  if (RAM8(0xd001) < 5) {
    dec_regY_mant = 0;
    dec_regY = 0;
    display_dirty = 0;
    irq_pending_shadow = 0;
    dec_regY_tail = 0;
    calc_state_f = 0;
    calc_state_e = 0;
    RAM8(0xd036) = 0;
    _DAT_ram_d034 = 0;
    calc_state_g = 0;
    calc_state_c = dec_accum0;
    _DAT_ram_d021 = RAM8(0xd001);
    uVar6 = CONCAT14(4,CONCAT22(CONCAT11(RAM8(0xd001),dec_accum0),CONCAT11(RAM8(0xd001),dec_accum0)));
    do {
      bVar9 = (byte)((uint5)uVar6 >> 0x10);
      dec_accum0 = daa((byte)uVar6 + bVar9);
      RAM8(0xd001) = daa(((char)((uint5)uVar6 >> 8) + (char)((uint5)uVar6 >> 0x18)) -
                     ((char)(CARRY1((byte)uVar6,bVar9) << 7) >> 7));
      cVar10 = (char)((uint5)uVar6 >> 0x20) + -1;
      uVar6 = CONCAT14(cVar10,(int)CONCAT32((int3)((uint5)uVar6 >> 0x10),
                                            CONCAT11(RAM8(0xd001),dec_accum0)));
    } while (cVar10 != '\0');
    uVar3 = decc_add8((byte)dec_accum1,(byte)((uint6)dec_accum1 >> 8), (uintptr_t)0, (uintptr_t)0)
                           (byte)((uint6)dec_accum1 >> 0x10),(byte)((uint6)dec_accum1 >> 0x18)
                          );
    dec_regP_mant = CONCAT62(extraout_var,uVar3);
    uVar3 = decc_add8((byte)uVar3,(byte)((ushort)uVar3 >> 8),(byte)extraout_var, (uintptr_t)0)
                           (byte)((uint6)extraout_var >> 8));
    bVar9 = (CONCAT17(dec_flags,CONCAT16(dec_accum4,dec_accum1)) == 0) << 6;
    uVar4 = decc_add8((byte)uVar3,(byte)((ushort)uVar3 >> 8),(byte)extraout_ER2, (uintptr_t)0)
                           (byte)((ushort)extraout_ER2 >> 8));
    if ((bVar9 >> 6 & 1) != 1) {
      uVar15 = daa(RAM8(0xd001) + 5);
      uVar14 = CONCAT11(uVar15,dec_accum0) & 0xfff;
      dec_accum0 = (byte)uVar14;
      RAM8(0xd001) = (byte)(uVar14 >> 8);
    }
    dec_accum1 = (undefined6)CONCAT62(extraout_var_00,uVar4);
    dec_accum4 = (undefined)((uint6)extraout_var_00 >> 0x20);
    dec_flags = (byte)((uint6)extraout_var_00 >> 0x28);
    if ((dec_accum0 & 1) == 0) {
      uVar2 = (ushort)((uint6)extraout_var_00 >> 0x20);
      bVar9 = (byte)(((ushort)RAM8(0xd001) * 0x100 + (ushort)dec_accum0) * 0x10 >> 8);
      uVar14 = (ushort)bVar9 * 0x100 + (ushort)(byte)(dec_accum0 << 4) >> 4;
      dec_accum0 = (byte)uVar14;
      uVar1 = uVar4 * 0x100 + (ushort)bVar9 >> 4;
      RAM8(0xd001) = (byte)uVar1;
      bVar9 = (byte)(uVar4 >> 8);
      bVar11 = (byte)((uint6)extraout_var_00 >> 8);
      bVar13 = (byte)((uint6)extraout_var_00 >> 0x18);
      dec_accum1 =
           CONCAT15((char)(uVar2 * 0x100 + (ushort)bVar13 >> 4),
                    CONCAT14((char)((ushort)bVar13 * 0x100 +
                                    ((ushort)((uint6)extraout_var_00 >> 0x10) & 0xff) >> 4),
                             CONCAT13((char)((ushort)(byte)((uint6)extraout_var_00 >> 0x10) * 0x100
                                             + (ushort)bVar11 >> 4),
                                      CONCAT12((char)((ushort)bVar11 * 0x100 +
                                                      (ushort)(byte)extraout_var_00 >> 4),
                                               CONCAT11((char)((ushort)(byte)extraout_var_00 * 0x100
                                                               + (ushort)bVar9 >> 4),
                                                        (char)((ushort)bVar9 * 0x100 +
                                                               (uVar4 & 0xff) >> 4))))));
      dec_accum4 = (undefined)((uVar2 & 0xff00) + (uVar2 & 0xff) >> 4);
      dec_flags = dec_flags >> 4;
      uVar15 = (char)(uVar1 * 0x100 + (uVar14 & 0xff) >> 4);
    }
    else {
      dec_accum0 = (byte)((ushort)RAM8(0xd001) * 0x100 + (ushort)dec_accum0 >> 4);
      RAM8(0xd001) = RAM8(0xd001) >> 4;
      uVar15 = dec_accum0;
    }
    calc_state_c = CONCAT11(_DAT_ram_d021,uVar15);
    uVar7 = 0xd03900000000050e;
    while( true ) {
      uVar7 = CONCAT53((int5)(uVar7 >> 0x18),(uint3)(ushort)uVar7);
      while( true ) {
        pbVar12 = (byte *)(uVar7 >> 0x30);
        bVar9 = (byte)(uVar7 >> 8);
        if ((uVar7 & 1) == 0) {
          uVar6 = CONCAT14(pbVar12[-1],CONCAT13(bVar9 << 4,(int3)uVar7));
          uVar7 = CONCAT35((int3)(CONCAT26(pbVar12,CONCAT15(*pbVar12,uVar6)) >> 0x28),uVar6) &
                  0xffffff0fffffffff;
          uVar7 = CONCAT26((short)(uVar7 >> 0x30),
                           CONCAT15((char)(uVar7 >> 0x28),
                                    CONCAT14((byte)(uVar7 >> 0x20) | (byte)(uVar7 >> 0x18),
                                             (int)uVar7))) & 0xfffff0ffffffffff;
          bVar9 = (byte)(uVar7 >> 0x28) | (byte)(uVar7 >> 0x10);
          uVar8 = CONCAT26((short)(uVar7 >> 0x30),CONCAT15(bVar9,(int5)uVar7));
          pbVar12[-1] = (byte)(uVar7 >> 0x20);
          *pbVar12 = bVar9;
        }
        else {
          bVar9 = (char)(uVar7 >> 0x10) << 4 | bVar9;
          uVar8 = CONCAT44((int)(uVar7 >> 0x20),CONCAT13(bVar9,(int3)uVar7));
          *pbVar12 = bVar9;
        }
        bVar9 = (byte)((ushort)calc_state_e >> 8);
        cVar10 = (RAM8(0xd001) < bVar9) << 7;
        RAM8(0xd001) = das(RAM8(0xd001) - bVar9);
        uVar3 = decc_sub8_mb((byte)dec_accum1,(byte)((uint6)dec_accum1 >> 8), (uintptr_t)0, (uintptr_t)0)
                               (byte)((uint6)dec_accum1 >> 0x10),
                               (byte)((uint6)dec_accum1 >> 0x18));
        dec_accum1 = (undefined6)CONCAT62(extraout_var_01,uVar3);
        dec_accum4 = (undefined)((uint6)extraout_var_01 >> 0x20);
        dec_flags = (byte)((uint6)extraout_var_01 >> 0x28);
        if (cVar10 < '\0') break;
        uVar7 = CONCAT53((int5)((ulonglong)uVar8 >> 0x18),
                         CONCAT12((char)((ulonglong)uVar8 >> 0x10) + '\x01',(short)uVar8));
      }
      RAM8(0xd001) = daa(RAM8(0xd001) + (char)((ushort)calc_state_e >> 8));
      uVar3 = decc_add8_mb((byte)uVar3,(byte)((ushort)uVar3 >> 8),(byte)extraout_var_01, (uintptr_t)0)
                             (byte)((uint6)extraout_var_01 >> 8));
      dec_accum1 = (undefined6)CONCAT62(extraout_var_02,uVar3);
      dec_accum4 = (undefined)((uint6)extraout_var_02 >> 0x20);
      dec_flags = (byte)((uint6)extraout_var_02 >> 0x28);
      if ((char)uVar8 == '\0') break;
      bVar9 = (char)uVar8 - 1;
      uVar7 = CONCAT44((int)((ulonglong)uVar8 >> 0x20),
                       CONCAT13(bVar9,(int3)CONCAT71((int7)((ulonglong)uVar8 >> 8),bVar9))) &
              0xffffffff01ffffff;
      if ((bVar9 & 1) != 0) {
        uVar7 = CONCAT26((short)(uVar7 >> 0x30) + -1,(int6)uVar7);
      }
      uVar3 = (undefined2)((uint6)extraout_var_02 >> 0x20);
      uVar5 = decc_reload();
      dec_accum0 = (byte)uVar5;
      RAM8(0xd001) = (byte)((ushort)uVar5 >> 8);
      dec_accum4 = (undefined)uVar3;
      dec_flags = (byte)((ushort)uVar3 >> 8);
      dec_accum1 = extraout_var_03;
    }
    dec_accum0 = (byte)calc_state_c;
    RAM8(0xd001) = (byte)((ushort)calc_state_c >> 8);
    dec_accum1 = CONCAT24(RAM8(0xd036),CONCAT22(_DAT_ram_d034,calc_state_f));
    dec_accum4 = (undefined)calc_state_g;
    dec_flags = (byte)((ushort)calc_state_g >> 8);
  }
  else {
    dec_zero_helper();
  }
  return 0;
}

/**
 * @brief 置 Y = 10^0（与 0x1C40A 相同但不检查 X 类型），调用 0x1C022
 * @addr 0x1BFE8
 * @module bcd
 * @proto void dec_set_Y_1e0_x(void)
 * @confidence strong
 * @note 置 Y = 10^0（与 0x1C40A 相同但不检查 X 类型），调用 0x1C022。
 * @tag bcd
 */
int dec_set_Y_1e0_x(void)

{
  if (0xef < dec_flags) {
    return 0;
  }
  dec_regY = 0x100;
  dec_regY_mant = 0;
  irq_pending_shadow = 0;
  display_dirty = 0;
  dec_regY_tail = 0x100;
  dec_neg_Y_inplace();
  return 0;
}

/**
 * @brief 按 D009/D019 的类型标志修正 X（0x1AFB8 或 0x19CB0）
 * @addr 0x1C00A
 * @module bcd
 * @proto void dec_fixup_types(void)
 * @confidence likely
 * @note 按 D009/D019 的类型标志修正 X（0x1AFB8 或 0x19CB0）。
 * @tag bcd
 */
int dec_fixup_types(void)

{
  if (dec_flags < 0xf0) {
    if ((char)((dec_flags_Y < 0xf0) << 7) < '\0') {
      dec_swap_XY();
      dec_core_add();
      return 0;
    }
    dec_g_X_to_Y();
  }
  return 0;
}

/**
 * @brief Y ← −Y
 * @addr 0x1C022
 * @module bcd
 * @proto void dec_neg_Y_inplace(void)
 * @confidence strong
 * @note Y ← −Y：先交换 X/Y，取反后换回。
 * @tag bcd
 */
int dec_neg_Y_inplace(void)

{
  dec_swap_XY();
  dec_core_add();
  return 0;
}

/**
 * @brief 运算后把 Y 规格化（调用 0x1C30C/0x1C338 修正尾数）
 * @addr 0x1C028
 * @module bcd
 * @proto void dec_normalize_y(void)
 * @confidence likely
 * @note 运算后把 Y 规格化（调用 0x1C30C/0x1C338 修正尾数）。
 * @tag bcd
 */
int dec_normalize_y(void)

{
  short sVar1;
  uint uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  undefined2 uVar6;
  undefined2 uVar7;
  undefined uVar9;
  char cVar10;
  undefined uVar11;
  undefined2 extraout_ER2;
  undefined6 extraout_var;
  undefined6 extraout_var_00;
  undefined6 extraout_var_01;
  undefined8 uVar8;
  undefined6 extraout_var_02;
  undefined6 extraout_var_03;
  byte bVar12;
  byte bVar13;
  undefined2 uVar14;
  undefined8 uVar15;
  
  if (dec_flags < 0xf0) {
    if ((char)((dec_flags_Y < 0xf0) << 7) < '\0') {
      uVar15 = CONCAT62(calc_state_f,calc_state_e);
      if (dec_flags_Y != 0) {
        uVar9 = das((byte)dec_accum0 - (byte)dec_regY);
        cVar10 = das(((char)((ushort)dec_accum0 >> 8) - (char)((ushort)dec_regY >> 8)) -
                     ((byte)dec_accum0 < (byte)dec_regY));
        uVar11 = daa(cVar10 + '\x01');
        uVar2 = (uint)CONCAT11(uVar11,uVar9) & 0xfff;
        cVar10 = (char)uVar2;
        uVar9 = das(cVar10 + -1);
        sVar1 = (ushort)(byte)(uVar2 >> 8) - (ushort)(cVar10 == '\0');
        bVar13 = (char)((ushort)sVar1 >> 8) << 7;
        uVar11 = das((char)sVar1);
        calc_state_e = CONCAT11(uVar11,uVar9) & 0xfff;
        uVar7 = (undefined2)dec_regY_mant;
        uVar14 = calc_state_g;
        uVar6 = decc_add8((byte)dec_regY_mant,(byte)((uint7)dec_regY_mant >> 8), (uintptr_t)0, (uintptr_t)0)
                               (byte)((uint7)dec_regY_mant >> 0x10),
                               (byte)((uint7)dec_regY_mant >> 0x18));
        uVar6 = decc_add8((byte)uVar6,(byte)((ushort)uVar6 >> 8),(byte)extraout_ER2, (uintptr_t)0)
                               (byte)((ushort)extraout_ER2 >> 8));
        calc_state_f = (undefined6)CONCAT62(extraout_var,uVar6);
        calc_state_g = (undefined2)((uint6)extraout_var >> 0x20);
        dec_accum0 = calc_state_c;
        calc_state_c = CONCAT62(extraout_var,0x12);
        bVar13 = bVar13 & 0x9f;
        calc_state_d = uVar7;
        while( true ) {
          bVar12 = 2;
          uVar8 = CONCAT17(dec_flags,CONCAT16(dec_accum4,dec_accum1));
          while( true ) {
            bVar13 = bVar13 & 0x9f;
            uVar7 = decc_sub8((byte)uVar8,(byte)((ulonglong)uVar8 >> 8), (uintptr_t)0, (uintptr_t)0)
                                   (byte)((ulonglong)uVar8 >> 0x10),(byte)((ulonglong)uVar8 >> 0x18)
                                  );
            uVar8 = CONCAT62(extraout_var_00,uVar7);
            if ((char)bVar13 < '\0') break;
            bVar13 = (0xfc < bVar12) << 7;
            bVar12 = bVar12 + 3;
          }
          while( true ) {
            bVar13 = bVar13 & 0x9f;
            uVar7 = decc_add8((byte)uVar8,(byte)((ulonglong)uVar8 >> 8), (uintptr_t)0, (uintptr_t)0)
                                   (byte)((ulonglong)uVar8 >> 0x10),(byte)((ulonglong)uVar8 >> 0x18)
                                  );
            uVar8 = CONCAT62(extraout_var_01,uVar7);
            if ((char)bVar13 < '\0') break;
            bVar13 = (bVar12 != 0) << 7;
            bVar12 = bVar12 - 1;
          }
          dec_accum1 = (undefined6)uVar8;
          dec_accum4 = (undefined)((uint6)extraout_var_01 >> 0x20);
          dec_flags = (byte)((uint6)extraout_var_01 >> 0x28);
          bVar13 = ((char)calc_state_c == '\0') << 7;
          cVar10 = (char)calc_state_c + -1;
          uVar8 = CONCAT71((int7)((ulonglong)calc_state_c >> 8),cVar10);
          uVar3 = (ulonglong)calc_state_c >> 8;
          if (cVar10 == '\0') break;
          uVar7 = decc_reload();
          calc_state_c = CONCAT62(extraout_var_02,uVar7);
          bVar13 = bVar13 & 0x9f;
          dec_accum0 = decc_reload();
          dec_accum1 = extraout_var_03;
        }
        dec_accum0 = (undefined2)uVar8;
        dec_accum1 = (undefined6)((ulonglong)calc_state_c >> 0x10);
        dec_accum4 = (undefined)calc_state_d;
        dec_flags = (byte)((ushort)calc_state_d >> 8);
        uVar4 = (ulonglong)calc_state_c >> 0x10;
        uVar5 = (ulonglong)calc_state_c >> 0x18;
        calc_state_c = uVar8;
        dec_pack_X(0,(char)uVar3,(char)uVar4,(char)uVar5,uVar14,uVar15);
        return 0;
      }
      dec_zero_helper();
      return 0;
    }
    dec_g_X_to_Y();
  }
  return 0;
}

/**
 * @brief 浮点加法核心（按指数对齐并 DAA 规范化）
 * @addr 0x1C042
 * @module bcd
 * @proto void dec_ieee_add(void)
 * @confidence strong
 * @note 浮点加法核心（按指数对齐并 DAA 规范化）。
 * @tag bcd
 */
int dec_ieee_add(void)

{
  short sVar1;
  uint uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  undefined2 uVar6;
  undefined2 uVar7;
  undefined uVar9;
  char cVar10;
  undefined uVar11;
  undefined2 extraout_ER2;
  undefined6 extraout_var;
  undefined6 extraout_var_00;
  undefined6 extraout_var_01;
  undefined8 uVar8;
  undefined6 extraout_var_02;
  undefined6 extraout_var_03;
  byte bVar12;
  byte bVar13;
  undefined2 uVar14;
  undefined8 uVar15;
  
  if (dec_flags < 0xf0) {
    if ((char)((dec_flags_Y < 0xf0) << 7) < '\0') {
      calc_state_c = calc_state_c & 0xffffffffffff0000;
      uVar15 = CONCAT62(calc_state_f,calc_state_e);
      if (dec_flags_Y != 0) {
        uVar9 = das((byte)dec_accum0 - (byte)dec_regY);
        cVar10 = das(((char)((ushort)dec_accum0 >> 8) - (char)((ushort)dec_regY >> 8)) -
                     ((byte)dec_accum0 < (byte)dec_regY));
        uVar11 = daa(cVar10 + '\x01');
        uVar2 = (uint)CONCAT11(uVar11,uVar9) & 0xfff;
        cVar10 = (char)uVar2;
        uVar9 = das(cVar10 + -1);
        sVar1 = (ushort)(byte)(uVar2 >> 8) - (ushort)(cVar10 == '\0');
        bVar13 = (char)((ushort)sVar1 >> 8) << 7;
        uVar11 = das((char)sVar1);
        calc_state_e = CONCAT11(uVar11,uVar9) & 0xfff;
        uVar7 = (undefined2)dec_regY_mant;
        uVar14 = calc_state_g;
        uVar6 = decc_add8((byte)dec_regY_mant,(byte)((uint7)dec_regY_mant >> 8), (uintptr_t)0, (uintptr_t)0)
                               (byte)((uint7)dec_regY_mant >> 0x10),
                               (byte)((uint7)dec_regY_mant >> 0x18));
        uVar6 = decc_add8((byte)uVar6,(byte)((ushort)uVar6 >> 8),(byte)extraout_ER2, (uintptr_t)0)
                               (byte)((ushort)extraout_ER2 >> 8));
        calc_state_f = (undefined6)CONCAT62(extraout_var,uVar6);
        calc_state_g = (undefined2)((uint6)extraout_var >> 0x20);
        dec_accum0 = calc_state_c;
        calc_state_c = CONCAT62(extraout_var,0x12);
        bVar13 = bVar13 & 0x9f;
        calc_state_d = uVar7;
        while( true ) {
          bVar12 = 2;
          uVar8 = CONCAT17(dec_flags,CONCAT16(dec_accum4,dec_accum1));
          while( true ) {
            bVar13 = bVar13 & 0x9f;
            uVar7 = decc_sub8((byte)uVar8,(byte)((ulonglong)uVar8 >> 8), (uintptr_t)0, (uintptr_t)0)
                                   (byte)((ulonglong)uVar8 >> 0x10),(byte)((ulonglong)uVar8 >> 0x18)
                                  );
            uVar8 = CONCAT62(extraout_var_00,uVar7);
            if ((char)bVar13 < '\0') break;
            bVar13 = (0xfc < bVar12) << 7;
            bVar12 = bVar12 + 3;
          }
          while( true ) {
            bVar13 = bVar13 & 0x9f;
            uVar7 = decc_add8((byte)uVar8,(byte)((ulonglong)uVar8 >> 8), (uintptr_t)0, (uintptr_t)0)
                                   (byte)((ulonglong)uVar8 >> 0x10),(byte)((ulonglong)uVar8 >> 0x18)
                                  );
            uVar8 = CONCAT62(extraout_var_01,uVar7);
            if ((char)bVar13 < '\0') break;
            bVar13 = (bVar12 != 0) << 7;
            bVar12 = bVar12 - 1;
          }
          dec_accum1 = (undefined6)uVar8;
          dec_accum4 = (undefined)((uint6)extraout_var_01 >> 0x20);
          dec_flags = (byte)((uint6)extraout_var_01 >> 0x28);
          bVar13 = ((char)calc_state_c == '\0') << 7;
          cVar10 = (char)calc_state_c + -1;
          uVar8 = CONCAT71((int7)(calc_state_c >> 8),cVar10);
          uVar3 = calc_state_c >> 8;
          if (cVar10 == '\0') break;
          uVar7 = decc_reload();
          calc_state_c = CONCAT62(extraout_var_02,uVar7);
          bVar13 = bVar13 & 0x9f;
          dec_accum0 = decc_reload();
          dec_accum1 = extraout_var_03;
        }
        dec_accum0 = (undefined2)uVar8;
        dec_accum1 = (undefined6)(calc_state_c >> 0x10);
        dec_accum4 = (undefined)calc_state_d;
        dec_flags = (byte)((ushort)calc_state_d >> 8);
        uVar4 = calc_state_c >> 0x10;
        uVar5 = calc_state_c >> 0x18;
        calc_state_c = uVar8;
        dec_pack_X(0,(char)uVar3,(char)uVar4,(char)uVar5,uVar14,uVar15);
        return 0;
      }
      dec_zero_helper();
      return 0;
    }
    dec_g_X_to_Y();
  }
  return 0;
}

/**
 * @brief 算术核心
 * @addr 0x1C05A
 * @module bcd
 * @proto void dec_core_add(void)
 * @confidence likely
 * @note 算术核心：加法变体（3.7KB，0x1C00A 进入）。
 * @tag bcd
 */
int dec_core_add(void)

{
  short sVar1;
  uint uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  undefined2 uVar6;
  undefined2 uVar7;
  undefined uVar9;
  char cVar10;
  undefined uVar11;
  undefined2 extraout_ER2;
  undefined6 extraout_var;
  undefined6 extraout_var_00;
  undefined6 extraout_var_01;
  undefined8 uVar8;
  undefined6 extraout_var_02;
  undefined6 extraout_var_03;
  byte bVar12;
  byte bVar13;
  undefined2 uVar14;
  undefined8 uVar15;
  
  calc_state_c = calc_state_c & 0xffffffffffff0000;
  uVar15 = CONCAT62(calc_state_f,calc_state_e);
  if (dec_flags_Y != '\0') {
    uVar9 = das((byte)dec_accum0 - (byte)dec_regY);
    cVar10 = das(((char)((ushort)dec_accum0 >> 8) - (char)((ushort)dec_regY >> 8)) -
                 ((byte)dec_accum0 < (byte)dec_regY));
    uVar11 = daa(cVar10 + '\x01');
    uVar2 = (uint)CONCAT11(uVar11,uVar9) & 0xfff;
    cVar10 = (char)uVar2;
    uVar9 = das(cVar10 + -1);
    sVar1 = (ushort)(byte)(uVar2 >> 8) - (ushort)(cVar10 == '\0');
    bVar13 = (char)((ushort)sVar1 >> 8) << 7;
    uVar11 = das((char)sVar1);
    calc_state_e = CONCAT11(uVar11,uVar9) & 0xfff;
    uVar7 = (undefined2)dec_regY_mant;
    uVar14 = calc_state_g;
    uVar6 = decc_add8((byte)dec_regY_mant,(byte)((uint7)dec_regY_mant >> 8), (uintptr_t)0, (uintptr_t)0)
                           (byte)((uint7)dec_regY_mant >> 0x10),(byte)((uint7)dec_regY_mant >> 0x18)
                          );
    uVar6 = decc_add8((byte)uVar6,(byte)((ushort)uVar6 >> 8),(byte)extraout_ER2, (uintptr_t)0)
                           (byte)((ushort)extraout_ER2 >> 8));
    calc_state_f = (undefined6)CONCAT62(extraout_var,uVar6);
    calc_state_g = (undefined2)((uint6)extraout_var >> 0x20);
    dec_accum0 = calc_state_c;
    calc_state_c = CONCAT62(extraout_var,0x12);
    bVar13 = bVar13 & 0x9f;
    calc_state_d = uVar7;
    while( true ) {
      bVar12 = 2;
      uVar8 = CONCAT26(dec_accum4,dec_accum1);
      while( true ) {
        bVar13 = bVar13 & 0x9f;
        uVar7 = decc_sub8((byte)uVar8,(byte)((ulonglong)uVar8 >> 8), (uintptr_t)0, (uintptr_t)0)
                               (byte)((ulonglong)uVar8 >> 0x10),(byte)((ulonglong)uVar8 >> 0x18));
        uVar8 = CONCAT62(extraout_var_00,uVar7);
        if ((char)bVar13 < '\0') break;
        bVar13 = (0xfc < bVar12) << 7;
        bVar12 = bVar12 + 3;
      }
      while( true ) {
        bVar13 = bVar13 & 0x9f;
        uVar7 = decc_add8((byte)uVar8,(byte)((ulonglong)uVar8 >> 8), (uintptr_t)0, (uintptr_t)0)
                               (byte)((ulonglong)uVar8 >> 0x10),(byte)((ulonglong)uVar8 >> 0x18));
        uVar8 = CONCAT62(extraout_var_01,uVar7);
        if ((char)bVar13 < '\0') break;
        bVar13 = (bVar12 != 0) << 7;
        bVar12 = bVar12 - 1;
      }
      dec_accum1 = (undefined6)uVar8;
      dec_accum4 = (undefined2)((uint6)extraout_var_01 >> 0x20);
      bVar13 = ((char)calc_state_c == '\0') << 7;
      cVar10 = (char)calc_state_c + -1;
      uVar8 = CONCAT71((int7)(calc_state_c >> 8),cVar10);
      uVar3 = calc_state_c >> 8;
      if (cVar10 == '\0') break;
      uVar7 = decc_reload();
      calc_state_c = CONCAT62(extraout_var_02,uVar7);
      bVar13 = bVar13 & 0x9f;
      dec_accum0 = decc_reload();
      dec_accum1 = extraout_var_03;
    }
    dec_accum0 = (undefined2)uVar8;
    dec_accum1 = (undefined6)(calc_state_c >> 0x10);
    dec_accum4 = calc_state_d;
    uVar4 = calc_state_c >> 0x10;
    uVar5 = calc_state_c >> 0x18;
    calc_state_c = uVar8;
    dec_pack_X(0,(char)uVar3,(char)uVar4,(char)uVar5,uVar14,uVar15);
    return 0;
  }
  dec_zero_helper();
  return 0;
}

/**
 * @brief 算术核心
 * @addr 0x1C082
 * @module bcd
 * @proto void dec_core_sub(void)
 * @confidence likely
 * @note 算术核心：减法变体（3.2KB）。
 * @tag bcd
 */
int dec_core_sub(int _a1, int _a2, int _a3, int _a4)

{
  short sVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  undefined2 uVar5;
  char cVar8;
  undefined uVar9;
  uint uVar6;
  undefined uVar10;
  undefined2 extraout_ER2;
  undefined6 extraout_var;
  undefined6 extraout_var_00;
  undefined6 extraout_var_01;
  undefined8 uVar7;
  undefined6 extraout_var_02;
  undefined6 extraout_var_03;
  undefined2 uVar11;
  byte bVar12;
  byte bVar13;
  
  cVar8 = das(_a2);
  uVar9 = daa(cVar8 + '\x01');
  uVar6 = CONCAT13(uVar9,(uint3)CONCAT11(_a2,_a1) << 0x10) & 0xfffffff;
  cVar8 = (char)(uVar6 >> 0x10);
  uVar9 = das(cVar8 + -1);
  sVar1 = (ushort)(byte)(uVar6 >> 0x18) - (ushort)(cVar8 == '\0');
  bVar13 = (char)((ushort)sVar1 >> 8) << 7;
  uVar10 = das((char)sVar1);
  calc_state_e = CONCAT11(uVar10,uVar9) & 0xfff;
  uVar7 = dec_regY_mant;
  uVar5 = decc_add8((byte)dec_regY_mant,(byte)((ulonglong)dec_regY_mant >> 8), (uintptr_t)0, (uintptr_t)0)
                         (byte)((ulonglong)dec_regY_mant >> 0x10),
                         (byte)((ulonglong)dec_regY_mant >> 0x18));
  uVar11 = (undefined2)uVar7;
  uVar5 = decc_add8((byte)uVar5,(byte)((ushort)uVar5 >> 8),(byte)extraout_ER2, (uintptr_t)0)
                         (byte)((ushort)extraout_ER2 >> 8));
  calc_state_f = CONCAT62(extraout_var,uVar5);
  dec_accum0 = calc_state_c;
  calc_state_c = CONCAT62(extraout_var,0x12);
  bVar13 = bVar13 & 0x9f;
  calc_state_d = uVar11;
  while( true ) {
    bVar12 = 2;
    uVar7 = CONCAT26(dec_accum4,dec_accum1);
    while( true ) {
      bVar13 = bVar13 & 0x9f;
      uVar5 = decc_sub8((byte)uVar7,(byte)((ulonglong)uVar7 >> 8), (uintptr_t)0, (uintptr_t)0)
                             (byte)((ulonglong)uVar7 >> 0x10),(byte)((ulonglong)uVar7 >> 0x18));
      uVar7 = CONCAT62(extraout_var_00,uVar5);
      if ((char)bVar13 < '\0') break;
      bVar13 = (0xfc < bVar12) << 7;
      bVar12 = bVar12 + 3;
    }
    while( true ) {
      bVar13 = bVar13 & 0x9f;
      uVar5 = decc_add8((byte)uVar7,(byte)((ulonglong)uVar7 >> 8), (uintptr_t)0, (uintptr_t)0)
                             (byte)((ulonglong)uVar7 >> 0x10),(byte)((ulonglong)uVar7 >> 0x18));
      uVar7 = CONCAT62(extraout_var_01,uVar5);
      if ((char)bVar13 < '\0') break;
      bVar13 = (bVar12 != 0) << 7;
      bVar12 = bVar12 - 1;
    }
    dec_accum1 = (undefined6)uVar7;
    dec_accum4 = (undefined2)((uint6)extraout_var_01 >> 0x20);
    bVar13 = ((char)calc_state_c == '\0') << 7;
    cVar8 = (char)calc_state_c + -1;
    uVar7 = CONCAT71((int7)((ulonglong)calc_state_c >> 8),cVar8);
    uVar2 = (ulonglong)calc_state_c >> 8;
    if (cVar8 == '\0') break;
    uVar5 = decc_reload();
    calc_state_c = CONCAT62(extraout_var_02,uVar5);
    bVar13 = bVar13 & 0x9f;
    dec_accum0 = decc_reload();
    dec_accum1 = extraout_var_03;
  }
  dec_accum0 = (undefined2)uVar7;
  dec_accum1 = (undefined6)((ulonglong)calc_state_c >> 0x10);
  dec_accum4 = calc_state_d;
  uVar3 = (ulonglong)calc_state_c >> 0x10;
  uVar4 = (ulonglong)calc_state_c >> 0x18;
  calc_state_c = uVar7;
  dec_pack_X(0,(char)uVar2,(char)uVar3,(char)uVar4,_a3,_a4);
  return 0;
}

/**
 * @brief Y ← X 的完整 10 字节复制（X 为特殊值时直接返回），供取负/一元运算使用
 * @addr 0x1C152
 * @module bcd
 * @proto void dec_g_X_to_Y_copy(void)
 * @confidence strong
 * @note Y ← X 的完整 10 字节复制（X 为特殊值时直接返回），供取负/一元运算使用。
 * @tag bcd
 */
int dec_g_X_to_Y_copy(void)

{
  if (0xef < dec_flags) {
    return 0;
  }
  dec_regY = dec_accum0;
  dec_regY_tail = dec_accum4;
  dec_core_mul_b();
  return 0;
}

/**
 * @brief 算术核心
 * @addr 0x1C170
 * @module bcd
 * @proto void dec_core_mul(void)
 * @confidence likely
 * @note 算术核心：乘法（7.1KB）。
 * @tag bcd
 */
int dec_core_mul(void)

{
  ushort uVar1;
  uint7 uVar2;
  undefined2 uVar3;
  undefined6 uVar4;
  undefined2 uVar5;
  undefined2 uVar6;
  byte bVar12;
  uint3 uVar7;
  undefined3 uVar8;
  byte bVar14;
  byte bVar16;
  char cVar17;
  uint uVar9;
  undefined2 extraout_ER2;
  undefined2 extraout_ER2_00;
  undefined *puVar19;
  undefined6 extraout_var;
  undefined8 uVar10;
  ulonglong uVar11;
  byte bVar18;
  undefined6 extraout_var_00;
  undefined6 extraout_var_01;
  undefined6 extraout_var_02;
  undefined6 extraout_var_03;
  byte bVar21;
  undefined4 uVar20;
  undefined uVar13;
  byte bVar15;
  
  uVar5 = calc_state_g;
  uVar4 = calc_state_f;
  uVar3 = calc_state_e;
  if (dec_flags < 0xf0) {
    if ((char)((dec_flags_Y < 0xf0) << 7) < '\0') {
      uVar13 = daa((byte)dec_accum0 + (byte)dec_regY);
      uVar7 = CONCAT12(uVar13,0x11);
      cVar17 = daa(((char)(dec_accum0 >> 8) + (char)((ushort)dec_regY >> 8)) -
                   ((char)(CARRY1((byte)dec_accum0,(byte)dec_regY) << 7) >> 7));
      uVar13 = das(cVar17 + -1);
      uVar9 = CONCAT13(uVar13,uVar7) & 0xfffffff;
      calc_state_e = (undefined2)(uVar9 >> 0x10);
      uVar6 = decc_add8((byte)dec_regY_mant,(byte)((uint7)dec_regY_mant >> 8), (uintptr_t)0, (uintptr_t)0)
                             (byte)((uint7)dec_regY_mant >> 0x10),
                             (byte)((uint7)dec_regY_mant >> 0x18));
      uVar6 = decc_add8((byte)uVar6,(byte)((ushort)uVar6 >> 8),(byte)extraout_ER2, (uintptr_t)0)
                             (byte)((ushort)extraout_ER2 >> 8));
      calc_state_f = (undefined6)CONCAT62(extraout_var,uVar6);
      calc_state_g = (undefined2)((uint6)extraout_var >> 0x20);
      dec_regP_mant =
           CONCAT17(dec_flags,
                    CONCAT16(dec_accum4,
                             CONCAT24(dec_accum3,CONCAT22(dec_accum2,dec_accum1))));
      uVar11 = CONCAT35(0xd0,CONCAT14(0x22,(uint)uVar7 & 0xff));
      if ((char)uVar9 != '\x0f') {
        uVar11 = (ulonglong)CONCAT24((short)(uVar11 >> 0x20) + -1,(uint)uVar7) & 0xffffffff000000ff;
      }
      uVar10 = CONCAT44((int)(uVar11 >> 0x20),(uint)(byte)uVar11);
      dec_accum1 = 0;
      dec_accum2 = 0;
      dec_accum3 = 0;
      dec_accum4 = 0;
      dec_flags = 0;
      do {
        if ((char)((ulonglong)uVar10 >> 8) == '\0') {
          puVar19 = (undefined *)((ulonglong)uVar10 >> 0x20);
          uVar13 = *puVar19;
          uVar8 = CONCAT12(uVar13,CONCAT11(1,(byte)uVar10));
          uVar11 = (ulonglong)
                   CONCAT33((int3)(CONCAT24(puVar19 + 1,CONCAT13(uVar13,uVar8)) >> 0x18),uVar8) &
                   0xfffffffff00fffff;
          uVar11 = CONCAT44((int)(uVar11 >> 0x20),CONCAT13((byte)(uVar11 >> 0x18) >> 4,(int3)uVar11)
                           );
        }
        else {
          uVar11 = CONCAT53((int5)((ulonglong)uVar10 >> 0x18),
                            CONCAT12((char)((ulonglong)uVar10 >> 0x18),(ushort)(byte)uVar10));
        }
        while( true ) {
          bVar15 = (byte)(uVar11 >> 0x10);
          bVar14 = bVar15 - 3;
          uVar2 = CONCAT43((int)(CONCAT16(3,(int6)uVar11) >> 0x18),CONCAT12(bVar14,(short)uVar11));
          bVar21 = (byte)dec_accum1;
          bVar12 = (byte)(dec_accum1 >> 8);
          bVar16 = (byte)dec_accum2;
          bVar18 = (byte)(dec_accum2 >> 8);
          if (bVar14 == 0) break;
          if (bVar15 < 3) {
            if (bVar14 == 0xfe) {
              dec_accum1 = decc_add8(bVar21,bVar12,bVar16,bVar18);
              dec_accum2 = (ushort)extraout_var_03;
              dec_accum3 = (ushort)((uint6)extraout_var_03 >> 0x10);
              dec_accum4 = (byte)((uint6)extraout_var_03 >> 0x20);
              dec_flags = (byte)((uint6)extraout_var_03 >> 0x28);
            }
            else if (0xfd < bVar14) {
              uVar6 = decc_add8(bVar21,bVar12,bVar16,bVar18);
              dec_accum1 =
                   decc_add8((byte)uVar6,(byte)((ushort)uVar6 >> 8),(byte)extraout_ER2_00, (uintptr_t)0)
                                  (byte)((ushort)extraout_ER2_00 >> 8));
              dec_accum2 = (ushort)extraout_var_02;
              dec_accum3 = (ushort)((uint6)extraout_var_02 >> 0x10);
              dec_accum4 = (byte)((uint6)extraout_var_02 >> 0x20);
              dec_flags = (byte)((uint6)extraout_var_02 >> 0x28);
            }
            goto LAB_rom_01c2ac;
          }
          dec_accum1 = decc_add8(bVar21,bVar12,bVar16,bVar18);
          dec_accum2 = (ushort)extraout_var_00;
          dec_accum3 = (ushort)((uint6)extraout_var_00 >> 0x10);
          dec_accum4 = (byte)((uint6)extraout_var_00 >> 0x20);
          dec_flags = (byte)((uint6)extraout_var_00 >> 0x28);
          uVar11 = (ulonglong)uVar2;
        }
        dec_accum1 = decc_add8(bVar21,bVar12,bVar16,bVar18);
        dec_accum2 = (ushort)extraout_var_01;
        dec_accum3 = (ushort)((uint6)extraout_var_01 >> 0x10);
        dec_accum4 = (byte)((uint6)extraout_var_01 >> 0x20);
        dec_flags = (byte)((uint6)extraout_var_01 >> 0x28);
LAB_rom_01c2ac:
        cVar17 = (char)uVar11 + -1;
        if (cVar17 == '\0') {
          calc_state_c = dec_accum0;
          if (0xf < dec_flags) {
            calc_state_c =
                 CONCAT11((char)(dec_accum1 * 0x100 + (dec_accum0 >> 8) >> 4),
                          (char)dec_accum0);
          }
          dec_accum0 = calc_state_e;
          calc_state_e = uVar3;
          calc_state_f = uVar4;
          calc_state_g = uVar5;
          dec_ieee_norm();
          return 0;
        }
        uVar10 = CONCAT17((char)(dec_accum1 * 0x100 + (dec_accum0 >> 8) >> 4),
                          (int7)CONCAT26(dec_accum0,
                                         (int6)CONCAT71(CONCAT16(1,(int6)uVar2) >> 8,cVar17)));
        bVar21 = (byte)(dec_accum1 >> 8);
        dec_accum1 =
             CONCAT11((char)(dec_accum2 * 0x100 + (ushort)bVar21 >> 4),
                      (char)((ushort)bVar21 * 0x100 + (dec_accum1 & 0xff) >> 4));
        bVar21 = (byte)(dec_accum2 >> 8);
        uVar20 = CONCAT13((char)(dec_accum3 * 0x100 + (ushort)bVar21 >> 4),
                          CONCAT12((char)((ushort)bVar21 * 0x100 + (dec_accum2 & 0xff) >> 4),
                                   dec_accum1));
        bVar21 = (byte)(dec_accum3 >> 8);
        uVar1 = (ushort)dec_accum4;
        dec_accum4 = (byte)((ushort)dec_flags * 0x100 + (ushort)dec_accum4 >> 4);
        dec_flags = dec_flags >> 4;
        dec_accum0 = (ushort)((ulonglong)uVar10 >> 0x30);
        dec_accum2 = (ushort)((uint)uVar20 >> 0x10);
        dec_accum3 =
             (ushort)(CONCAT15((char)(uVar1 * 0x100 + (ushort)bVar21 >> 4),
                               CONCAT14((char)((ushort)bVar21 * 0x100 + (dec_accum3 & 0xff) >> 4)
                                        ,uVar20)) >> 0x20);
      } while( true );
    }
    dec_g_X_to_Y();
  }
  return 0;
}

/**
 * @brief 浮点→整数/科学计数中间表示转换（X、Y 寄存器）
 * @addr 0x1C18C
 * @module bcd
 * @proto void dec_int_convert(void)
 * @confidence likely
 * @note 浮点→整数/科学计数中间表示转换（X、Y 寄存器）。
 * @tag bcd
 */
int dec_int_convert(void)

{
  ushort uVar1;
  uint7 uVar2;
  undefined2 uVar3;
  undefined6 uVar4;
  undefined2 uVar5;
  undefined2 uVar6;
  byte bVar12;
  uint3 uVar7;
  undefined3 uVar8;
  byte bVar14;
  byte bVar16;
  char cVar17;
  uint uVar9;
  undefined2 extraout_ER2;
  undefined2 extraout_ER2_00;
  undefined *puVar19;
  undefined6 extraout_var;
  undefined8 uVar10;
  ulonglong uVar11;
  byte bVar18;
  undefined6 extraout_var_00;
  undefined6 extraout_var_01;
  undefined6 extraout_var_02;
  undefined6 extraout_var_03;
  byte bVar21;
  undefined4 uVar20;
  undefined uVar13;
  byte bVar15;
  
  uVar5 = calc_state_g;
  uVar4 = calc_state_f;
  uVar3 = calc_state_e;
  if (dec_flags < 0xf0) {
    if ((char)((dec_flags_Y < 0xf0) << 7) < '\0') {
      uVar13 = daa((byte)dec_accum0 + (byte)dec_regY);
      uVar7 = CONCAT12(uVar13,0xf);
      cVar17 = daa(((char)(dec_accum0 >> 8) + (char)((ushort)dec_regY >> 8)) -
                   ((char)(CARRY1((byte)dec_accum0,(byte)dec_regY) << 7) >> 7));
      uVar13 = das(cVar17 + -1);
      uVar9 = CONCAT13(uVar13,uVar7) & 0xfffffff;
      calc_state_e = (undefined2)(uVar9 >> 0x10);
      uVar6 = decc_add8((byte)dec_regY_mant,(byte)((uint7)dec_regY_mant >> 8), (uintptr_t)0, (uintptr_t)0)
                             (byte)((uint7)dec_regY_mant >> 0x10),
                             (byte)((uint7)dec_regY_mant >> 0x18));
      uVar6 = decc_add8((byte)uVar6,(byte)((ushort)uVar6 >> 8),(byte)extraout_ER2, (uintptr_t)0)
                             (byte)((ushort)extraout_ER2 >> 8));
      calc_state_f = (undefined6)CONCAT62(extraout_var,uVar6);
      calc_state_g = (undefined2)((uint6)extraout_var >> 0x20);
      dec_regP_mant =
           CONCAT17(dec_flags,
                    CONCAT16(dec_accum4,
                             CONCAT24(dec_accum3,CONCAT22(dec_accum2,dec_accum1))));
      uVar11 = CONCAT35(0xd0,CONCAT14(0x22,(uint)uVar7 & 0xff));
      if ((char)uVar9 != '\x0f') {
        uVar11 = (ulonglong)CONCAT24((short)(uVar11 >> 0x20) + -1,(uint)uVar7) & 0xffffffff000000ff;
      }
      uVar10 = CONCAT44((int)(uVar11 >> 0x20),(uint)(byte)uVar11);
      dec_accum1 = 0;
      dec_accum2 = 0;
      dec_accum3 = 0;
      dec_accum4 = 0;
      dec_flags = 0;
      do {
        if ((char)((ulonglong)uVar10 >> 8) == '\0') {
          puVar19 = (undefined *)((ulonglong)uVar10 >> 0x20);
          uVar13 = *puVar19;
          uVar8 = CONCAT12(uVar13,CONCAT11(1,(byte)uVar10));
          uVar11 = (ulonglong)
                   CONCAT33((int3)(CONCAT24(puVar19 + 1,CONCAT13(uVar13,uVar8)) >> 0x18),uVar8) &
                   0xfffffffff00fffff;
          uVar11 = CONCAT44((int)(uVar11 >> 0x20),CONCAT13((byte)(uVar11 >> 0x18) >> 4,(int3)uVar11)
                           );
        }
        else {
          uVar11 = CONCAT53((int5)((ulonglong)uVar10 >> 0x18),
                            CONCAT12((char)((ulonglong)uVar10 >> 0x18),(ushort)(byte)uVar10));
        }
        while( true ) {
          bVar15 = (byte)(uVar11 >> 0x10);
          bVar14 = bVar15 - 3;
          uVar2 = CONCAT43((int)(CONCAT16(3,(int6)uVar11) >> 0x18),CONCAT12(bVar14,(short)uVar11));
          bVar21 = (byte)dec_accum1;
          bVar12 = (byte)(dec_accum1 >> 8);
          bVar16 = (byte)dec_accum2;
          bVar18 = (byte)(dec_accum2 >> 8);
          if (bVar14 == 0) break;
          if (bVar15 < 3) {
            if (bVar14 == 0xfe) {
              dec_accum1 = decc_add8(bVar21,bVar12,bVar16,bVar18);
              dec_accum2 = (ushort)extraout_var_03;
              dec_accum3 = (ushort)((uint6)extraout_var_03 >> 0x10);
              dec_accum4 = (byte)((uint6)extraout_var_03 >> 0x20);
              dec_flags = (byte)((uint6)extraout_var_03 >> 0x28);
            }
            else if (0xfd < bVar14) {
              uVar6 = decc_add8(bVar21,bVar12,bVar16,bVar18);
              dec_accum1 =
                   decc_add8((byte)uVar6,(byte)((ushort)uVar6 >> 8),(byte)extraout_ER2_00, (uintptr_t)0)
                                  (byte)((ushort)extraout_ER2_00 >> 8));
              dec_accum2 = (ushort)extraout_var_02;
              dec_accum3 = (ushort)((uint6)extraout_var_02 >> 0x10);
              dec_accum4 = (byte)((uint6)extraout_var_02 >> 0x20);
              dec_flags = (byte)((uint6)extraout_var_02 >> 0x28);
            }
            goto LAB_rom_01c2ac;
          }
          dec_accum1 = decc_add8(bVar21,bVar12,bVar16,bVar18);
          dec_accum2 = (ushort)extraout_var_00;
          dec_accum3 = (ushort)((uint6)extraout_var_00 >> 0x10);
          dec_accum4 = (byte)((uint6)extraout_var_00 >> 0x20);
          dec_flags = (byte)((uint6)extraout_var_00 >> 0x28);
          uVar11 = (ulonglong)uVar2;
        }
        dec_accum1 = decc_add8(bVar21,bVar12,bVar16,bVar18);
        dec_accum2 = (ushort)extraout_var_01;
        dec_accum3 = (ushort)((uint6)extraout_var_01 >> 0x10);
        dec_accum4 = (byte)((uint6)extraout_var_01 >> 0x20);
        dec_flags = (byte)((uint6)extraout_var_01 >> 0x28);
LAB_rom_01c2ac:
        cVar17 = (char)uVar11 + -1;
        if (cVar17 == '\0') {
          calc_state_c = dec_accum0;
          if (0xf < dec_flags) {
            calc_state_c =
                 CONCAT11((char)(dec_accum1 * 0x100 + (dec_accum0 >> 8) >> 4),
                          (char)dec_accum0);
          }
          dec_accum0 = calc_state_e;
          calc_state_e = uVar3;
          calc_state_f = uVar4;
          calc_state_g = uVar5;
          dec_ieee_norm();
          return 0;
        }
        uVar10 = CONCAT17((char)(dec_accum1 * 0x100 + (dec_accum0 >> 8) >> 4),
                          (int7)CONCAT26(dec_accum0,
                                         (int6)CONCAT71(CONCAT16(1,(int6)uVar2) >> 8,cVar17)));
        bVar21 = (byte)(dec_accum1 >> 8);
        dec_accum1 =
             CONCAT11((char)(dec_accum2 * 0x100 + (ushort)bVar21 >> 4),
                      (char)((ushort)bVar21 * 0x100 + (dec_accum1 & 0xff) >> 4));
        bVar21 = (byte)(dec_accum2 >> 8);
        uVar20 = CONCAT13((char)(dec_accum3 * 0x100 + (ushort)bVar21 >> 4),
                          CONCAT12((char)((ushort)bVar21 * 0x100 + (dec_accum2 & 0xff) >> 4),
                                   dec_accum1));
        bVar21 = (byte)(dec_accum3 >> 8);
        uVar1 = (ushort)dec_accum4;
        dec_accum4 = (byte)((ushort)dec_flags * 0x100 + (ushort)dec_accum4 >> 4);
        dec_flags = dec_flags >> 4;
        dec_accum0 = (ushort)((ulonglong)uVar10 >> 0x30);
        dec_accum2 = (ushort)((uint)uVar20 >> 0x10);
        dec_accum3 =
             (ushort)(CONCAT15((char)(uVar1 * 0x100 + (ushort)bVar21 >> 4),
                               CONCAT14((char)((ushort)bVar21 * 0x100 + (dec_accum3 & 0xff) >> 4)
                                        ,uVar20)) >> 0x20);
      } while( true );
    }
    dec_g_X_to_Y();
  }
  return 0;
}

/**
 * @brief 算术核心
 * @addr 0x1C1A4
 * @module bcd
 * @proto void dec_core_mul_b(void)
 * @confidence likely
 * @note 算术核心：乘法变体（6.3KB）。
 * @tag bcd
 */
int dec_core_mul_b(void)

{
  uint7 uVar1;
  undefined2 uVar2;
  undefined6 uVar3;
  undefined2 uVar4;
  undefined2 uVar5;
  uint3 uVar6;
  undefined3 uVar7;
  byte bVar12;
  byte bVar14;
  char cVar15;
  uint uVar8;
  undefined2 extraout_ER2;
  undefined2 extraout_ER2_00;
  undefined *puVar17;
  undefined6 extraout_var;
  undefined8 uVar9;
  ulonglong uVar10;
  byte bVar16;
  undefined6 extraout_var_00;
  undefined6 extraout_var_01;
  undefined6 extraout_var_02;
  undefined6 extraout_var_03;
  byte bVar20;
  undefined4 uVar18;
  undefined6 uVar19;
  byte bVar21;
  undefined uVar11;
  byte bVar13;
  
  uVar4 = calc_state_g;
  uVar3 = calc_state_f;
  uVar2 = calc_state_e;
  uVar11 = daa((byte)dec_accum0 + (byte)dec_regY);
  uVar6 = CONCAT12(uVar11,0xf);
  cVar15 = daa(((char)(dec_accum0 >> 8) + (char)((ushort)dec_regY >> 8)) -
               ((char)(CARRY1((byte)dec_accum0,(byte)dec_regY) << 7) >> 7));
  uVar11 = das(cVar15 + -1);
  uVar8 = CONCAT13(uVar11,uVar6) & 0xfffffff;
  calc_state_e = (undefined2)(uVar8 >> 0x10);
  uVar5 = decc_add8((byte)dec_regY_mant,(byte)((ulonglong)dec_regY_mant >> 8), (uintptr_t)0, (uintptr_t)0)
                         (byte)((ulonglong)dec_regY_mant >> 0x10),
                         (byte)((ulonglong)dec_regY_mant >> 0x18));
  uVar5 = decc_add8((byte)uVar5,(byte)((ushort)uVar5 >> 8),(byte)extraout_ER2, (uintptr_t)0)
                         (byte)((ushort)extraout_ER2 >> 8));
  calc_state_f = (undefined6)CONCAT62(extraout_var,uVar5);
  calc_state_g = (undefined2)((uint6)extraout_var >> 0x20);
  dec_regP_mant =
       CONCAT26(dec_accum4,CONCAT24(dec_accum3,CONCAT22(dec_accum2,dec_accum1)));
  uVar10 = CONCAT35((int3)(CONCAT26(dec_accum4,0xd00000000000) >> 0x28),
                    CONCAT14(0x22,(uint)uVar6 & 0xff));
  if ((char)uVar8 != '\x0f') {
    uVar10 = CONCAT26(dec_accum4,CONCAT24((short)(uVar10 >> 0x20) + -1,(uint)uVar6)) &
             0xffffffff000000ff;
  }
  uVar9 = CONCAT44((int)(uVar10 >> 0x20),(uint)(byte)uVar10);
  dec_accum1 = 0;
  dec_accum2 = 0;
  dec_accum3 = 0;
  dec_accum4 = 0;
  do {
    if ((char)((ulonglong)uVar9 >> 8) == '\0') {
      puVar17 = (undefined *)((ulonglong)uVar9 >> 0x20);
      uVar11 = *puVar17;
      uVar7 = CONCAT12(uVar11,CONCAT11(1,(byte)uVar9));
      uVar10 = (ulonglong)
               CONCAT33((int3)(CONCAT24(puVar17 + 1,CONCAT13(uVar11,uVar7)) >> 0x18),uVar7) &
               0xfffffffff00fffff;
      uVar10 = CONCAT44((int)(uVar10 >> 0x20),CONCAT13((byte)(uVar10 >> 0x18) >> 4,(int3)uVar10));
    }
    else {
      uVar10 = CONCAT53((int5)((ulonglong)uVar9 >> 0x18),
                        CONCAT12((char)((ulonglong)uVar9 >> 0x18),(ushort)(byte)uVar9));
    }
    while( true ) {
      bVar13 = (byte)(uVar10 >> 0x10);
      bVar12 = bVar13 - 3;
      uVar1 = CONCAT43((int)(CONCAT16(3,(int6)uVar10) >> 0x18),CONCAT12(bVar12,(short)uVar10));
      bVar21 = (byte)dec_accum1;
      bVar20 = (byte)(dec_accum1 >> 8);
      bVar14 = (byte)dec_accum2;
      bVar16 = (byte)(dec_accum2 >> 8);
      if (bVar12 == 0) break;
      if (bVar13 < 3) {
        if (bVar12 == 0xfe) {
          dec_accum1 = decc_add8(bVar21,bVar20,bVar14,bVar16);
          dec_accum2 = (ushort)extraout_var_03;
          dec_accum3 = (ushort)((uint6)extraout_var_03 >> 0x10);
          dec_accum4 = (ushort)((uint6)extraout_var_03 >> 0x20);
        }
        else if (0xfd < bVar12) {
          uVar5 = decc_add8(bVar21,bVar20,bVar14,bVar16);
          dec_accum1 =
               decc_add8((byte)uVar5,(byte)((ushort)uVar5 >> 8),(byte)extraout_ER2_00, (uintptr_t)0)
                              (byte)((ushort)extraout_ER2_00 >> 8));
          dec_accum2 = (ushort)extraout_var_02;
          dec_accum3 = (ushort)((uint6)extraout_var_02 >> 0x10);
          dec_accum4 = (ushort)((uint6)extraout_var_02 >> 0x20);
        }
        goto LAB_rom_01c2ac;
      }
      dec_accum1 = decc_add8(bVar21,bVar20,bVar14,bVar16);
      dec_accum2 = (ushort)extraout_var_00;
      dec_accum3 = (ushort)((uint6)extraout_var_00 >> 0x10);
      dec_accum4 = (ushort)((uint6)extraout_var_00 >> 0x20);
      uVar10 = (ulonglong)uVar1;
    }
    dec_accum1 = decc_add8(bVar21,bVar20,bVar14,bVar16);
    dec_accum2 = (ushort)extraout_var_01;
    dec_accum3 = (ushort)((uint6)extraout_var_01 >> 0x10);
    dec_accum4 = (ushort)((uint6)extraout_var_01 >> 0x20);
LAB_rom_01c2ac:
    cVar15 = (char)uVar10 + -1;
    bVar21 = (byte)(dec_accum4 >> 8);
    if (cVar15 == '\0') {
      calc_state_c = dec_accum0;
      if (0xf < bVar21) {
        calc_state_c =
             CONCAT11((char)(dec_accum1 * 0x100 + (dec_accum0 >> 8) >> 4),(char)dec_accum0)
        ;
      }
      dec_accum0 = calc_state_e;
      calc_state_e = uVar2;
      calc_state_f = uVar3;
      calc_state_g = uVar4;
      dec_ieee_norm();
      return 0;
    }
    uVar9 = CONCAT17((char)(dec_accum1 * 0x100 + (dec_accum0 >> 8) >> 4),
                     (int7)CONCAT26(dec_accum0,
                                    (int6)CONCAT71(CONCAT16(1,(int6)uVar1) >> 8,cVar15)));
    bVar20 = (byte)(dec_accum1 >> 8);
    dec_accum1 =
         CONCAT11((char)(dec_accum2 * 0x100 + (ushort)bVar20 >> 4),
                  (char)((ushort)bVar20 * 0x100 + (dec_accum1 & 0xff) >> 4));
    bVar20 = (byte)(dec_accum2 >> 8);
    uVar18 = CONCAT13((char)(dec_accum3 * 0x100 + (ushort)bVar20 >> 4),
                      CONCAT12((char)((ushort)bVar20 * 0x100 + (dec_accum2 & 0xff) >> 4),
                               dec_accum1));
    bVar20 = (byte)(dec_accum3 >> 8);
    uVar19 = CONCAT15((char)(dec_accum4 * 0x100 + (ushort)bVar20 >> 4),
                      CONCAT14((char)((ushort)bVar20 * 0x100 + (dec_accum3 & 0xff) >> 4),uVar18))
    ;
    dec_accum0 = (ushort)((ulonglong)uVar9 >> 0x30);
    dec_accum2 = (ushort)((uint)uVar18 >> 0x10);
    dec_accum3 = (ushort)((uint6)uVar19 >> 0x20);
    dec_accum4 =
         (ushort)(CONCAT17(bVar21 >> 4,
                           CONCAT16((char)((ushort)bVar21 * 0x100 + (dec_accum4 & 0xff) >> 4),
                                    uVar19)) >> 0x30);
  } while( true );
}

/**
 * @brief 把 X 的尾数与指数打包到 P（0xD020）
 * @addr 0x1C2D6
 * @module bcd
 * @proto void dec_pack_X(void)
 * @confidence likely
 * @note 把 X 的尾数与指数打包到 P（0xD020）。
 * @tag bcd
 */
int dec_pack_X(uintptr_t _a3, uintptr_t _a4, uintptr_t _a5, uintptr_t _a6, uintptr_t _a7, uintptr_t _a8, int _a1, int _a2)

{
  calc_state_c = dec_accum0;
  if (0xf < (byte)((ushort)dec_accum4 >> 8)) {
    calc_state_c =
         CONCAT11((char)((ushort)(byte)dec_accum1 * 0x100 + (dec_accum0 >> 8) >> 4),
                  (char)dec_accum0);
  }
  dec_accum0 = calc_state_e;
  calc_state_e = _a2;
  calc_state_g = _a1;
  dec_ieee_norm();
  return 0;
}

/**
 * @brief 8 字节 BCD 加法（多字节复用入口，对应 0x1C30C 的 ADDC 链）
 * @addr 0x1C304
 * @module bcd
 * @proto undefined2 decc_add8_mb(byte r0, byte r1, byte r2, byte r3)
 * @confidence strong
 * @note 8 字节 BCD 加法（多字节复用入口，对应 0x1C30C 的 ADDC 链）。
 * @tag bcd
 */
undefined2 decc_add8_mb(byte r0, byte r1, byte r2, byte r3)

{
  short sVar1;
  undefined uVar2;
  undefined uVar3;
  byte unaff_R4;
  byte unaff_R5;
  byte unaff_R6;
  char unaff_R7;
  byte unaff_R8;
  byte unaff_R9;
  byte unaff_R10;
  byte unaff_R11;
  byte unaff_R12;
  byte unaff_R13;
  byte unaff_R14;
  char unaff_R15;
  byte in_PSW;
  
  sVar1 = (ushort)r0 + (ushort)unaff_R8 + (ushort)(in_PSW >> 7);
  uVar2 = daa((char)sVar1);
  sVar1 = (ushort)r1 + (ushort)unaff_R9 + (ushort)((byte)((ushort)sVar1 >> 8) & 1);
  uVar3 = daa((char)sVar1);
  sVar1 = (ushort)r2 + (ushort)unaff_R10 + (ushort)((byte)((ushort)sVar1 >> 8) & 1);
  daa((char)sVar1);
  sVar1 = (ushort)r3 + (ushort)unaff_R11 + (ushort)((byte)((ushort)sVar1 >> 8) & 1);
  daa((char)sVar1);
  sVar1 = (ushort)unaff_R4 + (ushort)unaff_R12 + (ushort)((byte)((ushort)sVar1 >> 8) & 1);
  daa((char)sVar1);
  sVar1 = (ushort)unaff_R5 + (ushort)unaff_R13 + (ushort)((byte)((ushort)sVar1 >> 8) & 1);
  daa((char)sVar1);
  sVar1 = (ushort)unaff_R6 + (ushort)unaff_R14 + (ushort)((byte)((ushort)sVar1 >> 8) & 1);
  daa((char)sVar1);
  daa((unaff_R7 + unaff_R15) - ((char)(in_PSW & 0xf | (char)((ushort)sVar1 >> 8) << 7) >> 7));
  return CONCAT11(uVar3,uVar2);
}

/**
 * @brief 8 字节 BCD 加法
 * @addr 0x1C30C
 * @module bcd
 * @proto undefined2 decc_add8(byte r0, byte r1, byte r2, byte r3)
 * @confidence verified
 * @note 8 字节 BCD 加法：ADD/ADDC + DAA 链，操作数在 R0..R7 与 R8..R15，结果留在
 *       R0..R7（Ghidra 记为 unaff_R8..R15）。
 * @tag bcd
 */
undefined2 decc_add8(byte r0, byte r1, byte r2, byte r3)

{
  short sVar1;
  undefined uVar2;
  undefined uVar3;
  byte unaff_R4;
  byte unaff_R5;
  byte unaff_R6;
  char unaff_R7;
  byte unaff_R8;
  byte unaff_R9;
  byte unaff_R10;
  byte unaff_R11;
  byte unaff_R12;
  byte unaff_R13;
  byte unaff_R14;
  char unaff_R15;
  
  uVar2 = daa(r0 + unaff_R8);
  sVar1 = (ushort)r1 + (ushort)unaff_R9 + (ushort)CARRY1(r0,unaff_R8);
  uVar3 = daa((char)sVar1);
  sVar1 = (ushort)r2 + (ushort)unaff_R10 + (ushort)((byte)((ushort)sVar1 >> 8) & 1);
  daa((char)sVar1);
  sVar1 = (ushort)r3 + (ushort)unaff_R11 + (ushort)((byte)((ushort)sVar1 >> 8) & 1);
  daa((char)sVar1);
  sVar1 = (ushort)unaff_R4 + (ushort)unaff_R12 + (ushort)((byte)((ushort)sVar1 >> 8) & 1);
  daa((char)sVar1);
  sVar1 = (ushort)unaff_R5 + (ushort)unaff_R13 + (ushort)((byte)((ushort)sVar1 >> 8) & 1);
  daa((char)sVar1);
  sVar1 = (ushort)unaff_R6 + (ushort)unaff_R14 + (ushort)((byte)((ushort)sVar1 >> 8) & 1);
  daa((char)sVar1);
  daa((unaff_R7 + unaff_R15) - ((char)((char)((ushort)sVar1 >> 8) << 7) >> 7));
  return CONCAT11(uVar3,uVar2);
}

/**
 * @brief 8 字节 BCD 减法（多字节复用入口
 * @addr 0x1C330
 * @module bcd
 * @proto undefined2 decc_sub8_mb(byte r0, byte r1, byte r2, byte r3)
 * @confidence strong
 * @note 8 字节 BCD 减法（多字节复用入口：首字节 DAS 后 BC AL 跳入 0x1C33E 的 SUBC 链）。
 * @tag bcd
 */
undefined2 decc_sub8_mb(byte r0, byte r1, byte r2, byte r3)

{
  short sVar1;
  undefined uVar2;
  undefined uVar3;
  byte unaff_R4;
  byte unaff_R5;
  byte unaff_R6;
  char unaff_R7;
  byte unaff_R8;
  byte unaff_R9;
  byte unaff_R10;
  byte unaff_R11;
  byte unaff_R12;
  byte unaff_R13;
  byte unaff_R14;
  char unaff_R15;
  byte in_PSW;
  
  sVar1 = ((ushort)r0 - (ushort)unaff_R8) - (ushort)(in_PSW >> 7);
  uVar2 = das((char)sVar1);
  sVar1 = ((ushort)r1 - (ushort)unaff_R9) - (ushort)((byte)((ushort)sVar1 >> 8) & 1);
  uVar3 = das((char)sVar1);
  sVar1 = ((ushort)r2 - (ushort)unaff_R10) - (ushort)((byte)((ushort)sVar1 >> 8) & 1);
  das((char)sVar1);
  sVar1 = ((ushort)r3 - (ushort)unaff_R11) - (ushort)((byte)((ushort)sVar1 >> 8) & 1);
  das((char)sVar1);
  sVar1 = ((ushort)unaff_R4 - (ushort)unaff_R12) - (ushort)((byte)((ushort)sVar1 >> 8) & 1);
  das((char)sVar1);
  sVar1 = ((ushort)unaff_R5 - (ushort)unaff_R13) - (ushort)((byte)((ushort)sVar1 >> 8) & 1);
  das((char)sVar1);
  sVar1 = ((ushort)unaff_R6 - (ushort)unaff_R14) - (ushort)((byte)((ushort)sVar1 >> 8) & 1);
  das((char)sVar1);
  das((unaff_R7 - unaff_R15) + ((char)(in_PSW & 0xf | (char)((ushort)sVar1 >> 8) << 7) >> 7));
  return CONCAT11(uVar3,uVar2);
}

/**
 * @brief 8 字节 BCD 减法
 * @addr 0x1C338
 * @module bcd
 * @proto undefined2 decc_sub8(byte r0, byte r1, byte r2, byte r3)
 * @confidence verified
 * @note 8 字节 BCD 减法：SUB/SUBC + DAS 链。
 * @tag bcd
 */
undefined2 decc_sub8(byte r0, byte r1, byte r2, byte r3)

{
  short sVar1;
  undefined uVar2;
  undefined uVar3;
  byte unaff_R4;
  byte unaff_R5;
  byte unaff_R6;
  char unaff_R7;
  byte unaff_R8;
  byte unaff_R9;
  byte unaff_R10;
  byte unaff_R11;
  byte unaff_R12;
  byte unaff_R13;
  byte unaff_R14;
  char unaff_R15;
  
  uVar2 = das(r0 - unaff_R8);
  sVar1 = ((ushort)r1 - (ushort)unaff_R9) - (ushort)(r0 < unaff_R8);
  uVar3 = das((char)sVar1);
  sVar1 = ((ushort)r2 - (ushort)unaff_R10) - (ushort)((byte)((ushort)sVar1 >> 8) & 1);
  das((char)sVar1);
  sVar1 = ((ushort)r3 - (ushort)unaff_R11) - (ushort)((byte)((ushort)sVar1 >> 8) & 1);
  das((char)sVar1);
  sVar1 = ((ushort)unaff_R4 - (ushort)unaff_R12) - (ushort)((byte)((ushort)sVar1 >> 8) & 1);
  das((char)sVar1);
  sVar1 = ((ushort)unaff_R5 - (ushort)unaff_R13) - (ushort)((byte)((ushort)sVar1 >> 8) & 1);
  das((char)sVar1);
  sVar1 = ((ushort)unaff_R6 - (ushort)unaff_R14) - (ushort)((byte)((ushort)sVar1 >> 8) & 1);
  das((char)sVar1);
  das((unaff_R7 - unaff_R15) + ((char)((char)((ushort)sVar1 >> 8) << 7) >> 7));
  return CONCAT11(uVar3,uVar2);
}

/**
 * @brief 把 *p 的 10 字节 BCD 单元载入算数寄存器 0xD000..
 * @addr 0x1C35C
 * @module bcd
 * @proto void dec_load(undefined2* p)
 * @confidence verified
 * @note 把 *p 的 10 字节 BCD 单元载入算数寄存器 0xD000..。
 * @tag bcd
 */
int dec_load(undefined2* p)

{
  undefined2 *puVar1;
  undefined8 uVar2;
  
  puVar1 = (undefined2 *)dec_load_Y_from(p);
  uVar2 = *(undefined8 *)(puVar1 + 1);
  dec_accum0 = (short)((ulonglong)uVar2 >> 0x30);
  dec_accum1 = (char)((ulonglong)uVar2 >> 0x28);
  _DAT_ram_d003 = (char)((ulonglong)uVar2 >> 0x20);
  dec_accum2 = (char)((ulonglong)uVar2 >> 0x18);
  _DAT_ram_d005 = (char)((ulonglong)uVar2 >> 0x10);
  dec_accum3 = (char)((ulonglong)uVar2 >> 8);
  _DAT_ram_d007 = (char)uVar2;
  dec_accum4 = (char)((ushort)*puVar1 >> 8);
  dec_flags = (char)*puVar1;
  return 0;
}

/**
 * @brief 把 *p 载入算数寄存器 0xD000..0xD009
 * @addr 0x1C364
 * @module bcd
 * @proto void dec_load_regs(undefined2* p)
 * @confidence verified
 * @note 把 *p 载入算数寄存器 0xD000..0xD009。
 * @tag bcd
 */
int dec_load_regs(undefined2* p)

{
  undefined8 uVar1;
  
  uVar1 = *(undefined8 *)(p + 1);
  dec_accum0 = (short)((ulonglong)uVar1 >> 0x30);
  dec_accum1 = (char)((ulonglong)uVar1 >> 0x28);
  _DAT_ram_d003 = (char)((ulonglong)uVar1 >> 0x20);
  dec_accum2 = (char)((ulonglong)uVar1 >> 0x18);
  _DAT_ram_d005 = (char)((ulonglong)uVar1 >> 0x10);
  dec_accum3 = (char)((ulonglong)uVar1 >> 8);
  _DAT_ram_d007 = (char)uVar1;
  dec_accum4 = (char)((ushort)*p >> 8);
  dec_flags = (char)*p;
  return 0;
}

/**
 * @brief 从 p+1 的 9 字节载入 Y（0xD010 起）
 * @addr 0x1C384
 * @module bcd
 * @proto void dec_load_Y_from(byte* p)
 * @confidence verified
 * @note 从 p+1 的 9 字节载入 Y（0xD010 起）。
 * @tag bcd
 */
int dec_load_Y_from(byte* p)

{
  undefined8 uVar1;
  
  uVar1 = *(undefined8 *)(p + 1);
  dec_regY = (short)((ulonglong)uVar1 >> 0x30);
  dec_regY_mant = (char)((ulonglong)uVar1 >> 0x28);
  _DAT_ram_d013 = (char)((ulonglong)uVar1 >> 0x20);
  irq_pending_shadow = (char)((ulonglong)uVar1 >> 0x18);
  edit_state = (char)((ulonglong)uVar1 >> 0x10);
  display_dirty = (char)((ulonglong)uVar1 >> 8);
  _DAT_ram_d017 = (char)uVar1;
  dec_regY_tail = (char)((ushort)*p >> 8);
  dec_flags_Y = (char)*p;
  return 0;
}

/**
 * @brief 把算数寄存器（0xD000..）写回 *0xD05C 指定的 BCD 单元
 * @addr 0x1C392
 * @module bcd
 * @proto void dec_store(void)
 * @confidence verified
 * @note 把算数寄存器（0xD000..）写回 *0xD05C 指定的 BCD 单元。
 * @tag bcd
 */
int dec_store(void)

{
  undefined8 uVar1;
  undefined2 uVar2;
  undefined *puVar3;
  
  puVar3 = dec_param_a;
  uVar2 = dec_accum4;
  uVar1 = dec_accum0;
  *dec_param_a = (char)((ushort)dec_accum4 >> 8);
  puVar3[1] = (char)uVar2;
  puVar3[2] = (char)((ulonglong)uVar1 >> 0x38);
  puVar3[3] = (char)((ulonglong)uVar1 >> 0x30);
  puVar3[4] = (char)((ulonglong)uVar1 >> 0x28);
  puVar3[5] = (char)((ulonglong)uVar1 >> 0x20);
  puVar3[6] = (char)((ulonglong)uVar1 >> 0x18);
  puVar3[7] = (char)((ulonglong)uVar1 >> 0x10);
  *(short *)(puVar3 + 8) = (short)uVar1;
  return 0;
}

/**
 * @brief 把 X（0xD010 起）写回 _D05E 指向的输出缓冲
 * @addr 0x1C3B8
 * @module bcd
 * @proto void dec_store_result(void)
 * @confidence strong
 * @note 把 X（0xD010 起）写回 _D05E 指向的输出缓冲。
 * @tag bcd
 */
int dec_store_result(void)

{
  undefined8 uVar1;
  undefined2 uVar2;
  undefined *puVar3;
  
  puVar3 = dec_param_b;
  uVar2 = dec_regY_tail;
  uVar1 = dec_regY;
  *dec_param_b = (char)((ushort)dec_regY_tail >> 8);
  puVar3[1] = (char)uVar2;
  puVar3[2] = (char)((ulonglong)uVar1 >> 0x38);
  puVar3[3] = (char)((ulonglong)uVar1 >> 0x30);
  puVar3[4] = (char)((ulonglong)uVar1 >> 0x28);
  puVar3[5] = (char)((ulonglong)uVar1 >> 0x20);
  puVar3[6] = (char)((ulonglong)uVar1 >> 0x18);
  puVar3[7] = (char)((ulonglong)uVar1 >> 0x10);
  *(short *)(puVar3 + 8) = (short)uVar1;
  return 0;
}

/**
 * @brief 返回 0xD009 低 4 位（特殊值时 0）
 * @addr 0x1C3C8
 * @module bcd
 * @proto byte dec_status_low(void)
 * @confidence verified
 * @note 返回 0xD009 低 4 位（特殊值时 0）。
 * @tag bcd
 */
byte dec_status_low(void)

{
  byte bVar1;
  
  if ((char)((dec_flags < 0xf0) << 7) < '\0') {
    bVar1 = 0;
  }
  else {
    bVar1 = dec_flags & 0xf;
  }
  return bVar1;
}

/**
 * @brief 算术核心
 * @addr 0x1C3DA
 * @module bcd
 * @proto void dec_core_div(void)
 * @confidence likely
 * @note 算术核心：除法（6.1KB，0x1AB54 等调用 0x1C3DA）。
 * @tag bcd
 */
int dec_core_div(void)

{
  short sVar1;
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  undefined2 uVar5;
  undefined uVar8;
  byte bVar9;
  undefined uVar10;
  byte bVar11;
  undefined uVar12;
  byte bVar13;
  undefined uVar14;
  byte bVar15;
  undefined uVar16;
  undefined uVar17;
  ulonglong uVar6;
  ulonglong uVar7;
  undefined6 extraout_var;
  undefined6 extraout_var_00;
  undefined uVar18;
  byte bVar19;
  byte bVar20;
  undefined uVar22;
  byte bVar23;
  byte bVar24;
  byte *pbVar21;
  char cVar25;
  byte bVar26;
  char cVar27;
  byte bVar28;
  byte bVar29;
  byte bVar30;
  byte bVar31;
  
  if (0xef < dec_flags) {
    return 0;
  }
  if (0xef < dec_flags_Y) {
    dec_g_X_to_Y();
    return 0;
  }
  uVar8 = daa((char)(dec_accum0 >> 8) + '\x05');
  dec_accum0 = CONCAT11(uVar8,(char)dec_accum0) & 0xfff;
  uVar6 = CONCAT71((uint7)(byte)(dec_accum0 >> 8),1);
  _DAT_ram_d03b = '\x01';
  while (uVar3 = dec_tail_233((ushort)uVar6), uVar2 = dec_regY, uVar6 = dec_accum1,
        uVar4 = dec_accum0, (char)uVar3 != '\0') {
    dec_accum0 = dec_regY;
    dec_regY = uVar4;
    uVar7 = dec_accum1;
    dec_accum1 = dec_regY_mant;
    dec_regY_mant = uVar6;
    uVar6 = CONCAT71((int7)(uVar6 >> 8),dec_accum6);
    if (dec_accum6 != '\0') {
      uVar8 = daa((char)(uVar2 >> 8) + '\x05');
      dec_accum0 = CONCAT11(uVar8,(char)uVar2) & 0xfff;
      uVar6 = (ulonglong)dec_accum0;
    }
  }
  if (dec_accum6 != '\0') {
    uVar8 = das((char)dec_accum0 + -1);
    uVar22 = das((char)(dec_accum0 >> 8) - ((char)dec_accum0 == '\0'));
    uVar4 = CONCAT11(uVar22,uVar8) & 0xfff;
    uVar5 = dec_shift_left4((byte)dec_accum1,(byte)(dec_accum1 >> 8));
    dec_accum1 = CONCAT62(extraout_var,uVar5);
    dec_accum0 = uVar4;
  }
  bVar19 = das((byte)dec_accum0 - (byte)dec_regY);
  bVar23 = das(((char)(dec_accum0 >> 8) - (char)(dec_regY >> 8)) -
               ((byte)dec_accum0 < (byte)dec_regY));
  uVar4 = CONCAT11(bVar23,bVar19) & 0xfff;
  cVar25 = das(-0x67 - bVar19);
  cVar27 = ('\t' - (char)(uVar4 >> 8)) - (0x99 < bVar19);
  das(cVar27);
  if (((byte)(-0x67 - bVar19) == '\0' && cVar27 == '\0') && (cVar25 == '\0')) {
    uVar5 = dec_shift_left4((byte)dec_regY_mant,(byte)(dec_regY_mant >> 8));
    dec_regY_mant = CONCAT62(extraout_var_00,uVar5);
    bVar19 = 0;
  }
  else {
    cVar27 = (char)(((bVar23 & 0xf) * 0x100 + (ushort)bVar19) * 0x10 >> 8);
    if (cVar27 != '\0') {
      if (cVar27 != '\x01') goto LAB_rom_01c604;
      bVar19 = (char)uVar4 - 6;
    }
  }
  dec_accum7 = bVar19;
  dec_scale_xy();
  bVar20 = (byte)dec_regY_mant;
  bVar24 = (byte)(dec_regY_mant >> 8);
  bVar26 = (byte)(dec_regY_mant >> 0x10);
  bVar28 = (byte)(dec_regY_mant >> 0x18);
  bVar29 = (byte)(dec_regY_mant >> 0x20);
  bVar30 = (byte)(dec_regY_mant >> 0x28);
  bVar31 = (byte)(dec_regY_mant >> 0x30);
  cVar25 = (char)(dec_regY_mant >> 0x38);
  bVar19 = (byte)dec_accum1;
  bVar23 = (byte)(dec_accum1 >> 8);
  bVar9 = (byte)(dec_accum1 >> 0x10);
  bVar11 = (byte)(dec_accum1 >> 0x18);
  bVar13 = (byte)(dec_accum1 >> 0x20);
  bVar15 = (byte)(dec_accum1 >> 0x28);
  cVar27 = (char)(dec_accum1 >> 0x38);
  uVar4 = (ushort)(dec_accum1 >> 0x30);
  if (dec_accum6 == '\0') {
    uVar8 = daa(bVar19 + bVar20);
    sVar1 = (ushort)bVar23 + (ushort)bVar24 + (ushort)CARRY1(bVar19,bVar20);
    uVar22 = daa((char)sVar1);
    sVar1 = (ushort)bVar9 + (ushort)bVar26 + (ushort)((byte)((ushort)sVar1 >> 8) & 1);
    uVar10 = daa((char)sVar1);
    sVar1 = (ushort)bVar11 + (ushort)bVar28 + (ushort)((byte)((ushort)sVar1 >> 8) & 1);
    uVar12 = daa((char)sVar1);
    sVar1 = (ushort)bVar13 + (ushort)bVar29 + (ushort)((byte)((ushort)sVar1 >> 8) & 1);
    uVar14 = daa((char)sVar1);
    sVar1 = (ushort)bVar15 + (ushort)bVar30 + (ushort)((byte)((ushort)sVar1 >> 8) & 1);
    uVar16 = daa((char)sVar1);
    sVar1 = (uVar4 & 0xff) + (ushort)bVar31 + (ushort)((byte)((ushort)sVar1 >> 8) & 1);
    uVar17 = daa((char)sVar1);
    uVar18 = daa((cVar27 + cVar25) - ((char)((char)((ushort)sVar1 >> 8) << 7) >> 7));
    dec_accum1 =
         CONCAT17(uVar18,CONCAT16(uVar17,CONCAT15(uVar16,CONCAT14(uVar14,CONCAT13(uVar12,CONCAT12(
                                                  uVar10,CONCAT11(uVar22,uVar8)))))));
  }
  else {
    uVar8 = das(bVar19 - bVar20);
    sVar1 = ((ushort)bVar23 - (ushort)bVar24) - (ushort)(bVar19 < bVar20);
    uVar22 = das((char)sVar1);
    sVar1 = ((ushort)bVar9 - (ushort)bVar26) - (ushort)((byte)((ushort)sVar1 >> 8) & 1);
    uVar10 = das((char)sVar1);
    sVar1 = ((ushort)bVar11 - (ushort)bVar28) - (ushort)((byte)((ushort)sVar1 >> 8) & 1);
    uVar12 = das((char)sVar1);
    sVar1 = ((ushort)bVar13 - (ushort)bVar29) - (ushort)((byte)((ushort)sVar1 >> 8) & 1);
    uVar14 = das((char)sVar1);
    sVar1 = ((ushort)bVar15 - (ushort)bVar30) - (ushort)((byte)((ushort)sVar1 >> 8) & 1);
    uVar16 = das((char)sVar1);
    sVar1 = ((uVar4 & 0xff) - (ushort)bVar31) - (ushort)((byte)((ushort)sVar1 >> 8) & 1);
    uVar17 = das((char)sVar1);
    uVar18 = das((cVar27 - cVar25) + ((char)((char)((ushort)sVar1 >> 8) << 7) >> 7));
    dec_accum1 =
         CONCAT17(uVar18,CONCAT16(uVar17,CONCAT15(uVar16,CONCAT14(uVar14,CONCAT13(uVar12,CONCAT12(
                                                  uVar10,CONCAT11(uVar22,uVar8)))))));
    if (_DAT_ram_d03b == '\x01') {
      uVar6 = 0x800d009;
      while( true ) {
        pbVar21 = (byte *)uVar6;
        bVar23 = (byte)(uVar6 >> 0x10);
        bVar19 = bVar23;
        if ((0xe < *pbVar21) || (bVar19 = bVar23 + 1, *pbVar21 != 0)) break;
        bVar19 = bVar23 + 2;
        cVar27 = (char)(uVar6 >> 0x18) + -1;
        if (cVar27 == '\0') break;
        uVar6 = (ulonglong)
                CONCAT22((short)(CONCAT13(cVar27,CONCAT12(bVar19,pbVar21)) >> 0x10),pbVar21 + -1);
      }
      if (0xc < bVar19) {
        dec_accum1 = dec_accum1 & 0xffffffffffff0000;
        dec_ieee_norm();
        return 0;
      }
    }
  }
LAB_rom_01c604:
  dec_ieee_norm();
  return 0;
}

/**
 * @brief 置 Y = 10^0（Y 清零、0xD010=0x100 且 0xD018=0x100），并…
 * @addr 0x1C40A
 * @module bcd
 * @proto void dec_set_Y_1e0(void)
 * @confidence strong
 * @note 置 Y = 10^0（Y 清零、0xD010=0x100 且 0xD018=0x100），并调用 0x1C506 整理尾数。
 * @tag bcd
 */
int dec_set_Y_1e0(void)

{
  if (0xef < dec_flags) {
    return 0;
  }
  dec_regY = 0x100;
  dec_regY_mant = 0;
  irq_pending_shadow = 0;
  display_dirty = 0;
  dec_regY_tail = 0x100;
  dec_tail_round2();
  return 0;
}

/**
 * @brief 构造特殊常量（D010=0x600、D018=0x100）并调用 0x1C506
 * @addr 0x1C42C
 * @module bcd
 * @proto void dec_build_const(void)
 * @confidence likely
 * @note 构造特殊常量（D010=0x600、D018=0x100）并调用 0x1C506。
 * @tag bcd
 */
int dec_build_const(void)

{
  if (0xef < dec_flags) {
    return 0;
  }
  dec_regY = 0x600;
  dec_regY_mant = 0;
  irq_pending_shadow = 0;
  display_dirty = 0;
  dec_regY_tail = 0x100;
  dec_tail_round2();
  return 0;
}

/**
 * @brief 最终舍入
 * @addr 0x1C450
 * @module bcd
 * @proto void dec_round_final(void)
 * @confidence strong
 * @note 最终舍入：尾数加 5 并按 DAA 链规整（0x1AC2C/0x1AE22 使用）。
 * @tag bcd
 */
int dec_round_final(void)

{
  undefined uVar1;
  
  if (dec_flags < 0xf0) {
    if ((char)((dec_flags_Y < 0xf0) << 7) < '\0') {
      uVar1 = daa((char)(dec_accum0 >> 8) + '\x05');
      dec_accum0 = CONCAT11(uVar1,(char)dec_accum0) & 0xfff;
      dec_tail_round2();
      return 0;
    }
    dec_g_X_to_Y();
  }
  return 0;
}

/**
 * @brief 算术核心
 * @addr 0x1C478
 * @module bcd
 * @proto void dec_core_op9(void)
 * @confidence likely
 * @note 算术核心：运算档 9（6.1KB，0x1A15A 选择）。
 * @tag bcd
 */
int dec_core_op9(void)

{
  short sVar1;
  ushort uVar2;
  undefined2 uVar3;
  undefined uVar6;
  byte bVar7;
  undefined uVar8;
  ushort uVar9;
  byte bVar10;
  undefined uVar11;
  byte bVar12;
  undefined uVar13;
  byte bVar14;
  undefined uVar15;
  undefined uVar16;
  ulonglong uVar4;
  ulonglong uVar5;
  undefined6 extraout_var;
  undefined6 extraout_var_00;
  undefined uVar17;
  byte bVar18;
  byte bVar19;
  undefined uVar21;
  byte bVar22;
  byte bVar23;
  byte *pbVar20;
  char cVar24;
  byte bVar25;
  char cVar26;
  byte bVar27;
  byte bVar28;
  byte bVar29;
  byte bVar30;
  
  if (0xef < dec_flags) {
    return 0;
  }
  if (0xef < dec_flags_Y) {
    dec_g_X_to_Y();
    return 0;
  }
  uVar6 = daa((char)(dec_regY >> 8) + '\x05');
  dec_regY = CONCAT11(uVar6,(char)dec_regY) & 0xfff;
  uVar4 = CONCAT71((uint7)(byte)(dec_regY >> 8),1);
  _DAT_ram_d03b = '\x01';
  while (uVar2 = dec_tail_233((ushort)uVar4), uVar9 = dec_regY, uVar4 = dec_accum1,
        (char)uVar2 != '\0') {
    dec_regY = dec_accum0;
    uVar5 = dec_accum1;
    dec_accum1 = dec_regY_mant;
    dec_regY_mant = uVar4;
    uVar4 = CONCAT71((int7)(uVar4 >> 8),dec_accum6);
    dec_accum0 = uVar9;
    if (dec_accum6 != '\0') {
      uVar6 = daa((char)(uVar9 >> 8) + '\x05');
      dec_accum0 = CONCAT11(uVar6,(char)uVar9) & 0xfff;
      uVar4 = (ulonglong)dec_accum0;
    }
  }
  if (dec_accum6 != '\0') {
    uVar6 = das((char)dec_accum0 + -1);
    uVar21 = das((char)(dec_accum0 >> 8) - ((char)dec_accum0 == '\0'));
    uVar9 = CONCAT11(uVar21,uVar6) & 0xfff;
    uVar3 = dec_shift_left4((byte)dec_accum1,(byte)(dec_accum1 >> 8));
    dec_accum1 = CONCAT62(extraout_var,uVar3);
    dec_accum0 = uVar9;
  }
  bVar18 = das((byte)dec_accum0 - (byte)dec_regY);
  bVar22 = das(((char)(dec_accum0 >> 8) - (char)(dec_regY >> 8)) -
               ((byte)dec_accum0 < (byte)dec_regY));
  uVar9 = CONCAT11(bVar22,bVar18) & 0xfff;
  cVar24 = das(-0x67 - bVar18);
  cVar26 = ('\t' - (char)(uVar9 >> 8)) - (0x99 < bVar18);
  das(cVar26);
  if (((byte)(-0x67 - bVar18) == '\0' && cVar26 == '\0') && (cVar24 == '\0')) {
    uVar3 = dec_shift_left4((byte)dec_regY_mant,(byte)(dec_regY_mant >> 8));
    dec_regY_mant = CONCAT62(extraout_var_00,uVar3);
    bVar18 = 0;
  }
  else {
    cVar26 = (char)(((bVar22 & 0xf) * 0x100 + (ushort)bVar18) * 0x10 >> 8);
    if (cVar26 != '\0') {
      if (cVar26 != '\x01') goto LAB_rom_01c604;
      bVar18 = (char)uVar9 - 6;
    }
  }
  dec_accum7 = bVar18;
  dec_scale_xy();
  bVar19 = (byte)dec_regY_mant;
  bVar23 = (byte)(dec_regY_mant >> 8);
  bVar25 = (byte)(dec_regY_mant >> 0x10);
  bVar27 = (byte)(dec_regY_mant >> 0x18);
  bVar28 = (byte)(dec_regY_mant >> 0x20);
  bVar29 = (byte)(dec_regY_mant >> 0x28);
  bVar30 = (byte)(dec_regY_mant >> 0x30);
  cVar24 = (char)(dec_regY_mant >> 0x38);
  bVar18 = (byte)dec_accum1;
  bVar22 = (byte)(dec_accum1 >> 8);
  bVar7 = (byte)(dec_accum1 >> 0x10);
  bVar10 = (byte)(dec_accum1 >> 0x18);
  bVar12 = (byte)(dec_accum1 >> 0x20);
  bVar14 = (byte)(dec_accum1 >> 0x28);
  cVar26 = (char)(dec_accum1 >> 0x38);
  uVar9 = (ushort)(dec_accum1 >> 0x30);
  if (dec_accum6 == '\0') {
    uVar6 = daa(bVar18 + bVar19);
    sVar1 = (ushort)bVar22 + (ushort)bVar23 + (ushort)CARRY1(bVar18,bVar19);
    uVar21 = daa((char)sVar1);
    sVar1 = (ushort)bVar7 + (ushort)bVar25 + (ushort)((byte)((ushort)sVar1 >> 8) & 1);
    uVar8 = daa((char)sVar1);
    sVar1 = (ushort)bVar10 + (ushort)bVar27 + (ushort)((byte)((ushort)sVar1 >> 8) & 1);
    uVar11 = daa((char)sVar1);
    sVar1 = (ushort)bVar12 + (ushort)bVar28 + (ushort)((byte)((ushort)sVar1 >> 8) & 1);
    uVar13 = daa((char)sVar1);
    sVar1 = (ushort)bVar14 + (ushort)bVar29 + (ushort)((byte)((ushort)sVar1 >> 8) & 1);
    uVar15 = daa((char)sVar1);
    sVar1 = (uVar9 & 0xff) + (ushort)bVar30 + (ushort)((byte)((ushort)sVar1 >> 8) & 1);
    uVar16 = daa((char)sVar1);
    uVar17 = daa((cVar26 + cVar24) - ((char)((char)((ushort)sVar1 >> 8) << 7) >> 7));
    dec_accum1 =
         CONCAT17(uVar17,CONCAT16(uVar16,CONCAT15(uVar15,CONCAT14(uVar13,CONCAT13(uVar11,CONCAT12(
                                                  uVar8,CONCAT11(uVar21,uVar6)))))));
  }
  else {
    uVar6 = das(bVar18 - bVar19);
    sVar1 = ((ushort)bVar22 - (ushort)bVar23) - (ushort)(bVar18 < bVar19);
    uVar21 = das((char)sVar1);
    sVar1 = ((ushort)bVar7 - (ushort)bVar25) - (ushort)((byte)((ushort)sVar1 >> 8) & 1);
    uVar8 = das((char)sVar1);
    sVar1 = ((ushort)bVar10 - (ushort)bVar27) - (ushort)((byte)((ushort)sVar1 >> 8) & 1);
    uVar11 = das((char)sVar1);
    sVar1 = ((ushort)bVar12 - (ushort)bVar28) - (ushort)((byte)((ushort)sVar1 >> 8) & 1);
    uVar13 = das((char)sVar1);
    sVar1 = ((ushort)bVar14 - (ushort)bVar29) - (ushort)((byte)((ushort)sVar1 >> 8) & 1);
    uVar15 = das((char)sVar1);
    sVar1 = ((uVar9 & 0xff) - (ushort)bVar30) - (ushort)((byte)((ushort)sVar1 >> 8) & 1);
    uVar16 = das((char)sVar1);
    uVar17 = das((cVar26 - cVar24) + ((char)((char)((ushort)sVar1 >> 8) << 7) >> 7));
    dec_accum1 =
         CONCAT17(uVar17,CONCAT16(uVar16,CONCAT15(uVar15,CONCAT14(uVar13,CONCAT13(uVar11,CONCAT12(
                                                  uVar8,CONCAT11(uVar21,uVar6)))))));
    if (_DAT_ram_d03b == '\x01') {
      uVar4 = 0x800d009;
      while( true ) {
        pbVar20 = (byte *)uVar4;
        bVar22 = (byte)(uVar4 >> 0x10);
        bVar18 = bVar22;
        if ((0xe < *pbVar20) || (bVar18 = bVar22 + 1, *pbVar20 != 0)) break;
        bVar18 = bVar22 + 2;
        cVar26 = (char)(uVar4 >> 0x18) + -1;
        if (cVar26 == '\0') break;
        uVar4 = (ulonglong)
                CONCAT22((short)(CONCAT13(cVar26,CONCAT12(bVar18,pbVar20)) >> 0x10),pbVar20 + -1);
      }
      if (0xc < bVar18) {
        dec_accum1 = dec_accum1 & 0xffffffffffff0000;
        dec_ieee_norm();
        return 0;
      }
    }
  }
LAB_rom_01c604:
  dec_ieee_norm();
  return 0;
}

/**
 * @brief 算术核心
 * @addr 0x1C4A6
 * @module bcd
 * @proto void dec_core_op8(void)
 * @confidence likely
 * @note 算术核心：运算档 8（6.0KB，0x1A15A 选择）。
 * @tag bcd
 */
int dec_core_op8(void)

{
  short sVar1;
  ushort uVar2;
  undefined uVar6;
  undefined2 uVar3;
  byte bVar7;
  undefined uVar8;
  ushort uVar9;
  byte bVar10;
  undefined uVar11;
  byte bVar12;
  undefined uVar13;
  byte bVar14;
  undefined uVar15;
  undefined uVar16;
  undefined8 in_QR0;
  ulonglong uVar4;
  ulonglong uVar5;
  undefined6 extraout_var;
  undefined6 extraout_var_00;
  undefined uVar17;
  byte bVar18;
  byte bVar19;
  undefined uVar21;
  byte bVar22;
  byte bVar23;
  byte *pbVar20;
  char cVar24;
  byte bVar25;
  char cVar26;
  byte bVar27;
  byte bVar28;
  byte bVar29;
  byte bVar30;
  
  if (0xef < dec_flags) {
    return 0;
  }
  if (0xef < dec_flags_Y) {
    dec_g_X_to_Y();
    return 0;
  }
  uVar4 = CONCAT71((int7)((ulonglong)in_QR0 >> 8),1);
  _DAT_ram_d03b = '\x01';
  while (uVar2 = dec_tail_233((ushort)uVar4), uVar9 = dec_regY, uVar4 = dec_accum1,
        (char)uVar2 != '\0') {
    uVar2 = dec_accum0;
    dec_regY = dec_accum0;
    uVar5 = dec_accum1;
    dec_accum1 = dec_regY_mant;
    dec_regY_mant = uVar4;
    uVar4 = CONCAT71((int7)(uVar4 >> 8),dec_accum6);
    dec_accum0 = uVar9;
    if (dec_accum6 != '\0') {
      uVar6 = daa((char)(uVar9 >> 8) + '\x05');
      dec_accum0 = CONCAT11(uVar6,(char)uVar9) & 0xfff;
      uVar4 = (ulonglong)dec_accum0;
    }
  }
  if (dec_accum6 != '\0') {
    uVar6 = das((char)dec_accum0 + -1);
    uVar21 = das((char)(dec_accum0 >> 8) - ((char)dec_accum0 == '\0'));
    uVar9 = CONCAT11(uVar21,uVar6) & 0xfff;
    uVar3 = dec_shift_left4((byte)dec_accum1,(byte)(dec_accum1 >> 8));
    dec_accum1 = CONCAT62(extraout_var,uVar3);
    dec_accum0 = uVar9;
  }
  bVar18 = das((byte)dec_accum0 - (byte)dec_regY);
  bVar22 = das(((char)(dec_accum0 >> 8) - (char)(dec_regY >> 8)) -
               ((byte)dec_accum0 < (byte)dec_regY));
  uVar9 = CONCAT11(bVar22,bVar18) & 0xfff;
  cVar24 = das(-0x67 - bVar18);
  cVar26 = ('\t' - (char)(uVar9 >> 8)) - (0x99 < bVar18);
  das(cVar26);
  if (((byte)(-0x67 - bVar18) == '\0' && cVar26 == '\0') && (cVar24 == '\0')) {
    uVar3 = dec_shift_left4((byte)dec_regY_mant,(byte)(dec_regY_mant >> 8));
    dec_regY_mant = CONCAT62(extraout_var_00,uVar3);
    bVar18 = 0;
  }
  else {
    cVar26 = (char)(((bVar22 & 0xf) * 0x100 + (ushort)bVar18) * 0x10 >> 8);
    if (cVar26 != '\0') {
      if (cVar26 != '\x01') goto LAB_rom_01c604;
      bVar18 = (char)uVar9 - 6;
    }
  }
  dec_accum7 = bVar18;
  dec_scale_xy();
  bVar19 = (byte)dec_regY_mant;
  bVar23 = (byte)(dec_regY_mant >> 8);
  bVar25 = (byte)(dec_regY_mant >> 0x10);
  bVar27 = (byte)(dec_regY_mant >> 0x18);
  bVar28 = (byte)(dec_regY_mant >> 0x20);
  bVar29 = (byte)(dec_regY_mant >> 0x28);
  bVar30 = (byte)(dec_regY_mant >> 0x30);
  cVar24 = (char)(dec_regY_mant >> 0x38);
  bVar18 = (byte)dec_accum1;
  bVar22 = (byte)(dec_accum1 >> 8);
  bVar7 = (byte)(dec_accum1 >> 0x10);
  bVar10 = (byte)(dec_accum1 >> 0x18);
  bVar12 = (byte)(dec_accum1 >> 0x20);
  bVar14 = (byte)(dec_accum1 >> 0x28);
  cVar26 = (char)(dec_accum1 >> 0x38);
  uVar9 = (ushort)(dec_accum1 >> 0x30);
  if (dec_accum6 == '\0') {
    uVar6 = daa(bVar18 + bVar19);
    sVar1 = (ushort)bVar22 + (ushort)bVar23 + (ushort)CARRY1(bVar18,bVar19);
    uVar21 = daa((char)sVar1);
    sVar1 = (ushort)bVar7 + (ushort)bVar25 + (ushort)((byte)((ushort)sVar1 >> 8) & 1);
    uVar8 = daa((char)sVar1);
    sVar1 = (ushort)bVar10 + (ushort)bVar27 + (ushort)((byte)((ushort)sVar1 >> 8) & 1);
    uVar11 = daa((char)sVar1);
    sVar1 = (ushort)bVar12 + (ushort)bVar28 + (ushort)((byte)((ushort)sVar1 >> 8) & 1);
    uVar13 = daa((char)sVar1);
    sVar1 = (ushort)bVar14 + (ushort)bVar29 + (ushort)((byte)((ushort)sVar1 >> 8) & 1);
    uVar15 = daa((char)sVar1);
    sVar1 = (uVar9 & 0xff) + (ushort)bVar30 + (ushort)((byte)((ushort)sVar1 >> 8) & 1);
    uVar16 = daa((char)sVar1);
    uVar17 = daa((cVar26 + cVar24) - ((char)((char)((ushort)sVar1 >> 8) << 7) >> 7));
    dec_accum1 =
         CONCAT17(uVar17,CONCAT16(uVar16,CONCAT15(uVar15,CONCAT14(uVar13,CONCAT13(uVar11,CONCAT12(
                                                  uVar8,CONCAT11(uVar21,uVar6)))))));
  }
  else {
    uVar6 = das(bVar18 - bVar19);
    sVar1 = ((ushort)bVar22 - (ushort)bVar23) - (ushort)(bVar18 < bVar19);
    uVar21 = das((char)sVar1);
    sVar1 = ((ushort)bVar7 - (ushort)bVar25) - (ushort)((byte)((ushort)sVar1 >> 8) & 1);
    uVar8 = das((char)sVar1);
    sVar1 = ((ushort)bVar10 - (ushort)bVar27) - (ushort)((byte)((ushort)sVar1 >> 8) & 1);
    uVar11 = das((char)sVar1);
    sVar1 = ((ushort)bVar12 - (ushort)bVar28) - (ushort)((byte)((ushort)sVar1 >> 8) & 1);
    uVar13 = das((char)sVar1);
    sVar1 = ((ushort)bVar14 - (ushort)bVar29) - (ushort)((byte)((ushort)sVar1 >> 8) & 1);
    uVar15 = das((char)sVar1);
    sVar1 = ((uVar9 & 0xff) - (ushort)bVar30) - (ushort)((byte)((ushort)sVar1 >> 8) & 1);
    uVar16 = das((char)sVar1);
    uVar17 = das((cVar26 - cVar24) + ((char)((char)((ushort)sVar1 >> 8) << 7) >> 7));
    dec_accum1 =
         CONCAT17(uVar17,CONCAT16(uVar16,CONCAT15(uVar15,CONCAT14(uVar13,CONCAT13(uVar11,CONCAT12(
                                                  uVar8,CONCAT11(uVar21,uVar6)))))));
    if (_DAT_ram_d03b == '\x01') {
      uVar4 = 0x800d009;
      while( true ) {
        pbVar20 = (byte *)uVar4;
        bVar22 = (byte)(uVar4 >> 0x10);
        bVar18 = bVar22;
        if ((0xe < *pbVar20) || (bVar18 = bVar22 + 1, *pbVar20 != 0)) break;
        bVar18 = bVar22 + 2;
        cVar26 = (char)(uVar4 >> 0x18) + -1;
        if (cVar26 == '\0') break;
        uVar4 = (ulonglong)
                CONCAT22((short)(CONCAT13(cVar26,CONCAT12(bVar18,pbVar20)) >> 0x10),pbVar20 + -1);
      }
      if (0xc < bVar18) {
        dec_accum1 = dec_accum1 & 0xffffffffffff0000;
        dec_ieee_norm();
        return 0;
      }
    }
  }
LAB_rom_01c604:
  dec_ieee_norm();
  return 0;
}

/**
 * @brief 按精度设置（0xD00A）截断尾数并舍入（FUN 0x1C7C8 系列）
 * @addr 0x1C4EE
 * @module bcd
 * @proto void dec_tail_round(void)
 * @confidence likely
 * @note 按精度设置（0xD00A）截断尾数并舍入（FUN 0x1C7C8 系列）。
 * @tag bcd
 */
int dec_tail_round(void)

{
  short sVar1;
  ushort uVar2;
  undefined uVar6;
  undefined2 uVar3;
  byte bVar7;
  undefined uVar8;
  ushort uVar9;
  byte bVar10;
  undefined uVar11;
  byte bVar12;
  undefined uVar13;
  byte bVar14;
  undefined uVar15;
  undefined uVar16;
  ulonglong in_QR0;
  ulonglong uVar4;
  ulonglong uVar5;
  undefined6 extraout_var;
  undefined6 extraout_var_00;
  undefined uVar17;
  byte bVar18;
  byte bVar19;
  undefined uVar21;
  byte bVar22;
  byte bVar23;
  byte *pbVar20;
  char cVar24;
  byte bVar25;
  char cVar26;
  byte bVar27;
  byte bVar28;
  byte bVar29;
  byte bVar30;
  
  if (0xef < dec_flags) {
    return 0;
  }
  if (0xef < dec_flags_Y) {
    dec_g_X_to_Y();
    return 0;
  }
  uVar4 = in_QR0 & 0xffffffffffffff00;
  _DAT_ram_d03b = '\0';
  while (uVar2 = dec_tail_233((ushort)uVar4), uVar9 = dec_regY, uVar4 = dec_accum1,
        (char)uVar2 != '\0') {
    uVar2 = dec_accum0;
    dec_regY = dec_accum0;
    uVar5 = dec_accum1;
    dec_accum1 = dec_regY_mant;
    dec_regY_mant = uVar4;
    uVar4 = CONCAT71((int7)(uVar4 >> 8),dec_accum6);
    dec_accum0 = uVar9;
    if (dec_accum6 != '\0') {
      uVar6 = daa((char)(uVar9 >> 8) + '\x05');
      dec_accum0 = CONCAT11(uVar6,(char)uVar9) & 0xfff;
      uVar4 = (ulonglong)dec_accum0;
    }
  }
  if (dec_accum6 != '\0') {
    uVar6 = das((char)dec_accum0 + -1);
    uVar21 = das((char)(dec_accum0 >> 8) - ((char)dec_accum0 == '\0'));
    uVar9 = CONCAT11(uVar21,uVar6) & 0xfff;
    uVar3 = dec_shift_left4((byte)dec_accum1,(byte)(dec_accum1 >> 8));
    dec_accum1 = CONCAT62(extraout_var,uVar3);
    dec_accum0 = uVar9;
  }
  bVar18 = das((byte)dec_accum0 - (byte)dec_regY);
  bVar22 = das(((char)(dec_accum0 >> 8) - (char)(dec_regY >> 8)) -
               ((byte)dec_accum0 < (byte)dec_regY));
  uVar9 = CONCAT11(bVar22,bVar18) & 0xfff;
  cVar24 = das(-0x67 - bVar18);
  cVar26 = ('\t' - (char)(uVar9 >> 8)) - (0x99 < bVar18);
  das(cVar26);
  if (((byte)(-0x67 - bVar18) == '\0' && cVar26 == '\0') && (cVar24 == '\0')) {
    uVar3 = dec_shift_left4((byte)dec_regY_mant,(byte)(dec_regY_mant >> 8));
    dec_regY_mant = CONCAT62(extraout_var_00,uVar3);
    bVar18 = 0;
  }
  else {
    cVar26 = (char)(((bVar22 & 0xf) * 0x100 + (ushort)bVar18) * 0x10 >> 8);
    if (cVar26 != '\0') {
      if (cVar26 != '\x01') goto LAB_rom_01c604;
      bVar18 = (char)uVar9 - 6;
    }
  }
  dec_accum7 = bVar18;
  dec_scale_xy();
  bVar19 = (byte)dec_regY_mant;
  bVar23 = (byte)(dec_regY_mant >> 8);
  bVar25 = (byte)(dec_regY_mant >> 0x10);
  bVar27 = (byte)(dec_regY_mant >> 0x18);
  bVar28 = (byte)(dec_regY_mant >> 0x20);
  bVar29 = (byte)(dec_regY_mant >> 0x28);
  bVar30 = (byte)(dec_regY_mant >> 0x30);
  cVar24 = (char)(dec_regY_mant >> 0x38);
  bVar18 = (byte)dec_accum1;
  bVar22 = (byte)(dec_accum1 >> 8);
  bVar7 = (byte)(dec_accum1 >> 0x10);
  bVar10 = (byte)(dec_accum1 >> 0x18);
  bVar12 = (byte)(dec_accum1 >> 0x20);
  bVar14 = (byte)(dec_accum1 >> 0x28);
  cVar26 = (char)(dec_accum1 >> 0x38);
  uVar9 = (ushort)(dec_accum1 >> 0x30);
  if (dec_accum6 == '\0') {
    uVar6 = daa(bVar18 + bVar19);
    sVar1 = (ushort)bVar22 + (ushort)bVar23 + (ushort)CARRY1(bVar18,bVar19);
    uVar21 = daa((char)sVar1);
    sVar1 = (ushort)bVar7 + (ushort)bVar25 + (ushort)((byte)((ushort)sVar1 >> 8) & 1);
    uVar8 = daa((char)sVar1);
    sVar1 = (ushort)bVar10 + (ushort)bVar27 + (ushort)((byte)((ushort)sVar1 >> 8) & 1);
    uVar11 = daa((char)sVar1);
    sVar1 = (ushort)bVar12 + (ushort)bVar28 + (ushort)((byte)((ushort)sVar1 >> 8) & 1);
    uVar13 = daa((char)sVar1);
    sVar1 = (ushort)bVar14 + (ushort)bVar29 + (ushort)((byte)((ushort)sVar1 >> 8) & 1);
    uVar15 = daa((char)sVar1);
    sVar1 = (uVar9 & 0xff) + (ushort)bVar30 + (ushort)((byte)((ushort)sVar1 >> 8) & 1);
    uVar16 = daa((char)sVar1);
    uVar17 = daa((cVar26 + cVar24) - ((char)((char)((ushort)sVar1 >> 8) << 7) >> 7));
    dec_accum1 =
         CONCAT17(uVar17,CONCAT16(uVar16,CONCAT15(uVar15,CONCAT14(uVar13,CONCAT13(uVar11,CONCAT12(
                                                  uVar8,CONCAT11(uVar21,uVar6)))))));
  }
  else {
    uVar6 = das(bVar18 - bVar19);
    sVar1 = ((ushort)bVar22 - (ushort)bVar23) - (ushort)(bVar18 < bVar19);
    uVar21 = das((char)sVar1);
    sVar1 = ((ushort)bVar7 - (ushort)bVar25) - (ushort)((byte)((ushort)sVar1 >> 8) & 1);
    uVar8 = das((char)sVar1);
    sVar1 = ((ushort)bVar10 - (ushort)bVar27) - (ushort)((byte)((ushort)sVar1 >> 8) & 1);
    uVar11 = das((char)sVar1);
    sVar1 = ((ushort)bVar12 - (ushort)bVar28) - (ushort)((byte)((ushort)sVar1 >> 8) & 1);
    uVar13 = das((char)sVar1);
    sVar1 = ((ushort)bVar14 - (ushort)bVar29) - (ushort)((byte)((ushort)sVar1 >> 8) & 1);
    uVar15 = das((char)sVar1);
    sVar1 = ((uVar9 & 0xff) - (ushort)bVar30) - (ushort)((byte)((ushort)sVar1 >> 8) & 1);
    uVar16 = das((char)sVar1);
    uVar17 = das((cVar26 - cVar24) + ((char)((char)((ushort)sVar1 >> 8) << 7) >> 7));
    dec_accum1 =
         CONCAT17(uVar17,CONCAT16(uVar16,CONCAT15(uVar15,CONCAT14(uVar13,CONCAT13(uVar11,CONCAT12(
                                                  uVar8,CONCAT11(uVar21,uVar6)))))));
    if (_DAT_ram_d03b == '\x01') {
      uVar4 = 0x800d009;
      while( true ) {
        pbVar20 = (byte *)uVar4;
        bVar22 = (byte)(uVar4 >> 0x10);
        bVar18 = bVar22;
        if ((0xe < *pbVar20) || (bVar18 = bVar22 + 1, *pbVar20 != 0)) break;
        bVar18 = bVar22 + 2;
        cVar26 = (char)(uVar4 >> 0x18) + -1;
        if (cVar26 == '\0') break;
        uVar4 = (ulonglong)
                CONCAT22((short)(CONCAT13(cVar26,CONCAT12(bVar18,pbVar20)) >> 0x10),pbVar20 + -1);
      }
      if (0xc < bVar18) {
        dec_accum1 = dec_accum1 & 0xffffffffffff0000;
        dec_ieee_norm();
        return 0;
      }
    }
  }
LAB_rom_01c604:
  dec_ieee_norm();
  return 0;
}

/**
 * @brief 尾数截断/舍入的变体（不同精度路径）
 * @addr 0x1C506
 * @module bcd
 * @proto void dec_tail_round2(void)
 * @confidence likely
 * @note 尾数截断/舍入的变体（不同精度路径）。
 * @tag bcd
 */
int dec_tail_round2(void)

{
  short sVar1;
  ushort uVar2;
  undefined uVar6;
  undefined2 uVar3;
  byte bVar7;
  undefined uVar8;
  ushort uVar9;
  byte bVar10;
  undefined uVar11;
  byte bVar12;
  undefined uVar13;
  byte bVar14;
  undefined uVar15;
  undefined uVar16;
  ulonglong in_QR0;
  ulonglong uVar4;
  ulonglong uVar5;
  undefined6 extraout_var;
  undefined6 extraout_var_00;
  undefined uVar17;
  byte bVar18;
  byte bVar19;
  undefined uVar21;
  byte bVar22;
  byte bVar23;
  byte *pbVar20;
  char cVar24;
  byte bVar25;
  char cVar26;
  byte bVar27;
  byte bVar28;
  byte bVar29;
  byte bVar30;
  
  uVar4 = in_QR0 & 0xffffffffffffff00;
  _DAT_ram_d03b = '\0';
  while (uVar2 = dec_tail_233((ushort)uVar4), uVar9 = dec_regY, uVar4 = dec_accum1,
        (char)uVar2 != '\0') {
    uVar2 = dec_accum0;
    dec_regY = dec_accum0;
    uVar5 = dec_accum1;
    dec_accum1 = dec_regY_mant;
    dec_regY_mant = uVar4;
    uVar4 = CONCAT71((int7)(uVar4 >> 8),dec_accum6);
    dec_accum0 = uVar9;
    if (dec_accum6 != '\0') {
      uVar6 = daa((char)(uVar9 >> 8) + '\x05');
      dec_accum0 = CONCAT11(uVar6,(char)uVar9) & 0xfff;
      uVar4 = (ulonglong)dec_accum0;
    }
  }
  if (dec_accum6 != '\0') {
    uVar6 = das((char)dec_accum0 + -1);
    uVar21 = das((char)(dec_accum0 >> 8) - ((char)dec_accum0 == '\0'));
    uVar9 = CONCAT11(uVar21,uVar6) & 0xfff;
    uVar3 = dec_shift_left4((byte)dec_accum1,(byte)(dec_accum1 >> 8));
    dec_accum1 = CONCAT62(extraout_var,uVar3);
    dec_accum0 = uVar9;
  }
  bVar18 = das((byte)dec_accum0 - (byte)dec_regY);
  bVar22 = das(((char)(dec_accum0 >> 8) - (char)(dec_regY >> 8)) -
               ((byte)dec_accum0 < (byte)dec_regY));
  uVar9 = CONCAT11(bVar22,bVar18) & 0xfff;
  cVar24 = das(-0x67 - bVar18);
  cVar26 = ('\t' - (char)(uVar9 >> 8)) - (0x99 < bVar18);
  das(cVar26);
  if (((byte)(-0x67 - bVar18) == '\0' && cVar26 == '\0') && (cVar24 == '\0')) {
    uVar3 = dec_shift_left4((byte)dec_regY_mant,(byte)(dec_regY_mant >> 8));
    dec_regY_mant = CONCAT62(extraout_var_00,uVar3);
    bVar18 = 0;
  }
  else {
    cVar26 = (char)(((bVar22 & 0xf) * 0x100 + (ushort)bVar18) * 0x10 >> 8);
    if (cVar26 != '\0') {
      if (cVar26 != '\x01') goto LAB_rom_01c604;
      bVar18 = (char)uVar9 - 6;
    }
  }
  dec_accum7 = bVar18;
  dec_scale_xy();
  bVar19 = (byte)dec_regY_mant;
  bVar23 = (byte)(dec_regY_mant >> 8);
  bVar25 = (byte)(dec_regY_mant >> 0x10);
  bVar27 = (byte)(dec_regY_mant >> 0x18);
  bVar28 = (byte)(dec_regY_mant >> 0x20);
  bVar29 = (byte)(dec_regY_mant >> 0x28);
  bVar30 = (byte)(dec_regY_mant >> 0x30);
  cVar24 = (char)(dec_regY_mant >> 0x38);
  bVar18 = (byte)dec_accum1;
  bVar22 = (byte)(dec_accum1 >> 8);
  bVar7 = (byte)(dec_accum1 >> 0x10);
  bVar10 = (byte)(dec_accum1 >> 0x18);
  bVar12 = (byte)(dec_accum1 >> 0x20);
  bVar14 = (byte)(dec_accum1 >> 0x28);
  cVar26 = (char)(dec_accum1 >> 0x38);
  uVar9 = (ushort)(dec_accum1 >> 0x30);
  if (dec_accum6 == '\0') {
    uVar6 = daa(bVar18 + bVar19);
    sVar1 = (ushort)bVar22 + (ushort)bVar23 + (ushort)CARRY1(bVar18,bVar19);
    uVar21 = daa((char)sVar1);
    sVar1 = (ushort)bVar7 + (ushort)bVar25 + (ushort)((byte)((ushort)sVar1 >> 8) & 1);
    uVar8 = daa((char)sVar1);
    sVar1 = (ushort)bVar10 + (ushort)bVar27 + (ushort)((byte)((ushort)sVar1 >> 8) & 1);
    uVar11 = daa((char)sVar1);
    sVar1 = (ushort)bVar12 + (ushort)bVar28 + (ushort)((byte)((ushort)sVar1 >> 8) & 1);
    uVar13 = daa((char)sVar1);
    sVar1 = (ushort)bVar14 + (ushort)bVar29 + (ushort)((byte)((ushort)sVar1 >> 8) & 1);
    uVar15 = daa((char)sVar1);
    sVar1 = (uVar9 & 0xff) + (ushort)bVar30 + (ushort)((byte)((ushort)sVar1 >> 8) & 1);
    uVar16 = daa((char)sVar1);
    uVar17 = daa((cVar26 + cVar24) - ((char)((char)((ushort)sVar1 >> 8) << 7) >> 7));
    dec_accum1 =
         CONCAT17(uVar17,CONCAT16(uVar16,CONCAT15(uVar15,CONCAT14(uVar13,CONCAT13(uVar11,CONCAT12(
                                                  uVar8,CONCAT11(uVar21,uVar6)))))));
  }
  else {
    uVar6 = das(bVar18 - bVar19);
    sVar1 = ((ushort)bVar22 - (ushort)bVar23) - (ushort)(bVar18 < bVar19);
    uVar21 = das((char)sVar1);
    sVar1 = ((ushort)bVar7 - (ushort)bVar25) - (ushort)((byte)((ushort)sVar1 >> 8) & 1);
    uVar8 = das((char)sVar1);
    sVar1 = ((ushort)bVar10 - (ushort)bVar27) - (ushort)((byte)((ushort)sVar1 >> 8) & 1);
    uVar11 = das((char)sVar1);
    sVar1 = ((ushort)bVar12 - (ushort)bVar28) - (ushort)((byte)((ushort)sVar1 >> 8) & 1);
    uVar13 = das((char)sVar1);
    sVar1 = ((ushort)bVar14 - (ushort)bVar29) - (ushort)((byte)((ushort)sVar1 >> 8) & 1);
    uVar15 = das((char)sVar1);
    sVar1 = ((uVar9 & 0xff) - (ushort)bVar30) - (ushort)((byte)((ushort)sVar1 >> 8) & 1);
    uVar16 = das((char)sVar1);
    uVar17 = das((cVar26 - cVar24) + ((char)((char)((ushort)sVar1 >> 8) << 7) >> 7));
    dec_accum1 =
         CONCAT17(uVar17,CONCAT16(uVar16,CONCAT15(uVar15,CONCAT14(uVar13,CONCAT13(uVar11,CONCAT12(
                                                  uVar8,CONCAT11(uVar21,uVar6)))))));
    if (_DAT_ram_d03b == '\x01') {
      uVar4 = 0x800d009;
      while( true ) {
        pbVar20 = (byte *)uVar4;
        bVar22 = (byte)(uVar4 >> 0x10);
        bVar18 = bVar22;
        if ((0xe < *pbVar20) || (bVar18 = bVar22 + 1, *pbVar20 != 0)) break;
        bVar18 = bVar22 + 2;
        cVar26 = (char)(uVar4 >> 0x18) + -1;
        if (cVar26 == '\0') break;
        uVar4 = (ulonglong)
                CONCAT22((short)(CONCAT13(cVar26,CONCAT12(bVar18,pbVar20)) >> 0x10),pbVar20 + -1);
      }
      if (0xc < bVar18) {
        dec_accum1 = dec_accum1 & 0xffffffffffff0000;
        dec_ieee_norm();
        return 0;
      }
    }
  }
LAB_rom_01c604:
  dec_ieee_norm();
  return 0;
}

