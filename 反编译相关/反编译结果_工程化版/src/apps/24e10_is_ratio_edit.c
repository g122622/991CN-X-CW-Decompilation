/*
 * 应用模式 / 24e10_is_ratio_edit.c
 * 地址范围: 0x24E10 - 0x2557A
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 0xD111 == 0xC1 且 0x20D10() == 0、0xD117 bit4 为 …
 * @addr 0x24E10
 * @module apps
 * @proto char is_ratio_edit(void)
 * @confidence likely
 * @note 0xD111 == 0xC1 且 0x20D10() == 0、0xD117 bit4 为 0、0xD127 为 0 时返回
 *       1。
 * @tag mode
 */
char is_ratio_edit(void)

{
  int cVar1;
  
  if ((((calc_mode == -0x3f) && (cVar1 = stat_view_event(), cVar1 == '\0')) &&
      ((key_history_flags & 0x10) == 0)) && (menu_state_e == '\0')) {
    return 1;
  }
  return 0;
}

/**
 * @brief 按行绘制带间距的文本（调用 0x246F4）
 * @addr 0x24EF2
 * @module apps
 * @proto int draw_spaced(ushort row, ushort n)
 * @confidence likely
 * @note 按行绘制带间距的文本（调用 0x246F4）。
 * @tag text
 */
int draw_spaced(ushort row, ushort n)

{
  divmod_signed16(row,n);
  return 0;
}

/**
 * @brief 模式公共循环（5.2KB，0x23088/0x278B6/0x2BA30 使用）
 * @addr 0x24F00
 * @module apps
 * @proto int mode_loop_common(void)
 * @confidence likely
 * @note 模式公共循环（5.2KB，0x23088/0x278B6/0x2BA30 使用）。
 * @tag mode
 */
int mode_loop_common(uintptr_t _a2, int _a1)

{
  int bVar1;
  int bVar2;
  undefined2 *puVar3;
  undefined2 uVar4;
  short sVar5;
  short sVar6;
  ushort uVar7;
  undefined2 *puVar8;
  undefined uVar9;
  undefined uVar10;
  short sVar11;
  short sVar12;
  short unaff_ER14;
  
  bVar1 = frame_enter();
  puVar3 = (undefined2 *)key_pos_offset(0);
  dec_copy((undefined2 *)(unaff_ER14 + -10),puVar3);
  for (sVar11 = 1; (byte)(SBORROW2(sVar11,(ushort)bVar1) ^ (short)(sVar11 - (ushort)bVar1) < 0) == 1
      ; sVar11 = sVar11 + 1) {
    puVar3 = (undefined2 *)key_pos_offset(sVar11 << 8);
    dec_copy((undefined2 *)(unaff_ER14 + -0x14),puVar3);
    bVar2 = dec_add_or_round((undefined2 *)(unaff_ER14 + -0x14),(undefined2 *)(unaff_ER14 + -10));
    *(ushort *)(unaff_ER14 + -0x2a) = (ushort)bVar2;
    if (bVar2 != 0) {
      uVar7 = *(ushort *)(unaff_ER14 + -0x2a);
      goto LAB_rom_024f5a;
    }
    puVar3 = (undefined2 *)key_pos_offset(sVar11 << 8);
    dec_copy(puVar3,(undefined2 *)(unaff_ER14 + -0x14));
  }
  if (2 < bVar1) {
    sVar11 = 1;
    while (sVar6 = sVar11, sVar11 < (short)(bVar1 - 1)) {
      for (; uVar9 = (undefined)sVar11, sVar6 < (short)(ushort)bVar1; sVar6 = sVar6 + 1) {
        uVar10 = (undefined)sVar6;
        puVar3 = (undefined2 *)key_pos_offset(CONCAT11(uVar9,uVar10));
        dec_copy((undefined2 *)(unaff_ER14 + -0x1e),puVar3);
        *(undefined2 *)(unaff_ER14 + -0x2a) = 0;
        for (sVar12 = 0; sVar5 = sVar11 + -1,
            (byte)(SBORROW2(sVar12,sVar5) ^ sVar12 - sVar5 < 0 | sVar12 == sVar5) == 1;
            sVar12 = sVar12 + 1) {
          *(short *)(unaff_ER14 + -0x2e) = unaff_ER14 + -0x1e;
          uVar4 = key_pos_offset(CONCAT11((char)sVar12,uVar10));
          *(undefined2 *)(unaff_ER14 + -0x2c) = uVar4;
          key_pos_offset(CONCAT11(uVar9,(char)sVar12));
          bVar2 = dec_pow_then_div(*(undefined2 **)(unaff_ER14 + -0x2c));
          *(ushort *)(unaff_ER14 + -0x2a) = (ushort)bVar2;
        }
        uVar7 = *(ushort *)(unaff_ER14 + -0x2a);
        if (uVar7 != 0) goto LAB_rom_024f5a;
        puVar3 = (undefined2 *)key_pos_offset(CONCAT11(uVar9,uVar10));
        dec_copy(puVar3,(undefined2 *)(unaff_ER14 + -0x1e));
      }
      bVar2 = expr_matrix_scan(_a1);
      *(ushort *)(unaff_ER14 + -0x2a) = (ushort)bVar2;
      if (bVar2 != 0) {
        uVar7 = *(ushort *)(unaff_ER14 + -0x2a);
        goto LAB_rom_024f5a;
      }
      uVar4 = kbd_wait_key();
      if ((char)uVar4 != '\0') {
        uVar7 = 1;
        goto LAB_rom_024f5a;
      }
      sVar6 = sVar11 + 1;
      *(short *)(unaff_ER14 + -0x34) = sVar6;
      for (; sVar6 < (short)(ushort)bVar1; sVar6 = sVar6 + 1) {
        uVar10 = (undefined)sVar6;
        puVar3 = (undefined2 *)key_pos_offset(CONCAT11(uVar10,uVar9));
        dec_copy((undefined2 *)(unaff_ER14 + -0x1e),puVar3);
        for (sVar12 = 0; sVar5 = sVar11 + -1,
            (byte)(SBORROW2(sVar12,sVar5) ^ sVar12 - sVar5 < 0 | sVar12 == sVar5) == 1;
            sVar12 = sVar12 + 1) {
          *(short *)(unaff_ER14 + -0x32) = unaff_ER14 + -0x1e;
          uVar4 = key_pos_offset(CONCAT11((char)sVar12,uVar9));
          *(undefined2 *)(unaff_ER14 + -0x30) = uVar4;
          key_pos_offset(CONCAT11(uVar10,(char)sVar12));
          dec_pow_then_div(*(undefined2 **)(unaff_ER14 + -0x30));
        }
        puVar3 = (undefined2 *)key_pos_offset(CONCAT11(uVar9,uVar9));
        dec_copy((undefined2 *)(unaff_ER14 + -0x28),puVar3);
        bVar2 = index_wrap((undefined2 *)(unaff_ER14 + -0x28));
        *(ushort *)(unaff_ER14 + -0x2a) = (ushort)bVar2;
        if ((*(byte *)(unaff_ER14 + -0x2a) & 1) == 0) {
          bVar2 = dec_add_or_round((undefined2 *)(unaff_ER14 + -0x1e), (uintptr_t)0)
                                 (undefined2 *)(unaff_ER14 + -0x28));
          uVar7 = (ushort)bVar2;
        }
        else {
          dec_set_uint_small((ushort *)(unaff_ER14 + -0x1e),0);
          uVar7 = 0;
        }
        *(ushort *)(unaff_ER14 + -0x2a) = uVar7;
        if (uVar7 != 0) goto LAB_rom_024f5a;
        puVar3 = (undefined2 *)key_pos_offset(CONCAT11(uVar10,uVar9));
        dec_copy(puVar3,(undefined2 *)(unaff_ER14 + -0x1e));
      }
      sVar11 = *(short *)(unaff_ER14 + -0x34);
    }
  }
  puVar3 = (undefined2 *)key_pos_offset(CONCAT11(bVar1 - 1,bVar1 - 1));
  dec_copy((undefined2 *)(unaff_ER14 + -0x1e),puVar3);
  *(undefined2 *)(unaff_ER14 + -0x2a) = 0;
  for (sVar11 = 0; (byte)(SBORROW2(sVar11,bVar1 - 1) ^ (short)(sVar11 - (bVar1 - 1)) < 0) == 1;
      sVar11 = sVar11 + 1) {
    puVar3 = (undefined2 *)key_pos_offset(CONCAT11((char)sVar11,bVar1 - 1));
    key_pos_offset(CONCAT11(bVar1 - 1,(char)sVar11));
    bVar2 = dec_pow_then_div(puVar3);
    *(ushort *)(unaff_ER14 + -0x2a) = (ushort)bVar2;
  }
  uVar7 = *(ushort *)(unaff_ER14 + -0x2a);
  if (uVar7 == 0) {
    puVar3 = (undefined2 *)key_pos_offset(CONCAT11(bVar1 - 1,bVar1 - 1));
    puVar8 = (undefined2 *)(unaff_ER14 + -0x1e);
    dec_copy(puVar3,puVar8);
    dec_bin_result((ushort *)(unaff_ER14 + -0x1e),puVar8);
    bVar1 = index_wrap((undefined2 *)(unaff_ER14 + -0x1e));
    *(ushort *)(unaff_ER14 + -0x2a) = (ushort)bVar1;
    if ((*(byte *)(unaff_ER14 + -0x2a) & 1) == 0) goto LAB_rom_024f62;
    uVar7 = 0xb;
  }
LAB_rom_024f5a:
  dec_round_to(_a1,(byte)uVar7);
LAB_rom_024f62:
  frame_leave();
  return 0;
}

/**
 * @brief STAT 列表光标复位封装（0x96E8）
 * @addr 0x251EC
 * @module apps
 * @proto void stat_list_reset(void)
 * @confidence likely
 * @note STAT 列表光标复位封装（0x96E8）。
 * @tag stat
 */
int stat_list_reset(void)

{
  cursor_home();
  matrix_set_dims(4);
  matrix_set_dims(4);
  matrix_set_dims(4);
  edit_state2 = 0x15;
  return 0;
}

/**
 * @brief RATIO 模式（0xD111 == 0x88）下清 0xD152 标志与回放保存区 0xD…
 * @addr 0x25258
 * @module apps
 * @proto void ratio_reset(void)
 * @confidence strong
 * @note RATIO 模式（0xD111 == 0x88）下清 0xD152 标志与回放保存区 0xD84C（200 字节）。
 * @tag mode
 */
int ratio_reset(void)

{
  if (calc_mode == -0x78) {
    ratio_flags = 0;
    memzero((undefined *)0xd84c,200);
  }
  return 0;
}

/**
 * @brief 以 0xEB15 启动 0xE21E 的菜单循环（返回 3 时继续）
 * @addr 0x25276
 * @module apps
 * @proto void menu_eb15_loop(void)
 * @confidence likely
 * @note 以 0xEB15 启动 0xE21E 的菜单循环（返回 3 时继续）。
 * @tag ui
 */
int menu_eb15_loop(void)

{
  int cVar1;
  byte bVar2;
  short unaff_ER14;
  
  frame_enter();
  *(undefined2 *)(unaff_ER14 + -2) = 0xeb15;
  while( true ) {
    while (cVar1 = edit_loop(), cVar1 == '\x03') {
      bVar2 = (byte)*(undefined2 *)(unaff_ER14 + -2);
      cVar1 = (char)((ushort)*(undefined2 *)(unaff_ER14 + -2) >> 8);
      if (bVar2 == 0x14 && (bool)(cVar1 + '\x13') == bVar2 < 0x14) {
        *(undefined2 *)(unaff_ER14 + -2) = 0xeb16;
      }
      else {
        if (bVar2 != 0x15 || (bool)(cVar1 + '\x13') != bVar2 < 0x15) goto LAB_rom_0252b6;
        *(undefined2 *)(unaff_ER14 + -2) = 0xeb17;
      }
    }
    if ((cVar1 != '\x01') ||
       (bVar2 = (byte)*(undefined2 *)(unaff_ER14 + -2),
       bVar2 != 5 ||
       (bool)((char)((ushort)*(undefined2 *)(unaff_ER14 + -2) >> 8) + '\x12') != bVar2 < 5)) break;
    *(undefined2 *)(unaff_ER14 + -2) = 0xeb15;
  }
LAB_rom_0252b6:
  frame_leave();
  return 0;
}

/**
 * @brief 按 0xD137 与行缓冲偏移绘制滚动行（0x256E0 使用）
 * @addr 0x2532C
 * @module apps
 * @proto void draw_row_scroll(void)
 * @confidence likely
 * @note 按 0xD137 与行缓冲偏移绘制滚动行（0x256E0 使用）。
 * @tag app
 */
int draw_row_scroll(void)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  short *psVar4;
  short sVar5;
  short sVar6;
  byte bVar7;
  
  psVar4 = (short *)frame_enter();
  bVar2 = cur_line;
  sVar5 = *psVar4 + (ushort)cur_line;
  sVar6 = sVar5 + (ushort)cur_line;
  bVar3 = (byte)sVar6;
  bVar7 = (byte)((ushort)sVar6 >> 8);
  bVar1 = bVar7 - (bVar3 < 0x41);
  if ((byte)((byte)((bVar1 ^ bVar7) & ~bVar1) >> 7 ^ (char)bVar1 < '\0' |
            (bVar3 == 0x41 && bVar1 == 0)) == 1) {
    *psVar4 = sVar5;
  }
  else {
    scroll_screen(cur_line);
    _DAT_ram_d157 = _DAT_ram_d157 - bVar2;
  }
  frame_leave();
  return 0;
}

/**
 * @brief 恒返回 4
 * @addr 0x25362
 * @module apps
 * @proto byte return_4(void)
 * @confidence verified
 * @note 恒返回 4。
 * @tag util
 */
byte return_4(void)

{
  return 4;
}

/**
 * @brief 字节串长度（到 NUL）
 * @addr 0x2536A
 * @module apps
 * @proto ushort strlen(char* s)
 * @confidence verified
 * @note 字节串长度（到 NUL）。
 * @tag libc
 */
ushort strlen(char* s)

{
  char *pcVar1;
  
  for (pcVar1 = s; *pcVar1 != '\0'; pcVar1 = pcVar1 + 1) {
  }
  return CONCAT11(((char)((ushort)pcVar1 >> 8) - (char)((ushort)s >> 8)) -
                  ((byte)pcVar1 < (byte)s),(byte)pcVar1 - (byte)s);
}

/**
 * @brief 查找字符 c，找不到返回 0
 * @addr 0x25388
 * @module apps
 * @proto char* strchr(char* s, char c)
 * @confidence verified
 * @note 查找字符 c，找不到返回 0。
 * @tag libc
 */
char* strchr(char* s, char c)

{
  while( true ) {
    if (*s == c) {
      return s;
    }
    if (*s == '\0') break;
    s = s + 1;
  }
  return (char *)0x0;
}

/**
 * @brief 响铃
 * @addr 0x253F0
 * @module apps
 * @proto void beep(void)
 * @confidence verified
 * @note 响铃：蜂鸣器开 → 延时 0x640 → 关。
 * @tag hw
 */
int beep(void)

{
  buzzer_set('\x01');
  editor_action(0x640);
  buzzer_set('\0');
  return 0;
}

/**
 * @brief 矩阵编辑循环（3.3KB，0x14FF8 调用）
 * @addr 0x25408
 * @module apps
 * @proto int matrix_edit_loop(void)
 * @confidence likely
 * @note 矩阵编辑循环（3.3KB，0x14FF8 调用）。
 * @tag matrix
 */
int matrix_edit_loop(uintptr_t _a2, int _a1)

{
  undefined2 *puVar1;
  undefined2 uVar2;
  undefined2 *puVar3;
  undefined2 uVar4;
  short unaff_ER14;
  
  puVar1 = (undefined2 *)frame_enter();
  *(undefined *)(unaff_ER14 + -9) = 1;
  *(undefined *)(unaff_ER14 + -0xf) = 0;
  *(undefined2 *)(unaff_ER14 + -4) = 0xd6bc;
  *(undefined2 *)(unaff_ER14 + -0xe) = 0xd6c6;
  *(undefined2 *)(unaff_ER14 + -0xc) = 0xd6d0;
  *(undefined2 *)(unaff_ER14 + -8) = 0xd6da;
  *(undefined2 *)(unaff_ER14 + -6) = 0xd6e4;
  uVar4 = 0xd72a;
  *(undefined2 *)(unaff_ER14 + -2) = 0xd73e;
  uVar2 = dec_cmp((undefined2 *)0xd6da,_a1);
  if ((char)uVar2 != '\x04') {
    uVar2 = dec_cmp(*(undefined2 **)(unaff_ER14 + -6),_a1);
    if ((char)uVar2 == '\x02') {
      *(undefined *)(unaff_ER14 + -9) = 0;
    }
    puVar3 = *(undefined2 **)(unaff_ER14 + -8);
    dec_copy((undefined2 *)0xd72a,puVar3);
    dec_inc5((undefined2 *)0xd72a,puVar3);
    dec_round((undefined2 *)0xd72a,puVar3);
    uVar2 = uVar4;
    dec_copy((undefined2 *)0xd734,(undefined2 *)0xd72a);
    if (*(char *)(unaff_ER14 + -9) == '\0') {
      dec_inc5((undefined2 *)0xd72a,uVar2);
    }
    else {
      dec_inc5((undefined2 *)0xd734,uVar2);
    }
    dec_set_uint_small((ushort *)0xd6f8,2);
    dec_bin_pow((undefined2 *)0xd734,(undefined2 *)0xd6f8);
    dec_bin_mul((undefined2 *)0xd72a,*(undefined2 **)(unaff_ER14 + -4));
    dec_bin_mul((undefined2 *)0xd734,*(undefined2 **)(unaff_ER14 + -4));
    dec_set_uint_small((ushort *)0xd6f8,3);
    dec_add_or_round((undefined2 *)0xd72a,(undefined2 *)0xd6f8);
    dec_add_or_round((undefined2 *)0xd734,(undefined2 *)0xd6f8);
    dec_copy((undefined2 *)0xd748,(undefined2 *)0xd72a);
    dec_xy_sub((undefined2 *)0xd748,uVar4);
    dec_copy((undefined2 *)0xd6f8,(undefined2 *)0xd748);
    dec_bin_pow((undefined2 *)0xd748,(undefined2 *)0xd734);
    puVar3 = *(undefined2 **)(unaff_ER14 + -0xc);
    dec_bin_div((undefined2 *)0xd748,puVar3);
    uVar2 = dec_cmp((undefined2 *)0xd748,puVar3);
    if ((char)uVar2 == '\x01') {
      dec_set_uint_small(*(ushort **)(unaff_ER14 + -2),2);
      dec_bin_pow(*(undefined2 **)(unaff_ER14 + -2),(undefined2 *)0xd72a);
      dec_copy((undefined2 *)0xd748,*(undefined2 **)(unaff_ER14 + -2));
      dec_bin_pow(*(undefined2 **)(unaff_ER14 + -2),(undefined2 *)0xd734);
      dec_bin_div(*(undefined2 **)(unaff_ER14 + -2),(undefined2 *)0xd6f8);
      puVar3 = *(undefined2 **)(unaff_ER14 + -0xe);
      dec_bin_mul(*(undefined2 **)(unaff_ER14 + -2),puVar3);
      uVar2 = dec_cmp(*(undefined2 **)(unaff_ER14 + -2),puVar3);
      if ((char)uVar2 == '\x01') {
        dec_copy((undefined2 *)0xd6f8,(undefined2 *)0xd748);
        dec_bin_div((undefined2 *)0xd6f8,(undefined2 *)0xd734);
        puVar3 = *(undefined2 **)(unaff_ER14 + -4);
        dec_bin_div((undefined2 *)0xd6f8,puVar3);
        uVar2 = dec_cmp((undefined2 *)0xd6f8,puVar3);
        if ((char)uVar2 == '\x01') {
          *(undefined *)(unaff_ER14 + -0xf) = 1;
          dec_copy(puVar1,(undefined2 *)0xd734);
          dec_copy(puVar1 + 0x14,(undefined2 *)0xd72a);
        }
      }
    }
  }
  frame_leave();
  return 0;
}

/**
 * @brief 列表模式循环（3.2KB，0x1F4EC/0x263C8 调用）
 * @addr 0x2557A
 * @module apps
 * @proto int list_mode_loop(void)
 * @confidence likely
 * @note 列表模式循环（3.2KB，0x1F4EC/0x263C8 调用）。
 * @tag ui
 */
int list_mode_loop(uintptr_t _a2, int _a1)

{
  int cVar1;
  byte bVar2;
  undefined2 uVar3;
  ushort uVar4;
  ushort uVar5;
  byte bVar6;
  short unaff_ER14;
  
  uVar3 = frame_enter();
  *(undefined2 *)(unaff_ER14 + -2) = uVar3;
  if (_a1 != '\0') {
    ratio_unit = 0;
  }
  while (cVar1 = edit_loop(), cVar1 != '\0') {
    if (cVar1 == '\x01') {
      bVar2 = (byte)*(undefined2 *)(unaff_ER14 + -2);
      if (bVar2 != 6 ||
          (bool)((char)((ushort)*(undefined2 *)(unaff_ER14 + -2) >> 8) + '\x12') != bVar2 < 6)
      break;
      if (_a1 == '\0') {
        cVar1 = editor_accept_ready();
        if (cVar1 == '\0') {
          *(undefined2 *)(unaff_ER14 + -2) = 0xeb22;
        }
        else {
          *(undefined2 *)(unaff_ER14 + -2) = 0xeb20;
        }
      }
      else {
        *(undefined2 *)(unaff_ER14 + -2) = uVar3;
      }
    }
    else {
      if (cVar1 == '\x02') {
        input_key = *(undefined2 *)(unaff_ER14 + -2);
        goto LAB_rom_0255de;
      }
      if (cVar1 != '\x03') goto LAB_rom_0255b8;
      bVar2 = (byte)*(undefined2 *)(unaff_ER14 + -2);
      cVar1 = (char)((ushort)*(undefined2 *)(unaff_ER14 + -2) >> 8);
      if (bVar2 == 0xc && (bool)(cVar1 + '\x13') == bVar2 < 0xc) {
        *(undefined2 *)(unaff_ER14 + -2) = 0xeb23;
      }
      else if (bVar2 == 0xd && (bool)(cVar1 + '\x13') == bVar2 < 0xd) {
        *(undefined2 *)(unaff_ER14 + -2) = 0xeb24;
      }
      else {
        if (bVar2 != 0xe || (bool)(cVar1 + '\x13') != bVar2 < 0xe) {
          uVar5 = *(ushort *)(unaff_ER14 + -2);
          bVar6 = (byte)(uVar5 >> 8);
          bVar2 = (byte)uVar5;
          if ((uVar5 < 0xed00) ||
             (uVar4 = (bVar6 - 0xed) - (ushort)(bVar2 < 3),
             (uVar4 & 0x100) == 0 && (bVar2 != 3 || (char)uVar4 != '\0'))) {
            if ((uVar5 < 0xed04) ||
               (uVar4 = (bVar6 - 0xed) - (ushort)(bVar2 < 7),
               (uVar4 & 0x100) == 0 && (bVar2 != 7 || (char)uVar4 != '\0'))) {
              if ((0xed07 < uVar5) &&
                 (uVar4 = *(ushort *)(unaff_ER14 + -2),
                 uVar5 = ((uVar4 >> 8) - 0xed) - (ushort)((byte)uVar4 < 0xb),
                 (uVar5 & 0x100) != 0 || (byte)uVar4 == 0xb && (char)uVar5 == '\0')) {
                ratio_unit = *(undefined *)(uVar4 + 0x906e);
              }
            }
            else {
              ratio_unit = *(undefined *)(uVar5 + 0x9072);
            }
          }
          else {
            ratio_unit = *(undefined *)(uVar5 + 0x9076);
          }
          goto LAB_rom_0255b8;
        }
        *(undefined2 *)(unaff_ER14 + -2) = 0xeb25;
      }
    }
  }
  if (_a1 == '\0') {
    cVar1 = editor_accept_ready();
    if (cVar1 == '\0') {
      input_key = 0;
    }
    else {
      input_key = 0xfc26;
    }
  }
  else {
LAB_rom_0255b8:
    if (_a1 == '\0') {
      cVar1 = editor_accept_ready();
      if (cVar1 == '\0') {
        input_key = 0;
      }
      else {
        input_key = 0xfc26;
      }
      mode_switch_refresh();
    }
    else {
      mode_switch_refresh();
      input_key = 0;
    }
  }
LAB_rom_0255de:
  frame_leave();
  return 0;
}

