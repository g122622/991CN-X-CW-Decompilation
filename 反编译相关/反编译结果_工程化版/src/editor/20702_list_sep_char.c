/*
 * 输入编辑器 / 20702_list_sep_char.c
 * 地址范围: 0x20702 - 0x20E7A
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 返回列表分隔符
 * @addr 0x20702
 * @module editor
 * @proto byte list_sep_char(void)
 * @confidence strong
 * @note 返回列表分隔符：0xD11C == 0 时为 0x2C（,），否则 0x2E（.）。
 * @tag editor
 */
byte list_sep_char(void)

{
  undefined uVar1;
  
  if (menu_toggle == '\0') {
    uVar1 = 0x2c;
  }
  else {
    uVar1 = 0x2e;
  }
  return uVar1;
}

/**
 * @brief p+0x12 处的偏移为负时把 p+0x14 的计数钳位（编辑缓存的越界修正）
 * @addr 0x209CA
 * @module editor
 * @proto void edit_clamp_offset(byte* p)
 * @confidence likely
 * @note p+0x12 处的偏移为负时把 p+0x14 的计数钳位（编辑缓存的越界修正）。
 * @tag editor
 */
int edit_clamp_offset(byte* p)

{
  byte bVar1;
  byte bVar2;
  
  bVar2 = *(byte *)(p + 0x14);
  if ((*(short *)(p + 0x12) < 0) &&
     (bVar1 = (bVar2 + (char)*(short *)(p + 0x12)) - 1, bVar1 < bVar2)) {
    bVar2 = bVar1;
  }
  *(byte *)(p + 0x14) = bVar2;
  return 0;
}

/**
 * @brief 编辑位置规范化
 * @addr 0x20A58
 * @module editor
 * @proto undefined2 edit_normalize_pos(undefined2 v)
 * @confidence likely
 * @note 编辑位置规范化：参数高低字节不同时逐位调整。
 * @tag editor
 */
undefined2 edit_normalize_pos(undefined2 v)

{
  undefined2 uVar1;
  char cVar2;
  byte bVar3;
  byte bVar4;
  
  bVar4 = (byte)((ushort)v >> 8);
  if ((char)v == -0x10) {
    v = CONCAT11(bVar4,bVar4);
  }
  bVar3 = (byte)v;
  uVar1 = CONCAT11(bVar4,bVar3);
  if (bVar4 != bVar3) {
    bVar4 = (byte)((ushort)v >> 8);
    uVar1 = v;
    if (bVar3 < bVar4) {
      uVar1 = CONCAT11(bVar3,bVar4);
    }
    if (((char)uVar1 == '\r') && (cVar2 = (char)((ushort)uVar1 >> 8), cVar2 != '\n')) {
      uVar1 = CONCAT11(cVar2,cVar2);
    }
  }
  return uVar1;
}

/**
 * @brief 回显输入区
 * @addr 0x20C20
 * @module editor
 * @proto void echo_input(void)
 * @confidence strong
 * @note 回显输入区：清屏后把 0x9D52（输入区字符串）绘制到屏幕。
 * @tag editor
 */
int echo_input(void)

{
  char acStack_2a [38];
  
  clear_screen();
  input_read_str(acStack_2a);
  draw_text4x(0x100,acStack_2a);
  return 0;
}

/**
 * @brief 绘制编辑器行
 * @addr 0x20C64
 * @module editor
 * @proto void render_editor_line(byte mode)
 * @confidence strong
 * @note 绘制编辑器行：按模式调用 0x23780 生成内容，清 0x40-当前行 的剩余行，再绘制。
 * @tag editor
 */
int render_editor_line(byte mode)

{
  byte bVar1;
  int cVar2;
  undefined2 auStack_20 [14];
  
  if (mode == 0) {
    cVar2 = '\0';
    auStack_20[0]._0_1_ = 0;
  }
  else {
    mixed_fraction = 0;
    cVar2 = edit_render_content(auStack_20);
  }
  key_hist_set_hi(cVar2);
  bVar1 = 0x40 - cur_line;
  fb_clear_rows(bVar1);
  cVar2 = draw_result_line();
  draw_text4x(CONCAT11(bVar1,-0x40 - cVar2),auStack_20);
  return 0;
}

/**
 * @brief 重绘行并做语法高亮（0x28576/0x1F10E/0xAF74 链）
 * @addr 0x20DF4
 * @module editor
 * @proto void redraw_line_syntax(void)
 * @confidence likely
 * @note 重绘行并做语法高亮（0x28576/0x1F10E/0xAF74 链）。
 * @tag editor
 */
int redraw_line_syntax(void)

{
  char cVar1;
  char cVar2;
  byte bVar3;
  undefined2 uVar4;
  ushort uVar5;
  
  cVar1 = is_math_io();
  if (cVar1 != '\0') {
    uVar4 = token_class((char *)CONCAT11((0x7f < history_cursor) + -0x2f,history_cursor + 0x80));
    cVar2 = is_digit_key((byte)uVar4);
    if (cVar2 != '\0') {
      key_flag_clear_b7();
    }
  }
  uVar5 = CONCAT11(status_bits,cVar1) & 0x80ff;
  cVar1 = strline_len(&input_buf);
  bVar3 = input_max_len();
  cVar2 = (char)(uVar5 >> 8);
  if ((byte)(cVar1 + 0xbU) < bVar3) {
    if (cVar2 == '\0') {
      input_disp_mode = 0x7c;
    }
    else {
      input_disp_mode = 0xcf;
    }
  }
  else {
    input_disp_mode = 0xcc;
  }
  if (((char)uVar5 != '\0') && (cVar2 != '\0')) {
    input_disp_mode = 0x9e;
  }
  return 0;
}

/**
 * @brief 按模式返回历史记录/输入区指针（0xD784 或 0xD180 等）
 * @addr 0x20E5A
 * @module editor
 * @proto void input_history_ptr(void)
 * @confidence strong
 * @note 按模式返回历史记录/输入区指针（0xD784 或 0xD180 等）。
 * @tag editor
 */
int input_history_ptr(void)

{
  if (calc_mode != 0x88) {
    if ((calc_mode & 0x80) != 0) {
      return 0xd522;
    }
    if ((calc_mode & 0x40) == 0) {
      return 0;
    }
  }
  return 0xd784;
}

/**
 * @brief 按模式返回历史/输入区基址
 * @addr 0x20E7A
 * @module editor
 * @proto undefined* history_base_ptr(void)
 * @confidence strong
 * @note 按模式返回历史/输入区基址：0xD111 == 0x0C 时为 0xD784，否则按 0xD111 < 4 选择。
 * @tag editor
 */
undefined* history_base_ptr(void)

{
  undefined *puVar1;
  
  if (calc_mode == 0xc) {
    puVar1 = (undefined *)0xd784;
  }
  else if ((calc_mode == 0x4a) || (calc_mode == 0x45)) {
    puVar1 = &app_work_area;
  }
  else {
    puVar1 = &stat_data;
    if ((calc_mode != 0x89) && (((calc_mode & 0xf) == 3 || (5 < (calc_mode & 0xf))))) {
      puVar1 = (undefined *)0x0;
    }
  }
  return puVar1;
}

