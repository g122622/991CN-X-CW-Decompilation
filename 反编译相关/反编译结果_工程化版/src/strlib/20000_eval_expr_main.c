/*
 * 字符串与格式化 / 20000_eval_expr_main.c
 * 地址范围: 0x20000 - 0x206E4
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 表达式求值主流程（4.1KB，0x2021C 入口）
 * @addr 0x20000
 * @module strlib
 * @proto void eval_expr_main(void)
 * @confidence strong
 * @note 表达式求值主流程（4.1KB，0x2021C 入口）。
 * @tag eval
 */
int eval_expr_main(uintptr_t _a2, int _a1)

{
  bool bVar1;
  bool bVar2;
  char cVar3;
  short sVar4;
  undefined2 uVar5;
  undefined extraout_R1;
  ushort uVar6;
  undefined2 *puVar7;
  undefined2 *puVar8;
  undefined2 *puVar9;
  byte bVar10;
  byte bVar11;
  undefined2 *unaff_ER10;
  undefined2 *unaff_ER12;
  undefined2 *puVar12;
  
  sVar4 = copy_from_ER12_to(unaff_ER12 + 0x14,_a1);
  sVar4 = copy_from_ER12_to(sVar4 + -0x1e,_a1);
  copy_from_ER12_to(sVar4 + 10,_a1);
  bVar11 = (byte)unaff_ER12[4];
  bVar10 = das(bVar11 - 0x13);
  das((char)((ushort)unaff_ER12[4] >> 8) - (bVar11 < 0x13));
  puVar7 = unaff_ER12 + 0xf;
  dec_copy_ret((undefined2 *)0x1b8a,puVar7);
  puVar7[4] = (ushort)bVar10;
  dec_bin_or_core(unaff_ER12 + 10,puVar7);
  dec_bin_xor_core(unaff_ER12 + 5,puVar7);
  uVar5 = copy_from_ER12_to(unaff_ER10,puVar7);
  dec_unary_cos(uVar5,puVar7);
  bVar1 = false;
  do {
    puVar12 = unaff_ER12;
    unaff_ER12 = puVar12 + 5;
    decm_round10(unaff_ER12,puVar7);
    uVar6 = CONCAT11(extraout_R1,*(byte *)(puVar12 + 9));
    if (*(byte *)(puVar12 + 9) < 0x56) goto LAB_rom_0201f6;
    bVar2 = !bVar1;
    bVar1 = true;
  } while (bVar2);
  uVar6 = dec_to_string(unaff_ER12,puVar12);
  if ((char)uVar6 != '\x04') {
    bVar11 = 0;
    puVar7 = puVar12 + 10;
    dec_copy_ret((undefined2 *)0x1b6c,puVar7);
    puVar9 = unaff_ER10 + 5;
    copy_from_ER12_to(puVar9,puVar7);
    while( true ) {
      dec_abs_wrap();
      bVar11 = bVar11 + 1;
      if ((bVar11 == 0x15) || (*(char *)(puVar12 + 10) == '\0')) break;
      puVar9 = puVar9 + 5;
      puVar7 = dec_copy_ret(puVar12 + 10,puVar9);
      dec_copy_ret(unaff_ER12,puVar7);
      dec_copy_ret(puVar9,unaff_ER12);
    }
    puVar7 = puVar12 + 10;
    dec_copy_ret((undefined2 *)0x1b6c,puVar7);
    puVar7 = puVar7 + -5;
    dec_copy_ret(puVar12,puVar7);
    puVar9 = unaff_ER10 + 5;
    bVar10 = 0;
    while( true ) {
      dec_abs_wrap();
      uVar6 = dec_to_string(puVar7,puVar9);
      if ((char)uVar6 != '\x01') break;
      if (((byte)(bVar10 + 1) == bVar11) ||
         (uVar6 = CONCAT11((char)(uVar6 >> 8),*(char *)(puVar12 + 10)),
         *(char *)(puVar12 + 10) == '\0')) goto LAB_rom_02016c;
      puVar9 = puVar9 + 5;
      puVar8 = dec_copy_ret(puVar12 + 10,puVar7);
      dec_copy_ret(puVar12,puVar8);
      dec_copy_ret(puVar7,puVar12);
      bVar10 = bVar10 + 1;
    }
    if ((bVar10 & 1) == 0) {
      dec_bin_or_core(puVar9,puVar7);
      puVar7 = dec_copy_ret(puVar7,puVar9);
      uVar6 = CONCAT11((char)((ushort)puVar7 >> 8),*(char *)(puVar12 + 10));
      if (*(char *)(puVar12 + 10) != '\0') {
        uVar6 = dec_bin_xor_core(puVar9,(undefined2 *)0x1b6c);
      }
    }
    else {
      uVar6 = dec_bin_or_core(puVar7,puVar9);
      if ((byte)(bVar11 - bVar10) != '\x01') {
        uVar6 = dec_bin_xor_core(puVar9,(undefined2 *)0x1b6c);
      }
    }
LAB_rom_02016c:
    bVar10 = bVar10 + 1;
    puVar7 = unaff_ER10 + (ushort)bVar10 * 5;
    if (bVar10 < 0x15) {
      puVar9 = puVar12;
      dec_copy_ret((undefined2 *)0x1b6c,puVar12);
      dec_copy_ret(puVar7,puVar9 + 5);
      while (bVar10 = bVar10 - 1, bVar10 != 0) {
        puVar7 = puVar7 + -5;
        puVar9 = puVar12 + 10;
        dec_copy_ret(puVar12 + 5,puVar9);
        dec_bin_pow_core(puVar9,puVar7);
        dec_bin_xor_core(puVar12 + 10,puVar12);
        puVar9 = puVar12;
        puVar8 = dec_copy_ret(puVar12 + 5,puVar12);
        dec_copy_ret(puVar8 + 5,puVar9 + 5);
      }
      cVar3 = *(char *)unaff_ER10;
      if (cVar3 != '\0') {
        cVar3 = *(char *)(unaff_ER10 + 4) + '\x02';
      }
      bVar11 = *(byte *)(puVar12 + 4);
      uVar6 = CONCAT11(bVar11,cVar3);
      if (bVar11 < 8) {
        bVar10 = *(byte *)(puVar12 + 9);
        uVar6 = CONCAT11(bVar10,cVar3 + bVar11);
        if ((bVar10 < 8) &&
           (bVar11 = cVar3 + bVar11 + bVar10, uVar6 = CONCAT11(bVar10,bVar11), bVar11 < 8)) {
          puVar7 = dec_copy_ret(unaff_ER10,puVar12 + -5);
          return CONCAT11((char)((ushort)puVar7 >> 8),1);
        }
      }
    }
  }
LAB_rom_0201f6:
  return uVar6 & 0xff00;
}

/**
 * @brief 格式化前处理
 * @addr 0x201FE
 * @module strlib
 * @proto void fmt_exp_set(undefined2* x, undefined2 y)
 * @confidence likely
 * @note 格式化前处理：把 *x 偏移 7 处的指数记号夹到 0x99，调用 0x1D7B0 后再 0x1D37E。
 * @tag format
 */
int fmt_exp_set(undefined2* x, undefined2 _a1)

{
  undefined uVar1;
  undefined2 *unaff_ER12;
  
  uVar1 = 0;
  if (0x4f < *(byte *)((short)unaff_ER12 + 7)) {
    uVar1 = 0x99;
  }
  *(undefined *)((short)unaff_ER12 + 7) = uVar1;
  dec_cmp_ex(unaff_ER12,x);
  dec_cmp_status(unaff_ER12,x);
  return 0;
}

/**
 * @brief 数值格式化主例程
 * @addr 0x2021C
 * @module strlib
 * @proto undefined2* fmt_number_core(undefined2* x)
 * @confidence strong
 * @note 数值格式化主例程：处理指数档位（-5 偏移）、调用 0x20000/0x201FE 生成数字串。
 * @tag format
 */
undefined2* fmt_number_core(undefined2* x)

{
  undefined2 *puVar1;
  undefined extraout_R1;
  byte bVar2;
  undefined2 *puVar3;
  byte bVar4;
  undefined2 *puVar5;
  
  bVar4 = *(byte *)((short)x + 9);
  bVar2 = bVar4;
  if (4 < bVar4) {
    bVar2 = bVar4 - 5;
    *(byte *)((short)x + 9) = bVar2;
  }
  puVar5 = x;
  if (bVar2 == 0) {
    if (0x91 < *(byte *)(x + 4)) {
LAB_rom_020246:
      puVar1 = x + 0x14;
      dec_copy_ret(x,puVar1);
      bVar2 = (puVar5 == (undefined2 *)0xffd8) << 6;
      x = (undefined2 *)fmt_exp_set(puVar1, (uintptr_t)0);
      if ((bVar2 >> 6 & 1) != 0) {
        copy_to_ER12(puVar5 + 0x14,puVar1);
        puVar3 = puVar5 + 5;
        puVar1 = dec_copy_ret((undefined2 *)0x1b62,puVar3);
        puVar3 = puVar3 + 5;
        puVar1 = dec_copy_ret(puVar1 + 5,puVar3);
LAB_rom_020276:
        if (bVar4 < 5) {
          return (undefined2 *)CONCAT11((char)((ushort)puVar1 >> 8),1);
        }
        dec_inc5(puVar5,puVar3);
        dec_inc5(puVar5 + 5,puVar3);
        return (undefined2 *)CONCAT11(extraout_R1,1);
      }
      puVar3 = (undefined2 *)puVar5[4];
      if (((char)((ushort)puVar3 >> 8) == '\0') || ((byte)puVar3 < 6)) {
        puVar1 = (undefined2 *)eval_expr_main(puVar3);
        if ((char)puVar1 == '\x01') goto LAB_rom_020276;
        goto LAB_rom_0202ac;
      }
    }
  }
  else if (*(byte *)(x + 4) < 7) goto LAB_rom_020246;
  puVar1 = (undefined2 *)CONCAT11((char)((ushort)x >> 8),0xff);
LAB_rom_0202ac:
  *(byte *)((short)puVar5 + 9) = bVar4;
  return puVar1;
}

/**
 * @brief 调用 0x2021C 检查格式
 * @addr 0x202B8
 * @module strlib
 * @proto ushort fmt_check(undefined2* x)
 * @confidence strong
 * @note 调用 0x2021C 检查格式；返回 -1 时只保留高字节。
 * @tag format
 */
ushort fmt_check(undefined2* x)

{
  ushort uVar1;
  
  uVar1 = fmt_number_core(x);
  if ((char)uVar1 == -1) {
    uVar1 = uVar1 & 0xff00;
  }
  return uVar1;
}

/**
 * @brief 空指针安全的 strlen（= strlen(s) 或 0）
 * @addr 0x203B8
 * @module strlib
 * @proto ushort strlen_checked(char* s)
 * @confidence verified
 * @note 空指针安全的 strlen（= strlen(s) 或 0）。
 * @tag libc
 */
ushort strlen_checked(char* s)

{
  if (s != (char *)0x0) {
    strlen(s);
    return;
  }
  return;
}

/**
 * @brief 空指针安全的 strcpy
 * @addr 0x203C2
 * @module strlib
 * @proto int strcpy_checked(char* dst, char* src)
 * @confidence verified
 * @note 空指针安全的 strcpy：src 为 0 时只写结尾 NUL。
 * @tag libc
 */
int strcpy_checked(char* dst, char* src)

{
  if (dst != (char *)0x0) {
    if (src == (char *)0x0) {
      *dst = '\0';
      return 0;
    }
    strcpy(dst,src);
  }
  return 0;
}

/**
 * @brief 字符串拼接（调用 0x2A020）
 * @addr 0x203D6
 * @module strlib
 * @proto void strcat_checked(char* dst, char* src)
 * @confidence verified
 * @note 字符串拼接（调用 0x2A020）；src 为 0 时把 dst 置空。
 * @tag libc
 */
int strcat_checked(char* dst, char* src)

{
  if (dst == (char *)0x0) {
    return 0;
  }
  if (src != (char *)0x0) {
    strcat_raw(dst,src);
    return 0;
  }
  *dst = '\0';
  return 0;
}

/**
 * @brief 把内部数值格式化为显示字符串
 * @addr 0x20462
 * @module strlib
 * @proto void fmt_number(short ctx, char* out)
 * @confidence strong
 * @note 把内部数值格式化为显示字符串。
 * @tag format
 */
int fmt_number(short ctx, char* out)

{
  char cVar1;
  char cVar2;
  char cVar3;
  ushort uVar4;
  char *pcVar5;
  char *pcVar6;
  
  cVar1 = disp_mode;
  if (mixed_fraction == '\0') {
    cVar2 = -0x70;
    if (disp_mode == '\x01') {
      *out = -5;
      out = out + 1;
      cVar2 = ':';
    }
    *out = cVar2;
    pcVar5 = out + 1;
    cVar3 = cVar2 + '\x01';
    uVar4 = *(ushort *)((uintptr_t)ctx + 0x10);
    if ((short)uVar4 < 0) {
      cVar3 = cVar2 + '\x02';
      uVar4 = (uVar4 ^ 0xffff) + 1;
    }
    if (cVar1 == '\x01') {
      *pcVar5 = -5;
      pcVar5 = out + 2;
    }
    *pcVar5 = cVar3;
    pcVar6 = pcVar5 + 1;
    cVar2 = (char)(uVar4 / 10);
    cVar3 = -0x60;
    if (cVar2 != '\0') {
      if (cVar1 == '\x01') {
        *pcVar6 = -5;
        pcVar6 = pcVar5 + 2;
        if (cur_line == '\x0e') {
          cVar3 = 'D';
        }
        else {
          cVar3 = '0';
        }
      }
      else if (cur_line == '\x0e') {
        *pcVar6 = '\x04';
        pcVar6 = pcVar5 + 2;
      }
      *pcVar6 = cVar2 + cVar3;
      pcVar6 = pcVar6 + 1;
    }
    if (cVar1 == '\x01') {
      *pcVar6 = -5;
      pcVar6 = pcVar6 + 1;
      cVar3 = '0';
    }
    *pcVar6 = (char)(uVar4 % 10) + cVar3;
    pcVar6[1] = '\0';
  }
  else {
    *out = '-';
    pcVar5 = out + 1;
    uVar4 = *(ushort *)((uintptr_t)ctx + 0x10);
    if ((short)uVar4 < 0) {
      *pcVar5 = -0x40;
      pcVar5 = out + 2;
      uVar4 = (uVar4 ^ 0xffff) + 1;
    }
    cVar1 = (char)(uVar4 / 10);
    if (cVar1 != '\0') {
      *pcVar5 = cVar1 + '0';
      pcVar5 = pcVar5 + 1;
    }
    *pcVar5 = (char)(uVar4 % 10) + '0';
    pcVar5[1] = '\0';
  }
  return 0;
}

/**
 * @brief 科学计数格式化
 * @addr 0x2051E
 * @module strlib
 * @proto void fmt_sci(ushort ctx, char* out)
 * @confidence strong
 * @note 科学计数格式化。
 * @tag format
 */
int fmt_sci(ushort ctx, char* out)

{
  undefined uVar1;
  char cVar2;
  char cVar3;
  byte bVar4;
  ushort uVar5;
  byte bVar6;
  ushort uVar7;
  char cVar8;
  undefined3 uVar9;
  undefined4 uVar10;
  char cVar14;
  longlong lVar11;
  undefined8 uVar12;
  undefined4 uVar16;
  ulonglong uVar13;
  char *pcVar17;
  char *pcVar18;
  undefined auStack_10 [12];
  ushort uVar15;
  
  lVar11 = (ulonglong)CONCAT22(auStack_10,ctx) << 0x20;
  uVar1 = get_ptr_ffd8_4();
  *(undefined *)((short)((ulonglong)lVar11 >> 0x30) + -2) = uVar1;
  uVar1 = list_sep_char();
  uVar5 = *(ushort *)((short)((ulonglong)lVar11 >> 0x20) + 0x14);
  uVar12 = CONCAT62((int6)((ulonglong)lVar11 >> 0x10),CONCAT11(0x30,uVar1));
  if (mixed_fraction != '\0') {
    uVar12 = CONCAT71((int7)((ulonglong)uVar12 >> 8),0x2e);
  }
  pcVar17 = (char *)((ulonglong)uVar12 >> 0x20);
  bVar4 = (byte)uVar5;
  cVar2 = (char)(uVar5 >> 8);
  cVar14 = (char)((ulonglong)uVar12 >> 8);
  cVar8 = (char)uVar12;
  if (*pcVar17 == '\0') {
    uVar12 = CONCAT53((int5)((ulonglong)uVar12 >> 0x18),(uint3)(ushort)uVar12);
    *out = cVar14;
    pcVar18 = out + 1;
    if (cVar2 == '\0') {
      if (bVar4 != 1) {
        *pcVar18 = cVar8;
        pcVar18 = out + 2;
        bVar6 = 0;
        do {
          cVar2 = span_check_3b(*(char *)((short)((ulonglong)uVar12 >> 0x30) + -2));
          if (cVar2 != '\0') {
            *pcVar18 = '\x01';
            pcVar18 = pcVar18 + 1;
          }
          *pcVar18 = (char)((ulonglong)uVar12 >> 8);
          bVar6 = bVar6 + 1;
          uVar12 = CONCAT53((int5)((ulonglong)uVar12 >> 0x18),(uint3)(ushort)uVar12);
LAB_rom_020696:
          pcVar18 = pcVar18 + 1;
        } while ((char)((bVar6 < (byte)(bVar4 - 1)) << 7) < '\0');
      }
    }
    else {
      if (cVar2 == '\x02') {
        *pcVar18 = cVar8;
        bVar6 = 0;
        goto LAB_rom_020696;
      }
      if (cVar2 == '\x03') {
        *pcVar18 = cVar8;
        pcVar18 = out + 2;
      }
    }
  }
  else {
    pcVar18 = out;
    if (pcVar17[0xf] == '\x01') {
      if ((disp_mode == '\x01') || (mixed_fraction != '\0')) {
        cVar3 = -0x40;
      }
      else {
        cVar3 = '`';
      }
      *out = cVar3;
      pcVar18 = out + 1;
    }
    uVar16 = (undefined4)((ulonglong)uVar12 >> 0x20);
    uVar15 = *(ushort *)(pcVar17 + 0x12);
    uVar10 = CONCAT22(uVar15,(ushort)uVar12);
    uVar12 = CONCAT44(uVar16,uVar10);
    if ((short)uVar15 < 0) {
      if (((cVar2 == '\x01') || (cVar2 == '\x03')) && (bVar4 != 0)) {
        while ((bVar4 = bVar4 - 1, bVar4 != 0 && (pcVar17[bVar4] == '\0'))) {
          uVar5 = (ushort)(byte)((char)uVar5 - 1);
        }
      }
      *pcVar18 = cVar14;
      pcVar18[1] = cVar8;
      pcVar18 = pcVar18 + 2;
      uVar9 = (undefined3)uVar10;
      for (uVar13 = (CONCAT53((int5)(CONCAT44(uVar16,CONCAT13((char)uVar15,uVar9)) >> 0x18),uVar9) ^
                    0xff000000) & 0xffffffffff00ffff; (char)(uVar13 >> 0x18) != '\0';
          uVar13 = CONCAT44((int)(uVar13 >> 0x20),
                            CONCAT13((char)(uVar13 >> 0x18) + -1,(uint3)(ushort)uVar13))) {
        cVar2 = span_check_3b(*(char *)((short)(uVar13 >> 0x30) + -2));
        if (cVar2 != '\0') {
          *pcVar18 = '\x01';
          pcVar18 = pcVar18 + 1;
        }
        *pcVar18 = (char)(uVar13 >> 8);
        pcVar18 = pcVar18 + 1;
      }
      uVar13 = uVar13 & 0xffffffff00000000;
      while( true ) {
        uVar10 = (undefined4)(uVar13 >> 0x20);
        if ((char)uVar5 == '\0') break;
        cVar2 = span_check_3b(*(char *)((short)(uVar13 >> 0x30) + -2));
        if (cVar2 != '\0') {
          *pcVar18 = '\x01';
          pcVar18 = pcVar18 + 1;
        }
        *pcVar18 = *(char *)uVar10 + '0';
        pcVar18 = pcVar18 + 1;
        uVar13 = (ulonglong)CONCAT22((short)((uint)uVar10 >> 0x10),(char *)uVar10 + 1) << 0x20;
        uVar5 = (ushort)(byte)((char)uVar5 - 1);
      }
    }
    else {
      if ((cVar2 == '\x01') || (cVar2 == '\x03')) {
        uVar7 = uVar5 & 0xff;
        while ((uVar7 = uVar7 - 1,
               (byte)(SBORROW2(uVar7,uVar15) ^ (short)(uVar7 - uVar15) < 0 | uVar7 == uVar15) == 0
               && (pcVar17[uVar7] == '\0'))) {
          uVar5 = CONCAT11((char)(uVar5 >> 8),(char)uVar5 + -1);
        }
      }
      if ((uVar5 & 0xff) - 1 == uVar15) {
        for (; -1 < (char)((ulonglong)uVar12 >> 0x10);
            uVar12 = CONCAT53((int5)(((ulonglong)
                                      CONCAT22((short)((ulonglong)uVar12 >> 0x30),
                                               (short)((ulonglong)uVar12 >> 0x20) + 1) << 0x20) >>
                                    0x18),
                              CONCAT12((char)((ulonglong)uVar12 >> 0x10) + -1,(short)uVar12))) {
          *pcVar18 = *(char *)((ulonglong)uVar12 >> 0x20) + '0';
          pcVar18 = pcVar18 + 1;
          cVar2 = span_check_3(*(char *)((short)((ulonglong)uVar12 >> 0x30) + -2));
          if (cVar2 == '\x01') {
            *pcVar18 = '\x01';
            pcVar18 = pcVar18 + 1;
          }
        }
        cVar2 = (char)(uVar5 >> 8);
        if ((cVar2 == '\x02') || (cVar2 == '\x03')) {
          *pcVar18 = (char)uVar12;
          pcVar18 = pcVar18 + 1;
        }
      }
      else {
        for (; (char)uVar5 != '\0'; uVar5 = (ushort)(byte)((char)uVar5 - 1)) {
          cVar2 = span_check_3b(*(char *)((short)((ulonglong)uVar12 >> 0x30) + -2));
          pcVar17 = pcVar18;
          if (cVar2 != '\0') {
            *pcVar18 = '\x01';
            pcVar17 = pcVar18 + 1;
          }
          *pcVar17 = *(char *)((ulonglong)uVar12 >> 0x20) + '0';
          pcVar18 = pcVar17 + 1;
          if ((char)((ulonglong)uVar12 >> 0x10) == '\0') {
            *pcVar18 = (char)uVar12;
            pcVar18 = pcVar17 + 2;
          }
          cVar2 = span_check_3(*(char *)((short)((ulonglong)uVar12 >> 0x30) + -2));
          if (cVar2 == '\x01') {
            *pcVar18 = '\x01';
            pcVar18 = pcVar18 + 1;
          }
          uVar12 = CONCAT44(CONCAT22((short)((ulonglong)uVar12 >> 0x30),
                                     (short)((ulonglong)uVar12 >> 0x20) + 1),
                            CONCAT22((short)((ulonglong)uVar12 >> 0x10) + -1,(short)uVar12));
        }
      }
    }
  }
  *pcVar18 = '\0';
  return 0;
}

/**
 * @brief 从 R10 开始每次减 3 检查是否越过 0（掩码区间判定）
 * @addr 0x206B0
 * @module strlib
 * @proto byte span_check_3(void)
 * @confidence likely
 * @note 从 R10 开始每次减 3 检查是否越过 0（掩码区间判定）。
 * @tag parser
 */
byte span_check_3(uintptr_t _a2, int _a1)

{
  byte unaff_R10;
  short unaff_ER14;
  
  if (*(char *)(unaff_ER14 + 0x10) != '\0') {
    do {
      unaff_R10 = unaff_R10 - 3;
      if ((char)unaff_R10 < '\0') {
        return 0;
      }
      if (unaff_R10 == 0) {
        return 1;
      }
    } while (_a1 != '\x04');
    if ((unaff_R10 & 1) == 0) {
      return 1;
    }
  }
  return 0;
}

/**
 * @brief mode==2 时从 R10 取反开始每次减 3 检查区间
 * @addr 0x206D0
 * @module strlib
 * @proto byte span_check_3b(char mode)
 * @confidence likely
 * @note mode==2 时从 R10 取反开始每次减 3 检查区间。
 * @tag parser
 */
byte span_check_3b(char mode)

{
  byte bVar1;
  byte unaff_R10;
  short unaff_ER14;
  
  if (((*(char *)(unaff_ER14 + 0x10) != '\0') && (mode == '\x02')) &&
     (bVar1 = unaff_R10 ^ 0xff, bVar1 != 0)) {
    for (; -1 < (char)bVar1; bVar1 = bVar1 - 3) {
      if (bVar1 == 0) {
        return 1;
      }
    }
  }
  return 0;
}

/**
 * @brief mode==2 时用 R10 取反做 3 步掩码区间判定，命中返回 1
 * @addr 0x206E4
 * @module strlib
 * @proto byte span_check_3c(char mode)
 * @confidence likely
 * @note mode==2 时用 R10 取反做 3 步掩码区间判定，命中返回 1。
 * @tag parser
 */
byte span_check_3c(char mode)

{
  byte bVar1;
  byte unaff_R10;
  
  if ((mode == '\x02') && (bVar1 = unaff_R10 ^ 0xff, bVar1 != 0)) {
    for (; -1 < (char)bVar1; bVar1 = bVar1 - 3) {
      if (bVar1 == 0) {
        return 1;
      }
    }
  }
  return 0;
}

