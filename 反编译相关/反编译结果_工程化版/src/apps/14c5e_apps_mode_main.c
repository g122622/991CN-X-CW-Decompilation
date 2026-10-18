/*
 * 应用模式 / 14c5e_apps_mode_main.c
 * 地址范围: 0x14C5E - 0x15396
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 应用模式主例程
 * @addr 0x14C5E
 * @module apps
 * @proto undefined2 apps_mode_main(undefined2 arg)
 * @confidence strong
 * @note 应用模式主例程：按 0xD112/0xD111 的模式号建立界面、进入按键循环，处理
 *       ON/菜单键并调用各子过程。0x280B0（BASE-N）与 0x13368（矩阵）都调用它。
 * @tag mode
 */
undefined2 apps_mode_main(undefined2 arg)

{
  bool bVar1;
  undefined uVar2;
  ushort uVar3;
  undefined2 *puVar4;
  undefined2 uVar5;
  byte extraout_R1;
  undefined extraout_R1_00;
  byte extraout_R1_01;
  undefined extraout_R1_02;
  undefined2 uVar6;
  undefined extraout_R1_03;
  undefined extraout_R1_04;
  undefined2 *puVar7;
  undefined2 *puVar8;
  short sVar9;
  undefined *puVar10;
  byte *pbVar11;
  ushort *puVar12;
  undefined2 *puVar13;
  short sVar14;
  byte *pbVar15;
  byte bVar16;
  char cVar17;
  byte bVar25;
  byte bVar26;
  undefined3 uVar27;
  ulonglong uVar18;
  undefined8 uVar19;
  undefined8 uVar20;
  longlong lVar21;
  ulonglong uVar22;
  undefined6 uVar24;
  undefined7 uVar23;
  undefined auStack_10 [12];
  
  lVar21 = ZEXT28(auStack_10) << 0x30;
  screen_mode_blank(arg);
  _DAT_ram_d14d = '\0';
  sVar14 = (short)((ulonglong)lVar21 >> 0x30);
  *(undefined *)(sVar14 + -7) = 0;
  puVar10 = &stat_data;
  puVar13 = (undefined2 *)&app_work_area;
  *(undefined **)(sVar14 + -4) = &app_work_area;
  *(undefined2 *)(sVar14 + -6) = 0xd752;
  memzero(&app_work_area,0x140);
  bVar16 = sub_mode;
  sVar14 = (short)((ulonglong)lVar21 >> 0x30);
  *(byte *)(sVar14 + -1) = sub_mode;
  if (bVar16 < 4) {
    bVar16 = bVar16 + 1;
    _DAT_ram_d102 = CONCAT11(bVar16,bVar16);
    puVar13 = (undefined2 *)&_DAT_ram_d104;
    _DAT_ram_d104 = CONCAT11(1,bVar16);
    uVar19 = CONCAT35((int3)((ulonglong)lVar21 >> 0x28),(uint5)bVar16);
    do {
      puVar7 = puVar13;
      uVar19 = CONCAT26((short)((ulonglong)uVar19 >> 0x30),(uint6)(uint5)uVar19);
      do {
        uVar20 = uVar19;
        puVar13 = (undefined2 *)matrix_cell_index4();
        dec_copy(puVar7 + -0x14a7,puVar13);
        sVar14 = (short)((ulonglong)uVar20 >> 0x30);
        bVar26 = (char)((ulonglong)uVar20 >> 0x28) + 1;
        uVar19 = CONCAT26(sVar14,CONCAT15(bVar26,(int5)uVar20));
        bVar16 = (byte)uVar20;
        puVar7 = puVar13;
      } while ((char)((bVar26 < bVar16) << 7) < '\0');
      uVar27 = (undefined3)((ulonglong)uVar19 >> 0x28);
      bVar26 = (char)((ulonglong)uVar20 >> 0x20) + 1;
      uVar19 = CONCAT35(uVar27,CONCAT14(bVar26,(int)uVar20));
    } while ((char)((bVar26 < bVar16) << 7) < '\0');
    sVar14 = *(short *)(sVar14 + -6);
    if (3 < bVar16) {
      puVar10 = (undefined *)0xd432;
    }
    uVar18 = CONCAT35(uVar27,(int5)uVar20) & 0xffffff00ffffffff;
    do {
      bVar25 = (byte)(uVar18 >> 0x20);
      bVar26 = bVar25 * '\x04';
      bVar16 = bVar26 + (byte)uVar18;
      if (3 < (byte)uVar18) {
        bVar16 = bVar25;
      }
      uVar19 = CONCAT53((int5)(uVar18 >> 0x18),CONCAT12(10,(short)uVar18));
      puVar13 = (undefined2 *)(puVar10 + (ushort)bVar16 * 10);
      dec_copy((undefined2 *)((ushort)bVar26 * 10 + sVar14),puVar13);
      bVar16 = (char)((ulonglong)uVar19 >> 0x20) + 1;
      uVar18 = CONCAT35((int3)((ulonglong)uVar19 >> 0x28),CONCAT14(bVar16,(int)uVar19));
    } while ((char)((bVar16 < (byte)uVar19) << 7) < '\0');
    sVar14 = (short)((ulonglong)uVar19 >> 0x30);
    pbVar15 = (byte *)(sVar14 + -0x1e);
    pbVar11 = (byte *)(sVar14 + -0x14);
    *pbVar11 = 0x65;
    *pbVar15 = 0x66;
    bVar16 = (pbVar15 == (byte *)0x0) << 6;
    call_13b6c(pbVar15,(ushort)puVar13);
    uVar3 = kbd_wait_key();
    if ((bVar16 >> 6 & 1) != 1) {
      return uVar3;
    }
    bVar16 = (byte)uVar18;
    if (bVar16 < 4) {
      uVar3 = call_13cf2(pbVar11,puVar13);
      bVar1 = (char)uVar3 == '\0';
      bVar16 = bVar1 << 6;
      if (!bVar1) {
        return uVar3;
      }
      uVar3 = kbd_wait_key();
      if ((bVar16 >> 6 & 1) != 1) {
        return uVar3;
      }
      uVar3 = matrix_core_d(pbVar11,pbVar15);
      cVar17 = (char)uVar3;
    }
    else {
      uVar3 = base_mode_loop(*(ushort **)((short)(uVar18 >> 0x30) + -6));
      uVar18 = CONCAT71((int7)(uVar18 >> 8),bVar16);
      cVar17 = (char)uVar3;
    }
    if (cVar17 != '\0') {
      return uVar3;
    }
  }
  else {
    _DAT_ram_d102 = 0x404;
    _DAT_ram_d104 = 0x404;
    uVar19 = CONCAT26(sVar14,(uint6)CONCAT22(0xd432,(ushort)(byte)(bVar16 - 2)));
    do {
      bVar16 = (byte)((ulonglong)uVar19 >> 0x28);
      sVar14 = (ushort)bVar16 * 10;
      puVar7 = (undefined2 *)(&stat_data + sVar14);
      if (bVar16 == 4) {
        puVar7 = (undefined2 *)((ulonglong)uVar19 >> 0x10);
      }
      dec_copy((undefined2 *)(&app_work_area + sVar14),puVar7);
      sVar14 = (short)((ulonglong)uVar19 >> 0x30);
      bVar26 = (char)((ulonglong)uVar19 >> 0x28) + 1;
      uVar20 = CONCAT26(sVar14,CONCAT15(bVar26,(int5)uVar19));
      bVar16 = (byte)uVar19;
      uVar19 = uVar20;
    } while (bVar26 <= bVar16);
    puVar10 = (undefined *)(sVar14 + -10);
    *puVar10 = 0x65;
    bVar16 = (puVar10 == (undefined *)0x0) << 6;
    call_13b6c(puVar10,(ushort)puVar7);
    uVar3 = kbd_wait_key();
    if ((bVar16 >> 6 & 1) != 1) {
      return uVar3;
    }
    *(char *)((short)((ulonglong)uVar20 >> 0x30) + -8) = (char)uVar20;
    uVar23 = CONCAT61((int6)((ulonglong)uVar20 >> 0x10),(char)uVar20);
    uVar2 = is_edit_locked();
    uVar19 = CONCAT71(uVar23,uVar2);
    puVar7 = (undefined2 *)0xd6da;
    if ((char)uVar23 == '\x04') {
      puVar7 = (undefined2 *)0xd6e4;
    }
    puVar8 = puVar13;
    dec_copy(puVar7,(undefined2 *)&app_work_area);
    uVar19 = CONCAT35((int3)((ulonglong)uVar19 >> 0x28),(uint5)(uint)uVar19);
    do {
      puVar4 = (undefined2 *)matrix_index();
      uVar6 = dec_cmp(puVar4,puVar8);
      uVar20 = CONCAT62((int6)((ulonglong)uVar19 >> 0x10),CONCAT11((char)uVar6,(char)uVar19));
      puVar8 = puVar7;
      uVar3 = dec_add_or_round((undefined2 *)((ulonglong)uVar19 >> 0x10),puVar7);
      if ((char)uVar3 != '\0') {
        return uVar3;
      }
      uVar6 = dec_cmp((undefined2 *)((ulonglong)uVar20 >> 0x10),puVar8);
      if (((char)uVar6 == '\x01') && ((char)((ulonglong)uVar20 >> 8) != '\x01')) {
        return CONCAT11((char)((ushort)uVar6 >> 8),3);
      }
      uVar3 = dec_cmp_ex((undefined2 *)((ulonglong)uVar20 >> 0x10),puVar8);
      if ((char)uVar3 != '\0') {
        return uVar3;
      }
      if ((char)uVar20 != '\x01') {
        dec_normalize2((short)((ulonglong)uVar20 >> 0x10),puVar8);
      }
      bVar25 = (char)((ulonglong)uVar20 >> 0x20) + 1;
      bVar26 = *(byte *)((short)((ulonglong)uVar20 >> 0x30) + -8);
      uVar19 = CONCAT62((int6)(CONCAT35((int3)((ulonglong)uVar20 >> 0x28),
                                        CONCAT14(bVar25,(int)uVar20)) >> 0x10),
                        CONCAT11(bVar26,(char)uVar20));
      bVar16 = (bVar25 == bVar26) << 6;
    } while (bVar25 <= bVar26);
    uVar3 = kbd_wait_key();
    if ((bVar16 >> 6 & 1) != 1) {
      return uVar3;
    }
    bVar16 = (byte)((ulonglong)uVar19 >> 8);
    uVar19 = CONCAT71((int7)((ulonglong)uVar19 >> 8),bVar16);
    if (bVar16 == 3) {
      uVar3 = apps_display_update(puVar8);
      return uVar3;
    }
    if (3 < bVar16) {
      uVar3 = apps_help_view(puVar8);
      return uVar3;
    }
    bVar16 = 0;
    int_to_dec((undefined2 *)0xd6c6,puVar8);
    if ((bVar16 >> 6 & 1) == 1) {
      lVar21 = (ulonglong)
               CONCAT42((int)((ulonglong)uVar19 >> 0x20),
                        *(undefined2 *)((short)((ulonglong)uVar19 >> 0x30) + -6)) << 0x10;
      puVar13 = (undefined2 *)dec_copy_step((uintptr_t)0);
      uVar18 = CONCAT71((int7)((ulonglong)lVar21 >> 8),1);
      bVar16 = 0;
      int_to_dec(puVar13,puVar8);
      if ((bVar16 >> 6 & 1) == 0) {
        uVar22 = CONCAT71((int7)(uVar18 >> 8),2);
        dec_inc5((undefined2 *)(uVar18 >> 0x10),puVar8);
        bVar16 = 0;
        uVar3 = dec_add_or_round((undefined2 *)(uVar22 >> 0x10),(undefined2 *)&app_work_area);
        uVar18 = uVar22;
        if ((bVar16 >> 6 & 1) != 1) {
          return uVar3;
        }
      }
    }
    else {
      uVar6 = 0xd6da;
      dec_copy_step((uintptr_t)0);
      dec_xy_sub((undefined2 *)0xd6da,puVar8);
      uVar19 = CONCAT44((int)((ulonglong)uVar19 >> 0x20),CONCAT22(0xd6e4,(short)uVar19));
      dec_set_uint_small((ushort *)0xd6e4,4);
      dec_pow_ER10();
      dec_pow_ER10();
      uVar3 = dec_mul_ER4((undefined2 *)((ulonglong)uVar19 >> 0x10));
      if ((char)uVar3 != '\0') {
        return uVar3;
      }
      dec_set_uint_small((ushort *)((ulonglong)uVar19 >> 0x10),2);
      puVar12 = (ushort *)((short)((ulonglong)uVar19 >> 0x10) + 10);
      uVar19 = CONCAT44((int)((ulonglong)uVar19 >> 0x20),CONCAT22(puVar12,(short)uVar19));
      dec_set_uint_small(puVar12,2);
      dec_pow_ER10();
      sVar14 = *(short *)((short)((ulonglong)uVar19 >> 0x30) + -6);
      uVar19 = CONCAT44((int)((ulonglong)uVar19 >> 0x20),CONCAT22(sVar14,(short)uVar19));
      bVar16 = (sVar14 == 0) << 6;
      uVar3 = kbd_wait_key();
      if ((bVar16 >> 6 & 1) != 1) {
        return uVar3;
      }
      uVar5 = dec_cmp((undefined2 *)0xd6da,puVar13);
      if ((char)uVar5 == '\x04') {
        dec_round((undefined2 *)0xd6da,puVar13);
        uVar19 = CONCAT26((short)((ulonglong)uVar19 >> 0x30),CONCAT24(0xd6bc,(int)uVar19));
        uVar5 = dec_cmp((undefined2 *)0xd6bc,puVar13);
        uVar20 = CONCAT62((int6)((ulonglong)uVar19 >> 0x10),CONCAT11((char)uVar5,(char)uVar19));
        dec_bin_result((ushort *)((ulonglong)uVar19 >> 0x20),puVar13);
        dec_bin_div((undefined2 *)0xd6da,(undefined2 *)((ulonglong)uVar20 >> 0x20));
        uVar18 = CONCAT26((short)((ulonglong)uVar20 >> 0x30),CONCAT24(0xd6e4,(int)uVar20));
        dec_bin_pow((undefined2 *)0xd6e4,(undefined2 *)0xd6c6);
        uVar3 = dec_add_or_round((undefined2 *)(uVar18 >> 0x20),(undefined2 *)0xd6da);
        if ((char)uVar3 != '\0') {
          return uVar3;
        }
        bVar16 = 0;
        uVar3 = call_1909a_slot((undefined2 *)0xd6da);
        if ((bVar16 >> 6 & 1) != 1) {
          return uVar3;
        }
        if ((char)(uVar18 >> 8) == '\x02') {
          dec_copy_a((uintptr_t)0);
          copy_to_slot28((uintptr_t)0);
        }
        else {
          dec_inc5((undefined2 *)0xd6da,uVar6);
          dec_inc5((undefined2 *)(uVar18 >> 0x20),uVar6);
          copy_to_slot3((uintptr_t)0);
          copy_to_slot28((uintptr_t)0);
        }
      }
      else {
        uVar18 = CONCAT62((int6)((ulonglong)uVar19 >> 0x10),CONCAT11((char)uVar5,(char)uVar19));
        dec_copy_step((uintptr_t)0);
        dec_inc5((undefined2 *)(uVar18 >> 0x10),puVar13);
        puVar13 = (undefined2 *)(uVar18 >> 0x10);
        bVar16 = (puVar13 == (undefined2 *)0x0) << 6;
        uVar3 = call_1909a_slot(puVar13);
        if ((bVar16 >> 6 & 1) != 1) {
          return uVar3;
        }
        uVar23 = (undefined7)(uVar18 >> 8);
        if ((char)(uVar18 >> 8) == '\x02') {
          sVar14 = (short)(uVar18 >> 0x30);
          puVar10 = (undefined *)(uVar18 >> 0x10);
          if ((*(char *)(sVar14 + -7) == '\x06') ||
             ((calc_mode != 'K' && (key_state_a == '\x01')))) {
            copy_to_slot28((uintptr_t)0);
            dec_inc5((undefined2 *)0xd6da,puVar10);
            dec_round((undefined2 *)0xd6da,puVar10);
            bVar16 = 0;
            uVar3 = call_1909a_slot((undefined2 *)0xd6da);
            if ((bVar16 >> 6 & 1) != 1) {
              return uVar3;
            }
            copy_slot4_to_slot3((uintptr_t)0);
            dec_inc5((undefined2 *)0xd6da,puVar10);
            copy_slot4_to_slot3((uintptr_t)0);
          }
          else {
            if (*(char *)(sVar14 + -7) == '\x01') {
              *(undefined *)(sVar14 + -7) = 2;
            }
            cVar17 = (char)uVar18 + -2;
            uVar18 = CONCAT71(uVar23,cVar17);
            if (cVar17 == '\0') {
              _DAT_ram_d14d = '\x04';
            }
            memzero_A0(puVar10);
          }
        }
        else {
          uVar18 = CONCAT71(uVar23,(char)uVar18 + -1);
        }
      }
    }
  }
  while( true ) {
    sVar14 = (short)(uVar18 >> 0x30);
    bVar16 = *(byte *)(sVar14 + -7);
    uVar19 = CONCAT53((int5)(uVar18 >> 0x18),CONCAT12(bVar16,(ushort)uVar18));
    uVar27 = (undefined3)(uVar18 >> 0x28);
    if (bVar16 == 3) {
      uVar19 = CONCAT35(uVar27,(uint5)(uint)uVar19);
      do {
        uVar3 = (ushort)(byte)((ulonglong)uVar19 >> 0x20) * 4;
        uVar3 = dec_cmp_ex((undefined2 *, (uintptr_t)0)
                               ((uVar3 & 0xff) * 10 +
                               *(short *)((short)((ulonglong)uVar19 >> 0x30) + -6)),uVar3);
        if ((char)uVar3 != '\0') {
          return uVar3;
        }
        bVar26 = (char)((ulonglong)uVar19 >> 0x20) + 1;
        bVar16 = (byte)uVar19;
        uVar19 = CONCAT35((int3)((ulonglong)uVar19 >> 0x28),CONCAT14(bVar26,(int)uVar19));
      } while (bVar26 < bVar16);
      uVar3 = apps_prompt();
      return uVar3;
    }
    if (3 < bVar16) {
      if ((char)uVar18 != '\0') {
        puVar13 = *(undefined2 **)(sVar14 + -10);
        uVar19 = CONCAT35(uVar27,(uint5)(uint)uVar19);
        do {
          puVar12 = (ushort *)
                    (*(short *)((short)((ulonglong)uVar19 >> 0x30) + -6) +
                    (ushort)(byte)((char)((ulonglong)uVar19 >> 0x20) * '\x04') * 10);
          puVar7 = puVar13;
          dec_mul_ER4(puVar13);
          bVar16 = dec_get_small(puVar12,puVar7);
          if (bVar16 != 0) {
            return CONCAT11(extraout_R1_03,bVar16);
          }
          bVar16 = (byte)uVar19;
          *(byte *)(puVar12 + 10) = '\x03' - bVar16;
          bVar26 = (char)((ulonglong)uVar19 >> 0x20) + 1;
          uVar19 = CONCAT35((int3)((ulonglong)uVar19 >> 0x28),CONCAT14(bVar26,(int)uVar19));
        } while (bVar26 < bVar16);
      }
      bVar16 = (byte)((ulonglong)uVar19 >> 0x10);
      if (4 < bVar16) {
        if (bVar16 != 5) {
          uVar3 = apps_menu_loop();
          return uVar3;
        }
        bVar16 = apps_dialog_loop();
        return CONCAT11(extraout_R1_04,bVar16);
      }
      uVar3 = apps_message();
      return uVar3;
    }
    if (bVar16 == 0) break;
    sVar9 = (ushort)(byte)(4 - (char)uVar18) * 0x28;
    memzero((undefined *)(((ushort)uVar18 & 0xff) * 0x28 + *(short *)(sVar14 + -6)),sVar9);
    uVar3 = (ushort)((ulonglong)uVar19 >> 0x30);
    sVar14 = *(short *)(uVar3 - 6);
    uVar20 = CONCAT53((int5)(((ulonglong)uVar3 << 0x30) >> 0x18),
                      CONCAT12(*(undefined *)(uVar3 - 7),(short)uVar19));
    if ((char)uVar19 != '\0') {
      if ((char)uVar19 != '\x02') goto LAB_rom_01555e;
      uVar6 = dec_cmp((undefined2 *)0xd3b0,sVar9);
      if ((char)uVar6 != '\x01') goto LAB_rom_01555e;
      uVar6 = dec_cmp((undefined2 *)0xd3a6,sVar9);
      if ((char)uVar6 == '\x01') goto LAB_rom_01555e;
      uVar20 = CONCAT26((short)((ulonglong)uVar20 >> 0x30),CONCAT15(1,(int5)uVar20));
      goto LAB_rom_01555e;
    }
    uVar19 = CONCAT62((int6)((ulonglong)uVar20 >> 0x10),0x100);
    if (key_state_a != '\0') {
      return CONCAT11(extraout_R1_02,3);
    }
    while( true ) {
      bVar16 = (byte)((ulonglong)uVar19 >> 0x20);
      *(char *)((ushort)bVar16 * 0x28 + sVar14 + 0x14) = (char)((ulonglong)uVar19 >> 8);
      bVar16 = bVar16 + 1;
      uVar20 = CONCAT35((int3)((ulonglong)uVar19 >> 0x28),CONCAT14(bVar16,(int)uVar19));
      if ((byte)uVar19 < bVar16) break;
LAB_rom_01555e:
      uVar24 = (undefined6)((ulonglong)uVar20 >> 0x10);
      bVar16 = (byte)uVar20;
      uVar19 = CONCAT62(uVar24,CONCAT11(1,bVar16));
      bVar26 = (byte)((ulonglong)uVar20 >> 0x20);
      if (bVar16 == 2) {
        if ((bVar26 < 2) && (bVar26 != (byte)((ulonglong)uVar20 >> 0x28))) {
          uVar19 = CONCAT62(uVar24,0x202);
        }
      }
      else if (((bVar16 < 3) && (bVar26 == 0)) && ((char)((ulonglong)uVar20 >> 0x10) != '\x02')) {
        uVar19 = CONCAT62(uVar24,CONCAT11(3,bVar16));
      }
    }
    uVar23 = (undefined7)((ulonglong)uVar20 >> 8);
    uVar2 = matrix_dispatch((byte)uVar19 + 1);
    *(undefined2 *)((short)((uint7)uVar23 >> 0x28) + -8) = 4;
    uVar18 = CONCAT71(uVar23,uVar2);
  }
  key_mod_clear();
  key_dispatch_menu();
  if (calc_mode == 'K') {
    return (ushort)(byte)uVar19 << 8;
  }
  uVar19 = CONCAT44((int)((ulonglong)uVar19 >> 0x20),CONCAT22(&input_buf,(short)uVar19));
  strcpy_checked(&input_buf,(char *)0x0);
  input_ptr = (undefined2)((ulonglong)uVar19 >> 0x10);
  menu_index = 0;
  uVar18 = CONCAT44((int)((ulonglong)uVar19 >> 0x20),CONCAT13(0xd1,CONCAT12(0x6c,(short)uVar19)));
  if ((char)uVar19 == '\0') {
    if (_DAT_ram_d14d != '\x04') {
      menu_index = 0;
      return CONCAT11(_DAT_ram_d14d,3);
    }
    memzero(*(undefined **)((short)((ulonglong)uVar19 >> 0x30) + -4),0x1e0);
    return (ushort)extraout_R1 << 8;
  }
  stat_fill_cells();
  puVar10 = *(undefined **)((short)(uVar18 >> 0x30) + -4);
  memzero(puVar10,0x1e0);
  uVar18 = uVar18 & 0xffffffff;
  do {
    puVar13 = (undefined2 *)
              (puVar10 + (ushort)(byte)((char)(uVar18 >> 0x20) * '\x04') * 10 + -0x140);
    dec_copy_rev((undefined2 *)(uVar18 >> 0x10),puVar13);
    bVar16 = dec_get_small((ushort *)(uVar18 >> 0x10),puVar13);
    if (bVar16 != 0) {
      return CONCAT11(extraout_R1_00,bVar16);
    }
    append_history(puVar13);
    bVar26 = (char)(uVar18 >> 0x20) + 1;
    bVar16 = (byte)uVar18;
    uVar18 = (ulonglong)CONCAT14(bVar26,(int)uVar18);
  } while (bVar26 < bVar16);
  return (ushort)extraout_R1_01 << 8;
}

/**
 * @brief 子菜单/选项卡处理子过程（被 0x14C5E 与 0x15384/0x158EE/0x159…
 * @addr 0x14E38
 * @module apps
 * @proto undefined2 apps_submenu(undefined2 arg)
 * @confidence strong
 * @note 子菜单/选项卡处理子过程（被 0x14C5E 与 0x15384/0x158EE/0x159C6/0x15A62 调用）。
 * @tag mode
 */
undefined2 apps_submenu(undefined2 arg)

{
  undefined uVar1;
  ushort uVar2;
  undefined2 uVar3;
  byte extraout_R1;
  undefined extraout_R1_00;
  byte extraout_R1_01;
  undefined extraout_R1_02;
  undefined extraout_R1_03;
  undefined extraout_R1_04;
  undefined2 *puVar4;
  short sVar5;
  undefined2 *unaff_ER6;
  undefined *puVar6;
  undefined2 *puVar7;
  char cVar8;
  byte bVar14;
  ushort *puVar15;
  byte bVar18;
  undefined8 in_QR8;
  short sVar16;
  longlong lVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined3 uVar19;
  ulonglong uVar12;
  undefined6 uVar17;
  undefined7 uVar13;
  
  bVar14 = (unaff_ER6 + 10 == (undefined2 *)0x0) << 6;
  int_to_dec(unaff_ER6 + 10,arg);
  if ((bVar14 >> 6 & 1) == 1) {
    lVar9 = (ulonglong)
            CONCAT42((int)((ulonglong)in_QR8 >> 0x20),
                     *(undefined2 *)((short)((ulonglong)in_QR8 >> 0x30) + -6)) << 0x10;
    puVar7 = (undefined2 *)dec_copy_step((uintptr_t)0);
    uVar10 = CONCAT71((int7)((ulonglong)lVar9 >> 8),1);
    bVar14 = 0;
    int_to_dec(puVar7,arg);
    if ((bVar14 >> 6 & 1) == 0) {
      uVar11 = CONCAT71((int7)((ulonglong)uVar10 >> 8),2);
      dec_inc5((undefined2 *)((ulonglong)uVar10 >> 0x10),arg);
      bVar14 = (unaff_ER6 == (undefined2 *)0x0) << 6;
      uVar2 = dec_add_or_round((undefined2 *)((ulonglong)uVar11 >> 0x10),unaff_ER6);
      uVar10 = uVar11;
      if ((bVar14 >> 6 & 1) != 1) {
        return uVar2;
      }
    }
  }
  else {
    puVar7 = unaff_ER6 + 0x14;
    dec_copy_step((uintptr_t)0);
    dec_xy_sub(puVar7,arg);
    uVar10 = CONCAT44((int)((ulonglong)in_QR8 >> 0x20),CONCAT22(unaff_ER6 + 0x19,(short)in_QR8));
    dec_set_uint_small(unaff_ER6 + 0x19,4);
    dec_pow_ER10();
    dec_pow_ER10();
    uVar2 = dec_mul_ER4((undefined2 *)((ulonglong)uVar10 >> 0x10));
    if ((char)uVar2 != '\0') {
      return uVar2;
    }
    dec_set_uint_small((ushort *)((ulonglong)uVar10 >> 0x10),2);
    puVar15 = (ushort *)((short)((ulonglong)uVar10 >> 0x10) + 10);
    uVar10 = CONCAT44((int)((ulonglong)uVar10 >> 0x20),CONCAT22(puVar15,(short)uVar10));
    dec_set_uint_small(puVar15,2);
    puVar4 = unaff_ER6;
    dec_pow_ER10();
    sVar16 = *(short *)((short)((ulonglong)uVar10 >> 0x30) + -6);
    uVar10 = CONCAT44((int)((ulonglong)uVar10 >> 0x20),CONCAT22(sVar16,(short)uVar10));
    bVar14 = (sVar16 == 0) << 6;
    uVar2 = kbd_wait_key();
    if ((bVar14 >> 6 & 1) != 1) {
      return uVar2;
    }
    uVar3 = dec_cmp(puVar7,puVar4);
    if ((char)uVar3 == '\x04') {
      dec_round(puVar7,puVar4);
      uVar10 = CONCAT26((short)((ulonglong)uVar10 >> 0x30),CONCAT24(unaff_ER6 + 5,(int)uVar10));
      uVar3 = dec_cmp(unaff_ER6 + 5,puVar4);
      uVar11 = CONCAT62((int6)((ulonglong)uVar10 >> 0x10),CONCAT11((char)uVar3,(char)uVar10));
      dec_bin_result((ushort *)((ulonglong)uVar10 >> 0x20),puVar4);
      dec_bin_div(puVar7,(undefined2 *)((ulonglong)uVar11 >> 0x20));
      uVar10 = CONCAT26((short)((ulonglong)uVar11 >> 0x30),CONCAT24(unaff_ER6 + 0x19,(int)uVar11));
      dec_bin_pow(unaff_ER6 + 0x19,unaff_ER6 + 10);
      puVar4 = puVar7;
      uVar2 = dec_add_or_round((undefined2 *)((ulonglong)uVar10 >> 0x20),puVar7);
      if ((char)uVar2 != '\0') {
        return uVar2;
      }
      bVar14 = (puVar7 == (undefined2 *)0x0) << 6;
      uVar2 = call_1909a_slot(puVar7);
      if ((bVar14 >> 6 & 1) != 1) {
        return uVar2;
      }
      if ((char)((ulonglong)uVar10 >> 8) == '\x02') {
        dec_copy_a((uintptr_t)0);
        copy_to_slot28((uintptr_t)0);
      }
      else {
        dec_inc5(puVar7,puVar4);
        dec_inc5((undefined2 *)((ulonglong)uVar10 >> 0x20),puVar4);
        copy_to_slot3((uintptr_t)0);
        copy_to_slot28((uintptr_t)0);
      }
    }
    else {
      uVar10 = CONCAT62((int6)((ulonglong)uVar10 >> 0x10),CONCAT11((char)uVar3,(char)uVar10));
      dec_copy_step((uintptr_t)0);
      dec_inc5((undefined2 *)((ulonglong)uVar10 >> 0x10),puVar4);
      puVar4 = (undefined2 *)((ulonglong)uVar10 >> 0x10);
      bVar14 = (puVar4 == (undefined2 *)0x0) << 6;
      uVar2 = call_1909a_slot(puVar4);
      if ((bVar14 >> 6 & 1) != 1) {
        return uVar2;
      }
      uVar13 = (undefined7)((ulonglong)uVar10 >> 8);
      if ((char)((ulonglong)uVar10 >> 8) == '\x02') {
        sVar16 = (short)((ulonglong)uVar10 >> 0x30);
        puVar6 = (undefined *)((ulonglong)uVar10 >> 0x10);
        if ((*(char *)(sVar16 + -7) == '\x06') ||
           ((calc_mode != 'K' && (key_state_a == '\x01')))) {
          copy_to_slot28((uintptr_t)0);
          dec_inc5(puVar7,puVar6);
          dec_round(puVar7,puVar6);
          bVar14 = (puVar7 == (undefined2 *)0x0) << 6;
          uVar2 = call_1909a_slot(puVar7);
          if ((bVar14 >> 6 & 1) != 1) {
            return uVar2;
          }
          copy_slot4_to_slot3((uintptr_t)0);
          dec_inc5(puVar7,puVar6);
          copy_slot4_to_slot3((uintptr_t)0);
        }
        else {
          if (*(char *)(sVar16 + -7) == '\x01') {
            *(undefined *)(sVar16 + -7) = 2;
          }
          cVar8 = (char)uVar10 + -2;
          uVar10 = CONCAT71(uVar13,cVar8);
          if (cVar8 == '\0') {
            _DAT_ram_d14d = '\x04';
          }
          memzero_A0(puVar6);
        }
      }
      else {
        uVar10 = CONCAT71(uVar13,(char)uVar10 + -1);
      }
    }
  }
  while( true ) {
    sVar16 = (short)((ulonglong)uVar10 >> 0x30);
    bVar14 = *(byte *)(sVar16 + -7);
    uVar11 = CONCAT53((int5)((ulonglong)uVar10 >> 0x18),CONCAT12(bVar14,(ushort)uVar10));
    uVar19 = (undefined3)((ulonglong)uVar10 >> 0x28);
    if (bVar14 == 3) {
      uVar10 = CONCAT35(uVar19,(uint5)(uint)uVar11);
      do {
        uVar2 = (ushort)(byte)((ulonglong)uVar10 >> 0x20) * 4;
        uVar2 = dec_cmp_ex((undefined2 *, (uintptr_t)0)
                               ((uVar2 & 0xff) * 10 +
                               *(short *)((short)((ulonglong)uVar10 >> 0x30) + -6)),uVar2);
        if ((char)uVar2 != '\0') {
          return uVar2;
        }
        bVar18 = (char)((ulonglong)uVar10 >> 0x20) + 1;
        bVar14 = (byte)uVar10;
        uVar10 = CONCAT35((int3)((ulonglong)uVar10 >> 0x28),CONCAT14(bVar18,(int)uVar10));
      } while (bVar18 < bVar14);
      uVar2 = apps_prompt();
      return uVar2;
    }
    if (3 < bVar14) {
      if ((char)uVar10 != '\0') {
        puVar7 = *(undefined2 **)(sVar16 + -10);
        uVar11 = CONCAT35(uVar19,(uint5)(uint)uVar11);
        do {
          puVar15 = (ushort *)
                    (*(short *)((short)((ulonglong)uVar11 >> 0x30) + -6) +
                    (ushort)(byte)((char)((ulonglong)uVar11 >> 0x20) * '\x04') * 10);
          puVar4 = puVar7;
          dec_mul_ER4(puVar7);
          bVar14 = dec_get_small(puVar15,puVar4);
          if (bVar14 != 0) {
            return CONCAT11(extraout_R1_03,bVar14);
          }
          bVar14 = (byte)uVar11;
          *(byte *)(puVar15 + 10) = '\x03' - bVar14;
          bVar18 = (char)((ulonglong)uVar11 >> 0x20) + 1;
          uVar11 = CONCAT35((int3)((ulonglong)uVar11 >> 0x28),CONCAT14(bVar18,(int)uVar11));
        } while (bVar18 < bVar14);
      }
      bVar14 = (byte)((ulonglong)uVar11 >> 0x10);
      if (4 < bVar14) {
        if (bVar14 != 5) {
          uVar2 = apps_menu_loop();
          return uVar2;
        }
        bVar14 = apps_dialog_loop();
        return CONCAT11(extraout_R1_04,bVar14);
      }
      uVar2 = apps_message();
      return uVar2;
    }
    if (bVar14 == 0) break;
    sVar5 = (ushort)(byte)(4 - (char)uVar10) * 0x28;
    memzero((undefined *)(((ushort)uVar10 & 0xff) * 0x28 + *(short *)(sVar16 + -6)),sVar5);
    uVar2 = (ushort)((ulonglong)uVar11 >> 0x30);
    sVar16 = *(short *)(uVar2 - 6);
    uVar10 = CONCAT53((int5)(((ulonglong)uVar2 << 0x30) >> 0x18),
                      CONCAT12(*(undefined *)(uVar2 - 7),(short)uVar11));
    if ((char)uVar11 != '\0') {
      if ((char)uVar11 != '\x02') goto LAB_rom_01555e;
      uVar3 = dec_cmp((undefined2 *)0xd3b0,sVar5);
      if ((char)uVar3 != '\x01') goto LAB_rom_01555e;
      uVar3 = dec_cmp((undefined2 *)0xd3a6,sVar5);
      if ((char)uVar3 == '\x01') goto LAB_rom_01555e;
      uVar10 = CONCAT26((short)((ulonglong)uVar10 >> 0x30),CONCAT15(1,(int5)uVar10));
      goto LAB_rom_01555e;
    }
    uVar11 = CONCAT62((int6)((ulonglong)uVar10 >> 0x10),0x100);
    if (key_state_a != '\0') {
      return CONCAT11(extraout_R1_02,3);
    }
    while( true ) {
      bVar14 = (byte)((ulonglong)uVar11 >> 0x20);
      *(char *)((ushort)bVar14 * 0x28 + sVar16 + 0x14) = (char)((ulonglong)uVar11 >> 8);
      bVar14 = bVar14 + 1;
      uVar10 = CONCAT35((int3)((ulonglong)uVar11 >> 0x28),CONCAT14(bVar14,(int)uVar11));
      if ((byte)uVar11 < bVar14) break;
LAB_rom_01555e:
      uVar17 = (undefined6)((ulonglong)uVar10 >> 0x10);
      bVar14 = (byte)uVar10;
      uVar11 = CONCAT62(uVar17,CONCAT11(1,bVar14));
      bVar18 = (byte)((ulonglong)uVar10 >> 0x20);
      if (bVar14 == 2) {
        if ((bVar18 < 2) && (bVar18 != (byte)((ulonglong)uVar10 >> 0x28))) {
          uVar11 = CONCAT62(uVar17,0x202);
        }
      }
      else if (((bVar14 < 3) && (bVar18 == 0)) && ((char)((ulonglong)uVar10 >> 0x10) != '\x02')) {
        uVar11 = CONCAT62(uVar17,CONCAT11(3,bVar14));
      }
    }
    uVar13 = (undefined7)((ulonglong)uVar10 >> 8);
    uVar1 = matrix_dispatch((byte)uVar11 + 1);
    *(undefined2 *)((short)((uint7)uVar13 >> 0x28) + -8) = 4;
    uVar10 = CONCAT71(uVar13,uVar1);
  }
  key_mod_clear();
  key_dispatch_menu();
  if (calc_mode == 'K') {
    return (ushort)(byte)uVar11 << 8;
  }
  uVar10 = CONCAT44((int)((ulonglong)uVar11 >> 0x20),CONCAT22(&input_buf,(short)uVar11));
  strcpy_checked(&input_buf,(char *)0x0);
  input_ptr = (undefined2)((ulonglong)uVar10 >> 0x10);
  menu_index = 0;
  uVar12 = CONCAT44((int)((ulonglong)uVar10 >> 0x20),CONCAT13(0xd1,CONCAT12(0x6c,(short)uVar10)));
  if ((char)uVar10 == '\0') {
    if (_DAT_ram_d14d != '\x04') {
      menu_index = 0;
      return CONCAT11(_DAT_ram_d14d,3);
    }
    memzero(*(undefined **)((short)((ulonglong)uVar10 >> 0x30) + -4),0x1e0);
    return (ushort)extraout_R1 << 8;
  }
  stat_fill_cells();
  puVar6 = *(undefined **)((short)(uVar12 >> 0x30) + -4);
  memzero(puVar6,0x1e0);
  uVar12 = uVar12 & 0xffffffff;
  do {
    puVar7 = (undefined2 *)(puVar6 + (ushort)(byte)((char)(uVar12 >> 0x20) * '\x04') * 10 + -0x140);
    dec_copy_rev((undefined2 *)(uVar12 >> 0x10),puVar7);
    bVar14 = dec_get_small((ushort *)(uVar12 >> 0x10),puVar7);
    if (bVar14 != 0) {
      return CONCAT11(extraout_R1_00,bVar14);
    }
    append_history(puVar7);
    bVar18 = (char)(uVar12 >> 0x20) + 1;
    bVar14 = (byte)uVar12;
    uVar12 = (ulonglong)CONCAT14(bVar18,(int)uVar12);
  } while (bVar18 < bVar14);
  return (ushort)extraout_R1_01 << 8;
}

/**
 * @brief 视图滚动/翻页子过程（不读键，只处理显示缓冲区）
 * @addr 0x14ECE
 * @module apps
 * @proto undefined2 apps_view_scroll(undefined2 arg)
 * @confidence likely
 * @note 视图滚动/翻页子过程（不读键，只处理显示缓冲区）。
 * @tag mode
 */
undefined2 apps_view_scroll(undefined2 arg)

{
  undefined uVar1;
  undefined2 *puVar2;
  undefined2 uVar3;
  short sVar4;
  ushort uVar5;
  undefined2 *puVar6;
  short sVar7;
  ushort *puVar8;
  undefined2 *unaff_ER6;
  undefined *puVar9;
  byte bVar15;
  int bVar17;
  undefined8 in_QR8;
  longlong lVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  undefined3 uVar18;
  ulonglong uVar13;
  undefined6 uVar16;
  undefined7 uVar14;
  
  lVar10 = (ulonglong)
           CONCAT42((int)((ulonglong)in_QR8 >> 0x20),
                    *(undefined2 *)((short)((ulonglong)in_QR8 >> 0x30) + -6)) << 0x10;
  puVar2 = (undefined2 *)dec_copy_step((uintptr_t)0);
  uVar11 = CONCAT71((int7)((ulonglong)lVar10 >> 8),1);
  bVar15 = 0;
  int_to_dec(puVar2,arg);
  if ((bVar15 >> 6 & 1) == 0) {
    uVar12 = CONCAT71((int7)((ulonglong)uVar11 >> 8),2);
    dec_inc5((undefined2 *)((ulonglong)uVar11 >> 0x10),arg);
    bVar15 = (unaff_ER6 == (undefined2 *)0x0) << 6;
    bVar17 = dec_add_or_round((undefined2 *)((ulonglong)uVar12 >> 0x10),unaff_ER6);
    uVar11 = uVar12;
    if ((bVar15 >> 6 & 1) != 1) {
      return bVar17;
    }
  }
  while( true ) {
    sVar7 = (short)((ulonglong)uVar11 >> 0x30);
    bVar15 = *(byte *)(sVar7 + -7);
    uVar12 = CONCAT53((int5)((ulonglong)uVar11 >> 0x18),CONCAT12(bVar15,(ushort)uVar11));
    uVar18 = (undefined3)((ulonglong)uVar11 >> 0x28);
    if (bVar15 == 3) {
      uVar11 = CONCAT35(uVar18,(uint5)(uint)uVar12);
      do {
        uVar5 = (ushort)(byte)((ulonglong)uVar11 >> 0x20) * 4;
        bVar15 = dec_cmp_ex((undefined2 *, (uintptr_t)0)
                                ((uVar5 & 0xff) * 10 +
                                *(short *)((short)((ulonglong)uVar11 >> 0x30) + -6)),uVar5);
        if (bVar15 != 0) {
          return bVar15;
        }
        bVar17 = (char)((ulonglong)uVar11 >> 0x20) + 1;
        bVar15 = (byte)uVar11;
        uVar11 = CONCAT35((int3)((ulonglong)uVar11 >> 0x28),CONCAT14(bVar17,(int)uVar11));
      } while (bVar17 < bVar15);
      bVar15 = apps_prompt();
      return bVar15;
    }
    if (3 < bVar15) {
      if ((char)uVar11 != '\0') {
        puVar2 = *(undefined2 **)(sVar7 + -10);
        uVar12 = CONCAT35(uVar18,(uint5)(uint)uVar12);
        do {
          puVar8 = (ushort *)
                   (*(short *)((short)((ulonglong)uVar12 >> 0x30) + -6) +
                   (ushort)(byte)((char)((ulonglong)uVar12 >> 0x20) * '\x04') * 10);
          puVar6 = puVar2;
          dec_mul_ER4(puVar2);
          bVar15 = dec_get_small(puVar8,puVar6);
          if (bVar15 != 0) {
            return bVar15;
          }
          bVar15 = (byte)uVar12;
          *(byte *)(puVar8 + 10) = '\x03' - bVar15;
          bVar17 = (char)((ulonglong)uVar12 >> 0x20) + 1;
          uVar12 = CONCAT35((int3)((ulonglong)uVar12 >> 0x28),CONCAT14(bVar17,(int)uVar12));
        } while (bVar17 < bVar15);
      }
      bVar15 = (byte)((ulonglong)uVar12 >> 0x10);
      if (4 < bVar15) {
        if (bVar15 != 5) {
          uVar5 = apps_menu_loop();
          return (byte)uVar5;
        }
        bVar15 = apps_dialog_loop();
        return bVar15;
      }
      bVar15 = apps_message();
      return bVar15;
    }
    if (bVar15 == 0) break;
    sVar4 = (ushort)(byte)(4 - (char)uVar11) * 0x28;
    memzero((undefined *)(((ushort)uVar11 & 0xff) * 0x28 + *(short *)(sVar7 + -6)),sVar4);
    uVar5 = (ushort)((ulonglong)uVar12 >> 0x30);
    sVar7 = *(short *)(uVar5 - 6);
    uVar11 = CONCAT53((int5)(((ulonglong)uVar5 << 0x30) >> 0x18),
                      CONCAT12(*(undefined *)(uVar5 - 7),(short)uVar12));
    if ((char)uVar12 != '\0') {
      if ((char)uVar12 != '\x02') goto LAB_rom_01555e;
      uVar3 = dec_cmp((undefined2 *)0xd3b0,sVar4);
      if ((char)uVar3 != '\x01') goto LAB_rom_01555e;
      uVar3 = dec_cmp((undefined2 *)0xd3a6,sVar4);
      if ((char)uVar3 == '\x01') goto LAB_rom_01555e;
      uVar11 = CONCAT26((short)((ulonglong)uVar11 >> 0x30),CONCAT15(1,(int5)uVar11));
      goto LAB_rom_01555e;
    }
    uVar12 = CONCAT62((int6)((ulonglong)uVar11 >> 0x10),0x100);
    if (key_state_a != '\0') {
      return 3;
    }
    while( true ) {
      bVar15 = (byte)((ulonglong)uVar12 >> 0x20);
      *(char *)((ushort)bVar15 * 0x28 + sVar7 + 0x14) = (char)((ulonglong)uVar12 >> 8);
      bVar15 = bVar15 + 1;
      uVar11 = CONCAT35((int3)((ulonglong)uVar12 >> 0x28),CONCAT14(bVar15,(int)uVar12));
      if ((byte)uVar12 < bVar15) break;
LAB_rom_01555e:
      uVar16 = (undefined6)((ulonglong)uVar11 >> 0x10);
      bVar15 = (byte)uVar11;
      uVar12 = CONCAT62(uVar16,CONCAT11(1,bVar15));
      bVar17 = (byte)((ulonglong)uVar11 >> 0x20);
      if (bVar15 == 2) {
        if ((bVar17 < 2) && (bVar17 != (byte)((ulonglong)uVar11 >> 0x28))) {
          uVar12 = CONCAT62(uVar16,0x202);
        }
      }
      else if (((bVar15 < 3) && (bVar17 == 0)) && ((char)((ulonglong)uVar11 >> 0x10) != '\x02')) {
        uVar12 = CONCAT62(uVar16,CONCAT11(3,bVar15));
      }
    }
    uVar14 = (undefined7)((ulonglong)uVar11 >> 8);
    uVar1 = matrix_dispatch((byte)uVar12 + 1);
    *(undefined2 *)((short)((uint7)uVar14 >> 0x28) + -8) = 4;
    uVar11 = CONCAT71(uVar14,uVar1);
  }
  key_mod_clear();
  key_dispatch_menu();
  if (calc_mode == 'K') {
    return 0;
  }
  uVar11 = CONCAT44((int)((ulonglong)uVar12 >> 0x20),CONCAT22(&input_buf,(short)uVar12));
  strcpy_checked(&input_buf,(char *)0x0);
  input_ptr = (undefined2)((ulonglong)uVar11 >> 0x10);
  menu_index = 0;
  uVar13 = CONCAT44((int)((ulonglong)uVar11 >> 0x20),CONCAT13(0xd1,CONCAT12(0x6c,(short)uVar11)));
  if ((char)uVar11 == '\0') {
    if (_DAT_ram_d14d != '\x04') {
      menu_index = 0;
      return 3;
    }
    memzero(*(undefined **)((short)((ulonglong)uVar11 >> 0x30) + -4),0x1e0);
    return 0;
  }
  stat_fill_cells();
  puVar9 = *(undefined **)((short)(uVar13 >> 0x30) + -4);
  memzero(puVar9,0x1e0);
  uVar13 = uVar13 & 0xffffffff;
  do {
    puVar2 = (undefined2 *)(puVar9 + (ushort)(byte)((char)(uVar13 >> 0x20) * '\x04') * 10 + -0x140);
    dec_copy_rev((undefined2 *)(uVar13 >> 0x10),puVar2);
    bVar15 = dec_get_small((ushort *)(uVar13 >> 0x10),puVar2);
    if (bVar15 != 0) {
      return bVar15;
    }
    append_history(puVar2);
    bVar17 = (char)(uVar13 >> 0x20) + 1;
    bVar15 = (byte)uVar13;
    uVar13 = (ulonglong)CONCAT14(bVar17,(int)uVar13);
  } while (bVar17 < bVar15);
  return 0;
}

/**
 * @brief 结果/表达式显示刷新子过程（调用 decm_add/dec_to_string 的格式化路径…
 * @addr 0x14FF8
 * @module apps
 * @proto undefined2 apps_display_update(undefined2 arg)
 * @confidence strong
 * @note 结果/表达式显示刷新子过程（调用 decm_add/dec_to_string 的格式化路径，经 0x14C5E 与
 *       0x15650 调用）。
 * @tag mode
 */
undefined2 apps_display_update(undefined2 arg)

{
  undefined6 uVar1;
  undefined3 uVar2;
  int cVar3;
  undefined uVar4;
  ushort uVar5;
  undefined2 *puVar6;
  undefined extraout_R1;
  byte extraout_R1_00;
  undefined extraout_R1_01;
  byte extraout_R1_02;
  undefined extraout_R1_03;
  undefined2 uVar7;
  undefined extraout_R1_04;
  undefined extraout_R1_05;
  undefined2 *puVar8;
  short sVar9;
  short sVar10;
  ushort *puVar11;
  undefined2 *unaff_ER6;
  undefined *puVar12;
  undefined2 *puVar13;
  byte bVar19;
  byte bVar20;
  undefined8 in_QR8;
  undefined4 uVar21;
  longlong lVar14;
  undefined8 uVar15;
  undefined8 uVar16;
  ulonglong uVar17;
  undefined7 uVar18;
  
  uVar21 = (undefined4)((ulonglong)in_QR8 >> 0x20);
  bVar19 = (unaff_ER6 + 0xf == (undefined2 *)0x0) << 6;
  int_to_dec(unaff_ER6 + 0xf,arg);
  if ((bVar19 >> 6 & 1) != 0) {
    uVar5 = matrix_op_dispatch(arg);
    return uVar5;
  }
  dec_set_uint_small(unaff_ER6 + 0x14,3);
  pow_ER4_ER6();
  puVar13 = unaff_ER6 + 10;
  pow_ER4_ER2();
  lVar14 = (ulonglong)CONCAT42(uVar21,unaff_ER6 + 0x28) << 0x10;
  dec_copy_step((uintptr_t)0);
  dec_xy_sub((undefined2 *)((ulonglong)lVar14 >> 0x10),puVar13);
  puVar13 = (undefined2 *)((ulonglong)lVar14 >> 0x10);
  uVar5 = dec_mul_ER4(puVar13);
  uVar21 = (undefined4)((ulonglong)lVar14 >> 0x20);
  if ((char)uVar5 != '\0') {
    return uVar5;
  }
  puVar8 = unaff_ER6 + 0x19;
  dec_set_from_fmt(puVar8,CONCAT11((char)((ushort)puVar13 >> 8),0x1b));
  lVar14 = (ulonglong)CONCAT42(uVar21,unaff_ER6 + 0x2d) << 0x10;
  puVar13 = unaff_ER6;
  dec_copy(unaff_ER6 + 0x2d,unaff_ER6);
  dec_xy_sub((undefined2 *)((ulonglong)lVar14 >> 0x10),puVar13);
  pow_ER4_ER2();
  uVar4 = (undefined)((ushort)(unaff_ER6 + 0xf) >> 8);
  pow_ER4_ER2();
  copy_slot4_to_slot3((uintptr_t)0);
  uVar15 = CONCAT62((int6)((ulonglong)lVar14 >> 0x10),unaff_ER6 + 0x23);
  dec_set_from_fmt(unaff_ER6 + 0x23,CONCAT11(uVar4,9));
  uVar16 = CONCAT26((short)((ulonglong)uVar15 >> 0x30),(uint6)(uint)uVar15);
  dec_copy((undefined2 *)((short)((ulonglong)uVar15 >> 0x10) + 10),unaff_ER6);
  pow_ER12_ER2();
  pow_ER12_ER2();
  pow_ER8_ER12();
  puVar13 = (undefined2 *)uVar16;
  dec_mul_ER4(puVar13);
  uVar7 = CONCAT11((char)((ushort)puVar13 >> 8),2);
  dec_set_from_fmt((short)uVar16,uVar7);
  uVar15 = CONCAT26((short)((ulonglong)uVar16 >> 0x30),
                    CONCAT24((short)((ulonglong)uVar16 >> 0x10) + 0x14,(int)uVar16));
  dec_copy_step((uintptr_t)0);
  dec_xy_add((undefined2 *)((ulonglong)uVar15 >> 0x20),uVar7);
  pow_ER8_ER12();
  puVar13 = (undefined2 *)uVar15;
  uVar5 = dec_bin_div(puVar8,puVar13);
  if ((char)uVar5 != '\0') {
    return uVar5;
  }
  bVar19 = (puVar8 == (undefined2 *)0x0) << 6;
  int_to_dec(puVar8,puVar13);
  if ((bVar19 >> 6 & 1) != 0) {
    bVar19 = (unaff_ER6 + 0x14 == (undefined2 *)0x0) << 6;
    int_to_dec(unaff_ER6 + 0x14,puVar13);
    if ((bVar19 >> 6 & 1) != 0) {
      lVar14 = (ulonglong)
               CONCAT42((int)((ulonglong)uVar15 >> 0x20),
                        *(undefined2 *)((short)((ulonglong)uVar15 >> 0x30) + -6)) << 0x10;
      dec_copy_step((uintptr_t)0);
      dec_inc5((undefined2 *)((ulonglong)lVar14 >> 0x10),puVar13);
      dec_add_or_round((undefined2 *)((ulonglong)lVar14 >> 0x10),(undefined2 *)0x1b80);
      uVar15 = CONCAT71((int7)((ulonglong)lVar14 >> 8),1);
      goto LAB_rom_015458;
    }
  }
  cVar3 = matrix_edit_loop(puVar13);
  if (cVar3 == '\x01') {
    uVar15 = CONCAT71((int7)((ulonglong)uVar15 >> 8),2);
  }
  else {
    puVar6 = unaff_ER6 + 0x1e;
    puVar13 = unaff_ER6 + 0xf;
    dec_bin_pow(puVar6,puVar13);
    dec_set_from_fmt((short)uVar15,CONCAT11((char)((ushort)puVar13 >> 8),0x12));
    dec_pow_slot_const();
    pow_ER8_ER2();
    puVar13 = (undefined2 *)uVar15;
    dec_mul_ER4(puVar13);
    uVar7 = CONCAT11((char)((ushort)puVar13 >> 8),4);
    dec_set_from_fmt((short)uVar15,uVar7);
    dec_pow_slot_const();
    pow_ER8_ER12();
    dec_div_slots();
    dec_xy_add((undefined2 *)uVar15,uVar7);
    dec_set_from_fmt((short)((ulonglong)uVar15 >> 0x20),CONCAT11((char)((ushort)uVar7 >> 8),4));
    puVar13 = (undefined2 *)uVar15;
    pow_ER8_ER12();
    puVar8 = unaff_ER6;
    pow_ER8_ER2();
    dec_div_slots();
    dec_xy_sub(puVar13,puVar8);
    pow_ER8_ER2();
    uVar5 = dec_mul_ER4(puVar13);
    if ((char)uVar5 != '\0') {
      return uVar5;
    }
    uVar21 = 0;
    dec_set_uint_small(unaff_ER6 + 0xf,3);
    puVar13 = unaff_ER6;
    dec_pow_ER10();
    puVar12 = *(undefined **)((short)((uint)uVar21 >> 0x10) + -6);
    lVar14 = (ulonglong)CONCAT42(uVar21,puVar12) << 0x10;
    bVar19 = (puVar12 == (undefined *)0x0) << 6;
    memzero_A0(puVar12);
    uVar5 = kbd_wait_key();
    if ((bVar19 >> 6 & 1) != 1) {
      return uVar5;
    }
    bVar19 = (puVar6 == (undefined2 *)0x0) << 6;
    cVar3 = int_to_dec(puVar6,puVar13);
    if ((bVar19 >> 6 & 1) != 0) {
      bVar19 = apps_key_handler();
      return CONCAT11(extraout_R1,bVar19);
    }
    if (cVar3 == '\x02') {
      uVar5 = apps_matrix_edit(puVar13);
      return uVar5;
    }
    dec_pow_slots(puVar13);
    dec_round(puVar6,puVar13);
    pow_ER4_ER6();
    uVar15 = CONCAT26((short)((ulonglong)lVar14 >> 0x30),CONCAT24(unaff_ER6 + 0x14,(int)lVar14));
    copy_slot4_to_slot3((uintptr_t)0);
    puVar13 = (undefined2 *)((short)((ulonglong)uVar15 >> 0x20) + 10);
    dec_mul_ER4(puVar13);
    dec_cmp_Y_one(puVar6);
    dec_call_1d17e_a(puVar6,puVar13);
    puVar8 = (undefined2 *)((ulonglong)uVar15 >> 0x20);
    puVar13 = puVar8 + 5;
    dec_bin_div(puVar8,puVar13);
    dec_cmp_Y_one((undefined2 *)((ulonglong)uVar15 >> 0x20));
    dec_call_1d17e_a((short)((ulonglong)uVar15 >> 0x20),puVar13);
    dec_copy_a((uintptr_t)0);
    dec_bin_mul((undefined2 *)((ulonglong)uVar15 >> 0x10), (uintptr_t)0)
                   (undefined2 *)((ulonglong)uVar15 >> 0x20));
    puVar13 = (undefined2 *)((ulonglong)uVar15 >> 0x10);
    uVar15 = CONCAT62((int6)((ulonglong)uVar15 >> 0x10),puVar13 + 0x14);
    bVar19 = (puVar13 == (undefined2 *)0x0) << 6;
    dec_copy(puVar13 + 0x14,puVar13);
    uVar5 = matrix_mul_add();
    if ((bVar19 >> 6 & 1) != 1) {
      return uVar5;
    }
    if ((calc_mode == 'K') || (key_state_a != '\x01')) {
      sVar10 = (short)((ulonglong)uVar15 >> 0x30);
      if (*(char *)(sVar10 + -7) == '\x01') {
        *(undefined *)(sVar10 + -7) = 2;
      }
      uVar15 = CONCAT71((int7)((ulonglong)uVar15 >> 8),1);
    }
    else {
      dec_cmp_Y_one((undefined2 *)uVar15);
      puVar8 = unaff_ER6 + 5;
      puVar13 = (undefined2 *)dec_div_slot_const(puVar8);
      uVar5 = dec_inc5(puVar13,puVar8);
      if ((char)uVar5 != '\0') {
        return uVar5;
      }
      dec_copy((undefined2 *)uVar15 + 0x14,(undefined2 *)uVar15);
      uVar15 = CONCAT62((int6)((ulonglong)uVar15 >> 0x10),(short)uVar15 + 10);
      copy_ER8_from_ER4();
      puVar8 = (undefined2 *)((ulonglong)uVar15 >> 0x20);
      puVar13 = (undefined2 *)dec_div_slot_const(puVar8);
      uVar4 = (undefined)((ushort)puVar8 >> 8);
      dec_cmp_Y_one(puVar13);
      uVar7 = CONCAT11(uVar4,3);
      dec_set_from_fmt((short)((ulonglong)uVar15 >> 0x20),uVar7);
      dec_round((undefined2 *)((ulonglong)uVar15 >> 0x20),uVar7);
      uVar5 = pow_ER8_ER12();
      if ((char)uVar5 != '\0') {
        return uVar5;
      }
      sVar10 = (short)uVar15;
      uVar15 = CONCAT62((int6)((ulonglong)uVar15 >> 0x10),sVar10 + 0x28);
      copy_from_ER2_to_ER8();
      dec_inc5((undefined2 *)uVar15,sVar10);
      uVar15 = CONCAT71((int7)((ulonglong)uVar15 >> 8),3);
    }
  }
LAB_rom_015458:
  while( true ) {
    sVar10 = (short)((ulonglong)uVar15 >> 0x30);
    bVar19 = *(byte *)(sVar10 + -7);
    uVar16 = CONCAT53((int5)((ulonglong)uVar15 >> 0x18),CONCAT12(bVar19,(ushort)uVar15));
    uVar2 = (undefined3)((ulonglong)uVar15 >> 0x28);
    if (bVar19 == 3) {
      uVar15 = CONCAT35(uVar2,(uint5)(uint)uVar16);
      do {
        uVar5 = (ushort)(byte)((ulonglong)uVar15 >> 0x20) * 4;
        uVar5 = dec_cmp_ex((undefined2 *, (uintptr_t)0)
                               ((uVar5 & 0xff) * 10 +
                               *(short *)((short)((ulonglong)uVar15 >> 0x30) + -6)),uVar5);
        if ((char)uVar5 != '\0') {
          return uVar5;
        }
        bVar20 = (char)((ulonglong)uVar15 >> 0x20) + 1;
        bVar19 = (byte)uVar15;
        uVar15 = CONCAT35((int3)((ulonglong)uVar15 >> 0x28),CONCAT14(bVar20,(int)uVar15));
      } while (bVar20 < bVar19);
      uVar5 = apps_prompt();
      return uVar5;
    }
    if (3 < bVar19) {
      if ((char)uVar15 != '\0') {
        puVar13 = *(undefined2 **)(sVar10 + -10);
        uVar16 = CONCAT35(uVar2,(uint5)(uint)uVar16);
        do {
          puVar11 = (ushort *)
                    (*(short *)((short)((ulonglong)uVar16 >> 0x30) + -6) +
                    (ushort)(byte)((char)((ulonglong)uVar16 >> 0x20) * '\x04') * 10);
          puVar8 = puVar13;
          dec_mul_ER4(puVar13);
          bVar19 = dec_get_small(puVar11,puVar8);
          if (bVar19 != 0) {
            return CONCAT11(extraout_R1_04,bVar19);
          }
          bVar19 = (byte)uVar16;
          *(byte *)(puVar11 + 10) = '\x03' - bVar19;
          bVar20 = (char)((ulonglong)uVar16 >> 0x20) + 1;
          uVar16 = CONCAT35((int3)((ulonglong)uVar16 >> 0x28),CONCAT14(bVar20,(int)uVar16));
        } while (bVar20 < bVar19);
      }
      bVar19 = (byte)((ulonglong)uVar16 >> 0x10);
      if (4 < bVar19) {
        if (bVar19 != 5) {
          uVar5 = apps_menu_loop();
          return uVar5;
        }
        bVar19 = apps_dialog_loop();
        return CONCAT11(extraout_R1_05,bVar19);
      }
      uVar5 = apps_message();
      return uVar5;
    }
    if (bVar19 == 0) break;
    sVar9 = (ushort)(byte)(4 - (char)uVar15) * 0x28;
    memzero((undefined *)(((ushort)uVar15 & 0xff) * 0x28 + *(short *)(sVar10 + -6)),sVar9);
    uVar5 = (ushort)((ulonglong)uVar16 >> 0x30);
    sVar10 = *(short *)(uVar5 - 6);
    uVar15 = CONCAT53((int5)(((ulonglong)uVar5 << 0x30) >> 0x18),
                      CONCAT12(*(undefined *)(uVar5 - 7),(short)uVar16));
    if ((char)uVar16 != '\0') {
      if ((char)uVar16 != '\x02') goto LAB_rom_01555e;
      uVar7 = dec_cmp((undefined2 *)0xd3b0,sVar9);
      if ((char)uVar7 != '\x01') goto LAB_rom_01555e;
      uVar7 = dec_cmp((undefined2 *)0xd3a6,sVar9);
      if ((char)uVar7 == '\x01') goto LAB_rom_01555e;
      uVar15 = CONCAT26((short)((ulonglong)uVar15 >> 0x30),CONCAT15(1,(int5)uVar15));
      goto LAB_rom_01555e;
    }
    uVar16 = CONCAT62((int6)((ulonglong)uVar15 >> 0x10),0x100);
    if (key_state_a != '\0') {
      return CONCAT11(extraout_R1_03,3);
    }
    while( true ) {
      bVar19 = (byte)((ulonglong)uVar16 >> 0x20);
      *(char *)((ushort)bVar19 * 0x28 + sVar10 + 0x14) = (char)((ulonglong)uVar16 >> 8);
      bVar19 = bVar19 + 1;
      uVar15 = CONCAT35((int3)((ulonglong)uVar16 >> 0x28),CONCAT14(bVar19,(int)uVar16));
      if ((byte)uVar16 < bVar19) break;
LAB_rom_01555e:
      uVar1 = (undefined6)((ulonglong)uVar15 >> 0x10);
      bVar19 = (byte)uVar15;
      uVar16 = CONCAT62(uVar1,CONCAT11(1,bVar19));
      bVar20 = (byte)((ulonglong)uVar15 >> 0x20);
      if (bVar19 == 2) {
        if ((bVar20 < 2) && (bVar20 != (byte)((ulonglong)uVar15 >> 0x28))) {
          uVar16 = CONCAT62(uVar1,0x202);
        }
      }
      else if (((bVar19 < 3) && (bVar20 == 0)) && ((char)((ulonglong)uVar15 >> 0x10) != '\x02')) {
        uVar16 = CONCAT62(uVar1,CONCAT11(3,bVar19));
      }
    }
    uVar18 = (undefined7)((ulonglong)uVar15 >> 8);
    uVar4 = matrix_dispatch((byte)uVar16 + 1);
    uVar15 = CONCAT71(uVar18,uVar4);
    *(undefined2 *)((short)((uint7)uVar18 >> 0x28) + -8) = 4;
  }
  key_mod_clear();
  key_dispatch_menu();
  if (calc_mode == 'K') {
    return (ushort)(byte)uVar16 << 8;
  }
  uVar15 = CONCAT44((int)((ulonglong)uVar16 >> 0x20),CONCAT22(&input_buf,(short)uVar16));
  strcpy_checked(&input_buf,(char *)0x0);
  input_ptr = (undefined2)((ulonglong)uVar15 >> 0x10);
  menu_index = 0;
  uVar17 = CONCAT44((int)((ulonglong)uVar15 >> 0x20),CONCAT13(0xd1,CONCAT12(0x6c,(short)uVar15)));
  if ((char)uVar15 == '\0') {
    if (_DAT_ram_d14d != '\x04') {
      menu_index = 0;
      return CONCAT11(_DAT_ram_d14d,3);
    }
    memzero(*(undefined **)((short)((ulonglong)uVar15 >> 0x30) + -4),0x1e0);
    return (ushort)extraout_R1_00 << 8;
  }
  stat_fill_cells();
  puVar12 = *(undefined **)((short)(uVar17 >> 0x30) + -4);
  memzero(puVar12,0x1e0);
  uVar17 = uVar17 & 0xffffffff;
  do {
    puVar13 = (undefined2 *)
              (puVar12 + (ushort)(byte)((char)(uVar17 >> 0x20) * '\x04') * 10 + -0x140);
    dec_copy_rev((undefined2 *)(uVar17 >> 0x10),puVar13);
    bVar19 = dec_get_small((ushort *)(uVar17 >> 0x10),puVar13);
    if (bVar19 != 0) {
      return CONCAT11(extraout_R1_01,bVar19);
    }
    append_history(puVar13);
    bVar20 = (char)(uVar17 >> 0x20) + 1;
    bVar19 = (byte)uVar17;
    uVar17 = (ulonglong)CONCAT14(bVar20,(int)uVar17);
  } while (bVar20 < bVar19);
  return (ushort)extraout_R1_02 << 8;
}

/**
 * @brief 输入行编辑子过程
 * @addr 0x15180
 * @module apps
 * @proto undefined2 apps_input_line(void)
 * @confidence strong
 * @note 输入行编辑子过程：检查 0xD111 == 0x4B（矩阵模式）后进入矩阵编辑分支。
 * @tag mode
 */
undefined2 apps_input_line(void)

{
  undefined6 uVar1;
  undefined3 uVar2;
  int cVar3;
  byte bVar4;
  undefined uVar5;
  ushort uVar6;
  undefined extraout_R1;
  byte extraout_R1_00;
  undefined extraout_R1_01;
  byte extraout_R1_02;
  undefined extraout_R1_03;
  undefined2 uVar7;
  undefined extraout_R1_04;
  undefined extraout_R1_05;
  undefined2 *puVar8;
  undefined2 *puVar9;
  short sVar10;
  undefined2 *unaff_ER4;
  short sVar11;
  ushort *puVar12;
  short unaff_ER6;
  undefined *puVar18;
  byte bVar19;
  undefined4 uVar20;
  longlong lVar13;
  undefined8 uVar14;
  ulonglong uVar15;
  undefined8 uVar16;
  undefined7 uVar17;
  
  uVar20 = 0;
  dec_set_uint_small((ushort *)(unaff_ER6 + 0x1e),3);
  sVar11 = unaff_ER6;
  dec_pow_ER10();
  puVar18 = *(undefined **)((short)((uint)uVar20 >> 0x10) + -6);
  lVar13 = (ulonglong)CONCAT42(uVar20,puVar18) << 0x10;
  bVar4 = (puVar18 == (undefined *)0x0) << 6;
  memzero_A0(puVar18);
  uVar6 = kbd_wait_key();
  if ((bVar4 >> 6 & 1) != 1) {
    return uVar6;
  }
  bVar4 = (unaff_ER4 == (undefined2 *)0x0) << 6;
  cVar3 = int_to_dec(unaff_ER4,sVar11);
  if ((bVar4 >> 6 & 1) != 0) {
    bVar4 = apps_key_handler();
    return CONCAT11(extraout_R1,bVar4);
  }
  if (cVar3 == '\x02') {
    uVar6 = apps_matrix_edit(sVar11);
    return uVar6;
  }
  dec_pow_slots(sVar11);
  dec_round(unaff_ER4,sVar11);
  pow_ER4_ER6();
  uVar14 = CONCAT26((short)((ulonglong)lVar13 >> 0x30),CONCAT24(unaff_ER6 + 0x28,(int)lVar13));
  copy_slot4_to_slot3((uintptr_t)0);
  puVar8 = (undefined2 *)((short)((ulonglong)uVar14 >> 0x20) + 10);
  dec_mul_ER4(puVar8);
  dec_cmp_Y_one(unaff_ER4);
  dec_call_1d17e_a(unaff_ER4,puVar8);
  puVar9 = (undefined2 *)((ulonglong)uVar14 >> 0x20);
  puVar8 = puVar9 + 5;
  dec_bin_div(puVar9,puVar8);
  dec_cmp_Y_one((undefined2 *)((ulonglong)uVar14 >> 0x20));
  dec_call_1d17e_a((short)((ulonglong)uVar14 >> 0x20),puVar8);
  dec_copy_a((uintptr_t)0);
  dec_bin_mul((undefined2 *)((ulonglong)uVar14 >> 0x10),(undefined2 *)((ulonglong)uVar14 >> 0x20)
                );
  puVar8 = (undefined2 *)((ulonglong)uVar14 >> 0x10);
  uVar14 = CONCAT62((int6)((ulonglong)uVar14 >> 0x10),puVar8 + 0x14);
  bVar4 = (puVar8 == (undefined2 *)0x0) << 6;
  dec_copy(puVar8 + 0x14,puVar8);
  uVar6 = matrix_mul_add();
  if ((bVar4 >> 6 & 1) != 1) {
    return uVar6;
  }
  if ((calc_mode == 'K') || (key_state_a != '\x01')) {
    sVar11 = (short)((ulonglong)uVar14 >> 0x30);
    if (*(char *)(sVar11 + -7) == '\x01') {
      *(undefined *)(sVar11 + -7) = 2;
    }
    uVar14 = CONCAT71((int7)((ulonglong)uVar14 >> 8),1);
  }
  else {
    dec_cmp_Y_one((undefined2 *)uVar14);
    puVar9 = (undefined2 *)(unaff_ER6 + 10);
    puVar8 = (undefined2 *)dec_div_slot_const(puVar9);
    uVar6 = dec_inc5(puVar8,puVar9);
    if ((char)uVar6 != '\0') {
      return uVar6;
    }
    dec_copy((undefined2 *)uVar14 + 0x14,(undefined2 *)uVar14);
    uVar14 = CONCAT62((int6)((ulonglong)uVar14 >> 0x10),(short)uVar14 + 10);
    copy_ER8_from_ER4();
    puVar9 = (undefined2 *)((ulonglong)uVar14 >> 0x20);
    puVar8 = (undefined2 *)dec_div_slot_const(puVar9);
    uVar5 = (undefined)((ushort)puVar9 >> 8);
    dec_cmp_Y_one(puVar8);
    uVar7 = CONCAT11(uVar5,3);
    dec_set_from_fmt((short)((ulonglong)uVar14 >> 0x20),uVar7);
    dec_round((undefined2 *)((ulonglong)uVar14 >> 0x20),uVar7);
    uVar6 = pow_ER8_ER12();
    if ((char)uVar6 != '\0') {
      return uVar6;
    }
    sVar11 = (short)uVar14;
    uVar14 = CONCAT62((int6)((ulonglong)uVar14 >> 0x10),sVar11 + 0x28);
    copy_from_ER2_to_ER8();
    dec_inc5((undefined2 *)uVar14,sVar11);
    uVar14 = CONCAT71((int7)((ulonglong)uVar14 >> 8),3);
  }
  while( true ) {
    sVar11 = (short)((ulonglong)uVar14 >> 0x30);
    bVar4 = *(byte *)(sVar11 + -7);
    uVar16 = CONCAT53((int5)((ulonglong)uVar14 >> 0x18),CONCAT12(bVar4,(ushort)uVar14));
    uVar2 = (undefined3)((ulonglong)uVar14 >> 0x28);
    if (bVar4 == 3) {
      uVar14 = CONCAT35(uVar2,(uint5)(uint)uVar16);
      do {
        uVar6 = (ushort)(byte)((ulonglong)uVar14 >> 0x20) * 4;
        uVar6 = dec_cmp_ex((undefined2 *, (uintptr_t)0)
                               ((uVar6 & 0xff) * 10 +
                               *(short *)((short)((ulonglong)uVar14 >> 0x30) + -6)),uVar6);
        if ((char)uVar6 != '\0') {
          return uVar6;
        }
        bVar19 = (char)((ulonglong)uVar14 >> 0x20) + 1;
        bVar4 = (byte)uVar14;
        uVar14 = CONCAT35((int3)((ulonglong)uVar14 >> 0x28),CONCAT14(bVar19,(int)uVar14));
      } while (bVar19 < bVar4);
      uVar6 = apps_prompt();
      return uVar6;
    }
    if (3 < bVar4) {
      if ((char)uVar14 != '\0') {
        puVar8 = *(undefined2 **)(sVar11 + -10);
        uVar16 = CONCAT35(uVar2,(uint5)(uint)uVar16);
        do {
          puVar12 = (ushort *)
                    (*(short *)((short)((ulonglong)uVar16 >> 0x30) + -6) +
                    (ushort)(byte)((char)((ulonglong)uVar16 >> 0x20) * '\x04') * 10);
          puVar9 = puVar8;
          dec_mul_ER4(puVar8);
          bVar4 = dec_get_small(puVar12,puVar9);
          if (bVar4 != 0) {
            return CONCAT11(extraout_R1_04,bVar4);
          }
          bVar4 = (byte)uVar16;
          *(byte *)(puVar12 + 10) = '\x03' - bVar4;
          bVar19 = (char)((ulonglong)uVar16 >> 0x20) + 1;
          uVar16 = CONCAT35((int3)((ulonglong)uVar16 >> 0x28),CONCAT14(bVar19,(int)uVar16));
        } while (bVar19 < bVar4);
      }
      bVar4 = (byte)((ulonglong)uVar16 >> 0x10);
      if (4 < bVar4) {
        if (bVar4 != 5) {
          uVar6 = apps_menu_loop();
          return uVar6;
        }
        bVar4 = apps_dialog_loop();
        return CONCAT11(extraout_R1_05,bVar4);
      }
      uVar6 = apps_message();
      return uVar6;
    }
    if (bVar4 == 0) break;
    sVar10 = (ushort)(byte)(4 - (char)uVar14) * 0x28;
    memzero((undefined *)(((ushort)uVar14 & 0xff) * 0x28 + *(short *)(sVar11 + -6)),sVar10);
    uVar6 = (ushort)((ulonglong)uVar16 >> 0x30);
    sVar11 = *(short *)(uVar6 - 6);
    uVar14 = CONCAT53((int5)(((ulonglong)uVar6 << 0x30) >> 0x18),
                      CONCAT12(*(undefined *)(uVar6 - 7),(short)uVar16));
    if ((char)uVar16 != '\0') {
      if ((char)uVar16 != '\x02') goto LAB_rom_01555e;
      uVar7 = dec_cmp((undefined2 *)0xd3b0,sVar10);
      if ((char)uVar7 != '\x01') goto LAB_rom_01555e;
      uVar7 = dec_cmp((undefined2 *)0xd3a6,sVar10);
      if ((char)uVar7 == '\x01') goto LAB_rom_01555e;
      uVar14 = CONCAT26((short)((ulonglong)uVar14 >> 0x30),CONCAT15(1,(int5)uVar14));
      goto LAB_rom_01555e;
    }
    uVar16 = CONCAT62((int6)((ulonglong)uVar14 >> 0x10),0x100);
    if (key_state_a != '\0') {
      return CONCAT11(extraout_R1_03,3);
    }
    while( true ) {
      bVar4 = (byte)((ulonglong)uVar16 >> 0x20);
      *(char *)((ushort)bVar4 * 0x28 + sVar11 + 0x14) = (char)((ulonglong)uVar16 >> 8);
      bVar4 = bVar4 + 1;
      uVar14 = CONCAT35((int3)((ulonglong)uVar16 >> 0x28),CONCAT14(bVar4,(int)uVar16));
      if ((byte)uVar16 < bVar4) break;
LAB_rom_01555e:
      uVar1 = (undefined6)((ulonglong)uVar14 >> 0x10);
      bVar4 = (byte)uVar14;
      uVar16 = CONCAT62(uVar1,CONCAT11(1,bVar4));
      bVar19 = (byte)((ulonglong)uVar14 >> 0x20);
      if (bVar4 == 2) {
        if ((bVar19 < 2) && (bVar19 != (byte)((ulonglong)uVar14 >> 0x28))) {
          uVar16 = CONCAT62(uVar1,0x202);
        }
      }
      else if (((bVar4 < 3) && (bVar19 == 0)) && ((char)((ulonglong)uVar14 >> 0x10) != '\x02')) {
        uVar16 = CONCAT62(uVar1,CONCAT11(3,bVar4));
      }
    }
    uVar17 = (undefined7)((ulonglong)uVar14 >> 8);
    uVar5 = matrix_dispatch((byte)uVar16 + 1);
    uVar14 = CONCAT71(uVar17,uVar5);
    *(undefined2 *)((short)((uint7)uVar17 >> 0x28) + -8) = 4;
  }
  key_mod_clear();
  key_dispatch_menu();
  if (calc_mode == 'K') {
    return (ushort)(byte)uVar16 << 8;
  }
  uVar14 = CONCAT44((int)((ulonglong)uVar16 >> 0x20),CONCAT22(&input_buf,(short)uVar16));
  strcpy_checked(&input_buf,(char *)0x0);
  input_ptr = (undefined2)((ulonglong)uVar14 >> 0x10);
  menu_index = 0;
  uVar15 = CONCAT44((int)((ulonglong)uVar14 >> 0x20),CONCAT13(0xd1,CONCAT12(0x6c,(short)uVar14)));
  if ((char)uVar14 == '\0') {
    if (_DAT_ram_d14d != '\x04') {
      menu_index = 0;
      return CONCAT11(_DAT_ram_d14d,3);
    }
    memzero(*(undefined **)((short)((ulonglong)uVar14 >> 0x30) + -4),0x1e0);
    return (ushort)extraout_R1_00 << 8;
  }
  stat_fill_cells();
  puVar18 = *(undefined **)((short)(uVar15 >> 0x30) + -4);
  memzero(puVar18,0x1e0);
  uVar15 = uVar15 & 0xffffffff;
  do {
    puVar8 = (undefined2 *)(puVar18 + (ushort)(byte)((char)(uVar15 >> 0x20) * '\x04') * 10 + -0x140)
    ;
    dec_copy_rev((undefined2 *)(uVar15 >> 0x10),puVar8);
    bVar4 = dec_get_small((ushort *)(uVar15 >> 0x10),puVar8);
    if (bVar4 != 0) {
      return CONCAT11(extraout_R1_01,bVar4);
    }
    append_history(puVar8);
    bVar19 = (char)(uVar15 >> 0x20) + 1;
    bVar4 = (byte)uVar15;
    uVar15 = (ulonglong)CONCAT14(bVar19,(int)uVar15);
  } while (bVar19 < bVar4);
  return (ushort)extraout_R1_02 << 8;
}

/**
 * @brief 按键处理子过程
 * @addr 0x1532E
 * @module apps
 * @proto undefined2 apps_key_handler(void)
 * @confidence strong
 * @note 按键处理子过程：调用 0x152FA（乘方）/0x1513C（比较）等十进制运算后交给 0x15628。
 * @tag mode
 */
undefined2 apps_key_handler(void)

{
  byte bVar1;
  int bVar2;
  undefined uVar3;
  undefined2 uVar4;
  short sVar5;
  ushort uVar6;
  undefined2 *puVar7;
  short sVar8;
  ushort *puVar9;
  short unaff_ER6;
  undefined *puVar10;
  undefined2 *puVar11;
  undefined8 in_QR8;
  longlong lVar12;
  undefined8 uVar13;
  undefined3 uVar18;
  ulonglong uVar14;
  undefined8 uVar15;
  undefined6 uVar17;
  undefined7 uVar16;
  
  uVar13 = CONCAT26((short)((ulonglong)in_QR8 >> 0x30),CONCAT24(unaff_ER6 + 0x32,(int)in_QR8));
  copy_to_slot3((uintptr_t)0);
  uVar4 = 0x1b8a;
  dec_pow_ER10();
  dec_call_1d17e_a((short)((ulonglong)uVar13 >> 0x10),uVar4);
  matrix_div_add();
  bVar1 = dec_inc5((undefined2 *)((ulonglong)uVar13 >> 0x10),uVar4);
  if (bVar1 != 0) {
    return bVar1;
  }
  lVar12 = (ulonglong)
           CONCAT42((int)((ulonglong)uVar13 >> 0x20),(short)((ulonglong)uVar13 >> 0x10) + 0x28) <<
           0x10;
  uVar4 = (undefined2)((ulonglong)uVar13 >> 0x20);
  copy_to_slot3((uintptr_t)0);
  dec_cmp_Y_one((undefined2 *)((ulonglong)lVar12 >> 0x10));
  sVar8 = (short)((ulonglong)lVar12 >> 0x10);
  bVar1 = (sVar8 == 0) << 6;
  dec_call_1d17e_a(sVar8,uVar4);
  bVar2 = matrix_mul_add();
  if ((bVar1 >> 6 & 1) != 1) {
    return bVar2;
  }
  uVar13 = CONCAT71((int7)((ulonglong)lVar12 >> 8),2);
  puVar11 = (undefined2 *)((ulonglong)lVar12 >> 0x20);
  bVar1 = (puVar11 == (undefined2 *)0x0) << 6;
  int_to_dec(puVar11,uVar4);
  if ((bVar1 >> 6 & 1) != 0) {
    uVar13 = CONCAT71((int7)((ulonglong)uVar13 >> 8),1);
  }
  while( true ) {
    sVar8 = (short)((ulonglong)uVar13 >> 0x30);
    bVar1 = *(byte *)(sVar8 + -7);
    uVar15 = CONCAT53((int5)((ulonglong)uVar13 >> 0x18),CONCAT12(bVar1,(ushort)uVar13));
    uVar18 = (undefined3)((ulonglong)uVar13 >> 0x28);
    if (bVar1 == 3) {
      uVar13 = CONCAT35(uVar18,(uint5)(uint)uVar15);
      do {
        uVar6 = (ushort)(byte)((ulonglong)uVar13 >> 0x20) * 4;
        bVar1 = dec_cmp_ex((undefined2 *, (uintptr_t)0)
                               ((uVar6 & 0xff) * 10 +
                               *(short *)((short)((ulonglong)uVar13 >> 0x30) + -6)),uVar6);
        if (bVar1 != 0) {
          return bVar1;
        }
        bVar2 = (char)((ulonglong)uVar13 >> 0x20) + 1;
        bVar1 = (byte)uVar13;
        uVar13 = CONCAT35((int3)((ulonglong)uVar13 >> 0x28),CONCAT14(bVar2,(int)uVar13));
      } while (bVar2 < bVar1);
      bVar1 = apps_prompt();
      return bVar1;
    }
    if (3 < bVar1) {
      if ((char)uVar13 != '\0') {
        puVar11 = *(undefined2 **)(sVar8 + -10);
        uVar15 = CONCAT35(uVar18,(uint5)(uint)uVar15);
        do {
          puVar9 = (ushort *)
                   (*(short *)((short)((ulonglong)uVar15 >> 0x30) + -6) +
                   (ushort)(byte)((char)((ulonglong)uVar15 >> 0x20) * '\x04') * 10);
          puVar7 = puVar11;
          dec_mul_ER4(puVar11);
          bVar1 = dec_get_small(puVar9,puVar7);
          if (bVar1 != 0) {
            return bVar1;
          }
          bVar1 = (byte)uVar15;
          *(byte *)(puVar9 + 10) = '\x03' - bVar1;
          bVar2 = (char)((ulonglong)uVar15 >> 0x20) + 1;
          uVar15 = CONCAT35((int3)((ulonglong)uVar15 >> 0x28),CONCAT14(bVar2,(int)uVar15));
        } while (bVar2 < bVar1);
      }
      bVar1 = (byte)((ulonglong)uVar15 >> 0x10);
      if (4 < bVar1) {
        if (bVar1 != 5) {
          uVar6 = apps_menu_loop();
          return (byte)uVar6;
        }
        bVar1 = apps_dialog_loop();
        return bVar1;
      }
      bVar1 = apps_message();
      return bVar1;
    }
    if (bVar1 == 0) break;
    sVar5 = (ushort)(byte)(4 - (char)uVar13) * 0x28;
    memzero((undefined *)(((ushort)uVar13 & 0xff) * 0x28 + *(short *)(sVar8 + -6)),sVar5);
    uVar6 = (ushort)((ulonglong)uVar15 >> 0x30);
    sVar8 = *(short *)(uVar6 - 6);
    uVar13 = CONCAT53((int5)(((ulonglong)uVar6 << 0x30) >> 0x18),
                      CONCAT12(*(undefined *)(uVar6 - 7),(short)uVar15));
    if ((char)uVar15 != '\0') {
      if ((char)uVar15 != '\x02') goto LAB_rom_01555e;
      uVar4 = dec_cmp((undefined2 *)0xd3b0,sVar5);
      if ((char)uVar4 != '\x01') goto LAB_rom_01555e;
      uVar4 = dec_cmp((undefined2 *)0xd3a6,sVar5);
      if ((char)uVar4 == '\x01') goto LAB_rom_01555e;
      uVar13 = CONCAT26((short)((ulonglong)uVar13 >> 0x30),CONCAT15(1,(int5)uVar13));
      goto LAB_rom_01555e;
    }
    uVar15 = CONCAT62((int6)((ulonglong)uVar13 >> 0x10),0x100);
    if (key_state_a != '\0') {
      return 3;
    }
    while( true ) {
      bVar1 = (byte)((ulonglong)uVar15 >> 0x20);
      *(char *)((ushort)bVar1 * 0x28 + sVar8 + 0x14) = (char)((ulonglong)uVar15 >> 8);
      bVar1 = bVar1 + 1;
      uVar13 = CONCAT35((int3)((ulonglong)uVar15 >> 0x28),CONCAT14(bVar1,(int)uVar15));
      if ((byte)uVar15 < bVar1) break;
LAB_rom_01555e:
      uVar17 = (undefined6)((ulonglong)uVar13 >> 0x10);
      bVar1 = (byte)uVar13;
      uVar15 = CONCAT62(uVar17,CONCAT11(1,bVar1));
      bVar2 = (byte)((ulonglong)uVar13 >> 0x20);
      if (bVar1 == 2) {
        if ((bVar2 < 2) && (bVar2 != (byte)((ulonglong)uVar13 >> 0x28))) {
          uVar15 = CONCAT62(uVar17,0x202);
        }
      }
      else if (((bVar1 < 3) && (bVar2 == 0)) && ((char)((ulonglong)uVar13 >> 0x10) != '\x02')) {
        uVar15 = CONCAT62(uVar17,CONCAT11(3,bVar1));
      }
    }
    uVar16 = (undefined7)((ulonglong)uVar13 >> 8);
    uVar3 = matrix_dispatch((byte)uVar15 + 1);
    uVar13 = CONCAT71(uVar16,uVar3);
    *(undefined2 *)((short)((uint7)uVar16 >> 0x28) + -8) = 4;
  }
  key_mod_clear();
  key_dispatch_menu();
  if (calc_mode == 'K') {
    return 0;
  }
  uVar13 = CONCAT44((int)((ulonglong)uVar15 >> 0x20),CONCAT22(&input_buf,(short)uVar15));
  strcpy_checked(&input_buf,(char *)0x0);
  input_ptr = (undefined2)((ulonglong)uVar13 >> 0x10);
  menu_index = 0;
  uVar14 = CONCAT44((int)((ulonglong)uVar13 >> 0x20),CONCAT13(0xd1,CONCAT12(0x6c,(short)uVar13)));
  if ((char)uVar13 == '\0') {
    if (_DAT_ram_d14d != '\x04') {
      menu_index = 0;
      return 3;
    }
    memzero(*(undefined **)((short)((ulonglong)uVar13 >> 0x30) + -4),0x1e0);
    return 0;
  }
  stat_fill_cells();
  puVar10 = *(undefined **)((short)(uVar14 >> 0x30) + -4);
  memzero(puVar10,0x1e0);
  uVar14 = uVar14 & 0xffffffff;
  do {
    puVar11 = (undefined2 *)
              (puVar10 + (ushort)(byte)((char)(uVar14 >> 0x20) * '\x04') * 10 + -0x140);
    dec_copy_rev((undefined2 *)(uVar14 >> 0x10),puVar11);
    bVar1 = dec_get_small((ushort *)(uVar14 >> 0x10),puVar11);
    if (bVar1 != 0) {
      return bVar1;
    }
    append_history(puVar11);
    bVar2 = (char)(uVar14 >> 0x20) + 1;
    bVar1 = (byte)uVar14;
    uVar14 = (ulonglong)CONCAT14(bVar2,(int)uVar14);
  } while (bVar2 < bVar1);
  return 0;
}

/**
 * @brief 矩阵模式编辑子过程（同样检查 0xD111 == 0x4B），被 0x14FF8/0x151…
 * @addr 0x15396
 * @module apps
 * @proto undefined2 apps_matrix_edit(undefined2 arg)
 * @confidence strong
 * @note 矩阵模式编辑子过程（同样检查 0xD111 == 0x4B），被 0x14FF8/0x15180 调用。
 * @tag mode
 */
undefined2 apps_matrix_edit(undefined2 arg)

{
  char cVar1;
  undefined uVar2;
  undefined2 uVar3;
  ushort uVar4;
  byte extraout_R1;
  undefined extraout_R1_00;
  byte extraout_R1_01;
  undefined extraout_R1_02;
  undefined extraout_R1_03;
  undefined extraout_R1_04;
  undefined2 uVar5;
  short sVar6;
  undefined2 *puVar7;
  undefined2 *unaff_ER4;
  short sVar8;
  ushort *puVar9;
  undefined2 *unaff_ER6;
  undefined *puVar10;
  undefined2 *puVar11;
  byte bVar16;
  byte bVar18;
  undefined8 in_QR8;
  undefined8 uVar12;
  undefined3 uVar19;
  ulonglong uVar13;
  undefined8 uVar14;
  undefined6 uVar17;
  undefined7 uVar15;
  
  uVar12 = CONCAT26((short)((ulonglong)in_QR8 >> 0x30),(uint6)(uint)in_QR8);
  dec_to_special(unaff_ER6 + 10,arg);
  dec_pow_const_1b76();
  dec_pow_slots(arg);
  dec_inc5(unaff_ER4,arg);
  dec_round(unaff_ER4,arg);
  pow_ER4_ER6();
  puVar11 = unaff_ER6 + 0x19;
  uVar12 = CONCAT26((short)((ulonglong)uVar12 >> 0x30),CONCAT24(puVar11,(int)uVar12));
  dec_add_or_round(unaff_ER4,puVar11);
  uVar5 = CONCAT11((char)((ushort)puVar11 >> 8),1);
  dec_set_from_fmt((short)uVar12,uVar5);
  uVar3 = dec_cmp((undefined2 *)((ulonglong)uVar12 >> 0x20),uVar5);
  *(char *)((short)((ulonglong)uVar12 >> 0x30) + -2) = (char)uVar3;
  if ((char)uVar3 == '\x02') {
    dec_inc5((undefined2 *)uVar12,uVar5);
  }
  puVar11 = (undefined2 *)CONCAT11((char)((ushort)uVar5 >> 8),5);
  cVar1 = decc_op(unaff_ER4,puVar11);
  if (cVar1 != '\0') {
    dec_to_special(unaff_ER4,puVar11);
    dec_cmp_Y_one(unaff_ER4);
    puVar11 = unaff_ER6;
    dec_cmp_special(unaff_ER4,unaff_ER6);
    if (*(char *)((short)((ulonglong)uVar12 >> 0x30) + -2) == '\x02') {
      dec_inc5(unaff_ER4,puVar11);
    }
  }
  dec_inc5(unaff_ER6 + 0xf,puVar11);
  uVar12 = CONCAT26((short)((ulonglong)uVar12 >> 0x30),CONCAT24(unaff_ER6 + 0x14,(int)uVar12));
  dec_inc5(unaff_ER6 + 0x14,puVar11);
  dec_round((undefined2 *)((ulonglong)uVar12 >> 0x20),puVar11);
  dec_pow_const_1b76();
  pow_ER12_ER2();
  uVar12 = CONCAT62((int6)((ulonglong)uVar12 >> 0x10),unaff_ER6 + 10);
  bVar16 = (unaff_ER6 + 10 == (undefined2 *)0x0) << 6;
  dec_copy_a((uintptr_t)0);
  uVar4 = matrix_rhs_mul();
  if ((bVar16 >> 6 & 1) == 0) {
    return uVar4;
  }
  matrix_div_28();
  uVar4 = matrix_rhs_mul();
  if ((bVar16 >> 6 & 1) == 0) {
    return uVar4;
  }
  matrix_div_28();
  bVar16 = ((undefined2 *)uVar12 == (undefined2 *)0x0) << 6;
  dec_bin_div((undefined2 *)((ulonglong)uVar12 >> 0x10),(undefined2 *)uVar12);
  uVar4 = matrix_rhs_mul();
  if ((bVar16 >> 6 & 1) == 0) {
    return uVar4;
  }
  uVar12 = CONCAT71((int7)((ulonglong)uVar12 >> 8),3);
  while( true ) {
    sVar8 = (short)((ulonglong)uVar12 >> 0x30);
    bVar16 = *(byte *)(sVar8 + -7);
    uVar14 = CONCAT53((int5)((ulonglong)uVar12 >> 0x18),CONCAT12(bVar16,(ushort)uVar12));
    uVar19 = (undefined3)((ulonglong)uVar12 >> 0x28);
    if (bVar16 == 3) {
      uVar12 = CONCAT35(uVar19,(uint5)(uint)uVar14);
      do {
        uVar4 = (ushort)(byte)((ulonglong)uVar12 >> 0x20) * 4;
        uVar4 = dec_cmp_ex((undefined2 *, (uintptr_t)0)
                               ((uVar4 & 0xff) * 10 +
                               *(short *)((short)((ulonglong)uVar12 >> 0x30) + -6)),uVar4);
        if ((char)uVar4 != '\0') {
          return uVar4;
        }
        bVar18 = (char)((ulonglong)uVar12 >> 0x20) + 1;
        bVar16 = (byte)uVar12;
        uVar12 = CONCAT35((int3)((ulonglong)uVar12 >> 0x28),CONCAT14(bVar18,(int)uVar12));
      } while (bVar18 < bVar16);
      uVar4 = apps_prompt();
      return uVar4;
    }
    if (3 < bVar16) {
      if ((char)uVar12 != '\0') {
        puVar11 = *(undefined2 **)(sVar8 + -10);
        uVar14 = CONCAT35(uVar19,(uint5)(uint)uVar14);
        do {
          puVar9 = (ushort *)
                   (*(short *)((short)((ulonglong)uVar14 >> 0x30) + -6) +
                   (ushort)(byte)((char)((ulonglong)uVar14 >> 0x20) * '\x04') * 10);
          puVar7 = puVar11;
          dec_mul_ER4(puVar11);
          bVar16 = dec_get_small(puVar9,puVar7);
          if (bVar16 != 0) {
            return CONCAT11(extraout_R1_03,bVar16);
          }
          bVar16 = (byte)uVar14;
          *(byte *)(puVar9 + 10) = '\x03' - bVar16;
          bVar18 = (char)((ulonglong)uVar14 >> 0x20) + 1;
          uVar14 = CONCAT35((int3)((ulonglong)uVar14 >> 0x28),CONCAT14(bVar18,(int)uVar14));
        } while (bVar18 < bVar16);
      }
      bVar16 = (byte)((ulonglong)uVar14 >> 0x10);
      if (4 < bVar16) {
        if (bVar16 != 5) {
          uVar4 = apps_menu_loop();
          return uVar4;
        }
        bVar16 = apps_dialog_loop();
        return CONCAT11(extraout_R1_04,bVar16);
      }
      uVar4 = apps_message();
      return uVar4;
    }
    if (bVar16 == 0) break;
    sVar6 = (ushort)(byte)(4 - (char)uVar12) * 0x28;
    memzero((undefined *)(((ushort)uVar12 & 0xff) * 0x28 + *(short *)(sVar8 + -6)),sVar6);
    uVar4 = (ushort)((ulonglong)uVar14 >> 0x30);
    sVar8 = *(short *)(uVar4 - 6);
    uVar12 = CONCAT53((int5)(((ulonglong)uVar4 << 0x30) >> 0x18),
                      CONCAT12(*(undefined *)(uVar4 - 7),(short)uVar14));
    if ((char)uVar14 != '\0') {
      if ((char)uVar14 != '\x02') goto LAB_rom_01555e;
      uVar3 = dec_cmp((undefined2 *)0xd3b0,sVar6);
      if ((char)uVar3 != '\x01') goto LAB_rom_01555e;
      uVar3 = dec_cmp((undefined2 *)0xd3a6,sVar6);
      if ((char)uVar3 == '\x01') goto LAB_rom_01555e;
      uVar12 = CONCAT26((short)((ulonglong)uVar12 >> 0x30),CONCAT15(1,(int5)uVar12));
      goto LAB_rom_01555e;
    }
    uVar14 = CONCAT62((int6)((ulonglong)uVar12 >> 0x10),0x100);
    if (key_state_a != '\0') {
      return CONCAT11(extraout_R1_02,3);
    }
    while( true ) {
      bVar16 = (byte)((ulonglong)uVar14 >> 0x20);
      *(char *)((ushort)bVar16 * 0x28 + sVar8 + 0x14) = (char)((ulonglong)uVar14 >> 8);
      bVar16 = bVar16 + 1;
      uVar12 = CONCAT35((int3)((ulonglong)uVar14 >> 0x28),CONCAT14(bVar16,(int)uVar14));
      if ((byte)uVar14 < bVar16) break;
LAB_rom_01555e:
      uVar17 = (undefined6)((ulonglong)uVar12 >> 0x10);
      bVar16 = (byte)uVar12;
      uVar14 = CONCAT62(uVar17,CONCAT11(1,bVar16));
      bVar18 = (byte)((ulonglong)uVar12 >> 0x20);
      if (bVar16 == 2) {
        if ((bVar18 < 2) && (bVar18 != (byte)((ulonglong)uVar12 >> 0x28))) {
          uVar14 = CONCAT62(uVar17,0x202);
        }
      }
      else if (((bVar16 < 3) && (bVar18 == 0)) && ((char)((ulonglong)uVar12 >> 0x10) != '\x02')) {
        uVar14 = CONCAT62(uVar17,CONCAT11(3,bVar16));
      }
    }
    uVar15 = (undefined7)((ulonglong)uVar12 >> 8);
    uVar2 = matrix_dispatch((byte)uVar14 + 1);
    uVar12 = CONCAT71(uVar15,uVar2);
    *(undefined2 *)((short)((uint7)uVar15 >> 0x28) + -8) = 4;
  }
  key_mod_clear();
  key_dispatch_menu();
  if (calc_mode == 'K') {
    return (ushort)(byte)uVar14 << 8;
  }
  uVar12 = CONCAT44((int)((ulonglong)uVar14 >> 0x20),CONCAT22(&input_buf,(short)uVar14));
  strcpy_checked(&input_buf,(char *)0x0);
  input_ptr = (undefined2)((ulonglong)uVar12 >> 0x10);
  menu_index = 0;
  uVar13 = CONCAT44((int)((ulonglong)uVar12 >> 0x20),CONCAT13(0xd1,CONCAT12(0x6c,(short)uVar12)));
  if ((char)uVar12 == '\0') {
    if (_DAT_ram_d14d != '\x04') {
      menu_index = 0;
      return CONCAT11(_DAT_ram_d14d,3);
    }
    memzero(*(undefined **)((short)((ulonglong)uVar12 >> 0x30) + -4),0x1e0);
    return (ushort)extraout_R1 << 8;
  }
  stat_fill_cells();
  puVar10 = *(undefined **)((short)(uVar13 >> 0x30) + -4);
  memzero(puVar10,0x1e0);
  uVar13 = uVar13 & 0xffffffff;
  do {
    puVar11 = (undefined2 *)
              (puVar10 + (ushort)(byte)((char)(uVar13 >> 0x20) * '\x04') * 10 + -0x140);
    dec_copy_rev((undefined2 *)(uVar13 >> 0x10),puVar11);
    bVar16 = dec_get_small((ushort *)(uVar13 >> 0x10),puVar11);
    if (bVar16 != 0) {
      return CONCAT11(extraout_R1_00,bVar16);
    }
    append_history(puVar11);
    bVar18 = (char)(uVar13 >> 0x20) + 1;
    bVar16 = (byte)uVar13;
    uVar13 = (ulonglong)CONCAT14(bVar18,(int)uVar13);
  } while (bVar18 < bVar16);
  return (ushort)extraout_R1_01 << 8;
}

