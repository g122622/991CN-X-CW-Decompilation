/*
 * 应用模式 / 28c10_menu_router_main.c
 * 地址范围: 0x28C10 - 0x293D2
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 菜单/视图路由（7.2KB，0x263C8 调用）
 * @addr 0x28C10
 * @module apps
 * @proto int menu_router_main(void)
 * @confidence strong
 * @note 菜单/视图路由（7.2KB，0x263C8 调用）。
 * @tag ui
 */
int menu_router_main(void)

{
  byte bVar1;
  char cVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  ushort uVar6;
  undefined2 uVar7;
  char cVar10;
  undefined2 uVar8;
  short sVar9;
  ushort uVar11;
  byte bVar12;
  byte bVar13;
  
  frame_enter();
  if (mode_count < 4) {
    bVar1 = mode_count + 1;
  }
  else {
    bVar1 = 4;
  }
  uVar6 = mul_signed16(mode_count + 1,(ushort)bVar1);
  bVar5 = mode_group;
  bVar12 = mode_index;
  bVar13 = (byte)uVar6;
  if ((byte)uVar6 == 0) {
    bVar13 = bVar1;
  }
LAB_rom_028c4a:
  table_calc_page(bVar5);
  do {
    uVar7 = input_is_empty();
    cVar10 = (char)((ushort)uVar7 >> 8);
    cVar2 = is_arrow_key((byte)uVar7,cVar10);
    if (cVar2 != '\0') {
      key_flag_bit7();
    }
    uVar8 = is_menu_range(uVar7);
    if ((char)uVar8 != '\0') {
      uVar7 = menu_code_map((byte)uVar7,cVar10);
    }
    bVar4 = (byte)uVar7;
    cVar2 = (char)((ushort)uVar7 >> 8);
    if (((((bVar4 == 0x31 && (bool)cVar2 == bVar4 < 0x31) ||
          (bVar4 == 0x32 && (bool)cVar2 == bVar4 < 0x32)) ||
         (bVar4 == 0x33 && (bool)cVar2 == bVar4 < 0x33)) ||
        ((bVar4 == 0x34 && (bool)cVar2 == bVar4 < 0x34 ||
         (bVar4 == 0x35 && (bool)cVar2 == bVar4 < 0x35)))) ||
       (((bVar4 == 0x36 && (bool)cVar2 == bVar4 < 0x36 ||
         ((bVar4 == 0x37 && (bool)cVar2 == bVar4 < 0x37 ||
          (bVar4 == 0x38 && (bool)cVar2 == bVar4 < 0x38)))) ||
        (bVar4 == 0x39 && (bool)cVar2 == bVar4 < 0x39)))) {
      bVar4 = bVar4 - 0x31;
LAB_rom_028ef2:
      mul16((ushort)bVar4,6);
      if (bVar4 <= mode_count) {
        uVar6 = (ushort)bVar4;
        if (bVar1 != 0) {
          uVar6 = uVar6 / bVar1;
        }
        if (bVar5 < uVar6) {
          uVar6 = (ushort)bVar13 + (ushort)bVar4;
          uVar11 = (ushort)mode_count;
          if ((byte)(SBORROW2(uVar6,uVar11) ^ (short)(uVar6 - uVar11) < 0 | uVar6 == uVar11) == 0)
          goto LAB_rom_028f3c;
          bVar5 = bVar4;
          if (bVar1 != 0) {
            bVar5 = bVar4 / bVar1;
          }
          mode_group = bVar5 - 1;
        }
        else {
LAB_rom_028f3c:
          mode_group = bVar4;
          if (bVar1 != 0) {
            mode_group = bVar4 / bVar1;
          }
        }
        uVar6 = (ushort)bVar13 + (ushort)bVar4;
        uVar11 = (ushort)mode_count;
        if ((byte)(SBORROW2(uVar6,uVar11) ^ (short)(uVar6 - uVar11) < 0 | uVar6 == uVar11) != 1) {
          mode_group = mode_group - 1;
        }
        mode_index = bVar4;
        if ((char)((mode_count < 4) << 7) < '\0') {
          mode_group = 0;
        }
LAB_rom_028da2:
        key_flag_clear();
        frame_leave();
        return 0;
      }
    }
    else {
      if (bVar4 == 0x40 && (bool)cVar2 == bVar4 < 0x40) {
        bVar4 = 0xf;
        goto LAB_rom_028ef2;
      }
      if ((((bVar4 == 0x42 && (bool)cVar2 == bVar4 < 0x42) ||
           (bVar4 == 0x43 && (bool)cVar2 == bVar4 < 0x43)) ||
          (bVar4 == 0x44 && (bool)cVar2 == bVar4 < 0x44)) ||
         (((bVar4 == 0x45 && (bool)cVar2 == bVar4 < 0x45 ||
           (bVar4 == 0x46 && (bool)cVar2 == bVar4 < 0x46)) ||
          (bVar4 == 0x47 && (bool)cVar2 == bVar4 < 0x47)))) {
        bVar4 = bVar4 - 0x39;
        goto LAB_rom_028ef2;
      }
      if ((bVar4 == 0x48 && (bool)cVar2 == bVar4 < 0x48) ||
         (bVar4 == 0x49 && (bool)cVar2 == bVar4 < 0x49)) {
        bVar4 = bVar4 - 0x38;
        goto LAB_rom_028ef2;
      }
      if (bVar4 == 0x1c && (bool)(cVar2 + '\x04') == bVar4 < 0x1c) {
        if ((char)((bVar12 < bVar1) << 7) < '\0') {
          if (bVar12 < bVar1) {
            bVar5 = mode_count;
            if (bVar1 != 0) {
              bVar5 = mode_count / bVar1;
            }
            bVar12 = bVar12 + bVar5 * bVar1;
            bVar5 = bVar5 - 1;
            if (mode_count < bVar12) {
              bVar12 = mode_count;
            }
            if (mode_count < 4) {
              bVar5 = 0;
            }
          }
        }
        else {
          bVar12 = bVar12 - bVar1;
        }
        bVar3 = bVar12;
        if ((short)(ushort)bVar12 < (short)((ushort)bVar5 * (ushort)bVar1)) {
          bVar5 = bVar5 - 1;
        }
        goto LAB_rom_028d88;
      }
      bVar3 = mode_count;
      if (bVar4 == 0x1d && (bool)(cVar2 + '\x04') == bVar4 < 0x1d) {
        uVar6 = (ushort)bVar1 + (ushort)bVar12;
        uVar11 = (ushort)mode_count;
        if ((byte)(SBORROW2(uVar6,uVar11) ^ (short)(uVar6 - uVar11) < 0 | uVar6 == uVar11) == 0) {
          uVar6 = (ushort)bVar12;
          if (bVar1 != 0) {
            uVar6 = uVar6 / bVar1;
          }
          uVar11 = (ushort)mode_count;
          if (bVar1 != 0) {
            uVar11 = uVar11 / bVar1;
          }
          if (uVar11 <= uVar6) {
            bVar4 = bVar1;
            if (bVar1 != 0) {
              bVar4 = mode_count % bVar1;
            }
            uVar11 = CONCAT11(-(mode_count < bVar4),mode_count - bVar4);
            uVar6 = (ushort)bVar12;
            bVar3 = bVar12;
            if ((byte)(SBORROW2(uVar11,uVar6) ^ (short)(uVar11 - uVar6) < 0 | uVar11 == uVar6) != 0)
            {
              bVar3 = bVar1;
              if (bVar1 != 0) {
                bVar3 = bVar12 % bVar1;
              }
              bVar5 = 0;
            }
          }
        }
        else {
          bVar3 = bVar12 + bVar1;
        }
        uVar6 = (ushort)bVar5 * (ushort)bVar1 + 7;
        uVar11 = (ushort)bVar3;
        if ((byte)(SBORROW2(uVar11,uVar6) ^ (short)(uVar11 - uVar6) < 0 | uVar11 == uVar6) == 0) {
          bVar5 = bVar5 + 1;
        }
        goto LAB_rom_028d88;
      }
      if (bVar4 == 0x1e && (bool)(cVar2 + '\x04') == bVar4 < 0x1e) {
        if (mode_count == bVar12) {
          bVar12 = 0;
          bVar5 = 0;
        }
        else if (bVar12 < mode_count) {
          bVar12 = bVar12 + 1;
        }
        sVar9 = mul16(bVar5 + 2,(ushort)bVar1);
        bVar3 = bVar12;
        if (sVar9 <= (short)(ushort)bVar12) {
          bVar5 = bVar5 + 1;
        }
        goto LAB_rom_028d88;
      }
      if (bVar4 == 0x1f && (bool)(cVar2 + '\x04') == bVar4 < 0x1f) break;
      if ((bVar4 == 0x24 && (bool)(cVar2 + '\x04') == bVar4 < 0x24) ||
         (bVar4 == 0x26 && (bool)(cVar2 + '\x04') == bVar4 < 0x26)) goto LAB_rom_028da2;
      if ((bVar4 == 0x2d && (bool)(cVar2 + '\x04') == bVar4 < 0x2d) ||
         (bVar4 == 0x30 && (bool)(cVar2 + '\x04') == bVar4 < 0x30)) {
        mul16((ushort)bVar12,6);
        mode_index = bVar12;
        mode_group = bVar5;
        goto LAB_rom_028da2;
      }
    }
    key_flag_clear();
    beep();
  } while( true );
  if (bVar12 == 0) {
    bVar5 = mode_count;
    if (bVar1 != 0) {
      bVar5 = mode_count / bVar1;
    }
    bVar5 = bVar5 - 1;
    if ((char)((mode_count < 4) << 7) < '\0') {
      bVar5 = 0;
    }
  }
  else {
    if (bVar12 != 0) {
      bVar12 = bVar12 - 1;
    }
    bVar3 = bVar12;
    if ((byte)(SBORROW2((ushort)bVar12,(ushort)bVar5 * (ushort)bVar1) ^
              (short)((ushort)bVar12 - (ushort)bVar5 * (ushort)bVar1) < 0) == 1) {
      bVar5 = bVar5 - 1;
    }
  }
LAB_rom_028d88:
  var_menu();
  bVar12 = bVar3;
  goto LAB_rom_028c4a;
}

/**
 * @brief 按 0xD132/0xD167/0xD168 绘制表格形状与数据（0xF746 使用）
 * @addr 0x29358
 * @module apps
 * @proto void table_shape_draw(void)
 * @confidence likely
 * @note 按 0xD132/0xD167/0xD168 绘制表格形状与数据（0xF746 使用）。
 * @tag app
 */
int table_shape_draw(uintptr_t _a2, int _a1)

{
  char cVar1;
  byte bVar2;
  undefined uVar3;
  char cVar4;
  byte bVar5;
  short unaff_ER14;
  
  uVar3 = frame_enter();
  bVar2 = hl_col2;
  cVar1 = hl_row2;
  if (((input_disp_mode == '|') && (10 < hl_col2)) &&
     ((hl_col2 != 0xe || (cur_line != '\x0e')))) {
    *_a1 = hl_row2;
    if (*(char *)(unaff_ER14 + 0x12) != '\0') {
      bVar5 = 1;
      cVar4 = hl_line;
      do {
        draw_vline(CONCAT11(cVar1,cVar4),(ushort)(byte)((bVar2 + cVar1) - 1));
        bVar5 = bVar5 + 1;
        cVar4 = cVar4 + '\x01';
      } while (bVar5 < 4);
    }
  }
  else {
    *_a1 = hl_col;
    if (*(char *)(unaff_ER14 + 0x12) != '\0') {
      draw_char(CONCAT11(*_a1,uVar3),*(ushort *)(unaff_ER14 + 0x10));
    }
  }
  frame_leave();
  return 0;
}

/**
 * @brief 列表视图主流程（2.7KB，0x23A3E 调用）
 * @addr 0x293D2
 * @module apps
 * @proto void list_view_main(void)
 * @confidence likely
 * @note 列表视图主流程（2.7KB，0x23A3E 调用）。
 * @tag ui
 */
int list_view_main(void)

{
  int bVar1;
  byte bVar2;
  byte bVar3;
  int cVar4;
  bool bVar5;
  byte **ppbVar6;
  byte *pbVar7;
  ushort uVar8;
  undefined2 uVar9;
  byte *pbVar10;
  undefined extraout_R1;
  byte bVar11;
  byte *pbVar12;
  short unaff_ER14;
  
  ppbVar6 = (byte **)frame_enter();
  *(undefined *)(unaff_ER14 + -0x28) = 0;
  *(undefined *)(unaff_ER14 + -0x27) = 0;
  bVar1 = line_col_count();
  pbVar10 = input_ptr;
  bVar1 = draw_spaced(CONCAT11(-(0xc0 < history_key),-0x40 - history_key),(ushort)bVar1);
  pbVar7 = *ppbVar6;
  do {
    pbVar12 = pbVar7;
    pbVar7 = prev_char_ptr(pbVar10,pbVar12);
    if (pbVar7 == (byte *)0x0) break;
    uVar8 = token_at(pbVar7);
    *(ushort *)(unaff_ER14 + -0x26) = uVar8;
    uVar9 = key_is_23(uVar8);
  } while ((char)uVar9 == '\0');
  bVar2 = (char)pbVar12 - (char)pbVar10;
  bVar3 = 0;
  do {
    bVar11 = bVar3;
    *(byte *)(unaff_ER14 + -0x24) = bVar11;
    *(byte *)(unaff_ER14 + -0x23) = bVar2;
    pbVar7 = pbVar10 + bVar2;
    bVar3 = bVar11;
    do {
      if (bVar1 <= bVar11) goto LAB_rom_02944a;
      uVar8 = token_at(pbVar7);
      *(ushort *)(unaff_ER14 + -0x26) = uVar8;
      cVar4 = text_clear_panel(uVar8,(byte *)(unaff_ER14 + -0x22));
      *(char *)(unaff_ER14 + -0x28) = cVar4;
      if (cVar4 == '\0') goto LAB_rom_02944a;
      bVar11 = bVar11 + *(char *)(unaff_ER14 + -0x28);
      bVar3 = bVar3 + *(char *)(unaff_ER14 + -0x28);
      bVar5 = is_neg_char(*pbVar7);
      if (CONCAT11(extraout_R1,bVar5) == 0) {
        cVar4 = *(char *)(unaff_ER14 + -0x23) + '\x01';
      }
      else {
        cVar4 = *(char *)(unaff_ER14 + -0x23) + '\x02';
      }
      *(char *)(unaff_ER14 + -0x23) = cVar4;
      pbVar7 = char_ptr_next(pbVar7);
      uVar9 = key_is_23(*(short *)(unaff_ER14 + -0x26));
    } while ((char)uVar9 == '\0');
    *(undefined *)(unaff_ER14 + -0x27) = 1;
LAB_rom_02944a:
    if (*(char *)(unaff_ER14 + -0x27) != '\0') break;
    bVar2 = *(byte *)(unaff_ER14 + -0x23);
    if (bVar1 < bVar11) {
      bVar3 = bVar3 - bVar1;
    }
    else {
      bVar3 = 0;
    }
  } while ((*(char *)(unaff_ER14 + -0x28) != '\0') || (bVar1 == bVar11));
  _DAT_ram_d15a = bVar2;
  if (*(char *)(unaff_ER14 + -0x24) == '\0') {
    _DAT_ram_d15b = '\0';
  }
  else {
    pbVar10 = prev_char_ptr(pbVar10,pbVar10 + bVar2);
    uVar8 = token_at(pbVar10);
    *(ushort *)(unaff_ER14 + -0x26) = uVar8;
    cVar4 = text_clear_panel(uVar8,(byte *)(unaff_ER14 + -0x22));
    *(char *)(unaff_ER14 + -0x28) = cVar4;
    _DAT_ram_d15b = (cVar4 - *(char *)(unaff_ER14 + -0x24)) + '\x01';
  }
  frame_leave();
  return 0;
}

