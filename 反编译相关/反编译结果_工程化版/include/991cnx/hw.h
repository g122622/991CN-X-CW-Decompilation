#ifndef _991CNX_HW_H
#define _991CNX_HW_H
/* nX-U8（ClassWiz）特殊功能寄存器地址。
 * 依据：CasioEmuNeo / CasioEmuX 的 MMU 与外设实现，以及固件对 0xF000-0xF8FF 的读写。 */
#define IO_DSR          0xF000   /* DSR 数据段选择 */
#define IO_CHIP_CTRL    0xF004
#define IO_STPACP       0xF008   /* 待机接受 */
#define IO_SBYCON       0xF009   /* 待机控制 */
#define IO_INT_SRC      0xF00A
#define IO_INT_MASK     0xF010
#define IO_INT_CTRL2    0xF012
#define IO_INT_PENDING  0xF014
#define IO_INT_CTRL3    0xF018
#define IO_TIMER_INT    0xF020   /* 定时器重装值 */
#define IO_TIMER_CNT    0xF022   /* 定时器计数器 */
#define IO_TIMER_CTRL   0xF024
#define IO_PORT_CTRL    0xF028
#define IO_LCD_RANGE    0xF030
#define IO_LCD_MODE     0xF031
#define IO_LCD_CONTRAST 0xF032
#define IO_KBD_KI       0xF040   /* 键盘输入 */
#define IO_KBD_FILTER   0xF042
#define IO_KBD_KOMASK   0xF044
#define IO_KBD_KO       0xF046   /* 键盘输出 */
#define IO_LCD_VRAM     0xF800
#define IO_LCD_REFRESH  0xF816

/* 键码（低字节 KI、高字节 KO；0xFCxx 为扩展键） */
#define KEY_NONE        0x00
#define KEY_ON          0xFC24
#define KEY_MENU        0xFC25
#define KEY_LEFT        0xFC1C
#define KEY_RIGHT       0xFC1D
#define KEY_UP          0xFC1E
#define KEY_DOWN        0xFC1F
#endif
