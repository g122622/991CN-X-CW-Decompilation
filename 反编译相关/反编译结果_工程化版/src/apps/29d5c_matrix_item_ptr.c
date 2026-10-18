/*
 * 应用模式 / 29d5c_matrix_item_ptr.c
 * 地址范围: 0x29D5C - 0x2A472
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 返回矩阵/表格第 i 项的 16 位值（0xD12B 索引到 ROM 0x62A4 表）
 * @addr 0x29D5C
 * @module apps
 * @proto undefined2 matrix_item_ptr(ushort i)
 * @confidence strong
 * @note 返回矩阵/表格第 i 项的 16 位值（0xD12B 索引到 ROM 0x62A4 表）。
 * @tag matrix
 */
undefined2 matrix_item_ptr(ushort i)

{
  return *(undefined2 *)(*(short *)((ushort)menu_sel_c * 2 + 0x62a4) + i * 2 + -2);
}

/**
 * @brief 把输入表达式转换成常量（0x2101E 处理）
 * @addr 0x29D7A
 * @module apps
 * @proto char* expr_to_const(char* p)
 * @confidence likely
 * @note 把输入表达式转换成常量（0x2101E 处理）。
 * @tag eval
 */
char* expr_to_const(char* p, int _a2)

{
  if (_a2 == '\0') {
    str_emit_1DBA(p);
  }
  else {
    str_emit_1D97(p);
  }
  return p;
}

/**
 * @brief 特殊编辑状态判断（0x2880E 或 is_edit_state_6_9）
 * @addr 0x29D94
 * @module apps
 * @proto char is_special_editing(void)
 * @confidence strong
 * @note 特殊编辑状态判断（0x2880E 或 is_edit_state_6_9）。
 * @tag ui
 */
char is_special_editing(void)

{
  char cVar1;
  undefined uVar2;
  
  cVar1 = is_edit_flag_16();
  if ((cVar1 == '\0') && (cVar1 = is_edit_state_6_9(), cVar1 == '\0')) {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}

/**
 * @brief 列表打开
 * @addr 0x29DBE
 * @module apps
 * @proto void list_open_cursor(void)
 * @confidence likely
 * @note 列表打开：按 0x1EB86 选初始行 0x1B/0x18，0xE21E 返回 3 时复位。
 * @tag ui
 */
int list_open_cursor(void)

{
  int cVar1;
  undefined uVar2;
  short unaff_ER14;
  
  frame_enter();
  cVar1 = is_equation_mode();
  if (cVar1 == '\0') {
    uVar2 = 0x1b;
  }
  else {
    uVar2 = 0x18;
  }
  *(ushort *)(unaff_ER14 + -2) = CONCAT11(0xeb,uVar2);
  cVar1 = edit_loop();
  if (cVar1 == '\x03') {
    input_key = 0;
    mode_switch_refresh();
    input_key = 0xfc26;
  }
  else if (cVar1 == '\x02') {
    input_key = *(undefined2 *)(unaff_ER14 + -2);
  }
  else {
    *(undefined2 *)(unaff_ER14 + -2) = 0;
  }
  frame_leave();
  return 0;
}

/**
 * @brief p[5] 递减（到 0 时先 0x253F0）
 * @addr 0x29E14
 * @module apps
 * @proto void decrement_field(byte* p)
 * @confidence likely
 * @note p[5] 递减（到 0 时先 0x253F0）。
 * @tag ui
 */
int decrement_field(byte* p)

{
  char cVar1;
  
  if (*(char *)(p + 5) == '\0') {
    beep();
    cVar1 = '\0';
  }
  else {
    cVar1 = *(char *)(p + 5) + -1;
  }
  *(char *)(p + 5) = cVar1;
  return 0;
}

/**
 * @brief 统计计算主流程（3.1KB，0x9C40/0x1E842 调用）
 * @addr 0x29E38
 * @module apps
 * @proto void stat_calc_main(void)
 * @confidence likely
 * @note 统计计算主流程（3.1KB，0x9C40/0x1E842 调用）。
 * @tag app
 */
int stat_calc_main(uintptr_t _a2, int _a1)

{
  bool bVar1;
  bool bVar2;
  char cVar3;
  int bVar4;
  undefined2 *puVar5;
  undefined2 uVar6;
  undefined2 *puVar7;
  char *pcVar8;
  ushort uVar9;
  short sVar10;
  short unaff_ER14;
  
  puVar5 = (undefined2 *)frame_enter();
  puVar7 = _a1;
  uVar6 = dec_cmp(puVar5,_a1);
  *(char *)(unaff_ER14 + -0x41) = (char)uVar6;
  uVar6 = dec_cmp(puVar5 + 5,puVar7);
  cVar3 = (char)uVar6;
  *(undefined *)(unaff_ER14 + -0x44) = _DAT_ram_d166;
  bVar2 = false;
  if ((*(char *)(unaff_ER14 + -0x41) == '\x01') && (cVar3 != '\x01')) {
    bVar2 = true;
  }
  _DAT_ram_d166 = 0;
  *(undefined *)_a1 = 0;
  if (!bVar2) {
    *(undefined *)(unaff_ER14 + -0x42) = 6;
    uVar6 = disp_field_width((byte *)puVar5);
    *(char *)(unaff_ER14 + -0x43) = (char)uVar6;
    uVar9 = 8;
    puVar7 = puVar5;
    sVar10 = unaff_ER14;
    do {
      *(undefined2 *)(sVar10 + -2) = puVar7[4];
      puVar7 = puVar7 + -1;
      sVar10 = sVar10 + -2;
      bVar1 = 1 < uVar9;
      uVar9 = uVar9 - 2;
    } while ((char)(bVar1 << 7) < '\0');
    uVar9 = dec_type_of((undefined *)(unaff_ER14 + -10));
    if ((char)((uVar9 & 0xff) >> 4) == '\x04') {
      draw_token_plain(puVar5,_a1,6,0);
    }
    else {
      if ((*(char *)(unaff_ER14 + -0x43) != '\0') && (*(char *)(unaff_ER14 + -0x41) != '\x02')) {
        *(undefined *)(unaff_ER14 + -0x42) = 5;
      }
      bVar4 = draw_tokens((undefined2 *)(unaff_ER14 + -10));
      if ((*(char *)(unaff_ER14 + -0x42) == '\x05') && (*(byte *)(unaff_ER14 + -10) >> 4 != bVar4))
      {
        draw_token_plain(puVar5,_a1,6,0);
      }
    }
    if (cVar3 == '\x04') {
      strcat_raw((char *)_a1,"+");
    }
  }
  if (cVar3 != '\x01') {
    uVar9 = 8;
    puVar7 = puVar5;
    sVar10 = unaff_ER14;
    do {
      *(undefined2 *)(sVar10 + -0xc) = puVar7[9];
      puVar7 = puVar7 + -1;
      sVar10 = sVar10 + -2;
      bVar1 = 1 < uVar9;
      uVar9 = uVar9 - 2;
    } while ((char)(bVar1 << 7) < '\0');
    uVar6 = disp_field_width((byte *)(puVar5 + 5));
    bVar4 = 6;
    if (((bVar2) && (cVar3 == '\x04')) && ((char)uVar6 == '\0')) {
      bVar4 = 7;
    }
    if (cVar3 == '\x04') {
      dec_inc5((undefined2 *)(unaff_ER14 + -0x14),uVar9);
    }
    uVar9 = dec_type_of((undefined *)(unaff_ER14 + -0x14));
    if ((char)((uVar9 & 0xff) >> 4) == '\x04') {
      draw_token_plain((undefined2 *)(unaff_ER14 + -0x14),(undefined2 *)(unaff_ER14 + -0x40),bVar4,0);
    }
    else {
      bVar4 = draw_tokens((undefined2 *)(unaff_ER14 + -0x14));
      if ((((char)uVar6 != '\0') && (cVar3 == '\x04')) &&
         ((bVar2 && (*(byte *)(unaff_ER14 + -0x14) >> 4 != bVar4)))) {
        draw_token_plain((undefined2 *)(unaff_ER14 + -0x14),(undefined2 *)(unaff_ER14 + -0x40),7,0);
      }
    }
    if (cVar3 == '\x02') {
      if (bVar2) {
        pcVar8 = "`";
      }
      else {
        pcVar8 = "-";
      }
      strcat_raw((char *)_a1,pcVar8);
    }
    parse_number_str((char *)(unaff_ER14 + -0x3f),-0x80);
    strcat_raw((char *)_a1,(char *)(unaff_ER14 + -0x3f));
  }
  _DAT_ram_d166 = *(undefined *)(unaff_ER14 + -0x44);
  frame_leave();
  return 0;
}

/**
 * @brief 把 src 追加到 dst 末尾（无长度检查），返回 dst
 * @addr 0x2A020
 * @module apps
 * @proto char* strcat_raw(char* dst, char* src)
 * @confidence verified
 * @note 把 src 追加到 dst 末尾（无长度检查），返回 dst。
 * @tag libc
 */
char* strcat_raw(char* dst, char* src)

{
  char cVar1;
  char *pcVar2;
  
  for (pcVar2 = dst; *pcVar2 != '\0'; pcVar2 = pcVar2 + 1) {
  }
  for (; cVar1 = *src, *pcVar2 = cVar1, cVar1 != '\0'; src = src + 1) {
    pcVar2 = pcVar2 + 1;
  }
  return dst;
}

/**
 * @brief 取点阵指针后按缩放系数绘制字符 ch
 * @addr 0x2A048
 * @module apps
 * @proto void draw_scaled_char(ushort ch, char wide)
 * @confidence strong
 * @note 取点阵指针后按缩放系数绘制字符 ch：宽字符时纵向步长减半（8 行 -> 4 行）。
 * @tag ui
 */
int draw_scaled_char(ushort ch, char _a1)

{
  int cVar1;
  byte bVar2;
  undefined2 uVar3;
  
  uVar3 = frame_enter();
  cVar1 = skip_input_line();
  bVar2 = -cVar1 - 0x40;
  if ((char)((ushort)ch >> 8) != '\0') {
    bVar2 = bVar2 >> 1;
  }
  draw_string(CONCAT11((char)ch,bVar2),uVar3);
  frame_leave();
  return 0;
}

/**
 * @brief 按单元数据计算索引并把值写入矩阵单元（0x1D550，0xC85A/0xDAA4 使用）
 * @addr 0x2A074
 * @module apps
 * @proto void matrix_set_value(byte idx)
 * @confidence likely
 * @note 按单元数据计算索引并把值写入矩阵单元（0x1D550，0xC85A/0xDAA4 使用）。
 * @tag matrix
 */
int matrix_set_value(byte idx)

{
  byte bVar1;
  byte bVar2;
  undefined2 *puVar3;
  short sVar4;
  ushort uVar5;
  
  puVar3 = (undefined2 *)frame_enter();
  bVar1 = *(byte *)((short)puVar3 + 9) & 0xf;
  bVar2 = *(byte *)(puVar3 + 4);
  sVar4 = mul16((puVar3[4] & 0xff) >> 4,10);
  sVar4 = sVar4 + (ushort)(bVar2 & 0xf);
  if ((bVar1 == 0) || (bVar1 == 5)) {
    sVar4 = CONCAT11((char)((ushort)sVar4 >> 8) + -1 + (0x62 < (byte)sVar4),(byte)sVar4 + 0x9d);
  }
  else {
    sVar4 = sVar4 + 1;
  }
  uVar5 = (ushort)idx + sVar4 + 1;
  bVar2 = (byte)(uVar5 >> 8);
  bVar1 = bVar2 - ((byte)uVar5 < 10);
  if ((byte)((byte)((bVar1 ^ bVar2) & ~bVar1) >> 7 ^ (char)bVar1 < '\0' |
            ((byte)uVar5 == 10 && bVar1 == 0)) == 1) {
    if ((short)uVar5 < 0) {
      dec_exp_shift(puVar3,(ushort)bVar2 << 8);
    }
    else {
      dec_exp_shift(puVar3,uVar5);
    }
  }
  else {
    dec_exp_shift(puVar3,CONCAT11(bVar2,0xb));
  }
  frame_leave();
  return 0;
}

/**
 * @brief 表格菜单流程（1.3KB，0x27284 调用）
 * @addr 0x2A13C
 * @module apps
 * @proto int table_menu_flow(void)
 * @confidence likely
 * @note 表格菜单流程（1.3KB，0x27284 调用）。
 * @tag app
 */
int table_menu_flow(uintptr_t _a2, int _a1)

{
  byte bVar1;
  char cVar2;
  byte bVar3;
  undefined2 *puVar4;
  short sVar5;
  bool bVar6;
  short unaff_ER14;
  
  puVar4 = (undefined2 *)frame_enter();
  bVar1 = cur_line;
  cVar2 = is_modifier_1();
  if ((cVar2 != '\0') && (**(byte **)(unaff_ER14 + 0x12) != 0)) {
    sVar5 = (ushort)bVar1 + (ushort)**(byte **)(unaff_ER14 + 0x12);
    bVar3 = (byte)sVar5;
    bVar6 = SUB21((ushort)sVar5 >> 8,0);
    if ((-1 < (char)(bVar6 - (bVar3 < 0x41)) && (bVar3 != 0x41 || bVar6 != bVar3 < 0x41)) &&
       (0xbf < **(byte **)(unaff_ER14 + 0x10))) {
      **(byte **)(unaff_ER14 + 0x10) = history_key;
    }
    bVar3 = 1;
    if (calc_mode == '\x02') {
      bVar3 = 0xf;
    }
    if ((ushort)**(byte **)(unaff_ER14 + 0x12) < (ushort)bVar1 + (ushort)bVar3) goto LAB_rom_02a19a;
    **(char **)(unaff_ER14 + 0x12) = **(char **)(unaff_ER14 + 0x12) - bVar1;
  }
  bVar3 = (byte)*puVar4;
  *puVar4 = CONCAT11((char)((ushort)*puVar4 >> 8) - (bVar3 < bVar1),bVar3 - bVar1);
  bVar3 = (byte)*_a1;
  cVar2 = (char)((ushort)*_a1 >> 8) - (bVar3 < bVar1);
  *_a1 = CONCAT11(cVar2,bVar3 - bVar1);
  if (cVar2 < '\0') {
    *_a1 = CONCAT11(-(bVar1 != 0),-bVar1);
  }
  scroll_screen(bVar1);
LAB_rom_02a19a:
  frame_leave();
  return 0;
}

/**
 * @brief 表格编辑流程（2.8KB，0x1F25A/0x2B00A 调用）
 * @addr 0x2A1CE
 * @module apps
 * @proto int table_edit_flow(void)
 * @confidence likely
 * @note 表格编辑流程（2.8KB，0x1F25A/0x2B00A 调用）。
 * @tag app
 */
int table_edit_flow(void)

{
  bool bVar1;
  byte bVar2;
  byte bVar3;
  undefined2 uVar4;
  ushort uVar5;
  ushort uVar6;
  byte bVar7;
  char cVar8;
  
  uVar4 = frame_enter();
  bVar1 = true;
  cVar8 = -0x60;
  if (calc_mode == '\f') {
    cVar8 = 'Z';
  }
  bVar2 = stat_table_width();
  bVar3 = cVar8 - var_scroll * bVar2;
  uVar5 = (ushort)bVar3;
  bVar7 = var_scroll;
  if (bVar3 < bVar2) {
    bVar7 = var_scroll - 1;
  }
  bVar3 = (byte)uVar4;
  cVar8 = (char)((ushort)uVar4 >> 8);
  if (bVar3 == 0x1c && (bool)(cVar8 + '\x04') == bVar3 < 0x1c) {
    uVar5 = (ushort)list_col;
    if (list_col == 1) {
      if ((char)((list_page < 2) << 7) < '\0') {
        if (bVar7 < 4) {
          list_col = bVar7 + 1;
          uVar5 = (ushort)list_col;
        }
        else {
          list_col = 4;
          list_page = bVar7 - 2;
          uVar5 = (ushort)list_page;
        }
      }
      else {
        list_page = list_page - 1;
        uVar5 = (ushort)list_page;
      }
    }
    else {
      if (list_col < 2) goto LAB_rom_02a224;
      list_col = list_col - 1;
      uVar5 = (ushort)list_col;
    }
    bVar1 = false;
    goto LAB_rom_02a224;
  }
  if (bVar3 != 0x1d || (bool)(cVar8 + '\x04') != bVar3 < 0x1d) {
    if (bVar3 == 0x1e && (bool)(cVar8 + '\x04') == bVar3 < 0x1e) {
      if (((calc_mode != '\f') || (uVar5 = (ushort)key_modifiers, key_modifiers == 5)) &&
         (uVar5 = (ushort)list_row, (char)((list_row < bVar2) << 7) < '\0')) {
        list_row = list_row + 1;
        uVar5 = (ushort)list_row;
        bVar1 = false;
      }
      goto LAB_rom_02a224;
    }
    if (bVar3 == 0x1f && (bool)(cVar8 + '\x04') == bVar3 < 0x1f) {
      uVar5 = (ushort)list_row;
      if (1 < list_row) {
        list_row = list_row - 1;
        uVar5 = (ushort)list_row;
        bVar1 = false;
      }
      goto LAB_rom_02a224;
    }
    if (bVar3 != 0x2d || (bool)(cVar8 + '\x04') != bVar3 < 0x2d) goto LAB_rom_02a224;
  }
  uVar5 = (ushort)list_col + (ushort)list_page;
  uVar6 = bVar7 + 1;
  if ((byte)(SBORROW2(uVar5,uVar6) ^ (short)(uVar5 - uVar6) < 0 | uVar5 == uVar6) == 0) {
    if (bVar3 != 0x2d || (bool)(cVar8 + '\x04') != bVar3 < 0x2d) {
      uVar5 = 1;
      list_page = 1;
      list_col = 1;
      bVar1 = false;
    }
  }
  else if (list_col == 4) {
    uVar6 = (ushort)list_page;
    uVar5 = bVar7 - 3;
    if ((byte)(SBORROW2(uVar6,uVar5) ^ (short)(uVar6 - uVar5) < 0 | uVar6 == uVar5) != 0) {
      list_page = list_page + 1;
      uVar5 = (ushort)list_page;
      bVar1 = false;
    }
  }
  else {
    list_col = list_col + 1;
    uVar5 = (ushort)list_col;
    bVar1 = false;
  }
LAB_rom_02a224:
  if (!bVar1) {
    key_hist_clear0((char)uVar5);
  }
  frame_leave();
  return 0;
}

/**
 * @brief 构造格式符 1 的 10 字节描述
 * @addr 0x2A318
 * @module apps
 * @proto void format_pattern_a(byte* dst)
 * @confidence strong
 * @note 构造格式符 1 的 10 字节描述：3 字节签名 + 5 字节参数 + 显示位置 0x104。
 * @tag format
 */
int format_pattern_a(byte* dst)

{
  memzero(dst,10);
  *dst = 3;
  dst[1] = 0x27;
  dst[2] = 0x67;
  *(undefined2 *)(dst + 8) = 0x104;
  return 0;
}

/**
 * @brief 表格粘贴（1.3KB，0xCED6/0x23BD6 调用）
 * @addr 0x2A340
 * @module apps
 * @proto void table_paste(undefined2* a)
 * @confidence likely
 * @note 表格粘贴（1.3KB，0xCED6/0x23BD6 调用）。
 * @tag app
 */
int table_paste(undefined2* a)

{
  byte *pbVar1;
  byte bVar2;
  byte bVar3;
  char cVar4;
  byte *pbVar5;
  byte *pbVar6;
  undefined2 uVar7;
  char cVar8;
  
  pbVar5 = (byte *)frame_enter();
  pbVar1 = input_ptr;
  cVar8 = '\x01';
  *a = 0;
  pbVar6 = pbVar5;
  if (*pbVar5 == 0x1e) {
    pbVar6 = prev_char_ptr(pbVar1,pbVar5);
  }
  if (*pbVar6 == 0x1b) {
    pbVar6 = prev_char_ptr(pbVar1,pbVar6);
  }
  do {
    while( true ) {
      uVar7 = token_class((char *)pbVar6);
      pbVar6 = prev_char_ptr(pbVar1,pbVar6);
      if (pbVar6 == (byte *)0x0) goto LAB_rom_02a3e2;
      cVar4 = is_frac_sep((char)uVar7);
      if (cVar4 == '\0') break;
      cVar8 = cVar8 + '\x01';
    }
    cVar4 = is_v2_02((char)uVar7);
  } while (((cVar4 == '\0') || (cVar8 = cVar8 + -1, cVar8 != '\0')) || (*pbVar6 == 0x1b));
  if ((*pbVar6 == 0x1d) && (pbVar6 = prev_char_ptr(pbVar1,pbVar6), *pbVar6 == 0x1f)) {
    pbVar6 = prev_char_ptr(pbVar1,pbVar6);
  }
  bVar2 = (char)pbVar5 - (char)pbVar6;
  bVar3 = token_insert_pos((uintptr_t)0);
  if (((bVar2 <= bVar3) && (cVar8 = get_token_class(pbVar6), cVar8 != '\0')) &&
     ((bVar3 = token_scan(1), bVar3 <= bVar2 &&
      (((*a = 1, cVar8 != '\x01' && (cVar8 != '\x02')) &&
       (bVar3 = token_scan(2), bVar3 <= bVar2)))))) {
    *a = 2;
  }
LAB_rom_02a3e2:
  frame_leave();
  return 0;
}

/**
 * @brief 构造格式符 2 的 10 字节描述
 * @addr 0x2A428
 * @module apps
 * @proto void format_pattern_b(byte* dst)
 * @confidence strong
 * @note 构造格式符 2 的 10 字节描述：3 字节签名 + 5 字节参数 + 显示位置 0x104。
 * @tag format
 */
int format_pattern_b(byte* dst)

{
  memzero(dst,10);
  *dst = 4;
  dst[1] = 0x29;
  dst[2] = 0x49;
  dst[3] = 0x67;
  dst[4] = 0x29;
  dst[5] = 0x60;
  *(undefined2 *)(dst + 8) = 0x109;
  return 0;
}

/**
 * @brief 读取并返回光标/编辑模式 0xD137，随后置为 10（与 fill_screen 的 0x…
 * @addr 0x2A462
 * @module apps
 * @proto byte cursor_mode_take(void)
 * @confidence strong
 * @note 读取并返回光标/编辑模式 0xD137，随后置为 10（与 fill_screen 的 0x400 参数对应）。
 * @tag ui
 */
byte cursor_mode_take(void)

{
  undefined uVar1;
  
  uVar1 = cur_line;
  cur_line = 10;
  return uVar1;
}

/**
 * @brief 表格复制（3.9KB，0xDCFA/0x1E1B6 调用）
 * @addr 0x2A472
 * @module apps
 * @proto void table_copy(byte* p)
 * @confidence likely
 * @note 表格复制（3.9KB，0xDCFA/0x1E1B6 调用）。
 * @tag app
 */
int table_copy(byte* p)

{
  char cVar1;
  int bVar2;
  char cVar3;
  short sVar4;
  undefined2 uVar5;
  short sVar6;
  byte *pbVar7;
  undefined *puVar8;
  short unaff_ER14;
  
  frame_enter();
  sVar6 = input_key;
  *(undefined *)(unaff_ER14 + -1) = 0;
  if ((byte)input_key == 0x42 &&
      (bool)((char)((ushort)input_key >> 8) + '\x04') == (byte)input_key < 0x42) {
    commit_line();
  }
  sVar4 = key_filter_mode(sVar6);
  if (sVar4 != 0) {
    history_dirty = 1;
LAB_rom_02a4aa:
    bVar2 = (byte)sVar6;
    cVar3 = (char)((ushort)sVar6 >> 8);
    if (bVar2 == 0x42 && (bool)(cVar3 + '\x04') == bVar2 < 0x42) {
LAB_rom_02a4d6:
      main_loop();
    }
    else {
      uVar5 = key_is_extended(sVar6);
      if ((char)uVar5 != '\0') {
        sVar6 = key_code_lookup(sVar6);
        bVar2 = (byte)((ushort)p >> 8);
        if (sVar6 != 0) {
          set_input_key(sVar6);
        }
        commit_line();
        p = (byte *)((ushort)bVar2 << 8);
        wrap_29614('\0');
        goto LAB_rom_02a4d6;
      }
      cVar1 = is_key_3e_1e_1f(bVar2,cVar3);
      if (cVar1 == '\0') {
        input_active = 0;
      }
      if (bVar2 == 7 && (bool)(cVar3 + '\x04') == bVar2 < 7) goto LAB_rom_02a5de;
      if ((((bVar2 == 0x1c && (bool)(cVar3 + '\x04') == bVar2 < 0x1c) ||
           (bVar2 == 0x1d && (bool)(cVar3 + '\x04') == bVar2 < 0x1d)) ||
          (bVar2 == 0x1e && (bool)(cVar3 + '\x04') == bVar2 < 0x1e)) ||
         (bVar2 == 0x1f && (bool)(cVar3 + '\x04') == bVar2 < 0x1f)) {
LAB_rom_02a568:
        edit_ctx_check();
        goto LAB_rom_02a4d6;
      }
      if (bVar2 == 0x24 && (bool)(cVar3 + '\x04') == bVar2 < 0x24) goto LAB_rom_02a564;
      if (bVar2 == 0x25 && (bool)(cVar3 + '\x04') == bVar2 < 0x25) goto LAB_rom_02a55e;
      if (bVar2 == 0x26 && (bool)(cVar3 + '\x04') == bVar2 < 0x26) goto LAB_rom_02a5de;
      if ((bVar2 == 0x2d && (bool)(cVar3 + '\x04') == bVar2 < 0x2d) ||
         (bVar2 == 0x30 && (bool)(cVar3 + '\x04') == bVar2 < 0x30)) {
        if (input_buf != '\0') {
          *(undefined **)(unaff_ER14 + -4) = &input_buf;
          p = (byte *)(unaff_ER14 + -0x18);
          bVar2 = matrix_entry((undefined2 *)(unaff_ER14 + -4),(ushort)p);
          *(byte *)(unaff_ER14 + -1) = bVar2;
          if ((bVar2 == 0) || (0x1f < *(byte *)(unaff_ER14 + -1))) {
            puVar8 = (undefined *)(unaff_ER14 + -1);
            uVar5 = cursor_pos_update((undefined2 *)(unaff_ER14 + -0x18),puVar8);
            if ((char)uVar5 == '\0') {
              key_mod_clear();
              if (calc_mode != -0x3c) {
                puVar8 = (undefined *)((ushort)puVar8 & 0xff00);
                dec_set_uint_small((ushort *)(unaff_ER14 + -0xe),0);
              }
              stat_edit_move(puVar8);
              goto LAB_rom_02a55e;
            }
            p = *(byte **)(unaff_ER14 + -4);
            pbVar7 = prev_char_ptr(&input_buf,p);
            *(byte **)(unaff_ER14 + -4) = pbVar7;
          }
          history_cursor = *(char *)(unaff_ER14 + -4) + -0x80;
          key_modifiers = 0x80;
          sVar6 = menu_get_key(*(char *)(unaff_ER14 + -1));
          cVar3 = is_up_down((char)sVar6,(char)((ushort)sVar6 >> 8));
          if (cVar3 != '\0') {
            input_init();
            goto LAB_rom_02a4d6;
          }
          set_input_key(0xfc26);
LAB_rom_02a5de:
          input_init();
          goto LAB_rom_02a55e;
        }
      }
      else if (bVar2 == 0x3e && (bool)(cVar3 + '\x04') == bVar2 < 0x3e) goto LAB_rom_02a568;
    }
    fb_flush();
    sVar6 = process_key((short)p);
    sVar6 = key_filter_mode(sVar6);
    if ((byte)sVar6 == 0x36 && (bool)((char)((ushort)sVar6 >> 8) + '\x04') == (byte)sVar6 < 0x36) {
      sVar6 = 0xdc;
    }
    set_input_key(sVar6);
    goto LAB_rom_02a4aa;
  }
LAB_rom_02a55e:
  key_modifiers = 3;
LAB_rom_02a564:
  frame_leave();
  return 0;
}

