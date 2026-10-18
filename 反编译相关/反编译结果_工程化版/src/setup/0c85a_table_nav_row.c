/*
 * 设置与模式逻辑 / 0c85a_table_nav_row.c
 * 地址范围: 0x0C85A - 0x0CF94
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 表格行导航（0x2A074 写值、0xDAA4 配合），4.2KB
 * @addr 0x0C85A
 * @module setup
 * @proto void table_nav_row(byte* p)
 * @confidence likely
 * @note 表格行导航（0x2A074 写值、0xDAA4 配合），4.2KB。
 * @tag app
 */
int table_nav_row(byte* p)

{
  int cVar1;
  char cVar2;
  byte bVar3;
  byte bVar4;
  undefined2 *puVar5;
  undefined2 uVar6;
  byte *pbVar7;
  byte bVar9;
  short sVar8;
  undefined2 *puVar10;
  short unaff_ER14;
  
  puVar5 = (undefined2 *)frame_enter();
  *p = '\0';
  if (puVar5 != (undefined2 *)0x0) {
    puVar10 = puVar5;
    dec_copy((undefined2 *)(unaff_ER14 + -10),puVar5);
    uVar6 = dec_cmp(puVar5,puVar10);
    if ((char)uVar6 == '\x01') {
      memzero((undefined *)(unaff_ER14 + -0x22),0x18);
      *(char *)(unaff_ER14 + -0xe) = *(char *)(unaff_ER14 + 0x10) + '\x01';
      *(undefined *)(unaff_ER14 + -0xd) = 2;
      fmt_sci(unaff_ER14 + -0x22,p);
    }
    else {
      matrix_set_value(*(byte *)(unaff_ER14 + 0x10));
      if ((*(byte *)(unaff_ER14 + -10) & 0xf0) != 0) {
        dec_copy((undefined2 *)(unaff_ER14 + -10),puVar5);
      }
      pbVar7 = dec_parse((byte *)(unaff_ER14 + -10),(byte **)(unaff_ER14 + -0x22));
      if ((char)pbVar7 != '\0') {
        *(undefined2 *)(unaff_ER14 + -0x10) = 0;
        cVar1 = token_list_draw(CONCAT11(*(undefined *)(unaff_ER14 + 0x14))
                                        *(undefined *)(unaff_ER14 + 0x12)));
        cVar2 = *(char *)(unaff_ER14 + 0x12);
        if (((((cVar2 == '\x01') || (cVar2 == '\x03')) || (cVar2 == '\x02')) &&
            (bVar3 = (byte)*(undefined2 *)(unaff_ER14 + -0x12),
            bVar9 = (byte)((ushort)*(undefined2 *)(unaff_ER14 + -0x12) >> 8),
            bVar4 = bVar9 - (bVar3 < 9),
            (byte)((byte)((bVar4 ^ bVar9) & ~bVar4) >> 7 ^ (char)bVar4 < '\0' |
                  (bVar3 == 9 && bVar4 == 0)) != 1)) &&
           (((cVar1 == '\0' && (*(char *)(unaff_ER14 + -0x19) != '\0')) ||
            ((cVar1 != '\0' &&
             (bVar3 = (byte)((ushort)*(undefined2 *)(unaff_ER14 + -0x10) >> 8),
             bVar4 = bVar3 - ((byte)*(undefined2 *)(unaff_ER14 + -0x10) < 9),
             (bool)((byte)((bVar4 ^ bVar3) & ~bVar4) >> 7) != (char)bVar4 < '\0')))))) {
          *(undefined *)(unaff_ER14 + 0x10) = 9;
          if (*(short *)(unaff_ER14 + -0x10) < 0) {
            *(char *)(unaff_ER14 + 0x10) = *(char *)(unaff_ER14 + -0x10) + '\t';
          }
          table_row_paint(p);
        }
        else {
          sVar8 = *(short *)(unaff_ER14 + -0x12);
          bVar3 = (byte)((ushort)sVar8 >> 8);
          bVar4 = bVar3 - ((byte)sVar8 < 10);
          if (((bool)((byte)((bVar4 ^ bVar3) & ~bVar4) >> 7) == (char)bVar4 < '\0') ||
             (cVar1 != '\0')) {
            fmt_number(unaff_ER14 + -0x22,(char *)(unaff_ER14 + -0x2c));
            *(undefined *)(unaff_ER14 + -0xe) = 10;
            *(undefined *)(unaff_ER14 + -0xd) = 1;
            if (cVar1 != '\0') {
              draw_cell_value(unaff_ER14 + -0x22);
            }
            fmt_sci(unaff_ER14 + -0x22,p);
            strcat_checked(p,(char *)(unaff_ER14 + -0x2c));
          }
          else {
            if (sVar8 < 0) {
              if ((short)((ushort)*(byte *)(unaff_ER14 + 0x10) + *(short *)(unaff_ER14 + -0x12)) < 0
                 ) {
                *(undefined *)(unaff_ER14 + -0x13) = 0;
                sVar8 = *(byte *)(unaff_ER14 + 0x10) + 1;
                cVar1 = (char)sVar8;
                sVar8 = CONCAT11(-(cVar1 != '\0') - (char)((ushort)sVar8 >> 8),-cVar1);
              }
              else {
                sVar8 = *(short *)(unaff_ER14 + -0x12);
              }
            }
            *(short *)(unaff_ER14 + -0x10) = sVar8;
            cVar1 = (char)*(undefined2 *)(unaff_ER14 + -0x12);
            if ((short)(ushort)(byte)(*(char *)(unaff_ER14 + 0x10) + 1) <
                CONCAT11(-(cVar1 != '\0') - (char)((ushort)*(undefined2 *)(unaff_ER14 + -0x12) >> 8)
                         ,-cVar1)) {
              bVar4 = 0;
            }
            else {
              bVar4 = *(char *)(unaff_ER14 + -0x12) + *(char *)(unaff_ER14 + 0x10) + 1;
            }
            *(byte *)(unaff_ER14 + -0xe) = bVar4;
            if (9 < bVar4) {
              *(undefined *)(unaff_ER14 + -0xe) = 10;
            }
            *(undefined *)(unaff_ER14 + -0xd) = 2;
            fmt_sci(unaff_ER14 + -0x22,p);
          }
        }
      }
    }
  }
  frame_leave();
  return 0;
}

/**
 * @brief 按首字节给出的总长 n（n+1 字节）把 src 原样复制到 ER0 指向的缓冲区
 * @addr 0x0CCF0
 * @module setup
 * @proto void copy_prefixed(char* src)
 * @confidence likely
 * @note 按首字节给出的总长 n（n+1 字节）把 src 原样复制到 ER0 指向的缓冲区。
 * @tag strlib
 */
int copy_prefixed(char* src)

{
  byte bVar1;
  char *pcVar2;
  short sVar3;
  
  pcVar2 = (char *)frame_enter();
  bVar1 = strline_len(src);
  for (sVar3 = bVar1 + 1; -1 < sVar3 && ((char)sVar3 != '\0' || (char)((ushort)sVar3 >> 8) != '\0');
      sVar3 = sVar3 + -1) {
    *pcVar2 = *src;
    pcVar2 = pcVar2 + 1;
    src = src + 1;
  }
  frame_leave();
  return 0;
}

/**
 * @brief 以 0 调用 0x22BF4（关闭菜单层）
 * @addr 0x0CD20
 * @module setup
 * @proto int menu_close(void)
 * @confidence likely
 * @note 以 0 调用 0x22BF4（关闭菜单层）。
 * @tag ui
 */
int menu_close(void)

{
  menu_open('\0');
  return 0;
}

/**
 * @brief 按 flag 选择 0x20ED4 或 0x20F86 切换光标可见性，返回 er0
 * @addr 0x0CD26
 * @module setup
 * @proto undefined2 set_cursor_visible(undefined2 er0, char flag)
 * @confidence likely
 * @note 按 flag 选择 0x20ED4 或 0x20F86 切换光标可见性，返回 er0。
 * @tag ui
 */
undefined2 set_cursor_visible(undefined2 er0, char flag)

{
  if (flag == '\0') {
    str_emit_plus();
  }
  else {
    str_emit_1D35();
  }
  return er0;
}

/**
 * @brief 返回 (0x24E10() != 0) && (0xD122 != 0)
 * @addr 0x0CDD0
 * @module setup
 * @proto char is_display_busy(void)
 * @confidence likely
 * @note 返回 (0x24E10() != 0) && (0xD122 != 0)：显示/计算进行中标志。
 * @tag ui
 */
char is_display_busy(void)

{
  char cVar1;
  
  cVar1 = is_ratio_edit();
  if ((cVar1 != '\0') && (menu_state_a != '\0')) {
    return 1;
  }
  return 0;
}

/**
 * @brief 统计表插入行
 * @addr 0x0CDE8
 * @module setup
 * @proto void table_insert_row(void)
 * @confidence strong
 * @note 统计表插入行：按每行单元数 0x8F48 与光标行 0xD0F6 计算插入位置，0x9A3A 搬移后续行、memzero
 *       清空新行并更新计数。
 * @tag app
 */
int table_insert_row(void)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  ushort uVar4;
  short sVar5;
  short sVar6;
  undefined *puVar7;
  byte bVar8;
  ushort uVar9;
  short unaff_ER14;
  
  bVar1 = frame_enter();
  bVar3 = 0xa0;
  if (calc_mode == '\f') {
    bVar3 = 0x5a;
  }
  bVar2 = stat_table_width();
  bVar8 = (byte)((ushort)var_scroll * (ushort)bVar2);
  if ((short)(ushort)bVar2 <=
      CONCAT11(-(bVar3 < bVar8) - (char)((ushort)var_scroll * (ushort)bVar2 >> 8),bVar3 - bVar8))
  {
    uVar4 = var_scroll + 1;
    uVar9 = (ushort)bVar1;
    if (((byte)(SBORROW2(uVar9,uVar4) ^ (short)(uVar9 - uVar4) < 0 | uVar9 == uVar4) != 0) &&
       (bVar1 != 0)) {
      bVar3 = stat_table_base((undefined2 *)(unaff_ER14 + -2));
      uVar4 = bVar3 + 1;
      uVar9 = (ushort)bVar1;
      if (((byte)(SBORROW2(uVar9,uVar4) ^ (short)(uVar9 - uVar4) < 0 | uVar9 == uVar4) != 0) &&
         (bVar1 != 0)) {
        sVar5 = line_index_calc();
        uVar4 = mul16(bVar1 - 1,(ushort)bVar2);
        sVar6 = mul16(uVar4,10);
        puVar7 = (undefined *)(sVar6 + *(short *)(unaff_ER14 + -2));
        sVar6 = mul16((ushort)bVar2,10);
        var_scroll = var_scroll + 1;
        memmove(puVar7 + sVar6,puVar7, (uintptr_t)0)
                       CONCAT11(((char)((ushort)sVar5 >> 8) - (char)((ushort)puVar7 >> 8)) -
                                ((byte)sVar5 < (byte)puVar7),(byte)sVar5 - (byte)puVar7));
        sVar5 = mul16((ushort)bVar2,10);
        memzero(puVar7,sVar5);
        if (var_list_open != '\0') {
          dec_set_uint_small((ushort *)(unaff_ER14 + -0xc),1);
          list_entry_fetch(unaff_ER14 + -0xc);
        }
      }
    }
  }
  frame_leave();
  return 0;
}

/**
 * @brief 输入态按键过滤
 * @addr 0x0CF94
 * @module setup
 * @proto void input_key_filter(void)
 * @confidence likely
 * @note 输入态按键过滤：0xD116==1 时屏蔽/清零 0xD10E 的部分键（0x36/0x31/0xFC3B 区）。
 * @tag key
 */
int input_key_filter(void)

{
  ushort uVar1;
  byte bVar2;
  byte bVar3;
  
  if (key_modifiers == '\x01') {
    bVar3 = (byte)input_key;
    bVar2 = (byte)(input_key >> 8);
    if (bVar3 == 0x36 && (bool)(bVar2 + 4) == bVar3 < 0x36) {
      set_input_key(0xdc);
      return 0;
    }
    if (((0xfc36 < input_key) &&
        (uVar1 = (bVar2 - 0xfc) - (ushort)(bVar3 < 0x3b),
        (uVar1 & 0x100) != 0 || bVar3 == 0x3b && (char)uVar1 == '\0')) ||
       (bVar3 == 0x31 && (bool)(bVar2 + 4) == bVar3 < 0x31)) {
      input_key = 0;
    }
  }
  return 0;
}

