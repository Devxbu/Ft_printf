#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>

int put_hex(unsigned long n, int upper);
int put_char(char c);
int put_str(char *s);
int put_signed(long n);
int put_unsigned(unsigned long n);
int ft_printf(const char *, ...);

#endif