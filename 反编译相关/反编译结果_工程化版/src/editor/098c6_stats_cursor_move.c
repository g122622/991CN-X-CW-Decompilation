/*
 * 输入编辑器 / 098c6_stats_cursor_move.c
 * 地址范围: 0x098C6 - 0x0A052
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 统计表光标移动
 * @addr 0x098C6
 * @module editor
 * @proto void stats_cursor_move(void)
 * @confidence strong
 * @note 统计表光标移动：按方向键（0xD116 bit5）在 1..行数 0xD154 间移动并调用0x2AC7C 刷新当前行。
 * @tag app
 */
int stats_cursor_move(void)

{
  byte bVar1;
  char cVar2;
  byte bVar3;
  char **ppcVar4;
  short sVar5;
  
  ppcVar4 = (char **)frame_enter();
  cVar2 = is_left_right((char)input_key,(char)((ushort)input_key >> 8));
  bVar1 = menu_index;
  if ((((cVar2 == '\0') || (*(char *)(ppcVar4 + 5) != '\0')) ||
      ((cVar2 = is_modifier_3_5(), cVar2 == '\0' && (bVar1 = menu_index, **ppcVar4 != '\0')))) ||
     (bVar3 = table_row_count(), bVar1 = menu_index, (char)((bVar3 == 0) << 7) < '\0'))
  goto LAB_rom_0098dc;
  if ((key_modifiers & 0x20) == 0) {
    sVar5 = key_is_1a_04();
    if ((char)sVar5 == '\0') {
      bVar1 = menu_index;
      if (cVar2 != '\0') goto LAB_rom_0098dc;
      menu_index = 1;
    }
    else {
      menu_index = bVar3;
      if (((cVar2 != '\0') && (1 < bVar3)) && (edit_state2 != -0x40)) {
        menu_index = bVar3 - 1;
      }
    }
  }
  else {
    sVar5 = key_is_1a_04();
    if ((char)sVar5 == '\0') {
      menu_index = menu_index + 1;
      bVar1 = bVar3;
      if (bVar3 < menu_index) goto LAB_rom_0098dc;
    }
    else {
      menu_index = menu_index - 1;
      if (menu_index == 0) {
        menu_index = 1;
        bVar1 = menu_index;
        goto LAB_rom_0098dc;
      }
    }
  }
  row_refresh();
  bVar1 = menu_index;
LAB_rom_0098dc:
  menu_index = bVar1;
  frame_leave();
  return 0;
}

/**
 * @brief 绘制输入行
 * @addr 0x09972
 * @module editor
 * @proto int draw_input_line(undefined* p)
 * @confidence likely
 * @note 绘制输入行：按 0xD111/0xD115/0xD116 选择 0x203C2 复制行内容（0xE5A 区）。
 * @tag editor
 */
int draw_input_line(undefined* p)

{
  int cVar1;
  byte **ppbVar2;
  byte *pbVar3;
  undefined *puVar4;
  
  ppbVar2 = (byte **)frame_enter();
  puVar4 = &input_buf;
  pbVar3 = (byte *)input_history_ptr();
  *ppbVar2 = pbVar3;
  if ((calc_mode == -0x78) && (stat_state == '\x04')) {
    p = (undefined *)0xd248;
    strcpy_checked(&input_buf,(char *)0xd248);
  }
  else if ((key_modifiers & 0x40) == 0) {
    expr_append_A();
    strcpy_checked((char *)0xd248,&input_buf);
    p = puVar4;
  }
  cVar1 = is_math_io();
  if (cVar1 == '\0') {
    strcpy_checked((char *)*ppbVar2,&input_buf);
    if ((key_modifiers & 0x40) != 0) {
      input_ptr = input_ptr + (ushort)(byte)(input_end_ptr - *(char *)ppbVar2);
    }
  }
  else {
    cVar1 = menu_layer(p);
    if (cVar1 != '\0') {
      buffer_transfer(*ppbVar2);
    }
  }
  frame_leave();
  return 0;
}

/**
 * @brief 0xD111==0x88 且 0xD114==1 时返回 1
 * @addr 0x09A08
 * @module editor
 * @proto char is_ratio_input(void)
 * @confidence strong
 * @note 0xD111==0x88 且 0xD114==1 时返回 1。
 * @tag ui
 */
char is_ratio_input(void)

{
  undefined uVar1;
  
  uVar1 = 0;
  if ((calc_mode == -0x78) && (edit_state2 == '\x01')) {
    uVar1 = 1;
  }
  return uVar1;
}

/**
 * @brief 调用 0x20F98/0x20EE6 输出提示字符串
 * @addr 0x09A20
 * @module editor
 * @proto undefined2 emit_hint(undefined2 a, char flag)
 * @confidence likely
 * @note 调用 0x20F98/0x20EE6 输出提示字符串。
 * @tag ui
 */
undefined2 emit_hint(undefined2 a, char flag)

{
  if (flag == '\0') {
    str_emit_lparen();
  }
  else {
    str_emit_backtick();
  }
  return a;
}

/**
 * @brief 标准 memmove（处理重叠区间）
 * @addr 0x09A3A
 * @module editor
 * @proto undefined* memmove(undefined* dst, undefined* src, short len)
 * @confidence verified
 * @note 标准 memmove（处理重叠区间）。
 * @tag libc
 */
undefined* memmove(undefined* dst, undefined* src, short len)

{
  undefined *puVar1;
  undefined *puVar2;
  
  puVar1 = dst;
  if (((short)src < (short)dst) && ((short)dst < (short)(src + len))) {
    puVar1 = dst + len;
    puVar2 = src + len;
    for (; (char)((len != 0) << 7) < '\0'; len = len + -1) {
      puVar1 = puVar1 + -1;
      puVar2 = puVar2 + -1;
      *puVar1 = *puVar2;
    }
  }
  else {
    for (; (char)((len != 0) << 7) < '\0'; len = len + -1) {
      *puVar1 = *src;
      src = src + 1;
      puVar1 = puVar1 + 1;
    }
  }
  return dst;
}

/**
 * @brief 数字键 1..4 选择菜单项
 * @addr 0x09AA6
 * @module editor
 * @proto void menu_numeric_select(void)
 * @confidence strong
 * @note 数字键 1..4 选择菜单项：索引表 0x394E，上限 0x6798，返回选中项字节。
 * @tag menu
 */
int menu_numeric_select(void)

{
  byte bVar1;
  byte bVar2;
  int sVar3;
  char cVar4;
  ushort uVar5;
  
LAB_rom_009aaa:
  stats_matrix_draw();
  do {
    sVar3 = input_is_empty();
    bVar1 = _DAT_ram_d163;
    bVar2 = (byte)sVar3;
    cVar4 = (char)((ushort)sVar3 >> 8);
    if ((((bVar2 == 0x31 && (bool)cVar4 == bVar2 < 0x31) ||
         (bVar2 == 0x32 && (bool)cVar4 == bVar2 < 0x32)) ||
        (bVar2 == 0x33 && (bool)cVar4 == bVar2 < 0x33)) ||
       (bVar2 == 0x34 && (bool)cVar4 == bVar2 < 0x34)) {
      uVar5 = CONCAT11((char)(((ushort)_DAT_ram_d163 << 2) >> 8),_DAT_ram_d163 << 2) + sVar3 + -0x31;
      if ((ushort)(CONCAT11((char)(((ushort)_DAT_ram_d163 << 2) >> 8),_DAT_ram_d163 << 2) +
                  sVar3 + -0x31) <= (ushort)_DAT_ram_6798) {
        return *(undefined *)
                (CONCAT11((char)(((uVar5 & 0xff00) + (uVar5 & 0xff)) * 4 >> 8),(char)uVar5 << 2) +
                0x394e);
      }
    }
    else {
      if (bVar2 == 2 && (bool)(cVar4 + '\x04') == bVar2 < 2) {
        return 6;
      }
      if (bVar2 == 0x1c && (bool)(cVar4 + '\x04') == bVar2 < 0x1c) {
        if (_DAT_ram_d163 == 0) {
          _DAT_ram_d163 = _DAT_ram_6798 >> 2;
        }
        else {
          _DAT_ram_d163 = _DAT_ram_d163 - 1;
        }
        goto LAB_rom_009aaa;
      }
      if (bVar2 == 0x1d && (bool)(cVar4 + '\x04') == bVar2 < 0x1d) break;
      if (bVar2 == 0x26 && (bool)(cVar4 + '\x04') == bVar2 < 0x26) {
        return 6;
      }
    }
    beep();
  } while( true );
  uVar5 = (ushort)_DAT_ram_d163;
  sVar3 = draw_spaced((ushort)_DAT_ram_6798,4);
  if ((short)uVar5 < sVar3) {
    _DAT_ram_d163 = bVar1 + 1;
  }
  else {
    _DAT_ram_d163 = 0;
  }
  goto LAB_rom_009aaa;
}

/**
 * @brief 返回输入区最大长度
 * @addr 0x09B6E
 * @module editor
 * @proto byte input_max_len(void)
 * @confidence strong
 * @note 返回输入区最大长度：常态 200，0x0D 模式 0x32，特定状态 0x31。
 * @tag editor
 */
byte input_max_len(void)

{
  undefined uVar1;
  
  uVar1 = 200;
  if (((calc_mode == '\r') && (uVar1 = 0x32, _DAT_ram_ddb0 == '\x01')) && (stat_state == '\x01')
     ) {
    uVar1 = 0x31;
  }
  return uVar1;
}

/**
 * @brief 调用 0x1D620 以固定格式 0x1B6C 把 v 格式化
 * @addr 0x09B90
 * @module editor
 * @proto undefined2 dec_fmt_1b6c(undefined2 v)
 * @confidence strong
 * @note 调用 0x1D620 以固定格式 0x1B6C 把 v 格式化。
 * @tag format
 */
undefined2 dec_fmt_1b6c(undefined2 v)

{
  undefined2 uVar1;
  
  uVar1 = dec_to_string(v,(undefined2 *)0x1b6c);
  return uVar1;
}

/**
 * @brief 若当前编辑状态为 1 且词法单元为函数，则向输入区追加字符 A
 * @addr 0x09B98
 * @module editor
 * @proto int expr_append_A(void)
 * @confidence likely
 * @note 若当前编辑状态为 1 且词法单元为函数，则向输入区追加字符 A。
 * @tag editor
 */
int expr_append_A(void)

{
  byte *pbVar1;
  short sVar2;
  ushort uVar3;
  undefined2 uVar4;
  short unaff_ER14;
  
  pbVar1 = (byte *)frame_enter();
  if ((edit_state2 == '\x01') && (sVar2 = input_char_count(pbVar1), (char)sVar2 == '\x01')) {
    uVar3 = token_at(pbVar1);
    uVar4 = check_type1_codes(uVar3);
    if ((char)uVar4 != '\0') {
      *(undefined *)(unaff_ER14 + -2) = 0x41;
      *(undefined *)(unaff_ER14 + -1) = 0;
      strcat_checked((char *)pbVar1,(char *)(unaff_ER14 + -2));
    }
  }
  frame_leave();
  return 0;
}

/**
 * @brief 初始化滚动/高亮状态（0xD157/0xD15A/0xD15B）
 * @addr 0x09BD8
 * @module editor
 * @proto void scroll_init(void)
 * @confidence strong
 * @note 初始化滚动/高亮状态（0xD157/0xD15A/0xD15B）。
 * @tag ui
 */
int scroll_init(void)

{
  _DAT_ram_d157 = '\x01';
  _DAT_ram_d15a = 0;
  _DAT_ram_d15b = 0;
  if (calc_mode == '\x02') {
    _DAT_ram_d157 = cur_line + '\x01';
    hl_col = hl_col + cur_line;
  }
  return 0;
}

/**
 * @brief 把结果变量 0xD16C 置 0（0xD176 也清零）
 * @addr 0x09C0A
 * @module editor
 * @proto void result_clear(void)
 * @confidence strong
 * @note 把结果变量 0xD16C 置 0（0xD176 也清零）。
 * @tag vars
 */
int result_clear(void)

{
  undefined2 *puVar1;
  short unaff_ER14;
  
  puVar1 = (undefined2 *)frame_enter();
  dec_set_uint_small((ushort *)0xd176,0);
  if (puVar1 == (undefined2 *)0x0) {
    puVar1 = (undefined2 *)(unaff_ER14 + -10);
    dec_set_special((ushort *)(unaff_ER14 + -10),0xd);
  }
  dec_copy((undefined2 *)0xd16c,puVar1);
  frame_leave();
  return 0;
}

/**
 * @brief 绘制变量/表格内容（遍历 0x4B42 表并格式化数值）
 * @addr 0x09C40
 * @module editor
 * @proto void draw_var_table(void)
 * @confidence strong
 * @note 绘制变量/表格内容（遍历 0x4B42 表并格式化数值）。
 * @tag vars
 */
int draw_var_table(void)

{
  byte bVar1;
  undefined uVar2;
  char cVar3;
  char cVar4;
  ushort uVar5;
  byte bVar6;
  short unaff_ER14;
  
  frame_enter();
  cur_line = 10;
  uVar5 = 0;
  do {
    if ((uVar5 & 1) == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = 0x60;
    }
    cVar4 = _DAT_ram_6492 * (char)((uVar5 & 0xff00) + (uVar5 & 0xff) >> 1);
    var_get_value(*(byte *)(uVar5 + 0x4b42),(undefined *)(unaff_ER14 + -0x14));
    *(undefined *)(unaff_ER14 + -0x40) = *(undefined *)(uVar5 + 0x195a);
    *(undefined *)(unaff_ER14 + -0x3f) = 0x3d;
    *(undefined *)(unaff_ER14 + -0x3e) = 0;
    cVar3 = is_mode_E();
    if (cVar3 == '\0') {
      refresh_list((undefined2 *)(unaff_ER14 + -0x14));
    }
    else {
      stat_calc_main((undefined2 *)(unaff_ER14 + -0x3e));
    }
    draw_string(CONCAT11(cVar4 + '\x01',uVar2),unaff_ER14 + -0x40);
    uVar5 = uVar5 + 1;
    bVar6 = (byte)(uVar5 >> 8);
    bVar1 = bVar6 - ((byte)uVar5 < 9);
  } while ((byte)((byte)((bVar1 ^ bVar6) & ~bVar1) >> 7 ^ (char)bVar1 < '\0') == 1);
  frame_leave();
  return 0;
}

/**
 * @brief 输入字符分类
 * @addr 0x09CC4
 * @module editor
 * @proto undefined2 token_class2(byte* p)
 * @confidence strong
 * @note 输入字符分类：数字 0x3A..0x3F 与 0x01 特殊处理，用于 token 化。
 * @tag editor
 */
undefined2 token_class2(byte* p)

{
  byte bVar1;
  short sVar2;
  byte bVar3;
  
  sVar2 = is_digit_at(p);
  if ((char)sVar2 == '\0') {
    bVar3 = (byte)((ushort)sVar2 >> 8);
    if (calc_mode == '\x02') {
      bVar1 = *p;
      sVar2 = CONCAT11(bVar3,bVar1);
      if ((0x39 < bVar1) && (bVar1 < 0x40)) goto LAB_rom_009cd2;
    }
    sVar2 = CONCAT11(bVar3,*p);
    if (*p != 1) {
      return (ushort)bVar3 << 8;
    }
  }
LAB_rom_009cd2:
  return CONCAT11((char)((ushort)sVar2 >> 8),1);
}

/**
 * @brief 函数序言辅助
 * @addr 0x09D22
 * @module editor
 * @proto short frame_enter(void)
 * @confidence verified
 * @note 函数序言辅助：PUSH QR8 → PUSH XR4 → MOV ER14,SP → RT。约 230 个函数先 CALL
 *       它，再保存其他寄存器，形成可变长序言。Ghidra 不理解跨调用的栈帧，把它当作无参函数。
 * @tag frame
 */
short frame_enter(void)

{
  return;
}

/**
 * @brief 函数尾声辅助
 * @addr 0x09D2A
 * @module editor
 * @proto void frame_leave(void)
 * @confidence verified
 * @note 函数尾声辅助：MOV SP,ER14 → POP XR4 → POP QR8 → POP PC。与 frame_enter
 *       成对使用，所有复杂函数都以它收尾。
 * @tag frame
 */
int frame_leave(void)

{
  return 0;
}

/**
 * @brief 返回 |col - 光标列|
 * @addr 0x09D32
 * @module editor
 * @proto char abs_col_diff(byte col)
 * @confidence verified
 * @note 返回 |col - 光标列|。
 * @tag editor
 */
char abs_col_diff(byte col)

{
  char cVar1;
  
  if ((char)((col < dec_regY) << 7) < '\0') {
    cVar1 = dec_regY - col;
  }
  else {
    cVar1 = col - dec_regY;
  }
  return cVar1;
}

/**
 * @brief 原地回显/读取输入区的当前字符串（Ghidra 的"参数"其实是调用后由 ER0 返回的指针…
 * @addr 0x09D52
 * @module editor
 * @proto char* input_read_str(void)
 * @confidence likely
 * @note 原地回显/读取输入区的当前字符串（Ghidra 的"参数"其实是调用后由 ER0 返回的指针，调用点总是写成
 *       input_read_str((char*)buf) 后才用 ER0，C 原型按无参声明），返回输入区字符串指针。
 * @tag editor
 */
char* input_read_str(uintptr_t _a3, int _a1, int _a2)

{
  short sVar1;
  char *pcVar2;
  
  sVar1 = frame_enter();
  pcVar2 = (char *)matrix_item_ptr(sVar1);
  strcpy_checked(_a1,pcVar2);
  strlen_checked(_a1);
  frame_leave();
  return;
}



// 内存复制函数 (prev_char_ptr)
// 地址: 0x9D72
// _a1: 目标地址
// _a2: 源地址
// 返回: 目标地址

/**
 * @brief 返回 p 之前一个"字符"的地址
 * @addr 0x09D72
 * @module editor
 * @proto byte* prev_char_ptr(byte* start, byte* p)
 * @confidence verified
 * @note 返回 p 之前一个"字符"的地址：若 p-2 字节 >= 0xF0（双字节字符首字节）则 p-2，否则
 *       p-1；p<=start 返回 0。原记录误命名为 memcpy。
 * @tag editor
 */
byte* prev_char_ptr(byte* start, byte* p)

{
  byte *pbVar1;
  
  if (start < p) {
    pbVar1 = p + -1;
    if ((start != pbVar1) && (pbVar1 = p + -2, *pbVar1 < 0xf0)) {
      pbVar1 = p + -1;
    }
  }
  else {
    pbVar1 = (byte *)0x0;
  }
  return pbVar1;
}

/**
 * @brief 切换输入上下文（保存/恢复 0xD144、清 0xD00C/0xD011），并调用 0x1F…
 * @addr 0x09DC8
 * @module editor
 * @proto void input_context_switch(short* p)
 * @confidence strong
 * @note 切换输入上下文（保存/恢复 0xD144、清 0xD00C/0xD011），并调用 0x1FC7C/0x25D7C。
 * @tag editor
 */
int input_context_switch(short* p)

{
  undefined2 uVar1;
  undefined2 uVar2;
  
  uVar2 = frame_enter();
  uVar1 = input_ptr;
  dec_accum8 = 0;
  dec_regY_1 = 0;
  input_ptr = uVar2;
  set_sel_mode('\0');
  row_buffer_init(p);
  input_active = 0;
  input_ptr = uVar1;
  frame_leave();
  return 0;
}

/**
 * @brief 调用 0xC438(0)（置编辑状态 0）
 * @addr 0x09E1E
 * @module editor
 * @proto void edit_state_set0(void)
 * @confidence likely
 * @note 调用 0xC438(0)（置编辑状态 0）。
 * @tag ui
 */
int edit_state_set0(void)

{
  matrix_mode_key('\0');
  return 0;
}

/**
 * @brief 解析 p 处 BCD 数值，格式化为科学计数并追加到目标字符串
 * @addr 0x09E4C
 * @module editor
 * @proto byte* append_number_str(byte* p)
 * @confidence strong
 * @note 解析 p 处 BCD 数值，格式化为科学计数并追加到目标字符串。
 * @tag format
 */
byte* append_number_str(byte* p)

{
  char *pcVar1;
  byte *pbVar2;
  short unaff_ER14;
  
  pcVar1 = (char *)frame_enter();
  pbVar2 = dec_parse(p,(byte **)(unaff_ER14 + -0x18));
  if ((char)pbVar2 != '\0') {
    *(undefined2 *)(unaff_ER14 + -6) = *(undefined2 *)(unaff_ER14 + -8);
    *(undefined *)(unaff_ER14 + -4) = 10;
    *(undefined *)(unaff_ER14 + -3) = 1;
    fmt_sci(unaff_ER14 + -0x18,(char *)(unaff_ER14 + -0x2c));
    strcat_checked(pcVar1,(char *)(unaff_ER14 + -0x2c));
  }
  frame_leave();
  return;
}

/**
 * @brief 运行编辑器直到用户按 ON 或完成输入
 * @addr 0x09EA4
 * @module editor
 * @proto int editor_run(void)
 * @confidence strong
 * @note 运行编辑器直到用户按 ON 或完成输入。
 * @tag editor
 */
int editor_run(void)

{
  char cVar1;
  bool bVar2;
  short sVar3;
  short sVar4;
  short unaff_ER14;
  
  frame_enter();
  *(undefined *)(unaff_ER14 + -2) = 0x80;
  *(undefined *)(unaff_ER14 + -1) = 1;
  sVar3 = 500;
  while (sVar4 = sVar3 + -1, sVar3 != 0) {
    timer_wait(0x50);
    cVar1 = key_repeat_wait();
    sVar3 = sVar4;
    if (cVar1 == '\0') {
      do {
        kbd_filter_on();
        kbd_ko_enable();
        do {
          sVar4 = sVar4 + -1;
          if (sVar4 == 0) {
            kbd_ko_disable();
            kbd_filter_off();
            goto LAB_rom_009ed8;
          }
          timer_wait(0x50);
          bVar2 = kbd_any_key();
        } while (!bVar2);
        kbd_ko_disable();
        kbd_filter_off();
        timer_wait(1);
        cVar1 = lcd_scan_keys((uintptr_t)0);
      } while ((cVar1 == '\0') || (cVar1 = wait_release((uintptr_t)0), cVar1 == '\0'));
      if ((((*(char *)(unaff_ER14 + -4) == '\x04') && (*(char *)(unaff_ER14 + -3) == '\x04')) ||
          ((*(char *)(unaff_ER14 + -4) == '\x04' && (*(char *)(unaff_ER14 + -3) == '\x10')))) ||
         ((*(char *)(unaff_ER14 + -4) == '\x04' && (*(char *)(unaff_ER14 + -3) == '\x02')))) break;
      *(undefined2 *)(unaff_ER14 + -2) = *(undefined2 *)(unaff_ER14 + -4);
      sVar3 = sVar4;
    }
  }
LAB_rom_009ed8:
  kbd_ko_disable();
  frame_leave();
  return 0;
}

/**
 * @brief 对输入区首字符做分类（供 token 分派跳转表使用）
 * @addr 0x09F66
 * @module editor
 * @proto int char_class(void)
 * @confidence strong
 * @note 对输入区首字符做分类（供 token 分派跳转表使用）。
 * @tag editor
 */
int char_class(void)

{
  int bVar1;
  byte *pbVar2;
  ushort uVar3;
  char cVar4;
  
  pbVar2 = (byte *)frame_enter();
  bVar1 = font_class_of(*pbVar2);
  if (0xe < bVar1) {
    uVar3 = token_at(pbVar2);
    cVar4 = (char)(uVar3 >> 8);
    bVar1 = (byte)uVar3;
    if (((cVar4 != '\0') ||
        (((((bVar1 != 0 && (bVar1 != 0x1a)) && (bVar1 != 0x1b)) &&
          ((((bVar1 != 0x1c && (bVar1 != 0x1d)) &&
            ((bVar1 != 0x1e && ((bVar1 != 0x60 && (bVar1 != 0xa5)))))) && (bVar1 != 0xd0)))) &&
         (((bVar1 != 0xd2 && (bVar1 != 0xd3)) && (bVar1 != 0xe9)))))) &&
       (bVar1 = token_class_ex(bVar1,cVar4),
       (-(ushort)(bVar1 < 10) & 0x100) != 0 || bVar1 == 10 && (char)-(ushort)(bVar1 < 10) == '\0'))
    {
                    // WARNING: Could not recover jumptable at 0x009fd0. Too many branches
                    // WARNING: Treating indirect jump as call
      ((void)0);
      return 0;
    }
  }
  frame_leave();
  return 0;
}

/**
 * @brief 0xD114 为 6/9/0xA0/0xC0 且 0xD115<3、0xD116==1 时返…
 * @addr 0x0A026
 * @module editor
 * @proto char is_edit_state_6_9(void)
 * @confidence strong
 * @note 0xD114 为 6/9/0xA0/0xC0 且 0xD115<3、0xD116==1 时返回 1。
 * @tag ui
 */
char is_edit_state_6_9(void)

{
  if ((((edit_state2 == '\x06') || (edit_state2 == '\t')) ||
      (((edit_state2 == -0x60 || (edit_state2 == -0x40)) && (stat_state < 3)))) &&
     (key_modifiers == '\x01')) {
    return 1;
  }
  return 0;
}

/**
 * @brief 在输入区按行列扫描（调用 key_pos_offset），用于矩阵/表格输入
 * @addr 0x0A052
 * @module editor
 * @proto ushort* expr_matrix_scan(ushort* p)
 * @confidence likely
 * @note 在输入区按行列扫描（调用 key_pos_offset），用于矩阵/表格输入。
 * @tag editor
 */
ushort* expr_matrix_scan(ushort* p)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  undefined2 *puVar4;
  ushort uVar5;
  short unaff_ER14;
  
  bVar1 = frame_enter();
  bVar2 = *(byte *)(unaff_ER14 + 0x12);
  dec_set_uint_small((ushort *)(unaff_ER14 + -10),1);
  dec_bcd_to_bin((undefined2 *)(unaff_ER14 + -10),0xff9d);
  puVar4 = (undefined2 *)
           key_pos_offset(CONCAT11(*(undefined *)(unaff_ER14 + 0x12))
                                   *(undefined *)(unaff_ER14 + 0x12)));
  dec_copy((undefined2 *)(unaff_ER14 + -0x14),puVar4);
  dec_bin_result((ushort *)(unaff_ER14 + -0x14),puVar4);
  bVar3 = *(byte *)(unaff_ER14 + 0x12);
  while (bVar3 = bVar3 + 1, (char)((bVar3 < bVar1) << 7) < '\0') {
    puVar4 = (undefined2 *)key_pos_offset(CONCAT11(*(undefined *)(unaff_ER14 + 0x12),bVar3));
    dec_copy((undefined2 *)(unaff_ER14 + -0x1e),puVar4);
    dec_bin_result((ushort *)(unaff_ER14 + -0x1e),puVar4);
    uVar5 = dec_cmp_bool((undefined2 *)(unaff_ER14 + -0x14));
    if ((uVar5 & 2) != 0) {
      dec_copy((undefined2 *)(unaff_ER14 + -0x14),(undefined2 *)(unaff_ER14 + -0x1e));
      bVar2 = bVar3;
    }
  }
  uVar5 = dec_cmp_bool((undefined2 *)(unaff_ER14 + -0x14));
  if ((uVar5 & 2) == 0) {
    if (*(byte *)(unaff_ER14 + 0x12) != bVar2) {
      **(char **)(unaff_ER14 + 0x14) = **(char **)(unaff_ER14 + 0x14) + '\x01';
      for (bVar3 = 0; (char)((bVar3 < bVar1) << 7) < '\0'; bVar3 = bVar3 + 1) {
        key_pos_offset(CONCAT11(bVar3,*(undefined *)(unaff_ER14 + 0x12)));
        puVar4 = (undefined2 *)key_pos_offset(CONCAT11(bVar3,bVar2));
        dec_swap_ptr(puVar4);
      }
      key_pos_offset((ushort)*(byte *)(unaff_ER14 + 0x12));
      puVar4 = (undefined2 *)key_pos_offset((ushort)bVar2);
      dec_swap_ptr(puVar4);
    }
  }
  else {
    dec_round_to(p,0xb);
  }
  frame_leave();
  return;
}



// 刷新显示 (lcd_request_refresh)
// 地址: 0xA15A

