/*
 * 行打印与文本 / 22a8c_stat_analysis.c
 * 地址范围: 0x22A8C - 0x2326E
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief STAT 数据处理（1-VAR/2-VAR 统计量计算）
 * @addr 0x22A8C
 * @module textlib
 * @proto void stat_analysis(void)
 * @confidence likely
 * @note STAT 数据处理（1-VAR/2-VAR 统计量计算）。
 * @tag stat
 */
int mode_06_stat_loop(uintptr_t _a2, int _a1)

{
  char cVar1;
  int cVar2;
  short sVar3;
  byte *pbVar4;
  undefined2 uVar5;
  byte bVar6;
  
  key_hist_c = 1;
  do {
    key_modifiers = 3;
    cursor_update_list();
    fb_flush();
    while( true ) {
      sVar3 = process_key((short)_a1);
      pbVar4 = (byte *)key_filter_lookup4(sVar3);
      set_input_key(pbVar4);
      uVar5 = key_is_extended((short)pbVar4);
      if ((char)uVar5 != '\0') break;
      bVar6 = (byte)pbVar4;
      cVar2 = (char)((ushort)pbVar4 >> 8);
      if (bVar6 == 0x26 && (bool)(cVar2 + '\x04') == bVar6 < 0x26) {
        edit_state2 = 1;
        return 0;
      }
      if (bVar6 == 0x40 && (bool)(cVar2 + '\x04') == bVar6 < 0x40) {
        edit_state2 = 1;
        return 0;
      }
      cVar1 = is_arrow_key(bVar6,cVar2);
      if (cVar1 == '\0') {
        uVar5 = key_is_menu_key((short)pbVar4);
        if ((char)uVar5 == '\0') {
          cVar2 = is_key_12_15(bVar6,cVar2);
          if (cVar2 != '\0') {
            cVar2 = bVar6 - 0x12;
            _a1 = (byte *)CONCAT11((char)((ushort)_a1 >> 8),cVar2);
            if (cVar2 != sub_mode) {
              mat_set_dims_ptr();
            }
            sub_mode = cVar2;
            stat_table_reset();
          }
        }
        else {
          edit_ctx_check();
        }
        goto LAB_rom_022b74;
      }
      key_flag_bit7();
      _a1 = pbVar4;
      if (calc_mode == '\x06') {
        cVar2 = stat_row_edit(bVar6,cVar2);
      }
      else {
        cVar2 = edit_key_handler(pbVar4);
      }
      if (cVar2 == '\0') goto LAB_rom_022b74;
      key_flag_clear();
    }
    if (sub_mode == '\x04') {
      sVar3 = key_code_lookup((short)pbVar4);
      if (sVar3 != 0) {
        set_input_key(sVar3);
      }
      commit_line();
      edit_state2 = 1;
      return 0;
    }
    table_copy(_a1);
    pbVar4 = input_key;
LAB_rom_022b74:
    if ((byte)pbVar4 == 0x24 && (bool)((char)((ushort)pbVar4 >> 8) + '\x04') == (byte)pbVar4 < 0x24)
    {
      return 0;
    }
  } while( true );
}

/**
 * @brief STAT 编辑入口（1.4KB，0xC0DA/0xD3A2/0xD82E 使用）
 * @addr 0x22B82
 * @module textlib
 * @proto void stat_edit_entry(void)
 * @confidence likely
 * @note STAT 编辑入口（1.4KB，0xC0DA/0xD3A2/0xD82E 使用）。
 * @tag app
 */
int stat_edit_entry(uintptr_t _a2, int _a1)

{
  char cVar1;
  byte bVar2;
  ushort uVar3;
  byte bVar4;
  ushort uVar5;
  byte bVar6;
  short unaff_ER14;
  
  uVar3 = frame_enter();
  if (((edit_state == '\x01') && (dec_regY_1 <= *(byte *)(unaff_ER14 + 0x10))) &&
     (bVar2 = *(byte *)(unaff_ER14 + 0x10) - dec_regY_1, *(byte *)(unaff_ER14 + 0x10) = bVar2,
     bVar2 < 0x40)) {
    uVar5 = uVar3;
    if (_a1 < uVar3) {
      uVar5 = _a1;
      _a1 = uVar3;
    }
    uVar3 = editor_pos_limit();
    if (uVar3 <= _a1) {
      bVar4 = (byte)dec_accum8;
      cVar1 = (char)((ushort)dec_accum8 >> 8);
      bVar2 = history_key;
      if ((uVar5 < uVar3) ||
         (bVar2 = (byte)uVar5 - bVar4,
         uVar3 = (ushort)(byte)(((char)(uVar5 >> 8) - cVar1) - ((byte)uVar5 < bVar4)) -
                 (ushort)(bVar2 < 0xbf),
         (uVar3 & 0x100) != 0 || bVar2 == 0xbf && (char)uVar3 == '\0')) {
        bVar6 = (byte)_a1 - bVar4;
        uVar3 = (ushort)(byte)(((char)((uint32_t)_a1 >> 8) - cVar1) - ((byte)_a1 < bVar4)) -
                (ushort)(bVar6 < 0xbf);
        if ((uVar3 & 0x100) == 0 && (bVar6 != 0xbf || (char)uVar3 != '\0')) {
          bVar6 = 0xbf;
        }
        draw_hline_animated(CONCAT11(*(undefined *)(unaff_ER14 + 0x10),bVar2), (uintptr_t)0)
                       CONCAT11(*(undefined *)(unaff_ER14 + 0x10),bVar6));
      }
    }
  }
  frame_leave();
  return 0;
}

/**
 * @brief 打开/关闭菜单层（1.4KB，0xC9F2/0xCD20/0x23BD6 使用，含合并子入口…
 * @addr 0x22BF4
 * @module textlib
 * @proto int menu_open(char which)
 * @confidence strong
 * @note 打开/关闭菜单层（1.4KB，0xC9F2/0xCD20/0x23BD6 使用，含合并子入口）。
 * @tag ui
 */
int menu_open(char which)

{
  byte *pbVar1;
  bool bVar2;
  byte bVar3;
  int cVar4;
  byte *pbVar5;
  undefined extraout_R1;
  ushort uVar6;
  undefined2 uVar7;
  undefined extraout_R1_00;
  char cVar8;
  short unaff_ER14;
  
  pbVar5 = (byte *)frame_enter();
  cVar8 = '\x01';
  bVar2 = is_neg_char(*pbVar5);
  pbVar1 = pbVar5 + 1;
  if (CONCAT11(extraout_R1,bVar2) != 0) {
    pbVar1 = pbVar5 + 2;
  }
  while( true ) {
    pbVar5 = pbVar1;
    uVar6 = token_at(pbVar5);
    uVar7 = key_filter_d116(uVar6);
    if ((char)uVar7 != '\0') break;
    uVar7 = token_class((char *)pbVar5);
    cVar4 = (char)uVar7;
    if (cVar4 == '\t') {
      cVar8 = cVar8 + -1;
      if (cVar8 == '\0') break;
    }
    else if ((cVar4 == '\b') || (cVar4 == '\n')) {
      cVar8 = cVar8 + '\x01';
    }
    else if (cVar4 == '\x01') {
      bVar3 = token_insert_pos((uintptr_t)0);
      pbVar5 = pbVar5 + bVar3;
    }
    else if (((cVar4 == '\x03') || (cVar4 == '\x04')) ||
            ((which != '\0' &&
             (((*pbVar5 == 0x2c &&
               (skip_expr_end((undefined *)(unaff_ER14 + -1)), *(char *)(unaff_ER14 + -1) == '\x01'
               )) && (cVar4 = token_replace_range(pbVar5), cVar4 != '\0')))))) break;
    bVar2 = is_neg_char(*pbVar5);
    pbVar1 = pbVar5 + 1;
    if (CONCAT11(extraout_R1_00,bVar2) != 0) {
      pbVar1 = pbVar5 + 2;
    }
  }
  frame_leave();
  return 0;
}

/**
 * @brief 标准 memcpy（len 由调用者压栈）
 * @addr 0x22DC4
 * @module textlib
 * @proto byte* memcpy_bytes(byte* dst, byte* src, ushort len)
 * @confidence verified
 * @note 标准 memcpy（len 由调用者压栈）。ROP 教程中 0x22DC4 的用法与之一致。
 * @tag libc
 */
byte* memcpy_bytes(byte* dst, byte* src, ushort len)

{
  undefined *puVar1;
  
  puVar1 = dst;
  for (; (char)((len != 0) << 7) < '\0'; len = len + -1) {
    *puVar1 = *src;
    puVar1 = puVar1 + 1;
    src = src + 1;
  }
  return dst;
}

/**
 * @brief 菜单录入入口
 * @addr 0x22DFE
 * @module textlib
 * @proto void menu_edit_entry(undefined2 key)
 * @confidence strong
 * @note 菜单录入入口：调用编辑器（0xE21E），结果为 2 时把返回值写入 0xD10E。
 * @tag menu
 */
int menu_edit_entry(undefined2 key)

{
  int cVar1;
  short unaff_ER14;
  
  cVar1 = frame_enter();
  if ((cVar1 == '\0') || (calc_mode == cVar1)) {
    *(undefined2 *)(unaff_ER14 + -2) = key;
    cVar1 = edit_loop();
    if (cVar1 == '\x02') {
      input_key = *(undefined2 *)(unaff_ER14 + -2);
    }
  }
  frame_leave();
  return 0;
}

/**
 * @brief 反复 0x25388 查找控制字节 1 并跳过各 token
 * @addr 0x23178
 * @module textlib
 * @proto int skip_token_loops(void)
 * @confidence likely
 * @note 反复 0x25388 查找控制字节 1 并跳过各 token。
 * @tag parser
 */
int skip_token_loops(void)

{
  char *pcVar1;
  
  pcVar1 = (char *)frame_enter();
  while (pcVar1 = strchr(pcVar1,'\x01'), pcVar1 != (char *)0x0) {
    pcVar1 = pcVar1 + 1;
  }
  frame_leave();
  return 0;
}

/**
 * @brief 以 0 调用 0x27E84（关闭左侧菜单栏）
 * @addr 0x2319E
 * @module textlib
 * @proto void menu_enter_off(void)
 * @confidence likely
 * @note 以 0 调用 0x27E84（关闭左侧菜单栏）。
 * @tag ui
 */
int menu_enter_off(void)

{
  sidebar_menu('\0');
  return 0;
}

/**
 * @brief 模式切换入口
 * @addr 0x231C0
 * @module textlib
 * @proto void mode_switch_entry(char m)
 * @confidence likely
 * @note 模式切换入口：记录 0xD11E，按 0xD111/0xD114 选择 0x2A99C 等复位流程。
 * @tag ui
 */
int mode_switch_entry(char m, int _a2)

{
  char cVar1;
  
  menu_io = m;
  if (((((calc_mode != 'E') && (calc_mode != 'K')) && (calc_mode != 'J')) &&
      (calc_mode != '\f')) || (cVar1 = is_modifier_3_5(), cVar1 == '\0')) {
    if ((((edit_state2 == 0x13) || (edit_state2 == 0x14)) ||
        ((edit_state2 == 0x1a || ((edit_state2 == 0x12 && (calc_mode == '\x03')))))) &&
       (cVar1 = is_modifier_3_5(), cVar1 != '\0')) {
      buffer_reset_for_mode(_a2);
    }
    else {
      if ((edit_state2 & 0x80) != 0) {
        stat_state_reset();
      }
      input_init();
      buffer_reset_for_mode(_a2);
      expr_state_clear();
      if (edit_state2 != 1) {
        key_mod_clear();
      }
      if ((calc_mode == -0x78) && (memzero((undefined *)0xd84c,200), edit_state2 != 0x12)
         ) {
        ratio_flags = 0;
      }
    }
  }
  return 0;
}

/**
 * @brief 按 flag 选择 0x20FCE / 0x21016 显示/隐藏窗口，返回 er0
 * @addr 0x23254
 * @module textlib
 * @proto undefined2 set_window_visible(undefined2 er0, char flag)
 * @confidence likely
 * @note 按 flag 选择 0x20FCE / 0x21016 显示/隐藏窗口，返回 er0。
 * @tag ui
 */
undefined2 set_window_visible(undefined2 er0, char flag)

{
  if (flag == '\0') {
    str_emit_ltxlt(er0);
  }
  else {
    str_emit_1D90(er0);
  }
  return er0;
}

/**
 * @brief 统计函数调用分派（1.3KB，0x15A62 调用）
 * @addr 0x2326E
 * @module textlib
 * @proto int stat_func_call(void)
 * @confidence likely
 * @note 统计函数调用分派（1.3KB，0x15A62 调用）。
 * @tag app
 */
int stat_func_call(uintptr_t _a2, int _a1)

{
  bool bVar1;
  undefined2 *puVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  undefined2 uVar5;
  
  puVar2 = (undefined2 *)frame_enter();
  uVar5 = 0xd824;
  uVar4 = 0xd842;
  uVar3 = dec_cmp((undefined2 *)0xd824,_a1);
  bVar1 = (char)uVar3 == '\x02';
  if (bVar1) {
    if ((calc_mode == 'K') || ((calc_mode == 'E' && (key_state_a == '\0'))))
    goto LAB_rom_023332;
    dec_inc5((undefined2 *)0xd824,_a1);
  }
  dec_set_uint_small((ushort *)0xd842,2);
  dec_add_or_round((undefined2 *)0xd824,(undefined2 *)0xd842);
  dec_round((undefined2 *)0xd824,uVar4);
  dec_cmp_ex((undefined2 *)0xd824,uVar4);
  dec_copy((undefined2 *)0xd842,(undefined2 *)0xd824);
  dec_inc5((undefined2 *)0xd842,uVar5);
  dec_inc5((undefined2 *)0xd7f2,uVar5);
  dec_copy(puVar2,(undefined2 *)0xd7f2);
  dec_copy(puVar2 + 0x14,(undefined2 *)0xd7f2);
  if (bVar1) {
    dec_copy(puVar2 + 5,(undefined2 *)0xd824);
    dec_copy(puVar2 + 0x19,(undefined2 *)0xd842);
  }
  else {
    dec_bin_div(puVar2,(undefined2 *)0xd824);
    dec_bin_div(puVar2 + 0x14,(undefined2 *)0xd842);
  }
LAB_rom_023332:
  frame_leave();
  return 0;
}

