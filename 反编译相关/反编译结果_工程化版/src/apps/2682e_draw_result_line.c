/*
 * 应用模式 / 2682e_draw_result_line.c
 * 地址范围: 0x2682E - 0x26FFA
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 绘制结果行
 * @addr 0x2682E
 * @module apps
 * @proto int draw_result_line(void)
 * @confidence strong
 * @note 绘制结果行：按 0xD116 选择 0xD08E(+mult16) 或 0x25362，再逐字符绘制（处理换行）。
 * @tag text
 */
int draw_result_line(void)

{
  byte bVar1;
  bool bVar2;
  byte *pbVar3;
  ushort uVar4;
  undefined extraout_R1;
  byte *pbVar5;
  
  pbVar3 = (byte *)frame_enter();
  bVar1 = line_col_count();
  if (key_modifiers == '\x01') {
    uVar4 = input_char_count(pbVar3);
    mul16((ushort)bVar1,uVar4);
  }
  else {
    return_4();
    while (pbVar5 = pbVar3, *pbVar5 != 0) {
      bVar2 = is_neg_char(*pbVar5);
      pbVar3 = pbVar5 + 1;
      if (CONCAT11(extraout_R1,bVar2) != 0) {
        pbVar3 = pbVar5 + 2;
      }
    }
  }
  frame_leave();
  return 0;
}

/**
 * @brief 0xD111 == 0x4A（EQUA）且 0xD114 == 1 时返回 1
 * @addr 0x26892
 * @module apps
 * @proto char is_mode_4a(void)
 * @confidence strong
 * @note 0xD111 == 0x4A（EQUA）且 0xD114 == 1 时返回 1。
 * @tag mode
 */
char is_mode_4a(void)

{
  if ((calc_mode == 'J') && (edit_state2 == '\x01')) {
    return 1;
  }
  return 0;
}

/**
 * @brief 矩阵单元应用
 * @addr 0x268AA
 * @module apps
 * @proto void mat_cell_apply(byte* p)
 * @confidence likely
 * @note 矩阵单元应用：按 0x27284 的输入把值写入单元（含类型转换）。
 * @tag matrix
 */
int mat_cell_apply(byte* p)

{
  bool bVar1;
  byte bVar2;
  byte *pbVar3;
  undefined extraout_R1;
  ushort uVar4;
  byte *pbVar5;
  short unaff_ER14;
  
  pbVar3 = (byte *)frame_enter();
  if (p == (byte *)0x0) {
    *pbVar3 = 0;
  }
  else {
    uVar4 = 0;
    if (*(short *)(unaff_ER14 + 0x10) != 0) {
      *(short *)(unaff_ER14 + 0x10) = *(short *)(unaff_ER14 + 0x10) + -1;
    }
    for (; (char)((uVar4 < *(ushort *)(unaff_ER14 + 0x10)) << 7) < '\0'; uVar4 = uVar4 + 1) {
      pbVar5 = p + 1;
      bVar1 = is_neg_char(*p);
      if (CONCAT11(extraout_R1,bVar1) != 0) {
        pbVar5 = p + 2;
      }
      p = pbVar5;
    }
    bVar2 = strline_len((char *)p);
    for (uVar4 = bVar2 + 1; (char)uVar4 != '\0' || (char)(uVar4 >> 8) != '\0'; uVar4 = uVar4 - 1) {
      *pbVar3 = *p;
      pbVar3 = pbVar3 + 1;
      p = p + 1;
    }
  }
  frame_leave();
  return 0;
}

/**
 * @brief 对 pos 与 pos+1 两个单元格调用 0x1F9D4 绘制
 * @addr 0x26906
 * @module apps
 * @proto void cell_draw_pair(ushort pos, ushort code)
 * @confidence likely
 * @note 对 pos 与 pos+1 两个单元格调用 0x1F9D4 绘制。
 * @tag ui
 */
int cell_draw_pair(ushort pos, ushort code)

{
  draw_cell_at(pos,code);
  draw_cell_at((uintptr_t)pos + 1,code);
  return 0;
}

/**
 * @brief 在 token 数组中查找（1.1KB，0xAFAE 使用）
 * @addr 0x2696E
 * @module apps
 * @proto byte token_array_find(char* s)
 * @confidence likely
 * @note 在 token 数组中查找（1.1KB，0xAFAE 使用）。
 * @tag parser
 */
byte token_array_find(char* s)

{
  byte bVar1;
  undefined uVar2;
  byte bVar3;
  byte bVar4;
  short sVar5;
  char cVar6;
  byte bVar7;
  short unaff_ER14;
  
  sVar5 = frame_enter();
  bVar1 = strline_len(*(char **)(unaff_ER14 + 0x10));
  bVar7 = 0;
  for (bVar4 = 0; bVar4 <= bVar1; bVar4 = bVar4 + 1) {
    bVar3 = bVar7;
    if (*(char *)((ushort)bVar4 + sVar5) != '\0') {
      if (*(char *)((ushort)bVar4 + sVar5) == '\x01') {
        uVar2 = 0x60;
      }
      else {
        uVar2 = 0xd0;
      }
      *(undefined *)((ushort)bVar4 + s + (ushort)bVar7) = uVar2;
      bVar3 = bVar7 + 1;
      cVar6 = '\0';
      if (*(char *)((ushort)bVar4 + sVar5) == '\x04') {
        cVar6 = -0x30;
      }
      if (*(char *)((ushort)bVar4 + sVar5) == '\x03') {
        cVar6 = '`';
      }
      if (cVar6 != '\0') {
        *(char *)((ushort)bVar4 + s + (ushort)bVar3) = cVar6;
        bVar3 = bVar7 + 2;
      }
    }
    *(undefined *)((ushort)bVar4 + s + (ushort)bVar3) =
         *(undefined *)((ushort)bVar4 + *(short *)(unaff_ER14 + 0x10));
    bVar7 = bVar3;
  }
  frame_leave();
  return;
}

/**
 * @brief 0xD0F5 == 0、0xD113 == 0、0xD116 == 1 时返回 1（空闲编辑…
 * @addr 0x26A1C
 * @module apps
 * @proto char is_idle_editing(void)
 * @confidence strong
 * @note 0xD0F5 == 0、0xD113 == 0、0xD116 == 1 时返回 1（空闲编辑态）。
 * @tag ui
 */
char is_idle_editing(void)

{
  if (diag_mode != '\0') {
    return 0;
  }
  if (input_layout != '\0') {
    return 0;
  }
  if (key_modifiers != '\x01') {
    return 0;
  }
  return 1;
}

/**
 * @brief 单元行列数与矩阵表不一致时调用 0x1E96A 重建
 * @addr 0x26BBA
 * @module apps
 * @proto void matrix_ensure_dims(byte* dim)
 * @confidence strong
 * @note 单元行列数与矩阵表不一致时调用 0x1E96A 重建。
 * @tag matrix
 */
int matrix_ensure_dims(byte* dim)

{
  byte bVar1;
  
  bVar1 = frame_enter();
  if ((*(char *)((ushort)bVar1 * 2 + -0x2f08) != *dim) ||
     (dim[1] != *(char *)((ushort)bVar1 * 2 + -0x2f07))) {
    matrix_set_dims(dim[1]);
  }
  frame_leave();
  return 0;
}

/**
 * @brief 统计网格重绘
 * @addr 0x26F24
 * @module apps
 * @proto void stat_grid_clear(void)
 * @confidence strong
 * @note 统计网格重绘：清屏后从 0xD163 起逐行清空（0x400 缓冲）。
 * @tag app
 */
int stat_grid_clear(void)

{
  byte bVar1;
  ushort uVar2;
  short sVar3;
  byte bVar4;
  
  fill_screen(0x400);
  draw_target = 0;
  sVar3 = 0;
  do {
    cur_line = 0xe;
    uVar2 = CONCAT11((char)(((ushort)_DAT_ram_d163 << 2) >> 8),_DAT_ram_d163 << 2) + sVar3;
    bVar1 = (char)sVar3 * '\x10' + 1;
    draw_format_string(CONCAT11(bVar1,0x16), (uintptr_t)0)
                   *(char **)(CONCAT11((char)(((uVar2 & 0xff00) + (uVar2 & 0xff)) * 4 >> 8),
                                       (char)uVar2 << 2) + 0x5dac));
    draw_char_fast((ushort)bVar1 << 8,*(byte *)(sVar3 + 0x6474));
    draw_char_fast(CONCAT11(bVar1,0xb),_DAT_ram_50be);
    if ((short)(ushort)_DAT_ram_0af4 <=
        CONCAT11((char)(((ushort)_DAT_ram_d163 << 2) >> 8),_DAT_ram_d163 << 2) + sVar3) break;
    sVar3 = sVar3 + 1;
    bVar4 = (byte)((ushort)sVar3 >> 8);
    bVar1 = bVar4 - ((byte)sVar3 < 4);
  } while ((byte)((byte)((bVar1 ^ bVar4) & ~bVar1) >> 7 ^ (char)bVar1 < '\0') == 1);
  fb_alt_flush();
  draw_target = 1;
  draw_cursor_box();
  return 0;
}

/**
 * @brief 表格计算页绘制（3.4KB，0x28C10 调用）
 * @addr 0x26FFA
 * @module apps
 * @proto void table_calc_page(void)
 * @confidence likely
 * @note 表格计算页绘制（3.4KB，0x28C10 调用）。
 * @tag app
 */
int table_calc_page(uintptr_t _a2, int _a1)

{
  byte bVar1;
  ushort uVar2;
  byte bVar7;
  short sVar3;
  short sVar4;
  short sVar5;
  ushort uVar6;
  byte bVar8;
  char cVar9;
  ushort uVar10;
  short unaff_ER14;
  
  uVar2 = frame_enter();
  bVar7 = (byte)(uVar2 >> 8);
  fill_screen(0x400);
  draw_target = 0;
  cur_line = 0xe;
  uVar10 = CONCAT11((char)(((ushort)_a1 << 2) >> 8),_a1 << 2);
  *(undefined2 *)(unaff_ER14 + -2) = 0;
  do {
    sVar3 = 0;
    while( true ) {
      *(short *)(unaff_ER14 + -4) = sVar3;
      if ((short)(uVar2 & 0xff) <= *(short *)(unaff_ER14 + -4)) break;
      if (bVar7 == uVar10) {
        cursor_visible = 4;
      }
      sVar3 = mul16(uVar10,6);
      sVar3 = *(short *)(sVar3 + 0x668a);
      sVar4 = mul16(*(ushort *)(unaff_ER14 + -2),0x18);
      *(short *)(unaff_ER14 + -10) = sVar4;
      *(short *)(unaff_ER14 + -6) = sVar4 + 2;
      sVar5 = mul16(*(ushort *)(unaff_ER14 + -4),0x30);
      *(short *)(unaff_ER14 + -8) = sVar5;
      *(short *)(unaff_ER14 + -0xc) = sVar5 + 1;
      draw_list_scroller3((byte *)CONCAT11((char)(sVar4 + 2),(char)(sVar5 + 1)),0x172f,sVar3);
      cursor_visible = 0;
      if (bVar7 == uVar10) {
        px_clear(CONCAT11(*(undefined *)(unaff_ER14 + -6),*(undefined *)(unaff_ER14 + -0xc)));
        px_clear(CONCAT11(*(undefined *)(unaff_ER14 + -6),*(char *)(unaff_ER14 + -8) + '.'));
        cVar9 = (char)*(undefined2 *)(unaff_ER14 + -8) + '/';
        px_clear(CONCAT11(*(undefined *)(unaff_ER14 + -6),cVar9));
        draw_list_scroller(CONCAT11(*(char *)(unaff_ER14 + -10) + '\x17', (uintptr_t)0)
                                *(undefined *)(unaff_ER14 + -0xc)),0x201);
        px_clear(CONCAT11(*(char *)(unaff_ER14 + -10) + '\x18',cVar9));
      }
      bVar8 = (byte)(uVar10 >> 8);
      bVar1 = bVar8 - ((byte)uVar10 < 0x12);
      if ((bool)((byte)((bVar1 ^ bVar8) & ~bVar1) >> 7) != (char)bVar1 < '\0') {
        if (bVar7 != uVar10) {
          cursor_visible = 4;
        }
        cur_line = 8;
        draw_char_fast(CONCAT11(*(char *)(unaff_ER14 + -10) + '\x10', (uintptr_t)0)
                                *(char *)(unaff_ER14 + -8) + '('),*(byte *)(uVar10 + 0x6474));
        cursor_visible = 0;
      }
      uVar10 = uVar10 + 1;
      uVar6 = (ushort)mode_count;
      if ((byte)(SBORROW2(uVar10,uVar6) ^ (short)(uVar10 - uVar6) < 0 | uVar10 == uVar6) == 0)
      goto LAB_rom_027126;
      sVar3 = *(short *)(unaff_ER14 + -4) + 1;
    }
    sVar3 = *(short *)(unaff_ER14 + -2) + 1;
    *(short *)(unaff_ER14 + -2) = sVar3;
    bVar8 = (byte)((ushort)sVar3 >> 8);
    bVar1 = bVar8 - ((byte)sVar3 < 2);
  } while ((bool)((byte)((bVar1 ^ bVar8) & ~bVar1) >> 7) != (char)bVar1 < '\0');
LAB_rom_027126:
  cur_line = 0xe;
  sVar3 = mul16((ushort)bVar7,6);
  draw_format_string(0x3316,*(char **)(sVar3 + 0x668e));
  if (bVar7 < 0x12) {
    draw_char_fast(0x3300,*(byte *)(bVar7 + 0x6474));
    draw_char_fast(0x330b,_DAT_ram_50be);
  }
  fb_alt_flush();
  draw_target = 1;
  if ((byte)(SBORROW2((ushort)mode_count,(uVar2 & 0xff) * 2) ^
            (short)((ushort)mode_count + (uVar2 & 0xff) * -2) < 0) != 1) {
    uVar10 = (ushort)mode_count;
    if ((char)uVar2 != '\0') {
      uVar10 = uVar10 / (uVar2 & 0xff);
    }
    if ((ushort)_a1 != uVar10 - 1) {
      lcd_set_status_x();
    }
    if (_a1 != 0) {
      show_error_press_ac();
    }
  }
  frame_leave();
  return 0;
}

