/*
 * 应用模式 / 2a6a0_table_clear.c
 * 地址范围: 0x2A6A0 - 0x2AE46
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 表格清除（3.8KB，0x15650 调用）
 * @addr 0x2A6A0
 * @module apps
 * @proto int table_clear(void)
 * @confidence likely
 * @note 表格清除（3.8KB，0x15650 调用）。
 * @tag app
 */
int table_clear(void)

{
  undefined2 uVar1;
  undefined2 *puVar2;
  undefined uVar5;
  undefined2 uVar3;
  undefined2 uVar4;
  undefined uVar6;
  undefined uVar7;
  short unaff_ER14;
  
  frame_enter();
  *(undefined *)(unaff_ER14 + -0x13) = 0;
  uVar4 = 0xd6e4;
  *(undefined2 *)(unaff_ER14 + -4) = 0xd6f8;
  uVar7 = 0xd7;
  uVar6 = 0xd7;
  *(undefined2 *)(unaff_ER14 + -6) = 0xd716;
  *(undefined2 *)(unaff_ER14 + -2) = 0xd720;
  uVar3 = 0xd72a;
  *(undefined2 *)(unaff_ER14 + -10) = 0xd7fc;
  *(undefined2 *)(unaff_ER14 + -8) = 0xd806;
  *(undefined2 *)(unaff_ER14 + -0xc) = 0xd810;
  *(undefined2 *)(unaff_ER14 + -0xe) = 0xd81a;
  *(undefined2 *)(unaff_ER14 + -0x10) = 0xd87e;
  *(undefined2 *)(unaff_ER14 + -0x12) = 0xd888;
  uVar1 = 0xd806;
  dec_copy((undefined2 *)0xd6da,(undefined2 *)0xd806);
  dec_xy_sub((undefined2 *)0xd6da,uVar1);
  dec_copy(*(undefined2 **)(unaff_ER14 + -4),(undefined2 *)0xd6da);
  dec_copy((undefined2 *)0xd702,*(undefined2 **)(unaff_ER14 + -10));
  puVar2 = *(undefined2 **)(unaff_ER14 + -0xc);
  dec_bin_pow((undefined2 *)0xd702,puVar2);
  dec_cmp_ex((undefined2 *)0xd702,puVar2);
  uVar5 = uVar7;
  dec_copy((undefined2 *)0xd6e4,(undefined2 *)0xd702);
  dec_set_from_fmt(0xd70c,CONCAT11(uVar5,3));
  dec_bin_pow((undefined2 *)0xd702,(undefined2 *)0xd70c);
  dec_bin_mul((undefined2 *)0xd6da,(undefined2 *)0xd702);
  dec_set_from_fmt(0xd70c,CONCAT11(uVar7,4));
  dec_add_or_round((undefined2 *)0xd6da,(undefined2 *)0xd70c);
  dec_add_or_round(*(undefined2 **)(unaff_ER14 + -4),(undefined2 *)0xd70c);
  puVar2 = *(undefined2 **)(unaff_ER14 + -0xe);
  dec_copy((undefined2 *)0xd72a,puVar2);
  dec_set_from_fmt(0xd70c,CONCAT11((char)((ushort)puVar2 >> 8),3));
  dec_bin_pow((undefined2 *)0xd72a,(undefined2 *)0xd70c);
  dec_bin_div((undefined2 *)0xd6da,(undefined2 *)0xd72a);
  dec_inc5((undefined2 *)0xd6da,uVar3);
  dec_copy(*(undefined2 **)(unaff_ER14 + -0x10),(undefined2 *)0xd6da);
  dec_bin_pow((undefined2 *)0xd6e4,*(undefined2 **)(unaff_ER14 + -8));
  puVar2 = *(undefined2 **)(unaff_ER14 + -10);
  dec_copy(*(undefined2 **)(unaff_ER14 + -6),puVar2);
  dec_xy_sub(*(undefined2 **)(unaff_ER14 + -6),puVar2);
  dec_bin_pow(*(undefined2 **)(unaff_ER14 + -6),(undefined2 *)0xd72a);
  dec_bin_mul((undefined2 *)0xd6e4,*(undefined2 **)(unaff_ER14 + -6));
  puVar2 = *(undefined2 **)(unaff_ER14 + -0xc);
  dec_copy(*(undefined2 **)(unaff_ER14 + -2),puVar2);
  dec_xy_sub(*(undefined2 **)(unaff_ER14 + -2),puVar2);
  dec_cmp_ex(*(undefined2 **)(unaff_ER14 + -2),puVar2);
  dec_bin_pow(*(undefined2 **)(unaff_ER14 + -2),(undefined2 *)0xd70c);
  puVar2 = *(undefined2 **)(unaff_ER14 + -2);
  dec_bin_mul((undefined2 *)0xd6e4,puVar2);
  dec_set_from_fmt(0xd70c,CONCAT11((char)((ushort)puVar2 >> 8),8));
  dec_add_or_round((undefined2 *)0xd6e4,(undefined2 *)0xd70c);
  dec_set_from_fmt(0xd70c,CONCAT11(uVar6,9));
  dec_bin_pow((undefined2 *)0xd6e4,(undefined2 *)0xd70c);
  dec_bin_pow(*(undefined2 **)(unaff_ER14 + -4),*(undefined2 **)(unaff_ER14 + -8));
  dec_bin_mul((undefined2 *)0xd6e4,*(undefined2 **)(unaff_ER14 + -4));
  dec_copy((undefined2 *)0xd72a,*(undefined2 **)(unaff_ER14 + -8));
  dec_bin_pow((undefined2 *)0xd72a,*(undefined2 **)(unaff_ER14 + -0xe));
  dec_bin_pow((undefined2 *)0xd72a,(undefined2 *)0xd70c);
  dec_bin_div((undefined2 *)0xd6e4,(undefined2 *)0xd72a);
  dec_copy(*(undefined2 **)(unaff_ER14 + -0x12),(undefined2 *)0xd6e4);
  uVar1 = dec_cmp(*(undefined2 **)(unaff_ER14 + -0x10),uVar4);
  if (((char)uVar1 == '\x01') &&
     (uVar1 = dec_cmp(*(undefined2 **)(unaff_ER14 + -0x12),uVar4), (char)uVar1 == '\x01')) {
    *(undefined *)(unaff_ER14 + -0x13) = 1;
  }
  frame_leave();
  return 0;
}

/**
 * @brief 逐行扫描键盘矩阵（最多 8 行，0xF046 行走位），找到首个按下键后返回 1
 * @addr 0x2A84C
 * @module apps
 * @proto byte lcd_scan_keys(byte* out)
 * @confidence strong
 * @note 逐行扫描键盘矩阵（最多 8 行，0xF046 行走位），找到首个按下键后返回 1；未按下返回 0。
 * @tag key
 */
byte lcd_scan_keys(byte* _a1)

{
  byte bVar1;
  byte bVar2;
  byte *pbVar3;
  byte bVar4;
  
  pbVar3 = (byte *)frame_enter();
  bVar1 = _DAT_ram_f040;
  bVar4 = 1;
  bVar2 = 1;
  do {
    kbd_ko = bVar2;
    if (_DAT_ram_f040 != 0xff) {
      pbVar3[1] = kbd_ko;
      *pbVar3 = bVar1 ^ 0xff;
      break;
    }
    bVar4 = bVar4 + 1;
    bVar2 = kbd_ko << 1;
  } while (bVar4 < 8);
  kbd_ko_disable();
  frame_leave();
  return;
}

/**
 * @brief 字符为 3（分数/混合数标记）时返回 1，否则 0
 * @addr 0x2A886
 * @module apps
 * @proto byte is_frac_sep(char ch)
 * @confidence likely
 * @note 字符为 3（分数/混合数标记）时返回 1，否则 0。
 * @tag parser
 */
byte is_frac_sep(char ch)

{
  if (ch == '\x03') {
    return 1;
  }
  return 0;
}

/**
 * @brief 列表模式 0xD112 为 1..3 时按 4 字节步长刷新对应三角形/矩阵条目（table…
 * @addr 0x2A892
 * @module apps
 * @proto void page2_triangle_redraw(void)
 * @confidence likely
 * @note 列表模式 0xD112 为 1..3 时按 4 字节步长刷新对应三角形/矩阵条目（table 0x1A70）。
 * @tag ui matrix
 */
int page2_triangle_redraw(void)

{
  short sVar1;
  
  if (((sub_mode == 1) || (sub_mode == 2)) || (sub_mode == 3)) {
    sVar1 = CONCAT11((char)(((ushort)sub_mode << 2) >> 8),sub_mode << 2);
    draw_hline(*(undefined2 *)(sVar1 + 0x1a70),*(undefined2 *)(sVar1 + 0x1a72));
  }
  return 0;
}

/**
 * @brief 若目标字段高位半字节为 2 或 8（宽值）则宽度字节置 1，否则 0
 * @addr 0x2A960
 * @module apps
 * @proto ushort disp_field_width(byte* dst)
 * @confidence likely
 * @note 若目标字段高位半字节为 2 或 8（宽值）则宽度字节置 1，否则 0。
 * @tag ui
 */
ushort disp_field_width(byte* dst)

{
  byte bVar1;
  
  bVar1 = (byte)((ushort)dst >> 8);
  if ((*dst >> 4 != 2) && (*dst >> 4 != 8)) {
    return (ushort)bVar1 << 8;
  }
  return CONCAT11(bVar1,1);
}

/**
 * @brief 0x262BA 归一化后判断是否在 0x40..0x49 菜单码范围
 * @addr 0x2A974
 * @module apps
 * @proto byte is_menu_range(ushort tok)
 * @confidence likely
 * @note 0x262BA 归一化后判断是否在 0x40..0x49 菜单码范围。
 * @tag parser
 */
byte is_menu_range(ushort tok)

{
  ushort uVar1;
  undefined2 uVar2;
  byte bVar3;
  byte bVar4;
  
  uVar1 = menu_code_map((byte)tok,(char)((ushort)tok >> 8));
  bVar4 = (byte)(uVar1 >> 8);
  bVar3 = (byte)uVar1;
  if (((uVar1 < 0x42) ||
      (uVar1 = (ushort)bVar4 - (ushort)(bVar3 < 0x49),
      (uVar1 & 0x100) == 0 && (bVar3 != 0x49 || (char)uVar1 != '\0'))) &&
     (bVar3 != 0x40 || (bool)bVar4 != bVar3 < 0x40)) {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}

/**
 * @brief 按当前模式清行缓冲
 * @addr 0x2A99C
 * @module apps
 * @proto void buffer_reset_for_mode(undefined2 er0)
 * @confidence likely
 * @note 按当前模式清行缓冲；模式 C1/2/C4/89 时连 0xD392 的 400 字节一起清。
 * @tag ui
 */
int buffer_reset_for_mode(undefined2 er0)

{
  undefined *puVar1;
  
  puVar1 = (undefined *)((ushort)calc_mode << 8);
  kbd_repeat = 0;
  if ((((calc_mode == 0xc1) || (calc_mode == 2)) || (calc_mode == 0xc4)) ||
     (calc_mode == 0x89)) {
    er0 = 400;
    puVar1 = (undefined *)memzero(&stat_data,400);
  }
  clear_replay_buf(puVar1,er0);
  return 0;
}

/**
 * @brief 按 0xD13F 写格式化缓冲区[0]=0x88/0xAC、[1]=0，返回 buf
 * @addr 0x2A9CC
 * @module apps
 * @proto byte* fmt_buf_init(byte* buf)
 * @confidence likely
 * @note 按 0xD13F 写格式化缓冲区[0]=0x88/0xAC、[1]=0，返回 buf。
 * @tag format
 */
byte* fmt_buf_init(byte* buf)

{
  undefined uVar1;
  
  if (disp_mode == '\0') {
    uVar1 = 0x88;
  }
  else {
    uVar1 = 0xac;
  }
  *buf = uVar1;
  buf[1] = 0;
  return buf;
}

/**
 * @brief 渲染上下文判定
 * @addr 0x2A9EA
 * @module apps
 * @proto byte is_list_render_ctx(char mode)
 * @confidence likely
 * @note 渲染上下文判定：模式 2 直接为真，否则要求调用点为列表元素 4。
 * @tag ui
 */
byte is_list_render_ctx(char mode)

{
  char cVar1;
  undefined uVar2;
  
  cVar1 = is_v2_02(mode);
  if (cVar1 == '\0') {
    if (mode == '\x04') {
      uVar2 = 1;
    }
    else {
      uVar2 = 0;
    }
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}

/**
 * @brief 按键 0x20 的处理入口
 * @addr 0x2AA5C
 * @module apps
 * @proto undefined2 key_jump_20(undefined2 er0, char flag)
 * @confidence likely
 * @note 按键 0x20 的处理入口：flag 为 0 走 0x2100E，否则走 0x20FC6。
 * @tag key
 */
undefined2 key_jump_20(undefined2 er0, char flag)

{
  if (flag == '\0') {
    str_emit_1DB3();
  }
  else {
    str_emit_1D8B();
  }
  return er0;
}

/**
 * @brief 按 0xD112 绘制列表表头（"=0" 等固定串）
 * @addr 0x2AB3E
 * @module apps
 * @proto void draw_list_header(void)
 * @confidence likely
 * @note 按 0xD112 绘制列表表头（"=0" 等固定串）。
 * @tag ui
 */
int draw_list_header(void)

{
  short unaff_ER14;
  
  frame_enter();
  if ((byte)(sub_mode - 4U) < 2) {
    strcpy_checked((char *)(unaff_ER14 + -0x12), (uintptr_t)0)
                   *(char **)(&_DAT_ram_38fc + (ushort)(byte)(sub_mode - 4U) * 2));
    strcat_checked((char *)(unaff_ER14 + -0x12),"=0");
  }
  else {
    strcpy_checked((char *)(unaff_ER14 + -0x12),_DAT_ram_391a);
  }
  draw_string(0x100,unaff_ER14 + -0x12);
  frame_leave();
  return 0;
}

/**
 * @brief 按键 0x1E 的处理入口
 * @addr 0x2AB8A
 * @module apps
 * @proto undefined2 key_jump_1e(undefined2 er0, char flag)
 * @confidence likely
 * @note 按键 0x1E 的处理入口：flag 为 0 走 0x21006，否则走 0x20FBE。
 * @tag key
 */
undefined2 key_jump_1e(undefined2 er0, char flag)

{
  if (flag == '\0') {
    str_emit_ltx();
  }
  else {
    str_emit_1D86();
  }
  return er0;
}

/**
 * @brief 把光标模式置 8，并按 0xD111 从 ROM 0x24C 或 0x67EA 表绘制第 i…
 * @addr 0x2ABA4
 * @module apps
 * @proto void render_sel_label(ushort i)
 * @confidence likely
 * @note 把光标模式置 8，并按 0xD111 从 ROM 0x24C 或 0x67EA 表绘制第 i 个标签。
 * @tag ui
 */
int render_sel_label(ushort i)

{
  cur_line = 8;
  if (calc_mode == '\x06') {
    draw_string(0x200,*(undefined2 *)((ushort)i * 2 + 0x24c));
  }
  else {
    draw_string(0x200,*(undefined2 *)((ushort)i * 2 + 0x67ea));
  }
  return 0;
}

/**
 * @brief 返回显示忙标志（0xD110 的 bit7）
 * @addr 0x2ABE2
 * @module apps
 * @proto byte disp_busy(void)
 * @confidence strong
 * @note 返回显示忙标志（0xD110 的 bit7）。
 * @tag ui
 */
byte disp_busy(void)

{
  return (status_bits & 0x80) != 0;
}

/**
 * @brief 刷新当前行（1.3KB，0x975A/0x98C6 使用）
 * @addr 0x2AC7C
 * @module apps
 * @proto void row_refresh(void)
 * @confidence likely
 * @note 刷新当前行（1.3KB，0x975A/0x98C6 使用）。
 * @tag app
 */
int row_refresh(void)

{
  char cVar1;
  byte bVar2;
  byte *pbVar3;
  char *pcVar4;
  byte bVar5;
  
  frame_enter();
  cVar1 = calc_mode;
  pbVar3 = history_base_ptr();
  bVar5 = menu_index;
  if ((pbVar3 != (byte *)0x0) && (menu_index != 0)) {
    bVar2 = table_row_count();
    kbd_repeat = 0;
    if ((bVar5 != 1) || ((((bVar2 < 2 && (cVar1 != 'E')) && (cVar1 != 'J')) && (cVar1 != '\f')))) {
      kbd_repeat = 1;
    }
    if (bVar5 < bVar2) {
      kbd_repeat = kbd_repeat | 2;
    }
    stat_state_reset();
    input_init();
    for (bVar2 = 1; bVar2 <= (byte)(bVar5 - 1); bVar2 = bVar2 + 1) {
      pbVar3 = (byte *)input_mark_hash();
    }
    bVar2 = *pbVar3;
    bVar5 = 10;
    if ((bVar2 & 0x80) != 0) {
      bVar5 = 0x14;
    }
    key_hist_write(pbVar3[1]);
    key_hist_b = pbVar3[2];
    memcpy_bytes((undefined *)0xd16c,pbVar3 + 3,(ushort)bVar5);
    pbVar3 = pbVar3 + 3 + bVar5;
    if (bVar5 == 10) {
      dec_set_uint_small((ushort *)0xd176,0);
    }
    key_modifiers = 0x23;
    key_history_flags = bVar2 & 0x7f;
    pcVar4 = strchr((char *)pbVar3,'#');
    bVar5 = (char)pcVar4 - (char)pbVar3;
    memcpy_bytes(&input_buf,pbVar3,(ushort)bVar5);
    (&input_buf)[bVar5] = 0;
    if (((cVar1 == 'E') || (cVar1 == 'J')) || (cVar1 == '\f')) {
      key_dispatch_menu();
    }
  }
  frame_leave();
  return 0;
}

/**
 * @brief 表格恢复/撤销（1.3KB，无外部调用者）
 * @addr 0x2AD7A
 * @module apps
 * @proto void table_restore(void)
 * @confidence likely
 * @note 表格恢复/撤销（1.3KB，无外部调用者）。
 * @tag app
 */
int table_restore(void)

{
  char cVar1;
  byte bVar2;
  ushort uVar3;
  char cVar4;
  ushort uVar5;
  ushort uVar6;
  
  cVar1 = frame_enter();
  uVar6 = 0x30;
  uVar5 = 0x39;
  cur_line = 0xe;
  draw_target = 0;
  if (cVar1 == '\x06') {
    draw_format_string(0x3100,(char *)0x5564);
  }
  else if (cVar1 == '\a') {
    draw_format_string(0x3100,(char *)0x1a5c);
  }
  else {
    uVar6 = 0x31;
    uVar5 = 0x32;
    draw_format_string(0x3100,(char *)0x67aa);
  }
  fb_alt_flush();
  show_press_ac();
  draw_target = 1;
  while( true ) {
    uVar3 = input_is_empty();
    bVar2 = (byte)uVar3;
    cVar4 = (char)(uVar3 >> 8);
    if ((uVar6 <= uVar3) && (uVar3 <= uVar5)) break;
    if (((bVar2 == 0x25 && (bool)(cVar4 + '\x04') == bVar2 < 0x25) ||
        (bVar2 == 0x26 && (bool)(cVar4 + '\x04') == bVar2 < 0x26)) ||
       (bVar2 == 0x1f && (bool)(cVar4 + '\x04') == bVar2 < 0x1f)) goto LAB_rom_02adba;
  }
  if (cVar1 == '\x06') {
    menu_sel_a = 8;
    _DAT_ram_d11b = bVar2 & 0xf;
  }
  else if (cVar1 == '\a') {
    menu_sel_a = 9;
    _DAT_ram_d11b = bVar2 & 0xf;
  }
  else if (cVar1 == '\b') {
    if (bVar2 == 0x31 && (bool)cVar4 == bVar2 < 0x31) {
      menu_sel_a = 0;
    }
    else {
      menu_sel_a = 4;
    }
  }
LAB_rom_02adba:
  frame_leave();
  return 0;
}

/**
 * @brief 表格删除（4.1KB，0x15650 调用）
 * @addr 0x2AE46
 * @module apps
 * @proto int table_delete(void)
 * @confidence likely
 * @note 表格删除（4.1KB，0x15650 调用）。
 * @tag app
 */
int table_delete(uintptr_t _a2, int _a1)

{
  bool bVar1;
  undefined2 *puVar2;
  undefined2 uVar3;
  char cVar4;
  undefined2 uVar5;
  undefined2 *puVar6;
  undefined2 *puVar7;
  undefined2 *puVar8;
  short unaff_ER14;
  
  puVar2 = (undefined2 *)frame_enter();
  cVar4 = (char)_a1;
  *(undefined *)(unaff_ER14 + -0x15) = 0;
  *(undefined2 *)(unaff_ER14 + -8) = 0xd7f2;
  *(undefined2 *)(unaff_ER14 + -0x14) = 0xd7fc;
  *(undefined2 *)(unaff_ER14 + -0x12) = 0xd806;
  *(undefined2 *)(unaff_ER14 + -0x10) = 0xd810;
  *(undefined2 *)(unaff_ER14 + -0xe) = 0xd81a;
  *(undefined2 *)(unaff_ER14 + -0xc) = 0xd824;
  *(undefined2 *)(unaff_ER14 + -10) = 0xd82e;
  puVar7 = (undefined2 *)0xd842;
  uVar5 = 0xd856;
  *(undefined2 *)(unaff_ER14 + -2) = 0xd860;
  *(undefined2 *)(unaff_ER14 + -6) = 0xd86a;
  *(undefined2 *)(unaff_ER14 + -4) = 0xd874;
  uVar3 = dec_cmp((undefined2 *)0xd824,_a1);
  if ((char)uVar3 == '\x02') goto LAB_rom_02b004;
  uVar3 = dec_cmp(*(undefined2 **)(unaff_ER14 + -10),_a1);
  bVar1 = (char)uVar3 == '\x02';
  dec_copy((undefined2 *)0xd842,*(undefined2 **)(unaff_ER14 + -0xc));
  dec_set_uint_small((ushort *)0xd856,6);
  dec_add_or_round((undefined2 *)0xd842,(undefined2 *)0xd856);
  dec_round((undefined2 *)0xd842,uVar5);
  dec_cmp_ex((undefined2 *)0xd842,uVar5);
  puVar6 = puVar7;
  dec_copy((undefined2 *)0xd84c,(undefined2 *)0xd842);
  if (bVar1) {
    dec_inc5((undefined2 *)0xd842,puVar6);
  }
  else {
    dec_inc5((undefined2 *)0xd84c,puVar6);
  }
  dec_set_uint_small((ushort *)0xd856,3);
  dec_bin_pow((undefined2 *)0xd84c,(undefined2 *)0xd856);
  dec_bin_mul((undefined2 *)0xd842,*(undefined2 **)(unaff_ER14 + -8));
  dec_bin_mul((undefined2 *)0xd84c,*(undefined2 **)(unaff_ER14 + -8));
  if (cVar4 == '\0') {
    puVar6 = puVar7;
    dec_copy((undefined2 *)0xd856,(undefined2 *)0xd842);
    dec_xy_sub((undefined2 *)0xd856,puVar6);
    dec_copy(*(undefined2 **)(unaff_ER14 + -2),(undefined2 *)0xd856);
    dec_bin_pow((undefined2 *)0xd856,(undefined2 *)0xd842);
    dec_bin_pow((undefined2 *)0xd856,(undefined2 *)0xd84c);
    puVar6 = *(undefined2 **)(unaff_ER14 + -0xe);
    dec_bin_mul((undefined2 *)0xd856,puVar6);
    uVar3 = dec_cmp((undefined2 *)0xd856,puVar6);
    if ((char)uVar3 != '\x01') goto LAB_rom_02b004;
    dec_set_uint_small(*(ushort **)(unaff_ER14 + -4),3);
    dec_bin_pow(*(undefined2 **)(unaff_ER14 + -4),(undefined2 *)0xd84c);
    dec_bin_div(*(undefined2 **)(unaff_ER14 + -4),(undefined2 *)0xd842);
    dec_bin_pow(*(undefined2 **)(unaff_ER14 + -4),*(undefined2 **)(unaff_ER14 + -2));
    puVar6 = *(undefined2 **)(unaff_ER14 + -0x10);
    dec_bin_div(*(undefined2 **)(unaff_ER14 + -4),puVar6);
    uVar3 = dec_cmp(*(undefined2 **)(unaff_ER14 + -4),puVar6);
    if ((char)uVar3 != '\x01') goto LAB_rom_02b004;
    dec_copy(*(undefined2 **)(unaff_ER14 + -6),(undefined2 *)0xd842);
    dec_bin_div(*(undefined2 **)(unaff_ER14 + -6),(undefined2 *)0xd84c);
    dec_set_uint_small(*(ushort **)(unaff_ER14 + -2),3);
    dec_bin_pow(*(undefined2 **)(unaff_ER14 + -2),(undefined2 *)0xd842);
    dec_bin_pow(*(undefined2 **)(unaff_ER14 + -6),*(undefined2 **)(unaff_ER14 + -2));
    puVar6 = *(undefined2 **)(unaff_ER14 + -0x12);
    dec_bin_mul(*(undefined2 **)(unaff_ER14 + -6),puVar6);
    uVar3 = dec_cmp(*(undefined2 **)(unaff_ER14 + -6),puVar6);
    if ((char)uVar3 != '\x01') goto LAB_rom_02b004;
    dec_bin_div(*(undefined2 **)(unaff_ER14 + -2),(undefined2 *)0xd84c);
    puVar6 = *(undefined2 **)(unaff_ER14 + -0x14);
    dec_bin_div(*(undefined2 **)(unaff_ER14 + -2),puVar6);
    uVar3 = dec_cmp(*(undefined2 **)(unaff_ER14 + -2),puVar6);
    if ((char)uVar3 != '\x01') goto LAB_rom_02b004;
  }
  *(undefined *)(unaff_ER14 + -0x15) = 2;
  puVar6 = puVar7;
  puVar8 = (undefined2 *)0xd84c;
  if (bVar1) {
    puVar6 = (undefined2 *)0xd84c;
    puVar8 = puVar7;
  }
  dec_copy(puVar2,puVar6);
  dec_copy(puVar2 + 0x14,puVar8);
LAB_rom_02b004:
  frame_leave();
  return 0;
}

