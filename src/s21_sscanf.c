#ifndef S21_SSCANF_H
#define S21_SSCANF_H
#include "s21_string.h"

int s21_sscanf(const char *buffer, const char *frmt, ...) {
  const char *copy_buffer = buffer;
  format format[MAX_LENTH] = {0};
  int return_value = -1;
  s21_size_t left_variable = 0;
  if (s21_strlen(buffer) > 0 && s21_strlen(frmt) > 0) {
    s21_size_t err = parcer(format, frmt, &left_variable);
    va_list argc;
    s21_size_t sep = 0;
    va_start(argc, frmt);
    for (s21_size_t num = 0; num < err; ++num) {
      switch (format[num].specifer) {
        case 'c': {
          s21_sscanf_char(&buffer, argc, format[num], &sep);
          while (*frmt++ != 'c')
            ;
          if (*frmt == ' ') sep = 1;
          break;
        }
        case 's':
          s21_sscanf_string(&buffer, argc, format[num], &sep);
          while (*frmt++ != 's')
            ;
          sep = 1;
          break;
        case 'i': {
          s21_sscanf_signed_integers(&buffer, argc, format[num]);
          while (*frmt++ != 'i')
            ;
          sep = 1;
          break;
        }
        case 'd': {
          s21_sscanf_signed_integers(&buffer, argc, format[num]);
          while (*frmt++ != 'd')
            ;
          sep = 1;
          break;
        }
        case 'o': {
          format[num].system = 8;
          s21_sscanf_unsigned_integers(&buffer, argc, format[num]);
          while (*frmt++ != 'o')
            ;
          sep = 1;
          break;
        }
        case 'x': {
          format[num].system = 16;
          s21_sscanf_unsigned_integers(&buffer, argc, format[num]);
          while (*frmt++ != 'x')
            ;
          sep = 1;
          break;
        }
        case 'X': {
          format[num].system = 16;
          s21_sscanf_unsigned_integers(&buffer, argc, format[num]);
          while (*frmt++ != 'X')
            ;
          sep = 1;
          break;
        }
        case 'n': {
          s21_sscanf_symbols_before_n(buffer, copy_buffer, argc, frmt);
          left_variable++;
          while (*frmt++ != 'n')
            ;
          break;
        }
        case 'p': {
          format[num].system = 16;
          s21_sscanf_address(&buffer, argc, format[num]);
          sep = 1;
          while (*frmt++ != 'p')
            ;
          break;
        }
        case 'u': {
          format[num].system = 10;
          s21_sscanf_unsigned_integers(&buffer, argc, format[num]);
          sep = 1;
          while (*frmt++ != 'u')
            ;
          break;
        }
        case 'f': {
          s21_sscanf_double(&buffer, argc, format[num]);
          sep = 1;
          while (*frmt++ != 'f')
            ;
          break;
        }
        case 'e': {
          s21_sscanf_double(&buffer, argc, format[num]);
          sep = 1;
          while (*frmt++ != 'e')
            ;
          break;
        }
        case 'E': {
          s21_sscanf_double(&buffer, argc, format[num]);
          sep = 1;
          while (*frmt++ != 'E')
            ;
          break;
        }
        case 'g': {
          s21_sscanf_double(&buffer, argc, format[num]);
          sep = 1;
          while (*frmt++ != 'g')
            ;
          break;
        }
        case 'G': {
          s21_sscanf_double(&buffer, argc, format[num]);
          sep = 1;
          while (*frmt++ != 'G')
            ;
          break;
        }
        case '%': {
          sep = 1;
          percent(&buffer);
          while (*frmt++ != '%')
            ;
          break;
        }
        default:
          break;
      }
    }
    va_end(argc);
    return_value = err - left_variable;
  }
  return return_value;
}

void percent(const char **buffer) {
  if (**buffer == ' ') ++(*buffer);
  // char *result = va_arg(argc, char *);
  // *result = '%';
  ++(*buffer);
  // printf("%c\n",*result);
}

void s21_sscanf_string(const char **buffer, va_list argc, format format,
                       s21_size_t *separator) {
  wchar_t str[MAX_LENTH];
  wchar_t *px = str;
  if ((**buffer == ' ' || **buffer == '\t' || **buffer == '\n') &&
      *separator == 1)
    ++(*buffer);
  while (**buffer == ' ') ++(*buffer);
  unsigned width = 0;
  unsigned valid_size = string_to_dec_int(format.with);
  if (valid_size == 0) valid_size = s21_strlen(*buffer);
  while (**buffer != ' ' &&
         (**buffer != '\0' && **buffer != '\t' && **buffer != '\n') &&
         width++ != valid_size) {
    *px++ = **buffer;
    ++(*buffer);
  }
  *px = '\0';
  if (format.point == 0) check_length_string(str, format, argc);
}

void check_length_string(wchar_t *c, format format, va_list argc) {
  if (format.length == 'l') {
    wchar_t *res = va_arg(argc, wchar_t *);
    copy_wchar(res, c);
  } else if (format.length == 0) {
    char *res = va_arg(argc, char *);
    copy_wchar_char(res, c);
  }
}

void copy_wchar(wchar_t *src, wchar_t *str) {
  while (*str) {
    *src++ = *str++;
  }
  *src = '\0';
}
void copy_wchar_char(char *src, const wchar_t *str) {
  while (*str) {
    *src++ = (char)*str++;
  }
  *src = '\0';
}

void s21_sscanf_char(const char **buffer, va_list argc, format format,
                     s21_size_t *separator) {
  wchar_t c;
  if (**buffer == ' ' && *separator == 1) ++(*buffer);
  if (**buffer != '\0') {
    c = (**buffer);
  }
  *buffer += 1;
  *separator = 0;
  if (format.point == 0) check_length_char(c, format, argc);
}

void check_length_char(wchar_t c, format format, va_list argc) {
  if (format.length == 'l') {
    wchar_t *res = va_arg(argc, wchar_t *);
    *res = c;
  } else if (format.length == 0) {
    char *res = va_arg(argc, char *);
    *res = c;
  }
}

void s21_sscanf_symbols_before_n(const char *buffer, const char *copy_buffer,
                                 va_list argc, const char *frmt) {
  int n = 0;
  for (s21_size_t i = 0; i < s21_strlen(frmt); i++) {
    if (buffer[i] == frmt[i])
      n++;
    else
      break;
  }
  int *pointer = va_arg(argc, int *);
  *pointer = buffer - copy_buffer + n;
}

void read_string_number(const char **buffer, format format, char *px,
                        int *sign) {
  while (**buffer == ' ' || **buffer == '\n') *buffer += 1;
  if (**buffer == '+') {
    (*buffer)++;
    *sign = 1;
  } else if (**buffer == '-') {
    (*buffer)++;
    *sign = -1;
  }
  int flag_exp = 0;
  unsigned width = 0;
  unsigned valid_size = string_to_dec_int(format.with) + (*sign == 1 ? 0 : -1);
  if (valid_size == 0) valid_size = s21_strlen(*buffer);
  while (**buffer != ' ' && **buffer != '\0' && **buffer != '%' &&
         width++ != valid_size) {
    *px++ = **buffer;
    *buffer += 1;
    if (**buffer == 'E' || **buffer == 'e')
      flag_exp = 1;
    else if ((**buffer == '+' || **buffer == '-') && flag_exp == 0)
      break;
  }
  //(*buffer)++;
  *px = '\0';
}

void s21_sscanf_address(const char **buffer, va_list argc, format format) {
  char str_numbers[MAX_LENTH];
  char *px = str_numbers;
  int sign = 1;
  read_string_number(buffer, format, px, &sign);
  if (format.point == 0) {
    void **pointer = va_arg(argc, void **);
    unsigned long result = unsigned_with_system_int2dec(str_numbers, format);
    *pointer = (void *)(0x0 + result);
  }
}

void s21_sscanf_signed_integers(const char **buffer, va_list argc,
                                format format) {
  int sign = 1;
  char str_numbers[MAX_LENTH];
  char *px = str_numbers;
  read_string_number(buffer, format, px, &sign);
  long long result = signed_int2dec(str_numbers);
  result *= sign;
  if (format.point == 0) check_length_signed(result, format, argc);
}

void s21_sscanf_double(const char **buffer, va_list argc, format format) {
  int sign = 1;
  char str_numbers[MAX_LENTH];
  char *px = str_numbers;
  read_string_number(buffer, format, px, &sign);
  long double result = scientific_to_double(str_numbers);
  result *= sign;
  if (format.point == 0) check_length_double(result, format, argc);
}

void check_length_double(long double result, format format, va_list argc) {
  if (format.length == 'L') {
    long double *n = va_arg(argc, long double *);
    *n = result;
  } else {
    float *n = va_arg(argc, float *);
    *n = (double)result;
  }
}

void check_length_signed(long result, format format, va_list argc) {
  if (format.length == 'l') {
    long int *n = va_arg(argc, long int *);
    *n = (long)result;
  } else if (format.length == 'h') {
    short *n = va_arg(argc, short int *);
    *n = (short)result;
  } else {
    int *n = va_arg(argc, int *);
    *n = (int)result;
  }
}

void check_length_unsigned(long result, format format, va_list argc) {
  if (format.length == 'l') {
    unsigned long int *n = va_arg(argc, unsigned long int *);
    *n = (unsigned long)result;
  } else if (format.length == 'h') {
    unsigned short *n = va_arg(argc, unsigned short int *);
    *n = (unsigned short)result;
  } else {
    unsigned int *n = va_arg(argc, unsigned int *);
    *n = (unsigned int)result;
  }
}

void s21_sscanf_unsigned_integers(const char **buffer, va_list argc,
                                  format format) {
  char str_numbers[MAX_LENTH];
  char *px = str_numbers;
  int sign = 1;
  read_string_number(buffer, format, px, &sign);
  unsigned long result =
      unsigned_with_system_int2dec(str_numbers, format) * sign;
  if (format.point == 0) check_length_unsigned(result, format, argc);
}

s21_size_t parcer(format *format, const char *str, s21_size_t *left_variable) {
  const char Specifiers[] = "cdieEfgGosuxXpn";
  const char Length[] = "hlL";
  s21_size_t i = -1;
  int percent_repeat = 0;
  int j = 0;
  while (*str) {
    if (*str == '%') {
      percent_repeat++;
      if (percent_repeat <= 1) i++;
      j = 0;
      if (percent_repeat == 2) {
        (*left_variable)++;
        format[i].specifer = *str;
        percent_repeat = 0;
      }
    } else if (s21_strchr(Specifiers, *str)) {
      format[i].specifer = *str;
      percent_repeat = 0;
    } else if (s21_strchr(Length, *str)) {
      format[i].length = *str;
    } else if (*str - '0' >= 0 && *str - '0' <= 9) {
      format[i].with[j] = *str;
      j++;
      format[i].with[j] = '\0';
    } else if (*str == '*') {
      format[i].point = 1;
      (*left_variable)++;
    }
    ++str;
  }
  return i + 1;
}

unsigned int check_calculus_system(const char *str) {
  unsigned system = 0;
  if (s21_strlen(str) > 2 && str[0] == '0' &&
      (str[1] == 'x' || str[1] == 'X') && is_valid_hex_string(str))
    system = 16;
  else if (s21_strlen(str) > 1 && str[0] == '0' && is_valid_oct_string(str)) {
    system = 8;
  } else if (is_valid_dec_string(str))
    system = 10;
  return system;
}

unsigned int is_valid(const char *str, unsigned int system) {
  unsigned size = 0;
  switch (system) {
    case 8: {
      while (*str++ != '\0' && is_valid_octal(*str)) {
        size++;
      }
      break;
    }
    case 16: {
      while (*str++ != '\0' && is_valid_hex(*str)) {
        size++;
      }
      break;
    }
  }
  return size;
}
int is_valid_hex(const char hex) {
  int bool_ = 1;
  if (!((hex >= '0' && hex <= '9') || (hex >= 'a' && hex <= 'f') ||
        (hex >= 'A' && hex <= 'F') || hex == 'x' || hex == 'X'))
    bool_ = 0;
  return bool_;
}

int is_valid_octal(const char oct) {
  int bool_ = 1;
  if (!((oct >= '0' && oct <= '7'))) bool_ = 0;
  return bool_;
}

unsigned is_valid_hex_string(const char *hex) {
  unsigned bool_ = 1;
  for (s21_size_t i = 0; i < s21_strlen(hex); ++i)
    if (!((hex[i] >= '0' && hex[i] <= '9') ||
          (hex[i] >= 'a' && hex[i] <= 'f') ||
          (hex[i] >= 'A' && hex[i] <= 'Z') || hex[i] == 'x'))
      bool_ = 0;
  return bool_;
}

unsigned is_valid_dec_string(const char *hex) {
  unsigned bool_ = 1;
  for (s21_size_t i = 0; i < s21_strlen(hex); ++i)
    if (!((hex[i] >= '0' && hex[i] <= '9'))) bool_ = 0;
  return bool_;
}

unsigned is_valid_oct_string(const char *oct) {
  unsigned bool_ = 1;
  for (s21_size_t i = 0; i < s21_strlen(oct); ++i)
    if (!((oct[i] >= '0' && oct[i] <= '9'))) bool_ = 0;
  return bool_;
}

unsigned int char2int(char chr) {
  int bool_ = 0;
  if (chr >= '0' && chr <= '9') {
    chr = chr - '0';
    bool_ = 1;
  } else if (chr >= 'A' && chr <= 'Z') {
    chr = chr - 'A' + 10;
    bool_ = 1;
  } else if (chr >= 'a' && chr <= 'z') {
    chr = chr - 'a' + 10;
    bool_ = 1;
  }
  return bool_ == 1 ? chr : 0;
}
unsigned long string_to_dec_int(const char *str) {
  unsigned long dec = 0;
  for (s21_size_t j = 0, i = s21_strlen(str) - 1; j < s21_strlen(str);
       ++j, --i) {
    dec += char2int(str[j]) * pow(10, i);
  }
  return dec;
}

// long double string_to_double(const char *str) {
//   long double integer_part = 0;
//   s21_size_t size_before_point = 0;
//   for (; size_before_point < s21_strlen(str); ++size_before_point) {
//     if (str[size_before_point] == '.') break;
//   }
//   for (
//       struct {
//         s21_size_t j;
//         s21_size_t i;
//       } index = {size_before_point - 1, 0};
//       index.i < size_before_point; index.i++, index.j--) {
//     integer_part += char2int(str[index.i]) * pow(10, index.j);
//   }
//   for (
//       struct {
//         s21_size_t j;
//         s21_size_t i;
//       } index = {1, size_before_point + 1};
//       index.i < s21_strlen(str); index.i++, index.j++) {
//     integer_part += char2int(str[index.i]) * 1. / pow(10, index.j);
//   }
//   return integer_part;
// }

long double scientific_to_double(char *str) {
  long double num = 0.0;
  int exp_sign = 1;
  int exp_value = 0;
  char *p = str;
  // Читаем целую часть числа
  while (*p >= '0' && *p <= '9') {
    num = num * 10.0 + (long double)(*p - '0');
    ++p;
  }
  // Читаем дробную часть числа
  if (*p == '.') {
    ++p;
    long double frac = 0.1;
    while (*p >= '0' && *p <= '9') {
      num += frac * (*p - '0');
      frac *= 0.1;
      ++p;
    }
  }
  // Читаем экспоненту числа
  if (*p == 'e' || *p == 'E') {
    ++p;
    if (*p == '-') {
      exp_sign = -1;
      ++p;
    } else if (*p == '+') {
      ++p;
    }
    while (*p >= '0' && *p <= '9') {
      exp_value = exp_value * 10 + (*p - '0');
      ++p;
    }
  }
  // Применяем знак, экспоненту и возвращаем результат
  num *= pow(10.0, exp_sign * exp_value);
  return num;
}

long int signed_int2dec(const char *hex) {
  long long int dec = 0;
  unsigned int system = check_calculus_system(hex);
  unsigned delta = 0;
  if (system == 8 || system == 16) {
    if (system == 16 &&
        (s21_strcspn(hex, "0x") == 0 || s21_strcspn(hex, "0X") == 0))
      delta = 2;
    else if (system == 8 && hex[0] == '0')
      delta = 1;
    int size_of_valid = is_valid(hex, system) + 1;
    for (int j = delta, i = size_of_valid - delta - 1; j < size_of_valid;
         ++j, --i) {
      dec += char2int(hex[j]) * pow(system, i);
    }
  } else if (system == 10) {
    for (s21_size_t j = 0, i = s21_strlen(hex) - 1; j < s21_strlen(hex);
         ++j, --i) {
      dec += char2int(hex[j]) * powl(system, i);
    }
  } else
    dec = 1;
  return dec;
}

unsigned long unsigned_with_system_int2dec(const char *str, format format) {
  unsigned long dec = 0;
  unsigned delta = 0;
  if (format.system == 8) {
    int size_of_valid = is_valid(str, format.system) + 1;
    if (s21_strlen(str) > 1 && str[0] == '0') delta = 1;
    for (int j = delta, i = size_of_valid - delta - 1; j < size_of_valid;
         ++j, --i) {
      dec += char2int(str[j]) * pow(format.system, i);
    }
  } else if (format.system == 10) {
    dec = string_to_dec_int(str);
  } else if (format.system == 16) {
    int size_of_valid = is_valid(str, format.system) + 1;
    if (s21_strcspn(str, "0x") == 0) delta = 2;
    for (int j = delta, i = size_of_valid - delta - 1; j < size_of_valid;
         ++j, --i) {
      dec += char2int(str[j]) * pow(format.system, i);
    }
  }
  return dec;
}
#endif
