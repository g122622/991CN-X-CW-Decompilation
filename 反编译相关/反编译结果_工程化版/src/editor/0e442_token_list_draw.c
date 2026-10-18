/*
 * 输入编辑器 / 0e442_token_list_draw.c
 * 地址范围: 0x0E442 - 0x0EC1C
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 令牌列表绘制（4.7KB，0xC85A/0xDAA4/0x1E99E 使用）
 * @addr 0x0E442
 * @module editor
 * @proto int token_list_draw(void)
 * @confidence likely
 * @note 令牌列表绘制（4.7KB，0xC85A/0xDAA4/0x1E99E 使用）。
 * @tag editor
 */
int token_list_draw(uintptr_t _a2, int _a1)

{
  byte bVar1;
  byte bVar2;
  char *pcVar3;
  ushort uVar4;
  byte bVar5;
  byte bVar6;
  short sVar7;
  byte bVar8;
  char cVar9;
  char cVar10;
  short sVar11;
  short unaff_ER14;
  
  pcVar3 = (char *)frame_enter();
  bVar1 = key_hist_hi();
  bVar2 = key_hist_lo();
  if ((1 < bVar2) && (bVar2 < 10)) {
    cVar9 = (char)_a1;
    if ((cVar9 == '\x02') || (cVar9 == '\x05')) {
      if (bVar2 < 6) {
        bVar1 = 5;
      }
      else {
        bVar1 = 6;
      }
      key_hist_clear_lo(bVar1);
    }
    else {
      cVar10 = (char)((ushort)_a1 >> 8);
      if ((cVar10 == '\0') || (*pcVar3 != '\0')) {
        sVar11 = -0x15;
        *(undefined2 *)(unaff_ER14 + -2) = 3;
        if (cVar10 == '\x01') {
          sVar11 = -0x1b;
          *(undefined2 *)(unaff_ER14 + -2) = 9;
        }
        uVar4 = mul_signed16(*(ushort *)(pcVar3 + 0x10),3);
        *(ushort *)(unaff_ER14 + -4) = uVar4;
        if ((short)uVar4 < 0) {
          *(short *)(unaff_ER14 + -4) = *(short *)(unaff_ER14 + -4) + 3;
        }
        sVar7 = *(short *)(pcVar3 + 0x10);
        if (*pcVar3 == '\0') {
          bVar2 = 6;
          sVar7 = 0;
        }
        else if (bVar2 < 6) {
          sVar11 = *(short *)(unaff_ER14 + -4);
          if (((sVar11 == 0) && (bVar1 == 6)) && (bVar2 == 5)) {
            bVar2 = 4;
          }
          sVar7 = CONCAT11(((char)((ushort)sVar7 >> 8) - (char)((ushort)sVar11 >> 8)) -
                           ((byte)sVar7 < (byte)sVar11),(byte)sVar7 - (byte)sVar11);
          *(short *)(unaff_ER14 + -4) = sVar7;
          sVar7 = sVar7 + (bVar2 - 5) * 3;
          while( true ) {
            bVar6 = (byte)((ushort)sVar7 >> 8);
            bVar5 = (bVar6 + 1) - ((byte)sVar7 < 0x9d);
            if (((byte)((byte)((bVar5 ^ bVar6) & (~bVar5 ^ 0xff)) >> 7 ^ (char)bVar5 < '\0') != 1)
               && ((char)(((byte)(pcVar3[0x10] - (byte)sVar7) < 10) << 7) < '\0')) break;
            bVar2 = bVar2 + 1;
            sVar7 = (bVar2 - 5) * 3 + *(short *)(unaff_ER14 + -4);
          }
        }
        else {
          if (*(short *)(unaff_ER14 + -4) == 0) {
            if ((bVar1 == 5) && (bVar2 == 6)) {
              bVar2 = 7;
            }
          }
          else {
            bVar5 = (byte)*(undefined2 *)(unaff_ER14 + -4);
            *(ushort *)(unaff_ER14 + -4) =
                 CONCAT11(-(3 < bVar5) - (char)((ushort)*(undefined2 *)(unaff_ER14 + -4) >> 8),
                          '\x03' - bVar5);
          }
          if ((cVar9 != '\0') &&
             (((((byte)(SBORROW2(sVar7,sVar11) ^ sVar7 - sVar11 < 0 | sVar7 == sVar11) == 1 ||
                ((byte)(SBORROW2(sVar7,*(short *)(unaff_ER14 + -2)) ^
                       sVar7 - *(short *)(unaff_ER14 + -2) < 0) != 1)) &&
               (*(short *)(unaff_ER14 + -4) == 0)) && (bVar2 == 9)))) {
            bVar2 = 8;
          }
          sVar7 = sVar7 + *(short *)(unaff_ER14 + -4);
          *(short *)(unaff_ER14 + -4) = sVar7;
          sVar7 = sVar7 + (bVar2 - 6) * 3;
          while( true ) {
            bVar6 = (byte)sVar7;
            bVar8 = (byte)((ushort)sVar7 >> 8);
            bVar5 = bVar8 - (bVar6 < 99);
            if (((byte)((byte)((bVar5 ^ bVar8) & ~bVar5) >> 7 ^ (char)bVar5 < '\0' |
                       (bVar6 == 99 && bVar5 == 0)) != 0) && ((byte)(bVar6 - pcVar3[0x10]) < 10))
            break;
            bVar2 = bVar2 - 1;
            sVar7 = (bVar2 - 6) * 3 + *(short *)(unaff_ER14 + -4);
          }
        }
        if ((cVar10 != '\0') &&
           ((((char)((bVar1 < 2) << 7) < '\0' || (9 < bVar1)) && (mixed_fraction == '\0')))) {
          if ((bVar2 == 5) &&
             (bVar5 = (byte)((ushort)sVar7 >> 8), bVar1 = (bVar5 + 1) - ((byte)sVar7 < 0x9f),
             (byte)((byte)((bVar1 ^ bVar5) & (~bVar1 ^ 0xff)) >> 7 ^ (char)bVar1 < '\0' |
                   ((byte)sVar7 == 0x9f && bVar1 == 0)) != 1)) {
            bVar2 = 4;
            sVar7 = sVar7 + -3;
          }
          if (((bVar2 == 6) && (*(short *)(pcVar3 + 0x12) == 0)) &&
             ((*(short *)(pcVar3 + 0x10) == sVar7 &&
              (bVar5 = (byte)((ushort)sVar7 >> 8), bVar1 = bVar5 - ((byte)sVar7 < 0x61),
              (bool)((byte)((bVar1 ^ bVar5) & ~bVar1) >> 7) != (char)bVar1 < '\0')))) {
            bVar2 = 7;
            sVar7 = sVar7 + 3;
          }
        }
        key_hist_clear_lo(bVar2);
        bVar1 = (byte)*(undefined2 *)(pcVar3 + 0x10);
        *(ushort *)(pcVar3 + 0x12) =
             CONCAT11(((char)((ushort)*(undefined2 *)(pcVar3 + 0x10) >> 8) -
                      (char)((ushort)sVar7 >> 8)) - (bVar1 < (byte)sVar7),bVar1 - (byte)sVar7);
        *(short *)(pcVar3 + 0x10) = sVar7;
      }
    }
  }
  frame_leave();
  return 0;
}

/**
 * @brief 标记输入需要重绘
 * @addr 0x0E5D6
 * @module editor
 * @proto int editor_mark_dirty(void)
 * @confidence likely
 * @note 标记输入需要重绘。
 * @tag editor
 */
int editor_mark_dirty(void)

{
  byte bVar1;
  undefined *puVar2;
  ushort uVar3;
  
  puVar2 = (undefined *)frame_enter();
  bVar1 = key_hist_lo();
  if ((((bVar1 != 1) && (uVar3 = dec_type_of(puVar2), (char)uVar3 == '@')) &&
      (((char)((bVar1 < 2) << 7) < '\0' || (0xc < bVar1)))) && (bVar1 == 0xd)) {
    key_hist_hi();
  }
  frame_leave();
  return 0;
}

/**
 * @brief 编辑器退格处理
 * @addr 0x0E620
 * @module editor
 * @proto void editor_backspace(ushort n)
 * @confidence likely
 * @note 编辑器退格处理。
 * @tag editor
 */
int editor_backspace(ushort n)

{
  bool bVar1;
  short sVar2;
  short sVar3;
  ushort uVar4;
  short unaff_ER14;
  
  sVar2 = frame_enter();
  if ((((byte)n < 7) && ((byte)(n >> 8) <= *(byte *)((n & 0xff) * 2 + -0x2f08)))
     && (*(byte *)(unaff_ER14 + 0x10) <= *(byte *)((n & 0xff) * 2 + -0x2f07))) {
    sVar3 = stat_cell_addr(n,*(byte *)(unaff_ER14 + 0x10));
    uVar4 = 8;
    do {
      *(undefined2 *)(sVar3 + 8) = *(undefined2 *)(sVar2 + 8);
      sVar2 = sVar2 + -2;
      sVar3 = sVar3 + -2;
      bVar1 = 1 < uVar4;
      uVar4 = uVar4 - 2;
    } while ((char)(bVar1 << 7) < '\0');
  }
  frame_leave();
  return 0;
}

/**
 * @brief 编辑选择区域处理
 * @addr 0x0E674
 * @module editor
 * @proto ushort editor_selection(ushort a, char b)
 * @confidence likely
 * @note 编辑选择区域处理。
 * @tag editor
 */
ushort editor_selection(ushort a, char b)

{
  if ((b == '\0') && (mixed_fraction == '\0')) {
    str_emit_backtick2();
  }
  else {
    str_emit_1D39();
  }
  return a;
}

/**
 * @brief 编辑器格式化/分词
 * @addr 0x0E698
 * @module editor
 * @proto int editor_format(char* p)
 * @confidence likely
 * @note 编辑器格式化/分词。
 * @tag editor
 */
int editor_format(char* p)

{
  byte bVar1;
  char cVar2;
  char cVar3;
  byte bVar4;
  undefined uVar5;
  undefined2 *puVar6;
  ushort uVar7;
  byte bVar12;
  ushort uVar8;
  ushort uVar9;
  ushort uVar10;
  byte *pbVar11;
  undefined2 *puVar13;
  short sVar14;
  undefined2 uVar15;
  char cVar16;
  byte bVar17;
  short unaff_ER14;
  
  puVar6 = (undefined2 *)frame_enter();
  *(undefined *)(unaff_ER14 + -0x59) = 10;
  puVar13 = puVar6;
  dec_copy((undefined2 *)(unaff_ER14 + -10),puVar6);
  dec_bin_result((ushort *)(unaff_ER14 + -10),puVar13);
  dec_cmp_signed(unaff_ER14 + -10,puVar13);
  uVar7 = dec_unary_sin((undefined2 *)(unaff_ER14 + -10),puVar13);
  cVar3 = mixed_fraction;
  cVar2 = disp_mode;
  bVar12 = (byte)(uVar7 >> 8);
  bVar4 = bVar12 - ((byte)uVar7 < 7);
  if ((byte)((byte)((bVar4 ^ bVar12) & ~bVar4) >> 7 ^ (char)bVar4 < '\0') == 1) {
    dec_set_from_fmt(unaff_ER14 + -0x14,CONCAT11((char)((ushort)puVar13 >> 8),0x3c));
    *p = '\0';
    puVar13 = (undefined2 *)(unaff_ER14 + -10);
    dec_copy((undefined2 *)(unaff_ER14 + -0x1e),puVar13);
    dec_unary_cos(unaff_ER14 + -0x1e,puVar13);
    decm_round10(unaff_ER14 + -10,puVar13);
    uVar8 = dec_unary_sin((undefined2 *)(unaff_ER14 + -10),puVar13);
    sVar14 = unaff_ER14 + -0x14;
    dec_bin_pow_core(unaff_ER14 + -10,sVar14);
    dec_cmp_ex((undefined2 *)(unaff_ER14 + -10),sVar14);
    uVar9 = dec_unary_sin((undefined2 *)(unaff_ER14 + -10),sVar14);
    puVar13 = (undefined2 *)(unaff_ER14 + -10);
    dec_copy((undefined2 *)(unaff_ER14 + -0x28),puVar13);
    dec_unary_cos(unaff_ER14 + -0x28,puVar13);
    decm_round10(unaff_ER14 + -10,puVar13);
    uVar10 = dec_unary_sin((undefined2 *)(unaff_ER14 + -10),puVar13);
    sVar14 = unaff_ER14 + -0x14;
    dec_bin_pow_core(unaff_ER14 + -10,sVar14);
    dec_cmp_ex((undefined2 *)(unaff_ER14 + -10),sVar14);
    dec_exp_shift((undefined2 *)(unaff_ER14 + -10), (uintptr_t)0)
                   CONCAT11((char)((ushort)sVar14 >> 8),
                            '\x0e' - (((byte)uVar7 - (char)uVar8) + ((char)uVar9 - (char)uVar10))));
    uVar15 = 2;
    dec_bcd_to_bin((undefined2 *)(unaff_ER14 + -10),2);
    dec_to_bcd_a((undefined2 *)(unaff_ER14 + -10),uVar15);
    dec_bcd_to_bin((undefined2 *)(unaff_ER14 + -10),0xfffe);
    uVar15 = dec_to_string(unaff_ER14 + -10,(undefined2 *)(unaff_ER14 + -0x14));
    if ((char)uVar15 != '\x02') {
      dec_bin_or_core(unaff_ER14 + -10,unaff_ER14 + -0x14);
      dec_bin_xor_core(unaff_ER14 + -0x28,(undefined2 *)0x1b6c);
    }
    puVar13 = (undefined2 *)(unaff_ER14 + -0x14);
    uVar15 = dec_to_string(unaff_ER14 + -0x28,puVar13);
    if ((char)uVar15 != '\x02') {
      dec_bin_or_core(unaff_ER14 + -0x28,unaff_ER14 + -0x14);
      puVar13 = (undefined2 *)0x1b6c;
      dec_bin_xor_core(unaff_ER14 + -0x1e,(undefined2 *)0x1b6c);
    }
    uVar7 = dec_unary_sin((undefined2 *)(unaff_ER14 + -0x1e),puVar13);
    bVar12 = (byte)(uVar7 >> 8);
    bVar4 = bVar12 - ((byte)uVar7 < 7);
    if ((byte)((byte)((bVar4 ^ bVar12) & ~bVar4) >> 7 ^ (char)bVar4 < '\0') == 1) {
      uVar15 = dec_cmp(puVar6,puVar13);
      if (((char)uVar15 == '\x02') &&
         (((uVar15 = dec_cmp((undefined2 *)(unaff_ER14 + -0x1e),puVar13),
           (char)uVar15 != '\x01' ||
           (uVar15 = dec_cmp((undefined2 *)(unaff_ER14 + -0x28),puVar13),
           (char)uVar15 != '\x01')) ||
          (uVar15 = dec_cmp((undefined2 *)(unaff_ER14 + -10),puVar13), (char)uVar15 != '\x01'
          )))) {
        cVar16 = '\0';
        if ((cVar2 != '\0') || (cVar3 != '\0')) {
          cVar16 = '\x01';
        }
        editor_selection(p,cVar16);
      }
      pbVar11 = dec_parse((byte *)(unaff_ER14 + -0x1e),(byte **)(unaff_ER14 + -0x40));
      if ((char)pbVar11 != '\0') {
        bVar17 = 0;
        bVar4 = (byte)*(undefined2 *)(unaff_ER14 + -0x30);
        bVar12 = (byte)((ushort)*(undefined2 *)(unaff_ER14 + -0x30) >> 8);
        if (bVar4 == 4 && (bool)bVar12 == bVar4 < 4) {
          bVar17 = 1;
        }
        else {
          bVar1 = bVar12 - (bVar4 < 3);
          if ((byte)((byte)((bVar1 ^ bVar12) & ~bVar1) >> 7 ^ (char)bVar1 < '\0' |
                    (bVar4 == 3 && bVar1 == 0)) != 0) {
            bVar17 = 2;
          }
        }
        *(undefined2 *)(unaff_ER14 + -0x2e) = *(undefined2 *)(unaff_ER14 + -0x30);
        *(undefined *)(unaff_ER14 + -0x2c) = 7;
        *(undefined *)(unaff_ER14 + -0x2b) = 1;
        bVar4 = (byte)unaff_ER14;
        cVar16 = (char)((ushort)unaff_ER14 >> 8);
        fmt_sci(unaff_ER14 + -0x40, (uintptr_t)0)
                       (char *)CONCAT11(cVar16 + -1 + (0x53 < bVar4),bVar4 + 0xac));
        strcat_checked(p,(char *)CONCAT11(cVar16 + -1 + (0x53 < bVar4),bVar4 + 0xac));
        *(undefined *)(unaff_ER14 + -0x57) = 0;
        if (cVar3 == '\0') {
          if (cVar2 == '\0') {
            uVar5 = 0x85;
          }
          else {
            uVar5 = 0xd9;
          }
        }
        else {
          uVar5 = 0xdc;
        }
        *(undefined *)(unaff_ER14 + -0x58) = uVar5;
        strcat_checked(p,(char *)CONCAT11(cVar16 + -1 + (0x57 < bVar4),bVar4 + 0xa8));
        pbVar11 = dec_parse((byte *)(unaff_ER14 + -0x28),(byte **)(unaff_ER14 + -0x40));
        if ((char)pbVar11 != '\0') {
          *(undefined2 *)(unaff_ER14 + -0x2e) = *(undefined2 *)(unaff_ER14 + -0x30);
          *(char *)(unaff_ER14 + -0x2c) = *(char *)(unaff_ER14 + -0x30) + '\x01';
          *(undefined *)(unaff_ER14 + -0x2b) = 1;
          fmt_sci(unaff_ER14 + -0x40, (uintptr_t)0)
                         (char *)CONCAT11(cVar16 + -1 + (0x53 < bVar4),bVar4 + 0xac));
          strcat_checked(p,(char *)CONCAT11(cVar16 + -1 + (0x53 < bVar4),bVar4 + 0xac));
          *(undefined *)(unaff_ER14 + -0x57) = 0;
          if (cVar3 == '\0') {
            if (cVar2 == '\0') {
              *(undefined *)(unaff_ER14 + -0x58) = 0x27;
            }
            else {
              *(undefined *)(unaff_ER14 + -0x58) = 0xfb;
              *(undefined *)(unaff_ER14 + -0x57) = 0x3d;
              *(undefined *)(unaff_ER14 + -0x56) = 0;
            }
          }
          else {
            *(undefined *)(unaff_ER14 + -0x58) = 0xdc;
          }
          strcat_checked(p,(char *)CONCAT11(cVar16 + -1 + (0x57 < bVar4),bVar4 + 0xa8));
          pbVar11 = dec_parse((byte *)(unaff_ER14 + -10),(byte **)(unaff_ER14 + -0x40));
          if ((char)pbVar11 != '\0') {
            sVar14 = (ushort)bVar17 + *(short *)(unaff_ER14 + -0x30) + 1;
            *(short *)(unaff_ER14 + -0x2e) = sVar14;
            if (sVar14 < 0 || (char)sVar14 == '\0' && (char)((ushort)sVar14 >> 8) == '\0') {
              uVar5 = 1;
            }
            else {
              uVar5 = *(undefined *)(unaff_ER14 + -0x2e);
            }
            *(undefined *)(unaff_ER14 + -0x2c) = uVar5;
            *(undefined2 *)(unaff_ER14 + -0x2e) = *(undefined2 *)(unaff_ER14 + -0x30);
            *(undefined *)(unaff_ER14 + -0x2b) = 1;
            fmt_sci(unaff_ER14 + -0x40, (uintptr_t)0)
                           (char *)CONCAT11(cVar16 + -1 + (0x53 < bVar4),bVar4 + 0xac));
            strcat_checked(p,(char *)CONCAT11(cVar16 + -1 + (0x53 < bVar4),bVar4 + 0xac));
            *(undefined *)(unaff_ER14 + -0x57) = 0;
            if (cVar3 == '\0') {
              if (cVar2 == '\0') {
                *(undefined *)(unaff_ER14 + -0x58) = 0x22;
              }
              else {
                *(undefined *)(unaff_ER14 + -0x58) = 0xfb;
                *(undefined *)(unaff_ER14 + -0x57) = 0x3e;
                *(undefined *)(unaff_ER14 + -0x56) = 0;
              }
            }
            else {
              *(undefined *)(unaff_ER14 + -0x58) = 0xdc;
            }
            strcat_checked(p,(char *)CONCAT11(cVar16 + -1 + (0x57 < bVar4),bVar4 + 0xa8));
            *(undefined *)(unaff_ER14 + -0x59) = 1;
          }
        }
      }
    }
  }
  frame_leave();
  return 0;
}

/**
 * @brief 循环调用 0xB3DC（输入区插入 # 记号）直到返回非 0
 * @addr 0x0EA12
 * @module editor
 * @proto int input_mark_hash_loop(void)
 * @confidence likely
 * @note 循环调用 0xB3DC（输入区插入 # 记号）直到返回非 0。
 * @tag editor
 */
int input_mark_hash_loop(void)

{
  short sVar1;
  
  frame_enter();
  do {
    sVar1 = input_mark_hash();
  } while (sVar1 != 0);
  frame_leave();
  return 0;
}

/**
 * @brief 按方向掩码在光标两侧绘制插入符（0xEA36 与 0xBC08 配合）
 * @addr 0x0EA36
 * @module editor
 * @proto void draw_insert_cursor(ushort dirMask)
 * @confidence likely
 * @note 按方向掩码在光标两侧绘制插入符（0xEA36 与 0xBC08 配合）。
 * @tag editor
 */
int draw_insert_cursor(ushort dirMask)

{
  byte bVar1;
  undefined2 uVar2;
  byte bVar3;
  char cVar4;
  byte bVar5;
  short sVar6;
  char cVar7;
  byte bVar8;
  
  cVar4 = (char)((ushort)dirMask >> 8);
  uVar2 = frame_enter();
  sVar6 = 1;
  if (cVar4 != '\0') {
    sVar6 = -1;
  }
  bVar5 = (byte)sVar6;
  bVar8 = (byte)uVar2 - bVar5;
  cVar7 = (char)((ushort)sVar6 >> 8);
  bVar1 = (byte)(sVar6 * 2);
  bVar3 = bVar8 - bVar1;
  cVar4 = ((((char)((ushort)uVar2 >> 8) - cVar7) - ((byte)uVar2 < bVar5)) -
          (char)((ushort)(sVar6 * 2) >> 8)) - (bVar8 < bVar1);
  stat_edit_entry(CONCAT11(cVar4,bVar3));
  stat_edit_entry(CONCAT11((cVar4 - cVar7) - (bVar3 < bVar5),bVar3 - bVar5));
  frame_leave();
  return 0;
}

/**
 * @brief 把当前输入追加进历史记录区（0xD176），必要时滚动
 * @addr 0x0EA80
 * @module editor
 * @proto void append_history(undefined2 k)
 * @confidence strong
 * @note 把当前输入追加进历史记录区（0xD176），必要时滚动。
 * @tag editor
 */
int append_history(undefined2 k)

{
  ushort uVar1;
  char *pcVar2;
  byte bVar3;
  byte bVar4;
  undefined *puVar5;
  undefined2 uVar6;
  char *pcVar7;
  ushort uVar8;
  int sVar9;
  char cVar10;
  short sVar11;
  byte bVar12;
  short unaff_ER14;
  
  frame_enter();
  puVar5 = history_base_ptr();
  *(undefined **)(unaff_ER14 + -10) = puVar5;
  pcVar2 = input_ptr;
  if (puVar5 != (undefined *)0x0) {
    bVar12 = 10;
    *(undefined *)(unaff_ER14 + -1) = key_history_flags;
    uVar6 = dec_cmp((undefined2 *)0xd176,k);
    if ((char)uVar6 != '\x01') {
      *(byte *)(unaff_ER14 + -1) = *(byte *)(unaff_ER14 + -1) | 0x80;
      bVar12 = 0x14;
    }
    if ((key_modifiers & 0x40) == 0) {
      bVar3 = strline_len(pcVar2);
    }
    else {
      pcVar7 = strchr(pcVar2,'#');
      bVar3 = (char)pcVar7 - (char)pcVar2;
    }
    uVar8 = (ushort)bVar12 + (ushort)bVar3 + 4;
    *(ushort *)(unaff_ER14 + -8) = uVar8;
    uVar1 = ((uVar8 >> 8) - 1) - (ushort)((byte)uVar8 < 0x90);
    if ((uVar1 & 0x100) != 0 || (byte)uVar8 == 0x90 && (char)uVar1 == '\0') {
      puVar5 = *(undefined **)(unaff_ER14 + -10);
      sVar9 = input_mark_hash_loop();
      sVar11 = 0;
      while( true ) {
        bVar4 = (byte)sVar11;
        cVar10 = (char)((ushort)sVar11 >> 8);
        if ((ushort)(*(short *)(unaff_ER14 + -8) + sVar9) <=
            CONCAT11(cVar10 + '\x01' + (0x6f < bVar4),bVar4 + 0x90)) break;
        *(undefined **)(unaff_ER14 + -6) = puVar5;
        puVar5 = (undefined *)input_mark_hash();
        bVar4 = (byte)*(undefined2 *)(unaff_ER14 + -6);
        sVar11 = sVar11 + CONCAT11(((char)((ushort)puVar5 >> 8) -
                                   (char)((ushort)*(undefined2 *)(unaff_ER14 + -6) >> 8)) -
                                   ((byte)puVar5 < bVar4),(byte)puVar5 - bVar4);
      }
      sVar9 = CONCAT11(((char)((ushort)sVar9 >> 8) - cVar10) - ((byte)sVar9 < bVar4),
                       (byte)sVar9 - bVar4);
      memmove(*(undefined **)(unaff_ER14 + -10),puVar5,sVar9);
      puVar5 = (undefined *)(*(short *)(unaff_ER14 + -10) + sVar9);
      *(undefined **)(unaff_ER14 + -10) = puVar5;
      memzero(puVar5,sVar11);
      puVar5 = *(undefined **)(unaff_ER14 + -10);
      *(undefined **)(unaff_ER14 + -10) = puVar5 + 1;
      memmove(puVar5,(undefined *)(unaff_ER14 + -1),1);
      *(undefined *)(unaff_ER14 + -1) = key_hist_a;
      puVar5 = *(undefined **)(unaff_ER14 + -10);
      *(undefined **)(unaff_ER14 + -10) = puVar5 + 1;
      memmove(puVar5,(undefined *)(unaff_ER14 + -1),1);
      *(undefined *)(unaff_ER14 + -1) = key_hist_b;
      puVar5 = *(undefined **)(unaff_ER14 + -10);
      *(undefined **)(unaff_ER14 + -10) = puVar5 + 1;
      memmove(puVar5,(undefined *)(unaff_ER14 + -1),1);
      memcpy_bytes(*(undefined **)(unaff_ER14 + -10),(undefined *)0xd16c,(ushort)bVar12);
      *(ushort *)(unaff_ER14 + -10) = *(short *)(unaff_ER14 + -10) + (ushort)bVar12;
      memcpy_bytes(*(undefined **)(unaff_ER14 + -10),pcVar2,(ushort)bVar3);
      *(ushort *)(unaff_ER14 + -10) = *(short *)(unaff_ER14 + -10) + (ushort)bVar3;
      *(undefined *)(unaff_ER14 + -4) = 0x23;
      *(undefined *)(unaff_ER14 + -3) = 0;
      memcpy_bytes(*(undefined **)(unaff_ER14 + -10),(undefined *)(unaff_ER14 + -4),1);
    }
  }
  frame_leave();
  return 0;
}

/**
 * @brief K 模式且状态 1 时返回 1
 * @addr 0x0EC04
 * @module editor
 * @proto char editor_accept_ready(void)
 * @confidence likely
 * @note K 模式且状态 1 时返回 1。
 * @tag editor
 */
char editor_accept_ready(void)

{
  if ((calc_mode == 'K') && (edit_state2 == '\x01')) {
    return 1;
  }
  return 0;
}

/**
 * @brief 初始化编辑区与模式
 * @addr 0x0EC1C
 * @module editor
 * @proto void editor_init(byte* p, ushort len)
 * @confidence strong
 * @note 初始化编辑区与模式。
 * @tag editor
 */
int editor_init(byte* p, ushort len)

{
  clear_replay_buf(p,len);
  buffer_reset_for_mode(len);
  defaults_load();
  calc_mode = 0xc1;
  sub_mode = 0;
  input_layout = 3;
  edit_state2 = 1;
  mode_index = 0;
  mode_group = 0;
  input_init();
  return 0;
}

