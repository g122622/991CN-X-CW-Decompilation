/*
 * 应用模式 / 26002_draw_scroll_grid.c
 * 地址范围: 0x26002 - 0x26784
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 绘制可滚动网格（1KB）
 * @addr 0x26002
 * @module apps
 * @proto void draw_scroll_grid(void)
 * @confidence likely
 * @note 绘制可滚动网格（1KB）。
 * @tag app
 */
int draw_scroll_grid(void)

{
  char cVar1;
  byte bVar2;
  undefined2 uVar3;
  char cVar4;
  
  cVar1 = frame_enter();
  cur_line = 0xe;
  draw_target = 0;
  if (cVar1 == '.') {
    draw_text4x(0x5a48);
  }
  else if (cVar1 == '/') {
    draw_text4x(0x3d4e);
  }
  fb_alt_flush();
  show_press_ac();
  draw_target = 1;
  while( true ) {
    uVar3 = input_is_empty();
    bVar2 = (byte)uVar3;
    cVar4 = (char)((ushort)uVar3 >> 8);
    if ((bVar2 == 0x31 && (bool)cVar4 == bVar2 < 0x31) ||
       (bVar2 == 0x32 && (bool)cVar4 == bVar2 < 0x32)) break;
    if (((bVar2 == 0x25 && (bool)(cVar4 + '\x04') == bVar2 < 0x25) ||
        (bVar2 == 0x26 && (bool)(cVar4 + '\x04') == bVar2 < 0x26)) ||
       (bVar2 == 0x1f && (bool)(cVar4 + '\x04') == bVar2 < 0x1f)) goto LAB_rom_02606e;
    beep();
  }
  if (cVar1 == '.') {
    _DAT_ram_d12c = bVar2 == 0x31 && (bool)cVar4 == bVar2 < 0x31;
  }
  else if (cVar1 == '/') {
    _DAT_ram_d12d = bVar2 != 0x31 || (bool)cVar4 != bVar2 < 0x31;
  }
LAB_rom_02606e:
  frame_leave();
  return 0;
}

/**
 * @brief 按 0x1D800 结果初始化变量槽（0xD118/0xD166/0xD14E）并调用 0x…
 * @addr 0x26184
 * @module apps
 * @proto int var_slot_init(void)
 * @confidence likely
 * @note 按 0x1D800 结果初始化变量槽（0xD118/0xD166/0xD14E）并调用 0x23780。
 * @tag var
 */
int var_slot_init(uintptr_t _a2, int _a1)

{
  byte bVar1;
  byte bVar2;
  byte *pbVar3;
  
  pbVar3 = (byte *)frame_enter();
  bVar2 = bcd_type(pbVar3);
  bVar1 = _DAT_ram_d166;
  if ((bVar2 == 0) && (pbVar3 != (byte *)0x0)) {
    key_hist_a = key_hist_a >> 4;
    if ((key_hist_a == 0xf) || (key_hist_a == 0xe)) {
      key_hist_a = 0;
    }
    mixed_fraction = 1;
    _DAT_ram_d166 = _DAT_ram_d166 & 0xfd;
    edit_render_content(_a1);
    mixed_fraction = 0;
    _DAT_ram_d166 = bVar1;
    strlen_checked((char *)_a1);
  }
  frame_leave();
  return 0;
}

/**
 * @brief 单一 token 时返回 0x15E4E 的类别判定结果
 * @addr 0x261EA
 * @module apps
 * @proto undefined token_class_of(byte* tok)
 * @confidence likely
 * @note 单一 token 时返回 0x15E4E 的类别判定结果。
 * @tag parser
 */
undefined token_class_of(byte* _a1)

{
  byte *pbVar1;
  undefined2 uVar2;
  ushort uVar3;
  
  pbVar1 = (byte *)frame_enter();
  uVar2 = token_class((char *)pbVar1);
  if ((char)uVar2 == '\0') {
    uVar3 = token_at(pbVar1);
    is_token_3(uVar3);
  }
  frame_leave();
  return;
}

/**
 * @brief 返回字符串中到扩展字符前的长度
 * @addr 0x26226
 * @module apps
 * @proto char strline_len(char* s)
 * @confidence likely
 * @note 返回字符串中到扩展字符前的长度。
 * @tag libc
 */
char strline_len(char* s)

{
  char cVar1;
  
  cVar1 = '\0';
  for (; *s != '\0'; s = s + 1) {
    cVar1 = cVar1 + '\x01';
  }
  return cVar1;
}

/**
 * @brief 统计表复位
 * @addr 0x2623C
 * @module apps
 * @proto void stat_table_reset(void)
 * @confidence strong
 * @note 统计表复位：调用 0x96E8 与 0x8FC6（清修饰键/状态）。
 * @tag stat
 */
int stat_table_reset(void)

{
  cursor_home();
  key_mod_clear();
  return 0;
}

/**
 * @brief 判断 0xE 模块下是否处于列表/矩阵视图
 * @addr 0x2627A
 * @module apps
 * @proto byte is_matrix_list(void)
 * @confidence likely
 * @note 判断 0xE 模块下是否处于列表/矩阵视图。
 * @tag matrix
 */
byte is_matrix_list(void)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  undefined uVar4;
  
  bVar2 = menu_index;
  uVar4 = 0;
  if ((sub_mode == '\x04') && (calc_mode == 'E')) {
    uVar4 = 0;
    bVar3 = table_row_count();
    bVar1 = -(bVar3 < bVar2) - (bVar3 == bVar2);
    if ((byte)((byte)((bVar1 ^ -(bVar3 < bVar2)) & ~bVar1) >> 7 ^ (char)bVar1 < '\0' |
              ((byte)(bVar3 - bVar2) == '\x01' && bVar1 == 0)) != 0) {
      uVar4 = 1;
    }
  }
  return uVar4;
}

/**
 * @brief 返回 a、b 中较大者
 * @addr 0x262B0
 * @module apps
 * @proto undefined2 max_u16(undefined2 a, undefined2 b)
 * @confidence verified
 * @note 返回 a、b 中较大者。
 * @tag util
 */
undefined2 max_u16(undefined2 a, undefined2 b)

{
  if (b < a) {
    return a;
  }
  return b;
}

/**
 * @brief 把菜单键码（0x77/0x78/0x79 等）映射成菜单项码（0x45/0x46/0x47）
 * @addr 0x262BA
 * @module apps
 * @proto ushort menu_code_map(byte k)
 * @confidence strong
 * @note 把菜单键码（0x77/0x78/0x79 等）映射成菜单项码（0x45/0x46/0x47）。
 * @tag ui
 */
ushort menu_code_map(byte k, int _a2)

{
  if (k == 0x77 && (bool)_a2 == k < 0x77) {
    return 0x45;
  }
  if (k == 0x78 && (bool)_a2 == k < 0x78) {
    return 0x46;
  }
  if (k == 0x79 && (bool)_a2 == k < 0x79) {
    return 0x47;
  }
  if (k == 0xc0 && (bool)_a2 == k < 0xc0) {
    return 0x42;
  }
  if (k == 0xd0 && (bool)_a2 == k < 0xd0) {
    return 0x48;
  }
  if (k == 0x2e && (bool)(_a2 + '\x04') == k < 0x2e) {
    return 0x40;
  }
  if (k == 0x36 && (bool)(_a2 + '\x04') == k < 0x36) {
    return 0x43;
  }
  if (k != 0x3a || (bool)(_a2 + '\x04') != k < 0x3a) {
    if (k != 0x54 || (bool)(_a2 + '\x04') != k < 0x54) {
      return CONCAT11(_a2,k);
    }
    return 0x44;
  }
  return 0x49;
}

/**
 * @brief 调用 0xE21E，返回 3 时清 0xD10E，随后 0x1F6C6 刷新
 * @addr 0x26332
 * @module apps
 * @proto void list_close_entry(void)
 * @confidence likely
 * @note 调用 0xE21E，返回 3 时清 0xD10E，随后 0x1F6C6 刷新。
 * @tag ui
 */
int list_close_entry(void)

{
  int cVar1;
  undefined2 uVar2;
  short unaff_ER14;
  
  uVar2 = frame_enter();
  *(undefined2 *)(unaff_ER14 + -2) = uVar2;
  cVar1 = edit_loop();
  if (cVar1 == '\x03') {
    input_key = 0;
  }
  else {
    *(undefined2 *)(unaff_ER14 + -2) = 0;
  }
  mode_switch_refresh();
  frame_leave();
  return 0;
}

/**
 * @brief 按 0x28C10 选择子视图（2/3/6/7/E/J/K）并打开十六进制/进制视图
 * @addr 0x263C8
 * @module apps
 * @proto void open_hex_view(undefined2 er0)
 * @confidence likely
 * @note 按 0x28C10 选择子视图（2/3/6/7/E/J/K）并打开十六进制/进制视图。
 * @tag ui
 */
int open_hex_view(undefined2 er0)

{
  int cVar1;
  
  cVar1 = menu_router_main();
  if ((cVar1 != '\0') && (cVar1 != -1)) {
    kbd_repeat = 0;
    buffer_reset_for_mode(er0);
    if (cVar1 == '\x02') {
      mode_switch_refresh();
    }
    else if (cVar1 == '\x03') {
      matrix_mode_key('\x01');
      mode_switch_refresh();
    }
    else if (cVar1 == '\x06') {
      sidebar_menu('\x01');
    }
    else if (cVar1 == '\a') {
      sidebar_menu('\x01');
    }
    else if (cVar1 == 'E') {
      menu_eb15_loop();
      mode_switch_refresh();
    }
    else if (cVar1 == 'J') {
      list_close_entry();
    }
    else if (cVar1 == 'K') {
      list_mode_loop('\x01');
    }
    else {
      mode_switch_refresh();
    }
  }
  return cVar1;
}

/**
 * @brief 0xD111 == 0x0C 且 0xD114 == 1 时返回 1
 * @addr 0x2646C
 * @module apps
 * @proto char is_mode_0c(void)
 * @confidence strong
 * @note 0xD111 == 0x0C 且 0xD114 == 1 时返回 1。
 * @tag mode
 */
char is_mode_0c(void)

{
  if ((calc_mode == '\f') && (edit_state2 == '\x01')) {
    return 1;
  }
  return 0;
}

/**
 * @brief 0xD015 为 1 或 3 时返回 1（编辑/撤销状态的当前值判定）
 * @addr 0x26594
 * @module apps
 * @proto char is_d015_1_3(void)
 * @confidence strong
 * @note 0xD015 为 1 或 3 时返回 1（编辑/撤销状态的当前值判定）。
 * @tag ui
 */
char is_d015_1_3(void)

{
  if ((edit_state != '\x01') && (edit_state != '\x03')) {
    return 0;
  }
  return 1;
}

/**
 * @brief 以 er0 调用 0x22B82（主循环入口）
 * @addr 0x265A8
 * @module apps
 * @proto void call_22b82(short er0)
 * @confidence likely
 * @note 以 er0 调用 0x22B82（主循环入口）。
 * @tag ui
 */
int call_22b82(short er0)

{
  frame_enter();
  stat_edit_entry(er0);
  frame_leave();
  return 0;
}

/**
 * @brief 统计行编辑（1.7KB，0x1F25A/0x22A8C 使用）
 * @addr 0x26610
 * @module apps
 * @proto int stat_row_edit(byte k)
 * @confidence likely
 * @note 统计行编辑（1.7KB，0x1F25A/0x22A8C 使用）。
 * @tag app
 */
int stat_row_edit(byte k, int _a2)

{
  bool bVar1;
  byte bVar2;
  byte bVar3;
  
  bVar2 = frame_enter();
  bVar1 = true;
  bVar3 = list_col;
  if (k == 0x1c && (bool)(_a2 + '\x04') == k < 0x1c) {
    if (1 < list_col) {
      bVar3 = list_col - 1;
      bVar1 = false;
      list_col = bVar3;
    }
  }
  else if (k == 0x1d && (bool)(_a2 + '\x04') == k < 0x1d) {
    bVar3 = *(byte *)((ushort)bVar2 * 2 + -0x2f08);
    if (list_col < bVar3) {
      bVar1 = false;
      bVar3 = list_col + 1;
      list_col = list_col + 1;
    }
  }
  else {
    if (k != 0x1e || (bool)(_a2 + '\x04') != k < 0x1e) {
      if (k == 0x1f && (bool)(_a2 + '\x04') == k < 0x1f) {
        if (list_row < 2) {
          if (list_col < 2) goto LAB_rom_026638;
          list_col = list_col - 1;
          list_row = *(byte *)((ushort)bVar2 * 2 + -0x2f07);
        }
        else {
          list_row = list_row - 1;
        }
        bVar1 = false;
        bVar3 = list_row;
        goto LAB_rom_026638;
      }
      bVar3 = bVar2;
      if (k != 0x2d || (bool)(_a2 + '\x04') != k < 0x2d) goto LAB_rom_026638;
    }
    if (list_row < *(byte *)((ushort)bVar2 * 2 + -0x2f07)) {
      list_row = list_row + 1;
    }
    else {
      bVar3 = *(byte *)((ushort)bVar2 * 2 + -0x2f08);
      if (bVar3 <= list_col) goto LAB_rom_026638;
      list_col = list_col + 1;
      list_row = 1;
    }
    bVar1 = false;
    bVar3 = list_row;
  }
LAB_rom_026638:
  if (!bVar1) {
    key_hist_clear0(bVar3);
  }
  frame_leave();
  return 0;
}

/**
 * @brief 在 (x, 0xA0+R) 处绘制字段（0x2682E 给出 R）
 * @addr 0x266E0
 * @module apps
 * @proto void draw_field_y(char x)
 * @confidence likely
 * @note 在 (x, 0xA0+R) 处绘制字段（0x2682E 给出 R）。
 * @tag ui
 */
int draw_field_y(char x)

{
  int cVar1;
  undefined2 uVar2;
  
  uVar2 = frame_enter();
  cVar1 = draw_result_line();
  draw_text4x(CONCAT11(x,-0x40 - cVar1),uVar2);
  frame_leave();
  return 0;
}

/**
 * @brief 分数格式化（a/b 与 d/c 两种显示）
 * @addr 0x26700
 * @module apps
 * @proto void str_format_frac(void)
 * @confidence likely
 * @note 分数格式化（a/b 与 d/c 两种显示）。
 * @tag format
 */
int str_format_frac(uintptr_t _a2, int _a1)

{
  char cVar1;
  undefined *puVar2;
  ushort uVar3;
  byte bVar4;
  short unaff_ER14;
  
  puVar2 = (undefined *)frame_enter();
  cVar1 = is_idle_editing();
  if (cVar1 != '\0') {
    for (bVar4 = 0; (char)((bVar4 < *(byte *)(unaff_ER14 + 0x10)) << 7) < '\0'; bVar4 = bVar4 + 1) {
      uVar3 = addr_norm((ushort)puVar2);
      if ((char)uVar3 != '\0') {
        *puVar2 = *(undefined *)((ushort)bVar4 * 3 + _a1);
      }
      uVar3 = addr_norm((ushort)puVar2);
      if ((char)uVar3 != '\0') {
        puVar2[1] = *(undefined *)((ushort)bVar4 * 3 + _a1 + 1);
      }
      uVar3 = addr_norm((ushort)puVar2);
      if ((char)uVar3 != '\0') {
        puVar2[2] = *(undefined *)((ushort)bVar4 * 3 + _a1 + 2);
      }
      if (draw_target == '\0') {
        puVar2 = puVar2 + 0x20;
      }
      else {
        puVar2 = puVar2 + 0x18;
      }
    }
  }
  frame_leave();
  return 0;
}

/**
 * @brief 编辑菜单循环（1.4KB）
 * @addr 0x26784
 * @module apps
 * @proto void edit_menu_loop(void)
 * @confidence likely
 * @note 编辑菜单循环（1.4KB）。
 * @tag ui
 */
int edit_menu_loop(int _a1)

{
  char cVar1;
  byte bVar2;
  byte *pbVar3;
  undefined2 uVar4;
  char cVar5;
  byte bVar6;
  short unaff_ER14;
  
  pbVar3 = (byte *)frame_enter();
  *_a1 = 0;
  uVar4 = is_two_byte_char((char *)pbVar3);
  cVar5 = (char)uVar4;
  cVar1 = get_token_class(pbVar3);
  if (((cVar1 != '\x02') && (cVar1 != '\x04')) && (cVar5 == '\0')) {
LAB_rom_0267c0:
    frame_leave();
    return 0;
  }
  if (cVar1 == '\x04') {
    *_a1 = 1;
  }
  do {
    while( true ) {
      if (((pbVar3 == &input_buf) ||
          (pbVar3 = (byte *)table_paste((undefined *)(unaff_ER14 + -1)), pbVar3 == (byte *)0x0))
         || ((cVar1 = get_token_class(pbVar3), cVar1 != '\x02' && (cVar1 != '\x04'))))
      goto LAB_rom_0267c0;
      if (cVar1 != '\x02') break;
      if ((cVar5 != '\0') || (*(char *)(unaff_ER14 + -1) != '\0')) goto LAB_rom_0267c0;
    }
    if (cVar5 != '\0') {
      *_a1 = 1;
      if (*(char *)(unaff_ER14 + -1) == '\x02') goto LAB_rom_0267c0;
      cVar5 = '\0';
    }
    if (*(char *)(unaff_ER14 + -1) != '\0') {
      *(char *)(unaff_ER14 + -1) = *(char *)(unaff_ER14 + -1) + -1;
    }
    for (bVar6 = 0; bVar6 <= *(byte *)(unaff_ER14 + -1); bVar6 = bVar6 + 1) {
      bVar2 = token_scan(bVar6);
      uVar4 = is_two_byte_char((char *)(pbVar3 + bVar2));
      if ((char)uVar4 == '\0') goto LAB_rom_0267c0;
    }
  } while( true );
}

