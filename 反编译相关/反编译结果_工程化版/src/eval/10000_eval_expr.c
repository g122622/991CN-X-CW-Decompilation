/*
 * 表达式求值 / 10000_eval_expr.c
 * 地址范围: 0x10000 - 0x107F4
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 表达式求值主例程
 * @addr 0x10000
 * @module eval
 * @proto undefined2 eval_expr(byte** pp, undefined2* slots)
 * @confidence strong
 * @note 表达式求值主例程。先用 0xD4C8（token_at）/0x179C2 预扫描表达式，把
 *       0x52/0x51/0x77..0x79 记进标志位（Surveying 的度/弧度/工程记数标记）；随后 0x8FEC
 *       载入首操作数， 0x1D780 做二元入口初始化，进入运算循环。
 * @tag eval
 */
undefined2 eval_expr(byte** pp, undefined2* slots)

{
  byte bVar1;
  char cVar2;
  ushort uVar3;
  undefined2 uVar4;
  undefined extraout_R1;
  undefined extraout_R1_00;
  undefined2 *puVar5;
  ushort *puVar6;
  ushort *puVar7;
  undefined uVar8;
  byte bVar9;
  byte *pbVar10;
  undefined2 auStack_ce [10];
  undefined2 auStack_ba [10];
  undefined2 auStack_a6 [5];
  undefined auStack_9c [10];
  undefined auStack_92 [10];
  ushort auStack_88 [4];
  undefined2 uStack_80;
  undefined2 auStack_7e [5];
  ushort auStack_74 [10];
  undefined2 auStack_60 [5];
  ushort auStack_56 [5];
  undefined2 auStack_4c [5];
  ushort auStack_42 [10];
  ushort auStack_2e [5];
  ushort auStack_24 [4];
  undefined2 uStack_1c;
  ushort auStack_1a [5];
  byte bStack_10;
  char cStack_f;
  byte bStack_e;
  char cStack_d;
  
  pbVar10 = *pp;
  bVar9 = 0;
  while( true ) {
    uVar3 = token_at(pbVar10);
    uVar4 = token_class_ex((byte)uVar3,(char)(uVar3 >> 8));
    if ((char)uVar4 == '\n') break;
    bVar1 = *pbVar10;
    if (bVar1 == 0x52) {
      bVar9 = bVar9 | 1;
    }
    else if (bVar1 == 0x51) {
      bVar9 = bVar9 | 4;
    }
    else if ((bVar9 & 4) != 0) {
      if (bVar1 == 0x77) {
        bVar9 = bVar9 | 2;
      }
      else if (bVar1 == 0x78) {
        bVar9 = bVar9 | 2;
      }
      else if (bVar1 == 0x79) {
        bVar9 = bVar9 | 2;
      }
    }
    advance_token_ptr(CONCAT11((char)((ushort)uVar4 >> 8),bVar1));
  }
  puVar7 = auStack_1a;
  bStack_10 = calc_buf_len - 0x40;
  puVar6 = auStack_24;
  bStack_e = bVar9;
  var_get_value(bStack_10,(undefined *)auStack_24);
  dec_bin_init(auStack_24,puVar6);
  dec_entry_x(auStack_24,puVar6);
  dec_copy(auStack_4c,auStack_24);
  var_get_value(bStack_10,auStack_92);
  dec_set_uint_small(auStack_74,0);
  dec_set_uint_small(auStack_56,0);
  cStack_d = '\x01';
  if (bStack_e == 0) {
    dec_set_uint_small(auStack_56,0);
  }
  puVar5 = auStack_4c;
  dec_copy(auStack_42,puVar5);
  bVar9 = eval_get_operand();
  if ((bVar9 == 2) || (bVar9 == 7)) {
    eval_error(bVar9);
  }
  else {
    if (bVar9 != 0) {
      puVar5 = (undefined2 *)((ushort)puVar5 & 0xff00);
      dec_set_uint_small(auStack_56,0);
      cStack_d = 0;
      uVar4 = eval_loop_e(puVar5);
      return uVar4;
    }
    cVar2 = eval_shift_op();
    if (cVar2 == '\x01') {
      uVar4 = eval_rotate2();
      return uVar4;
    }
    if (bStack_e != 0) {
      uVar4 = dec_cmp(auStack_74,puVar5);
      cVar2 = (char)uVar4;
      if (((cVar2 != '\x01') && (cVar2 != -0x10)) &&
         (uVar4 = eval_diff_abs(puVar5), 4 < (byte)uVar4)) {
        uVar4 = dec_cmp(auStack_60,puVar5);
        if ((char)uVar4 != '\x04') {
          if (cVar2 == '\x04') {
            uVar4 = eval_compare_op(puVar5);
            return uVar4;
          }
          uVar4 = eval_loop_c();
          return uVar4;
        }
        if (cVar2 == '\x02') {
          uVar4 = eval_compare_op(puVar5);
          return uVar4;
        }
      }
    }
    if ((bStack_e != 0) && (cStack_d != '\0')) {
      dec_set_uint_small(auStack_56,0);
      cStack_d = '\0';
    }
    dec_copy(auStack_74,auStack_60);
    puVar6 = auStack_42;
    dec_copy(auStack_7e,puVar6);
    uVar4 = dec_cmp(auStack_42,puVar6);
    if ((char)uVar4 == '\x01') {
      puVar6 = (ushort *)CONCAT11((char)((ushort)puVar6 >> 8),1);
      dec_set_uint_small(auStack_88,1);
      uStack_80 = 0x85;
    }
    else {
      puVar6 = auStack_42;
      dec_copy(auStack_88,puVar6);
    }
    cVar2 = eval_cmp_op();
    if (cVar2 != '\0') {
      uVar4 = eval_loop_e(puVar6);
      return uVar4;
    }
    puVar6 = puVar7;
    dec_copy(auStack_ba,puVar7);
    uVar4 = dec_cmp(auStack_ba,puVar6);
    if ((char)uVar4 == '\x01') {
      uVar4 = eval_loop_e(puVar6);
      return uVar4;
    }
    dec_copy(puVar7,auStack_60);
    dec_bin_and_core(puVar7,auStack_ba);
    dec_copy(auStack_56,auStack_42);
    dec_bin_or_core(auStack_42,puVar7);
    puVar6 = auStack_42;
    dec_copy(auStack_4c,puVar6);
    bVar9 = eval_get_operand();
    if (bVar9 == 0) {
      cVar2 = eval_shift_op();
      if (cVar2 == '\x01') {
        uVar4 = eval_rotate2();
        return uVar4;
      }
      dec_copy(puVar7,auStack_42);
      puVar5 = auStack_7e;
      dec_bin_or_core(puVar7,puVar5);
      dec_bin_result(puVar7,puVar5);
      puVar6 = auStack_88;
      dec_copy(auStack_24,puVar6);
      dec_bin_result(auStack_24,puVar6);
      puVar6 = auStack_24;
      dec_bin_and_core(puVar7,auStack_24);
      dec_bin_result(puVar7,puVar6);
      dec_set_uint_small(auStack_24,1);
      if ((bStack_e & 1) == 0) {
        if ((bStack_e & 4) == 0) {
          uStack_1c = 0x87;
        }
        else {
          uStack_1c = 0x91;
        }
      }
      else {
        uStack_1c = 0x93;
      }
      cVar2 = dec_cmp_bool(puVar7);
      if (cVar2 == '\x02') {
        uVar4 = eval_rotate2();
        return uVar4;
      }
      puVar5 = auStack_60;
      dec_copy(puVar7,puVar5);
      dec_bin_result(puVar7,puVar5);
      puVar6 = auStack_74;
      dec_copy(auStack_24,puVar6);
      dec_bin_result(auStack_24,puVar6);
      dec_bin_or_core(auStack_24,puVar7);
      uVar4 = dec_cmp(auStack_24,puVar7);
      if ((byte)uVar4 < 4) {
        uVar4 = eval_loop_f(puVar7);
        return uVar4;
      }
      uVar4 = kbd_wait_key();
      if ((byte)uVar4 == 0) {
        uVar4 = eval_loop_b(puVar7);
        return uVar4;
      }
      eval_error((byte)uVar4);
    }
    else {
      bVar9 = 0;
      uVar4 = dec_cmp(auStack_42,puVar6);
      if (((char)uVar4 == '\x01') &&
         (uVar4 = dec_cmp(auStack_56,puVar6), (char)uVar4 == '\x01')) {
        uVar4 = eval_rotate((short)puVar6);
        return uVar4;
      }
      do {
        uVar4 = kbd_wait_key();
        if ((byte)uVar4 != 0) {
          eval_error((byte)uVar4);
          goto LAB_rom_01072e;
        }
        bVar1 = bcd_type((byte *)auStack_a6);
        if (((bVar1 != 0) && (bVar1 != 3)) && (bVar1 != 0xb)) {
          eval_error(bVar1);
          goto LAB_rom_01072e;
        }
        bVar9 = bVar9 + 1;
        if (0xe < bVar9) {
          uVar4 = eval_rotate((short)puVar6);
          return uVar4;
        }
        puVar6 = auStack_42;
        dec_copy(puVar7,puVar6);
        dec_bin_result(puVar7,puVar6);
        puVar6 = auStack_56;
        dec_copy(auStack_24,puVar6);
        dec_bin_result(auStack_24,puVar6);
        bVar1 = dec_cmp_bool(puVar7);
        if (bVar1 < 4) {
          dec_copy(auStack_2e,auStack_56);
          dec_copy(auStack_24,auStack_42);
        }
        else {
          dec_copy(auStack_2e,auStack_42);
          dec_copy(auStack_24,auStack_56);
        }
        dec_bin_or_core(auStack_2e,auStack_24);
        dec_set_uint_small(auStack_24,2);
        dec_bin_and_core(auStack_2e,auStack_24);
        dec_copy(puVar7,auStack_42);
        dec_copy(auStack_24,auStack_56);
        puVar6 = auStack_24;
        bVar1 = dec_cmp_bool(puVar7);
        if (bVar1 < 4) {
          puVar6 = auStack_42;
          dec_copy(auStack_24,puVar6);
        }
        dec_bin_result(auStack_2e,puVar6);
        dec_bin_xor_core(auStack_2e,auStack_24);
        dec_copy(auStack_42,auStack_2e);
        puVar6 = auStack_42;
        dec_copy(auStack_4c,puVar6);
        bVar1 = eval_get_operand();
      } while (bVar1 != 0);
      cVar2 = eval_shift_op();
      if (cVar2 != '\x01') {
        dec_copy_rev(auStack_ce,auStack_a6);
        puVar6 = auStack_42;
        dec_copy(auStack_4c,puVar6);
        uVar3 = CONCAT11((char)((ushort)puVar6 >> 8),4);
        dec_exp_shift(auStack_4c,uVar3);
        uVar8 = (undefined)(uVar3 >> 8);
        bVar9 = eval_get_operand();
        if ((bVar9 == 0) && (cVar2 = eval_shift_op(), cVar2 == '\x01')) {
          dec_exp_shift(auStack_42,CONCAT11(uVar8,4));
          uVar4 = eval_rotate2();
          return uVar4;
        }
        puVar5 = auStack_ce;
        dec_copy_rev(auStack_a6,puVar5);
        uVar4 = eval_loop_a(puVar5);
        return uVar4;
      }
      cStack_f = '\0';
      dec_copy(auStack_4c,auStack_42);
      bVar9 = eval_get_operand();
      if (bVar9 == 0) {
        if (cStack_f == '\0') {
          dec_bin_mul_core(auStack_a6,auStack_9c);
        }
        else {
          dec_bin_or_core(auStack_a6,auStack_9c);
        }
        dec_copy(auStack_24,auStack_a6);
        dec_copy(auStack_2e,auStack_42);
        base_clear(CONCAT11(extraout_R1,bStack_10),(undefined *)auStack_42);
      }
      else {
        eval_error(10);
      }
    }
  }
LAB_rom_01072e:
  dec_copy_rev(slots,auStack_2e);
  return CONCAT11(extraout_R1_00,cStack_f);
}

/**
 * @brief 求值循环的一段（XREF 仅 0x10670）
 * @addr 0x100BC
 * @module eval
 * @proto undefined2 eval_loop_shift(void)
 * @confidence likely
 * @note 求值循环的一段（XREF 仅 0x10670）：设置当前令牌位 -7[FP]=1 并推进操作数栈。
 * @tag eval
 */
undefined2 eval_loop_shift(void)

{
  byte bVar1;
  char cVar2;
  byte bVar3;
  undefined2 uVar4;
  undefined extraout_R1;
  undefined extraout_R1_00;
  undefined2 *puVar5;
  short sVar6;
  ushort *puVar7;
  ushort uVar8;
  undefined uVar9;
  char unaff_R4;
  ushort *unaff_ER10;
  ushort *unaff_ER12;
  short unaff_ER14;
  
  *(undefined *)(unaff_ER14 + -7) = 1;
  if (*(char *)(unaff_ER14 + -8) == '\0') {
    dec_set_uint_small((ushort *)(unaff_ER14 + -0x50),0);
  }
  puVar5 = (undefined2 *)(unaff_ER14 + -0x46);
  dec_copy((undefined2 *)(unaff_ER14 + -0x3c),puVar5);
  bVar1 = eval_get_operand();
  if ((bVar1 == 2) || (bVar1 == 7)) {
    eval_error(bVar1);
  }
  else {
    if (bVar1 != 0) {
      puVar5 = (undefined2 *)((ushort)puVar5 & 0xff00);
      dec_set_uint_small((ushort *)(unaff_ER14 + -0x50),0);
      *(undefined *)(unaff_ER14 + -7) = 0;
      uVar4 = eval_loop_e(puVar5);
      return uVar4;
    }
    cVar2 = eval_shift_op();
    if (cVar2 == '\x01') {
      uVar4 = eval_rotate2();
      return uVar4;
    }
    if (*(char *)(unaff_ER14 + -8) != '\0') {
      uVar4 = dec_cmp((undefined2 *)(unaff_ER14 + -0x6e),puVar5);
      cVar2 = (char)uVar4;
      if (((cVar2 != '\x01') && (cVar2 != -0x10)) &&
         (uVar4 = eval_diff_abs(puVar5), 4 < (byte)uVar4)) {
        uVar4 = dec_cmp((undefined2 *)(unaff_ER14 + -0x5a),puVar5);
        if ((char)uVar4 != '\x04') {
          if (cVar2 == '\x04') {
            uVar4 = eval_compare_op(puVar5);
            return uVar4;
          }
          uVar4 = eval_loop_c();
          return uVar4;
        }
        if (cVar2 == '\x02') {
          uVar4 = eval_compare_op(puVar5);
          return uVar4;
        }
      }
    }
    if ((*(char *)(unaff_ER14 + -8) != '\0') && (*(char *)(unaff_ER14 + -7) != '\0')) {
      dec_set_uint_small((ushort *)(unaff_ER14 + -0x50),0);
      *(undefined *)(unaff_ER14 + -7) = 0;
    }
    dec_copy((undefined2 *)(unaff_ER14 + -0x6e),(undefined2 *)(unaff_ER14 + -0x5a));
    puVar5 = (undefined2 *)(unaff_ER14 + -0x3c);
    dec_copy((undefined2 *)(unaff_ER14 + -0x78),puVar5);
    uVar4 = dec_cmp((undefined2 *)(unaff_ER14 + -0x3c),puVar5);
    if ((char)uVar4 == '\x01') {
      puVar5 = (undefined2 *)CONCAT11((char)((ushort)puVar5 >> 8),1);
      dec_set_uint_small((ushort *)(unaff_ER14 + -0x82),1);
      *(undefined2 *)(unaff_ER14 + -0x7a) = 0x85;
    }
    else {
      puVar5 = (undefined2 *)(unaff_ER14 + -0x3c);
      dec_copy((undefined2 *)(unaff_ER14 + -0x82),puVar5);
    }
    cVar2 = eval_cmp_op();
    if (cVar2 != '\0') {
      uVar4 = eval_loop_e(puVar5);
      return uVar4;
    }
    puVar7 = unaff_ER12;
    dec_copy((undefined2 *)(unaff_ER14 + -0xb4),unaff_ER12);
    uVar4 = dec_cmp((undefined2 *)(unaff_ER14 + -0xb4),puVar7);
    if ((char)uVar4 == '\x01') {
      uVar4 = eval_loop_e(puVar7);
      return uVar4;
    }
    dec_copy(unaff_ER12,(undefined2 *)(unaff_ER14 + -0x5a));
    dec_bin_and_core(unaff_ER12,unaff_ER14 + -0xb4);
    dec_copy((undefined2 *)(unaff_ER14 + -0x50),(undefined2 *)(unaff_ER14 + -0x3c));
    dec_bin_or_core(unaff_ER14 + -0x3c,unaff_ER12);
    puVar5 = (undefined2 *)(unaff_ER14 + -0x3c);
    dec_copy((undefined2 *)(unaff_ER14 + -0x46),puVar5);
    bVar1 = eval_get_operand();
    if (bVar1 == 0) {
      cVar2 = eval_shift_op();
      if (cVar2 == '\x01') {
        uVar4 = eval_rotate2();
        return uVar4;
      }
      dec_copy(unaff_ER12,(undefined2 *)(unaff_ER14 + -0x3c));
      sVar6 = unaff_ER14 + -0x78;
      dec_bin_or_core(unaff_ER12,sVar6);
      dec_bin_result(unaff_ER12,sVar6);
      puVar5 = (undefined2 *)(unaff_ER14 + -0x82);
      dec_copy(unaff_ER10,puVar5);
      dec_bin_result(unaff_ER10,puVar5);
      puVar7 = unaff_ER10;
      dec_bin_and_core(unaff_ER12,unaff_ER10);
      dec_bin_result(unaff_ER12,puVar7);
      dec_set_uint_small(unaff_ER10,1);
      if ((*(byte *)(unaff_ER14 + -8) & 1) == 0) {
        if ((*(byte *)(unaff_ER14 + -8) & 4) == 0) {
          uVar4 = 0x87;
        }
        else {
          uVar4 = 0x91;
        }
      }
      else {
        uVar4 = 0x93;
      }
      *(undefined2 *)(unaff_ER14 + -0x16) = uVar4;
      cVar2 = dec_cmp_bool(unaff_ER12);
      if (cVar2 == '\x02') {
        uVar4 = eval_rotate2();
        return uVar4;
      }
      puVar5 = (undefined2 *)(unaff_ER14 + -0x5a);
      dec_copy(unaff_ER12,puVar5);
      dec_bin_result(unaff_ER12,puVar5);
      puVar5 = (undefined2 *)(unaff_ER14 + -0x6e);
      dec_copy(unaff_ER10,puVar5);
      dec_bin_result(unaff_ER10,puVar5);
      dec_bin_or_core(unaff_ER10,unaff_ER12);
      uVar4 = dec_cmp(unaff_ER10,unaff_ER12);
      if ((byte)uVar4 < 4) {
        uVar4 = eval_loop_f(unaff_ER12);
        return uVar4;
      }
      uVar4 = kbd_wait_key();
      if ((byte)uVar4 == 0) {
        if (0x27 < (byte)(unaff_R4 + 1U)) {
          uVar4 = eval_func_args((short)unaff_ER12);
          return uVar4;
        }
        uVar4 = eval_loop_b(unaff_ER12);
        return uVar4;
      }
      eval_error((byte)uVar4);
    }
    else {
      bVar1 = 0;
      uVar4 = dec_cmp((undefined2 *)(unaff_ER14 + -0x3c),puVar5);
      if (((char)uVar4 == '\x01') &&
         (uVar4 = dec_cmp((undefined2 *)(unaff_ER14 + -0x50),puVar5), (char)uVar4 == '\x01'))
      {
        uVar4 = eval_rotate((short)puVar5);
        return uVar4;
      }
      do {
        uVar4 = kbd_wait_key();
        if ((byte)uVar4 != 0) {
          eval_error((byte)uVar4);
          goto LAB_rom_01072e;
        }
        bVar3 = bcd_type((byte *)(unaff_ER14 + -0xa0));
        if (((bVar3 != 0) && (bVar3 != 3)) && (bVar3 != 0xb)) {
          eval_error(bVar3);
          goto LAB_rom_01072e;
        }
        bVar1 = bVar1 + 1;
        if (0xe < bVar1) {
          uVar4 = eval_rotate((short)puVar5);
          return uVar4;
        }
        puVar5 = (undefined2 *)(unaff_ER14 + -0x3c);
        dec_copy(unaff_ER12,puVar5);
        dec_bin_result(unaff_ER12,puVar5);
        puVar5 = (undefined2 *)(unaff_ER14 + -0x50);
        dec_copy(unaff_ER10,puVar5);
        dec_bin_result(unaff_ER10,puVar5);
        bVar3 = dec_cmp_bool(unaff_ER12);
        if (bVar3 < 4) {
          dec_copy((undefined2 *)(unaff_ER14 + -0x28),(undefined2 *)(unaff_ER14 + -0x50));
          dec_copy(unaff_ER10,(undefined2 *)(unaff_ER14 + -0x3c));
        }
        else {
          dec_copy((undefined2 *)(unaff_ER14 + -0x28),(undefined2 *)(unaff_ER14 + -0x3c));
          dec_copy(unaff_ER10,(undefined2 *)(unaff_ER14 + -0x50));
        }
        dec_bin_or_core(unaff_ER14 + -0x28,unaff_ER10);
        dec_set_uint_small(unaff_ER10,2);
        dec_bin_and_core(unaff_ER14 + -0x28,unaff_ER10);
        dec_copy(unaff_ER12,(undefined2 *)(unaff_ER14 + -0x3c));
        dec_copy(unaff_ER10,(undefined2 *)(unaff_ER14 + -0x50));
        puVar7 = unaff_ER10;
        bVar3 = dec_cmp_bool(unaff_ER12);
        if (bVar3 < 4) {
          puVar7 = (ushort *)(unaff_ER14 + -0x3c);
          dec_copy(unaff_ER10,puVar7);
        }
        dec_bin_result((ushort *)(unaff_ER14 + -0x28),puVar7);
        dec_bin_xor_core(unaff_ER14 + -0x28,unaff_ER10);
        dec_copy((undefined2 *)(unaff_ER14 + -0x3c),(undefined2 *)(unaff_ER14 + -0x28));
        puVar5 = (undefined2 *)(unaff_ER14 + -0x3c);
        dec_copy((undefined2 *)(unaff_ER14 + -0x46),puVar5);
        bVar3 = eval_get_operand();
      } while (bVar3 != 0);
      cVar2 = eval_shift_op();
      if (cVar2 != '\x01') {
        dec_copy_rev((undefined2 *)(unaff_ER14 + -200),(undefined2 *)(unaff_ER14 + -0xa0));
        puVar5 = (undefined2 *)(unaff_ER14 + -0x3c);
        dec_copy((undefined2 *)(unaff_ER14 + -0x46),puVar5);
        uVar8 = CONCAT11((char)((ushort)puVar5 >> 8),4);
        dec_exp_shift((undefined2 *)(unaff_ER14 + -0x46),uVar8);
        uVar9 = (undefined)(uVar8 >> 8);
        bVar1 = eval_get_operand();
        if ((bVar1 == 0) && (cVar2 = eval_shift_op(), cVar2 == '\x01')) {
          dec_exp_shift((undefined2 *)(unaff_ER14 + -0x3c),CONCAT11(uVar9,4));
          uVar4 = eval_rotate2();
          return uVar4;
        }
        puVar5 = (undefined2 *)(unaff_ER14 + -200);
        dec_copy_rev((undefined2 *)(unaff_ER14 + -0xa0),puVar5);
        uVar4 = eval_loop_a(puVar5);
        return uVar4;
      }
      *(undefined *)(unaff_ER14 + -9) = 0;
      dec_copy((undefined2 *)(unaff_ER14 + -0x46),(undefined2 *)(unaff_ER14 + -0x3c));
      bVar1 = eval_get_operand();
      if (bVar1 == 0) {
        if (*(char *)(unaff_ER14 + -9) == '\0') {
          dec_bin_mul_core(unaff_ER14 + -0xa0,unaff_ER14 + -0x96);
        }
        else {
          dec_bin_or_core(unaff_ER14 + -0xa0,unaff_ER14 + -0x96);
        }
        dec_copy(unaff_ER10,(undefined2 *)(unaff_ER14 + -0xa0));
        dec_copy((undefined2 *)(unaff_ER14 + -0x28),(undefined2 *)(unaff_ER14 + -0x3c));
        base_clear(CONCAT11(extraout_R1,*(undefined *)(unaff_ER14 + -10)), (uintptr_t)0)
                       (undefined *)(unaff_ER14 + -0x3c));
      }
      else {
        eval_error(10);
      }
    }
  }
LAB_rom_01072e:
  dec_copy_rev(*(undefined2 **)(unaff_ER14 + -6),(undefined2 *)(unaff_ER14 + -0x28));
  return CONCAT11(extraout_R1_00,*(undefined *)(unaff_ER14 + -9));
}

/**
 * @brief 求值循环分支 A（被 0x10118/0x10674/0x10882 跳入）
 * @addr 0x1010C
 * @module eval
 * @proto undefined2 eval_loop_a(void)
 * @confidence likely
 * @note 求值循环分支 A（被 0x10118/0x10674/0x10882 跳入）。
 * @tag eval
 */
undefined2 eval_loop_a(uintptr_t _a2, int _a1)

{
  char cVar1;
  byte bVar2;
  byte bVar3;
  undefined2 uVar4;
  undefined extraout_R1;
  undefined extraout_R1_00;
  undefined2 *puVar5;
  short sVar6;
  ushort *puVar7;
  ushort uVar8;
  undefined uVar9;
  char unaff_R4;
  byte unaff_R6;
  ushort *unaff_ER10;
  ushort *unaff_ER12;
  short unaff_ER14;
  
  cVar1 = eval_shift_op();
  if (cVar1 == '\x01') {
    uVar4 = eval_rotate2();
    return uVar4;
  }
  if (*(char *)(unaff_ER14 + -8) != '\0') {
    uVar4 = dec_cmp((undefined2 *)(unaff_ER14 + -0x6e),_a1);
    cVar1 = (char)uVar4;
    if (((cVar1 != '\x01') && (cVar1 != -0x10)) &&
       (uVar4 = eval_diff_abs(_a1), 4 < (byte)uVar4)) {
      uVar4 = dec_cmp((undefined2 *)(unaff_ER14 + -0x5a),_a1);
      if ((char)uVar4 != '\x04') {
        if (cVar1 != '\x04') {
          uVar4 = eval_loop_c();
          return uVar4;
        }
        uVar4 = eval_compare_op(_a1);
        return uVar4;
      }
      if (cVar1 == '\x02') {
        uVar4 = eval_compare_op(_a1);
        return uVar4;
      }
    }
  }
  if ((*(char *)(unaff_ER14 + -8) != '\0') && (*(char *)(unaff_ER14 + -7) != '\0')) {
    dec_set_uint_small((ushort *)(unaff_ER14 + -0x50),0);
    *(undefined *)(unaff_ER14 + -7) = 0;
  }
  dec_copy((undefined2 *)(unaff_ER14 + -0x6e),(undefined2 *)(unaff_ER14 + -0x5a));
  puVar5 = (undefined2 *)(unaff_ER14 + -0x3c);
  dec_copy((undefined2 *)(unaff_ER14 + -0x78),puVar5);
  uVar4 = dec_cmp((undefined2 *)(unaff_ER14 + -0x3c),puVar5);
  if ((char)uVar4 == '\x01') {
    puVar5 = (undefined2 *)CONCAT11((char)((ushort)puVar5 >> 8),1);
    dec_set_uint_small((ushort *)(unaff_ER14 + -0x82),1);
    *(undefined2 *)(unaff_ER14 + -0x7a) = 0x85;
  }
  else {
    puVar5 = (undefined2 *)(unaff_ER14 + -0x3c);
    dec_copy((undefined2 *)(unaff_ER14 + -0x82),puVar5);
  }
  cVar1 = eval_cmp_op();
  if (cVar1 != '\0') {
    uVar4 = eval_loop_e(puVar5);
    return uVar4;
  }
  puVar7 = unaff_ER12;
  dec_copy((undefined2 *)(unaff_ER14 + -0xb4),unaff_ER12);
  uVar4 = dec_cmp((undefined2 *)(unaff_ER14 + -0xb4),puVar7);
  if ((char)uVar4 == '\x01') {
    uVar4 = eval_loop_e(puVar7);
    return uVar4;
  }
  dec_copy(unaff_ER12,(undefined2 *)(unaff_ER14 + -0x5a));
  dec_bin_and_core(unaff_ER12,unaff_ER14 + -0xb4);
  dec_copy((undefined2 *)(unaff_ER14 + -0x50),(undefined2 *)(unaff_ER14 + -0x3c));
  dec_bin_or_core(unaff_ER14 + -0x3c,unaff_ER12);
  puVar5 = (undefined2 *)(unaff_ER14 + -0x3c);
  dec_copy((undefined2 *)(unaff_ER14 + -0x46),puVar5);
  bVar2 = eval_get_operand();
  if (bVar2 == 0) {
    cVar1 = eval_shift_op();
    if (cVar1 == '\x01') {
      uVar4 = eval_rotate2();
      return uVar4;
    }
    dec_copy(unaff_ER12,(undefined2 *)(unaff_ER14 + -0x3c));
    sVar6 = unaff_ER14 + -0x78;
    dec_bin_or_core(unaff_ER12,sVar6);
    dec_bin_result(unaff_ER12,sVar6);
    puVar5 = (undefined2 *)(unaff_ER14 + -0x82);
    dec_copy(unaff_ER10,puVar5);
    dec_bin_result(unaff_ER10,puVar5);
    puVar7 = unaff_ER10;
    dec_bin_and_core(unaff_ER12,unaff_ER10);
    dec_bin_result(unaff_ER12,puVar7);
    dec_set_uint_small(unaff_ER10,1);
    if ((*(byte *)(unaff_ER14 + -8) & 1) == 0) {
      if ((*(byte *)(unaff_ER14 + -8) & 4) == 0) {
        uVar4 = 0x87;
      }
      else {
        uVar4 = 0x91;
      }
    }
    else {
      uVar4 = 0x93;
    }
    *(undefined2 *)(unaff_ER14 + -0x16) = uVar4;
    cVar1 = dec_cmp_bool(unaff_ER12);
    if (cVar1 == '\x02') {
      uVar4 = eval_rotate2();
      return uVar4;
    }
    puVar5 = (undefined2 *)(unaff_ER14 + -0x5a);
    dec_copy(unaff_ER12,puVar5);
    dec_bin_result(unaff_ER12,puVar5);
    puVar5 = (undefined2 *)(unaff_ER14 + -0x6e);
    dec_copy(unaff_ER10,puVar5);
    dec_bin_result(unaff_ER10,puVar5);
    dec_bin_or_core(unaff_ER10,unaff_ER12);
    uVar4 = dec_cmp(unaff_ER10,unaff_ER12);
    if ((byte)uVar4 < 4) {
      uVar4 = eval_loop_f(unaff_ER12);
      return uVar4;
    }
    uVar4 = kbd_wait_key();
    if ((byte)uVar4 == 0) {
      if ((byte)(unaff_R4 + 1U) < 0x28) {
        uVar4 = eval_loop_b(unaff_ER12);
        return uVar4;
      }
      uVar4 = eval_func_args((short)unaff_ER12);
      return uVar4;
    }
    eval_error((byte)uVar4);
  }
  else {
    if (0xc < unaff_R6) {
      uVar4 = eval_rotate((short)puVar5);
      return uVar4;
    }
    bVar2 = 0;
    uVar4 = dec_cmp((undefined2 *)(unaff_ER14 + -0x3c),puVar5);
    if (((char)uVar4 == '\x01') &&
       (uVar4 = dec_cmp((undefined2 *)(unaff_ER14 + -0x50),puVar5), (char)uVar4 == '\x01')) {
      uVar4 = eval_rotate((short)puVar5);
      return uVar4;
    }
    do {
      uVar4 = kbd_wait_key();
      if ((byte)uVar4 != 0) {
        eval_error((byte)uVar4);
        goto LAB_rom_01072e;
      }
      bVar3 = bcd_type((byte *)(unaff_ER14 + -0xa0));
      if (((bVar3 != 0) && (bVar3 != 3)) && (bVar3 != 0xb)) {
        eval_error(bVar3);
        goto LAB_rom_01072e;
      }
      bVar2 = bVar2 + 1;
      if (0xe < bVar2) {
        uVar4 = eval_rotate((short)puVar5);
        return uVar4;
      }
      puVar5 = (undefined2 *)(unaff_ER14 + -0x3c);
      dec_copy(unaff_ER12,puVar5);
      dec_bin_result(unaff_ER12,puVar5);
      puVar5 = (undefined2 *)(unaff_ER14 + -0x50);
      dec_copy(unaff_ER10,puVar5);
      dec_bin_result(unaff_ER10,puVar5);
      bVar3 = dec_cmp_bool(unaff_ER12);
      if (bVar3 < 4) {
        dec_copy((undefined2 *)(unaff_ER14 + -0x28),(undefined2 *)(unaff_ER14 + -0x50));
        dec_copy(unaff_ER10,(undefined2 *)(unaff_ER14 + -0x3c));
      }
      else {
        dec_copy((undefined2 *)(unaff_ER14 + -0x28),(undefined2 *)(unaff_ER14 + -0x3c));
        dec_copy(unaff_ER10,(undefined2 *)(unaff_ER14 + -0x50));
      }
      dec_bin_or_core(unaff_ER14 + -0x28,unaff_ER10);
      dec_set_uint_small(unaff_ER10,2);
      dec_bin_and_core(unaff_ER14 + -0x28,unaff_ER10);
      dec_copy(unaff_ER12,(undefined2 *)(unaff_ER14 + -0x3c));
      dec_copy(unaff_ER10,(undefined2 *)(unaff_ER14 + -0x50));
      puVar7 = unaff_ER10;
      bVar3 = dec_cmp_bool(unaff_ER12);
      if (bVar3 < 4) {
        puVar7 = (ushort *)(unaff_ER14 + -0x3c);
        dec_copy(unaff_ER10,puVar7);
      }
      dec_bin_result((ushort *)(unaff_ER14 + -0x28),puVar7);
      dec_bin_xor_core(unaff_ER14 + -0x28,unaff_ER10);
      dec_copy((undefined2 *)(unaff_ER14 + -0x3c),(undefined2 *)(unaff_ER14 + -0x28));
      puVar5 = (undefined2 *)(unaff_ER14 + -0x3c);
      dec_copy((undefined2 *)(unaff_ER14 + -0x46),puVar5);
      bVar3 = eval_get_operand();
    } while (bVar3 != 0);
    cVar1 = eval_shift_op();
    if (cVar1 != '\x01') {
      dec_copy_rev((undefined2 *)(unaff_ER14 + -200),(undefined2 *)(unaff_ER14 + -0xa0));
      puVar5 = (undefined2 *)(unaff_ER14 + -0x3c);
      dec_copy((undefined2 *)(unaff_ER14 + -0x46),puVar5);
      uVar8 = CONCAT11((char)((ushort)puVar5 >> 8),4);
      dec_exp_shift((undefined2 *)(unaff_ER14 + -0x46),uVar8);
      uVar9 = (undefined)(uVar8 >> 8);
      bVar2 = eval_get_operand();
      if ((bVar2 == 0) && (cVar1 = eval_shift_op(), cVar1 == '\x01')) {
        dec_exp_shift((undefined2 *)(unaff_ER14 + -0x3c),CONCAT11(uVar9,4));
        uVar4 = eval_rotate2();
        return uVar4;
      }
      puVar5 = (undefined2 *)(unaff_ER14 + -200);
      dec_copy_rev((undefined2 *)(unaff_ER14 + -0xa0),puVar5);
      uVar4 = eval_loop_a(puVar5);
      return uVar4;
    }
    *(undefined *)(unaff_ER14 + -9) = 0;
    dec_copy((undefined2 *)(unaff_ER14 + -0x46),(undefined2 *)(unaff_ER14 + -0x3c));
    bVar2 = eval_get_operand();
    if (bVar2 == 0) {
      if (*(char *)(unaff_ER14 + -9) == '\0') {
        dec_bin_mul_core(unaff_ER14 + -0xa0,unaff_ER14 + -0x96);
      }
      else {
        dec_bin_or_core(unaff_ER14 + -0xa0,unaff_ER14 + -0x96);
      }
      dec_copy(unaff_ER10,(undefined2 *)(unaff_ER14 + -0xa0));
      dec_copy((undefined2 *)(unaff_ER14 + -0x28),(undefined2 *)(unaff_ER14 + -0x3c));
      base_clear(CONCAT11(extraout_R1,*(undefined *)(unaff_ER14 + -10)), (uintptr_t)0)
                     (undefined *)(unaff_ER14 + -0x3c));
    }
    else {
      eval_error(10);
    }
  }
LAB_rom_01072e:
  dec_copy_rev(*(undefined2 **)(unaff_ER14 + -6),(undefined2 *)(unaff_ER14 + -0x28));
  return CONCAT11(extraout_R1_00,*(undefined *)(unaff_ER14 + -9));
}

/**
 * @brief 求值循环分支 B（被 0x1010C 跳入，内部跳到 0x10158）
 * @addr 0x10118
 * @module eval
 * @proto undefined2 eval_loop_b(void)
 * @confidence likely
 * @note 求值循环分支 B（被 0x1010C 跳入，内部跳到 0x10158）。
 * @tag eval
 */
undefined2 eval_loop_b(uintptr_t _a2, int _a1)

{
  char cVar1;
  byte bVar2;
  byte bVar3;
  undefined2 uVar4;
  undefined extraout_R1;
  undefined extraout_R1_00;
  undefined2 *puVar5;
  short sVar6;
  ushort *puVar7;
  ushort uVar8;
  undefined uVar9;
  char unaff_R4;
  byte unaff_R6;
  ushort *unaff_ER10;
  ushort *unaff_ER12;
  short unaff_ER14;
  
  if (*(char *)(unaff_ER14 + -8) != '\0') {
    uVar4 = dec_cmp((undefined2 *)(unaff_ER14 + -0x6e),_a1);
    cVar1 = (char)uVar4;
    if (((cVar1 != '\x01') && (cVar1 != -0x10)) &&
       (uVar4 = eval_diff_abs(_a1), 4 < (byte)uVar4)) {
      uVar4 = dec_cmp((undefined2 *)(unaff_ER14 + -0x5a),_a1);
      if ((char)uVar4 != '\x04') {
        if (cVar1 != '\x04') {
          uVar4 = eval_loop_c();
          return uVar4;
        }
        uVar4 = eval_compare_op(_a1);
        return uVar4;
      }
      if (cVar1 == '\x02') {
        uVar4 = eval_compare_op(_a1);
        return uVar4;
      }
    }
  }
  if ((*(char *)(unaff_ER14 + -8) != '\0') && (*(char *)(unaff_ER14 + -7) != '\0')) {
    dec_set_uint_small((ushort *)(unaff_ER14 + -0x50),0);
    *(undefined *)(unaff_ER14 + -7) = 0;
  }
  dec_copy((undefined2 *)(unaff_ER14 + -0x6e),(undefined2 *)(unaff_ER14 + -0x5a));
  puVar5 = (undefined2 *)(unaff_ER14 + -0x3c);
  dec_copy((undefined2 *)(unaff_ER14 + -0x78),puVar5);
  uVar4 = dec_cmp((undefined2 *)(unaff_ER14 + -0x3c),puVar5);
  if ((char)uVar4 == '\x01') {
    puVar5 = (undefined2 *)CONCAT11((char)((ushort)puVar5 >> 8),1);
    dec_set_uint_small((ushort *)(unaff_ER14 + -0x82),1);
    *(undefined2 *)(unaff_ER14 + -0x7a) = 0x85;
  }
  else {
    puVar5 = (undefined2 *)(unaff_ER14 + -0x3c);
    dec_copy((undefined2 *)(unaff_ER14 + -0x82),puVar5);
  }
  cVar1 = eval_cmp_op();
  if (cVar1 != '\0') {
    uVar4 = eval_loop_e(puVar5);
    return uVar4;
  }
  puVar7 = unaff_ER12;
  dec_copy((undefined2 *)(unaff_ER14 + -0xb4),unaff_ER12);
  uVar4 = dec_cmp((undefined2 *)(unaff_ER14 + -0xb4),puVar7);
  if ((char)uVar4 == '\x01') {
    uVar4 = eval_loop_e(puVar7);
    return uVar4;
  }
  dec_copy(unaff_ER12,(undefined2 *)(unaff_ER14 + -0x5a));
  dec_bin_and_core(unaff_ER12,unaff_ER14 + -0xb4);
  dec_copy((undefined2 *)(unaff_ER14 + -0x50),(undefined2 *)(unaff_ER14 + -0x3c));
  dec_bin_or_core(unaff_ER14 + -0x3c,unaff_ER12);
  puVar5 = (undefined2 *)(unaff_ER14 + -0x3c);
  dec_copy((undefined2 *)(unaff_ER14 + -0x46),puVar5);
  bVar2 = eval_get_operand();
  if (bVar2 == 0) {
    cVar1 = eval_shift_op();
    if (cVar1 == '\x01') {
      uVar4 = eval_rotate2();
      return uVar4;
    }
    dec_copy(unaff_ER12,(undefined2 *)(unaff_ER14 + -0x3c));
    sVar6 = unaff_ER14 + -0x78;
    dec_bin_or_core(unaff_ER12,sVar6);
    dec_bin_result(unaff_ER12,sVar6);
    puVar5 = (undefined2 *)(unaff_ER14 + -0x82);
    dec_copy(unaff_ER10,puVar5);
    dec_bin_result(unaff_ER10,puVar5);
    puVar7 = unaff_ER10;
    dec_bin_and_core(unaff_ER12,unaff_ER10);
    dec_bin_result(unaff_ER12,puVar7);
    dec_set_uint_small(unaff_ER10,1);
    if ((*(byte *)(unaff_ER14 + -8) & 1) == 0) {
      if ((*(byte *)(unaff_ER14 + -8) & 4) == 0) {
        uVar4 = 0x87;
      }
      else {
        uVar4 = 0x91;
      }
    }
    else {
      uVar4 = 0x93;
    }
    *(undefined2 *)(unaff_ER14 + -0x16) = uVar4;
    cVar1 = dec_cmp_bool(unaff_ER12);
    if (cVar1 == '\x02') {
      uVar4 = eval_rotate2();
      return uVar4;
    }
    puVar5 = (undefined2 *)(unaff_ER14 + -0x5a);
    dec_copy(unaff_ER12,puVar5);
    dec_bin_result(unaff_ER12,puVar5);
    puVar5 = (undefined2 *)(unaff_ER14 + -0x6e);
    dec_copy(unaff_ER10,puVar5);
    dec_bin_result(unaff_ER10,puVar5);
    dec_bin_or_core(unaff_ER10,unaff_ER12);
    uVar4 = dec_cmp(unaff_ER10,unaff_ER12);
    if ((byte)uVar4 < 4) {
      uVar4 = eval_loop_f(unaff_ER12);
      return uVar4;
    }
    uVar4 = kbd_wait_key();
    if ((byte)uVar4 == 0) {
      if ((byte)(unaff_R4 + 1U) < 0x28) {
        uVar4 = eval_loop_b(unaff_ER12);
        return uVar4;
      }
      uVar4 = eval_func_args((short)unaff_ER12);
      return uVar4;
    }
    eval_error((byte)uVar4);
  }
  else {
    if (0xc < unaff_R6) {
      uVar4 = eval_rotate((short)puVar5);
      return uVar4;
    }
    bVar2 = 0;
    uVar4 = dec_cmp((undefined2 *)(unaff_ER14 + -0x3c),puVar5);
    if (((char)uVar4 == '\x01') &&
       (uVar4 = dec_cmp((undefined2 *)(unaff_ER14 + -0x50),puVar5), (char)uVar4 == '\x01')) {
      uVar4 = eval_rotate((short)puVar5);
      return uVar4;
    }
    do {
      uVar4 = kbd_wait_key();
      if ((byte)uVar4 != 0) {
        eval_error((byte)uVar4);
        goto LAB_rom_01072e;
      }
      bVar3 = bcd_type((byte *)(unaff_ER14 + -0xa0));
      if (((bVar3 != 0) && (bVar3 != 3)) && (bVar3 != 0xb)) {
        eval_error(bVar3);
        goto LAB_rom_01072e;
      }
      bVar2 = bVar2 + 1;
      if (0xe < bVar2) {
        uVar4 = eval_rotate((short)puVar5);
        return uVar4;
      }
      puVar5 = (undefined2 *)(unaff_ER14 + -0x3c);
      dec_copy(unaff_ER12,puVar5);
      dec_bin_result(unaff_ER12,puVar5);
      puVar5 = (undefined2 *)(unaff_ER14 + -0x50);
      dec_copy(unaff_ER10,puVar5);
      dec_bin_result(unaff_ER10,puVar5);
      bVar3 = dec_cmp_bool(unaff_ER12);
      if (bVar3 < 4) {
        dec_copy((undefined2 *)(unaff_ER14 + -0x28),(undefined2 *)(unaff_ER14 + -0x50));
        dec_copy(unaff_ER10,(undefined2 *)(unaff_ER14 + -0x3c));
      }
      else {
        dec_copy((undefined2 *)(unaff_ER14 + -0x28),(undefined2 *)(unaff_ER14 + -0x3c));
        dec_copy(unaff_ER10,(undefined2 *)(unaff_ER14 + -0x50));
      }
      dec_bin_or_core(unaff_ER14 + -0x28,unaff_ER10);
      dec_set_uint_small(unaff_ER10,2);
      dec_bin_and_core(unaff_ER14 + -0x28,unaff_ER10);
      dec_copy(unaff_ER12,(undefined2 *)(unaff_ER14 + -0x3c));
      dec_copy(unaff_ER10,(undefined2 *)(unaff_ER14 + -0x50));
      puVar7 = unaff_ER10;
      bVar3 = dec_cmp_bool(unaff_ER12);
      if (bVar3 < 4) {
        puVar7 = (ushort *)(unaff_ER14 + -0x3c);
        dec_copy(unaff_ER10,puVar7);
      }
      dec_bin_result((ushort *)(unaff_ER14 + -0x28),puVar7);
      dec_bin_xor_core(unaff_ER14 + -0x28,unaff_ER10);
      dec_copy((undefined2 *)(unaff_ER14 + -0x3c),(undefined2 *)(unaff_ER14 + -0x28));
      puVar5 = (undefined2 *)(unaff_ER14 + -0x3c);
      dec_copy((undefined2 *)(unaff_ER14 + -0x46),puVar5);
      bVar3 = eval_get_operand();
    } while (bVar3 != 0);
    cVar1 = eval_shift_op();
    if (cVar1 != '\x01') {
      dec_copy_rev((undefined2 *)(unaff_ER14 + -200),(undefined2 *)(unaff_ER14 + -0xa0));
      puVar5 = (undefined2 *)(unaff_ER14 + -0x3c);
      dec_copy((undefined2 *)(unaff_ER14 + -0x46),puVar5);
      uVar8 = CONCAT11((char)((ushort)puVar5 >> 8),4);
      dec_exp_shift((undefined2 *)(unaff_ER14 + -0x46),uVar8);
      uVar9 = (undefined)(uVar8 >> 8);
      bVar2 = eval_get_operand();
      if ((bVar2 == 0) && (cVar1 = eval_shift_op(), cVar1 == '\x01')) {
        dec_exp_shift((undefined2 *)(unaff_ER14 + -0x3c),CONCAT11(uVar9,4));
        uVar4 = eval_rotate2();
        return uVar4;
      }
      puVar5 = (undefined2 *)(unaff_ER14 + -200);
      dec_copy_rev((undefined2 *)(unaff_ER14 + -0xa0),puVar5);
      uVar4 = eval_loop_a(puVar5);
      return uVar4;
    }
    *(undefined *)(unaff_ER14 + -9) = 0;
    dec_copy((undefined2 *)(unaff_ER14 + -0x46),(undefined2 *)(unaff_ER14 + -0x3c));
    bVar2 = eval_get_operand();
    if (bVar2 == 0) {
      if (*(char *)(unaff_ER14 + -9) == '\0') {
        dec_bin_mul_core(unaff_ER14 + -0xa0,unaff_ER14 + -0x96);
      }
      else {
        dec_bin_or_core(unaff_ER14 + -0xa0,unaff_ER14 + -0x96);
      }
      dec_copy(unaff_ER10,(undefined2 *)(unaff_ER14 + -0xa0));
      dec_copy((undefined2 *)(unaff_ER14 + -0x28),(undefined2 *)(unaff_ER14 + -0x3c));
      base_clear(CONCAT11(extraout_R1,*(undefined *)(unaff_ER14 + -10)), (uintptr_t)0)
                     (undefined *)(unaff_ER14 + -0x3c));
    }
    else {
      eval_error(10);
    }
  }
LAB_rom_01072e:
  dec_copy_rev(*(undefined2 **)(unaff_ER14 + -6),(undefined2 *)(unaff_ER14 + -0x28));
  return CONCAT11(extraout_R1_00,*(undefined *)(unaff_ER14 + -9));
}

/**
 * @brief 求值循环分支 C
 * @addr 0x10158
 * @module eval
 * @proto undefined2 eval_loop_c(void)
 * @confidence likely
 * @note 求值循环分支 C：读取 R9（当前层级/优先级），为空时把操作数槽置 0。
 * @tag eval
 */
undefined2 eval_loop_c(void)

{
  char cVar1;
  byte bVar2;
  byte bVar3;
  undefined2 uVar4;
  undefined extraout_R1;
  undefined extraout_R1_00;
  undefined2 *puVar5;
  short sVar6;
  ushort *puVar7;
  ushort uVar8;
  undefined uVar9;
  char unaff_R4;
  byte unaff_R6;
  ushort *unaff_ER10;
  ushort *unaff_ER12;
  short unaff_ER14;
  
  if ((*(char *)(unaff_ER14 + -8) != '\0') && (*(char *)(unaff_ER14 + -7) != '\0')) {
    dec_set_uint_small((ushort *)(unaff_ER14 + -0x50),0);
    *(undefined *)(unaff_ER14 + -7) = 0;
  }
  dec_copy((undefined2 *)(unaff_ER14 + -0x6e),(undefined2 *)(unaff_ER14 + -0x5a));
  puVar5 = (undefined2 *)(unaff_ER14 + -0x3c);
  dec_copy((undefined2 *)(unaff_ER14 + -0x78),puVar5);
  uVar4 = dec_cmp((undefined2 *)(unaff_ER14 + -0x3c),puVar5);
  if ((char)uVar4 == '\x01') {
    puVar5 = (undefined2 *)CONCAT11((char)((ushort)puVar5 >> 8),1);
    dec_set_uint_small((ushort *)(unaff_ER14 + -0x82),1);
    *(undefined2 *)(unaff_ER14 + -0x7a) = 0x85;
  }
  else {
    puVar5 = (undefined2 *)(unaff_ER14 + -0x3c);
    dec_copy((undefined2 *)(unaff_ER14 + -0x82),puVar5);
  }
  cVar1 = eval_cmp_op();
  if (cVar1 != '\0') {
    uVar4 = eval_loop_e(puVar5);
    return uVar4;
  }
  puVar7 = unaff_ER12;
  dec_copy((undefined2 *)(unaff_ER14 + -0xb4),unaff_ER12);
  uVar4 = dec_cmp((undefined2 *)(unaff_ER14 + -0xb4),puVar7);
  if ((char)uVar4 == '\x01') {
    uVar4 = eval_loop_e(puVar7);
    return uVar4;
  }
  dec_copy(unaff_ER12,(undefined2 *)(unaff_ER14 + -0x5a));
  dec_bin_and_core(unaff_ER12,unaff_ER14 + -0xb4);
  dec_copy((undefined2 *)(unaff_ER14 + -0x50),(undefined2 *)(unaff_ER14 + -0x3c));
  dec_bin_or_core(unaff_ER14 + -0x3c,unaff_ER12);
  puVar5 = (undefined2 *)(unaff_ER14 + -0x3c);
  dec_copy((undefined2 *)(unaff_ER14 + -0x46),puVar5);
  bVar2 = eval_get_operand();
  if (bVar2 == 0) {
    cVar1 = eval_shift_op();
    if (cVar1 == '\x01') {
      uVar4 = eval_rotate2();
      return uVar4;
    }
    dec_copy(unaff_ER12,(undefined2 *)(unaff_ER14 + -0x3c));
    sVar6 = unaff_ER14 + -0x78;
    dec_bin_or_core(unaff_ER12,sVar6);
    dec_bin_result(unaff_ER12,sVar6);
    puVar5 = (undefined2 *)(unaff_ER14 + -0x82);
    dec_copy(unaff_ER10,puVar5);
    dec_bin_result(unaff_ER10,puVar5);
    puVar7 = unaff_ER10;
    dec_bin_and_core(unaff_ER12,unaff_ER10);
    dec_bin_result(unaff_ER12,puVar7);
    dec_set_uint_small(unaff_ER10,1);
    if ((*(byte *)(unaff_ER14 + -8) & 1) == 0) {
      if ((*(byte *)(unaff_ER14 + -8) & 4) == 0) {
        uVar4 = 0x87;
      }
      else {
        uVar4 = 0x91;
      }
    }
    else {
      uVar4 = 0x93;
    }
    *(undefined2 *)(unaff_ER14 + -0x16) = uVar4;
    cVar1 = dec_cmp_bool(unaff_ER12);
    if (cVar1 == '\x02') {
      uVar4 = eval_rotate2();
      return uVar4;
    }
    puVar5 = (undefined2 *)(unaff_ER14 + -0x5a);
    dec_copy(unaff_ER12,puVar5);
    dec_bin_result(unaff_ER12,puVar5);
    puVar5 = (undefined2 *)(unaff_ER14 + -0x6e);
    dec_copy(unaff_ER10,puVar5);
    dec_bin_result(unaff_ER10,puVar5);
    dec_bin_or_core(unaff_ER10,unaff_ER12);
    uVar4 = dec_cmp(unaff_ER10,unaff_ER12);
    if ((byte)uVar4 < 4) {
      uVar4 = eval_loop_f(unaff_ER12);
      return uVar4;
    }
    uVar4 = kbd_wait_key();
    if ((byte)uVar4 == 0) {
      if ((byte)(unaff_R4 + 1U) < 0x28) {
        uVar4 = eval_loop_b(unaff_ER12);
        return uVar4;
      }
      uVar4 = eval_func_args((short)unaff_ER12);
      return uVar4;
    }
    eval_error((byte)uVar4);
  }
  else {
    if (0xc < unaff_R6) {
      uVar4 = eval_rotate((short)puVar5);
      return uVar4;
    }
    bVar2 = 0;
    uVar4 = dec_cmp((undefined2 *)(unaff_ER14 + -0x3c),puVar5);
    if (((char)uVar4 == '\x01') &&
       (uVar4 = dec_cmp((undefined2 *)(unaff_ER14 + -0x50),puVar5), (char)uVar4 == '\x01')) {
      uVar4 = eval_rotate((short)puVar5);
      return uVar4;
    }
    do {
      uVar4 = kbd_wait_key();
      if ((byte)uVar4 != 0) {
        eval_error((byte)uVar4);
        goto LAB_rom_01072e;
      }
      bVar3 = bcd_type((byte *)(unaff_ER14 + -0xa0));
      if (((bVar3 != 0) && (bVar3 != 3)) && (bVar3 != 0xb)) {
        eval_error(bVar3);
        goto LAB_rom_01072e;
      }
      bVar2 = bVar2 + 1;
      if (0xe < bVar2) {
        uVar4 = eval_rotate((short)puVar5);
        return uVar4;
      }
      puVar5 = (undefined2 *)(unaff_ER14 + -0x3c);
      dec_copy(unaff_ER12,puVar5);
      dec_bin_result(unaff_ER12,puVar5);
      puVar5 = (undefined2 *)(unaff_ER14 + -0x50);
      dec_copy(unaff_ER10,puVar5);
      dec_bin_result(unaff_ER10,puVar5);
      bVar3 = dec_cmp_bool(unaff_ER12);
      if (bVar3 < 4) {
        dec_copy((undefined2 *)(unaff_ER14 + -0x28),(undefined2 *)(unaff_ER14 + -0x50));
        dec_copy(unaff_ER10,(undefined2 *)(unaff_ER14 + -0x3c));
      }
      else {
        dec_copy((undefined2 *)(unaff_ER14 + -0x28),(undefined2 *)(unaff_ER14 + -0x3c));
        dec_copy(unaff_ER10,(undefined2 *)(unaff_ER14 + -0x50));
      }
      dec_bin_or_core(unaff_ER14 + -0x28,unaff_ER10);
      dec_set_uint_small(unaff_ER10,2);
      dec_bin_and_core(unaff_ER14 + -0x28,unaff_ER10);
      dec_copy(unaff_ER12,(undefined2 *)(unaff_ER14 + -0x3c));
      dec_copy(unaff_ER10,(undefined2 *)(unaff_ER14 + -0x50));
      puVar7 = unaff_ER10;
      bVar3 = dec_cmp_bool(unaff_ER12);
      if (bVar3 < 4) {
        puVar7 = (ushort *)(unaff_ER14 + -0x3c);
        dec_copy(unaff_ER10,puVar7);
      }
      dec_bin_result((ushort *)(unaff_ER14 + -0x28),puVar7);
      dec_bin_xor_core(unaff_ER14 + -0x28,unaff_ER10);
      dec_copy((undefined2 *)(unaff_ER14 + -0x3c),(undefined2 *)(unaff_ER14 + -0x28));
      puVar5 = (undefined2 *)(unaff_ER14 + -0x3c);
      dec_copy((undefined2 *)(unaff_ER14 + -0x46),puVar5);
      bVar3 = eval_get_operand();
    } while (bVar3 != 0);
    cVar1 = eval_shift_op();
    if (cVar1 != '\x01') {
      dec_copy_rev((undefined2 *)(unaff_ER14 + -200),(undefined2 *)(unaff_ER14 + -0xa0));
      puVar5 = (undefined2 *)(unaff_ER14 + -0x3c);
      dec_copy((undefined2 *)(unaff_ER14 + -0x46),puVar5);
      uVar8 = CONCAT11((char)((ushort)puVar5 >> 8),4);
      dec_exp_shift((undefined2 *)(unaff_ER14 + -0x46),uVar8);
      uVar9 = (undefined)(uVar8 >> 8);
      bVar2 = eval_get_operand();
      if ((bVar2 == 0) && (cVar1 = eval_shift_op(), cVar1 == '\x01')) {
        dec_exp_shift((undefined2 *)(unaff_ER14 + -0x3c),CONCAT11(uVar9,4));
        uVar4 = eval_rotate2();
        return uVar4;
      }
      puVar5 = (undefined2 *)(unaff_ER14 + -200);
      dec_copy_rev((undefined2 *)(unaff_ER14 + -0xa0),puVar5);
      uVar4 = eval_loop_a(puVar5);
      return uVar4;
    }
    *(undefined *)(unaff_ER14 + -9) = 0;
    dec_copy((undefined2 *)(unaff_ER14 + -0x46),(undefined2 *)(unaff_ER14 + -0x3c));
    bVar2 = eval_get_operand();
    if (bVar2 == 0) {
      if (*(char *)(unaff_ER14 + -9) == '\0') {
        dec_bin_mul_core(unaff_ER14 + -0xa0,unaff_ER14 + -0x96);
      }
      else {
        dec_bin_or_core(unaff_ER14 + -0xa0,unaff_ER14 + -0x96);
      }
      dec_copy(unaff_ER10,(undefined2 *)(unaff_ER14 + -0xa0));
      dec_copy((undefined2 *)(unaff_ER14 + -0x28),(undefined2 *)(unaff_ER14 + -0x3c));
      base_clear(CONCAT11(extraout_R1,*(undefined *)(unaff_ER14 + -10)), (uintptr_t)0)
                     (undefined *)(unaff_ER14 + -0x3c));
    }
    else {
      eval_error(10);
    }
  }
LAB_rom_01072e:
  dec_copy_rev(*(undefined2 **)(unaff_ER14 + -6),(undefined2 *)(unaff_ER14 + -0x28));
  return CONCAT11(extraout_R1_00,*(undefined *)(unaff_ER14 + -9));
}

/**
 * @brief 求值循环分支 D（跳入 0x10302/0x104AC）
 * @addr 0x101F2
 * @module eval
 * @proto undefined2 eval_loop_d(void)
 * @confidence likely
 * @note 求值循环分支 D（跳入 0x10302/0x104AC）。
 * @tag eval
 */
undefined2 eval_loop_d(void)

{
  byte bVar1;
  char cVar2;
  byte bVar3;
  undefined2 uVar4;
  undefined extraout_R1;
  undefined extraout_R1_00;
  undefined2 *puVar5;
  short sVar6;
  ushort *puVar7;
  ushort uVar8;
  undefined uVar9;
  char unaff_R4;
  byte unaff_R6;
  undefined2 unaff_ER10;
  ushort *puVar10;
  ushort *unaff_ER12;
  short unaff_ER14;
  
  puVar10 = (ushort *)CONCAT11((char)((ushort)unaff_ER10 >> 8),*(undefined *)(unaff_ER12 + 1));
  dec_bin_and_core(unaff_ER12,unaff_ER14 + -0xb4);
  dec_copy((undefined2 *)(unaff_ER14 + -0x50),(undefined2 *)(unaff_ER14 + -0x3c));
  dec_bin_or_core(unaff_ER14 + -0x3c,unaff_ER12);
  puVar5 = (undefined2 *)(unaff_ER14 + -0x3c);
  dec_copy((undefined2 *)(unaff_ER14 + -0x46),puVar5);
  bVar1 = eval_get_operand();
  if (bVar1 == 0) {
    cVar2 = eval_shift_op();
    if (cVar2 == '\x01') {
      uVar4 = eval_rotate2();
      return uVar4;
    }
    dec_copy(unaff_ER12,(undefined2 *)(unaff_ER14 + -0x3c));
    sVar6 = unaff_ER14 + -0x78;
    dec_bin_or_core(unaff_ER12,sVar6);
    dec_bin_result(unaff_ER12,sVar6);
    puVar5 = (undefined2 *)(unaff_ER14 + -0x82);
    dec_copy(puVar10,puVar5);
    dec_bin_result(puVar10,puVar5);
    puVar7 = puVar10;
    dec_bin_and_core(unaff_ER12,puVar10);
    dec_bin_result(unaff_ER12,puVar7);
    dec_set_uint_small(puVar10,1);
    if ((*(byte *)(unaff_ER14 + -8) & 1) == 0) {
      if ((*(byte *)(unaff_ER14 + -8) & 4) == 0) {
        uVar4 = 0x87;
      }
      else {
        uVar4 = 0x91;
      }
    }
    else {
      uVar4 = 0x93;
    }
    *(undefined2 *)(unaff_ER14 + -0x16) = uVar4;
    cVar2 = dec_cmp_bool(unaff_ER12);
    if (cVar2 == '\x02') {
      uVar4 = eval_rotate2();
      return uVar4;
    }
    puVar5 = (undefined2 *)(unaff_ER14 + -0x5a);
    dec_copy(unaff_ER12,puVar5);
    dec_bin_result(unaff_ER12,puVar5);
    puVar5 = (undefined2 *)(unaff_ER14 + -0x6e);
    dec_copy(puVar10,puVar5);
    dec_bin_result(puVar10,puVar5);
    dec_bin_or_core(puVar10,unaff_ER12);
    uVar4 = dec_cmp(puVar10,unaff_ER12);
    if ((byte)uVar4 < 4) {
      uVar4 = eval_loop_f(unaff_ER12);
      return uVar4;
    }
    uVar4 = kbd_wait_key();
    if ((byte)uVar4 == 0) {
      if ((byte)(unaff_R4 + 1U) < 0x28) {
        uVar4 = eval_loop_b(unaff_ER12);
        return uVar4;
      }
      uVar4 = eval_func_args((short)unaff_ER12);
      return uVar4;
    }
    eval_error((byte)uVar4);
  }
  else {
    if (0xc < unaff_R6) {
      uVar4 = eval_rotate((short)puVar5);
      return uVar4;
    }
    bVar1 = 0;
    uVar4 = dec_cmp((undefined2 *)(unaff_ER14 + -0x3c),puVar5);
    if (((char)uVar4 == '\x01') &&
       (uVar4 = dec_cmp((undefined2 *)(unaff_ER14 + -0x50),puVar5), (char)uVar4 == '\x01')) {
      uVar4 = eval_rotate((short)puVar5);
      return uVar4;
    }
    do {
      uVar4 = kbd_wait_key();
      if ((byte)uVar4 != 0) {
        eval_error((byte)uVar4);
        goto LAB_rom_01072e;
      }
      bVar3 = bcd_type((byte *)(unaff_ER14 + -0xa0));
      if (((bVar3 != 0) && (bVar3 != 3)) && (bVar3 != 0xb)) {
        eval_error(bVar3);
        goto LAB_rom_01072e;
      }
      bVar1 = bVar1 + 1;
      if (0xe < bVar1) {
        uVar4 = eval_rotate((short)puVar5);
        return uVar4;
      }
      puVar5 = (undefined2 *)(unaff_ER14 + -0x3c);
      dec_copy(unaff_ER12,puVar5);
      dec_bin_result(unaff_ER12,puVar5);
      puVar5 = (undefined2 *)(unaff_ER14 + -0x50);
      dec_copy(puVar10,puVar5);
      dec_bin_result(puVar10,puVar5);
      bVar3 = dec_cmp_bool(unaff_ER12);
      if (bVar3 < 4) {
        dec_copy((undefined2 *)(unaff_ER14 + -0x28),(undefined2 *)(unaff_ER14 + -0x50));
        dec_copy(puVar10,(undefined2 *)(unaff_ER14 + -0x3c));
      }
      else {
        dec_copy((undefined2 *)(unaff_ER14 + -0x28),(undefined2 *)(unaff_ER14 + -0x3c));
        dec_copy(puVar10,(undefined2 *)(unaff_ER14 + -0x50));
      }
      dec_bin_or_core(unaff_ER14 + -0x28,puVar10);
      dec_set_uint_small(puVar10,2);
      dec_bin_and_core(unaff_ER14 + -0x28,puVar10);
      dec_copy(unaff_ER12,(undefined2 *)(unaff_ER14 + -0x3c));
      dec_copy(puVar10,(undefined2 *)(unaff_ER14 + -0x50));
      puVar7 = puVar10;
      bVar3 = dec_cmp_bool(unaff_ER12);
      if (bVar3 < 4) {
        puVar7 = (ushort *)(unaff_ER14 + -0x3c);
        dec_copy(puVar10,puVar7);
      }
      dec_bin_result((ushort *)(unaff_ER14 + -0x28),puVar7);
      dec_bin_xor_core(unaff_ER14 + -0x28,puVar10);
      dec_copy((undefined2 *)(unaff_ER14 + -0x3c),(undefined2 *)(unaff_ER14 + -0x28));
      puVar5 = (undefined2 *)(unaff_ER14 + -0x3c);
      dec_copy((undefined2 *)(unaff_ER14 + -0x46),puVar5);
      bVar3 = eval_get_operand();
    } while (bVar3 != 0);
    cVar2 = eval_shift_op();
    if (cVar2 != '\x01') {
      dec_copy_rev((undefined2 *)(unaff_ER14 + -200),(undefined2 *)(unaff_ER14 + -0xa0));
      puVar5 = (undefined2 *)(unaff_ER14 + -0x3c);
      dec_copy((undefined2 *)(unaff_ER14 + -0x46),puVar5);
      uVar8 = CONCAT11((char)((ushort)puVar5 >> 8),4);
      dec_exp_shift((undefined2 *)(unaff_ER14 + -0x46),uVar8);
      uVar9 = (undefined)(uVar8 >> 8);
      bVar1 = eval_get_operand();
      if ((bVar1 == 0) && (cVar2 = eval_shift_op(), cVar2 == '\x01')) {
        dec_exp_shift((undefined2 *)(unaff_ER14 + -0x3c),CONCAT11(uVar9,4));
        uVar4 = eval_rotate2();
        return uVar4;
      }
      puVar5 = (undefined2 *)(unaff_ER14 + -200);
      dec_copy_rev((undefined2 *)(unaff_ER14 + -0xa0),puVar5);
      uVar4 = eval_loop_a(puVar5);
      return uVar4;
    }
    *(undefined *)(unaff_ER14 + -9) = 0;
    dec_copy((undefined2 *)(unaff_ER14 + -0x46),(undefined2 *)(unaff_ER14 + -0x3c));
    bVar1 = eval_get_operand();
    if (bVar1 == 0) {
      if (*(char *)(unaff_ER14 + -9) == '\0') {
        dec_bin_mul_core(unaff_ER14 + -0xa0,unaff_ER14 + -0x96);
      }
      else {
        dec_bin_or_core(unaff_ER14 + -0xa0,unaff_ER14 + -0x96);
      }
      dec_copy(puVar10,(undefined2 *)(unaff_ER14 + -0xa0));
      dec_copy((undefined2 *)(unaff_ER14 + -0x28),(undefined2 *)(unaff_ER14 + -0x3c));
      base_clear(CONCAT11(extraout_R1,*(undefined *)(unaff_ER14 + -10)), (uintptr_t)0)
                     (undefined *)(unaff_ER14 + -0x3c));
    }
    else {
      eval_error(10);
    }
  }
LAB_rom_01072e:
  dec_copy_rev(*(undefined2 **)(unaff_ER14 + -6),(undefined2 *)(unaff_ER14 + -0x28));
  return CONCAT11(extraout_R1_00,*(undefined *)(unaff_ER14 + -9));
}

/**
 * @brief 求值循环分支 E（调用 kbd_wait_key 的空闲等待段）
 * @addr 0x10302
 * @module eval
 * @proto undefined2 eval_loop_e(void)
 * @confidence likely
 * @note 求值循环分支 E（调用 kbd_wait_key 的空闲等待段）。
 * @tag eval
 */
undefined2 eval_loop_e(uintptr_t _a2, int _a1)

{
  byte bVar1;
  char cVar2;
  undefined2 uVar3;
  undefined extraout_R1;
  undefined extraout_R1_00;
  undefined2 *puVar4;
  ushort *puVar5;
  ushort uVar6;
  undefined uVar7;
  byte bVar8;
  byte unaff_R6;
  ushort *unaff_ER10;
  ushort *unaff_ER12;
  short unaff_ER14;
  
  if (0xc < unaff_R6) {
    uVar3 = eval_rotate((short)_a1);
    return uVar3;
  }
  bVar8 = 0;
  uVar3 = dec_cmp((undefined2 *)(unaff_ER14 + -0x3c),_a1);
  if (((char)uVar3 == '\x01') &&
     (uVar3 = dec_cmp((undefined2 *)(unaff_ER14 + -0x50),_a1), (char)uVar3 == '\x01')) {
    uVar3 = eval_rotate((short)_a1);
    return uVar3;
  }
  while( true ) {
    uVar3 = kbd_wait_key();
    if ((byte)uVar3 != 0) {
      eval_error((byte)uVar3);
      goto LAB_rom_01072e;
    }
    bVar1 = bcd_type((byte *)(unaff_ER14 + -0xa0));
    if (((bVar1 != 0) && (bVar1 != 3)) && (bVar1 != 0xb)) break;
    bVar8 = bVar8 + 1;
    if (0xe < bVar8) {
      uVar3 = eval_rotate((short)_a1);
      return uVar3;
    }
    puVar4 = (undefined2 *)(unaff_ER14 + -0x3c);
    dec_copy(unaff_ER12,puVar4);
    dec_bin_result(unaff_ER12,puVar4);
    puVar4 = (undefined2 *)(unaff_ER14 + -0x50);
    dec_copy(unaff_ER10,puVar4);
    dec_bin_result(unaff_ER10,puVar4);
    bVar1 = dec_cmp_bool(unaff_ER12);
    if (bVar1 < 4) {
      dec_copy((undefined2 *)(unaff_ER14 + -0x28),(undefined2 *)(unaff_ER14 + -0x50));
      dec_copy(unaff_ER10,(undefined2 *)(unaff_ER14 + -0x3c));
    }
    else {
      dec_copy((undefined2 *)(unaff_ER14 + -0x28),(undefined2 *)(unaff_ER14 + -0x3c));
      dec_copy(unaff_ER10,(undefined2 *)(unaff_ER14 + -0x50));
    }
    dec_bin_or_core(unaff_ER14 + -0x28,unaff_ER10);
    dec_set_uint_small(unaff_ER10,2);
    dec_bin_and_core(unaff_ER14 + -0x28,unaff_ER10);
    dec_copy(unaff_ER12,(undefined2 *)(unaff_ER14 + -0x3c));
    dec_copy(unaff_ER10,(undefined2 *)(unaff_ER14 + -0x50));
    puVar5 = unaff_ER10;
    bVar1 = dec_cmp_bool(unaff_ER12);
    if (bVar1 < 4) {
      puVar5 = (ushort *)(unaff_ER14 + -0x3c);
      dec_copy(unaff_ER10,puVar5);
    }
    dec_bin_result((ushort *)(unaff_ER14 + -0x28),puVar5);
    dec_bin_xor_core(unaff_ER14 + -0x28,unaff_ER10);
    dec_copy((undefined2 *)(unaff_ER14 + -0x3c),(undefined2 *)(unaff_ER14 + -0x28));
    _a1 = (undefined2 *)(unaff_ER14 + -0x3c);
    dec_copy((undefined2 *)(unaff_ER14 + -0x46),_a1);
    bVar1 = eval_get_operand();
    if (bVar1 == 0) {
      cVar2 = eval_shift_op();
      if (cVar2 != '\x01') {
        dec_copy_rev((undefined2 *)(unaff_ER14 + -200),(undefined2 *)(unaff_ER14 + -0xa0));
        puVar4 = (undefined2 *)(unaff_ER14 + -0x3c);
        dec_copy((undefined2 *)(unaff_ER14 + -0x46),puVar4);
        uVar6 = CONCAT11((char)((ushort)puVar4 >> 8),4);
        dec_exp_shift((undefined2 *)(unaff_ER14 + -0x46),uVar6);
        uVar7 = (undefined)(uVar6 >> 8);
        bVar8 = eval_get_operand();
        if ((bVar8 == 0) && (cVar2 = eval_shift_op(), cVar2 == '\x01')) {
          dec_exp_shift((undefined2 *)(unaff_ER14 + -0x3c),CONCAT11(uVar7,4));
          uVar3 = eval_rotate2();
          return uVar3;
        }
        puVar4 = (undefined2 *)(unaff_ER14 + -200);
        dec_copy_rev((undefined2 *)(unaff_ER14 + -0xa0),puVar4);
        uVar3 = eval_loop_a(puVar4);
        return uVar3;
      }
      *(undefined *)(unaff_ER14 + -9) = 0;
      dec_copy((undefined2 *)(unaff_ER14 + -0x46),(undefined2 *)(unaff_ER14 + -0x3c));
      bVar8 = eval_get_operand();
      if (bVar8 == 0) {
        if (*(char *)(unaff_ER14 + -9) == '\0') {
          dec_bin_mul_core(unaff_ER14 + -0xa0,unaff_ER14 + -0x96);
        }
        else {
          dec_bin_or_core(unaff_ER14 + -0xa0,unaff_ER14 + -0x96);
        }
        dec_copy(unaff_ER10,(undefined2 *)(unaff_ER14 + -0xa0));
        dec_copy((undefined2 *)(unaff_ER14 + -0x28),(undefined2 *)(unaff_ER14 + -0x3c));
        base_clear(CONCAT11(extraout_R1,*(undefined *)(unaff_ER14 + -10)), (uintptr_t)0)
                       (undefined *)(unaff_ER14 + -0x3c));
      }
      else {
        eval_error(10);
      }
LAB_rom_01072e:
      dec_copy_rev(*(undefined2 **)(unaff_ER14 + -6),(undefined2 *)(unaff_ER14 + -0x28));
      return CONCAT11(extraout_R1_00,*(undefined *)(unaff_ER14 + -9));
    }
  }
  eval_error(bVar1);
  goto LAB_rom_01072e;
}

/**
 * @brief 求值循环分支 F（调用 0x105E2/0x10674）
 * @addr 0x104AC
 * @module eval
 * @proto undefined2 eval_loop_f(void)
 * @confidence likely
 * @note 求值循环分支 F（调用 0x105E2/0x10674）。
 * @tag eval
 */
undefined2 eval_loop_f(uintptr_t _a2, int _a1)

{
  char cVar1;
  byte bVar2;
  byte bVar3;
  undefined2 uVar4;
  undefined extraout_R1;
  undefined extraout_R1_00;
  ushort *puVar5;
  ushort uVar6;
  undefined uVar9;
  undefined2 *puVar7;
  short sVar8;
  undefined2 unaff_ER6;
  byte unaff_R8;
  ushort *unaff_ER10;
  ushort *unaff_ER12;
  short unaff_ER14;
  
  cVar1 = eval_cmp_op();
  if (cVar1 != '\0') {
    uVar4 = eval_loop_e(_a1);
    return uVar4;
  }
  uVar4 = dec_cmp((undefined2 *)(unaff_ER14 + -0xb4),_a1);
  if (((char)uVar4 == '\x02') && (uVar4 = dec_cmp(unaff_ER12,_a1), (char)uVar4 == '\x04')
     ) {
    uVar4 = eval_rotate((short)_a1);
    return uVar4;
  }
  uVar4 = dec_cmp((undefined2 *)(unaff_ER14 + -0xb4),_a1);
  if (((char)uVar4 == '\x04') && (uVar4 = dec_cmp(unaff_ER12,_a1), (char)uVar4 == '\x02')
     ) {
    uVar4 = eval_rotate((short)_a1);
    return uVar4;
  }
  if ((char)(((byte)((ushort)unaff_ER6 >> 8) < 0x32) << 7) < '\0') {
    bVar3 = 0;
    do {
      uVar4 = kbd_wait_key();
      if ((byte)uVar4 != 0) {
        eval_error((byte)uVar4);
        goto LAB_rom_01072e;
      }
      bVar3 = bVar3 + 1;
      if (0x1d < bVar3) goto code_s0x0105e2;
      dec_copy(unaff_ER12,(undefined2 *)(unaff_ER14 + -0x50));
      dec_bin_or_core(unaff_ER12,unaff_ER14 + -0x3c);
      *(undefined2 *)(unaff_ER14 + -0x1e) = 0x6606;
      *(undefined2 *)(unaff_ER14 + -0x1c) = 0x6666;
      *(undefined2 *)(unaff_ER14 + -0x1a) = 0x6666;
      *(undefined2 *)(unaff_ER14 + -0x18) = 0x6666;
      *(undefined2 *)(unaff_ER14 + -0x16) = 0x99;
      dec_bin_pow_core(unaff_ER12,unaff_ER10);
      dec_bin_xor_core(unaff_ER14 + -0x3c,unaff_ER12);
      puVar7 = (undefined2 *)(unaff_ER14 + -0x3c);
      dec_copy((undefined2 *)(unaff_ER14 + -0x46),puVar7);
      bVar2 = eval_get_operand();
      if (bVar2 != 0) goto LAB_rom_01032a;
      dec_copy(unaff_ER12,(undefined2 *)(unaff_ER14 + -0xa0));
      sVar8 = unaff_ER14 + -0x96;
      dec_bin_or_core(unaff_ER12,sVar8);
      dec_bin_result(unaff_ER12,sVar8);
      puVar7 = (undefined2 *)(unaff_ER14 + -0x6e);
      dec_copy(unaff_ER10,puVar7);
      dec_bin_result(unaff_ER10,puVar7);
      _a1 = unaff_ER10;
      cVar1 = dec_cmp_bool(unaff_ER12);
    } while ((cVar1 != '\x02') && (cVar1 != -0x10));
    dec_copy_rev((undefined2 *)(unaff_ER14 + -200),(undefined2 *)(unaff_ER14 + -0xa0));
    uVar4 = eval_round_op();
    if ((char)uVar4 != '\0') {
      puVar7 = (undefined2 *)(unaff_ER14 + -200);
      dec_copy_rev((undefined2 *)(unaff_ER14 + -0xa0),puVar7);
      uVar4 = eval_loop_a(puVar7);
      return uVar4;
    }
    dec_copy((undefined2 *)(unaff_ER14 + -0x3c),(undefined2 *)(unaff_ER14 + -0x32));
    goto LAB_rom_0106d8;
  }
  uVar4 = eval_round_op_b();
  if ((char)uVar4 == '\0') {
LAB_rom_0106cc:
    dec_copy((undefined2 *)(unaff_ER14 + -0x3c),(undefined2 *)(unaff_ER14 + -0x32));
    goto LAB_rom_0106d8;
  }
  uVar4 = eval_conv_op();
  if ((char)uVar4 != '\x02') {
    if ((char)uVar4 == '\0') goto LAB_rom_0106cc;
    cVar1 = dec_cmp_swap((undefined2 *)(unaff_ER14 + -0x3c));
    if (cVar1 == '\x01') goto LAB_rom_010692;
    *(undefined *)(unaff_ER14 + -9) = 0x24;
    goto LAB_rom_0106dc;
  }
  goto LAB_rom_010692;
code_s0x0105e2:
  unaff_R8 = unaff_R8 + 1;
  if (9 < unaff_R8) {
LAB_rom_0105e8:
    eval_error(10);
    goto LAB_rom_01072e;
  }
  if (unaff_R8 == 1) {
    dec_set_uint_small((ushort *)(unaff_ER14 + -0x46),0);
  }
  else {
    if ((*(byte *)(unaff_ER14 + -8) & 1) == 0) {
      if ((*(byte *)(unaff_ER14 + -8) & 4) == 0) {
        if (unaff_R8 == 2) {
          unaff_R8 = 4;
        }
        goto LAB_rom_01062c;
      }
      if (3 < unaff_R8) {
        if (unaff_R8 == 8) goto LAB_rom_0105e8;
        goto LAB_rom_01062c;
      }
      dec_set_from_fmt(unaff_ER14 + -0x46,CONCAT11((char)((ushort)_a1 >> 8),0xf));
    }
    else {
      if (unaff_R8 == 4) {
        unaff_R8 = 8;
      }
LAB_rom_01062c:
      dec_set_uint_small((ushort *)(unaff_ER14 + -0x46),1);
    }
    *(undefined2 *)(unaff_ER14 + -0x3e) = *(undefined2 *)((byte)((unaff_R8 - 2) * '\x02') + 0x342a);
  }
  _a1 = (ushort *)(unaff_ER14 + -0x8c);
  cVar1 = dec_cmp_swap((undefined2 *)(unaff_ER14 + -0x46));
  if (cVar1 != '\x01') {
    uVar4 = eval_loop_shift();
    return uVar4;
  }
  goto code_s0x0105e2;
  while( true ) {
    bVar3 = bVar3 + 1;
    if (0xe < bVar3) {
      uVar4 = eval_rotate((short)puVar7);
      return uVar4;
    }
    puVar7 = (undefined2 *)(unaff_ER14 + -0x3c);
    dec_copy(unaff_ER12,puVar7);
    dec_bin_result(unaff_ER12,puVar7);
    puVar7 = (undefined2 *)(unaff_ER14 + -0x50);
    dec_copy(unaff_ER10,puVar7);
    dec_bin_result(unaff_ER10,puVar7);
    bVar2 = dec_cmp_bool(unaff_ER12);
    if (bVar2 < 4) {
      dec_copy((undefined2 *)(unaff_ER14 + -0x28),(undefined2 *)(unaff_ER14 + -0x50));
      dec_copy(unaff_ER10,(undefined2 *)(unaff_ER14 + -0x3c));
    }
    else {
      dec_copy((undefined2 *)(unaff_ER14 + -0x28),(undefined2 *)(unaff_ER14 + -0x3c));
      dec_copy(unaff_ER10,(undefined2 *)(unaff_ER14 + -0x50));
    }
    dec_bin_or_core(unaff_ER14 + -0x28,unaff_ER10);
    dec_set_uint_small(unaff_ER10,2);
    dec_bin_and_core(unaff_ER14 + -0x28,unaff_ER10);
    dec_copy(unaff_ER12,(undefined2 *)(unaff_ER14 + -0x3c));
    dec_copy(unaff_ER10,(undefined2 *)(unaff_ER14 + -0x50));
    puVar5 = unaff_ER10;
    bVar2 = dec_cmp_bool(unaff_ER12);
    if (bVar2 < 4) {
      puVar5 = (ushort *)(unaff_ER14 + -0x3c);
      dec_copy(unaff_ER10,puVar5);
    }
    dec_bin_result((ushort *)(unaff_ER14 + -0x28),puVar5);
    dec_bin_xor_core(unaff_ER14 + -0x28,unaff_ER10);
    dec_copy((undefined2 *)(unaff_ER14 + -0x3c),(undefined2 *)(unaff_ER14 + -0x28));
    puVar7 = (undefined2 *)(unaff_ER14 + -0x3c);
    dec_copy((undefined2 *)(unaff_ER14 + -0x46),puVar7);
    bVar2 = eval_get_operand();
    if (bVar2 == 0) break;
LAB_rom_01032a:
    uVar4 = kbd_wait_key();
    if ((byte)uVar4 != 0) {
      eval_error((byte)uVar4);
      goto LAB_rom_01072e;
    }
    bVar2 = bcd_type((byte *)(unaff_ER14 + -0xa0));
    if (((bVar2 != 0) && (bVar2 != 3)) && (bVar2 != 0xb)) {
      eval_error(bVar2);
      goto LAB_rom_01072e;
    }
  }
  cVar1 = eval_shift_op();
  if (cVar1 != '\x01') {
    dec_copy_rev((undefined2 *)(unaff_ER14 + -200),(undefined2 *)(unaff_ER14 + -0xa0));
    puVar7 = (undefined2 *)(unaff_ER14 + -0x3c);
    dec_copy((undefined2 *)(unaff_ER14 + -0x46),puVar7);
    uVar6 = CONCAT11((char)((ushort)puVar7 >> 8),4);
    dec_exp_shift((undefined2 *)(unaff_ER14 + -0x46),uVar6);
    uVar9 = (undefined)(uVar6 >> 8);
    bVar3 = eval_get_operand();
    if ((bVar3 == 0) && (cVar1 = eval_shift_op(), cVar1 == '\x01')) {
      dec_exp_shift((undefined2 *)(unaff_ER14 + -0x3c),CONCAT11(uVar9,4));
      uVar4 = eval_rotate2();
      return uVar4;
    }
    puVar7 = (undefined2 *)(unaff_ER14 + -200);
    dec_copy_rev((undefined2 *)(unaff_ER14 + -0xa0),puVar7);
    uVar4 = eval_loop_a(puVar7);
    return uVar4;
  }
LAB_rom_0106d8:
  *(undefined *)(unaff_ER14 + -9) = 0;
LAB_rom_0106dc:
  dec_copy((undefined2 *)(unaff_ER14 + -0x46),(undefined2 *)(unaff_ER14 + -0x3c));
  bVar3 = eval_get_operand();
  if (bVar3 == 0) {
    if (*(char *)(unaff_ER14 + -9) == '\0') {
      dec_bin_mul_core(unaff_ER14 + -0xa0,unaff_ER14 + -0x96);
    }
    else {
      dec_bin_or_core(unaff_ER14 + -0xa0,unaff_ER14 + -0x96);
    }
    dec_copy(unaff_ER10,(undefined2 *)(unaff_ER14 + -0xa0));
    dec_copy((undefined2 *)(unaff_ER14 + -0x28),(undefined2 *)(unaff_ER14 + -0x3c));
    base_clear(CONCAT11(extraout_R1,*(undefined *)(unaff_ER14 + -10)), (uintptr_t)0)
                   (undefined *)(unaff_ER14 + -0x3c));
    goto LAB_rom_01072e;
  }
LAB_rom_010692:
  eval_error(10);
LAB_rom_01072e:
  dec_copy_rev(*(undefined2 **)(unaff_ER14 + -6),(undefined2 *)(unaff_ER14 + -0x28));
  return CONCAT11(extraout_R1_00,*(undefined *)(unaff_ER14 + -9));
}

/**
 * @brief 操作数寄存器轮换
 * @addr 0x105E2
 * @module eval
 * @proto undefined2 eval_rotate(void)
 * @confidence likely
 * @note 操作数寄存器轮换：把 0xD020/0xD010 系列轮转（用于连续二元运算的暂存）。
 * @tag eval
 */
undefined2 eval_rotate(uintptr_t _a2, int _a1)

{
  char cVar1;
  undefined2 uVar2;
  undefined extraout_R1;
  byte unaff_R8;
  short unaff_ER14;
  
  do {
    unaff_R8 = unaff_R8 + 1;
    if (9 < unaff_R8) {
LAB_rom_0105e8:
      eval_error(10);
      dec_copy_rev(*(undefined2 **)(unaff_ER14 + -6),(undefined2 *)(unaff_ER14 + -0x28));
      return CONCAT11(extraout_R1,*(undefined *)(unaff_ER14 + -9));
    }
    if (unaff_R8 == 1) {
      dec_set_uint_small((ushort *)(unaff_ER14 + -0x46),0);
    }
    else {
      if ((*(byte *)(unaff_ER14 + -8) & 1) == 0) {
        if ((*(byte *)(unaff_ER14 + -8) & 4) == 0) {
          if (unaff_R8 == 2) {
            unaff_R8 = 4;
          }
          goto LAB_rom_01062c;
        }
        if (3 < unaff_R8) {
          if (unaff_R8 == 8) goto LAB_rom_0105e8;
          goto LAB_rom_01062c;
        }
        dec_set_from_fmt(unaff_ER14 + -0x46,CONCAT11((char)((ushort)_a1 >> 8),0xf));
      }
      else {
        if (unaff_R8 == 4) {
          unaff_R8 = 8;
        }
LAB_rom_01062c:
        dec_set_uint_small((ushort *)(unaff_ER14 + -0x46),1);
      }
      *(undefined2 *)(unaff_ER14 + -0x3e) =
           *(undefined2 *)((byte)((unaff_R8 - 2) * '\x02') + 0x342a);
    }
    _a1 = unaff_ER14 + -0x8c;
    cVar1 = dec_cmp_swap((undefined2 *)(unaff_ER14 + -0x46));
    if (cVar1 != '\x01') {
      uVar2 = eval_loop_shift();
      return uVar2;
    }
  } while( true );
}

/**
 * @brief 操作数寄存器轮换的变体
 * @addr 0x10674
 * @module eval
 * @proto undefined2 eval_rotate2(void)
 * @confidence likely
 * @note 操作数寄存器轮换的变体。
 * @tag eval
 */
undefined2 eval_rotate2(void)

{
  byte bVar1;
  undefined2 uVar2;
  undefined extraout_R1;
  undefined extraout_R1_00;
  undefined2 *unaff_ER10;
  short unaff_ER14;
  
  uVar2 = eval_round_op_b();
  if ((char)uVar2 == '\0') {
LAB_rom_01067c:
    dec_copy((undefined2 *)(unaff_ER14 + -0x3c),(undefined2 *)(unaff_ER14 + -0x32));
LAB_rom_0106d8:
    *(undefined *)(unaff_ER14 + -9) = 0;
    dec_copy((undefined2 *)(unaff_ER14 + -0x46),(undefined2 *)(unaff_ER14 + -0x3c));
    bVar1 = eval_get_operand();
    if (bVar1 == 0) {
      if (*(char *)(unaff_ER14 + -9) == '\0') {
        dec_bin_mul_core(unaff_ER14 + -0xa0,unaff_ER14 + -0x96);
      }
      else {
        dec_bin_or_core(unaff_ER14 + -0xa0,unaff_ER14 + -0x96);
      }
      dec_copy(unaff_ER10,(undefined2 *)(unaff_ER14 + -0xa0));
      dec_copy((undefined2 *)(unaff_ER14 + -0x28),(undefined2 *)(unaff_ER14 + -0x3c));
      base_clear(CONCAT11(extraout_R1,*(undefined *)(unaff_ER14 + -10)), (uintptr_t)0)
                     (undefined *)(unaff_ER14 + -0x3c));
      goto LAB_rom_01072e;
    }
  }
  else {
    uVar2 = eval_conv_op();
    if ((char)uVar2 != '\x02') {
      if ((char)uVar2 == '\0') goto LAB_rom_01067c;
      goto LAB_rom_0106d8;
    }
  }
  eval_error(10);
LAB_rom_01072e:
  dec_copy_rev(*(undefined2 **)(unaff_ER14 + -6),(undefined2 *)(unaff_ER14 + -0x28));
  return CONCAT11(extraout_R1_00,*(undefined *)(unaff_ER14 + -9));
}

/**
 * @brief 函数参数求值（2.8KB，0x100BC/0x1010C/0x10118 调用）
 * @addr 0x106A0
 * @module eval
 * @proto int eval_func_args(void)
 * @confidence likely
 * @note 函数参数求值（2.8KB，0x100BC/0x1010C/0x10118 调用）。
 * @tag eval
 */
int eval_func_args(uintptr_t _a2, int _a1)

{
  char cVar1;
  byte bVar2;
  undefined2 uVar3;
  undefined extraout_R1;
  undefined extraout_R1_00;
  char unaff_R6;
  byte unaff_R8;
  undefined2 *unaff_ER10;
  short unaff_ER14;
  
  if (unaff_R6 != '\0') {
    while (unaff_R8 = unaff_R8 + 1, (char)((unaff_R8 < 10) << 7) < '\0') {
      if (unaff_R8 == 1) {
        dec_set_uint_small((ushort *)(unaff_ER14 + -0x46),0);
      }
      else {
        if ((*(byte *)(unaff_ER14 + -8) & 1) == 0) {
          if ((*(byte *)(unaff_ER14 + -8) & 4) == 0) {
            if (unaff_R8 == 2) {
              unaff_R8 = 4;
            }
            goto LAB_rom_01062c;
          }
          if (3 < unaff_R8) {
            if (unaff_R8 == 8) break;
            goto LAB_rom_01062c;
          }
          dec_set_from_fmt(unaff_ER14 + -0x46,CONCAT11((char)((ushort)_a1 >> 8),0xf));
        }
        else {
          if (unaff_R8 == 4) {
            unaff_R8 = 8;
          }
LAB_rom_01062c:
          dec_set_uint_small((ushort *)(unaff_ER14 + -0x46),1);
        }
        *(undefined2 *)(unaff_ER14 + -0x3e) =
             *(undefined2 *)((byte)((unaff_R8 - 2) * '\x02') + 0x342a);
      }
      _a1 = unaff_ER14 + -0x8c;
      cVar1 = dec_cmp_swap((undefined2 *)(unaff_ER14 + -0x46));
      if (cVar1 != '\x01') {
        uVar3 = eval_loop_shift();
        return uVar3;
      }
    }
    eval_error(10);
    goto LAB_rom_01072e;
  }
  uVar3 = eval_round_op_b();
  if ((char)uVar3 == '\0') {
LAB_rom_0106cc:
    dec_copy((undefined2 *)(unaff_ER14 + -0x3c),(undefined2 *)(unaff_ER14 + -0x32));
    *(undefined *)(unaff_ER14 + -9) = 0;
LAB_rom_0106dc:
    dec_copy((undefined2 *)(unaff_ER14 + -0x46),(undefined2 *)(unaff_ER14 + -0x3c));
    bVar2 = eval_get_operand();
    if (bVar2 == 0) {
      if (*(char *)(unaff_ER14 + -9) == '\0') {
        dec_bin_mul_core(unaff_ER14 + -0xa0,unaff_ER14 + -0x96);
      }
      else {
        dec_bin_or_core(unaff_ER14 + -0xa0,unaff_ER14 + -0x96);
      }
      dec_copy(unaff_ER10,(undefined2 *)(unaff_ER14 + -0xa0));
      dec_copy((undefined2 *)(unaff_ER14 + -0x28),(undefined2 *)(unaff_ER14 + -0x3c));
      base_clear(CONCAT11(extraout_R1,*(undefined *)(unaff_ER14 + -10)), (uintptr_t)0)
                     (undefined *)(unaff_ER14 + -0x3c));
      goto LAB_rom_01072e;
    }
  }
  else {
    uVar3 = eval_conv_op();
    if ((char)uVar3 != '\x02') {
      if ((char)uVar3 == '\0') goto LAB_rom_0106cc;
      cVar1 = dec_cmp_swap((undefined2 *)(unaff_ER14 + -0x3c));
      if (cVar1 == '\x01') goto LAB_rom_010692;
      *(undefined *)(unaff_ER14 + -9) = 0x24;
      goto LAB_rom_0106dc;
    }
  }
LAB_rom_010692:
  eval_error(10);
LAB_rom_01072e:
  dec_copy_rev(*(undefined2 **)(unaff_ER14 + -6),(undefined2 *)(unaff_ER14 + -0x28));
  return CONCAT11(extraout_R1_00,*(undefined *)(unaff_ER14 + -9));
}

/**
 * @brief 比较运算求值（0x10B3E 逻辑段后 0x1D9EC 链）
 * @addr 0x1074C
 * @module eval
 * @proto int eval_compare_op(void)
 * @confidence likely
 * @note 比较运算求值（0x10B3E 逻辑段后 0x1D9EC 链）。
 * @tag eval
 */
int eval_compare_op(uintptr_t _a2, int _a1)

{
  byte bVar1;
  undefined extraout_R1;
  undefined extraout_R1_00;
  ushort uVar2;
  undefined2 uVar3;
  undefined2 *unaff_ER10;
  short unaff_ER14;
  
  uVar2 = eval_logic_op();
  if ((char)uVar2 != '\0') {
    if ((char)uVar2 == '\n') {
      uVar3 = eval_loop_c();
      return uVar3;
    }
    uVar3 = eval_loop_e(_a1);
    return uVar3;
  }
  uVar3 = eval_round_op_b();
  if ((char)uVar3 == '\0') {
LAB_rom_01067c:
    dec_copy((undefined2 *)(unaff_ER14 + -0x3c),(undefined2 *)(unaff_ER14 + -0x32));
LAB_rom_0106d8:
    *(undefined *)(unaff_ER14 + -9) = 0;
    dec_copy((undefined2 *)(unaff_ER14 + -0x46),(undefined2 *)(unaff_ER14 + -0x3c));
    bVar1 = eval_get_operand();
    if (bVar1 == 0) {
      if (*(char *)(unaff_ER14 + -9) == '\0') {
        dec_bin_mul_core(unaff_ER14 + -0xa0,unaff_ER14 + -0x96);
      }
      else {
        dec_bin_or_core(unaff_ER14 + -0xa0,unaff_ER14 + -0x96);
      }
      dec_copy(unaff_ER10,(undefined2 *)(unaff_ER14 + -0xa0));
      dec_copy((undefined2 *)(unaff_ER14 + -0x28),(undefined2 *)(unaff_ER14 + -0x3c));
      base_clear(CONCAT11(extraout_R1,*(undefined *)(unaff_ER14 + -10)), (uintptr_t)0)
                     (undefined *)(unaff_ER14 + -0x3c));
      goto LAB_rom_01072e;
    }
  }
  else {
    uVar3 = eval_conv_op();
    if ((char)uVar3 != '\x02') {
      if ((char)uVar3 == '\0') goto LAB_rom_01067c;
      goto LAB_rom_0106d8;
    }
  }
  eval_error(10);
LAB_rom_01072e:
  dec_copy_rev(*(undefined2 **)(unaff_ER14 + -6),(undefined2 *)(unaff_ER14 + -0x28));
  return CONCAT11(extraout_R1_00,*(undefined *)(unaff_ER14 + -9));
}

/**
 * @brief 转换/取整求值（0x1D66E 初始 + 参数槽）
 * @addr 0x10764
 * @module eval
 * @proto int eval_conv_op(void)
 * @confidence likely
 * @note 转换/取整求值（0x1D66E 初始 + 参数槽）。
 * @tag eval
 */
int eval_conv_op(void)

{
  byte bVar1;
  undefined extraout_R1;
  undefined extraout_R1_00;
  undefined2 uVar2;
  undefined2 *puVar3;
  char cVar4;
  short unaff_ER14;
  
  if ((*(byte *)(unaff_ER14 + -8) & 1) == 0) {
    cVar4 = '\x06';
  }
  else {
    cVar4 = '\x04';
  }
  while( true ) {
    while( true ) {
      puVar3 = (undefined2 *)(unaff_ER14 + -0x3c);
      dec_copy((undefined2 *)(unaff_ER14 + -0x32),puVar3);
      dec_exp_shift((undefined2 *)(unaff_ER14 + -0x32),CONCAT11((char)((ushort)puVar3 >> 8),cVar4))
      ;
      bVar1 = bcd_type((byte *)(unaff_ER14 + -0x32));
      if (bVar1 != 0) {
        return CONCAT11(extraout_R1,1);
      }
      dec_copy((undefined2 *)(unaff_ER14 + -0x46),(undefined2 *)(unaff_ER14 + -0x32));
      bVar1 = eval_get_operand();
      if (bVar1 != 0) {
        return CONCAT11(extraout_R1_00,2);
      }
      if (*(char *)(unaff_ER14 + -8) == '\0') {
        uVar2 = dec_cmp_bool((undefined2 *)(unaff_ER14 + -0x96));
      }
      else {
        uVar2 = dec_cmp_swap((undefined2 *)(unaff_ER14 + -0x96));
      }
      bVar1 = (byte)((ushort)uVar2 >> 8);
      if ((char)uVar2 == '\x01') {
        return (ushort)bVar1 << 8;
      }
      if ((*(byte *)(unaff_ER14 + -8) & 1) != 0) break;
      if (cVar4 == '\v') goto LAB_rom_0107ec;
      cVar4 = '\v';
    }
    if (cVar4 == '\x06') break;
    cVar4 = '\x06';
  }
LAB_rom_0107ec:
  return CONCAT11(bVar1,1);
}

/**
 * @brief 数值取整/舍入求值（0x1D66E(1) 链）
 * @addr 0x107F4
 * @module eval
 * @proto int eval_round_op(void)
 * @confidence likely
 * @note 数值取整/舍入求值（0x1D66E(1) 链）。
 * @tag eval
 */
int eval_round_op(void)

{
  byte bVar1;
  undefined2 uVar2;
  undefined extraout_R1;
  undefined2 *puVar3;
  ushort *unaff_ER10;
  ushort *unaff_ER12;
  short unaff_ER14;
  
  dec_set_uint_small(unaff_ER10,1);
  *(undefined2 *)(unaff_ER14 + -0x16) = 0x50;
  puVar3 = (undefined2 *)(unaff_ER14 + -0x3c);
  dec_copy(unaff_ER12,puVar3);
  dec_bin_result(unaff_ER12,puVar3);
  uVar2 = dec_cmp_bool(unaff_ER12);
  if ((char)uVar2 == '\x02') {
    dec_set_uint_small((ushort *)(unaff_ER14 + -0x32),0);
    dec_copy((undefined2 *)(unaff_ER14 + -0x46),(undefined2 *)(unaff_ER14 + -0x32));
    bVar1 = eval_get_operand();
    if (bVar1 == 0) {
      uVar2 = dec_cmp_bool((undefined2 *)(unaff_ER14 + -0x96));
      bVar1 = (byte)((ushort)uVar2 >> 8);
      if ((char)uVar2 == '\x01') {
        return (ushort)bVar1 << 8;
      }
      uVar2 = CONCAT11(bVar1,1);
    }
    else {
      uVar2 = CONCAT11(extraout_R1,1);
    }
  }
  else {
    uVar2 = CONCAT11((char)((ushort)uVar2 >> 8),1);
  }
  return uVar2;
}

