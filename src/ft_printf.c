#include "../ft_printf.h"

static int handle_format(char c, va_list *ap) {
  if (c == 'c')
    return put_char((char)va_arg(*ap, int));
  if (c == 's')
    return put_str(va_arg(*ap, char *));
  if (c == 'd' || c == 'i')
    return put_signed((long)va_arg(*ap, int));
  if (c == 'u')
    return put_unsigned((unsigned long)va_arg(*ap, unsigned int));
  if (c == 'x')
    return put_hex((unsigned long)va_arg(*ap, unsigned int), 0);
  if (c == 'X')
    return put_hex((unsigned long)va_arg(*ap, unsigned int), 1);
  if (c == 'p') {
    void *p = va_arg(*ap, void *);
    if (!p)
      return write(1, "0x0", 3);
    return write(1, "0x", 2) + put_hex((unsigned long)p, 0);
  }
  if (c == '%')
    return put_char('%');
  return put_char('%') + put_char(c);
}

int ft_printf(const char *s, ...) {
  va_list ap;
  int total = 0;

  va_start(ap, s);
  while (*s) {
    if (*s == '%' && *(s + 1)) {
      s++;
      total += handle_format(*s, &ap);
    } else
      total += write(1, s, 1);
    s++;
  }
  va_end(ap);
  return total;
}

// Hatalar
// "%"
// "ndonaoudn%"
// "daobuo% "
// "", NULL

// src icinde olup olamaycagini kontrol et