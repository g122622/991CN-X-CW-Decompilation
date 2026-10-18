/*
 * BCD 浮点库 / 179b0_dec_set_zero.c
 * 地址范围: 0x179B0 - 0x18198
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 把算数寄存器组置零
 * @addr 0x179B0
 * @module bcd
 * @proto void dec_set_zero(undefined2 a)
 * @confidence likely
 * @note 把算数寄存器组置零。
 * @tag bcd
 */
int dec_set_zero(undefined2 a)

{
  byte *unaff_ER14;
  
  prev_char_ptr((byte *)0x0,unaff_ER14);
  return a;
}

/**
 * @brief BCD 结果归一化/修正
 * @addr 0x179D2
 * @module bcd
 * @proto undefined2 dec_normalize2(undefined2 a, undefined2 b)
 * @confidence strong
 * @note BCD 结果归一化/修正。
 * @tag bcd
 */
undefined2 dec_normalize2(undefined2 a, undefined2 b)

{
  dec_param_a = a;
  dec_param_b = b;
  dec_load_callee();
  return;
}

/**
 * @brief 设置 _D05C=a、_D05E=b 后调用 0x17A1A（十进制运算核心）
 * @addr 0x179E2
 * @module bcd
 * @proto void dec_bin_op_d05c(undefined* a, undefined* b)
 * @confidence verified
 * @note 设置 _D05C=a、_D05E=b 后调用 0x17A1A（十进制运算核心）。
 * @tag bcd
 */
int dec_bin_op_d05c(undefined* a, undefined* b)

{
  dec_param_a = a;
  dec_param_b = b;
  dec_bin_arith();
  return 0;
}

/**
 * @brief 载入 *p 到 X 并清除 0x40 内部标志（0xD009 &= 0xBF），再经 0x1…
 * @addr 0x179F4
 * @module bcd
 * @proto int dec_load_strip_flag(undefined2* p)
 * @confidence strong
 * @note 载入 *p 到 X 并清除 0x40 内部标志（0xD009 &= 0xBF），再经 0x19C9E/0x19370
 *       归一化。
 * @tag bcd
 */
int dec_load_strip_flag(undefined2* p)

{
  dec_load_regs(p);
  if (dec_flags < 0xf0) {
    dec_flags = dec_flags & 0xbf;
  }
  dec_g_X_to_Z2();
  dec_light_normalize();
  return 0;
}

/**
 * @brief 十进制运算核心（0x17A 段）
 * @addr 0x17A1A
 * @module bcd
 * @proto void dec_bin_arith(void)
 * @confidence strong
 * @note 十进制运算核心（0x17A 段）：按 _D05C/_D05E 操作数类型调用 0x17E8E/0x17B4E，由
 *       0x179E2、decm_mul/decm_div 等调用。
 * @tag bcd
 */
int dec_bin_arith(void)

{
  uint5 uVar1;
  byte extraout_R1;
  byte extraout_R1_00;
  undefined8 in_QR0;
  uint6 extraout_var;
  undefined4 extraout_XR4;
  ulonglong uVar2;
  
  uVar1 = CONCAT14(*dec_param_b,(int)CONCAT62((int6)((ulonglong)in_QR0 >> 0x10),dec_param_b)) &
          0xf0ffffffff;
  uVar2 = (ulonglong)uVar1;
  if ((char)(uVar1 >> 0x20) == -0x80) {
    dec_core_17e8e((char)uVar1,(char)(uVar1 >> 8),0,(char)(uVar1 >> 0x18));
    dec_load_and_run((ushort)extraout_R1 << 8,dec_param_b);
    uVar2 = (ulonglong)extraout_var << 0x10;
    dec_param_b = (undefined *)(extraout_var >> 0x20);
    dec_param_a = (undefined *)(extraout_var >> 0x10);
  }
  uVar1 = CONCAT14(*dec_param_a,(int)CONCAT62((int6)(uVar2 >> 0x10),dec_param_a)) & 0xf0ffffffff
  ;
  if ((char)(uVar1 >> 0x20) == -0x80) {
    dec_core_17e8e((char)uVar1,(char)(uVar1 >> 8),0,(char)(uVar1 >> 0x18));
    dec_load_and_run((ushort)extraout_R1_00 << 8,dec_param_a);
    dec_param_b = (undefined *)((uint)extraout_XR4 >> 0x10);
    dec_param_a = (undefined *)extraout_XR4;
  }
  return (short)in_QR0;
}

/**
 * @brief 按 0xD05E（运算参数 B 指针）载入 BCD 单元到 X，并把 0xD01E 置为操作…
 * @addr 0x17A48
 * @module bcd
 * @proto void dec_load_callee(void)
 * @confidence strong
 * @note 按 0xD05E（运算参数 B 指针）载入 BCD 单元到 X，并把 0xD01E 置为操作码。
 * @tag bcd
 */
int dec_load_callee(void)

{
  uint5 uVar1;
  byte extraout_R1;
  undefined8 in_QR0;
  undefined4 extraout_XR4;
  
  uVar1 = CONCAT14(*dec_param_a,(int)CONCAT62((int6)((ulonglong)in_QR0 >> 0x10),dec_param_a)) &
          0xf0ffffffff;
  if ((char)(uVar1 >> 0x20) == -0x80) {
    dec_core_17e8e((char)uVar1,(char)(uVar1 >> 8),0,(char)(uVar1 >> 0x18));
    dec_load_and_run((ushort)extraout_R1 << 8,dec_param_a);
    dec_param_b = (undefined2)((uint)extraout_XR4 >> 0x10);
    dec_param_a = (undefined *)extraout_XR4;
  }
  return (short)in_QR0;
}

/**
 * @brief 十进制运算核心变体（被 0x1874A 调用）
 * @addr 0x17A78
 * @module bcd
 * @proto void dec_bin_arith_b(void)
 * @confidence likely
 * @note 十进制运算核心变体（被 0x1874A 调用）。
 * @tag bcd
 */
int dec_bin_arith_b(uintptr_t _a2, int _a1)

{
  undefined2 *puVar1;
  char cVar2;
  undefined2 *puVar3;
  
  puVar1 = (undefined2 *)dec_ptr_by_idx(_a1);
  dec_param_a = dec_ptr_by_idx(CONCAT11((char)((ushort)puVar1 >> 8),(char)((uint32_t)_a1 >> 8)));
  cVar2 = '\x03';
  for (puVar3 = puVar1;
      (dec_param_b = puVar1, *(char *)puVar3 != '\0' &&
      ((*(char *)puVar3 != '\x01' || (*(char *)(puVar3 + 4) != '\0')))); puVar3 = puVar3 + 10) {
    cVar2 = cVar2 + -1;
    if (cVar2 == '\0') {
      dec_load(puVar1 + 10);
      dec_arith_dual();
      dec_load_regs(dec_param_b + 0x14);
      dec_arith_dual();
      dec_g_X_to_W();
      dec_load_regs(dec_param_b);
      dec_ieee_add();
      dec_store();
      dec_load_regs(dec_param_b + 10);
      dec_g_Y_to_X();
      dec_ieee_add();
      dec_param_a = dec_param_a + 0x14;
      dec_store();
      dec_load_regs(dec_param_b + 0x14);
      dec_g_Y_to_X();
      dec_ieee_add();
      dec_param_a = dec_param_a + 0x14;
      dec_store();
      return 0;
    }
  }
  copy10();
  copy10();
  copy10();
  return 0;
}

/**
 * @brief 载入操作数（0x187DA）后按 _D05E 首字节分派 0x17BD6/0x19CC2/0…
 * @addr 0x17B4E
 * @module bcd
 * @proto void dec_load_and_run(undefined2 b, undefined2* a)
 * @confidence strong
 * @note 载入操作数（0x187DA）后按 _D05E 首字节分派 0x17BD6/0x19CC2/0x1C364/0x19C0E。
 * @tag bcd
 */
int dec_load_and_run(undefined2 b, undefined2* a)

{
  dec_param_b = (char *)dec_ptr_by_idx(b);
  dec_param_a = a;
  if (*dec_param_b == '\0') {
    _DAT_ram_d048 = 0;
    _DAT_ram_d046 = 0;
    _DAT_ram_d04c = 0;
    _DAT_ram_d04a = 0;
    _DAT_ram_d04e = 0;
  }
  else {
    dec_load((undefined2 *)(dec_param_b + 0x14));
    dec_g_X_to_W();
    dec_g_X_to_Z4();
    dec_load_regs((undefined2 *)(dec_param_b + 10));
    dec_normalize_both();
    dec_g_X_to_W2();
  }
  dec_load((undefined2 *)(dec_param_b + 0x32));
  dec_g_X_to_W();
  dec_g_X_to_Z4();
  dec_load_regs((undefined2 *)(dec_param_b + 0x28));
  dec_normalize_both();
  dec_g_Q_to_Y();
  dec_tail_round();
  dec_store();
  dec_status_low();
  return 0;
}

/**
 * @brief 对当前 _D05C/_D05E 两个操作数依次调用 0x1C35C/0x19CC2/0x1C…
 * @addr 0x17BD6
 * @module bcd
 * @proto void dec_normalize_both(void)
 * @confidence likely
 * @note 对当前 _D05C/_D05E 两个操作数依次调用
 *       0x1C35C/0x19CC2/0x1C042/0x1C18C/0x19C56/0x1BE46 规整。
 * @tag bcd
 */
int dec_normalize_both(void)

{
  stat_calc_proc();
  dec_g_Z4_to_Y();
  dec_int_convert();
  dec_g_Y_to_X();
  dec_ieee_add();
  return 0;
}

/**
 * @brief 十进制计算主流程
 * @addr 0x17BEE
 * @module bcd
 * @proto void dec_calc_main(char a0, char a1, char a2, char a3)
 * @confidence likely
 * @note 十进制计算主流程：按 4 字节参数设置 _D05C/_D05E 后进入结果缓冲区遍历。
 * @tag bcd
 */
int dec_calc_main(char a0, char a1, char a2, char a3)

{
  char *pcVar1;
  undefined uVar2;
  undefined uVar3;
  undefined uVar4;
  longlong lVar5;
  char *pcVar9;
  undefined8 uVar6;
  undefined8 uVar7;
  short sVar10;
  byte bVar11;
  undefined5 uVar8;
  
  dec_param_b = CONCAT11(a3,a2);
  dec_param_a = CONCAT11(a1,a0);
  lVar5 = (ulonglong)CONCAT11(a3,a2) << 0x20;
  pcVar1 = (char *)dec_ptr_by_idx(CONCAT11(a1,a0));
  uVar8 = (undefined5)(CONCAT26(pcVar1,(int6)lVar5) >> 0x18);
  lVar5 = (ulonglong)CONCAT51(uVar8,*pcVar1) << 0x10;
  if (*pcVar1 == '\0') {
    if (pcVar1[0x1e] == '\0') {
      dec_regY = 0;
      dec_regY_tail = 0;
      goto LAB_rom_017c86;
    }
    lVar5 = (ulonglong)CONCAT51(uVar8,pcVar1[0x30]) << 0x10;
    if ((pcVar1[0x30] == '\0') &&
       (lVar5 = (ulonglong)CONCAT51(uVar8,pcVar1[0x28]) << 0x10, pcVar1[0x28] == '\x01')) {
      bVar11 = ((undefined2 *)(pcVar1 + 0x32) == (undefined2 *)0x0) << 6;
      dec_load((undefined2 *)(pcVar1 + 0x32));
      base_submode();
      if ((bVar11 >> 6 & 1) == 1) {
        decc_arith_core();
      }
      dec_g_X_to_Z2();
      goto LAB_rom_017c86;
    }
  }
  pcVar9 = (char *)((ulonglong)lVar5 >> 0x30);
  uVar8 = (undefined5)((ulonglong)lVar5 >> 0x18);
  lVar5 = (ulonglong)CONCAT51(uVar8,pcVar9[8]) << 0x10;
  if ((((1 < (byte)pcVar9[8]) ||
       (lVar5 = (ulonglong)CONCAT51(uVar8,pcVar9[0x12]) << 0x10, 2 < (byte)pcVar9[0x12])) ||
      (lVar5 = (ulonglong)CONCAT51(uVar8,pcVar9[0x1c]) << 0x10, 1 < (byte)pcVar9[0x1c])) ||
     (((lVar5 = (ulonglong)CONCAT51(uVar8,pcVar9[0x26]) << 0x10, 1 < (byte)pcVar9[0x26] ||
       (lVar5 = (ulonglong)CONCAT51(uVar8,pcVar9[0x30]) << 0x10, 2 < (byte)pcVar9[0x30])) ||
      (lVar5 = (ulonglong)CONCAT51(uVar8,pcVar9[0x3a]) << 0x10, 1 < (byte)pcVar9[0x3a])))) {
    dec_load_and_run(CONCAT11((char)((ushort)pcVar1 >> 8),dec_param_a), (uintptr_t)0)
                   (short)((ulonglong)lVar5 >> 0x20));
    return 0;
  }
  uVar6 = CONCAT44((int)((ZEXT28(pcVar9) << 0x30) >> 0x20),CONCAT13(*pcVar9,(int3)lVar5));
  if (*pcVar9 == '\0') {
    uVar3 = 1;
    uVar4 = 0;
  }
  else {
    nop_17cec();
    uVar4 = (undefined)((ulonglong)uVar6 >> 0x18);
    uVar6 = CONCAT26((short)((ulonglong)uVar6 >> 0x30),(uint6)(uint)uVar6);
    nop_17cfe();
    uVar6 = CONCAT26((short)((ulonglong)uVar6 >> 0x30),
                     (uint6)(uint)CONCAT62((int6)((ulonglong)uVar6 >> 0x10),
                                           (short)((ulonglong)uVar6 >> 0x10)));
    nop_17cec();
    uVar3 = (undefined)((ulonglong)uVar6 >> 0x18);
  }
  uVar6 = CONCAT26((short)((ulonglong)uVar6 >> 0x30),(uint6)(uint)uVar6);
  nop_17cec();
  uVar2 = (undefined)((ulonglong)uVar6 >> 0x18);
  uVar6 = CONCAT26((short)((ulonglong)uVar6 >> 0x30),(uint6)(uint)uVar6);
  nop_17cfe();
  uVar7 = CONCAT26((short)((ulonglong)uVar6 >> 0x30),(uint6)(uint)uVar6);
  nop_17cec();
  dec_regY_tail = (ushort)uVar7 | 0x8000;
  sVar10 = (short)((ulonglong)uVar7 >> 0x30);
  dec_regY =
       CONCAT17(uVar4,CONCAT16(uVar3,CONCAT24((short)((ulonglong)uVar6 >> 0x10),
                                              CONCAT13(uVar2,CONCAT12((char)((ulonglong)uVar7 >>
                                                                            0x18),
                                                                      CONCAT11(*(undefined *)
                                                                                (sVar10 + 9),
                                                                               *(undefined *)
                                                                                (sVar10 + 0x27))))))
               );
LAB_rom_017c86:
  dec_store_result();
  dec_g_X_to_Y();
  dec_status_low();
  return 0;
}

/**
 * @brief 取操作数（0x187DA）并按 0xD05C/0xD05E 归一化
 * @addr 0x17D1A
 * @module bcd
 * @proto undefined2 dec_get_word(undefined2 a, undefined2 b)
 * @confidence likely
 * @note 取操作数（0x187DA）并按 0xD05C/0xD05E 归一化。
 * @tag bcd
 */
undefined2 dec_get_word(undefined2 a, undefined2 b)

{
  undefined2 *puVar1;
  undefined uVar4;
  ushort uVar2;
  short sVar3;
  undefined2 uVar5;
  
  uVar4 = (undefined)((ushort)a >> 8);
  dec_param_a = a;
  dec_param_b = b;
  puVar1 = (undefined2 *)dec_ptr_by_idx(CONCAT11(uVar4,uVar4));
  dec_ptr_by_idx(CONCAT11((char)((ushort)puVar1 >> 8),(char)a));
  dec_load(puVar1);
  uVar2 = dec_regY;
  if ((char)(dec_regY >> 8) == '\x06') {
    dec_regY = CONCAT11(1,(char)dec_regY);
    uVar2 = dec_accum0;
    if (dec_accum0 != 0) {
      uVar4 = daa((char)(dec_accum0 >> 8) + '\x05');
      uVar2 = CONCAT11(uVar4,(char)dec_accum0) & 0xfff;
      dec_accum0 = uVar2;
    }
  }
  uVar4 = (undefined)(uVar2 >> 8);
  if (((dec_flags != '\0') &&
      (((dec_flags != '\x01' || (dec_accum0 != '\0')) && (dec_flags_Y != '\0')))) &&
     ((dec_flags_Y != '\x01' || (dec_regY != '\0')))) {
    dec_g_X_to_Z();
    dec_g_X_to_W();
    dec_arith_dual();
    dec_g_W_to_Y();
    dec_g_X_to_W();
    dec_ieee_add();
    dec_swap_XZ();
    dec_g_Y_to_X();
    dec_ieee_add();
    uVar4 = 0;
    dec_g_Z_to_Y();
  }
  uVar5 = dec_param_b;
  sVar3 = dec_ptr_by_idx(CONCAT11(uVar4,(char)dec_param_b));
  dec_param_b = dec_ptr_by_idx(CONCAT11((char)((ushort)sVar3 >> 8),(char)((ushort)uVar5 >> 8)));
  dec_param_a = sVar3;
  dec_store();
  dec_store_result();
  return;
}

/**
 * @brief 按 0x187DA 得到的单元指针载入一个 BCD 操作数
 * @addr 0x17DCC
 * @module bcd
 * @proto void dec_arg_load(void)
 * @confidence likely
 * @note 按 0x187DA 得到的单元指针载入一个 BCD 操作数。
 * @tag bcd
 */
int dec_arg_load(uintptr_t _a2, int _a1)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  undefined6 extraout_var;
  undefined2 uVar3;
  
  puVar1 = (undefined8 *)dec_ptr_by_idx(_a1);
  puVar2 = (undefined8 *)
           dec_ptr_by_idx((ushort)CONCAT71((int7)(CONCAT62(extraout_var,puVar1) >> 8))
                                           (char)((uint6)extraout_var >> 0x10)));
  uVar3 = *(undefined2 *)(puVar1 + 1);
  *puVar2 = *puVar1;
  *(undefined2 *)(puVar2 + 1) = uVar3;
  return 0;
}

/**
 * @brief 运算准备
 * @addr 0x17DF4
 * @module bcd
 * @proto void dec_op_setup(undefined2 a, undefined2 b)
 * @confidence likely
 * @note 运算准备：从 0x187DA 结果设置 _D05E/_D05C。
 * @tag bcd
 */
int dec_op_setup(undefined2 _a1, undefined2 _a2)

{
  undefined2 uVar1;
  ulonglong in_QR0;
  undefined6 extraout_var;
  longlong lVar2;
  undefined6 extraout_var_00;
  uint7 uVar3;
  char cVar5;
  short sVar6;
  ulonglong uVar4;
  
  lVar2 = (in_QR0 & 0xffff) << 0x20;
  dec_param_b = dec_ptr_by_idx((ushort)CONCAT71((int7)(in_QR0 >> 8),(char)(in_QR0 >> 0x10)));
  dec_param_a = (undefined8 *)((ulonglong)lVar2 >> 0x20);
  if ((*(byte *)(uintptr_t)dec_param_a & 0xf0) == 0) {
    uVar4 = CONCAT62(CONCAT51((int5)(CONCAT26(dec_param_b,(int6)lVar2) >> 0x18),
                              *(byte *)(uintptr_t)dec_param_a),*(undefined2 *)(dec_param_a + 1)) &
            0xfffffffffff0ffff;
    sVar6 = (short)(uVar4 >> 0x30);
    *(undefined8 *)(sVar6 + 0x1e) = *dec_param_a;
    *(short *)(sVar6 + 0x26) = (short)uVar4;
    uVar1 = evaluator_abort();
    uVar3 = (uint7)(CONCAT62(extraout_var_00,uVar1) >> 8);
    lVar2 = CONCAT71(uVar3,1);
    sVar6 = (short)(uVar4 >> 0x30);
    *(byte *)(uintptr_t)(longlong *)(sVar6 + 0x32) = lVar2;
    uVar1 = (undefined2)uVar4;
    *(undefined2 *)(sVar6 + 0x3a) = uVar1;
    cVar5 = *(char *)(uVar4 >> 0x20);
    uVar4 = CONCAT53((int5)(uVar4 >> 0x18),CONCAT12(cVar5,uVar1));
    if (cVar5 == '\0') {
      lVar2 = (ulonglong)uVar3 << 8;
      uVar4 = CONCAT62((int6)(uVar4 >> 0x10),uVar1) & 0xffffffffffff00ff;
    }
  }
  else {
    dec_load_regs((undefined2 *)(uintptr_t)dec_param_a);
    dec_work_a = 0xf;
    decc_int_prep();
    uVar4 = (ulonglong)dec_param_b;
    dec_param_a = (undefined8 *)(dec_param_b + 0x1e);
    dec_param_b = dec_param_b + 0x32;
    uVar4 = CONCAT44((int)((uVar4 << 0x30) >> 0x20),CONCAT22(dec_param_b,dec_param_a));
    dec_store();
    dec_store_result();
    uVar1 = evaluator_abort();
    lVar2 = CONCAT71((int7)(CONCAT62(extraout_var,uVar1) >> 8),1);
  }
  sVar6 = (short)(uVar4 >> 0x30);
  *(byte *)(uintptr_t)(longlong *)(sVar6 + 0x28) = lVar2;
  *(short *)(sVar6 + 0x30) = (short)uVar4;
  eval_result_init((short)((ulonglong)lVar2 >> 0x10));
  return 0;
}

/**
 * @brief 十进制运算核心（被 0x17A1A 等调用）
 * @addr 0x17E8E
 * @module bcd
 * @proto undefined2 dec_core_17e8e(char a, char b, char c, char d)
 * @confidence likely
 * @note 十进制运算核心（被 0x17A1A 等调用）：以 0x187DA 解引用操作数后运算并写回。
 * @tag bcd
 */
undefined2 dec_core_17e8e(char a, char b, char c, char d)

{
  int bVar1;
  undefined uVar2;
  undefined extraout_R1;
  undefined2 unaff_ER4;
  undefined2 unaff_ER6;
  ushort uVar3;
  undefined4 unaff_XR8;
  ulonglong uVar4;
  undefined8 uVar5;
  undefined8 *puVar7;
  short sVar8;
  char cVar6;
  
  uVar4 = (ulonglong)CONCAT24(CONCAT11(b,a),unaff_XR8);
  sVar8 = dec_ptr_by_idx(CONCAT11(b,c));
  uVar2 = (undefined)((ushort)sVar8 >> 8);
  cVar6 = *(char *)((short)(uVar4 >> 0x20) + 2);
  uVar5 = CONCAT53((int5)(CONCAT26(sVar8,(int6)uVar4) >> 0x18),CONCAT12(cVar6,(short)uVar4));
  if (cVar6 == '\0') {
    eval_result_init(CONCAT11(d,c));
    uVar2 = extraout_R1;
  }
  else {
    bVar1 = nibble_pair();
    uVar3 = CONCAT11(*(undefined *)((short)((ulonglong)uVar5 >> 0x20) + 9),(char)uVar5);
    puVar7 = (undefined8 *)((ulonglong)uVar5 >> 0x30);
    *puVar7 = CONCAT26(unaff_ER6,
                       CONCAT24(unaff_ER4,CONCAT13(d,CONCAT12(c,CONCAT11(uVar2,bVar1))))
                      );
    *(ushort *)(puVar7 + 1) = uVar3;
    uVar4 = CONCAT53((int5)((ulonglong)uVar5 >> 0x18),(uint3)uVar3) & 0xffffffff00ffffff;
    bVar1 = unpack_nibbles();
    sVar8 = (short)(uVar4 >> 0x30);
    *(byte *)(uintptr_t)(ulonglong *)(sVar8 + 10) =
         CONCAT26(unaff_ER6,
                  CONCAT24(unaff_ER4,CONCAT13(d,CONCAT12(c,CONCAT11(uVar2,bVar1)))));
    *(ushort *)(sVar8 + 0x12) = (ushort)uVar4;
    uVar5 = CONCAT53((int5)(uVar4 >> 0x18),(uint3)(ushort)uVar4);
    bVar1 = nibble_pair();
    sVar8 = (short)((ulonglong)uVar5 >> 0x30);
    *(byte *)(uintptr_t)(ulonglong *)(sVar8 + 0x14) =
         CONCAT26(unaff_ER6,
                  CONCAT24(unaff_ER4,CONCAT13(d,CONCAT12(c,CONCAT11(uVar2,bVar1)))));
    *(short *)(sVar8 + 0x1c) = (short)uVar5;
  }
  uVar5 = CONCAT53((int5)((ulonglong)uVar5 >> 0x18),(uint3)(ushort)uVar5);
  bVar1 = nibble_pair();
  uVar3 = CONCAT11(*(undefined *)((short)((ulonglong)uVar5 >> 0x20) + 8),(char)uVar5);
  sVar8 = (short)((ulonglong)uVar5 >> 0x30);
  *(byte *)(uintptr_t)(ulonglong *)(sVar8 + 0x1e) =
       CONCAT26(unaff_ER6,
                CONCAT24(unaff_ER4,CONCAT13(d,CONCAT12(c,CONCAT11(uVar2,bVar1)))));
  *(ushort *)(sVar8 + 0x26) = uVar3;
  uVar4 = CONCAT53((int5)((ulonglong)uVar5 >> 0x18),(uint3)uVar3) & 0xffffffff00ffffff;
  bVar1 = unpack_nibbles();
  sVar8 = (short)(uVar4 >> 0x30);
  *(byte *)(uintptr_t)(ulonglong *)(sVar8 + 0x28) =
       CONCAT26(unaff_ER6,
                CONCAT24(unaff_ER4,CONCAT13(d,CONCAT12(c,CONCAT11(uVar2,bVar1)))));
  *(ushort *)(sVar8 + 0x30) = (ushort)uVar4;
  uVar5 = CONCAT53((int5)(uVar4 >> 0x18),(uint3)(ushort)uVar4);
  bVar1 = nibble_pair();
  sVar8 = (short)((ulonglong)uVar5 >> 0x30);
  *(byte *)(uintptr_t)(ulonglong *)(sVar8 + 0x32) =
       CONCAT26(unaff_ER6,
                CONCAT24(unaff_ER4,CONCAT13(d,CONCAT12(c,CONCAT11(uVar2,bVar1)))));
  *(short *)(sVar8 + 0x3a) = (short)uVar5;
  return;
}

/**
 * @brief 一元运算的分发
 * @addr 0x17F78
 * @module bcd
 * @proto void dec_unary_calc(void)
 * @confidence likely
 * @note 一元运算的分发：按 0x187DA 取单元指针后调用 0x1C18C/0x1C30C 完成计算。
 * @tag bcd
 */
int dec_unary_calc(uintptr_t _a3, uintptr_t _a4, int _a1, int _a2)

{
  bool bVar1;
  undefined2 *puVar2;
  byte extraout_R1;
  undefined uVar3;
  
  uVar3 = (undefined)((ushort)_a1 >> 8);
  dec_param_a = dec_ptr_by_idx(CONCAT11(uVar3,_a2));
  puVar2 = (undefined2 *)dec_ptr_by_idx(CONCAT11((char)((ushort)dec_param_a >> 8),uVar3));
  dec_ptr_by_idx(CONCAT11((char)((ushort)puVar2 >> 8),(char)_a1));
  dec_load(puVar2);
  dec_is_nan();
  bVar1 = dec_is_nan_Y();
  if ((extraout_R1 | bVar1) == 0) {
    if ((dec_regY == '\0') && (dec_flags_Y == '\x01')) {
      if (((char)((ushort)dec_regY >> 8) != '\x01') && (dec_accum0 != 0)) {
        uVar3 = daa((char)(dec_accum0 >> 8) + '\x05');
        dec_accum0 = CONCAT11(uVar3,(char)dec_accum0) & 0xfff;
      }
    }
    else {
      dec_int_convert();
    }
  }
  else {
    dec_zero_helper();
  }
  dec_store();
  dec_status_low();
  return 0;
}

/**
 * @brief 比较偏移值
 * @addr 0x17F82
 * @module bcd
 * @proto void dec_compare_offset(undefined2 a, undefined2 b)
 * @confidence likely
 * @note 比较偏移值：按 0x187DA 解引用三个操作数后调用 0x1C35C/0x1B3BE 比较。
 * @tag bcd
 */
int dec_compare_offset(undefined2 a, undefined2 b)

{
  bool bVar1;
  undefined uVar3;
  undefined2 *puVar2;
  byte extraout_R1;
  
  uVar3 = (undefined)((ushort)a >> 8);
  dec_param_a = dec_ptr_by_idx(CONCAT11(uVar3,b));
  puVar2 = (undefined2 *)dec_ptr_by_idx(CONCAT11((char)((ushort)dec_param_a >> 8),uVar3));
  dec_ptr_by_idx(CONCAT11((char)((ushort)puVar2 >> 8),(char)a));
  dec_load(puVar2);
  dec_is_nan();
  bVar1 = dec_is_nan_Y();
  if ((extraout_R1 | bVar1) == 0) {
    decc_carry_round();
  }
  else {
    dec_zero_helper();
  }
  dec_store();
  dec_status_low();
  return 0;
}

/**
 * @brief 以 0x187DA 解引用两操作数后调用 0x17A1A（十进制运算核心）
 * @addr 0x17F8C
 * @module bcd
 * @proto void dec_bin_op2(undefined2 a, undefined2 b)
 * @confidence likely
 * @note 以 0x187DA 解引用两操作数后调用 0x17A1A（十进制运算核心）。
 * @tag bcd
 */
int dec_bin_op2(undefined2 a, undefined2 b)

{
  bool bVar1;
  undefined uVar3;
  undefined2 *puVar2;
  byte extraout_R1;
  
  uVar3 = (undefined)((ushort)a >> 8);
  dec_param_a = dec_ptr_by_idx(CONCAT11(uVar3,b));
  puVar2 = (undefined2 *)dec_ptr_by_idx(CONCAT11((char)((ushort)dec_param_a >> 8),uVar3));
  dec_ptr_by_idx(CONCAT11((char)((ushort)puVar2 >> 8),(char)a));
  dec_load(puVar2);
  dec_is_nan();
  bVar1 = dec_is_nan_Y();
  if ((extraout_R1 | bVar1) == 0) {
    dec_tail_round();
  }
  else {
    dec_zero_helper();
  }
  dec_store();
  dec_status_low();
  return 0;
}

/**
 * @brief 矩阵扩展复制
 * @addr 0x1801A
 * @module bcd
 * @proto undefined2 matrix_copy_ext(undefined2* a, undefined2* b)
 * @confidence likely
 * @note 矩阵扩展复制：按单元类型复制并转换（大函数，0x1DA02/0x1D94C 链）。
 * @tag matrix
 */
undefined2 matrix_copy_ext(undefined2* a, undefined2* b)

{
  undefined2 *puVar1;
  undefined2 *puVar2;
  undefined2 uVar3;
  byte bVar6;
  undefined uVar7;
  char *pcVar8;
  undefined4 uVar9;
  char *pcVar10;
  ulonglong uVar4;
  ulonglong uVar5;
  short sVar11;
  undefined auStack_42 [20];
  undefined local_2e [42];
  
  uVar9 = CONCAT22(local_2e,auStack_42);
  puVar2 = a;
  puVar1 = dec_copy_ret((undefined2 *)0x1b6c,a);
  if (*(char *)(b + 4) == '\0') {
    dec_copy_ret(b,puVar2 + 5);
    bVar6 = *(byte *)b;
    uVar3 = 0x102;
    if (bVar6 != 4) {
      if (bVar6 == 8) {
        uVar3 = 0x202;
      }
      else {
        uVar3 = (undefined2)CONCAT71((uint7)(ushort)(CONCAT12(bVar6,0x102) >> 8),3);
        if (bVar6 < 8) {
          return;
        }
      }
    }
    *(char *)a = (char)uVar3;
    *(char *)(a + 5) = (char)((ushort)uVar3 >> 8);
  }
  else {
    puVar2 = dec_copy_ret(puVar1 + 5,(undefined2 *)uVar9);
    dec_copy_ret(puVar2,(undefined2 *)((short)((uint)uVar9 >> 0x10) + 0x14));
    dec_copy_ret(b,(undefined2 *)((short)uVar9 + 10));
    uVar4 = CONCAT44(uVar9,0x504001c);
    do {
      while( true ) {
        puVar2 = (undefined2 *)(uVar4 >> 0x30);
        dec_copy_ret((undefined2 *)((short)(uVar4 >> 0x20) + 10),puVar2);
        puVar2 = puVar2 + 5;
        dec_copy_ret((undefined2 *)(uVar4 >> 0x20),puVar2);
        dec_bin_pow_core(puVar2,puVar2);
        dec_abs_wrap();
        pcVar10 = (char *)(uVar4 >> 0x30);
        pcVar8 = (char *)(uVar4 >> 0x20);
        if (*pcVar10 == '\0') break;
        if (pcVar10[10] == '\0') goto LAB_rom_0180f4;
        bVar6 = (char)uVar4 - 1;
        uVar4 = CONCAT71((int7)(uVar4 >> 8),bVar6);
        if (bVar6 == 0) goto LAB_rom_0180f4;
        if ((char)((bVar6 < 0x1a) << 7) < '\0') {
          do {
            uVar5 = uVar4 ^ 0x60000;
            sVar11 = (short)(uVar4 >> 0x30);
            *(char *)(sVar11 + 0x14) = (char)(uVar5 >> 0x10);
            dec_bin_xor_core((short)(uVar4 >> 0x20),(undefined2 *)(sVar11 + 0x14));
            uVar7 = daa((char)(uVar5 >> 0x18) + (char)(uVar5 >> 0x10));
            uVar4 = CONCAT44((int)(uVar5 >> 0x20),CONCAT13(uVar7,(int3)uVar5)) & 0xffffffff0fffffff;
          } while ((char)(uVar4 >> 0x18) == '\x05');
        }
        else {
          *pcVar8 = ('\x1b' - bVar6) * '\x02' + '\x03';
        }
      }
      dec_bin_pow_core(a,pcVar8);
      dec_copy_ret((undefined2 *)((short)(uVar4 >> 0x30) + 10), (uintptr_t)0)
                     (undefined2 *)((short)(uVar4 >> 0x20) + 10));
    } while (*(char *)((short)(uVar4 >> 0x30) + 10) != '\0');
LAB_rom_0180f4:
    dec_copy_ret((undefined2 *)((short)(uVar4 >> 0x20) + 10),a + 5);
  }
  return;
}

/**
 * @brief 返回第 idx 个 BCD 单元的首字节（类型/符号，0x187DA 取指针后的封装）
 * @addr 0x18108
 * @module bcd
 * @proto byte dec_type_byte(ushort idx)
 * @confidence verified
 * @note 返回第 idx 个 BCD 单元的首字节（类型/符号，0x187DA 取指针后的封装）。
 * @tag bcd
 */
byte dec_type_byte(ushort idx)

{
  undefined *puVar1;
  
  puVar1 = (undefined *)dec_ptr_by_idx(idx);
  return *puVar1;
}

/**
 * @brief 把第 idx 个 BCD 单元格式化为字符串（0x187DA 取指针后调用 0x1D620）
 * @addr 0x18112
 * @module bcd
 * @proto char* dec_to_str_idx(ushort idx)
 * @confidence strong
 * @note 把第 idx 个 BCD 单元格式化为字符串（0x187DA 取指针后调用 0x1D620）。
 * @tag bcd
 */
char* dec_to_str_idx(ushort idx)

{
  short sVar1;
  undefined2 *puVar2;
  
  sVar1 = dec_ptr_by_idx(idx);
  puVar2 = (undefined2 *)dec_ptr_by_idx(CONCAT11((char)((ushort)sVar1 >> 8),(char)(idx >> 8)));
  dec_to_string(sVar1,puVar2);
  return;
}

/**
 * @brief 对第 idx 个变量单元调用 0x1D730（加常量 c）
 * @addr 0x18130
 * @module bcd
 * @proto void var_add_const(ushort idx, undefined2 c)
 * @confidence strong
 * @note 对第 idx 个变量单元调用 0x1D730（加常量 c）。
 * @tag vars
 */
int var_add_const(ushort idx, undefined2 c)

{
  undefined2 *puVar1;
  
  puVar1 = (undefined2 *)dec_ptr_by_idx(idx);
  dec_inc5(puVar1,c);
  return 0;
}

/**
 * @brief 把 a、b 分别存到 _D05C 句柄的 +0x1E / +0x1F 槽
 * @addr 0x1813C
 * @module bcd
 * @proto void dec_store_pair(undefined2* a, undefined2* b)
 * @confidence likely
 * @note 把 a、b 分别存到 _D05C 句柄的 +0x1E / +0x1F 槽。
 * @tag bcd
 */
int dec_store_pair(undefined2* a, undefined2* b)

{
  undefined2 *puVar1;
  undefined extraout_R1;
  
  puVar1 = (undefined2 *)dec_ptr_by_idx(CONCAT11((char)((ushort)a >> 8),0x1e));
  dec_copy(puVar1,a);
  puVar1 = (undefined2 *)dec_ptr_by_idx(CONCAT11(extraout_R1,0x1f));
  dec_copy(puVar1,b);
  return 0;
}

/**
 * @brief 二进制整数转 BCD（按 0x1D668 取得串长选择 1/4/0x40 路径）
 * @addr 0x1815C
 * @module bcd
 * @proto int dec_bin_to_bcd(undefined2* a)
 * @confidence likely
 * @note 二进制整数转 BCD（按 0x1D668 取得串长选择 1/4/0x40 路径）。
 * @tag bcd
 */
int dec_bin_to_bcd(undefined2* a, int _a2)

{
  char cVar1;
  byte bVar2;
  ushort uVar3;
  undefined uVar4;
  
  eval_recip(a);
  uVar4 = 1;
  uVar3 = dec_type_of((undefined *)a);
  cVar1 = (char)uVar3;
  if (((cVar1 != -0x80) && (uVar4 = 4, cVar1 != ' ')) && (uVar4 = 0x40, cVar1 == '\0')) {
    bVar2 = dec_cmp_status(a,_a2);
    if ((bVar2 == 0) && (*(byte *)(a + 4) < 8)) {
      uVar4 = 0x10;
    }
  }
  return uVar4;
}

/**
 * @brief 矩阵运算操作数准备（0x187DA 解引用后归一化）
 * @addr 0x18198
 * @module bcd
 * @proto undefined2 matrix_prep_opnd(undefined2 a, undefined2 b)
 * @confidence likely
 * @note 矩阵运算操作数准备（0x187DA 解引用后归一化）。
 * @tag matrix
 */
undefined2 matrix_prep_opnd(undefined2 a, undefined2 b)

{
  undefined uVar3;
  undefined2 *puVar1;
  undefined2 uVar2;
  undefined uVar4;
  byte bVar5;
  undefined8 uVar6;
  ulonglong uVar7;
  
  uVar3 = (undefined)((ushort)a >> 8);
  uVar7 = (ulonglong)CONCAT16(uVar3,(uint6)(byte)a << 8);
  puVar1 = (undefined2 *)dec_ptr_by_idx(CONCAT11(uVar3,0x1e));
  uVar6 = CONCAT44((int)(uVar7 >> 0x20),CONCAT22(puVar1,(short)uVar7));
  uVar2 = dec_bin_to_bcd(puVar1,b);
  uVar6 = CONCAT71((int7)((ulonglong)uVar6 >> 8),(char)uVar2);
  puVar1 = (undefined2 *)dec_ptr_by_idx(CONCAT11((char)((ushort)uVar2 >> 8),0x1f));
  uVar6 = CONCAT26((short)((ulonglong)uVar6 >> 0x30),CONCAT24(puVar1,(int)uVar6));
  uVar2 = dec_bin_to_bcd(puVar1,b);
  uVar3 = (undefined)((ushort)uVar2 >> 8);
  bVar5 = (char)uVar6 + (char)uVar2 * '\x02';
  uVar7 = CONCAT71((int7)((ulonglong)uVar6 >> 8),bVar5);
  if (bVar5 < 0x40) {
    uVar4 = (undefined)((ushort)b >> 8);
    if ((bVar5 & 1) == 0) {
      if (((char)((ulonglong)uVar6 >> 0x30) == '\0') || ((bVar5 & 0x10) == 0)) {
        dec_op_setup((uintptr_t)0, (uintptr_t)0);
      }
    }
    else {
      dec_core_17e8e((char)((ulonglong)uVar6 >> 0x10),(char)((ulonglong)uVar6 >> 0x18), (uintptr_t)0, (uintptr_t)0)
                     (char)((ulonglong)uVar6 >> 8),uVar4);
    }
    if ((uVar7 & 2) == 0) {
      uVar3 = 0;
      dec_op_setup((uintptr_t)0, (uintptr_t)0);
    }
    else {
      uVar3 = 0;
      dec_core_17e8e((char)(uVar7 >> 0x20),(char)(uVar7 >> 0x28),(char)(uVar7 >> 8) + '\x06',uVar4);
    }
  }
  return CONCAT11(uVar3,(char)uVar7);
}

