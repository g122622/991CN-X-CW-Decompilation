/*
 * 键盘与菜单 / 1fbe4_draw_prompt_pair.c
 * 地址范围: 0x1FBE4 - 0x1FFF6
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 绘制输入/提示对（0x203C2/0x20E5A）
 * @addr 0x1FBE4
 * @module kbd_menu
 * @proto void draw_prompt_pair(void)
 * @confidence likely
 * @note 绘制输入/提示对（0x203C2/0x20E5A）。
 * @tag ui
 */
int draw_prompt_pair(void)

{
  undefined uVar1;
  byte bVar2;
  char cVar4;
  char *pcVar3;
  undefined2 unaff_ER14;
  
  frame_enter();
  bVar2 = (byte)unaff_ER14;
  cVar4 = (char)((ushort)unaff_ER14 >> 8);
  strcpy_checked((char *)CONCAT11(cVar4 + -1 + (199 < bVar2),bVar2 + 0x38),&input_buf);
  uVar1 = history_cursor;
  pcVar3 = (char *)input_history_ptr();
  strcpy_checked(&input_buf,pcVar3);
  history_cursor = input_saved;
  pcVar3 = (char *)input_history_ptr();
  strcpy_checked(pcVar3,(char *)CONCAT11(cVar4 + -1 + (199 < bVar2),bVar2 + 0x38));
  input_saved = uVar1;
  frame_leave();
  return 0;
}

/**
 * @brief 按 0xD116/0xD13E 决定选择模式（0 或 2）并调用 0x23CCE
 * @addr 0x1FC7C
 * @module kbd_menu
 * @proto void set_sel_mode(undefined2 v)
 * @confidence likely
 * @note 按 0xD116/0xD13E 决定选择模式（0 或 2）并调用 0x23CCE。
 * @tag ui
 */
int set_sel_mode(undefined2 v)

{
  char cVar1;
  
  cVar1 = '\0';
  if ((key_modifiers != '\x01') && (history_dirty != '\0')) {
    cVar1 = '\x02';
  }
  mode_state_init(v,cVar1);
  return 0;
}

/**
 * @brief c == 0 时追加 ")"，否则追加 ROM 0x1D3D 记号串
 * @addr 0x1FCA4
 * @module kbd_menu
 * @proto void str_emit_lparen_or_1D3D(undefined2 v, byte c)
 * @confidence likely
 * @note c == 0 时追加 ")"，否则追加 ROM 0x1D3D 记号串。
 * @tag text
 */
int str_emit_lparen_or_1D3D(undefined2 v, byte c)

{
  if (c == '\0') {
    str_emit_rparen();
  }
  else {
    str_emit_1D3D();
  }
  return v;
}

/**
 * @brief 按模式绘制主界面（1.3KB，0x2209E/0x288EE 调用）
 * @addr 0x1FCBE
 * @module kbd_menu
 * @proto void mode_paint(void)
 * @confidence likely
 * @note 按模式绘制主界面（1.3KB，0x2209E/0x288EE 调用）。
 * @tag ui
 */
int mode_paint(void)

{
  char cVar1;
  byte bVar2;
  undefined2 uVar3;
  char cVar4;
  byte bVar5;
  byte bVar6;
  byte bVar7;
  short unaff_ER14;
  
  cVar1 = frame_enter();
  bVar5 = contrast;
  bVar7 = 0x1f;
  bVar6 = 0xb;
  if (cVar1 == '\0') {
    draw_text4x(0x52fe);
    draw_target = 0;
    input_read_str((char *)(unaff_ER14 + -0x24));
    draw_scaled_char(0x21, (uintptr_t)0);
  }
  else {
    draw_text4x(0x5ac6);
    draw_target = 0;
    draw_scaled_char(0x21, (uintptr_t)0);
  }
  draw_scaled_char(0x31, (uintptr_t)0);
  fb_alt_flush();
  draw_target = 1;
  do {
    if (cVar1 != '\0') {
      bVar6 = 0;
      bVar7 = 0x2a;
      draw_hex_byte(bVar5);
    }
    uVar3 = input_is_empty();
    bVar2 = (byte)uVar3;
    cVar4 = (char)((ushort)uVar3 >> 8);
    if (bVar2 == 0x1f && (bool)(cVar4 + '\x04') == bVar2 < 0x1f) {
      if (bVar6 < bVar5) {
        key_flag_bit7();
        bVar5 = bVar5 - 1;
      }
      else {
        key_flag_clear();
      }
    }
    else if (bVar2 == 0x1e && (bool)(cVar4 + '\x04') == bVar2 < 0x1e) {
      if (bVar5 < bVar7) {
        key_flag_bit7();
        bVar5 = bVar5 + 1;
      }
      else {
        key_flag_clear();
      }
    }
    else if (bVar2 == 0x26 && (bool)(cVar4 + '\x04') == bVar2 < 0x26) {
      frame_leave();
      return 0;
    }
    contrast_set(bVar5);
    contrast = bVar5;
  } while( true );
}

/**
 * @brief 按 token 类别遍历（0x1ECFA 链）
 * @addr 0x1FD88
 * @module kbd_menu
 * @proto void token_class_scan(byte* p)
 * @confidence likely
 * @note 按 token 类别遍历（0x1ECFA 链）。
 * @tag parser
 */
int token_class_scan(byte* _a1)

{
  char cVar1;
  byte bVar2;
  byte *pbVar3;
  undefined2 uVar4;
  byte bVar5;
  
  pbVar3 = (byte *)frame_enter();
  cVar1 = get_token_class(pbVar3);
  if (cVar1 != '\x05') {
    bVar5 = 0;
    do {
      bVar2 = token_scan(bVar5);
      if ((bVar2 == 0) || (uVar4 = is_two_byte_char((char *)(pbVar3 + bVar2)), (char)uVar4 == '\0'))
      break;
      bVar5 = bVar5 + 1;
    } while (bVar5 < 3);
  }
  frame_leave();
  return 0;
}

/**
 * @brief 按键状态链（0xB830/0xAF3A/0xC2E2/0x1EBC8 判定）
 * @addr 0x1FE22
 * @module kbd_menu
 * @proto int key_state_chain(void)
 * @confidence likely
 * @note 按键状态链（0xB830/0xAF3A/0xC2E2/0x1EBC8 判定）。
 * @tag key
 */
int key_state_chain(void)

{
  byte bVar1;
  short sVar2;
  byte bVar3;
  
  sVar2 = key_is_14_02();
  if (((((char)sVar2 == '\0') && (sVar2 = is_key_1f_23(), (char)sVar2 == '\0')) &&
      (sVar2 = key_is_1a_04(), (char)sVar2 == '\0')) &&
     (sVar2 = key_is_11_04(), (char)sVar2 == '\0')) {
    bVar1 = (byte)input_key;
    bVar3 = (byte)((ushort)input_key >> 8);
    if ((bVar1 == 0x3e && (bool)(bVar3 + 4) == bVar1 < 0x3e) ||
       (bVar1 == 0x3f && (bool)(bVar3 + 4) == bVar1 < 0x3f)) {
      sVar2 = CONCAT11(bVar3,1);
    }
    else {
      sVar2 = (ushort)bVar3 << 8;
    }
  }
  else {
    sVar2 = CONCAT11((char)((ushort)sVar2 >> 8),1);
  }
  return sVar2;
}

/**
 * @brief 菜单滚动（1.3KB，0x975A/0x2B00A 使用）
 * @addr 0x1FE7E
 * @module kbd_menu
 * @proto void menu_scroll(void)
 * @confidence likely
 * @note 菜单滚动（1.3KB，0x975A/0x2B00A 使用）。
 * @tag ui
 */
int menu_scroll(void)

{
  ushort uVar1;
  char cVar2;
  byte bVar3;
  undefined2 uVar4;
  ushort uVar5;
  char cVar6;
  short unaff_ER14;
  
  cVar2 = frame_enter();
  uVar4 = keycode_norm(input_key);
  if ((char)uVar4 != '\0') {
    if (((stat_state == '\x03') && (calc_mode == 'E')) ||
       (bVar3 = bcd_type((byte *)0xd16c), bVar3 != 0)) {
      input_read_str((char *)(unaff_ER14 + -0x24));
    }
    else {
      bVar3 = (byte)input_key;
      if (bVar3 == 0x10 && (bool)((char)(input_key >> 8) + '\x04') == bVar3 < 0x10) {
        cVar6 = cVar2 + '=';
        uVar5 = input_key;
      }
      else {
        uVar5 = 0xfc12;
        if ((input_key < 0xfc12) ||
           (uVar1 = ((input_key >> 8) - 0xfc) - (ushort)(bVar3 < 0x17),
           (uVar1 & 0x100) == 0 && (bVar3 != 0x17 || (char)uVar1 != '\0'))) {
          cVar6 = cVar2 + -8;
        }
        else {
          cVar6 = cVar2 + '/';
        }
      }
      base_clear(CONCAT11((char)(uVar5 >> 8),cVar2 + -0x10),(undefined *)0xd16c);
      input_read_str((char *)(unaff_ER14 + -0x24));
      *(char *)(unaff_ER14 + -0x26) = cVar6;
      *(undefined *)(unaff_ER14 + -0x25) = 0;
      token_replace_all((char *)(unaff_ER14 + -0x26));
    }
    boot_splash(unaff_ER14 + -0x24);
  }
  frame_leave();
  return 0;
}

/**
 * @brief 列表模式切换（按 0xD112 与入参比较，刷新缓冲）
 * @addr 0x1FF2A
 * @module kbd_menu
 * @proto int set_list_mode(void)
 * @confidence likely
 * @note 列表模式切换（按 0xD112 与入参比较，刷新缓冲）。
 * @tag ui
 */
int set_list_mode(void)

{
  bool bVar1;
  char cVar2;
  
  cVar2 = frame_enter();
  bVar1 = false;
  if (sub_mode == '\x01') {
    bVar1 = false;
    if (cVar2 != '\x01') {
      bVar1 = true;
    }
  }
  else if (cVar2 == '\x01') {
    bVar1 = true;
  }
  if (bVar1) {
    draw_text4(0x4d60,0x576a,0x4f02,0x6686);
    cVar2 = wait_arrow_exit();
    if (cVar2 != '\0') {
      cursor_home_ui();
      key_mod_clear();
    }
  }
  frame_leave();
  return 0;
}

/**
 * @brief 复制 0xA0 字节，成功返回 1
 * @addr 0x1FF84
 * @module kbd_menu
 * @proto short memcpy160(byte* dst, byte* src)
 * @confidence verified
 * @note 复制 0xA0 字节，成功返回 1。
 * @tag libc
 */
short memcpy160(byte* dst, byte* src)

{
  undefined *puVar1;
  
  puVar1 = memcpy_bytes(dst,src,0xa0);
  return CONCAT11((char)((ushort)puVar1 >> 8),1);
}

/**
 * @brief 取列表项（0x8EF2）并在 0xD112 下标上做对比
 * @addr 0x1FF9E
 * @module kbd_menu
 * @proto void list_entry_fetch(void)
 * @confidence likely
 * @note 取列表项（0x8EF2）并在 0xD112 下标上做对比。
 * @tag ui
 */
int list_entry_fetch(uintptr_t _a2, int _a1)

{
  bool bVar1;
  ushort uVar2;
  undefined2 uVar3;
  short sVar4;
  short unaff_ER14;
  
  uVar2 = frame_enter();
  uVar3 = stat_cell_addr_ex(uVar2,(short *)(unaff_ER14 + -2));
  if ((char)uVar3 == '\0') {
    sVar4 = *(short *)(unaff_ER14 + -2);
    uVar2 = 8;
    do {
      *(undefined2 *)(sVar4 + 8) = *(undefined2 *)(_a1 + 8);
      _a1 = _a1 + -2;
      sVar4 = sVar4 + -2;
      bVar1 = 1 < uVar2;
      uVar2 = uVar2 - 2;
    } while ((char)(bVar1 << 7) < '\0');
  }
  frame_leave();
  return 0;
}

/**
 * @brief 返回 0x20D10() == 0 && (0xD111 & 0x80) != 0
 * @addr 0x1FFD0
 * @module kbd_menu
 * @proto char is_mode_high(void)
 * @confidence likely
 * @note 返回 0x20D10() == 0 && (0xD111 & 0x80) != 0。
 * @tag ui
 */
char is_mode_high(void)

{
  int cVar1;
  
  cVar1 = stat_view_event();
  if ((cVar1 == '\0') && ((calc_mode & 0x80) != 0)) {
    return 1;
  }
  return 0;
}

/**
 * @brief 光标复位后把 0xD114 置 0x18（进入某种编辑状态）
 * @addr 0x1FFE8
 * @module kbd_menu
 * @proto void enter_mode_18(void)
 * @confidence likely
 * @note 光标复位后把 0xD114 置 0x18（进入某种编辑状态）。
 * @tag ui
 */
int enter_mode_18(void)

{
  stat_list_reset();
  edit_state2 = 0x18;
  return 0;
}

/**
 * @brief 调用 0x14BDA（row*5+col 索引封装）
 * @addr 0x1FFF6
 * @module kbd_menu
 * @proto int index_wrap(byte v)
 * @confidence likely
 * @note 调用 0x14BDA（row*5+col 索引封装）。
 * @tag util
 */
int index_wrap(byte v)

{
  dec_cmp_bool(v);
  return 0;
}

