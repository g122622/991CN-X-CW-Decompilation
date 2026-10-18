/*
 * 应用模式 / 2950c_mode_c4_disp_loop.c
 * 地址范围: 0x2950C - 0x29BA8
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 0xD111==0xC4（默认分支）
 * @addr 0x2950C
 * @module apps
 * @proto void mode_c4_disp_loop(byte* input)
 * @confidence strong
 * @note 【0xD111==0xC4（默认分支）】主循环：编辑/滚动显示并等待按键。
 * @tag mode
 */
int mode_c4_disp_loop(byte* input)

{
  char cVar1;
  bool bVar2;
  short sVar3;
  byte bVar4;
  char cVar5;
  
  cVar1 = calc_mode;
  key_repeat_start();
  do {
    ui_update();
    fb_flush();
    sVar3 = process_key((short)input);
    if (cVar1 == -0x3c) {
      sVar3 = key_filter_52e8(sVar3);
    }
    set_input_key(sVar3);
    cVar5 = (char)((ushort)sVar3 >> 8);
    bVar4 = (byte)sVar3;
    if (((edit_state2 & 0x80) == 0) ||
       (((bVar4 != 0x2d || (bool)(cVar5 + '\x04') != bVar4 < 0x2d &&
         (bVar4 != 0x30 || (bool)(cVar5 + '\x04') != bVar4 < 0x30)) || ((key_modifiers & 0x40) != 0))
       )) {
      if (bVar4 == 0x3c && (bool)(cVar5 + '\x04') == bVar4 < 0x3c) {
        bVar2 = input_is_empty();
        if (!bVar2) {
          edit_state_set(-0x60);
          goto LAB_rom_02953c;
        }
      }
      else if ((bVar4 == 0x3d && (bool)(cVar5 + '\x04') == bVar4 < 0x3d) &&
              (bVar2 = input_is_empty(), !bVar2)) {
        edit_state_set(-0x40);
        goto LAB_rom_02953c;
      }
    }
    else {
LAB_rom_02953c:
      var_edit_entry(input);
      sVar3 = input_key;
    }
    if ((byte)sVar3 == 0x24 && (bool)((char)((ushort)sVar3 >> 8) + '\x04') == (byte)sVar3 < 0x24) {
      return 0;
    }
  } while( true );
}

/**
 * @brief 在 0xD169 行表中按 (c - 0xD144) 查找匹配行，返回 (行号标志<<8)|…
 * @addr 0x29594
 * @module apps
 * @proto ushort find_table_row(char c)
 * @confidence likely
 * @note 在 0xD169 行表中按 (c - 0xD144) 查找匹配行，返回 (行号标志<<8)|行号。
 * @tag table
 */
ushort find_table_row(char c)

{
  char cVar1;
  byte bVar2;
  
  bVar2 = 0;
  cVar1 = input_ptr;
  while ((irq_pending_shadow = 0, bVar2 < input_active &&
         (cVar1 = (char)(((ushort)bVar2 << 3) >> 8), irq_pending_shadow = bVar2,
         *(char *)(CONCAT11(cVar1,bVar2 << 3) + -0x241a) != (char)(c - input_ptr)))) {
    bVar2 = bVar2 + 1;
  }
  return CONCAT11(cVar1,irq_pending_shadow);
}

/**
 * @brief 根据统计/图形模式与 0x1EDCC 结果重算表格（清 0xD169 并调用 0xA326）
 * @addr 0x295D6
 * @module apps
 * @proto void recalc_table(void)
 * @confidence likely
 * @note 根据统计/图形模式与 0x1EDCC 结果重算表格（清 0xD169 并调用 0xA326）。
 * @tag table
 */
int recalc_table(void)

{
  char cVar1;
  undefined2 uVar2;
  
  uVar2 = frame_enter();
  cVar1 = is_math_io();
  if ((cVar1 == '\0') && (cVar1 = is_special_editing(), cVar1 == '\0')) {
    input_active = 0;
  }
  cVar1 = is_key_3e_1e_1f((byte)uVar2,(char)((ushort)uVar2 >> 8));
  if (cVar1 == '\0') {
    input_active = 0;
  }
  edit_loop_main((uintptr_t)0);
  frame_leave();
  return 0;
}

/**
 * @brief 在 (0x113/0x13D/0x167/0x191, 0x30) 处按 n 绘制列标签
 * @addr 0x29AEA
 * @module apps
 * @proto void draw_column_labels(byte n)
 * @confidence likely
 * @note 在 (0x113/0x13D/0x167/0x191, 0x30) 处按 n 绘制列标签。
 * @tag ui
 */
int draw_column_labels(byte n)

{
  draw_vline(0x113,0x30);
  draw_vline(0x13d,0x30);
  if (1 < n) {
    draw_vline(0x167,0x30);
  }
  if (2 < n) {
    draw_vline(0x191,0x30);
  }
  return 0;
}

/**
 * @brief 循环读键直到方向键（0x24-0x27），按 0x24/0x25 返回 1，0x26/0x2…
 * @addr 0x29B2C
 * @module apps
 * @proto byte wait_dir_key(void)
 * @confidence strong
 * @note 循环读键直到方向键（0x24-0x27），按 0x24/0x25 返回 1，0x26/0x27 返回 0。
 * @tag key
 */
byte wait_dir_key(void)

{
  byte bVar1;
  char extraout_R1;
  
  do {
    bVar1 = input_is_empty();
    if ((bVar1 == 0x24 && (bool)(extraout_R1 + '\x04') == bVar1 < 0x24) ||
       (bVar1 == 0x25 && (bool)(extraout_R1 + '\x04') == bVar1 < 0x25)) {
      return 1;
    }
  } while ((bVar1 != 0x26 || (bool)(extraout_R1 + '\x04') != bVar1 < 0x26) &&
          (bVar1 != 0x27 || (bool)(extraout_R1 + '\x04') != bVar1 < 0x27));
  return 0;
}

/**
 * @brief 0xD111==3，推测为 TABLE 表格模式
 * @addr 0x29B58
 * @module apps
 * @proto void mode_03_table_loop(byte* input)
 * @confidence strong
 * @note 【0xD111==3，推测为 TABLE 表格模式】主循环：切换到子模式 1 后运行编辑循环。
 * @tag mode
 */
int mode_03_table_loop(byte* input)

{
  short sVar1;
  
  if (sub_mode == '\0') {
    sub_mode = '\x01';
    key_repeat_start();
  }
  do {
    if (edit_state2 == '\x12') {
      list_ui_loop(input);
      sVar1 = input_key;
    }
    else {
      ui_update();
      fb_flush();
      sVar1 = process_key((short)input);
      sVar1 = key_filter_lookup4(sVar1);
      set_input_key(sVar1);
    }
  } while ((byte)sVar1 != 0x24 || (bool)((char)((ushort)sVar1 >> 8) + '\x04') != (byte)sVar1 < 0x24)
  ;
  return 0;
}

/**
 * @brief 统计模式主循环（3.6KB，0x27284 调用）
 * @addr 0x29BA8
 * @module apps
 * @proto int stat_mode_main(void)
 * @confidence likely
 * @note 统计模式主循环（3.6KB，0x27284 调用）。
 * @tag app
 */
int stat_mode_main(uintptr_t _a2, int _a1)

{
  byte bVar1;
  char cVar2;
  byte bVar3;
  byte bVar4;
  short *psVar5;
  bool bVar7;
  ushort uVar6;
  byte bVar8;
  ushort uVar9;
  short sVar10;
  short sVar11;
  char *pcVar12;
  short unaff_ER14;
  
  psVar5 = (short *)frame_enter();
  bVar1 = cur_line;
  **(undefined **)(unaff_ER14 + 0x14) = 0;
  sVar10 = *psVar5 + (ushort)bVar1;
  sVar11 = sVar10 + (ushort)bVar1;
  bVar3 = (byte)sVar11;
  bVar8 = (byte)((ushort)sVar11 >> 8);
  bVar4 = bVar8 - (bVar3 < 0x41);
  if ((byte)((byte)((bVar4 ^ bVar8) & ~bVar4) >> 7 ^ (char)bVar4 < '\0' |
            (bVar3 == 0x41 && bVar4 == 0)) == 0) {
    cVar2 = is_modifier_1();
    if ((cVar2 != '\0') && (**(byte **)(unaff_ER14 + 0x12) != 0)) {
      if (*(char *)(unaff_ER14 + 0x16) == '\0') {
        sVar11 = (ushort)bVar1 + (ushort)**(byte **)(unaff_ER14 + 0x12);
        bVar4 = (byte)sVar11;
        bVar7 = SUB21((ushort)sVar11 >> 8,0);
        if (((char)(bVar7 - (bVar4 < 0x41)) < '\0' || bVar4 == 0x41 && bVar7 == bVar4 < 0x41) ||
           (**(byte **)(unaff_ER14 + 0x10) < 0xc0)) goto LAB_rom_029c02;
        **(byte **)(unaff_ER14 + 0x10) = history_key;
      }
      uVar6 = CONCAT11(1,calc_mode);
      if (calc_mode == '\x02') {
        uVar6 = 0xf00;
      }
      if ((ushort)**(byte **)(unaff_ER14 + 0x12) < (ushort)bVar1 + (uVar6 >> 8))
      goto LAB_rom_029c02;
      **(char **)(unaff_ER14 + 0x12) = **(char **)(unaff_ER14 + 0x12) - bVar1;
    }
    **(undefined **)(unaff_ER14 + 0x14) = 1;
    bVar4 = bVar1;
    if (calc_mode != '\x02') {
      *(undefined *)(unaff_ER14 + -3) = 0;
      if (_DAT_ram_d15a == '\0') {
        bVar3 = bVar1 + 1;
        *(byte *)(unaff_ER14 + -2) = bVar3;
        *(byte *)(unaff_ER14 + -1) = bVar3 + bVar1;
        uVar6 = (ushort)bVar3;
        uVar9 = *_a1;
        if ((byte)(SBORROW2(uVar9,uVar6) ^ (short)(uVar9 - uVar6) < 0 | uVar9 == uVar6) == 1) {
          bVar8 = (byte)(uVar9 >> 8);
          bVar3 = bVar8 - ((char)uVar9 == '\0');
          if (((byte)((byte)((bVar3 ^ bVar8) & ~bVar3) >> 7 ^ (char)bVar3 < '\0' |
                     ((char)uVar9 == '\x01' && bVar3 == 0)) != 1) &&
             ((short)uVar9 < (short)(ushort)*(byte *)(unaff_ER14 + -2))) {
            *(undefined *)(unaff_ER14 + -3) = 1;
          }
        }
        else if (((short)*_a1 < (short)(ushort)*(byte *)(unaff_ER14 + -1)) &&
                (sVar11 = *_a1 + 0x3f, bVar3 = (byte)sVar11,
                sVar10 = CONCAT11(((char)((ushort)sVar11 >> 8) - (char)((ushort)sVar10 >> 8)) -
                                  (bVar3 < (byte)sVar10),bVar3 - (byte)sVar10),
                SBORROW2(sVar10,(ushort)bVar1 * 2) != (short)(sVar10 + (ushort)bVar1 * -2) < 0)) {
          *(undefined *)(unaff_ER14 + -3) = 1;
        }
      }
      if (*(char *)(unaff_ER14 + -3) != '\0') {
        bVar4 = (char)*_a1 - 1;
        bVar3 = bVar4 - bVar1;
        bVar8 = (byte)*psVar5;
        *psVar5 = CONCAT11(((char)((ushort)*psVar5 >> 8) + (bVar4 < bVar1)) - (bVar8 < bVar3),
                           bVar8 - bVar3);
        pcVar12 = *(char **)(unaff_ER14 + 0x12);
        if (*pcVar12 != '\0') {
          *pcVar12 = *pcVar12 - bVar3;
        }
        if (bVar4 < bVar1) {
          **(undefined **)(unaff_ER14 + 0x14) = 0;
        }
      }
    }
    bVar3 = (byte)*_a1;
    cVar2 = (char)(*_a1 >> 8) - (bVar3 < bVar4);
    *_a1 = CONCAT11(cVar2,bVar3 - bVar4);
    if (cVar2 < '\0') {
      *_a1 = (ushort)bVar1 + *_a1;
    }
    scroll_screen(bVar4);
  }
  else {
    *psVar5 = sVar10;
  }
LAB_rom_029c02:
  frame_leave();
  return 0;
}

