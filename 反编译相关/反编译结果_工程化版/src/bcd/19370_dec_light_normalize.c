/*
 * BCD 浮点库 / 19370_dec_light_normalize.c
 * 地址范围: 0x19370 - 0x19A4C
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 轻量归一化
 * @addr 0x19370
 * @module bcd
 * @proto byte dec_light_normalize(void)
 * @confidence likely
 * @note 轻量归一化：尾数为 0x0E 时按 0x1AFB8 再规整（供 0x179F4 调用）。
 * @tag bcd
 */
byte dec_light_normalize(void)

{
  byte bVar1;
  undefined2 uVar2;
  
  dec_swap_XY();
  if ((dec_flags < 10) && (uVar2 = dec_scan_digits(), bVar1 = dec_flags, (char)uVar2 == '\x0e')
     ) {
    if (dec_flags == 1) {
      if (dec_accum0 == 0x600) {
        dec_swap_XY();
        return 1;
      }
    }
    else if (dec_accum0 == 0x100) {
      dec_swap_XY();
      return bVar1;
    }
  }
  dec_swap_XY();
  return 0;
}

/**
 * @brief 尾数对齐（DAA/SLLC 链）
 * @addr 0x193BA
 * @module bcd
 * @proto void dec_align_mant(void)
 * @confidence strong
 * @note 尾数对齐（DAA/SLLC 链）：按 D009 尾数档位循环 0x19CB0/0x1AFB8/0x1B86C。
 * @tag bcd
 */
int dec_align_mant(void)

{
  short sVar1;
  ushort uVar2;
  undefined2 uVar3;
  undefined uVar4;
  undefined uVar5;
  undefined uVar6;
  undefined uVar7;
  undefined uVar8;
  undefined uVar9;
  undefined8 in_QR0;
  undefined6 extraout_var;
  byte bVar10;
  byte bVar11;
  byte bVar12;
  char cVar13;
  char cVar14;
  
  if (0xef < dec_flags) {
    return 0;
  }
  if (0xef < dec_flags_Y) {
    dec_g_X_to_Y();
    return 0;
  }
  uVar2 = dec_tail_233((ushort)CONCAT71((int7)((ulonglong)in_QR0 >> 8),dec_flags_Y));
  if ((char)uVar2 != '\0') {
    dec_swap_XY();
  }
  bVar11 = das((byte)dec_accum0 - (byte)dec_regY);
  bVar12 = das(((char)((ushort)dec_accum0 >> 8) - (char)((ushort)dec_regY >> 8)) -
               ((byte)dec_accum0 < (byte)dec_regY));
  uVar2 = CONCAT11(bVar12,bVar11) & 0xfff;
  cVar13 = das(-0x67 - bVar11);
  cVar14 = ('\t' - (char)(uVar2 >> 8)) - (0x99 < bVar11);
  das(cVar14);
  if (((byte)(-0x67 - bVar11) == '\0' && cVar14 == '\0') && (cVar13 == '\0')) {
    uVar3 = dec_shift_left4((byte)dec_regY_mant,(byte)((ulonglong)dec_regY_mant >> 8));
    dec_regY_mant = CONCAT62(extraout_var,uVar3);
    bVar11 = 0;
  }
  else {
    cVar14 = (char)(((bVar12 & 0xf) * 0x100 + (ushort)bVar11) * 0x10 >> 8);
    if (cVar14 != '\0') {
      if (cVar14 != '\x01') {
        dec_regY = 0;
        goto LAB_rom_019490;
      }
      bVar11 = (char)uVar2 - 6;
    }
  }
  dec_accum7 = bVar11;
  uVar3 = dec_accum0;
  dec_accum0 = 0;
  dec_scale_xy();
  bVar11 = (byte)((ushort)dec_accum0 >> 8);
  bVar10 = (byte)((ushort)dec_regY >> 8);
  bVar12 = daa(bVar11 + bVar10);
  sVar1 = (ushort)(byte)dec_accum1 + (ushort)(byte)dec_regY_mant + (ushort)CARRY1(bVar11,bVar10);
  bVar11 = daa((char)sVar1);
  sVar1 = (ushort)(byte)((ulonglong)dec_accum1 >> 8) +
          (ushort)(byte)((ulonglong)dec_regY_mant >> 8) + (ushort)((byte)((ushort)sVar1 >> 8) & 1);
  uVar4 = daa((char)sVar1);
  sVar1 = (ushort)(byte)((ulonglong)dec_accum1 >> 0x10) +
          (ushort)(byte)((ulonglong)dec_regY_mant >> 0x10) +
          (ushort)((byte)((ushort)sVar1 >> 8) & 1);
  uVar5 = daa((char)sVar1);
  sVar1 = (ushort)(byte)((ulonglong)dec_accum1 >> 0x18) +
          (ushort)(byte)((ulonglong)dec_regY_mant >> 0x18) +
          (ushort)((byte)((ushort)sVar1 >> 8) & 1);
  uVar6 = daa((char)sVar1);
  sVar1 = (ushort)(byte)((ulonglong)dec_accum1 >> 0x20) +
          (ushort)(byte)((ulonglong)dec_regY_mant >> 0x20) +
          (ushort)((byte)((ushort)sVar1 >> 8) & 1);
  uVar7 = daa((char)sVar1);
  sVar1 = (ushort)(byte)((ulonglong)dec_accum1 >> 0x28) +
          (ushort)(byte)((ulonglong)dec_regY_mant >> 0x28) +
          (ushort)((byte)((ushort)sVar1 >> 8) & 1);
  uVar8 = daa((char)sVar1);
  sVar1 = ((ushort)((ulonglong)dec_accum1 >> 0x30) & 0xff) +
          (ushort)(byte)((ulonglong)dec_regY_mant >> 0x30) +
          (ushort)((byte)((ushort)sVar1 >> 8) & 1);
  uVar9 = daa((char)sVar1);
  bVar10 = daa(((char)((ulonglong)dec_accum1 >> 0x38) + (char)((ulonglong)dec_regY_mant >> 0x38))
               - ((char)((char)((ushort)sVar1 >> 8) << 7) >> 7));
  dec_accum1 =
       CONCAT17(bVar10,CONCAT16(uVar9,CONCAT15(uVar8,CONCAT14(uVar7,CONCAT13(uVar6,CONCAT12(uVar5,
                                                  CONCAT11(uVar4,bVar11)))))));
  if ((bVar10 & 0xf0) != 0) {
    bVar12 = (byte)((ushort)bVar11 * 0x100 + (ushort)bVar12 >> 4);
  }
  dec_regY = CONCAT11(bVar12,(char)dec_accum0);
  dec_accum0 = uVar3;
LAB_rom_019490:
  dec_ieee_norm();
  return 0;
}

/**
 * @brief X ← (X ∪ Y)
 * @addr 0x1949E
 * @module bcd
 * @proto int dec_load_union(void)
 * @confidence likely
 * @note X ← (X ∪ Y)：把 X 的类型/符号与 Y 的尾数合并成内部运算表示。
 * @tag bcd
 */
int dec_load_union(void)

{
  undefined2 uVar1;
  undefined extraout_R1;
  
  dec_g_W_to_X();
  dec_fix_mant_hi();
  dec_set_y1();
  dec_regY = 7;
  dec_tmp_flag = 0;
  uVar1 = dec_special_check();
  dec_g_W_to_Y();
  return CONCAT11(extraout_R1,(char)uVar1);
}

/**
 * @brief Y ← 1.0（0xD010=0x0101，其余清零）
 * @addr 0x194C6
 * @module bcd
 * @proto void dec_set_y1(void)
 * @confidence verified
 * @note Y ← 1.0（0xD010=0x0101，其余清零）。
 * @tag bcd
 */
int dec_set_y1(void)

{
  dec_regY = 0x100;
  dec_regY_mant = 0;
  irq_pending_shadow = 0;
  display_dirty = 0;
  dec_regY_tail = 0x100;
  return 0;
}

/**
 * @brief Y ← 1（0xD010=0x0100，尾数 0x1111 填满，指数固定）
 * @addr 0x194DC
 * @module bcd
 * @proto void dec_set_Y_one(void)
 * @confidence strong
 * @note Y ← 1（0xD010=0x0100，尾数 0x1111 填满，指数固定）。
 * @tag bcd
 */
int dec_set_Y_one(void)

{
  dec_regY = 0x100;
  irq_pending_shadow = 0x1111;
  dec_regY_mant = 0x1111;
  display_dirty = 0x1111;
  dec_regY_tail = 0x11;
  dec_flags_Y = 1;
  return 0;
}

/**
 * @brief Y ← 9×10^0（0xD010=0x9900，指数 0x0900）
 * @addr 0x194F6
 * @module bcd
 * @proto void dec_set_Y_9e0(void)
 * @confidence strong
 * @note Y ← 9×10^0（0xD010=0x9900，指数 0x0900）。
 * @tag bcd
 */
int dec_set_Y_9e0(void)

{
  dec_regY = 0x99;
  dec_regY_mant = 0;
  irq_pending_shadow = 0;
  display_dirty = 0;
  dec_regY_tail = 0x900;
  return 0;
}

/**
 * @brief Y ← 1×10^0（0xD010=0x0102，指数 0x0200）
 * @addr 0x19510
 * @module bcd
 * @proto void dec_set_Y_1e0_a(void)
 * @confidence strong
 * @note Y ← 1×10^0（0xD010=0x0102，指数 0x0200）。
 * @tag bcd
 */
int dec_set_Y_1e0_a(void)

{
  dec_regY = 0x102;
  dec_regY_mant = 0;
  irq_pending_shadow = 0;
  display_dirty = 0;
  dec_regY_tail = 0x200;
  return 0;
}

/**
 * @brief Y ← 1.0（0xD010=0x0102，指数 0x0180）
 * @addr 0x1952A
 * @module bcd
 * @proto void dec_set_Y_1e0_b(void)
 * @confidence strong
 * @note Y ← 1.0（0xD010=0x0102，指数 0x0180）。
 * @tag bcd
 */
int dec_set_Y_1e0_b(void)

{
  dec_regY = 0x102;
  dec_regY_mant = 0;
  irq_pending_shadow = 0;
  display_dirty = 0;
  dec_regY_tail = 0x180;
  return 0;
}

/**
 * @brief 特殊值检查
 * @addr 0x19542
 * @module bcd
 * @proto byte dec_special_check(void)
 * @confidence likely
 * @note 特殊值检查：D009/D019 >= 0xF 时返回 0xF0（溢出/非法）。
 * @tag bcd
 */
byte dec_special_check(void)

{
  undefined2 in_ER0;
  byte bVar2;
  undefined extraout_R1;
  undefined extraout_R1_00;
  undefined uVar3;
  undefined2 uVar1;
  byte bVar4;
  
  if ((0xf < dec_flags) || (0xf < dec_flags_Y)) {
    return CONCAT11((char)((ushort)in_ER0 >> 8),0xf0);
  }
  bVar2 = (byte)((ushort)dec_accum0 >> 8);
  bVar4 = (byte)((ushort)dec_regY >> 8);
  if ((char)((bVar2 < 5) << 7) < '\0') {
    if ((char)((bVar4 < 5) << 7) < '\0') goto LAB_rom_01956e;
LAB_rom_01958e:
    uVar1 = CONCAT11(bVar2,4);
  }
  else {
    if (4 < bVar4) {
LAB_rom_01956e:
      if (dec_tmp_flag == '\0') {
        decc_carry_round();
        uVar3 = extraout_R1;
      }
      else {
        dec_core_op9();
        uVar3 = extraout_R1_00;
      }
      if (dec_flags == 0) {
        return CONCAT11(uVar3,1);
      }
      bVar2 = (byte)((ushort)dec_accum0 >> 8);
      if (bVar2 < 5) goto LAB_rom_01958e;
    }
    uVar1 = CONCAT11(bVar2,2);
  }
  return uVar1;
}

/**
 * @brief BCD 乘 22
 * @addr 0x1959E
 * @module bcd
 * @proto undefined2 bcd_mul22(byte n, char v)
 * @confidence verified
 * @note BCD 乘 22：按 n>>4 次数做 DAA 链（v*0x16 累加）。
 * @tag bcd
 */
undefined2 bcd_mul22(byte n, char _a1)

{
  bool bVar1;
  undefined uVar2;
  byte bVar3;
  undefined uVar4;
  byte bVar5;
  char cVar6;
  
  bVar5 = 0;
  cVar6 = '\0';
  for (bVar3 = n >> 4; bVar3 != 0; bVar3 = bVar3 - 1) {
    bVar1 = 0xe9 < bVar5;
    bVar5 = daa(bVar5 + 0x16);
    cVar6 = daa(cVar6 + bVar1);
  }
  bVar3 = n & 0xf;
  if (9 < bVar3) {
    bVar3 = bVar3 + 6;
  }
  uVar2 = daa(bVar3 + bVar5);
  uVar4 = daa(cVar6 + CARRY1(bVar3,bVar5));
  return CONCAT11(uVar4,uVar2);
}

/**
 * @brief BCD 除 22
 * @addr 0x195C8
 * @module bcd
 * @proto undefined2 bcd_div22(ushort a, char b)
 * @confidence verified
 * @note BCD 除 22：DAS 链减法循环。
 * @tag bcd
 */
undefined2 bcd_div22(ushort a, char b)

{
  bool bVar1;
  ushort uVar2;
  byte bVar3;
  char cVar4;
  
  cVar4 = '\0';
  while( true ) {
    bVar1 = a < 0x16;
    a = das((uintptr_t)a - 0x16);
    uVar2 = (ushort)b - (ushort)bVar1;
    b = das((char)uVar2);
    if ((uVar2 & 0x100) != 0) break;
    cVar4 = cVar4 + '\x01';
  }
  bVar3 = daa((uintptr_t)a + 0x16);
  if (0xf < bVar3) {
    bVar3 = bVar3 - 6;
  }
  return bVar3 + cVar4 * '\x10';
}

/**
 * @brief 一元运算收尾（0x19C8C/0x1BBA8/0x19C7A/0x1AFB8/0x1C4C6…
 * @addr 0x195EA
 * @module bcd
 * @proto void dec_unary_abs(void)
 * @confidence likely
 * @note 一元运算收尾（0x19C8C/0x1BBA8/0x19C7A/0x1AFB8/0x1C4C6 链，即取绝对值）。
 * @tag bcd
 */
int dec_unary_abs(void)

{
  dec_g_X_to_Z();
  dec_abs_core();
  dec_g_Z_to_Y();
  dec_swap_XY();
  decc_carry_round();
  return 0;
}

/**
 * @brief 工作寄存器初始化
 * @addr 0x19768
 * @module bcd
 * @proto void dec_init_work(void)
 * @confidence likely
 * @note 工作寄存器初始化：X←W、X=1.0，依次调用 0x1B426/0x19C0E/0x1C152/…
 *       建立计算上下文（无调用者，推测由启动/模式切换直接进入）。
 * @tag bcd
 */
int dec_init_work(void)

{
  dec_g_W_to_X();
  dec_accum0 = 0x101;
  dec_accum1 = 0;
  dec_accum2 = 0;
  dec_accum3 = 0;
  dec_accum4 = 0;
  dec_flags = 1;
  calc_state_a = 0;
  decc_sub();
  dec_g_X_to_W2();
  dec_g_X_to_Y_copy();
  dec_g_X_to_Z();
  dec_g_Y_to_X();
  dec_g_X_to_Y();
  dec_int_convert();
  dec_g_Z_to_Y();
  dec_int_convert();
  dec_regY_mant = 0;
  dec_regY = 0x100;
  irq_pending_shadow = 0;
  display_dirty = 0;
  dec_regY_tail = 0x200;
  dec_ieee_add();
  dec_g_X_to_Z4();
  dec_g_W_to_Y();
  dec_g_Q_to_Y();
  dec_int_convert();
  dec_g_Z4_to_Y();
  dec_tail_round();
  return 0;
}

/**
 * @brief X 规整主流程
 * @addr 0x19980
 * @module bcd
 * @proto int dec_normalize_x(void)
 * @confidence strong
 * @note X 规整主流程：按尾数高位档 0x19A48/0x19C56/0x19CF8 逐段处理特殊值。
 * @tag bcd
 */
int dec_normalize_x(void)

{
  ushort uVar1;
  byte bVar2;
  undefined2 uVar3;
  undefined uVar4;
  byte extraout_R1;
  byte bVar5;
  char cVar6;
  
  bVar2 = (byte)((ushort)dec_accum0 >> 8);
  cVar6 = (bVar2 < 5) << 7;
  uVar3 = dec_accum0;
  if ((bVar2 < 5) && (uVar3 = dec_bcd_sub16((byte)dec_accum0,bVar2), cVar6 < '\0')) {
    bVar5 = (byte)((ushort)dec_regY >> 8);
    bVar2 = (bVar5 < 5) << 7;
    uVar3 = dec_regY;
    if ((bVar5 < 5) && (uVar3 = dec_bcd_sub16((byte)dec_regY,bVar5), (char)bVar2 < '\0')) {
      uVar4 = (undefined)((ushort)uVar3 >> 8);
      uVar3 = CONCAT11(uVar4,dec_flags);
      if ((dec_flags != '\0') && (uVar3 = CONCAT11(uVar4,dec_flags_Y), dec_flags_Y != 0)) {
        bVar2 = bVar2 & 0x9f;
        uVar3 = dec_bcd_sub32((byte)dec_accum0,(char)((ushort)dec_accum0 >> 8), (uintptr_t)0, (uintptr_t)0)
                               (byte)dec_regY,(char)((ushort)dec_regY >> 8));
        if ((char)bVar2 < '\0') {
          bVar2 = bVar2 & 0x9f;
          uVar3 = dec_bcd_sub32((byte)dec_regY,(char)((ushort)dec_regY >> 8), (uintptr_t)0, (uintptr_t)0)
                                 (byte)dec_accum0,(char)((ushort)dec_accum0 >> 8));
        }
        bVar2 = bVar2 & 0x9f;
        uVar3 = dec_bcd_sub32((byte)uVar3,(char)((ushort)uVar3 >> 8),0x10,'\0');
        if ((char)bVar2 < '\0') {
          dec_g_W_to_X();
          dec_ieee_add();
          dec_g_Y_to_Z();
          dec_abs_core();
          dec_g_Z_to_Y();
          dec_g_X_to_Z();
          dec_int_convert();
          dec_g_Y_to_X();
          dec_core_div();
          dec_g_Z_to_Y();
          cVar6 = (dec_flags_Y < 0xf0) << 7;
          if (dec_flags_Y >= 0xf0) {
LAB_rom_019a3c:
            dec_swap_XY();
            return (ushort)extraout_R1 << 8;
          }
          uVar3 = dec_bcd_sub16((byte)dec_regY,(char)((ushort)dec_regY >> 8));
          if (cVar6 < '\0') {
            if (dec_flags == '\0') goto LAB_rom_019a3c;
            cVar6 = '\0';
            uVar3 = dec_bcd_sub16((byte)dec_accum0,(char)((ushort)dec_accum0 >> 8));
            if (cVar6 < '\0') {
              uVar3 = dec_scan_digits();
              bVar2 = (byte)uVar3;
              if (9 < bVar2) {
                bVar2 = bVar2 + 6;
              }
              bVar5 = daa((byte)dec_accum0 + bVar2);
              bVar2 = daa((char)((ushort)dec_accum0 >> 8) + CARRY1((byte)dec_accum0,bVar2));
              uVar3 = 0x111;
              das(bVar5 - 0x11);
              uVar1 = (bVar2 - 1) - (ushort)(bVar5 < 0x11);
              das((char)uVar1);
              if ((uVar1 & 0x100) == 0) goto LAB_rom_019a3c;
            }
          }
        }
      }
    }
  }
  return CONCAT11((char)((ushort)uVar3 >> 8),1);
}

/**
 * @brief 16 位 BCD 减 0x10
 * @addr 0x19A48
 * @module bcd
 * @proto undefined2 dec_bcd_sub16(byte lo, byte hi)
 * @confidence likely
 * @note 16 位 BCD 减 0x10：DAS 链，返回高/低字节拼接。
 * @tag bcd
 */
undefined2 dec_bcd_sub16(byte lo, byte hi)

{
  undefined uVar1;
  undefined uVar2;
  
  uVar1 = das((uintptr_t)lo - 0x10);
  uVar2 = das((hi + -1) - (lo < 0x10));
  return CONCAT11(uVar2,uVar1);
}

/**
 * @brief 32 位 BCD 减法（两个 16 位半），DAS 链
 * @addr 0x19A4C
 * @module bcd
 * @proto undefined2 dec_bcd_sub32(byte a0, byte a1, byte b0, byte b1)
 * @confidence likely
 * @note 32 位 BCD 减法（两个 16 位半），DAS 链。
 * @tag bcd
 */
undefined2 dec_bcd_sub32(byte a0, byte a1, byte b0, byte b1)

{
  undefined uVar1;
  undefined uVar2;
  
  uVar1 = das(a0 - b0);
  uVar2 = das((a1 - b1) - (a0 < b0));
  return CONCAT11(uVar2,uVar1);
}

