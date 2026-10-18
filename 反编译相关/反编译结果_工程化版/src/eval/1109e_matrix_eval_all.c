/*
 * 表达式求值 / 1109e_matrix_eval_all.c
 * 地址范围: 0x1109E - 0x115E2
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 矩阵整体求值（1.1KB）
 * @addr 0x1109E
 * @module eval
 * @proto int matrix_eval_all(undefined2* a)
 * @confidence likely
 * @note 矩阵整体求值（1.1KB）：按单元类型 4 分派
 *       0x112CA/0x1125E/0x111BC/0x11140/0x11474。
 * @tag matrix
 */
int matrix_eval_all(undefined2* a)

{
  int cVar1;
  undefined uVar2;
  ushort uVar3;
  undefined2 uVar4;
  short unaff_ER14;
  
  uVar3 = matrix_cell_chain();
  cVar1 = (char)uVar3;
  if (cVar1 == '\0') {
    uVar4 = dec_cmp((undefined2 *)(unaff_ER14 + -0x46),a);
    if ((char)uVar4 == '\x04') {
      cVar1 = matrix_cell_pow();
      if ((((cVar1 == '\0') && (cVar1 = dec_op_pow_mul_b(), cVar1 == '\0')) &&
          (cVar1 = dec_op_pow_mul(), cVar1 == '\0')) &&
         (((cVar1 = dec_op_seq_c(), cVar1 == '\0' && (cVar1 = matrix_cell_int(), cVar1 == '\0')) &&
          (cVar1 = dec_op_mixed(), cVar1 == '\0')))) {
        return 0;
      }
    }
    else {
      cVar1 = '\x03';
    }
  }
  if (cVar1 == '\x01') {
    dec_set_special((ushort *)(unaff_ER14 + -200),1);
    dec_set_special((ushort *)(unaff_ER14 + -0xbe),1);
    dec_set_special((ushort *)(unaff_ER14 + -0xb4),1);
    uVar2 = 1;
  }
  else {
    dec_set_special((ushort *)(unaff_ER14 + -200),3);
    dec_set_special((ushort *)(unaff_ER14 + -0xbe),3);
    dec_set_special((ushort *)(unaff_ER14 + -0xb4),3);
    uVar2 = 3;
  }
  return uVar2;
}

/**
 * @brief 矩阵单元运算序列 C（0xB4/0xA0 操作数 0x1C86C 链）
 * @addr 0x11140
 * @module eval
 * @proto int dec_op_seq_c(void)
 * @confidence likely
 * @note 矩阵单元运算序列 C（0xB4/0xA0 操作数 0x1C86C 链）。
 * @tag matrix
 */
int dec_op_seq_c(void)

{
  short sVar1;
  undefined2 *puVar2;
  undefined2 *puVar3;
  short unaff_ER14;
  
  puVar3 = (undefined2 *)(unaff_ER14 + -0x14);
  puVar2 = (undefined2 *)(unaff_ER14 + -0x1e);
  dec_copy(puVar3,(undefined2 *)(unaff_ER14 + -0x78));
  dec_copy(puVar2,(undefined2 *)(unaff_ER14 + -0xbe));
  dec_bin_pow_core(puVar2,unaff_ER14 + -100);
  dec_bin_mul_core(puVar3,puVar2);
  dec_copy(puVar2,(undefined2 *)(unaff_ER14 + -200));
  dec_bin_pow_core(puVar2,unaff_ER14 + -0x6e);
  dec_bin_mul_core(puVar3,puVar2);
  sVar1 = unaff_ER14 + -0x46;
  dec_bin_and_core(puVar3,sVar1);
  dec_cmp_ex(puVar3,sVar1);
  dec_copy((undefined2 *)(unaff_ER14 + -0xb4),puVar3);
  bcd_type((byte *)puVar3);
  return 0;
}

/**
 * @brief 矩阵单元乘方（0x113..）
 * @addr 0x112CA
 * @module eval
 * @proto int matrix_cell_pow(void)
 * @confidence likely
 * @note 矩阵单元乘方（0x113..）。
 * @tag matrix
 */
int matrix_cell_pow(void)

{
  byte bVar1;
  undefined2 *puVar2;
  undefined2 *puVar3;
  undefined2 *puVar4;
  short unaff_ER14;
  
  puVar4 = (undefined2 *)(unaff_ER14 + -0x14);
  puVar3 = (undefined2 *)(unaff_ER14 + -0x1e);
  puVar2 = (undefined2 *)(unaff_ER14 + -100);
  dec_copy(puVar4,puVar2);
  decm_pow(puVar4,puVar2);
  dec_copy(puVar3,(undefined2 *)(unaff_ER14 + -0x6e));
  dec_bin_pow_core(puVar3,unaff_ER14 + -0x46);
  dec_bin_mul_core(puVar3,puVar4);
  dec_copy((undefined2 *)(unaff_ER14 + -0xb4),puVar3);
  bVar1 = bcd_type((byte *)puVar3);
  if (bVar1 == 0) {
    dec_copy(puVar4,(undefined2 *)(unaff_ER14 + -100));
    dec_bin_pow_core(puVar4,unaff_ER14 + -0x78);
    dec_bin_pow_core(unaff_ER14 + -0x8c,unaff_ER14 + -0x46);
    dec_bin_mul_core(unaff_ER14 + -0x8c,puVar4);
    bVar1 = bcd_type((byte *)(unaff_ER14 + -0x8c));
    if (bVar1 == 0) {
      dec_copy(puVar4,(undefined2 *)(unaff_ER14 + -100));
      dec_bin_pow_core(puVar4,unaff_ER14 + -0x6e);
      dec_bin_pow_core(unaff_ER14 + -0x96,unaff_ER14 + -0x46);
      dec_bin_mul_core(unaff_ER14 + -0x96,puVar4);
      bVar1 = bcd_type((byte *)(unaff_ER14 + -0x96));
      if (bVar1 == 0) {
        puVar2 = (undefined2 *)(unaff_ER14 + -0x6e);
        dec_copy(puVar4,puVar2);
        decm_pow(puVar4,puVar2);
        dec_bin_pow_core(unaff_ER14 + -0xa0,unaff_ER14 + -0x46);
        dec_bin_mul_core(unaff_ER14 + -0xa0,puVar4);
        bVar1 = bcd_type((byte *)(unaff_ER14 + -0xa0));
        if (bVar1 == 0) {
          dec_copy(puVar4,(undefined2 *)(unaff_ER14 + -0x6e));
          dec_bin_pow_core(puVar4,unaff_ER14 + -0x78);
          dec_bin_pow_core(unaff_ER14 + -0xaa,unaff_ER14 + -0x46);
          dec_bin_mul_core(unaff_ER14 + -0xaa,puVar4);
          bcd_type((byte *)(unaff_ER14 + -0xaa));
        }
      }
    }
  }
  return 0;
}

/**
 * @brief 矩阵单元取整操作
 * @addr 0x11474
 * @module eval
 * @proto int matrix_cell_int(void)
 * @confidence likely
 * @note 矩阵单元取整操作。
 * @tag matrix
 */
int matrix_cell_int(void)

{
  undefined2 *puVar1;
  short sVar2;
  undefined2 *puVar3;
  undefined2 *puVar4;
  short unaff_ER14;
  
  puVar4 = (undefined2 *)(unaff_ER14 + -0x14);
  puVar3 = (undefined2 *)(unaff_ER14 + -0x1e);
  dec_copy(puVar3,(undefined2 *)(unaff_ER14 + -0xb4));
  dec_copy(puVar4,(undefined2 *)(unaff_ER14 + -0xbe));
  dec_bin_pow_core(puVar4,unaff_ER14 + -0x50);
  dec_bin_mul_core(puVar3,puVar4);
  puVar1 = (undefined2 *)(unaff_ER14 + -0x50);
  dec_copy(puVar4,puVar1);
  decm_pow(puVar4,puVar1);
  dec_bin_pow_core(puVar4,unaff_ER14 + -200);
  dec_bin_div_core(puVar3,puVar4);
  sVar2 = unaff_ER14 + -0x5a;
  dec_bin_div_core(puVar3,sVar2);
  dec_cmp_ex(puVar3,sVar2);
  dec_copy((undefined2 *)(unaff_ER14 + -0xb4),puVar3);
  bcd_type((byte *)puVar3);
  return 0;
}

/**
 * @brief 矩阵单元链式求值（0x12650 循环）
 * @addr 0x114F6
 * @module eval
 * @proto int matrix_cell_chain(void)
 * @confidence likely
 * @note 矩阵单元链式求值（0x12650 循环）。
 * @tag matrix
 */
int matrix_cell_chain(void)

{
  int bVar1;
  ushort uVar2;
  undefined extraout_R1;
  undefined extraout_R1_00;
  undefined extraout_R1_01;
  undefined extraout_R1_02;
  
  uVar2 = stat_table_loop();
  if (((char)uVar2 == '\0') && (uVar2 = stat_table_loop(), (char)uVar2 == '\0')) {
    uVar2 = kbd_wait_key();
    if ((char)uVar2 != '\0') {
      return uVar2;
    }
    uVar2 = table_cell_calc();
    if ((char)uVar2 == '\0') {
      if (stat_sel == '\x01') {
        uVar2 = dec_copy_10_slot();
        return uVar2;
      }
      bVar1 = stat_sub_loop();
      uVar2 = CONCAT11(extraout_R1,bVar1);
      if (bVar1 == 1) {
        return uVar2;
      }
      if (bVar1 == 0) {
        bVar1 = stat_sub_loop();
        uVar2 = CONCAT11(extraout_R1_00,bVar1);
        if (bVar1 == 1) {
          return uVar2;
        }
        if (bVar1 == 0) {
          bVar1 = stat_1var_calc();
          uVar2 = CONCAT11(extraout_R1_01,bVar1);
          if (bVar1 == 1) {
            return uVar2;
          }
          if ((bVar1 == 0) && (uVar2 = mat_cell_binary_b(), (char)uVar2 == '\0')) {
            uVar2 = kbd_wait_key();
            if ((char)uVar2 != '\0') {
              return uVar2;
            }
            bVar1 = mat_cell_binary_a();
            uVar2 = CONCAT11(extraout_R1_02,bVar1);
            if (bVar1 == 0) {
              uVar2 = kbd_wait_key();
              if ((char)uVar2 != '\0') {
                return uVar2;
              }
              uVar2 = dec_copy_10_slot_ng();
              return uVar2;
            }
          }
        }
      }
    }
  }
  return CONCAT11((char)(uVar2 >> 8),0xf0);
}

/**
 * @brief 矩阵求值包装
 * @addr 0x115E2
 * @module eval
 * @proto void matrix_eval_wrap(undefined2* a)
 * @confidence likely
 * @note 矩阵求值包装：0x1109E 后把结果整理写回（0x1D6A4 收尾）。
 * @tag matrix
 */
int matrix_eval_wrap(undefined2* a)

{
  int bVar1;
  undefined2 *puVar2;
  ushort *puVar3;
  char unaff_R4;
  ushort *puVar4;
  undefined2 *puVar5;
  short unaff_ER14;
  
  bVar1 = matrix_eval_all(a);
  puVar5 = (undefined2 *)(unaff_ER14 + -0x14);
  if (bVar1 == 0) {
    puVar4 = (ushort *)(unaff_ER14 + -0x1e);
    dec_copy(puVar5,(undefined2 *)(unaff_ER14 + -0xb4));
    dec_bin_mul_core(puVar5,*(undefined2 *)(unaff_ER14 + -2));
    dec_bin_pow_core(puVar5,unaff_ER14 + -200);
    dec_set_uint_small(puVar4,4);
    dec_bin_pow_core(puVar4,puVar5);
    puVar2 = (undefined2 *)(unaff_ER14 + -0xbe);
    dec_copy(puVar5,puVar2);
    decm_pow(puVar5,puVar2);
    puVar3 = puVar4;
    dec_bin_mul_core(puVar5,puVar4);
    decm_power_common(puVar5,puVar3);
    if (unaff_R4 != '\0') {
      dec_inc5(puVar5,puVar3);
    }
    dec_bin_mul_core(puVar5,unaff_ER14 + -0xbe);
    dec_set_uint_small(puVar4,2);
    dec_bin_pow_core(puVar4,unaff_ER14 + -200);
    dec_bin_and_core(puVar5,puVar4);
    bcd_type((byte *)puVar5);
    return 0;
  }
  dec_set_prec(bVar1);
  return 0;
}

