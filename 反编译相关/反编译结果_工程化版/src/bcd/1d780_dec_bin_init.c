/*
 * BCD 浮点库 / 1d780_dec_bin_init.c
 * 地址范围: 0x1D780 - 0x1DE40
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 二元运算初始化
 * @addr 0x1D780
 * @module bcd
 * @proto void dec_bin_init(undefined2* a, undefined2* b)
 * @confidence verified
 * @note 二元运算初始化：载入 X←*a、保存 *b 到 0xD05C；若 X 带 0x40 内部标志则先清掉并写回。
 * @tag bcd
 */
int dec_bin_init(undefined2* a, undefined2* b)

{
  ushort uVar1;
  
  dec_param_a = a;
  dec_param_b = b;
  dec_load_regs(a);
  uVar1 = CONCAT11(dec_flags,dec_flags) & 0xf0ff;
  if ((char)(uVar1 >> 8) == '@') {
    dec_flags = (byte)uVar1 & 0xbf;
    dec_store();
  }
  dec_status_low();
  return 0;
}

/**
 * @brief 比较并返回/归一化两个 BCD 单元
 * @addr 0x1D7B0
 * @module bcd
 * @proto undefined2* dec_cmp_ex(undefined2* a, undefined2 b)
 * @confidence strong
 * @note 比较并返回/归一化两个 BCD 单元。
 * @tag bcd
 */
undefined2* dec_cmp_ex(undefined2* a, undefined2 b)

{
  ushort uVar1;
  
  dec_param_a = a;
  dec_param_b = b;
  dec_load_regs(a);
  if ((dec_flags & 0xf0) == 0) {
    dec_prepare_compare();
  }
  else {
    if ((dec_flags & 0xf0) != 0x40) goto LAB_rom_01d7f6;
    dec_flags = dec_flags & 0xf;
    dec_prepare_compare();
    uVar1 = dec_load_union();
    if ((char)uVar1 == '\x02') {
      dec_flags = dec_flags | 0x40;
    }
  }
  dec_store();
LAB_rom_01d7f6:
  dec_status_low();
  return;
}

/**
 * @brief 返回 BCD 单元的高 4 位（0 为浮点，F 为特殊值）
 * @addr 0x1D800
 * @module bcd
 * @proto byte bcd_type(void)
 * @confidence verified
 * @note 返回 BCD 单元的高 4 位（0 为浮点，F 为特殊值）。
 * @tag bcd
 */
byte bcd_type(uintptr_t _a2, int _a1)

{
  byte bVar1;
  
  if ((char)((*_a1 < 0xf0) << 7) < '\0') {
    bVar1 = 0;
  }
  else {
    bVar1 = *_a1 & 0xf;
  }
  return bVar1;
}

/**
 * @brief BCD 转二进制整数（1.5KB，0x1C364 载入后循环折算）
 * @addr 0x1D80E
 * @module bcd
 * @proto int dec_bcd_to_bin(undefined2* a, undefined2* b)
 * @confidence likely
 * @note BCD 转二进制整数（1.5KB，0x1C364 载入后循环折算）。
 * @tag bcd
 */
int dec_bcd_to_bin(undefined2* a, undefined2* b)

{
  undefined uVar1;
  undefined2 uVar2;
  undefined uVar4;
  ushort uVar3;
  byte bVar5;
  
  dec_param_a = a;
  dec_param_b = b;
  dec_load_regs(a);
  uVar3 = dec_accum0;
  if (dec_flags == 0) goto LAB_rom_01d87a;
  if (dec_flags < 10) {
    if ((b & 0x8000) != 0) {
      uVar2 = bcd_mul22(-(byte)b, (uintptr_t)0);
      uVar1 = das((byte)dec_accum0 - (byte)uVar2);
      uVar4 = das(((char)(dec_accum0 >> 8) - (char)((ushort)uVar2 >> 8)) -
                  ((byte)dec_accum0 < (byte)uVar2));
      uVar3 = CONCAT11(uVar4,uVar1) & 0xfff;
      bVar5 = (byte)(uVar3 >> 8);
      if (((1 < bVar5) && (bVar5 != 5)) && (bVar5 != 6)) {
        dec_accum1 = 0;
        dec_accum0 = 0;
        dec_accum3 = 0;
        dec_accum2 = 0;
        dec_accum4 = 0;
        uVar3 = dec_accum0;
      }
      goto LAB_rom_01d87a;
    }
    uVar2 = bcd_mul22((byte)b, (uintptr_t)0);
    uVar1 = daa((byte)uVar2 + (byte)dec_accum0);
    uVar4 = daa((char)((ushort)uVar2 >> 8) + (char)(dec_accum0 >> 8) +
                CARRY1((byte)uVar2,(byte)dec_accum0));
    uVar3 = CONCAT11(uVar4,uVar1) & 0xfff;
    bVar5 = (byte)(uVar3 >> 8);
    if (((bVar5 < 2) || (bVar5 == 5)) || (bVar5 == 6)) goto LAB_rom_01d87a;
  }
  dec_zero_helper();
  uVar3 = dec_accum0;
LAB_rom_01d87a:
  dec_accum0 = uVar3;
  dec_store();
  dec_status_low();
  return 0;
}

/**
 * @brief 一元入口（sin 路径，调用 0x1C364 载入后进入 0x1D280）
 * @addr 0x1D89E
 * @module bcd
 * @proto int dec_unary_sin(void)
 * @confidence likely
 * @note 一元入口（sin 路径，调用 0x1C364 载入后进入 0x1D280）。
 * @tag bcd
 */
int dec_unary_sin(uintptr_t _a3, uintptr_t _a4, int _a1, int _a2)

{
  char cVar1;
  byte bVar3;
  ushort uVar2;
  
  dec_param_a = _a1;
  dec_param_b = _a2;
  dec_load_regs(_a1);
  if (dec_flags < 10) {
    cVar1 = (char)((ushort)dec_accum0 >> 8);
    if ((cVar1 == '\x01') || (cVar1 == '\x06')) {
      bVar3 = bcd_div22((byte)dec_accum0,0);
      uVar2 = (ushort)bVar3;
    }
    else {
      bVar3 = das(-(byte)dec_accum0);
      cVar1 = bcd_div22(bVar3,0);
      uVar2 = CONCAT11(-(cVar1 != '\0'),-cVar1);
    }
  }
  else {
    uVar2 = 0x5000;
  }
  return uVar2;
}

/**
 * @brief 一元入口（cos 路径）
 * @addr 0x1D900
 * @module bcd
 * @proto int dec_unary_cos(void)
 * @confidence likely
 * @note 一元入口（cos 路径）。
 * @tag bcd
 */
int dec_unary_cos(uintptr_t _a3, uintptr_t _a4, int _a1, int _a2)

{
  bool bVar1;
  undefined2 *puVar2;
  char cVar3;
  
  cVar3 = '\0';
  dec_param_a = _a1;
  dec_param_b = _a2;
  puVar2 = (undefined2 *)dec_load_callee();
  dec_opcode = cVar3;
  dec_load_regs(puVar2);
  bVar1 = dec_check_nan_X();
  if (bVar1) {
    dec_zero_helper();
  }
  else {
    decc_int_entry();
    if (dec_opcode == '\0') {
      dec_abs_core();
    }
    else {
      dec_unary_abs();
    }
  }
  dec_store();
  dec_status_low();
  return 0;
}

/**
 * @brief 按格式参数把数值装载为 BCD 单元
 * @addr 0x1D94C
 * @module bcd
 * @proto undefined2 dec_set_from_fmt(undefined2 a, undefined2 b)
 * @confidence likely
 * @note 按格式参数把数值装载为 BCD 单元。
 * @tag bcd
 */
undefined2 dec_set_from_fmt(undefined2 a, undefined2 b)

{
  undefined uVar1;
  
  dec_param_a = a;
  dec_param_b = b;
  if ((byte)b == 0) {
    dec_accum0 = 0;
    dec_accum4 = 0;
  }
  else {
    dec_accum4 = bcd_mul22((byte)b, (uintptr_t)0);
    if ((char)(dec_accum4 >> 8) == '\0') {
      if ((char)(((byte)dec_accum4 < 0x10) << 7) < '\0') {
        dec_accum4 = dec_accum4 << 8;
        uVar1 = 0;
      }
      else {
        dec_accum4 =
             CONCAT11((char)((dec_accum4 & 0xff) * 0x10 >> 8),(byte)dec_accum4 << 4);
        uVar1 = 1;
      }
    }
    else {
      uVar1 = 2;
    }
    dec_accum0 = CONCAT11(1,uVar1);
  }
  dec_accum3 = 0;
  dec_accum2 = 0;
  dec_accum1 = 0;
  dec_store();
  return;
}

/**
 * @brief 二进制到 BCD 上下文转换（0x1C364 后按标志选择路径）
 * @addr 0x1D9A8
 * @module bcd
 * @proto int dec_bin_to_bcd_ctx(void)
 * @confidence likely
 * @note 二进制到 BCD 上下文转换（0x1C364 后按标志选择路径）。
 * @tag bcd
 */
int dec_bin_to_bcd_ctx(void)

{
  byte bVar1;
  undefined8 in_QR0;
  byte bVar3;
  ushort uVar2;
  
  dec_param_b = (undefined2)((ulonglong)in_QR0 >> 0x10);
  dec_param_a = (undefined2 *)in_QR0;
  dec_load_regs(dec_param_a);
  bVar3 = (byte)(dec_accum4 >> 8);
  if (((bVar3 < 10) && ((char)((ulonglong)dec_accum0 >> 8) == '\x01')) &&
     (bVar1 = (byte)dec_accum0, bVar1 < 3)) {
    if (bVar1 == 1) {
      uVar2 = CONCAT11(bVar3 >> 4,(char)((ushort)bVar3 * 0x100 + (dec_accum4 & 0xff) >> 4));
    }
    else {
      uVar2 = dec_accum4;
      if (bVar1 == 0) {
        uVar2 = (ushort)bVar3;
      }
    }
    bcd_div22((byte)uVar2,(byte)(uVar2 >> 8));
  }
  return 0;
}

/**
 * @brief 倒序复制 10 字节 BCD 单元（dst 与 src 重叠时安全）
 * @addr 0x1D9EC
 * @module bcd
 * @proto void dec_copy_rev(undefined2* dst, undefined2* src)
 * @confidence verified
 * @note 倒序复制 10 字节 BCD 单元（dst 与 src 重叠时安全）。
 * @tag bcd
 */
int dec_copy_rev(undefined2* dst, undefined2* src)

{
  undefined8 uVar1;
  
  uVar1 = *(undefined8 *)(src + 6);
  dst[5] = src[5];
  *(undefined8 *)(dst + 6) = uVar1;
  uVar1 = *(undefined8 *)(src + 1);
  *dst = *src;
  *(undefined8 *)(dst + 1) = uVar1;
  return 0;
}

/**
 * @brief 复制 10 字节 BCD 浮点寄存器（dst ← src）
 * @addr 0x1DA02
 * @module bcd
 * @proto void dec_copy(undefined2* dst, undefined2* src)
 * @confidence verified
 * @note 复制 10 字节 BCD 浮点寄存器（dst ← src）。
 * @tag bcd
 */
int dec_copy(undefined2* dst, undefined2* src)

{
  undefined8 uVar1;
  
  uVar1 = *(undefined8 *)(src + 1);
  *dst = *src;
  *(undefined8 *)(dst + 1) = uVar1;
  return 0;
}

/**
 * @brief 把 0xD05C/0xD05E 送入 0x1974A（特殊值构造）后收尾
 * @addr 0x1DA2E
 * @module bcd
 * @proto void dec_to_special(undefined2* a, undefined2* b)
 * @confidence likely
 * @note 把 0xD05C/0xD05E 送入 0x1974A（特殊值构造）后收尾。
 * @tag bcd
 */
int dec_to_special(undefined2* a, undefined2* b)

{
  dec_param_a = a;
  dec_param_b = b;
  dec_const_pi();
  dec_store();
  return 0;
}

/**
 * @brief 整数到 BCD 的转换
 * @addr 0x1DA48
 * @module bcd
 * @proto int dec_from_integer(undefined2* a, undefined2* b)
 * @confidence likely
 * @note 整数到 BCD 的转换：0x1C364 载入后调用 0x19C8C/0x19EB2。
 * @tag bcd
 */
int dec_from_integer(undefined2* a, undefined2* b)

{
  dec_param_a = a;
  dec_param_b = b;
  dec_load_regs(a);
  dec_g_X_to_Z();
  dec_y_exponent();
  return 0;
}

/**
 * @brief p[0] 低半字节 < 10 且 p[9] 高半字节为 0 时返回 0（简单整数），否则返回…
 * @addr 0x1DA62
 * @module bcd
 * @proto byte is_simple_bcd(byte* p)
 * @confidence verified
 * @note p[0] 低半字节 < 10 且 p[9] 高半字节为 0 时返回 0（简单整数），否则返回 1。
 * @tag bcd
 */
byte is_simple_bcd(byte* p)

{
  byte bVar1;
  
  bVar1 = (byte)((ushort)p >> 8);
  if (((*p & 0xf) < 10) && ((p[9] & 0xf0) == 0)) {
    return (ushort)bVar1 << 8;
  }
  return CONCAT11(bVar1,1);
}

/**
 * @brief 带符号数值比较
 * @addr 0x1DA7A
 * @module bcd
 * @proto undefined2 dec_cmp_signed(undefined2 a, undefined2 b)
 * @confidence likely
 * @note 带符号数值比较。
 * @tag bcd
 */
undefined2 dec_cmp_signed(undefined2 a, undefined2 b)

{
  byte *pbVar1;
  byte bVar2;
  
  pbVar1 = (byte *)dec_normalize2(a,b);
  bVar2 = *pbVar1;
  if (bVar2 < 0x50) {
    *pbVar1 = bVar2 & 0xbf;
    dec_entry_x(pbVar1,CONCAT11((char)((ushort)b >> 8),bVar2) & 0xffbf);
  }
  return a;
}

/**
 * @brief 矩阵查看/编辑界面（初始化 0xD6B2 工作区与若干暂存指针，调用 clear_work_…
 * @addr 0x1DBC6
 * @module bcd
 * @proto int apps_matrix_view(void)
 * @confidence likely
 * @note 矩阵查看/编辑界面（初始化 0xD6B2 工作区与若干暂存指针，调用 clear_work_area）。
 * @tag matrix
 */
int apps_matrix_view(uintptr_t _a2, int _a1)

{
  char cVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  undefined2 *puVar4;
  undefined2 uVar5;
  undefined uVar6;
  short unaff_ER14;
  
  cVar1 = frame_enter();
  *(undefined *)(unaff_ER14 + -0xd) = 1;
  *(undefined *)(unaff_ER14 + -0x11) = 0;
  *(undefined *)(unaff_ER14 + -0x15) = 0;
  *(undefined **)(unaff_ER14 + -0x10) = &app_work_area;
  *(undefined2 *)(unaff_ER14 + -0x14) = 0xd6bc;
  *(undefined2 *)(unaff_ER14 + -8) = 0xd6c6;
  *(undefined2 *)(unaff_ER14 + -0xc) = 0xd6da;
  *(undefined2 *)(unaff_ER14 + -10) = 0xd6e4;
  *(undefined2 *)(unaff_ER14 + -2) = 0xd824;
  uVar5 = 0xd84c;
  *(undefined2 *)(unaff_ER14 + -4) = 0xd856;
  *(undefined2 *)(unaff_ER14 + -6) = 0xd874;
  uVar2 = dec_cmp((undefined2 *)0xd6da,_a1);
  if ((char)uVar2 != '\x04') {
    uVar3 = dec_cmp(*(undefined2 **)(unaff_ER14 + -10),_a1);
    puVar4 = *(undefined2 **)(unaff_ER14 + -0xc);
    dec_copy((undefined2 *)0xd842,puVar4);
    dec_inc5((undefined2 *)0xd842,puVar4);
    dec_round((undefined2 *)0xd842,puVar4);
    dec_cmp_ex((undefined2 *)0xd842,puVar4);
    dec_set_uint_small((ushort *)0xd84c,2);
    uVar2 = uVar5;
    dec_bin_pow((undefined2 *)0xd842,(undefined2 *)0xd84c);
    if ((char)uVar3 != '\x02') {
      dec_inc5((undefined2 *)0xd842,uVar2);
    }
    dec_copy(*(undefined2 **)(unaff_ER14 + -4),*(undefined2 **)(unaff_ER14 + -2));
    dec_add_or_round(*(undefined2 **)(unaff_ER14 + -4),(undefined2 *)0xd84c);
    dec_bin_mul((undefined2 *)0xd842,*(undefined2 **)(unaff_ER14 + -4));
    dec_set_uint_small((ushort *)0xd84c,3);
    dec_add_or_round((undefined2 *)0xd842,(undefined2 *)0xd84c);
    dec_copy((undefined2 *)0xd860,(undefined2 *)0xd842);
    dec_copy((undefined2 *)0xd86a,*(undefined2 **)(unaff_ER14 + -2));
    dec_set_uint_small((ushort *)0xd84c,2);
    dec_bin_pow((undefined2 *)0xd860,(undefined2 *)0xd84c);
    dec_bin_mul((undefined2 *)0xd86a,(undefined2 *)0xd860);
    puVar4 = *(undefined2 **)(unaff_ER14 + -2);
    dec_bin_div((undefined2 *)0xd860,puVar4);
    uVar2 = dec_cmp((undefined2 *)0xd860,puVar4);
    if ((char)uVar2 != '\x02') {
      dec_round((undefined2 *)0xd860,puVar4);
      dec_cmp_ex((undefined2 *)0xd860,puVar4);
      dec_set_uint_small((ushort *)0xd84c,4);
      dec_add_or_round((undefined2 *)0xd86a,(undefined2 *)0xd84c);
      dec_cmp_ex((undefined2 *)0xd86a,uVar5);
      uVar2 = dec_cmp((undefined2 *)0xd86a,uVar5);
      if ((char)uVar2 == '\x02') {
        *(undefined *)(unaff_ER14 + -0xd) = 0;
      }
      if (cVar1 == *(char *)(unaff_ER14 + -0xd)) {
        dec_inc5((undefined2 *)0xd86a,uVar5);
        *(undefined *)(unaff_ER14 + -0x11) = 1;
      }
      uVar6 = (undefined)((ushort)uVar5 >> 8);
      clear_work_area();
      uVar2 = CONCAT11(uVar6,1);
      dec_set_uint_small(*(ushort **)(unaff_ER14 + -0x10),1);
      if (*(char *)(unaff_ER14 + -0x11) == '\0') {
        dec_inc5((undefined2 *)0xd860,uVar2);
        dec_inc5((undefined2 *)0xd86a,uVar2);
      }
      dec_copy(*(undefined2 **)(unaff_ER14 + -6),(undefined2 *)0xd860);
      dec_copy(*(undefined2 **)(unaff_ER14 + -0x14),*(undefined2 **)(unaff_ER14 + -6));
      dec_set_uint_small((ushort *)0xd84c,2);
      dec_add_or_round(*(undefined2 **)(unaff_ER14 + -6),(undefined2 *)0xd84c);
      dec_copy(*(undefined2 **)(unaff_ER14 + -8),(undefined2 *)0xd842);
      dec_bin_div(*(undefined2 **)(unaff_ER14 + -8),(undefined2 *)0xd86a);
      *(undefined *)(unaff_ER14 + -0x15) = 1;
    }
  }
  frame_leave();
  return 0;
}

/**
 * @brief 统计表导航键（0xD013/D014 行游标）处理
 * @addr 0x1DD68
 * @module bcd
 * @proto void table_nav_key(void)
 * @confidence likely
 * @note 统计表导航键（0xD013/D014 行游标）处理。
 * @tag app
 */
int table_nav_key(int _a1)

{
  char cVar1;
  undefined uVar2;
  int bVar3;
  byte *pbVar4;
  ushort uVar5;
  int sVar6;
  short unaff_ER14;
  
  pbVar4 = (byte *)frame_enter();
  cVar1 = is_d015_1_3();
  uVar5 = history_recall((char)pbVar4);
  _DAT_ram_d013 = _DAT_ram_d013 + '\x02';
  if (cVar1 == '\0') {
    var_slot_write(*(undefined2 *)(unaff_ER14 + 0x10));
  }
  irq_pending_shadow = (byte)uVar5 + 1;
  uVar2 = line_col_count();
  *(undefined *)(unaff_ER14 + -4) = uVar2;
  *(undefined *)(unaff_ER14 + -3) = 0;
  if (*pbVar4 != 0x60) {
    token_at(pbVar4);
    bVar3 = finish_edit_line(*(ushort *)(unaff_ER14 + 0x10));
    *(byte *)(unaff_ER14 + -3) = bVar3;
    *(ushort *)(unaff_ER14 + 0x10) = *(short *)(unaff_ER14 + 0x10) + (ushort)bVar3;
  }
  char_ptr_next(pbVar4);
  sVar6 = row_buffer_init(_a1);
  if (sVar6 != 0) {
    editor_action((ushort)*(byte *)(unaff_ER14 + 0x12));
    *_a1 = *_a1 + (ushort)*(byte *)(unaff_ER14 + -4) + (ushort)*(byte *)(unaff_ER14 + -3);
    if (cVar1 == '\0') {
      var_scalar_addr((byte)uVar5);
    }
  }
  frame_leave();
  return 0;
}

/**
 * @brief 统计/表格绘制（4.7KB，按 0x50BE/D137/D139）
 * @addr 0x1DE40
 * @module bcd
 * @proto void stat_draw(void)
 * @confidence likely
 * @note 统计/表格绘制（4.7KB，按 0x50BE/D137/D139）。
 * @tag app
 */
int stat_draw(void)

{
  int bVar1;
  ushort uVar2;
  short sVar3;
  byte bVar4;
  byte bVar5;
  char cVar6;
  byte bVar7;
  short sVar8;
  short sVar9;
  byte bVar10;
  short sVar11;
  short unaff_ER14;
  
  uVar2 = frame_enter();
  *(undefined2 *)(unaff_ER14 + -100) = 0;
  *(undefined2 *)(unaff_ER14 + -0x68) = 0;
  fill_screen(0x400);
  cur_line = 10;
  draw_target = 0;
  sVar11 = 0;
  if ((char)uVar2 != '\0') {
    for (sVar8 = 0; (byte)(SBORROW2(sVar8,uVar2 & 0xff) ^ (short)(sVar8 - (uVar2 & 0xff)) < 0) == 1;
        sVar8 = sVar8 + 1) {
      sVar11 = sVar11 + (ushort)*(byte *)(sVar8 + 0x5a3e);
    }
  }
  bVar10 = (byte)(uVar2 >> 8);
  sVar8 = mul16((ushort)bVar10,0xc);
  sVar9 = 0;
  *(short *)(unaff_ER14 + -0x6a) = sVar11 + sVar8;
  *(short *)(unaff_ER14 + -0x6c) = sVar11 + sVar8;
  do {
    sVar11 = 0;
    do {
      *(undefined *)(sVar11 + unaff_ER14 + -0x62) = 0;
      sVar11 = sVar11 + 1;
      bVar5 = (byte)((ushort)sVar11 >> 8);
      bVar1 = bVar5 - ((byte)sVar11 < 0x40);
    } while ((byte)((byte)((bVar1 ^ bVar5) & ~bVar1) >> 7 ^ (char)bVar1 < '\0') == 1);
    *(undefined *)(unaff_ER14 + -0x62) = *(undefined *)(sVar9 * 2 + 0x6474);
    *(undefined *)(unaff_ER14 + -0x61) = _DAT_ram_50be;
    sVar8 = sVar9 * 2 + *(short *)(unaff_ER14 + -0x6a);
    *(short *)(unaff_ER14 + -0x66) = sVar9 * 2;
    sVar11 = *(short *)(sVar8 * 2 + 0x37cc) + -1;
    bVar1 = (byte)sVar11;
    bVar5 = (byte)((ushort)sVar11 >> 8);
    if ((-1 < sVar11) &&
       (bVar4 = bVar5 - (bVar1 < 0xee),
       (bool)((byte)((bVar4 ^ bVar5) & ~bVar4) >> 7) != (char)bVar4 < '\0')) {
      *(ushort *)(unaff_ER14 + -100) = CONCAT11((bVar5 - 2) + (0xfe < bVar1),bVar1 + 1);
    }
    bVar4 = bVar5 - (bVar1 < 0xee);
    if (((byte)((byte)((bVar4 ^ bVar5) & ~bVar4) >> 7 ^ (char)bVar4 < '\0') != 1) &&
       (bVar4 = (bVar5 - 1) - (bVar1 < 0x2e),
       (bool)((byte)((bVar4 ^ bVar5) & ~bVar4) >> 7) != (char)bVar4 < '\0')) {
      *(ushort *)(unaff_ER14 + -100) = CONCAT11((bVar5 - 7) + (0xec < bVar1),bVar1 + 0x13);
    }
    bVar5 = (byte)unaff_ER14;
    cVar6 = (char)((ushort)unaff_ER14 >> 8);
    bVar1 = text_clear_panel(*(ushort *)(unaff_ER14 + -100), (uintptr_t)0)
                           (byte *)CONCAT11(cVar6 + -1 + (0x5f < bVar5),bVar5 + 0xa0));
    if (sVar9 == 0) {
      *(short *)(unaff_ER14 + -0x68) = sVar8;
    }
    sVar8 = 0;
    sVar11 = 0;
    do {
      if ((0xef < *(byte *)(sVar11 + unaff_ER14 + -0x62)) &&
         (*(char *)(sVar11 + unaff_ER14 + -0x62) != -1)) {
        sVar8 = sVar8 + 1;
      }
      sVar11 = sVar11 + 1;
      bVar7 = (byte)((ushort)sVar11 >> 8);
      bVar4 = bVar7 - ((byte)sVar11 < 0x40);
    } while ((byte)((byte)((bVar4 ^ bVar7) & ~bVar4) >> 7 ^ (char)bVar4 < '\0') == 1);
    for (sVar11 = (ushort)bVar1 + sVar8 + 2; sVar3 = sVar8 + 0x10,
        (byte)(SBORROW2(sVar11,sVar3) ^ sVar11 - sVar3 < 0) == 1; sVar11 = sVar11 + 1) {
      *(undefined *)(sVar11 + unaff_ER14 + -0x62) = 0x20;
    }
    *(undefined *)(sVar3 + unaff_ER14 + -0x62) =
         *(undefined *)(*(short *)(unaff_ER14 + -0x66) + 0x6475);
    *(undefined *)(sVar3 + unaff_ER14 + -0x61) = _DAT_ram_50be;
    sVar11 = *(short *)((*(short *)(unaff_ER14 + -0x66) + 1 + *(short *)(unaff_ER14 + -0x6c)) * 2 +
                       0x37cc) + -1;
    bVar1 = (byte)sVar11;
    bVar4 = (byte)((ushort)sVar11 >> 8);
    if ((-1 < sVar11) &&
       (bVar7 = bVar4 - (bVar1 < 0xee),
       (bool)((byte)((bVar7 ^ bVar4) & ~bVar7) >> 7) != (char)bVar7 < '\0')) {
      *(ushort *)(unaff_ER14 + -100) = CONCAT11((bVar4 - 2) + (0xfe < bVar1),bVar1 + 1);
    }
    bVar7 = bVar4 - (bVar1 < 0xee);
    if (((byte)((byte)((bVar7 ^ bVar4) & ~bVar7) >> 7 ^ (char)bVar7 < '\0') != 1) &&
       (bVar7 = (bVar4 - 1) - (bVar1 < 0x2e),
       (bool)((byte)((bVar7 ^ bVar4) & ~bVar7) >> 7) != (char)bVar7 < '\0')) {
      *(ushort *)(unaff_ER14 + -100) = CONCAT11((bVar4 - 7) + (0xec < bVar1),bVar1 + 0x13);
    }
    text_clear_panel(*(ushort *)(unaff_ER14 + -100), (uintptr_t)0)
                   (byte *)(sVar8 + 0x12 + CONCAT11(cVar6 + -1 + (0x61 < bVar5),bVar5 + 0x9e)));
    draw_text4x((ushort)(byte)((char)sVar9 * '\n' + 1) << 8)
                   CONCAT11(cVar6 + -1 + (0x61 < bVar5),bVar5 + 0x9e));
    sVar9 = sVar9 + 1;
    sVar11 = mul16((ushort)bVar10,0xc);
  } while ((sVar9 * 2 + sVar11 < (short)(ushort)*(byte *)((uVar2 & 0xff) + 0x5a3e)) &&
          (bVar5 = (byte)((ushort)sVar9 >> 8), bVar1 = bVar5 - ((byte)sVar9 < 6),
          (bool)((byte)((bVar1 ^ bVar5) & ~bVar1) >> 7) != (char)bVar1 < '\0'));
  fb_alt_flush();
  draw_target = 1;
  uVar2 = draw_spaced(*(byte *)((uVar2 & 0xff) + 0x5a3e) - 1,2);
  draw_spaced(uVar2,6);
  draw_cursor_box();
  frame_leave();
  return 0;
}

