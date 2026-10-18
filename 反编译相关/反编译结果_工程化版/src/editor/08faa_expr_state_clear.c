/*
 * 输入编辑器 / 08faa_expr_state_clear.c
 * 地址范围: 0x08FAA - 0x0975A
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 清零 0xD16C 的 20 字节表达式状态
 * @addr 0x08FAA
 * @module editor
 * @proto void expr_state_clear(void)
 * @confidence verified
 * @note 清零 0xD16C 的 20 字节表达式状态。
 * @tag editor
 */
int expr_state_clear(int _a1, int _a2)

{
  memzero((undefined *)0xd16c,0x14);
  return 0;
}



// 内存清零函数 (memzero)
// 地址: 0x8FB8
// _a1: 目标地址
// _a2: 清零长度

/**
 * @brief 把 0xDBD0 起的 16 字节填为 0x0F..0x00
 * @addr 0x090C0
 * @module editor
 * @proto void cursor_stack_fill(void)
 * @confidence verified
 * @note 把 0xDBD0 起的 16 字节填为 0x0F..0x00。
 * @tag editor
 */
int cursor_stack_fill(void)

{
  char cVar1;
  char *pcVar2;
  
  pcVar2 = &diag_status;
  cVar1 = '\x0f';
  do {
    *pcVar2 = cVar1;
    pcVar2 = pcVar2 + 1;
    cVar1 = cVar1 + -1;
  } while (cVar1 != '\0');
  return 0;
}

/**
 * @brief c == 0 时输出 "x<"（0x1DA4 段），否则 ROM 0x1D7C 记号
 * @addr 0x09462
 * @module editor
 * @proto undefined2 emit_xlt_by_mode(undefined2 p, byte c)
 * @confidence likely
 * @note c == 0 时输出 "x<"（0x1DA4 段），否则 ROM 0x1D7C 记号。
 * @tag text
 */
undefined2 emit_xlt_by_mode(undefined2 p, byte c)

{
  if (c == '\0') {
    str_emit_xlt(p);
  }
  else {
    str_emit_1D7C(p);
  }
  return p;
}

/**
 * @brief 统计变量运算
 * @addr 0x0947C
 * @module editor
 * @proto void stats_x2_minus_y2_div(void)
 * @confidence strong
 * @note 统计变量运算：t = x*x（0x1881C），u = y*y（0x18858），返回 t/u（0x1CF68
 *       除法）。用于标准差的 x²、y²、xy 累积。
 * @tag app
 */
int stats_x2_minus_y2_div(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined uVar3;
  
  frame_enter();
  uVar3 = 0xd6;
  uVar2 = 0xd6e4;
  uVar1 = 0xd6da;
  dec_copy((undefined2 *)0xd6ee,(undefined2 *)0xd6da);
  dec_xy_add((undefined2 *)0xd6ee,uVar1);
  dec_set_from_fmt(0xd6f8,CONCAT11((char)((ushort)uVar1 >> 8),4));
  dec_bin_pow((undefined2 *)0xd6ee,(undefined2 *)0xd6f8);
  dec_copy((undefined2 *)0xd6f8,(undefined2 *)0xd6e4);
  dec_xy_sub((undefined2 *)0xd6f8,uVar2);
  dec_bin_div((undefined2 *)0xd6ee,(undefined2 *)0xd6f8);
  dec_set_from_fmt(0xd6f8,CONCAT11(uVar3,0x1b));
  dec_add_or_round((undefined2 *)0xd6ee,(undefined2 *)0xd6f8);
  frame_leave();
  return 0;
}



// 延迟函数 (editor_action)
// 地址: 0x916A

/**
 * @brief 编辑器动作（撤销/重做/删除等）分派
 * @addr 0x094DA
 * @module editor
 * @proto void editor_action(ushort op)
 * @confidence strong
 * @note 编辑器动作（撤销/重做/删除等）分派：按 0xD015 状态和 op 修改输入区并重绘。原记录命名为
 *       delay，实际没有任何延时循环。
 * @tag editor
 */
int editor_action(ushort op)

{
  byte bVar1;
  undefined uVar2;
  char cVar3;
  ushort uVar4;
  char cVar5;
  short unaff_ER14;
  
  cVar5 = (char)((ushort)op >> 8);
  uVar4 = frame_enter();
  if (edit_state == '\x01') {
    bVar1 = editor_max_cols();
    if (bVar1 < *(byte *)(unaff_ER14 + 0x12)) {
      line_col_count();
      cursor_column_calc((char *)(unaff_ER14 + -3));
      *(char *)(unaff_ER14 + -4) = *(char *)(unaff_ER14 + -4) + '\x04';
      if (cur_line < 0xe) {
        cVar3 = *(char *)(unaff_ER14 + -3) + -3;
      }
      else {
        cVar3 = *(char *)(unaff_ER14 + -3) + -4;
      }
      *(char *)(unaff_ER14 + -3) = cVar3;
      cursor_step_repaint(CONCAT11(cVar3,*(undefined *)(unaff_ER14 + -4)));
      cursor_move_draw(CONCAT11(cVar5,*(undefined *)(unaff_ER14 + -4)));
      cursor_move_draw(CONCAT11(cVar5,*(undefined *)(unaff_ER14 + -3)));
    }
    else {
      if (cVar5 == '\0') {
        uVar2 = 0x28;
      }
      else {
        uVar2 = 0x29;
      }
      *(undefined *)(unaff_ER14 + -2) = uVar2;
      *(undefined *)(unaff_ER14 + -1) = 0;
      edit_line_commit(uVar4);
    }
  }
  frame_leave();
  return 0;
}



// 智能字符串连接 (emit_ltx_by_mode)
// 地址: 0x203D6

/**
 * @brief c == 0 时输出 " and "，否则 ROM 0x1D9E 记号
 * @addr 0x0959C
 * @module editor
 * @proto undefined2 emit_ltx_by_mode(undefined2 p, byte c)
 * @confidence likely
 * @note c == 0 时输出 " and "，否则 ROM 0x1D9E 记号。
 * @tag text
 */
undefined2 emit_ltx_by_mode(undefined2 p, byte c)

{
  if (c == '\0') {
    str_emit_and(p);
  }
  else {
    str_emit_1D9E(p);
  }
  return p;
}

/**
 * @brief 按栈帧里的列偏移计算 *out 与光标列（0x15+0x10−0x14−3）
 * @addr 0x095B6
 * @module editor
 * @proto void cursor_column_calc(char* out)
 * @confidence likely
 * @note 按栈帧里的列偏移计算 *out 与光标列（0x15+0x10−0x14−3）。
 * @tag editor
 */
int cursor_column_calc(char* out)

{
  char cVar1;
  char *pcVar2;
  short unaff_ER14;
  
  pcVar2 = (char *)frame_enter();
  cVar1 = *(char *)(unaff_ER14 + 0x15) + *(char *)(unaff_ER14 + 0x10);
  *out = cVar1;
  *pcVar2 = cVar1 - *(char *)(unaff_ER14 + 0x14);
  *out = *out + -3;
  frame_leave();
  return 0;
}

/**
 * @brief 按模式（0x0C=统计、0x88=表格、其它）绘制表头
 * @addr 0x095D6
 * @module editor
 * @proto void stats_headers_draw(void)
 * @confidence strong
 * @note 按模式（0x0C=统计、0x88=表格、其它）绘制表头：0x5B14/0x7E14/0x5D0C 等固定文本串与
 *       0x0A60 区标题。
 * @tag app
 */
int stats_headers_draw(void)

{
  byte bVar1;
  int cVar2;
  undefined2 uVar3;
  char cVar4;
  short unaff_ER14;
  
  frame_enter();
  cVar4 = '\x19';
  cur_line = 8;
  if (calc_mode == '\f') {
    if (sub_mode < 6) {
      draw_format_string(0x219,"  \x04\x01");
    }
    else {
      draw_format_string(0x219,(char *)0x4b1c);
    }
    draw_text4x(0x242,0x2c4);
  }
  else if (calc_mode == -0x78) {
    draw_text4x(0x219,0x5b14);
    draw_text4x(0x240,0x7e14);
    if ((history_recall == '\x01') && ((ratio_flags & 0x80) == 0)) {
      draw_text4x(0x26b,0x7e1a);
    }
  }
  else {
    draw_text4x(0x219,0x5d0c);
    if (sub_mode != 1) {
      cVar4 = 'C';
      draw_text4x(0x243,0x5d10);
    }
    if (var_list_open != '\0') {
      input_read_str((char *)(unaff_ER14 + -0x24));
      bVar1 = strlen_checked((char *)(unaff_ER14 + -0x24));
      uVar3 = mul16((ushort)bVar1,6);
      cVar2 = draw_spaced(CONCAT11(-(0x29 < (byte)uVar3) - (char)((ushort)uVar3 >> 8), (uintptr_t)0)
                                      ')' - (byte)uVar3),2);
      draw_text4x(CONCAT11(2,cVar4 + cVar2 + '%'),unaff_ER14 + -0x24);
    }
  }
  frame_leave();
  return 0;
}



// 等待按键 (key_pos_offset)
// 地址: 0x221C4

/**
 * @brief 把光标三元组复位
 * @addr 0x096E8
 * @module editor
 * @proto void cursor_home(void)
 * @confidence strong
 * @note 把光标三元组复位：0xD134=0xD135=0xD136=1，0xD16A=1（列表回到位置 1,1）。
 * @tag ui
 */
int cursor_home(void)

{
  list_page = 1;
  list_col = 1;
  list_row = 1;
  _DAT_ram_d16a = 1;
  return 0;
}



// 读取按键 (input_is_empty)
// 地址: 0xF746

/**
 * @brief 若输入区 0xD180 为空（strlen==0）或 0xD116 bit6 置位则返回 t…
 * @addr 0x096FC
 * @module editor
 * @proto bool input_is_empty(void)
 * @confidence verified
 * @note 若输入区 0xD180 为空（strlen==0）或 0xD116 bit6 置位则返回 true，否则
 *       false。原记录命名为 read_key，实际并不读键盘。
 * @tag editor
 */
bool input_is_empty(void)

{
  byte bVar1;
  short sVar2;
  
  bVar1 = key_modifiers & 0x40;
  sVar2 = strlen_checked(&input_buf);
  return sVar2 == 0 || bVar1 != 0;
}

/**
 * @brief 跳过输入缓冲区中的一行（按双字节字符前进），调用 0x23A0C 取列数
 * @addr 0x0971E
 * @module editor
 * @proto int skip_input_line(void)
 * @confidence strong
 * @note 跳过输入缓冲区中的一行（按双字节字符前进），调用 0x23A0C 取列数。
 * @tag editor
 */
int skip_input_line(void)

{
  bool bVar1;
  byte *pbVar2;
  undefined extraout_R1;
  
  pbVar2 = (byte *)frame_enter();
  line_col_count();
  for (; *pbVar2 != 0; pbVar2 = pbVar2 + 1) {
    bVar1 = is_neg_char(*pbVar2);
    if (CONCAT11(extraout_R1,bVar1) != 0) {
      pbVar2 = pbVar2 + 1;
    }
  }
  frame_leave();
  return 0;
}

/**
 * @brief 统计表单元格编辑循环（0xD114=1、0xD154=1，0x2AC7C 重绘，读键刷新）
 * @addr 0x0975A
 * @module editor
 * @proto void table_cell_edit(void)
 * @confidence strong
 * @note 统计表单元格编辑循环（0xD114=1、0xD154=1，0x2AC7C 重绘，读键刷新）。
 * @tag app
 */
int table_cell_edit(uintptr_t _a2, int _a1)

{
  char cVar1;
  char cVar2;
  ushort uVar4;
  undefined2 uVar5;
  byte bVar6;
  byte bVar3;
  
  frame_enter();
  cVar1 = stat_state;
  edit_state2 = 1;
  if (stat_state != '\x03') {
    menu_index = 1;
    row_refresh();
  }
  key_dispatch_menu();
  do {
    while( true ) {
      key_modifiers = 3;
      if (cVar1 == '\x03') {
        echo_input_row();
      }
      else {
        cVar2 = editor_accept_ready();
        if (cVar2 == '\0') {
          key_modifiers = key_modifiers | 0x20;
          clear_screen();
          cur_line = 0xe;
          stat_main_loop();
          table_cell_key2(_a1);
        }
        else {
          table_mode_main();
        }
      }
      while( true ) {
        do {
          fb_flush();
          uVar4 = process_key(_a1);
          set_input_key(uVar4);
          if ((byte)input_key == 0x25 &&
              (bool)((char)((ushort)input_key >> 8) + '\x04') == (byte)input_key < 0x25) {
            key_dispatch_menu();
          }
          uVar5 = key_is_extended(uVar4);
        } while ((char)uVar5 != '\0');
        uVar5 = keycode_norm(uVar4);
        if (((char)uVar5 == '\0') || (calc_mode != 'E')) break;
        menu_scroll();
      }
      uVar5 = key_is_menu_key(uVar4);
      if ((char)uVar5 == '\0') break;
LAB_rom_009814:
      edit_ctx_check();
    }
    bVar3 = (byte)uVar4;
    bVar6 = (byte)(uVar4 >> 8);
    cVar2 = is_up_down(bVar3,bVar6);
    if (cVar2 != '\0') goto LAB_rom_009814;
    uVar4 = (bVar6 - 0xfc) - (ushort)(bVar3 < 0x30);
    if (((uVar4 & 0x100) != 0 || bVar3 == 0x30 && (char)uVar4 == '\0') &&
       (((bVar6 - 0xfc) - (ushort)(bVar3 < 0x1c) & 0x100) == 0)) {
                    // WARNING: Could not recover jumptable at 0x009870. Too many branches
                    // WARNING: Treating indirect jump as call
      ((void)0);
      return 0;
    }
  } while( true );
}

