/*
 * BCD 浮点库 / 181f6_var_scale.c
 * 地址范围: 0x181F6 - 0x1898E
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 按 0x187DA 取单元指针并做带有常量的运算（0x18723 系列）
 * @addr 0x181F6
 * @module bcd
 * @proto int var_scale(void)
 * @confidence likely
 * @note 按 0x187DA 取单元指针并做带有常量的运算（0x18723 系列）。
 * @tag vars
 */
int var_scale(uintptr_t _a3, uintptr_t _a4, int _a1, int _a2)

{
  undefined2 *puVar1;
  undefined extraout_R1;
  short sVar2;
  
  puVar1 = (undefined2 *)dec_ptr_by_idx(CONCAT11((char)((ushort)_a1 >> 8),0x1e));
  dec_normalize2(puVar1,_a2);
  dec_copy(_a1,puVar1);
  sVar2 = dec_ptr_by_idx(CONCAT11(extraout_R1,0x1f));
  dec_normalize2(sVar2,puVar1);
  return sVar2;
}

/**
 * @brief 复制/交换两个 BCD 操作数（0x187DA 指针 + memcpy_bytes）
 * @addr 0x1821E
 * @module bcd
 * @proto int dec_arg_copy(void)
 * @confidence likely
 * @note 复制/交换两个 BCD 操作数（0x187DA 指针 + memcpy_bytes）。
 * @tag bcd
 */
int dec_arg_copy(uintptr_t _a2, int _a1)

{
  undefined uVar3;
  undefined *puVar1;
  undefined *puVar2;
  undefined2 uVar4;
  
  uVar3 = (undefined)((ushort)_a1 >> 8);
  puVar1 = (undefined *)dec_ptr_by_idx(CONCAT11(uVar3,uVar3));
  puVar2 = (undefined *)dec_ptr_by_idx(CONCAT11((char)((ushort)puVar1 >> 8),(char)_a1));
  uVar4 = 0x1e;
  memcpy_bytes(puVar1,puVar2,0x1e);
  return uVar4;
}

/**
 * @brief 把 [0x1B, lo]、[lo, hi]、[hi, 0x1B] 三个值依次复制到变量表（0…
 * @addr 0x18244
 * @module bcd
 * @proto void var_fill_triple(ushort idx)
 * @confidence likely
 * @note 把 [0x1B, lo]、[lo, hi]、[hi, 0x1B] 三个值依次复制到变量表（0x1821E）。
 * @tag vars
 */
int var_fill_triple(ushort idx)

{
  undefined uVar1;
  
  dec_arg_copy(CONCAT11(0x1b,(char)idx));
  uVar1 = (undefined)((ushort)idx >> 8);
  dec_arg_copy(CONCAT11((char)idx,uVar1));
  dec_arg_copy(CONCAT11(uVar1,0x1b));
  return 0;
}

/**
 * @brief 若第 idx+0x0101 个变量的类型字节为 4，则调用 0x18244 填充三项
 * @addr 0x18264
 * @module bcd
 * @proto void var_init_slot(ushort idx)
 * @confidence likely
 * @note 若第 idx+0x0101 个变量的类型字节为 4，则调用 0x18244 填充三项。
 * @tag vars
 */
int var_init_slot(ushort idx)

{
  char cVar1;
  
  cVar1 = dec_to_str_idx(CONCAT11((char)((ushort)idx >> 8) + '\x01',(char)idx + '\x01'));
  if (cVar1 == '\x04') {
    var_fill_triple(idx);
  }
  return 0;
}

/**
 * @brief 按 3 层三角布局初始化变量槽（循环调用 0x18264，列号步进 3）
 * @addr 0x18280
 * @module bcd
 * @proto void var_init_matrix(void)
 * @confidence likely
 * @note 按 3 层三角布局初始化变量槽（循环调用 0x18264，列号步进 3）。
 * @tag vars
 */
int var_init_matrix(void)

{
  byte bVar1;
  byte bVar2;
  
  bVar1 = 0;
  do {
    bVar2 = 0;
    do {
      var_init_slot(CONCAT11((bVar2 + 1) * '\x03' + '\f',bVar2 * '\x03' + '\f'));
      bVar2 = bVar2 + 1;
    } while ((char)((bVar2 < (byte)(3 - bVar1)) << 7) < '\0');
    bVar1 = bVar1 + 1;
  } while ((char)((bVar1 < 3) << 7) < '\0');
  return 0;
}

/**
 * @brief 把第 idx、idx+1、idx+2 个变量单元分别置 0、0、1
 * @addr 0x182B8
 * @module bcd
 * @proto void var_zero_block(ushort idx)
 * @confidence strong
 * @note 把第 idx、idx+1、idx+2 个变量单元分别置 0、0、1。
 * @tag vars
 */
int var_zero_block(ushort idx)

{
  ushort *puVar1;
  undefined2 uVar2;
  
  puVar1 = (ushort *)dec_ptr_by_idx(idx);
  uVar2 = dec_set_uint_small(puVar1,0);
  puVar1 = (ushort *)dec_ptr_by_idx(CONCAT11((char)((ushort)uVar2 >> 8),(char)idx + '\x01'));
  uVar2 = dec_set_uint_small(puVar1,0);
  puVar1 = (ushort *)dec_ptr_by_idx(CONCAT11((char)((ushort)uVar2 >> 8),(char)idx + '\x02'));
  dec_set_uint_small(puVar1,1);
  return 0;
}

/**
 * @brief 返回第 idx 个 BCD 单元偏移 8 处的字节 > 0x0E（大数/特殊值判断）
 * @addr 0x182E8
 * @module bcd
 * @proto char dec_is_big(short idx)
 * @confidence verified
 * @note 返回第 idx 个 BCD 单元偏移 8 处的字节 > 0x0E（大数/特殊值判断）。
 * @tag bcd
 */
char dec_is_big(short idx)

{
  short sVar1;
  
  sVar1 = dec_ptr_by_idx(idx);
  return 0xe < *(byte *)(sVar1 + 8);
}

/**
 * @brief 逐单元 0x17F78/0x17F8C 求值，比较相邻单元（0x1B/0x1C 常量）
 * @addr 0x18300
 * @module bcd
 * @proto byte matrix_check_vals(undefined2 a)
 * @confidence likely
 * @note 逐单元 0x17F78/0x17F8C 求值，比较相邻单元（0x1B/0x1C 常量）。
 * @tag matrix
 */
byte matrix_check_vals(undefined2 a, int _a2)

{
  char cVar1;
  bool bVar2;
  bool bVar3;
  char cVar4;
  undefined extraout_R1;
  undefined extraout_R1_00;
  undefined2 uVar5;
  
  cVar4 = (char)((ushort)a >> 8);
  cVar1 = (char)a;
  dec_unary_calc(CONCAT11(cVar4 + '\x02',cVar1),0x1b);
  dec_unary_calc(CONCAT11(cVar4,cVar1 + '\x02'),0x1c);
  dec_bin_op2(0x1c1b,_a2);
  dec_arg_load(CONCAT11(_a2 + '\x01',cVar1 + '\x01'));
  dec_unary_calc(CONCAT11(cVar4 + '\x02',cVar1 + '\x02'),_a2 + '\x02');
  uVar5 = CONCAT11(_a2 + '\x02',_a2);
  bVar2 = dec_is_big(CONCAT11(extraout_R1,_a2));
  bVar3 = dec_is_big(CONCAT11(extraout_R1_00,_a2 + '\x02'));
  dec_get_word(uVar5,uVar5);
  return bVar2 + bVar3;
}

/**
 * @brief 相邻单元 0x1D 常量与 0x17F78 求值并比较
 * @addr 0x18334
 * @module bcd
 * @proto byte matrix_check_vals_b(undefined2 a)
 * @confidence likely
 * @note 相邻单元 0x1D 常量与 0x17F78 求值并比较。
 * @tag matrix
 */
byte matrix_check_vals_b(undefined2 a, int _a2)

{
  bool bVar1;
  bool bVar2;
  char cVar5;
  undefined extraout_R1;
  undefined2 *puVar3;
  undefined2 *puVar4;
  undefined extraout_R1_00;
  undefined extraout_R1_01;
  undefined2 uVar6;
  
  cVar5 = (char)((ushort)a >> 8);
  dec_unary_calc(CONCAT11(cVar5 + '\x01',(char)a + '\x01'),0x1d);
  puVar3 = (undefined2 *)dec_ptr_by_idx(CONCAT11(extraout_R1,0x1d));
  puVar4 = (undefined2 *)dec_ptr_by_idx(CONCAT11((char)((ushort)puVar3 >> 8),0x1b));
  matrix_copy_ext(puVar4,puVar3);
  dec_arg_load(CONCAT11(_a2 + '\x01',0x1c));
  dec_unary_calc(a,_a2);
  dec_unary_calc(CONCAT11(0x1b,_a2),_a2);
  dec_unary_calc(CONCAT11(cVar5 + '\x02',(char)a + '\x02'),_a2 + '\x02');
  uVar6 = CONCAT11(_a2 + '\x02',_a2);
  bVar1 = dec_is_big(CONCAT11(extraout_R1_00,_a2));
  bVar2 = dec_is_big(CONCAT11(extraout_R1_01,_a2 + '\x02'));
  dec_get_word(uVar6,uVar6);
  return bVar1 + bVar2;
}

/**
 * @brief 对 a 与 a+1/a+2 三个单元求值（0x17F78/0x17DCC）
 * @addr 0x183AE
 * @module bcd
 * @proto byte matrix_check_vals_c(undefined2 a, undefined2 b)
 * @confidence likely
 * @note 对 a 与 a+1/a+2 三个单元求值（0x17F78/0x17DCC）。
 * @tag matrix
 */
byte matrix_check_vals_c(undefined2 a, undefined2 b)

{
  bool bVar1;
  bool bVar2;
  undefined extraout_R1;
  undefined extraout_R1_00;
  char cVar3;
  undefined2 uVar4;
  
  dec_unary_calc(a,b);
  cVar3 = (char)((ushort)a >> 8);
  dec_arg_load(CONCAT11(b + '\x01',cVar3 + '\x01'));
  dec_arg_load(CONCAT11(b + '\x02',cVar3 + '\x02'));
  uVar4 = CONCAT11(b + '\x02',b);
  bVar1 = dec_is_big(CONCAT11(extraout_R1_00,b));
  bVar2 = dec_is_big(CONCAT11(extraout_R1,b + '\x02'));
  dec_get_word(uVar4,uVar4);
  return bVar1 + bVar2;
}

/**
 * @brief 取 a+1 处单元类型（0x18108）作检查
 * @addr 0x183D4
 * @module bcd
 * @proto byte matrix_cell_probe(undefined2 a)
 * @confidence likely
 * @note 取 a+1 处单元类型（0x18108）作检查。
 * @tag matrix
 */
byte matrix_cell_probe(undefined2 a)

{
  bool bVar1;
  bool bVar2;
  undefined extraout_R1;
  undefined extraout_R1_00;
  char cVar3;
  char cVar4;
  undefined2 uVar5;
  byte bVar6;
  
  cVar4 = (char)a;
  cVar3 = (char)((ushort)a >> 8);
  bVar6 = ((char)(cVar4 + '\x01') == '\0') << 6;
  dec_type_byte(CONCAT11(cVar3,cVar4 + '\x01'));
  if ((bVar6 >> 6 & 1) == 1) {
    cVar4 = '\0';
  }
  else {
    dec_unary_calc(a,cVar4);
    dec_unary_calc(CONCAT11(cVar3 + '\x02',cVar4 + '\x02'),cVar4 + '\x02');
    uVar5 = CONCAT11(cVar4 + '\x02',cVar4);
    bVar1 = dec_is_big(CONCAT11(extraout_R1,cVar4));
    bVar2 = dec_is_big(CONCAT11(extraout_R1_00,cVar4 + '\x02'));
    cVar4 = bVar1 + bVar2;
    dec_get_word(uVar5,uVar5);
  }
  return cVar4;
}

/**
 * @brief 变量初始化批次 1
 * @addr 0x183EE
 * @module bcd
 * @proto void var_init_1(void)
 * @confidence likely
 * @note 变量初始化批次 1：对索引 6、9、0x603、0x903 调用 0x18334（设置初值 0x0C/0x0F/…）。
 * @tag vars
 */
int var_init_1(void)

{
  matrix_check_vals_b(6,'\f');
  matrix_check_vals_b(9,'\x0f');
  matrix_check_vals_b(0x603,'\x12');
  matrix_check_vals_b(0x903,'\x15');
  return 0;
}

/**
 * @brief 变量初始化批次 2
 * @addr 0x18416
 * @module bcd
 * @proto void var_init_2(void)
 * @confidence likely
 * @note 变量初始化批次 2：对索引 0x61E、0x91E 调用 0x183AE。
 * @tag vars
 */
int var_init_2(void)

{
  matrix_check_vals_c(0x61e,'\0');
  matrix_check_vals_c(0x91e,'\x03');
  return 0;
}

/**
 * @brief 变量初始化批次 3
 * @addr 0x1842E
 * @module bcd
 * @proto void var_init_3(void)
 * @confidence likely
 * @note 变量初始化批次 3：按索引表（0xB08、0x1818、…）调用 0x17F78/0x17F82/0x17D1A。
 * @tag vars
 */
int var_init_3(void)

{
  dec_unary_calc(0xb08,0x18);
  dec_unary_calc(0x1818,0x18);
  dec_unary_calc(0xb06,0x1a);
  dec_unary_calc(0x1a1a,0x1a);
  dec_unary_calc(0x71a,0x1a);
  dec_unary_calc(0x809,0x19);
  dec_unary_calc(0x1919,0x19);
  dec_unary_calc(0xa19,0x19);
  dec_compare_offset(0x191a,0x1a);
  dec_get_word(0x1a18,0x1a18);
  return 0;
}

/**
 * @brief 依次检查 0x1800/0x1803 两个单元的探测结果
 * @addr 0x18496
 * @module bcd
 * @proto byte matrix_probe_1800(void)
 * @confidence likely
 * @note 依次检查 0x1800/0x1803 两个单元的探测结果。
 * @tag matrix
 */
byte matrix_probe_1800(void)

{
  byte extraout_R1;
  byte extraout_R1_00;
  byte bVar1;
  byte bVar2;
  
  bVar2 = 0;
  matrix_cell_probe(0x1800);
  bVar1 = extraout_R1;
  if ((bVar2 >> 6 & 1) != 0) {
    bVar2 = 0;
    matrix_cell_probe(0x1803);
    bVar1 = extraout_R1_00;
    if ((bVar2 >> 6 & 1) != 0) {
      return (ushort)extraout_R1_00 << 8;
    }
  }
  return CONCAT11(bVar1,1);
}

/**
 * @brief 变量初始化批次 4
 * @addr 0x184B6
 * @module bcd
 * @proto void var_init_4(void)
 * @confidence likely
 * @note 变量初始化批次 4：调用 0x17DCC/0x17F78/0x18334 及 0x184F2、0x18264 设置若干槽位。
 * @tag vars
 */
int var_init_4(void)

{
  char cVar1;
  undefined extraout_R1;
  
  dec_arg_load(0x60b);
  dec_arg_load(0x70a);
  dec_unary_calc(0xa09,8);
  matrix_check_vals_b(6,'\0');
  cVar1 = matrix_check_vals_b(0x603,'\x03');
  matrix_cell_type_b(CONCAT11(extraout_R1,cVar1));
  var_init_slot(0x300);
  return 0;
}

/**
 * @brief 单元类型判定（0x18108/0x182B8/0x18112）
 * @addr 0x184F2
 * @module bcd
 * @proto byte matrix_cell_type_b(undefined2 a)
 * @confidence likely
 * @note 单元类型判定（0x18108/0x182B8/0x18112）。
 * @tag matrix
 */
byte matrix_cell_type_b(undefined2 a)

{
  ushort uVar1;
  undefined extraout_R1;
  byte bVar3;
  undefined uVar2;
  
  bVar3 = 0x40;
  uVar1 = dec_type_byte(a & 0xff00);
  uVar2 = (undefined)(uVar1 >> 8);
  if ((bVar3 >> 6 & 1) != 0) {
    var_zero_block(uVar1 & 0xff00);
    uVar2 = extraout_R1;
  }
  bVar3 = 0;
  dec_type_byte(CONCAT11(uVar2,3));
  if ((bVar3 >> 6 & 1) != 0) {
    uVar1 = dec_arg_copy(0x300);
    var_zero_block(uVar1 & 0xff00);
  }
  return;
}

/**
 * @brief 扫描矩阵全部单元（0x18300/0x18334/0x184F2 组合）
 * @addr 0x1851A
 * @module bcd
 * @proto byte matrix_scan_all(void)
 * @confidence likely
 * @note 扫描矩阵全部单元（0x18300/0x18334/0x184F2 组合）。
 * @tag matrix
 */
byte matrix_scan_all(void)

{
  char cVar1;
  undefined extraout_R1;
  undefined extraout_R1_00;
  ushort uVar2;
  undefined extraout_R1_01;
  undefined extraout_R1_02;
  byte extraout_R1_03;
  undefined extraout_R1_04;
  undefined extraout_R1_05;
  undefined extraout_R1_06;
  undefined extraout_R1_07;
  undefined extraout_R1_08;
  undefined extraout_R1_09;
  byte extraout_R1_10;
  undefined extraout_R1_11;
  byte extraout_R1_12;
  byte extraout_R1_13;
  byte extraout_R1_14;
  byte bVar3;
  undefined uVar4;
  byte bVar5;
  
  var_init_matrix();
  bVar5 = 0;
  dec_type_byte(CONCAT11(extraout_R1,0x10));
  if ((bVar5 >> 6 & 1) == 0) {
    bVar5 = 0;
    dec_type_byte(CONCAT11(extraout_R1_00,0xd));
    if ((bVar5 >> 6 & 1) != 0) {
      bVar5 = 0;
      dec_to_str_idx(0x1310);
      if ((bVar5 >> 6 & 1) == 0) {
        bVar5 = 0;
        dec_to_str_idx(0x1613);
        uVar4 = extraout_R1_01;
        if ((bVar5 >> 6 & 1) == 0) goto LAB_rom_018658;
        dec_arg_copy(0xf);
        cVar1 = matrix_check_vals(0x1512,'\x03');
        uVar2 = CONCAT11(extraout_R1_02,cVar1);
      }
      else {
        matrix_check_vals(0x120f,'\0');
        uVar2 = dec_arg_copy(0x315);
      }
      goto LAB_rom_018636;
    }
    bVar5 = 0;
    dec_to_str_idx(0x100d);
    if ((bVar5 >> 6 & 1) == 0) {
      bVar5 = 0;
      dec_to_str_idx(0x1310);
      if ((bVar5 >> 6 & 1) == 0) {
        bVar5 = 0;
        dec_to_str_idx(0x1613);
        uVar4 = extraout_R1_09;
        if ((bVar5 >> 6 & 1) != 0) {
          matrix_check_vals(0x1512,'\0');
          bVar5 = 0x40;
          dec_type_byte((ushort)extraout_R1_10 << 8);
          uVar4 = extraout_R1_11;
          if ((bVar5 >> 6 & 1) != 0) {
            dec_arg_copy(0xc);
            uVar2 = dec_arg_copy(0x30f);
            goto LAB_rom_018636;
          }
        }
LAB_rom_018658:
        return CONCAT11(uVar4,1);
      }
      dec_arg_copy(0xc);
      matrix_check_vals(0x120f,'\x03');
      bVar5 = 0;
      dec_to_str_idx(0x1610);
      if ((bVar5 >> 6 & 1) == 0) {
        bVar5 = 0;
        dec_type_byte(CONCAT11(extraout_R1_06,3));
        uVar4 = extraout_R1_08;
        if ((bVar5 >> 6 & 1) == 0) goto LAB_rom_018658;
        uVar2 = dec_arg_copy(0x315);
      }
      else {
        cVar1 = matrix_check_vals(0x1503,'\x03');
        uVar2 = CONCAT11(extraout_R1_07,cVar1);
      }
      goto LAB_rom_018636;
    }
    matrix_check_vals(0xf0c,'\0');
    bVar5 = 0;
    dec_to_str_idx(0x130d);
    if ((bVar5 >> 6 & 1) != 0) {
      matrix_check_vals(0x12,'\0');
      uVar2 = dec_arg_copy(0x315);
      goto LAB_rom_018636;
    }
    bVar5 = 0;
    dec_to_str_idx(0x1613);
    if ((bVar5 >> 6 & 1) != 0) {
      cVar1 = matrix_check_vals(0x1512,'\x03');
      uVar2 = CONCAT11(extraout_R1_04,cVar1);
      goto LAB_rom_018636;
    }
    bVar5 = 0x40;
    dec_type_byte((ushort)extraout_R1_03 << 8);
    uVar4 = extraout_R1_05;
    if ((bVar5 >> 6 & 1) == 0) goto LAB_rom_018658;
  }
  dec_arg_copy(0x12);
  uVar2 = dec_arg_copy(0x315);
LAB_rom_018636:
  matrix_cell_type_b(uVar2);
  bVar5 = 0;
  dec_to_str_idx(0x401);
  bVar3 = extraout_R1_12;
  if ((bVar5 >> 6 & 1) != 0) {
    matrix_check_vals(3,'\x03');
    var_zero_block((ushort)extraout_R1_13 << 8);
    bVar3 = extraout_R1_14;
  }
  return (ushort)bVar3 << 8;
}

/**
 * @brief 矩阵扫描流程（0x13C）经 0x1813C 等单元检查
 * @addr 0x1865C
 * @module bcd
 * @proto byte matrix_scan_1865c(void)
 * @confidence likely
 * @note 矩阵扫描流程（0x13C）经 0x1813C 等单元检查。
 * @tag matrix
 */
byte matrix_scan_1865c(uintptr_t _a3, uintptr_t _a4, int _a1, int _a2)

{
  undefined2 uVar1;
  int sVar2;
  byte bVar3;
  
  dec_store_pair(_a1,_a2);
  uVar1 = matrix_prep_opnd(0xc,_a2);
  bVar3 = ((byte)uVar1 == 0x40) << 6;
  if (((byte)uVar1 < 0x40) && (sVar2 = matrix_scan_all(), (bVar3 >> 6 & 1) != 0)) {
    dec_calc_main(0,(char)((ushort)sVar2 >> 8),(char)_a1,(char)((ushort)_a1 >> 8));
  }
  else {
    sVar2 = var_scale(_a1,_a2);
    dec_bin_div_core(_a1,sVar2);
  }
  return;
}

/**
 * @brief 矩阵扫描流程（0x186A0）经 0x18130 等单元检查
 * @addr 0x186A0
 * @module bcd
 * @proto byte matrix_scan_186a0(void)
 * @confidence likely
 * @note 矩阵扫描流程（0x186A0）经 0x18130 等单元检查。
 * @tag matrix
 */
byte matrix_scan_186a0(uintptr_t _a2, int _a1)

{
  undefined extraout_R1;
  undefined2 uVar1;
  int sVar2;
  undefined2 *in_ER2;
  byte bVar3;
  
  dec_store_pair(_a1,in_ER2);
  var_add_const(CONCAT11(extraout_R1,0x1f),in_ER2);
  uVar1 = matrix_prep_opnd(0xc,in_ER2);
  bVar3 = ((byte)uVar1 == 0x40) << 6;
  if (((byte)uVar1 < 0x40) && (sVar2 = matrix_scan_all(), (bVar3 >> 6 & 1) != 0)) {
    dec_calc_main(0,(char)((ushort)sVar2 >> 8),(char)_a1,(char)((ushort)_a1 >> 8));
  }
  else {
    sVar2 = var_scale(_a1,in_ER2);
    dec_bin_div_core(_a1,sVar2);
  }
  return;
}

/**
 * @brief 矩阵扫描流程变体
 * @addr 0x186A8
 * @module bcd
 * @proto byte matrix_scan_186a8(void)
 * @confidence likely
 * @note 矩阵扫描流程变体。
 * @tag matrix
 */
byte matrix_scan_186a8(uintptr_t _a3, uintptr_t _a4, int _a1, int _a2)

{
  bool bVar1;
  ushort uVar2;
  int sVar3;
  undefined extraout_R1;
  byte bVar5;
  undefined uVar4;
  
  dec_store_pair(_a1,_a2);
  uVar2 = matrix_prep_opnd(0x100,_a2);
  if ((byte)uVar2 < 0x40) {
    bVar1 = (uVar2 & 0x10) == 0;
    bVar5 = bVar1 << 6;
    if (bVar1) {
      var_init_1();
      sVar3 = matrix_scan_all();
      uVar4 = (undefined)((ushort)sVar3 >> 8);
      if ((bVar5 >> 6 & 1) == 0) goto LAB_rom_0186da;
    }
    else {
      var_init_2();
      uVar4 = extraout_R1;
    }
    dec_calc_main(0,uVar4,(char)_a1,(char)((ushort)_a1 >> 8));
    return;
  }
LAB_rom_0186da:
  sVar3 = var_scale(_a1,_a2);
  dec_bin_pow_core(_a1,sVar3);
  return;
}

/**
 * @brief 矩阵扫描流程变体（0x18496 探测）
 * @addr 0x186EC
 * @module bcd
 * @proto byte matrix_scan_186ec(void)
 * @confidence likely
 * @note 矩阵扫描流程变体（0x18496 探测）。
 * @tag matrix
 */
byte matrix_scan_186ec(uintptr_t _a3, uintptr_t _a4, int _a1, int _a2)

{
  undefined2 uVar1;
  undefined extraout_R1;
  int sVar2;
  undefined extraout_R1_00;
  byte bVar4;
  undefined uVar3;
  
  dec_store_pair(_a1,_a2);
  uVar1 = matrix_prep_opnd(0,_a2);
  if ((byte)uVar1 < 0x40) {
    bVar4 = 0;
    dec_type_byte(CONCAT11((char)((ushort)uVar1 >> 8),7));
    if ((bVar4 >> 6 & 1) == 1) {
      bVar4 = 0;
      dec_type_byte(CONCAT11(extraout_R1,10));
      if ((bVar4 >> 6 & 1) != 1) {
        var_init_4();
        uVar3 = extraout_R1_00;
LAB_rom_018720:
        dec_calc_main(0,uVar3,(char)_a1,(char)((ushort)_a1 >> 8));
        return;
      }
    }
    else {
      bVar4 = 0;
      var_add_const(CONCAT11(extraout_R1,9),_a2);
      var_init_1();
      var_init_3();
      matrix_scan_all();
      if ((bVar4 >> 6 & 1) != 0) {
        sVar2 = matrix_probe_1800();
        uVar3 = (undefined)((ushort)sVar2 >> 8);
        if ((bVar4 >> 6 & 1) != 0) goto LAB_rom_018720;
      }
    }
  }
  sVar2 = var_scale(_a1,_a2);
  dec_bin_and_core(_a1,sVar2);
  return;
}

/**
 * @brief 矩阵扫描流程变体（调用 0x17A78）
 * @addr 0x1874A
 * @module bcd
 * @proto byte matrix_scan_1874a(void)
 * @confidence likely
 * @note 矩阵扫描流程变体（调用 0x17A78）。
 * @tag matrix
 */
byte matrix_scan_1874a(uintptr_t _a3, uintptr_t _a4, int _a1, int _a2)

{
  undefined extraout_R1;
  short sVar1;
  undefined2 uVar2;
  byte extraout_R1_00;
  undefined *puVar3;
  
  dec_core_17e8e((char)_a1,(char)((ushort)_a1 >> 8),6,(char)((ushort)_a2 >> 8));
  sVar1 = dec_ptr_by_idx(CONCAT11(extraout_R1,7));
  uVar2 = dec_to_string(sVar1,(undefined2 *)0x1b6c);
  if ((char)uVar2 == '\x01') {
    dec_unary_calc(0xb06,0);
    dec_arg_load(0x107);
    dec_unary_calc(0x908,2);
    dec_arg_load(0x30a);
  }
  else {
    dec_unary_calc(0x908,0);
    dec_arg_load(0x10a);
    dec_unary_calc(0xb06,2);
    dec_arg_load(0x307);
  }
  dec_unary_calc(0xb08,4);
  dec_bin_arith_b(0);
  puVar3 = (undefined *)dec_ptr_by_idx((ushort)extraout_R1_00 << 8);
  uVar2 = 0x32;
  memcpy_bytes(_a1,puVar3,0x32);
  return uVar2;
}

/**
 * @brief BCD 单元指针
 * @addr 0x187DA
 * @module bcd
 * @proto short dec_ptr_by_idx(ushort idx)
 * @confidence verified
 * @note BCD 单元指针：0x25C0 + (idx&0xFF)*10。
 * @tag bcd
 */
short dec_ptr_by_idx(ushort idx)

{
  return (idx & 0xff) * 10 + -0x25c0;
}

/**
 * @brief X ← X + *x（先把 *x 复制到 tmp，再调用加减法入口 0x1CFA4 opco…
 * @addr 0x1881C
 * @module bcd
 * @proto int dec_xy_add(undefined2* tmp, undefined2* x)
 * @confidence verified
 * @note X ← X + *x（先把 *x 复制到 tmp，再调用加减法入口 0x1CFA4 opcode 0）。
 * @tag bcd
 */
int dec_xy_add(undefined2* tmp, undefined2* x)

{
  uint6 uVar1;
  longlong lVar2;
  undefined4 uVar3;
  undefined auStack_c [8];
  
  uVar1 = CONCAT51((int5)(((ulonglong)CONCAT22(auStack_c,tmp) << 0x20) >> 0x18),
                   *(undefined *)tmp) & 0xfffffffffff0;
  lVar2 = (ulonglong)uVar1 << 0x10;
  if ((char)uVar1 == -0x80) {
    dec_copy((undefined2 *)((short)(uVar1 >> 0x20) + -10),(undefined2 *)(uVar1 >> 0x10));
    uVar3 = (undefined4)((ulonglong)lVar2 >> 0x30);
    matrix_scan_186a8((undefined2 *)((short)((ulonglong)lVar2 >> 0x30) + -10), (uintptr_t)0)
                   (undefined2 *)((ulonglong)lVar2 >> 0x20));
    matrix_scan_186a8((undefined2 *)uVar3,(undefined2 *)((short)((uint)uVar3 >> 0x10) + -10));
  }
  else {
    dec_call_1d17e_b(tmp,x);
  }
  return 0;
}

/**
 * @brief X ← X − *x（以 opcode 1 调用二元运算入口）
 * @addr 0x18858
 * @module bcd
 * @proto int dec_xy_sub(undefined2* tmp, undefined2* x)
 * @confidence verified
 * @note X ← X − *x（以 opcode 1 调用二元运算入口）。
 * @tag bcd
 */
int dec_xy_sub(undefined2* tmp, undefined2* x)

{
  uint6 uVar1;
  undefined2 *puVar2;
  
  uVar1 = CONCAT51((int5)((ZEXT28(tmp) << 0x20) >> 0x18),*(undefined *)tmp) & 0xfffffffffff0
  ;
  if ((char)uVar1 == -0x80) {
    puVar2 = (undefined2 *)(uVar1 >> 0x10);
    matrix_scan_186a8(puVar2,puVar2);
  }
  else {
    dec_call_1d17e_c(tmp,x);
  }
  return 0;
}

/**
 * @brief 把 a 与 b 槽做十进制加法（0x1D620/0x19C0E 路径）
 * @addr 0x1887A
 * @module bcd
 * @proto undefined2 dec_add_slot(undefined2* a, undefined2 b)
 * @confidence likely
 * @note 把 a 与 b 槽做十进制加法（0x1D620/0x19C0E 路径）。
 * @tag bcd
 */
undefined2 dec_add_slot(undefined2* a, undefined2 b)

{
  uint6 uVar1;
  undefined uVar2;
  undefined extraout_R1;
  undefined2 uVar3;
  longlong lVar4;
  undefined4 uVar5;
  undefined auStack_c [8];
  
  uVar1 = CONCAT51((int5)(((ulonglong)CONCAT22(auStack_c,a) << 0x20) >> 0x18),
                   *(undefined *)a) & 0xfffffffffff0;
  lVar4 = (ulonglong)uVar1 << 0x10;
  if ((char)uVar1 == -0x80) {
    dec_set_uint_small((ushort *)((short)(uVar1 >> 0x20) + -10),1);
    uVar5 = (undefined4)((ulonglong)lVar4 >> 0x30);
    uVar2 = matrix_scan_186ec((undefined2 *)((short)((ulonglong)lVar4 >> 0x30) + -10), (uintptr_t)0)
                           (undefined2 *)((ulonglong)lVar4 >> 0x20));
    dec_copy((undefined2 *)uVar5,(undefined2 *)((short)((uint)uVar5 >> 0x10) + -10));
    uVar3 = CONCAT11(extraout_R1,uVar2);
  }
  else {
    uVar3 = dec_call_1d17e_d(a,b);
  }
  return uVar3;
}

/**
 * @brief 矩阵单元二运算
 * @addr 0x188B6
 * @module bcd
 * @proto undefined2 matrix_cell_op(undefined2* a, undefined2* b)
 * @confidence likely
 * @note 矩阵单元二运算：清除 0x40 标志后按类型调用 0x16712/0x1671C 等。
 * @tag matrix
 */
undefined2 matrix_cell_op(undefined2* a, undefined2* b)

{
  int cVar1;
  undefined2 uVar2;
  undefined2 *puVar3;
  longlong lVar4;
  undefined2 auStack_16 [9];
  
  lVar4 = (ulonglong)CONCAT22(b,a) << 0x10;
  if ((*(byte *)a < 0xf0) && (*(byte *)a = *(byte *)a & 0xbf, *b < 0xf0)) {
    uVar2 = dec_cmp(a,b);
    if ((char)uVar2 != '\x02') {
      puVar3 = (undefined2 *)((ulonglong)lVar4 >> 0x20);
      dec_copy(auStack_16,puVar3);
      dec_add5_bcd((short)((ulonglong)lVar4 >> 0x20),(ushort)puVar3 & 0xff00);
      puVar3 = (undefined2 *)((ulonglong)lVar4 >> 0x10);
      cVar1 = dec_bin_pow((undefined2 *)((ulonglong)lVar4 >> 0x20),puVar3);
      if (cVar1 == '\0') {
        dec_op5_bcd((short)auStack_16,(ushort)puVar3 & 0xff00);
        cVar1 = dec_bin_pow((undefined2 *)((ulonglong)lVar4 >> 0x10),auStack_16);
        if (cVar1 == '\0') {
          return;
        }
      }
    }
  }
  dec_set_special((ushort *)((ulonglong)lVar4 >> 0x20),3);
  dec_set_special((ushort *)((ulonglong)lVar4 >> 0x10),3);
  nop_rt_3();
  return;
}

/**
 * @brief 空函数（仅 return）
 * @addr 0x18914
 * @module bcd
 * @proto void nop_rt_3(void)
 * @confidence verified
 * @note 空函数（仅 return）。
 * @tag util
 */
int nop_rt_3(void)

{
  return 0;
}

/**
 * @brief 矩阵单元比较（0x1DA7A/0x1D620 链）
 * @addr 0x18930
 * @module bcd
 * @proto undefined2 matrix_cell_cmp(undefined2* a, undefined2* b)
 * @confidence likely
 * @note 矩阵单元比较（0x1DA7A/0x1D620 链）。
 * @tag matrix
 */
undefined2 matrix_cell_cmp(undefined2* a, undefined2* b)

{
  int cVar1;
  ushort auStack_20 [5];
  undefined2 auStack_16 [9];
  
  if ((*(byte *)a < 0xf0) && (*(byte *)b < 0xf0)) {
    dec_copy(auStack_20,a);
    dec_copy(auStack_16,b);
    cVar1 = dec_to_polar(auStack_20);
    if ((cVar1 == '\0') && (cVar1 = decm_mul(a,b), cVar1 == '\0')) {
      dec_copy(b,a);
      dec_copy(a,auStack_20);
      nop_rt_3();
      return;
    }
  }
  dec_set_special(b,3);
  dec_set_special(a,3);
  nop_rt_3();
  return;
}

/**
 * @brief 比例/除法核心（1KB，0x18C8A/0x18CB6 调用）
 * @addr 0x1898E
 * @module bcd
 * @proto void dec_ratio_core(undefined2* a, undefined2* b)
 * @confidence likely
 * @note 比例/除法核心（1KB，0x18C8A/0x18CB6 调用）。
 * @tag bcd
 */
int dec_ratio_core(undefined2* a, undefined2* b)

{
  undefined2 uVar1;
  undefined2 *unaff_ER4;
  undefined8 in_QR8;
  undefined8 uVar2;
  short sVar3;
  undefined auStack_c [8];
  
  uVar2 = CONCAT26(auStack_c,(int6)in_QR8);
  uVar1 = compare_bcd_slots(a,b);
  if ((char)uVar1 == '\0') {
    dec_div_slots_local();
    dec_bin_div((undefined2 *)((ulonglong)uVar2 >> 0x10),(undefined2 *)((ulonglong)uVar2 >> 0x20)
                  );
    dec_copy((undefined2 *)((short)((ulonglong)uVar2 >> 0x30) + -0x32), (uintptr_t)0)
                   (undefined2 *)((ulonglong)uVar2 >> 0x10));
    dec_div_slots_local_b();
    dec_bin_mul((undefined2 *)((ulonglong)uVar2 >> 0x10),(undefined2 *)((ulonglong)uVar2 >> 0x20)
                  );
    dec_copy((undefined2 *)((short)((ulonglong)uVar2 >> 0x30) + -0x3c), (uintptr_t)0)
                   (undefined2 *)((ulonglong)uVar2 >> 0x10));
    matrix_cell_is_zero();
    return 0;
  }
  set_ops_3_0();
  sVar3 = (short)((ulonglong)uVar2 >> 0x30);
  dec_copy_rev(unaff_ER4,(undefined2 *)(sVar3 + -0x3c));
  bcd_type((byte *)(sVar3 + -0x3c));
  return 0;
}

