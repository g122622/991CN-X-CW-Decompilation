/*
 * 字符串与格式化 / 20fb0_str_emit_1d7c.c
 * 地址范围: 0x20FB0 - 0x2153C
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 追加 ROM 0x1D7C 处的记号串
 * @addr 0x20FB0
 * @module strlib
 * @proto void str_emit_1D7C(void)
 * @confidence likely
 * @note 追加 ROM 0x1D7C 处的记号串。
 * @tag text
 */
int str_emit_1D7C(uintptr_t _a2, int _a1)

{
  strcat_checked(_a1,(char *)0x1d7c);
  return 0;
}

/**
 * @brief 追加 ROM 0x1D81 处的记号串
 * @addr 0x20FB6
 * @module strlib
 * @proto void str_emit_1D81(void)
 * @confidence likely
 * @note 追加 ROM 0x1D81 处的记号串。
 * @tag text
 */
int str_emit_1D81(uintptr_t _a2, int _a1)

{
  strcat_checked(_a1,(char *)0x1d81);
  return 0;
}

/**
 * @brief 追加 ROM 0x1D86 处的记号串
 * @addr 0x20FBE
 * @module strlib
 * @proto void str_emit_1D86(void)
 * @confidence likely
 * @note 追加 ROM 0x1D86 处的记号串。
 * @tag text
 */
int str_emit_1D86(void)

{
  char *in_ER0;
  
  strcat_checked(in_ER0,(char *)0x1d86);
  return 0;
}

/**
 * @brief 追加 ROM 0x1D8B 处的记号串
 * @addr 0x20FC6
 * @module strlib
 * @proto void str_emit_1D8B(void)
 * @confidence likely
 * @note 追加 ROM 0x1D8B 处的记号串。
 * @tag text
 */
int str_emit_1D8B(void)

{
  char *in_ER0;
  
  strcat_checked(in_ER0,(char *)0x1d8b);
  return 0;
}

/**
 * @brief 追加 ROM 0x1D90 处的记号串
 * @addr 0x20FCE
 * @module strlib
 * @proto void str_emit_1D90(void)
 * @confidence likely
 * @note 追加 ROM 0x1D90 处的记号串。
 * @tag text
 */
int str_emit_1D90(uintptr_t _a2, int _a1)

{
  strcat_checked(_a1,(char *)0x1d90);
  return 0;
}

/**
 * @brief 追加 ROM 0x1D97 处的记号串
 * @addr 0x20FD6
 * @module strlib
 * @proto void str_emit_1D97(void)
 * @confidence likely
 * @note 追加 ROM 0x1D97 处的记号串。
 * @tag text
 */
int str_emit_1D97(uintptr_t _a2, int _a1)

{
  strcat_checked(_a1,(char *)0x1d97);
  return 0;
}

/**
 * @brief 追加 ROM 0x1D9E 处的记号串
 * @addr 0x20FDE
 * @module strlib
 * @proto void str_emit_1D9E(void)
 * @confidence likely
 * @note 追加 ROM 0x1D9E 处的记号串。
 * @tag text
 */
int str_emit_1D9E(uintptr_t _a2, int _a1)

{
  strcat_checked(_a1,(char *)0x1d9e);
  return 0;
}

/**
 * @brief 追加 ASCII "x="（ROM 0x1DA4）
 * @addr 0x20FE6
 * @module strlib
 * @proto void str_emit_xeq(void)
 * @confidence verified
 * @note 追加 ASCII "x="（ROM 0x1DA4）。
 * @tag text
 */
int str_emit_xeq(uintptr_t _a2, int _a1)

{
  strcat_checked(_a1,"x=");
  return 0;
}

/**
 * @brief 追加 ROM 0x1DA7 处的记号串
 * @addr 0x20FEE
 * @module strlib
 * @proto void str_emit_1DA7(void)
 * @confidence likely
 * @note 追加 ROM 0x1DA7 处的记号串。
 * @tag text
 */
int str_emit_1DA7(uintptr_t _a2, int _a1)

{
  strcat_checked(_a1,(char *)0x1da7);
  return 0;
}

/**
 * @brief 追加 ASCII "x<"（ROM 0x1DAA）
 * @addr 0x20FF6
 * @module strlib
 * @proto void str_emit_xlt(void)
 * @confidence verified
 * @note 追加 ASCII "x<"（ROM 0x1DAA）。
 * @tag text
 */
int str_emit_xlt(uintptr_t _a2, int _a1)

{
  strcat_checked(_a1,"x<");
  return 0;
}

/**
 * @brief 追加 ROM 0x1DAD 处的记号串
 * @addr 0x20FFE
 * @module strlib
 * @proto void str_emit_1DAD(void)
 * @confidence likely
 * @note 追加 ROM 0x1DAD 处的记号串。
 * @tag text
 */
int str_emit_1DAD(uintptr_t _a2, int _a1)

{
  strcat_checked(_a1,(char *)0x1dad);
  return 0;
}

/**
 * @brief 追加 ASCII "<x"（ROM 0x1DB0）
 * @addr 0x21006
 * @module strlib
 * @proto void str_emit_ltx(void)
 * @confidence verified
 * @note 追加 ASCII "<x"（ROM 0x1DB0）。
 * @tag text
 */
int str_emit_ltx(void)

{
  char *in_ER0;
  
  strcat_checked(in_ER0,"<x");
  return 0;
}

/**
 * @brief 追加 ROM 0x1DB3 处的记号串
 * @addr 0x2100E
 * @module strlib
 * @proto void str_emit_1DB3(void)
 * @confidence likely
 * @note 追加 ROM 0x1DB3 处的记号串。
 * @tag text
 */
int str_emit_1DB3(void)

{
  char *in_ER0;
  
  strcat_checked(in_ER0,(char *)0x1db3);
  return 0;
}

/**
 * @brief 追加 ASCII "<x<"（ROM 0x1DB6）
 * @addr 0x21016
 * @module strlib
 * @proto void str_emit_ltxlt(void)
 * @confidence verified
 * @note 追加 ASCII "<x<"（ROM 0x1DB6）。
 * @tag text
 */
int str_emit_ltxlt(uintptr_t _a2, int _a1)

{
  strcat_checked(_a1,"<x<");
  return 0;
}

/**
 * @brief 追加 ROM 0x1DBA 处的记号串
 * @addr 0x2101E
 * @module strlib
 * @proto void str_emit_1DBA(void)
 * @confidence likely
 * @note 追加 ROM 0x1DBA 处的记号串。
 * @tag text
 */
int str_emit_1DBA(uintptr_t _a2, int _a1)

{
  strcat_checked(_a1,(char *)0x1dba);
  return 0;
}

/**
 * @brief 追加 ASCII " and "（ROM 0x1DBE）
 * @addr 0x21026
 * @module strlib
 * @proto void str_emit_and(void)
 * @confidence verified
 * @note 追加 ASCII " and "（ROM 0x1DBE）。
 * @tag text
 */
int str_emit_and(uintptr_t _a2, int _a1)

{
  strcat_checked(_a1," and ");
  return 0;
}

/**
 * @brief 矩阵输入主流程（3.5KB，0x280B0 调用）
 * @addr 0x2102E
 * @module strlib
 * @proto int matrix_entry_main(void)
 * @confidence likely
 * @note 矩阵输入主流程（3.5KB，0x280B0 调用）。
 * @tag matrix
 */
int matrix_entry_main(void)

{
  bool bVar1;
  uint6 uVar2;
  byte bVar3;
  undefined2 uVar4;
  undefined *puVar5;
  undefined2 *puVar6;
  undefined *puVar8;
  undefined2 *puVar9;
  ushort uVar10;
  byte bVar11;
  ushort *puVar12;
  undefined6 uVar13;
  ulonglong uVar14;
  longlong lVar16;
  undefined auStack_10 [12];
  undefined uVar7;
  undefined8 uVar15;
  
  puVar8 = &stat_data;
  puVar9 = (undefined2 *)0xd432;
  uVar13 = CONCAT15((char)(_DAT_ram_d102 >> 8) + '\x01',(uint5)_DAT_ram_d102 << 0x20);
  _DAT_ram_d10a = (undefined2)((uint6)uVar13 >> 0x20);
  uVar14 = CONCAT44((int)(CONCAT26(auStack_10,uVar13) >> 0x20),0xd9320000);
  memzero((undefined *)0xd932,200);
  uVar14 = uVar14 & 0xffffffffffff0000;
  while( true ) {
    puVar5 = puVar8;
    memcpy_bytes((undefined *)(uVar14 >> 0x10),puVar8,0x28);
    uVar7 = (undefined)((ushort)puVar5 >> 8);
    if (3 < (byte)(uVar14 >> 0x20)) {
      puVar6 = puVar9;
      dec_copy((undefined2 *)((short)(uVar14 >> 0x10) + 0x28),puVar9);
      uVar7 = (undefined)((ushort)puVar6 >> 8);
    }
    bVar11 = (char)uVar14 + 1;
    if ((byte)(uVar14 >> 0x20) <= bVar11) break;
    uVar14 = CONCAT44((int)(uVar14 >> 0x20),CONCAT22((short)(uVar14 >> 0x10) + 0x32,(ushort)bVar11))
    ;
    puVar8 = puVar8 + 0x28;
    puVar9 = puVar9 + 5;
  }
  puVar12 = (ushort *)((short)(uVar14 >> 0x30) + -0x14);
  uVar15 = CONCAT62((int6)(uVar14 >> 0x10),puVar12);
  dec_set_uint_small(puVar12,0);
  puVar9 = (undefined2 *)CONCAT11(uVar7,0x69);
  *(byte *)uVar15 = 0x69;
  matrix_op((byte *)uVar15,puVar9);
  bVar11 = ((byte *)uVar15 == (byte *)0x0) << 6;
  bVar3 = bcd_type((byte *)uVar15);
  if ((bVar11 >> 6 & 1) != 0) {
    bVar11 = 0;
    uVar2 = CONCAT42((int)((ulonglong)uVar15 >> 0x20),
                     *(short *)((short)((ulonglong)uVar15 >> 0x30) + -4) +
                     (ushort)(byte)((char)((ulonglong)uVar15 >> 0x20) - 1) * 0x32);
    while( true ) {
      lVar16 = (ulonglong)uVar2 << 0x10;
      uVar4 = dec_cmp((undefined2 *)uVar2,puVar9);
      if (((char)uVar4 != '\x01') ||
         (bVar11 = bVar11 + 1, (byte)((ulonglong)lVar16 >> 0x28) <= bVar11)) break;
      uVar2 = CONCAT42((int)((ulonglong)lVar16 >> 0x20),(short)((ulonglong)lVar16 >> 0x10) + 10);
    }
    bVar3 = (byte)((ulonglong)lVar16 >> 0x20);
    if (bVar11 == bVar3) {
LAB_rom_021114:
      bVar3 = 2;
    }
    else {
      if (bVar11 < bVar3) {
        if (bVar11 == (byte)(bVar3 - 1)) {
          return 3;
        }
      }
      else {
        uVar10 = (ushort)(byte)(bVar3 - 1);
        do {
          uVar10 = (ushort)(byte)((char)uVar10 - 1);
          uVar2 = CONCAT42((int)((ulonglong)lVar16 >> 0x20),
                           *(short *)((short)((ulonglong)lVar16 >> 0x30) + -4) + uVar10 * 0x32);
          while( true ) {
            lVar16 = (ulonglong)uVar2 << 0x10;
            uVar4 = dec_cmp((undefined2 *)uVar2,puVar9);
            if (((char)uVar4 != '\x01') ||
               (bVar11 = (char)(uVar10 >> 8) + 1, uVar10 = CONCAT11(bVar11,(char)uVar10),
               (byte)((ulonglong)lVar16 >> 0x28) <= bVar11)) break;
            uVar2 = CONCAT42((int)((ulonglong)lVar16 >> 0x20),
                             (short)((ulonglong)lVar16 >> 0x10) + 10);
          }
          bVar11 = (byte)(uVar10 >> 8);
          bVar3 = (byte)((ulonglong)lVar16 >> 0x20);
          if (bVar11 == bVar3) goto LAB_rom_021114;
        } while ((bVar3 <= bVar11) &&
                (bVar1 = (char)uVar10 == '\0', -1 < (char)(bVar1 << 6) && !bVar1));
      }
      bVar3 = 1;
    }
  }
  return bVar3;
}

/**
 * @brief 返回 *p 在 b 下的有效位数（0x1D37E 结果为 0 时用 p+4 的指数-0x10…
 * @addr 0x21122
 * @module strlib
 * @proto char dec_digit_count(undefined2* p, undefined2 b)
 * @confidence likely
 * @note 返回 *p 在 b 下的有效位数（0x1D37E 结果为 0 时用 p+4 的指数-0x10）。
 * @tag format
 */
char dec_digit_count(undefined2* p, undefined2 _a1)

{
  byte bVar1;
  char cVar2;
  undefined2 *unaff_ER12;
  
  bVar1 = dec_cmp_status(unaff_ER12,p);
  cVar2 = bVar1 - 1;
  if (bVar1 == 0) {
    cVar2 = *(char *)(unaff_ER12 + 4) + -0x10;
  }
  return cVar2;
}

/**
 * @brief 空函数（仅 return）
 * @addr 0x2113E
 * @module strlib
 * @proto int nop_rt_4(void)
 * @confidence verified
 * @note 空函数（仅 return）。
 * @tag util
 */
int nop_rt_4(void)

{
  return 0;
}

/**
 * @brief STAT 视图循环（与 0x2153C 类似的运算分派）
 * @addr 0x21140
 * @module strlib
 * @proto int stat_view_loop(void)
 * @confidence likely
 * @note STAT 视图循环（与 0x2153C 类似的运算分派）。
 * @tag stat
 */
int stat_view_loop(uintptr_t _a5, uintptr_t _a6, uintptr_t _a7, uintptr_t _a8, int _a1, int _a2, int _a3, int _a4)

{
  bool bVar1;
  int bVar2;
  int bVar3;
  undefined extraout_R1;
  undefined extraout_R1_00;
  undefined extraout_R1_01;
  undefined extraout_R1_02;
  byte extraout_R1_03;
  undefined extraout_R1_04;
  byte extraout_R1_05;
  undefined2 *puVar4;
  undefined2 uVar5;
  short sVar6;
  ushort uVar7;
  undefined extraout_R1_06;
  undefined8 *puVar8;
  undefined uVar9;
  char unaff_R6;
  undefined2 *unaff_ER12;
  undefined2 unaff_ER14;
  char cVar10;
  undefined8 uStack_26;
  undefined8 uStack_1c;
  undefined8 uStack_12;
  
  if (unaff_R6 != '\0') {
    return _a1;
  }
  bVar3 = 0;
  bVar2 = str_parse_number(_a2,_a4);
  uVar7 = CONCAT11(extraout_R1,bVar2);
  if ((char)bVar3 < '\0' || (bVar3 >> 6 & 1) != 0) {
    if ((bVar3 >> 6 & 1) == 0) {
      return uVar7;
    }
    bVar3 = bVar3 & 0x9f;
    bVar2 = str_parse_number(_a2,_a4);
    uVar7 = CONCAT11(extraout_R1_00,bVar2);
    if ((char)bVar3 < '\0' || (bVar3 >> 6 & 1) != 0) {
      if ((bVar3 >> 6 & 1) == 0) {
        return uVar7;
      }
      bVar2 = ((undefined *)0xfff5 < &uStack_26) << 7 | (&uStack_1c == (undefined8 *)0x0) << 6;
      stat_layout(&uStack_1c);
      bVar3 = str_parse_number(_a2,_a4);
      if ((char)bVar2 < '\0') {
        return CONCAT11(extraout_R1_01,bVar3);
      }
      if ((bVar2 >> 6 & 1) != 0) {
        dec_set_zero(CONCAT11(extraout_R1_01,bVar3));
      }
      matrix_prec();
      bVar1 = (char)_a2 == '\0';
      cVar10 = bVar1 << 6;
      uVar9 = extraout_R1_02;
      if (bVar1) {
        dec_digit_count(_a2, (uintptr_t)0);
        sVar6 = (ushort)extraout_R1_03 << 8;
        if (-1 < cVar10) {
          matrix_prec();
          bVar1 = (char)_a2 == '\0';
          cVar10 = bVar1 << 6;
          uVar9 = extraout_R1_04;
          if (!bVar1) goto LAB_rom_02124c;
          dec_digit_count(_a2, (uintptr_t)0);
          sVar6 = (ushort)extraout_R1_05 << 8;
          if (-1 < cVar10) {
            puVar4 = (undefined2 *)dec_cmp_signed(unaff_ER12,_a2);
            uVar5 = dec_cmp_signed(&uStack_1c,puVar4);
            sVar6 = dec_to_string(uVar5,puVar4);
            if ((char)sVar6 != '\x04') {
              screen_mode_blank(sVar6);
              stat_layout(&uStack_12);
              stat_cell_read((undefined8 *)0x1b62);
              puVar8 = &uStack_1c;
              input_clear8(unaff_ER14,(undefined *)puVar8);
              while( true ) {
                uVar7 = kbd_wait_key();
                if ((char)uVar7 != '\0') {
                  return uVar7;
                }
                bVar3 = 0;
                bVar2 = str_parse_number((ushort)puVar8,_a3);
                if ((bVar3 >> 6 & 1) == 0) {
                  return CONCAT11(extraout_R1_06,bVar2);
                }
                puVar4 = unaff_ER12;
                dec_bin_div((undefined2 *)&uStack_26,unaff_ER12);
                uVar7 = dec_cmp_ex((undefined2 *)&uStack_26,puVar4);
                if ((char)uVar7 != '\0') {
                  return uVar7;
                }
                uVar5 = dec_to_string(0xd36a,(undefined2 *)&uStack_12);
                if ((char)uVar5 == '\x01') break;
                puVar8 = (undefined8 *)0x1b6c;
                dec_bin_div((undefined2 *)0xd36a,(undefined2 *)0x1b6c);
              }
              puVar8 = stat_layout2(&uStack_26);
              return (ushort)puVar8 & 0xff00;
            }
          }
        }
        return CONCAT11((char)((ushort)sVar6 >> 8),8);
      }
LAB_rom_02124c:
      return CONCAT11(uVar9,3);
    }
  }
  return CONCAT11((char)(uVar7 >> 8),2);
}

/**
 * @brief 把数字 d 转成 10 的幂形式后在 BCD 中相乘（d+0xAA / d+0xA0 影射）
 * @addr 0x21250
 * @module strlib
 * @proto void fmt_pow10_digit(undefined2 x, undefined2 d)
 * @confidence likely
 * @note 把数字 d 转成 10 的幂形式后在 BCD 中相乘（d+0xAA / d+0xA0 影射）。
 * @tag format
 */
int fmt_pow10_digit(undefined2 x, undefined2 d)

{
  byte bVar1;
  char cVar3;
  undefined2 uVar2;
  undefined8 *unaff_ER8;
  
  bVar1 = (byte)d;
  cVar3 = (char)((ushort)d >> 8);
  uVar2 = CONCAT11(cVar3 + (0x55 < bVar1),bVar1 + 0xaa);
  stat_cell_read(unaff_ER8);
  dec_bin_pow_core(uVar2,CONCAT11(cVar3 + (0x5f < bVar1),bVar1 + 0xa0));
  dec_bin_div_core(x,CONCAT11(cVar3 + (0x55 < bVar1),bVar1 + 0xaa));
  return 0;
}

/**
 * @brief 统计编辑主流程（1.9KB，0x21342 调用）
 * @addr 0x21280
 * @module strlib
 * @proto void stat_entry_main(void)
 * @confidence likely
 * @note 统计编辑主流程（1.9KB，0x21342 调用）。
 * @tag app
 */
int stat_entry_main(uintptr_t _a3, uintptr_t _a4, int _a1, int _a2)

{
  ushort uVar1;
  undefined2 uVar2;
  byte bVar3;
  char cVar6;
  undefined2 uVar4;
  undefined *puVar5;
  undefined8 *unaff_ER8;
  undefined2 unaff_ER12;
  byte bVar7;
  
  bVar3 = (byte)_a1;
  cVar6 = (char)((ushort)_a1 >> 8);
  uVar2 = CONCAT11(cVar6 + (0x5f < bVar3),bVar3 + 0xa0);
  stat_cell_read(unaff_ER8);
  dec_bin_pow_core(uVar2,CONCAT11(cVar6 + (0x87 < bVar3),bVar3 + 0x78));
  uVar2 = stat_cell_read((undefined8 *)CONCAT11(cVar6 + (0x5f < bVar3),bVar3 + 0xa0));
  uVar4 = CONCAT11(cVar6 + (0x7d < bVar3),bVar3 + 0x82);
  dec_bin_mul_core(uVar2,uVar4);
  uVar2 = dec_inc5((undefined2 *)CONCAT11(cVar6 + (0x5f < bVar3),bVar3 + 0xa0),uVar4);
  puVar5 = (undefined *)CONCAT11(cVar6 + (0x5f < bVar3),bVar3 + 0xa0);
  while( true ) {
    input_clear8(uVar2,puVar5);
    bVar7 = 0;
    str_parse_number((ushort)puVar5,_a2);
    if ((bVar7 >> 6 & 1) == 0) {
      return 0;
    }
    uVar1 = (ushort)unaff_ER8 & 1;
    unaff_ER8 = (undefined8 *)(ushort)(byte)((byte)unaff_ER8 | 1);
    if (uVar1 != 0) break;
    stat_layout((undefined8 *)CONCAT11(cVar6 + (0x5f < bVar3),bVar3 + 0xa0));
    uVar2 = dec_bin_div_core(CONCAT11(cVar6 + (0x55 < bVar3),bVar3 + 0xaa), (uintptr_t)0)
                           CONCAT11(cVar6 + (0x7d < bVar3),bVar3 + 0x82));
    if ((char)uVar2 != '\0') {
      return 0;
    }
    puVar5 = (undefined *)CONCAT11(cVar6 + (0x55 < bVar3),bVar3 + 0xaa);
  }
  dec_bin_div_core(CONCAT11(cVar6 + (0x5f < bVar3),bVar3 + 0xa0),unaff_ER12);
  dec_cmp_ex((undefined2 *)CONCAT11(cVar6 + (0x5f < bVar3),bVar3 + 0xa0),unaff_ER12);
  return 0;
}

/**
 * @brief 统计编辑主体（2.8KB，0x2153C 调用）
 * @addr 0x21342
 * @module strlib
 * @proto int stat_edit_main(void)
 * @confidence likely
 * @note 统计编辑主体（2.8KB，0x2153C 调用）。
 * @tag app
 */
int stat_edit_main(uintptr_t _a4, uintptr_t _a5, uintptr_t _a6, int _a1, int _a2, int _a3)

{
  bool bVar1;
  char cVar2;
  char cVar3;
  undefined8 *puVar4;
  undefined2 uVar5;
  int sVar6;
  undefined2 *puVar7;
  byte extraout_R1;
  undefined extraout_R1_00;
  undefined extraout_R1_01;
  undefined extraout_R1_02;
  undefined uVar10;
  undefined2 uVar8;
  undefined *puVar9;
  short unaff_ER8;
  undefined2 unaff_ER12;
  byte bVar11;
  
  uVar10 = (undefined)((ushort)_a1 >> 8);
  nxsb_test(0x28);
  puVar4 = (undefined8 *)nxsb_clear();
  stat_cell_read(puVar4);
  uVar8 = CONCAT11(uVar10,0x1e);
  uVar5 = nxsb_clear();
  dec_bin_mul_core(uVar5,uVar8);
  sVar6 = nxsb_test(0x78);
  uVar5 = 0x1b76;
  dec_bin_and_core(sVar6,0x1b76);
  puVar7 = (undefined2 *)nxsb_test(0x78);
  sVar6 = dec_cmp(puVar7,uVar5);
  uVar10 = (undefined)((ushort)uVar5 >> 8);
  if (((char)sVar6 != -0x10) && ((char)sVar6 != '\x01')) {
    nxsb_test(0x28);
    puVar4 = (undefined8 *)nxsb_clear();
    stat_cell_read(puVar4);
    uVar8 = CONCAT11(uVar10,0x1e);
    uVar5 = nxsb_clear();
    dec_bin_div_core(uVar5,uVar8);
    sVar6 = nxsb_test(0x82);
    uVar10 = 0x1b;
    sVar6 = dec_bin_and_core(sVar6,0x1b76);
    if ((char)sVar6 != '\x03') {
      puVar9 = (undefined *)CONCAT11(uVar10,0x82);
      uVar5 = nxsb_clear();
      input_clear8(uVar5,puVar9);
      bVar11 = 0;
      str_parse_number((ushort)puVar9,_a3);
      sVar6 = (ushort)extraout_R1 << 8;
      if ((bVar11 >> 6 & 1) != 0) {
        uVar8 = CONCAT11((char)((ushort)puVar9 >> 8),0x8c);
        puVar4 = (undefined8 *)nxsb_clear();
        stat_cell_read(puVar4);
        uVar5 = unaff_ER12;
        dec_bin_pow_core(uVar8,unaff_ER12);
        uVar5 = CONCAT11((char)((ushort)uVar5 >> 8),0x96);
        puVar4 = (undefined8 *)nxsb_clear();
        stat_cell_read(puVar4);
        dec_bin_pow_core(uVar5,unaff_ER12);
        do {
          uVar5 = kbd_wait_key();
          bVar1 = (char)uVar5 == '\0';
          bVar11 = bVar1 << 6;
          if (!bVar1) {
            return uVar5;
          }
          sVar6 = unaff_ER8;
          stat_entry_main(unaff_ER8,_a2);
          uVar10 = extraout_R1_00;
          if ((bVar11 >> 6 & 1) == 0) break;
          cVar3 = (byte)unaff_ER8 + 0x96;
          cVar2 = (char)((ushort)unaff_ER8 >> 8) + (0x69 < (byte)unaff_ER8);
          bVar11 = (cVar3 == '\0' && cVar2 == '\0') << 6;
          fmt_pow10_digit(CONCAT11(cVar2,cVar3),sVar6);
          uVar10 = extraout_R1_01;
          if ((bVar11 >> 6 & 1) == 0) break;
          bVar11 = (unaff_ER8 + 0x8c == 0) << 6;
          fmt_pow10_digit(unaff_ER8 + 0x8c,unaff_ER8);
          uVar10 = extraout_R1_02;
        } while ((bVar11 >> 6 & 1) != 0);
        goto LAB_rom_02145c;
      }
    }
  }
  uVar10 = (undefined)((ushort)sVar6 >> 8);
LAB_rom_02145c:
  return CONCAT11(uVar10,3);
}

/**
 * @brief 从矩阵单元提取数值（0x2196A 位测试后 0x1C35C 等）
 * @addr 0x214DE
 * @module strlib
 * @proto int mat_cell_extract(ushort sel)
 * @confidence likely
 * @note 从矩阵单元提取数值（0x2196A 位测试后 0x1C35C 等）。
 * @tag matrix
 */
int mat_cell_extract(ushort sel)

{
  undefined8 *puVar1;
  undefined2 uVar2;
  undefined uVar6;
  undefined2 *puVar3;
  undefined2 *puVar4;
  undefined2 uVar5;
  ushort auStack_10 [4];
  undefined2 uStack_8;
  
  uVar6 = (undefined)((ushort)sel >> 8);
  nxsb_test(0x14);
  puVar3 = (undefined2 *)CONCAT11(uVar6,0x8c);
  puVar1 = (undefined8 *)nxsb_clear();
  puVar4 = puVar3;
  stat_layout2(puVar1);
  uVar5 = CONCAT11((char)((ushort)puVar4 >> 8),0x96);
  uVar2 = nxsb_clear();
  uVar2 = dec_bin_pow_core(uVar2,uVar5);
  if ((char)uVar2 == '\0') {
    dec_bin_result(auStack_10,uVar5);
    if (((char)((ushort)uStack_8 >> 8) == '\0') && ((byte)uStack_8 < 0x90)) {
      stat_cell_read((undefined8 *)0x1b6c);
      uStack_8 = 0x90;
    }
    uVar2 = dec_round_scaled(auStack_10,puVar3);
  }
  else {
    uVar2 = CONCAT11((char)((ushort)uVar2 >> 8),4);
  }
  return uVar2;
}

/**
 * @brief STAT 编辑界面（大量十进制运算入口）
 * @addr 0x2153C
 * @module strlib
 * @proto int stat_editor(void)
 * @confidence strong
 * @note STAT 编辑界面（大量十进制运算入口）。
 * @tag stat
 */
int stat_editor(uintptr_t _a3, uintptr_t _a4, int _a1, int _a2)

{
  bool bVar1;
  int bVar2;
  int cVar3;
  undefined extraout_R1;
  undefined extraout_R1_00;
  undefined8 *puVar4;
  undefined extraout_R1_01;
  undefined extraout_R1_02;
  undefined extraout_R1_03;
  undefined2 *puVar5;
  undefined2 uVar6;
  byte extraout_R1_04;
  byte extraout_R1_05;
  byte extraout_R1_06;
  byte extraout_R1_07;
  int sVar7;
  undefined *puVar8;
  short *psVar9;
  char *pcVar10;
  ushort uVar11;
  undefined uVar14;
  short sVar12;
  undefined2 uVar13;
  char unaff_R6;
  undefined2 *unaff_ER12;
  undefined2 unaff_ER14;
  byte bVar15;
  undefined2 *in_stack_0000ff5e;
  undefined2 *in_stack_0000ff68;
  undefined2 *in_stack_0000ff70;
  
  bVar15 = 0;
  if (unaff_R6 != '\0') {
    return _a1;
  }
  screen_mode_blank(_a1);
  bVar15 = bVar15 & 0x9f;
  bVar2 = str_parse_number(_a2,in_stack_0000ff70);
  uVar11 = CONCAT11(extraout_R1,bVar2);
  if (-1 < (char)bVar15 && (bVar15 >> 6 & 1) != 1) {
LAB_rom_021954:
    return CONCAT11((char)(uVar11 >> 8),2);
  }
  if ((bVar15 >> 6 & 1) != 1) {
    return uVar11;
  }
  bVar15 = bVar15 & 0x9f;
  bVar2 = str_parse_number(_a2,in_stack_0000ff70);
  uVar11 = CONCAT11(extraout_R1_00,bVar2);
  if (-1 < (char)bVar15 && (bVar15 >> 6 & 1) != 1) goto LAB_rom_021954;
  if ((bVar15 >> 6 & 1) != 1) {
    return uVar11;
  }
  bVar15 = bVar15 & 0x9f;
  dec_cmp_signed(unaff_ER12,_a2);
  bVar15 = bVar15 & 0x9f;
  puVar4 = (undefined8 *)nxsb_test(0);
  stat_layout(puVar4);
  bVar2 = str_parse_number(_a2,in_stack_0000ff70);
  if ((char)bVar15 < '\0') {
    return CONCAT11(extraout_R1_01,bVar2);
  }
  uVar11 = CONCAT11((char)((uint32_t)_a2 >> 8),bVar2);
  dec_cmp_signed(unaff_ER12,uVar11);
  puVar4 = (undefined8 *)nxsb_test(10);
  stat_layout(puVar4);
  cVar3 = (char)uVar11;
  bVar15 = (cVar3 != -1) << 7 | (cVar3 == -1) << 6;
  if (cVar3 == -1) {
LAB_rom_0215e2:
    uVar14 = (undefined)(uVar11 >> 8);
    stat_layout2((undefined8 *)0x1b6c);
    unaff_ER12[4] = 0x95;
  }
  else {
    bVar2 = str_parse_number(uVar11,in_stack_0000ff70);
    if ((char)bVar15 < '\0') {
      return CONCAT11(extraout_R1_02,bVar2);
    }
    if ((bVar15 >> 6 & 1) != 0) {
      dec_set_zero(CONCAT11(extraout_R1_02,bVar2));
    }
    matrix_prec();
    if ((char)uVar11 != '\0') {
      return CONCAT11(extraout_R1_03,3);
    }
    puVar5 = (undefined2 *)dec_cmp_signed(unaff_ER12,uVar11);
    uVar6 = dec_cmp(puVar5,uVar11);
    uVar14 = (undefined)(uVar11 >> 8);
    if ((char)uVar6 != '\x04') {
      return CONCAT11((char)((ushort)uVar6 >> 8),8);
    }
    if ((edit_state2 & 0x40) != 0) goto LAB_rom_0215e2;
  }
  puVar4 = (undefined8 *)nxsb_test(0x14);
  stat_layout(puVar4);
  puVar5 = (undefined2 *)nxsb_test(0xbe);
  *puVar5 = unaff_ER14;
  nxsb_test(0);
  puVar5 = (undefined2 *)CONCAT11(uVar14,10);
  uVar6 = nxsb_clear();
  uVar6 = dec_round_scaled(uVar6,puVar5);
  bVar15 = (byte)((ushort)puVar5 >> 8);
  if ((char)uVar6 == '\x01') {
    puVar8 = (undefined *)CONCAT11(bVar15,10);
    uVar6 = nxsb_clear();
    input_clear8(uVar6,puVar8);
    bVar15 = 0;
    str_parse_number((ushort)puVar8,in_stack_0000ff70);
    sVar7 = (ushort)extraout_R1_04 << 8;
    if ((bVar15 >> 6 & 1) != 1) {
LAB_rom_021950:
      return CONCAT11((char)((ushort)sVar7 >> 8),3);
    }
    puVar8 = (undefined *)((ushort)puVar8 & 0xff00);
    uVar6 = nxsb_clear();
    input_clear8(uVar6,puVar8);
    bVar15 = 0;
    str_parse_number((ushort)puVar8,in_stack_0000ff70);
    sVar7 = (ushort)extraout_R1_05 << 8;
    if ((bVar15 >> 6 & 1) != 1) goto LAB_rom_021950;
    stat_layout2((undefined8 *)0x1b62);
  }
  else {
    puVar8 = (undefined *)((ushort)bVar15 << 8);
    uVar6 = nxsb_clear();
    input_clear8(uVar6,puVar8);
    bVar15 = 0;
    str_parse_number((ushort)puVar8,in_stack_0000ff70);
    sVar7 = (ushort)extraout_R1_06 << 8;
    if ((bVar15 >> 6 & 1) != 1) goto LAB_rom_021950;
    puVar8 = (undefined *)CONCAT11((char)((ushort)puVar8 >> 8),10);
    uVar6 = nxsb_clear();
    input_clear8(uVar6,puVar8);
    bVar15 = 0;
    str_parse_number((ushort)puVar8,in_stack_0000ff70);
    uVar14 = (undefined)((ushort)puVar8 >> 8);
    sVar7 = (ushort)extraout_R1_07 << 8;
    if ((bVar15 >> 6 & 1) != 1) goto LAB_rom_021950;
    nxsb_test(0);
    sVar12 = CONCAT11(uVar14,0x1e);
    puVar4 = (undefined8 *)nxsb_clear();
    sVar7 = stat_cell_read(puVar4);
    uVar14 = (undefined)((ushort)(sVar12 + 10) >> 8);
    stat_cell_read((undefined8 *)(sVar7 + 10));
    sVar12 = CONCAT11(uVar14,0x3c);
    puVar4 = (undefined8 *)nxsb_clear();
    sVar7 = stat_cell_read(puVar4);
    sVar12 = sVar12 + 0x14;
    puVar4 = (undefined8 *)stat_cell_read((undefined8 *)(sVar7 + 10));
    uVar14 = (undefined)((ushort)(sVar12 + 10) >> 8);
    stat_cell_read(puVar4);
    puVar8 = (undefined *)nxsb_test(0xc3);
    *puVar8 = 0x2f;
    puVar5 = (undefined2 *)CONCAT11(uVar14,0xc0);
    uVar6 = nxsb_clear();
    *puVar5 = uVar6;
    nxsb_test(10);
    bVar15 = (byte)((ushort)puVar5 >> 8);
    puVar4 = (undefined8 *)nxsb_clear();
    stat_cell_read(puVar4);
    puVar8 = (undefined *)((ushort)bVar15 << 8);
    uVar6 = nxsb_clear();
    sVar7 = dec_bin_mul_core(uVar6,puVar8);
    bVar1 = (char)sVar7 == '\x03';
    bVar15 = bVar1 << 6;
    if (bVar1) goto LAB_rom_021950;
    sVar7 = stat_edit_main(puVar8,in_stack_0000ff5e,in_stack_0000ff68);
    if ((bVar15 >> 6 & 1) != 1) {
LAB_rom_02194c:
      if ((char)sVar7 != '\x01') goto LAB_rom_021950;
      goto LAB_rom_021942;
    }
    uVar6 = mat_cell_extract(puVar8);
    if ((char)uVar6 != '\x04') {
LAB_rom_021718:
      do {
        psVar9 = (short *)nxsb_test(0xc0);
        sVar7 = *psVar9 + -1;
        bVar15 = (sVar7 == 0) << 6;
        *psVar9 = sVar7;
        if (sVar7 == 0) {
LAB_rom_021784:
          return CONCAT11((char)((ushort)sVar7 >> 8),0xb);
        }
        sVar7 = stat_edit_main(puVar8,in_stack_0000ff5e,in_stack_0000ff68);
        if ((bVar15 >> 6 & 1) != 1) goto LAB_rom_02194c;
        uVar6 = mat_cell_extract(puVar8);
        uVar14 = (undefined)((ushort)puVar8 >> 8);
        if ((char)uVar6 != '\x02') {
LAB_rom_02180c:
          nxsb_test(0x3c);
          uVar13 = CONCAT11(uVar14,0x96);
          uVar6 = nxsb_clear();
          sVar7 = dec_bin_div_core(uVar6,uVar13);
          cVar3 = (char)sVar7;
          while( true ) {
            if (cVar3 == '\x03') goto LAB_rom_021950;
            sVar7 = nxsb_test(0x50);
            puVar8 = (undefined *)0x1b6c;
            uVar6 = dec_round_scaled(sVar7,(undefined2 *)0x1b6c);
            if ((char)uVar6 == '\x01') {
              puVar4 = (undefined8 *)nxsb_test(0x3c);
              stat_layout2(puVar4);
              goto LAB_rom_02193a;
            }
            puVar5 = (undefined2 *)nxsb_test(0x50);
            cVar3 = dec_from_integer(puVar5,puVar8);
            if (cVar3 == '\0') break;
            pcVar10 = (char *)nxsb_test(0xc3);
            *pcVar10 = *pcVar10 + '\x01';
            sVar7 = nxsb_test(0x5a);
            dec_bin_and_core(sVar7,0x1b76);
            sVar7 = nxsb_test(0x50);
            dec_bin_mul_core(sVar7,0x1b6c);
            uVar14 = 0x1b;
            dec_bin_and_core(sVar7,0x1b76);
            nxsb_test(0x50);
            puVar4 = (undefined8 *)nxsb_clear();
            stat_cell_read(puVar4);
            uVar13 = CONCAT11(uVar14,0x5a);
            uVar6 = nxsb_clear();
            dec_bin_mul_core(uVar6,uVar13);
            dec_bin_and_core(uVar6,uVar13);
            uVar14 = (undefined)((ushort)uVar13 >> 8);
            nxsb_test(0x1e);
            uVar13 = CONCAT11(uVar14,0x6e);
            uVar6 = nxsb_clear();
            dec_bin_pow_core(uVar6,uVar13);
            bVar15 = (byte)((ushort)uVar13 >> 8);
            nxsb_test(0x1e);
            sVar7 = (ushort)bVar15 << 8;
            uVar6 = nxsb_clear();
            sVar7 = dec_bin_div_core(uVar6,sVar7);
            cVar3 = (char)sVar7;
          }
          sVar7 = nxsb_test(0x50);
          dec_bin_div_core(sVar7,0x1b6c);
          nxsb_test(0x28);
          puVar4 = (undefined8 *)nxsb_clear();
          uVar6 = stat_cell_read(puVar4);
          puVar4 = (undefined8 *)nxsb_test(0x50);
          stat_cell_read(puVar4);
          uVar14 = 0x1b;
          dec_bin_div_core(uVar6,0x1b6c);
          nxsb_test(0x28);
          uVar13 = CONCAT11(uVar14,0x5a);
          uVar6 = nxsb_clear();
          dec_bin_mul_core(uVar6,uVar13);
          dec_bin_and_core(uVar6,uVar13);
          uVar14 = (undefined)((ushort)uVar13 >> 8);
          nxsb_test(0x28);
          uVar13 = CONCAT11(uVar14,0x6e);
          uVar6 = nxsb_clear();
          dec_bin_pow_core(uVar6,uVar13);
          bVar15 = (byte)((ushort)uVar13 >> 8);
          nxsb_test(0x28);
          puVar8 = (undefined *)((ushort)bVar15 << 8);
          uVar6 = nxsb_clear();
          dec_bin_div_core(uVar6,puVar8);
          goto LAB_rom_021718;
        }
        sVar7 = nxsb_test(0x5a);
        uVar14 = 0x1b;
        dec_bin_pow_core(sVar7,0x1b76);
        pcVar10 = (char *)nxsb_test(0xc3);
        cVar3 = *pcVar10;
        *pcVar10 = cVar3 + -1;
        if ((char)(cVar3 + -1) == '\0') {
          nxsb_test(0x3c);
          puVar4 = (undefined8 *)nxsb_clear();
          stat_cell_read(puVar4);
          uVar13 = CONCAT11(uVar14,0x96);
          uVar6 = nxsb_clear();
          dec_bin_div_core(uVar6,uVar13);
          uVar14 = (undefined)((ushort)uVar13 >> 8);
          nxsb_test(0xa0);
          puVar5 = (undefined2 *)CONCAT11(uVar14,0x3c);
          uVar6 = nxsb_clear();
          sVar7 = dec_to_string(uVar6,puVar5);
          if ((char)sVar7 != '\x01') goto LAB_rom_021784;
          pcVar10 = (char *)nxsb_test(0xc3);
          *pcVar10 = *pcVar10 + '\x01';
          sVar7 = nxsb_test(0x5a);
          uVar14 = 0x1b;
          dec_bin_and_core(sVar7,0x1b76);
          goto LAB_rom_02180c;
        }
        sVar7 = nxsb_test(0x50);
        uVar14 = 0x1b;
        dec_bin_pow_core(sVar7,0x1b76);
        nxsb_test(0x50);
        uVar6 = CONCAT11(uVar14,0x28);
        puVar4 = (undefined8 *)nxsb_clear();
        stat_cell_read(puVar4);
        uVar14 = 0x1b;
        dec_bin_div_core(uVar6,0x1b6c);
        nxsb_test(0x28);
        uVar13 = CONCAT11(uVar14,0x5a);
        uVar6 = nxsb_clear();
        dec_bin_mul_core(uVar6,uVar13);
        dec_bin_and_core(uVar6,uVar13);
        uVar14 = (undefined)((ushort)uVar13 >> 8);
        nxsb_test(0x28);
        uVar13 = CONCAT11(uVar14,0x6e);
        uVar6 = nxsb_clear();
        dec_bin_pow_core(uVar6,uVar13);
        bVar15 = (byte)((ushort)uVar13 >> 8);
        nxsb_test(0x28);
        puVar8 = (undefined *)((ushort)bVar15 << 8);
        uVar6 = nxsb_clear();
        sVar7 = dec_bin_div_core(uVar6,puVar8);
      } while ((char)sVar7 != '\x03');
      goto LAB_rom_021950;
    }
    puVar4 = (undefined8 *)nxsb_test(0x96);
    stat_layout2(puVar4);
  }
LAB_rom_02193a:
  dec_cmp_ex(unaff_ER12,puVar8);
LAB_rom_021942:
  uVar11 = nxsb_clear();
  return uVar11;
}

