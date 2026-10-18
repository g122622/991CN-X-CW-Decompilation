/*
 * 输入编辑器 / 0a326_edit_loop_main.c
 * 地址范围: 0x0A326 - 0x0A326
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 编辑主循环（3.5KB，0x295D6 调用）
 * @addr 0x0A326
 * @module editor
 * @proto void edit_loop_main(short arg)
 * @confidence strong
 * @note 编辑主循环（3.5KB，0x295D6 调用）：读键并分派 0x23A0C/0x24EF2/0x28576 等。
 * @tag editor
 */
int edit_loop_main(short _a1)

{
  short sVar1;
  ushort uVar2;
  short sVar3;
  byte bVar4;
  bool bVar5;
  char cVar6;
  byte bVar7;
  byte bVar10;
  undefined2 uVar8;
  char *pcVar9;
  byte bVar11;
  byte bVar12;
  short unaff_ER14;
  
  bVar11 = 0;
  bVar12 = 0;
  frame_enter();
  *(undefined *)(unaff_ER14 + -0x4e) = 0;
  bVar4 = line_col_count();
  draw_spaced(CONCAT11(-(0xc0 < history_key),-0x40 - history_key),(ushort)bVar4);
  bVar4 = history_cursor;
  *(ushort *)(unaff_ER14 + -0x40) = CONCAT11((0x7f < history_cursor) + -0x2f,history_cursor + 0x80);
  bVar5 = disp_busy();
  *(byte *)(uintptr_t)(bool *)(unaff_ER14 + -0x49) = bVar5;
  cVar6 = is_math_io();
  uVar8 = _DAT_ram_d15e;
  if (cVar6 != '\0') {
    if (bVar11 == 0x3e && (bool)(bVar12 + 4) == bVar11 < 0x3e) {
      *(undefined2 *)(unaff_ER14 + -0x2e) = _DAT_ram_d15e;
      *(undefined2 *)(unaff_ER14 + -0x2c) = 0;
      bVar7 = (byte)uVar8;
      bVar10 = (byte)((ushort)uVar8 >> 8);
      if ((bVar7 != 0 || bVar10 != 0) &&
         (((((sVar1 = (ushort)bVar10 - (ushort)(bVar7 < 0xd5),
             sVar3 = -(ushort)((byte)((ushort)sVar1 >> 8) & 1),
             ((bVar7 == 0xd5 && (char)sVar1 == '\0') && (char)sVar3 == '\0') &&
             -1 < (char)((char)((ushort)sVar3 >> 8) << 7) ||
             (sVar1 = (ushort)bVar10 - (ushort)(bVar7 < 0xd6),
             sVar3 = -(ushort)((byte)((ushort)sVar1 >> 8) & 1),
             ((bVar7 == 0xd6 && (char)sVar1 == '\0') && (char)sVar3 == '\0') &&
             -1 < (char)((char)((ushort)sVar3 >> 8) << 7))) ||
            (sVar1 = (ushort)bVar10 - (ushort)(bVar7 < 0xd4),
            sVar3 = -(ushort)((byte)((ushort)sVar1 >> 8) & 1),
            ((bVar7 == 0xd4 && (char)sVar1 == '\0') && (char)sVar3 == '\0') &&
            -1 < (char)((char)((ushort)sVar3 >> 8) << 7))) ||
           ((sVar1 = (ushort)bVar10 - (ushort)(bVar7 < 0x76),
            sVar3 = -(ushort)((byte)((ushort)sVar1 >> 8) & 1),
            ((bVar7 == 0x76 && (char)sVar1 == '\0') && (char)sVar3 == '\0') &&
            -1 < (char)((char)((ushort)sVar3 >> 8) << 7) ||
            (sVar1 = (ushort)bVar10 - (ushort)(bVar7 < 0x18),
            sVar3 = -(ushort)((byte)((ushort)sVar1 >> 8) & 1),
            ((bVar7 == 0x18 && (char)sVar1 == '\0') && (char)sVar3 == '\0') &&
            -1 < (char)((char)((ushort)sVar3 >> 8) << 7))))) ||
          (uVar8 = key_is_cmp(*(char **)(unaff_ER14 + -0x40)), (char)uVar8 != '\0')))) {
        bVar11 = 0x3f;
        bVar12 = 0xfc;
        input_active = 0;
      }
    }
    _DAT_ram_d15e = 0;
    if (bVar11 != 0x3f || (bool)(bVar12 + 4) != bVar11 < 0x3f) {
      pcVar9 = (char *)input_history_ptr();
      strcpy_checked(pcVar9,&input_buf);
      input_saved = bVar4;
    }
  }
  dec_accum3 = 0;
  dec_accum4 = 0;
  dec_accum6 = 0;
  uVar2 = (bVar12 - 0xfc) - (ushort)(bVar11 < 0x3f);
  if (((uVar2 & 0x100) != 0 || bVar11 == 0x3f && (char)uVar2 == '\0') &&
     (((bVar12 - 0xfc) - (ushort)(bVar11 < 0x1c) & 0x100) == 0)) {
                    // WARNING: Could not recover jumptable at 0x00a422. Too many branches
                    // WARNING: Treating indirect jump as call
    ((void)0);
    return 0;
  }
  frame_leave();
  return 0;
}

