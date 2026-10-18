/*
 * 自检与诊断 / 22040_diagnostic_mode.c
 * 地址范围: 0x22040 - 0x22502
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 自检/诊断入口（《异常教程》示例 1 的自检函数）
 * @addr 0x22040
 * @module diag
 * @proto ushort diagnostic_mode(ushort a)
 * @confidence verified
 * @note 自检/诊断入口（《异常教程》示例 1 的自检函数）：清屏、绘制 DIAG 标题、等待按键。
 * @tag diag
 */
ushort diagnostic_mode(ushort a)

{
  int cVar1;
  byte extraout_R2;
  
  fill_screen(0x100);
  line_print_font14_col0(1,0x4de9);
  line_print_font14_col0(0x31,0x4dce);
  fb_flush();
  cVar1 = editor_run();
  if (cVar1 != '\0') {
    if (cVar1 == '\x02') {
      diag_8_keytest();
    }
    else {
      diagnostic(extraout_R2);
    }
  }
  return a;
}

/**
 * @brief 调用 0x916A(1)（1ms 延时），返回 v
 * @addr 0x2207E
 * @module diag
 * @proto undefined2 delay_1(undefined2 v)
 * @confidence verified
 * @note 调用 0x916A(1)（1ms 延时），返回 v。
 * @tag hal
 */
undefined2 delay_1(undefined2 v)

{
  editor_action(1);
  return v;
}

/**
 * @brief 调用 0x916A(10)（10ms 延时），返回 v
 * @addr 0x2208E
 * @module diag
 * @proto undefined2 delay_10(undefined2 v)
 * @confidence verified
 * @note 调用 0x916A(10)（10ms 延时），返回 v。
 * @tag hal
 */
undefined2 delay_10(undefined2 v)

{
  editor_action(10);
  return v;
}

/**
 * @brief 诊断测试项
 * @addr 0x2209E
 * @module diag
 * @proto void diagnostic(byte b)
 * @confidence strong
 * @note 诊断测试项：检查 RAM、执行按键测试，绘制/刷新自检画面。
 * @tag diag
 */
int diagnostic(byte b)

{
  undefined2 uVar1;
  undefined uVar2;
  int cVar3;
  
  memcpy_sym(diag_status, 0, sizeof diag_status);
  _DAT_ram_dbd2 = 0;
  diag_mode = 1;
  draw_splash_32();
  fill_screen_mode(0xff);
  fill_screen_mode(0);
  diag_fill_55aa();
  diag_scr_ckb2_ws(b);
  cVar3 = diag_scr_version();
  if (cVar3 == '\x01') {
    diag_checksum();
    draw_mode_header();
  }
  key_28_handler();
  diag_check_key();
  mode_paint();
  line_print_font14_col0(1,0x4dd7);
  line_print_font14_col0(0x21,0x4ddf);
  line_print_font14_col0(0x31,0x4dce);
  fb_flush();
  loop_read_key();
  uVar2 = contrast;
  uVar1 = last_key;
  ram_clear_all();
  last_key = uVar1;
  contrast = uVar2;
  contrast_set(uVar2);
  ui_state_init();
  return 0;
}

/**
 * @brief RAM 测试（BCD 累加/校验）并绘制进度
 * @addr 0x22140
 * @module diag
 * @proto void diag_check_key(void)
 * @confidence strong
 * @note RAM 测试（BCD 累加/校验）并绘制进度。
 * @tag diag
 */
int diag_check_key(void)

{
  undefined8 uVar1;
  byte bVar2;
  byte bVar3;
  char cVar4;
  undefined6 uVar5;
  undefined8 uVar6;
  ulonglong uVar7;
  undefined2 *puVar10;
  undefined local_1a [22];
  ulonglong uVar8;
  undefined uVar9;
  
  uVar7 = ZEXT28(local_1a) << 0x30;
  clear_screen();
  uVar8 = uVar7 & 0xffffffffffff0000;
  *(undefined2 *)((short)(uVar7 >> 0x30) + 2) = 0;
  do {
    bVar3 = (byte)uVar8;
    uVar1 = CONCAT26((short)(uVar8 >> 0x30),CONCAT24(1,(int)uVar8));
    do {
      uVar6 = uVar1;
      cVar4 = bVar3 << 7;
      bVar3 = bVar3 >> 1;
      if (cVar4 < '\0') {
        uVar9 = daa((char)((ulonglong)uVar6 >> 0x28) + (char)((ulonglong)uVar6 >> 0x20));
        uVar6 = CONCAT26((short)((ulonglong)uVar6 >> 0x30),CONCAT15(uVar9,(int5)uVar6));
      }
      uVar9 = daa((char)((ulonglong)uVar6 >> 0x20) * '\x02');
      uVar1 = CONCAT35((int3)((ulonglong)uVar6 >> 0x28),CONCAT14(uVar9,(int)uVar6));
    } while (bVar3 != 0);
    bVar3 = (byte)((ulonglong)uVar6 >> 0x28);
    uVar7 = CONCAT26((short)((ulonglong)uVar6 >> 0x30),
                     CONCAT15(bVar3,CONCAT14(bVar3 >> 4,(int)uVar6))) & 0xffff0fffffffffff;
    puVar10 = (undefined2 *)(uVar7 >> 0x30);
    uVar5 = CONCAT15((char)(uVar7 >> 0x28) + '0',CONCAT14((char)(uVar7 >> 0x20) + '0',(int)uVar7));
    uVar8 = CONCAT26(puVar10,uVar5);
    *puVar10 = (short)((uint6)uVar5 >> 0x20);
    line_print_font14_col0(1,puVar10);
    fb_flush();
    loop_read_key();
    bVar3 = bit_reverse_index(*(byte *)(uVar8 >> 0x30));
    bVar3 = bVar3 << 4;
    bVar2 = bit_reverse_index(*(byte *)((short)(uVar8 >> 0x30) + 1));
  } while ((*(byte *)((short)uVar8 + 0x4d9c) != (bVar3 | bVar2)) ||
          (cVar4 = (char)uVar8 + '\x01', uVar8 = CONCAT71((int7)(uVar8 >> 8),cVar4), cVar4 != '1'));
  return 0;
}

/**
 * @brief 诊断填充
 * @addr 0x221CA
 * @module diag
 * @proto void diag_fill_55aa(void)
 * @confidence strong
 * @note 诊断填充：F800 显存填充 0x55/0xAA 交替。
 * @tag diag
 */
int diag_fill_55aa(void)

{
  byte bVar1;
  undefined *puVar2;
  char cVar3;
  
  bVar1 = 0x55;
  contrast_set(contrast + '\x04');
  puVar2 = &lcd_vram;
  cVar3 = ' ';
  do {
    memset(puVar2,bVar1,0x20);
    memset(puVar2 + 0x20,bVar1 ^ 0xff,0x20);
    puVar2 = puVar2 + 0x40;
    cVar3 = cVar3 + -1;
  } while (cVar3 != '\0');
  wait_any_key();
  contrast_set(contrast);
  return 0;
}

/**
 * @brief 诊断填充
 * @addr 0x221CC
 * @module diag
 * @proto void diag_fill_pattern(byte b)
 * @confidence strong
 * @note 诊断填充：F800 显存填充 b/!b 交替。
 * @tag diag
 */
int diag_fill_pattern(byte b)

{
  undefined *puVar1;
  char cVar2;
  
  contrast_set(contrast + '\x04');
  puVar1 = &lcd_vram;
  cVar2 = ' ';
  do {
    memset(puVar1,b,0x20);
    memset(puVar1 + 0x20,b ^ 0xff,0x20);
    puVar1 = puVar1 + 0x40;
    cVar2 = cVar2 + -1;
  } while (cVar2 != '\0');
  wait_any_key();
  contrast_set(contrast);
  return 0;
}

/**
 * @brief 诊断页第二种棋盘格（casio-main 符号 diag_scr_ckb2_ws）
 * @addr 0x22226
 * @module diag
 * @proto void diag_scr_ckb2_ws(void)
 * @confidence strong
 * @note 诊断页第二种棋盘格（casio-main 符号 diag_scr_ckb2_ws）：R2=0xAA 后跳到 0x221CC
 *       填充 0xAA/0x55，等待 SHIFT。
 * @tag diag
 */
int diag_scr_ckb2_ws(void)

{
  diag_fill_pattern(0xaa);
  return 0;
}

/**
 * @brief 诊断页显示版本信息（casio-main 符号 diag_scr_version）
 * @addr 0x22250
 * @module diag
 * @proto int diag_scr_version(void)
 * @confidence strong
 * @note 诊断页显示版本信息（casio-main 符号 diag_scr_version）：清屏后以 0x4DCE 调用
 *       0x221AC 绘制，刷新屏幕并等待按键。
 * @tag diag
 */
int diag_scr_version(void)

{
  diag_print_ver();
  line_print_font14_col0(0x31,0x4dce);
  fb_flush();
  wait_dir_key();
  return 0;
}

/**
 * @brief 打印版本号（casio-main 符号 diag_print_ver）
 * @addr 0x22278
 * @module diag
 * @proto void diag_print_ver(void)
 * @confidence likely
 * @note 打印版本号（casio-main 符号 diag_print_ver）：清空缓冲并置 0xD137=0xE（Ghidra
 *       截断处 halt_baddata）。
 * @tag diag
 */
int diag_print_ver(void)

{
  clear_screen();
  cur_line = 0xe;
                    // WARNING: Bad instruction - Truncating control flow here
  halt_baddata();
}

/**
 * @brief 打印 ROM 中的部分数据（casio-main 符号 diag_print_pd，被 di…
 * @addr 0x222AE
 * @module diag
 * @proto void diag_print_pd(void)
 * @confidence likely
 * @note 打印 ROM 中的部分数据（casio-main 符号 diag_print_pd，被 diag_checksum
 *       调用）：键盘 IO 初始化后按 0x22382 的结果输出到 0x21xx。
 * @tag diag
 */
int diag_print_pd(void)

{
  uintptr_t fp = 0;
  undefined uVar1;
  
  get_ram_base();
  uVar1 = store_reg_to_stack();
  line_print_col0_nop(CONCAT11(0x21,uVar1),&*(byte *)(uintptr_t)(fp + 0x0000));
  return 0;
}

/**
 * @brief 诊断页主循环（casio-main 符号 diag_checksum）
 * @addr 0x222D4
 * @module diag
 * @proto ushort diag_checksum(void)
 * @confidence strong
 * @note 诊断页主循环（casio-main 符号 diag_checksum）：调用 0x22392 计算校验和、0x222AE
 *       显示，等待按键返回。
 * @tag diag
 */
ushort diag_checksum(void)

{
  undefined uVar1;
  uint uVar3;
  longlong lVar2;
  short sVar4;
  byte bVar5;
  undefined auStack_24 [16];
  undefined auStack_14 [16];
  
  uVar3 = (uint)((ZEXT28(auStack_14) << 0x30) >> 0x20);
  clear_screen();
  diag_print_ver();
  fb_flush();
  diag_calc_checksum();
  lVar2 = (ulonglong)uVar3 << 0x20;
  uVar1 = store_reg_to_stack();
  line_print_col0_nop(CONCAT11(0x11,uVar1),auStack_24);
  diag_print_pd();
  fb_flush();
  diag_key_test();
  store_reg_to_stack();
  draw_text4x(0x212c,auStack_24);
  line_print_font14_col0(0x31,0x4dce);
  bVar5 = 0;
  io_flag_x = 1;
  io_flag_y = 1;
  io_flag_z = 1;
  io_flag_w = 0;
  do {
    fb_flush();
    kbd_wait_key();
    sVar4 = (short)((ulonglong)lVar2 >> 0x30);
  } while ((bVar5 >> 6 & 1) == 1);
  timer_stub_init();
  return (short)*(undefined8 *)(sVar4 + 8);
}

/**
 * @brief 保存 R0..R15 到栈（casio-main 符号 r0..r15 -> [er14-1…
 * @addr 0x22382
 * @module diag
 * @proto int store_reg_to_stack(void)
 * @confidence strong
 * @note 保存 R0..R15 到栈（casio-main 符号 r0..r15 -> [er14-16]）。
 * @tag diag
 */
int store_reg_to_stack(void)

{
  undefined8 in_QR0;
  undefined4 unaff_XR8;
  undefined2 unaff_ER12;
  short unaff_ER14;
  
  *(undefined8 *)(unaff_ER14 + -0x10) = in_QR0;
  *(byte *)(uintptr_t)(ulonglong *)(unaff_ER14 + -8) = CONCAT26(unaff_ER14,CONCAT24(unaff_ER12,unaff_XR8));
  return 0;
}

/**
 * @brief 计算 ROM 校验和（casio-main 符号 diag_calc_checksum）
 * @addr 0x22392
 * @module diag
 * @proto ushort diag_calc_checksum(void)
 * @confidence strong
 * @note 计算 ROM 校验和（casio-main 符号 diag_calc_checksum）：写 0xF004，按
 *       0x0000..0xFBFF、1 段、2 段各扫一遍，结果与 0xFFF6 处的 A8 04 比较。
 * @tag diag
 */
ushort diag_calc_checksum(void)

{
  undefined2 *puVar1;
  ushort uVar2;
  undefined2 uVar3;
  byte bVar6;
  byte bVar7;
  undefined8 uVar4;
  short sVar8;
  ulonglong uVar5;
  ushort uVar9;
  
  chip_ctrl = 1;
  uVar4 = 0xfc00000000000000;
  uVar9 = 0;
  do {
    puVar1 = (undefined2 *)(uint3)uVar9;
    uVar9 = uVar9 + 2;
    nop();
    bVar6 = (byte)*puVar1;
    uVar2 = CONCAT11(((char)((ulonglong)uVar4 >> 8) - (char)((ushort)*puVar1 >> 8)) -
                     ((byte)uVar4 < bVar6),(byte)uVar4 - bVar6);
    sVar8 = (short)((ulonglong)uVar4 >> 0x30) + -2;
    uVar4 = CONCAT26(sVar8,(uint6)uVar2);
  } while (sVar8 != 0);
  uVar5 = (ulonglong)uVar2;
  uVar9 = 0;
  do {
    puVar1 = (undefined2 *)(uint3)uVar9;
    uVar9 = uVar9 + 2;
    nop();
    bVar6 = (byte)*puVar1;
    uVar2 = CONCAT11(((char)(uVar5 >> 8) - (char)((ushort)*puVar1 >> 8)) - ((byte)uVar5 < bVar6),
                     (byte)uVar5 - bVar6);
    sVar8 = (short)(uVar5 >> 0x30) + -2;
    uVar5 = CONCAT26(sVar8,(uint6)uVar2);
  } while (sVar8 != 0);
  uVar5 = (ulonglong)uVar2;
  uVar9 = 0;
  do {
    puVar1 = (undefined2 *)(uint3)uVar9;
    uVar9 = uVar9 + 2;
    nop();
    bVar6 = (byte)*puVar1;
    uVar2 = CONCAT11(((char)(uVar5 >> 8) - (char)((ushort)*puVar1 >> 8)) - ((byte)uVar5 < bVar6),
                     (byte)uVar5 - bVar6);
    sVar8 = (short)(uVar5 >> 0x30) + -2;
    uVar5 = CONCAT26(sVar8,(uint6)uVar2);
  } while (sVar8 != 0);
  uVar4 = CONCAT44((int)(CONCAT17(0xff,CONCAT16(0xf6,(uint6)uVar2)) >> 0x20),(uint)uVar2);
  uVar9 = 0;
  do {
    puVar1 = (undefined2 *)(uint3)uVar9;
    uVar9 = uVar9 + 2;
    nop();
    bVar7 = (byte)*puVar1;
    bVar6 = ((char)((ulonglong)uVar4 >> 8) - (char)((ushort)*puVar1 >> 8)) - ((byte)uVar4 < bVar7);
    sVar8 = (short)((ulonglong)uVar4 >> 0x30) + -2;
    uVar4 = CONCAT26(sVar8,(uint6)CONCAT11(bVar6,(byte)uVar4 - bVar7));
  } while (sVar8 != 0);
  hex_byte(bVar6);
  uVar3 = (undefined2)uVar4;
  hex_byte((byte)uVar4);
  return uVar3;
}

/**
 * @brief 按键/接口测试结果判断（返回 0xA5 表示 OK）
 * @addr 0x22408
 * @module diag
 * @proto byte diag_key_test(void)
 * @confidence strong
 * @note 按键/接口测试结果判断（返回 0xA5 表示 OK）。
 * @tag diag
 */
byte diag_key_test(void)

{
  undefined4 uVar1;
  undefined uVar2;
  ushort uVar3;
  uint6 uVar4;
  short sVar8;
  undefined8 uVar5;
  undefined8 uVar7;
  ulonglong uVar6;
  
  chip_ctrl = 1;
  sVar8 = -0x400;
  do {
    sVar8 = sVar8 + -1;
  } while (sVar8 != 0);
  uVar5 = 0x5a00;
  do {
    uVar3 = (ushort)uVar5;
    sVar8 = (short)((ulonglong)uVar5 >> 0x30) + -1;
    uVar5 = CONCAT26(sVar8,(uint6)CONCAT14(0x44,(uint)(uint3)uVar3));
  } while (sVar8 != 0);
  uVar6 = (ulonglong)(uint3)uVar3;
  do {
    uVar1 = (undefined4)uVar6;
    uVar4 = (uint6)CONCAT14(0x44,uVar1);
    sVar8 = (short)(uVar6 >> 0x30) + -1;
    uVar6 = CONCAT26(sVar8,uVar4);
  } while (sVar8 != 0);
  uVar5 = CONCAT44((int)(CONCAT17(0xff,CONCAT16(0xf6,uVar4)) >> 0x20),uVar1);
  do {
    uVar7 = uVar5;
    sVar8 = (short)((ulonglong)uVar7 >> 0x30) + -1;
    uVar5 = CONCAT26(sVar8,(uint6)CONCAT14(0x44,(int)uVar7));
  } while (sVar8 != 0);
  if ((char)((ulonglong)uVar7 >> 8) == 'Z') {
    uVar2 = 0xa5;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

/**
 * @brief 把 R0 的低/高半字节分别转成大写十六进制字符并合到 ER0（0xAB -> "AB"
 * @addr 0x22492
 * @module diag
 * @proto char hex_byte(byte b)
 * @confidence verified
 * @note 把 R0 的低/高半字节分别转成大写十六进制字符并合到 ER0（0xAB -> "AB"；casio-main 符号
 *       hex_byte）。
 * @tag libc
 */
char hex_byte(byte b)

{
  byte bVar1;
  char cVar2;
  
  bVar1 = b >> 4;
  if (bVar1 < 10) {
    cVar2 = bVar1 + 0x30;
  }
  else {
    cVar2 = bVar1 + 0x37;
  }
  return cVar2;
}

/**
 * @brief 把字节以 2 位十六进制绘制到自检页
 * @addr 0x224AE
 * @module diag
 * @proto void draw_hex_byte(byte b)
 * @confidence strong
 * @note 把字节以 2 位十六进制绘制到自检页。
 * @tag diag
 */
int draw_hex_byte(byte b)

{
  ushort uVar1;
  char cVar2;
  ushort local_16;
  undefined2 uStack_14;
  
  uVar1 = CONCAT11(b,b >> 4) & 0xfff;
  local_16 = uVar1 | 0x3030;
  cVar2 = (char)(local_16 >> 8);
  if ((byte)(SBORROW1(cVar2,'9') ^ (char)(cVar2 + -0x39) < '\0' | cVar2 == '9') != 1) {
    local_16 = CONCAT11(cVar2 + '\a',(char)uVar1) | 0x30;
  }
  draw_target = 0;
  uStack_14 = 0x68;
  line_print_font14_col0(0x11,&local_16);
  fb_alt_flush();
  draw_target = 1;
  return 0;
}

/**
 * @brief 返回 b 的最高有效位位置
 * @addr 0x224EE
 * @module diag
 * @proto byte bit_reverse_index(byte b)
 * @confidence strong
 * @note 返回 b 的最高有效位位置。
 * @tag libc
 */
byte bit_reverse_index(byte b)

{
  bool bVar1;
  byte bVar2;
  
  if (2 < b) {
    bVar2 = b;
    b = 9;
    do {
      b = (uintptr_t)b - 1;
      bVar1 = CARRY1(bVar2,bVar2);
      bVar2 = bVar2 * '\x02';
    } while (bVar1 == false);
    if (bVar2 != 0) {
      b = 0x10;
    }
  }
  return b;
}

/**
 * @brief flush 显存并等待按键（诊断页）
 * @addr 0x22502
 * @module diag
 * @proto void diag_flush(void)
 * @confidence verified
 * @note flush 显存并等待按键（诊断页）。
 * @tag diag
 */
int diag_flush(void)

{
  fb_flush();
  wait_any_key();
  return 0;
}

