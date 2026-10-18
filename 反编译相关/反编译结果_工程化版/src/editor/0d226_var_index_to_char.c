/*
 * 输入编辑器 / 0d226_var_index_to_char.c
 * 地址范围: 0x0D226 - 0x0D9BC
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 把变量序号转换成变量名字符
 * @addr 0x0D226
 * @module editor
 * @proto char* var_index_to_char(char* out, byte idx)
 * @confidence likely
 * @note 把变量序号转换成变量名字符。
 * @tag editor
 */
char* var_index_to_char(char* out, byte idx)

{
  bool bVar1;
  char cVar2;
  byte bVar3;
  
  bVar3 = 1;
  bVar1 = false;
  if ((disp_mode != '\0') || (mixed_fraction != '\0')) {
    bVar1 = true;
  }
  if (idx < 5) {
    if (bVar1) {
      cVar2 = -0x19 - idx;
    }
    else {
      cVar2 = (uintptr_t)idx - 0x30;
    }
    *out = cVar2;
  }
  else if (idx == 5) {
    if (bVar1) {
      if (mixed_fraction == '\0') {
        *out = -5;
        out[1] = 'C';
        bVar3 = 2;
      }
      else {
        bVar3 = 0;
      }
    }
    else {
      *out = ' ';
    }
  }
  else if (bVar1) {
    *out = -0x18 - idx;
  }
  else {
    *out = (uintptr_t)idx - 0x31;
  }
  out[bVar3] = '\0';
  return out;
}

/**
 * @brief 从历史记录恢复一行到输入区（0xD155 历史游标）
 * @addr 0x0D2E8
 * @module editor
 * @proto void restore_history_line(void)
 * @confidence strong
 * @note 从历史记录恢复一行到输入区（0xD155 历史游标）。
 * @tag editor
 */
int restore_history_line(void)

{
  byte *pbVar1;
  
  frame_enter();
  if ((history_cursor != 0) &&
     (pbVar1 = prev_char_ptr(&input_buf, (uintptr_t)0)
                              (byte *)CONCAT11((0x7f < history_cursor) + -0x2f,history_cursor + 0x80)),
     *pbVar1 == 0x19)) {
    input_active = 0;
    token_del_merge((uintptr_t)0);
  }
  frame_leave();
  return 0;
}

/**
 * @brief 跳过成对括号
 * @addr 0x0D328
 * @module editor
 * @proto void skip_brackets(void)
 * @confidence strong
 * @note 跳过成对括号。
 * @tag editor
 */
int skip_brackets(void)

{
  byte *pbVar1;
  byte *pbVar2;
  undefined2 uVar3;
  char cVar4;
  
  pbVar2 = (byte *)frame_enter();
  pbVar1 = input_ptr;
  cVar4 = '\0';
  for (; pbVar2 != (byte *)0x0; pbVar2 = prev_char_ptr(pbVar1,pbVar2)) {
    uVar3 = token_class((char *)pbVar2);
    if ((char)uVar3 == '\x03') {
      cVar4 = cVar4 + '\x01';
    }
    else if (((char)uVar3 == '\x02') && (cVar4 = cVar4 + -1, cVar4 == '\0')) break;
  }
  pbVar2 = prev_char_ptr(pbVar1,pbVar2);
  if (*pbVar2 == 0x1d) {
    prev_char_ptr(pbVar1,pbVar2);
  }
  frame_leave();
  return 0;
}

/**
 * @brief 光标左移
 * @addr 0x0D3A2
 * @module editor
 * @proto void cursor_left(short n)
 * @confidence likely
 * @note 光标左移。
 * @tag editor
 */
int cursor_left(short n)

{
  byte bVar1;
  byte bVar2;
  char cVar3;
  ushort *puVar4;
  byte bVar5;
  short unaff_ER14;
  
  puVar4 = (ushort *)frame_enter();
  bVar1 = get_ptr_ffd8_2();
  *(undefined *)(unaff_ER14 + -1) = 0;
  bVar2 = line_col_count();
  if (bVar1 == 3) {
    *puVar4 = *puVar4 + (ushort)bVar2 * 2;
  }
  else {
    *(char *)(puVar4 + 1) = *(char *)(puVar4 + 1) + '\x04';
    *puVar4 = *puVar4 + 4;
  }
  if (bVar1 == 2) {
    *(char *)((short)puVar4 + 3) = *(char *)((short)puVar4 + 3) + '\x04';
  }
  if (edit_state == '\x01') {
    if (bVar1 < 2) {
      cVar3 = input_cols2();
      *(char *)(unaff_ER14 + 0x10) = *(char *)(unaff_ER14 + 0x10) - (cVar3 + '\x02');
    }
    if (bVar1 == 2) {
      cVar3 = input_cols();
      *(char *)(unaff_ER14 + 0x10) = *(char *)(unaff_ER14 + 0x10) + cVar3;
    }
    if (bVar1 == 0) {
      draw_spaced((ushort)bVar2,2);
      fill_grid(*(char *)(unaff_ER14 + 0x10));
      if ((ushort)bVar2 * 2 <= *puVar4) {
        draw_spaced((ushort)bVar2,2);
        fill_grid(*(char *)(unaff_ER14 + 0x10));
      }
    }
    else if ((bVar1 == 1) || (bVar1 == 2)) {
      stat_edit_entry((*puVar4 + n) - 4);
    }
    else {
      *(undefined *)(unaff_ER14 + -2) = 0xad;
      edit_line_commit(CONCAT11((char)((ushort)n >> 8) - ((byte)n < bVar2))
                              (byte)n - bVar2));
      *(undefined *)(unaff_ER14 + -2) = 0xae;
      bVar1 = (byte)((ushort)bVar2 * 2);
      bVar5 = (byte)(*puVar4 + n);
      edit_line_commit(CONCAT11(((char)(*puVar4 + n >> 8) - (char)((ushort)bVar2 * 2 >> 8)) )
                              (bVar5 < bVar1),bVar5 - bVar1));
    }
  }
  frame_leave();
  return 0;
}

/**
 * @brief 读取输入区一个字符（处理双字节字符）
 * @addr 0x0D4C8
 * @module editor
 * @proto ushort token_at(byte* p)
 * @confidence strong
 * @note 读取输入区一个字符（处理双字节字符）。
 * @tag editor
 */
ushort token_at(byte* p)

{
  ushort uVar1;
  
  if ((char)((*p < 0xf0) << 7) < '\0') {
    uVar1 = (ushort)*p;
  }
  else {
    uVar1 = ((*p & 0x1fe) * 0x80 + (ushort)(byte)(*p << 7)) * 2 + (ushort)p[1];
  }
  return uVar1;
}

/**
 * @brief c == 0 时输出 ROM 0x1DA7 记号，否则 ROM 0x1D77 记号
 * @addr 0x0D4F6
 * @module editor
 * @proto undefined2 emit_num_by_mode(undefined2 p, byte c)
 * @confidence likely
 * @note c == 0 时输出 ROM 0x1DA7 记号，否则 ROM 0x1D77 记号。
 * @tag text
 */
undefined2 emit_num_by_mode(undefined2 p, byte c)

{
  if (c == '\0') {
    str_emit_1DA7(p);
  }
  else {
    str_emit_1D77(p);
  }
  return p;
}

/**
 * @brief c == 0 时输出 "x="（0x1DA4），否则 ROM 0x1D73 记号
 * @addr 0x0D510
 * @module editor
 * @proto undefined2 emit_num_by_mode2(undefined2 p, byte c)
 * @confidence likely
 * @note c == 0 时输出 "x="（0x1DA4），否则 ROM 0x1D73 记号。
 * @tag text
 */
undefined2 emit_num_by_mode2(undefined2 p, byte c)

{
  if (c == '\0') {
    str_emit_xeq(p);
  }
  else {
    str_emit_1D73(p);
  }
  return p;
}

/**
 * @brief c == 0 时输出 ROM 0x1DAD 记号，否则 ROM 0x1D81 记号
 * @addr 0x0D52A
 * @module editor
 * @proto undefined2 emit_num_by_mode3(undefined2 p, byte c)
 * @confidence likely
 * @note c == 0 时输出 ROM 0x1DAD 记号，否则 ROM 0x1D81 记号。
 * @tag text
 */
undefined2 emit_num_by_mode3(undefined2 p, byte c)

{
  if (c == '\0') {
    str_emit_1DAD(p);
  }
  else {
    str_emit_1D81(p);
  }
  return p;
}

/**
 * @brief 历史/计算循环（0xB342/0xA16E/0x22A8C/0x2AA76 组合）
 * @addr 0x0D544
 * @module editor
 * @proto void hist_loop(short arg)
 * @confidence likely
 * @note 历史/计算循环（0xB342/0xA16E/0x22A8C/0x2AA76 组合）。
 * @tag ui
 */
int hist_loop(short arg)

{
  char cVar1;
  short sVar2;
  
  cVar1 = is_stat_running();
  if (cVar1 == '\0') {
    key_repeat_start();
  }
  do {
    cVar1 = is_stat_running();
    if (cVar1 == '\0') {
      ui_update();
      cVar1 = is_stat_running();
      if (cVar1 != '\0') goto LAB_rom_00d986;
      fb_flush();
      sVar2 = process_key((short)arg);
      sVar2 = key_filter_lookup4(sVar2);
      set_input_key(sVar2);
    }
    else {
LAB_rom_00d986:
      stat_analysis(arg);
      sVar2 = input_key;
    }
    if ((byte)sVar2 == 0x24 && (bool)((char)((ushort)sVar2 >> 8) + '\x04') == (byte)sVar2 < 0x24) {
      return 0;
    }
  } while( true );
}

/**
 * @brief 矩阵模式主分派（5.4KB，0x14C5E/0x14E38/0x14ECE 等矩阵编辑调用）
 * @addr 0x0D548
 * @module editor
 * @proto int matrix_dispatch(void)
 * @confidence likely
 * @note 矩阵模式主分派（5.4KB，0x14C5E/0x14E38/0x14ECE 等矩阵编辑调用）。
 * @tag matrix
 */
int matrix_dispatch(uintptr_t _a2, int _a1)

{
  byte bVar1;
  byte bVar2;
  char cVar3;
  short sVar4;
  short sVar5;
  undefined2 *puVar6;
  undefined2 uVar7;
  undefined2 uVar8;
  short sVar9;
  byte bVar10;
  short unaff_ER14;
  
  sVar4 = frame_enter();
  *(undefined *)(unaff_ER14 + -0x7f) = 0;
  *(undefined *)(unaff_ER14 + -0x80) = 0;
  bVar1 = (byte)unaff_ER14;
  cVar3 = (char)((ushort)unaff_ER14 >> 8);
  memset((undefined *)CONCAT11(cVar3 + -1 + (0x4f < bVar1),bVar1 + 0xb0),0,0x50);
  memset((undefined *)CONCAT11(cVar3 + -1 + (0x53 < bVar1),bVar1 + 0xac),0,4);
  for (bVar10 = 0; bVar10 < _a1; bVar10 = bVar10 + 1) {
    sVar5 = mul16((ushort)bVar10,0x28);
    if (*(short *)(sVar5 + sVar4 + 0x14) != 0) {
      sVar5 = mul16((ushort)bVar10,0x28);
      dec_copy_rev((undefined2 *)CONCAT11(cVar3 + -1 + (0x67 < bVar1),bVar1 + 0x98), (uintptr_t)0)
                     (undefined2 *)(sVar5 + sVar4));
      *(undefined *)(unaff_ER14 + -0x7d) = 0;
      bVar2 = 0;
      while (*(byte *)(unaff_ER14 + -0x7e) = bVar2, bVar2 < _a1) {
        if ((bVar2 != bVar10) &&
           (sVar5 = mul16((ushort)bVar2,0x28), *(short *)(sVar5 + sVar4 + 0x14) != 0)) {
          sVar5 = mul16((ushort)*(byte *)(unaff_ER14 + -0x7e),0x28);
          puVar6 = (undefined2 *)(sVar5 + sVar4);
          dec_copy_rev((undefined2 *)CONCAT11(cVar3 + -1 + (0x7b < bVar1),bVar1 + 0x84),puVar6);
          uVar7 = dec_cmp((undefined2 *)CONCAT11(cVar3 + -1 + (0x5d < bVar1),bVar1 + 0xa2), (uintptr_t)0)
                                 puVar6);
          uVar8 = dec_cmp((undefined2 *)CONCAT11(cVar3 + -1 + (0x71 < bVar1),bVar1 + 0x8e), (uintptr_t)0)
                                 puVar6);
          if (((char)uVar7 != '\x01') || ((char)uVar8 == '\x01')) {
            if (((char)uVar7 == '\x01') || ((char)uVar8 != '\x01')) {
              bVar2 = dec_cmp_bool((undefined2 *)
                                     CONCAT11(cVar3 + -1 + (0x67 < bVar1),bVar1 + 0x98));
              if ((bVar2 & 2) != 0) {
                *(char *)(unaff_ER14 + -0x7d) = *(char *)(unaff_ER14 + -0x7d) + '\x01';
              }
              if ((bVar2 & 1) != 0) {
                bVar2 = dec_cmp_bool((undefined2 *)
                                       CONCAT11(cVar3 + -1 + (0x5d < bVar1),bVar1 + 0xa2));
                if ((bVar2 & 2) != 0) {
                  *(char *)(unaff_ER14 + -0x7d) = *(char *)(unaff_ER14 + -0x7d) + '\x01';
                }
                if ((bVar2 & 1) != 0) {
                  sVar5 = mul16((ushort)bVar10,0x28);
                  sVar9 = mul16((ushort)*(byte *)(unaff_ER14 + -0x7e),0x28);
                  *(short *)(sVar5 + sVar4 + 0x14) =
                       *(short *)(sVar5 + sVar4 + 0x14) + *(short *)(sVar9 + sVar4 + 0x14);
                  sVar5 = mul16((ushort)*(byte *)(unaff_ER14 + -0x7e),0x28);
                  *(undefined2 *)(sVar5 + sVar4 + 0x14) = 0;
                }
              }
            }
            else {
              *(char *)(unaff_ER14 + -0x7d) = *(char *)(unaff_ER14 + -0x7d) + '\x01';
            }
          }
        }
        bVar2 = *(char *)(unaff_ER14 + -0x7e) + 1;
      }
      sVar5 = mul16((ushort)*(byte *)(unaff_ER14 + -0x7d),0x14);
      dec_copy_rev((undefined2 *)(sVar5 + CONCAT11(cVar3 + -1 + (0x4f < bVar1),bVar1 + 0xb0)), (uintptr_t)0)
                     (undefined2 *)CONCAT11(cVar3 + -1 + (0x67 < bVar1),bVar1 + 0x98));
      sVar5 = mul16((ushort)bVar10,0x28);
      bVar2 = *(byte *)(unaff_ER14 + -0x7d);
      *(undefined *)((ushort)bVar2 + unaff_ER14 + -0x54) = *(undefined *)(sVar5 + sVar4 + 0x14);
      *(char *)(unaff_ER14 + -0x7f) =
           *(char *)(unaff_ER14 + -0x7f) + *(char *)((ushort)bVar2 + unaff_ER14 + -0x54);
    }
  }
  *(undefined *)(unaff_ER14 + -0x7e) = 0;
  for (bVar10 = 0; (char)((bVar10 < _a1) << 7) < '\0'; bVar10 = bVar10 + 1) {
    if (*(char *)((ushort)bVar10 + unaff_ER14 + -0x54) != '\0') {
      sVar5 = mul16((ushort)bVar10,0x14);
      sVar9 = mul16((ushort)*(byte *)(unaff_ER14 + -0x7e),0x28);
      dec_copy_rev((undefined2 *)(sVar9 + sVar4), (uintptr_t)0)
                     (undefined2 *)(sVar5 + CONCAT11(cVar3 + -1 + (0x4f < bVar1),bVar1 + 0xb0)));
      sVar5 = mul16((ushort)*(byte *)(unaff_ER14 + -0x7e),0x28);
      *(ushort *)(sVar5 + sVar4 + 0x14) = (ushort)*(byte *)((ushort)bVar10 + unaff_ER14 + -0x54);
      *(char *)(unaff_ER14 + -0x80) =
           *(char *)(unaff_ER14 + -0x80) + *(char *)((ushort)bVar10 + unaff_ER14 + -0x54);
      *(char *)(unaff_ER14 + -0x7e) = *(char *)(unaff_ER14 + -0x7e) + '\x01';
      if ((byte)((ushort)*(undefined2 *)(unaff_ER14 + -0x80) >> 8) <=
          (byte)*(undefined2 *)(unaff_ER14 + -0x80)) break;
    }
  }
  if (((calc_mode == 'K') && (cVar3 = *(char *)(unaff_ER14 + -0x7e), cVar3 != '\0')) &&
     (cVar3 != '\x01')) {
    if (cVar3 == '\x02') {
      if (*(char *)(unaff_ER14 + -0x54) == '\x02') {
        *(undefined *)(unaff_ER14 + -0x7e) = 3;
      }
    }
    else if (cVar3 == '\x03') {
      *(undefined *)(unaff_ER14 + -0x7e) = 4;
      if (*(char *)(unaff_ER14 + -0x53) == '\x02') {
        *(undefined *)(unaff_ER14 + -0x7e) = 5;
      }
      if (*(char *)(unaff_ER14 + -0x52) == '\x02') {
        *(undefined *)(unaff_ER14 + -0x7e) = 6;
      }
    }
    else if (cVar3 == '\x04') {
      *(undefined *)(unaff_ER14 + -0x7e) = 7;
    }
  }
  frame_leave();
  return 0;
}

/**
 * @brief c >= 0xF0（双字节字符首字节）时返回 true
 * @addr 0x0D806
 * @module editor
 * @proto bool is_neg_char(byte c)
 * @confidence verified
 * @note c >= 0xF0（双字节字符首字节）时返回 true。
 * @tag charset
 */
bool is_neg_char(byte c)

{
  return 0xef < c;
}

/**
 * @brief 恒返回 0
 * @addr 0x0D82A
 * @module editor
 * @proto short return_zero_d(void)
 * @confidence verified
 * @note 恒返回 0。
 * @tag util
 */
short return_zero_d(void)

{
  return 0;
}

/**
 * @brief 按方向 d 移动光标（±1）并三次重绘（0x22B82）
 * @addr 0x0D82E
 * @module editor
 * @proto void cursor_move_draw(undefined2 d)
 * @confidence strong
 * @note 按方向 d 移动光标（±1）并三次重绘（0x22B82）。
 * @tag ui
 */
int cursor_move_draw(undefined2 d)

{
  short sVar1;
  char cVar3;
  ushort uVar2;
  short sVar4;
  
  cVar3 = (char)((ushort)d >> 8);
  sVar1 = frame_enter();
  sVar4 = 1;
  if (cVar3 == '\0') {
    sVar1 = sVar1 + 1;
  }
  else {
    sVar1 = sVar1 + -1;
    sVar4 = -1;
  }
  uVar2 = sVar1 + sVar4;
  stat_edit_entry(uVar2);
  stat_edit_entry(uVar2);
  stat_edit_entry(uVar2 + sVar4);
  stat_edit_entry(uVar2 + sVar4 + sVar4);
  frame_leave();
  return 0;
}

/**
 * @brief 统计分母 Σ 计算
 * @addr 0x0D898
 * @module editor
 * @proto void stats_denominator_calc(void)
 * @confidence strong
 * @note 统计分母 Σ 计算：对 0xD7FC/0xD806/0xD810/0xD81A
 *       四组操作数做平方（0x1CF90）与除法（0x1CF68），写入 0xD842.. 的统计槽。
 * @tag app
 */
int stats_denominator_calc(void)

{
  undefined2 *puVar1;
  undefined2 uVar2;
  undefined uVar3;
  short unaff_ER14;
  
  frame_enter();
  *(undefined2 *)(unaff_ER14 + -6) = 0xd7fc;
  *(undefined2 *)(unaff_ER14 + -2) = 0xd806;
  *(undefined2 *)(unaff_ER14 + -8) = 0xd810;
  *(undefined2 *)(unaff_ER14 + -4) = 0xd81a;
  uVar3 = 0xd8;
  uVar2 = 0xd7fc;
  dec_copy((undefined2 *)0xd84c,(undefined2 *)0xd7fc);
  dec_xy_sub((undefined2 *)0xd84c,uVar2);
  dec_copy((undefined2 *)0xd856,*(undefined2 **)(unaff_ER14 + -2));
  puVar1 = *(undefined2 **)(unaff_ER14 + -4);
  dec_copy((undefined2 *)0xd86a,puVar1);
  uVar2 = CONCAT11((char)((ushort)puVar1 >> 8),4);
  dec_set_uint_small((ushort *)0xd860,4);
  dec_inc5((undefined2 *)0xd860,uVar2);
  dec_bin_pow((undefined2 *)0xd856,(undefined2 *)0xd860);
  dec_bin_pow((undefined2 *)0xd86a,(undefined2 *)0xd860);
  dec_set_uint_small((ushort *)0xd842,3);
  dec_bin_pow((undefined2 *)0xd842,(undefined2 *)0xd84c);
  dec_bin_div((undefined2 *)0xd842,(undefined2 *)0xd856);
  dec_bin_div((undefined2 *)0xd84c,(undefined2 *)0xd856);
  dec_bin_pow((undefined2 *)0xd842,(undefined2 *)0xd84c);
  dec_set_from_fmt(0xd860,CONCAT11(uVar3,0x10));
  dec_add_or_round((undefined2 *)0xd842,(undefined2 *)0xd860);
  dec_copy((undefined2 *)0xd860,*(undefined2 **)(unaff_ER14 + -6));
  dec_bin_pow((undefined2 *)0xd860,*(undefined2 **)(unaff_ER14 + -8));
  dec_bin_div((undefined2 *)0xd842,(undefined2 *)0xd860);
  dec_bin_div((undefined2 *)0xd842,(undefined2 *)0xd86a);
  frame_leave();
  return 0;
}

/**
 * @brief 处理输入态按键
 * @addr 0x0D9BC
 * @module editor
 * @proto int kbd_input_handle(void)
 * @confidence likely
 * @note 处理输入态按键：按 0xD114/0xD116 与当前模式（E/J/K/0x0C）决定分支。
 * @tag key
 */
int kbd_input_handle(void)

{
  byte bVar1;
  int cVar2;
  char **ppcVar3;
  short sVar4;
  char *pcVar5;
  
  ppcVar3 = (char **)frame_enter();
  cVar2 = is_up_down((char)input_key,(char)((ushort)input_key >> 8));
  bVar1 = edit_state2;
  if (cVar2 != '\0') {
    if ((key_modifiers & 0x80) == 0) {
      cVar2 = *(char *)(ppcVar3 + 3);
      if ((((cVar2 == -0x78) || (cVar2 == 'E')) || (cVar2 == 'K')) ||
         ((cVar2 == 'J' || (cVar2 == '\f')))) goto LAB_rom_00d9d2;
      cVar2 = is_modifier_3_5();
      if (cVar2 == '\0') {
        if ((**ppcVar3 != '\0') || (bVar1 != 1)) goto LAB_rom_00d9d2;
        strcpy_checked(*ppcVar3,(char *)0xd248);
      }
      else {
        stat_state_reset();
        input_init();
      }
      sVar4 = key_is_14_02();
      if ((char)sVar4 == '\0') {
        history_cursor = strline_len(*ppcVar3);
      }
      else {
        history_cursor = '\0';
      }
    }
    else {
      cVar2 = stat_view_event();
      if ((cVar2 == '\0') && (((bVar1 & 0x80) != 0 || (bVar1 == 6)))) {
        stat_state_reset();
      }
      input_init();
    }
    pcVar5 = (char *)input_history_ptr();
    if (pcVar5 != (char *)0x0) {
      strcpy_checked(pcVar5,*ppcVar3);
      input_saved = history_cursor;
    }
    input_active = 0;
    key_flag_bit7();
  }
LAB_rom_00d9d2:
  frame_leave();
  return 0;
}

