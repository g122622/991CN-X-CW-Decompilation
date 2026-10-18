/*
 * 表达式求值 / 15bac_matrix_func_ext.c
 * 地址范围: 0x15BAC - 0x1637A
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 扩展矩阵函数
 * @addr 0x15BAC
 * @module eval
 * @proto byte matrix_func_ext(byte fn, undefined2* x)
 * @confidence strong
 * @note 扩展矩阵函数：x 经 0x1D800 归一化后按函数号 fn 选择
 *       0x1D246/0x1C880/0x1C86C等核心求值，返回状态（0 成功、3/8 为特殊值）。
 * @tag matrix
 */
byte matrix_func_ext(byte fn, undefined2* x)

{
  byte bVar1;
  undefined2 uVar2;
  undefined2 *puVar3;
  undefined2 *puVar5;
  undefined8 uVar4;
  undefined auStack_20 [10];
  undefined2 auStack_16 [9];
  
  uVar4 = CONCAT44((int)(CONCAT26(auStack_20,CONCAT24(fn,0x100)) >> 0x20),
                   CONCAT22(auStack_16,0x100));
  dec_copy(auStack_16,x);
  bVar1 = bcd_type((byte *)((ulonglong)uVar4 >> 0x20));
  if (bVar1 != 0) {
    return bVar1;
  }
  bVar1 = bcd_type((byte *)((ulonglong)uVar4 >> 0x10));
  if (bVar1 != 0) {
    uVar4 = CONCAT71((int7)((ulonglong)uVar4 >> 8),bVar1);
    goto LAB_rom_015c8a;
  }
  dec_cmp_signed((short)((ulonglong)uVar4 >> 0x20),x);
  puVar3 = (undefined2 *)((ulonglong)uVar4 >> 0x20);
  dec_copy((undefined2 *)((ulonglong)uVar4 >> 0x30),puVar3);
  puVar5 = (undefined2 *)((ulonglong)uVar4 >> 0x30);
  bVar1 = (puVar5 == (undefined2 *)0x0) << 6;
  dec_type_flag(puVar5,puVar3);
  if ((bVar1 >> 6 & 1) != 0) {
    dec_cmp_signed((short)((ulonglong)uVar4 >> 0x10),puVar3);
    puVar5 = (undefined2 *)((ulonglong)uVar4 >> 0x10);
    bVar1 = (puVar5 == (undefined2 *)0x0) << 6;
    dec_type_flag(puVar5,puVar3);
    if ((bVar1 >> 6 & 1) != 0) {
      uVar2 = dec_cmp((undefined2 *)((ulonglong)uVar4 >> 0x10),puVar3);
      if (((char)((ulonglong)uVar4 >> 8) == '\0') || ((char)uVar2 != '\x02')) {
        puVar5 = (undefined2 *)((ulonglong)uVar4 >> 0x30);
        if ((char)uVar2 == '\x01') {
          uVar2 = dec_cmp(puVar5,puVar3);
          if (((char)((ulonglong)uVar4 >> 8) == '\0') || ((char)uVar2 != '\x02')) {
LAB_rom_015c78:
            dec_bin_result((ushort *)((ulonglong)uVar4 >> 0x30),puVar3);
            goto LAB_rom_015c26;
          }
        }
        else {
          uVar2 = dec_cmp(puVar5,puVar3);
          if (((char)((ulonglong)uVar4 >> 8) == '\0') || ((char)uVar2 != '\x02')) {
            puVar3 = (undefined2 *)((ulonglong)uVar4 >> 0x10);
            puVar5 = (undefined2 *)((ulonglong)uVar4 >> 0x30);
            if ((char)uVar2 == '\x01') {
              dec_copy(puVar5,puVar3);
              goto LAB_rom_015c78;
            }
            decm_tan(puVar5,puVar3);
LAB_rom_015c26:
            uVar2 = dec_cmp((undefined2 *)((ulonglong)uVar4 >> 0x30),puVar3);
            puVar3 = (undefined2 *)((ulonglong)uVar4 >> 0x20);
            puVar5 = (undefined2 *)((ulonglong)uVar4 >> 0x30);
            if (((char)uVar2 == '\x01') || ((char)((ulonglong)uVar4 >> 8) == '\0')) {
              dec_copy(puVar3,puVar5);
              return 0;
            }
            dec_bin_and_core(puVar3,puVar5);
            uVar2 = (undefined2)((ulonglong)uVar4 >> 0x10);
            dec_bin_pow_core((short)((ulonglong)uVar4 >> 0x20),uVar2);
            puVar3 = (undefined2 *)((ulonglong)uVar4 >> 0x20);
            bVar1 = (puVar3 == (undefined2 *)0x0) << 6;
            dec_type_flag(puVar3,uVar2);
            if ((bVar1 >> 6 & 1) != 0) {
              return 0;
            }
            uVar4 = CONCAT71((int7)((ulonglong)uVar4 >> 8),3);
            goto LAB_rom_015c8a;
          }
        }
      }
    }
  }
  uVar4 = CONCAT71((int7)((ulonglong)uVar4 >> 8),8);
LAB_rom_015c8a:
  dec_set_special((ushort *)((ulonglong)uVar4 >> 0x20),(byte)uVar4);
  return (byte)uVar4;
}

/**
 * @brief p[0] 为数字（0x30..0x39）、小数点 0x2E 或负号 0x2D 时返回 低字节…
 * @addr 0x15D3C
 * @module eval
 * @proto short is_digit_at(byte* p)
 * @confidence verified
 * @note p[0] 为数字（0x30..0x39）、小数点 0x2E 或负号 0x2D 时返回 低字节|0x100，否则
 *       低字节<<8。
 * @tag parser
 */
short is_digit_at(byte* p)

{
  byte bVar2;
  short sVar1;
  
  bVar2 = *p;
  sVar1 = CONCAT11(bVar2,1);
  if (((bVar2 != 0x2e) && (bVar2 != 0x2d)) && ((0x39 < bVar2 || (bVar2 < 0x30)))) {
    sVar1 = (ushort)bVar2 << 8;
  }
  return sVar1;
}

/**
 * @brief 把 token 编码成显示/存储串
 * @addr 0x15D72
 * @module eval
 * @proto void token_encode(byte* tok, byte* out)
 * @confidence strong
 * @note 把 token 编码成显示/存储串：按类型 0x15F86 展开，0xD112==9 时加 0x60 前缀，否则按
 *       0x15FFC 的长度信息压缩编码。
 * @tag parser
 */
int token_encode(byte* tok, byte* out)

{
  bool bVar1;
  char cVar2;
  ushort uVar3;
  byte bVar4;
  byte unaff_R4;
  byte bVar6;
  ushort uVar5;
  char cVar7;
  ushort unaff_ER6;
  uint5 uVar8;
  byte bVar11;
  undefined8 in_QR8;
  ulonglong uVar9;
  ulonglong uVar10;
  byte bVar12;
  byte *pbVar13;
  
  *out = 0;
  bVar6 = *(byte *)tok;
  uVar3 = CONCAT11(bVar6,unaff_R4);
  if (bVar6 < 0x10) {
    uVar10 = CONCAT26(out,(int6)in_QR8) & 0xffff0000ffffffff;
    token_norm(tok,out);
    bVar11 = sub_mode;
    uVar9 = CONCAT62((int6)(uVar10 >> 0x10),CONCAT11(sub_mode,(char)uVar10));
    bVar12 = (sub_mode < 9) << 7 | (sub_mode == 9) << 6;
    if (sub_mode == 9) {
      pbVar13 = (byte *)(uVar10 >> 0x30);
      uVar9 = uVar9 & 0xffffffffffff;
      if ((char)(uVar9 >> 0x10) != '\0') {
        uVar9 = (ulonglong)CONCAT12(0x60,(short)uVar9);
        *pbVar13 = 0x60;
        pbVar13 = pbVar13 + 1;
      }
      uVar5 = CONCAT11(bVar6,(char)uVar9);
      cVar7 = '\n';
      bVar1 = false;
      uVar10 = 0xf04;
    }
    else {
      uVar3 = bcd_mul_table();
      if ((char)bVar12 < '\0') {
        return 0;
      }
      pbVar13 = (byte *)(uVar9 >> 0x30);
      cVar7 = '\x10';
      bVar1 = true;
      uVar10 = (ulonglong)CONCAT11(bVar11,bVar11);
      bVar12 = (byte)(uVar3 >> 8);
      cVar2 = (char)uVar3;
      if (bVar11 == 1) {
        uVar5 = CONCAT11(bVar6,bVar12);
        unaff_ER6 = CONCAT11(cVar2,(char)out);
      }
      else {
        uVar10 = (ulonglong)CONCAT11(bVar11,(bVar11 >> 3) + 3);
        cVar7 = '\v';
        bVar1 = true;
        bVar4 = (byte)((ushort)out >> 8);
        if (bVar11 == 7) {
          unaff_ER6 = CONCAT11((char)(((ushort)bVar4 * 0x100 + ((ushort)out & 0xff)) * 0x80 >> 8
                                     ),(char)(((short)out * 0x100 + (ushort)bVar12) * 0x80 >> 8)
                              );
          uVar3 = CONCAT11((char)(((ushort)bVar12 * 0x100 + (uVar3 & 0xff)) * 0x80 >> 8),cVar2 << 7)
          ;
          uVar5 = CONCAT11(bVar6,(char)(((ushort)unaff_R4 * 0x100 + (ushort)bVar4) * 0x80 >> 8)) &
                  0xff7f;
        }
        else {
          cVar7 = '\b';
          bVar1 = true;
          uVar5 = CONCAT11(bVar6,bVar4);
          unaff_ER6 = CONCAT11((char)out,bVar12);
          uVar3 = CONCAT11(cVar2,cVar2);
        }
      }
    }
    while( true ) {
      bVar11 = (byte)(uVar10 >> 8);
      bVar6 = (byte)(((uVar5 & 0xff00) + (uVar5 & 0xff) << ((byte)uVar10 & 7)) >> 8) & bVar11;
      if (((bVar6 != 0) || (bVar1)) || (bVar12 = 0, cVar7 == '\x01')) {
        bVar1 = true;
        bVar12 = bVar6 + 0x30;
        if (0x39 < bVar12) {
          bVar12 = bVar6 + 0xae;
        }
        *pbVar13 = bVar12;
        pbVar13 = pbVar13 + 1;
      }
      cVar7 = cVar7 + -1;
      if (cVar7 == '\0') break;
      if ((bVar1) && (bVar11 == 1)) {
        uVar8 = CONCAT14(cVar7,(int)uVar10) & 0x3ffffffff;
        uVar10 = (ulonglong)uVar8;
        if ((char)(uVar8 >> 0x20) == '\0') {
          uVar10 = (ulonglong)CONCAT14(1,(int)uVar8);
          *pbVar13 = 1;
          pbVar13 = pbVar13 + 1;
        }
      }
      bVar6 = (byte)uVar10;
      uVar5 = CONCAT11(bVar12,(char)((CONCAT11(bVar12,(char)uVar5) * 0x100 + (unaff_ER6 >> 8) <<
                                     (bVar6 & 7)) >> 8));
      unaff_ER6 = CONCAT11((char)(((unaff_ER6 & 0xff00) + (unaff_ER6 & 0xff) << (bVar6 & 7)) >> 8),
                           (char)((unaff_ER6 * 0x100 + (uVar3 >> 8) << (bVar6 & 7)) >> 8));
      uVar3 = CONCAT11((char)(((uVar3 & 0xff00) + (uVar3 & 0xff) << (bVar6 & 7)) >> 8),
                       (byte)uVar3 << (bVar6 & 7));
    }
    *pbVar13 = (byte)uVar3;
  }
  return 0;
}

/**
 * @brief 调用 0x15ECA 分类后，类型 2/3/8 返回 (高字节<<8)|1，否则 高字节<<…
 * @addr 0x15E30
 * @module eval
 * @proto short reject_type_2_3_8(ushort tok)
 * @confidence likely
 * @note 调用 0x15ECA 分类后，类型 2/3/8 返回 (高字节<<8)|1，否则 高字节<<8。
 * @tag eval
 */
short reject_type_2_3_8(ushort tok)

{
  undefined2 uVar1;
  short sVar2;
  char cVar4;
  byte bVar3;
  
  uVar1 = token_classify(tok);
  bVar3 = (byte)((ushort)uVar1 >> 8);
  sVar2 = CONCAT11(bVar3,1);
  cVar4 = (char)tok;
  if (((cVar4 != '\x02') && (cVar4 != '\x03')) && (cVar4 != '\b')) {
    sVar2 = (ushort)bVar3 << 8;
  }
  return sVar2;
}

/**
 * @brief 先 0x15ECA 分类，再返回 (低字节 == 3)
 * @addr 0x15E4E
 * @module eval
 * @proto char is_token_3(ushort tok)
 * @confidence strong
 * @note 先 0x15ECA 分类，再返回 (低字节 == 3)。
 * @tag eval
 */
char is_token_3(ushort tok)

{
  token_classify(tok);
  return (char)tok == '\x03';
}

/**
 * @brief 类型 1 令牌的一串保留码检查（0x6A/0x6B/0x85/0x86/0x92 等）
 * @addr 0x15E64
 * @module eval
 * @proto byte check_type1_codes(ushort tok)
 * @confidence likely
 * @note 类型 1 令牌的一串保留码检查（0x6A/0x6B/0x85/0x86/0x92 等）。
 * @tag eval
 */
byte check_type1_codes(ushort tok)

{
  byte bVar1;
  ushort uVar2;
  byte bVar3;
  
  uVar2 = token_classify(tok);
  if (((((((char)tok == '\x01') && (bVar1 = (byte)uVar2, bVar1 != 0x6a)) && (bVar1 != 0x6b)) &&
       ((bVar1 < 0xc1 && (bVar1 != 0x85)))) && ((bVar1 != 0x86 && (bVar1 != 0x92)))) &&
     ((bVar3 = (bVar1 == 0x7d) << 6, bVar1 == 0x7d ||
      (uVar2 = is_paren_range(bVar1,(char)(uVar2 >> 8)), (bVar3 >> 6 & 1) != 0)))) {
    uVar2 = CONCAT11((char)(uVar2 >> 8),1);
  }
  else {
    uVar2 = uVar2 & 0xff00;
  }
  return uVar2;
}

/**
 * @brief 令牌是否为复合结构
 * @addr 0x15E98
 * @module eval
 * @proto undefined2 token_is_complex(ushort tok, undefined2 ctx)
 * @confidence strong
 * @note 令牌是否为复合结构：0x15ECA 分类后，类型 3/4/5/6/7/8 返回 1（其余 0）。
 * @tag parser
 */
undefined2 token_is_complex(ushort tok, undefined2 ctx)

{
  undefined2 uVar1;
  char cVar2;
  undefined2 uVar3;
  
  if (((char)(tok >> 8) != '\0') || ((char)tok != -0x17)) {
    uVar3 = CONCAT11((char)((ushort)ctx >> 8),(char)tok);
    uVar1 = token_classify(uVar3);
    tok = CONCAT11((char)((ushort)uVar1 >> 8),1);
    cVar2 = (char)uVar3;
    if (cVar2 == '\x03') {
      return tok;
    }
    if (cVar2 == '\x04') {
      return tok;
    }
    if (cVar2 == '\x05') {
      return tok;
    }
    if (cVar2 == '\b') {
      return tok;
    }
    if (cVar2 == '\x06') {
      return tok;
    }
    if (cVar2 == '\a') {
      return tok;
    }
  }
  return tok & 0xff00;
}

/**
 * @brief 以 (低字节, 高字节) 调用 0x15EEA 重新分类令牌，返回原令牌
 * @addr 0x15ECA
 * @module eval
 * @proto ushort token_classify(ushort tok)
 * @confidence strong
 * @note 以 (低字节, 高字节) 调用 0x15EEA 重新分类令牌，返回原令牌。
 * @tag eval
 */
ushort token_classify(ushort tok)

{
  token_class_ex((byte)tok,(char)((ushort)tok >> 8));
  return tok;
}

/**
 * @brief 求值预扫描
 * @addr 0x15ECE
 * @module eval
 * @proto ushort eval_token_scan(void)
 * @confidence strong
 * @note 求值预扫描：从输入区取下一个字符（0xD4C8 → 0x179C2 → 0x15EEA），返回令牌编码。
 * @tag eval
 */
ushort eval_token_scan(void)

{
  ushort uVar1;
  byte *unaff_ER14;
  
  uVar1 = token_at(unaff_ER14);
  advance_token_ptr(uVar1);
  token_class_ex((byte)uVar1,(char)(uVar1 >> 8));
  return uVar1;
}

/**
 * @brief 在 0xD4C8 取到字符后，把它编码成令牌类别
 * @addr 0x15EEA
 * @module eval
 * @proto int token_class_ex(byte ki, char ko)
 * @confidence strong
 * @note 在 0xD4C8 取到字符后，把它编码成令牌类别：调用 0x179C2 记录原码并返回类别。
 * @tag eval
 */
int token_class_ex(byte ki, char ko)

{
  if (ko == -5) {
    if (0xf < ki) {
      if ((char)((ki < 0x20) << 7) < '\0') {
        return 8;
      }
      if (0x2f < ki) {
        return 0xf;
      }
      return 7;
    }
  }
  else {
    if (ko == -3) {
      return 6;
    }
    if (ko == -2) {
      return 3;
    }
    if (ko == -6) {
      return 3;
    }
    if (ki != 0) {
      if ((char)((ki < 0x20) << 7) < '\0') {
        return 0xf;
      }
      if (ki < 0x23) {
        return 6;
      }
      if (ki != 0x23) {
        if (ki != 0x24) {
          if (ki == 0x25) {
            return 0xf;
          }
          if (ki == 0x2c) {
            return 9;
          }
          if ((char)((ki < 0x40) << 7) < '\0') {
            return 4;
          }
          if (0x4f < ki) {
            if ((char)((ki < 0x60) << 7) < '\0') {
              return 0;
            }
            if (ki < 0xa0) {
              return 1;
            }
            if ((char)((ki < 0xb8) << 7) < '\0') {
              return 2;
            }
            if (0xbf < ki) {
              if ((char)((ki < 200) << 7) < '\0') {
                return 1;
              }
              if ((char)((ki < 0xd0) << 7) < '\0') {
                return 2;
              }
            }
            return 3;
          }
        }
        return 5;
      }
    }
  }
  return 10;
}

/**
 * @brief 16 位取负（0xFFFF - v + 1）
 * @addr 0x15F76
 * @module eval
 * @proto ushort neg_u16(ushort v)
 * @confidence verified
 * @note 16 位取负（0xFFFF - v + 1）。
 * @tag util
 */
ushort neg_u16(ushort v)

{
  return (v ^ 0xffff) + 1;
}

/**
 * @brief 令牌值归一化
 * @addr 0x15F86
 * @module eval
 * @proto void token_norm(undefined2* a, undefined2* b)
 * @confidence likely
 * @note 令牌值归一化：按 0x1D5B6 比较结果调用 0x1D730，再以 0x1D66E/0x1C844 做 10 进制对齐。
 * @tag parser
 */
int token_norm(undefined2* a, undefined2* b)

{
  ushort uVar1;
  undefined2 *unaff_ER12;
  undefined2 auStack_18 [5];
  ushort auStack_e [4];
  undefined uStack_6;
  
  uVar1 = dec_cmp(a,b);
  dec_copy(auStack_18,unaff_ER12);
  if ((uVar1 & 2) != 0) {
    dec_inc5(auStack_18,unaff_ER12);
  }
  dec_set_uint_small(auStack_e,1);
  uStack_6 = 0x10;
  dec_bin_div_core(auStack_18,auStack_e);
  return 0;
}

/**
 * @brief 矩阵求值大流程（2KB，0x16D9C 使用）
 * @addr 0x16068
 * @module eval
 * @proto byte matrix_eval_big(undefined2 a)
 * @confidence likely
 * @note 矩阵求值大流程（2KB，0x16D9C 使用）。
 * @tag matrix
 */
byte matrix_eval_big(undefined2 a, int _a2)

{
  bool bVar1;
  short sVar2;
  undefined uVar3;
  ushort uVar4;
  undefined uVar5;
  ushort uVar6;
  char cVar7;
  byte bVar8;
  ushort uVar9;
  ushort uVar10;
  char cVar11;
  byte bVar12;
  
  uVar4 = 0;
  uVar6 = 0;
  if ((a == 0) && (_a2 == 0)) {
    return;
  }
  if ((_a2 & 0x8000) != 0) {
    a = neg_u16(a);
  }
  cVar7 = '\0';
  bVar8 = 1;
  uVar9 = 0;
  uVar10 = 0;
  do {
    cVar11 = (char)(uVar10 >> 8);
    if ((char)((char)a << 7) < '\0') {
      uVar3 = daa((byte)uVar4 + bVar8);
      sVar2 = (uVar4 >> 8) + (uVar9 & 0xff) + (ushort)CARRY1((byte)uVar4,bVar8);
      uVar5 = daa((char)sVar2);
      uVar4 = CONCAT11(uVar5,uVar3);
      sVar2 = (uVar6 & 0xff) + (uVar9 >> 8) + (ushort)((byte)((ushort)sVar2 >> 8) & 1);
      uVar3 = daa((char)sVar2);
      sVar2 = (uVar6 >> 8) + (uVar10 & 0xff) + (ushort)((byte)((ushort)sVar2 >> 8) & 1);
      uVar5 = daa((char)sVar2);
      uVar6 = CONCAT11(uVar5,uVar3);
      cVar7 = daa((cVar7 + cVar11) - ((char)((char)((ushort)sVar2 >> 8) << 7) >> 7));
    }
    a = CONCAT11((char)(_a2 * 0x100 + (a >> 8) >> 1),
                       (char)((a & 0xff00) + (a & 0xff) >> 1));
    _a2 = CONCAT11((byte)((uint32_t)_a2 >> 9),(char)((_a2 & 0xff00) + (_a2 & 0xff) >> 1));
    bVar1 = CARRY1(bVar8,bVar8);
    bVar8 = daa(bVar8 * '\x02');
    sVar2 = (uVar9 & 0xff) + (uVar9 & 0xff) + (ushort)bVar1;
    bVar12 = (byte)(uVar9 >> 8);
    uVar3 = daa((char)sVar2);
    sVar2 = (ushort)bVar12 + (ushort)bVar12 + (ushort)((byte)((ushort)sVar2 >> 8) & 1);
    uVar5 = daa((char)sVar2);
    uVar9 = CONCAT11(uVar5,uVar3);
    sVar2 = (uVar10 & 0xff) + (uVar10 & 0xff) + (ushort)((byte)((ushort)sVar2 >> 8) & 1);
    uVar3 = daa((char)sVar2);
    bVar12 = daa(cVar11 * '\x02' - ((char)((char)((ushort)sVar2 >> 8) << 7) >> 7));
    uVar10 = CONCAT11(bVar12,uVar3);
  } while ((bVar12 & 0x40) == 0);
                    // WARNING: Bad instruction - Truncating control flow here
  halt_baddata();
}

/**
 * @brief R9 != R10 时把 v 的低半字节写到 base+R10+0x28 的单元格
 * @addr 0x160CE
 * @module eval
 * @proto void store_cell_if_ne(char v)
 * @confidence verified
 * @note R9 != R10 时把 v 的低半字节写到 base+R10+0x28 的单元格。
 * @tag matrix
 */
int store_cell_if_ne(char v)

{
  byte unaff_R9;
  byte unaff_R10;
  undefined2 unaff_ER12;
  
  if (unaff_R9 != unaff_R10) {
    *(byte *)(CONCAT11((char)((ushort)unaff_ER12 >> 8) + CARRY1((byte)unaff_ER12,unaff_R10),
                       (byte)unaff_ER12 + unaff_R10) + 0x28) = v & 0xf;
  }
  return 0;
}

/**
 * @brief R10 != 0xF 时把 v 的低半字节写到 base+R10+0x28 的单元格
 * @addr 0x160D2
 * @module eval
 * @proto void store_cell_if_lt(char v)
 * @confidence verified
 * @note R10 != 0xF 时把 v 的低半字节写到 base+R10+0x28 的单元格。
 * @tag matrix
 */
int store_cell_if_lt(char v)

{
  byte unaff_R10;
  undefined2 unaff_ER12;
  
  if (unaff_R10 != 0xf) {
    *(byte *)(CONCAT11((char)((ushort)unaff_ER12 >> 8) + CARRY1((byte)unaff_ER12,unaff_R10),
                       (byte)unaff_ER12 + unaff_R10) + 0x28) = v & 0xf;
  }
  return 0;
}

/**
 * @brief 字节位反转
 * @addr 0x160E8
 * @module eval
 * @proto int bit_reverse8(byte v)
 * @confidence likely
 * @note 字节位反转：循环左移直到最高位为 1（结果留在参数寄存器）。
 * @tag util
 */
int bit_reverse8(byte v)

{
  bool bVar1;
  
  if (v < 0xf8) {
    do {
      bVar1 = CARRY1(v,v);
      v = v * '\x02';
    } while ((char)(bVar1 << 7) < '\0');
  }
  return 0;
}

/**
 * @brief v 置位 (0x80 >> (R4-5)) 后返回
 * @addr 0x160FC
 * @module eval
 * @proto char set_bit_hi(char v)
 * @confidence verified
 * @note v 置位 (0x80 >> (R4-5)) 后返回。
 * @tag matrix
 */
char set_bit_hi(char v)

{
  char unaff_R4;
  
  return v | 0x80U >> (unaff_R4 - 5U & 7);
}

/**
 * @brief v 清位 (0x80 >> (R4-5)) 后返回
 * @addr 0x1610A
 * @module eval
 * @proto char clear_bit_hi(char v)
 * @confidence verified
 * @note v 清位 (0x80 >> (R4-5)) 后返回。
 * @tag matrix
 */
char clear_bit_hi(char v)

{
  char unaff_R4;
  
  return v & (0x80U >> (unaff_R4 - 5U & 7) ^ 0xff);
}

/**
 * @brief 矩阵运算推进
 * @addr 0x1611A
 * @module eval
 * @proto undefined2 matrix_advance(undefined2 v)
 * @confidence likely
 * @note 矩阵运算推进：0x16BE8 复制、0x16F10 处理 +0x14、0x16C16 推进操作数并返回 v。
 * @tag matrix
 */
undefined2 matrix_advance(undefined2 v)

{
  short unaff_ER12;
  
  matrix_copy_to_slot();
  stat_layout((undefined8 *)(unaff_ER12 + 0x14));
  matrix_opnd_advance();
  return v;
}

/**
 * @brief 对 (param_1+0x14) 处的矩阵原地转置（0x161DE 算法）
 * @addr 0x161BE
 * @module eval
 * @proto void matrix_transpose_inplace(byte* t)
 * @confidence likely
 * @note 对 (param_1+0x14) 处的矩阵原地转置（0x161DE 算法）。
 * @tag matrix
 */
int matrix_transpose_inplace(byte* t)

{
  short sVar1;
  undefined8 *puVar2;
  undefined8 uStack_e;
  
  puVar2 = &uStack_e;
  sVar1 = stat_cell_read((undefined8 *)(t + 0x14));
  matrix_transpose_core(sVar1 + -0x14,puVar2);
  stat_cell_read(&uStack_e);
  return 0;
}

/**
 * @brief 矩阵转置核心
 * @addr 0x161DE
 * @module eval
 * @proto byte matrix_transpose_core(undefined2* a, undefined2* b)
 * @confidence likely
 * @note 矩阵转置核心：0x1DA7A 比较后按 0xD11A 标志交换/移动单元，返回 3 表示失败。
 * @tag matrix
 */
byte matrix_transpose_core(undefined2* a, undefined2* b)

{
  int cVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  undefined2 *puVar4;
  undefined2 *puVar5;
  undefined2 *unaff_ER12;
  byte in_PSW;
  
  dec_cmp_signed(a,b);
  if ((in_PSW >> 6 & 1) != 1) {
    return '\x03';
  }
  if ((char)menu_sel_a == '\b') {
    uVar3 = menu_sel_a;
    uVar2 = copy_from_ER12_to(unaff_ER12 + 10,menu_sel_a);
    cVar1 = decm_round10(uVar2,uVar3);
    if (cVar1 == '\0') {
      uVar3 = dec_cmp(unaff_ER12 + 10,uVar3);
      cVar1 = (char)uVar3 + -1;
      if (cVar1 != '\0') {
        puVar4 = unaff_ER12 + 10;
        dec_copy_ret((undefined2 *)0x1b6c,puVar4);
        *(undefined *)(puVar4 + 4) = _DAT_ram_d11b;
        puVar5 = puVar4;
        dec_bin_pow_core(unaff_ER12,puVar4);
        cVar1 = dec_to_bcd_a(unaff_ER12,puVar5);
        if (cVar1 == '\0') {
          cVar1 = dec_bin_and_core(unaff_ER12,puVar4);
          return cVar1;
        }
      }
    }
  }
  else {
    uVar3 = menu_sel_a;
    if ((char)menu_sel_a != '\t') {
      uVar3 = 0xa00;
    }
    cVar1 = (char)((ushort)uVar3 >> 8);
    if (cVar1 == '\0') {
      cVar1 = '\n';
    }
    cVar1 = dec_exp_shift(unaff_ER12,CONCAT11(cVar1,cVar1 + '\x01'));
  }
  return cVar1;
}

/**
 * @brief 按标志把常量 0x3150 作用于矩阵单元（0x1D620 比较后写回），返回 3 或 0
 * @addr 0x1637A
 * @module eval
 * @proto char matrix_apply_const(char flag, undefined2* b)
 * @confidence likely
 * @note 按标志把常量 0x3150 作用于矩阵单元（0x1D620 比较后写回），返回 3 或 0。
 * @tag matrix
 */
char matrix_apply_const(char flag, undefined2* b)

{
  undefined2 uVar1;
  undefined2 *puVar2;
  char unaff_R6;
  undefined2 *unaff_ER12;
  
  if ((flag == '\0') && (unaff_R6 == '\x02')) {
    uVar1 = dec_cmp(unaff_ER12,b);
    if ((char)uVar1 != '\x01') {
      puVar2 = unaff_ER12 + 0x14;
      stat_cell_read((undefined8 *)0x3150);
      if ((char)uVar1 == '\x04') {
        uVar1 = dec_to_string(unaff_ER12,puVar2);
        if ((char)uVar1 != '\x02') {
          return '\x03';
        }
      }
      else {
        *(undefined *)((short)puVar2 + 9) = 6;
        uVar1 = dec_to_string(unaff_ER12,puVar2);
        if ((char)uVar1 == '\x02') {
          return '\x03';
        }
      }
    }
    flag = '\0';
  }
  return flag;
}

