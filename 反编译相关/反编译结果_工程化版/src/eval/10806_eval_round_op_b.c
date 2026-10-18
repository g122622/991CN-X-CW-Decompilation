/*
 * 表达式求值 / 10806_eval_round_op_b.c
 * 地址范围: 0x10806 - 0x10F6A
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 数值取整/舍入求值变体（1..n 参数）
 * @addr 0x10806
 * @module eval
 * @proto int eval_round_op_b(void)
 * @confidence likely
 * @note 数值取整/舍入求值变体（1..n 参数）。
 * @tag eval
 */
int eval_round_op_b(void)

{
  byte bVar1;
  undefined2 uVar2;
  undefined extraout_R1;
  undefined2 *puVar3;
  ushort *unaff_ER10;
  ushort *unaff_ER12;
  short unaff_ER14;
  
  dec_set_uint_small(unaff_ER10,1);
  if ((*(byte *)(unaff_ER14 + -8) & 1) == 0) {
    uVar2 = 0x88;
  }
  else {
    uVar2 = 0x97;
  }
  *(undefined2 *)(unaff_ER14 + -0x16) = uVar2;
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

/**
 * @brief 移位类运算
 * @addr 0x10882
 * @module eval
 * @proto undefined2 eval_shift_op(void)
 * @confidence likely
 * @note 移位类运算：复制操作数后调用 0x1C830（乘）与 0x1C858（或）做移位合成。
 * @tag eval
 */
undefined2 eval_shift_op(void)

{
  short sVar1;
  short unaff_ER14;
  
  dec_copy((undefined2 *)(unaff_ER14 + -0x5a),(undefined2 *)(unaff_ER14 + -0xa0));
  sVar1 = unaff_ER14 + -0x96;
  if (*(char *)(unaff_ER14 + -8) == '\0') {
    dec_bin_or_core(unaff_ER14 + -0x5a,sVar1);
  }
  else {
    dec_bin_mul_core(unaff_ER14 + -0x5a,sVar1);
  }
  dec_cmp((undefined2 *)(unaff_ER14 + -0x5a),sVar1);
  return;
}

/**
 * @brief 求值错误处理
 * @addr 0x108BA
 * @module eval
 * @proto void eval_error(byte code)
 * @confidence strong
 * @note 求值错误处理：设置错误码并写结果。
 * @tag eval
 */
int eval_error(byte code)

{
  undefined2 uVar1;
  ushort *unaff_ER10;
  short unaff_ER14;
  
  if ((code == 10) || (code == 1)) {
    **(char **)(unaff_ER14 + -2) = **(char **)(unaff_ER14 + -2) + -1;
  }
  *(byte *)(unaff_ER14 + -9) = code;
  dec_set_special((ushort *)(unaff_ER14 + -0x28),code);
  uVar1 = dec_set_uint_small(unaff_ER10,0);
  base_clear(CONCAT11((char)((ushort)uVar1 >> 8),*(undefined *)(unaff_ER14 + -10)), (uintptr_t)0)
                 (undefined *)(unaff_ER14 + -0x8c));
  return 0;
}

/**
 * @brief 求值器
 * @addr 0x108EC
 * @module eval
 * @proto byte eval_get_operand(void)
 * @confidence strong
 * @note 求值器：取当前操作数（处理阶乘/括号等）。
 * @tag eval
 */
byte eval_get_operand(void)

{
  int bVar1;
  undefined extraout_R1;
  undefined2 *puVar2;
  undefined2 *unaff_ER12;
  short unaff_ER14;
  
  bVar1 = bcd_type((byte *)(unaff_ER14 + -0x46));
  if (bVar1 == 0) {
    puVar2 = (undefined2 *)(unaff_ER14 + -0x46);
    dec_copy(unaff_ER12,puVar2);
    dec_cmp_ex(unaff_ER12,puVar2);
    base_clear(CONCAT11(extraout_R1,*(undefined *)(unaff_ER14 + -10)),(undefined *)unaff_ER12);
    puVar2 = *(undefined2 **)(unaff_ER14 + -2);
    *puVar2 = *(undefined2 *)(unaff_ER14 + -4);
    bVar1 = matrix_entry(puVar2,unaff_ER14 - 0xa0);
    if (bVar1 == 0) {
      return 0;
    }
  }
  dec_set_special((ushort *)(unaff_ER14 + -0xa0),bVar1);
  dec_set_special((ushort *)(unaff_ER14 + -0x96),bVar1);
  return bVar1;
}

/**
 * @brief 比较类运算（<,>,=,≤,≥）
 * @addr 0x1094A
 * @module eval
 * @proto undefined2 eval_cmp_op(void)
 * @confidence strong
 * @note 比较类运算（<,>,=,≤,≥）：把操作数乘/复制后与 1 比较，按三种结果写回。
 * @tag eval
 */
undefined2 eval_cmp_op(void)

{
  char cVar1;
  byte bVar2;
  undefined2 uVar3;
  undefined2 *puVar4;
  undefined uVar6;
  short sVar5;
  ushort *unaff_ER10;
  ushort *unaff_ER12;
  short unaff_ER14;
  
  puVar4 = (undefined2 *)(unaff_ER14 + -0x3c);
  dec_copy(unaff_ER12,puVar4);
  dec_bin_result(unaff_ER12,puVar4);
  uVar6 = (undefined)((ushort)puVar4 >> 8);
  dec_set_uint_small(unaff_ER10,0);
  uVar3 = CONCAT11(uVar6,1);
  dec_set_uint_small((ushort *)(unaff_ER14 + -0x28),1);
  *(undefined2 *)(unaff_ER14 + -0x20) = 7;
  uVar3 = dec_cmp(unaff_ER12,uVar3);
  if ((char)uVar3 == '\x01') {
    dec_set_uint_small(unaff_ER12,1);
    *(undefined2 *)(unaff_ER14 + -0xc) = 0x93;
  }
  else {
    cVar1 = dec_cmp_bool(unaff_ER12);
    if (cVar1 == '\x02') {
      dec_copy(unaff_ER12,(undefined2 *)(unaff_ER14 + -0x28));
    }
    else {
      dec_set_uint_small(unaff_ER10,1);
      *(undefined2 *)(unaff_ER14 + -0x16) = 0x93;
      dec_bin_pow_core(unaff_ER12,unaff_ER10);
    }
  }
  dec_copy((undefined2 *)(unaff_ER14 + -100),unaff_ER12);
  dec_bin_xor_core(unaff_ER12,(undefined2 *)(unaff_ER14 + -0x3c));
  dec_copy((undefined2 *)(unaff_ER14 + -0x46),unaff_ER12);
  bVar2 = eval_get_operand();
  if (bVar2 == 0) {
    dec_copy((undefined2 *)(unaff_ER14 + -0xaa),(undefined2 *)(unaff_ER14 + -0xa0));
    dec_bin_or_core(unaff_ER14 + -0xaa,unaff_ER14 + -0x96);
    dec_copy(unaff_ER12,(undefined2 *)(unaff_ER14 + -0x3c));
    dec_bin_or_core(unaff_ER12,unaff_ER14 + -100);
    dec_copy((undefined2 *)(unaff_ER14 + -0x46),unaff_ER12);
    bVar2 = eval_get_operand();
    if (bVar2 != 0) {
      dec_copy(unaff_ER10,(undefined2 *)(unaff_ER14 + -100));
      dec_copy(unaff_ER12,(undefined2 *)(unaff_ER14 + -0xaa));
LAB_rom_010aac:
      dec_bin_and_core(unaff_ER12,unaff_ER10);
      bcd_type((byte *)unaff_ER12);
      return;
    }
    dec_copy(unaff_ER12,(undefined2 *)(unaff_ER14 + -0xa0));
    dec_bin_or_core(unaff_ER12,unaff_ER14 + -0x96);
    if ((*(byte *)(unaff_ER14 + -8) & 2) == 0) {
      dec_bin_or_core(unaff_ER14 + -0xaa,unaff_ER12);
    }
    else {
      dec_bin_mul_core(unaff_ER14 + -0xaa,unaff_ER12);
    }
    dec_copy(unaff_ER10,(undefined2 *)(unaff_ER14 + -100));
    dec_bin_xor_core(unaff_ER10,unaff_ER10);
    dec_copy(unaff_ER12,(undefined2 *)(unaff_ER14 + -0xaa));
    dec_bin_and_core(unaff_ER12,unaff_ER10);
    bcd_type((byte *)unaff_ER12);
  }
  else {
    dec_copy(unaff_ER12,(undefined2 *)(unaff_ER14 + -0x3c));
    dec_bin_or_core(unaff_ER12,unaff_ER14 + -100);
    dec_copy((undefined2 *)(unaff_ER14 + -0x46),unaff_ER12);
    bVar2 = eval_get_operand();
    if (bVar2 == 0) {
      dec_copy(unaff_ER12,(undefined2 *)(unaff_ER14 + -0xa0));
      sVar5 = unaff_ER14 + -0x96;
      dec_bin_or_core(unaff_ER12,sVar5);
      dec_inc5(unaff_ER12,sVar5);
      dec_copy(unaff_ER10,(undefined2 *)(unaff_ER14 + -100));
      goto LAB_rom_010aac;
    }
  }
  return;
}

/**
 * @brief 求两个操作数之差的绝对值（0x1D89E 取值后相减并取补）
 * @addr 0x10B12
 * @module eval
 * @proto ushort eval_diff_abs(void)
 * @confidence likely
 * @note 求两个操作数之差的绝对值（0x1D89E 取值后相减并取补）。
 * @tag eval
 */
ushort eval_diff_abs(uintptr_t _a2, int _a1)

{
  char cVar1;
  char cVar2;
  ushort uVar3;
  ushort uVar4;
  undefined2 uVar5;
  short unaff_ER14;
  
  uVar3 = dec_unary_sin((undefined2 *)(unaff_ER14 + -0x6e),_a1);
  uVar4 = dec_unary_sin((undefined2 *)(unaff_ER14 + -0x5a),_a1);
  cVar2 = (byte)uVar4 - (byte)uVar3;
  cVar1 = ((char)(uVar4 >> 8) - (char)(uVar3 >> 8)) - ((byte)uVar4 < (byte)uVar3);
  uVar5 = CONCAT11(cVar1,cVar2);
  if (cVar1 == -1) {
    cVar2 = -cVar2;
    uVar5 = CONCAT11(cVar2 + -1,cVar2);
  }
  return uVar5;
}

/**
 * @brief 逻辑类运算（And/Or/Xor/Not 的求值段）
 * @addr 0x10B3E
 * @module eval
 * @proto undefined2 eval_logic_op(void)
 * @confidence likely
 * @note 逻辑类运算（And/Or/Xor/Not 的求值段）。
 * @tag eval
 */
undefined2 eval_logic_op(void)

{
  byte bVar1;
  char cVar2;
  ushort uVar3;
  undefined2 uVar4;
  undefined2 *puVar5;
  undefined extraout_R1;
  byte extraout_R1_00;
  short sVar6;
  byte bVar7;
  short unaff_ER14;
  
  bVar7 = 0;
  while( true ) {
    uVar3 = kbd_wait_key();
    if ((char)uVar3 != '\0') {
      return uVar3;
    }
    uVar4 = dec_cmp_bool((undefined2 *)(unaff_ER14 + -0x50));
    if ((char)uVar4 == '\x01') break;
    puVar5 = (undefined2 *)(unaff_ER14 + -0x46);
    dec_copy(puVar5,(undefined2 *)(unaff_ER14 + -0x3c));
    dec_bin_xor_core(puVar5,(undefined2 *)(unaff_ER14 + -0x50));
    dec_bin_and_core(puVar5,0x1b76);
    bVar1 = eval_get_operand();
    if (bVar1 != 0) {
      return CONCAT11(extraout_R1,bVar1);
    }
    puVar5 = (undefined2 *)(unaff_ER14 + -0x14);
    dec_copy(puVar5,(undefined2 *)(unaff_ER14 + -0xa0));
    sVar6 = unaff_ER14 + -0x96;
    dec_bin_mul_core(puVar5,sVar6);
    uVar4 = dec_cmp(puVar5,sVar6);
    cVar2 = (char)uVar4;
    if (cVar2 == '\x01') {
      dec_copy((undefined2 *)(unaff_ER14 + -0x3c),(undefined2 *)(unaff_ER14 + -0x46));
      dec_copy((undefined2 *)(unaff_ER14 + -0x5a),(undefined2 *)(unaff_ER14 + -0x14));
      return (ushort)extraout_R1_00 << 8;
    }
    uVar4 = dec_cmp((undefined2 *)(unaff_ER14 + -0x6e),sVar6);
    if ((char)uVar4 == '\x04') {
      if (cVar2 == '\x02') goto LAB_rom_010bd2;
LAB_rom_010bf2:
      dec_copy((undefined2 *)(unaff_ER14 + -0x50),(undefined2 *)(unaff_ER14 + -0x46));
      puVar5 = (undefined2 *)(unaff_ER14 + -0x14);
      uVar4 = dec_copy((undefined2 *)(unaff_ER14 + -0x6e),puVar5);
    }
    else {
      if (cVar2 != '\x04') goto LAB_rom_010bf2;
LAB_rom_010bd2:
      dec_copy((undefined2 *)(unaff_ER14 + -0x3c),(undefined2 *)(unaff_ER14 + -0x46));
      puVar5 = (undefined2 *)(unaff_ER14 + -0x14);
      uVar4 = dec_copy((undefined2 *)(unaff_ER14 + -0x5a),puVar5);
    }
    if (((4 < bVar7) && (uVar4 = eval_diff_abs(puVar5), (byte)uVar4 < 4)) ||
       (bVar7 = bVar7 + 1, 100 < bVar7)) break;
  }
  return CONCAT11((char)((ushort)uVar4 >> 8),10);
}

/**
 * @brief 求倒数段
 * @addr 0x10C4E
 * @module eval
 * @proto undefined2 eval_recip(void)
 * @confidence strong
 * @note 求倒数段：调用 0x1D25A（1/x）后接 0x1CF68（除法）。
 * @tag eval
 */
undefined2 eval_recip(uintptr_t _a2, int _a1)

{
  char cVar1;
  ushort uVar2;
  undefined2 uVar3;
  undefined2 *puVar4;
  undefined2 auStack_38 [5];
  undefined2 auStack_2e [5];
  undefined2 auStack_24 [16];
  
  puVar4 = _a1;
  dec_copy(auStack_38,_a1);
  uVar2 = dec_type_of((undefined *)auStack_38);
  cVar1 = (char)uVar2;
  if ((cVar1 != ' ') && (cVar1 != -0x80)) {
    if ((cVar1 != '\0') || (uVar2 = fmt_check(auStack_38), (char)uVar2 == '\0')) {
LAB_rom_010cc8:
      return CONCAT11((char)(uVar2 >> 8),1);
    }
    uVar3 = dec_cmp(auStack_2e,puVar4);
    if ((char)uVar3 != '\x01') {
      decm_recip(auStack_2e,auStack_24);
      dec_bin_div(auStack_38,auStack_2e);
      uVar2 = dec_type_of((undefined *)auStack_38);
      if ((char)uVar2 != ' ') goto LAB_rom_010cc8;
    }
    uVar2 = dec_copy(_a1,auStack_38);
  }
  return uVar2 & 0xff00;
}

/**
 * @brief 求倒数段的变体（不同操作数字节对齐）
 * @addr 0x10DF4
 * @module eval
 * @proto undefined2 eval_recip2(void)
 * @confidence likely
 * @note 求倒数段的变体（不同操作数字节对齐）。
 * @tag eval
 */
undefined2 eval_recip2(uintptr_t _a2, int _a1)

{
  ushort uVar1;
  undefined2 *unaff_ER8;
  short unaff_ER14;
  
  uVar1 = fmt_check(unaff_ER8);
  if (((char)uVar1 != '\0') &&
     (uVar1 = dec_cmp((undefined2 *)(unaff_ER14 + -0x3c),_a1), (char)uVar1 != '\x01')) {
    decm_recip(unaff_ER14 + -0x3c,(undefined2 *)(unaff_ER14 + -0x32));
    dec_bin_div(unaff_ER8,(undefined2 *)(unaff_ER14 + -0x3c));
    uVar1 = dec_type_of((undefined *)unaff_ER8);
    if ((char)uVar1 == ' ') {
      return uVar1 & 0xff00;
    }
  }
  return CONCAT11((char)(uVar1 >> 8),1);
}

/**
 * @brief 读取 0x3:0xFFDC 处 16 位值（微函数
 * @addr 0x10E34
 * @module eval
 * @proto short get_ptr_ffd8_4(void)
 * @confidence verified
 * @note 读取 0x3:0xFFDC 处 16 位值（微函数：XR12=4 跳入 0x10E4A）。
 * @tag util
 */
short get_ptr_ffd8_4(void)

{
  read_ptrtab_ffd8();
  return;
}

/**
 * @brief 读取 0x3:0xFFDA 处 16 位值（微函数
 * @addr 0x10E3A
 * @module eval
 * @proto short get_ptr_ffd8_2(void)
 * @confidence verified
 * @note 读取 0x3:0xFFDA 处 16 位值（微函数：XR12=2 跳入 0x10E4A）。
 * @tag util
 */
short get_ptr_ffd8_2(void)

{
  read_ptrtab_ffd8();
  return;
}

/**
 * @brief 读取 0x3:0xFFD9 处 16 位值（微函数
 * @addr 0x10E40
 * @module eval
 * @proto short get_ptr_ffd8_1(void)
 * @confidence verified
 * @note 读取 0x3:0xFFD9 处 16 位值（微函数：XR12=1 跳入 0x10E4A）。
 * @tag util
 */
short get_ptr_ffd8_1(void)

{
  read_ptrtab_ffd8();
  return;
}

/**
 * @brief 恒返回 0xFF
 * @addr 0x10E46
 * @module eval
 * @proto short return_ff(void)
 * @confidence verified
 * @note 恒返回 0xFF。
 * @tag util
 */
short return_ff(void)

{
  return 0xff;
}

/**
 * @brief 返回 0x3:0xFFD8+XR12 处的 16 位值（XR12 由各微入口设置）
 * @addr 0x10E4A
 * @module eval
 * @proto short read_ptrtab_ffd8(void)
 * @confidence verified
 * @note 返回 0x3:0xFFD8+XR12 处的 16 位值（XR12 由各微入口设置）。
 * @tag util
 */
short read_ptrtab_ffd8(void)

{
  short unaff_ER12;
  
  return *(undefined *)(uint3)(unaff_ER12 - 0x28);
}

/**
 * @brief 从 0xFFF8 表逐项 0x22492 载入矩阵维度（6 项写入 +0x0B 起）
 * @addr 0x10E58
 * @module eval
 * @proto void matrix_seed_dims(short er0)
 * @confidence likely
 * @note 从 0xFFF8 表逐项 0x22492 载入矩阵维度（6 项写入 +0x0B 起）。
 * @tag matrix
 */
int matrix_seed_dims(short er0)

{
  byte *pbVar1;
  char cVar2;
  undefined extraout_R1;
  undefined2 *puVar3;
  char cVar4;
  ushort uVar5;
  
  puVar3 = (undefined2 *)((uintptr_t)er0 + 0xb);
  uVar5 = 0xfff8;
  cVar4 = '\x06';
  do {
    pbVar1 = (byte *)(uint3)uVar5;
    uVar5 = uVar5 + 1;
    cVar2 = nibble_to_ascii(*pbVar1);
    *puVar3 = CONCAT11(extraout_R1,cVar2);
    puVar3 = puVar3 + -1;
    cVar4 = cVar4 + -1;
  } while (cVar4 != '\0');
  return 0;
}

/**
 * @brief 把 ROM 0xFFC0 起的 24 字节默认设置复制到 0xD11A..0xD131
 * @addr 0x10E80
 * @module eval
 * @proto void defaults_load(void)
 * @confidence verified
 * @note 把 ROM 0xFFC0 起的 24 字节默认设置复制到 0xD11A..0xD131。
 * @tag setup
 */
int defaults_load(void)

{
  char cVar1;
  ushort uVar2;
  undefined *puVar3;
  
  puVar3 = &menu_sel_a;
  uVar2 = 0xffc0;
  cVar1 = '\x18';
  do {
    nop();
    *puVar3 = *(undefined *)(uint3)uVar2;
    puVar3 = puVar3 + 1;
    uVar2 = uVar2 + 1;
    cVar1 = cVar1 + -1;
  } while (cVar1 != '\0');
  return 0;
}

/**
 * @brief 设置模式复位
 * @addr 0x10E9C
 * @module eval
 * @proto void details_reset(void)
 * @confidence likely
 * @note 设置模式复位：清 0xD122/0xD123；亮度 0xD153 不在 11..31 时复位为 0x14并调用
 *       0x9304；清 0xD125，把 0xD12B 限制为 >=1。
 * @tag setup
 */
int details_reset(void)

{
  menu_state_a = 0;
  menu_state_b = 0;
  if (((byte)(SBORROW1(contrast,'\v') ^ (char)(contrast + -0xb) < '\0') == 1) ||
     ((byte)(SBORROW1(contrast,'\x1f') ^ (char)(contrast + -0x1f) < '\0' |
            contrast == '\x1f') == 0)) {
    contrast = '\x14';
    contrast_set(0x14);
  }
  if ((menu_sel_c < '\0') ||
     ((byte)(SBORROW1(menu_sel_c,'\x01') ^ (char)(menu_sel_c + -1) < '\0' |
            menu_sel_c == '\x01') == 0)) {
    menu_sel_c = '\x01';
  }
  menu_state_d = 0;
  return 0;
}

/**
 * @brief 矩阵槽复制 A（0xBE/0xB4 偏移，0x11A62 使用）
 * @addr 0x10EDE
 * @module eval
 * @proto int mat_slot_copy_a(void)
 * @confidence likely
 * @note 矩阵槽复制 A（0xBE/0xB4 偏移，0x11A62 使用）。
 * @tag matrix
 */
int mat_slot_copy_a(uintptr_t _a2, int _a1)

{
  undefined2 uVar1;
  char cVar2;
  undefined2 *puVar4;
  undefined2 *puVar5;
  undefined8 in_QR8;
  short sVar6;
  ulonglong uVar3;
  
  sVar6 = (short)((ulonglong)in_QR8 >> 0x30);
  uVar3 = CONCAT71((int7)(((ulonglong)CONCAT42(CONCAT22(sVar6,sVar6 + -0xbe),sVar6 + -0xb4) << 0x10)
                         >> 8),5);
  do {
    puVar4 = (undefined2 *)(uVar3 >> 0x10);
    puVar5 = (undefined2 *)(uVar3 >> 0x20);
    uVar1 = *puVar5;
    *puVar5 = *puVar4;
    *puVar4 = uVar1;
    cVar2 = (char)uVar3 + -1;
    uVar3 = (ulonglong)CONCAT51((int5)(((uint6)CONCAT22(puVar5 + 1,puVar4 + 1) << 0x10) >> 8),cVar2)
    ;
  } while (cVar2 != '\0');
  return _a1;
}

/**
 * @brief 矩阵槽复制 B（0xC8/0xB4 偏移）
 * @addr 0x10EE8
 * @module eval
 * @proto void mat_slot_copy_b(void)
 * @confidence likely
 * @note 矩阵槽复制 B（0xC8/0xB4 偏移）。
 * @tag matrix
 */
int mat_slot_copy_b(int _a1)

{
  undefined2 uVar1;
  char cVar2;
  undefined2 *puVar4;
  undefined2 *puVar5;
  undefined8 in_QR8;
  short sVar6;
  ulonglong uVar3;
  
  sVar6 = (short)((ulonglong)in_QR8 >> 0x30);
  uVar3 = CONCAT71((int7)(((ulonglong)CONCAT42(CONCAT22(sVar6,sVar6 + -200),sVar6 + -0xb4) << 0x10)
                         >> 8),5);
  do {
    puVar4 = (undefined2 *)(uVar3 >> 0x10);
    puVar5 = (undefined2 *)(uVar3 >> 0x20);
    uVar1 = *puVar5;
    *puVar5 = *puVar4;
    *puVar4 = uVar1;
    cVar2 = (char)uVar3 + -1;
    uVar3 = (ulonglong)CONCAT51((int5)(((uint6)CONCAT22(puVar5 + 1,puVar4 + 1) << 0x10) >> 8),cVar2)
    ;
  } while (cVar2 != '\0');
  return _a1;
}

/**
 * @brief 乘方/开方求值段
 * @addr 0x10F6A
 * @module eval
 * @proto undefined2 eval_pow_op(void)
 * @confidence strong
 * @note 乘方/开方求值段：调用 0x1CA7E/0x1CAA6 与
 *       0x1CACE（sin）/0x1CAE2（cos）等一元/二元核心。
 * @tag eval
 */
undefined2 eval_pow_op(void)

{
  undefined2 uVar1;
  undefined extraout_R1;
  undefined extraout_R1_00;
  undefined extraout_R1_01;
  undefined2 *puVar2;
  ushort *puVar3;
  ushort *puVar4;
  ushort *puVar5;
  char cVar6;
  ushort *puVar7;
  ushort *puVar8;
  short unaff_ER14;
  
  puVar8 = (ushort *)(unaff_ER14 + -0x14);
  puVar7 = (ushort *)(unaff_ER14 + -0x1e);
  puVar5 = (ushort *)(unaff_ER14 + -0x32);
  puVar4 = (ushort *)(unaff_ER14 + -0x3c);
  puVar2 = *(undefined2 **)(unaff_ER14 + -2);
  dec_copy(puVar8,puVar2);
  dec_bin_init(puVar8,puVar2);
  dec_entry_x(puVar8,puVar2);
  uVar1 = dec_cmp(puVar8,puVar2);
  if ((char)uVar1 == '\x01') {
    dec_set_uint_small(puVar7,5);
    *(undefined2 *)(unaff_ER14 + -0x16) = 0x99;
    return;
  }
  dec_bin_result(puVar8,puVar2);
  if (0x102 < *(ushort *)(unaff_ER14 + -0xc)) {
    dec_set_uint_small(puVar7,0);
    return;
  }
  dec_copy_const(*(ushort *)(unaff_ER14 + -0xc) & 0xff00);
  dec_bin_pow_core(puVar8,puVar4);
  dec_set_uint_small(puVar5,1);
  dec_bin_xor_core(puVar8,puVar5);
  dec_bin_and_core(puVar5,puVar8);
  dec_copy(puVar8,puVar5);
  dec_copy_const(CONCAT11(extraout_R1,5));
  dec_bin_pow_core(puVar8,puVar4);
  dec_copy_const(CONCAT11(extraout_R1_00,4));
  dec_bin_xor_core(puVar8,puVar4);
  cVar6 = '\x03';
  do {
    dec_bin_pow_core(puVar8,puVar5);
    dec_copy_const(CONCAT11(extraout_R1_01,cVar6));
    dec_bin_xor_core(puVar8,puVar4);
    cVar6 = cVar6 + -1;
  } while (cVar6 != '\0');
  dec_bin_pow_core(puVar5,puVar8);
  puVar2 = *(undefined2 **)(unaff_ER14 + -2);
  dec_copy(puVar7,puVar2);
  decm_pow(puVar7,puVar2);
  dec_set_uint_small(puVar4,2);
  puVar3 = puVar4;
  dec_bin_and_core(puVar7,puVar4);
  dec_inc5(puVar7,puVar3);
  decm_sin(puVar7,puVar3);
  dec_bin_pow_core(puVar7,puVar5);
  dec_to_special(puVar8,puVar5);
  dec_bin_pow_core(puVar8,puVar4);
  decm_power_common(puVar8,puVar4);
  dec_bin_and_core(puVar7,puVar8);
  bcd_type((byte *)puVar7);
  return;
}

