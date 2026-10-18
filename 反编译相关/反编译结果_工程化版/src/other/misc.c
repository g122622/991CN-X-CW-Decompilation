/* 未能按地址区间归类的函数 */
#include "991cnx/all.h"

/**
 * @brief 按 0xD0F6 与每行单元数计算表格单元格地址（0xDCB0/0x8F48）
 * @addr 0x0F30E
 * @module other
 * @proto int table_cell_addr(void)
 * @confidence likely
 * @note 按 0xD0F6 与每行单元数计算表格单元格地址（0xDCB0/0x8F48）。
 * @tag app
 */
int table_cell_addr(void)

{
  byte bVar1;
  byte bVar2;
  short sVar3;
  ushort uVar4;
  short sVar5;
  undefined *puVar6;
  undefined *puVar7;
  char cVar9;
  undefined2 uVar8;
  ushort uVar10;
  short unaff_ER14;
  
  bVar1 = frame_enter();
  if ((bVar1 <= var_scroll) && (bVar1 != 0)) {
    sVar3 = line_index_calc();
    bVar2 = stat_table_width();
    stat_table_base((undefined2 *)(unaff_ER14 + -2));
    uVar10 = (ushort)bVar2;
    uVar4 = mul16(bVar1 - 1,uVar10);
    sVar5 = mul16(uVar4,10);
    puVar6 = (undefined *)(sVar5 + *(short *)(unaff_ER14 + -2));
    sVar5 = mul16(uVar10,10);
    puVar7 = puVar6 + sVar5;
    bVar1 = (byte)sVar3;
    cVar9 = (char)((ushort)sVar3 >> 8);
    memcpy_bytes(puVar6,puVar7, (uintptr_t)0)
                   CONCAT11((cVar9 - (char)((ushort)puVar7 >> 8)) - (bVar1 < (byte)puVar7),
                            bVar1 - (byte)puVar7));
    sVar3 = mul16(uVar10,10);
    uVar8 = mul16(uVar10,10);
    memzero((undefined *, (uintptr_t)0)
                   CONCAT11((cVar9 - (char)((ushort)uVar8 >> 8)) - (bVar1 < (byte)uVar8),
                            bVar1 - (byte)uVar8),sVar3);
    var_scroll = var_scroll - 1;
  }
  frame_leave();
  return 0;
}

/**
 * @brief p 处字节为 0x30..0x39 时返回 1
 * @addr 0x0F918
 * @module other
 * @proto char is_ascii_digit(byte* p)
 * @confidence verified
 * @note p 处字节为 0x30..0x39 时返回 1。
 * @tag util
 */
char is_ascii_digit(byte* p)

{
  if (0x39 < *p) {
    return 0;
  }
  if (*p < 0x30) {
    return 0;
  }
  return 1;
}

/**
 * @brief 矩阵打印格式（4.8KB，0x15828 调用）
 * @addr 0x0F952
 * @module other
 * @proto int matrix_print_fmt(void)
 * @confidence likely
 * @note 矩阵打印格式（4.8KB，0x15828 调用）。
 * @tag matrix
 */
int matrix_print_fmt(void)

{
  undefined *puVar1;
  undefined2 uVar2;
  short sVar3;
  undefined2 uVar4;
  undefined2 *puVar5;
  short unaff_ER14;
  
  puVar1 = (undefined *)frame_enter();
  *(undefined *)(unaff_ER14 + -0x29) = 0;
  *(undefined *)(unaff_ER14 + -0x19) = 2;
  *(undefined *)(unaff_ER14 + -0x2a) = 0;
  *(undefined2 *)(unaff_ER14 + -0x16) = 0xd752;
  *(undefined2 *)(unaff_ER14 + -0x1e) = 0xd75c;
  *(undefined2 *)(unaff_ER14 + -0x20) = 0xd77a;
  *(undefined2 *)(unaff_ER14 + -0x28) = 0xd7fc;
  *(undefined2 *)(unaff_ER14 + -0x26) = 0xd806;
  *(undefined2 *)(unaff_ER14 + -0x24) = 0xd810;
  *(undefined2 *)(unaff_ER14 + -0x22) = 0xd81a;
  uVar4 = 0xd842;
  *(undefined2 *)(unaff_ER14 + -0x18) = 0xd84c;
  *(undefined2 *)(unaff_ER14 + -0x1c) = 0xd874;
  uVar2 = 0xd7f2;
  dec_bin_mul((undefined2 *)0xd874,(undefined2 *)0xd7f2);
  uVar2 = dec_cmp(*(undefined2 **)(unaff_ER14 + -0x1e),uVar2);
  if ((char)uVar2 == '\x01') {
    dec_copy((undefined2 *)(unaff_ER14 + -10),*(undefined2 **)(unaff_ER14 + -0x16));
    dec_copy((undefined2 *)(unaff_ER14 + -0x14),*(undefined2 **)(unaff_ER14 + -0x16));
    dec_bin_div((undefined2 *)(unaff_ER14 + -10),*(undefined2 **)(unaff_ER14 + -0x20));
    dec_bin_pow((undefined2 *)(unaff_ER14 + -0x14),*(undefined2 **)(unaff_ER14 + -0x20));
  }
  else {
    *(undefined *)(unaff_ER14 + -0x29) = 1;
    dec_copy((undefined2 *)(unaff_ER14 + -10),*(undefined2 **)(unaff_ER14 + -0x16));
    dec_copy((undefined2 *)(unaff_ER14 + -0x14),*(undefined2 **)(unaff_ER14 + -0x16));
    dec_set_uint_small((ushort *)0xd842,2);
    dec_bin_pow((undefined2 *)(unaff_ER14 + -10),(undefined2 *)0xd842);
    dec_xy_sub((undefined2 *)(unaff_ER14 + -0x14),uVar4);
    puVar5 = *(undefined2 **)(unaff_ER14 + -0x1e);
    dec_copy((undefined2 *)0xd842,puVar5);
    dec_xy_sub((undefined2 *)0xd842,puVar5);
    dec_bin_div((undefined2 *)(unaff_ER14 + -0x14),(undefined2 *)0xd842);
  }
  puVar5 = *(undefined2 **)(unaff_ER14 + -0x1c);
  dec_copy((undefined2 *)0xd86a,puVar5);
  dec_xy_sub((undefined2 *)0xd86a,puVar5);
  dec_copy((undefined2 *)0xd860,(undefined2 *)0xd86a);
  dec_bin_pow((undefined2 *)0xd86a,(undefined2 *)(unaff_ER14 + -0x14));
  puVar5 = *(undefined2 **)(unaff_ER14 + -0x22);
  dec_bin_mul((undefined2 *)0xd86a,puVar5);
  uVar2 = dec_cmp((undefined2 *)0xd86a,puVar5);
  if ((char)uVar2 == '\x01') {
    dec_copy((undefined2 *)0xd86a,(undefined2 *)0xd860);
    dec_bin_pow((undefined2 *)0xd860,(undefined2 *)(unaff_ER14 + -10));
    dec_set_uint_small((ushort *)0xd842,2);
    dec_bin_pow((undefined2 *)0xd842,*(undefined2 **)(unaff_ER14 + -0x1c));
    dec_copy(*(undefined2 **)(unaff_ER14 + -0x18),(undefined2 *)0xd842);
    dec_copy((undefined2 *)0xd856,(undefined2 *)0xd842);
    dec_bin_pow((undefined2 *)0xd842,(undefined2 *)(unaff_ER14 + -0x14));
    dec_bin_div((undefined2 *)0xd860,(undefined2 *)0xd842);
    puVar5 = *(undefined2 **)(unaff_ER14 + -0x24);
    dec_bin_div((undefined2 *)0xd860,puVar5);
    uVar2 = dec_cmp((undefined2 *)0xd860,puVar5);
    if ((char)uVar2 == '\x01') {
      dec_bin_pow((undefined2 *)0xd856,(undefined2 *)(unaff_ER14 + -10));
      dec_bin_div((undefined2 *)0xd856,(undefined2 *)0xd86a);
      dec_bin_div((undefined2 *)0xd856,(undefined2 *)(unaff_ER14 + -0x14));
      puVar5 = *(undefined2 **)(unaff_ER14 + -0x26);
      dec_bin_mul((undefined2 *)0xd856,puVar5);
      uVar2 = dec_cmp((undefined2 *)0xd856,puVar5);
      if ((char)uVar2 == '\x01') {
        dec_bin_div(*(undefined2 **)(unaff_ER14 + -0x18),(undefined2 *)(unaff_ER14 + -10));
        puVar5 = *(undefined2 **)(unaff_ER14 + -0x28);
        dec_bin_div(*(undefined2 **)(unaff_ER14 + -0x18),puVar5);
        uVar2 = dec_cmp(*(undefined2 **)(unaff_ER14 + -0x18),puVar5);
        if ((char)uVar2 == '\x01') {
          if (*(char *)(unaff_ER14 + -0x29) != '\0') {
            if (calc_mode == 'K') {
              *(undefined *)(unaff_ER14 + -0x19) = 0;
            }
            if ((calc_mode == 'E') && (key_state_a == '\0')) {
              *(undefined *)(unaff_ER14 + -0x19) = 0;
            }
          }
          if (*(char *)(unaff_ER14 + -0x19) == '\0') {
            memset(puVar1,0,0x50);
          }
          puVar5 = *(undefined2 **)(unaff_ER14 + -0x1c);
          sVar3 = mul16((ushort)*(byte *)(unaff_ER14 + -0x19),0x28);
          dec_copy((undefined2 *)(puVar1 + sVar3),puVar5);
          sVar3 = mul16((ushort)*(byte *)(unaff_ER14 + -0x19),0x28);
          *(undefined2 *)(puVar1 + sVar3 + 0x14) = 2;
          *(char *)(unaff_ER14 + -0x2a) = *(char *)(unaff_ER14 + -0x19) + '\x01';
        }
      }
    }
  }
  frame_leave();
  return 0;
}

/**
 * @brief 记录错误位置（0xD158/0xD159），调用 0x20DF4 重绘，并把 0xD137 …
 * @addr 0x0FBD4
 * @module other
 * @proto void error_set_location(byte q, byte r)
 * @confidence likely
 * @note 记录错误位置（0xD158/0xD159），调用 0x20DF4 重绘，并把 0xD137 暂存到 0xD133。
 * @tag eval
 */
int error_set_location(byte q, byte r)

{
  hl_line = q;
  hl_col = r;
  redraw_line_syntax();
  saved_line = cur_line;
  return 0;
}

/**
 * @brief 菜单门槛检查
 * @addr 0x0FBFE
 * @module other
 * @proto byte menu_gate(void)
 * @confidence likely
 * @note 菜单门槛检查：弹栈返回。注意位于 0xFC00 保留区（ROM 中为 0xFF 填充）之前的最后一个函数。
 * @tag ui
 */
byte menu_gate(void)

{
  return;
}

