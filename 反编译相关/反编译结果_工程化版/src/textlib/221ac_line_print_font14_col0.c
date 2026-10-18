/*
 * 行打印与文本 / 221ac_line_print_font14_col0.c
 * 地址范围: 0x221AC - 0x2292E
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 诊断页绘制一行（casio-main 原始符号 line_print_font14_col0…
 * @addr 0x221AC
 * @module textlib
 * @proto void line_print_font14_col0(char row, ushort str)
 * @confidence verified
 * @note 诊断页绘制一行（casio-main 原始符号
 *       line_print_font14_col0，r0:row,er2:char*）：0xD137=14 后以
 *       line_print(0,row,str) 输出——“Press AC”等诊断提示即由此打印。
 * @tag diag
 */
int line_print_font14_col0(char row, ushort str)

{
  cur_line = 0xe;
  line_print_col0_nop(CONCAT11(row,0xe),str);
  return 0;
}

/**
 * @brief 表格编辑主流程（3.4KB，0x23088/0x2BA30 调用）
 * @addr 0x2253E
 * @module textlib
 * @proto int table_edit_main(void)
 * @confidence likely
 * @note 表格编辑主流程（3.4KB，0x23088/0x2BA30 调用）。
 * @tag app
 */
int table_edit_main(void)

{
  byte bVar1;
  int bVar2;
  byte bVar3;
  undefined2 *puVar4;
  ushort uVar5;
  short sVar6;
  char cVar7;
  ushort uVar8;
  undefined uVar9;
  ushort uVar10;
  short unaff_ER14;
  
  bVar1 = frame_enter();
  puVar4 = (undefined2 *)key_pos_offset((ushort)*(byte *)(unaff_ER14 + 0x12) << 8);
  dec_copy((undefined2 *)(unaff_ER14 + -10),puVar4);
  puVar4 = (undefined2 *)key_pos_offset(0);
  bVar2 = dec_add_or_round((undefined2 *)(unaff_ER14 + -10),puVar4);
  if (bVar2 == 0) {
    dec_copy((undefined2 *)(unaff_ER14 + -0x32),(undefined2 *)(unaff_ER14 + -10));
    for (uVar10 = 1; (short)uVar10 < (short)(ushort)bVar1; uVar10 = uVar10 + 1) {
      uVar9 = (undefined)uVar10;
      puVar4 = (undefined2 *)key_pos_offset(CONCAT11(*(undefined *)(unaff_ER14 + 0x12),uVar9));
      dec_copy((undefined2 *)(unaff_ER14 + -0x3c),puVar4);
      for (uVar8 = 0; uVar5 = uVar10 - 1,
          (byte)(SBORROW2(uVar8,uVar5) ^ (short)(uVar8 - uVar5) < 0 | uVar8 == uVar5) == 1;
          uVar8 = uVar8 + 1) {
        *(short *)(unaff_ER14 + -0x48) = unaff_ER14 + -0x3c;
        puVar4 = (undefined2 *)key_pos_offset(CONCAT11((char)uVar8,uVar9));
        mul16(uVar8,10);
        dec_pow_then_div(puVar4);
      }
      puVar4 = (undefined2 *)key_pos_offset(CONCAT11(uVar9,uVar9));
      dec_copy((undefined2 *)(unaff_ER14 + -10),puVar4);
      bVar2 = dec_add_or_round((undefined2 *)(unaff_ER14 + -0x3c),(undefined2 *)(unaff_ER14 + -10));
      if (bVar2 != 0) goto LAB_rom_022580;
      sVar6 = mul16(uVar10,10);
      dec_copy((undefined2 *)(sVar6 + unaff_ER14 + -0x32),(undefined2 *)(unaff_ER14 + -0x3c));
    }
    sVar6 = mul16(bVar1 - 1,10);
    puVar4 = (undefined2 *)(sVar6 + unaff_ER14 + -0x32);
    dec_copy((undefined2 *)(unaff_ER14 + -10),puVar4);
    bVar2 = dec_cmp_ex((undefined2 *)(unaff_ER14 + -10),puVar4);
    if (bVar2 == 0) {
      puVar4 = (undefined2 *)key_pos_offset(CONCAT11(*(undefined *)(unaff_ER14 + 0x12),bVar1 - 1));
      dec_copy(puVar4,(undefined2 *)(unaff_ER14 + -10));
      for (uVar10 = bVar1 - 2; -1 < (short)uVar10; uVar10 = uVar10 - 1) {
        sVar6 = mul16(uVar10,10);
        puVar4 = (undefined2 *)(sVar6 + unaff_ER14 + -0x32);
        bVar3 = (byte)unaff_ER14;
        cVar7 = (char)((ushort)unaff_ER14 >> 8);
        dec_copy((undefined2 *)CONCAT11(cVar7 + -1 + (0x45 < bVar3),bVar3 + 0xba),puVar4);
        uVar8 = uVar10;
        while( true ) {
          uVar8 = uVar8 + 1;
          if ((byte)(SBORROW2(uVar8,(ushort)bVar1) ^ (short)(uVar8 - bVar1) < 0) != 1) break;
          *(ushort *)(unaff_ER14 + -0x4a) = CONCAT11(cVar7 + -1 + (0x45 < bVar3),bVar3 + 0xba);
          puVar4 = (undefined2 *)key_pos_offset(CONCAT11((char)uVar8,(char)uVar10));
          key_pos_offset(CONCAT11(*(undefined *)(unaff_ER14 + 0x12),(char)uVar8));
          dec_pow_then_div(puVar4);
        }
        bVar2 = dec_cmp_ex((undefined2 *)CONCAT11(cVar7 + -1 + (0x45 < bVar3),bVar3 + 0xba), (uintptr_t)0)
                               puVar4);
        if (bVar2 != 0) goto LAB_rom_022580;
        puVar4 = (undefined2 *)
                 key_pos_offset(CONCAT11(*(undefined *)(unaff_ER14 + 0x12),(char)uVar10));
        dec_copy(puVar4,(undefined2 *)CONCAT11(cVar7 + -1 + (0x45 < bVar3),bVar3 + 0xba));
      }
      goto LAB_rom_022588;
    }
  }
LAB_rom_022580:
  dec_round_to(*(ushort **)(unaff_ER14 + 0x10),bVar2);
LAB_rom_022588:
  frame_leave();
  return 0;
}

/**
 * @brief 表格/统计按键路由（2.9KB，0x247BE 调用
 * @addr 0x2292E
 * @module textlib
 * @proto void table_key_router(undefined2 k)
 * @confidence strong
 * @note 表格/统计按键路由（2.9KB，0x247BE 调用；含 0x22980 跳表）。
 * @tag app
 */
int table_key_router(undefined2 k)

{
  undefined uVar1;
  undefined2 uVar2;
  ushort uVar3;
  char cVar4;
  byte bVar5;
  short unaff_ER14;
  
  uVar2 = frame_enter();
  uVar1 = disp_mode;
  disp_mode = *(undefined *)(unaff_ER14 + 0x10);
  cVar4 = (char)k;
  bVar5 = (byte)((ushort)k >> 8);
  if (cVar4 == '\0') {
    if (((-(ushort)(bVar5 < 0x20) & 0x100) != 0 ||
         bVar5 == 0x20 && (char)-(ushort)(bVar5 < 0x20) == '\0') &&
       ((-(ushort)(bVar5 < 3) & 0x100) == 0)) {
      uVar3 = bVar5 - 3;
                    // WARNING: Jumptable at 0x022980 did not pass sanity check.
                    // WARNING: Treating indirect jump as call
      ((void)0);
      return 0;
    }
  }
  else if (cVar4 == '\x01') {
    if (((-(ushort)(bVar5 < 0x20) & 0x100) != 0 ||
         bVar5 == 0x20 && (char)-(ushort)(bVar5 < 0x20) == '\0') &&
       ((-(ushort)(bVar5 < 7) & 0x100) == 0)) {
      uVar3 = bVar5 - 7;
                    // WARNING: Could not recover jumptable at 0x02299e. Too many branches
                    // WARNING: Treating indirect jump as call
      ((void)0);
      return 0;
    }
  }
  else if (cVar4 == '\x02') {
    if (((-(ushort)(bVar5 < 0x20) & 0x100) != 0 ||
         bVar5 == 0x20 && (char)-(ushort)(bVar5 < 0x20) == '\0') &&
       ((-(ushort)(bVar5 < 0xb) & 0x100) == 0)) {
      uVar3 = bVar5 - 0xb;
                    // WARNING: Could not recover jumptable at 0x0229bc. Too many branches
                    // WARNING: Treating indirect jump as call
      ((void)0);
      return 0;
    }
  }
  else if (cVar4 == '\x03') {
    if (((-(ushort)(bVar5 < 0x20) & 0x100) != 0 ||
         bVar5 == 0x20 && (char)-(ushort)(bVar5 < 0x20) == '\0') &&
       ((-(ushort)(bVar5 < 0x11) & 0x100) == 0)) {
      uVar3 = bVar5 - 0x11;
                    // WARNING: Could not recover jumptable at 0x0229da. Too many branches
                    // WARNING: Treating indirect jump as call
      ((void)0);
      return 0;
    }
  }
  else if (bVar5 == 0x1e) {
    key_jump_1e(uVar2,*(char *)(unaff_ER14 + 0x10));
  }
  else if (bVar5 == 0x20) {
    key_jump_20(uVar2,*(char *)(unaff_ER14 + 0x10));
  }
  disp_mode = uVar1;
  frame_leave();
  return 0;
}

