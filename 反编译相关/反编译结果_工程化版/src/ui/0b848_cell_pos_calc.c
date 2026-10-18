/*
 * 主界面与菜单 / 0b848_cell_pos_calc.c
 * 地址范围: 0x0B848 - 0x0BDC2
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 按行列差（下溢归 0）计算单元格位置（0x262B0 取大）
 * @addr 0x0B848
 * @module ui
 * @proto ushort cell_pos_calc(byte a, byte b)
 * @confidence likely
 * @note 按行列差（下溢归 0）计算单元格位置（0x262B0 取大）。
 * @tag matrix
 */
ushort cell_pos_calc(byte _a1, byte _a2)

{
  byte bVar1;
  byte bVar2;
  short sVar3;
  byte bVar6;
  ushort uVar4;
  ushort uVar5;
  short unaff_ER14;
  
  sVar3 = frame_enter();
  bVar1 = (byte)*(undefined2 *)(sVar3 + 2);
  bVar2 = (byte)((ushort)*(undefined2 *)(sVar3 + 2) >> 8);
  if ((char)((bVar1 < bVar2) << 7) < '\0') {
    bVar1 = 0;
  }
  else {
    bVar1 = bVar1 - bVar2;
  }
  bVar2 = (byte)*(undefined2 *)(unaff_ER14 + 0x12);
  bVar6 = (byte)((ushort)*(undefined2 *)(unaff_ER14 + 0x12) >> 8);
  if ((char)((bVar2 < bVar6) << 7) < '\0') {
    bVar2 = 0;
  }
  else {
    bVar2 = bVar2 - bVar6;
  }
  uVar4 = max_u16((ushort)bVar1,(ushort)bVar2);
  uVar5 = max_u16((ushort)*(byte *)(sVar3 + 3),(ushort)*(byte *)(unaff_ER14 + 0x13));
  *(char *)(sVar3 + 3) = (char)uVar5;
  *(char *)(sVar3 + 2) = (char)uVar5 + (char)uVar4;
  frame_leave();
  return;
}

/**
 * @brief 统计表追加行
 * @addr 0x0B8A6
 * @module ui
 * @proto int table_add_row(ushort v)
 * @confidence strong
 * @note 统计表追加行：0xD0F6 行数 × 行宽（10/20）搬移，0x1D1C6 换算，0x23D28 收尾。
 * @tag app
 */
int table_add_row(ushort _a1)

{
  byte bVar1;
  byte bVar2;
  undefined2 *puVar3;
  undefined2 uVar4;
  byte bVar5;
  
  puVar3 = (undefined2 *)frame_enter();
  bVar1 = var_scroll;
  if (var_list_open == '\0') {
    bVar2 = 10;
  }
  else {
    bVar2 = 0x14;
  }
  uVar4 = 0xd400;
  memcpy_bytes((undefined *)puVar3,(undefined *)0xd400,(ushort)var_scroll * (ushort)bVar2);
  for (bVar5 = 0; (char)((bVar5 < bVar1) << 7) < '\0'; bVar5 = bVar5 + 1) {
    dec_bin_init(puVar3,uVar4);
    dec_entry_x(puVar3,uVar4);
    puVar3 = (undefined2 *)((short)puVar3 + (ushort)bVar2);
  }
  table_commit((ushort)bVar1);
  frame_leave();
  return 0;
}

/**
 * @brief 空函数（仅 return），用作调用占位
 * @addr 0x0B90A
 * @module ui
 * @proto void nop_rt(void)
 * @confidence verified
 * @note 空函数（仅 return），用作调用占位。
 * @tag util
 */
int nop_rt(void)

{
  return 0;
}

/**
 * @brief 统计表按键选择单元格
 * @addr 0x0BABE
 * @module ui
 * @proto char stats_cell_key(void)
 * @confidence strong
 * @note 统计表按键选择单元格：数字键 1..4（按 4 列）选列，方向键在 0xAF4 上限内移动，返回 0x5DAA
 *       表对应的单元格类型。
 * @tag app
 */
char stats_cell_key(void)

{
  byte bVar1;
  byte bVar2;
  ushort uVar3;
  short sVar4;
  char cVar5;
  ushort uVar6;
  
LAB_rom_00bac2:
  stat_grid_clear();
  do {
    sVar4 = input_is_empty();
    bVar1 = _DAT_ram_d163;
    bVar2 = (byte)sVar4;
    cVar5 = (char)((ushort)sVar4 >> 8);
    if ((((bVar2 == 0x31 && (bool)cVar5 == bVar2 < 0x31) ||
         (bVar2 == 0x32 && (bool)cVar5 == bVar2 < 0x32)) ||
        (bVar2 == 0x33 && (bool)cVar5 == bVar2 < 0x33)) ||
       (bVar2 == 0x34 && (bool)cVar5 == bVar2 < 0x34)) {
      uVar3 = CONCAT11((char)(((ushort)_DAT_ram_d163 << 2) >> 8),_DAT_ram_d163 << 2) + sVar4 + -0x31;
      if ((ushort)(CONCAT11((char)(((ushort)_DAT_ram_d163 << 2) >> 8),_DAT_ram_d163 << 2) +
                  sVar4 + -0x31) <= (ushort)_DAT_ram_0af4) {
        return *(undefined *)
                (CONCAT11((char)(((uVar3 & 0xff00) + (uVar3 & 0xff)) * 4 >> 8),(char)uVar3 << 2) +
                0x5daa);
      }
    }
    else {
      if (bVar2 == 0x1c && (bool)(cVar5 + '\x04') == bVar2 < 0x1c) {
        if (_DAT_ram_d163 == 0) {
          _DAT_ram_d163 = _DAT_ram_0af4 >> 2;
        }
        else {
          _DAT_ram_d163 = _DAT_ram_d163 - 1;
        }
        goto LAB_rom_00bac2;
      }
      if (bVar2 == 0x1d && (bool)(cVar5 + '\x04') == bVar2 < 0x1d) break;
      if ((bVar2 == 0x25 && (bool)(cVar5 + '\x04') == bVar2 < 0x25) ||
         (bVar2 == 0x26 && (bool)(cVar5 + '\x04') == bVar2 < 0x26)) {
        return 0xe;
      }
    }
    beep();
  } while( true );
  uVar6 = (ushort)_DAT_ram_d163;
  uVar3 = draw_spaced((ushort)_DAT_ram_0af4,4);
  if (uVar3 == uVar6) {
    _DAT_ram_d163 = 0;
  }
  else {
    _DAT_ram_d163 = bVar1 + 1;
  }
  goto LAB_rom_00bac2;
}

/**
 * @brief 更新统计行的计数/累加
 * @addr 0x0BB82
 * @module ui
 * @proto void table_count_update(byte delta)
 * @confidence likely
 * @note 更新统计行的计数/累加：遍历行的起止区间并给匹配项加 delta，同时累加 0xD00E/0xD010。
 * @tag app
 */
int table_count_update(byte delta)

{
  byte bVar1;
  short sVar2;
  short sVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  byte bVar7;
  short unaff_ER14;
  
  sVar2 = frame_enter();
  bVar5 = input_active;
  if (input_active == 0) {
    bVar5 = _DAT_ram_d013;
  }
  if (sVar2 != 0) {
    sVar3 = CONCAT11((char)(((ushort)*(byte *)(unaff_ER14 + 0x12) << 3) >> 8),
                     *(byte *)(unaff_ER14 + 0x12) << 3);
    bVar7 = *(byte *)(sVar3 + -0x241a);
    bVar1 = *(byte *)(sVar3 + -0x2419);
    for (bVar6 = *(byte *)(unaff_ER14 + 0x12); (char)((bVar6 < bVar5) << 7) < '\0';
        bVar6 = bVar6 + 1) {
      bVar4 = *(byte *)(CONCAT11((char)(((ushort)bVar6 << 3) >> 8),bVar6 << 3) + -0x241a);
      if ((bVar7 <= bVar4) && ((char)((bVar4 < bVar1) << 7) < '\0')) {
        sVar3 = CONCAT11((char)(((ushort)bVar6 << 3) >> 8),bVar6 << 3);
        *(short *)(sVar3 + -0x241c) = *(short *)(sVar3 + -0x241c) + sVar2;
      }
    }
  }
  if (*(char *)(unaff_ER14 + 0x10) != '\0') {
    dec_temp_a = dec_temp_a + sVar2;
    dec_regY = dec_regY + delta;
  }
  frame_leave();
  return 0;
}

/**
 * @brief 绘制统计表头
 * @addr 0x0BC7A
 * @module ui
 * @proto int stats_head_draw(void)
 * @confidence strong
 * @note 绘制统计表头：按 0xD112 选 "r="/"c=" 并绘制 a=/b=/r=/c= 列标题。
 * @tag app
 */
int stats_head_draw(void)

{
  byte bVar1;
  int cVar2;
  char *pcVar3;
  short unaff_ER14;
  
  frame_enter();
  bVar1 = sub_mode - 2;
  pcVar3 = "r=";
  screen_mode_blank(0x2b36);
  if (sub_mode == '\x03') {
    pcVar3 = "c=";
  }
  draw_text4x(0x124,*(undefined2 *)((ushort)bVar1 * 2 + 0x7c2e));
  cVar2 = draw_edit_string("a=");
  *(char *)(unaff_ER14 + -4) = cVar2;
  if (cVar2 != '\x01') {
    cVar2 = draw_edit_string("b=");
    *(char *)(unaff_ER14 + -3) = cVar2;
    if (cVar2 != '\x01') {
      cVar2 = draw_edit_string(pcVar3);
      *(char *)(unaff_ER14 + -2) = cVar2;
      if (cVar2 != '\x01') {
        if (((*(char *)(unaff_ER14 + -4) != '\0') && (*(char *)(unaff_ER14 + -3) != '\0')) &&
           (*(char *)(unaff_ER14 + -2) != '\0')) {
          wait_valid_key(*(char *)(unaff_ER14 + -4));
        }
        goto LAB_rom_00bcec;
      }
    }
  }
  wait_valid_key('\x01');
LAB_rom_00bcec:
  frame_leave();
  return 0;
}

/**
 * @brief 带符号 16 位乘法（0x246F4 取绝对值后乘、按符号取补）
 * @addr 0x0BD42
 * @module ui
 * @proto undefined2 mul_signed16(undefined2 a, undefined2 b)
 * @confidence strong
 * @note 带符号 16 位乘法（0x246F4 取绝对值后乘、按符号取补）。
 * @tag util
 */
undefined2 mul_signed16(undefined2 a, undefined2 b)

{
  divmod_signed16(a,b);
  return b;
}

/**
 * @brief 绘制表格行（5.2KB）
 * @addr 0x0BDC2
 * @module ui
 * @proto void draw_table_row(void)
 * @confidence likely
 * @note 绘制表格行（5.2KB）：按行类型绘制标签/数值（0x2BA30 列表调用）。
 * @tag app
 */
int draw_table_row(void)

{
  byte bVar1;
  byte bVar2;
  int bVar3;
  ushort uVar4;
  short sVar5;
  short sVar6;
  byte bVar7;
  short sVar8;
  char cVar10;
  byte bVar11;
  ushort uVar9;
  short sVar12;
  ushort uVar13;
  short unaff_ER14;
  
  bVar2 = frame_enter();
  uVar13 = 0;
  fill_screen(0x400);
  cur_line = 10;
  draw_target = 0;
  sVar12 = 0;
  do {
    sVar8 = 0;
    do {
      *(undefined *)(sVar8 + unaff_ER14 + -0x62) = 0;
      sVar8 = sVar8 + 1;
      bVar3 = (byte)((ushort)sVar8 >> 8);
      bVar7 = bVar3 - ((byte)sVar8 < 0x40);
    } while ((byte)((byte)((bVar7 ^ bVar3) & ~bVar7) >> 7 ^ (char)bVar7 < '\0') == 1);
    sVar8 = sVar12 * 3;
    uVar4 = sVar8 + 1;
    uVar9 = (ushort)*(byte *)(bVar2 + 0x3d34);
    cVar10 = (char)((ushort)unaff_ER14 >> 8);
    bVar7 = (byte)unaff_ER14;
    if ((byte)(SBORROW2(uVar4,uVar9) ^ (short)(uVar4 - uVar9) < 0 | uVar4 == uVar9) == 1) {
      *(undefined *)(unaff_ER14 + -0x62) = *(undefined *)(sVar8 + 0x6474);
      *(undefined *)(unaff_ER14 + -0x61) = _DAT_ram_50be;
      sVar5 = mul16((ushort)bVar2,0x12);
      sVar5 = *(byte *)(sVar5 + sVar8 + 0x4f10) - 1;
      if (-1 < sVar5) {
        uVar13 = CONCAT11((char)((ushort)sVar5 >> 8) + -3 + (0xcf < (byte)sVar5),(byte)sVar5 + 0x30)
        ;
      }
      bVar3 = text_clear_panel(uVar13,(byte *)CONCAT11(cVar10 + -1 + (0x5f < bVar7),bVar7 + 0xa0));
      *(undefined2 *)(unaff_ER14 + -100) = 0;
      sVar5 = 2;
      do {
        if ((0xef < *(byte *)(sVar5 + unaff_ER14 + -0x62)) &&
           (*(char *)(sVar5 + unaff_ER14 + -0x62) != -1)) {
          *(short *)(unaff_ER14 + -100) = *(short *)(unaff_ER14 + -100) + 1;
        }
        sVar5 = sVar5 + 1;
        bVar11 = (byte)((ushort)sVar5 >> 8);
        bVar1 = bVar11 - ((byte)sVar5 < 0x40);
      } while ((byte)((byte)((bVar1 ^ bVar11) & ~bVar1) >> 7 ^ (char)bVar1 < '\0') == 1);
      sVar5 = (ushort)bVar3 + *(short *)(unaff_ER14 + -100) + 2;
      while( true ) {
        sVar6 = *(short *)(unaff_ER14 + -100) + 10;
        *(short *)(unaff_ER14 + -0x66) = sVar6;
        if ((byte)(SBORROW2(sVar5,sVar6) ^ sVar5 - sVar6 < 0) != 1) break;
        *(undefined *)(sVar5 + unaff_ER14 + -0x62) = 0x20;
        sVar5 = sVar5 + 1;
      }
      uVar4 = sVar8 + 2;
      uVar9 = (ushort)*(byte *)(bVar2 + 0x3d34);
      if ((byte)(SBORROW2(uVar4,uVar9) ^ (short)(uVar4 - uVar9) < 0 | uVar4 == uVar9) == 1) {
        *(undefined *)(*(short *)(unaff_ER14 + -0x66) + unaff_ER14 + -0x62) =
             *(undefined *)(sVar8 + 0x6475);
        *(undefined *)(*(short *)(unaff_ER14 + -0x66) + unaff_ER14 + -0x61) = _DAT_ram_50be;
        sVar5 = mul16((ushort)bVar2,0x12);
        sVar5 = *(byte *)(sVar5 + sVar8 + 0x4f11) - 1;
        if (-1 < sVar5) {
          uVar13 = CONCAT11((char)((ushort)sVar5 >> 8) + -3 + (0xcf < (byte)sVar5),
                            (byte)sVar5 + 0x30);
        }
        bVar3 = text_clear_panel(uVar13,(byte *)(*(short *)(unaff_ER14 + -0x66) + 2 )
                                              CONCAT11(cVar10 + -1 + (0x61 < bVar7),bVar7 + 0x9e)));
        *(undefined2 *)(unaff_ER14 + -100) = 0;
        sVar5 = 0xc;
        do {
          if ((0xef < *(byte *)(sVar5 + unaff_ER14 + -0x62)) &&
             (*(char *)(sVar5 + unaff_ER14 + -0x62) != -1)) {
            *(short *)(unaff_ER14 + -100) = *(short *)(unaff_ER14 + -100) + 1;
          }
          sVar5 = sVar5 + 1;
          bVar11 = (byte)((ushort)sVar5 >> 8);
          bVar1 = bVar11 - ((byte)sVar5 < 0x40);
        } while ((byte)((byte)((bVar1 ^ bVar11) & ~bVar1) >> 7 ^ (char)bVar1 < '\0') == 1);
        sVar5 = (ushort)bVar3 + *(short *)(unaff_ER14 + -100) + 0xc;
        while( true ) {
          sVar6 = *(short *)(unaff_ER14 + -100) + 0x14;
          *(short *)(unaff_ER14 + -0x68) = sVar6;
          if ((byte)(SBORROW2(sVar5,sVar6) ^ sVar5 - sVar6 < 0) != 1) break;
          *(undefined *)(sVar5 + unaff_ER14 + -0x62) = 0x20;
          sVar5 = sVar5 + 1;
        }
        uVar4 = sVar8 + 3;
        uVar9 = (ushort)*(byte *)(bVar2 + 0x3d34);
        if ((byte)(SBORROW2(uVar4,uVar9) ^ (short)(uVar4 - uVar9) < 0 | uVar4 == uVar9) != 0) {
          *(undefined *)(*(short *)(unaff_ER14 + -0x68) + unaff_ER14 + -0x62) =
               *(undefined *)(sVar8 + 0x6476);
          *(undefined *)(*(short *)(unaff_ER14 + -0x68) + unaff_ER14 + -0x61) = _DAT_ram_50be;
          sVar5 = mul16((ushort)bVar2,0x12);
          sVar8 = *(byte *)(sVar5 + sVar8 + 0x4f12) - 1;
          if (-1 < sVar8) {
            uVar13 = CONCAT11((char)((ushort)sVar8 >> 8) + -3 + (0xcf < (byte)sVar8),
                              (byte)sVar8 + 0x30);
          }
          text_clear_panel(uVar13,(byte *)(*(short *)(unaff_ER14 + -0x68) + 2 )
                                        CONCAT11(cVar10 + -1 + (0x61 < bVar7),bVar7 + 0x9e)));
        }
      }
    }
    draw_text4x(CONCAT11((char)sVar12 * '\n' + '\x01',1))
                   CONCAT11(cVar10 + -1 + (0x61 < bVar7),bVar7 + 0x9e));
    sVar12 = sVar12 + 1;
    bVar3 = (byte)((ushort)sVar12 >> 8);
    bVar7 = bVar3 - ((byte)sVar12 < 6);
  } while ((bool)((byte)((bVar7 ^ bVar3) & ~bVar7) >> 7) != (char)bVar7 < '\0');
  fb_alt_flush();
  draw_target = 1;
  frame_leave();
  return 0;
}

