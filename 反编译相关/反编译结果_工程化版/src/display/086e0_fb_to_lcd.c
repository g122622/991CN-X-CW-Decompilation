/*
 * 显示驱动 / 086e0_fb_to_lcd.c
 * 地址范围: 0x086E0 - 0x08CEE
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 主缓冲 0xDDD4 复制 0x600 字节到 LCD 显存 0xF800（memcpy_b…
 * @addr 0x086E0
 * @module display
 * @proto void fb_to_lcd(void)
 * @confidence verified
 * @note 主缓冲 0xDDD4 复制 0x600 字节到 LCD 显存 0xF800（memcpy_bytes）。
 * @tag gfx
 */
int fb_to_lcd(void)

{
  undefined2 uVar1;
  
  uVar1 = 0x600;
  memcpy_bytes((undefined *)0xe3d4,&screen_fb,0x600);
  return uVar1;
}

/**
 * @brief 把 0xE3D4 子缓冲按 24→32 字节/行扩展渲染到 LCD 显存 0xF800（64…
 * @addr 0x086F8
 * @module display
 * @proto void fb_alt_flush(void)
 * @confidence verified
 * @note 把 0xE3D4 子缓冲按 24→32 字节/行扩展渲染到 LCD 显存 0xF800（64 行），再请求刷新。原记录称
 *       render_e3d4。
 * @tag gfx
 */
int fb_alt_flush(void)

{
  undefined4 uVar1;
  char cVar2;
  undefined2 *puVar3;
  undefined8 uVar4;
  undefined4 *puStack_12;
  
  puStack_12 = (undefined4 *)0xe3d4;
  puVar3 = (undefined2 *)&lcd_vram;
  cVar2 = '@';
  do {
    uVar1 = *puStack_12;
    uVar4 = *(undefined8 *)(puStack_12 + 1);
    puVar3[1] = (short)((uint)uVar1 >> 0x10);
    *puVar3 = (short)uVar1;
    *(undefined8 *)(puVar3 + 2) = uVar4;
    uVar1 = puStack_12[3];
    uVar4 = *(undefined8 *)(puStack_12 + 4);
    puStack_12 = puStack_12 + 6;
    puVar3[7] = (short)((uint)uVar1 >> 0x10);
    puVar3[6] = (short)uVar1;
    *(undefined8 *)(puVar3 + 8) = uVar4;
    puVar3 = puVar3 + 0x10;
    cVar2 = cVar2 + -1;
  } while (cVar2 != '\0');
  lcd_request_refresh();
  return 0;
}

/**
 * @brief 把主缓冲 0xDDD4 按 24→32 字节/行扩展渲染到 LCD 显存 0xF800，再请…
 * @addr 0x08704
 * @module display
 * @proto void fb_flush(void)
 * @confidence verified
 * @note 把主缓冲 0xDDD4 按 24→32 字节/行扩展渲染到 LCD 显存 0xF800，再请求刷新。
 * @tag gfx
 */
int fb_flush(void)

{
  undefined4 uVar1;
  char cVar2;
  undefined2 *puVar3;
  undefined8 uVar4;
  undefined4 *puStack_12;
  
  puStack_12 = (undefined4 *)&screen_fb;
  puVar3 = (undefined2 *)&lcd_vram;
  cVar2 = '@';
  do {
    uVar1 = *puStack_12;
    uVar4 = *(undefined8 *)(puStack_12 + 1);
    puVar3[1] = (short)((uint)uVar1 >> 0x10);
    *puVar3 = (short)uVar1;
    *(undefined8 *)(puVar3 + 2) = uVar4;
    uVar1 = puStack_12[3];
    uVar4 = *(undefined8 *)(puStack_12 + 4);
    puStack_12 = puStack_12 + 6;
    puVar3[7] = (short)((uint)uVar1 >> 0x10);
    puVar3[6] = (short)uVar1;
    *(undefined8 *)(puVar3 + 8) = uVar4;
    puVar3 = puVar3 + 0x10;
    cVar2 = cVar2 + -1;
  } while (cVar2 != '\0');
  lcd_request_refresh();
  return 0;
}

/**
 * @brief 由 (行 y, 列 x) 算出 0xE3D4 区显存指针写入 *out，返回水平位偏移 x&…
 * @addr 0x08746
 * @module display
 * @proto byte calc_fb_ptr(byte x, byte y, short* out)
 * @confidence strong
 * @note 由 (行 y, 列 x) 算出 0xE3D4 区显存指针写入 *out，返回水平位偏移 x&7。
 * @tag gfx
 */
byte calc_fb_ptr(byte x, byte y, short* out)

{
  char cVar1;
  short sVar2;
  
  if ((y & 0x80) == 0) {
    sVar2 = (ushort)y * 0x20 + -0x800;
  }
  else {
    cVar1 = (char)((ushort)(byte)-y * 0x20);
    sVar2 = CONCAT11((-8 - (char)((ushort)(byte)-y * 0x20 >> 8)) - (cVar1 != '\0'),-cVar1);
  }
  *out = sVar2 + (ushort)(x >> 3);
  return x & 7;
}

/**
 * @brief 由屏幕坐标算像素地址（按 0xD139 选 0xDDD4/0xE3D4 缓冲），返回位偏移
 * @addr 0x08750
 * @module display
 * @proto byte calc_px_ptr(byte x, byte y, ushort* out)
 * @confidence verified
 * @note 由屏幕坐标算像素地址（按 0xD139 选 0xDDD4/0xE3D4 缓冲），返回位偏移。
 * @tag gfx
 */
byte calc_px_ptr(byte x, byte y, ushort* out)

{
  byte bVar1;
  undefined *puVar2;
  
  puVar2 = &screen_fb;
  if (draw_target == '\0') {
    puVar2 = (undefined *)0xe3d4;
  }
  if ((y & 0x80) == 0) {
    puVar2 = puVar2 + (ushort)y * 0x18;
  }
  else {
    bVar1 = (byte)((ushort)(byte)-y * 0x18);
    puVar2 = (undefined *)
             CONCAT11(((char)((ushort)puVar2 >> 8) - (char)((ushort)(byte)-y * 0x18 >> 8)) -
                      ((byte)puVar2 < bVar1),(byte)puVar2 - bVar1);
  }
  *out = puVar2 + (x >> 3);
  return x & 7;
}

/**
 * @brief 按 0xD110 的标志位初始化状态栏（F800/F802）位
 * @addr 0x08786
 * @module display
 * @proto void status_bits_init(void)
 * @confidence strong
 * @note 按 0xD110
 *       的标志位初始化状态栏（F800/F802）位：S/A/M/STO/MATH/D/R/G/FIX/SCI/E/复角等。
 * @tag gfx
 */
int status_bits_init(void)

{
  bool bVar1;
  
  _DAT_ram_f802 = 0;
  bVar1 = (status_bits & 8) != 0;
  memcpy_sym(lcd_vram, (ushort)bVar1, sizeof lcd_vram);
  if ((status_bits & 4) != 0) {
    memcpy_sym(lcd_vram, CONCAT11(1,bVar1), sizeof lcd_vram);
  }
  if ((status_bits & 1) != 0) {
    _DAT_ram_f802 = 0x100;
  }
  return 0;
}

/**
 * @brief 按 0xD110/0xD111/0xD112/0xD11A..0xD11D 的组合点亮状态栏…
 * @addr 0x087B2
 * @module display
 * @proto void status_bits_draw(void)
 * @confidence strong
 * @note 按 0xD110/0xD111/0xD112/0xD11A..0xD11D
 *       的组合点亮状态栏图标（Angle/Fix/Sci/Rnd 等）。
 * @tag gfx
 */
int status_bits_draw(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  
  uVar2 = 0x18;
  memzero(&screen_fb,0x18);
  if ((status_bits & 8) != 0) {
    memcpy_sym(screen_fb, screen_fb | 1, sizeof screen_fb);
  }
  if ((status_bits & 4) != 0) {
    _DAT_ram_ddd5 = _DAT_ram_ddd5 | 1;
  }
  if ((status_bits & 1) != 0) {
    _DAT_ram_ddd7 = _DAT_ram_ddd7 | 1;
  }
  uVar1 = dec_cmp((undefined2 *)0xd31a,uVar2);
  if ((char)uVar1 != '\x01') {
    _DAT_ram_ddd6 = _DAT_ram_ddd6 | 1;
  }
  if ((calc_mode == 0xc4) &&
     (uVar2 = dec_cmp((undefined2 *)0xd612,uVar2), (char)uVar2 != '\x01')) {
    _DAT_ram_ddd6 = _DAT_ram_ddd6 | 1;
  }
  if (calc_mode != 2) {
    if (menu_sel_b == '\x04') {
      _DAT_ram_ddda = _DAT_ram_ddda | 1;
    }
    if (menu_sel_b == '\x05') {
      _DAT_ram_dddb = _DAT_ram_dddb | 1;
    }
    if (menu_sel_b == '\x06') {
      _DAT_ram_dddc = _DAT_ram_dddc | 1;
    }
    if (menu_sel_a == '\b') {
      _DAT_ram_dddd = _DAT_ram_dddd | 1;
    }
    if (menu_sel_a == '\t') {
      _DAT_ram_ddde = _DAT_ram_ddde | 1;
    }
  }
  if ((menu_io != '\0') && ((calc_mode & 0xc0) != 0)) {
    _DAT_ram_ddd9 = _DAT_ram_ddd9 | 1;
  }
  if ((menu_state_b != '\0') && (calc_mode == 0xc1)) {
    _DAT_ram_dde3 = _DAT_ram_dde3 | 1;
  }
  if (((calc_mode != 2) && (calc_mode != 0x89)) && (menu_state_e != '\0')) {
    _DAT_ram_dddf = _DAT_ram_dddf | 1;
  }
  if ((calc_mode == 0xc4) ||
     (((calc_mode == 0x45 && (3 < sub_mode)) && (key_state_a != '\0')))) {
    if (_DAT_ram_d120 == '\0') {
      _DAT_ram_dde1 = _DAT_ram_dde1 | 1;
    }
    else {
      _DAT_ram_dde0 = _DAT_ram_dde0 | 1;
    }
  }
  if ((key_modifiers & 0x40) != 0) {
    _DAT_ram_dde9 = _DAT_ram_dde9 | 1;
  }
  if ((key_modifiers & 0x80) == 0) {
    if ((kbd_repeat & 1) != 0) {
      _DAT_ram_dde6 = _DAT_ram_dde6 | 1;
    }
    if ((kbd_repeat & 2) != 0) {
      _DAT_ram_dde5 = _DAT_ram_dde5 | 1;
    }
    if ((kbd_repeat & 4) != 0) {
      _DAT_ram_dde4 = _DAT_ram_dde4 | 1;
    }
    if ((kbd_repeat & 8) != 0) {
      _DAT_ram_dde7 = _DAT_ram_dde7 | 1;
    }
  }
  memcpy_bytes(&lcd_vram,&screen_fb,0x18);
  lcd_request_refresh();
  return 0;
}

/**
 * @brief 绘制菜单/对话框边框（调用各角与边），style 选择圆角/直角/虚线
 * @addr 0x088F0
 * @module display
 * @proto void draw_frame(ushort pos, short w, byte style, byte top)
 * @confidence likely
 * @note 绘制菜单/对话框边框（调用各角与边），style 选择圆角/直角/虚线。
 * @tag gfx
 */
int draw_frame(ushort pos, short w, byte _a1, byte _a2, int _a5)

{
  char cVar1;
  short sVar2;
  undefined2 *puVar3;
  undefined2 uVar4;
  undefined extraout_R1;
  undefined unaff_R4;
  char cVar7;
  char cVar8;
  char cVar9;
  undefined8 in_QR8;
  undefined8 uVar5;
  undefined8 uVar6;
  
  uVar5 = CONCAT53((int5)(CONCAT26(pos,(int6)CONCAT62((int6)((ulonglong)in_QR8 >> 0x10),_a5
                                                         )) >> 0x18),CONCAT12(1,_a5));
  cur_line = unaff_R4;
  do {
    uVar5 = CONCAT35((int3)((ulonglong)uVar5 >> 0x28),
                     CONCAT14((char)((ulonglong)uVar5 >> 0x38),CONCAT13(1,(int3)uVar5)));
    do {
      uVar6 = uVar5;
      cVar1 = (char)((ulonglong)uVar6 >> 0x10);
      sVar2 = (ushort)(byte)(cVar1 - 1) * 4;
      cVar7 = (char)((ulonglong)uVar6 >> 0x18);
      puVar3 = *(undefined2 **)
                (CONCAT11((char)((ushort)sVar2 >> 8),((char)sVar2 + cVar7 + -1) * '\x02') +
                (short)uVar6);
      cVar8 = (short)((ulonglong)uVar6 >> 0x10) == w;
      cVar9 = (char)((ulonglong)uVar6 >> 0x28);
      if (cVar9 == '\0') {
LAB_rom_008930:
        uVar4 = frame_corner_1(cVar1,cVar7);
      }
      else if (cVar9 == '\x01') {
        uVar4 = frame_corner_2(cVar1,cVar7);
      }
      else if (cVar9 == '\x02') {
        uVar4 = frame_corner_3(cVar1,cVar7);
      }
      else {
        if (cVar9 != '\x03') goto LAB_rom_008930;
        cVar1 = frame_corner_4(cVar7);
        uVar4 = CONCAT11(extraout_R1,cVar1);
      }
      draw_label(puVar3,uVar4,cVar8);
      cVar8 = (char)((ulonglong)uVar6 >> 0x20) + -1;
      uVar5 = CONCAT35((int3)((ulonglong)uVar6 >> 0x28),
                       CONCAT14(cVar8,CONCAT13((char)((ulonglong)uVar6 >> 0x18) + '\x01',(int3)uVar6
                                              )));
    } while (cVar8 != '\0');
    cVar8 = (char)((ulonglong)uVar6 >> 0x30) + -1;
    uVar5 = CONCAT17((char)((ulonglong)uVar6 >> 0x38),
                     CONCAT16(cVar8,(int6)CONCAT53((int5)((ulonglong)uVar5 >> 0x18),
                                                   CONCAT12((char)((ulonglong)uVar6 >> 0x10) +
                                                            '\x01',(short)uVar6))));
    if (cVar8 == '\0') {
      return 0;
    }
  } while( true );
}

/**
 * @brief 边框边绘制（方向 A）
 * @addr 0x08966
 * @module display
 * @proto void draw_frame_edge_a(ushort pos, short w, ushort s)
 * @confidence likely
 * @note 边框边绘制（方向 A）。
 * @tag gfx
 */
int draw_frame_edge_a(ushort pos, short w, ushort s)

{
  undefined unaff_R4;
  undefined unaff_R6;
  undefined5 in_QR8;
  undefined unaff_R14;
  undefined3 unaff_retaddr;
  
  draw_frame(pos,w,(char)in_QR8,(char)((uint5)in_QR8 >> 0x10), (uintptr_t)0, (uintptr_t)0, (uintptr_t)0, (uintptr_t)0, (uintptr_t)0, (uintptr_t)0, (uintptr_t)0)
                 (char)((uint5)in_QR8 >> 0x20),unaff_R14,unaff_R4,unaff_R6,(char)unaff_retaddr,
                 (char)((uint3)unaff_retaddr >> 0x10),s);
  return 0;
}

/**
 * @brief 边框边绘制（方向 B）
 * @addr 0x08972
 * @module display
 * @proto void draw_frame_edge_b(ushort pos, short w, ushort s)
 * @confidence likely
 * @note 边框边绘制（方向 B）。
 * @tag gfx
 */
int draw_frame_edge_b(ushort pos, short w, ushort s)

{
  undefined unaff_R4;
  undefined unaff_R6;
  undefined5 in_QR8;
  undefined unaff_R14;
  undefined3 unaff_retaddr;
  
  draw_frame(pos,w,(char)in_QR8,(char)((uint5)in_QR8 >> 0x10), (uintptr_t)0, (uintptr_t)0, (uintptr_t)0, (uintptr_t)0, (uintptr_t)0, (uintptr_t)0, (uintptr_t)0)
                 (char)((uint5)in_QR8 >> 0x20),unaff_R14,unaff_R4,unaff_R6,(char)unaff_retaddr,
                 (char)((uint3)unaff_retaddr >> 0x10),s);
  return 0;
}

/**
 * @brief 边框边绘制（方向 C）
 * @addr 0x0897E
 * @module display
 * @proto void draw_frame_edge_c(ushort pos, short w, ushort s)
 * @confidence likely
 * @note 边框边绘制（方向 C）。
 * @tag gfx
 */
int draw_frame_edge_c(ushort pos, short w, ushort s)

{
  undefined unaff_R4;
  undefined unaff_R6;
  undefined5 in_QR8;
  undefined unaff_R14;
  undefined3 unaff_retaddr;
  
  draw_frame(pos,w,(char)in_QR8,(char)((uint5)in_QR8 >> 0x10), (uintptr_t)0, (uintptr_t)0, (uintptr_t)0, (uintptr_t)0, (uintptr_t)0, (uintptr_t)0, (uintptr_t)0)
                 (char)((uint5)in_QR8 >> 0x20),unaff_R14,unaff_R4,unaff_R6,(char)unaff_retaddr,
                 (char)((uint3)unaff_retaddr >> 0x10),s);
  return 0;
}

/**
 * @brief 边框边绘制（方向 D）
 * @addr 0x0898A
 * @module display
 * @proto void draw_frame_edge_d(ushort pos, short w, ushort s)
 * @confidence likely
 * @note 边框边绘制（方向 D）。
 * @tag gfx
 */
int draw_frame_edge_d(ushort pos, short w, ushort s)

{
  undefined unaff_R4;
  undefined unaff_R6;
  undefined5 in_QR8;
  undefined unaff_R14;
  undefined3 unaff_retaddr;
  
  draw_frame(pos,w,(char)in_QR8,(char)((uint5)in_QR8 >> 0x10), (uintptr_t)0, (uintptr_t)0, (uintptr_t)0, (uintptr_t)0, (uintptr_t)0, (uintptr_t)0, (uintptr_t)0)
                 (char)((uint5)in_QR8 >> 0x20),unaff_R14,unaff_R4,unaff_R6,(char)unaff_retaddr,
                 (char)((uint3)unaff_retaddr >> 0x10),s);
  return 0;
}

/**
 * @brief 边框角图案 1
 * @addr 0x08996
 * @module display
 * @proto ushort frame_corner_1(char x, char y)
 * @confidence likely
 * @note 边框角图案 1。
 * @tag gfx
 */
ushort frame_corner_1(char x, char y)

{
  return CONCAT11((x + -1) * '\n' + '\v',(y + -1) * '*' + '\x16');
}

/**
 * @brief 边框角图案 2
 * @addr 0x089BC
 * @module display
 * @proto ushort frame_corner_2(char x, char y)
 * @confidence likely
 * @note 边框角图案 2。
 * @tag gfx
 */
ushort frame_corner_2(char x, char y)

{
  return CONCAT11((x + -1) * '\f' + '\x03',(y + -1) * '>' + '\x0f');
}

/**
 * @brief 边框角图案 3
 * @addr 0x089E2
 * @module display
 * @proto ushort frame_corner_3(char x, char y)
 * @confidence likely
 * @note 边框角图案 3。
 * @tag gfx
 */
ushort frame_corner_3(char x, char y)

{
  return CONCAT11((x + -1) * '\f' + '\x0f',(y + -1) * '>' + '\x0f');
}

/**
 * @brief 边框角图案 4
 * @addr 0x08A08
 * @module display
 * @proto char frame_corner_4(char x)
 * @confidence likely
 * @note 边框角图案 4。
 * @tag gfx
 */
char frame_corner_4(char x)

{
  char cVar1;
  char cVar2;
  
  cVar2 = (x + -1) * '*';
  cVar1 = cVar2 + '\t';
  if ((char)(x + -1) == '\x02') {
    if (sub_mode == '\x02') {
      cVar1 = cVar2 + '\x15';
    }
    else {
      cVar1 = cVar2 + '?';
    }
  }
  return cVar1;
}

/**
 * @brief 绘制带数字的标签（如菜单项序号）
 * @addr 0x08A3C
 * @module display
 * @proto void draw_label(ushort* dst, ushort num, char sel)
 * @confidence likely
 * @note 绘制带数字的标签（如菜单项序号）。
 * @tag text
 */
int draw_label(ushort* dst, ushort num, char sel)

{
  undefined2 uVar1;
  byte bVar2;
  byte bVar3;
  undefined2 auStack_12 [7];
  
  auStack_12[0] = 0x20;
  if (dst == (undefined2 *)0x0) {
    if ((edit_state2 != '\x12') && (edit_state2 != '\x1a')) {
      return 0;
    }
  }
  else {
    draw_token_plain(dst,auStack_12,6,0);
  }
  uVar1 = strlen((char *)auStack_12);
  bVar2 = 6 - (char)uVar1;
  bVar3 = (byte)auStack_12;
  if (sel != '\0') {
    cursor_visible = 4;
  }
  draw_string(num,CONCAT11((char)((ushort)auStack_12 >> 8) - (bVar3 < bVar2),bVar3 - bVar2));
  cursor_visible = 0;
  return 0;
}

/**
 * @brief 列表滚动条/滑块绘制 1
 * @addr 0x08AAE
 * @module display
 * @proto short draw_list_scroller(short x, ushort flag)
 * @confidence likely
 * @note 列表滚动条/滑块绘制 1。
 * @tag gfx
 */
short draw_list_scroller(short x, ushort flag)

{
  byte bVar1;
  byte bVar2;
  char cVar3;
  byte bVar8;
  ulonglong uVar4;
  byte bVar9;
  undefined8 uVar5;
  undefined8 uVar6;
  byte *pbStack_14;
  undefined2 uStack_12;
  byte bVar7;
  
  uStack_12 = 0;
  bVar7 = (byte)flag;
  bVar1 = (byte)((ushort)flag >> 8);
  uVar4 = (ulonglong)CONCAT11(bVar1,bVar7 - 1) << 0x10;
  bVar2 = (byte)x;
  bVar8 = (byte)((ushort)x >> 8);
  if ((((-1 < (char)(CARRY1(bVar2,bVar7) << 7)) && ((byte)(bVar2 + bVar7) < 0xc1)) &&
      (-1 < (char)(CARRY1(bVar8,bVar1) << 7))) && ((byte)(bVar8 + bVar1) < 0x41)) {
    bVar1 = calc_px_ptr(bVar2,bVar8,&pbStack_14);
    do {
      uVar6 = CONCAT17(*(undefined *)(bVar1 + 0x33bc),
                       CONCAT16(*(undefined *)(bVar1 + 0x33cc),(int6)uVar4));
      cVar3 = '\0';
      do {
        bVar2 = (byte)((ulonglong)uVar6 >> 0x10);
        if (bVar2 < 8) {
          bVar2 = 7 - bVar2;
          bVar9 = (byte)((ulonglong)uVar6 >> 0x38);
          bVar8 = (byte)((ulonglong)uVar6 >> 0x30);
          uVar6 = CONCAT17((byte)(((ushort)bVar9 * 0x100 + (ushort)bVar8 << (bVar2 & 7)) >> 8) &
                           bVar9,CONCAT16(bVar8 << (bVar2 & 7),(int6)uVar6));
        }
        cVar3 = cVar3 + '\x01';
        if ((byte *)uVar6 == (byte *)0x0) {
          bVar2 = (byte)uStack_12;
        }
        else {
          bVar2 = *(byte *)uVar6;
        }
        bVar8 = bVar2 >> (bVar1 & 7);
        uVar5 = CONCAT26((short)((ulonglong)uVar6 >> 0x30),
                         CONCAT15(bVar8,CONCAT14((char)((ushort)bVar2 * 0x100 >> (bVar1 & 7)),
                                                 (int)uVar6)));
        fb_write_op(CONCAT11((char)((ulonglong)uVar6 >> 0x38),bVar8),pbStack_14);
        pbStack_14 = pbStack_14 + 1;
        if (bVar1 != 0) {
          fb_write_op(CONCAT11((char)((ulonglong)uVar5 >> 0x30),(char)((ulonglong)uVar5 >> 0x20), (uintptr_t)0)
                         ,pbStack_14);
        }
        if ((short)uVar5 != 0) {
          uVar5 = CONCAT62((int6)((ulonglong)uVar5 >> 0x10),(short)uVar5 + 1);
        }
        bVar2 = (byte)((ulonglong)uVar5 >> 0x10);
        uVar6 = CONCAT53((int5)((ulonglong)uVar5 >> 0x18),CONCAT12(bVar2 - 8,(short)uVar5));
      } while ((char)((7 < bVar2) << 7) < '\0');
      x = (short)(pbStack_14 + (byte)(0x18 - cVar3));
      cVar3 = (char)((ulonglong)uVar5 >> 0x18) + -1;
      uVar4 = (ulonglong)CONCAT13(cVar3,CONCAT12(bVar7 - 1,(short)uVar5));
      pbStack_14 = (byte *)x;
    } while (cVar3 != '\0');
  }
  return x;
}

/**
 * @brief 列表滚动条/滑块绘制 2
 * @addr 0x08ABC
 * @module display
 * @proto short draw_list_scroller2(short x, ushort flag)
 * @confidence likely
 * @note 列表滚动条/滑块绘制 2。
 * @tag gfx
 */
short draw_list_scroller2(short x, ushort flag)

{
  byte bVar1;
  byte bVar2;
  char cVar3;
  byte bVar8;
  ulonglong uVar4;
  byte bVar9;
  undefined8 uVar5;
  undefined8 uVar6;
  byte *pbStack_14;
  undefined2 uStack_12;
  byte bVar7;
  
  uStack_12 = 0xffff;
  bVar7 = (byte)flag;
  bVar1 = (byte)((ushort)flag >> 8);
  uVar4 = (ulonglong)CONCAT11(bVar1,bVar7 - 1) << 0x10;
  bVar2 = (byte)x;
  bVar8 = (byte)((ushort)x >> 8);
  if ((((-1 < (char)(CARRY1(bVar2,bVar7) << 7)) && ((byte)(bVar2 + bVar7) < 0xc1)) &&
      (-1 < (char)(CARRY1(bVar8,bVar1) << 7))) && ((byte)(bVar8 + bVar1) < 0x41)) {
    bVar1 = calc_px_ptr(bVar2,bVar8,&pbStack_14);
    do {
      uVar6 = CONCAT17(*(undefined *)(bVar1 + 0x33bc),
                       CONCAT16(*(undefined *)(bVar1 + 0x33cc),(int6)uVar4));
      cVar3 = '\0';
      do {
        bVar2 = (byte)((ulonglong)uVar6 >> 0x10);
        if (bVar2 < 8) {
          bVar2 = 7 - bVar2;
          bVar9 = (byte)((ulonglong)uVar6 >> 0x38);
          bVar8 = (byte)((ulonglong)uVar6 >> 0x30);
          uVar6 = CONCAT17((byte)(((ushort)bVar9 * 0x100 + (ushort)bVar8 << (bVar2 & 7)) >> 8) &
                           bVar9,CONCAT16(bVar8 << (bVar2 & 7),(int6)uVar6));
        }
        cVar3 = cVar3 + '\x01';
        if ((byte *)uVar6 == (byte *)0x0) {
          bVar2 = (byte)uStack_12;
        }
        else {
          bVar2 = *(byte *)uVar6;
        }
        bVar8 = bVar2 >> (bVar1 & 7);
        uVar5 = CONCAT26((short)((ulonglong)uVar6 >> 0x30),
                         CONCAT15(bVar8,CONCAT14((char)((ushort)bVar2 * 0x100 >> (bVar1 & 7)),
                                                 (int)uVar6)));
        fb_write_op(CONCAT11((char)((ulonglong)uVar6 >> 0x38),bVar8),pbStack_14);
        pbStack_14 = pbStack_14 + 1;
        if (bVar1 != 0) {
          fb_write_op(CONCAT11((char)((ulonglong)uVar5 >> 0x30),(char)((ulonglong)uVar5 >> 0x20), (uintptr_t)0)
                         ,pbStack_14);
        }
        if ((short)uVar5 != 0) {
          uVar5 = CONCAT62((int6)((ulonglong)uVar5 >> 0x10),(short)uVar5 + 1);
        }
        bVar2 = (byte)((ulonglong)uVar5 >> 0x10);
        uVar6 = CONCAT53((int5)((ulonglong)uVar5 >> 0x18),CONCAT12(bVar2 - 8,(short)uVar5));
      } while ((char)((7 < bVar2) << 7) < '\0');
      x = (short)(pbStack_14 + (byte)(0x18 - cVar3));
      cVar3 = (char)((ulonglong)uVar5 >> 0x18) + -1;
      uVar4 = (ulonglong)CONCAT13(cVar3,CONCAT12(bVar7 - 1,(short)uVar5));
      pbStack_14 = (byte *)x;
    } while (cVar3 != '\0');
  }
  return x;
}

/**
 * @brief 列表滚动条/滑块绘制 3
 * @addr 0x08ACE
 * @module display
 * @proto byte* draw_list_scroller3(byte* p, ushort a, short b)
 * @confidence likely
 * @note 列表滚动条/滑块绘制 3。
 * @tag gfx
 */
byte* draw_list_scroller3(byte* p, ushort a, short b)

{
  byte bVar1;
  byte bVar2;
  char cVar3;
  byte bVar8;
  ulonglong uVar4;
  byte bVar9;
  undefined8 uVar5;
  undefined8 uVar6;
  byte *local_14;
  byte bStack_12;
  byte bVar7;
  
  if (b != 0) {
    bVar7 = (byte)a;
    bVar1 = (byte)((ushort)a >> 8);
    uVar4 = (ulonglong)CONCAT13(bVar1,CONCAT12(bVar7 - 1,b));
    bVar2 = (byte)p;
    bVar8 = (byte)((ushort)p >> 8);
    if ((((-1 < (char)(CARRY1(bVar2,bVar7) << 7)) && ((byte)(bVar2 + bVar7) < 0xc1)) &&
        (-1 < (char)(CARRY1(bVar8,bVar1) << 7))) && ((byte)(bVar8 + bVar1) < 0x41)) {
      bVar1 = calc_px_ptr(bVar2,bVar8,&local_14);
      do {
        uVar6 = CONCAT17(*(undefined *)(bVar1 + 0x33bc),
                         CONCAT16(*(undefined *)(bVar1 + 0x33cc),(int6)uVar4));
        cVar3 = '\0';
        do {
          bVar2 = (byte)((ulonglong)uVar6 >> 0x10);
          if (bVar2 < 8) {
            bVar2 = 7 - bVar2;
            bVar9 = (byte)((ulonglong)uVar6 >> 0x38);
            bVar8 = (byte)((ulonglong)uVar6 >> 0x30);
            uVar6 = CONCAT17((byte)(((ushort)bVar9 * 0x100 + (ushort)bVar8 << (bVar2 & 7)) >> 8) &
                             bVar9,CONCAT16(bVar8 << (bVar2 & 7),(int6)uVar6));
          }
          cVar3 = cVar3 + '\x01';
          bVar2 = bStack_12;
          if ((byte *)uVar6 != (byte *)0x0) {
            bVar2 = *(byte *)uVar6;
          }
          bVar8 = bVar2 >> (bVar1 & 7);
          uVar5 = CONCAT26((short)((ulonglong)uVar6 >> 0x30),
                           CONCAT15(bVar8,CONCAT14((char)((ushort)bVar2 * 0x100 >> (bVar1 & 7)),
                                                   (int)uVar6)));
          fb_write_op(CONCAT11((char)((ulonglong)uVar6 >> 0x38),bVar8),local_14);
          local_14 = local_14 + 1;
          if (bVar1 != 0) {
            fb_write_op(CONCAT11((char)((ulonglong)uVar5 >> 0x30), (uintptr_t)0)
                                    (char)((ulonglong)uVar5 >> 0x20)),local_14);
          }
          if ((short)uVar5 != 0) {
            uVar5 = CONCAT62((int6)((ulonglong)uVar5 >> 0x10),(short)uVar5 + 1);
          }
          bVar2 = (byte)((ulonglong)uVar5 >> 0x10);
          uVar6 = CONCAT53((int5)((ulonglong)uVar5 >> 0x18),CONCAT12(bVar2 - 8,(short)uVar5));
        } while ((char)((7 < bVar2) << 7) < '\0');
        p = local_14 + (byte)(0x18 - cVar3);
        cVar3 = (char)((ulonglong)uVar5 >> 0x18) + -1;
        uVar4 = (ulonglong)CONCAT13(cVar3,CONCAT12(bVar7 - 1,(short)uVar5));
        local_14 = p;
      } while (cVar3 != '\0');
    }
  }
  return p;
}

/**
 * @brief 菜单行背景
 * @addr 0x08B80
 * @module display
 * @proto void draw_menu_row_bg(uchar row)
 * @confidence likely
 * @note 菜单行背景。
 * @tag menu
 */
int draw_menu_row_bg(uchar row)

{
  undefined uVar1;
  byte bVar3;
  char cVar4;
  longlong lVar2;
  undefined auStack_12 [14];
  
  cur_line = 8;
  lVar2 = CONCAT44(CONCAT31((int3)(CONCAT26(auStack_12,0x40000000000) >> 0x28),row),0xb000000);
  do {
    draw_menu_row_text((byte)((ulonglong)lVar2 >> 0x20),(char *)((ulonglong)lVar2 >> 0x30));
    uVar1 = 0;
    bVar3 = (byte)((ulonglong)lVar2 >> 0x20);
    if ((bVar3 < 100) && (uVar1 = 6, bVar3 < 10)) {
      uVar1 = 0xc;
    }
    draw_string(CONCAT11((char)((ulonglong)lVar2 >> 0x18),uVar1), (uintptr_t)0)
                   (short)((ulonglong)lVar2 >> 0x30));
    cVar4 = (char)((ulonglong)lVar2 >> 0x28) + -1;
    lVar2 = (ulonglong)
            CONCAT23((short)((ulonglong)lVar2 >> 0x30),
                     CONCAT12(cVar4,CONCAT11((char)((ulonglong)lVar2 >> 0x20) + '\x01',
                                             (char)((ulonglong)lVar2 >> 0x18) + '\n'))) << 0x18;
  } while (cVar4 != '\0');
  return 0;
}

/**
 * @brief 菜单行文字
 * @addr 0x08BC0
 * @module display
 * @proto void draw_menu_row_text(byte row, char* text)
 * @confidence likely
 * @note 菜单行文字。
 * @tag menu
 */
int draw_menu_row_text(byte row, char* text)

{
  byte bVar1;
  
  bVar1 = row % 100;
  if (row != 0) {
    *text = row / 100 + 0x30;
    text = text + 1;
  }
  if (bVar1 == 0) {
    if (row != 0) {
      *text = '0';
      text = text + 1;
    }
  }
  else {
    *text = bVar1 / 10 + 0x30;
    text = text + 1;
  }
  *text = bVar1 % 10 + 0x30;
  text[1] = '\0';
  return 0;
}

/**
 * @brief 一次性绘制 4 段字符串（自检、错误页）
 * @addr 0x08BF4
 * @module display
 * @proto void draw_text4(ushort p1, ushort p2, ushort p3, ushort p4)
 * @confidence strong
 * @note 一次性绘制 4 段字符串（自检、错误页）。
 * @tag text
 */
int draw_text4(ushort p1, ushort p2, ushort p3, ushort p4)

{
  undefined uVar1;
  undefined2 uVar2;
  byte bVar3;
  ushort *puVar4;
  ushort uStack_14;
  undefined2 uStack_12;
  undefined2 uStack_10;
  undefined2 uStack_e;
  
  uStack_e = p4;
  uStack_10 = p3;
  puVar4 = &uStack_14;
  uStack_14 = p1;
  uStack_12 = p2;
  uVar1 = smallprint(p1);
  bVar3 = 1;
  do {
    uVar2 = *puVar4;
    puVar4 = puVar4 + 1;
    uVar1 = draw_format_string_al(CONCAT11(bVar3,uVar1),uVar2);
    bVar3 = bVar3 + 0x10;
  } while (bVar3 < 0x32);
  draw_target = 1;
  fb_alt_flush();
  timer_base_restore();
  return 0;
}



// 行打印函数 (draw_text4x)
// 地址: 0x2235A

/**
 * @brief 显示 4 行文本（DISP/诊断/错误确认页）
 * @addr 0x08C4A
 * @module display
 * @proto void draw_text4x(ushort pos)
 * @confidence strong
 * @note 显示 4 行文本（DISP/诊断/错误确认页）：smallprint 后以 0x10 像素行距绘制 4 行。
 * @tag text
 */
int draw_text4x(ushort pos)

{
  undefined uVar1;
  short sVar2;
  undefined2 uVar5;
  char cVar6;
  undefined8 uVar3;
  longlong lVar4;
  
  uVar3 = CONCAT62(0x400,pos);
  uVar1 = smallprint(pos);
  sVar2 = (short)uVar3;
  lVar4 = CONCAT53((int5)((ulonglong)uVar3 >> 0x18),0x10000);
  do {
    uVar5 = (undefined2)((ulonglong)lVar4 >> 0x10);
    uVar1 = draw_format_string_al(CONCAT11((char)((ulonglong)lVar4 >> 0x10),uVar1),sVar2);
    sVar2 = sVar2 + 1;
    cVar6 = (char)((ushort)uVar5 >> 8) + -1;
    lVar4 = (ulonglong)CONCAT11(cVar6,(char)uVar5 + '\x10') << 0x10;
  } while (cVar6 != '\0');
  draw_target = 1;
  fb_alt_flush();
  timer_base_restore();
  return 0;
}



// 小字体打印 (smallprint)
// 地址: 0x221B2

/**
 * @brief 小字/状态行显示入口
 * @addr 0x08C6C
 * @module display
 * @proto int smallprint(ushort pat)
 * @confidence verified
 * @note 小字/状态行显示入口：0xD137=14、0xD139=0，清屏并绘制。
 * @tag text
 */
int smallprint(ushort pat)

{
  cur_line = 0xe;
  draw_target = 0;
  screen_mode_blank(pat & 0xff00);
  fill_screen(0x400);
  return 0;
}



// 从第0列开始打印行 (show_press_ac)
// 地址: 0x220FE

/**
 * @brief 显示 Press AC 并等待 AC
 * @addr 0x08C88
 * @module display
 * @proto void show_press_ac(void)
 * @confidence verified
 * @note 显示 Press AC 并等待 AC。
 * @tag text
 */
int show_press_ac(void)

{
  lcd_cursor_col = 1;
  return 0;
}



// 从第3列开始打印行 (show_error_press_ac)
// 地址: 0x22108

/**
 * @brief 显示错误页并等待 AC
 * @addr 0x08C90
 * @module display
 * @proto void show_error_press_ac(void)
 * @confidence verified
 * @note 显示错误页并等待 AC。
 * @tag text
 */
int show_error_press_ac(void)

{
  lcd_status_y = 1;
  return 0;
}

/**
 * @brief 置位 LCD 状态寄存器 0xF811 的 bit0
 * @addr 0x08C98
 * @module display
 * @proto void lcd_set_status_x(void)
 * @confidence verified
 * @note 置位 LCD 状态寄存器 0xF811 的 bit0。
 * @tag display
 */
int lcd_set_status_x(void)

{
  lcd_status_x = 1;
  return 0;
}

/**
 * @brief 返回 0xF050（LCD/键盘外设基址的低字节）
 * @addr 0x08CA8
 * @module display
 * @proto byte get_ram_base(void)
 * @confidence verified
 * @note 返回 0xF050（LCD/键盘外设基址的低字节）。
 * @tag hal
 */
byte get_ram_base(void)

{
  return _DAT_ram_f050;
}

/**
 * @brief 菜单绘制
 * @addr 0x08CC0
 * @module display
 * @proto void menu_draw(char first)
 * @confidence strong
 * @note 菜单绘制：设置当前行 0xD137=0x0E，按 first 选择 ROM 0x62A8/0x6686 表绘制菜单项。
 * @tag ui
 */
int menu_draw(char first)

{
  cur_line = 0xe;
  draw_text4(*(ushort *)((ushort)(byte)((uintptr_t)first - 1) * 2 + 0x9ea),0x576a,0x6686,0x62a8);
  return 0;
}

/**
 * @brief 界面状态复位
 * @addr 0x08CEE
 * @module display
 * @proto void ui_state_init(void)
 * @confidence strong
 * @note 界面状态复位：0xD114=1、清 0xD0F7/0xD13A/0xD13F/0xD10E(设
 *       0xFC26)、0xD142/0xD164/0xD165，0xD139=1，并调用 0x9304 建立显示。
 * @tag ui
 */
int ui_state_init(void)

{
  ushort uVar1;
  
  edit_state2 = 1;
  display_ctrl = 0;
  key_flags = 0;
  disp_mode = 0;
  input_key = 0xfc26;
  stat_sel = 0;
  stat_rows = 0;
  stat_cols = 0;
  kbd_repeat = 0;
  uVar1 = CONCAT11(1,status_bits) & 0xff80;
  status_bits = (undefined)uVar1;
  cursor_visible = 0;
  draw_target = 1;
  base_addr = get_ram_base();
  input_layout = 0;
  contrast_set(contrast);
  stat_table_reset();
  clear_screen();
  buffer_reset_for_mode(uVar1);
  ratio_reset();
  fb_flush();
  return 0;
}

