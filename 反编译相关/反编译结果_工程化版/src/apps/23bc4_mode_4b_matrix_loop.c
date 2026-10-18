/*
 * 应用模式 / 23bc4_mode_4b_matrix_loop.c
 * 地址范围: 0x23BC4 - 0x24128
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 0xD111==0x4B，推测为矩阵/向量模式
 * @addr 0x23BC4
 * @module apps
 * @proto void mode_4b_matrix_loop(byte* input)
 * @confidence strong
 * @note 【0xD111==0x4B，推测为矩阵/向量模式】主循环：调用 0x28594。
 * @tag mode
 */
int mode_4b_matrix_loop(byte* input)

{
  do {
    mode_4b_matrix_impl(input);
  } while ((byte)input_key != 0x24 ||
           (bool)((char)((ushort)input_key >> 8) + '\x04') != (byte)input_key < 0x24);
  return 0;
}

/**
 * @brief 写按键历史 v，调用 0x1FF9E，并把 0xD116 置 3
 * @addr 0x23C9A
 * @module apps
 * @proto void mode_switch_hist(char v)
 * @confidence likely
 * @note 写按键历史 v，调用 0x1FF9E，并把 0xD116 置 3。
 * @tag mode
 */
int mode_switch_hist(char v)

{
  key_hist_clear0((char)v);
  list_entry_fetch(v);
  key_modifiers = 3;
  return 0;
}

/**
 * @brief 设置编辑状态 0xD114（变化时 0xD115=1），并把 v 写入按键历史
 * @addr 0x24104
 * @module apps
 * @proto void edit_state_set(byte v)
 * @confidence strong
 * @note 设置编辑状态 0xD114（变化时 0xD115=1），并把 v 写入按键历史。
 * @tag ui
 */
int edit_state_set(byte v)

{
  undefined uVar1;
  
  if ((edit_state2 != -0x40) || (uVar1 = 0xc0, v != -0x40)) {
    uVar1 = 1;
    stat_state = 1;
  }
  edit_state2 = v;
  key_hist_clear0(uVar1);
  return 0;
}

/**
 * @brief 向导编辑流程（4.7KB，0x286D4 调用）
 * @addr 0x24128
 * @module apps
 * @proto void wizard_edit(void)
 * @confidence likely
 * @note 向导编辑流程（4.7KB，0x286D4 调用）。
 * @tag ui
 */
int wizard_edit(uintptr_t _a2, int _a1)

{
  char cVar1;
  byte bVar2;
  ushort uVar3;
  undefined2 uVar4;
  char cVar5;
  short unaff_ER14;
  
  uVar3 = frame_enter();
  *(undefined2 *)(unaff_ER14 + -2) = *(undefined2 *)((ushort)(byte)(sub_mode - 1) * 2 + 0x66d4);
  cur_line = 10;
  uVar4 = dec_cmp(_a1,_a1);
  cVar1 = (char)uVar4;
  cVar5 = (char)uVar3;
  bVar2 = (byte)(uVar3 >> 8);
  if (cVar1 == '\x02') {
    if (((list_col == cVar5) && (list_row == bVar2)) && (cursor_visible = 4, bVar2 != 1)) {
      draw_char_fast(CONCAT11(*(undefined *)((uVar3 & 0xff) + 0x51f1), (uintptr_t)0)
                              *(char *)(bVar2 + 0x51ed) + '\x06'),0x20);
      draw_char_fast(CONCAT11(*(undefined *)((uVar3 & 0xff) + 0x51f1), (uintptr_t)0)
                              *(char *)(bVar2 + 0x51ed) + '\f'),0x20);
    }
    draw_char_fast(CONCAT11(*(undefined *)((uVar3 & 0xff) + 0x51f1),*(undefined *)(bVar2 + 0x51ed)), (uintptr_t)0)
                   0x2d);
    if ((list_col == cVar5) && (list_row == bVar2)) {
      cursor_visible = 0;
    }
  }
  else if ((cVar1 == '\x04') || (cVar1 == '\x01')) {
    if ((list_col == cVar5) && (list_row == bVar2)) {
      cursor_visible = 4;
      draw_char_fast(CONCAT11(*(undefined *)((uVar3 & 0xff) + 0x51f1), (uintptr_t)0)
                              *(char *)(bVar2 + 0x51ed) + '\x06'),0x20);
      draw_char_fast(CONCAT11(*(undefined *)((uVar3 & 0xff) + 0x51f1), (uintptr_t)0)
                              *(char *)(bVar2 + 0x51ed) + '\f'),0x20);
    }
    if (list_page == 1) {
      if (bVar2 == 1) {
        draw_char_fast(CONCAT11(*(undefined *)((uVar3 & 0xff) + 0x51f1),RAM8(0x51ee)),0x20);
      }
      cVar1 = *(char *)(unaff_ER14 + -1);
      if (cVar1 == '\x03') {
        draw_char_fast(CONCAT11(*(undefined *)((uVar3 & 0xff) + 0x51f1), (uintptr_t)0)
                                *(undefined *)(bVar2 + 0x51ed)),0x20);
        if (bVar2 == 2) {
          draw_char_fast(CONCAT11(*(undefined *)((uVar3 & 0xff) + 0x51f1), (uintptr_t)0)
                                  *(undefined *)(bVar2 + 0x51ed)),0x2b);
        }
      }
      else if (((cVar1 == '\x04') || (cVar1 == '\x05')) && (bVar2 != 1)) {
        draw_char_fast(CONCAT11(*(undefined *)((uVar3 & 0xff) + 0x51f1), (uintptr_t)0)
                                *(undefined *)(bVar2 + 0x51ed)),0x2b);
      }
    }
    else if (list_page == 2) {
      if (*(char *)(unaff_ER14 + -1) == '\x04') {
        if (bVar2 == 3) {
          draw_char_fast(CONCAT11(*(undefined *)((uVar3 & 0xff) + 0x51f1),_DAT_ram_51f0),0x20);
        }
        else {
          draw_char_fast(CONCAT11(*(undefined *)((uVar3 & 0xff) + 0x51f1), (uintptr_t)0)
                                  *(undefined *)(bVar2 + 0x51ed)),0x2b);
        }
      }
      else {
        draw_char_fast(CONCAT11(*(undefined *)((uVar3 & 0xff) + 0x51f1), (uintptr_t)0)
                                *(undefined *)(bVar2 + 0x51ed)),0x2b);
      }
    }
    else if (list_page == 3) {
      if (bVar2 == 3) {
        draw_char_fast(CONCAT11(*(undefined *)((uVar3 & 0xff) + 0x51f1),_DAT_ram_51f0),0x20);
      }
      else {
        draw_char_fast(CONCAT11(*(undefined *)((uVar3 & 0xff) + 0x51f1), (uintptr_t)0)
                                *(undefined *)(bVar2 + 0x51ed)),0x2b);
      }
    }
    if ((list_col == cVar5) && (list_row == bVar2)) {
      cursor_visible = 0;
    }
  }
  if (list_page == 1) {
    if (bVar2 == 1) {
      draw_char_fast(CONCAT11(*(undefined *)((uVar3 & 0xff) + 0x51f1),RAM8(0x51f6)),0x78);
    }
    if (bVar2 == 2) {
      draw_char_fast(CONCAT11(*(undefined *)((uVar3 & 0xff) + 0x51f1),RAM8(0x51f7)),0x79);
    }
    if (((*(char *)(unaff_ER14 + -1) == '\x04') || (*(char *)(unaff_ER14 + -1) == '\x05')) &&
       (bVar2 == 3)) {
      draw_char_fast(CONCAT11(*(undefined *)((uVar3 & 0xff) + 0x51f1),RAM8(0x51f8)),0x7a);
    }
  }
  else if (list_page == 2) {
    if (bVar2 == 1) {
      draw_char_fast(CONCAT11(*(undefined *)((uVar3 & 0xff) + 0x51f1),RAM8(0x51f6)),0x79);
    }
    if (bVar2 == 2) {
      draw_char_fast(CONCAT11(*(undefined *)((uVar3 & 0xff) + 0x51f1),RAM8(0x51f7)),0x7a);
    }
    if ((*(char *)(unaff_ER14 + -1) == '\x05') && (bVar2 == 3)) {
      draw_char_fast(CONCAT11(*(undefined *)((uVar3 & 0xff) + 0x51f1),RAM8(0x51f8)),0x74);
    }
  }
  else if (list_page == 3) {
    if (bVar2 == 1) {
      draw_char_fast(CONCAT11(*(undefined *)((uVar3 & 0xff) + 0x51f1),RAM8(0x51f6)),0x7a);
    }
    if (bVar2 == 2) {
      draw_char_fast(CONCAT11(*(undefined *)((uVar3 & 0xff) + 0x51f1),RAM8(0x51f7)),0x74);
    }
  }
  bVar2 = *(byte *)(unaff_ER14 + -1) - list_page;
  if (bVar2 == 2 && (bool)-(*(byte *)(unaff_ER14 + -1) < list_page) == bVar2 < 2) {
    draw_char_fast(CONCAT11(*(undefined *)((uVar3 & 0xff) + 0x51f1),_DAT_ram_51f0 + -6),0x3d);
  }
  frame_leave();
  return 0;
}

