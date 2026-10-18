/*
 * 表达式求值 / 16be8_matrix_copy_to_slot.c
 * 地址范围: 0x16BE8 - 0x171F0
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief R11 有效时把矩阵操作数复制到当前槽
 * @addr 0x16BE8
 * @module eval
 * @proto int matrix_copy_to_slot(void)
 * @confidence likely
 * @note R11 有效时把矩阵操作数复制到当前槽。
 * @tag matrix
 */
int matrix_copy_to_slot(void)

{
  undefined8 in_QR0;
  byte unaff_R11;
  
  if (9 < unaff_R11) {
    return 0;
  }
  stat_cell_read((undefined8 *)((ulonglong)in_QR0 >> 0x10));
  return 0;
}

/**
 * @brief 把 R11 递减后的操作数槽复制到下一步（0xD111==0xC4 时多减 1）
 * @addr 0x16C16
 * @module eval
 * @proto void matrix_opnd_advance(void)
 * @confidence likely
 * @note 把 R11 递减后的操作数槽复制到下一步（0xD111==0xC4 时多减 1）。
 * @tag matrix
 */
int matrix_opnd_advance(void)

{
  char unaff_R11;
  byte bVar1;
  
  if (unaff_R11 == '\0') {
    return 0;
  }
  bVar1 = unaff_R11 - 1;
  if (calc_mode == -0x3c) {
    bVar1 = unaff_R11 - 2;
  }
  stat_cell_read((undefined8 *)((ushort)bVar1 * 10 + -0x2f70));
  return 0;
}

/**
 * @brief 返回统计表第 R10 项的指针（0xD05E + R10*2 读出的指针）
 * @addr 0x16C3A
 * @module eval
 * @proto ushort* stat_entry_ptr(void)
 * @confidence strong
 * @note 返回统计表第 R10 项的指针（0xD05E + R10*2 读出的指针）。
 * @tag stat
 */
ushort* stat_entry_ptr(void)

{
  return;
}

/**
 * @brief R10<0x18 时把 v 写入矩阵区 0x???0 + R10*2（基址 0x3060 区…
 * @addr 0x16C4E
 * @module eval
 * @proto int store_mat_word(undefined2 v)
 * @confidence verified
 * @note R10<0x18 时把 v 写入矩阵区 0x???0 + R10*2（基址 0x3060 区）。
 * @tag matrix
 */
int store_mat_word(undefined2 v)

{
  byte unaff_R10;
  
  if (0x17 < unaff_R10) {
    return 0;
  }
  *(undefined2 *)CONCAT11((0x9f < (byte)(unaff_R10 * '\x02')) + -0x30,unaff_R10 * '\x02' + 0x60) =
       v;
  return 0;
}

/**
 * @brief R5 为 0xFE 或 0xFA 时保留，否则返回（单元类型守卫）
 * @addr 0x16C70
 * @module eval
 * @proto void check_r5_pair(void)
 * @confidence verified
 * @note R5 为 0xFE 或 0xFA 时保留，否则返回（单元类型守卫）。
 * @tag matrix
 */
int check_r5_pair(void)

{
  char unaff_R5;
  
  if ((unaff_R5 != -2) && (unaff_R5 != -6)) {
    return 0;
  }
  return 0;
}

/**
 * @brief 矩阵单元比较并推进（0x16B4A 守卫），返回比较结果标志
 * @addr 0x16CC8
 * @module eval
 * @proto undefined2 mat_cmp_elem(ushort a, ushort b)
 * @confidence likely
 * @note 矩阵单元比较并推进（0x16B4A 守卫），返回比较结果标志。
 * @tag matrix
 */
undefined2 mat_cmp_elem(ushort a, ushort _a1)

{
  undefined2 uVar1;
  byte extraout_R1;
  ushort unaff_ER4;
  byte bVar2;
  
  bVar2 = (a < unaff_ER4) << 7 | (a == unaff_ER4) << 6;
  if (a == unaff_ER4) {
    emit_noop_guard();
    if (-1 < (char)bVar2) {
      return;
    }
  }
  else {
    uVar1 = emit_noop_guard();
    if ((char)bVar2 < '\0') {
      if (((char)((ushort)uVar1 >> 8) == '\0') && ((char)uVar1 == -0x5b)) {
        return;
      }
    }
    else {
      check_r5_pair();
      check_r5_pair();
      if (extraout_R1 <= (byte)(unaff_ER4 >> 8)) {
        return;
      }
    }
  }
  return;
}

/**
 * @brief 数字序列求值
 * @addr 0x16D00
 * @module eval
 * @proto undefined2 mat_digits_eval(undefined2 v)
 * @confidence likely
 * @note 数字序列求值：逐项 0x16C3A/0x16CC8 处理，遇结束标记返回。
 * @tag matrix
 */
undefined2 mat_digits_eval(undefined2 v, int _a2)

{
  ushort uVar1;
  undefined2 uVar2;
  char cVar3;
  ushort unaff_ER4;
  char unaff_R10;
  
  while( true ) {
    if (unaff_R10 == '\0') {
      return v;
    }
    uVar1 = stat_entry_ptr();
    cVar3 = (char)unaff_ER4;
    if (((char)(unaff_ER4 >> 8) == '\0') && (cVar3 == -0x24)) {
      if ((char)(uVar1 >> 8) != '\0') {
        return v;
      }
      if ((char)uVar1 != -0x24) {
        return v;
      }
    }
    uVar2 = mat_cmp_elem(uVar1, (uintptr_t)0);
    if (cVar3 == '\0') {
      return v;
    }
    if (((cVar3 == '\x01') && ((char)((ushort)uVar2 >> 8) == '\0')) && ((char)uVar2 == -0x38))
    break;
    unaff_R10 = unaff_R10 + -1;
    matrix_eval_tree(unaff_ER4,_a2);
    if ((char)_a2 != '\0') {
      return v;
    }
  }
  return v;
}

/**
 * @brief 从 0xD05E 起的 n 项逐项调用 0x16CC8 处理（数字/单元转换循环）
 * @addr 0x16D4E
 * @module eval
 * @proto int mat_digits_loop(char v, ushort n)
 * @confidence likely
 * @note 从 0xD05E 起的 n 项逐项调用 0x16CC8 处理（数字/单元转换循环）。
 * @tag matrix
 */
int mat_digits_loop(char v, ushort n)

{
  char cVar1;
  ushort uVar2;
  undefined2 uVar3;
  undefined2 *puVar4;
  
  if (n == 0) {
    return 0;
  }
  uVar2 = (ushort)n;
  puVar4 = (undefined2 *)(&dec_param_b + uVar2 * 2);
  while( true ) {
    cVar1 = (char)uVar2;
    uVar3 = *puVar4;
    v = mat_cmp_elem(v, (uintptr_t)0);
    if ((char)uVar3 == '\x01') {
      return 0;
    }
    if ((char)uVar3 == '\0') break;
    puVar4 = puVar4 + -1;
    uVar2 = (ushort)(byte)(cVar1 - 1U);
    if ((byte)(cVar1 - 1U) == 0) {
      return 0;
    }
  }
  return 0;
}

/**
 * @brief 把 EA 指向的打包半字节解成字节写到 ER12（R10 控制展开长度）
 * @addr 0x16D7C
 * @module eval
 * @proto void nibble_unpack(void)
 * @confidence verified
 * @note 把 EA 指向的打包半字节解成字节写到 ER12（R10 控制展开长度）。
 * @tag util
 */
int nibble_unpack(void)

{
  byte *pbVar1;
  byte bVar2;
  char unaff_R10;
  byte *unaff_ER12;
  byte *in_EA;
  byte *pbVar3;
  
  bVar2 = *in_EA;
  pbVar1 = in_EA + 1;
  while( true ) {
    pbVar3 = pbVar1;
    *unaff_ER12 = bVar2;
    unaff_ER12 = unaff_ER12 + 1;
    if ((unaff_R10 == '\x01') || (unaff_R10 == '\0')) break;
    bVar2 = *pbVar3 << 4;
    unaff_R10 = unaff_R10 + -2;
    pbVar1 = pbVar3 + 1;
    if (unaff_R10 != '\0') {
      bVar2 = bVar2 | pbVar3[1];
      pbVar1 = pbVar3 + 2;
    }
  }
  return 0;
}

/**
 * @brief 矩阵求值分派（3.1KB，0x170AE/0x171F0 使用）
 * @addr 0x16D9C
 * @module eval
 * @proto int matrix_eval_dispatch(undefined2 a)
 * @confidence likely
 * @note 矩阵求值分派（3.1KB，0x170AE/0x171F0 使用）。
 * @tag matrix
 */
int matrix_eval_dispatch(undefined2 a, int _a2)

{
  ushort uVar1;
  char cVar3;
  char extraout_R1;
  undefined8 *puVar2;
  byte bVar4;
  byte bVar6;
  ushort uVar5;
  byte bVar7;
  byte bVar8;
  char cVar9;
  char cVar10;
  char cVar11;
  short unaff_ER12;
  short sVar12;
  byte *pbVar13;
  
  cVar10 = '\0';
  cVar11 = '\0';
  bVar8 = 0x31;
  cVar9 = ' ';
  if (0xc1 < a) {
    if (a != 0xc2) {
      if (0xc3 < a) {
        bVar8 = 0x37;
        cVar9 = '\x1e';
      }
      bVar8 = bVar8 + 2;
      cVar9 = cVar9 + -1;
    }
    bVar8 = bVar8 + 6;
    cVar9 = cVar9 + -0x15;
  }
LAB_rom_016dbc:
  do {
    uVar1 = eval_token_scan();
    if (10 < (byte)_a2) {
      return 0;
    }
    if ((byte)_a2 != 4) {
      if (cVar11 == '\x01') {
        puVar2 = stat_layout2((undefined8 *)0x1b62);
      }
      else {
        if (cVar11 == '\0') {
          return 0;
        }
        pbVar13 = (byte *)(unaff_ER12 + 0x28);
        uVar1 = 0;
        uVar5 = 0;
        bVar7 = 4;
        *(undefined2 *)(unaff_ER12 + 6) = 0;
        *(undefined2 *)(unaff_ER12 + 4) = 0;
        *(undefined2 *)(unaff_ER12 + 2) = 0;
        *(undefined *)(unaff_ER12 + 1) = 0;
        if (bVar8 == 0x39) {
          *(undefined2 *)(unaff_ER12 + 8) = 0x1ff;
          puVar2 = (undefined8 *)nibble_unpack();
        }
        else {
          if (bVar8 < 0x39) {
            bVar7 = (bVar8 & 0xf | 2) >> 1;
          }
          do {
            uVar5 = CONCAT11((char)(((uVar5 & 0xff00) + (uVar5 & 0xff) << bVar7) >> 8),
                             (char)((uVar5 * 0x100 + (uVar1 >> 8) << bVar7) >> 8));
            bVar8 = *pbVar13;
            pbVar13 = pbVar13 + 1;
            uVar1 = CONCAT11((char)(((uVar1 & 0xff00) + (uVar1 & 0xff) << bVar7) >> 8),
                             (char)uVar1 << bVar7 | bVar8);
            cVar10 = cVar10 + -1;
          } while (cVar10 != '\0');
          matrix_eval_big(uVar1,uVar5);
          puVar2 = (undefined8 *)bcd_pack_r4();
        }
      }
      dec_set_zero(puVar2);
      return 0;
    }
    bVar7 = (byte)uVar1;
    if (bVar8 < bVar7) {
      return 0;
    }
    if (bVar7 == 0x30) {
      if (cVar11 != '\x02') {
        cVar11 = '\x01';
        goto LAB_rom_016dbc;
      }
    }
    else {
      cVar11 = '\x02';
    }
    if (cVar9 == '\x01') {
      if (bVar8 == 0x39) {
        pbVar13 = &_DAT_ram_3146;
        cVar3 = '\t';
        sVar12 = unaff_ER12;
        do {
          bVar6 = *pbVar13;
          pbVar13 = pbVar13 + 1;
          bVar4 = *(byte *)(sVar12 + 0x28);
          if (bVar4 < bVar6) goto LAB_rom_016e1c;
          if (bVar4 >= bVar6 && bVar4 != bVar6) {
            return 0;
          }
          sVar12 = sVar12 + 1;
          cVar3 = cVar3 + -1;
        } while (cVar3 != '\0');
        if ((byte)(*pbVar13 + 0x30) < bVar7) {
          return 0;
        }
LAB_rom_016e1c:
        _a2 = (ushort)bVar4;
      }
      else if ((bVar8 == 0x37) &&
              (_a2 = (ushort)*(byte *)(unaff_ER12 + 0x28), 3 < *(byte *)(unaff_ER12 + 0x28))) {
        return 0;
      }
    }
    store_cell_if_ne(bVar7);
    if (extraout_R1 == '\0') {
      return 0;
    }
  } while( true );
}

/**
 * @brief 按索引复制矩阵维度（0x2F08 表，0x22A8C 使用）
 * @addr 0x16E9C
 * @module eval
 * @proto void mat_set_dims_ptr(void)
 * @confidence likely
 * @note 按索引复制矩阵维度（0x2F08 表，0x22A8C 使用）。
 * @tag matrix
 */
int mat_set_dims_ptr(void)

{
  ushort uVar1;
  undefined7 uVar2;
  byte bVar3;
  undefined2 *puVar4;
  char cVar5;
  undefined8 in_QR0;
  
  bVar3 = (byte)((ulonglong)in_QR0 >> 8);
  *(undefined2 *)((ushort)(byte)in_QR0 * 2 + -0x2f08) = *(undefined2 *)((ushort)bVar3 * 2 + -0x2f08)
  ;
  uVar1 = (ushort)(CONCAT13(0xa0,(uint3)(byte)in_QR0 << 0x10) >> 0x10);
  uVar2 = CONCAT16(0x50,(uint6)CONCAT22(&stat_data + (uVar1 & 0xff) * (uVar1 >> 8),
                                        &stat_data + (ushort)bVar3 * 0xa0));
  do {
    puVar4 = (undefined2 *)((uint7)uVar2 >> 0x10);
    *puVar4 = *(undefined2 *)uVar2;
    cVar5 = (char)((uint7)uVar2 >> 0x30) + -1;
    uVar2 = CONCAT16(cVar5,(uint6)CONCAT22(puVar4 + 1,(undefined2 *)uVar2 + 1));
  } while (cVar5 != '\0');
  return (short)in_QR0;
}

/**
 * @brief 按 p[0] 低半字节载入矩阵单元维度到 0xD100（0x24A20 使用）
 * @addr 0x16EA4
 * @module eval
 * @proto int mat_load_cell_ptr(byte* p)
 * @confidence likely
 * @note 按 p[0] 低半字节载入矩阵单元维度到 0xD100（0x24A20 使用）。
 * @tag matrix
 */
int mat_load_cell_ptr(byte* p)

{
  ushort uVar1;
  undefined2 *puVar3;
  ushort uVar4;
  undefined7 uVar2;
  char cVar5;
  
  uVar4 = (ushort)(CONCAT15(4,(uint5)(*p & 0xf) << 0x20) >> 0x20);
  _DAT_ram_d100 = *(undefined2 *)((ushort)(*p & 0xf) * 2 + -0x2f08);
  uVar1 = (ushort)(CONCAT13(0xa0,CONCAT12(4,uVar4)) >> 0x10);
  uVar2 = CONCAT16(0x50,(uint6)CONCAT22(&stat_data + (uVar1 & 0xff) * (uVar1 >> 8),
                                        &stat_data + (uVar4 & 0xff) * 0xa0));
  do {
    puVar3 = (undefined2 *)((uint7)uVar2 >> 0x10);
    *puVar3 = *(undefined2 *)uVar2;
    cVar5 = (char)((uint7)uVar2 >> 0x30) + -1;
    uVar2 = CONCAT16(cVar5,(uint6)CONCAT22(puVar3 + 1,(undefined2 *)uVar2 + 1));
  } while (cVar5 != '\0');
  return p;
}

/**
 * @brief 按统计表填充 0xD392 区
 * @addr 0x16EAC
 * @module eval
 * @proto int stat_fill_cells(void)
 * @confidence likely
 * @note 按统计表填充 0xD392 区。
 * @tag stat
 */
int stat_fill_cells(void)

{
  uint uVar1;
  ushort uVar2;
  uint6 uVar3;
  ushort uVar7;
  undefined7 uVar4;
  byte bVar5;
  undefined2 *puVar6;
  char cVar8;
  undefined8 in_QR0;
  
  uVar1 = (uint)((ulonglong)in_QR0 >> 0x20) & 0xffffff0f;
  uVar3 = CONCAT15((char)(uVar1 >> 8),(uint5)uVar1 << 0x20) & 0xfffffffffff;
  uVar7 = (ushort)(uVar3 >> 0x20);
  bVar5 = (byte)(uVar3 >> 0x28);
  *(undefined2 *)((ushort)bVar5 * 2 + -0x2f08) =
       *(undefined2 *)((ushort)(byte)(uVar3 >> 0x20) * 2 + -0x2f08);
  uVar2 = (ushort)(CONCAT13(0xa0,CONCAT12(bVar5,uVar7)) >> 0x10);
  uVar4 = CONCAT16(0x50,(uint6)CONCAT22(&stat_data + (uVar2 & 0xff) * (uVar2 >> 8),
                                        &stat_data + (uVar7 & 0xff) * 0xa0));
  do {
    puVar6 = (undefined2 *)((uint7)uVar4 >> 0x10);
    *puVar6 = *(undefined2 *)uVar4;
    cVar8 = (char)((uint7)uVar4 >> 0x30) + -1;
    uVar4 = CONCAT16(cVar8,(uint6)CONCAT22(puVar6 + 1,(undefined2 *)uVar4 + 1));
  } while (cVar8 != '\0');
  return (short)in_QR0;
}

/**
 * @brief 按模式返回统计表布局
 * @addr 0x16F10
 * @module eval
 * @proto int stat_layout(undefined8* p)
 * @confidence likely
 * @note 按模式返回统计表布局。
 * @tag stat
 */
int stat_layout(undefined8* p)

{
  undefined2 uVar1;
  undefined8 *unaff_ER12;
  
  uVar1 = *(undefined2 *)(unaff_ER12 + 1);
  *p = *unaff_ER12;
  *(undefined2 *)(p + 1) = uVar1;
  if (calc_mode == -0x3c) {
    uVar1 = *(undefined2 *)((short)unaff_ER12 + 0x12);
    *(undefined8 *)((short)p + 10) = *(undefined8 *)((short)unaff_ER12 + 10);
    *(undefined2 *)((short)p + 0x12) = uVar1;
  }
  return p;
}

/**
 * @brief 按模式返回统计表布局（变体）
 * @addr 0x16F44
 * @module eval
 * @proto int stat_layout2(undefined8* p)
 * @confidence likely
 * @note 按模式返回统计表布局（变体）。
 * @tag stat
 */
int stat_layout2(undefined8* p)

{
  undefined2 uVar1;
  undefined8 *unaff_ER12;
  
  uVar1 = *(undefined2 *)(p + 1);
  *unaff_ER12 = *p;
  *(undefined2 *)(unaff_ER12 + 1) = uVar1;
  if (calc_mode == -0x3c) {
    uVar1 = *(undefined2 *)((short)p + 0x12);
    *(undefined8 *)((short)unaff_ER12 + 10) = *(undefined8 *)((short)p + 10);
    *(undefined2 *)((short)unaff_ER12 + 0x12) = uVar1;
  }
  return p;
}

/**
 * @brief 把 src 的 10 字节复制到 ER10
 * @addr 0x16F4A
 * @module eval
 * @proto undefined2* copy_cond_ext(undefined2* src)
 * @confidence likely
 * @note 把 src 的 10 字节复制到 ER10；0xD111==0xC4（向量模式）时再复制 +0x10 的 10 字节。
 * @tag matrix
 */
undefined2* copy_cond_ext(undefined2* src, int _a2)

{
  undefined2 uVar1;
  undefined8 *unaff_ER10;
  
  uVar1 = *(undefined2 *)(src + 1);
  *unaff_ER10 = *src;
  *(undefined2 *)(unaff_ER10 + 1) = uVar1;
  if (calc_mode == -0x3c) {
    uVar1 = *(undefined2 *)((short)src + 0x12);
    *(undefined8 *)((short)unaff_ER10 + 10) = *(undefined8 *)((short)src + 10);
    *(undefined2 *)((short)unaff_ER10 + 0x12) = uVar1;
  }
  return _a2;
}

/**
 * @brief 以当前操作数槽为目标的 0x16F4A 包装
 * @addr 0x16F50
 * @module eval
 * @proto undefined2* copy_opnd(undefined2* src)
 * @confidence likely
 * @note 以当前操作数槽为目标的 0x16F4A 包装。
 * @tag matrix
 */
undefined2* copy_opnd(undefined2* src)

{
  undefined in_R2;
  undefined in_R3;
  undefined unaff_R8;
  undefined unaff_R10;
  
  copy_cond_ext(src,in_R2,in_R3,unaff_R8,unaff_R10,src);
  return;
}

/**
 * @brief 读取统计表单元格
 * @addr 0x16F5A
 * @module eval
 * @proto void stat_cell_read(undefined8* p)
 * @confidence likely
 * @note 读取统计表单元格。
 * @tag stat
 */
int stat_cell_read(undefined8* p)

{
  undefined in_R2;
  undefined in_R3;
  undefined unaff_R8;
  undefined unaff_R10;
  
  copy_cond_ext(p,in_R2,in_R3,unaff_R8,unaff_R10,p);
  return 0;
}

/**
 * @brief 按 ER12 处操作数首字节高半字节映射精度档（0xF->7、9->3、6->1、2/8/0…
 * @addr 0x16F62
 * @module eval
 * @proto byte matrix_prec(void)
 * @confidence strong
 * @note 按 ER12 处操作数首字节高半字节映射精度档（0xF->7、9->3、6->1、2/8/0->0）。
 * @tag matrix
 */
byte matrix_prec(void)

{
  byte bVar1;
  undefined uVar2;
  byte *unaff_ER12;
  
  uVar2 = 7;
  bVar1 = *unaff_ER12 >> 4;
  if ((((bVar1 != 0xf) && (uVar2 = 3, bVar1 != 9)) && (uVar2 = 1, bVar1 != 6)) &&
     ((((uVar2 = 0, bVar1 != 2 && (bVar1 != 8)) && (bVar1 != 0)) ||
      ((calc_mode != -0x3c || (*(short *)(unaff_ER12 + 0x12) == 0)))))) {
    return uVar2;
  }
  return uVar2;
}

/**
 * @brief 按单元类型高位确定可保留的精度档（0xF 直接返回，0/0xFF 特殊处理）
 * @addr 0x16F64
 * @module eval
 * @proto byte matrix_prec_limit(byte v)
 * @confidence likely
 * @note 按单元类型高位确定可保留的精度档（0xF 直接返回，0/0xFF 特殊处理）。
 * @tag matrix
 */
byte matrix_prec_limit(byte v)

{
  char cVar1;
  byte bVar2;
  byte bVar3;
  byte *unaff_ER12;
  
  bVar2 = *unaff_ER12 >> 4;
  if (bVar2 == 0xf) {
    return v;
  }
  if (v == 0xff) {
    return 0xff;
  }
  if (v == 0) {
    bVar3 = 0;
    if ((bVar2 != 8) && (5 < bVar2)) {
      return 0;
    }
  }
  else {
    bVar3 = v >> 1;
    if (((-1 < (char)(v << 7)) || (bVar2 != 9)) &&
       ((cVar1 = bVar3 << 7, bVar3 = v >> 2, -1 < cVar1 || (bVar2 != 6)))) {
      cVar1 = bVar3 << 7;
      bVar3 = v >> 3;
      if (-1 < cVar1) {
        return bVar3;
      }
      if (((bVar2 != 2) && (bVar2 != 8)) && (bVar2 != 0)) {
        return bVar3;
      }
      if (calc_mode != -0x3c) {
        return bVar3;
      }
      if (*(short *)(unaff_ER12 + 0x12) == 0) {
        return bVar3;
      }
    }
  }
  return bVar3;
}

/**
 * @brief R6==0xFF 且 t 为 3/8 时把常量 0x1B62 复制到操作数槽
 * @addr 0x16FB4
 * @module eval
 * @proto void matrix_fix_operand(char t)
 * @confidence likely
 * @note R6==0xFF 且 t 为 3/8 时把常量 0x1B62 复制到操作数槽。
 * @tag matrix
 */
int matrix_fix_operand(char t)

{
  char unaff_R6;
  
  if ((unaff_R6 == -1) && ((t == '\b' || (t == '\x03')))) {
    stat_layout2((undefined8 *)0x1b62);
  }
  return 0;
}

/**
 * @brief 复制并调整矩阵操作数（+0x0A/+0x14 槽）供 0x171F0 使用
 * @addr 0x16FCE
 * @module eval
 * @proto void mat_opnd_copy(void)
 * @confidence likely
 * @note 复制并调整矩阵操作数（+0x0A/+0x14 槽）供 0x171F0 使用。
 * @tag matrix
 */
int mat_opnd_copy(uintptr_t _a2, int _a1)

{
  undefined2 *puVar1;
  undefined2 *puVar2;
  undefined2 *puVar3;
  ushort uVar4;
  undefined uVar6;
  undefined8 *puVar5;
  char unaff_R4;
  char unaff_R5;
  char unaff_R10;
  undefined2 *unaff_ER12;
  
  puVar3 = unaff_ER12 + 10;
  puVar5 = (undefined8 *)(unaff_ER12 + 0x14);
  uVar6 = (undefined)((ushort)_a1 >> 8);
  dec_set_uint_small((ushort *)puVar5,0);
  if (((unaff_R10 != '\0') && (stat_entry_ptr(), unaff_R5 == '\0')) && (unaff_R4 == -0x24)) {
    if (unaff_R10 != '\x01') {
      stat_entry_ptr();
      dec_set_from_fmt(puVar3,CONCAT11(uVar6,0x24));
      *(undefined *)(unaff_ER12 + 0xe) = 3;
      puVar2 = puVar3;
      puVar1 = (undefined2 *)dec_cmp_signed(unaff_ER12,puVar3);
      dec_bin_and(puVar1,puVar2);
      stat_layout(puVar5);
      puVar2 = unaff_ER12;
      matrix_opnd_advance();
      uVar6 = (undefined)((ushort)puVar2 >> 8);
    }
    dec_set_from_fmt(puVar3,CONCAT11(uVar6,0x3c));
    puVar2 = (undefined2 *)dec_cmp_signed(unaff_ER12,puVar3);
    dec_bin_and(puVar2,puVar3);
    dec_bin_div(unaff_ER12,(undefined2 *)puVar5);
    stat_layout(puVar5);
    matrix_opnd_advance();
  }
  puVar3 = (undefined2 *)dec_cmp_signed(unaff_ER12,puVar5);
  uVar4 = dec_bin_div(puVar3,(undefined2 *)puVar5);
  if ((((char)uVar4 == '\0') && (uVar4 = dec_cmp_ex(unaff_ER12,puVar5), (char)uVar4 == '\0')) &&
     ((*(char *)((short)unaff_ER12 + 9) == '\0' ||
      ((*(char *)((short)unaff_ER12 + 9) == '\x05' || (*(byte *)(unaff_ER12 + 4) < 7)))))) {
    uVar4 = (ushort)*(byte *)unaff_ER12 << 8 | 0x4000;
    *(char *)unaff_ER12 = (char)(uVar4 >> 8);
  }
  matrix_fix_operand((char)uVar4);
  return 0;
}

/**
 * @brief 以键码 0xAF 分派到 0x17150（菜单方向键类按键）
 * @addr 0x1708C
 * @module eval
 * @proto undefined2 key_af_dispatch(undefined2 a)
 * @confidence likely
 * @note 以键码 0xAF 分派到 0x17150（菜单方向键类按键）。
 * @tag key
 */
undefined2 key_af_dispatch(undefined2 a, int _a2, int _a3, int _a4)

{
  key_af_handler(0xaf,_a2,_a3,_a4);
  return a;
}

/**
 * @brief 0x17150 的子分派
 * @addr 0x170AE
 * @module eval
 * @proto void key_af_lists(undefined2 k)
 * @confidence likely
 * @note 0x17150 的子分派：按 0xD114 bit6 与键值选择列表操作。
 * @tag key
 */
int key_af_lists(undefined2 k, int _a2, int _a3, int _a4)

{
  char cVar1;
  byte bVar2;
  ushort uVar3;
  char unaff_R6;
  byte unaff_R7;
  undefined3 unaff_retaddr;
  undefined auStack_18 [20];
  undefined4 in_stack_0000fffc;
  
  cVar1 = (char)k;
  if ((edit_state2 & 0x40) == 0) {
    if ((unaff_R6 != '\x01') && (unaff_R6 != -1)) goto LAB_rom_0170d0;
  }
  else {
    if (cVar1 == -0x79) {
      return k;
    }
    if (cVar1 == -0x75) {
      return k;
    }
  }
  if (cVar1 == '~') {
    return k;
  }
  if (cVar1 == '\x7f') {
    return k;
  }
LAB_rom_0170d0:
  if (2 < unaff_R7) {
    bVar2 = (cVar1 == -0x40) << 6;
    if (cVar1 == -0x40) {
      return k;
    }
    k = key_af_dispatch(k,_a2,(undefined2 *)unaff_retaddr, (uintptr_t)0)
                             (undefined2 *)
                             (CONCAT13((char)((uint)in_stack_0000fffc >> 0x18),unaff_retaddr) >>
                             0x10));
    if ((bVar2 >> 6 & 1) != 1) {
      return k;
    }
  }
  bVar2 = (byte)k;
  if ((0xc0 < bVar2) && (bVar2 < 0xc5)) {
    uVar3 = matrix_eval_dispatch(bVar2,_a2);
    return uVar3;
  }
  uVar3 = store_mat_word(k);
  if (((char)_a2 == '\0') && ((bVar2 = (byte)uVar3, bVar2 < 0x54 || (bVar2 < 0x5c)))) {
    var_get_value(8,auStack_18);
    if (bVar2 == 0x53) {
      uVar3 = nop_rt_4();
    }
    else if (bVar2 == 0x51) {
      uVar3 = stat_editor(uVar3,_a2);
    }
    else if (bVar2 == 0x52) {
      uVar3 = stat_ui_loop(uVar3);
    }
    else {
      uVar3 = stat_view_loop(uVar3,_a2,_a3,_a4);
    }
    base_clear(CONCAT11((char)(uVar3 >> 8),8),auStack_18);
    return uVar3;
  }
  return uVar3;
}

/**
 * @brief 键码 0xAF 处理
 * @addr 0x17150
 * @module eval
 * @proto undefined2 key_af_handler(undefined2 k, undefined2 ctx)
 * @confidence likely
 * @note 键码 0xAF 处理：按 0xD111/0xD114 状态分派（列表/表格方向键、0x170AE 子处理）。
 * @tag key
 */
undefined2 key_af_handler(undefined2 k, undefined2 ctx, int _a3, int _a4)

{
  undefined2 uVar1;
  byte bVar2;
  ushort *puVar3;
  char unaff_R6;
  byte unaff_R7;
  byte unaff_R10;
  char unaff_R12;
  char cVar5;
  undefined uVar4;
  
  uVar4 = (undefined)((ushort)ctx >> 8);
  puVar3 = (ushort *)CONCAT11(uVar4,calc_mode);
  cVar5 = (char)k;
  if ((calc_mode == -0x77) && (cVar5 == -0x5b)) {
    matrix_key_walk((ushort)puVar3);
    return;
  }
  if (((((edit_state2 & 0x40) != 0) || (unaff_R6 == '\x01')) || (unaff_R6 == -1)) &&
     (cVar5 == -0x56)) {
    return;
  }
  if (unaff_R7 < 3) {
    if (cVar5 == -0x59) {
      key_af_lists(0xc0,(ushort)puVar3,_a3,_a4);
      return;
    }
    if (cVar5 != -0x5a) {
      return;
    }
    return;
  }
  if (cVar5 == -0x38) {
    puVar3 = (ushort *)CONCAT11(uVar4,unaff_R10);
    k = mat_digits_loop(k,unaff_R10);
    if ((char)puVar3 == '\0') goto LAB_rom_0171c0;
    bVar2 = (char)puVar3 - 1;
    puVar3 = (ushort *)CONCAT11((char)((ushort)puVar3 >> 8),bVar2);
    k = mat_digits_loop(k,bVar2);
    if ((char)puVar3 != '\0') {
      return;
    }
  }
  if ((char)k == -0x5b) {
    if (unaff_R6 != '\0') {
      return;
    }
    if ((edit_state2 & 0x40) == 0) {
      return;
    }
    bVar2 = stat_var_num & 1;
    stat_var_num = stat_var_num | 1;
    if (bVar2 != 0) {
      return;
    }
  }
LAB_rom_0171c0:
  uVar1 = mat_digits_eval(k,puVar3);
  if ((((char)puVar3 == '\0') &&
      ((cVar5 = ((byte)uVar1 < 200) << 7, (byte)uVar1 != 200 || (matrix_prec_limit(3), -1 < cVar5))))
     && (uVar1 = matrix_copy_to_slot(), unaff_R12 == '\0')) {
    if ((unaff_R10 != 0) && ((char)uVar1 == -0x5b)) {
      return;
    }
    store_mat_word(uVar1);
  }
  return;
}

/**
 * @brief 矩阵单元求值主分派（9KB）
 * @addr 0x171F0
 * @module eval
 * @proto ushort matrix_value_calc(ushort k, ushort* a)
 * @confidence likely
 * @note 矩阵单元求值主分派（9KB）：R7<3 直接返回
 *       2；按键值/单元类型调用0x16820/0x16CC8/0x1767C/0x17680 等，返回单元状态。
 * @tag matrix
 */
ushort matrix_value_calc(ushort k, ushort* a)

{
  bool bVar1;
  bool bVar2;
  ushort uVar3;
  undefined2 uVar4;
  undefined8 *puVar5;
  char cVar6;
  byte bVar7;
  ushort *puVar8;
  ushort uVar9;
  undefined uVar10;
  undefined2 unaff_ER4;
  byte unaff_R7;
  byte bVar11;
  ushort uVar12;
  char cVar13;
  char cVar14;
  byte unaff_R10;
  byte bVar15;
  undefined2 *unaff_ER12;
  undefined3 unaff_retaddr;
  undefined4 in_stack_0000fffc;
  undefined4 uVar16;
  
  uVar16 = CONCAT13((char)((uint)in_stack_0000fffc >> 0x18),unaff_retaddr);
  if (unaff_R7 < 3) {
    return k;
  }
  cVar6 = (char)(k >> 8);
  cVar13 = (char)((ushort)unaff_ER4 >> 8);
  if ((cVar6 == '\0') && ((char)k == -0x24)) {
    bVar15 = (unaff_R7 < 3) << 7 | (unaff_R7 == 3) << 6;
    if (unaff_R7 == 3) {
      return k;
    }
    uVar3 = matrix_prec();
    if ((char)bVar15 < '\0') {
      return uVar3;
    }
    uVar3 = eval_token_scan();
    uVar3 = dec_set_zero(uVar3);
    bVar15 = (byte)a;
    if (bVar15 == 4) {
      if (1 < unaff_R10) {
        cVar6 = '\x02';
        while ((uVar4 = stat_entry_ptr(), cVar13 == '\0' && ((byte)unaff_ER4 == 0xdc))) {
          cVar6 = cVar6 + -1;
          if (cVar6 == '\0') {
            uVar3 = advance_token_ptr(uVar4);
            return uVar3;
          }
        }
      }
      uVar3 = matrix_copy_to_slot();
      if ((char)unaff_ER12 != '\0') {
        return uVar3;
      }
      uVar3 = store_mat_word(0xdc);
      return uVar3;
    }
    if (((char)(uVar3 >> 8) == '\0') && ((char)uVar3 == -0x40)) {
      uVar3 = advance_token_ptr(uVar3);
      return uVar3;
    }
    puVar8 = a;
    mat_opnd_copy(a);
    if ((char)puVar8 != '\0') {
      return uVar3;
    }
    if (unaff_R10 == 0) {
      store_mat_word(0xdc);
    }
    if (((bVar15 != 2) && (bVar15 != 3)) && (bVar15 < 8)) {
      uVar3 = key_af_dispatch(uVar3,a,(undefined2 *)uVar16,(undefined2 *)((uint)uVar16 >> 0x10)
                            );
      return uVar3;
    }
    return uVar3;
  }
  if ((cVar6 == '\0') && ((char)k == -0x30)) {
    bVar2 = unaff_R10 == 0;
    bVar15 = bVar2 << 6;
    while( true ) {
      if (bVar2) {
        return k;
      }
      stat_entry_ptr();
      k = emit_noop_guard();
      if ((char)bVar15 < '\0') break;
      bVar1 = unaff_R10 != 0;
      unaff_R10 = unaff_R10 - 1;
      bVar2 = unaff_R10 == 0;
      bVar15 = bVar1 << 7 | bVar2 << 6;
    }
    uVar3 = matrix_walk_b((ushort)a);
    if ((char)a != '\0') {
      return uVar3;
    }
    if (cVar13 != '\0') {
      return uVar3;
    }
    if (0x53 < (byte)unaff_ER4) {
      return uVar3;
    }
    return uVar3;
  }
  uVar3 = mat_digits_eval(k,a);
  if ((char)a != '\0') {
    return uVar3;
  }
  cVar13 = (char)(uVar3 >> 8);
  cVar6 = (char)uVar3;
  if ((cVar13 != '\0') || (cVar6 != -0x17)) {
    if ((cVar13 != '\0') || ((cVar6 != -0x2e && (cVar6 != -0x2d)))) {
      if (unaff_R10 == 0) {
        uVar3 = store_mat_word(uVar3);
      }
      uVar3 = matrix_eval_tree(uVar3,a);
      return uVar3;
    }
    puVar5 = (undefined8 *)eval_token_scan();
    bVar15 = stat_var_num;
    if ((char)a == '\b') {
      matrix_edit_key_b(puVar5,(ushort)a);
      cVar6 = (char)a;
    }
    else {
      if ((char)a != '\n') {
        return uVar3;
      }
      if (stat_var_num == 0) {
        dec_set_zero((ushort)stat_var_num);
        matrix_walk((ushort)a);
        if ((char)a == '\0') {
          uVar3 = advance_token_ptr(uVar3);
          return uVar3;
        }
        return uVar3;
      }
      stat_var_num = 0;
      uVar9 = CONCAT11((char)((ushort)a >> 8),8);
      puVar5 = (undefined8 *)dec_set_zero(CONCAT11(0xfb,bVar15 - 0x30));
      matrix_edit_key(puVar5,uVar9);
      cVar6 = (char)uVar9;
    }
    if (cVar6 != -1) {
      return uVar3;
    }
    return uVar3;
  }
  if (2 < unaff_R7) {
    return uVar3;
  }
  uVar9 = CONCAT11((char)((ushort)a >> 8),calc_mode);
  if (calc_mode == '\x02') {
    dec_set_zero(uVar3);
    uVar3 = matrix_eval_dispatch(((sub_mode & 0xc) >> 2) - 0x3f,uVar9);
    return uVar3;
  }
  bVar11 = 0xff;
  cVar6 = -1;
  bVar15 = 0;
  do {
    bVar7 = (byte)uVar3;
    if (bVar7 == 0x2f) {
      return uVar3;
    }
    if (bVar7 == 0x30) {
      if (bVar15 == 2) goto LAB_rom_0173be;
      bVar15 = 1;
    }
    else {
      if (bVar7 == 0x2e) {
        bVar15 = bVar15 + (bVar15 == 0);
        goto LAB_rom_0173ce;
      }
      if (bVar7 == 0x2d) {
        if (bVar15 == 0) {
          bVar15 = 2;
          cVar6 = cVar6 + '\x01';
          store_cell_if_lt(0x31);
        }
        goto LAB_rom_017410;
      }
      bVar15 = 2;
LAB_rom_0173be:
      if (SBORROW1(cVar6 + '\x01','d') == (char)(cVar6 + -99) < '\0') {
        return uVar3;
      }
      store_cell_if_lt(bVar7);
      cVar6 = cVar6 + '\x01';
    }
    uVar3 = eval_token_scan();
    if (10 < (byte)uVar9) {
      return uVar3;
    }
  } while ((byte)uVar9 == 4);
LAB_rom_01744a:
  if (((char)(uVar3 >> 8) == '\0') && ((char)uVar3 == -0x40)) {
    return uVar3;
  }
  if ((bVar15 & 2) != 0) {
    if ((0xef < bVar11) && (bVar11 = bVar11 & 0xf, 0xe < bVar11)) {
      bVar11 = 0;
    }
    uVar9 = uVar9 & 0xff00;
    while( true ) {
      bVar2 = bVar11 < 0x10;
      bVar11 = bVar11 - 0x10;
      uVar10 = (undefined)(uVar9 >> 8);
      if (bVar2) break;
      uVar9 = CONCAT11(uVar10,(char)uVar9 + '\n');
    }
    uVar12 = CONCAT11(cVar6,bVar11) & 0xff0f;
    bVar7 = (char)uVar9 + (char)uVar12;
    bVar11 = bVar15 & 0x80;
    bVar15 = bVar15 & 0x7f;
    if (bVar11 != 0) {
      bVar7 = -bVar7;
    }
    bVar11 = (byte)(uVar12 >> 8);
    cVar6 = bVar7 + bVar11;
    uVar9 = CONCAT11(uVar10,cVar6);
    if (SCARRY1(bVar7,bVar11) == false) {
      if (cVar6 < '\0') {
        if ((byte)(SBORROW1(cVar6,-99) ^ (char)(cVar6 + 'c') < '\0') == 1) goto LAB_rom_0174be;
        uVar9 = CONCAT11(uVar10,cVar6 + 'd');
        uVar10 = 0;
      }
      else {
        if ((byte)(SBORROW1(cVar6,'c') ^ (char)(cVar6 + -99) < '\0' | cVar6 == 'c') == 0) {
          return uVar3;
        }
        uVar10 = 1;
      }
      *(undefined *)((short)unaff_ER12 + 9) = uVar10;
      cVar6 = '\x01';
      cVar13 = '\0';
      do {
        bVar7 = (byte)uVar9;
        bVar11 = bVar7 >> 1;
        uVar9 = CONCAT11((char)(uVar9 >> 8),bVar11);
        if ((char)(bVar7 << 7) < '\0') {
          cVar13 = daa(cVar13 + cVar6);
        }
        cVar6 = daa(cVar6 * '\x02');
      } while (bVar11 != 0);
      *(char *)(unaff_ER12 + 4) = cVar13;
      unaff_ER12[3] = 0;
      unaff_ER12[2] = 0;
      unaff_ER12[1] = 0;
      *(undefined *)((short)unaff_ER12 + 1) = 0;
      nibble_unpack();
      goto LAB_rom_0174c6;
    }
    if (-1 < (char)(CARRY1(bVar7,bVar11) << 7 | SCARRY1(bVar7,bVar11) << 4 | (cVar6 < '\0') << 5)) {
      return uVar3;
    }
  }
LAB_rom_0174be:
  stat_layout2((undefined8 *)0x1b62);
LAB_rom_0174c6:
  if ((bVar15 & 4) != 0) {
    eval_recip(unaff_ER12);
  }
  uVar3 = dec_cmp_ex(unaff_ER12,uVar9);
  if ((char)uVar3 != '\0') {
    return uVar3;
  }
  if (calc_mode == -0x3c) {
    uVar3 = dec_set_uint_small(unaff_ER12 + 5,0);
  }
  uVar3 = dec_set_zero(uVar3);
  return uVar3;
LAB_rom_0173ce:
  uVar3 = eval_token_scan();
  if (10 < (byte)uVar9) {
    return uVar3;
  }
  if ((byte)uVar9 != 4) goto LAB_rom_01744a;
  bVar7 = (byte)uVar3;
  if (bVar7 == 0x2f) {
    uVar3 = eval_token_scan();
    if ((char)uVar9 != '\x04') {
      return uVar3;
    }
    dec_set_zero(uVar3);
    goto LAB_rom_01750e;
  }
  if (bVar7 == 0x30) {
    if (bVar15 == 2) goto LAB_rom_0173fc;
    cVar14 = cVar6 + -1;
    cVar13 = cVar6 + 'c';
    cVar6 = cVar14;
    if ((byte)(SBORROW1(cVar14,-100) ^ cVar13 < '\0' | cVar14 == -100) == 1) {
      return uVar3;
    }
  }
  else {
    if (bVar7 == 0x2e) {
      return uVar3;
    }
    if (bVar7 == 0x2d) goto LAB_rom_017410;
    bVar15 = 2;
LAB_rom_0173fc:
    store_cell_if_lt(bVar7);
  }
  goto LAB_rom_0173ce;
LAB_rom_01750e:
  uVar3 = eval_token_scan();
  if (10 < (byte)uVar9) {
    return uVar3;
  }
  if ((byte)uVar9 != 4) {
    if (bVar15 != 2) goto LAB_rom_01744a;
    goto LAB_rom_01750e;
  }
  bVar7 = (byte)uVar3;
  if (bVar7 < 0x30) {
    return uVar3;
  }
  if (bVar7 == 0x30) {
    if (bVar15 == 2) goto LAB_rom_017536;
    cVar14 = cVar6 + -1;
    cVar13 = cVar6 + 'c';
    cVar6 = cVar14;
    if ((byte)(SBORROW1(cVar14,-100) ^ cVar13 < '\0' | cVar14 == -100) == 1) {
      return uVar3;
    }
  }
  else {
    bVar15 = 2;
LAB_rom_017536:
    store_cell_if_lt(bVar7);
  }
  goto LAB_rom_01750e;
LAB_rom_017410:
  while( true ) {
    uVar3 = eval_token_scan();
    if (10 < (byte)uVar9) {
      return uVar3;
    }
    bVar7 = (byte)uVar3;
    if ((byte)uVar9 != 4) break;
    if ((char)((bVar7 < 0x30) << 7) < '\0') {
      return uVar3;
    }
    if ((char)((bVar11 < 0xf0) << 7) < '\0') {
      return uVar3;
    }
    bVar11 = bVar11 << 4 | bVar7 & 0xf;
  }
  if (bVar11 == 0xff) {
    if ((char)(uVar3 >> 8) != '\0') {
      return uVar3;
    }
    if (bVar7 != 0xc0) goto code_s0x017438;
    goto LAB_rom_017446;
  }
  goto LAB_rom_01744a;
code_s0x017438:
  if (bVar7 != 0xa6) {
    if (bVar7 != 0xa7) {
      return uVar3;
    }
LAB_rom_017446:
    bVar15 = bVar15 ^ 0x80;
  }
  goto LAB_rom_017410;
}

