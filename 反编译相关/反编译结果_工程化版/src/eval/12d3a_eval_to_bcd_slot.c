/*
 * 表达式求值 / 12d3a_eval_to_bcd_slot.c
 * 地址范围: 0x12D3A - 0x134F8
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 把求值结果（0x1D7B0）写回调用块槽（0x129F6 准备）
 * @addr 0x12D3A
 * @module eval
 * @proto void eval_to_bcd_slot(undefined2 v)
 * @confidence likely
 * @note 把求值结果（0x1D7B0）写回调用块槽（0x129F6 准备）。
 * @tag eval
 */
int eval_to_bcd_slot(undefined2 v)

{
  undefined uVar1;
  undefined extraout_R1;
  undefined *puVar2;
  undefined auStack_c [8];
  
  puVar2 = auStack_c;
  table_cell_calc();
  uVar1 = dec_cmp_ex((undefined2 *)(puVar2 + -0x46),v);
  dec_copy(*(undefined2 **)(puVar2 + -2),(undefined2 *)(puVar2 + -0x46));
  return CONCAT11(extraout_R1,uVar1);
}

/**
 * @brief 表格变量初始化
 * @addr 0x130E6
 * @module eval
 * @proto undefined2 table_init_var(undefined2 er0)
 * @confidence likely
 * @note 表格变量初始化：把 4 组 BCD 置入 0xD392 缓冲，比较为 1 时返回 3，否则做格式换算并调用 0x131CC
 *       打开表格行。
 * @tag app
 */
undefined2 table_init_var(undefined2 er0)

{
  char cVar1;
  undefined2 *puVar2;
  undefined2 uVar3;
  ushort uVar4;
  undefined2 *puVar5;
  undefined8 uVar6;
  undefined2 auStack_3e [29];
  
  puVar2 = auStack_3e;
  screen_mode_blank(er0);
  uVar6 = CONCAT62(CONCAT42(CONCAT22(puVar2,puVar2 + 5),puVar2 + 10),puVar2 + 0xf);
  puVar2 = dec_copy_ret((undefined2 *)&stat_data,puVar2);
  puVar2 = dec_copy_ret(puVar2 + 5,(undefined2 *)((ulonglong)uVar6 >> 0x20));
  puVar5 = (undefined2 *)((ulonglong)uVar6 >> 0x10);
  dec_copy_ret(puVar2 + 5,puVar5);
  cVar1 = is_edit_locked();
  if (cVar1 != '\x01') {
    dec_normalize2((short)((ulonglong)uVar6 >> 0x30),puVar5);
    dec_normalize2((short)((ulonglong)uVar6 >> 0x20),puVar5);
    dec_normalize2((short)((ulonglong)uVar6 >> 0x10),puVar5);
  }
  dec_set_uint_small((ushort *)((short)((ulonglong)uVar6 >> 0x30) + 0x28),4);
  puVar2 = (undefined2 *)((ulonglong)uVar6 >> 0x30);
  dec_bin_pow(puVar2 + 0x14,puVar2);
  dec_copy((undefined2 *)uVar6,(undefined2 *)((ulonglong)uVar6 >> 0x20));
  dec_bin_pow((undefined2 *)uVar6,(undefined2 *)uVar6);
  dec_bin_and((undefined2 *)uVar6,(undefined2 *)((short)((ulonglong)uVar6 >> 0x30) + 0x28));
  puVar2 = (undefined2 *)uVar6;
  dec_bin_mul((undefined2 *)((ulonglong)uVar6 >> 0x10),puVar2);
  dec_cmp_ex((undefined2 *)((ulonglong)uVar6 >> 0x10),puVar2);
  uVar3 = dec_bin_init((undefined2 *)((ulonglong)uVar6 >> 0x10),puVar2);
  if ((char)uVar3 == '\0') {
    dec_set_uint_small((ushort *)((short)((ulonglong)uVar6 >> 0x30) + 0x28),2);
    puVar2 = (undefined2 *)((ulonglong)uVar6 >> 0x30);
    dec_bin_pow(puVar2,puVar2 + 0x14);
    dec_bin_and((undefined2 *)((ulonglong)uVar6 >> 0x20),(undefined2 *)((ulonglong)uVar6 >> 0x30)
                  );
    uVar3 = (undefined2)((ulonglong)uVar6 >> 0x30);
    dec_inc5((undefined2 *)((ulonglong)uVar6 >> 0x20),uVar3);
    dec_cmp_ex((undefined2 *)((ulonglong)uVar6 >> 0x20),uVar3);
    uVar3 = dec_bin_init((undefined2 *)((ulonglong)uVar6 >> 0x20),uVar3);
    if ((char)uVar3 == '\0') {
      table_open((undefined2 *)((ulonglong)uVar6 >> 0x20),0x101);
      uVar4 = table_open((undefined2 *)((ulonglong)uVar6 >> 0x10),0x101);
      return uVar4 & 0xff00;
    }
  }
  return CONCAT11((char)((ushort)uVar3 >> 8),3);
}

/**
 * @brief 打开表格
 * @addr 0x131CC
 * @module eval
 * @proto void table_open(undefined2* a, char flag)
 * @confidence likely
 * @note 打开表格：初始化行缓冲（0xD784 或 0xD6B2），必要时清历史并调用 0xEA80载入行数据。
 * @tag app
 */
int table_open(undefined2* a, char flag)

{
  byte extraout_R1;
  undefined2 *puVar1;
  undefined *puVar2;
  longlong lVar3;
  undefined2 auStack_20 [14];
  undefined8 uVar4;
  
  lVar3 = (ulonglong)CONCAT42((int)((ZEXT28(auStack_20) << 0x30) >> 0x20),flag) << 0x10;
  dec_copy(auStack_20,a);
  dec_set_uint_small((ushort *)((short)((ulonglong)lVar3 >> 0x30) + 10),0);
  if ((char)((ulonglong)lVar3 >> 0x10) == '\0') {
    puVar2 = (undefined *)0xd784;
  }
  else {
    puVar2 = &app_work_area;
  }
  uVar4 = CONCAT62((int6)((ulonglong)lVar3 >> 0x10),puVar2);
  if ((char)((ulonglong)lVar3 >> 0x18) == '\0') {
    key_mod_clear();
    key_dispatch_menu();
    uVar4 = CONCAT26((short)((ulonglong)uVar4 >> 0x30),CONCAT24(&input_buf,(int)uVar4));
    strcpy_checked(&input_buf,(char *)0x0);
    input_ptr = (undefined2)((ulonglong)uVar4 >> 0x20);
    menu_index = 0;
    memzero((undefined *)uVar4,0xfa);
  }
  puVar1 = (undefined2 *)((ulonglong)uVar4 >> 0x30);
  dec_copy_rev((undefined2 *)0xd16c,puVar1);
  append_history(puVar1);
  return (ushort)extraout_R1 << 8;
}

/**
 * @brief 把 0xD392 缓冲的 BCD 装入行结构，按 0xD112 选择操作数列，比较后调用 0…
 * @addr 0x1323A
 * @module eval
 * @proto byte table_load_row(undefined2 er0)
 * @confidence strong
 * @note 把 0xD392 缓冲的 BCD 装入行结构，按 0xD112 选择操作数列，比较后调用 0xEA80 载入表格行；0
 *       为成功、3 为空行。
 * @tag app
 */
byte table_load_row(undefined2 er0)

{
  char cVar1;
  byte bVar2;
  undefined2 *puVar3;
  undefined2 uVar4;
  undefined2 *puVar5;
  longlong lVar6;
  undefined4 uVar7;
  undefined2 local_2a [19];
  
  puVar3 = local_2a;
  screen_mode_blank(er0);
  lVar6 = (ulonglong)CONCAT42(CONCAT22(puVar3,puVar3 + 5),puVar3 + 10) << 0x10;
  if (sub_mode == '\x02') {
    puVar3 = dec_copy_ret((undefined2 *)&stat_data,puVar3 + 5);
    puVar5 = (undefined2 *)((ulonglong)lVar6 >> 0x30);
  }
  else {
    puVar3 = dec_copy_ret((undefined2 *)&stat_data,puVar3);
    puVar5 = (undefined2 *)((ulonglong)lVar6 >> 0x20);
  }
  puVar3 = dec_copy_ret(puVar3 + 5,puVar5);
  puVar5 = (undefined2 *)((ulonglong)lVar6 >> 0x10);
  dec_copy_ret(puVar3 + 5,puVar5);
  cVar1 = is_edit_locked();
  if (cVar1 != '\x01') {
    dec_normalize2((short)((ulonglong)lVar6 >> 0x30),puVar5);
    dec_normalize2((short)((ulonglong)lVar6 >> 0x20),puVar5);
    dec_normalize2((short)((ulonglong)lVar6 >> 0x10),puVar5);
  }
  puVar5 = (undefined2 *)((ulonglong)lVar6 >> 0x30);
  puVar3 = (undefined2 *)((ulonglong)lVar6 >> 0x10);
  if (((((*(byte *)puVar5 & 0x20) == 0) && ((*(byte *)puVar5 & 0x80) == 0)) &&
      ((*(byte *)puVar3 & 0x20) == 0)) && ((*(byte *)puVar3 & 0x80) == 0)) {
    uVar4 = puVar5[4];
    bVar2 = (byte)((ushort)uVar4 >> 8);
    if (4 < bVar2) {
      uVar4 = CONCAT11(bVar2 - 5,(char)uVar4);
    }
    if ((char)((ushort)uVar4 >> 8) == '\0') {
      if ((byte)uVar4 < 0x51) {
        uVar4 = puVar3[4];
        bVar2 = (byte)((ushort)uVar4 >> 8);
        if (4 < bVar2) {
          uVar4 = CONCAT11(bVar2 - 5,(char)uVar4);
        }
        if (((char)((ushort)uVar4 >> 8) == '\0') && ((byte)uVar4 < 0x51)) goto LAB_rom_0132e2;
      }
    }
    else if (0x4f < (byte)uVar4) {
      uVar4 = puVar3[4];
      bVar2 = (byte)((ushort)uVar4 >> 8);
      if (4 < bVar2) {
        uVar4 = CONCAT11(bVar2 - 5,(char)uVar4);
      }
      if (((char)((ushort)uVar4 >> 8) != '\0') && (0x4f < (byte)uVar4)) {
LAB_rom_0132e2:
        dec_bin_and(puVar5,(undefined2 *)((ulonglong)lVar6 >> 0x20));
        puVar3 = (undefined2 *)((ulonglong)lVar6 >> 0x10);
        dec_bin_pow((undefined2 *)((ulonglong)lVar6 >> 0x30),puVar3);
        uVar7 = (undefined4)((ulonglong)lVar6 >> 0x20);
        goto LAB_rom_013304;
      }
    }
  }
  dec_bin_pow(puVar5,puVar3);
  uVar7 = (undefined4)((ulonglong)lVar6 >> 0x20);
  puVar3 = (undefined2 *)((ulonglong)lVar6 >> 0x20);
  dec_bin_and((undefined2 *)((ulonglong)lVar6 >> 0x30),puVar3);
LAB_rom_013304:
  bVar2 = dec_get_small((ushort *)((uint)uVar7 >> 0x10),puVar3);
  if (bVar2 == 0) {
    dec_bin_init((undefined2 *)((uint)uVar7 >> 0x10),puVar3);
    if (*(char *)((uint)uVar7 >> 0x10) == '\0') {
      bVar2 = 3;
    }
    else {
      dec_set_uint_small((ushort *)uVar7,0);
      key_mod_clear();
      key_dispatch_menu();
      lVar6 = (ulonglong)CONCAT42(uVar7,&input_buf) << 0x10;
      strcpy_checked(&input_buf,(char *)0x0);
      input_ptr = (undefined2)((ulonglong)lVar6 >> 0x10);
      menu_index = 0;
      memzero(&app_work_area,0x10e);
      puVar3 = (undefined2 *)((ulonglong)lVar6 >> 0x30);
      dec_copy_rev((undefined2 *)0xd16c,puVar3);
      append_history(puVar3);
      bVar2 = 0;
    }
  }
  return bVar2;
}

/**
 * @brief 矩阵行操作（增删行）
 * @addr 0x13494
 * @module eval
 * @proto int apps_mat_row(void)
 * @confidence likely
 * @note 矩阵行操作（增删行）。
 * @tag matrix
 */
int apps_mat_row(uintptr_t _a2, int _a1)

{
  undefined2 *puVar1;
  undefined2 *puVar2;
  short sVar3;
  char cVar4;
  byte bVar5;
  
  cVar4 = (char)((ushort)_a1 >> 8);
  bVar5 = cVar4 - 1;
  puVar2 = (undefined2 *)&app_work_area;
  puVar1 = (undefined2 *)((ushort)bVar5 * 0x28 + -0x28ae);
  while( true ) {
    puVar2 = puVar2 + 5;
    puVar1 = dec_copy_ret(puVar1,puVar2);
    if (bVar5 == 0) break;
    bVar5 = bVar5 - 1;
    puVar1 = puVar1 + -0x14;
  }
  bVar5 = (byte)_a1 >> 6;
  if (bVar5 != 0) {
    sVar3 = -0x2944;
    cVar4 = cVar4 + -1;
    if (bVar5 < 3) {
      if (bVar5 == 2) {
        dec_copy_ret((undefined2 *)0xd6d0,(undefined2 *)0xd6c6);
      }
      else {
        puVar1 = dec_copy_ret((undefined2 *)0xd6c6,(undefined2 *)0xd6bc);
        dec_copy_ret(puVar1 + 5,(undefined2 *)(sVar3 + 10));
      }
    }
  }
  return cVar4;
}

/**
 * @brief 矩阵尺寸调整（列记忆 0xD149）
 * @addr 0x134F8
 * @module eval
 * @proto void apps_mat_size(undefined2 arg)
 * @confidence likely
 * @note 矩阵尺寸调整（列记忆 0xD149）。
 * @tag matrix
 */
int apps_mat_size(undefined2 arg)

{
  undefined2 uVar1;
  undefined2 *puVar2;
  undefined2 *puVar3;
  longlong lVar4;
  undefined4 uVar5;
  undefined auStack_20 [10];
  undefined auStack_16 [18];
  
  lVar4 = (ulonglong)CONCAT22(auStack_20,auStack_16) << 0x20;
  uVar1 = dec_cmp((undefined2 *)0xd3b0,arg);
  if (((char)uVar1 == '\x01') &&
     (uVar1 = dec_cmp((undefined2 *)0xd3a6,arg), (char)uVar1 != '\x01')) {
    puVar2 = dec_copy_ret((undefined2 *)0xd752,(undefined2 *)((ulonglong)lVar4 >> 0x30));
    puVar2 = dec_copy_ret(puVar2 + 0x14,puVar2);
    dec_copy_ret((undefined2 *)((ulonglong)lVar4 >> 0x30),puVar2);
  }
  puVar2 = dec_copy_ret((undefined2 *)0xd752,(undefined2 *)((ulonglong)lVar4 >> 0x30));
  puVar3 = (undefined2 *)((ulonglong)lVar4 >> 0x20);
  dec_copy_ret(puVar2 + 0x14,puVar3);
  dec_cmp_signed((short)((ulonglong)lVar4 >> 0x30),puVar3);
  uVar5 = (undefined4)((ulonglong)lVar4 >> 0x30);
  dec_cmp_signed((short)((ulonglong)lVar4 >> 0x20),puVar3);
  dec_to_string((short)uVar5,(undefined2 *)((uint)uVar5 >> 0x10));
  return 0;
}

