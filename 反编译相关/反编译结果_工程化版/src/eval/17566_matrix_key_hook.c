/*
 * 表达式求值 / 17566_matrix_key_hook.c
 * 地址范围: 0x17566 - 0x17CFE
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 0xD114 bit5 的矩阵按键回调（0x1767C/0x17680/0x177A4 共用…
 * @addr 0x17566
 * @module eval
 * @proto void matrix_key_hook(undefined2 k)
 * @confidence likely
 * @note 0xD114 bit5 的矩阵按键回调（0x1767C/0x17680/0x177A4 共用）。
 * @tag key
 */
int matrix_key_hook(undefined2 k, int _a2)

{
  bool bVar1;
  char cVar2;
  byte bVar3;
  ushort uVar4;
  undefined in_R3;
  undefined2 uVar5;
  byte unaff_R7;
  undefined *unaff_ER12;
  byte bVar6;
  undefined3 unaff_retaddr;
  undefined4 in_stack_0000fffc;
  undefined4 uVar7;
  
  uVar5 = CONCAT11(in_R3,_a2);
  uVar7 = CONCAT13((char)((uint)in_stack_0000fffc >> 0x18),unaff_retaddr);
  if (((((edit_state2 & 0x20) != 0) && (unaff_R7 == 0)) && (cVar2 = (char)k, cVar2 != 'A'))
     && (cVar2 != 'J')) {
    uVar4 = eval_token_scan();
    if (((char)(uVar4 >> 8) == '\0') && ((char)uVar4 == -0x5b)) {
      if (stat_var_num != '\0') {
        return 0;
      }
      stat_var_num = cVar2;
      return 0;
    }
    k = dec_set_zero(k);
  }
  bVar6 = (unaff_R7 == 3) << 6;
  if ((2 < unaff_R7) &&
     (k = key_af_dispatch(k,uVar5,(undefined2 *)uVar7,(undefined2 *)((uint)uVar7 >> 0x10)
                              ), (bVar6 >> 6 & 1) != 1)) {
    return 0;
  }
  bVar3 = (char)(uintptr_t)k - 0x40;
  bVar1 = (char)uVar5 == '\x10';
  bVar6 = bVar1 << 6;
  if (bVar1) {
    base_clear(CONCAT11((char)((ushort)k >> 8),bVar3),unaff_ER12);
  }
  else {
    copy_with_dims(bVar3,unaff_ER12);
    if ((bVar6 >> 6 & 1) != 1) {
      return 0;
    }
  }
  return 0;
}

/**
 * @brief 矩阵编辑按键（R7>=3）
 * @addr 0x1767C
 * @module eval
 * @proto undefined2 matrix_edit_key(undefined2 k)
 * @confidence likely
 * @note 矩阵编辑按键（R7>=3）：经 0x16820 解析后操作矩阵行/列。
 * @tag matrix
 */
undefined2 matrix_edit_key(undefined2 k, int _a2)

{
  byte bVar1;
  ushort uVar2;
  byte extraout_R1;
  undefined extraout_R1_00;
  undefined8 *puVar3;
  undefined uVar5;
  undefined2 uVar4;
  ushort *puVar6;
  char unaff_R6;
  byte unaff_R7;
  byte unaff_R11;
  short unaff_ER12;
  char cVar7;
  byte bVar8;
  
  if (unaff_R7 < 3) {
    return k;
  }
  bVar1 = (byte)k;
  uVar2 = eval_token_scan();
  if ((char)_a2 == '\n') {
    dec_set_zero(uVar2);
    uVar2 = matrix_walk(_a2);
    if ((char)_a2 == '\0') {
      if (unaff_R6 == '\0') {
        cVar7 = '\0';
        matrix_prec_limit(3);
        uVar2 = (ushort)extraout_R1 << 8;
        if (-1 < cVar7) {
          store_mat_word(0xff);
          cVar7 = '\0';
          uVar5 = extraout_R1_00;
          if (0x19 < bVar1) {
            puVar6 = (ushort *)((ushort)unaff_R11 * 10 + -0x2f70);
            bVar8 = 0x40;
            uVar2 = copy_with_dims(0,(undefined *)puVar6);
            if ((bVar8 >> 6 & 1) == 0) goto LAB_rom_01769c;
            puVar3 = (undefined8 *)matrix_eval_tree((ushort)(byte)(bVar1 + 0x8c),puVar6);
            if ((char)puVar6 != '\0') {
              return puVar3;
            }
            uVar5 = 0;
            bVar1 = 0x10;
            cVar7 = '\x01';
          }
          uVar4 = advance_token_ptr(CONCAT11(uVar5,bVar1 + 0x30));
          puVar3 = (undefined8 *)matrix_key_hook(uVar4,'\x10');
          if (cVar7 != '\0') {
            puVar3 = stat_layout2((undefined8 *)(unaff_ER12 + 0x14));
          }
          return puVar3;
        }
      }
      else {
        uVar2 = dec_set_zero(uVar2);
      }
    }
  }
LAB_rom_01769c:
  return (undefined8 *)CONCAT11((char)(uVar2 >> 8),bVar1);
}

/**
 * @brief 矩阵编辑按键变体（0xD114 bit7 时直接返回）
 * @addr 0x17680
 * @module eval
 * @proto undefined2 matrix_edit_key_b(undefined2 k)
 * @confidence likely
 * @note 矩阵编辑按键变体（0xD114 bit7 时直接返回）。
 * @tag matrix
 */
undefined2 matrix_edit_key_b(undefined2 k, int _a2)

{
  byte bVar1;
  ushort uVar2;
  byte extraout_R1;
  undefined extraout_R1_00;
  undefined8 *puVar3;
  undefined uVar5;
  undefined2 uVar4;
  ushort *puVar6;
  char unaff_R6;
  byte unaff_R7;
  byte unaff_R11;
  short unaff_ER12;
  char cVar7;
  byte bVar8;
  
  if (((edit_state2 & 0x80) != 0) || (unaff_R7 < 3)) {
    return k;
  }
  bVar1 = (byte)k;
  uVar2 = eval_token_scan();
  if ((char)_a2 == '\n') {
    dec_set_zero(uVar2);
    uVar2 = matrix_walk(_a2);
    if ((char)_a2 == '\0') {
      if (unaff_R6 == '\0') {
        cVar7 = '\0';
        matrix_prec_limit(3);
        uVar2 = (ushort)extraout_R1 << 8;
        if (-1 < cVar7) {
          store_mat_word(0xff);
          cVar7 = '\0';
          uVar5 = extraout_R1_00;
          if (0x19 < bVar1) {
            puVar6 = (ushort *)((ushort)unaff_R11 * 10 + -0x2f70);
            bVar8 = 0x40;
            uVar2 = copy_with_dims(0,(undefined *)puVar6);
            if ((bVar8 >> 6 & 1) == 0) goto LAB_rom_01769c;
            puVar3 = (undefined8 *)matrix_eval_tree((ushort)(byte)(bVar1 + 0x8c),puVar6);
            if ((char)puVar6 != '\0') {
              return puVar3;
            }
            uVar5 = 0;
            bVar1 = 0x10;
            cVar7 = '\x01';
          }
          uVar4 = advance_token_ptr(CONCAT11(uVar5,bVar1 + 0x30));
          puVar3 = (undefined8 *)matrix_key_hook(uVar4,'\x10');
          if (cVar7 != '\0') {
            puVar3 = stat_layout2((undefined8 *)(unaff_ER12 + 0x14));
          }
          return puVar3;
        }
      }
      else {
        uVar2 = dec_set_zero(uVar2);
      }
    }
  }
LAB_rom_01769c:
  return (undefined8 *)CONCAT11((char)(uVar2 >> 8),bVar1);
}

/**
 * @brief 矩阵模式按键
 * @addr 0x177A4
 * @module eval
 * @proto void matrix_key_walk(undefined2 k)
 * @confidence likely
 * @note 矩阵模式按键：0x16B80 遍历表达式后转 0x17566（R7>=3 时生效）。
 * @tag matrix
 */
int matrix_key_walk(undefined2 k)

{
  undefined2 uVar1;
  char unaff_R6;
  byte unaff_R7;
  
  if (unaff_R7 < 3) {
    return 0;
  }
  uVar1 = matrix_walk(k);
  if ((char)k == '\0') {
    if (((edit_state2 & 0x20) != 0) &&
       (uVar1 = CONCAT11((char)((ushort)uVar1 >> 8),stat_var_num), stat_var_num != '\0')) {
      matrix_key_hook(uVar1,'\x10');
      return 0;
    }
    if (unaff_R6 != '\0') {
      dec_set_zero(uVar1);
    }
  }
  return 0;
}

/**
 * @brief 把输出缓冲中的数字串解析成 BCD 数值（0x15ECE 读出字符 → 0x177DA 解析…
 * @addr 0x177D0
 * @module eval
 * @proto int str_parse_number(void)
 * @confidence likely
 * @note 把输出缓冲中的数字串解析成 BCD 数值（0x15ECE 读出字符 → 0x177DA 解析）。
 * @tag eval
 */
int str_parse_number(uintptr_t _a3, uintptr_t _a4, int _a1, int _a2)

{
  char cVar1;
  ushort uVar2;
  byte bVar3;
  ushort uVar4;
  char cVar5;
  char unaff_R6;
  byte *pbVar6;
  undefined8 in_QR8;
  
  _DAT_ram_d13c = _DAT_ram_d13c | 1;
  do {
    uVar2 = eval_token_scan();
    if (10 < (byte)_a1) {
      _a1 = 2;
      goto LAB_rom_017824;
    }
    bVar3 = (byte)_a1 * '\x02';
    _a1 = CONCAT11((char)((uint32_t)_a1 >> 8),bVar3);
    uVar4 = *(ushort *)CONCAT11((0xb9 < bVar3) + '.',bVar3 + 0x46);
    uVar2 = ((void)0);
  } while ((char)_a1 == '\0');
  if ((char)_a1 < '\0') {
    pbVar6 = (byte *)((ulonglong)in_QR8 >> 0x20);
    bVar3 = *pbVar6;
    if ((0x8f < bVar3) || ((bVar3 < 0x80 && (0x5f < bVar3)))) {
      uVar2 = CONCAT11((char)(uVar2 >> 8),edit_state2);
      if (edit_state2 == 1) {
        uVar2 = apps_tbl_read(pbVar6,_a1);
        _a1 = _a1 & 0xff;
        if ((char)uVar2 == '\0') goto LAB_rom_01786c;
        _a1 = 3;
      }
      else {
        _a1 = 2;
      }
      goto LAB_rom_017824;
    }
LAB_rom_01786c:
    bVar3 = (byte)_a1;
    if (unaff_R6 != '\0') goto LAB_rom_0178be;
    stat_layout((undefined8 *)in_QR8);
    if (bVar3 == 0xff) {
      in_QR8 = CONCAT53((int5)((ulonglong)in_QR8 >> 0x18),(uint3)(ushort)in_QR8);
      stat_entry_ptr();
      bVar3 = 0x25;
      cVar5 = (char)(uVar4 >> 8);
      cVar1 = (char)uVar4;
      if ((cVar5 == '\0') &&
         (((cVar1 == -0x56 || (bVar3 = 0x22, cVar1 == -0x7f)) || (bVar3 = 0x23, cVar1 == -0x7e)))) {
LAB_rom_0178dc:
        dec_copy_ret((undefined2 *)((short)((ulonglong)in_QR8 >> 0x20) + 0x14), (uintptr_t)0)
                       (undefined2 *)((short)in_QR8 + 10));
        goto LAB_rom_0178b4;
      }
      bVar3 = 0;
      if ((edit_state2 & 0x40) != 0) {
        if ((cVar5 != '\0') || (cVar1 != -0x5b)) {
          copy_opnd((undefined8 *)0x1b62);
          bVar3 = 0;
        }
        goto LAB_rom_0178dc;
      }
      goto LAB_rom_0178b0;
    }
    if (bVar3 == 0xfc) {
      bVar3 = 0x26;
      goto LAB_rom_0178dc;
    }
    bVar3 = (bVar3 ^ 0xff) + 0x21;
  }
  else {
LAB_rom_017824:
    bVar3 = (byte)_a1;
    if ((unaff_R6 == '\0') &&
       ((cVar1 = *(char *)((short)((ulonglong)in_QR8 >> 0x30) + -1), cVar1 == '\0' || (bVar3 != 1)))
       ) {
      dec_set_zero(CONCAT11((char)(uVar2 >> 8),cVar1));
    }
    dec_set_special((ushort *)in_QR8,bVar3);
LAB_rom_0178b0:
    if (unaff_R6 != '\0') goto LAB_rom_0178be;
  }
LAB_rom_0178b4:
  *_a2 = (short)((ulonglong)in_QR8 >> 0x30);
LAB_rom_0178be:
  _DAT_ram_d13c = _DAT_ram_d13c & 0xfe;
  return bVar3;
}

/**
 * @brief 矩阵输入入口
 * @addr 0x177DA
 * @module eval
 * @proto int matrix_entry(byte* src, undefined2 flags)
 * @confidence likely
 * @note 矩阵输入入口：按 0xD111==6 设置 0xD13D，解析输入并生成矩阵单元。
 * @tag matrix
 */
int matrix_entry(byte* src, undefined2 flags)

{
  char cVar1;
  ushort uVar2;
  byte bVar3;
  ushort uVar4;
  char cVar5;
  byte *pbVar7;
  undefined8 uVar6;
  undefined local_62 [80];
  undefined2 *puStack_12;
  
  stat_var_num = 0;
  if (calc_mode == '\x06') {
    stat_var_num = 0x18;
  }
  uVar6 = CONCAT53((int5)(((ulonglong)CONCAT22(*src,local_62) << 0x20) >> 0x18),(uint3)flags);
  puStack_12 = src;
  store_mat_word(CONCAT11((char)((ushort)src >> 8),0xff));
  uVar6 = CONCAT44((int)((ulonglong)uVar6 >> 0x20),(uint)(ushort)uVar6);
  do {
    uVar2 = eval_token_scan();
    if (10 < (byte)flags) {
      flags = 2;
      goto LAB_rom_017824;
    }
    bVar3 = (byte)flags * '\x02';
    flags = CONCAT11((char)(flags >> 8),bVar3);
    uVar4 = *(ushort *)CONCAT11((0xb9 < bVar3) + '.',bVar3 + 0x46);
    uVar2 = ((void)0);
  } while ((char)flags == '\0');
  if ((char)flags < '\0') {
    pbVar7 = (byte *)((ulonglong)uVar6 >> 0x20);
    bVar3 = *pbVar7;
    if ((bVar3 < 0x90) && ((0x7f < bVar3 || (bVar3 < 0x60)))) {
LAB_rom_01786c:
      bVar3 = (byte)flags;
      stat_layout((undefined8 *)uVar6);
      if (bVar3 == 0xff) {
        uVar6 = CONCAT53((int5)((ulonglong)uVar6 >> 0x18),(uint3)(ushort)uVar6);
        stat_entry_ptr();
        bVar3 = 0x25;
        cVar5 = (char)(uVar4 >> 8);
        cVar1 = (char)uVar4;
        if ((cVar5 != '\0') ||
           (((cVar1 != -0x56 && (bVar3 = 0x22, cVar1 != -0x7f)) && (bVar3 = 0x23, cVar1 != -0x7e))))
        {
          bVar3 = 0;
          if ((edit_state2 & 0x40) == 0) goto LAB_rom_0178b4;
          if ((cVar5 != '\0') || (cVar1 != -0x5b)) {
            copy_opnd((undefined8 *)0x1b62);
            bVar3 = 0;
          }
        }
      }
      else {
        if (bVar3 != 0xfc) {
          bVar3 = (bVar3 ^ 0xff) + 0x21;
          goto LAB_rom_0178b4;
        }
        bVar3 = 0x26;
      }
      dec_copy_ret((undefined2 *)((short)((ulonglong)uVar6 >> 0x20) + 0x14), (uintptr_t)0)
                     (undefined2 *)((short)uVar6 + 10));
      goto LAB_rom_0178b4;
    }
    uVar2 = CONCAT11((char)(uVar2 >> 8),edit_state2);
    if (edit_state2 == 1) {
      uVar2 = apps_tbl_read(pbVar7,flags);
      flags = flags & 0xff;
      if ((char)uVar2 == '\0') goto LAB_rom_01786c;
      flags = 3;
    }
    else {
      flags = 2;
    }
  }
LAB_rom_017824:
  bVar3 = (byte)flags;
  cVar1 = *(char *)((short)((ulonglong)uVar6 >> 0x30) + -1);
  if ((cVar1 == '\0') || (bVar3 != 1)) {
    dec_set_zero(CONCAT11((char)(uVar2 >> 8),cVar1));
  }
  dec_set_special((ushort *)uVar6,bVar3);
LAB_rom_0178b4:
  *puStack_12 = (short)((ulonglong)uVar6 >> 0x30);
  _DAT_ram_d13c = _DAT_ram_d13c & 0xfe;
  return bVar3;
}

/**
 * @brief 统计表计算（2.8KB）
 * @addr 0x178EE
 * @module eval
 * @proto int stat_table_calc(void)
 * @confidence likely
 * @note 统计表计算（2.8KB）：从 0xD5EC 读取行数据按 0xD114 状态计算统计量。
 * @tag app
 */
int stat_table_calc(uintptr_t _a2, int _a1)

{
  ushort uVar1;
  byte bVar3;
  short sVar2;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  uint uVar7;
  byte bVar11;
  uint6 uVar8;
  undefined2 *puVar15;
  char *pcVar16;
  undefined6 uVar13;
  ulonglong uVar9;
  ulonglong uVar10;
  byte bVar12;
  char cVar14;
  
  uVar8 = CONCAT15(0xd5,CONCAT14(0xec,(uint)edit_state2));
  puVar15 = (undefined2 *)(uVar8 >> 0x20);
  *puVar15 = 0xffff;
  puVar15[1] = 0xffff;
  puVar15[2] = 0xffff;
  puVar15[3] = 0xffff;
  puVar15[4] = 0xffff;
  bVar5 = 0;
  uVar9 = (ulonglong)uVar8;
  bVar11 = 0xff;
LAB_rom_017912:
  while( true ) {
    while( true ) {
      bVar4 = bVar11;
      uVar10 = uVar9;
      uVar1 = eval_token_scan();
      bVar6 = (byte)uVar10;
      bVar12 = (byte)uVar1;
      uVar13 = (undefined6)(uVar10 >> 0x10);
      bVar11 = bVar4;
      if (_a1 == '\x05') break;
      uVar9 = CONCAT62(uVar13,CONCAT11(1,bVar6));
      if (_a1 == '\n') {
        bVar3 = (byte)(uVar1 >> 8);
        if ((bVar3 != 0) || (bVar12 != 0x23)) {
          if (((uVar10 & 0x40) == 0) || (*(char *)(uVar10 >> 0x20) != -1)) {
            sVar2 = (ushort)bVar3 << 8;
          }
          else {
            sVar2 = CONCAT11(bVar3,0xc);
          }
          return sVar2;
        }
        uVar9 = CONCAT62(uVar13,(ushort)bVar6);
        if (bVar4 != 0xff) {
          if (bVar4 != 0) {
            bVar4 = bVar4 - 1;
          }
          bVar11 = '\x01' << (bVar4 & 7);
          bVar5 = bVar5 | bVar11;
          uVar9 = CONCAT53((int5)(uVar10 >> 0x18),CONCAT12(bVar11,(ushort)bVar6));
          bVar11 = 0xff;
        }
      }
    }
    if ((bVar12 != 0x4a) && (bVar12 != 0x41)) break;
    uVar9 = CONCAT62(uVar13,CONCAT11(1,bVar6));
  }
  if ((uVar10 & 0x40) == 0) {
    uVar9 = uVar10 | 0x100;
    if ((uVar10 & 0x100) == 0) goto code_s0x017960;
    goto LAB_rom_01797a;
  }
  goto LAB_rom_017988;
code_s0x017960:
  uVar1 = eval_token_scan();
  if ((_a1 != '\x02') || (bVar11 = bVar12, (char)uVar1 != -0x5b)) {
    uVar1 = dec_set_zero(CONCAT11((char)uVar1,bVar12));
LAB_rom_01797a:
    bVar12 = (byte)uVar1;
    bVar11 = bVar12;
    if (bVar12 != 0) {
      bVar11 = bVar12 - 1;
    }
    uVar1 = CONCAT11(bVar11,bVar12);
    bVar12 = '\x01' << (bVar11 & 7) & bVar5;
    uVar10 = CONCAT53((int5)(uVar9 >> 0x18),CONCAT12(bVar12,(short)uVar9));
    uVar9 = uVar10;
    bVar11 = bVar4;
    if (bVar12 == 0) {
LAB_rom_017988:
      uVar9 = uVar10 >> 0x20;
      do {
        pcVar16 = (char *)(uVar10 >> 0x20);
        cVar14 = *pcVar16;
        uVar7 = CONCAT13(cVar14,(int3)uVar10);
        uVar10 = (ulonglong)uVar7;
        if (cVar14 == (char)uVar1) goto LAB_rom_017998;
        uVar10 = (ulonglong)CONCAT24(pcVar16 + 1,uVar7);
      } while (cVar14 != -1);
      *pcVar16 = (char)uVar1;
LAB_rom_017998:
      uVar9 = (ulonglong)CONCAT24((short)uVar9,(int)uVar10);
      bVar11 = bVar4;
    }
  }
  goto LAB_rom_017912;
}

/**
 * @brief 调用 0xAF62 跳过当前 token（<0xF0 为 1 字节，否则 2 字节），返回 …
 * @addr 0x179C2
 * @module eval
 * @proto undefined2 advance_token_ptr(undefined2 v)
 * @confidence verified
 * @note 调用 0xAF62 跳过当前 token（<0xF0 为 1 字节，否则 2 字节），返回 v。
 * @tag parser
 */
undefined2 advance_token_ptr(undefined2 v)

{
  byte *unaff_ER14;
  
  char_ptr_next(unaff_ER14);
  return v;
}

/**
 * @brief 复制源指针处的 10 字节到目标指针（与 0x1DA02 等价，偏移 1 的变体）
 * @addr 0x17B40
 * @module eval
 * @proto void copy10(void)
 * @confidence verified
 * @note 复制源指针处的 10 字节到目标指针（与 0x1DA02 等价，偏移 1 的变体）。
 * @tag util
 */
int copy10(void)

{
  undefined2 uVar1;
  undefined8 *unaff_ER12;
  undefined8 *unaff_ER14;
  
  uVar1 = *(undefined2 *)(unaff_ER14 + 1);
  *unaff_ER12 = *unaff_ER14;
  *(undefined2 *)(unaff_ER12 + 1) = uVar1;
  return 0;
}

/**
 * @brief 空函数（直接返回）
 * @addr 0x17CEC
 * @module eval
 * @proto void nop_17cec(void)
 * @confidence verified
 * @note 空函数（直接返回）。
 * @tag util
 */
int nop_17cec(void)

{
  return 0;
}

/**
 * @brief 空函数（直接返回，Ghidra 标注了全局重叠）
 * @addr 0x17CFE
 * @module eval
 * @proto void nop_17cfe(void)
 * @confidence verified
 * @note 空函数（直接返回，Ghidra 标注了全局重叠）。
 * @tag util
 */
int nop_17cfe(void)

{
  return 0;
}

