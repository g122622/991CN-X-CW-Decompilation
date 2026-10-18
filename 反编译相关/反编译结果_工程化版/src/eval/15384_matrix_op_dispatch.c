/*
 * 表达式求值 / 15384_matrix_op_dispatch.c
 * 地址范围: 0x15384 - 0x15B66
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 检查 +0x14 单元后分派 0x14E38/0x14ECE（矩阵运算路径）
 * @addr 0x15384
 * @module eval
 * @proto int matrix_op_dispatch(undefined2 a)
 * @confidence likely
 * @note 检查 +0x14 单元后分派 0x14E38/0x14ECE（矩阵运算路径）。
 * @tag matrix
 */
int matrix_op_dispatch(undefined2 a)

{
  short unaff_ER6;
  byte bVar1;
  
  bVar1 = ((undefined2 *)(unaff_ER6 + 0x14) == (undefined2 *)0x0) << 6;
  int_to_dec((undefined2 *)(unaff_ER6 + 0x14),a);
  if ((bVar1 >> 6 & 1) != 1) {
    apps_submenu(a);
    return 0;
  }
  apps_view_scroll(a);
  return 0;
}

/**
 * @brief 右端项乘算
 * @addr 0x155F4
 * @module eval
 * @proto int matrix_rhs_mul(void)
 * @confidence likely
 * @note 右端项乘算：以常量 0x1B80 与操作数做 0x1909A，随后 0x1671C/0x152FA/0x15628 收尾。
 * @tag matrix
 */
int matrix_rhs_mul(void)

{
  undefined uVar1;
  undefined2 *unaff_ER10;
  
  uVar1 = 0x1b;
  dec_add_or_round(unaff_ER10,(undefined2 *)0x1b80);
  dec_op5_bcd((short)unaff_ER10,CONCAT11(uVar1,5));
  dec_pow_ER10();
  matrix_div_add();
  return 0;
}

/**
 * @brief 把操作数除以调用块 +0x28 处的 BCD（0x1CF68 除法）
 * @addr 0x15616
 * @module eval
 * @proto void matrix_div_28(void)
 * @confidence likely
 * @note 把操作数除以调用块 +0x28 处的 BCD（0x1CF68 除法）。
 * @tag matrix
 */
int matrix_div_28(void)

{
  undefined2 *unaff_ER8;
  short unaff_ER10;
  
  dec_copy_a((uintptr_t)0);
  dec_bin_div((undefined2 *)(unaff_ER10 + 0x28),unaff_ER8);
  return 0;
}

/**
 * @brief 把操作数除以调用块 +0x0A 并加上 +0x1E 处操作数（0x1CF68/0x1909A…
 * @addr 0x15628
 * @module eval
 * @proto void matrix_div_add(void)
 * @confidence likely
 * @note 把操作数除以调用块 +0x0A 并加上 +0x1E 处操作数（0x1CF68/0x1909A）。
 * @tag matrix
 */
int matrix_div_add(void)

{
  short unaff_ER6;
  undefined2 *unaff_ER10;
  
  dec_bin_div(unaff_ER10,(undefined2 *)(unaff_ER6 + 10));
  dec_add_or_round(unaff_ER10,(undefined2 *)(unaff_ER6 + 0x1e));
  return 0;
}

/**
 * @brief 把操作数乘以调用块 +0x0A 并加上 +0x1E 处操作数（0x1CF54/0x1909A…
 * @addr 0x15636
 * @module eval
 * @proto int matrix_mul_add(void)
 * @confidence likely
 * @note 把操作数乘以调用块 +0x0A 并加上 +0x1E 处操作数（0x1CF54/0x1909A）。
 * @tag matrix
 */
int matrix_mul_add(void)

{
  short unaff_ER6;
  undefined2 *unaff_ER10;
  
  dec_bin_mul(unaff_ER10,(undefined2 *)(unaff_ER6 + 10));
  dec_add_or_round(unaff_ER10,(undefined2 *)(unaff_ER6 + 0x1e));
  return 0;
}

/**
 * @brief 把 0xD6B2 起 0x140 字节清零（应用模式工作表）
 * @addr 0x15AFE
 * @module eval
 * @proto void clear_work_area(void)
 * @confidence verified
 * @note 把 0xD6B2 起 0x140 字节清零（应用模式工作表）。
 * @tag apps
 */
int clear_work_area(void)

{
  memzero(&app_work_area,0x140);
  return 0;
}

/**
 * @brief 按维度 n 扫描矩阵存储（每单元 0x28 字节），累加匹配单元，n==2 时改走 0x15…
 * @addr 0x15B0E
 * @module eval
 * @proto undefined2 matrix_size_scan(byte n)
 * @confidence likely
 * @note 按维度 n 扫描矩阵存储（每单元 0x28 字节），累加匹配单元，n==2 时改走 0x15B66。
 * @tag matrix
 */
undefined2 matrix_size_scan(byte n)

{
  undefined2 uVar1;
  short sVar2;
  byte bVar3;
  byte bVar4;
  
  sVar2 = -0x28ae;
  if (n == 2) {
    sVar2 = check_size_family('\0');
  }
  else if (2 < n) {
    bVar3 = 0;
    bVar4 = 0;
    do {
      uVar1 = dec_cmp((undefined2 *)((ushort)bVar3 * 0x28 + -0x28a4),(ushort)bVar3 * 0x28);
      if ((char)uVar1 == '\x01') {
        bVar4 = bVar4 + bVar3;
      }
      bVar3 = bVar3 + 1;
    } while ((char)((bVar3 < n) << 7) < '\0');
    if (bVar4 < 3) {
      sVar2 = (ushort)bVar4 * 0x28 + -0x28ae;
    }
    else {
      sVar2 = check_size_family('\x01');
    }
  }
  return sVar2;
}

/**
 * @brief which 为 0 时调用 0x1369A，否则调用 0x13584（矩阵/向量尺寸族检查）
 * @addr 0x15B66
 * @module eval
 * @proto undefined2 check_size_family(char which)
 * @confidence likely
 * @note which 为 0 时调用 0x1369A，否则调用 0x13584（矩阵/向量尺寸族检查）。
 * @tag matrix
 */
undefined2 check_size_family(char which)

{
  if (which == '\0') {
    dec_cmp_path1();
  }
  else {
    dec_cmp_path2();
  }
  return;
}

