/*
 * 应用模式 / 2b8ac_kdf_chain_count.c
 * 地址范围: 0x2B8AC - 0x2BBA6
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 沿 0x42BA 表（每项 2 字节，类型 7 为终止）最多走 10 步，返回 (终止类型<…
 * @addr 0x2B8AC
 * @module apps
 * @proto ushort kdf_chain_count(ushort idx)
 * @confidence likely
 * @note 沿 0x42BA 表（每项 2 字节，类型 7 为终止）最多走 10 步，返回 (终止类型<<8)|步数。
 * @tag setup
 */
ushort kdf_chain_count(ushort idx)

{
  ushort uVar1;
  short sVar2;
  ushort uVar3;
  char cVar4;
  char cVar5;
  
  cVar5 = '\0';
  cVar4 = '\n';
  uVar1 = (ushort)idx;
  do {
    sVar2 = mul16(uVar1,0x1a);
    uVar3 = *(ushort *)(sVar2 + 0x42ba);
    if (((byte)uVar3 == 7 && (bool)((char)(uVar3 >> 8) + '\x12') == (byte)uVar3 < 7) || (uVar3 == 0)
       ) break;
    uVar1 = uVar3 & 0xff;
    cVar5 = cVar5 + '\x01';
    cVar4 = cVar4 + -1;
    uVar3 = 0;
  } while (cVar4 != '\0');
  if (cVar4 == '\0') {
    cVar5 = '\0';
  }
  return CONCAT11((char)(uVar3 >> 8),cVar5);
}

/**
 * @brief 表格导航切换
 * @addr 0x2B8E8
 * @module apps
 * @proto void table_nav_switch(undefined2 k)
 * @confidence likely
 * @note 表格导航切换：0x1EB86/0x26892/0xEC04/0x8E6E 判断后按 0xD10E 处理。
 * @tag app
 */
int table_nav_switch(undefined2 k)

{
  char cVar1;
  byte bVar2;
  byte bVar4;
  ushort uVar3;
  
  if ((key_modifiers & 0x40) == 0) {
    cVar1 = is_equation_mode();
    if ((((cVar1 != '\0') || (cVar1 = is_mode_4a(), cVar1 != '\0')) ||
        (cVar1 = editor_accept_ready(), cVar1 != '\0')) || (cVar1 = is_ratio_mode(), cVar1 != '\0')) {
      bVar2 = (byte)input_key;
      bVar4 = (byte)((ushort)input_key >> 8);
      if (((bVar2 != 4 || (bool)(bVar4 + 4) != bVar2 < 4) &&
          (bVar2 != 1 || (bool)(bVar4 + 4) != (bVar2 == 0))) &&
         ((bVar2 != 6 || (bool)(bVar4 + 4) != bVar2 < 6 &&
          (bVar2 != 7 || (bool)(bVar4 + 4) != bVar2 < 7)))) {
        return (ushort)bVar4 << 8;
      }
    }
    uVar3 = menu_gate();
  }
  else {
    uVar3 = k & 0xff00;
  }
  return uVar3;
}

/**
 * @brief 进入表格编辑
 * @addr 0x2B97C
 * @module apps
 * @proto void table_edit_enter(undefined2 k)
 * @confidence likely
 * @note 进入表格编辑：0x9972 初始化后 0x177DA 建立矩阵单元，0x23C9A 更新。
 * @tag app
 */
int table_edit_enter(undefined2 k)

{
  int bVar1;
  short unaff_ER14;
  
  frame_enter();
  edit_state2 = 1;
  draw_input_line(k);
  edit_state2 = 0x12;
  bVar1 = matrix_entry((undefined2 *)(unaff_ER14 + -2),unaff_ER14 - 0x16);
  mode_switch_hist(unaff_ER14 + -0x16);
  if (bVar1 == 1) {
    menu_get_key('\x01');
    if ((history_recall == '\x01') && ((ratio_flags & 0x80) == 0)) {
      mode_switch_hist(unaff_ER14 + -0x16);
    }
  }
  else {
    if ((history_recall == '\x01') && ((ratio_flags & 0x80) == 0)) {
      edit_state2 = 1;
      restore_input_line();
      edit_state2 = 0x12;
      bVar1 = matrix_entry((undefined2 *)(unaff_ER14 + -2),unaff_ER14 - 0x16);
      mode_switch_hist(unaff_ER14 + -0x16);
      if (bVar1 == 1) {
        menu_get_key('\x01');
        mode_switch_hist(unaff_ER14 + -0x16);
        goto LAB_rom_02b9d2;
      }
    }
    table_edit_flow();
  }
LAB_rom_02b9d2:
  frame_leave();
  return 0;
}

/**
 * @brief 表格/列表菜单数字键处理（2.4KB，0x13CF2 调用）
 * @addr 0x2BA30
 * @module apps
 * @proto undefined2 menu_numeric_from_table(byte k)
 * @confidence likely
 * @note 表格/列表菜单数字键处理（2.4KB，0x13CF2 调用）。
 * @tag app
 */
undefined2 menu_numeric_from_table(byte k)

{
  byte bVar1;
  int cVar2;
  ushort *puVar3;
  char cVar7;
  ushort *puVar4;
  undefined2 uVar5;
  undefined2 *puVar6;
  int bVar8;
  int bVar9;
  short unaff_ER14;
  
  puVar3 = (ushort *)frame_enter();
  key_vartype((byte *)puVar3,(undefined2 *)(unaff_ER14 + -2));
  bVar1 = (byte)unaff_ER14;
  cVar7 = (char)((ushort)unaff_ER14 >> 8);
  memcpy160((undefined *)CONCAT11(cVar7 + -1 + (0xa1 < bVar1),bVar1 + 0x5e), (uintptr_t)0)
                 *(undefined **)(unaff_ER14 + -2));
  for (bVar8 = 0; (char)((bVar8 < k) << 7) < '\0'; bVar8 = bVar8 + 1) {
    puVar4 = (ushort *)key_pos_offset((ushort)bVar8);
    dec_set_uint_small(puVar4,bVar8);
  }
  *(undefined *)(unaff_ER14 + -0x143) = 0;
  bVar8 = expr_matrix_scan((ushort *)CONCAT11(cVar7 + -1 + (0xa1 < bVar1),bVar1 + 0x5e));
  if (bVar8 == 0) {
    uVar5 = kbd_wait_key();
    if ((char)uVar5 == '\0') {
      bVar8 = mode_loop_common((ushort *)CONCAT11(cVar7 + -1 + (0xa1 < bVar1),bVar1 + 0x5e));
      if (bVar8 == 0) {
        memzero((undefined *)CONCAT11(cVar7 + -2 + (0x4b < bVar1),bVar1 + 0xb4),8);
        for (bVar8 = 0; (char)((bVar8 < k) << 7) < '\0'; bVar8 = bVar8 + 1) {
          key_pos_offset((ushort)bVar8);
          bVar9 = dec_bin_to_bcd_ctx();
          *(ushort *)((ushort)bVar8 * 2 + unaff_ER14 + -0x14c) = (ushort)bVar9;
        }
        uVar5 = kbd_wait_key();
        if ((char)uVar5 == '\0') {
          for (bVar8 = 0; (char)((bVar8 < k) << 7) < '\0'; bVar8 = bVar8 + 1) {
            for (bVar9 = 0; (char)((bVar9 < k) << 7) < '\0'; bVar9 = bVar9 + 1) {
              dec_set_uint_small((ushort *)CONCAT11(cVar7 + -2 + (0x55 < bVar1),bVar1 + 0xaa), (uintptr_t)0)
                             (ushort)bVar8 == *(ushort *)((ushort)bVar9 * 2 + unaff_ER14 + -0x14c));
              puVar6 = (undefined2 *)key_pos_offset(CONCAT11(bVar8,bVar9));
              dec_copy(puVar6,(undefined2 *)CONCAT11(cVar7 + -2 + (0x55 < bVar1),bVar1 + 0xaa)
                            );
            }
            cVar2 = table_edit_main();
            if (cVar2 != '\0') {
              dec_type_byte2((byte *)puVar3);
              break;
            }
          }
          goto LAB_rom_02bab0;
        }
        bVar8 = 1;
      }
      else if (bVar8 == 0xb) {
        bVar8 = 3;
      }
    }
    else {
      bVar8 = 1;
    }
  }
  else if (bVar8 == 0xb) {
    bVar8 = 3;
  }
  dec_round_to(puVar3,bVar8);
LAB_rom_02bab0:
  frame_leave();
  return;
}

/**
 * @brief 表格编辑流程变体（3.8KB，0xDCFA/0x1F25A 调用）
 * @addr 0x2BBA6
 * @module apps
 * @proto int table_edit_flow2(void)
 * @confidence likely
 * @note 表格编辑流程变体（3.8KB，0xDCFA/0x1F25A 调用）。
 * @tag app
 */
int table_edit_flow2(void)

{
  short sVar1;
  bool bVar2;
  byte bVar3;
  undefined2 uVar4;
  ushort uVar5;
  char cVar6;
  short unaff_ER14;
  
  uVar4 = frame_enter();
  bVar2 = true;
  uVar5 = CONCAT11(sub_mode + -1,calc_mode);
  if (calc_mode == 'J') {
    uVar5 = 0x300;
  }
  sVar1 = (uVar5 >> 8) * 2;
  *(undefined2 *)(unaff_ER14 + -2) = *(undefined2 *)(sVar1 + 0x1af8);
  uVar5 = *(ushort *)(sVar1 + 0x66d4);
  *(ushort *)(unaff_ER14 + -4) = uVar5;
  bVar3 = (byte)uVar4;
  cVar6 = (char)((ushort)uVar4 >> 8);
  if (bVar3 == 0x1c && (bool)(cVar6 + '\x04') == bVar3 < 0x1c) {
    uVar5 = (ushort)list_col;
    if (1 < list_col) {
      list_col = list_col - 1;
      uVar5 = (ushort)list_col;
      bVar2 = false;
    }
  }
  else if (bVar3 == 0x1d && (bool)(cVar6 + '\x04') == bVar3 < 0x1d) {
    uVar5 = CONCAT11(*(byte *)(unaff_ER14 + -4),list_col);
    if (list_col < *(byte *)(unaff_ER14 + -4)) {
      list_col = list_col + 1;
      uVar5 = (ushort)list_col;
      bVar2 = false;
    }
  }
  else {
    if (bVar3 != 0x1e || (bool)(cVar6 + '\x04') != bVar3 < 0x1e) {
      if (bVar3 == 0x1f && (bool)(cVar6 + '\x04') == bVar3 < 0x1f) {
        if (list_row == 1) {
          if ((list_page == 2) || (list_page == 3)) {
            list_page = list_page - 1;
            uVar5 = (ushort)list_page;
          }
          else {
            uVar5 = (ushort)list_col;
            if (list_col == 1) goto LAB_rom_02bbf8;
            list_col = list_col - 1;
            bVar2 = false;
            list_row = *(byte *)(unaff_ER14 + -1);
            bVar3 = *(byte *)(unaff_ER14 + -3);
            uVar5 = (ushort)bVar3;
            if (bVar3 == 4) {
              uVar5 = 2;
              list_page = 2;
            }
            else {
              if (bVar3 != 5) goto LAB_rom_02bbf8;
              uVar5 = 3;
              list_page = 3;
            }
          }
          bVar2 = false;
        }
        else {
          list_row = list_row - 1;
          uVar5 = (ushort)list_row;
          bVar2 = false;
        }
        goto LAB_rom_02bbf8;
      }
      if (bVar3 != 0x2d || (bool)(cVar6 + '\x04') != bVar3 < 0x2d) goto LAB_rom_02bbf8;
    }
    if (list_row == 3) {
      if (list_page == 1) {
        uVar5 = 4;
        if (*(byte *)(unaff_ER14 + -3) + 1 < 5) {
          uVar5 = CONCAT11(*(byte *)(unaff_ER14 + -4),list_col);
          if (*(byte *)(unaff_ER14 + -4) <= list_col) goto LAB_rom_02bbf8;
          list_col = list_col + 1;
          uVar5 = 1;
          list_row = 1;
        }
        else {
          list_page = 2;
        }
        bVar2 = false;
      }
      else if (list_page == 2) {
        if (*(byte *)(unaff_ER14 + -3) + 1 < 6) {
          uVar5 = CONCAT11(*(byte *)(unaff_ER14 + -4),list_col);
          if (*(byte *)(unaff_ER14 + -4) <= list_col) goto LAB_rom_02bbf8;
          list_col = list_col + 1;
          uVar5 = 1;
          list_row = 1;
        }
        else {
          uVar5 = 3;
        }
        list_page = (byte)uVar5;
        bVar2 = false;
      }
      else {
        uVar5 = CONCAT11(*(byte *)(unaff_ER14 + -4),list_col);
        if (list_col < *(byte *)(unaff_ER14 + -4)) {
          list_col = list_col + 1;
          uVar5 = 1;
          list_page = 1;
          list_row = 1;
          bVar2 = false;
        }
      }
    }
    else {
      uVar5 = CONCAT11(*(byte *)(unaff_ER14 + -3),list_row);
      if (list_row < *(byte *)(unaff_ER14 + -3)) {
        list_row = list_row + 1;
        uVar5 = (ushort)list_row;
        bVar2 = false;
      }
    }
  }
LAB_rom_02bbf8:
  if (!bVar2) {
    key_hist_clear0((char)uVar5);
  }
  frame_leave();
  return 0;
}

