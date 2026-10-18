/*
 * 应用模式 / 13368_apps_matrix_main.c
 * 地址范围: 0x13368 - 0x13368
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 矩阵模式（0xD112 == 5）主例程
 * @addr 0x13368
 * @module apps
 * @proto undefined2 apps_matrix_main(undefined2 arg)
 * @confidence strong
 * @note 矩阵模式（0xD112 == 5）主例程：矩阵行列数检查与运算调用，再转 0x14C5E。
 * @tag mode
 */
undefined2 apps_matrix_main(undefined2 arg, int _a2)

{
  byte bVar1;
  byte bVar2;
  undefined uVar3;
  int cVar4;
  ushort uVar5;
  byte extraout_R1;
  undefined2 *puVar6;
  byte bVar7;
  byte extraout_R1_00;
  uint3 uVar8;
  uint uVar9;
  uint uVar10;
  short sVar13;
  undefined6 uVar11;
  ulonglong uVar12;
  
  uVar5 = apps_mode_main(arg);
  if ((char)uVar5 != '\0') {
    return uVar5;
  }
  bVar2 = (byte)(uVar5 >> 8);
  uVar10 = (uint)bVar2;
  uVar9 = (uint)bVar2;
  if (sub_mode == 5) {
    if (bVar2 == 2) {
      dec_cmp_path1();
      uVar12 = (ulonglong)CONCAT14(ratio_unit,uVar9);
      bVar2 = 0x40;
      apps_mat_check(_a2);
      if ((bVar2 >> 6 & 1) != 0) {
        sVar13 = (short)(uVar12 >> 0x20) + 4;
        uVar12 = (ulonglong)CONCAT24(sVar13,(int)uVar12);
        bVar2 = (sVar13 == 0) << 6;
      }
      apps_mat_size(_a2);
      if ((bVar2 >> 6 & 1) != 0) {
        uVar12 = (ulonglong)CONCAT24((short)(uVar12 >> 0x20) + 8,(int)uVar12);
      }
      bVar2 = (byte)(uVar12 >> 0x20);
      bVar2 = *(byte *)(uint3)CONCAT11((char)(uVar12 >> 0x28) + -0x26 + (0x41 < bVar2),bVar2 + 0xbe)
      ;
      bVar1 = bVar2 & 0x7f;
      if ((bVar2 & 0x80) == 0) {
        bVar1 = bVar2 & 0x3f;
        bVar7 = extraout_R1;
        memcpy_sym(app_work_area, bVar1, sizeof app_work_area);
        _DAT_ram_d6b3 = (char)uVar12;
        if ((bVar2 & 0x40) == 0) goto LAB_rom_01348c;
      }
      else {
        puVar6 = dec_copy_ret((undefined2 *)0xd6c6,(undefined2 *)0xd6bc);
        bVar7 = (byte)((ushort)puVar6 >> 8);
      }
      memcpy_sym(app_work_area, bVar1, sizeof app_work_area);
      _DAT_ram_d6b3 = 1;
      goto LAB_rom_01348c;
    }
    if (bVar2 < 2) {
      dec_swap_temp();
    }
    else {
      dec_cmp_path2();
    }
    uVar12 = (ulonglong)CONCAT14(ratio_unit,uVar10);
    bVar2 = 0x40;
    apps_mat_check(_a2);
    if ((bVar2 >> 6 & 1) != 0) {
      uVar12 = (ulonglong)CONCAT24((short)(uVar12 >> 0x20) + 4,(int)uVar12);
    }
    sVar13 = 0;
    if ((char)uVar12 != '\x01') {
      sVar13 = 8;
    }
    sVar13 = (short)(uVar12 >> 0x20) + sVar13;
    bVar2 = (byte)sVar13;
    uVar11 = CONCAT15((char)((ushort)sVar13 >> 8) + -0x26 + (0x51 < bVar2),
                      CONCAT14(bVar2 + 0xae,(int)uVar12));
  }
  else {
    if (5 < sub_mode) {
      uVar12 = (ulonglong)
               CONCAT14(ratio_unit,
                        (uint)CONCAT11(*(undefined *)
                                        (uint3)(ushort)(CONCAT15((9 < bVar2) + -0x26,
                                                                 CONCAT14(bVar2 - 10,uVar9)) >> 0x20
                                                       ),bVar2));
      bVar2 = 0x40;
      apps_mat_check(_a2);
      if ((bVar2 >> 6 & 1) != 0) {
        uVar12 = (ulonglong)CONCAT24((short)(uVar12 >> 0x20) + 4,(int)uVar12);
      }
      bVar1 = (byte)uVar12;
      bVar2 = bVar1;
      if (2 < bVar1) {
        bVar2 = bVar1 - 3;
      }
      sVar13 = (short)(uVar12 >> 0x20) + (ushort)(byte)(bVar2 << 3);
      bVar2 = (byte)sVar13;
      cVar4 = (char)((ushort)sVar13 >> 8);
      if (bVar1 < 3) {
        uVar11 = CONCAT15((cVar4 + -0x26) - ((char)((0x69 < bVar2) << 7) >> 7),
                          CONCAT14(bVar2 + 0x96,(int)uVar12));
      }
      else {
        uVar11 = CONCAT15((cVar4 + -0x26) - ((char)((0x31 < bVar2) << 7) >> 7),
                          CONCAT14(bVar2 - 0x32,(int)uVar12));
      }
      uVar3 = *(undefined *)(uint3)(ushort)((uint6)uVar11 >> 0x20);
      bVar7 = 0;
      uVar12 = (ulonglong)CONCAT12(uVar3,(short)uVar11);
      cVar4 = (char)((uint6)uVar11 >> 8);
      if (cVar4 != '\0') {
        cVar4 = apps_mat_row(CONCAT11(cVar4,uVar3));
        uVar12 = (ulonglong)CONCAT61((int6)(uVar12 >> 0x10),cVar4) << 8;
        bVar7 = extraout_R1_00;
      }
      uVar8 = (uint3)uVar12 & 0x3fffff;
      memcpy_sym(app_work_area, (byte)(uVar8 >> 0x10), sizeof app_work_area);
      _DAT_ram_d6b3 = (char)(uVar8 >> 8);
      goto LAB_rom_01348c;
    }
    if (bVar2 == 1) {
      uVar9 = uVar10;
      dec_swap_temp();
    }
    else if (bVar2 != 0) {
      uVar9 = uVar10;
      dec_cmp_path1();
    }
    uVar12 = (ulonglong)CONCAT14(ratio_unit,uVar9);
    bVar2 = 0x40;
    apps_mat_check(_a2);
    if ((bVar2 >> 6 & 1) != 0) {
      uVar12 = (ulonglong)CONCAT24((short)(uVar12 >> 0x20) + 4,(int)uVar12);
    }
    sVar13 = (short)(uVar12 >> 0x20) + (ushort)(byte)((char)uVar12 << 3);
    bVar2 = (byte)sVar13;
    uVar11 = CONCAT15((char)((ushort)sVar13 >> 8) + -0x26 + (0x69 < bVar2),
                      CONCAT14(bVar2 + 0x96,(int)uVar12));
  }
  bVar7 = 0;
  memcpy_sym(app_work_area, *(byte *)(uint3)(ushort)((uint6)uVar11 >> 0x20), sizeof app_work_area);
  _DAT_ram_d6b3 = (char)uVar11;
LAB_rom_01348c:
  return (ushort)bVar7 << 8;
}

