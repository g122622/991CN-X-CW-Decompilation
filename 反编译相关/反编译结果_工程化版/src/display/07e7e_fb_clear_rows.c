/*
 * 显示驱动 / 07e7e_fb_clear_rows.c
 * 地址范围: 0x07E7E - 0x08672
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 把帧缓冲 0xDDD4 的前 n 行清零（每行 24 字节，行地址 = 0xDDD4 + n…
 * @addr 0x07E7E
 * @module display
 * @proto void fb_clear_rows(byte n)
 * @confidence strong
 * @note 把帧缓冲 0xDDD4 的前 n 行清零（每行 24 字节，行地址 = 0xDDD4 + n*24）。
 * @tag display
 */
int fb_clear_rows(byte n)

{
  short sVar1;
  
  sVar1 = (ushort)n * (CONCAT11(0x18,n) >> 8);
  memzero(&screen_fb + sVar1, (uintptr_t)0)
                 CONCAT11(('\x06' - (char)((ushort)sVar1 >> 8)) - ((char)sVar1 != '\0'),-(char)sVar1
                         ));
  return 0;
}

/**
 * @brief 把 0xDDEC 起的变量区前 count*0x18 字节清零
 * @addr 0x07E9C
 * @module display
 * @proto void var_table0_clear(byte count)
 * @confidence likely
 * @note 把 0xDDEC 起的变量区前 count*0x18 字节清零。
 * @tag hal
 */
int var_table0_clear(byte count)

{
  memzero(&line_buf,(count & 0xff) * 0x18);
  return 0;
}



// 填充屏幕缓冲区 (fill_screen)
// count: 填充参数，高位字节指定填充模式
// 返回：填充的字节数

/**
 * @brief 按 pattern 高字节选择填充区
 * @addr 0x07EAC
 * @module display
 * @proto ushort fill_screen(ushort pattern)
 * @confidence verified
 * @note 按 pattern 高字节选择填充区：0x04 → 0xE3D4 区 0x600 字节；bit8 → 主缓冲
 *       0xDDD4（0x600）；bit9 → LCD 显存 0xF800（0x800）。低字节为填充值。
 * @tag gfx
 */
ushort fill_screen(ushort pattern)

{
  undefined uVar1;
  ushort uVar2;
  
  uVar1 = (undefined)pattern;
  if ((char)(pattern >> 8) == '\x04') {
    uVar2 = 0x600;  // 1536字节 (主显示缓冲区)
    memset((undefined *)0xe3d4,uVar1,0x600);  // 填充0xe3d4缓冲区
  }
  else {
    uVar2 = pattern;
    if ((pattern & 0x100) != 0) {
      uVar2 = 0x600;
      memset(&screen_fb,uVar1,0x600);  // 填充0xddd4缓冲区
    }
    if ((pattern & 0x200) != 0) {
      uVar2 = 0x800;  // 2048字节 (辅助显示缓冲区)
      memset(&lcd_vram,uVar1,0x800);  // 填充0xf800缓冲区
    }
  }
  return uVar2;
}



// 清空显示缓冲区 (clear_screen)
// 地址: 0x7F00
// 功能: 将0xddd4显示缓冲区清零

/**
 * @brief 清主缓冲 0xDDD4（0x600 字节 = 64 行 × 24 字节）
 * @addr 0x07F00
 * @module display
 * @proto void clear_screen(void)
 * @confidence verified
 * @note 清主缓冲 0xDDD4（0x600 字节 = 64 行 × 24 字节）。
 * @tag gfx
 */
int clear_screen(int _a1)

{
  char cVar1;
  undefined8 *puVar2;
  
  puVar2 = (undefined8 *)&screen_fb;  // 显示缓冲区起始地址
  cVar1 = -0x40;  // -64，循环64次 (每次清8字节，共512字节)
  do {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
    cVar1 = cVar1 + -1;
  } while (cVar1 != '\0');
  return 0;
}



// 设置显示行 (scroll_screen)
// 地址: 0x7F1A
// _a1: 行号

/**
 * @brief 屏幕上滚 lines 行
 * @addr 0x07F1A
 * @module display
 * @proto void scroll_screen(char lines)
 * @confidence strong
 * @note 屏幕上滚 lines 行：把 0xDDD4 中从 (lines+1) 行开始的内容前移，尾部清零。
 * @tag gfx
 */
int scroll_screen(char lines, int _a2)

{
  char cVar1;
  short sVar2;
  char cVar3;
  short sVar4;
  
  sVar4 = (ushort)(byte)((uintptr_t)lines + 1) * 0x18;
  cVar3 = (char)sVar4;
  cVar1 = ('\x06' - (char)((ushort)sVar4 >> 8)) - (cVar3 != '\0');
  sVar2 = CONCAT11(cVar1,-cVar3);
  memmove(&line_buf,&screen_fb + sVar4,sVar2);
  memzero(&line_buf + sVar2,CONCAT11(('\x06' - cVar1) - (-cVar3 != '\0'),cVar3) + -0x18);
  return 0;
}



// 设置显示位置 (draw_vline)
// 地址: 0x7F58
// lines: 列位置
// _a2: 行位置

/**
 * @brief 在 (行 = pos 高位, 列位 = pos 低位) 处画竖线
 * @addr 0x07F58
 * @module display
 * @proto void draw_vline(ushort pos, ushort flags)
 * @confidence strong
 * @note 在 (行 = pos 高位, 列位 = pos 低位) 处画竖线；flags 的 bit15/13
 *       控制左右相邻像素、bit14/12 控制上下相邻行是否连线。
 * @tag gfx
 */
int draw_vline(ushort pos, ushort flags)

{
  undefined uVar1;
  char cVar2;
  ushort uVar3;
  char cVar4;
  char cVar5;
  
  uVar1 = (undefined)(pos >> 8);
  uVar3 = flags;
  if ((flags & 0x8000) != 0) {
    char_print_zero(CONCAT11(uVar1,(char)pos + '\x01'),(char)flags);
  }
  if ((flags & 0x2000) != 0) {
    char_print_zero(CONCAT11(uVar1,(char)pos + -1),(char)uVar3);
  }
  while( true ) {
    char_print_zero(pos,(char)uVar3);
    cVar2 = (char)uVar3;
    cVar5 = (char)(pos >> 8);
    cVar4 = (char)pos;
    if (cVar5 == (char)flags) break;
    pos = CONCAT11(cVar5 + '\x01',cVar4);
  }
  if ((flags & 0x4000) != 0) {
    char_print_zero(CONCAT11(cVar5,cVar4 + '\x01'),cVar2);
  }
  if ((flags & 0x1000) != 0) {
    char_print_zero(CONCAT11(cVar5,cVar4 + -1),cVar2);
  }
  return 0;
}



// 设置显示区域 (draw_vline2)
// 地址: 0x7FA0
// pos: 起始位置
// flags: 结束位置

/**
 * @brief 双像素宽版 draw_vline（作框线左侧竖边）
 * @addr 0x07FA0
 * @module display
 * @proto void draw_vline2(ushort pos, ushort flags)
 * @confidence strong
 * @note 双像素宽版 draw_vline（作框线左侧竖边）。
 * @tag gfx
 */
int draw_vline2(ushort pos, ushort flags)

{
  char cVar1;
  char cVar2;
  char cVar3;
  ushort uVar4;
  
  cVar1 = (char)pos;
  cVar2 = (char)(pos >> 8);
  uVar4 = flags;
  if ((flags & 0x8000) != 0) {
    char_print_zero(CONCAT11(cVar2,cVar1 + '\x02'),(char)flags);
    char_print_zero(CONCAT11(cVar2,cVar1 + '\x03'),(char)uVar4);
    char_print_zero(CONCAT11(cVar2 + '\x01',cVar1 + '\x02'),(char)uVar4);
    char_print_zero(CONCAT11(cVar2 + '\x01',cVar1 + '\x03'),(char)uVar4);
  }
  if ((flags & 0x2000) != 0) {
    char_print_zero(CONCAT11(cVar2,cVar1 + -1),(char)uVar4);
    char_print_zero(CONCAT11(cVar2,cVar1 + -2),(char)uVar4);
    char_print_zero(CONCAT11(cVar2 + '\x01',cVar1 + -1),(char)uVar4);
    char_print_zero(CONCAT11(cVar2 + '\x01',cVar1 + -2),(char)uVar4);
  }
  while( true ) {
    char_print_zero(pos,(char)uVar4);
    cVar1 = (char)pos;
    cVar2 = (char)(pos >> 8);
    char_print_zero(CONCAT11(cVar2,cVar1 + '\x01'),(char)uVar4);
    cVar3 = (char)uVar4;
    if (cVar2 == (char)flags) break;
    pos = CONCAT11(cVar2 + '\x01',cVar1);
  }
  if ((flags & 0x4000) != 0) {
    char_print_zero(CONCAT11(cVar2,cVar1 + '\x02'),cVar3);
    char_print_zero(CONCAT11(cVar2,cVar1 + '\x03'),cVar3);
    char_print_zero(CONCAT11(cVar2 + -1,cVar1 + '\x02'),cVar3);
    char_print_zero(CONCAT11(cVar2 + -1,cVar1 + '\x03'),cVar3);
  }
  if ((flags & 0x1000) != 0) {
    char_print_zero(CONCAT11(cVar2,cVar1 + -1),cVar3);
    char_print_zero(CONCAT11(cVar2,cVar1 + -2),cVar3);
    char_print_zero(CONCAT11(cVar2 + -1,cVar1 + -1),cVar3);
    char_print_zero(CONCAT11(cVar2 + -1,cVar1 + -2),cVar3);
  }
  return 0;
}

/**
 * @brief 画横线
 * @addr 0x08060
 * @module display
 * @proto void draw_hline(ushort pos, ushort flags)
 * @confidence strong
 * @note 画横线：在行区间内连接像素，flags 同上，用于框线的上/下边。
 * @tag gfx
 */
int draw_hline(ushort pos, ushort flags)

{
  char cVar1;
  char cVar2;
  char cVar3;
  undefined2 uVar4;
  ushort uVar5;
  
  cVar1 = (char)pos;
  cVar3 = (char)((ushort)pos >> 8);
  uVar4 = flags;
  char_print_zero(CONCAT11(cVar3,cVar1 + '\x02'),(char)flags);
  char_print_zero(CONCAT11(cVar3,cVar1 + '\x03'),(char)uVar4);
  char_print_zero(CONCAT11(cVar3 + '\x01',cVar1 + '\x01'),(char)uVar4);
  char_print_zero(CONCAT11(cVar3 + '\x01',cVar1 + '\x02'),(char)uVar4);
  uVar5 = CONCAT11(cVar3 + '\x02',cVar1);
  while( true ) {
    char_print_zero(uVar5,(char)uVar4);
    cVar3 = (char)(uVar5 >> 8);
    cVar1 = (char)uVar5;
    if (cVar3 == (char)((ushort)flags >> 8)) {
      char_print_zero(CONCAT11(cVar3,cVar1 + -1),(char)uVar4);
      char_print_zero(CONCAT11(cVar3 + -1,cVar1 + -1),(char)uVar4);
      char_print_zero(CONCAT11(cVar3 + '\x01',cVar1 + -1),(char)uVar4);
      cVar2 = cVar1 + -2;
    }
    else {
      cVar2 = cVar1 + '\x01';
    }
    char_print_zero(CONCAT11(cVar3,cVar2),(char)uVar4);
    cVar2 = (char)uVar4;
    if (cVar3 == (char)((char)flags + -2)) break;
    uVar5 = CONCAT11(cVar3 + '\x01',cVar1);
  }
  char_print_zero(CONCAT11(cVar3 + '\x01',cVar1),cVar2);
  char_print_zero(CONCAT11(cVar3 + '\x01',cVar1 + '\x01'),cVar2);
  char_print_zero(CONCAT11(cVar3 + '\x02',cVar1 + '\x01'),cVar2);
  char_print_zero(CONCAT11(cVar3 + '\x02',cVar1 + '\x02'),cVar2);
  char_print_zero(CONCAT11(cVar3 + '\x03',cVar1 + '\x02'),cVar2);
  char_print_zero(CONCAT11(cVar3 + '\x03',cVar1 + '\x03'),cVar2);
  return 0;
}

/**
 * @brief 与 draw_hline 类似但带逐像素节奏（配合 0xF046 扫描），用于光标闪烁/呼吸…
 * @addr 0x08102
 * @module display
 * @proto void draw_hline_animated(ushort pos, ushort flags)
 * @confidence likely
 * @note 与 draw_hline 类似但带逐像素节奏（配合 0xF046 扫描），用于光标闪烁/呼吸线条。
 * @tag gfx
 */
int draw_hline_animated(ushort pos, ushort flags)

{
  byte bVar3;
  undefined2 uVar1;
  ushort uVar2;
  undefined uVar4;
  byte bVar6;
  undefined2 uVar5;
  short sVar7;
  char cVar8;
  byte bVar13;
  ushort uVar14;
  undefined8 in_QR8;
  ulonglong uVar9;
  ulonglong uVar10;
  longlong lVar11;
  short sVar15;
  undefined8 uVar12;
  
  uVar9 = CONCAT62((int6)(CONCAT44((int)(CONCAT26(0xfff0,(int6)in_QR8) >> 0x20),
                                   (uint)(byte)flags << 0x10) >> 0x10),pos) &
          0xffffffffffff00ff;
  bVar13 = (byte)(uVar9 >> 0x10);
  bVar6 = (byte)((ushort)flags >> 8);
  bVar3 = (byte)(pos >> 8);
  uVar10 = CONCAT26((short)(char)(uVar9 >> 0x30),
                    CONCAT15((char)(uVar9 >> 0x28) - (bVar6 < bVar3),
                             CONCAT14(bVar6 - bVar3,
                                      (int)CONCAT41((int)(((uint5)CONCAT12(bVar6,CONCAT11(-(bVar13 <
                                                                                           (byte)
                                                  uVar9),bVar13 - (byte)uVar9)) << 0x10) >> 8),bVar3
                                                  ))));
  px_set(pos);
  uVar4 = 1;
  uVar9 = uVar10 >> 0x10;
  uVar2 = (ushort)(uVar10 >> 0x10);
  if ((short)uVar2 < 0) {
    uVar9 = (ulonglong)CONCAT42((int)(uVar10 >> 0x20),(uVar2 ^ 0xffff) + 1);
    uVar4 = 0xff;
  }
  lVar11 = uVar9 << 0x10;
  uVar5 = CONCAT11(1,uVar4);
  uVar2 = (ushort)(uVar9 >> 0x10);
  if ((short)uVar2 < 0) {
    lVar11 = CONCAT26((short)(uVar9 >> 0x20),CONCAT24((uVar2 ^ 0xffff) + 1,(int)lVar11));
    uVar5 = CONCAT11(0xff,uVar4);
  }
  uVar1 = 0;
  uVar2 = (ushort)((ulonglong)lVar11 >> 0x10);
  uVar12 = CONCAT62((int6)((ulonglong)lVar11 >> 0x10),uVar2);
  uVar14 = (ushort)((ulonglong)lVar11 >> 0x20);
  if (uVar2 < uVar14) {
    pos = CONCAT11((char)pos,bVar3);
    uVar12 = CONCAT44(CONCAT22((short)((ulonglong)lVar11 >> 0x30),uVar2),CONCAT22(uVar14,uVar14));
    uVar5 = CONCAT11((char)uVar5,(char)((ushort)uVar5 >> 8));
    uVar1 = 0x100;
  }
  sVar15 = (short)((ulonglong)uVar12 >> 0x30);
  *(undefined2 *)(sVar15 + -4) = uVar1;
  *(undefined2 *)(sVar15 + -2) = uVar5;
  sVar7 = (short)((ulonglong)uVar12 >> 0x10);
  bVar3 = (byte)((ulonglong)uVar12 >> 0x10);
  bVar6 = (byte)((ulonglong)uVar12 >> 0x20);
  for (uVar12 = CONCAT35(CONCAT21(sVar15,(char)(((ushort)(byte)((ulonglong)uVar12 >> 0x28) * 0x100 +
                                                (ushort)bVar6) * 2 >> 8)),
                         CONCAT14(bVar6 << 1,
                                  CONCAT13((char)(((ushort)(byte)((ulonglong)uVar12 >> 0x18) * 0x100
                                                  + (ushort)bVar3) * 2 >> 8),
                                           CONCAT12(bVar3 << 1,(short)uVar12))));
      (char)uVar12 != '\0'; uVar12 = CONCAT71((int7)((ulonglong)uVar12 >> 8),(char)uVar12 + -1)) {
    bVar3 = (byte)((ulonglong)uVar12 >> 0x20);
    cVar8 = ((char)((ushort)sVar7 >> 8) - (char)((ulonglong)uVar12 >> 0x28)) - ((byte)sVar7 < bVar3)
    ;
    sVar7 = CONCAT11(cVar8,(byte)sVar7 - bVar3);
    sVar15 = (short)((ulonglong)uVar12 >> 0x30);
    if (SCARRY2(sVar7,0) != cVar8 < '\0') {
      sVar7 = sVar7 + (short)((ulonglong)uVar12 >> 0x10);
      pos = CONCAT11((char)(pos >> 8) + *(char *)(sVar15 + -1),(char)pos);
    }
    uVar4 = (undefined)(pos >> 8);
    cVar8 = (char)pos + *(char *)(sVar15 + -2);
    pos = CONCAT11(uVar4,cVar8);
    uVar2 = pos;
    if (*(char *)(sVar15 + -3) != '\0') {
      uVar2 = CONCAT11(cVar8,uVar4);
    }
    px_set(uVar2);
  }
  return 0;
}

/**
 * @brief draw_format_string 的 AL 参数变体（被 0x8C4A 使用）
 * @addr 0x081A2
 * @module display
 * @proto int draw_format_string_al(ushort pos, char* fmt)
 * @confidence likely
 * @note draw_format_string 的 AL 参数变体（被 0x8C4A 使用）。
 * @tag text
 */
int draw_format_string_al(ushort pos, char* fmt)

{
  char cVar1;
  byte bVar2;
  char *pcVar5;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined auStack_4e [74];
  
  uVar3 = CONCAT62(CONCAT42(CONCAT22(auStack_4e,auStack_4e),fmt),pos) & 0xffffffffffffff00;
  strlen_checked(fmt);
  cVar1 = *(char *)(uVar3 >> 0x10);
  while (pcVar5 = (char *)(uVar3 >> 0x30), cVar1 != '\0') {
    if ((cVar1 == '\x02') || (cVar1 == '\x04')) {
      uVar4 = CONCAT44((int)(uVar3 >> 0x20),CONCAT22((short)(uVar3 >> 0x10) + 1,(short)uVar3));
      bVar2 = input_read_str(pcVar5);
      uVar4 = CONCAT26((short)((ulonglong)uVar4 >> 0x30) + (ushort)bVar2,(int6)uVar4);
    }
    else {
      *pcVar5 = cVar1;
      uVar4 = CONCAT26(pcVar5 + 1,(int6)uVar3);
    }
    pcVar5 = (char *)((short)((ulonglong)uVar4 >> 0x10) + 1);
    uVar3 = CONCAT44((int)((ulonglong)uVar4 >> 0x20),CONCAT22(pcVar5,(short)uVar4));
    cVar1 = *pcVar5;
  }
  *pcVar5 = '\0';
  bVar2 = strlen_checked((char *)(uVar3 >> 0x20));
  if (0x20 < bVar2) {
    strcpy_checked((char *)(uVar3 >> 0x20),"ERROR");
  }
  draw_string((short)uVar3,(short)(uVar3 >> 0x20));
  return 0;
}

/**
 * @brief 绘制格式化字符串
 * @addr 0x081A4
 * @module display
 * @proto void draw_format_string(ushort pos, char* fmt)
 * @confidence strong
 * @note 绘制格式化字符串：0x02/0x04 之后的字节为"数值引用"，用 0x9D52 转成当前显示格式的字符串。
 * @tag text
 */
int draw_format_string(ushort pos, char* fmt)

{
  char cVar1;
  byte bVar2;
  char *pcVar4;
  undefined8 uVar3;
  undefined auStack_4e [74];
  
  uVar3 = CONCAT62(CONCAT42(CONCAT22(auStack_4e,auStack_4e),fmt),pos);
  strlen_checked(fmt);
  cVar1 = *(char *)((ulonglong)uVar3 >> 0x10);
  while (pcVar4 = (char *)((ulonglong)uVar3 >> 0x30), cVar1 != '\0') {
    if ((cVar1 == '\x02') || (cVar1 == '\x04')) {
      uVar3 = CONCAT44((int)((ulonglong)uVar3 >> 0x20),
                       CONCAT22((short)((ulonglong)uVar3 >> 0x10) + 1,(short)uVar3));
      bVar2 = input_read_str(pcVar4);
      uVar3 = CONCAT26((short)((ulonglong)uVar3 >> 0x30) + (ushort)bVar2,(int6)uVar3);
    }
    else {
      *pcVar4 = cVar1;
      uVar3 = CONCAT26(pcVar4 + 1,(int6)uVar3);
    }
    pcVar4 = (char *)((short)((ulonglong)uVar3 >> 0x10) + 1);
    uVar3 = CONCAT44((int)((ulonglong)uVar3 >> 0x20),CONCAT22(pcVar4,(short)uVar3));
    cVar1 = *pcVar4;
  }
  *pcVar4 = '\0';
  bVar2 = strlen_checked((char *)((ulonglong)uVar3 >> 0x20));
  if (0x20 < bVar2) {
    strcpy_checked((char *)((ulonglong)uVar3 >> 0x20),"ERROR");
  }
  draw_string((short)uVar3,(short)((ulonglong)uVar3 >> 0x20));
  return 0;
}

/**
 * @brief 绘制字符串
 * @addr 0x0821C
 * @module display
 * @proto ushort draw_string_nl(ushort pos, ushort str)
 * @confidence verified
 * @note 绘制字符串：0x01 = 换行、0x04 或 >=0xF0 的字节组成双字节字符；返回结束光标。
 * @tag text
 */
ushort draw_string_nl(ushort pos, ushort str)

{
  undefined uVar1;
  byte bVar2;
  char cVar4;
  undefined2 uVar5;
  byte *pbVar10;
  uint5 uVar6;
  undefined8 uVar8;
  undefined7 uVar9;
  ushort uVar3;
  uint6 uVar7;
  
  uVar6 = (uint5)(CONCAT22(str,pos) & 0xffffff00);
  uVar7 = CONCAT15(0xb,uVar6);
  uVar1 = (undefined)((ushort)pos >> 8);
  if (cur_line != '\x0e') {
    uVar7 = CONCAT15(6,uVar6);
  }
  uVar3 = 0;
  for (uVar8 = CONCAT35((int3)(CONCAT17(-0x40 - (char)(uVar7 >> 0x28),(uint7)uVar7) >> 0x28),
                        (uint5)(uint)uVar7); (byte)uVar8 <= (byte)((ulonglong)uVar8 >> 0x38);
      uVar8 = CONCAT44((int)((ulonglong)uVar8 >> 0x20),
                       CONCAT22((short)((ulonglong)uVar8 >> 0x10) + 1,(short)uVar8))) {
    cVar4 = (char)(uVar3 >> 8);
    pbVar10 = (byte *)((ulonglong)uVar8 >> 0x10);
    bVar2 = *pbVar10;
    uVar3 = CONCAT11(cVar4,bVar2);
    if (bVar2 == 0) break;
    uVar5 = (undefined2)uVar8;
    if (bVar2 == 4) {
      if (cur_line == '\x0e') {
        pbVar10 = pbVar10 + 1;
        uVar8 = CONCAT44((int)((ulonglong)uVar8 >> 0x20),CONCAT22(pbVar10,uVar5));
        uVar1 = 0;
        draw_char(uVar5,CONCAT11(cVar4,*pbVar10));
        uVar8 = CONCAT71((int7)((ulonglong)uVar8 >> 8),(char)uVar8 + '\t');
        goto LAB_rom_008282;
      }
    }
    else if (bVar2 < 0xf0) {
      if (bVar2 == 1) {
        uVar1 = 0;
        draw_blank_slot(uVar3);
      }
      else {
        uVar1 = 0;
        draw_char(uVar5,uVar3);
        uVar9 = (undefined7)((ulonglong)uVar8 >> 8);
        if ((cVar4 == -0xf) || (cVar4 == -0xe)) {
          uVar8 = CONCAT71(uVar9,(char)uVar8 + '\f');
        }
        else {
          uVar8 = CONCAT71(uVar9,(char)uVar8 + (char)((ulonglong)uVar8 >> 0x28));
        }
      }
LAB_rom_008282:
      uVar3 = 0;
      uVar8 = CONCAT35((int3)((ulonglong)uVar8 >> 0x28),
                       CONCAT14((char)((ulonglong)uVar8 >> 0x20) + '\x01',(int)uVar8));
    }
    else {
      uVar3 = (ushort)bVar2 << 8;
    }
  }
  return CONCAT11(uVar1,(char)((ulonglong)uVar8 >> 0x20));
}

/**
 * @brief 同 draw_string_nl，但不处理换行（0x01 为普通占位）
 * @addr 0x0821E
 * @module display
 * @proto ushort draw_string(ushort pos, ushort str)
 * @confidence verified
 * @note 同 draw_string_nl，但不处理换行（0x01 为普通占位）。
 * @tag text
 */
ushort draw_string(ushort pos, ushort str)

{
  undefined uVar1;
  byte bVar2;
  char cVar4;
  undefined2 uVar5;
  byte *pbVar9;
  uint6 uVar6;
  undefined8 uVar7;
  undefined7 uVar8;
  ushort uVar3;
  
  uVar6 = CONCAT15(0xb,(uint5)CONCAT22(str,pos));
  uVar1 = (undefined)((ushort)pos >> 8);
  if (cur_line != '\x0e') {
    uVar6 = CONCAT15(6,(uint5)CONCAT22(str,pos));
  }
  uVar3 = 0;
  for (uVar7 = CONCAT35((int3)(CONCAT17(-0x40 - (char)(uVar6 >> 0x28),(uint7)uVar6) >> 0x28),
                        (uint5)(uint)uVar6); (byte)uVar7 <= (byte)((ulonglong)uVar7 >> 0x38);
      uVar7 = CONCAT44((int)((ulonglong)uVar7 >> 0x20),
                       CONCAT22((short)((ulonglong)uVar7 >> 0x10) + 1,(short)uVar7))) {
    cVar4 = (char)(uVar3 >> 8);
    pbVar9 = (byte *)((ulonglong)uVar7 >> 0x10);
    bVar2 = *pbVar9;
    uVar3 = CONCAT11(cVar4,bVar2);
    if (bVar2 == 0) break;
    uVar5 = (undefined2)uVar7;
    if (bVar2 == 4) {
      if (cur_line == '\x0e') {
        pbVar9 = pbVar9 + 1;
        uVar7 = CONCAT44((int)((ulonglong)uVar7 >> 0x20),CONCAT22(pbVar9,uVar5));
        uVar1 = 0;
        draw_char(uVar5,CONCAT11(cVar4,*pbVar9));
        uVar7 = CONCAT71((int7)((ulonglong)uVar7 >> 8),(char)uVar7 + '\t');
        goto LAB_rom_008282;
      }
    }
    else if (bVar2 < 0xf0) {
      if (bVar2 == 1) {
        uVar1 = 0;
        draw_blank_slot(uVar3);
      }
      else {
        uVar1 = 0;
        draw_char(uVar5,uVar3);
        uVar8 = (undefined7)((ulonglong)uVar7 >> 8);
        if ((cVar4 == -0xf) || (cVar4 == -0xe)) {
          uVar7 = CONCAT71(uVar8,(char)uVar7 + '\f');
        }
        else {
          uVar7 = CONCAT71(uVar8,(char)uVar7 + (char)((ulonglong)uVar7 >> 0x28));
        }
      }
LAB_rom_008282:
      uVar3 = 0;
      uVar7 = CONCAT35((int3)((ulonglong)uVar7 >> 0x28),
                       CONCAT14((char)((ulonglong)uVar7 >> 0x20) + '\x01',(int)uVar7));
    }
    else {
      uVar3 = (ushort)bVar2 << 8;
    }
  }
  return CONCAT11(uVar1,(char)((ulonglong)uVar7 >> 0x20));
}

/**
 * @brief 把 str 中的 0x01 渲染为一个空格（处理 ALPHA/SHIFT 等占位）
 * @addr 0x08296
 * @module display
 * @proto void draw_blank_slot(ushort pos)
 * @confidence strong
 * @note 把 str 中的 0x01 渲染为一个空格（处理 ALPHA/SHIFT 等占位）。
 * @tag text
 */
int draw_blank_slot(ushort pos)

{
  byte bVar1;
  undefined uVar3;
  ushort uVar2;
  char cVar4;
  byte bVar5;
  undefined2 unaff_ER8;
  char unaff_R13;
  
  uVar3 = (undefined)((ushort)pos >> 8);
  bVar1 = get_ptr_ffd8_4();
  bVar5 = menu_toggle;
  if (bVar1 == 1) {
    bVar5 = menu_toggle ^ 1;
  }
  if ((bVar5 == 0) || (calc_mode == '\x02')) {
    uVar2 = CONCAT11(uVar3,0x20);
  }
  else {
    uVar2 = CONCAT11(uVar3,*(undefined *)(bVar1 + 0x33d4));
  }
  return_4();
  uVar3 = cursor_visible;
  cursor_visible = 1;
  if (unaff_R13 == '\v') {
    cVar4 = '\x02';
  }
  else {
    cVar4 = '\x01';
  }
  draw_char(CONCAT11((char)((ushort)unaff_ER8 >> 8),(char)unaff_ER8 - cVar4),uVar2);
  cursor_visible = uVar3;
  return 0;
}



// 打印单字节字符到屏幕 (draw_char_fast)
// 地址: 0x82EC

/**
 * @brief 与 draw_char 共享函数体的前导块（ROM 中 0x82EC 与 0x82F6 指令…
 * @addr 0x082EC
 * @module display
 * @proto void draw_char_fast(ushort pos, byte ch)
 * @confidence likely
 * @note 与 draw_char 共享函数体的前导块（ROM 中 0x82EC 与 0x82F6 指令重叠），由 0x82F6
 *       的完整函数覆盖；保留此入口仅为对照 Ghidra 的函数切分。
 * @tag text
 */
int draw_char_fast(ushort pos, byte ch)

{
  undefined4 uVar1;
  undefined7 uVar2;
  ushort *puVar3;
  byte bVar4;
  byte bVar5;
  undefined2 *puVar6;
  byte *pbVar7;
  byte bVar8;
  ushort uVar9;
  undefined2 uVar10;
  byte bVar11;
  byte bVar12;
  byte bVar13;
  undefined6 uVar14;
  undefined *puVar18;
  uint uVar17;
  short sVar19;
  longlong lVar15;
  longlong lVar16;
  short sVar20;
  undefined2 auStack_38 [15];
  ushort uStack_1a;
  undefined2 uStack_16;
  undefined2 uStack_14;
  undefined uStack_11;
  undefined auStack_10 [12];
  
  puVar18 = auStack_10;
  bVar4 = (byte)pos;
  if ((bVar4 < 0xc0) &&
     (bVar5 = (byte)((ushort)pos >> 8),
     (byte)(SBORROW1(bVar5,'@') ^ (char)(bVar5 - 0x40) < '\0') == 1)) {
    uStack_14 = 0xe3d3;
    if (draw_target == '\0') {
      uStack_14 = 0xe9d3;
    }
    uStack_11 = 0x18;
    if (cur_line == 0xe) {
      uVar10 = 0x50b;
    }
    else {
      uVar10 = 0x206;
    }
    uStack_1a = (ushort)(byte)(cur_line - 1);
    uStack_16 = uVar10;
    if (cur_line < 0xb) {
      puVar18 = auStack_10;
      puVar6 = (undefined2 *)glyph_get_large((ushort)ch,(byte *)auStack_38);
    }
    else {
      puVar6 = glyph_get_small((ushort)ch,auStack_38);
    }
    *(undefined2 **)((short)puVar18 - 0xc) = puVar6;
    uVar17 = ZEXT24(puVar18);
    bVar5 = calc_px_ptr(bVar4,bVar5,(undefined2 *)((short)puVar18 - 8));
    lVar16 = (ulonglong)
             CONCAT61(CONCAT42(uVar17,*(undefined2 *)((short)(uVar17 >> 0x10) + -8)),bVar5) << 8;
    bVar12 = *(byte *)(bVar5 + 0x33bc);
    bVar5 = (byte)((ushort)uVar10 >> 8);
    bVar11 = *(byte *)(((char)uVar10 + bVar4 & 7) + 0x33c4);
    bVar4 = 1;
    if (10 < cur_line) {
      bVar4 = 2;
      bVar5 = 0xff;
    }
    do {
      uVar2 = (undefined7)((ulonglong)lVar16 >> 8);
      bVar13 = (byte)((ulonglong)lVar16 >> 8);
      puVar3 = (ushort *)((ulonglong)lVar16 >> 0x20);
      pbVar7 = (byte *)((ulonglong)lVar16 >> 0x10);
      sVar20 = (short)((ulonglong)lVar16 >> 0x30);
      if (bVar4 == 1) {
        if (bVar13 == 0) {
          px_or_run(pbVar7,(byte *)puVar3,bVar11);
        }
        else {
          bVar8 = ('\b' - *(char *)(sVar20 + -6)) - bVar13;
          if ('\0' < (char)bVar8) {
            bVar12 = bVar12 & -1 << (bVar8 & 7);
          }
          bVar13 = *(byte *)puVar3 >> (bVar13 & 7) & bVar12;
          lVar15 = CONCAT71(uVar2,bVar13);
          *(byte *)(sVar20 + -2) = bVar13;
          px_or_run(pbVar7,(byte *)(sVar20 + -2),bVar12);
          sVar20 = (short)((ulonglong)lVar15 >> 0x30);
          bVar13 = (byte)((ulonglong)lVar15 >> 8);
          lVar16 = lVar15;
          if ((byte)(*(char *)(sVar20 + -5) + 1U) <= bVar13) {
            bVar13 = *(char *)((ulonglong)lVar15 >> 0x20) << (8 - bVar13 & 7) & bVar11;
            lVar16 = CONCAT71((int7)((ulonglong)lVar15 >> 8),bVar13);
            *(byte *)(sVar20 + -2) = bVar13;
            px_or_run((byte *)((short)((ulonglong)lVar15 >> 0x10) + 1),(byte *)(sVar20 + -2), (uintptr_t)0)
                           bVar11);
          }
        }
      }
      else {
        uVar9 = *puVar3;
        lVar16 = CONCAT71(uVar2,(char)((uVar9 & 0xff00) + (uVar9 & 0xff) >> (bVar13 & 7)));
        *(byte *)(sVar20 + -2) = (byte)(uVar9 >> 8) >> (bVar13 & 7);
        px_or_run(pbVar7,(byte *)(sVar20 + -2),bVar12);
        sVar19 = (short)((ulonglong)lVar16 >> 0x30);
        sVar20 = (short)((ulonglong)lVar16 >> 0x10);
        if ((char)(((byte)((ulonglong)lVar16 >> 8) < (byte)(*(char *)(sVar19 + -5) + 1U)) << 7) <
            '\0') {
          *(char *)(sVar19 + -2) = (char)lVar16;
          pbVar7 = (byte *)(sVar20 + 1);
        }
        else {
          *(char *)(sVar19 + -2) = (char)lVar16;
          px_or_run((byte *)(sVar20 + 1),(byte *)(sVar19 + -2),bVar5);
          *(char *)((short)((ulonglong)lVar16 >> 0x30) + -2) =
               (char)*(undefined2 *)((ulonglong)lVar16 >> 0x20) <<
               (8U - (char)((ulonglong)lVar16 >> 8) & 7);
          pbVar7 = (byte *)((short)((ulonglong)lVar16 >> 0x10) + 2);
        }
        px_or_run(pbVar7,(byte *)((short)((ulonglong)lVar16 >> 0x30) + -2),bVar11);
      }
      sVar20 = (short)((ulonglong)lVar16 >> 0x30);
      bVar13 = (byte)((ulonglong)lVar16 >> 0x10);
      uVar1 = CONCAT13((char)((ulonglong)lVar16 >> 0x18) -
                       ((char)(CARRY1(bVar13,*(byte *)(sVar20 + -1)) << 7) >> 7),
                       CONCAT12(bVar13 + *(byte *)(sVar20 + -1),(short)lVar16));
      if (*(ushort *)(sVar20 + -4) < (ushort)((uint)uVar1 >> 0x10)) {
        return 0;
      }
      bVar13 = (byte)((ulonglong)lVar16 >> 0x20);
      uVar14 = CONCAT15((char)((ulonglong)lVar16 >> 0x28) - ((char)(CARRY1(bVar13,bVar4) << 7) >> 7)
                        ,CONCAT14(bVar13 + bVar4,uVar1));
      bVar13 = (byte)*(undefined2 *)(sVar20 + -10);
      bVar8 = (char)((ushort)*(undefined2 *)(sVar20 + -10) >> 8) + 1;
      *(ushort *)(sVar20 + -10) = CONCAT11(bVar8,bVar13);
      if (bVar8 == bVar13) {
        uVar14 = CONCAT15(0xb,CONCAT14(0x8a,uVar1));
      }
      lVar16 = CONCAT26(sVar20,uVar14);
    } while (bVar8 <= bVar13);
  }
  return 0;
}



// 打印字符到屏幕 (draw_char)
// 地址: 0x82F6
// pos: 字符编码
// ch: 打印参数（包含位置、大小等信息）

/**
 * @brief 在 pos 处绘制一个字符
 * @addr 0x082F6
 * @module display
 * @proto void draw_char(ushort pos, ushort code)
 * @confidence verified
 * @note 在 pos 处绘制一个字符：取字形后逐位 OR 到 0xDDD4/0xE3D4 缓冲。
 * @tag text
 */
int draw_char(ushort pos, ushort code)

{
  undefined4 uVar1;
  undefined7 uVar2;
  ushort *puVar3;
  byte bVar4;
  byte bVar5;
  undefined2 *puVar6;
  byte *pbVar7;
  byte bVar8;
  char cVar10;
  ushort uVar9;
  undefined2 uVar11;
  byte bVar12;
  byte bVar13;
  byte bVar14;
  undefined6 uVar15;
  undefined *puVar19;
  uint uVar18;
  short sVar20;
  longlong lVar16;
  longlong lVar17;
  short sVar21;
  undefined2 auStack_38 [15];
  ushort uStack_1a;
  undefined2 uStack_16;
  undefined2 uStack_14;
  undefined uStack_11;
  undefined auStack_10 [12];
  
  puVar19 = auStack_10;
  cVar10 = (char)(code >> 8);
  bVar4 = (byte)pos;
  if ((bVar4 < 0xc0) &&
     (bVar5 = (byte)((ushort)pos >> 8),
     (byte)(SBORROW1(bVar5,'@') ^ (char)(bVar5 - 0x40) < '\0') == 1)) {
    uStack_14 = 0xe3d3;
    if (draw_target == '\0') {
      uStack_14 = 0xe9d3;
    }
    uStack_11 = 0x18;
    if ((cVar10 == -0xf) || (cVar10 == -0xe)) {
      bVar12 = cur_line - 1;
      uVar11 = 0x40c;
    }
    else {
      bVar12 = cur_line;
      if (cur_line == 0xe) {
        uVar11 = 0x50b;
      }
      else {
        uVar11 = 0x206;
      }
    }
    uStack_1a = (ushort)(byte)(bVar12 - 1);
    uStack_16 = uVar11;
    if (cur_line < 0xb) {
      puVar19 = auStack_10;
      puVar6 = (undefined2 *)glyph_get_large(code,(byte *)auStack_38);
    }
    else {
      puVar6 = glyph_get_small(code,auStack_38);
    }
    *(undefined2 **)((short)puVar19 - 0xc) = puVar6;
    uVar18 = ZEXT24(puVar19);
    bVar5 = calc_px_ptr(bVar4,bVar5,(undefined2 *)((short)puVar19 - 8));
    lVar17 = (ulonglong)
             CONCAT61(CONCAT42(uVar18,*(undefined2 *)((short)(uVar18 >> 0x10) + -8)),bVar5) << 8;
    bVar13 = *(byte *)(bVar5 + 0x33bc);
    bVar5 = (byte)((ushort)uVar11 >> 8);
    bVar12 = *(byte *)(((char)uVar11 + bVar4 & 7) + 0x33c4);
    bVar4 = 1;
    if (10 < cur_line) {
      bVar4 = 2;
      bVar5 = 0xff;
    }
    do {
      uVar2 = (undefined7)((ulonglong)lVar17 >> 8);
      bVar14 = (byte)((ulonglong)lVar17 >> 8);
      puVar3 = (ushort *)((ulonglong)lVar17 >> 0x20);
      pbVar7 = (byte *)((ulonglong)lVar17 >> 0x10);
      sVar21 = (short)((ulonglong)lVar17 >> 0x30);
      if (bVar4 == 1) {
        if (bVar14 == 0) {
          px_or_run(pbVar7,(byte *)puVar3,bVar12);
        }
        else {
          bVar8 = ('\b' - *(char *)(sVar21 + -6)) - bVar14;
          if ('\0' < (char)bVar8) {
            bVar13 = bVar13 & -1 << (bVar8 & 7);
          }
          bVar14 = *(byte *)puVar3 >> (bVar14 & 7) & bVar13;
          lVar16 = CONCAT71(uVar2,bVar14);
          *(byte *)(sVar21 + -2) = bVar14;
          px_or_run(pbVar7,(byte *)(sVar21 + -2),bVar13);
          sVar21 = (short)((ulonglong)lVar16 >> 0x30);
          bVar14 = (byte)((ulonglong)lVar16 >> 8);
          lVar17 = lVar16;
          if ((byte)(*(char *)(sVar21 + -5) + 1U) <= bVar14) {
            bVar14 = *(char *)((ulonglong)lVar16 >> 0x20) << (8 - bVar14 & 7) & bVar12;
            lVar17 = CONCAT71((int7)((ulonglong)lVar16 >> 8),bVar14);
            *(byte *)(sVar21 + -2) = bVar14;
            px_or_run((byte *)((short)((ulonglong)lVar16 >> 0x10) + 1),(byte *)(sVar21 + -2), (uintptr_t)0)
                           bVar12);
          }
        }
      }
      else {
        uVar9 = *puVar3;
        lVar17 = CONCAT71(uVar2,(char)((uVar9 & 0xff00) + (uVar9 & 0xff) >> (bVar14 & 7)));
        *(byte *)(sVar21 + -2) = (byte)(uVar9 >> 8) >> (bVar14 & 7);
        px_or_run(pbVar7,(byte *)(sVar21 + -2),bVar13);
        sVar20 = (short)((ulonglong)lVar17 >> 0x30);
        sVar21 = (short)((ulonglong)lVar17 >> 0x10);
        if ((char)(((byte)((ulonglong)lVar17 >> 8) < (byte)(*(char *)(sVar20 + -5) + 1U)) << 7) <
            '\0') {
          *(char *)(sVar20 + -2) = (char)lVar17;
          pbVar7 = (byte *)(sVar21 + 1);
        }
        else {
          *(char *)(sVar20 + -2) = (char)lVar17;
          px_or_run((byte *)(sVar21 + 1),(byte *)(sVar20 + -2),bVar5);
          *(char *)((short)((ulonglong)lVar17 >> 0x30) + -2) =
               (char)*(undefined2 *)((ulonglong)lVar17 >> 0x20) <<
               (8U - (char)((ulonglong)lVar17 >> 8) & 7);
          pbVar7 = (byte *)((short)((ulonglong)lVar17 >> 0x10) + 2);
        }
        px_or_run(pbVar7,(byte *)((short)((ulonglong)lVar17 >> 0x30) + -2),bVar12);
      }
      sVar21 = (short)((ulonglong)lVar17 >> 0x30);
      bVar14 = (byte)((ulonglong)lVar17 >> 0x10);
      uVar1 = CONCAT13((char)((ulonglong)lVar17 >> 0x18) -
                       ((char)(CARRY1(bVar14,*(byte *)(sVar21 + -1)) << 7) >> 7),
                       CONCAT12(bVar14 + *(byte *)(sVar21 + -1),(short)lVar17));
      if (*(ushort *)(sVar21 + -4) < (ushort)((uint)uVar1 >> 0x10)) {
        return 0;
      }
      bVar14 = (byte)((ulonglong)lVar17 >> 0x20);
      uVar15 = CONCAT15((char)((ulonglong)lVar17 >> 0x28) - ((char)(CARRY1(bVar14,bVar4) << 7) >> 7)
                        ,CONCAT14(bVar14 + bVar4,uVar1));
      bVar14 = (byte)*(undefined2 *)(sVar21 + -10);
      bVar8 = (char)((ushort)*(undefined2 *)(sVar21 + -10) >> 8) + 1;
      *(ushort *)(sVar21 + -10) = CONCAT11(bVar8,bVar14);
      if (bVar8 == bVar14) {
        uVar15 = CONCAT15(0xb,CONCAT14(0x8a,uVar1));
      }
      lVar17 = CONCAT26(sVar21,uVar15);
    } while (bVar8 <= bVar14);
  }
  return 0;
}

/**
 * @brief 以 0 为参数调用 0x849C（字形查表，对应字符码 0）
 * @addr 0x08482
 * @module display
 * @proto void char_print_zero(undefined* p)
 * @confidence likely
 * @note 以 0 为参数调用 0x849C（字形查表，对应字符码 0）。
 * @tag display
 */
int char_print_zero(undefined* p)

{
  px_write(p,'\0');
  return 0;
}

/**
 * @brief 画白点（清像素）
 * @addr 0x08486
 * @module display
 * @proto void px_clear(ushort pos)
 * @confidence verified
 * @note 画白点（清像素）。缓冲由 0xD139 选 0xE3D4/0xDDD4。
 * @tag gfx
 */
int px_clear(ushort pos)

{
  undefined *puVar1;
  
  if (((byte)pos < 0xc0) && (pos < 0x4000)) {
    if (draw_target == '\0') {
      puVar1 = (undefined *)0xe3d4;
    }
    else {
      puVar1 = &screen_fb;
    }
    puVar1[(pos >> 8) * 0x18 + (pos >> 3 & 0x1f)] =
         puVar1[(pos >> 8) * 0x18 + (pos >> 3 & 0x1f)] &
         (0x80U >> ((byte)pos & 7) ^ 0xff);
  }
  return 0;
}

/**
 * @brief 画黑点（置像素）
 * @addr 0x0848A
 * @module display
 * @proto void px_set(ushort pos)
 * @confidence verified
 * @note 画黑点（置像素）。
 * @tag gfx
 */
int px_set(ushort pos)

{
  undefined *puVar1;
  
  if (((byte)pos < 0xc0) && (pos < 0x4000)) {
    if (draw_target == '\0') {
      puVar1 = (undefined *)0xe3d4;
    }
    else {
      puVar1 = &screen_fb;
    }
    puVar1[(pos >> 8) * 0x18 + (pos >> 3 & 0x1f)] =
         puVar1[(pos >> 8) * 0x18 + (pos >> 3 & 0x1f)] | 0x80U >> ((byte)pos & 7);
  }
  return 0;
}

/**
 * @brief 像素写
 * @addr 0x0849C
 * @module display
 * @proto void px_write(ushort pos, char clear)
 * @confidence verified
 * @note 像素写：pos 高字节 = 行号，低字节为列位；clear=0 置黑、非 0 置白。原记录称
 *       set_display_position，实际是像素操作。
 * @tag gfx
 */
int px_write(ushort pos, char clear)

{
  byte bVar1;
  undefined *puVar2;
  byte bVar3;
  
  bVar3 = 0x80 >> ((byte)pos & 7);
  if (draw_target == '\0') {
    puVar2 = (undefined *)0xe3d4;
  }
  else {
    puVar2 = &screen_fb;
  }
  bVar1 = puVar2[(pos >> 8) * 0x18 + (pos >> 3 & 0x1f)];
  if (clear == '\0') {
    bVar1 = bVar1 | bVar3;
  }
  else {
    bVar1 = bVar1 & (bVar3 ^ 0xff);
  }
  puVar2[(pos >> 8) * 0x18 + (pos >> 3 & 0x1f)] = bVar1;
  return 0;
}



// 获取字符数据（14像素宽）(glyph_get_small)
// 地址: 0x84D8
// pos: 字符编码
// clear: 输出缓冲区指针
// 返回: 更新后的缓冲区指针

/**
 * @brief 取单字节字符的 14 宽小号点阵
 * @addr 0x084D8
 * @module display
 * @proto ushort* glyph_get_small(ushort code, ushort* buf)
 * @confidence verified
 * @note 取单字节字符的 14 宽小号点阵：用 0xB8A 页指针表定位字形，把竖排字节转为横排位图写入 buf；字符 |(0x7C)
 *       或首字节为 0 时填充 0xE000。
 * @tag font
 */
ushort* glyph_get_small(ushort code, ushort* buf)

{
  byte bVar1;
  ushort uVar2;
  ushort *puVar3;
  byte bVar4;
  byte bVar5;
  undefined2 *puVar6;
  short sVar7;
  byte bVar8;
  uint uVar9;
  byte bVar13;
  byte bVar14;
  byte bVar16;
  char cVar17;
  undefined7 uVar12;
  ulonglong uVar10;
  undefined8 uVar11;
  short sVar18;
  undefined2 uVar15;
  
  bVar13 = (byte)(code >> 8);
  sVar18 = 0xb8a;
  uVar12 = (undefined7)(((ulonglong)bVar13 << 0x20) >> 8);
  if ((bVar13 == 0) ||
     ((bVar5 = (bVar13 & 0xf) * '\x02',
      sVar18 = *(short *)CONCAT11((0x25 < bVar5) + '3',bVar5 - 0x26), bVar13 != 0xf1 &&
      (bVar13 != 0xf2)))) {
    uVar10 = CONCAT71(uVar12,0xd);
  }
  else {
    uVar10 = CONCAT71(uVar12,0xc);
  }
  cVar17 = (char)(uVar10 >> 0x20);
  bVar13 = (byte)uVar10;
  if ((cVar17 == '\0') && ((char)code == '|')) {
    uVar10 = uVar10 & 0xff;
    puVar6 = buf;
    do {
      *puVar6 = 0xe000;
      puVar6 = puVar6 + 1;
      bVar13 = (char)uVar10 - 1;
      uVar10 = (ulonglong)bVar13;
    } while (bVar13 != 0);
  }
  else {
    if ((cVar17 == -0xf) || (cVar17 == -0xe)) {
      sVar7 = 0xb;
    }
    else {
      sVar7 = 10;
    }
    uVar2 = ((code & 0xff) - 0x10 & 0xff) * sVar7;
    bVar5 = (byte)(uVar2 % 0x10);
    puVar3 = (ushort *)((uVar2 / 0x10) * (ushort)bVar13 * 2 + sVar18);
    puVar6 = buf;
    uVar11 = CONCAT62((int6)(uVar10 >> 0x10),(ushort)(byte)(bVar13 << 1));
    do {
      sVar18 = (short)uVar11;
      uVar2 = *puVar3;
      puVar3 = puVar3 + 1;
      if (7 < bVar5) {
        uVar2 = uVar2 << 8;
      }
      bVar4 = (byte)(((uVar2 & 0xff00) + (uVar2 & 0xff) << (bVar5 & 7)) >> 8);
      bVar1 = (char)uVar2 << (bVar5 & 7);
      uVar2 = CONCAT11(bVar4,bVar1);
      uVar15 = *(undefined2 *)((short)puVar3 + sVar18 + -2);
      uVar9 = CONCAT22(uVar15,sVar18);
      bVar8 = 0x10 - bVar5;
      if (7 < bVar8) {
        uVar9 = (uint)CONCAT12((char)((ushort)uVar15 >> 8),sVar18);
      }
      bVar16 = (byte)(uVar9 >> 0x18);
      bVar14 = (byte)((ushort)bVar16 * 0x100 + (ushort)(byte)(uVar9 >> 0x10) >> (bVar8 & 7));
      bVar16 = bVar16 >> (bVar8 & 7);
      if (bVar5 != 0) {
        uVar2 = CONCAT11(bVar4 | bVar16,bVar1 | bVar14);
      }
      cVar17 = (char)((ulonglong)uVar11 >> 0x20);
      if ((cVar17 == -0xf) || (cVar17 == -0xe)) {
        uVar2 = uVar2 & 0xffe0;
      }
      else {
        uVar2 = uVar2 & 0xffc0;
      }
      *puVar6 = CONCAT11((byte)(uVar2 >> 9),(char)((uVar2 & 0xff00) + (uVar2 & 0xff) >> 1));
      puVar6 = puVar6 + 1;
      *(char *)puVar3 = *(char *)puVar3 + '\x01';
      bVar13 = bVar13 - 1;
      uVar11 = CONCAT44((int)((ulonglong)uVar11 >> 0x20),
                        CONCAT13(bVar16,CONCAT12(bVar14,(short)uVar9)));
    } while (bVar13 != 0);
  }
  return buf;
}



// 获取字符数据（大字符）(glyph_get_large)
// 地址: 0x85B8
// code: 字符编码
// buf: 输出缓冲区指针
// 返回: 更新后的缓冲区指针

/**
 * @brief 取大号（5 位/像素压缩）点阵
 * @addr 0x085B8
 * @module display
 * @proto byte* glyph_get_large(ushort code, byte* buf)
 * @confidence verified
 * @note 取大号（5 位/像素压缩）点阵：0x3DE6/0x3BA 页指针表，按 0xD137 是否为 8 选择字号。
 * @tag font
 */
byte* glyph_get_large(ushort code, byte* buf)

{
  char cVar1;
  byte bVar4;
  ushort uVar2;
  char *pcVar3;
  byte bVar5;
  byte *pbVar6;
  sbyte sVar7;
  char cVar8;
  ushort uVar9;
  short sVar10;
  
  bVar4 = (byte)((ushort)code >> 8);
  if (cur_line == '\b') {
    sVar10 = 0x3ba;
    uVar9 = CONCAT11(bVar4,7);
  }
  else {
    sVar10 = 0x3de6;
    if (bVar4 != 0) {
      bVar5 = (bVar4 & 0xf) * '\x02';
      sVar10 = *(short *)CONCAT11((7 < bVar5) + '3',bVar5 - 8);
    }
    uVar9 = CONCAT11(bVar4,9);
  }
  cVar8 = (char)uVar9;
  if (((char)(uVar9 >> 8) == '\0') && (pbVar6 = buf, (char)code == '|')) {
    do {
      *pbVar6 = 0xe0;
      bVar4 = (char)uVar9 - 1;
      uVar9 = (ushort)bVar4;
      pbVar6 = pbVar6 + 1;
    } while (bVar4 != 0);
  }
  else {
    uVar2 = (ushort)(byte)((char)(uintptr_t)code - 0x10) * 5;
    sVar7 = (sbyte)(uVar2 % 8);
    pcVar3 = (char *)((uVar2 / 8) * (uVar9 & 0xff) + sVar10);
    pbVar6 = buf;
    do {
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
      bVar4 = (byte)(cVar1 << sVar7) >> 1;
      if ((byte)(8U - sVar7) < 5) {
        uVar9 = uVar9 & 0xff;
        bVar4 = bVar4 | (byte)pcVar3[uVar9 - 1] >> (9U - sVar7 & 7);
      }
      *pbVar6 = bVar4 & 0x7c;
      pbVar6 = pbVar6 + 1;
      cVar8 = cVar8 + -1;
    } while (cVar8 != '\0');
  }
  return buf;
}

/**
 * @brief 帧缓冲位写
 * @addr 0x08660
 * @module display
 * @proto void fb_write_op(ushort mask, byte* dst)
 * @confidence strong
 * @note 帧缓冲位写：按 0xD138 模式（0/4/其它）把 mask 与 dst 位合并写入。
 * @tag display
 */
int fb_write_op(ushort mask, byte* dst)

{
  byte bVar1;
  byte bVar2;
  
  if ((byte *)0xddeb < dst) {
    if (dst != (byte *)0xddeb) {
      bVar1 = (byte)((ushort)mask >> 8);
      mask = CONCAT11(bVar1,(byte)mask & bVar1);
    }
    bVar1 = (byte)mask;
    bVar2 = (byte)((ushort)mask >> 8);
    if (cursor_visible == '\0') {
      *dst = (bVar2 ^ 0xff) & *dst | bVar1;
    }
    else if (cursor_visible == '\x04') {
      *dst = (bVar1 ^ 0xff) & bVar2 | (bVar2 ^ 0xff) & *dst;
    }
    else if (cursor_visible == '\x01') {
      *dst = *dst | bVar1;
    }
    else if (cursor_visible == '\x02') {
      *dst = (bVar2 ^ 0xff | bVar1) & *dst;
    }
    else {
      *dst = *dst ^ bVar1;
    }
  }
  return 0;
}

/**
 * @brief 把 src 指定位区间按 mask 按位或入 dst（字符点阵拼接的基础操作）
 * @addr 0x08672
 * @module display
 * @proto void px_or_run(byte* src, byte* dst, byte mask)
 * @confidence strong
 * @note 把 src 指定位区间按 mask 按位或入 dst（字符点阵拼接的基础操作）。
 * @tag gfx
 */
int px_or_run(byte* src, byte* dst, byte mask)

{
  byte bVar1;
  
  if ((byte *)0xddeb < src) {
    bVar1 = *dst;
    if (mask != 0) {
      bVar1 = bVar1 & mask;
    }
    if (cursor_visible == '\0') {
      *src = (mask ^ 0xff) & *src | bVar1;
    }
    else if (cursor_visible == '\x04') {
      *src = (bVar1 ^ 0xff) & mask | (mask ^ 0xff) & *src;
    }
    else if (cursor_visible == '\x01') {
      *src = *src | bVar1;
    }
    else if (cursor_visible == '\x02') {
      *src = (mask ^ 0xff | bVar1) & *src;
    }
    else {
      *src = *src ^ bVar1;
    }
  }
  return 0;
}

