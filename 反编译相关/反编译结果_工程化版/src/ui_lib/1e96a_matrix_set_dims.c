/*
 * 界面辅助库 / 1e96a_matrix_set_dims.c
 * 地址范围: 0x1E96A - 0x1EDE6
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 设置矩阵单元的行列数（0x2F08 表）并清零 0x8ED0 返回的存储
 * @addr 0x1E96A
 * @module ui_lib
 * @proto void matrix_set_dims(byte n)
 * @confidence strong
 * @note 设置矩阵单元的行列数（0x2F08 表）并清零 0x8ED0 返回的存储。
 * @tag matrix
 */
int matrix_set_dims(byte n)

{
  short sVar1;
  ushort uVar2;
  undefined *puVar3;
  
  uVar2 = frame_enter();
  sVar1 = (uVar2 & 0xff) * 2;
  *(char *)(sVar1 + -0x2f08) = (char)(uVar2 >> 8);
  *(undefined *)(sVar1 + -0x2f07) = n;
  puVar3 = (undefined *)stat_cell_addr(CONCAT11(1,(char)uVar2),'\x01');
  memzero(puVar3,0xa0);
  frame_leave();
  return 0;
}

/**
 * @brief 表格行绘制（3.4KB，0xC85A/0xDAA4/0x23648 调用）
 * @addr 0x1E99E
 * @module ui_lib
 * @proto void table_row_paint(void)
 * @confidence likely
 * @note 表格行绘制（3.4KB，0xC85A/0xDAA4/0x23648 调用）。
 * @tag app
 */
int table_row_paint(uintptr_t _a2, int _a1)

{
  byte bVar1;
  int cVar2;
  char cVar3;
  byte bVar4;
  undefined2 *puVar5;
  byte *pbVar6;
  byte bVar7;
  undefined2 *puVar8;
  undefined2 uVar9;
  short unaff_ER14;
  
  puVar5 = (undefined2 *)frame_enter();
  *_a1 = '\0';
  if (puVar5 != (undefined2 *)0x0) {
    puVar8 = puVar5;
    dec_copy((undefined2 *)(unaff_ER14 + -10),puVar5);
    if (*(char *)(unaff_ER14 + 0x10) == '\0') {
      *(undefined *)(unaff_ER14 + 0x10) = 10;
    }
    cVar2 = dec_exp_shift((undefined2 *)(unaff_ER14 + -10), (uintptr_t)0)
                           CONCAT11((char)((ushort)puVar8 >> 8),
                                    *(char *)(unaff_ER14 + 0x10) + '\x01'));
    if (cVar2 != '\0') {
      dec_copy((undefined2 *)(unaff_ER14 + -10),puVar5);
    }
    pbVar6 = dec_parse((byte *)(unaff_ER14 + -10),(byte **)(unaff_ER14 + -0x22));
    if ((char)pbVar6 != '\0') {
      *(undefined2 *)(unaff_ER14 + -0x10) = 0;
      uVar9 = CONCAT11(*(undefined *)(unaff_ER14 + 0x14),*(undefined *)(unaff_ER14 + 0x12));
      cVar2 = token_list_draw(uVar9);
      cVar3 = *(char *)(unaff_ER14 + 0x12);
      if (((cVar3 == '\x01') || (cVar3 == '\x03')) || (cVar3 == '\x02')) {
        bVar4 = (byte)*(undefined2 *)(unaff_ER14 + -0x12);
        bVar7 = (byte)((ushort)*(undefined2 *)(unaff_ER14 + -0x12) >> 8);
        bVar1 = bVar7 - (bVar4 < 9);
        if ((((byte)((byte)((bVar1 ^ bVar7) & ~bVar1) >> 7 ^ (char)bVar1 < '\0' |
                    (bVar4 == 9 && bVar1 == 0)) == 0) ||
            (bVar1 = (bVar7 + 1) - (bVar4 < 0xf7),
            (bool)((byte)((bVar1 ^ bVar7) & (~bVar1 ^ 0xff)) >> 7) != (char)bVar1 < '\0')) &&
           (((cVar2 == '\0' && (*(char *)(unaff_ER14 + 0x10) == '\n')) ||
            ((cVar2 != '\0' &&
             (bVar4 = (byte)((ushort)*(undefined2 *)(unaff_ER14 + -0x10) >> 8),
             bVar1 = bVar4 - ((byte)*(undefined2 *)(unaff_ER14 + -0x10) < 9),
             (bool)((byte)((bVar1 ^ bVar4) & ~bVar1) >> 7) != (char)bVar1 < '\0')))))) {
          *(undefined *)(unaff_ER14 + 0x10) = 9;
          if (*(short *)(unaff_ER14 + -0x10) < 0) {
            *(char *)(unaff_ER14 + 0x10) = *(char *)(unaff_ER14 + -0x10) + '\t';
          }
          cVar3 = dec_exp_shift((undefined2 *)(unaff_ER14 + -10), (uintptr_t)0)
                                 CONCAT11((char)((ushort)uVar9 >> 8),
                                          *(char *)(unaff_ER14 + 0x10) + '\x01'));
          if (cVar3 != '\0') {
            dec_copy((undefined2 *)(unaff_ER14 + -10),puVar5);
          }
          pbVar6 = dec_parse((byte *)(unaff_ER14 + -10),(byte **)(unaff_ER14 + -0x22));
          if ((char)pbVar6 == '\0') goto LAB_rom_01e9b2;
          if (cVar2 != '\0') {
            cVar2 = token_list_draw(CONCAT11(*(undefined *)(unaff_ER14 + 0x14))
                                            *(undefined *)(unaff_ER14 + 0x12)));
          }
        }
      }
      fmt_number(unaff_ER14 + -0x22,(char *)(unaff_ER14 + -0x2c));
      *(undefined *)(unaff_ER14 + -0xe) = *(undefined *)(unaff_ER14 + 0x10);
      *(undefined *)(unaff_ER14 + -0xd) = 0;
      if (cVar2 != '\0') {
        draw_cell_value(unaff_ER14 + -0x22);
      }
      fmt_sci(unaff_ER14 + -0x22,_a1);
      strcat_checked(_a1,(char *)(unaff_ER14 + -0x2c));
    }
  }
LAB_rom_01e9b2:
  frame_leave();
  return 0;
}

/**
 * @brief 当键值 0xD10E 为 0x0D 或 0x21 时返回高位字节<<8|1，否则返回高位字节…
 * @addr 0x1EBC8
 * @module ui_lib
 * @proto byte key_is_11_04(void)
 * @confidence strong
 * @note 当键值 0xD10E 为 0x0D 或 0x21 时返回高位字节<<8|1，否则返回高位字节<<8。
 * @tag key
 */
byte key_is_11_04(void)

{
  byte bVar1;
  byte bVar2;
  
  bVar1 = (byte)input_key;
  bVar2 = (byte)((ushort)input_key >> 8);
  if ((bVar1 != 0x1d || (bool)(bVar2 + 4) != bVar1 < 0x1d) &&
     (bVar1 != 0x21 || (bool)(bVar2 + 4) != bVar1 < 0x21)) {
    return (ushort)bVar2 << 8;
  }
  return CONCAT11(bVar2,1);
}

/**
 * @brief 统计编辑重绘（buffer_clear、0xD137=0xE，0x9D52）
 * @addr 0x1EBF8
 * @module ui_lib
 * @proto void stat_edit_redraw(void)
 * @confidence likely
 * @note 统计编辑重绘（buffer_clear、0xD137=0xE，0x9D52）。
 * @tag app
 */
int stat_edit_redraw(void)

{
  byte bVar1;
  char cVar2;
  byte bVar3;
  short unaff_ER14;
  
  frame_enter();
  clear_screen();
  cur_line = 0xe;
  input_read_str((char *)(unaff_ER14 + -0x24));
  draw_text4x(0x100,unaff_ER14 + -0x24);
  _DAT_ram_d166 = 0;
  bVar3 = 0;
  do {
    input_read_str((char *)(unaff_ER14 + -0x24));
    draw_text4x((ushort)(byte)((bVar3 + 1) * '\x10' + 1) << 8,unaff_ER14 + -0x24);
    *(undefined *)(unaff_ER14 + -0x4c) = 0;
    bVar1 = (byte)unaff_ER14;
    cVar2 = (char)((ushort)unaff_ER14 >> 8);
    strcat_checked((char *)CONCAT11(cVar2 + -1 + (0x4b < bVar1),bVar1 + 0xb4),":");
    draw_tokens(*(undefined2 **)(&_DAT_ram_1a2a + (ushort)bVar3 * 2));
    strcat_checked((char *)CONCAT11(cVar2 + -1 + (0x4b < bVar1),bVar1 + 0xb4), (uintptr_t)0)
                   (char *)CONCAT11(cVar2 + -1 + (0x73 < bVar1),bVar1 + 0x8c));
    draw_text4x(CONCAT11((bVar3 + 1) * '\x10' + '\x01',0x42))
                   CONCAT11(cVar2 + -1 + (0x4b < bVar1),bVar1 + 0xb4));
    bVar3 = bVar3 + 1;
    if (stat_state == bVar3) {
      cursor_visible = 3;
      draw_list_scroller2((ushort)(byte)(bVar3 * '\x10' + 1) << 8,0xec0);
      cursor_visible = 0;
    }
  } while (bVar3 < 3);
  _DAT_ram_d166 = 3;
  frame_leave();
  return 0;
}

/**
 * @brief p[0]==0xC9 且 p[1]==0x1A 时返回 (高字节<<8)|1，否则 高字节<…
 * @addr 0x1ECE2
 * @module ui_lib
 * @proto byte is_ws_scan(byte* p)
 * @confidence verified
 * @note p[0]==0xC9 且 p[1]==0x1A 时返回 (高字节<<8)|1，否则 高字节<<8。
 * @tag parser
 */
byte is_ws_scan(byte* p)

{
  byte bVar1;
  
  bVar1 = (byte)((ushort)p >> 8);
  if ((*p == -0x37) && (p[1] == '\x1a')) {
    return CONCAT11(bVar1,1);
  }
  return (ushort)bVar1 << 8;
}

/**
 * @brief token 扫描（1.4KB）
 * @addr 0x1ECFA
 * @module ui_lib
 * @proto byte token_scan(byte mode)
 * @confidence strong
 * @note token 扫描（1.4KB）：按类别 2/3/4 移动，返回下一个 token 偏移。
 * @tag parser
 */
byte token_scan(byte mode)

{
  char cVar1;
  bool bVar2;
  byte bVar3;
  byte *pbVar4;
  undefined extraout_R1;
  undefined extraout_R1_00;
  byte bVar5;
  byte *pbVar6;
  
  pbVar4 = (byte *)frame_enter();
  cVar1 = get_token_class(pbVar4);
  if ((((char)((mode == 0) << 7) < '\0') || (cVar1 != '\0')) &&
     ((mode != 2 || ((cVar1 == '\x03' || (cVar1 == '\x04')))))) {
    if (cVar1 == '\x02') {
      bVar5 = 3;
    }
    else if (cVar1 == '\x04') {
      bVar5 = 4;
    }
    else {
      bVar5 = 2;
    }
    bVar2 = is_neg_char(*pbVar4);
    if (CONCAT11(extraout_R1,bVar2) != 0) {
      bVar5 = bVar5 + 1;
    }
    if (mode != 0) {
      pbVar4 = pbVar4 + bVar5;
      for (bVar5 = 0; (char)((bVar5 < mode) << 7) < '\0'; bVar5 = bVar5 + 1) {
        cVar1 = '\x01';
        while (pbVar6 = pbVar4, bVar3 = *pbVar6, bVar3 != 0) {
          if (bVar3 == 0x1a) {
            cVar1 = cVar1 + '\x01';
          }
          else if (bVar3 == 0x1b) {
            cVar1 = cVar1 + -1;
            if (cVar1 == '\0') break;
          }
          else if ((bVar3 == 0x1c) && (cVar1 == '\x01')) break;
          bVar2 = is_neg_char(*pbVar6);
          pbVar4 = pbVar6 + 1;
          if (CONCAT11(extraout_R1_00,bVar2) != 0) {
            pbVar4 = pbVar6 + 2;
          }
        }
        pbVar4 = pbVar6 + 1;
        if (*pbVar4 == 0x1a) {
          pbVar4 = pbVar6 + 2;
        }
      }
    }
  }
  frame_leave();
  return;
}

/**
 * @brief 把 (参数字节<<3)+0xDBE6 处的变量字节写成 0x9D22 的返回值减 0xD14…
 * @addr 0x1EDE6
 * @module ui_lib
 * @proto void var_slot_write(void)
 * @confidence likely
 * @note 把 (参数字节<<3)+0xDBE6 处的变量字节写成 0x9D22 的返回值减 0xD144。
 * @tag var
 */
int var_slot_write(uintptr_t _a2, int _a1)

{
  char cVar1;
  short sVar2;
  short unaff_ER14;
  
  cVar1 = frame_enter();
  sVar2 = CONCAT11((char)(((ushort)*(byte *)(unaff_ER14 + 0x10) << 3) >> 8),
                   *(byte *)(unaff_ER14 + 0x10) << 3);
  *(char *)(sVar2 + -0x241a) = cVar1 - input_ptr;
  *(undefined2 *)(sVar2 + -0x241c) = _a1;
  frame_leave();
  return 0;
}

