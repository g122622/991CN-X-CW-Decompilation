/*
 * 输入编辑器 / 1ebe0_token_line_index.c
 * 地址范围: 0x1EBE0 - 0x1F12E
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 计算 p 处字符在 0x37A4 表格中的行号（>0x0E 返回 5）
 * @addr 0x1EBE0
 * @module editor
 * @proto byte token_line_index(byte* p)
 * @confidence likely
 * @note 计算 p 处字符在 0x37A4 表格中的行号（>0x0E 返回 5）。
 * @tag editor
 */
byte token_line_index(byte* p)

{
  byte bVar1;
  
  bVar1 = font_class_of(*p);
  if (0xe < bVar1) {
    return 5;
  }
  return *(undefined *)(bVar1 + 0x37a4);
}

/**
 * @brief 编辑值拾取（3.9KB，0xC0DA/0x1E76E 使用）
 * @addr 0x1EF72
 * @module editor
 * @proto void edit_value_pick(void)
 * @confidence likely
 * @note 编辑值拾取（3.9KB，0xC0DA/0x1E76E 使用）。
 * @tag editor
 */
int edit_value_pick(uintptr_t _a2, int _a1)

{
  undefined2 uVar1;
  byte bVar2;
  undefined uVar3;
  byte bVar4;
  ushort uVar5;
  ushort uVar6;
  byte bVar7;
  char cVar8;
  byte bVar9;
  char cVar10;
  byte bVar11;
  short unaff_ER14;
  
  uVar5 = frame_enter();
  bVar2 = dec_regY_1;
  uVar1 = dec_accum8;
  if ((edit_state == '\x01') && ((uVar6 = editor_pos_limit(), uVar6 <= uVar5 || (uVar6 <= _a1)))
     ) {
    cVar8 = (char)((ushort)uVar1 >> 8);
    bVar7 = (byte)uVar1;
    cVar10 = (char)((uint32_t)_a1 >> 8);
    bVar4 = (byte)_a1;
    if (uVar5 < uVar6) {
      uVar3 = memmove_range(_a1);
      *(undefined *)(unaff_ER14 + 0x10) = uVar3;
      bVar9 = 0;
      uVar6 = CONCAT11((cVar10 - cVar8) - (bVar4 < bVar7),bVar4 - bVar7);
      bVar4 = history_key;
    }
    else {
      if (_a1 < uVar6) {
        uVar3 = memmove_range(_a1);
        *(undefined *)(unaff_ER14 + 0x12) = uVar3;
        uVar6 = (ushort)history_key;
      }
      else {
        uVar6 = CONCAT11((cVar10 - cVar8) - (bVar4 < bVar7),bVar4 - bVar7);
      }
      bVar4 = (byte)uVar5 - bVar7;
      bVar9 = ((char)(uVar5 >> 8) - cVar8) - ((byte)uVar5 < bVar7);
    }
    uVar5 = (ushort)bVar9 - (ushort)(bVar4 < 0xbf);
    bVar11 = (byte)(uVar6 >> 8);
    bVar7 = (byte)uVar6;
    if (((uVar5 & 0x100) != 0 || bVar4 == 0xbf && (char)uVar5 == '\0') ||
       (uVar5 = (ushort)bVar11 - (ushort)(bVar7 < 0xbf),
       (uVar5 & 0x100) != 0 || bVar7 == 0xbf && (char)uVar5 == '\0')) {
      uVar5 = (ushort)bVar9 - (ushort)(bVar4 < 0xbf);
      if ((uVar5 & 0x100) == 0 && (bVar4 != 0xbf || (char)uVar5 != '\0')) {
        uVar3 = memmove_range(uVar6);
        *(undefined *)(unaff_ER14 + 0x10) = uVar3;
        bVar4 = 0xbf;
      }
      else {
        uVar5 = (ushort)bVar11 - (ushort)(bVar7 < 0xbf);
        if ((uVar5 & 0x100) == 0 && (bVar7 != 0xbf || (char)uVar5 != '\0')) {
          uVar3 = memmove_range(uVar6);
          *(undefined *)(unaff_ER14 + 0x12) = uVar3;
          uVar6 = 0xbf;
        }
      }
      uVar3 = (undefined)uVar6;
      if ((bVar2 <= *(byte *)(unaff_ER14 + 0x10)) || (bVar2 <= *(byte *)(unaff_ER14 + 0x12))) {
        if (*(byte *)(unaff_ER14 + 0x10) < bVar2) {
          bVar4 = stat_cell_edit2(CONCAT11(*(undefined *)(unaff_ER14 + 0x12))
                                          *(byte *)(unaff_ER14 + 0x10)));
          *(undefined *)(unaff_ER14 + 0x10) = 0;
          *(byte *)(unaff_ER14 + 0x12) = *(char *)(unaff_ER14 + 0x12) - bVar2;
        }
        else if (*(byte *)(unaff_ER14 + 0x12) < bVar2) {
          uVar3 = stat_cell_edit2(CONCAT11(*(byte *)(unaff_ER14 + 0x12))
                                          *(undefined *)(unaff_ER14 + 0x10)));
          *(undefined *)(unaff_ER14 + 0x12) = 0;
          *(byte *)(unaff_ER14 + 0x10) = *(char *)(unaff_ER14 + 0x10) - bVar2;
        }
        else {
          *(byte *)(unaff_ER14 + 0x10) = *(char *)(unaff_ER14 + 0x10) - bVar2;
          *(byte *)(unaff_ER14 + 0x12) = *(char *)(unaff_ER14 + 0x12) - bVar2;
        }
        if ((*(byte *)(unaff_ER14 + 0x10) < 0x40) || (*(byte *)(unaff_ER14 + 0x12) < 0x40)) {
          if (*(byte *)(unaff_ER14 + 0x10) < 0x40) {
            if (0x3f < *(byte *)(unaff_ER14 + 0x12)) {
              uVar3 = stat_cell_edit2(CONCAT11(*(undefined *)(unaff_ER14 + 0x12))
                                              *(undefined *)(unaff_ER14 + 0x10)));
              *(undefined *)(unaff_ER14 + 0x12) = 0x3f;
            }
          }
          else {
            bVar4 = stat_cell_edit2(CONCAT11(*(undefined *)(unaff_ER14 + 0x12))
                                            *(undefined *)(unaff_ER14 + 0x10)));
            *(undefined *)(unaff_ER14 + 0x10) = 0x3f;
          }
          draw_hline_animated(CONCAT11(*(undefined *)(unaff_ER14 + 0x12),uVar3), (uintptr_t)0)
                         CONCAT11(*(undefined *)(unaff_ER14 + 0x10),bVar4));
        }
      }
    }
  }
  frame_leave();
  return 0;
}

/**
 * @brief token 区间替换（1.4KB，0x22BF4 调用
 * @addr 0x1F12E
 * @module editor
 * @proto int token_replace_range(byte* a)
 * @confidence likely
 * @note token 区间替换（1.4KB，0x22BF4 调用；含合并子入口与原文本丢失的一处 0x7F）。
 * @tag editor
 */
int token_replace_range(byte* a)

{
  byte *pbVar1;
  char cVar2;
  char cVar3;
  byte bVar4;
  bool bVar5;
  char *pcVar6;
  undefined2 uVar7;
  undefined extraout_R1;
  char cVar8;
  byte *pbVar9;
  
  pcVar6 = (char *)frame_enter();
  cVar8 = '\x01';
  cVar2 = *pcVar6;
  if (cVar2 == 'P') {
LAB_rom_01f1ce:
    cVar2 = '\x02';
  }
  else if (cVar2 == 'Q') {
    cVar2 = '\x03';
  }
  else {
    if ((cVar2 == 'R') || (cVar2 == 'S')) goto LAB_rom_01f1ce;
    if (((((cVar2 != '}') && (cVar2 != '~')) && (cVar2 != '\x7f')) &&
        ((cVar2 != -0x79 && (cVar2 != -0x78)))) &&
       ((cVar2 != -0x77 && ((cVar2 != -0x76 && (cVar2 != -0x6d)))))) goto LAB_rom_01f16e;
    cVar2 = '\x01';
  }
  pbVar1 = (byte *)(pcVar6 + 1);
  while (pbVar9 = pbVar1, pbVar9 <= a) {
    uVar7 = token_class((char *)pbVar9);
    cVar3 = (char)uVar7;
    if (cVar3 == '\t') {
      cVar8 = cVar8 + -1;
      if (cVar8 == '\0') break;
    }
    else if ((cVar3 == '\b') || (cVar3 == '\n')) {
      cVar8 = cVar8 + '\x01';
    }
    else if (cVar3 == '\x01') {
      bVar4 = token_insert_pos((uintptr_t)0);
      pbVar9 = pbVar9 + bVar4;
    }
    else if ((*pbVar9 == 0x2c) && (cVar8 == '\x01')) {
      if ((char)((cVar2 == '\0') << 7) < '\0') break;
      cVar2 = cVar2 + -1;
    }
    bVar5 = is_neg_char(*pbVar9);
    pbVar1 = pbVar9 + 1;
    if (CONCAT11(extraout_R1,bVar5) != 0) {
      pbVar1 = pbVar9 + 2;
    }
  }
LAB_rom_01f16e:
  frame_leave();
  return 0;
}

