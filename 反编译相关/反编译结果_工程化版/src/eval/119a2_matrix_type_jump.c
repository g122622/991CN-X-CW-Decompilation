/*
 * 表达式求值 / 119a2_matrix_type_jump.c
 * 地址范围: 0x119A2 - 0x12098
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 按 0xD112 在 0x19B6 跳表分派矩阵输入类型处理（Ghidra 未解出跳表）
 * @addr 0x119A2
 * @module eval
 * @proto void matrix_type_jump(void)
 * @confidence likely
 * @note 按 0xD112 在 0x19B6 跳表分派矩阵输入类型处理（Ghidra 未解出跳表）。
 * @tag matrix
 */
int matrix_type_jump(void)

{
  byte bVar1;
  
  bVar1 = (sub_mode + -2) * '\x02';
  ((void)0);
  return 0;
}

/**
 * @brief 统计函数 V 的包装（0x11B6E + 0x11F50）
 * @addr 0x11A08
 * @module eval
 * @proto byte stat_wrap_v(undefined2 a)
 * @confidence likely
 * @note 统计函数 V 的包装（0x11B6E + 0x11F50）。
 * @tag app
 */
byte stat_wrap_v(undefined2 a)

{
  int bVar1;
  undefined uVar2;
  ushort uVar3;
  short unaff_ER14;
  
  uVar3 = stat_func_v();
  bVar1 = (byte)uVar3;
  if (bVar1 == 0) {
    bVar1 = stat_entry_common(a);
    if ((bVar1 == 0) && (bVar1 = stat_seq_2(), bVar1 == 0)) {
      stat_seq_1();
      bVar1 = dec_copy_to_slot(a);
      if (bVar1 == 0) {
        return 0;
      }
    }
  }
  if (bVar1 == 1) {
    dec_set_special((ushort *)(unaff_ER14 + -0xbe),1);
    dec_set_special((ushort *)(unaff_ER14 + -0xb4),1);
    uVar2 = 1;
  }
  else {
    dec_set_special((ushort *)(unaff_ER14 + -0xbe),3);
    dec_set_special((ushort *)(unaff_ER14 + -0xb4),3);
    uVar2 = 3;
  }
  return uVar2;
}

/**
 * @brief 统计函数 W 的包装（0x11BD6 + 0x11F50）
 * @addr 0x11A30
 * @module eval
 * @proto byte stat_wrap_w(undefined2 a)
 * @confidence likely
 * @note 统计函数 W 的包装（0x11BD6 + 0x11F50）。
 * @tag app
 */
byte stat_wrap_w(undefined2 a)

{
  int bVar1;
  undefined uVar2;
  ushort uVar3;
  short unaff_ER14;
  
  uVar3 = stat_func_w();
  bVar1 = (byte)uVar3;
  if (bVar1 == 0) {
    bVar1 = stat_entry_common(a);
    if ((bVar1 == 0) && (bVar1 = stat_seq_2(), bVar1 == 0)) {
      stat_seq_1();
      decm_sin(unaff_ER14 + -0xb4,a);
      bVar1 = dec_copy_to_slot(a);
      if (bVar1 == 0) {
        return 0;
      }
    }
  }
  if (bVar1 == 1) {
    dec_set_special((ushort *)(unaff_ER14 + -0xbe),1);
    dec_set_special((ushort *)(unaff_ER14 + -0xb4),1);
    uVar2 = 1;
  }
  else {
    dec_set_special((ushort *)(unaff_ER14 + -0xbe),3);
    dec_set_special((ushort *)(unaff_ER14 + -0xb4),3);
    uVar2 = 3;
  }
  return uVar2;
}

/**
 * @brief 统计函数 Z 的包装（0x11D0E + 0x11F50）
 * @addr 0x11A62
 * @module eval
 * @proto byte stat_wrap_z(undefined2 a)
 * @confidence likely
 * @note 统计函数 Z 的包装（0x11D0E + 0x11F50）。
 * @tag app
 */
byte stat_wrap_z(undefined2 a)

{
  byte bVar1;
  ushort uVar2;
  undefined2 uVar3;
  short unaff_ER14;
  
  uVar2 = stat_func_z();
  if ((char)uVar2 == '\0') {
    bVar1 = stat_entry_common(a);
    uVar2 = (ushort)bVar1;
    if ((bVar1 == 0) && (uVar2 = stat_seq_2(), (char)uVar2 == '\0')) {
      stat_seq_1();
      uVar2 = dec_copy_to_slot(a);
      if ((char)uVar2 == '\0') {
        uVar3 = mat_slot_copy_a(uVar2);
        return uVar3;
      }
    }
  }
  if ((char)uVar2 == '\x01') {
    dec_set_special((ushort *)(unaff_ER14 + -0xbe),1);
    uVar2 = dec_set_special((ushort *)(unaff_ER14 + -0xb4),1);
    uVar3 = CONCAT11((char)(uVar2 >> 8),1);
  }
  else {
    dec_set_special((ushort *)(unaff_ER14 + -0xbe),3);
    uVar2 = dec_set_special((ushort *)(unaff_ER14 + -0xb4),3);
    uVar3 = CONCAT11((char)(uVar2 >> 8),3);
  }
  return uVar3;
}

/**
 * @brief 统计函数 X 的包装（0x11C3E + 0x11F50）
 * @addr 0x11ACA
 * @module eval
 * @proto byte stat_wrap_x(undefined2 a)
 * @confidence likely
 * @note 统计函数 X 的包装（0x11C3E + 0x11F50）。
 * @tag app
 */
byte stat_wrap_x(undefined2 a)

{
  undefined uVar1;
  int bVar2;
  ushort uVar3;
  short unaff_ER14;
  
  uVar3 = stat_func_x();
  bVar2 = (byte)uVar3;
  if (bVar2 == 0) {
    bVar2 = stat_entry_common(a);
    if ((bVar2 == 0) && (bVar2 = stat_seq_2(), bVar2 == 0)) {
      stat_seq_1();
      decm_sin(unaff_ER14 + -0xbe,a);
      bVar2 = dec_cmp_ex((undefined2 *)(unaff_ER14 + -0xbe),a);
      if (bVar2 == 0) {
        decm_sin(unaff_ER14 + -0xb4,a);
        bVar2 = dec_copy_to_slot(a);
        if (bVar2 == 0) {
          return 0;
        }
      }
    }
  }
  if (bVar2 == 1) {
    dec_set_special((ushort *)(unaff_ER14 + -0xbe),1);
    dec_set_special((ushort *)(unaff_ER14 + -0xb4),1);
    uVar1 = 1;
  }
  else {
    dec_set_special((ushort *)(unaff_ER14 + -0xbe),3);
    dec_set_special((ushort *)(unaff_ER14 + -0xb4),3);
    uVar1 = 3;
  }
  return uVar1;
}

/**
 * @brief 统计函数 X 的包装变体
 * @addr 0x11B14
 * @module eval
 * @proto byte stat_wrap_x2(undefined2 a)
 * @confidence likely
 * @note 统计函数 X 的包装变体。
 * @tag app
 */
byte stat_wrap_x2(undefined2 a)

{
  undefined uVar1;
  int bVar2;
  ushort uVar3;
  short unaff_ER14;
  
  uVar3 = stat_func_x();
  bVar2 = (byte)uVar3;
  if (bVar2 == 0) {
    bVar2 = stat_entry_common(a);
    if ((bVar2 == 0) && (bVar2 = stat_seq_2(), bVar2 == 0)) {
      stat_seq_1();
      decm_sin(unaff_ER14 + -0xb4,a);
      bVar2 = dec_copy_to_slot(a);
      if (bVar2 == 0) {
        return 0;
      }
    }
  }
  if (bVar2 == 1) {
    dec_set_special((ushort *)(unaff_ER14 + -0xbe),1);
    dec_set_special((ushort *)(unaff_ER14 + -0xb4),1);
    uVar1 = 1;
  }
  else {
    dec_set_special((ushort *)(unaff_ER14 + -0xbe),3);
    dec_set_special((ushort *)(unaff_ER14 + -0xb4),3);
    uVar1 = 3;
  }
  return uVar1;
}

/**
 * @brief 统计函数 Y 的包装（0x11CA6 + 0x11F50）
 * @addr 0x11B46
 * @module eval
 * @proto byte stat_wrap_y(undefined2 a)
 * @confidence likely
 * @note 统计函数 Y 的包装（0x11CA6 + 0x11F50）。
 * @tag app
 */
byte stat_wrap_y(undefined2 a)

{
  undefined uVar1;
  int bVar2;
  ushort uVar3;
  short unaff_ER14;
  
  uVar3 = stat_func_y();
  bVar2 = (byte)uVar3;
  if (bVar2 == 0) {
    bVar2 = stat_entry_common(a);
    if ((bVar2 == 0) && (bVar2 = stat_seq_2(), bVar2 == 0)) {
      stat_seq_1();
      bVar2 = dec_copy_to_slot(a);
      if (bVar2 == 0) {
        return 0;
      }
    }
  }
  if (bVar2 == 1) {
    dec_set_special((ushort *)(unaff_ER14 + -0xbe),1);
    dec_set_special((ushort *)(unaff_ER14 + -0xb4),1);
    uVar1 = 1;
  }
  else {
    dec_set_special((ushort *)(unaff_ER14 + -0xbe),3);
    dec_set_special((ushort *)(unaff_ER14 + -0xb4),3);
    uVar1 = 3;
  }
  return uVar1;
}

/**
 * @brief 统计函数族 V（0x12650 循环驱动）
 * @addr 0x11B6E
 * @module eval
 * @proto byte stat_func_v(void)
 * @confidence likely
 * @note 统计函数族 V（0x12650 循环驱动）。
 * @tag app
 */
byte stat_func_v(void)

{
  int bVar1;
  ushort uVar2;
  undefined extraout_R1;
  undefined extraout_R1_00;
  undefined extraout_R1_01;
  
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
          if (bVar1 == 0) {
            uVar2 = dec_copy_10_slot_ng();
            return uVar2;
          }
        }
      }
    }
  }
  return CONCAT11((char)(uVar2 >> 8),0xf0);
}

/**
 * @brief 统计函数族 W（0x12650 循环驱动）
 * @addr 0x11BD6
 * @module eval
 * @proto byte stat_func_w(void)
 * @confidence likely
 * @note 统计函数族 W（0x12650 循环驱动）。
 * @tag app
 */
byte stat_func_w(void)

{
  int bVar1;
  ushort uVar2;
  undefined extraout_R1;
  undefined extraout_R1_00;
  undefined extraout_R1_01;
  
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
          if (bVar1 == 0) {
            uVar2 = dec_copy_10_slot_ng();
            return uVar2;
          }
        }
      }
    }
  }
  return CONCAT11((char)(uVar2 >> 8),0xf0);
}

/**
 * @brief 统计函数族 X（0x12650 循环驱动）
 * @addr 0x11C3E
 * @module eval
 * @proto byte stat_func_x(void)
 * @confidence likely
 * @note 统计函数族 X（0x12650 循环驱动）。
 * @tag app
 */
byte stat_func_x(void)

{
  int bVar1;
  ushort uVar2;
  undefined extraout_R1;
  undefined extraout_R1_00;
  undefined extraout_R1_01;
  
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
          if (bVar1 == 0) {
            uVar2 = dec_copy_10_slot_ng();
            return uVar2;
          }
        }
      }
    }
  }
  return CONCAT11((char)(uVar2 >> 8),0xf0);
}

/**
 * @brief 统计函数族 Y（0x12650 循环驱动）
 * @addr 0x11CA6
 * @module eval
 * @proto byte stat_func_y(void)
 * @confidence likely
 * @note 统计函数族 Y（0x12650 循环驱动）。
 * @tag app
 */
byte stat_func_y(void)

{
  int bVar1;
  ushort uVar2;
  undefined extraout_R1;
  undefined extraout_R1_00;
  undefined extraout_R1_01;
  
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
          if (bVar1 == 0) {
            uVar2 = dec_copy_10_slot_ng();
            return uVar2;
          }
        }
      }
    }
  }
  return CONCAT11((char)(uVar2 >> 8),0xf0);
}

/**
 * @brief 统计函数族 Z（0x12650 循环驱动）
 * @addr 0x11D0E
 * @module eval
 * @proto byte stat_func_z(void)
 * @confidence likely
 * @note 统计函数族 Z（0x12650 循环驱动）。
 * @tag app
 */
byte stat_func_z(void)

{
  int bVar1;
  ushort uVar2;
  undefined extraout_R1;
  undefined extraout_R1_00;
  undefined extraout_R1_01;
  
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
          if (bVar1 == 0) {
            uVar2 = dec_copy_10_slot_ng();
            return uVar2;
          }
        }
      }
    }
  }
  return CONCAT11((char)(uVar2 >> 8),0xf0);
}

/**
 * @brief 统计运算序列 1（局部 BCD 槽）
 * @addr 0x11D76
 * @module eval
 * @proto void stat_seq_1(void)
 * @confidence likely
 * @note 统计运算序列 1（局部 BCD 槽）。
 * @tag app
 */
int stat_seq_1(void)

{
  undefined2 *puVar1;
  undefined2 *puVar2;
  short unaff_ER14;
  
  puVar1 = (undefined2 *)(unaff_ER14 + -0x1e);
  puVar2 = (undefined2 *)(unaff_ER14 + -0x28);
  dec_copy(puVar2,(undefined2 *)(unaff_ER14 + -0xb4));
  dec_copy(puVar1,(undefined2 *)(unaff_ER14 + -0xbe));
  dec_bin_pow_core(puVar1,unaff_ER14 + -0x50);
  dec_bin_mul_core(puVar2,puVar1);
  dec_bin_div_core(puVar2,unaff_ER14 + -0x5a);
  dec_copy((undefined2 *)(unaff_ER14 + -0xb4),puVar2);
  bcd_type((byte *)puVar2);
  return 0;
}

/**
 * @brief 开方求值段
 * @addr 0x11DCC
 * @module eval
 * @proto byte eval_nroot_op(undefined2* x)
 * @confidence likely
 * @note 开方求值段：先检查操作数类型为 4，再调用 0x1C86C/0x1CA7E 组合开方。
 * @tag eval
 */
byte eval_nroot_op(undefined2* x)

{
  byte bVar1;
  undefined2 uVar2;
  undefined2 *puVar3;
  undefined2 *puVar4;
  ushort *puVar5;
  undefined2 *puVar6;
  short unaff_ER14;
  
  uVar2 = dec_cmp((undefined2 *)(unaff_ER14 + -0x46),x);
  if ((char)uVar2 != '\x04') {
    dec_set_special((ushort *)(unaff_ER14 + -200),3);
    return 3;
  }
  puVar4 = (undefined2 *)(unaff_ER14 + -0x14);
  puVar5 = (ushort *)(unaff_ER14 + -0x1e);
  puVar6 = (undefined2 *)(unaff_ER14 + -0x28);
  dec_copy(puVar6,(undefined2 *)(unaff_ER14 + -0x46));
  dec_copy(puVar5,puVar6);
  dec_bin_pow_core(puVar6,unaff_ER14 + -0x6e);
  puVar3 = (undefined2 *)(unaff_ER14 + -100);
  dec_copy(puVar4,puVar3);
  decm_pow(puVar4,puVar3);
  dec_bin_mul_core(puVar6,puVar4);
  dec_bin_pow_core(puVar5,unaff_ER14 + -0x82);
  puVar3 = (undefined2 *)(unaff_ER14 + -0x78);
  dec_copy(puVar4,puVar3);
  decm_pow(puVar4,puVar3);
  dec_bin_mul_core(puVar5,puVar4);
  puVar3 = puVar6;
  dec_bin_pow_core(puVar5,puVar6);
  decm_power_common(puVar5,puVar3);
  dec_copy(puVar6,(undefined2 *)(unaff_ER14 + -0x46));
  dec_bin_pow_core(puVar6,unaff_ER14 + -0x8c);
  dec_copy(puVar4,(undefined2 *)(unaff_ER14 + -100));
  dec_bin_pow_core(puVar4,unaff_ER14 + -0x78);
  dec_bin_mul_core(puVar6,puVar4);
  dec_bin_and_core(puVar6,puVar5);
  dec_set_uint_small(puVar5,1);
  if ((byte)((ushort)*(undefined2 *)(unaff_ER14 + -0x20) >> 8) < 4) {
    uVar2 = dec_to_string(puVar6,puVar5);
    if ((char)uVar2 != '\x04') goto LAB_rom_011ee0;
  }
  else {
    *(undefined *)(unaff_ER14 + -0x15) = 6;
    uVar2 = dec_to_string(puVar6,puVar5);
    if ((char)uVar2 != '\x02') goto LAB_rom_011ee0;
  }
  dec_copy(puVar6,puVar5);
LAB_rom_011ee0:
  dec_copy((undefined2 *)(unaff_ER14 + -200),puVar6);
  bVar1 = bcd_type((byte *)puVar6);
  return bVar1;
}

/**
 * @brief 统计运算序列 2（局部 BCD 槽）
 * @addr 0x11EF4
 * @module eval
 * @proto int stat_seq_2(void)
 * @confidence likely
 * @note 统计运算序列 2（局部 BCD 槽）。
 * @tag app
 */
int stat_seq_2(void)

{
  short sVar1;
  undefined2 *puVar2;
  undefined2 *puVar3;
  short unaff_ER14;
  
  puVar2 = (undefined2 *)(unaff_ER14 + -0x14);
  puVar3 = (undefined2 *)(unaff_ER14 + -0x28);
  dec_copy(puVar3,(undefined2 *)(unaff_ER14 + -0x78));
  dec_copy(puVar2,(undefined2 *)(unaff_ER14 + -0xbe));
  dec_bin_pow_core(puVar2,unaff_ER14 + -100);
  dec_bin_mul_core(puVar3,puVar2);
  sVar1 = unaff_ER14 + -0x46;
  dec_bin_and_core(puVar3,sVar1);
  dec_cmp_ex(puVar3,sVar1);
  dec_copy((undefined2 *)(unaff_ER14 + -0xb4),puVar3);
  bcd_type((byte *)puVar3);
  return 0;
}

/**
 * @brief 统计函数公共入口
 * @addr 0x11F50
 * @module eval
 * @proto byte stat_entry_common(undefined2 a)
 * @confidence likely
 * @note 统计函数公共入口：0x1D5B6 比较后调用 0x11D76/0x11EF4 等序列。
 * @tag app
 */
byte stat_entry_common(undefined2 a)

{
  byte bVar1;
  undefined2 uVar2;
  undefined2 *puVar3;
  undefined2 *puVar4;
  undefined2 *puVar5;
  undefined2 *puVar6;
  short unaff_ER14;
  
  uVar2 = dec_cmp((undefined2 *)(unaff_ER14 + -0x46),a);
  if ((char)uVar2 != '\x04') {
    dec_set_special((ushort *)(unaff_ER14 + -0xbe),3);
    return 3;
  }
  puVar4 = (undefined2 *)(unaff_ER14 + -0x14);
  puVar5 = (undefined2 *)(unaff_ER14 + -0x1e);
  puVar6 = (undefined2 *)(unaff_ER14 + -0x28);
  dec_copy(puVar4,(undefined2 *)(unaff_ER14 + -0x46));
  dec_bin_pow_core(puVar4,unaff_ER14 + -0x8c);
  dec_copy(puVar6,(undefined2 *)(unaff_ER14 + -100));
  dec_bin_pow_core(puVar6,unaff_ER14 + -0x78);
  dec_bin_mul_core(puVar4,puVar6);
  dec_copy(puVar5,(undefined2 *)(unaff_ER14 + -0x46));
  dec_bin_pow_core(puVar5,unaff_ER14 + -0x6e);
  puVar3 = (undefined2 *)(unaff_ER14 + -100);
  dec_copy(puVar6,puVar3);
  decm_pow(puVar6,puVar3);
  dec_bin_mul_core(puVar5,puVar6);
  dec_bin_and_core(puVar4,puVar5);
  dec_cmp_ex(puVar4,puVar5);
  dec_copy((undefined2 *)(unaff_ER14 + -0xbe),puVar4);
  bVar1 = bcd_type((byte *)puVar4);
  return bVar1;
}

/**
 * @brief 统计载入行 A（0x8F34/0x8EF2 取行数据）
 * @addr 0x12008
 * @module eval
 * @proto void stat_load_row_a(void)
 * @confidence likely
 * @note 统计载入行 A（0x8F34/0x8EF2 取行数据）。
 * @tag app
 */
int stat_load_row_a(void)

{
  undefined uVar1;
  char cVar2;
  byte unaff_R12;
  short unaff_ER14;
  
  uVar1 = stat_table_base((undefined2 *)(unaff_ER14 + -0x14));
  *(undefined *)(unaff_ER14 + -9) = uVar1;
  stat_cell_addr_ex(CONCAT11(1,unaff_R12 & 1),(short *)(unaff_ER14 + -4));
  if (var_list_open != '\0') {
    stat_cell_addr_ex(0x102,(short *)(unaff_ER14 + -4));
  }
  cVar2 = stat_table_width();
  *(char *)(unaff_ER14 + -10) = cVar2 * '\n';
  return 0;
}

/**
 * @brief 统计载入行 B（0x8F34/0x8EF2）
 * @addr 0x1204A
 * @module eval
 * @proto void stat_load_row_b(void)
 * @confidence likely
 * @note 统计载入行 B（0x8F34/0x8EF2）。
 * @tag app
 */
int stat_load_row_b(void)

{
  undefined uVar1;
  char cVar2;
  short unaff_ER14;
  
  uVar1 = stat_table_base((undefined2 *)(unaff_ER14 + -0x14));
  *(undefined *)(unaff_ER14 + -9) = uVar1;
  stat_cell_addr_ex(0x100,(short *)(unaff_ER14 + -4));
  stat_cell_addr_ex(0x101,(short *)(unaff_ER14 + -4));
  if (var_list_open != '\0') {
    stat_cell_addr_ex(0x102,(short *)(unaff_ER14 + -4));
  }
  cVar2 = stat_table_width();
  *(char *)(unaff_ER14 + -10) = cVar2 * '\n';
  return 0;
}

/**
 * @brief 矩阵单元二元运算 A（2.3KB，0x1D730/0x1CF54 链）
 * @addr 0x12098
 * @module eval
 * @proto int mat_cell_binary_a(void)
 * @confidence likely
 * @note 矩阵单元二元运算 A（2.3KB，0x1D730/0x1CF54 链）。
 * @tag matrix
 */
int mat_cell_binary_a(void)

{
  byte bVar1;
  ushort uVar2;
  undefined2 *puVar3;
  undefined2 *unaff_ER4;
  byte unaff_R6;
  char unaff_R7;
  undefined2 *unaff_ER8;
  undefined2 *unaff_ER10;
  byte unaff_R12;
  char unaff_R13;
  short unaff_ER14;
  
  stat_load_row_b();
  if (unaff_R7 == '\0') {
    dec_set_special((ushort *)(unaff_ER14 + -0x28),3);
  }
  else {
    unaff_R13 = '\0';
    if (((unaff_R12 & 0xf0) == 0) && ((stat_rows & 0x40) != 0)) {
      var_load_to_reg((undefined2 *)(unaff_ER14 + -0x28),0x82);
      unaff_R13 = '\x01';
    }
    else {
      dec_set_uint_small((ushort *)(unaff_ER14 + -0x28),0);
      do {
        puVar3 = unaff_ER4;
        dec_copy((undefined2 *)(unaff_ER14 + -0x14),unaff_ER4);
        dec_bin_init((undefined2 *)(unaff_ER14 + -0x14),puVar3);
        puVar3 = unaff_ER10;
        dec_copy((undefined2 *)(unaff_ER14 + -0x1e),unaff_ER10);
        dec_bin_init((undefined2 *)(unaff_ER14 + -0x1e),puVar3);
        if ((unaff_R12 & 0x10) != 0) {
          dec_bin_mul_core(unaff_ER14 + -0x14,unaff_ER14 + -0x50);
          puVar3 = (undefined2 *)(unaff_ER14 + -0x5a);
          dec_bin_mul_core(unaff_ER14 + -0x1e,puVar3);
        }
        decm_pow((undefined2 *)(unaff_ER14 + -0x14),puVar3);
        if (var_list_open != '\0') {
          puVar3 = unaff_ER8;
          dec_copy((undefined2 *)(unaff_ER14 + -0x32),unaff_ER8);
          dec_bin_init((undefined2 *)(unaff_ER14 + -0x32),puVar3);
          dec_bin_pow_core(unaff_ER14 + -0x14,unaff_ER14 + -0x32);
        }
        dec_bin_pow_core(unaff_ER14 + -0x14,unaff_ER14 + -0x1e);
        dec_bin_div_core(unaff_ER14 + -0x28,unaff_ER14 + -0x14);
        bVar1 = bcd_type((byte *)(unaff_ER14 + -0x28));
        if (bVar1 != 0) break;
        uVar2 = (ushort)unaff_R6;
        unaff_ER4 = (undefined2 *)((short)unaff_ER4 + uVar2);
        unaff_ER8 = (undefined2 *)((short)unaff_ER8 + uVar2);
        unaff_ER10 = (undefined2 *)((short)unaff_ER10 + uVar2);
        unaff_R7 = unaff_R7 + -1;
      } while (unaff_R7 != '\0');
    }
  }
  dec_copy((undefined2 *)(unaff_ER14 + -0xaa),(undefined2 *)(unaff_ER14 + -0x28));
  bVar1 = bcd_type((byte *)(unaff_ER14 + -0x28));
  if ((unaff_R13 == '\0') && ((unaff_R12 & 0xf0) == 0)) {
    var_store_from_reg(0x82,(undefined2 *)(unaff_ER14 + -0x28));
    stat_rows = stat_rows | 0x40;
  }
  return bVar1;
}

