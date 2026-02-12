#include "../ft_printf.h"

int put_hex(unsigned long n, int upper) {
  int len = 0;
  char *base =
      upper ? "0123456789ABCDEF" : "0123456789abcdef"; // tenary degistir

  if (n >= 16)
    len += put_hex(n / 16, upper);
  len += write(1, &base[n % 16], 1);
  return len;
}

int put_char(char c) { return write(1, &c, 1); }

int put_str(char *s) {
  int len;

  len = 0;
  if (!s)
    s = "(null)";
  while (s[len])
    len++;
  write(1, s, len);
  return len;
}

int put_signed(long n) {
  int len;

  len = 0;
  if (n < 0) {
    len += put_char('-');
    n = -n;
  }
  if (n >= 10)
    len += put_signed(n / 10);
  len += put_char((n % 10) + '0');
  return len;
}

int put_unsigned(unsigned long n) {
  int len = 0;

  if (n >= 10)
    len += put_unsigned(n / 10);
  len += put_char((n % 10) + '0');
  return len;
}
