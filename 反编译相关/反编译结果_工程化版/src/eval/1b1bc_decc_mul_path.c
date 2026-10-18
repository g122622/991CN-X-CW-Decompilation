/*
 * 表达式求值 / 1b1bc_decc_mul_path.c
 * 地址范围: 0x1B1BC - 0x1B99A
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 乘法核心中按 0xD01C 取值范围拆分的公用尾巴
 * @addr 0x1B1BC
 * @module eval
 * @proto void decc_mul_path(void)
 * @confidence likely
 * @note 乘法核心中按 0xD01C 取值范围拆分的公用尾巴。
 * @tag float
 */
int decc_mul_path(void)

{
  bool bVar1;
  byte bVar2;
  ushort uVar3;
  undefined2 uVar4;
  ushort uVar5;
  undefined uVar9;
  undefined6 uVar8;
  undefined6 extraout_var;
  ulonglong uVar7;
  char cVar11;
  char cVar12;
  undefined uVar13;
  char cVar14;
  byte bVar15;
  undefined8 uVar6;
  byte bVar10;
  
  if (0xef < dec_flags) {
    return 0;
  }
  calc_state_c = (undefined2)CONCAT71((uint7)(byte)((ushort)calc_state_c >> 8),2);
  if (dec_opcode == '\x0e') {
    dec_normalize_y();
  }
  else {
    dec_core_mul();
  }
  bVar2 = dec_flags;
  if (0xef < dec_flags) {
    return 0;
  }
  dec_regP_mant = CONCAT24(dec_accum3,CONCAT22(dec_accum2,dec_accum1));
  calc_state_d = (ushort)(CONCAT17(dec_flags,CONCAT16(dec_accum4,dec_regP_mant)) >> 0x30);
  uVar5 = calc_state_d;
  uVar7 = (ulonglong)CONCAT14(5,(uint)CONCAT11(RAM8(0xd001),dec_accum0));
  do {
    uVar7 = uVar7 & 0xffffffffffff0fff;
    uVar9 = das((char)(uVar7 >> 0x18) - (char)(uVar7 >> 0x20));
    uVar7 = CONCAT44((int)(uVar7 >> 0x20),CONCAT13(uVar9,(int3)uVar7)) & 0xffffffff0fffffff;
    bVar15 = (byte)(uVar7 >> 8);
    bVar10 = (byte)(uVar7 >> 0x20);
    uVar8 = (undefined6)(uVar7 >> 0x10);
    uVar9 = das(bVar15 - bVar10);
    uVar4 = CONCAT11(uVar9,(char)uVar7);
    uVar7 = CONCAT62(uVar8,uVar4);
  } while ((char)((bVar15 < bVar10) << 7) < '\0');
  uVar7 = CONCAT62(uVar8,uVar4) & 0xffffffffffff0fff;
  uVar3 = (ushort)uVar7;
  dec_accum0 = (byte)uVar7;
  RAM8(0xd001) = (char)(uVar7 >> 8);
  dec_scale = (ushort)(uVar7 >> 0x10);
  if ((dec_flags & 0xf) != 0) {
    cVar14 = '\x03';
    uVar6 = CONCAT62(dec_regP_mant,calc_state_c);
    dec_scale = 0;
    bVar15 = dec_scale;
    while( true ) {
      cVar12 = (char)(uVar3 >> 8);
      cVar11 = (char)uVar3;
      if (cVar12 == '\0') break;
      cVar14 = cVar14 + -1;
      if (cVar14 == '\0') {
        bVar15 = bVar15 & 0xf | 0xe0;
        break;
      }
      uVar4 = decc_reload();
      uVar6 = CONCAT62(extraout_var,uVar4);
      uVar9 = das(cVar11 + -1);
      uVar13 = das(cVar12 - (cVar11 == '\0'));
      uVar3 = CONCAT11(uVar13,uVar9) & 0xfff;
      bVar15 = bVar2;
    }
    dec_scale = CONCAT11(DAT_ram_d01a_1,bVar15);
    uVar7 = CONCAT71((int7)((ulonglong)uVar6 >> 8),cVar11) & 0xfffffffffffff0ff;
    dec_accum0 = (byte)uVar7;
    RAM8(0xd001) = (char)(uVar7 >> 8);
    dec_accum1 = (undefined2)(uVar7 >> 0x10);
    dec_accum2 = (undefined2)(uVar7 >> 0x20);
    dec_accum3 = (undefined2)(uVar7 >> 0x30);
    dec_accum4 = (undefined)(uVar5 & 0xfff);
    dec_flags = (byte)((uVar5 & 0xfff) >> 8);
  }
  decc_unpack();
  dec_set_Y_1e0();
  bVar1 = CARRY1(dec_accum0,dec_scale);
  dec_accum0 = daa(dec_accum0 + dec_scale);
  if (((char)(bVar1 << 7) < '\0') && ((calc_state_b != '\n' || (dec_opcode != '\x03')))) {
    dec_accum1 = 0;
    dec_accum0 = 0;
    RAM8(0xd001) = '\0';
    dec_accum3 = 0;
    dec_accum2 = 0;
    dec_accum4 = 0;
    dec_flags = 0;
    uVar9 = daa((char)(dec_scale >> 8) + '\x05');
    dec_scale = CONCAT11(uVar9,dec_scale) & 0xfff;
  }
  if (dec_stage != '\0') {
    dec_neg_core();
  }
  uVar9 = das((char)(dec_scale >> 8) + -5);
  dec_scale = CONCAT11(uVar9,(char)dec_scale) & 0xfff;
  if ((char)(dec_scale >> 8) == '\0') {
    dec_set_Y_1e0_x();
    uVar9 = daa(RAM8(0xd001) + (char)(dec_scale >> 8));
    uVar5 = CONCAT11(uVar9,dec_accum0) & 0xfff;
    dec_accum0 = (byte)uVar5;
    RAM8(0xd001) = (char)(uVar5 >> 8);
  }
  if (0x9f < dec_accum0) {
    dec_zero_helper();
  }
  return 0;
}

/**
 * @brief 三角函数化简路径之一（±π/2 象限调整后调用）
 * @addr 0x1B1CA
 * @module eval
 * @proto void decc_sin_path(void)
 * @confidence likely
 * @note 三角函数化简路径之一（±π/2 象限调整后调用）。
 * @tag float
 */
int decc_sin_path(void)

{
  bool bVar1;
  byte bVar2;
  ushort uVar3;
  ushort uVar4;
  undefined2 uVar5;
  ushort uVar6;
  undefined uVar9;
  undefined6 uVar8;
  undefined6 extraout_var;
  ulonglong uVar7;
  char cVar11;
  char cVar12;
  undefined uVar13;
  char cVar14;
  byte bVar15;
  byte bVar10;
  
  bVar2 = dec_flags;
  if (0xef < dec_flags) {
    return 0;
  }
  dec_stage = '\0';
  dec_regP_mant = CONCAT24(dec_accum3,CONCAT22(dec_accum2,dec_accum1));
  calc_state_d = (ushort)(CONCAT17(dec_flags,CONCAT16(dec_accum4,dec_regP_mant)) >> 0x30);
  uVar6 = calc_state_d;
  uVar7 = (ulonglong)CONCAT14(5,(uint)CONCAT11(RAM8(0xd001),dec_accum0));
  do {
    uVar7 = uVar7 & 0xffffffffffff0fff;
    uVar9 = das((char)(uVar7 >> 0x18) - (char)(uVar7 >> 0x20));
    uVar7 = CONCAT44((int)(uVar7 >> 0x20),CONCAT13(uVar9,(int3)uVar7)) & 0xffffffff0fffffff;
    bVar15 = (byte)(uVar7 >> 8);
    bVar10 = (byte)(uVar7 >> 0x20);
    uVar8 = (undefined6)(uVar7 >> 0x10);
    uVar9 = das(bVar15 - bVar10);
    uVar5 = CONCAT11(uVar9,(char)uVar7);
    uVar7 = CONCAT62(uVar8,uVar5);
  } while ((char)((bVar15 < bVar10) << 7) < '\0');
  uVar7 = CONCAT62(uVar8,uVar5) & 0xffffffffffff0fff;
  uVar4 = (ushort)uVar7;
  dec_accum0 = (byte)uVar7;
  RAM8(0xd001) = (char)(uVar7 >> 8);
  dec_scale = (ushort)(uVar7 >> 0x10);
  uVar3 = calc_state_c & 0xff;
  if ((dec_flags & 0xf) != 0) {
    cVar14 = '\x03';
    uVar7 = CONCAT62(dec_regP_mant,calc_state_c) & 0xffffffffffff00ff;
    dec_scale = 0;
    bVar15 = dec_scale;
    calc_state_c = calc_state_c & 0xff;
    while( true ) {
      cVar12 = (char)(uVar4 >> 8);
      cVar11 = (char)uVar4;
      if (cVar12 == '\0') break;
      cVar14 = cVar14 + -1;
      if (cVar14 == '\0') {
        bVar15 = bVar15 & 0xf | 0xe0;
        break;
      }
      uVar5 = decc_reload();
      uVar7 = CONCAT62(extraout_var,uVar5);
      uVar9 = das(cVar11 + -1);
      uVar13 = das(cVar12 - (cVar11 == '\0'));
      uVar4 = CONCAT11(uVar13,uVar9) & 0xfff;
      bVar15 = bVar2;
    }
    dec_scale = CONCAT11(DAT_ram_d01a_1,bVar15);
    uVar7 = CONCAT71((int7)(uVar7 >> 8),cVar11) & 0xfffffffffffff0ff;
    dec_accum0 = (byte)uVar7;
    RAM8(0xd001) = (char)(uVar7 >> 8);
    dec_accum1 = (undefined2)(uVar7 >> 0x10);
    dec_accum2 = (undefined2)(uVar7 >> 0x20);
    dec_accum3 = (undefined2)(uVar7 >> 0x30);
    dec_accum4 = (undefined)(uVar6 & 0xfff);
    dec_flags = (byte)((uVar6 & 0xfff) >> 8);
    uVar3 = calc_state_c;
  }
  calc_state_c = uVar3;
  decc_unpack();
  dec_set_Y_1e0();
  bVar1 = CARRY1(dec_accum0,dec_scale);
  dec_accum0 = daa(dec_accum0 + dec_scale);
  if (((char)(bVar1 << 7) < '\0') && ((calc_state_b != '\n' || (dec_opcode != '\x03')))) {
    dec_accum1 = 0;
    dec_accum0 = 0;
    RAM8(0xd001) = '\0';
    dec_accum3 = 0;
    dec_accum2 = 0;
    dec_accum4 = 0;
    dec_flags = 0;
    uVar9 = daa((char)(dec_scale >> 8) + '\x05');
    dec_scale = CONCAT11(uVar9,dec_scale) & 0xfff;
  }
  if (dec_stage != '\0') {
    dec_neg_core();
  }
  uVar9 = das((char)(dec_scale >> 8) + -5);
  dec_scale = CONCAT11(uVar9,(char)dec_scale) & 0xfff;
  if ((char)(dec_scale >> 8) == '\0') {
    dec_set_Y_1e0_x();
    uVar9 = daa(RAM8(0xd001) + (char)(dec_scale >> 8));
    uVar6 = CONCAT11(uVar9,dec_accum0) & 0xfff;
    dec_accum0 = (byte)uVar6;
    RAM8(0xd001) = (char)(uVar6 >> 8);
  }
  if (0x9f < dec_accum0) {
    dec_zero_helper();
  }
  return 0;
}

/**
 * @brief e^x 的级数展开路径
 * @addr 0x1B1E8
 * @module eval
 * @proto void decc_exp_path(void)
 * @confidence likely
 * @note e^x 的级数展开路径。
 * @tag float
 */
int decc_exp_path(void)

{
  bool bVar1;
  byte bVar2;
  ushort uVar3;
  undefined2 uVar4;
  ushort uVar5;
  undefined uVar9;
  undefined6 uVar8;
  undefined6 extraout_var;
  ulonglong uVar7;
  char cVar11;
  char cVar12;
  undefined uVar13;
  char cVar14;
  byte bVar15;
  undefined8 uVar6;
  byte bVar10;
  
  if (0xef < dec_flags) {
    return 0;
  }
  dec_stage = '\0';
  decc_scale_x();
  dec_g_X_to_Z();
  dec_g_X_to_Y();
  calc_state_c = 0x8300;
  dec_g_Z_to_Y();
  calc_state_c = (undefined2)CONCAT71((uint7)(byte)((ushort)calc_state_c >> 8),2);
  if (dec_opcode == '\x0e') {
    dec_normalize_y();
  }
  else {
    dec_core_mul();
  }
  bVar2 = dec_flags;
  if (0xef < dec_flags) {
    return 0;
  }
  dec_regP_mant = CONCAT24(dec_accum3,CONCAT22(dec_accum2,dec_accum1));
  calc_state_d = (ushort)(CONCAT17(dec_flags,CONCAT16(dec_accum4,dec_regP_mant)) >> 0x30);
  uVar5 = calc_state_d;
  uVar7 = (ulonglong)CONCAT14(5,(uint)CONCAT11(RAM8(0xd001),dec_accum0));
  do {
    uVar7 = uVar7 & 0xffffffffffff0fff;
    uVar9 = das((char)(uVar7 >> 0x18) - (char)(uVar7 >> 0x20));
    uVar7 = CONCAT44((int)(uVar7 >> 0x20),CONCAT13(uVar9,(int3)uVar7)) & 0xffffffff0fffffff;
    bVar15 = (byte)(uVar7 >> 8);
    bVar10 = (byte)(uVar7 >> 0x20);
    uVar8 = (undefined6)(uVar7 >> 0x10);
    uVar9 = das(bVar15 - bVar10);
    uVar4 = CONCAT11(uVar9,(char)uVar7);
    uVar7 = CONCAT62(uVar8,uVar4);
  } while ((char)((bVar15 < bVar10) << 7) < '\0');
  uVar7 = CONCAT62(uVar8,uVar4) & 0xffffffffffff0fff;
  uVar3 = (ushort)uVar7;
  dec_accum0 = (byte)uVar7;
  RAM8(0xd001) = (char)(uVar7 >> 8);
  dec_scale = (ushort)(uVar7 >> 0x10);
  if ((dec_flags & 0xf) != 0) {
    cVar14 = '\x03';
    uVar6 = CONCAT62(dec_regP_mant,calc_state_c);
    dec_scale = 0;
    bVar15 = dec_scale;
    while( true ) {
      cVar12 = (char)(uVar3 >> 8);
      cVar11 = (char)uVar3;
      if (cVar12 == '\0') break;
      cVar14 = cVar14 + -1;
      if (cVar14 == '\0') {
        bVar15 = bVar15 & 0xf | 0xe0;
        break;
      }
      uVar4 = decc_reload();
      uVar6 = CONCAT62(extraout_var,uVar4);
      uVar9 = das(cVar11 + -1);
      uVar13 = das(cVar12 - (cVar11 == '\0'));
      uVar3 = CONCAT11(uVar13,uVar9) & 0xfff;
      bVar15 = bVar2;
    }
    dec_scale = CONCAT11(DAT_ram_d01a_1,bVar15);
    uVar7 = CONCAT71((int7)((ulonglong)uVar6 >> 8),cVar11) & 0xfffffffffffff0ff;
    dec_accum0 = (byte)uVar7;
    RAM8(0xd001) = (char)(uVar7 >> 8);
    dec_accum1 = (undefined2)(uVar7 >> 0x10);
    dec_accum2 = (undefined2)(uVar7 >> 0x20);
    dec_accum3 = (undefined2)(uVar7 >> 0x30);
    dec_accum4 = (undefined)(uVar5 & 0xfff);
    dec_flags = (byte)((uVar5 & 0xfff) >> 8);
  }
  decc_unpack();
  dec_set_Y_1e0();
  bVar1 = CARRY1(dec_accum0,dec_scale);
  dec_accum0 = daa(dec_accum0 + dec_scale);
  if (((char)(bVar1 << 7) < '\0') && ((calc_state_b != '\n' || (dec_opcode != '\x03')))) {
    dec_accum1 = 0;
    dec_accum0 = 0;
    RAM8(0xd001) = '\0';
    dec_accum3 = 0;
    dec_accum2 = 0;
    dec_accum4 = 0;
    dec_flags = 0;
    uVar9 = daa((char)(dec_scale >> 8) + '\x05');
    dec_scale = CONCAT11(uVar9,dec_scale) & 0xfff;
  }
  if (dec_stage != '\0') {
    dec_neg_core();
  }
  uVar9 = das((char)(dec_scale >> 8) + -5);
  dec_scale = CONCAT11(uVar9,(char)dec_scale) & 0xfff;
  if ((char)(dec_scale >> 8) == '\0') {
    dec_set_Y_1e0_x();
    uVar9 = daa(RAM8(0xd001) + (char)(dec_scale >> 8));
    uVar5 = CONCAT11(uVar9,dec_accum0) & 0xfff;
    dec_accum0 = (byte)uVar5;
    RAM8(0xd001) = (char)(uVar5 >> 8);
  }
  if (0x9f < dec_accum0) {
    dec_zero_helper();
  }
  return 0;
}

/**
 * @brief 减法核心入口
 * @addr 0x1B426
 * @module eval
 * @proto void decc_sub(void)
 * @confidence strong
 * @note 减法核心入口：0xD01C=2 后调用 0x1B44C（对齐减法）。
 * @tag float
 */
int decc_sub(void)

{
  if (0xef < dec_flags) {
    return 0;
  }
  dec_stage = 2;
  decc_sub_align();
  return 0;
}

/**
 * @brief 加法对齐核心
 * @addr 0x1B43A
 * @module eval
 * @proto void decc_add_align(void)
 * @confidence strong
 * @note 加法对齐核心：按指数差对齐尾数（DAS 十进制减），处理交换律换位，最后调用 0x1C028。
 * @tag float
 */
int decc_add_align(void)

{
  ushort uVar1;
  undefined uVar2;
  byte bVar4;
  undefined2 uVar3;
  undefined uVar5;
  undefined6 extraout_var;
  
  if (0xef < dec_flags) {
    return 0;
  }
  dec_stage = 3;
  bVar4 = (byte)(dec_accum0 >> 8);
  if ((char)((bVar4 < 5) << 7) < '\0') {
    dec_regY = 0;
    dec_regY_mant = 0x100000000000000;
    uVar1 = CONCAT11(bVar4 - 1,(char)dec_accum0);
    if (bVar4 == 0) {
      dec_regY = dec_accum0 & 0xff;
      dec_regY_mant = dec_accum1;
      dec_accum0 = 0x599;
      dec_accum1 = 0;
      uVar1 = dec_accum0;
    }
    dec_accum0 = uVar1;
    if (dec_flags_Y != '\0') {
      uVar3 = decc_sub8((byte)dec_accum1,(byte)(dec_accum1 >> 8), (uintptr_t)0, (uintptr_t)0)
                             (byte)(dec_accum1 >> 0x10),(byte)(dec_accum1 >> 0x18));
      dec_accum1 =
           CONCAT17((char)((uint6)extraout_var >> 0x28),(int7)CONCAT62(extraout_var,uVar3)) &
           0xfffffffffffffff;
      uVar2 = das((byte)dec_accum0 - (byte)dec_regY);
      uVar5 = das(((char)(dec_accum0 >> 8) - (char)(dec_regY >> 8)) -
                  ((byte)dec_accum0 < (byte)dec_regY));
      dec_scale = CONCAT11(uVar5,uVar2) & 0xfff;
      dec_accum0 = 0;
      decc_pack();
      dec_align_mant();
      calc_state_c = dec_regY;
      uVar2 = daa((char)(dec_accum0 >> 8) + (char)(dec_scale >> 8));
      dec_accum0 = CONCAT11(uVar2,(char)dec_accum0) & 0xfff;
      if (1 < dec_stage) {
        if (dec_stage == 2) {
          decc_scale_x();
          uVar2 = daa((char)(dec_accum0 >> 8) + calc_state_a);
          dec_accum0 = CONCAT11(uVar2,(char)dec_accum0) & 0xfff;
          dec_normalize_y();
        }
        return 0;
      }
      return 0;
    }
  }
  dec_zero_helper();
  return 0;
}

/**
 * @brief 减法对齐核心
 * @addr 0x1B44C
 * @module eval
 * @proto void decc_sub_align(void)
 * @confidence strong
 * @note 减法对齐核心：与 0x1B43A 对称，结果取补。
 * @tag float
 */
int decc_sub_align(void)

{
  ushort uVar1;
  undefined uVar2;
  byte bVar4;
  undefined2 uVar3;
  undefined uVar5;
  undefined6 extraout_var;
  
  bVar4 = (byte)(dec_accum0 >> 8);
  if ((char)((bVar4 < 5) << 7) < '\0') {
    dec_regY = 0;
    dec_regY_mant = 0x100000000000000;
    uVar1 = CONCAT11(bVar4 - 1,(char)dec_accum0);
    if (bVar4 == 0) {
      dec_regY = dec_accum0 & 0xff;
      dec_regY_mant = dec_accum1;
      dec_accum0 = 0x599;
      dec_accum1 = 0;
      uVar1 = dec_accum0;
    }
    dec_accum0 = uVar1;
    if (dec_flags_Y != '\0') {
      uVar3 = decc_sub8((byte)dec_accum1,(byte)(dec_accum1 >> 8), (uintptr_t)0, (uintptr_t)0)
                             (byte)(dec_accum1 >> 0x10),(byte)(dec_accum1 >> 0x18));
      dec_accum1 =
           CONCAT17((char)((uint6)extraout_var >> 0x28),(int7)CONCAT62(extraout_var,uVar3)) &
           0xfffffffffffffff;
      uVar2 = das((byte)dec_accum0 - (byte)dec_regY);
      uVar5 = das(((char)(dec_accum0 >> 8) - (char)(dec_regY >> 8)) -
                  ((byte)dec_accum0 < (byte)dec_regY));
      dec_scale = CONCAT11(uVar5,uVar2) & 0xfff;
      dec_accum0 = 0;
      decc_pack();
      dec_align_mant();
      calc_state_c = dec_regY;
      uVar2 = daa((char)(dec_accum0 >> 8) + (char)(dec_scale >> 8));
      dec_accum0 = CONCAT11(uVar2,(char)dec_accum0) & 0xfff;
      if (1 < dec_stage) {
        if (dec_stage == 2) {
          decc_scale_x();
          uVar2 = daa((char)(dec_accum0 >> 8) + calc_state_a);
          dec_accum0 = CONCAT11(uVar2,(char)dec_accum0) & 0xfff;
          dec_normalize_y();
        }
        return 0;
      }
      return 0;
    }
  }
  dec_zero_helper();
  return 0;
}

/**
 * @brief 十进制数学层舍入/规整过程 3（0x1AC2C 使用）
 * @addr 0x1B522
 * @module eval
 * @proto void decc_round(void)
 * @confidence likely
 * @note 十进制数学层舍入/规整过程 3（0x1AC2C 使用）。
 * @tag float
 */
int decc_round(void)

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
  _DAT_ram_d00d = 2;
  dec_accum0 = das(dec_accum0 + -1);
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
 * @brief 十进制数学层打包/对齐过程 2（0x1890/加减对齐使用）
 * @addr 0x1B536
 * @module eval
 * @proto void decc_pack(void)
 * @confidence likely
 * @note 十进制数学层打包/对齐过程 2（0x1890/加减对齐使用）。
 * @tag float
 */
int decc_pack(void)

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
  _DAT_ram_d00d = 0;
  dec_accum0 = das(dec_accum0 + -1);
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
 * @brief 十进制数学层拆分/规整过程 1（乘方/指数核心使用）
 * @addr 0x1B558
 * @module eval
 * @proto void decc_unpack(void)
 * @confidence likely
 * @note 十进制数学层拆分/规整过程 1（乘方/指数核心使用）。
 * @tag float
 */
int decc_unpack(void)

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
  _DAT_ram_d00d = 8;
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
 * @brief 空操作（仅 PUSH/POP 寄存器后返回）
 * @addr 0x1B858
 * @module eval
 * @proto int decc_nop(void)
 * @confidence verified
 * @note 空操作（仅 PUSH/POP 寄存器后返回）。
 * @tag float
 */
int decc_nop(void)

{
  return 0;
}

/**
 * @brief 重新装载当前运算寄存器（0x0D000 系列），无可见效果
 * @addr 0x1B87E
 * @module eval
 * @proto int decc_reload(void)
 * @confidence verified
 * @note 重新装载当前运算寄存器（0x0D000 系列），无可见效果。
 * @tag float
 */
int decc_reload(void)

{
  return 0;
}

/**
 * @brief Y ← Y − Z（尾数 0x1C330 十进制减）
 * @addr 0x1B892
 * @module eval
 * @proto void decc_Y_sub_Z(void)
 * @confidence strong
 * @note Y ← Y − Z（尾数 0x1C330 十进制减）。
 * @tag float
 */
int decc_Y_sub_Z(void)

{
  undefined uVar2;
  undefined2 uVar1;
  undefined6 extraout_var;
  
  uVar2 = das((char)((ushort)dec_regY >> 8) - (char)((ushort)calc_state_e >> 8));
  dec_regY = CONCAT11(uVar2,(char)dec_regY);
  uVar1 = decc_sub8_mb((byte)dec_regY_mant,(byte)((ulonglong)dec_regY_mant >> 8), (uintptr_t)0, (uintptr_t)0)
                         (byte)((ulonglong)dec_regY_mant >> 0x10),
                         (byte)((ulonglong)dec_regY_mant >> 0x18));
  dec_regY_mant = CONCAT62(extraout_var,uVar1);
  return 0;
}

/**
 * @brief X ← X − Y
 * @addr 0x1B8BC
 * @module eval
 * @proto void decc_X_sub_Y(void)
 * @confidence strong
 * @note X ← X − Y。
 * @tag float
 */
int decc_X_sub_Y(void)

{
  undefined uVar2;
  undefined2 uVar1;
  undefined6 extraout_var;
  
  uVar2 = das((char)((ushort)dec_accum0 >> 8) - (char)((ushort)dec_regY >> 8));
  dec_accum0 = CONCAT11(uVar2,(char)dec_accum0);
  uVar1 = decc_sub8_mb((byte)dec_accum1,(byte)((ulonglong)dec_accum1 >> 8), (uintptr_t)0, (uintptr_t)0)
                         (byte)((ulonglong)dec_accum1 >> 0x10),
                         (byte)((ulonglong)dec_accum1 >> 0x18));
  dec_accum1 = CONCAT62(extraout_var,uVar1);
  return 0;
}

/**
 * @brief Y ← Y + Z（尾数 0x1C304 十进制加）
 * @addr 0x1B8E6
 * @module eval
 * @proto void decc_Y_add_Z(void)
 * @confidence strong
 * @note Y ← Y + Z（尾数 0x1C304 十进制加）。
 * @tag float
 */
int decc_Y_add_Z(void)

{
  undefined uVar2;
  undefined2 uVar1;
  undefined6 extraout_var;
  
  uVar2 = daa((char)((ushort)dec_regY >> 8) + (char)((ushort)calc_state_e >> 8));
  dec_regY = CONCAT11(uVar2,(char)dec_regY);
  uVar1 = decc_add8_mb((byte)dec_regY_mant,(byte)((ulonglong)dec_regY_mant >> 8), (uintptr_t)0, (uintptr_t)0)
                         (byte)((ulonglong)dec_regY_mant >> 0x10),
                         (byte)((ulonglong)dec_regY_mant >> 0x18));
  dec_regY_mant = CONCAT62(extraout_var,uVar1);
  return 0;
}

/**
 * @brief X ← X + Y
 * @addr 0x1B910
 * @module eval
 * @proto void decc_X_add_Y(void)
 * @confidence strong
 * @note X ← X + Y。
 * @tag float
 */
int decc_X_add_Y(void)

{
  undefined uVar2;
  undefined2 uVar1;
  undefined6 extraout_var;
  
  uVar2 = daa((char)((ushort)dec_accum0 >> 8) + (char)((ushort)dec_regY >> 8));
  dec_accum0 = CONCAT11(uVar2,(char)dec_accum0);
  uVar1 = decc_add8_mb((byte)dec_accum1,(byte)((ulonglong)dec_accum1 >> 8), (uintptr_t)0, (uintptr_t)0)
                         (byte)((ulonglong)dec_accum1 >> 0x10),
                         (byte)((ulonglong)dec_accum1 >> 0x18));
  dec_accum1 = CONCAT62(extraout_var,uVar1);
  return 0;
}

/**
 * @brief 加减后的进位/借位处理（按精度 0xD00E 修正尾数）
 * @addr 0x1B93A
 * @module eval
 * @proto void decc_carry_out(void)
 * @confidence likely
 * @note 加减后的进位/借位处理（按精度 0xD00E 修正尾数）。
 * @tag float
 */
int decc_carry_out(void)

{
  byte bVar1;
  byte bVar2;
  char cVar3;
  
  bVar1 = dec_accum0 & 0xf;
  bVar2 = dec_accum0 >> 4;
  cVar3 = -bVar1 + '\n';
  if ((_DAT_ram_d00d & 2) == 0) {
    if ((7 < bVar2) && ((bVar2 != 8 || (cVar3 = -bVar1 + '\x14', 1 < bVar1)))) {
LAB_rom_01b95e:
      if (dec_temp_a == '\0') goto LAB_rom_01b968;
    }
  }
  else if ((8 < bVar2) && (bVar1 != 0)) goto LAB_rom_01b95e;
  cVar3 = '\0';
LAB_rom_01b968:
  if (_DAT_ram_d00d < 2) {
    _DAT_ram_d00f = cVar3 + '\x01';
  }
  else if (_DAT_ram_d00d == 2) {
    _DAT_ram_d00f = cVar3 * '\x02';
  }
  else {
    if ((char)((_DAT_ram_d00d < 10) << 7) < '\0') {
      decc_scale_x();
    }
    else {
      dec_set_y_prec();
    }
    _DAT_ram_d00f = '\0';
  }
  return 0;
}

/**
 * @brief 按 in_XR0 的高字节（指数）缩放
 * @addr 0x1B99A
 * @module eval
 * @proto void decc_scale_x(void)
 * @confidence strong
 * @note 按 in_XR0 的高字节（指数）缩放：0x1F 置 99/上限表值，否则查 0x1BB2 起的 10 字节常量表。
 * @tag float
 */
int decc_scale_x(void)

{
  byte bVar1;
  undefined4 in_XR0;
  
  bVar1 = (byte)((uint)in_XR0 >> 0x10);
  if (bVar1 == 0x1f) {
    dec_regY = CONCAT71((int7)((ulonglong)_DAT_ram_1c70 >> 8),0x99);
    dec_regY_tail = _DAT_ram_1c78;
  }
  else {
    if (0x12 < bVar1) {
      bVar1 = 0x12;
    }
    dec_regY =
         CONCAT71((int7)((ulonglong)*(undefined8 *)((ushort)bVar1 * 10 + 0x1bb2) >> 8),dec_regY)
    ;
    dec_regY_tail = *(undefined2 *)((ushort)bVar1 * 10 + 0x1bba);
  }
  return 0;
}

