#ifndef _991CNX_OTHER_H
#define _991CNX_OTHER_H
#include "types.h"

int table_cell_addr(void);
char is_ascii_digit(byte* p);
int matrix_print_fmt(void);
int error_set_location(byte q, byte r);
byte menu_gate(void);

#endif
