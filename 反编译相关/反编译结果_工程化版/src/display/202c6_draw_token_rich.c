/*
 * 显示驱动 / 202c6_draw_token_rich.c
 * 地址范围: 0x202C6 - 0x20710
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 复杂 token 绘制（2KB，0x2B4FC 调用）
 * @addr 0x202C6
 * @module display
 * @proto int draw_token_rich(undefined2 a)
 * @confidence likely
 * @note 复杂 token 绘制（2KB，0x2B4FC 调用）。
 * @tag display
 */
int draw_token_rich(undefined2 a, int _a2)

{
  undefined2 uVar1;
  byte bVar3;
  undefined2 *puVar2;
  undefined extraout_R1;
  undefined2 *puVar4;
  byte bVar5;
  char cVar8;
  short sVar9;
  longlong lVar6;
  undefined8 uVar7;
  
  lVar6 = (ulonglong)CONCAT22((uintptr_t)a + 0x14,(uintptr_t)a + 10) << 0x20;
  uVar1 = copy_to_ER12(a,_a2);
  sVar9 = (short)((ulonglong)lVar6 >> 0x20);
  bVar3 = (byte)((ushort)*(undefined2 *)(sVar9 + 8) >> 8);
  bVar5 = (byte)*(undefined2 *)(sVar9 + 8);
  cVar8 = bVar3 - 5;
  uVar7 = CONCAT62((int6)((ulonglong)lVar6 >> 0x10),CONCAT11(cVar8,bVar5));
  if (4 < bVar3) {
    *(char *)(sVar9 + 9) = cVar8;
  }
  bVar3 = (byte)((ushort)uVar1 >> 8);
  if ((*(char *)(sVar9 + 9) == '\0') || (bVar5 < 6)) {
    dec_to_special((short)((ulonglong)lVar6 >> 0x30),_a2);
    dec_bin_and_core((short)((ulonglong)uVar7 >> 0x20),(short)((ulonglong)uVar7 >> 0x30));
    uVar1 = 0x2e5c;
    bVar5 = 0;
    dec_bin_pow_core((short)((ulonglong)uVar7 >> 0x20),0x2e5c);
    bVar3 = 0;
    fmt_exp_set(uVar1, (uintptr_t)0);
    if ((bVar5 >> 6 & 1) != 0) {
      puVar4 = (undefined2 *)((ulonglong)uVar7 >> 0x30);
      puVar2 = dec_copy_ret((undefined2 *)0x2e5c,puVar4);
      puVar4 = puVar4 + 5;
      dec_copy_ret(puVar2,puVar4);
      decm_tan(puVar4,(undefined2 *)((ulonglong)uVar7 >> 0x20));
      dec_bin_and_core((short)((ulonglong)uVar7 >> 0x20),(short)((ulonglong)uVar7 >> 0x30) + 10);
      sVar9 = (short)((ulonglong)uVar7 >> 0x30);
      dec_bin_and_core(sVar9,sVar9 + 10);
      dec_copy_ret((undefined2 *)((ulonglong)uVar7 >> 0x30), (uintptr_t)0)
                     (undefined2 *)((short)((ulonglong)uVar7 >> 0x20) + -10));
      dec_abs_wrap();
      if (0xfa < (byte)((ulonglong)uVar7 >> 8)) {
        return CONCAT11(extraout_R1,0xff);
      }
      sVar9 = (short)((ulonglong)uVar7 >> 0x20);
      if (*(char *)(sVar9 + -1) != '\0') {
        *(undefined *)(sVar9 + -1) = 6;
      }
      if (*(char *)(sVar9 + 9) == '\0') {
        return 0x6ff;
      }
      *(undefined *)(sVar9 + 9) = 6;
      return 0x6ff;
    }
  }
  return (ushort)bVar3 << 8;
}

/**
 * @brief 字符码分类表
 * @addr 0x2035C
 * @module display
 * @proto byte font_class_of(byte ch)
 * @confidence strong
 * @note 字符码分类表：0x18->0，0x2F->1，0x30..0x4F->+0x0B 等，用于字形/宽度查表。
 * @tag display
 */
byte font_class_of(byte ch)

{
  if (ch == 0x18) {
    return '\0';
  }
  if (0x17 < ch) {
    if (ch == 0x2f) {
      return '\x01';
    }
    if ((0x2e < ch) && (0x4f < ch)) {
      if (ch < 0x54) {
        return (uintptr_t)ch + 0xb2;
      }
      if (ch == 0x68) {
        return '\x06';
      }
      if ((0x67 < ch) && (0x71 < ch)) {
        if (ch < 0x75) {
          return (uintptr_t)ch + 0x95;
        }
        if (ch == 0x7d) {
          return '\n';
        }
        if (((0x7c < ch) && (199 < ch)) && (ch < 0xcb)) {
          return (uintptr_t)ch + 0x43;
        }
      }
    }
  }
  return '\x0f';
}

/**
 * @brief 普通 token 绘制（3.1KB，0xED7C 调用）
 * @addr 0x20710
 * @module display
 * @proto int draw_token_plain(byte* tok)
 * @confidence likely
 * @note 普通 token 绘制（3.1KB，0xED7C 调用）。
 * @tag display
 */
int draw_token_plain(byte* tok, int _a2, int _a3, int _a4)

{
  byte bVar1;
  char cVar2;
  char cVar3;
  undefined2 uVar4;
  undefined2 *puVar5;
  byte bVar7;
  short sVar6;
  undefined extraout_R1;
  ushort uVar8;
  ushort uVar9;
  byte bVar10;
  byte abStack_34 [10];
  byte *apbStack_2a [7];
  char cStack_1b;
  short sStack_1a;
  short sStack_18;
  char cStack_16;
  undefined uStack_15;
  undefined2 auStack_12 [7];
  
  uVar8 = (ushort)_a3;
  *(undefined *)_a2 = 0;
  if (tok != (undefined2 *)0x0) {
    bVar10 = (auStack_12 == (undefined2 *)0x0) << 6;
    uVar4 = dec_copy(auStack_12,tok);
    puVar5 = (undefined2 *)dec_cmp_signed(uVar4,tok);
    if ((bVar10 >> 6 & 1) == 1) {
      dec_exp_shift(puVar5,CONCAT11((char)((ushort)tok >> 8),0xb));
      tok = (undefined2 *)dec_parse((byte *)auStack_12,apbStack_2a);
      if ((char)tok != '\0') {
        uVar9 = uVar8;
        if (cStack_1b != '\0') {
          uVar9 = (ushort)(byte)(_a3 - 1);
          uVar8 = uVar8 - 1;
        }
        uStack_15 = 1;
        bVar1 = (byte)sStack_1a;
        bVar7 = (byte)((ushort)sStack_1a >> 8);
        bVar10 = bVar7 - (bVar1 < 10);
        cStack_16 = (char)uVar9;
        if ((bool)((byte)((bVar10 ^ bVar7) & ~bVar10) >> 7) != (char)bVar10 < '\0') {
          if (key_history_flags == '\x14') {
            bVar10 = (bVar7 + 1) - (bVar1 < 0xfd);
            bVar10 = (byte)((bVar10 ^ bVar7) & (~bVar10 ^ 0xff)) >> 7 ^ (char)bVar10 < '\0';
          }
          else {
            bVar10 = (bVar7 + 1) - (bVar1 < 0xfe);
            bVar10 = (byte)((bVar10 ^ bVar7) & (~bVar10 ^ 0xff)) >> 7 ^ (char)bVar10 < '\0';
          }
          if ((bVar10 != 1) &&
             ((byte)(SBORROW2(sStack_1a,uVar8) ^ (short)(sStack_1a - uVar8) < 0) == 1)) {
            sStack_18 = sStack_1a;
            if (sStack_1a < 0) {
              cStack_16 = bVar1 + cStack_16 + -1;
            }
            else {
              sVar6 = uVar9 - 2;
              if ((byte)(SBORROW2(sStack_1a,sVar6) ^ sStack_1a - sVar6 < 0 | sStack_1a == sVar6) !=
                  0) {
                cStack_16 = cStack_16 + -1;
              }
            }
            fmt_sci(apbStack_2a,(char *)_a2);
            return (undefined2 *)CONCAT11(extraout_R1,_a4);
          }
        }
        fmt_number((short)apbStack_2a,(char *)abStack_34);
        sStack_18 = 0;
        sVar6 = input_char_count(abStack_34);
        cVar2 = (char)sVar6;
        if ((cStack_1b == '\0') ||
           (cVar3 = cStack_16 - cVar2,
           (byte)(SBORROW1(cVar3,'\x01') ^ (char)(cVar3 + -1) < '\0' | cVar3 == '\x01') == 0)) {
          cStack_16 = (cStack_16 - cVar2) + -1;
        }
        else {
          cStack_16 = cStack_16 - cVar2;
        }
        fmt_sci(apbStack_2a,(char *)_a2);
        tok = (undefined2 *)strcat_checked((char *)_a2,(char *)abStack_34);
      }
    }
    else {
      tok = (undefined2 *)0x5245;
      *_a2 = 0x5245;
      *(undefined *)(_a2 + 1) = 0x52;
      *(undefined *)((short)_a2 + 3) = 0x4f;
      *(undefined *)(_a2 + 2) = 0x52;
      *(undefined *)((short)_a2 + 5) = 0;
    }
  }
  return tok;
}

