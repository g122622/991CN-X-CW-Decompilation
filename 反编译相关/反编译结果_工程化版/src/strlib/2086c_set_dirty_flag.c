/*
 * 字符串与格式化 / 2086c_set_dirty_flag.c
 * 地址范围: 0x2086C - 0x20FAA
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 写显示脏/状态标志
 * @addr 0x2086C
 * @module strlib
 * @proto void set_dirty_flag(undefined2 v)
 * @confidence likely
 * @note 写显示脏/状态标志。
 * @tag ui
 */
int set_dirty_flag(undefined2 v)

{
  cur_line = 0xe;
  var_table0_clear(CONCAT11((char)((ushort)v >> 8),0xe));
  draw_text4x(0x100,(byte)((sub_mode & 0xfc) + (sub_mode >> 2) * '\x02') + 0x1cde);
  cur_line = prev_line;
  return 0;
}

/**
 * @brief 解析以 "1" 开头的数字串（0x208A6，0x256E0/0x29E38/0x2B4FC…
 * @addr 0x208A6
 * @module strlib
 * @proto char* parse_number_str(char* s)
 * @confidence likely
 * @note 解析以 "1" 开头的数字串（0x208A6，0x256E0/0x29E38/0x2B4FC 使用）。
 * @tag parser
 */
char* parse_number_str(char* s, int _a2)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  
  cVar1 = *s;
  pcVar3 = s + 1;
  if (cVar1 != '1') goto LAB_rom_0208b6;
  pcVar2 = s + 2;
  if (s[1] == '\0') {
    *s = _a2;
    return;
  }
  do {
    while( true ) {
      cVar1 = *pcVar2;
      pcVar2 = pcVar2 + 1;
      pcVar3 = pcVar2;
      if (cVar1 == '\0') goto LAB_rom_0208e6;
LAB_rom_0208b6:
      if (cVar1 != '`') break;
      cVar1 = *pcVar3;
      pcVar2 = pcVar3 + 1;
      if (cVar1 == '1') {
        pcVar2 = pcVar3 + 2;
        if (pcVar3[1] == '\0') {
          s[1] = _a2;
          return;
        }
      }
      else {
LAB_rom_0208de:
        if (cVar1 == '\0') {
LAB_rom_0208e6:
          *pcVar2 = cVar1;
          pcVar2[-1] = _a2;
          return;
        }
      }
    }
    pcVar2 = pcVar3;
    if (cVar1 != -0x40) goto LAB_rom_0208de;
    cVar1 = *pcVar3;
    pcVar2 = pcVar3 + 1;
    if (cVar1 != '1') goto LAB_rom_0208de;
    cVar1 = *pcVar2;
    pcVar2 = pcVar3 + 2;
    if (cVar1 == '\0') {
      s[1] = _a2;
      return;
    }
  } while( true );
}

/**
 * @brief 清空文本面板区域
 * @addr 0x208F2
 * @module strlib
 * @proto int text_clear_panel(void)
 * @confidence likely
 * @note 清空文本面板区域。
 * @tag text
 */
int text_clear_panel(uintptr_t _a3, uintptr_t _a4, int _a1, int _a2)

{
  byte bVar1;
  byte bVar2;
  char cVar3;
  short sVar4;
  byte *pbVar5;
  short sVar6;
  ushort uVar7;
  char cVar8;
  byte *pbVar9;
  
  cVar8 = '\0';
  if ((char)_a1 != '\0') {
    cVar3 = (char)((uint32_t)_a1 >> 8);
    if (cVar3 == -5) {
      sVar4 = 0x1dc4;
      sVar6 = 0x1e64;
    }
    else if (cVar3 == -3) {
      sVar4 = 0x1eb4;
      sVar6 = 0x1f74;
    }
    else if (cVar3 == -2) {
      sVar4 = 0x1fd4;
      sVar6 = 0x21b2;
    }
    else if (cVar3 == -6) {
      sVar4 = 0x22a2;
      sVar6 = 0x2324;
    }
    else {
      if (cVar3 != '\0') goto LAB_rom_020984;
      sVar4 = 0x2374;
      sVar6 = 0x2554;
    }
    pbVar5 = *(byte **)(sVar4 + (_a1 & 0xff) * 2);
    bVar1 = *(byte *)(sVar6 + (_a1 & 0xff));
    bVar2 = bVar1 & 0xf;
    if (bVar2 != 0) {
      bVar1 = bVar1 >> 4;
      uVar7 = (ushort)bVar1;
      if (bVar1 != 0xf) {
        uVar7 = (ushort)bVar1;
        pbVar5 = pbVar5 + uVar7;
      }
      do {
        pbVar9 = _a2;
        cVar8 = cVar8 + '\x01';
        _a2 = pbVar9;
        if (cVar8 == '!') goto LAB_rom_020984;
        cVar3 = (char)uVar7;
        bVar1 = *pbVar5;
        uVar7 = CONCAT11(bVar1,cVar3);
        nop();
        *pbVar9 = bVar1;
        _a2 = pbVar9 + 1;
        pbVar5 = pbVar5 + 1;
      } while (((bVar1 == 4) || (0xef < bVar1)) || (bVar2 = bVar2 - 1, bVar2 != 0));
      if (cVar3 == '\x0f') {
        *_a2 = 0x28;
        _a2 = pbVar9 + 2;
      }
    }
  }
LAB_rom_020984:
  *_a2 = 0;
  return 0;
}

/**
 * @brief 绘制单元格值（按 +0x12/+0x14 数据）
 * @addr 0x209EE
 * @module strlib
 * @proto void draw_cell_value(byte* p)
 * @confidence likely
 * @note 绘制单元格值（按 +0x12/+0x14 数据）。
 * @tag app
 */
int draw_cell_value(byte* p)

{
  ushort uVar1;
  char cVar2;
  ushort uVar3;
  byte bVar4;
  
  bVar4 = *(byte *)(p + 0x14);
  uVar3 = *(ushort *)(p + 0x12);
  cVar2 = (char)uVar3;
  if ((short)uVar3 < 0) {
    bVar4 = bVar4 + ('\x01' - cVar2);
    if ((byte)(cVar2 + 10U) < bVar4) {
      bVar4 = cVar2 + 10U;
    }
    *(undefined *)(p + 0x15) = 1;
  }
  else {
    uVar1 = (ushort)bVar4;
    if ((byte)(SBORROW2(uVar1,uVar3) ^ (short)(uVar1 - uVar3) < 0 | uVar1 == uVar3) == 1) {
      bVar4 = cVar2 + 1;
    }
    else {
      *(undefined *)(p + 0x15) = 1;
    }
  }
  if (0xb < bVar4) {
    bVar4 = 0xb;
  }
  *(byte *)(p + 0x14) = bVar4;
  return 0;
}

/**
 * @brief 按 BCD 类型字节（0x1D800）输出对应的特殊值字符串
 * @addr 0x20A38
 * @module strlib
 * @proto void dec_type_to_str(undefined2* p, char* out)
 * @confidence likely
 * @note 按 BCD 类型字节（0x1D800）输出对应的特殊值字符串。
 * @tag format
 */
int dec_type_to_str(undefined2* p, char* out)

{
  byte bVar1;
  
  *out = '\0';
  bVar1 = bcd_type(p);
  if (bVar1 != 0xd) {
    strcpy_checked(out,"ERROR");
  }
  return 0;
}

/**
 * @brief 行号推进
 * @addr 0x20A80
 * @module strlib
 * @proto char line_wrap(byte n)
 * @confidence strong
 * @note 行号推进：把 (n + 0xD140) 与 0x3F 比较，溢出时换行并清 0xD140，返回溢出量。
 * @tag text
 */
char line_wrap(byte n)

{
  char cVar1;
  char cStack_6;
  
  cVar1 = key_hist_c;
  if (key_hist_c == '\0') {
    cVar1 = '\x0e';
  }
  cStack_6 = '\0';
  if (0x3f < (byte)(n + cVar1)) {
    cStack_6 = (n + cVar1) - 0x3f;
    scroll_screen(cStack_6);
  }
  key_hist_c = 0;
  return cStack_6;
}

/**
 * @brief 矩阵编辑钩子（1.9KB，0xD117 bit4 判断）
 * @addr 0x20AA8
 * @module strlib
 * @proto int matrix_edit_hook(void)
 * @confidence likely
 * @note 矩阵编辑钩子（1.9KB，0xD117 bit4 判断）。
 * @tag matrix
 */
int matrix_edit_hook(uintptr_t _a3, uintptr_t _a4, int _a1, int _a2)

{
  char cVar1;
  byte bVar2;
  undefined uVar3;
  undefined *puVar4;
  
  cVar1 = disp_mode;
  puVar4 = _a2;
  if ((key_history_flags & 0x10) == 0) goto LAB_rom_020b4e;
  if (key_history_flags == 0x11) {
    if (_a1 == '\0') {
      if (disp_mode == '\0') {
        uVar3 = 0x10;
      }
      else {
        uVar3 = 0x48;
      }
    }
    else if (disp_mode == '\0') {
      uVar3 = 0x11;
    }
    else {
      uVar3 = 0x49;
    }
LAB_rom_020ade:
    *_a2 = uVar3;
    bVar2 = 1;
  }
  else {
    if (key_history_flags != 0x12) {
      if (key_history_flags == 0x13) {
        if (_a1 != '\0') {
          *_a2 = 0x4c;
          _a2[1] = 0x2d;
          _a2[2] = 0x52;
          bVar2 = 3;
          goto LAB_rom_020b3a;
        }
        uVar3 = *(undefined *)((byte)(calc_buf_len - 0x40) + 0x7da0);
      }
      else if (key_history_flags == 0x14) {
        if (_a1 == '\0') goto LAB_rom_020b4e;
        if (disp_mode != '\0') {
          *_a2 = 0xfb;
          uVar3 = 0x41;
          goto LAB_rom_020afa;
        }
        uVar3 = 0x52;
      }
      else {
        if (_a1 != '\0') goto LAB_rom_020b4e;
        if (disp_mode == '\0') {
          uVar3 = 0x46;
        }
        else {
          uVar3 = 0x47;
        }
      }
      goto LAB_rom_020ade;
    }
    if (_a1 != '\0') {
      if (disp_mode != '\0') {
        *_a2 = 0xfb;
        uVar3 = 0x42;
        goto LAB_rom_020afa;
      }
      uVar3 = 0xc4;
      goto LAB_rom_020ade;
    }
    if (disp_mode == '\0') {
      uVar3 = 0x72;
      goto LAB_rom_020ade;
    }
    *_a2 = 0xfd;
    uVar3 = 0x13;
LAB_rom_020afa:
    _a2[1] = uVar3;
    bVar2 = 2;
  }
LAB_rom_020b3a:
  if (cVar1 == '\0') {
    uVar3 = 0x3d;
  }
  else {
    uVar3 = 0xa5;
  }
  _a2[bVar2] = uVar3;
  puVar4 = _a2 + bVar2 + 1;
LAB_rom_020b4e:
  *puVar4 = 0;
  return _a2;
}

/**
 * @brief 表格单元按键（0xD111==E/0xD112==4 时 0x284EC）
 * @addr 0x20B94
 * @module strlib
 * @proto void table_cell_key2(undefined2 k)
 * @confidence likely
 * @note 表格单元按键（0xD111==E/0xD112==4 时 0x284EC）。
 * @tag app
 */
int table_cell_key2(undefined2 k)

{
  char cVar1;
  ushort uVar2;
  short sVar3;
  byte bVar4;
  char acStack_c [8];
  
  if ((calc_mode == 'E') && (sub_mode == 4)) {
    list_cursor_move(k);
    return 0;
  }
  bVar4 = menu_index - 1;
  uVar2 = (ushort)bVar4;
  if (calc_mode == 'J') {
    sVar3 = 0x1cfc;
  }
  else {
    if (3 < sub_mode) {
      draw_list_header();
      cVar1 = table_row_count();
      if (cVar1 != '\x01') {
        uVar2 = CONCAT11((char)((uVar2 << 2) >> 8),bVar4 * '\x04');
        sVar3 = 0x1d0b;
        goto LAB_rom_020bf8;
      }
    }
    uVar2 = uVar2 * 3;
    sVar3 = 0x1cff;
  }
LAB_rom_020bf8:
  strcpy_checked(acStack_c,(char *)(sVar3 + uVar2));
  bVar4 = 1;
  if (3 < sub_mode) {
    bVar4 = 0xf;
  }
  draw_text4x((ushort)bVar4 << 8,acStack_c);
  return 0;
}

/**
 * @brief STAT 模式视图按键事件（0xD114==6 时按 0xD115 分派）
 * @addr 0x20D10
 * @module strlib
 * @proto int stat_view_event(void)
 * @confidence likely
 * @note STAT 模式视图按键事件（0xD114==6 时按 0xD115 分派）。
 * @tag stat
 */
int stat_view_event(void)

{
  if (edit_state2 == 6) {
    if (((char)((stat_state == 0) << 7) < '\0') || (3 < stat_state)) {
      return 0;
    }
  }
  else {
    if ((edit_state2 & 0x80) == 0) {
      return 0;
    }
    if (stat_state != 2) {
      return 0;
    }
  }
  return 1;
}

/**
 * @brief 返回 (0xD114 & 0x80) != 0 && 0xD115 == 2
 * @addr 0x20D2A
 * @module strlib
 * @proto char is_stat_edit4(void)
 * @confidence likely
 * @note 返回 (0xD114 & 0x80) != 0 && 0xD115 == 2：STAT 编辑状态判断。
 * @tag stat
 */
char is_stat_edit4(void)

{
  undefined uVar1;
  
  if (((edit_state2 & 0x80) == 0) || (stat_state != '\x02')) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}

/**
 * @brief 在 (col, 0xD156) 处绘制光标字段，0xD13E==0 时用 0x19 标记否则…
 * @addr 0x20D48
 * @module strlib
 * @proto void draw_cursor_field(byte col)
 * @confidence strong
 * @note 在 (col, 0xD156) 处绘制光标字段，0xD13E==0 时用 0x19 标记否则 0x9F。
 * @tag ui
 */
int draw_cursor_field(byte col)

{
  undefined uStack_8;
  undefined uStack_7;
  
  uStack_8 = 0x9f;
  if (history_dirty == '\0') {
    uStack_8 = 0x19;
  }
  uStack_7 = 0;
  draw_text4x(CONCAT11(col,history_key),&uStack_8);
  return 0;
}

/**
 * @brief 按当前列数（0x23A0C）在行尾绘制占位
 * @addr 0x20D76
 * @module strlib
 * @proto void draw_line_end(void)
 * @confidence likely
 * @note 按当前列数（0x23A0C）在行尾绘制占位。
 * @tag ui
 */
int draw_line_end(uintptr_t _a2, int _a1)

{
  char cVar1;
  undefined uStack_8;
  undefined uStack_7;
  
  cVar1 = line_col_count();
  uStack_8 = 0x9e;
  if (history_dirty == '\0') {
    uStack_8 = 0xbf;
  }
  uStack_7 = 0;
  draw_text4x(CONCAT11(_a1,-0x40 - cVar1),&uStack_8);
  return 0;
}

/**
 * @brief 在 0x15E 处绘制下箭头记号
 * @addr 0x20D9E
 * @module strlib
 * @proto void draw_arrow_down(void)
 * @confidence strong
 * @note 在 0x15E 处绘制下箭头记号。
 * @tag ui
 */
int draw_arrow_down(void)

{
  undefined uStack_8;
  undefined uStack_7;
  
  uStack_8 = 0x14;
  uStack_7 = 0;
  draw_text4x(0x15e,&uStack_8);
  return 0;
}

/**
 * @brief 在 0x395E 处绘制上箭头记号
 * @addr 0x20DB0
 * @module strlib
 * @proto void draw_arrow_up(void)
 * @confidence strong
 * @note 在 0x395E 处绘制上箭头记号。
 * @tag ui
 */
int draw_arrow_up(void)

{
  undefined uStack_8;
  undefined uStack_7;
  
  uStack_8 = 0x15;
  uStack_7 = 0;
  draw_text4x(0x395e,&uStack_8);
  return 0;
}

/**
 * @brief 按 0xD126/0xD152 在 (n, 0x1D/0x21) 处绘制状态单元格
 * @addr 0x20DC2
 * @module strlib
 * @proto void draw_status_cell(byte n)
 * @confidence likely
 * @note 按 0xD126/0xD152 在 (n, 0x1D/0x21) 处绘制状态单元格。
 * @tag ui
 */
int draw_status_cell(byte n)

{
  undefined uVar1;
  
  if ((history_recall == '\0') || ((ratio_flags & 1) == 0)) {
    uVar1 = 0x1b;
  }
  else {
    uVar1 = 0x21;
  }
  draw_text4x((ushort)n << 8,CONCAT11(0x1d,uVar1));
  return 0;
}

/**
 * @brief 追加记号字符 0x1A（换行/分隔符）
 * @addr 0x20EB4
 * @module strlib
 * @proto void str_emit_1A(void)
 * @confidence likely
 * @note 追加记号字符 0x1A（换行/分隔符）。
 * @tag text
 */
int str_emit_1A(uintptr_t _a2, uintptr_t _a3, int _a1)

{
  strcat_checked(_a1,"\x1a");
  return 0;
}

/**
 * @brief 追加记号字符 0x1B
 * @addr 0x20EBC
 * @module strlib
 * @proto void str_emit_1B(void)
 * @confidence likely
 * @note 追加记号字符 0x1B。
 * @tag text
 */
int str_emit_1B(void)

{
  char *in_ER0;
  
  strcat_checked(in_ER0,"\x1b");
  return 0;
}

/**
 * @brief 追加记号序列 0x1B 0x1A
 * @addr 0x20EC2
 * @module strlib
 * @proto void str_emit_1B1A(void)
 * @confidence likely
 * @note 追加记号序列 0x1B 0x1A。
 * @tag text
 */
int str_emit_1B1A(void)

{
  char *in_ER0;
  
  strcat_checked(in_ER0,"\x1b\x1a");
  return 0;
}

/**
 * @brief 追加记号序列 0x1B 0x1E
 * @addr 0x20EC8
 * @module strlib
 * @proto void str_emit_1B1E(void)
 * @confidence likely
 * @note 追加记号序列 0x1B 0x1E。
 * @tag text
 */
int str_emit_1B1E(void)

{
  char *in_ER0;
  
  strcat_checked(in_ER0,"\x1b\x1e");
  return 0;
}

/**
 * @brief 追加 ROM 0x1D31 处的记号串
 * @addr 0x20ECE
 * @module strlib
 * @proto void str_emit_1D31(void)
 * @confidence likely
 * @note 追加 ROM 0x1D31 处的记号串。
 * @tag text
 */
int str_emit_1D31(void)

{
  char *in_ER0;
  
  strcat_checked(in_ER0,(char *)0x1d31);
  return 0;
}

/**
 * @brief 追加 ROM 0x1D35 处的记号串
 * @addr 0x20ED4
 * @module strlib
 * @proto void str_emit_1D35(void)
 * @confidence likely
 * @note 追加 ROM 0x1D35 处的记号串。
 * @tag text
 */
int str_emit_1D35(void)

{
  char *in_ER0;
  
  strcat_checked(in_ER0,(char *)0x1d35);
  return 0;
}

/**
 * @brief 追加 ROM 0x1D37 处的记号串
 * @addr 0x20EDA
 * @module strlib
 * @proto void str_emit_1D37(void)
 * @confidence likely
 * @note 追加 ROM 0x1D37 处的记号串。
 * @tag text
 */
int str_emit_1D37(void)

{
  char *in_ER0;
  
  strcat_checked(in_ER0,(char *)0x1d37);
  return 0;
}

/**
 * @brief 追加 ROM 0x1D39 处的记号串
 * @addr 0x20EE0
 * @module strlib
 * @proto void str_emit_1D39(void)
 * @confidence likely
 * @note 追加 ROM 0x1D39 处的记号串。
 * @tag text
 */
int str_emit_1D39(void)

{
  char *in_ER0;
  
  strcat_checked(in_ER0,(char *)0x1d39);
  return 0;
}

/**
 * @brief 向格式化输出追加反引号字符（文本内嵌格式标记）
 * @addr 0x20EE6
 * @module strlib
 * @proto void str_emit_backtick(void)
 * @confidence likely
 * @note 向格式化输出追加反引号字符（文本内嵌格式标记）。
 * @tag text
 */
int str_emit_backtick(void)

{
  char *in_ER0;
  
  strcat_checked(in_ER0,"`");
  return 0;
}

/**
 * @brief 追加 ROM 0x1D3D 处的记号串
 * @addr 0x20EEC
 * @module strlib
 * @proto void str_emit_1D3D(void)
 * @confidence likely
 * @note 追加 ROM 0x1D3D 处的记号串。
 * @tag text
 */
int str_emit_1D3D(void)

{
  char *in_ER0;
  
  strcat_checked(in_ER0,(char *)0x1d3d);
  return 0;
}

/**
 * @brief 按 0xD11C/0xD128/0xD13F 返回提示分隔串（";" 或 0x1D41 常量…
 * @addr 0x20EF2
 * @module strlib
 * @proto char* prompt_string(void)
 * @confidence likely
 * @note 按 0xD11C/0xD128/0xD13F 返回提示分隔串（";" 或 0x1D41 常量）。
 * @tag ui
 */
char* prompt_string(uintptr_t _a2, int _a1)

{
  char cVar1;
  char *pcVar2;
  
  if ((menu_toggle == '\0') ||
     ((_DAT_ram_d128 != '\0' && ((cVar1 = get_ptr_ffd8_4(), cVar1 == '\0' || (cVar1 == '\x04')))))) {
    if (disp_mode == '\0') {
      pcVar2 = ";";
    }
    else {
      pcVar2 = (char *)0x1d41;
    }
  }
  else {
    pcVar2 = ",";
  }
  strcat_checked(_a1,pcVar2);
  return;
}

/**
 * @brief 追加 ROM 0x1D1A 处的记号串
 * @addr 0x20F32
 * @module strlib
 * @proto void str_emit_1D1A(void)
 * @confidence likely
 * @note 追加 ROM 0x1D1A 处的记号串。
 * @tag text
 */
int str_emit_1D1A(void)

{
  char *in_ER0;
  
  strcat_checked(in_ER0,"\x1d\x1a");
  return 0;
}

/**
 * @brief 追加记号字符 0x1C
 * @addr 0x20F38
 * @module strlib
 * @proto void str_emit_1C(void)
 * @confidence likely
 * @note 追加记号字符 0x1C。
 * @tag text
 */
int str_emit_1C(void)

{
  char *in_ER0;
  
  strcat_checked(in_ER0,"\x1c");
  return 0;
}

/**
 * @brief 追加记号字符 0x19
 * @addr 0x20F3E
 * @module strlib
 * @proto void str_emit_19(void)
 * @confidence likely
 * @note 追加记号字符 0x19。
 * @tag text
 */
int str_emit_19(void)

{
  char *in_ER0;
  
  strcat_checked(in_ER0,"\x19");
  return 0;
}

/**
 * @brief 追加 ROM 0x1D4D 处的记号串
 * @addr 0x20F44
 * @module strlib
 * @proto void str_emit_1D4D(void)
 * @confidence likely
 * @note 追加 ROM 0x1D4D 处的记号串。
 * @tag text
 */
int str_emit_1D4D(void)

{
  char *in_ER0;
  
  strcat_checked(in_ER0,(char *)0x1d4d);
  return 0;
}

/**
 * @brief 追加 ROM 0x1D4F 处的记号串
 * @addr 0x20F4A
 * @module strlib
 * @proto void str_emit_1D4F(void)
 * @confidence likely
 * @note 追加 ROM 0x1D4F 处的记号串。
 * @tag text
 */
int str_emit_1D4F(void)

{
  char *in_ER0;
  
  strcat_checked(in_ER0,(char *)0x1d4f);
  return 0;
}

/**
 * @brief 追加记号序列 0x1C 0x19 0x1C 0x19 0x1B
 * @addr 0x20F50
 * @module strlib
 * @proto void str_emit_1C19x2_1B(void)
 * @confidence likely
 * @note 追加记号序列 0x1C 0x19 0x1C 0x19 0x1B。
 * @tag text
 */
int str_emit_1C19x2_1B(void)

{
  char *in_ER0;
  
  strcat_checked(in_ER0,"\x1c\x19\x1c\x19\x1b");
  return 0;
}

/**
 * @brief 追加记号字符 0x1F
 * @addr 0x20F56
 * @module strlib
 * @proto void str_emit_1F(void)
 * @confidence likely
 * @note 追加记号字符 0x1F。
 * @tag text
 */
int str_emit_1F(void)

{
  char *in_ER0;
  
  strcat_checked(in_ER0,"\x1f");
  return 0;
}

/**
 * @brief 追加记号序列 0x18 0x1F 0x1D 0x1A
 * @addr 0x20F5C
 * @module strlib
 * @proto void str_emit_181F1D1A(void)
 * @confidence likely
 * @note 追加记号序列 0x18 0x1F 0x1D 0x1A。
 * @tag text
 */
int str_emit_181F1D1A(void)

{
  char *in_ER0;
  
  strcat_checked(in_ER0,"\x18\x1f\x1d\x1a");
  return 0;
}

/**
 * @brief 追加 ASCII "t"
 * @addr 0x20F62
 * @module strlib
 * @proto void str_emit_t(void)
 * @confidence verified
 * @note 追加 ASCII "t"。
 * @tag text
 */
int str_emit_t(void)

{
  char *in_ER0;
  
  strcat_checked(in_ER0,"t");
  return 0;
}

/**
 * @brief 追加 ROM 0x1D61 处的记号串
 * @addr 0x20F68
 * @module strlib
 * @proto void str_emit_1D61(void)
 * @confidence likely
 * @note 追加 ROM 0x1D61 处的记号串。
 * @tag text
 */
int str_emit_1D61(void)

{
  char *in_ER0;
  
  strcat_checked(in_ER0,(char *)0x1d61);
  return 0;
}

/**
 * @brief 按 0xD14E 追加 0x99 或 0x65（两种状态标签）
 * @addr 0x20F6E
 * @module strlib
 * @proto void str_emit_mode_tag(void)
 * @confidence likely
 * @note 按 0xD14E 追加 0x99 或 0x65（两种状态标签）。
 * @tag text
 */
int str_emit_mode_tag(void)

{
  char *in_ER0;
  undefined uVar1;
  
  if (mixed_fraction == '\0') {
    uVar1 = 99;
  }
  else {
    uVar1 = 0x65;
  }
  strcat_checked(in_ER0,(char *)CONCAT11(0x1d,uVar1));
  return 0;
}

/**
 * @brief 追加 ROM 0x1D67 处的记号串
 * @addr 0x20F80
 * @module strlib
 * @proto void str_emit_1D67(void)
 * @confidence likely
 * @note 追加 ROM 0x1D67 处的记号串。
 * @tag text
 */
int str_emit_1D67(void)

{
  char *in_ER0;
  
  strcat_checked(in_ER0,(char *)0x1d67);
  return 0;
}

/**
 * @brief 追加 ASCII "+"
 * @addr 0x20F86
 * @module strlib
 * @proto void str_emit_plus(void)
 * @confidence verified
 * @note 追加 ASCII "+"。
 * @tag text
 */
int str_emit_plus(void)

{
  char *in_ER0;
  
  strcat_checked(in_ER0,"+");
  return 0;
}

/**
 * @brief 追加 ASCII "-"
 * @addr 0x20F8C
 * @module strlib
 * @proto void str_emit_minus(void)
 * @confidence verified
 * @note 追加 ASCII "-"。
 * @tag text
 */
int str_emit_minus(void)

{
  char *in_ER0;
  
  strcat_checked(in_ER0,"-");
  return 0;
}

/**
 * @brief 向格式化输出追加反引号（另一处调用点）
 * @addr 0x20F92
 * @module strlib
 * @proto void str_emit_backtick2(void)
 * @confidence likely
 * @note 向格式化输出追加反引号（另一处调用点）。
 * @tag text
 */
int str_emit_backtick2(void)

{
  char *in_ER0;
  
  strcat_checked(in_ER0,"`");
  return 0;
}

/**
 * @brief 追加 ASCII "("
 * @addr 0x20F98
 * @module strlib
 * @proto void str_emit_lparen(void)
 * @confidence verified
 * @note 追加 ASCII "("。
 * @tag text
 */
int str_emit_lparen(void)

{
  char *in_ER0;
  
  strcat_checked(in_ER0,"("))
  return 0;
}

/**
 * @brief 追加 ASCII ")"
 * @addr 0x20F9E
 * @module strlib
 * @proto void str_emit_rparen(void)
 * @confidence verified
 * @note 追加 ASCII ")"。
 * @tag text
 */
int str_emit_rparen(void)

{
  char *in_ER0;
  
  strcat_checked(in_ER0,")");
  return 0;
}

/**
 * @brief 追加 ROM 0x1D73 处的记号串
 * @addr 0x20FA4
 * @module strlib
 * @proto void str_emit_1D73(void)
 * @confidence likely
 * @note 追加 ROM 0x1D73 处的记号串。
 * @tag text
 */
int str_emit_1D73(uintptr_t _a2, int _a1)

{
  strcat_checked(_a1,(char *)0x1d73);
  return 0;
}

/**
 * @brief 追加 ROM 0x1D77 处的记号串
 * @addr 0x20FAA
 * @module strlib
 * @proto void str_emit_1D77(void)
 * @confidence likely
 * @note 追加 ROM 0x1D77 处的记号串。
 * @tag text
 */
int str_emit_1D77(uintptr_t _a2, int _a1)

{
  strcat_checked(_a1,(char *)0x1d77);
  return 0;
}

