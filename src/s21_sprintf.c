#include "s21_string.h"

int s21_sprintf(char *buffer, const char *format, ...) {
  va_list args;
  va_start(args, format);
  int printed = s21_parsing_format(buffer, (size_t)-1, format, args);
  va_end(args);
  return printed;
}

int s21_parsing_format(char *buffer, size_t size, const char *format,
                       va_list args) {
  struct buffer buf = {buffer, size, 0, 0};
  struct Flags_format flags = {0};

  while (*format) {
    if (*format != '%' || *++format == '%') {
      buffer_write(&buf, *format++);
      continue;
    }

    while (is_flag(*format)) {
      switch (*format++) {
        case '0':
          flags.FLAGS_ZEROPAD = 1;
          break;
        case '-':
          flags.FLAGS_LEFT = 1;
          break;
        case '+':
          flags.FLAGS_PLUS = 1;
          break;
        case ' ':
          flags.FLAGS_SPACE = 1;
          break;
        case '#':
          flags.FLAGS_HASH = 1;
          break;
      }
    }

    // если мы выравниваем слева то нули мы там размещать не можем //
    if (flags.FLAGS_ZEROPAD && flags.FLAGS_LEFT) {
      flags.FLAGS_ZEROPAD = 0;
    }
    if (flags.FLAGS_LEFT && flags.FLAGS_SPACE) {
      flags.FLAGS_SPACE = 0;
    }

    size_t width = format_atoz(&format);
    size_t precision = 0;
    if (*format == '*') {
      width = va_arg(args, size_t);
      format++;
    }

    if (*format == '.') {
      format++;
      if (*format == '*' && *(format + 1) != '*') {
        precision = va_arg(args, size_t);
        format++;
      } else {
        precision = format_atoz(&format);
      }
      flags.PRECISION = 1;
    }
    int s21_len = S21_INT;

    switch (*format) {
      case 'h':
        s21_len = (*++format == 'h') ? S21_CHAR : S21_SHORT;
        break;
      case 'l':
        s21_len = (*++format == 'l') ? S21_DLONG : S21_LONG;
        break;
      case 'L':
        s21_len = S21_LDOUBLE;
        format++;
        break;
    }

    switch (*format) {
      case 'd':
      case 'i':
        if (s21_len == S21_INT || s21_len == S21_LONG ||
            s21_len == S21_LDOUBLE) {
          itoa(&buf, type_definition_for_int(s21_len, args, &flags), 10, &flags,
               width, precision);
          flags_null(&flags);
        } else if (s21_len == S21_CHAR) {
          unsigned char arg = (char)va_arg(args, int);
          itoa(&buf, arg, 10, &flags, width, precision);
          flags_null(&flags);

        } else if (s21_len == S21_SHORT) {
          int arg = va_arg(args, int);
          if (arg < 0) {
            arg = -arg;
            flags.FLAGS_SIGNED = 1;
          }
          itoa(&buf, arg, 10, &flags, width, precision);
          flags_null(&flags);
          flags.FLAGS_ZEROPAD = 0;
        }
        break;
      case 'u':
      case 'o':
      case 'x':
      case 'X':

        if (s21_len == S21_INT) {
          if (*format == 'x' || *format == 'X') {
            if (*format == 'X') {
              flags.FLAGS_UPPER_X = 1;
            }
            unsigned int arg = va_arg(args, int);
            itoa(&buf, arg, 16, &flags, width, precision);
            flags_null(&flags);
          } else {
            unsigned int arg = va_arg(args, long int);
            itoa(&buf, arg, *format == 'o' ? 8 : 10, &flags, width, precision);
            flags_null(&flags);
          }
        }
        if (s21_len == S21_CHAR) {
          if (*format == 'x' || *format == 'X') {
            if (*format == 'X') {
              flags.FLAGS_UPPER_X = 1;
            }
            unsigned char arg = (char)va_arg(args, unsigned int);
            itoa(&buf, arg, 16, &flags, width, precision);
            flags_null(&flags);
          } else {
            unsigned char arg = (char)va_arg(args, unsigned int);
            itoa(&buf, arg, *format == 'o' ? 8 : 10, &flags, width, precision);
            flags_null(&flags);
          }
        } else if (s21_len == S21_SHORT) {
          if (*format == 'x' || *format == 'X') {
            if (*format == 'X') {
              flags.FLAGS_UPPER_X = 1;
            }
            unsigned short int arg = va_arg(args, unsigned int);
            itoa(&buf, arg, 16, &flags, width, precision);
            flags_null(&flags);
          } else {
            unsigned short int arg = va_arg(args, unsigned int);
            itoa(&buf, arg, *format == 'o' ? 8 : 10, &flags, width, precision);
            flags_null(&flags);
          }
        } else if (s21_len == S21_LONG) {
          if (*format == 'x' || *format == 'X') {
            if (*format == 'X') {
              flags.FLAGS_UPPER_X = 1;
            }
            unsigned long int arg = va_arg(args, unsigned long int);
            itoa(&buf, arg, 16, &flags, width, precision);
            flags_null(&flags);
          } else {
            unsigned long int arg = va_arg(args, unsigned long int);
            itoa(&buf, arg, *format == 'o' ? 8 : 10, &flags, width, precision);
            flags_null(&flags);
          }
        }
        flags.FLAGS_ZEROPAD = 0;
        flags.FLAGS_HASH = 0;
        break;

      case 'c':
        if (!flags.FLAGS_LEFT) {
          for (size_t i = 1; i < width; i++) {
            buffer_write(&buf, ' ');
          }
        }
        if (s21_len == S21_LONG)
          buffer_write(&buf, (wchar_t)va_arg(args, int));
        else {
          buffer_write(&buf, (char)va_arg(args, int));
        }
        if (flags.FLAGS_LEFT) {
          for (size_t i = 1; i < width; i++) {
            buffer_write(&buf, ' ');
          }
        }
        break;

      case 's':
        if (s21_len == S21_LONG) {
          buffer_write_str_wchar(&buf, va_arg(args, const wchar_t *), width,
                                 &flags, precision);
        } else {
          buffer_write_str(&buf, va_arg(args, const char *), width, &flags,
                           precision);
        }
        break;

      case 'f':
      case 'e':
      case 'E':
      case 'g':
      case 'G':
        flags.FLAGS_DOUBLE = 1;
        if (*format == 'e' || *format == 'E') {
          flags.EXPONENTA = 1;
        }
        if (*format == 'E') {
          flags.FLAGS_UPPER_E = 1;
        }
        if (*format == 'g') {
          flags.FLAGS_G = 1;
        }
        if (*format == 'G') {
          flags.FLAG_UPPER_G = 1;
          flags.FLAGS_G = 1;
        }
        if (s21_len == S21_LDOUBLE) {
          ftoa((long double)va_arg(args, long double),
               flags.PRECISION ? precision : 6, &buf, 10, &flags, width);
        } else {
          ftoa((long double)va_arg(args, double),
               flags.PRECISION ? precision : 6, &buf, 10, &flags, width);
        }
        flags_null(&flags);

        flags.EXPONENTA = 0;
        flags.FLAGS_ZEROPAD = 0;
        flags.FLAGS_UPPER_E = 0;
        flags.FLAGS_G = 0;
        flags.FLAG_UPPER_G = 0;
        flags.FLAG_G_E = 0;
        break;

      case 'p':
        flags.FLAGS_HASH = 0;
        flags.FLAGS_ZEROPAD = 0;
        flags.FLAG_POINTER = 1;
        itoa(&buf, (uintptr_t)va_arg(args, void *), 16, &flags, width,
             precision);
    }
    format++;
  }
  buffer_write(&buf, 0);
  // buffer[size - 1] = 0;
  return (buf.pos_buff - 1);
}

void buffer_write_str_wchar(struct buffer *buf, const wchar_t *arg,
                            size_t width, struct Flags_format *flags,
                            size_t precision) {
  char *str_temp = (char *)arg;
  size_t str_len = precision ? precision : s21_strlen(str_temp);
  if (!flags->FLAGS_LEFT) {
    for (size_t i = str_len; i < width; i++) {
      buffer_write(buf, ' ');
    }
  }

  for (size_t i = 0; i < str_len; i++) {
    buffer_write(buf, arg[i]);
  }
  if (flags->FLAGS_LEFT) {
    while (str_len++ < width) {
      buffer_write(buf, ' ');
    }
  }
}

void buffer_write_str(struct buffer *buf, const char *arg, size_t width,
                      struct Flags_format *flags, size_t precision) {
  size_t str_len = flags->PRECISION ? precision : s21_strlen(arg);
  if (!flags->FLAGS_LEFT) {
    for (size_t i = str_len; i < width; i++) {
      buffer_write(buf, ' ');
    }
  }
  for (size_t i = 0; i < str_len; i++) {
    buffer_write(buf, arg[i]);
  }
  if (flags->FLAGS_LEFT) {
    while (str_len++ < width) {
      buffer_write(buf, ' ');
    }
  }
}

void buffer_write(struct buffer *buf, char c) {
  if (buf->pos_buff < buf->size_buff) {
    buf->data[buf->pos_buff] = c;
  }
  buf->pos_buff++;
  buf->pos_buff_digit++;
}

int is_flag(int c) {
  return (c == '0' || c == '-' || c == '+' || c == ' ' || c == '#');
}

int is_digit(int c) { return (c >= '0' && c <= '9'); }

size_t format_atoz(const char **format) {
  size_t value = 0;
  while (is_digit(**format)) {
    value = (value * 10) + (**format - '0');
    (*format)++;
  }
  return value;
}

void flags_null(struct Flags_format *flags) {
  flags->FLAGS_LEFT = 0;
  flags->FLAGS_PLUS = 0;
  flags->FLAGS_SPACE = 0;
  flags->FLAGS_SIGNED = 0;
  flags->FLAGS_DOUBLE = 0;
  flags->FLAGS_UPPER_X = 0;
  flags->PRECISION = 0;
}

uintmax_t type_definition_for_int(int s21_len, va_list args,
                                  struct Flags_format *flags) {
  uintmax_t unsigned_arg = 0;

  switch (s21_len) {
    case S21_INT:
      unsigned_arg = va_arg(args, int);
      if ((long long int)unsigned_arg < 0) {
        unsigned_arg = -(unsigned long long int)unsigned_arg;
        flags->FLAGS_SIGNED = 1;
      }
      break;
    case S21_LONG:
    case S21_LDOUBLE:
      unsigned_arg = va_arg(args, signed long);
      if ((long long int)unsigned_arg < 0) {
        unsigned_arg = -(unsigned long long int)unsigned_arg;
        flags->FLAGS_SIGNED = 1;
      }
      break;
    default:
      unsigned_arg = 0;
      break;
  }
  return unsigned_arg;
}

void itoa(struct buffer *buf, uintmax_t arg, int base,
          struct Flags_format *flags, size_t width, size_t precision) {
  size_t flags_zero = 0;
  char buf_digit[1024] = {0};
  char buf_digit_zero[1024] = {0};
  struct buffer buf_digit_sc = {buf_digit, sizeof(buf_digit), 0, 0};
  struct buffer buf_zero = {buf_digit_zero, sizeof(buf_digit_zero), 0, 0};
  char sign = 0;
  if (flags->FLAGS_SIGNED) {
    sign = '-';
    buffer_write(&buf_digit_sc, sign);
    buffer_write(&buf_zero, sign);
  }
  if (sign == 0) {
    if (flags->FLAGS_SPACE) {
      sign = ' ';
      buffer_write(&buf_digit_sc, sign);
    } else if (flags->FLAGS_PLUS) {
      sign = '+';
      if (precision == 0 || flags->FLAGS_DOUBLE) {
        buffer_write(&buf_digit_sc, sign);
      } else {
        buffer_write(&buf_zero, sign);
      }
    }
  }
  buf_digit_sc.pos_buff_digit = 0;
  buf_zero.pos_buff_digit = 0;
  if (base == 16 && (flags->FLAG_POINTER || flags->FLAGS_HASH)) {
    if (precision == 0 && arg != 0) {
      buffer_write(&buf_digit_sc, '0');
      buffer_write(&buf_digit_sc, flags->FLAGS_UPPER_X ? 'X' : 'x');
    }

    buffer_write(&buf_zero, '0');
    buffer_write(&buf_zero, flags->FLAGS_UPPER_X ? 'X' : 'x');
    buf_zero.pos_buff_digit += 2;
  }
  if (flags->FLAGS_HASH) {
    if (base == 8) {
      buffer_write(&buf_digit_sc, '0');
    }
  }

  if (flags->FLAGS_SIGNED) {
    buf_digit_sc.pos_buff_digit++;
  }
  char *result = (char *)malloc(sizeof(char) * 33);
  int index = 0;
  while (arg != 0) {
    int remainder = arg % base;
    if (remainder < 10) {
      result[index++] = remainder + '0';
    } else {
      result[index++] = remainder - 10 + (flags->FLAGS_UPPER_X ? 'A' : 'a');
    }
    arg /= base;
  }
  if (index == 0) {
    result[index++] = '0';
  }
  result[index] = '\0';
  for (int i = 0, j = index - 1; i < j; i++, j--) {
    char temp = result[i];
    result[i] = result[j];
    result[j] = temp;
  }
  for (int i = 0; i < index; i++) {
    buffer_write(&buf_digit_sc, result[i]);
  }

  if (flags->PRECISION && !flags->FLAGS_DOUBLE) {
    flags_zero = 1;

    for (size_t i = (buf_digit_sc.pos_buff_digit);
         i <= precision - (!sign ? 1 : 0) - (flags->FLAGS_PLUS ? 1 : 0); i++) {
      buffer_write(&buf_zero, '0');
    }
    s21_strcat(buf_digit_zero, buf_digit + (flags->FLAGS_SIGNED ? 1 : 0));
    if (flags->FLAGS_PLUS) {
      buf_digit_sc.pos_buff_digit++;
    }
    buf_zero.pos_buff_digit += buf_digit_sc.pos_buff_digit;
    buf_digit_sc.pos_buff_digit = buf_zero.pos_buff_digit;
  }

  free(result);
  if (!flags->FLAGS_DOUBLE) {
    if (!flags->FLAGS_LEFT) {
      while (buf_digit_sc.pos_buff_digit++ < width) {
        buffer_write(buf, ' ');
      }
    }

    {
      for (size_t i = 0;
           i < (flags_zero ? buf_zero.pos_buff_digit : buf_digit_sc.pos_buff);
           i++) {
        buffer_write(buf, (flags_zero ? buf_digit_zero[i] : buf_digit[i]));
      }
    }

    while (buf_digit_sc.pos_buff_digit++ < width) {
      buffer_write(buf, ' ');
    }
  } else {
    for (size_t i = 0;
         i < (flags_zero ? buf_zero.pos_buff_digit : buf_digit_sc.pos_buff);
         i++) {
      buffer_write(buf, (flags_zero ? buf_digit_zero[i] : buf_digit[i]));
    }
  }
}

void exponenta(int *flag_plus, int *count_e, long double *n,
               struct Flags_format *flags, int *afterpoint) {
  long double k = *n;
  unsigned long long int int_part_e = 0;

  if (*n > 10) {
    *flag_plus = 1;
    long double p = 1;
    int_part_e = (unsigned long long)k;

    while ((int_part_e) > 9) {
      (*count_e)++;
      p *= 10.;
      int_part_e /= 10;
    }
    if (flags->FLAGS_G) {
      (*count_e)--;
      if ((*count_e >= (flags->PRECISION ? *afterpoint : 6))) {
        flags->EXPONENTA = 1;
        flags->FLAGS_G = 0;
        flags->FLAG_G_E = 1;
      }
    }
    if (!flags->FLAGS_G) {
      if (!flags->PRECISION) {
        *afterpoint = 6;
      }
      *n /= p;
    }
  } else if (*n > 1) {
    *flag_plus = 1;
  } else {
    if (k == 0) {
      *flag_plus = 1;
    }
    while (int_part_e == 0 && k != 0) {
      k *= 10;
      int_part_e = (unsigned long long)k;
      (*count_e)++;
    }
    if (flags->FLAGS_G) {
      if (*afterpoint > 6) {
        *afterpoint = 6;
      }
      if (*count_e >= (flags->PRECISION ? *afterpoint : 6)) {
        flags->EXPONENTA = 1;
        flags->FLAGS_G = 0;
        flags->FLAG_G_E = 1;
      }
    }
    if (!flags->FLAGS_G) {
      if (!flags->PRECISION) {
        *afterpoint = 6;
      }
      for (int i = 0; i < *count_e; i++) {
        *n *= 10;
      }
    }
  }
}

void ftoa(long double n, int afterpoint, struct buffer *buf, int base,
          struct Flags_format *flags, size_t width) {
  int afterpoint_temp = afterpoint;
  if (afterpoint == 0 && flags->FLAGS_G) {
    afterpoint = 2;
    if (flags->PRECISION) {
      afterpoint = 6;
    }
  }
  char buf_digit[128] = {0};
  struct buffer buf_digit_sc = {buf_digit, sizeof(buf_digit), 0, 0};
  int size = 30;
  int flag_sig = 0;
  if (n < 0) {
    buffer_write(&buf_digit_sc, '-');
    n = -n;
    size--;
    flag_sig = 1;
  }
  int count_e = 0;
  int flag_plus = 0;
  if (flags->EXPONENTA || flags->FLAGS_G) {
    exponenta(&flag_plus, &count_e, &n, flags, &afterpoint);
  }
  long double temp_n = n;
  if (afterpoint) {
    double multiplier = pow(10, afterpoint);
    n = round(n * multiplier) / multiplier;
  }

  buf_digit_sc.pos_buff_digit = 0;

  if (flags->PRECISION) {
    temp_n *= powf(10.0, afterpoint);
    temp_n = roundl(temp_n);
    temp_n /= powf(10.0, afterpoint);
    n = temp_n;
  }
  unsigned long long int_part = (long long)n;

  itoa(&buf_digit_sc, int_part, base, flags, width, afterpoint);

  if (afterpoint > 0 && size > 1) {
    buffer_write(&buf_digit_sc, '.');
    size--;
    double frac_part = fabsl(n) - (int_part);
    while (afterpoint > 0 && size > 1) {
      frac_part *= 10.0;
      float digit_f = (((fmod(frac_part, 10.0))));
      int digit = digit_f;
      buffer_write(&buf_digit_sc, (digit % 10) + '0');
      size--;
      afterpoint--;
    }
  }
  if (flags->FLAG_G_E) {
    buf_digit_sc.pos_buff--;
    for (size_t i = buf_digit_sc.pos_buff - 1; i > 0; i--) {
      if (buf_digit[i] == '0' || buf_digit[i] == '.') {
        buf_digit_sc.pos_buff--;
      } else {
        break;
      }
    }
    buf_digit_sc.pos_buff_digit = buf_digit_sc.pos_buff - (flag_sig ? 1 : 0);
  }
  if (flags->FLAGS_G) {
    if (!flags->PRECISION) {
      for (size_t i = 0; i < buf_digit_sc.pos_buff_digit; i++) {
        if (buf_digit[i] != '0' || buf_digit[i] != '.') {
          if (buf_digit[i] == '-') {
            afterpoint_temp++;
          }
          break;
        }
      }
    }
  }

  if (flags->FLAGS_G && !flags->FLAGS_HASH) {
    buf_digit_sc.pos_buff--;
    for (size_t i = buf_digit_sc.pos_buff; i > 0; i--) {
      if (buf_digit[i] == '0' || buf_digit[i] == '.') {
        buf_digit_sc.pos_buff--;
        if (buf_digit[i] == '.') {
          buf_digit_sc.pos_buff++;
          break;
        }
      } else {
        buf_digit_sc.pos_buff++;
        break;
      }
    }
    buf_digit_sc.pos_buff_digit = buf_digit_sc.pos_buff;
  }
  if (flags->EXPONENTA) {
    buffer_write(&buf_digit_sc,
                 flags->FLAGS_UPPER_E || flags->FLAG_UPPER_G ? 'E' : 'e');
    buffer_write(&buf_digit_sc, flag_plus ? '+' : '-');
    if (count_e < 10) {
      buffer_write(&buf_digit_sc, '0');
      buffer_write(&buf_digit_sc, count_e + '0');
    } else {
      char buf_e[2];
      int inx = 0;
      while (count_e != 0) {
        buf_e[inx] = (count_e % 10) + '0';
        count_e /= 10;
        inx++;
      }
      char temp = buf_e[0];
      buf_e[0] = buf_e[1];
      buf_e[1] = temp;
      for (int i = 0; i < 2; i++) {
        buffer_write(&buf_digit_sc, buf_e[i]);
      }
    }
  }

  if (!flags->FLAGS_LEFT) {
    while (buf_digit_sc.pos_buff_digit++ + (flag_sig ? 1 : 0) < width)
      if (flags->EXPONENTA && flags->FLAGS_ZEROPAD) {
        buffer_write(buf, '0');
      } else {
        buffer_write(buf, ' ');
      }
  }

  for (size_t i = 0; i < buf_digit_sc.pos_buff; i++) {
    buffer_write(buf, buf_digit[i]);
  }

  while (buf_digit_sc.pos_buff_digit++ + (flag_sig ? 1 : 0) < width) {
    if (flags->EXPONENTA && flags->FLAGS_ZEROPAD) {
      buffer_write(buf, '0');
    } else {
      buffer_write(buf, ' ');
    }
  }
  flags_null(flags);
}
