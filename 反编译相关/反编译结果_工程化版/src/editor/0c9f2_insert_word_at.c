/*
 * 输入编辑器 / 0c9f2_insert_word_at.c
 * 地址范围: 0x0C9F2 - 0x0D172
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 在编辑位置插入词元并重排 token（4.2KB，0xF3E4/0x22CA0 调用）
 * @addr 0x0C9F2
 * @module editor
 * @proto int insert_word_at(undefined2* a)
 * @confidence strong
 * @note 在编辑位置插入词元并重排 token（4.2KB，0xF3E4/0x22CA0 调用）。
 * @tag editor
 */
int insert_word_at(undefined2* a)

{
  bool bVar1;
  int cVar2;
  int bVar3;
  byte bVar4;
  byte bVar5;
  bool bVar6;
  byte *pbVar7;
  undefined2 uVar8;
  short sVar9;
  undefined extraout_R1;
  byte *pbVar10;
  byte *pbVar11;
  short unaff_ER14;
  
  pbVar7 = (byte *)frame_enter();
  **(undefined **)(unaff_ER14 + 0x12) = 0;
  **(undefined **)(unaff_ER14 + 0x14) = 0;
  uVar8 = is_two_byte_char((char *)pbVar7);
  if ((char)uVar8 == '\0') {
    cVar2 = is_menu_key_80(*pbVar7);
    if (cVar2 != '\0') {
      if ((char)((ushort)a >> 8) == '\0') goto LAB_rom_00cbaa;
      do {
        pbVar7 = pbVar7 + 1;
        cVar2 = is_menu_key_80(*pbVar7);
      } while (cVar2 != '\0');
      bVar3 = token_class_of((uintptr_t)0);
      if (*(char *)(unaff_ER14 + 0x10) == '\0') {
        uVar8 = token_class2(pbVar7);
        if ((char)uVar8 == '\0') goto LAB_rom_00cbaa;
      }
      else {
        cVar2 = is_digit_key(bVar3);
        if ((cVar2 != '\0') || (bVar3 == 0xd)) goto LAB_rom_00cbaa;
      }
    }
    bVar3 = 0xb;
    while( true ) {
      bVar4 = token_class_of((uintptr_t)0);
      cVar2 = is_digit_key(bVar4);
      if (cVar2 != '\0') break;
      if (bVar4 == 0xd) {
        cVar2 = is_menu_key_80(*pbVar7);
        if ((cVar2 == '\0') || ((bVar3 != 0xe && (bVar3 != 0x11)))) break;
        do {
          pbVar7 = pbVar7 + 1;
          cVar2 = is_menu_key_80(*pbVar7);
          bVar3 = bVar4;
        } while (cVar2 != '\0');
      }
      else {
        if (((*(char *)(unaff_ER14 + 0x10) != '\0') &&
            (cVar2 = edit_line_guard(pbVar7), cVar2 != '\0')) &&
           (uVar8 = edit_word_insert(pbVar7), (char)uVar8 != '\0')) {
          **(undefined **)(unaff_ER14 + 0x12) = 1;
        }
        if (bVar4 == 1) {
          bVar3 = token_insert_pos((uintptr_t)0);
          pbVar10 = pbVar7 + bVar3;
LAB_rom_00cb8a:
          if ((char)a != '\0') break;
          pbVar7 = pbVar10 + 1;
          bVar6 = is_neg_char(*pbVar10);
          bVar3 = bVar4;
          if (CONCAT11(extraout_R1,bVar6) != 0) {
            pbVar7 = pbVar10 + 2;
          }
        }
        else {
          if ((bVar4 == 8) || (bVar4 == 10)) {
            bVar3 = menu_open(*(char *)(unaff_ER14 + 0x10));
            bVar5 = pbVar7[bVar3];
            if (bVar5 == 0xd0) {
              **(undefined **)(unaff_ER14 + 0x14) = 1;
              pbVar10 = pbVar7 + bVar3;
              goto LAB_rom_00cb8a;
            }
            if (bVar5 == 0x2c) {
              **(undefined **)(unaff_ER14 + 0x12) = 2;
            }
            else {
              **(undefined **)(unaff_ER14 + 0x14) = 2;
            }
            break;
          }
          uVar8 = token_class2(pbVar7);
          if ((char)uVar8 == '\0') {
            pbVar10 = pbVar7;
            if (calc_mode == '\r') {
              if (*pbVar7 == 0x24) {
                pbVar7 = pbVar7 + 1;
              }
              sVar9 = is_var_token(pbVar7);
              if ((sVar9 != 0) || (*pbVar7 == 0x25)) {
                pbVar11 = pbVar7 + 1;
                if (*pbVar11 == 0x24) {
                  pbVar11 = pbVar7 + 2;
                }
                sVar9 = is_ascii_digit(pbVar11);
                if ((sVar9 != 0) || (*pbVar11 == 0x25)) {
                  do {
                    pbVar11 = pbVar11 + 1;
                    sVar9 = is_ascii_digit(pbVar11);
                    pbVar7 = pbVar11;
                  } while (sVar9 != 0);
                  goto joined_s0x00cb5e;
                }
              }
            }
            goto LAB_rom_00cb8a;
          }
          bVar6 = false;
          bVar1 = false;
          do {
            if (*pbVar7 == 0x2d) {
              if (bVar6) break;
              bVar6 = true;
              bVar1 = true;
              do {
                pbVar7 = pbVar7 + 1;
                cVar2 = is_menu_key_80(*pbVar7);
              } while (cVar2 != '\0');
            }
            else {
              if (*pbVar7 == 0x2e) {
                if (bVar1) break;
                bVar1 = true;
              }
              pbVar7 = pbVar7 + 1;
            }
            uVar8 = token_class2(pbVar7);
          } while ((char)uVar8 != '\0');
joined_s0x00cb5e:
          bVar3 = bVar4;
          if ((char)a != '\0') break;
        }
      }
    }
  }
LAB_rom_00cbaa:
  frame_leave();
  return 0;
}

/**
 * @brief 编辑项字段递增
 * @addr 0x0CD40
 * @module editor
 * @proto void edit_field_step(byte* p)
 * @confidence strong
 * @note 编辑项字段递增：p+5 小于 p+4 时自增，否则调用 0x253F0 回绕到 p+4。
 * @tag editor
 */
int edit_field_step(byte* p)

{
  char cVar1;
  
  if ((char)((*(byte *)(p + 5) < *(byte *)(p + 4)) << 7) < '\0') {
    cVar1 = *(char *)(p + 5) + '\x01';
  }
  else {
    beep();
    cVar1 = *(char *)(p + 4);
  }
  *(char *)(p + 5) = cVar1;
  return 0;
}

/**
 * @brief 初始化编辑上下文（0xC3EC）并按 0x1E668 与键值判断是否需要 0xFBFE
 * @addr 0x0CD6A
 * @module editor
 * @proto void edit_ctx_check(void)
 * @confidence likely
 * @note 初始化编辑上下文（0xC3EC）并按 0x1E668 与键值判断是否需要 0xFBFE。
 * @tag editor
 */
int edit_ctx_check(void)

{
  ushort uVar1;
  undefined2 uVar2;
  short unaff_ER14;
  
  uVar1 = frame_enter();
  edit_ctx_init((undefined2 *)(unaff_ER14 + -0xc));
  uVar2 = keycode_norm(uVar1);
  if (((char)uVar2 != '\0') || ((((uVar1 >> 8) - 0xfc) - (ushort)((byte)uVar1 < 0x1c) & 0x100) == 0)
     ) {
    menu_gate();
  }
  frame_leave();
  return 0;
}

/**
 * @brief 按输入区列数（0x29DAE）调用 0xFB98 绘制输入提示
 * @addr 0x0CDB6
 * @module editor
 * @proto int draw_input_prompt(void)
 * @confidence strong
 * @note 按输入区列数（0x29DAE）调用 0xFB98 绘制输入提示。
 * @tag editor
 */
int draw_input_prompt(void)

{
  frame_enter();
  input_cols3();
  draw_token_text((uintptr_t)0);
  frame_leave();
  return 0;
}

/**
 * @brief 行值编辑
 * @addr 0x0CED6
 * @module editor
 * @proto int row_value_edit(void)
 * @confidence likely
 * @note 行值编辑：memcpy 0xD144 后循环 0xAF74 解析 token（0x29614 使用）。
 * @tag editor
 */
int row_value_edit(void)

{
  byte *pbVar1;
  char cVar2;
  byte *pbVar3;
  undefined2 uVar4;
  short sVar5;
  short unaff_ER14;
  
  pbVar3 = (byte *)frame_enter();
  pbVar1 = input_ptr;
  pbVar3 = prev_char_ptr(input_ptr,pbVar3);
LAB_rom_00cef0:
  do {
    uVar4 = token_class((char *)pbVar3);
    *(byte *)(unaff_ER14 + -1) = (byte)uVar4;
    cVar2 = is_key_allowed((byte)uVar4);
    if (cVar2 != '\0') {
LAB_rom_00cf28:
      frame_leave();
      return 0;
    }
    cVar2 = *(char *)(unaff_ER14 + -1);
    if ((cVar2 == '\x03') || (cVar2 == '\x06')) {
      pbVar3 = (byte *)table_paste((undefined *)(unaff_ER14 + -1));
    }
    else if (cVar2 == '\t') {
      pbVar3 = (byte *)skip_expr_end((undefined *)(unaff_ER14 + -1));
      if (*(char *)(unaff_ER14 + -1) == '\0') goto LAB_rom_00cf28;
    }
    else {
      sVar5 = is_digit_at(pbVar3);
      if ((char)sVar5 != '\0') {
        do {
          if (pbVar3 == pbVar1) goto LAB_rom_00cf28;
          pbVar3 = prev_char_ptr(pbVar1,pbVar3);
          cVar2 = is_menu_key_80(*pbVar3);
          if (cVar2 != '\0') {
            do {
              if (pbVar3 == pbVar1) goto LAB_rom_00cf28;
              pbVar3 = prev_char_ptr(pbVar1,pbVar3);
              cVar2 = is_menu_key_80(*pbVar3);
            } while (cVar2 != '\0');
            if (*pbVar3 != 0x2d) goto LAB_rom_00cf28;
          }
          sVar5 = is_digit_at(pbVar3);
        } while ((char)sVar5 != '\0');
        goto LAB_rom_00cef0;
      }
    }
    if (pbVar3 == pbVar1) goto LAB_rom_00cf28;
    pbVar3 = prev_char_ptr(pbVar1,pbVar3);
  } while( true );
}

/**
 * @brief 标准 strcpy（复制到 NUL 为止）
 * @addr 0x0D070
 * @module editor
 * @proto char* strcpy(char* dst, char* src)
 * @confidence verified
 * @note 标准 strcpy（复制到 NUL 为止）。
 * @tag libc
 */
char* strcpy(char* dst, char* src)

{
  char cVar1;
  char *pcVar2;
  
  pcVar2 = dst;
  do {
    cVar1 = *src;
    *pcVar2 = cVar1;
    src = src + 1;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  return dst;
}

/**
 * @brief 统计输入区 p 的逻辑字符数（0x04 或 >=0xF0 的双字节字符计 1 个）
 * @addr 0x0D08E
 * @module editor
 * @proto short input_char_count(byte* p)
 * @confidence verified
 * @note 统计输入区 p 的逻辑字符数（0x04 或 >=0xF0 的双字节字符计 1 个）。
 * @tag editor
 */
short input_char_count(byte* p)

{
  byte bVar1;
  short sVar2;
  
  sVar2 = 0;
  for (; bVar1 = *p, bVar1 != 0; p = p + 1) {
    if ((bVar1 == 4) || (0xef < bVar1)) {
      p = p + 1;
    }
    sVar2 = sVar2 + 1;
  }
  return sVar2;
}

/**
 * @brief 扫描编辑行检查括号平衡
 * @addr 0x0D0AE
 * @module editor
 * @proto int check_balanced_expr(void)
 * @confidence strong
 * @note 扫描编辑行检查括号平衡：遇到 0x2A（(）与 0x2A886（分数 3）成对计数，0x24A14（分数 2）计数，遇
 *       0x1C 且已平衡时结束。
 * @tag editor
 */
int check_balanced_expr(void)

{
  char cVar1;
  bool bVar2;
  byte *pbVar3;
  undefined2 uVar4;
  undefined extraout_R1;
  char cVar5;
  byte *pbVar6;
  
  pbVar3 = (byte *)frame_enter();
  cVar5 = '\x01';
  while (pbVar6 = pbVar3, *pbVar6 != 0) {
    uVar4 = token_class((char *)pbVar6);
    cVar1 = is_v2_02((char)uVar4);
    if (cVar1 == '\0') {
      cVar1 = is_frac_sep((char)uVar4);
      if (cVar1 == '\0') {
        if ((*pbVar6 == 0x1c) && (cVar5 == '\x01')) break;
      }
      else {
        cVar5 = cVar5 + -1;
        if (cVar5 == '\0') break;
      }
    }
    else {
      cVar5 = cVar5 + '\x01';
    }
    bVar2 = is_neg_char(*pbVar6);
    pbVar3 = pbVar6 + 1;
    if (CONCAT11(extraout_R1,bVar2) != 0) {
      pbVar3 = pbVar6 + 2;
    }
  }
  frame_leave();
  return 0;
}

/**
 * @brief 确认输入行
 * @addr 0x0D108
 * @module editor
 * @proto void commit_line(void)
 * @confidence likely
 * @note 确认输入行：经 0x8D94 检查后按 0xD114/0xD115 状态调用 0x1E6B6/0x26A40/0x27A7A
 *       刷新显示。
 * @tag editor
 */
int commit_line(void)

{
  undefined uVar1;
  char cVar2;
  char cVar3;
  undefined2 uVar4;
  short unaff_ER14;
  
  frame_enter();
  if ((key_modifiers != '\x01') &&
     (uVar4 = input_variant((char *)(unaff_ER14 + -1)), (char)uVar4 != '\0')) {
    if (((edit_state2 & 0x80) != 0) && ((stat_state & 0xf0) != 0)) {
      stat_state_reset();
    }
    cVar2 = key_hist_c;
    uVar1 = key_hist_a;
    input_init();
    key_hist_a = uVar1;
    cVar3 = is_special_editing();
    if ((cVar3 == '\0') && (cVar2 != '\0')) {
      _DAT_ram_d157 = cVar2;
    }
    list_refresh();
    key_hist_a = 0;
  }
  frame_leave();
  return 0;
}

/**
 * @brief 按当前 token 的按键码（0x18/P/Q/S/0xC8/0x38 等）分派编辑命令
 * @addr 0x0D172
 * @module editor
 * @proto void edit_cmd_dispatch(char arg)
 * @confidence strong
 * @note 按当前 token 的按键码（0x18/P/Q/S/0xC8/0x38 等）分派编辑命令：0x1FBD2 替换
 *       token、0x1E2D2 切换矩阵/统计单元，并通过 param_3 返回状态码。
 * @tag editor
 */
int edit_cmd_dispatch(char arg)

{
  char cVar1;
  char cVar2;
  char cVar3;
  byte bVar4;
  char *pcVar5;
  short sVar6;
  short unaff_ER14;
  
  pcVar5 = (char *)frame_enter();
  sVar6 = key_is_1a_04();
  cVar1 = (char)sVar6;
  sVar6 = key_is_11_04();
  cVar2 = (char)sVar6;
  sVar6 = key_is_14_02();
  **(undefined **)(unaff_ER14 + 0x10) = 0;
  cVar3 = *pcVar5;
  if (cVar3 == '\x18') {
    if (cVar1 == '\0') {
      if (cVar2 == '\0') {
joined_s0x00d20c:
        if ((char)sVar6 != '\0') {
          bVar4 = token_insert_pos((uintptr_t)0);
          pcVar5 = pcVar5 + bVar4 + 1;
        }
        **(undefined **)(unaff_ER14 + 0x10) = 2;
        history_cursor_rel(pcVar5);
        goto LAB_rom_00d1aa;
      }
      if (arg == '\0') goto LAB_rom_00d1aa;
      cVar1 = '\x02';
    }
    else {
      if (arg == '\0') goto LAB_rom_00d1aa;
      cVar1 = '\x01';
    }
  }
  else if (((cVar3 == 'P') || (cVar3 == 'Q')) || (cVar3 == 'S')) {
    if (cVar1 == '\0') {
      if (cVar2 == '\0') goto joined_s0x00d20c;
      cVar1 = '\x01';
    }
    else {
      cVar1 = '\x02';
    }
  }
  else {
    if (cVar3 != -0x38) goto LAB_rom_00d1aa;
    if (cVar1 == '\0') {
      if (cVar2 == '\0') {
        **(undefined **)(unaff_ER14 + 0x10) = 1;
        goto LAB_rom_00d1aa;
      }
      cVar1 = '\x01';
    }
    else {
      cVar1 = '\0';
    }
  }
  if (cVar1 != arg) {
    matrix_switch_cell(CONCAT11(cVar1,arg));
  }
LAB_rom_00d1aa:
  frame_leave();
  return 0;
}

