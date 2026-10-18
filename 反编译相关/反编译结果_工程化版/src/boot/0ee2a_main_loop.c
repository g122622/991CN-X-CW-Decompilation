/*
 * 启动与主流程 / 0ee2a_main_loop.c
 * 地址范围: 0x0EE2A - 0x0EE2A
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 主循环（7.4KB）
 * @addr 0x0EE2A
 * @module boot
 * @proto void main_loop(void)
 * @confidence strong
 * @note 主循环（7.4KB）：按 0xD111 模式分派 0x9D94/0x29B58/0xD968/0xDC66/0xB810
 *       等。
 * @tag boot
 */
int main_loop(int _a1, int _a2, int _a3)

{
  char *pcVar1;
  byte bVar2;
  char cVar3;
  char cVar4;
  byte bVar5;
  int bVar6;
  byte bVar7;
  int sVar8;
  char *pcVar9;
  undefined2 uVar10;
  ushort uVar11;
  int sVar12;
  ushort uVar13;
  byte bVar14;
  char cVar15;
  char cVar16;
  short unaff_ER14;
  
  bVar2 = frame_enter();
  *(undefined *)(unaff_ER14 + -0xb) = 0;
  pcVar1 = input_ptr;
  cVar15 = history_dirty;
  input_active = 0;
  dec_accum8 = 0;
  dec_regY_1 = '\0';
  mode_state_init('\0',bVar2);
  sVar8 = row_buffer_init((short *)(unaff_ER14 + -4));
  *(short *)(unaff_ER14 + -10) = sVar8;
  if ((sVar8 != 0) && (*(byte *)(unaff_ER14 + -2) < 0x7f)) goto LAB_rom_00eeb0;
  do {
    _DAT_ram_d15e = 0;
    pcVar9 = (char *)input_history_ptr();
    strcpy_checked(pcVar1,pcVar9);
    history_cursor = input_saved;
    mode_state_init('\0',bVar2);
    uVar10 = row_buffer_init((short *)(unaff_ER14 + -4));
    *(undefined2 *)(unaff_ER14 + -10) = uVar10;
LAB_rom_00eeb0:
    var_scalar_addr(0);
    input_active = _DAT_ram_d013;
    _DAT_ram_ddd0 = dec_temp_a;
    _DAT_ram_ddd2 = dec_regY;
    sVar8 = 0;
    cVar16 = '\0';
    cVar3 = is_ratio_input();
    if (cVar3 != '\0') {
      cVar3 = line_col_count();
      history_key = cVar3 * '\x05';
      *(undefined *)(unaff_ER14 + -0xb) = 1;
    }
    cVar3 = _DAT_ram_d157;
    if (bVar2 == 1) {
      cVar4 = is_stat_edit4();
      if ((cVar4 == '\0') || (key_modifiers != '\x01')) {
        if ((edit_state2 == '\x06') || (edit_state2 == '\t')) {
          cVar4 = line_col_count();
          history_key = cVar4 * '\a';
        }
      }
      else {
        cVar4 = line_col_count();
        history_key = cVar4 * '\x03';
      }
      draw_list_scroller(CONCAT11(cVar3,history_key),CONCAT11(cur_line,-0x40 - history_key));
    }
    bVar7 = (byte)*(ushort *)(unaff_ER14 + -4);
    uVar11 = (*(ushort *)(unaff_ER14 + -4) >> 8) - (ushort)(bVar7 < 0xc0);
    if ((uVar11 & 0x100) == 0 && (bVar7 != 0xc0 || (char)uVar11 != '\0')) {
      bVar7 = 0xc0;
    }
    else {
      bVar7 = *(byte *)(unaff_ER14 + -4);
    }
    if ((char)((bVar2 < 2) << 7) < '\0') {
      key_hist_c = *(char *)(unaff_ER14 + -2);
      _DAT_ram_d143 = bVar7;
      *(ushort *)(unaff_ER14 + -8) = (ushort)history_key;
      bVar7 = 0xb5 - history_key;
      *(undefined2 *)(unaff_ER14 + -6) = dec_temp_a;
      if (history_key != 0) {
        bVar5 = input_cols3();
        bVar6 = draw_token_text((uintptr_t)0);
        uVar11 = mul16(bVar6 + 2,(ushort)bVar5);
        uVar13 = (ushort)bVar7;
        if ((byte)(SBORROW2(uVar11,uVar13) ^ (short)(uVar11 - uVar13) < 0 | uVar11 == uVar13) != 1)
        {
          uVar10 = mul16(bVar6 - 1,(ushort)bVar5);
          bVar5 = (byte)*(undefined2 *)(unaff_ER14 + -6);
          *(ushort *)(unaff_ER14 + -6) =
               CONCAT11(((char)((ushort)*(undefined2 *)(unaff_ER14 + -6) >> 8) -
                        (char)((ushort)uVar10 >> 8)) - (bVar5 < (byte)uVar10),bVar5 - (byte)uVar10);
        }
      }
      while( true ) {
        bVar6 = (byte)*(undefined2 *)(unaff_ER14 + -6);
        bVar14 = (byte)sVar8;
        bVar5 = bVar6 - bVar14;
        cVar3 = (char)((ushort)sVar8 >> 8);
        if ((CONCAT11((((char)((ushort)*(undefined2 *)(unaff_ER14 + -6) >> 8) - cVar3) -
                      (bVar6 < bVar14)) + -1 + (0xbe < bVar5),bVar5 + 0x41) <= (ushort)bVar7) ||
           (bVar5 = (byte)*(undefined2 *)(unaff_ER14 + -4),
           CONCAT11(((char)((ushort)*(undefined2 *)(unaff_ER14 + -4) >> 8) - cVar3) -
                    (bVar5 < bVar14),bVar5 - bVar14) <= (ushort)bVar7)) break;
        sVar8 = sVar8 + 8;
      }
      if (bVar2 == 1) {
        *(ushort *)(unaff_ER14 + -8) = (ushort)history_key;
        cVar3 = (cur_line >> 1) + _DAT_ram_d157;
      }
      else {
        cVar4 = (char)((ushort)*(undefined2 *)(unaff_ER14 + -2) >> 8);
        cVar3 = ((char)*(undefined2 *)(unaff_ER14 + -2) - cVar4) + '\x01';
        if (0x3f < *(byte *)(unaff_ER14 + -2)) {
          if ((cVar15 == '\0') || ((byte)((cVar4 + '~') - dec_regY) < 0x19)) {
            cVar16 = *(char *)(unaff_ER14 + -2) + -0x3f;
            key_hist_c = '?';
          }
          else {
            for (; (byte)(0xb7U - cVar3) < (byte)(dec_regY - cVar16); cVar16 = cVar16 + '\b') {
            }
          }
        }
        clear_screen();
      }
    }
    else {
      uVar10 = key_hi_plus(bVar7);
      if (((char)uVar10 != '\0') || (bVar2 == 3)) {
        cVar3 = line_wrap(*(char *)(unaff_ER14 + -2));
        _DAT_ram_d157 = _DAT_ram_d157 - cVar3;
      }
      bVar7 = (byte)*(ushort *)(unaff_ER14 + -4);
      uVar11 = (*(ushort *)(unaff_ER14 + -4) >> 8) - (ushort)(bVar7 < 0xc0);
      if ((uVar11 & 0x100) == 0 && (bVar7 != 0xc0 || (char)uVar11 != '\0')) {
        *(undefined2 *)(unaff_ER14 + -8) = 0;
        cVar3 = (char)(((ushort)history_cursor << 3) >> 8);
        sVar8 = CONCAT11(cVar3,history_cursor * '\b');
        bVar5 = (byte)*(undefined2 *)(unaff_ER14 + -4);
        bVar7 = bVar5 + history_cursor * -8;
        uVar11 = (ushort)(byte)(((char)((ushort)*(undefined2 *)(unaff_ER14 + -4) >> 8) - cVar3) -
                               (bVar5 < (byte)(history_cursor * '\b'))) - (ushort)(bVar7 < 0xb8);
        if ((uVar11 & 0x100) != 0 || bVar7 == 0xb8 && (char)uVar11 == '\0') {
          history_cursor = history_cursor - 1;
          sVar8 = CONCAT11((char)(((ushort)history_cursor << 3) >> 8),history_cursor * '\b');
          key_flag_clear();
        }
        key_hist_d = 1;
        fb_clear_rows(0x40 - *(char *)(unaff_ER14 + -2));
      }
      else {
        *(ushort *)(unaff_ER14 + -8) = (ushort)(byte)(-*(char *)(unaff_ER14 + -4) - 0x40);
      }
      if (bVar2 == 3) {
        cVar3 = ((char)*(undefined2 *)(unaff_ER14 + -2) -
                (char)((ushort)*(undefined2 *)(unaff_ER14 + -2) >> 8)) + _DAT_ram_d157;
        key_hist_c = _DAT_ram_d157 + *(char *)(unaff_ER14 + -2);
      }
      else {
        cVar3 = '@' - *(char *)(unaff_ER14 + -1);
      }
    }
    bVar7 = (byte)*(undefined2 *)(unaff_ER14 + -8);
    dec_accum8 =
         CONCAT11(-(0xbf < bVar7) - (char)((ushort)*(undefined2 *)(unaff_ER14 + -8) >> 8),
                  -0x41 - bVar7) + sVar8;
    dec_regY_1 = ('~' - cVar3) + cVar16;
    mode_state_init('\x01',bVar2);
    sVar12 = row_buffer_init((short *)(unaff_ER14 + -4));
    *(short *)(unaff_ER14 + -10) = sVar12;
  } while (sVar12 == 0);
  stored_a = 0;
  stored_b = 0;
  bVar2 = cVar3 - ((cur_line >> 1) + cVar16);
  if (*(char *)(unaff_ER14 + -0xb) != '\0') {
    draw_status_cell(bVar2);
  }
  bVar7 = (byte)sVar8;
  cVar15 = (char)((ushort)sVar8 >> 8);
  if (bVar7 != 0 || cVar15 != '\0') {
    draw_cursor_field(bVar2);
    stored_a = bVar2;
  }
  bVar5 = (byte)*(undefined2 *)(unaff_ER14 + -4);
  if ((ushort)(byte)(-history_key - 0x40) <
      CONCAT11(((char)((ushort)*(undefined2 *)(unaff_ER14 + -4) >> 8) - cVar15) - (bVar5 < bVar7),
               bVar5 - bVar7)) {
    draw_line_end(bVar2);
    stored_b = bVar2;
  }
  history_key = 0;
  if (key_modifiers == '\x01') {
    cur_line = 8;
    if (cVar16 != '\0') {
      draw_arrow_down();
    }
    if ((byte)(cVar16 + 0x3fU) < *(byte *)(unaff_ER14 + -2)) {
      draw_arrow_up();
    }
  }
  frame_leave();
  return 0;
}



// 内存填充函数 (memset)
// 地址: 0xF1A8
// _a1: 目标地址
// _a2: 填充值
// _a3: 填充长度
// 返回: 目标地址

