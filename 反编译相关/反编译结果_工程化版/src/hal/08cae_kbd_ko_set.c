/*
 * 硬件抽象层 / 08cae_kbd_ko_set.c
 * 地址范围: 0x08CAE - 0x09358
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 把键盘输出 0xF044 设为 0x80、0xF045 设为 0xFF（KO 全拉低），返回…
 * @addr 0x08CAE
 * @module hal
 * @proto undefined2 kbd_ko_set(undefined2 v)
 * @confidence verified
 * @note 把键盘输出 0xF044 设为 0x80、0xF045 设为 0xFF（KO 全拉低），返回参数。
 * @tag kbd
 */
undefined2 kbd_ko_set(undefined2 v)

{
  kbd_komask = 0x80;
  _DAT_ram_f045 = 0xff;
  return v;
}

/**
 * @brief 判断是否为扩展键（高字节 0xFC）
 * @addr 0x08D5E
 * @module hal
 * @proto short key_is_extended(ushort key)
 * @confidence likely
 * @note 判断是否为扩展键（高字节 0xFC）；key==0 或 0xFC42..0xFC5F 范围内返回 0。
 * @tag kbd
 */
short key_is_extended(ushort key)

{
  byte bVar1;
  
  bVar1 = (byte)((ushort)key >> 8);
  if ((key != 0) &&
     (((bVar1 != 0xfc || (key == -0x3be)) || ((0x4d < (byte)key && ((byte)key < 0x60))))
     )) {
    return CONCAT11(bVar1,1);
  }
  return (ushort)bVar1 << 8;
}

/**
 * @brief 若键码为 0xFC01 或 0xFC31..0xFC3B 区间则返回 0xFC01，否则返回…
 * @addr 0x08D7E
 * @module hal
 * @proto short key_is_menu_key(ushort key)
 * @confidence likely
 * @note 若键码为 0xFC01 或 0xFC31..0xFC3B 区间则返回 0xFC01，否则返回 0。
 * @tag kbd
 */
short key_is_menu_key(ushort key)

{
  byte bVar1;
  byte bVar3;
  undefined2 uVar2;
  
  bVar3 = (byte)((ushort)key >> 8);
  if ((key != 0) && (bVar3 == 0xfc)) {
    bVar1 = (byte)key;
    if (bVar1 != 0x31) {
      if ((char)((bVar1 < 0x36) << 7) < '\0') goto code_s0x008d7a;
      if (0x3b < bVar1) {
        uVar2 = return_zero();
        return uVar2;
      }
    }
    return 0xfc01;
  }
code_s0x008d7a:
  return (ushort)bVar3 << 8;
}

/**
 * @brief 键码 0xFC26 特殊判断，否则转 is_up_down
 * @addr 0x08DF6
 * @module hal
 * @proto short key_is_value(ushort key)
 * @confidence likely
 * @note 键码 0xFC26 特殊判断，否则转 is_up_down。
 * @tag kbd
 */
short key_is_value(ushort key)

{
  char cVar2;
  undefined2 uVar1;
  
  cVar2 = (char)((ushort)key >> 8);
  if (key != -0x3da) {
    uVar1 = is_up_down((char)key,cVar2);
    return uVar1;
  }
  return CONCAT11(cVar2,1);
}

/**
 * @brief 0xD116 低 4 位为 3 或 5 时返回 1
 * @addr 0x08E04
 * @module hal
 * @proto char is_modifier_3_5(void)
 * @confidence strong
 * @note 0xD116 低 4 位为 3 或 5 时返回 1。
 * @tag kbd
 */
char is_modifier_3_5(void)

{
  undefined uVar1;
  
  if (((key_modifiers & 0xf) != 3) && ((key_modifiers & 0xf) != 5)) {
    uVar1 = return_false();
    return uVar1;
  }
  return 1;
}

/**
 * @brief 0xD116 低 4 位为 1 时返回 1
 * @addr 0x08E14
 * @module hal
 * @proto char is_modifier_1(void)
 * @confidence strong
 * @note 0xD116 低 4 位为 1 时返回 1。
 * @tag kbd
 */
char is_modifier_1(void)

{
  undefined uVar1;
  
  if ((key_modifiers & 0xf) != 1) {
    uVar1 = return_false();
    return uVar1;
  }
  return 1;
}

/**
 * @brief hi==0xFC 且 0x1C<lo<0x20 时返回 1（方向键）
 * @addr 0x08E22
 * @module hal
 * @proto byte is_arrow_key(byte lo, char hi)
 * @confidence verified
 * @note hi==0xFC 且 0x1C<lo<0x20 时返回 1（方向键）。
 * @tag kbd
 */
byte is_arrow_key(byte lo, char hi)

{
  if (((hi == -4) && (0x1b < lo)) && (lo < 0x20)) {
    return 1;
  }
  return 0;
}

/**
 * @brief hi==0xFC 且 lo 为 0x1C/0x1D（左右键）时返回 1
 * @addr 0x08E36
 * @module hal
 * @proto byte is_left_right(byte lo, char hi)
 * @confidence verified
 * @note hi==0xFC 且 lo 为 0x1C/0x1D（左右键）时返回 1。
 * @tag kbd
 */
byte is_left_right(byte lo, char hi)

{
  undefined uVar1;
  
  if (hi != -4) {
    return 0;
  }
  if ((lo != '\x1c') && (lo != '\x1d')) {
    uVar1 = return_false();
    return uVar1;
  }
  return 1;
}

/**
 * @brief hi==0xFC 且 lo 为 0x1E/0x1F（上下键）时返回 1
 * @addr 0x08E44
 * @module hal
 * @proto byte is_up_down(byte lo, char hi)
 * @confidence verified
 * @note hi==0xFC 且 lo 为 0x1E/0x1F（上下键）时返回 1。
 * @tag kbd
 */
byte is_up_down(byte lo, char hi)

{
  undefined uVar1;
  
  if (hi != -4) {
    return 0;
  }
  if ((lo != '\x1f') && (lo != '\x1e')) {
    uVar1 = return_false();
    return uVar1;
  }
  return 1;
}

/**
 * @brief hi==0xFC 且 0x20<lo<0x24 时返回 1
 * @addr 0x08E52
 * @module hal
 * @proto byte is_key_20_23(byte lo, char hi)
 * @confidence verified
 * @note hi==0xFC 且 0x20<lo<0x24 时返回 1。
 * @tag kbd
 */
byte is_key_20_23(byte lo, char hi)

{
  if (((hi == -4) && (0x1f < lo)) && (lo < 0x24)) {
    return 1;
  }
  return 0;
}

/**
 * @brief hi==0xFC 且 0x12<lo<0x16 时返回 1
 * @addr 0x08E60
 * @module hal
 * @proto byte is_key_12_15(byte lo, char hi)
 * @confidence verified
 * @note hi==0xFC 且 0x12<lo<0x16 时返回 1。
 * @tag kbd
 */
byte is_key_12_15(byte lo, char hi)

{
  if (((hi == -4) && (0x11 < lo)) && (lo < 0x16)) {
    return 1;
  }
  return 0;
}

/**
 * @brief 在 ROM 0x5896 的键码表中查找 k
 * @addr 0x08E80
 * @module hal
 * @proto undefined2 key_filter_lookup4(undefined2 k)
 * @confidence strong
 * @note 在 ROM 0x5896 的键码表中查找 k：找到返回 0，遇 0 结束返回 k。
 * @tag kbd
 */
undefined2 key_filter_lookup4(undefined2 k)

{
  short sVar1;
  short *psVar2;
  
  psVar2 = (short *)0x5896;
  do {
    sVar1 = *psVar2;
    psVar2 = psVar2 + 1;
    if (sVar1 == 0) {
      return k;
    }
  } while (sVar1 != k);
  return 0;
}

/**
 * @brief 按模式选择过滤表（0x7DDA/0x5A92/0x52E8）的键过滤入口
 * @addr 0x08E88
 * @module hal
 * @proto short key_filter_mode(short key)
 * @confidence strong
 * @note 按模式选择过滤表（0x7DDA/0x5A92/0x52E8）的键过滤入口。
 * @tag kbd
 */
short key_filter_mode(short key)

{
  short sVar1;
  short *psVar2;
  
  if (calc_mode == '\r') {
    psVar2 = (short *)&keytab_filter5;
  }
  else {
    if (calc_mode == -0x3c) {
      key = key_filter_52e8(key);
    }
    psVar2 = (short *)&keytab_menu;
  }
  do {
    sVar1 = *psVar2;
    psVar2 = psVar2 + 1;
    if (sVar1 == 0) {
      return key;
    }
  } while (sVar1 != key);
  return 0;
}

/**
 * @brief 按键白名单过滤（表 0x582C）
 * @addr 0x08EB0
 * @module hal
 * @proto short key_filter_582c(short key)
 * @confidence verified
 * @note 按键白名单过滤（表 0x582C）。
 * @tag kbd
 */
short key_filter_582c(short key)

{
  short sVar1;
  short *psVar2;
  
  psVar2 = (short *)0x582c;
  do {
    sVar1 = *psVar2;
    psVar2 = psVar2 + 1;
    if (sVar1 == 0) {
      return key;
    }
  } while (sVar1 != key);
  return 0;
}

/**
 * @brief 按键白名单过滤（表 0x52E8）
 * @addr 0x08EB8
 * @module hal
 * @proto short key_filter_52e8(short key)
 * @confidence verified
 * @note 按键白名单过滤（表 0x52E8）。
 * @tag kbd
 */
short key_filter_52e8(short key)

{
  short sVar1;
  short *psVar2;
  
  psVar2 = (short *)0x52e8;
  do {
    sVar1 = *psVar2;
    psVar2 = psVar2 + 1;
    if (sVar1 == 0) {
      return key;
    }
  } while (sVar1 != key);
  return 0;
}

/**
 * @brief 按键白名单过滤（表 0x386C）
 * @addr 0x08EC8
 * @module hal
 * @proto short key_filter_386c(short key)
 * @confidence verified
 * @note 按键白名单过滤（表 0x386C）。
 * @tag kbd
 */
short key_filter_386c(short key)

{
  short sVar1;
  short *psVar2;
  
  psVar2 = (short *)0x386c;
  do {
    sVar1 = *psVar2;
    psVar2 = psVar2 + 1;
    if (sVar1 == 0) {
      return key;
    }
  } while (sVar1 != key);
  return 0;
}

/**
 * @brief 清零按键修饰/历史状态（0xD116..0xD119）
 * @addr 0x08FC6
 * @module hal
 * @proto void key_mod_clear(void)
 * @confidence strong
 * @note 清零按键修饰/历史状态（0xD116..0xD119）。
 * @tag kbd
 */
int key_mod_clear(void)

{
  key_modifiers = 0;
  key_history_flags = 0;
  key_hist_b = 0;
  key_hist_a = 0;
  key_hist_d = 0;
  return 0;
}

/**
 * @brief 写按键历史 0xD119
 * @addr 0x08FD0
 * @module hal
 * @proto void key_hist_set(uchar v)
 * @confidence strong
 * @note 写按键历史 0xD119。
 * @tag kbd
 */
int key_hist_set(uchar v)

{
  key_hist_b = v;
  key_hist_a = v;
  key_hist_d = v;
  return 0;
}

/**
 * @brief 调用 0x8FD0(0)（清按键历史值 0）
 * @addr 0x08FDE
 * @module hal
 * @proto void key_hist_clear0(void)
 * @confidence strong
 * @note 调用 0x8FD0(0)（清按键历史值 0）。
 * @tag kbd
 */
int key_hist_clear0(void)

{
  key_hist_set(0);
  return 0;
}

/**
 * @brief 清按键历史（0xD118/0xD148）
 * @addr 0x08FE2
 * @module hal
 * @proto void key_hist_clear(void)
 * @confidence strong
 * @note 清按键历史（0xD118/0xD148）。
 * @tag kbd
 */
int key_hist_clear(void)

{
  key_hist_a = 0;
  key_hist_d = 0;
  return 0;
}

/**
 * @brief 把当前键码写入 0xD10E
 * @addr 0x08FE6
 * @module hal
 * @proto void set_input_key(undefined2 key)
 * @confidence verified
 * @note 把当前键码写入 0xD10E。
 * @tag kbd
 */
int set_input_key(undefined2 key)

{
  input_key = key;
  return 0;
}

/**
 * @brief 定时器延时 / 进入 STOP
 * @addr 0x0916A
 * @module hal
 * @proto int delay(ushort interval)
 * @confidence verified
 * @note 定时器延时 / 进入 STOP：先写 0xF00A、清 0xF022(计数器)、0xF024=0x0101、清
 *       0xF014，再写 0xF008(STPACP)=0xA0、0xF009(SBYCON)=2 进入 STOP；随后写
 *       0xF020=interval。若 0xF042(键盘滤波) 为 0，则按 0x079E/0x010F
 *       重装并使能中断。casio-main 的 labels.txt 命名为 delay（调用处 0x913E 传入
 *       R0=0、R1=16）。
 * @tag hw
 */
int editor_action(ushort interval)

{
  if ((int_src_ctrl & 2) != 0) {
    int_src_ctrl = int_src_ctrl & 0xfd;
  }
  irq_disable();
  timer_counter = 0;
  timer_ctrl = 0x101;
  int_pending = 0;
  _DAT_ram_f015 = 0;
  stpacp = 0xa0;
  sbycon = 2;
  nop();
  nop();
  timer_interval = interval;
  if (kbd_filter == '\0') {
    timer_counter = 0;
    timer_interval = 0x79e;
    timer_ctrl = 0x10f;
    int_pending = 0;
    _DAT_ram_f015 = 0;
    irq_enable();
  }
  return 0;
}

/**
 * @brief 再次进入 STOP
 * @addr 0x09198
 * @module hal
 * @proto void timer_stop_wait(void)
 * @confidence verified
 * @note 再次进入 STOP：STPACP=0xA0、SBYCON=2、F020=0x079E、F024=0x010F。
 * @tag hw
 */
int timer_stop_wait(void)

{
  stpacp = 0xa0;
  sbycon = 2;
  nop();
  nop();
  if (kbd_filter == '\0') {
    timer_counter = 0;
    timer_interval = 0x79e;
    timer_ctrl = 0x10f;
    int_pending = 0;
    _DAT_ram_f015 = 0;
    irq_enable();
  }
  return 0;
}

/**
 * @brief 重新装载定时器（F020=0x079E、F024=0x010F、清 F014/F015）并使…
 * @addr 0x091E4
 * @module hal
 * @proto void timer_rearm(void)
 * @confidence strong
 * @note 重新装载定时器（F020=0x079E、F024=0x010F、清 F014/F015）并使能中断。
 * @tag hw
 */
int timer_rearm(void)

{
  timer_counter = 0;
  timer_interval = 0x79e;
  timer_ctrl = 0x10f;
  int_pending = 0;
  _DAT_ram_f015 = 0;
  irq_enable();
  return 0;
}

/**
 * @brief 清 F014 bit1 并再次置 STPACP=0xA0、SBYCON=2（轻量版 STOP…
 * @addr 0x091E8
 * @module hal
 * @proto void timer_clear_pending(void)
 * @confidence strong
 * @note 清 F014 bit1 并再次置 STPACP=0xA0、SBYCON=2（轻量版 STOP）。
 * @tag hw
 */
int timer_clear_pending(void)

{
  int_pending = int_pending & 0xfd;
  stpacp = 0xa0;
  sbycon = 2;
  nop();
  nop();
  return 0;
}

/**
 * @brief 读取 F014（可屏蔽中断待处理标志）
 * @addr 0x09208
 * @module hal
 * @proto byte irq_pending(void)
 * @confidence verified
 * @note 读取 F014（可屏蔽中断待处理标志）。
 * @tag hw
 */
byte irq_pending(void)

{
  return int_pending;
}

/**
 * @brief 读 0xD13A
 * @addr 0x09210
 * @module hal
 * @proto char key_flag_bit7(void)
 * @confidence likely
 * @note 读 0xD13A：若 bit7 置位返回 1，否则写 0xD13A=0x88 并返回 0x88。
 * @tag hw
 */
char key_flag_bit7(void)

{
  if ((key_flags & 0x80) == 0) {
    key_flags = 0x88;
    return 0x88;
  }
  return 1;
}

/**
 * @brief 写 0xD13A
 * @addr 0x09218
 * @module hal
 * @proto void key_flag_write(char value)
 * @confidence likely
 * @note 写 0xD13A。
 * @tag hw
 */
int key_flag_write(char value)

{
  key_flags = value;
  return 0;
}

/**
 * @brief 恒返回 1
 * @addr 0x0921E
 * @module hal
 * @proto short return_one(void)
 * @confidence verified
 * @note 恒返回 1。
 * @tag util
 */
short return_one(void)

{
  return 1;
}

/**
 * @brief 调用 0x9218 写下 0x80（状态栏退出标记）
 * @addr 0x09222
 * @module hal
 * @proto void statusbar_exit_mark(void)
 * @confidence strong
 * @note 调用 0x9218 写下 0x80（状态栏退出标记）。
 * @tag ui
 */
int statusbar_exit_mark(void)

{
  key_flag_write(0x80);
  return 0;
}

/**
 * @brief 清 0xD13A
 * @addr 0x09226
 * @module hal
 * @proto int key_flag_clear(void)
 * @confidence likely
 * @note 清 0xD13A。
 * @tag hw
 */
int key_flag_clear(void)

{
  key_flags = 0;
  return 0;
}

/**
 * @brief TB 0xD13A.7，返回 0/1
 * @addr 0x0922E
 * @module hal
 * @proto char key_flag_test7(void)
 * @confidence likely
 * @note TB 0xD13A.7，返回 0/1。
 * @tag hw
 */
char key_flag_test7(void)

{
  undefined uVar1;
  
  if ((key_flags & 0x80) != 0) {
    uVar1 = return_one();
    return uVar1;
  }
  return 0;
}

/**
 * @brief TB 0xD13A.3，返回 0/1
 * @addr 0x09236
 * @module hal
 * @proto char key_flag_test3(void)
 * @confidence likely
 * @note TB 0xD13A.3，返回 0/1。
 * @tag hw
 */
char key_flag_test3(void)

{
  undefined uVar1;
  
  if ((key_flags & 8) != 0) {
    uVar1 = return_one();
    return uVar1;
  }
  return 0;
}

/**
 * @brief 系统初始化
 * @addr 0x09242
 * @module hal
 * @proto void hw_init(void)
 * @confidence verified
 * @note 系统初始化：F00A=0x31、F028=0x17，延时循环，初始化中断/定时器/显示寄存器，F03D=7、等待 0x50
 *       tick、刷新对比度、清中断。
 * @tag hw
 */
int hw_init(void)

{
  char cVar1;
  undefined2 uVar2;
  
  int_src_ctrl = 0x31;
  port_ctrl = 0x17;
  cVar1 = '2';
  do {
    cVar1 = cVar1 + -1;
  } while (cVar1 != '\0');
  irq_mask_low_init();
  kbd_filter_off();
  port_h = 7;
  editor_action(0x50);
  timer_base_init();
  irq_stub_init();
  uVar2 = timer_stub_init();
  _DAT_ram_f041 = 0;
  kbd_ko_set(uVar2);
  kbd_ko_disable();
  return 0;
}

/**
 * @brief EI
 * @addr 0x09288
 * @module hal
 * @proto void irq_enable(void)
 * @confidence verified
 * @note EI：开可屏蔽中断。
 * @tag hw
 */
int irq_enable(void)

{
  enable_maskable_interrupts();
  return 0;
}

/**
 * @brief DI
 * @addr 0x0928C
 * @module hal
 * @proto void irq_disable(void)
 * @confidence verified
 * @note DI：关可屏蔽中断。
 * @tag hw
 */
int irq_disable(void)

{
  disable_maskable_interrupts();
  return 0;
}

/**
 * @brief F220=0x7F00、F222=0x7F00、F224=0（未识别寄存器）
 * @addr 0x09290
 * @module hal
 * @proto void irq_stub_init(void)
 * @confidence verified
 * @note F220=0x7F00、F222=0x7F00、F224=0（未识别寄存器）。
 * @tag hw
 */
int irq_stub_init(void)

{
  ext_io1 = 0x7f00;
  ext_io2 = 0x7f00;
  ext_io3 = 0;
  return 0;
}

/**
 * @brief F048=0、F04A=7、F04C=7（未识别寄存器）
 * @addr 0x092A0
 * @module hal
 * @proto int timer_stub_init(void)
 * @confidence verified
 * @note F048=0、F04A=7、F04C=7（未识别寄存器）。
 * @tag hw
 */
int timer_stub_init(void)

{
  timer_aux = 0;
  io_flag_y = 7;
  io_flag_w = 7;
  return 0;
}

/**
 * @brief F010=0x22（中断屏蔽低字节）、F012=0、F018=3
 * @addr 0x092B0
 * @module hal
 * @proto void irq_mask_low_init(void)
 * @confidence verified
 * @note F010=0x22（中断屏蔽低字节）、F012=0、F018=3。
 * @tag hw
 */
int irq_mask_low_init(void)

{
  int_mask = 0x22;
  int_ctrl2 = 0;
  int_ctrl3 = 3;
  return 0;
}

/**
 * @brief F030=4、F031=0x17、F032=0x14、F033=7、F034=9、F035=…
 * @addr 0x092DA
 * @module hal
 * @proto void timer_base_init(void)
 * @confidence verified
 * @note F030=4、F031=0x17、F032=0x14、F033=7、F034=9、F035=0x17、F036=1、F039
 *       =0。F030=屏幕范围、F031=屏幕模式、F032=对比度（见 CasioEmu 的 MMU 映射）。
 * @tag hw
 */
int timer_base_init(void)

{
  lcd_range = 4;
  port_a = 7;
  port_b = 9;
  port_c = 0x17;
  port_d = 1;
  port_e = 0;
  lcd_mode = 0x17;
  lcd_contrast = 0x14;
  return 0;
}

/**
 * @brief F032 = contrast（LCD 对比度，0..0x3F）
 * @addr 0x09304
 * @module hal
 * @proto void contrast_set(uchar contrast)
 * @confidence verified
 * @note F032 = contrast（LCD 对比度，0..0x3F）。
 * @tag hw
 */
int contrast_set(uchar contrast)

{
  lcd_contrast = contrast;
  return 0;
}

/**
 * @brief 主流程定时器基值
 * @addr 0x0930A
 * @module hal
 * @proto void timer_base_main(void)
 * @confidence strong
 * @note 主流程定时器基值：F00A=1、F030=4、F031=0x15、F033=3、F034=9、F035=0x17、F036=
 *       1、F039=0。
 * @tag hw
 */
int timer_base_main(void)

{
  int_src_ctrl = 1;
  lcd_range = 4;
  port_a = 3;
  port_b = 9;
  port_c = 0x17;
  port_d = 1;
  port_e = 0;
  lcd_mode = 0x15;
  return 0;
}

/**
 * @brief 恢复 F030..F039 的一组基值（F031=0x15）
 * @addr 0x09310
 * @module hal
 * @proto void timer_base_restore(void)
 * @confidence strong
 * @note 恢复 F030..F039 的一组基值（F031=0x15）。
 * @tag hw
 */
int timer_base_restore(void)

{
  lcd_range = 4;
  port_a = 3;
  port_b = 9;
  port_c = 0x17;
  port_d = 1;
  port_e = 0;
  lcd_mode = 0x15;
  return 0;
}

/**
 * @brief 设置屏幕模式 0xF031=0x16 并清状态位，返回参数
 * @addr 0x09346
 * @module hal
 * @proto undefined2 screen_mode_blank(undefined2 p)
 * @confidence strong
 * @note 设置屏幕模式 0xF031=0x16 并清状态位，返回参数。
 * @tag gfx
 */
undefined2 screen_mode_blank(undefined2 p)

{
  lcd_mode = 0x16;
  status_flags_clear();
  return p;
}

/**
 * @brief 清 F800/F801/F803/F811/F812/F815（状态栏/蜂鸣器位）
 * @addr 0x09358
 * @module hal
 * @proto void status_flags_clear(void)
 * @confidence strong
 * @note 清 F800/F801/F803/F811/F812/F815（状态栏/蜂鸣器位）。
 * @tag hw
 */
int status_flags_clear(void)

{
  memcpy_sym(lcd_vram, 0, sizeof lcd_vram);
  _DAT_ram_f801 = 0;
  _DAT_ram_f803 = 0;
  lcd_status_y = 0;
  lcd_status_x = 0;
  buzzer = 0;
  return 0;
}

