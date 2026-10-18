/*
 * 字符串与格式化 / 2196a_nxsb_test.c
 * 地址范围: 0x2196A - 0x21E9C
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief nX-U8 墓碑函数
 * @addr 0x2196A
 * @module strlib
 * @proto short nxsb_test(byte bit)
 * @confidence verified
 * @note nX-U8 墓碑函数：R1=0，ADD ER0,ER8，RT。即测试 *ER8 的指定位（结果在 R9 零标志），并保留
 *       clockless 语义；Ghidra 因缺失数据流分析，把它识别成“(ushort)param_1 +
 *       unaff_ER8”。全 ROM 共 50 处 BL 调用。
 * @tag hw
 */
short nxsb_test(byte bit)

{
  short unaff_ER8;
  
  return (ushort)bit + unaff_ER8;
}

/**
 * @brief nX-U8 墓碑函数
 * @addr 0x21970
 * @module strlib
 * @proto void nxsb_clear(void)
 * @confidence verified
 * @note nX-U8 墓碑函数：R3=0，ADD ER2,ER8，RT。即写 0 并丢弃结果（清除 *ER2 的位 / 空写）。全
 *       ROM 共 39 处 BL 调用。
 * @tag hw
 */
int nxsb_clear(void)

{
  return 0;
}

/**
 * @brief 矩阵单元上下文（0x21134 后处理 +0x3C/+0x28 槽）
 * @addr 0x21976
 * @module strlib
 * @proto void mat_cell_ctx(ushort sel)
 * @confidence likely
 * @note 矩阵单元上下文（0x21134 后处理 +0x3C/+0x28 槽）。
 * @tag matrix
 */
int mat_cell_ctx(ushort sel, int _a2)

{
  char cVar1;
  undefined8 *puVar2;
  undefined2 *puVar3;
  ushort uVar4;
  short sVar5;
  short unaff_ER8;
  undefined2 unaff_ER12;
  byte bVar6;
  
  input_clear8(sel,(undefined *)(unaff_ER8 + 0x3c));
  uVar4 = unaff_ER8 + 0x28;
  dec_bin_div_core(0xd36a,uVar4);
  bVar6 = 0;
  str_parse_number(uVar4,_a2);
  if ((bVar6 >> 6 & 1) != 0) {
    puVar2 = stat_layout(sel);
    input_clear8(puVar2,(undefined *)(unaff_ER8 + 0x3c));
    uVar4 = unaff_ER8 + 0x28;
    dec_bin_mul_core(0xd36a,uVar4);
    bVar6 = 0;
    str_parse_number(uVar4,_a2);
    if ((bVar6 >> 6 & 1) != 0) {
      dec_bin_mul_core(sel,unaff_ER12);
      sVar5 = unaff_ER8 + 0x1e;
      dec_bin_and_core(sel,sVar5);
      puVar3 = (undefined2 *)dec_cmp_signed(sel,sVar5);
      cVar1 = dec_cmp_ex(puVar3,sVar5);
      if (cVar1 == '\0') {
        return 0;
      }
      return 0xff;
    }
  }
  return 3;
}

/**
 * @brief STAT 模式菜单/编辑界面循环（stat_layout/stat_cell_read/st…
 * @addr 0x219FE
 * @module strlib
 * @proto int stat_ui_loop(void)
 * @confidence strong
 * @note STAT 模式菜单/编辑界面循环（stat_layout/stat_cell_read/str_parse_number）。
 * @tag stat
 */
int stat_ui_loop(uintptr_t _a2, int _a1)

{
  int bVar1;
  int cVar2;
  undefined extraout_R1;
  undefined2 uVar3;
  ushort uVar4;
  undefined8 *puVar5;
  undefined8 *puVar6;
  undefined extraout_R1_00;
  byte bVar7;
  byte bVar12;
  undefined2 uVar8;
  ushort *puVar9;
  undefined uVar13;
  undefined *puVar10;
  undefined2 *puVar11;
  short sVar14;
  char unaff_R6;
  int cVar15;
  ushort uVar16;
  ushort *unaff_ER12;
  undefined2 unaff_ER14;
  byte bVar17;
  undefined2 *in_stack_0000ff32;
  undefined2 *in_stack_0000ff34;
  undefined2 *in_stack_0000ff3a;
  undefined2 *in_stack_0000ff3c;
  undefined2 *in_stack_0000ff3e;
  undefined8 uStack_9e;
  undefined8 uStack_94;
  ushort auStack_8a [5];
  ushort auStack_80 [5];
  ushort auStack_76 [5];
  ushort auStack_6c [5];
  undefined8 local_62;
  undefined2 uStack_5a;
  ushort auStack_58 [5];
  undefined auStack_4e [10];
  undefined auStack_44 [10];
  undefined8 uStack_3a;
  undefined8 uStack_30;
  undefined8 auStack_26 [4];
  undefined auStack_6 [2];
  
  if (unaff_R6 != '\0') {
    return 0;
  }
  screen_mode_blank(_a1);
  puVar6 = &local_62;
  bVar7 = (byte)puVar6;
  bVar12 = (byte)((ushort)puVar6 >> 8);
  sVar14 = (ushort)bVar12 + (ushort)(0xa5 < bVar7);
  bVar17 = (char)((ushort)sVar14 >> 8) << 7;
  uVar4 = CONCAT11((char)sVar14,bVar7 + 0x5a);
  *(undefined **)uVar4 = auStack_6;
  str_parse_number(uVar4,in_stack_0000ff3e);
  if (-1 < (char)bVar17 && (bVar17 >> 6 & 1) != 1) {
    return 0;
  }
  if ((bVar17 >> 6 & 1) != 1) {
    return 0;
  }
  bVar17 = bVar17 & 0x9f;
  bVar1 = str_parse_number(uVar4,in_stack_0000ff3e);
  if ((char)bVar17 < '\0') {
    return 0;
  }
  uVar4 = CONCAT11((char)(uVar4 >> 8),bVar1);
  dec_cmp_signed(unaff_ER12,uVar4);
  stat_layout(auStack_26);
  cVar15 = (char)uVar4;
  bVar17 = (cVar15 != -1) << 7 | (cVar15 == -1) << 6;
  if (cVar15 == -1) {
    if ((edit_state2 & 0x40) != 0) goto LAB_rom_021a90;
    stat_layout2((undefined8 *)0x1b6c);
    unaff_ER12[4] = 0x90;
    stat_layout(&uStack_30);
    *(undefined *)(unaff_ER12 + 4) = 0x93;
    puVar5 = stat_layout((undefined8 *)CONCAT11(bVar12 + (0xb9 < bVar7),bVar7 + 0x46));
    *(undefined *)((short)puVar5 + 10) = 0xff;
  }
  else {
    bVar1 = str_parse_number(uVar4,in_stack_0000ff3e);
    if ((char)bVar17 < '\0') {
      return 0;
    }
    if ((bVar17 >> 6 & 1) != 0) {
      dec_set_zero(CONCAT11(extraout_R1,bVar1));
    }
    matrix_prec();
    if ((char)uVar4 != '\0') {
      return 0;
    }
    dec_cmp_signed(unaff_ER12,uVar4);
    uVar3 = dec_cmp(unaff_ER12,uVar4);
    if ((char)uVar3 != '\x04') {
      return 0;
    }
    if ((edit_state2 & 0x40) != 0) {
LAB_rom_021a90:
      uVar4 = dec_unary_sin((undefined2 *)auStack_26,uVar4);
      bVar1 = (byte)(uVar4 >> 8);
      bVar17 = bVar1 - ((char)uVar4 == '\0');
      if ((byte)((byte)((bVar17 ^ bVar1) & ~bVar17) >> 7 ^ (char)bVar17 < '\0') == 1) {
        stat_layout2((undefined8 *)0x1b6c);
        unaff_ER12[4] = 0x95;
      }
      else {
        stat_layout2((undefined8 *)0x1b6c);
        unaff_ER12[4] = 0x98;
      }
    }
    stat_layout(&uStack_30);
    *(undefined *)CONCAT11(bVar12 + (0xb9 < bVar7),bVar7 + 0x46) = 0xff;
  }
  puVar5 = auStack_26;
  input_clear8(unaff_ER14,(undefined *)puVar5);
  bVar17 = 0;
  str_parse_number((ushort)puVar5,in_stack_0000ff3c);
  if ((bVar17 >> 6 & 1) != 1) {
    return 0;
  }
  stat_layout2(auStack_26);
  uVar3 = dec_cmp(unaff_ER12,puVar5);
  uVar8 = CONCAT11((char)((ushort)puVar5 >> 8),0x98);
  if ((char)uVar3 != '\x01') {
    copy_opnd((undefined8 *)0x1b6c);
    unaff_ER12[0xe] = 0x97;
    puVar9 = unaff_ER12 + 10;
    dec_bin_pow_core(unaff_ER12,puVar9);
    uVar8 = CONCAT11((char)((ushort)puVar9 >> 8),1);
    dec_to_bcd_b(unaff_ER12,uVar8);
    if (*(char *)unaff_ER12 != '\0') {
      uVar4 = unaff_ER12[4];
      bVar17 = (byte)(uVar4 >> 8);
      if (4 < bVar17) {
        uVar4 = CONCAT11(bVar17 - 5,(char)uVar4);
      }
      if (((char)(uVar4 >> 8) != '\0') || (6 < (byte)uVar4)) goto LAB_rom_021b6e;
    }
    uVar8 = CONCAT11((char)((ushort)uVar8 >> 8),7);
  }
  *(char *)(unaff_ER12 + 4) = (char)uVar8;
  *(undefined *)unaff_ER12 = 1;
LAB_rom_021b6e:
  uVar13 = (undefined)((ushort)uVar8 >> 8);
  stat_layout(&uStack_3a);
  dec_set_from_fmt(auStack_6c,CONCAT11(uVar13,10));
  dec_set_uint_small(auStack_76,2);
  dec_bcd_to_bin(auStack_76,0xffff);
  dec_set_uint_small(auStack_80,9);
  uVar3 = dec_bcd_to_bin(auStack_80,0xffff);
  puVar5 = auStack_26;
  input_clear8(uVar3,(undefined *)puVar5);
  bVar17 = 0;
  str_parse_number((ushort)puVar5,in_stack_0000ff3c);
  if ((bVar17 >> 6 & 1) == 1) {
    dec_cmp_signed(unaff_ER12,puVar5);
    stat_layout(&uStack_94);
    dec_set_uint_small((ushort *)&uStack_9e,0);
    cVar15 = '\a';
    do {
      puVar9 = auStack_8a;
      dec_copy_ret((undefined2 *)auStack_26,puVar9);
      cVar2 = dec_bin_div_core(puVar9,&uStack_3a);
      if (cVar2 != '\0') {
        return 0;
      }
      bVar17 = bcd_type((byte *)&uStack_9e);
      uVar3 = CONCAT11(extraout_R1_00,bVar17);
      if ((bVar17 != 0) &&
         (uVar3 = dec_round_scaled(auStack_8a,(undefined2 *)auStack_26), (char)uVar3 == '\x01')) {
        return 0;
      }
      puVar9 = auStack_8a;
      input_clear8(uVar3,(undefined *)puVar9);
      str_parse_number((ushort)puVar9,in_stack_0000ff3a);
      dec_cmp_signed(unaff_ER12,puVar9);
      stat_layout(&uStack_9e);
      bVar17 = bcd_type((byte *)&uStack_9e);
      if (bVar17 == 0) {
        uVar3 = dec_cmp((undefined2 *)&uStack_94,puVar9);
        if (((char)uVar3 == '\x01') ||
           (uVar3 = dec_cmp((undefined2 *)&uStack_9e,puVar9), (char)uVar3 == '\x01')) break;
        stat_layout2(&uStack_9e);
        puVar5 = &uStack_94;
        dec_bin_and_core(unaff_ER12,puVar5);
        uVar3 = dec_cmp(unaff_ER12,puVar5);
        if (((char)uVar3 == '\x01') || ((char)uVar3 == '\x04')) {
          dec_bin_result(unaff_ER12,puVar5);
          puVar9 = auStack_80;
          dec_bin_or_core(unaff_ER12,puVar9);
          uVar3 = dec_cmp(unaff_ER12,puVar9);
          if (((char)uVar3 == '\x01') || ((char)uVar3 == '\x04')) {
            puVar9 = auStack_76;
            uVar3 = dec_to_string(unaff_ER12,puVar9);
            if (((char)uVar3 == '\x01') || ((char)uVar3 == '\x02')) break;
          }
        }
      }
      else if (bVar17 != 3) {
        return 0;
      }
      puVar9 = auStack_6c;
      dec_bin_and_core(&uStack_3a,puVar9);
      cVar15 = cVar15 + -1;
    } while (cVar15 != '\0');
    dec_bin_result((ushort *)&uStack_3a,puVar9);
    bVar17 = ((undefined8 *)0xffe1 < puVar6) << 7;
    puVar10 = auStack_44;
    uVar3 = stat_cell_read(&uStack_3a);
    bVar17 = bVar17 & 0x9f;
    dec_bin_div_core(puVar10,uVar3);
    bVar17 = bVar17 & 0x9f;
    mat_cell_ctx(puVar6,in_stack_0000ff34);
    if ((char)bVar17 < '\0') {
      uVar4 = 0xfff6;
      while( true ) {
        uVar3 = kbd_wait_key();
        if ((char)uVar3 != '\0') {
          return 0;
        }
        uVar3 = stat_cell_read(&uStack_3a);
        dec_bin_and_core(uVar3,0x1b76);
        stat_cell_read(puVar6);
        cVar15 = CARRY2((ushort)puVar6,uVar4) << 7;
        mat_cell_ctx((undefined8 *)((short)puVar6 + uVar4),in_stack_0000ff32);
        if (-1 < cVar15) {
          return 0;
        }
        puVar10 = auStack_4e;
        stat_cell_read((undefined8 *)0x1b80);
        puVar10[9] = 6;
        uVar16 = uVar4;
        while( true ) {
          sVar14 = uVar16 + 10;
          dec_bin_mul_core((short)puVar6 + sVar14,(short)puVar6 + uVar16);
          dec_bin_and_core((short)puVar6 + sVar14,auStack_4e);
          cVar15 = dec_bin_div_core((short)puVar6 + sVar14,(short)puVar6 + uVar16);
          if (cVar15 != '\0') {
            return 0;
          }
          if ((char)sVar14 == '\0') break;
          dec_bin_pow_core(auStack_4e,0x1b8a);
          dec_bin_mul_core(auStack_4e,0x1b80);
          uVar16 = uVar16 + 10;
        }
        if ((char)local_62 == '\0') break;
        dec_bin_mul_core(auStack_58,puVar6);
        puVar5 = puVar6;
        dec_bin_and_core(auStack_58,puVar6);
        uVar3 = dec_bin_result(auStack_58,puVar5);
        if ((char)uVar3 == '\0') {
          uVar3 = dec_round_scaled(auStack_58,(undefined2 *)&uStack_30);
          if ((char)uVar3 != '\x04') goto LAB_rom_021d20;
          if ((*(char *)CONCAT11(bVar12 + (0xb9 < bVar7),bVar7 + 0x46) != -1) &&
             (puVar11 = (undefined2 *)CONCAT11(bVar12 + (0xb9 < bVar7),bVar7 + 0x46),
             *(char *)puVar11 != '\0')) {
            while (uVar3 = dec_round_scaled(auStack_58,puVar11), (char)uVar3 != '\x04') {
              sVar14 = CONCAT11(bVar12 + (0xaf < bVar7),bVar7 + 0x50);
              stat_cell_read(puVar6);
              puVar11 = (undefined2 *)(sVar14 + -10);
              if (*(char *)(sVar14 + -2) == -0x6f) {
                *(undefined *)puVar11 = 0;
                break;
              }
              *(char *)(sVar14 + -2) = *(char *)(sVar14 + -2) + -1;
            }
          }
          cVar15 = (char)((ushort)uStack_5a >> 8);
          if (((cVar15 == '\0') || (cVar15 == '\x05')) &&
             ((char)(((byte)uStack_5a < 0x90) << 7) < '\0')) goto LAB_rom_021d18;
        }
        uVar4 = uVar4 - 10;
        if (*(char *)CONCAT11(bVar12 + (0xb9 < bVar7),bVar7 + 0x46) == -1) {
          if ((char)uVar4 == '`') {
            return 0;
          }
        }
        else if ((char)uVar4 == -0x6e) {
          puVar5 = (undefined8 *)CONCAT11(bVar12 + (0xaf < bVar7),bVar7 + 0x50);
          if (*(char *)puVar5 == -1) {
            return 0;
          }
          stat_cell_read(puVar5);
          goto LAB_rom_021d20;
        }
      }
      if ((char)auStack_58[0] != '\0') {
LAB_rom_021d18:
        puVar6 = (undefined8 *)0x1b62;
      }
LAB_rom_021d20:
      stat_layout2(puVar6);
    }
  }
  return 0;
}

/**
 * @brief STAT 表格编辑（stat_table_clear/stat_cell_read）
 * @addr 0x21E9C
 * @module strlib
 * @proto int stat_table_edit(void)
 * @confidence likely
 * @note STAT 表格编辑（stat_table_clear/stat_cell_read）。
 * @tag stat
 */
int stat_table_edit(uintptr_t _a2, int _a1)

{
  char cVar1;
  int bVar2;
  undefined2 uVar3;
  undefined extraout_R1;
  undefined extraout_R1_00;
  byte *pbVar4;
  byte extraout_R1_01;
  byte extraout_R1_02;
  undefined2 uVar5;
  ushort uVar6;
  ushort uVar7;
  byte bVar8;
  ushort *puVar10;
  longlong lVar9;
  byte *pbStack_52;
  undefined2 uStack_50;
  undefined local_4e [60];
  undefined2 *puStack_12;
  
  lVar9 = (ulonglong)CONCAT22(*_a1,local_4e) << 0x20;
  uVar5 = 0xd39c;
  puStack_12 = _a1;
  uVar3 = dec_round_scaled(&stat_data,(undefined2 *)0xd39c);
  if ((((char)uVar3 != -0x10) && ((char)uVar3 != '\x04')) &&
     (uVar3 = dec_cmp((undefined2 *)0xd3a6,uVar5), (char)uVar3 == '\x04')) {
    stat_layout2((undefined8 *)0xd39c);
    dec_bin_mul_core((short)((ulonglong)lVar9 >> 0x20),&stat_data);
    uVar5 = 0xd3a6;
    dec_bin_and_core((short)((ulonglong)lVar9 >> 0x20),0xd3a6);
    uVar3 = dec_cmp_ex((undefined2 *)((ulonglong)lVar9 >> 0x20),uVar5);
    if ((char)uVar3 != '\x03') {
      dec_unary_cos((short)((ulonglong)lVar9 >> 0x20),uVar5);
      puVar10 = (ushort *)((ulonglong)lVar9 >> 0x20);
      uVar6 = *puVar10;
      uVar7 = uVar6 & 0xff0f;
      cVar1 = *(char *)(puVar10 + 4);
      bVar2 = (byte)uVar7;
      if (cVar1 != '\0') {
        if (cVar1 != '\x01') {
LAB_rom_021ffc:
          uVar6 = CONCAT11(extraout_R1,4);
          goto LAB_rom_021fec;
        }
        bVar8 = (byte)(uVar7 >> 8);
        if ((history_recall & 1) == 0) {
          if ((4 < bVar2) || ((3 < bVar2 && (0x4f < bVar8)))) goto LAB_rom_021ffc;
        }
        else if (2 < bVar2) goto LAB_rom_021ffc;
        bVar2 = ((byte)uVar6 & 0xf) * '\n' + (bVar8 >> 4);
      }
      lVar9 = CONCAT62((int6)((ulonglong)lVar9 >> 0x10),CONCAT11(1,bVar2 + 1));
      if ((history_recall == 0) || ((ratio_flags & 1) == 0)) {
        stat_table_clear(bVar2 + 1);
      }
      stat_cell_read((undefined8 *)&stat_data);
      uStack_50 = (undefined2)((ulonglong)lVar9 >> 0x30);
      do {
        pbStack_52 = (byte *)((ulonglong)lVar9 >> 0x30);
        bVar2 = matrix_entry(&pbStack_52,(ushort)((ulonglong)lVar9 >> 0x20));
        uVar6 = CONCAT11(extraout_R1_00,bVar2);
        if ((bVar2 == 0) || (0x1f < bVar2)) {
          pbVar4 = prev_char_ptr((byte *)0x0,pbStack_52);
        }
        else {
          if (bVar2 != 3) {
            lVar9 = ZEXT28(pbStack_52) << 0x30;
            goto LAB_rom_021fec;
          }
          dec_set_special((ushort *)((ulonglong)lVar9 >> 0x20),3);
          pbVar4 = pbStack_52;
        }
        if ((history_recall == 0) || ((ratio_flags & 1) == 0)) {
          list_entry_fetch(-0x2c96);
          list_entry_fetch((short)((ulonglong)lVar9 >> 0x20));
          bVar2 = extraout_R1_01;
        }
        else {
          list_entry_fetch((short)((ulonglong)lVar9 >> 0x20));
          bVar2 = extraout_R1_02;
        }
        cVar1 = (char)((ulonglong)lVar9 >> 8);
        if (cVar1 == (char)lVar9) {
          uVar6 = (ushort)bVar2 << 8;
          goto LAB_rom_021fec;
        }
        lVar9 = CONCAT62((int6)((ulonglong)lVar9 >> 0x10),CONCAT11(cVar1 + '\x01',(char)lVar9));
        uVar6 = kbd_wait_key();
        if ((char)uVar6 != '\0') {
          lVar9 = ZEXT28(pbVar4) << 0x30;
          goto LAB_rom_021fec;
        }
        uVar3 = 0xd3a6;
        dec_bin_div_core(0xd36a,0xd3a6);
        cVar1 = dec_cmp_ex((undefined2 *)0xd36a,uVar3);
      } while (cVar1 == '\0');
      uVar3 = dec_set_uint_small((ushort *)0xd36a,0);
      uVar6 = CONCAT11((char)((ushort)uVar3 >> 8),3);
      goto LAB_rom_021fec;
    }
  }
  uVar6 = CONCAT11((char)((ushort)uVar3 >> 8),3);
LAB_rom_021fec:
  *puStack_12 = (short)((ulonglong)lVar9 >> 0x30);
  return uVar6;
}

