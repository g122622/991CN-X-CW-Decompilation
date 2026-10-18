/*
 * 输入编辑器 / 23540_paste_line.c
 * 地址范围: 0x23540 - 0x23BB4
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 把编辑行复制到 0xD144 备份区，按首 token 判断后调用 0x284CC（插入行）
 * @addr 0x23540
 * @module editor
 * @proto void paste_line(byte* src)
 * @confidence likely
 * @note 把编辑行复制到 0xD144 备份区，按首 token 判断后调用 0x284CC（插入行）。
 * @tag editor
 */
int paste_line(byte* src)

{
  char cVar1;
  byte *pbVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  
  pbVar2 = (byte *)frame_enter();
  uVar3 = push_edit_cache(pbVar2);
  if ((((char)uVar3 == '\0') || (uVar3 = is_ws_scan(src), (char)uVar3 == '\0')) &&
     (pbVar2 = prev_char_ptr(input_ptr,pbVar2), pbVar2 != (byte *)0x0)) {
    uVar3 = token_class((char *)pbVar2);
    uVar4 = token_class(src);
    cVar1 = is_list_render_ctx((char)uVar3);
    if (cVar1 != '\0') {
      insert_var_line((char)uVar4);
    }
  }
  frame_leave();
  return 0;
}

/**
 * @brief 生成编辑器行内容（调用 0xC85A/0xDAA4/0xE5D6/0xE698 等编辑辅助）…
 * @addr 0x23780
 * @module editor
 * @proto char edit_render_content(undefined2* out)
 * @confidence strong
 * @note 生成编辑器行内容（调用 0xC85A/0xDAA4/0xE5D6/0xE698 等编辑辅助），返回状态。
 * @tag editor
 */
char edit_render_content(undefined2* out)

{
  bool bVar1;
  bool bVar2;
  int bVar3;
  int cVar4;
  byte bVar5;
  undefined2 *puVar6;
  undefined uVar7;
  undefined2 *puVar8;
  short unaff_ER14;
  
  puVar6 = (undefined2 *)frame_enter();
  bVar5 = key_history_flags;
  bVar2 = false;
  if ((menu_state_e != '\0') && ((_DAT_ram_d166 & 1) != 0)) {
    bVar2 = true;
  }
  uVar7 = 0;
  if ((_DAT_ram_d128 != '\0') && ((_DAT_ram_d166 & 2) != 0)) {
    uVar7 = 1;
  }
  if ((*(byte *)puVar6 & 0xf0) == 0xf0) {
    dec_type_to_str((byte *)puVar6,(char *)out);
  }
  else if (calc_mode == '\x02') {
    token_encode(puVar6,(undefined *)out);
  }
  else {
    bVar3 = key_hist_lo();
    cVar4 = editor_mark_dirty();
    if (cVar4 != '\0') {
      bVar3 = editor_format((char *)out);
      if (bVar3 == 1) {
        *(undefined *)(unaff_ER14 + -0xb) = 1;
        goto LAB_rom_0237c6;
      }
      key_hist_clear_lo(bVar3);
    }
    puVar8 = puVar6;
    dec_copy((undefined2 *)(unaff_ER14 + -10),puVar6);
    dec_bin_init((undefined2 *)(unaff_ER14 + -10),puVar8);
    bVar1 = false;
    if (((bVar5 & 0x10) != 0) || (cVar4 = editor_accept_ready(), cVar4 != '\0')) {
      bVar1 = true;
    }
    cVar4 = menu_sel_a;
    if ((((!bVar2) || (bVar1)) || (*(char *)(unaff_ER14 + 0x10) == '\x05')) ||
       (*(char *)(unaff_ER14 + 0x10) == '\x02')) {
      if ((((10 < bVar3) || (bVar3 < 2)) && ((bVar5 & 0x10) == 0)) || (bVar5 == 0x15)) {
        is_line_start();
        puVar8 = (undefined2 *)(unaff_ER14 + -10);
        cVar4 = token_to_text(puVar8);
        *(char *)(unaff_ER14 + -0xb) = cVar4;
        if (cVar4 != '\n') goto LAB_rom_0237c6;
      }
      dec_cmp_signed(unaff_ER14 + -10,puVar8);
      if (10 < bVar3) {
        bVar3 = key_hist_hi();
        *(byte *)(unaff_ER14 + -0xb) = bVar3;
        if (bVar3 == 1) {
          bVar3 = editor_format((char *)out);
          *(byte *)(unaff_ER14 + -0xb) = bVar3;
          if (bVar3 == 1) goto LAB_rom_0237c6;
          key_hist_clear_lo(bVar3);
        }
        else {
          bVar3 = *(byte *)(unaff_ER14 + -0xb);
          if ((1 < bVar3) && (bVar3 < 10)) {
            key_hist_clear_lo(bVar3);
          }
        }
      }
      if (((bVar5 & 0x10) == 0) && (cVar4 = editor_accept_ready(), cVar4 == '\0')) {
        if (3 < *(byte *)(unaff_ER14 + 0x10)) {
          *(undefined *)(unaff_ER14 + 0x10) = 0;
        }
        cVar4 = menu_sel_a;
        *(char *)(unaff_ER14 + -0xb) = menu_sel_a;
        if (cVar4 == '\b') {
          table_nav_row((char *)out);
        }
        else if (*(char *)(unaff_ER14 + -0xb) == '\t') {
          table_row_paint((char *)out);
        }
        else if (*(char *)(unaff_ER14 + -0xb) == '\x04') {
          table_calc_draw((char *)out);
        }
        else {
          table_calc_draw((char *)out);
        }
        bVar5 = key_hist_lo();
        *(byte *)(unaff_ER14 + -0xb) = bVar5;
        if ((bVar5 == 0) || (10 < bVar5)) {
          *(undefined *)(unaff_ER14 + -0xb) = 10;
        }
      }
      else {
        draw_token_plain(puVar6,out,0xc,uVar7);
        *(undefined *)(unaff_ER14 + -0xb) = 10;
      }
    }
    else {
      *(char *)(unaff_ER14 + -0xb) = menu_sel_a;
      if (cVar4 == '\b') {
        *(undefined *)(unaff_ER14 + -0xb) = 0;
      }
      else {
        cVar4 = *(char *)(unaff_ER14 + -0xb);
        if (cVar4 == '\t') {
          *(undefined *)(unaff_ER14 + -0xb) = 1;
        }
        else if (cVar4 == '\0') {
          *(undefined *)(unaff_ER14 + -0xb) = 2;
        }
        else if (cVar4 == '\x04') {
          *(undefined *)(unaff_ER14 + -0xb) = 3;
        }
      }
      if (3 < *(byte *)(unaff_ER14 + 0x10)) {
        *(undefined *)(unaff_ER14 + 0x10) = 0;
      }
      dec_cmp_signed(unaff_ER14 + -10,puVar8);
      edit_value_adjust((char *)out);
      bVar5 = key_hist_lo();
      *(byte *)(unaff_ER14 + -0xb) = bVar5;
      if (bVar5 == 0xd) {
        *(undefined *)(unaff_ER14 + -0xb) = 10;
      }
    }
  }
LAB_rom_0237c6:
  frame_leave();
  return;
}

/**
 * @brief 返回输入区可用列数（0xD137 == 10 时为 5，否则 7）——0xAF52 的副本
 * @addr 0x23BB4
 * @module editor
 * @proto byte input_cols2(void)
 * @confidence strong
 * @note 返回输入区可用列数（0xD137 == 10 时为 5，否则 7）——0xAF52 的副本。
 * @tag editor
 */
byte input_cols2(void)

{
  undefined uVar1;
  
  uVar1 = 7;
  if (cur_line == '\n') {
    uVar1 = 5;
  }
  return uVar1;
}

