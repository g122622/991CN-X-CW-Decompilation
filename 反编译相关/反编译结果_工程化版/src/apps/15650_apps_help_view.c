/*
 * 应用模式 / 15650_apps_help_view.c
 * 地址范围: 0x15650 - 0x15A62
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 帮助/说明视图子过程
 * @addr 0x15650
 * @module apps
 * @proto undefined2 apps_help_view(undefined2 arg)
 * @confidence likely
 * @note 帮助/说明视图子过程：先切换到空屏（screen_mode_blank）再显示文本。
 * @tag mode
 */
undefined2 apps_help_view(undefined2 arg)

{
  bool bVar1;
  int cVar2;
  undefined uVar3;
  byte extraout_R1;
  undefined extraout_R1_00;
  byte extraout_R1_01;
  undefined extraout_R1_02;
  undefined extraout_R1_03;
  undefined extraout_R1_04;
  ushort uVar4;
  undefined *puVar5;
  undefined2 uVar6;
  short sVar7;
  short sVar8;
  undefined2 *puVar9;
  undefined *unaff_ER6;
  undefined2 *puVar10;
  byte bVar17;
  ushort *puVar18;
  byte bVar21;
  ushort *puVar22;
  undefined3 uVar24;
  ulonglong uVar11;
  undefined8 uVar12;
  undefined6 uVar20;
  undefined7 uVar16;
  undefined8 in_QR8;
  undefined4 uVar23;
  longlong lVar13;
  undefined2 *puVar19;
  undefined8 uVar14;
  longlong lVar15;
  
  uVar23 = (undefined4)((ulonglong)in_QR8 >> 0x20);
  bVar17 = ((undefined2 *)(unaff_ER6 + 0x28) == (undefined2 *)0x0) << 6;
  int_to_dec((undefined2 *)(unaff_ER6 + 0x28),arg);
  sVar8 = (short)((uint)uVar23 >> 0x10);
  if ((bVar17 >> 6 & 1) != 0) {
    *(undefined2 *)(sVar8 + -8) = 0x103;
    uVar4 = apps_display_update(arg);
    return uVar4;
  }
  puVar5 = (undefined *)(*(short *)(sVar8 + -6) + 0xa0);
  *(undefined **)(sVar8 + -10) = puVar5;
  memzero_A0(puVar5);
  memcpy_bytes(*(undefined **)((short)((uint)uVar23 >> 0x10) + -10),unaff_ER6,0x32);
  puVar10 = *(undefined2 **)((short)((uint)uVar23 >> 0x10) + -10);
  puVar19 = puVar10 + 0x19;
  dec_copy_step((uintptr_t)0);
  dec_xy_sub(puVar19,unaff_ER6);
  dec_cmp_ex(puVar19,unaff_ER6);
  lVar13 = (ulonglong)CONCAT42(uVar23,puVar10 + 0x28) << 0x10;
  dec_set_uint_small(puVar10 + 0x28,8);
  dec_add_or_round(puVar19,(undefined2 *)((ulonglong)lVar13 >> 0x10));
  dec_copy_a((uintptr_t)0);
  puVar18 = (ushort *)((short)((ulonglong)lVar13 >> 0x10) + 10);
  lVar13 = (ulonglong)CONCAT42((int)((ulonglong)lVar13 >> 0x20),puVar18) << 0x10;
  dec_set_uint_small(puVar18,3);
  pow_ER4_ER2();
  dec_copy_a((uintptr_t)0);
  uVar4 = dec_mul_ER4(puVar10 + 10);
  if ((char)uVar4 != '\0') {
    return uVar4;
  }
  dec_copy_step((uintptr_t)0);
  lVar13 = (ulonglong)
           CONCAT42((int)((ulonglong)lVar13 >> 0x20),(short)((ulonglong)lVar13 >> 0x10) + -10) <<
           0x10;
  pow_ER4_ER2();
  lVar13 = (ulonglong)
           CONCAT42((int)((ulonglong)lVar13 >> 0x20),(short)((ulonglong)lVar13 >> 0x10) + 0x14) <<
           0x10;
  dec_copy_step((uintptr_t)0);
  dec_cmp_Y_one((undefined2 *)((ulonglong)lVar13 >> 0x10));
  dec_pow_ER10();
  dec_mul_ER4((undefined2 *)((ulonglong)lVar13 >> 0x10));
  puVar19 = puVar10 + 0xf;
  uVar4 = dec_bin_div(puVar10 + 0x1e,puVar19);
  if ((char)uVar4 != '\0') {
    return uVar4;
  }
  uVar14 = CONCAT35((int3)((ulonglong)lVar13 >> 0x28),(uint5)(uint)lVar13);
  uVar6 = dec_cmp(puVar10 + 0x1e,puVar19);
  if ((char)uVar6 == '\x04') {
    uVar14 = CONCAT35((int3)((ulonglong)uVar14 >> 0x28),
                      CONCAT14((char)((ulonglong)uVar14 >> 0x20) + '\x01',(int)uVar14));
  }
  *(char *)((short)((ulonglong)uVar14 >> 0x30) + -0xc) = (char)((ulonglong)uVar14 >> 0x20);
  puVar9 = puVar10 + 0x23;
  puVar19 = (undefined2 *)((short)((ulonglong)uVar14 >> 0x10) + -10);
  lVar13 = (ulonglong)CONCAT42((int)((ulonglong)uVar14 >> 0x20),puVar19) << 0x10;
  dec_copy(puVar9,puVar19);
  dec_cmp_Y_one(puVar9);
  dec_cmp_Y_one(puVar9);
  lVar13 = (ulonglong)
           CONCAT42((int)((ulonglong)lVar13 >> 0x20),(short)((ulonglong)lVar13 >> 0x10) + -10) <<
           0x10;
  pow_ER4_ER2();
  dec_cmp_Y_one((undefined2 *)((ulonglong)lVar13 >> 0x10));
  dec_pow_ER10();
  dec_mul_ER4((undefined2 *)((ulonglong)lVar13 >> 0x10));
  dec_copy_step((uintptr_t)0);
  dec_cmp_Y_one((undefined2 *)((ulonglong)lVar13 >> 0x10));
  dec_cmp_Y_one((undefined2 *)((ulonglong)lVar13 >> 0x10));
  dec_copy(puVar10,(undefined2 *)((ulonglong)lVar13 >> 0x10));
  puVar19 = puVar10 + 0xf;
  dec_pow_ER10();
  dec_cmp_ex((undefined2 *)((ulonglong)lVar13 >> 0x10),puVar19);
  dec_bin_div(puVar9,(undefined2 *)((ulonglong)lVar13 >> 0x10));
  uVar6 = (undefined2)((ulonglong)lVar13 >> 0x30);
  puVar19 = puVar10 + 0x14;
  uVar4 = dec_mul_ER4(puVar19);
  bVar1 = (char)uVar4 == '\0';
  bVar17 = bVar1 << 6;
  if (!bVar1) {
    return uVar4;
  }
  uVar4 = kbd_wait_key();
  if ((bVar17 >> 6 & 1) != 1) {
    return uVar4;
  }
  lVar13 = (ulonglong)CONCAT22(uVar6,puVar10 + 0x1e) << 0x20;
  uVar6 = dec_cmp(puVar9,puVar19);
  if ((((char)uVar6 == '\x01') &&
      (uVar6 = dec_cmp(puVar10 + 0x1e,puVar19), (char)uVar6 == '\x01')) &&
     (uVar6 = dec_cmp(puVar10 + 0x19,puVar19), (char)uVar6 == '\x01')) {
    sVar8 = (short)((ulonglong)lVar13 >> 0x30);
    puVar19 = *(undefined2 **)(sVar8 + -10);
    dec_copy(*(undefined2 **)(sVar8 + -6),puVar19);
    dec_inc5(*(undefined2 **)((short)((ulonglong)lVar13 >> 0x30) + -6),puVar19);
    uVar14 = CONCAT71((int7)((ulonglong)lVar13 >> 8),1);
  }
  else {
    uVar3 = table_clear();
    lVar15 = (ulonglong)CONCAT61((int6)((ulonglong)lVar13 >> 0x10),uVar3) << 8;
    uVar6 = dec_cmp((undefined2 *)((ulonglong)lVar13 >> 0x20),puVar19);
    if ((char)uVar6 == '\x01') {
      uVar6 = dec_cmp((undefined2 *)((short)((ulonglong)lVar15 >> 0x20) + -10),puVar19);
      if ((char)uVar6 == '\x01') {
        uVar4 = apps_cell_edit();
        return uVar4;
      }
      uVar4 = apps_result_view(puVar19);
      return uVar4;
    }
    uVar6 = CONCAT11((char)((ushort)puVar19 >> 8),(char)((ulonglong)lVar15 >> 8));
    cVar2 = table_delete(uVar6);
    uVar23 = (undefined4)((ulonglong)lVar15 >> 0x20);
    if (cVar2 == '\0') {
      cVar2 = apps_matrix_view(uVar6);
      sVar8 = (short)((uint)uVar23 >> 0x10);
      if (cVar2 == '\x01') {
        *(undefined2 *)(sVar8 + -8) = 0x602;
        uVar4 = apps_submenu(uVar6);
        return uVar4;
      }
      sVar8 = *(short *)(sVar8 + -10);
      lVar13 = (ulonglong)CONCAT42(uVar23,sVar8 + 0x50) << 0x10;
      clear_work_area();
      puVar18 = *(ushort **)((short)((ulonglong)lVar13 >> 0x30) + -4);
      dec_set_uint_small(puVar18,1);
      puVar19 = (undefined2 *)dec_copy(puVar18 + 5,(undefined2 *)(sVar8 + 0x32));
      dec_cmp_Y_one(puVar19);
      puVar19 = (undefined2 *)(sVar8 + 0x46);
      dec_copy(puVar18 + 10,puVar19);
      copy_slot4_to_slot3((uintptr_t)0);
      pow_ER4_ER6();
      dec_copy_b((uintptr_t)0);
      dec_xy_sub((undefined2 *)((ulonglong)lVar13 >> 0x10),puVar19);
      dec_cmp_ex((undefined2 *)((ulonglong)lVar13 >> 0x10),puVar19);
      puVar22 = (ushort *)((short)((ulonglong)lVar13 >> 0x10) + 10);
      uVar14 = CONCAT26((short)((ulonglong)lVar13 >> 0x30),CONCAT24(puVar22,(int)lVar13));
      dec_set_uint_small(puVar22,8);
      dec_add_or_round((undefined2 *)((ulonglong)uVar14 >> 0x10), (uintptr_t)0)
                     (undefined2 *)((ulonglong)uVar14 >> 0x20));
      puVar19 = (undefined2 *)((ulonglong)uVar14 >> 0x10);
      bVar17 = (puVar19 == (undefined2 *)0x0) << 6;
      dec_mul_ER4(puVar19);
      uVar23 = (undefined4)((ulonglong)uVar14 >> 0x20);
      uVar4 = kbd_wait_key();
      if ((bVar17 >> 6 & 1) != 1) {
        return uVar4;
      }
      *(undefined2 *)((short)((uint)uVar23 >> 0x10) + -8) = 0x303;
      sVar8 = (short)uVar23;
      uVar6 = dec_cmp(puVar18 + 0xf,puVar19);
      if ((char)uVar6 != '\x01') {
        dec_copy(puVar18 + 0x14,(undefined2 *)(sVar8 + 0x32));
        dec_copy(puVar18 + 0x19,(undefined2 *)(sVar8 + 0x3c));
        stats_x2_minus_y2_div();
        uVar4 = apps_input_line();
        return uVar4;
      }
      uVar4 = matrix_op_dispatch(puVar19);
      return uVar4;
    }
    uVar14 = CONCAT71((int7)((ulonglong)lVar15 >> 8),cVar2);
  }
  while( true ) {
    sVar8 = (short)((ulonglong)uVar14 >> 0x30);
    *(undefined2 *)(sVar8 + -8) = 4;
    bVar17 = *(byte *)(sVar8 + -7);
    uVar12 = CONCAT53((int5)((ulonglong)uVar14 >> 0x18),CONCAT12(bVar17,(ushort)uVar14));
    uVar24 = (undefined3)((ulonglong)uVar14 >> 0x28);
    if (bVar17 == 3) {
      uVar14 = CONCAT35(uVar24,(uint5)(uint)uVar12);
      do {
        uVar4 = (ushort)(byte)((ulonglong)uVar14 >> 0x20) * 4;
        uVar4 = dec_cmp_ex((undefined2 *, (uintptr_t)0)
                               ((uVar4 & 0xff) * 10 +
                               *(short *)((short)((ulonglong)uVar14 >> 0x30) + -6)),uVar4);
        if ((char)uVar4 != '\0') {
          return uVar4;
        }
        bVar21 = (char)((ulonglong)uVar14 >> 0x20) + 1;
        bVar17 = (byte)uVar14;
        uVar14 = CONCAT35((int3)((ulonglong)uVar14 >> 0x28),CONCAT14(bVar21,(int)uVar14));
      } while (bVar21 < bVar17);
      uVar4 = apps_prompt();
      return uVar4;
    }
    if (3 < bVar17) {
      if ((char)uVar14 != '\0') {
        puVar19 = *(undefined2 **)(sVar8 + -10);
        uVar12 = CONCAT35(uVar24,(uint5)(uint)uVar12);
        do {
          puVar18 = (ushort *)
                    (*(short *)((short)((ulonglong)uVar12 >> 0x30) + -6) +
                    (ushort)(byte)((char)((ulonglong)uVar12 >> 0x20) * '\x04') * 10);
          puVar10 = puVar19;
          dec_mul_ER4(puVar19);
          bVar17 = dec_get_small(puVar18,puVar10);
          if (bVar17 != 0) {
            return CONCAT11(extraout_R1_03,bVar17);
          }
          bVar17 = (byte)uVar12;
          *(byte *)(puVar18 + 10) = '\x03' - bVar17;
          bVar21 = (char)((ulonglong)uVar12 >> 0x20) + 1;
          uVar12 = CONCAT35((int3)((ulonglong)uVar12 >> 0x28),CONCAT14(bVar21,(int)uVar12));
        } while (bVar21 < bVar17);
      }
      bVar17 = (byte)((ulonglong)uVar12 >> 0x10);
      if (4 < bVar17) {
        if (bVar17 != 5) {
          uVar4 = apps_menu_loop();
          return uVar4;
        }
        bVar17 = apps_dialog_loop();
        return CONCAT11(extraout_R1_04,bVar17);
      }
      uVar4 = apps_message();
      return uVar4;
    }
    if (bVar17 == 0) break;
    sVar7 = (ushort)(byte)(4 - (char)uVar14) * 0x28;
    memzero((undefined *)(((ushort)uVar14 & 0xff) * 0x28 + *(short *)(sVar8 + -6)),sVar7);
    uVar4 = (ushort)((ulonglong)uVar12 >> 0x30);
    sVar8 = *(short *)(uVar4 - 6);
    uVar14 = CONCAT53((int5)(((ulonglong)uVar4 << 0x30) >> 0x18),
                      CONCAT12(*(undefined *)(uVar4 - 7),(short)uVar12));
    if ((char)uVar12 != '\0') {
      if ((char)uVar12 != '\x02') goto LAB_rom_01555e;
      uVar6 = dec_cmp((undefined2 *)0xd3b0,sVar7);
      if ((char)uVar6 != '\x01') goto LAB_rom_01555e;
      uVar6 = dec_cmp((undefined2 *)0xd3a6,sVar7);
      if ((char)uVar6 == '\x01') goto LAB_rom_01555e;
      uVar14 = CONCAT26((short)((ulonglong)uVar14 >> 0x30),CONCAT15(1,(int5)uVar14));
      goto LAB_rom_01555e;
    }
    uVar12 = CONCAT62((int6)((ulonglong)uVar14 >> 0x10),0x100);
    if (key_state_a != '\0') {
      return CONCAT11(extraout_R1_02,3);
    }
    while( true ) {
      bVar17 = (byte)((ulonglong)uVar12 >> 0x20);
      *(char *)((ushort)bVar17 * 0x28 + sVar8 + 0x14) = (char)((ulonglong)uVar12 >> 8);
      bVar17 = bVar17 + 1;
      uVar14 = CONCAT35((int3)((ulonglong)uVar12 >> 0x28),CONCAT14(bVar17,(int)uVar12));
      if ((byte)uVar12 < bVar17) break;
LAB_rom_01555e:
      uVar20 = (undefined6)((ulonglong)uVar14 >> 0x10);
      bVar17 = (byte)uVar14;
      uVar12 = CONCAT62(uVar20,CONCAT11(1,bVar17));
      bVar21 = (byte)((ulonglong)uVar14 >> 0x20);
      if (bVar17 == 2) {
        if ((bVar21 < 2) && (bVar21 != (byte)((ulonglong)uVar14 >> 0x28))) {
          uVar12 = CONCAT62(uVar20,0x202);
        }
      }
      else if (((bVar17 < 3) && (bVar21 == 0)) && ((char)((ulonglong)uVar14 >> 0x10) != '\x02')) {
        uVar12 = CONCAT62(uVar20,CONCAT11(3,bVar17));
      }
    }
    uVar16 = (undefined7)((ulonglong)uVar14 >> 8);
    uVar3 = matrix_dispatch((byte)uVar12 + 1);
    uVar14 = CONCAT71(uVar16,uVar3);
  }
  key_mod_clear();
  key_dispatch_menu();
  if (calc_mode == 'K') {
    return (ushort)(byte)uVar12 << 8;
  }
  uVar14 = CONCAT44((int)((ulonglong)uVar12 >> 0x20),CONCAT22(&input_buf,(short)uVar12));
  strcpy_checked(&input_buf,(char *)0x0);
  input_ptr = (undefined2)((ulonglong)uVar14 >> 0x10);
  menu_index = 0;
  uVar11 = CONCAT44((int)((ulonglong)uVar14 >> 0x20),CONCAT13(0xd1,CONCAT12(0x6c,(short)uVar14)));
  if ((char)uVar14 == '\0') {
    if (_DAT_ram_d14d != '\x04') {
      menu_index = 0;
      return CONCAT11(_DAT_ram_d14d,3);
    }
    memzero(*(undefined **)((short)((ulonglong)uVar14 >> 0x30) + -4),0x1e0);
    return (ushort)extraout_R1 << 8;
  }
  stat_fill_cells();
  puVar5 = *(undefined **)((short)(uVar11 >> 0x30) + -4);
  memzero(puVar5,0x1e0);
  uVar11 = uVar11 & 0xffffffff;
  do {
    puVar19 = (undefined2 *)(puVar5 + (ushort)(byte)((char)(uVar11 >> 0x20) * '\x04') * 10 + -0x140)
    ;
    dec_copy_rev((undefined2 *)(uVar11 >> 0x10),puVar19);
    bVar17 = dec_get_small((ushort *)(uVar11 >> 0x10),puVar19);
    if (bVar17 != 0) {
      return CONCAT11(extraout_R1_00,bVar17);
    }
    append_history(puVar19);
    bVar21 = (char)(uVar11 >> 0x20) + 1;
    bVar17 = (byte)uVar11;
    uVar11 = (ulonglong)CONCAT14(bVar21,(int)uVar11);
  } while (bVar21 < bVar17);
  return (ushort)extraout_R1_01 << 8;
}

/**
 * @brief 菜单循环子过程
 * @addr 0x15828
 * @module apps
 * @proto undefined2 apps_menu_loop(void)
 * @confidence likely
 * @note 菜单循环子过程：反复读键（kbd_wait_key）并按 0x15180 分支。
 * @tag mode
 */
undefined2 apps_menu_loop(void)

{
  int bVar1;
  int cVar2;
  byte extraout_R1;
  undefined extraout_R1_00;
  byte extraout_R1_01;
  undefined extraout_R1_02;
  undefined2 uVar3;
  undefined extraout_R1_03;
  undefined extraout_R1_04;
  short sVar4;
  ushort uVar5;
  undefined2 *puVar6;
  short sVar7;
  ushort *puVar8;
  undefined *puVar9;
  undefined2 *puVar10;
  byte bVar17;
  ushort *puVar18;
  undefined3 uVar20;
  ulonglong uVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  undefined6 uVar16;
  undefined7 uVar15;
  undefined8 in_QR8;
  longlong lVar14;
  undefined4 uVar19;
  
  bVar1 = matrix_print_fmt();
  if (bVar1 == 0) {
    sVar7 = *(short *)((short)((ulonglong)in_QR8 >> 0x30) + -10);
    lVar14 = (ulonglong)CONCAT42((int)((ulonglong)in_QR8 >> 0x20),sVar7 + 0x50) << 0x10;
    clear_work_area();
    puVar8 = *(ushort **)((short)((ulonglong)lVar14 >> 0x30) + -4);
    dec_set_uint_small(puVar8,1);
    puVar10 = (undefined2 *)dec_copy(puVar8 + 5,(undefined2 *)(sVar7 + 0x32));
    dec_cmp_Y_one(puVar10);
    puVar10 = (undefined2 *)(sVar7 + 0x46);
    dec_copy(puVar8 + 10,puVar10);
    copy_slot4_to_slot3((uintptr_t)0);
    pow_ER4_ER6();
    dec_copy_b((uintptr_t)0);
    dec_xy_sub((undefined2 *)((ulonglong)lVar14 >> 0x10),puVar10);
    dec_cmp_ex((undefined2 *)((ulonglong)lVar14 >> 0x10),puVar10);
    puVar18 = (ushort *)((short)((ulonglong)lVar14 >> 0x10) + 10);
    uVar13 = CONCAT26((short)((ulonglong)lVar14 >> 0x30),CONCAT24(puVar18,(int)lVar14));
    dec_set_uint_small(puVar18,8);
    dec_add_or_round((undefined2 *)((ulonglong)uVar13 >> 0x10), (uintptr_t)0)
                   (undefined2 *)((ulonglong)uVar13 >> 0x20));
    puVar10 = (undefined2 *)((ulonglong)uVar13 >> 0x10);
    bVar1 = (puVar10 == (undefined2 *)0x0) << 6;
    dec_mul_ER4(puVar10);
    uVar19 = (undefined4)((ulonglong)uVar13 >> 0x20);
    uVar5 = kbd_wait_key();
    if ((bVar1 >> 6 & 1) != 1) {
      return uVar5;
    }
    *(undefined2 *)((short)((uint)uVar19 >> 0x10) + -8) = 0x303;
    sVar7 = (short)uVar19;
    uVar3 = dec_cmp(puVar8 + 0xf,puVar10);
    if ((char)uVar3 != '\x01') {
      dec_copy(puVar8 + 0x14,(undefined2 *)(sVar7 + 0x32));
      dec_copy(puVar8 + 0x19,(undefined2 *)(sVar7 + 0x3c));
      stats_x2_minus_y2_div();
      uVar5 = apps_input_line();
      return uVar5;
    }
    uVar5 = matrix_op_dispatch(puVar10);
    return uVar5;
  }
  uVar15 = (undefined7)((ulonglong)in_QR8 >> 8);
  while( true ) {
    cVar2 = matrix_dispatch(bVar1);
    sVar7 = (short)((uint7)uVar15 >> 0x28);
    *(undefined2 *)(sVar7 + -8) = 4;
    uVar5 = (ushort)CONCAT71(uVar15,cVar2);
    bVar1 = *(byte *)(sVar7 + -7);
    uVar13 = CONCAT53((int5)((uint7)uVar15 >> 0x10),CONCAT12(bVar1,uVar5));
    uVar20 = (undefined3)((uint7)uVar15 >> 0x20);
    if (bVar1 == 3) {
      uVar13 = CONCAT35(uVar20,(uint5)(uint)uVar13);
      do {
        uVar5 = (ushort)(byte)((ulonglong)uVar13 >> 0x20) * 4;
        uVar5 = dec_cmp_ex((undefined2 *, (uintptr_t)0)
                               ((uVar5 & 0xff) * 10 +
                               *(short *)((short)((ulonglong)uVar13 >> 0x30) + -6)),uVar5);
        if ((char)uVar5 != '\0') {
          return uVar5;
        }
        bVar17 = (char)((ulonglong)uVar13 >> 0x20) + 1;
        bVar1 = (byte)uVar13;
        uVar13 = CONCAT35((int3)((ulonglong)uVar13 >> 0x28),CONCAT14(bVar17,(int)uVar13));
      } while (bVar17 < bVar1);
      uVar5 = apps_prompt();
      return uVar5;
    }
    if (3 < bVar1) {
      if (cVar2 != '\0') {
        puVar10 = *(undefined2 **)(sVar7 + -10);
        uVar13 = CONCAT35(uVar20,(uint5)(uint)uVar13);
        do {
          puVar8 = (ushort *)
                   (*(short *)((short)((ulonglong)uVar13 >> 0x30) + -6) +
                   (ushort)(byte)((char)((ulonglong)uVar13 >> 0x20) * '\x04') * 10);
          puVar6 = puVar10;
          dec_mul_ER4(puVar10);
          bVar1 = dec_get_small(puVar8,puVar6);
          if (bVar1 != 0) {
            return CONCAT11(extraout_R1_03,bVar1);
          }
          bVar1 = (byte)uVar13;
          *(byte *)(puVar8 + 10) = '\x03' - bVar1;
          bVar17 = (char)((ulonglong)uVar13 >> 0x20) + 1;
          uVar13 = CONCAT35((int3)((ulonglong)uVar13 >> 0x28),CONCAT14(bVar17,(int)uVar13));
        } while (bVar17 < bVar1);
      }
      bVar1 = (byte)((ulonglong)uVar13 >> 0x10);
      if (4 < bVar1) {
        if (bVar1 != 5) {
          uVar5 = apps_menu_loop();
          return uVar5;
        }
        bVar1 = apps_dialog_loop();
        return CONCAT11(extraout_R1_04,bVar1);
      }
      uVar5 = apps_message();
      return uVar5;
    }
    if (bVar1 == 0) break;
    sVar4 = (ushort)(byte)(4 - cVar2) * 0x28;
    memzero((undefined *)((uVar5 & 0xff) * 0x28 + *(short *)(sVar7 + -6)),sVar4);
    uVar5 = (ushort)((ulonglong)uVar13 >> 0x30);
    sVar7 = *(short *)(uVar5 - 6);
    uVar12 = CONCAT53((int5)(((ulonglong)uVar5 << 0x30) >> 0x18),
                      CONCAT12(*(undefined *)(uVar5 - 7),(short)uVar13));
    if ((char)uVar13 != '\0') {
      if ((char)uVar13 != '\x02') goto LAB_rom_01555e;
      uVar3 = dec_cmp((undefined2 *)0xd3b0,sVar4);
      if ((char)uVar3 != '\x01') goto LAB_rom_01555e;
      uVar3 = dec_cmp((undefined2 *)0xd3a6,sVar4);
      if ((char)uVar3 == '\x01') goto LAB_rom_01555e;
      uVar12 = CONCAT26((short)((ulonglong)uVar12 >> 0x30),CONCAT15(1,(int5)uVar12));
      goto LAB_rom_01555e;
    }
    uVar13 = CONCAT62((int6)((ulonglong)uVar12 >> 0x10),0x100);
    if (key_state_a != '\0') {
      return CONCAT11(extraout_R1_02,3);
    }
    while( true ) {
      bVar1 = (byte)((ulonglong)uVar13 >> 0x20);
      *(char *)((ushort)bVar1 * 0x28 + sVar7 + 0x14) = (char)((ulonglong)uVar13 >> 8);
      bVar1 = bVar1 + 1;
      uVar12 = CONCAT35((int3)((ulonglong)uVar13 >> 0x28),CONCAT14(bVar1,(int)uVar13));
      if ((byte)uVar13 < bVar1) break;
LAB_rom_01555e:
      uVar16 = (undefined6)((ulonglong)uVar12 >> 0x10);
      bVar1 = (byte)uVar12;
      uVar13 = CONCAT62(uVar16,CONCAT11(1,bVar1));
      bVar17 = (byte)((ulonglong)uVar12 >> 0x20);
      if (bVar1 == 2) {
        if ((bVar17 < 2) && (bVar17 != (byte)((ulonglong)uVar12 >> 0x28))) {
          uVar13 = CONCAT62(uVar16,0x202);
        }
      }
      else if (((bVar1 < 3) && (bVar17 == 0)) && ((char)((ulonglong)uVar12 >> 0x10) != '\x02')) {
        uVar13 = CONCAT62(uVar16,CONCAT11(3,bVar1));
      }
    }
    uVar15 = (undefined7)((ulonglong)uVar12 >> 8);
    bVar1 = (byte)uVar13 + 1;
  }
  key_mod_clear();
  key_dispatch_menu();
  if (calc_mode == 'K') {
    return (ushort)(byte)uVar13 << 8;
  }
  uVar13 = CONCAT44((int)((ulonglong)uVar13 >> 0x20),CONCAT22(&input_buf,(short)uVar13));
  strcpy_checked(&input_buf,(char *)0x0);
  input_ptr = (undefined2)((ulonglong)uVar13 >> 0x10);
  menu_index = 0;
  uVar11 = CONCAT44((int)((ulonglong)uVar13 >> 0x20),CONCAT13(0xd1,CONCAT12(0x6c,(short)uVar13)));
  if ((char)uVar13 == '\0') {
    if (_DAT_ram_d14d != '\x04') {
      menu_index = 0;
      return CONCAT11(_DAT_ram_d14d,3);
    }
    memzero(*(undefined **)((short)((ulonglong)uVar13 >> 0x30) + -4),0x1e0);
    return (ushort)extraout_R1 << 8;
  }
  stat_fill_cells();
  puVar9 = *(undefined **)((short)(uVar11 >> 0x30) + -4);
  memzero(puVar9,0x1e0);
  uVar11 = uVar11 & 0xffffffff;
  do {
    puVar10 = (undefined2 *)(puVar9 + (ushort)(byte)((char)(uVar11 >> 0x20) * '\x04') * 10 + -0x140)
    ;
    dec_copy_rev((undefined2 *)(uVar11 >> 0x10),puVar10);
    bVar1 = dec_get_small((ushort *)(uVar11 >> 0x10),puVar10);
    if (bVar1 != 0) {
      return CONCAT11(extraout_R1_00,bVar1);
    }
    append_history(puVar10);
    bVar17 = (char)(uVar11 >> 0x20) + 1;
    bVar1 = (byte)uVar11;
    uVar11 = (ulonglong)CONCAT14(bVar17,(int)uVar11);
  } while (bVar17 < bVar1);
  return (ushort)extraout_R1_01 << 8;
}

/**
 * @brief 单元格编辑子过程
 * @addr 0x15838
 * @module apps
 * @proto int apps_cell_edit(void)
 * @confidence likely
 * @note 单元格编辑子过程。
 * @tag mode
 */
int apps_cell_edit(void)

{
  undefined2 *puVar1;
  undefined2 uVar2;
  ushort *puVar3;
  short sVar4;
  undefined8 in_QR8;
  longlong lVar5;
  undefined8 uVar6;
  undefined4 uVar8;
  byte bVar9;
  ushort *puVar7;
  
  sVar4 = *(short *)((short)((ulonglong)in_QR8 >> 0x30) + -10);
  lVar5 = (ulonglong)CONCAT42((int)((ulonglong)in_QR8 >> 0x20),sVar4 + 0x50) << 0x10;
  clear_work_area();
  puVar3 = *(ushort **)((short)((ulonglong)lVar5 >> 0x30) + -4);
  dec_set_uint_small(puVar3,1);
  puVar1 = (undefined2 *)dec_copy(puVar3 + 5,(undefined2 *)(sVar4 + 0x32));
  dec_cmp_Y_one(puVar1);
  puVar1 = (undefined2 *)(sVar4 + 0x46);
  dec_copy(puVar3 + 10,puVar1);
  copy_slot4_to_slot3((uintptr_t)0);
  pow_ER4_ER6();
  dec_copy_b((uintptr_t)0);
  dec_xy_sub((undefined2 *)((ulonglong)lVar5 >> 0x10),puVar1);
  dec_cmp_ex((undefined2 *)((ulonglong)lVar5 >> 0x10),puVar1);
  puVar7 = (ushort *)((short)((ulonglong)lVar5 >> 0x10) + 10);
  uVar6 = CONCAT26((short)((ulonglong)lVar5 >> 0x30),CONCAT24(puVar7,(int)lVar5));
  dec_set_uint_small(puVar7,8);
  dec_add_or_round((undefined2 *)((ulonglong)uVar6 >> 0x10),(undefined2 *)((ulonglong)uVar6 >> 0x20));
  puVar1 = (undefined2 *)((ulonglong)uVar6 >> 0x10);
  bVar9 = (puVar1 == (undefined2 *)0x0) << 6;
  dec_mul_ER4(puVar1);
  uVar8 = (undefined4)((ulonglong)uVar6 >> 0x20);
  kbd_wait_key();
  if ((bVar9 >> 6 & 1) != 1) {
    return 0;
  }
  *(undefined2 *)((short)((uint)uVar8 >> 0x10) + -8) = 0x303;
  sVar4 = (short)uVar8;
  uVar2 = dec_cmp(puVar3 + 0xf,puVar1);
  if ((char)uVar2 == '\x01') {
    matrix_op_dispatch(puVar1);
    return 0;
  }
  dec_copy(puVar3 + 0x14,(undefined2 *)(sVar4 + 0x32));
  dec_copy(puVar3 + 0x19,(undefined2 *)(sVar4 + 0x3c));
  stats_x2_minus_y2_div();
  apps_input_line();
  return 0;
}

/**
 * @brief 单行提示子过程（只调用 kbd_wait_key 等待一次按键）
 * @addr 0x158EE
 * @module apps
 * @proto undefined2 apps_prompt(void)
 * @confidence likely
 * @note 单行提示子过程（只调用 kbd_wait_key 等待一次按键）。
 * @tag mode
 */
undefined2 apps_prompt(void)

{
  undefined2 uVar1;
  undefined2 *puVar2;
  short sVar3;
  undefined2 *puVar4;
  short sVar7;
  ushort *puVar8;
  undefined8 in_QR8;
  undefined4 uVar9;
  longlong lVar5;
  undefined8 uVar6;
  uint uVar10;
  byte bVar11;
  
  matrix_size_scan((byte)in_QR8);
  uVar9 = (undefined4)((ulonglong)in_QR8 >> 0x20);
  sVar3 = *(short *)((short)((ulonglong)in_QR8 >> 0x30) + -10);
  bVar11 = (sVar3 == -10) << 6;
  copy_ER6_from_ER4();
  kbd_wait_key();
  if ((bVar11 >> 6 & 1) != 1) {
    return;
  }
  puVar4 = (undefined2 *)(sVar3 + 0x14);
  lVar5 = (ulonglong)CONCAT42(uVar9,sVar3 + 0x32) << 0x10;
  dec_copy_step2();
  uVar6 = CONCAT26((short)((ulonglong)lVar5 >> 0x30),(uint6)(uint)lVar5);
  dec_pow_const_1b76();
  puVar2 = (undefined2 *)((ulonglong)uVar6 >> 0x10);
  dec_bin_div(puVar4,puVar2);
  dec_round(puVar4,puVar2);
  dec_cmp_ex(puVar4,puVar2);
  uVar1 = dec_cmp(puVar4,puVar2);
  if ((char)uVar1 == '\x01') {
    puVar4 = (undefined2 *)(sVar3 + 0x1e);
    copy_ER6_from_ER4();
    dec_xy_sub(puVar4,puVar2);
    puVar2 = (undefined2 *)((short)((ulonglong)uVar6 >> 0x10) + 0x14);
    uVar10 = (uint)((ulonglong)uVar6 >> 0x30);
    dec_bin_div(puVar4,puVar2);
    dec_round(puVar4,puVar2);
    dec_cmp_ex(puVar4,puVar2);
    if (*(char *)((short)uVar10 + -0xc) == '\x01') {
      dec_inc5(puVar4,puVar2);
    }
  }
  else {
    puVar4 = (undefined2 *)(sVar3 + 0x1e);
    sVar7 = (short)((ulonglong)uVar6 >> 0x10) + 10;
    dec_copy_step2();
    uVar10 = 0;
    dec_inc5(puVar4,sVar7);
    dec_cmp_Y_one(puVar4);
    puVar2 = (undefined2 *)(sVar3 + 0x14);
    dec_add_or_round(puVar4,puVar2);
    dec_cmp_ex(puVar4,puVar2);
  }
  clear_work_area();
  puVar8 = *(ushort **)((short)(uVar10 >> 0x10) + -4);
  lVar5 = (ulonglong)CONCAT42(uVar10,puVar8) << 0x10;
  dec_set_uint_small(puVar8,1);
  lVar5 = (ulonglong)
          CONCAT42((int)((ulonglong)lVar5 >> 0x20),(short)((ulonglong)lVar5 >> 0x10) + 10) << 0x10;
  dec_copy_b((uintptr_t)0);
  lVar5 = (ulonglong)
          CONCAT42((int)((ulonglong)lVar5 >> 0x20),(short)((ulonglong)lVar5 >> 0x10) + 10) << 0x10;
  dec_copy_b((uintptr_t)0);
  puVar2 = (undefined2 *)(sVar3 + 10);
  dec_bin_div((undefined2 *)((ulonglong)lVar5 >> 0x10),puVar2);
  *(undefined2 *)((short)((ulonglong)lVar5 >> 0x30) + -8) = 0x402;
  apps_submenu(puVar2);
  return;
}

/**
 * @brief 消息框子过程（等待按键后返回）
 * @addr 0x159C6
 * @module apps
 * @proto undefined2 apps_message(void)
 * @confidence likely
 * @note 消息框子过程（等待按键后返回）。
 * @tag mode
 */
undefined2 apps_message(void)

{
  undefined *puVar1;
  undefined uVar3;
  undefined2 uVar2;
  short sVar4;
  undefined2 *puVar5;
  ushort *puVar7;
  undefined8 in_QR8;
  undefined4 uVar8;
  short sVar9;
  longlong lVar6;
  byte in_PSW;
  
  kbd_wait_key();
  if ((in_PSW >> 6 & 1) != 1) {
    return;
  }
  sVar4 = (short)((ulonglong)in_QR8 >> 0x30);
  *(char *)(sVar4 + -0xb) = (char)in_QR8;
  puVar1 = *(undefined **)(sVar4 + -6);
  memcpy_bytes((undefined *)(*(short *)(sVar4 + -10) + 0x28),puVar1,0x50);
  uVar3 = (undefined)((ushort)puVar1 >> 8);
  uVar8 = 0;
  clear_work_area();
  sVar9 = (short)((uint)uVar8 >> 0x10);
  sVar4 = *(short *)(sVar9 + -10);
  puVar7 = *(ushort **)(sVar9 + -4);
  lVar6 = (ulonglong)CONCAT42(uVar8,puVar7) << 0x10;
  uVar2 = CONCAT11(uVar3,1);
  dec_set_uint_small(puVar7,1);
  lVar6 = (ulonglong)
          CONCAT42((int)((ulonglong)lVar6 >> 0x20),(short)((ulonglong)lVar6 >> 0x10) + 10) << 0x10;
  dec_copy_b((uintptr_t)0);
  dec_inc5((undefined2 *)((ulonglong)lVar6 >> 0x10),uVar2);
  lVar6 = (ulonglong)
          CONCAT42((int)((ulonglong)lVar6 >> 0x20),(short)((ulonglong)lVar6 >> 0x10) + 10) << 0x10;
  dec_copy_b((uintptr_t)0);
  dec_inc5((undefined2 *)((ulonglong)lVar6 >> 0x10),uVar2);
  puVar5 = (undefined2 *)(sVar4 + 10);
  dec_bin_div((undefined2 *)((ulonglong)lVar6 >> 0x10),puVar5);
  *(undefined2 *)((short)((ulonglong)lVar6 >> 0x30) + -8) = 0x502;
  apps_submenu(puVar5);
  return;
}

/**
 * @brief 对话/提示框循环子过程（调用 log 相关十进制入口）
 * @addr 0x15A28
 * @module apps
 * @proto undefined2 apps_dialog_loop(void)
 * @confidence likely
 * @note 对话/提示框循环子过程（调用 log 相关十进制入口）。
 * @tag mode
 */
undefined2 apps_dialog_loop(void)

{
  undefined uVar1;
  undefined2 uVar2;
  short sVar3;
  ushort uVar4;
  undefined2 *puVar5;
  short sVar6;
  ushort *puVar7;
  undefined *puVar8;
  undefined2 *puVar9;
  char cVar10;
  byte bVar14;
  byte bVar16;
  undefined3 uVar17;
  ulonglong uVar11;
  undefined8 uVar12;
  undefined6 uVar15;
  undefined8 uVar13;
  undefined8 in_QR8;
  
  sVar6 = (short)((ulonglong)in_QR8 >> 0x30);
  uVar13 = CONCAT62((int6)((ulonglong)in_QR8 >> 0x10),CONCAT11(*(byte *)(sVar6 + -0xb),(byte)in_QR8)
                   );
  memcpy_bytes((undefined *)(*(short *)(sVar6 + -6) + (ushort)(byte)in_QR8 * 0x28), (uintptr_t)0, (uintptr_t)0)
                 (undefined *)(*(short *)(sVar6 + -10) + 0x28),
                 (ushort)*(byte *)(sVar6 + -0xb) * 0x28);
  cVar10 = (char)uVar13 + (char)((ulonglong)uVar13 >> 8);
  uVar13 = CONCAT71((int7)((ulonglong)uVar13 >> 8),cVar10);
  if (cVar10 == '\0') goto LAB_rom_015458;
  _DAT_ram_d14d = '\0';
  while( true ) {
    uVar1 = matrix_dispatch((byte)uVar13);
    uVar13 = CONCAT71((int7)((ulonglong)uVar13 >> 8),uVar1);
LAB_rom_015458:
    sVar6 = (short)((ulonglong)uVar13 >> 0x30);
    *(undefined2 *)(sVar6 + -8) = 4;
    bVar14 = *(byte *)(sVar6 + -7);
    uVar12 = CONCAT53((int5)((ulonglong)uVar13 >> 0x18),CONCAT12(bVar14,(ushort)uVar13));
    uVar17 = (undefined3)((ulonglong)uVar13 >> 0x28);
    if (bVar14 == 3) {
      uVar13 = CONCAT35(uVar17,(uint5)(uint)uVar12);
      do {
        uVar4 = (ushort)(byte)((ulonglong)uVar13 >> 0x20) * 4;
        bVar14 = dec_cmp_ex((undefined2 *, (uintptr_t)0)
                                ((uVar4 & 0xff) * 10 +
                                *(short *)((short)((ulonglong)uVar13 >> 0x30) + -6)),uVar4);
        if (bVar14 != 0) {
          return bVar14;
        }
        bVar16 = (char)((ulonglong)uVar13 >> 0x20) + 1;
        bVar14 = (byte)uVar13;
        uVar13 = CONCAT35((int3)((ulonglong)uVar13 >> 0x28),CONCAT14(bVar16,(int)uVar13));
      } while (bVar16 < bVar14);
      bVar14 = apps_prompt();
      return bVar14;
    }
    if (3 < bVar14) {
      if ((char)uVar13 != '\0') {
        puVar9 = *(undefined2 **)(sVar6 + -10);
        uVar12 = CONCAT35(uVar17,(uint5)(uint)uVar12);
        do {
          puVar7 = (ushort *)
                   (*(short *)((short)((ulonglong)uVar12 >> 0x30) + -6) +
                   (ushort)(byte)((char)((ulonglong)uVar12 >> 0x20) * '\x04') * 10);
          puVar5 = puVar9;
          dec_mul_ER4(puVar9);
          bVar14 = dec_get_small(puVar7,puVar5);
          if (bVar14 != 0) {
            return bVar14;
          }
          bVar14 = (byte)uVar12;
          *(byte *)(puVar7 + 10) = '\x03' - bVar14;
          bVar16 = (char)((ulonglong)uVar12 >> 0x20) + 1;
          uVar12 = CONCAT35((int3)((ulonglong)uVar12 >> 0x28),CONCAT14(bVar16,(int)uVar12));
        } while (bVar16 < bVar14);
      }
      bVar14 = (byte)((ulonglong)uVar12 >> 0x10);
      if (4 < bVar14) {
        if (bVar14 != 5) {
          uVar4 = apps_menu_loop();
          return (byte)uVar4;
        }
        bVar14 = apps_dialog_loop();
        return bVar14;
      }
      bVar14 = apps_message();
      return bVar14;
    }
    if (bVar14 == 0) {
      key_mod_clear();
      key_dispatch_menu();
      if (calc_mode == 'K') {
        return 0;
      }
      uVar13 = CONCAT44((int)((ulonglong)uVar12 >> 0x20),CONCAT22(&input_buf,(short)uVar12));
      strcpy_checked(&input_buf,(char *)0x0);
      input_ptr = (undefined2)((ulonglong)uVar13 >> 0x10);
      menu_index = 0;
      uVar11 = CONCAT44((int)((ulonglong)uVar13 >> 0x20),CONCAT13(0xd1,CONCAT12(0x6c,(short)uVar13))
                       );
      if ((char)uVar13 == '\0') {
        if (_DAT_ram_d14d != '\x04') {
          menu_index = 0;
          return 3;
        }
        memzero(*(undefined **)((short)((ulonglong)uVar13 >> 0x30) + -4),0x1e0);
        return 0;
      }
      stat_fill_cells();
      puVar8 = *(undefined **)((short)(uVar11 >> 0x30) + -4);
      memzero(puVar8,0x1e0);
      uVar11 = uVar11 & 0xffffffff;
      do {
        puVar9 = (undefined2 *)
                 (puVar8 + (ushort)(byte)((char)(uVar11 >> 0x20) * '\x04') * 10 + -0x140);
        dec_copy_rev((undefined2 *)(uVar11 >> 0x10),puVar9);
        bVar14 = dec_get_small((ushort *)(uVar11 >> 0x10),puVar9);
        if (bVar14 != 0) {
          return bVar14;
        }
        append_history(puVar9);
        bVar16 = (char)(uVar11 >> 0x20) + 1;
        bVar14 = (byte)uVar11;
        uVar11 = (ulonglong)CONCAT14(bVar16,(int)uVar11);
      } while (bVar16 < bVar14);
      return 0;
    }
    sVar3 = (ushort)(byte)(4 - (char)uVar13) * 0x28;
    memzero((undefined *)(((ushort)uVar13 & 0xff) * 0x28 + *(short *)(sVar6 + -6)),sVar3);
    uVar4 = (ushort)((ulonglong)uVar12 >> 0x30);
    sVar6 = *(short *)(uVar4 - 6);
    uVar13 = CONCAT53((int5)(((ulonglong)uVar4 << 0x30) >> 0x18),
                      CONCAT12(*(undefined *)(uVar4 - 7),(short)uVar12));
    if ((char)uVar12 != '\0') {
      if ((char)uVar12 != '\x02') goto LAB_rom_01555e;
      uVar2 = dec_cmp((undefined2 *)0xd3b0,sVar3);
      if ((char)uVar2 != '\x01') goto LAB_rom_01555e;
      uVar2 = dec_cmp((undefined2 *)0xd3a6,sVar3);
      if ((char)uVar2 == '\x01') goto LAB_rom_01555e;
      uVar13 = CONCAT26((short)((ulonglong)uVar13 >> 0x30),CONCAT15(1,(int5)uVar13));
      goto LAB_rom_01555e;
    }
    uVar12 = CONCAT62((int6)((ulonglong)uVar13 >> 0x10),0x100);
    if (key_state_a != '\0') break;
    while( true ) {
      bVar14 = (byte)((ulonglong)uVar12 >> 0x20);
      *(char *)((ushort)bVar14 * 0x28 + sVar6 + 0x14) = (char)((ulonglong)uVar12 >> 8);
      bVar14 = bVar14 + 1;
      uVar13 = CONCAT35((int3)((ulonglong)uVar12 >> 0x28),CONCAT14(bVar14,(int)uVar12));
      if ((byte)uVar12 < bVar14) break;
LAB_rom_01555e:
      uVar15 = (undefined6)((ulonglong)uVar13 >> 0x10);
      bVar14 = (byte)uVar13;
      uVar12 = CONCAT62(uVar15,CONCAT11(1,bVar14));
      bVar16 = (byte)((ulonglong)uVar13 >> 0x20);
      if (bVar14 == 2) {
        if ((bVar16 < 2) && (bVar16 != (byte)((ulonglong)uVar13 >> 0x28))) {
          uVar12 = CONCAT62(uVar15,0x202);
        }
      }
      else if (((bVar14 < 3) && (bVar16 == 0)) && ((char)((ulonglong)uVar13 >> 0x10) != '\x02')) {
        uVar12 = CONCAT62(uVar15,CONCAT11(3,bVar14));
      }
    }
    uVar13 = CONCAT71((int7)((ulonglong)uVar13 >> 8),(byte)uVar12 + 1);
  }
  return 3;
}

/**
 * @brief 结果显示视图子过程（调用 int_to_dec / dec_copy 等）
 * @addr 0x15A62
 * @module apps
 * @proto undefined2 apps_result_view(undefined2 arg)
 * @confidence likely
 * @note 结果显示视图子过程（调用 int_to_dec / dec_copy 等）。
 * @tag mode
 */
undefined2 apps_result_view(undefined2 arg)

{
  uint7 uVar1;
  undefined6 uVar2;
  undefined3 uVar3;
  undefined uVar4;
  int cVar5;
  byte extraout_R1;
  undefined extraout_R1_00;
  byte extraout_R1_01;
  undefined extraout_R1_02;
  undefined extraout_R1_03;
  undefined extraout_R1_04;
  undefined2 uVar6;
  short sVar7;
  ushort uVar8;
  short sVar9;
  ushort *puVar10;
  undefined *puVar11;
  undefined2 *puVar12;
  undefined2 *puVar13;
  short unaff_ER6;
  byte bVar19;
  byte bVar20;
  ulonglong uVar14;
  undefined8 uVar15;
  undefined4 uVar21;
  longlong lVar16;
  uint uVar22;
  undefined7 uVar18;
  undefined8 in_QR8;
  undefined8 uVar17;
  
  stats_denominator_calc();
  uVar6 = dec_cmp((undefined2 *)((ulonglong)in_QR8 >> 0x10),arg);
  if ((char)uVar6 != '\x01') {
    sVar9 = (short)((ulonglong)in_QR8 >> 0x20);
    dec_copy_a((uintptr_t)0);
    dec_cmp_Y_one((undefined2 *)((ulonglong)in_QR8 >> 0x10));
    puVar12 = (undefined2 *)((ulonglong)in_QR8 >> 0x10);
    uVar17 = CONCAT26((short)((ulonglong)in_QR8 >> 0x30),CONCAT24(puVar12 + 5,(int)in_QR8));
    dec_copy(puVar12 + 5,puVar12);
    dec_xy_sub((undefined2 *)((ulonglong)uVar17 >> 0x20),puVar12);
    puVar12 = (undefined2 *)(sVar9 + 10);
    dec_bin_div((undefined2 *)((ulonglong)uVar17 >> 0x20),puVar12);
    uVar6 = dec_cmp((undefined2 *)((ulonglong)uVar17 >> 0x20),puVar12);
    if ((char)uVar6 == '\x02') {
      dec_copy_a((uintptr_t)0);
      dec_inc5((undefined2 *)((ulonglong)uVar17 >> 0x10),puVar12);
      dec_round((undefined2 *)((ulonglong)uVar17 >> 0x10),puVar12);
      dec_copy((undefined2 *)((ulonglong)uVar17 >> 0x20), (uintptr_t)0)
                     (undefined2 *)((ulonglong)uVar17 >> 0x10));
      dec_pow_const_1b76();
      puVar12 = (undefined2 *)(sVar9 + -10);
      dec_bin_div((undefined2 *)((ulonglong)uVar17 >> 0x20),puVar12);
      uVar6 = dec_cmp((undefined2 *)((ulonglong)uVar17 >> 0x20),puVar12);
      if ((char)uVar6 == '\x02') {
        uVar8 = apps_cell_edit();
        return uVar8;
      }
    }
    else {
      dec_inc5((undefined2 *)((ulonglong)uVar17 >> 0x10),puVar12);
    }
    bVar19 = ((short)((ulonglong)uVar17 >> 0x10) == 0) << 6;
    dec_copy_step2();
    uVar21 = (undefined4)((ulonglong)uVar17 >> 0x20);
    uVar8 = kbd_wait_key();
    if ((bVar19 >> 6 & 1) != 1) {
      return uVar8;
    }
    puVar13 = (undefined2 *)(unaff_ER6 + 0x14);
    lVar16 = (ulonglong)CONCAT42(uVar21,unaff_ER6 + 0x32) << 0x10;
    dec_copy_step2();
    uVar17 = CONCAT26((short)((ulonglong)lVar16 >> 0x30),(uint6)(uint)lVar16);
    dec_pow_const_1b76();
    puVar12 = (undefined2 *)((ulonglong)uVar17 >> 0x10);
    dec_bin_div(puVar13,puVar12);
    dec_round(puVar13,puVar12);
    dec_cmp_ex(puVar13,puVar12);
    uVar6 = dec_cmp(puVar13,puVar12);
    if ((char)uVar6 == '\x01') {
      puVar13 = (undefined2 *)(unaff_ER6 + 0x1e);
      copy_ER6_from_ER4();
      dec_xy_sub(puVar13,puVar12);
      puVar12 = (undefined2 *)((short)((ulonglong)uVar17 >> 0x10) + 0x14);
      uVar22 = (uint)((ulonglong)uVar17 >> 0x30);
      dec_bin_div(puVar13,puVar12);
      dec_round(puVar13,puVar12);
      dec_cmp_ex(puVar13,puVar12);
      if (*(char *)((short)uVar22 + -0xc) == '\x01') {
        dec_inc5(puVar13,puVar12);
      }
    }
    else {
      puVar13 = (undefined2 *)(unaff_ER6 + 0x1e);
      sVar9 = (short)((ulonglong)uVar17 >> 0x10) + 10;
      dec_copy_step2();
      uVar22 = 0;
      dec_inc5(puVar13,sVar9);
      dec_cmp_Y_one(puVar13);
      puVar12 = (undefined2 *)(unaff_ER6 + 0x14);
      dec_add_or_round(puVar13,puVar12);
      dec_cmp_ex(puVar13,puVar12);
    }
    clear_work_area();
    puVar10 = *(ushort **)((short)(uVar22 >> 0x10) + -4);
    lVar16 = (ulonglong)CONCAT42(uVar22,puVar10) << 0x10;
    dec_set_uint_small(puVar10,1);
    lVar16 = (ulonglong)
             CONCAT42((int)((ulonglong)lVar16 >> 0x20),(short)((ulonglong)lVar16 >> 0x10) + 10) <<
             0x10;
    dec_copy_b((uintptr_t)0);
    lVar16 = (ulonglong)
             CONCAT42((int)((ulonglong)lVar16 >> 0x20),(short)((ulonglong)lVar16 >> 0x10) + 10) <<
             0x10;
    dec_copy_b((uintptr_t)0);
    puVar12 = (undefined2 *)(unaff_ER6 + 10);
    dec_bin_div((undefined2 *)((ulonglong)lVar16 >> 0x10),puVar12);
    *(undefined2 *)((short)((ulonglong)lVar16 >> 0x30) + -8) = 0x402;
    uVar8 = apps_submenu(puVar12);
    return uVar8;
  }
  cVar5 = stat_func_call(arg);
  uVar1 = (uint7)((ulonglong)in_QR8 >> 8);
  lVar16 = CONCAT71(uVar1,cVar5);
  if (cVar5 == '\x04') {
    lVar16 = (ulonglong)uVar1 << 8;
    _DAT_ram_d14d = '\x04';
  }
  while( true ) {
    sVar9 = (short)((ulonglong)lVar16 >> 0x30);
    *(undefined2 *)(sVar9 + -8) = 4;
    bVar19 = *(byte *)(sVar9 + -7);
    uVar17 = CONCAT53((int5)((ulonglong)lVar16 >> 0x18),CONCAT12(bVar19,(ushort)lVar16));
    uVar3 = (undefined3)((ulonglong)lVar16 >> 0x28);
    if (bVar19 == 3) {
      uVar17 = CONCAT35(uVar3,(uint5)(uint)uVar17);
      do {
        uVar8 = (ushort)(byte)((ulonglong)uVar17 >> 0x20) * 4;
        uVar8 = dec_cmp_ex((undefined2 *, (uintptr_t)0)
                               ((uVar8 & 0xff) * 10 +
                               *(short *)((short)((ulonglong)uVar17 >> 0x30) + -6)),uVar8);
        if ((char)uVar8 != '\0') {
          return uVar8;
        }
        bVar20 = (char)((ulonglong)uVar17 >> 0x20) + 1;
        bVar19 = (byte)uVar17;
        uVar17 = CONCAT35((int3)((ulonglong)uVar17 >> 0x28),CONCAT14(bVar20,(int)uVar17));
      } while (bVar20 < bVar19);
      uVar8 = apps_prompt();
      return uVar8;
    }
    if (3 < bVar19) {
      if ((char)lVar16 != '\0') {
        puVar12 = *(undefined2 **)(sVar9 + -10);
        uVar17 = CONCAT35(uVar3,(uint5)(uint)uVar17);
        do {
          puVar10 = (ushort *)
                    (*(short *)((short)((ulonglong)uVar17 >> 0x30) + -6) +
                    (ushort)(byte)((char)((ulonglong)uVar17 >> 0x20) * '\x04') * 10);
          puVar13 = puVar12;
          dec_mul_ER4(puVar12);
          bVar19 = dec_get_small(puVar10,puVar13);
          if (bVar19 != 0) {
            return CONCAT11(extraout_R1_03,bVar19);
          }
          bVar19 = (byte)uVar17;
          *(byte *)(puVar10 + 10) = '\x03' - bVar19;
          bVar20 = (char)((ulonglong)uVar17 >> 0x20) + 1;
          uVar17 = CONCAT35((int3)((ulonglong)uVar17 >> 0x28),CONCAT14(bVar20,(int)uVar17));
        } while (bVar20 < bVar19);
      }
      bVar19 = (byte)((ulonglong)uVar17 >> 0x10);
      if (4 < bVar19) {
        if (bVar19 != 5) {
          uVar8 = apps_menu_loop();
          return uVar8;
        }
        bVar19 = apps_dialog_loop();
        return CONCAT11(extraout_R1_04,bVar19);
      }
      uVar8 = apps_message();
      return uVar8;
    }
    if (bVar19 == 0) break;
    sVar7 = (ushort)(byte)(4 - (char)lVar16) * 0x28;
    memzero((undefined *)(((ushort)lVar16 & 0xff) * 0x28 + *(short *)(sVar9 + -6)),sVar7);
    uVar8 = (ushort)((ulonglong)uVar17 >> 0x30);
    sVar9 = *(short *)(uVar8 - 6);
    uVar15 = CONCAT53((int5)(((ulonglong)uVar8 << 0x30) >> 0x18),
                      CONCAT12(*(undefined *)(uVar8 - 7),(short)uVar17));
    if ((char)uVar17 != '\0') {
      if ((char)uVar17 != '\x02') goto LAB_rom_01555e;
      uVar6 = dec_cmp((undefined2 *)0xd3b0,sVar7);
      if ((char)uVar6 != '\x01') goto LAB_rom_01555e;
      uVar6 = dec_cmp((undefined2 *)0xd3a6,sVar7);
      if ((char)uVar6 == '\x01') goto LAB_rom_01555e;
      uVar15 = CONCAT26((short)((ulonglong)uVar15 >> 0x30),CONCAT15(1,(int5)uVar15));
      goto LAB_rom_01555e;
    }
    uVar17 = CONCAT62((int6)((ulonglong)uVar15 >> 0x10),0x100);
    if (key_state_a != '\0') {
      return CONCAT11(extraout_R1_02,3);
    }
    while( true ) {
      bVar19 = (byte)((ulonglong)uVar17 >> 0x20);
      *(char *)((ushort)bVar19 * 0x28 + sVar9 + 0x14) = (char)((ulonglong)uVar17 >> 8);
      bVar19 = bVar19 + 1;
      uVar15 = CONCAT35((int3)((ulonglong)uVar17 >> 0x28),CONCAT14(bVar19,(int)uVar17));
      if ((byte)uVar17 < bVar19) break;
LAB_rom_01555e:
      uVar2 = (undefined6)((ulonglong)uVar15 >> 0x10);
      bVar19 = (byte)uVar15;
      uVar17 = CONCAT62(uVar2,CONCAT11(1,bVar19));
      bVar20 = (byte)((ulonglong)uVar15 >> 0x20);
      if (bVar19 == 2) {
        if ((bVar20 < 2) && (bVar20 != (byte)((ulonglong)uVar15 >> 0x28))) {
          uVar17 = CONCAT62(uVar2,0x202);
        }
      }
      else if (((bVar19 < 3) && (bVar20 == 0)) && ((char)((ulonglong)uVar15 >> 0x10) != '\x02')) {
        uVar17 = CONCAT62(uVar2,CONCAT11(3,bVar19));
      }
    }
    uVar18 = (undefined7)((ulonglong)uVar15 >> 8);
    uVar4 = matrix_dispatch((byte)uVar17 + 1);
    lVar16 = CONCAT71(uVar18,uVar4);
  }
  key_mod_clear();
  key_dispatch_menu();
  if (calc_mode == 'K') {
    return (ushort)(byte)uVar17 << 8;
  }
  uVar17 = CONCAT44((int)((ulonglong)uVar17 >> 0x20),CONCAT22(&input_buf,(short)uVar17));
  strcpy_checked(&input_buf,(char *)0x0);
  input_ptr = (undefined2)((ulonglong)uVar17 >> 0x10);
  menu_index = 0;
  uVar14 = CONCAT44((int)((ulonglong)uVar17 >> 0x20),CONCAT13(0xd1,CONCAT12(0x6c,(short)uVar17)));
  if ((char)uVar17 == '\0') {
    if (_DAT_ram_d14d != '\x04') {
      menu_index = 0;
      return CONCAT11(_DAT_ram_d14d,3);
    }
    memzero(*(undefined **)((short)((ulonglong)uVar17 >> 0x30) + -4),0x1e0);
    return (ushort)extraout_R1 << 8;
  }
  stat_fill_cells();
  puVar11 = *(undefined **)((short)(uVar14 >> 0x30) + -4);
  memzero(puVar11,0x1e0);
  uVar14 = uVar14 & 0xffffffff;
  do {
    puVar12 = (undefined2 *)
              (puVar11 + (ushort)(byte)((char)(uVar14 >> 0x20) * '\x04') * 10 + -0x140);
    dec_copy_rev((undefined2 *)(uVar14 >> 0x10),puVar12);
    bVar19 = dec_get_small((ushort *)(uVar14 >> 0x10),puVar12);
    if (bVar19 != 0) {
      return CONCAT11(extraout_R1_00,bVar19);
    }
    append_history(puVar12);
    bVar20 = (char)(uVar14 >> 0x20) + 1;
    bVar19 = (byte)uVar14;
    uVar14 = (ulonglong)CONCAT14(bVar20,(int)uVar14);
  } while (bVar20 < bVar19);
  return (ushort)extraout_R1_01 << 8;
}

