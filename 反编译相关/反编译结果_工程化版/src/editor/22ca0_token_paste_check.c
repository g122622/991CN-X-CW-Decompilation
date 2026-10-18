/*
 * 输入编辑器 / 22ca0_token_paste_check.c
 * 地址范围: 0x22CA0 - 0x23338
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 粘贴前 token 检查（1.9KB，0xAFAE 使用）
 * @addr 0x22CA0
 * @module editor
 * @proto void token_paste_check(byte* p)
 * @confidence likely
 * @note 粘贴前 token 检查（1.9KB，0xAFAE 使用）。
 * @tag editor
 */
int token_paste_check(byte* p)

{
  byte bVar1;
  undefined uVar2;
  int cVar3;
  bool bVar4;
  byte *pbVar5;
  short sVar6;
  undefined extraout_R1;
  undefined extraout_R1_00;
  byte *pbVar7;
  byte *pbVar8;
  short unaff_ER14;
  
  pbVar5 = (byte *)frame_enter();
  bVar1 = input_max_len();
  *(byte **)(unaff_ER14 + -6) = pbVar5 + (bVar1 - 1);
  memset(p,0,(ushort)bVar1);
  pbVar7 = pbVar5;
  do {
    while( true ) {
      while( true ) {
        pbVar8 = pbVar7;
        if ((*pbVar8 == 0) || (*(byte **)(unaff_ER14 + -6) <= pbVar8)) goto LAB_rom_022db8;
        if ((*pbVar8 == 0xa9) || (*pbVar8 == 0xaa)) break;
        cVar3 = token_insert_check();
        if (cVar3 == '\0') {
          bVar4 = is_neg_char(*pbVar8);
          pbVar7 = pbVar8 + 1;
          if (CONCAT11(extraout_R1_00,bVar4) != 0) {
            pbVar7 = pbVar8 + 2;
          }
        }
        else {
          uVar2 = token_insert_pos((uintptr_t)0);
          *(undefined *)(unaff_ER14 + -7) = uVar2;
          bVar1 = (char)pbVar8 - (char)pbVar5;
          p[bVar1] = p[bVar1] + '\x01';
          sVar6 = (ushort)bVar1 + (ushort)*(byte *)(unaff_ER14 + -7);
          p[sVar6 + 1] = p[sVar6 + 1] + '\x02';
          bVar4 = is_neg_char(*pbVar8);
          pbVar7 = pbVar8 + 1;
          if (CONCAT11(extraout_R1,bVar4) != 0) {
            pbVar7 = pbVar8 + 2;
          }
        }
      }
      pbVar7 = pbVar8 + 1;
      *(byte **)(unaff_ER14 + -4) = pbVar7;
      uVar2 = insert_word_at(0x100);
      *(undefined *)(unaff_ER14 + -7) = uVar2;
      if (*(char *)(unaff_ER14 + -2) != '\x01') break;
      bVar1 = (char)pbVar7 - (char)pbVar5;
      p[bVar1] = 1;
      if (*(char *)(unaff_ER14 + -1) != '\x02') {
        p[(ushort)bVar1 + (ushort)*(byte *)(unaff_ER14 + -7)] =
             p[(ushort)bVar1 + (ushort)*(byte *)(unaff_ER14 + -7)] + '\x02';
      }
    }
  } while (*(char *)(unaff_ER14 + -2) != '\x02');
LAB_rom_022db8:
  frame_leave();
  return 0;
}

/**
 * @brief 变量编辑器（3.7KB，0x24728 调用）
 * @addr 0x23338
 * @module editor
 * @proto void var_editor(void)
 * @confidence likely
 * @note 变量编辑器（3.7KB，0x24728 调用）。
 * @tag editor
 */
int var_editor(void)

{
  bool bVar1;
  byte bVar2;
  byte bVar3;
  char cVar7;
  ushort uVar4;
  short sVar5;
  undefined2 uVar6;
  byte *pbVar8;
  byte bVar9;
  byte bVar10;
  char *pcVar11;
  
  bVar2 = frame_enter();
  bVar9 = 0;
  bVar1 = false;
  if (stat_state == '@') {
    bVar3 = (byte)input_key;
    cVar7 = (char)((ushort)input_key >> 8);
    if ((bVar3 != 0x3d || (bool)(cVar7 + '\x04') != bVar3 < 0x3d) &&
       (bVar3 != 0x3c || (bool)(cVar7 + '\x04') != bVar3 < 0x3c)) {
LAB_rom_0234f2:
      stat_state = 4;
LAB_rom_0234f8:
      input_init();
      strcpy_checked(&input_buf,(char *)0xd248);
      key_modifiers = 1;
      goto LAB_rom_02339a;
    }
    bVar1 = true;
  }
  else if (stat_state == ' ') {
    bVar1 = true;
  }
  stat_state = 2;
  uVar4 = restart_loop();
  bVar3 = (byte)uVar4;
  if (bVar1) {
    if (bVar3 <= _DAT_ram_d5eb) {
      bVar9 = _DAT_ram_d5eb - bVar3;
    }
  }
  else {
    _DAT_ram_d5eb = 0;
  }
  list_page = bVar9;
  input_init();
  do {
    pcVar11 = (char *)CONCAT11((0x13 < _DAT_ram_d5eb) + -0x2b,_DAT_ram_d5eb - 0x14);
    if (*pcVar11 == -1) {
      _DAT_ram_d5eb = _DAT_ram_d5eb - 1;
      pcVar11 = pcVar11 + -1;
    }
    sVar5 = CONCAT11(-(_DAT_ram_d5eb < bVar9),_DAT_ram_d5eb - bVar9);
    pbVar8 = (byte *)(uVar4 & 0xff);
    if ((byte)(SBORROW2(sVar5,(short)pbVar8) ^ sVar5 - (short)pbVar8 < 0) == 1) {
      if (_DAT_ram_d5eb < bVar9) {
        bVar9 = bVar9 - 1;
      }
    }
    else {
      bVar9 = bVar9 + 1;
    }
    key_modifiers = 3;
    var_list_draw();
    fb_flush();
    kbd_repeat = 0;
    if (bVar3 < bVar2) {
      pbVar8 = (byte *)(ushort)bVar2;
      if ((byte *)((uVar4 & 0xff) + (ushort)bVar9) < pbVar8) {
        kbd_repeat = 2;
      }
      if (bVar9 != 0) {
        kbd_repeat = kbd_repeat | 1;
      }
    }
    list_page = bVar9;
    sVar5 = process_key((short)pbVar8);
    set_input_key(sVar5);
    uVar6 = key_is_extended(sVar5);
    if ((char)uVar6 == '\0') {
      bVar10 = (byte)sVar5;
      cVar7 = (char)((ushort)sVar5 >> 8);
      if (bVar10 == 7 && (bool)(cVar7 + '\x04') == bVar10 < 7) {
        restart_loop();
      }
      else if (bVar10 == 0x1c && (bool)(cVar7 + '\x04') == bVar10 < 0x1c) {
        key_flag_bit7();
        if (_DAT_ram_d5eb == 0) {
          _DAT_ram_d5eb = bVar2 - 1;
          if (bVar3 < bVar2) {
            bVar9 = bVar2 - bVar3;
          }
        }
        else {
          _DAT_ram_d5eb = _DAT_ram_d5eb - 1;
          if (_DAT_ram_d5eb == 0) {
            key_flag_clear();
          }
        }
      }
      else if (bVar10 == 0x1d && (bool)(cVar7 + '\x04') == bVar10 < 0x1d) {
        key_flag_bit7();
        if (bVar2 - 1 == (ushort)_DAT_ram_d5eb) {
          _DAT_ram_d5eb = 0;
          bVar9 = 0;
        }
        else {
          _DAT_ram_d5eb = _DAT_ram_d5eb + 1;
          if (bVar2 - 1 == (ushort)_DAT_ram_d5eb) {
            key_flag_clear();
          }
        }
      }
      else {
        if (bVar10 == 0x26 && (bool)(cVar7 + '\x04') == bVar10 < 0x26) {
          edit_state2 = '\x01';
          break;
        }
        if ((bVar10 == 0x2d && (bool)(cVar7 + '\x04') == bVar10 < 0x2d) ||
           (bVar10 == 0x30 && (bool)(cVar7 + '\x04') == bVar10 < 0x30)) {
          if (edit_state2 != -0x40) {
            stat_state = 3;
            goto LAB_rom_0234f8;
          }
          calc_buf_len = *pcVar11;
          goto LAB_rom_0234f2;
        }
      }
    }
    else {
      table_copy(pbVar8);
      sVar5 = input_key;
      restart_loop();
    }
  } while ((byte)sVar5 != 0x24 || (bool)((char)((ushort)sVar5 >> 8) + '\x04') != (byte)sVar5 < 0x24)
  ;
LAB_rom_02339a:
  frame_leave();
  return 0;
}

