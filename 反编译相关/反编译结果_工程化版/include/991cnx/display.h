#ifndef _991CNX_DISPLAY_H
#define _991CNX_DISPLAY_H
#include "types.h"

/* 显示驱动：帧缓冲、像素、字形、文本绘制、状态栏（66 个函数） */

int fb_clear_rows(byte n);
int var_table0_clear(byte count);
ushort fill_screen(ushort pattern);
int clear_screen(int _a1);
int scroll_screen(char lines, int _a2);
int draw_vline(ushort pos, ushort flags);
int draw_vline2(ushort pos, ushort flags);
int draw_hline(ushort pos, ushort flags);
int draw_hline_animated(ushort pos, ushort flags);
int str_decompress_print_nop(ushort pos, char* fmt);
int draw_format_string(ushort pos, char* fmt);
ushort line_print_col0_nop(ushort col, ushort row);
int draw_blank_slot(ushort pos);
int draw_char_fast(ushort pos, byte ch);
int draw_char(ushort pos, ushort code);
int char_print_zero(undefined* p);
int px_clear(ushort pos);
int px_set(ushort pos);
int px_write(ushort pos, char clear);
ushort* glyph_get_small(ushort code, ushort* buf);
byte* glyph_get_large(ushort code, byte* buf);
int fb_write_op(ushort mask, byte* dst);
int px_or_run(byte* src, byte* dst, byte mask);
int fb_to_lcd(void);
int fb_alt_flush(void);
int fb_flush(void);
byte calc_fb_ptr(byte x, byte y, short* out);
byte calc_px_ptr(byte x, byte y, ushort* out);
int status_bits_init(void);
int status_bits_draw(void);
int draw_frame(ushort pos, short w, byte _a1, byte _a2, int _a5);
int draw_frame_edge_a(ushort pos, short w, ushort s);
int draw_frame_edge_b(ushort pos, short w, ushort s);
int draw_frame_edge_c(ushort pos, short w, ushort s);
int draw_frame_edge_d(ushort pos, short w, ushort s);
ushort frame_corner_1(char x, char y);
ushort frame_corner_2(char x, char y);
ushort frame_corner_3(char x, char y);
char frame_corner_4(char x);
int draw_label(ushort* dst, ushort num, char sel);
short draw_list_scroller(short x, ushort flag);
short draw_list_scroller2(short x, ushort flag);
byte* draw_list_scroller3(byte* p, ushort a, short b);
int draw_menu_row_bg(uchar row);
int draw_menu_row_text(byte row, char* text);
int draw_text4(ushort p1, ushort p2, ushort p3, ushort p4);
int draw_text4x(ushort pos);
int smallprint(ushort pat);
int show_press_ac(void);
int show_error_press_ac(void);
int lcd_set_status_x(void);
byte get_ram_base(void);
int menu_draw(char first);
int ui_state_init(void);
undefined2 lcd_mode_16(undefined2 v);
undefined* addr_norm(undefined* p);
int fmt_print_number(byte n);
int lcd_contrast_step(uintptr_t _a2, int _a1);
int draw_cursor_line(void);
int draw_token_rich(undefined2 a, int _a2);
byte font_class_of(byte ch);
int draw_token_plain(byte* tok, int _a2, int _a3, int _a4);
int fill_screen_mode(byte mode);
int draw_fraction_bars(void);
int set_col_areas(void);

#endif
