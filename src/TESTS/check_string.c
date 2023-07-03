#include <check.h>
#include <ctype.h>
#include <inttypes.h>
#include <limits.h>
#include <locale.h>
#include <math.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <wchar.h>

#include "../s21_string.h"

// Tests usual function
START_TEST(test_s21_strlen) {
  char str[6][50] = {"1234#fdfsd23423",        "A-1-_- A1231 asda\\=\n",
                     "ddddNice\n Nice",        "00000_____________0000",
                     "AAAAAs**sasass a d*AAA", "A-1-_- A1231 asda\\=\n"};

  printf("STRLEN\n");
  for (int i = 0; i < 5; i++) {
    ck_assert_int_eq(s21_strlen(str[i]), strlen(str[i]));
  }
}
END_TEST

START_TEST(test_s21_memset) {
  char str[6][50] = {"1234#fdfsd23423",        "A-1-_- A1231 asda\\=\n",
                     "ddddNice\n Nice",        "00000_____________0000",
                     "AAAAAs**sasass a d*AAA", "A-1-_- A1231 asda\\=\n"};
  char symb[6] = {'#', ' ', '\n', '_', '*', '$'};

  printf("MEMSET\n");
  for (int i = 0; i < 5; i++) {
    ck_assert_str_eq(s21_memset(str[i], symb[i], 5),
                     memset(str[i], symb[i], 5));
  }
}
END_TEST

START_TEST(test_s21_memchr) {
  char str[6][50] = {"1234#fdfsd23423",        "A-1-_- A1231 asda\\=\n",
                     "ddddNice\n Nice",        "00000_____________0000",
                     "AAAAAs**sasass a d*AAA", "A-1-_- A1231 asda\\=\n"};
  char symb[6] = {'#', ' ', '\n', '_', '*', '$'};

  printf("MEMCHR\n");
  for (int i = 0; i < 5; i++) {
    ck_assert(s21_memchr(str[i], symb[i], SIZE) ==
              memchr(str[i], symb[i], SIZE));
  }
}
END_TEST

START_TEST(test_s21_memcmp) {
  char str1[6][50] = {"1234#fdfsd23423",        "A-1-_- A1231 asda\\=\n",
                      "ddddNice\n Nice",        "00000___\\__________0000",
                      "AAAAAs**sasass a d*AAA", "A-1-_- A1231 asda\\=\n"};
  char str2[6][50] = {"1234#fdfsd23423",    "A-1s-31 asda\\=\n\naaan",
                      "dddAfh37ice\n Nice", "00000_____________0000",
                      "AAAAAs**s",          "A-1-_- A1231 asda\\=\n"};

  printf("MEMCMP\n");
  for (int i = 0; i < 6; i++) {
    ck_assert_int_eq(s21_memcmp(str1[i], str2[i], SIZE),
                     memcmp(str1[i], str2[i], SIZE));
  }
}
END_TEST

START_TEST(test_s21_memmove) {
  char str1[6][50] = {"1234#fdfsd23423",        "A-1-_- A1231 asda\\=\n",
                      "ddddNice\n Nice",        "00000___\\__________0000",
                      "AAAAAs**sasass a d*AAA", "A-1-_- A1231 asda\\=\n"};
  char str2[6][50] = {"1234#fdfsd23423",    "A-1s-31 asda\\=\n\naaan",
                      "dddh37iффce\n Nice", "00000_____________0000",
                      "AAAAAs**s",          "A-1-_- A1231 asda\\=\n"};

  printf("MEMMOVE\n");
  for (int i = 0; i < 6; i++) {
    ck_assert_str_eq(s21_memmove(str1[i], str2[i], SIZE),
                     memmove(str1[i], str2[i], SIZE));
  }
}
END_TEST

START_TEST(test_s21_memcpy) {
  char str1[6][50] = {"1234#fdfsd23423",        "A-1-_- A1231 asda\\=\n",
                      "ddddNice\n Nice",        "00000___\\__________0000",
                      "AAAAAs**sasass a d*AAA", "A-1-_- A1231 asda\\=\n"};
  char str2[6][50] = {"1234#fdfsd23423",    "A-1s-31 asda\\=\n\naaan",
                      "dddAfh37ice\n Nice", "00000_____________0000",
                      "AAAAAs**s",          "A-1-_- A1231 asda\\=\n"};

  printf("MEMCPY\n");
  for (int i = 0; i < 6; i++) {
    ck_assert_str_eq(s21_memcpy(str1[i], str2[i], SIZE),
                     memcpy(str1[i], str2[i], SIZE));
  }
}
END_TEST

START_TEST(test_s21_strcat) {
  char str1[6][100] = {"1234#fdfsd23423",        "A-1-_- A1231 asda\\=\n",
                       "ddddNice\n Nice",        "00000___\\__________0000",
                       "AAAAAs**sasass a d*AAA", "A-1-_- A1231 asda\\=\n"};
  char str2[6][100] = {"1234#fdfsd23423",    "A-1s-31 asda\\=\n\naaan",
                       "dddh37iффce\n Nice", "00000_____________0000",
                       "AAAAAs**s",          "A-1-_- A1231 asda\\=\n"};

  printf("STRCAT\n");
  for (int i = 0; i < 6; i++) {
    ck_assert_str_eq(s21_strcat(str1[i], str2[i]), strcat(str1[i], str2[i]));
  }
}
END_TEST

START_TEST(test_s21_strncat) {
  char str1[6][100] = {"1234#fdfsd23423",        "A-1-_- A1231 asda\\=\n",
                       "ddddNice\n Nice",        "00000___\\__________0000",
                       "AAAAAs**sasass a d*AAA", "A-1-_- A1231 asda\\=\n"};
  char str2[6][100] = {"1234#fdfsd23423",    "A-1s-31 asda\\=\n\naaan",
                       "dddh37iффce\n Nice", "00000_____________0000",
                       "AAAAAs**s",          "A-1-_- A1231 asda\\=\n"};

  printf("STRNCAT\n");
  for (int i = 0; i < 6; i++) {
    ck_assert_str_eq(s21_strncat(str1[i], str2[i], SIZE),
                     strncat(str1[i], str2[i], SIZE));
  }
}
END_TEST

START_TEST(test_s21_strchr) {
  char str[6][50] = {"1234#fdfsd23423",        "A-1-_- A1231 asda\\=\n",
                     "ddddNice\n Nice",        "00000___\\__________0000",
                     "AAAAAs**sasass a d*AAA", "A-1-_- A1231 asda\\=\n"};
  char symb[6] = {'#', ' ', '\n', '_', '*', '$'};

  printf("STRCHR\n");
  for (int i = 0; i < 6; i++) {
    ck_assert(s21_strchr(str[i], symb[i]) == strchr(str[i], symb[i]));
  }
}
END_TEST

START_TEST(test_s21_strcmp) {
  char str1[6][50] = {"1234#fdfsd23423",        "A-1-_- A1231 asda\\=\n",
                      "ddddNice\n Nice",        "00000___\\__________0000",
                      "AAAAAs**sasass a d*AAA", "A-1-_- A1231 asda\\=\n"};
  char str2[6][50] = {"1234#fdfsd23423",    "A-1s-31 asda\\=\n\naaan",
                      "dddAfh37ice\n Nice", "00000_____________0000",
                      "AAAAAs**s",          "A-1-_- A1231 asda\\=\n"};

  printf("STRCMP\n");
  for (int i = 0; i < 6; i++) {
    ck_assert_int_eq(s21_strcmp(str1[i], str2[i]), strcmp(str1[i], str2[i]));
  }
}
END_TEST

START_TEST(test_s21_strncmp) {
  char str1[6][50] = {"1234#fdfsd23423",        "A-1-_- A1231 asda\\=\n",
                      "ddddNice\n Nice",        "00000___\\__________0000",
                      "AAAAAs**sasass a d*AAA", "A-1-_- A1231 asda\\=\n"};
  char str2[6][50] = {"1234#fdfsd23423",    "A-1s-31 asda\\=\n\naaan",
                      "dddAfh37ice\n Nice", "00000_____________0000",
                      "AAAAAs**s",          "A-1-_- A1231 asda\\=\n"};

  printf("STRNCMP\n");
  for (int i = 0; i < 6; i++) {
    ck_assert_int_eq(s21_strncmp(str1[i], str2[i], SIZE),
                     strncmp(str1[i], str2[i], SIZE));
  }
}
END_TEST

START_TEST(test_s21_strcpy) {
  char str1[6][50] = {"1234#fdfsd23423",        "A-1-_- A1231 asda\\=\n",
                      "ddddNice\n Nice",        "00000___\\__________0000",
                      "AAAAAs**sasass a d*AAA", "A-1-_- A1231 asda\\=\n"};
  char str2[6][50] = {"1234#fdfsd23423",    "A-1s-31 asda\\=\n\naaan",
                      "dddAfh37ice\n Nice", "00000_____________0000",
                      "AAAAAs**s",          "A-1-_- A1231 asda\\=\n"};

  printf("STRCPY\n");
  for (int i = 0; i < 6; i++) {
    ck_assert_str_eq(s21_strcpy(str1[i], str2[i]), strcpy(str1[i], str2[i]));
  }
}
END_TEST

START_TEST(test_s21_strncpy) {
  char str1[6][50] = {"1234#fdfsd23423",        "A-1-_- A1231 asda\\=\n",
                      "ddddNice\n Nice",        "00000___\\__________0000",
                      "AAAAAs**sasass a d*AAA", "A-1-_- A1231 asda\\=\n"};
  char str2[6][50] = {"1234#fdfsd23423",    "A-1s-31 asda\\=\n\naaan",
                      "dddAfh37ice\n Nice", "00000_____________0000",
                      "AAAAAs**s",          "A-1-_- A1231 asda\\=\n"};

  printf("STRNCPY\n");
  for (int i = 0; i < 6; i++) {
    ck_assert_str_eq(s21_strncpy(str1[i], str2[i], SIZE),
                     strncpy(str1[i], str2[i], SIZE));
  }
}
END_TEST

START_TEST(test_s21_strrchr) {
  char str[6][50] = {"1234#fdfsd23423",        "A-1-_- A1231 asda\\=\n",
                     "ddddNice\n Nice",        "00000___\\__________0000",
                     "AAAAAs**sasass a d*AAA", "A-1-_- A1231 asda\\=\n"};
  char symb[6] = {'#', ' ', '\n', '_', '*', '$'};

  printf("STRRCHR\n");
  for (int i = 0; i < 6; i++) {
    ck_assert(s21_strrchr(str[i], symb[i]) == strrchr(str[i], symb[i]));
  }
}
END_TEST

START_TEST(test_s21_strspn) {
  char str1[6][50] = {"1234#fdfsd23423",        "A-1-_- A1231 asda\\=\n",
                      "ddddNice\n Nice",        "00000___\\__________0000",
                      "AAAAAs**sasass a d*AAA", "A-1-_- A1231 asda\\=\n"};
  char str2[6][50] = {"1234#fdfsd23423",    "A-1s-31 asda\\=\n\naaan",
                      "dddAfh37ice\n Nice", "00000_____________0000",
                      "AAAAAs**s",          "A-1-_- A1231 asda\\=\n"};

  printf("STRSPN\n");
  for (int i = 0; i < 6; i++) {
    ck_assert_int_eq(s21_strspn(str1[i], str2[i]), strspn(str1[i], str2[i]));
  }
}
END_TEST

START_TEST(test_s21_strstr) {
  char str1[6][50] = {"1234#fdfsd23423",        "A-1-_- A1231 asda\\=\n",
                      "ddddNice\n Nice",        "00000___\\__________0000",
                      "AAAAAs**sasass a d*AAA", "A-1-_- A1231 asda\\=\n"};
  char str2[6][50] = {"1234#fdfsd23423",    "A-1s-31 asda\\=\n\naaan",
                      "dddAfh37ice\n Nice", "00000_____________0000",
                      "AAAAAs**s",          "A-1-_- A1231 asda\\=\n"};

  printf("STRSTR\n");
  for (int i = 0; i < 6; i++) {
    ck_assert(s21_strstr(str1[i], str2[i]) == strstr(str1[i], str2[i]));
  }
}
END_TEST

START_TEST(test_s21_strcspn) {
  char str1[6][50] = {"1234#fdfsd23423",        "A-1-_- A1231 asda\\=\n",
                      "ddddNice\n Nice",        "00000___\\__________0000",
                      "AAAAAs**sasass a d*AAA", "A-1-_- A1231 asda\\=\n"};
  char str2[6][50] = {"1234#fdfsd23423",    "A-1s-31 asda\\=\n\naaan",
                      "dddAfh37ice\n Nice", "00000_____________0000",
                      "AAAAAs**s",          "A-1-_- A1231 asda\\=\n"};

  printf("STRCSPN\n");
  for (int i = 0; i < 6; i++) {
    ck_assert(s21_strcspn(str1[i], str2[i]) == s21_strcspn(str1[i], str2[i]));
  }
}
END_TEST

START_TEST(test_s21_strtok) {
  char str1[6][50] = {
      "1234#fdfsd23423",          "A- 1-_- A1231 asda\\=\n",
      "dd\ndd\n\n\nNice\n Nice",  "000_00___\\__0____0000",
      "A**AAAAs**sasass a d*AAA", "A-#1-_- ##A12#31 asda#\\=\n"};
  char str2[6][50] = {"23", " ", "\n\n\n", "__", "**", "asdaq"};

  printf("STRTOK\n");
  for (int i = 0; i < 6; i++) {
    ck_assert(s21_strtok(str1[i], str2[i]) == strtok(str1[i], str2[i]));
  }
}
END_TEST

START_TEST(test_s21_strpbrk) {
  char str1[6][50] = {
      "1234#fdfsd23423",          "A- 1-_- A1231 asda\\=\n",
      "dd\ndd\n\n\nNice\n Nice",  "000_00___\\__0____0000",
      "A**AAAAs**sasass a d*AAA", "A-#1-_- ##A12#31 asda#\\=\n"};
  char str2[6][50] = {"23", " ", "\n\n\n", "__", "**", "asdaq"};

  printf("STRPBRK\n");
  for (int i = 0; i < 6; i++) {
    ck_assert(s21_strpbrk(str1[i], str2[i]) == strpbrk(str1[i], str2[i]));
  }
}
END_TEST

// Tests sscanf
START_TEST(sscanf_flag_c_one) {
  const char format[] = "%c";
  printf("SSCANF_FLAG_C\n");
  char s21_c, c;
  const char str[] =
      "My name is Dima. I am 16 years old. I have only 1.55321321 money";
  ck_assert_int_eq(sscanf(str, format, &c), s21_sscanf(str, format, &s21_c));
  ck_assert_int_eq(c, s21_c);
}
END_TEST

START_TEST(sscanf_flag_c_two) {
  const char format[] = "%c%c";
  printf("SSCANF_FLAG_C_TWO\n");
  int n = 2;
  char def[n];
  char s21[n];
  const char str[] =
      "My name is Dima. I am 16 years old. I have only 1.55321321 money";
  ck_assert_int_eq(sscanf(str, format, &def[0], &def[1]),
                   s21_sscanf(str, format, &s21[0], &s21[1]));
  for (int i = 0; i < n; i++) {
    ck_assert_int_eq(def[i], s21[i]);
  }
}
END_TEST

START_TEST(sscanf_flag_c_three) {
  const char format[] = "%c%c%c";
  printf("SSCANF_FLAG_C_THREE\n");
  int n = 3;
  char def[n];
  char s21[n];
  const char str[] =
      "My name is Dima. I am 16 years old. I have only 1.55321321 money";
  ck_assert_int_eq(sscanf(str, format, &def[0], &def[1], &def[2]),
                   s21_sscanf(str, format, &s21[0], &s21[1], &s21[2]));
  for (int i = 0; i < n; i++) {
    ck_assert_int_eq(def[i], s21[i]);
  }
}
END_TEST

START_TEST(sscanf_flag_d) {
  const char format[] = "%d%d%d%d%d";
  printf("SSCANF_FLAG_D\n");
  int n = 5;
  int def[n];
  int s21[n];
  const char str[] = "0 123 2147483647 2147483648 -1000     ";
  ck_assert_int_eq(
      sscanf(str, format, &def[0], &def[1], &def[2], &def[3], &def[4]),
      s21_sscanf(str, format, &s21[0], &s21[1], &s21[2], &s21[3], &s21[4]));
  for (int i = 0; i < n; i++) {
    ck_assert_int_eq(def[i], s21[i]);
  }
}
END_TEST

START_TEST(sscanf_flag_i) {
  const char format[] = "%i%i%i%i%i%i%i%i";
  printf("SSCANF_FLAG_I\n");
  int n = 8;
  int def[n];
  int s21[n];
  const char str[] =
      "0 123 -2147483647 0x1Aa8 011111 0xFFFF 0123455 -0xAAAA    ";
  ck_assert_int_eq(sscanf(str, format, &def[0], &def[1], &def[2], &def[3],
                          &def[4], &def[5], &def[6], &def[7]),
                   s21_sscanf(str, format, &s21[0], &s21[1], &s21[2], &s21[3],
                              &s21[4], &s21[5], &s21[6], &s21[7]));
  for (int i = 0; i < n; i++) {
    ck_assert_int_eq(def[i], s21[i]);
  }
}
END_TEST

START_TEST(sscanf_flag_e) {
  const char format[] = "%e%e%e%e%e%e%e%e";
  printf("SSCANF_FLAG_e\n");
  int n = 8;
  float def[n];
  float s21[n];
  const char str[] =
      "321 1.0555554545423423 23343.4234324324 1.8e-3 -232.e+3 32e+3 "
      "-999999.00001 -0.555e-3";
  ck_assert_int_eq(sscanf(str, format, &def[0], &def[1], &def[2], &def[3],
                          &def[4], &def[5], &def[6], &def[7]),
                   s21_sscanf(str, format, &s21[0], &s21[1], &s21[2], &s21[3],
                              &s21[4], &s21[5], &s21[6], &s21[7]));
  for (int i = 0; i < n; i++) {
    ck_assert_float_eq(def[i], s21[i]);
  }
}
END_TEST

START_TEST(sscanf_flag_E) {
  const char format[] = "%E%E%E%E%E%E%E%E";
  printf("SSCANF_FLAG_E\n");
  int n = 8;
  float def[n];
  float s21[n];
  const char str[] =
      "99999999 1.0555554545423423 23343.4234324324 1.8e-21 -232.321333e+3 "
      "32.09090e+3 -999999.00001 -0.555e-3";
  ck_assert_int_eq(sscanf(str, format, &def[0], &def[1], &def[2], &def[3],
                          &def[4], &def[5], &def[6], &def[7]),
                   s21_sscanf(str, format, &s21[0], &s21[1], &s21[2], &s21[3],
                              &s21[4], &s21[5], &s21[6], &s21[7]));
  for (int i = 0; i < n; i++) {
    ck_assert_float_eq(def[i], s21[i]);
  }
}
END_TEST

START_TEST(sscanf_flag_f) {
  const char format[] = "%f%f%f%f%f%f%f%f";
  printf("SSCANF_FLAG_f\n");
  int n = 8;
  float def[n];
  float s21[n];
  const char str[] =
      "99999999.e-5 1.0555554545423423e+5 23343.4234324324e3 1.8e-21 "
      "-232.321333e+3 32.09090e+3 -999999.00001 -0.555e-3";
  ck_assert_int_eq(sscanf(str, format, &def[0], &def[1], &def[2], &def[3],
                          &def[4], &def[5], &def[6], &def[7]),
                   s21_sscanf(str, format, &s21[0], &s21[1], &s21[2], &s21[3],
                              &s21[4], &s21[5], &s21[6], &s21[7]));
  for (int i = 0; i < n; i++) {
    ck_assert_float_eq(def[i], s21[i]);
  }
}
END_TEST

START_TEST(sscanf_flag_g) {
  const char format[] = "%g%g%g%g%g%g%g%g";
  printf("SSCANF_FLAG_g\n");
  int n = 8;
  float def[n];
  float s21[n];
  const char str[] =
      "0000005555.e5 1.0555554545423423e-5 23343.4234324324e-33 1.8e-21 "
      "-232.321333e+3 32.09090e+3 -999999.00001 -0.555e-3";
  ck_assert_int_eq(sscanf(str, format, &def[0], &def[1], &def[2], &def[3],
                          &def[4], &def[5], &def[6], &def[7]),
                   s21_sscanf(str, format, &s21[0], &s21[1], &s21[2], &s21[3],
                              &s21[4], &s21[5], &s21[6], &s21[7]));
  for (int i = 0; i < n; i++) {
    ck_assert_float_eq(def[i], s21[i]);
  }
}
END_TEST

START_TEST(sscanf_flag_G) {
  const char format[] = "%G%G%G%G%G%G%G%G";
  printf("SSCANF_FLAG_G\n");
  int n = 8;
  float def[n];
  float s21[n];
  const char str[] =
      "0000005555.e5 1.0555554545423423321312321343242332432 "
      "23343.4234324324e-109 1.8e-21 -232.321333e+300 32.09090e+3 "
      "-999999.00001 -0.555e-3";
  ck_assert_int_eq(sscanf(str, format, &def[0], &def[1], &def[2], &def[3],
                          &def[4], &def[5], &def[6], &def[7]),
                   s21_sscanf(str, format, &s21[0], &s21[1], &s21[2], &s21[3],
                              &s21[4], &s21[5], &s21[6], &s21[7]));
  for (int i = 0; i < n; i++) {
    ck_assert_float_eq(def[i], s21[i]);
  }
}
END_TEST

START_TEST(sscanf_flag_o) {
  const char format[] = "%o%o%o%o%o%o%o%o";
  printf("SSCANF_FLAG_o\n");
  int n = 8;
  unsigned def[n];
  unsigned s21[n];
  const char str[] =
      "012312321312 1231232134777 7777321 032143243242 012312143 012 "
      "0444444444 21343";
  ck_assert_int_eq(sscanf(str, format, &def[0], &def[1], &def[2], &def[3],
                          &def[4], &def[5], &def[6], &def[7]),
                   s21_sscanf(str, format, &s21[0], &s21[1], &s21[2], &s21[3],
                              &s21[4], &s21[5], &s21[6], &s21[7]));
  for (int i = 0; i < n; i++) {
    ck_assert_uint_eq(def[i], s21[i]);
  }
}
END_TEST

START_TEST(sscanf_flag_s) {
  const char format[] = "%s%s%s%s%s%s%s%s";
  printf("SSCANF_FLAG_s\n");
  int n = 8;
  char def[n][MAX_LENTH];
  char s21[n][MAX_LENTH];
  const char str[] =
      "wqewfefsdf fsf dsf sddsf dssdsdg ds   dsdfds  dfsdsdf    ";
  ck_assert_int_eq(sscanf(str, format, def[0], def[1], def[2], def[3], def[4],
                          def[5], def[6], def[7]),
                   s21_sscanf(str, format, s21[0], s21[1], s21[2], s21[3],
                              s21[4], s21[5], s21[6], s21[7]));
  for (int i = 0; i < n; i++) {
    ck_assert_str_eq(def[i], s21[i]);
  }
}
END_TEST

START_TEST(sscanf_flag_u) {
  const char format[] = "%u%u%u%u%u%u%u%u";
  printf("SSCANF_FLAG_u\n");
  int n = 8;
  unsigned def[n];
  unsigned s21[n];
  const char str[] =
      "2147483647 4294967295 4294967299 1 32 10001000000 0444444444 21343     ";
  ck_assert_int_eq(sscanf(str, format, &def[0], &def[1], &def[2], &def[3],
                          &def[4], &def[5], &def[6], &def[7]),
                   s21_sscanf(str, format, &s21[0], &s21[1], &s21[2], &s21[3],
                              &s21[4], &s21[5], &s21[6], &s21[7]));
  for (int i = 0; i < n; i++) {
    ck_assert_uint_eq(def[i], s21[i]);
  }
}
END_TEST

START_TEST(sscanf_flag_x) {
  const char format[] = "%x%x%x%x%x%x%x%x";
  printf("SSCANF_FLAG_x\n");
  int n = 8;
  unsigned def[n];
  unsigned s21[n];
  const char str[] =
      "0xAAAAA 0x9999FF 0xABD 0x1 0x32 0x10001000000 0x111FFFFF 0xFFFF     ";
  ck_assert_int_eq(sscanf(str, format, &def[0], &def[1], &def[2], &def[3],
                          &def[4], &def[5], &def[6], &def[7]),
                   s21_sscanf(str, format, &s21[0], &s21[1], &s21[2], &s21[3],
                              &s21[4], &s21[5], &s21[6], &s21[7]));
  for (int i = 0; i < n; i++) {
    ck_assert_uint_eq(def[i], s21[i]);
  }
}
END_TEST

START_TEST(sscanf_flag_X) {
  const char format[] = "%x%x%x%x%x%x%x%x";
  printf("SSCANF_FLAG_X\n");
  int n = 8;
  unsigned def[n];
  unsigned s21[n];
  const char str[] =
      "0x999999 9000000 222AAAA99FFF 909 0x01 101010101010 0xFffbbcda 0xffff   "
      "  ";
  ck_assert_int_eq(sscanf(str, format, &def[0], &def[1], &def[2], &def[3],
                          &def[4], &def[5], &def[6], &def[7]),
                   s21_sscanf(str, format, &s21[0], &s21[1], &s21[2], &s21[3],
                              &s21[4], &s21[5], &s21[6], &s21[7]));
  for (int i = 0; i < n; i++) {
    ck_assert_uint_eq(def[i], s21[i]);
  }
}
END_TEST

START_TEST(sscanf_flag_p) {
  const char format[] = "%p";
  printf("SSCANF_FLAG_p\n");
  int n = 3;
  int a = 1;
  int *b = &a;
  int z = 3;
  int *c = &z;
  int d = 5;
  int *l = &d;
  int *def[3];
  int *s21[3];
  char str1[MAX_LENTH];
  char str2[MAX_LENTH];
  char str3[MAX_LENTH];
  sprintf(str1, "%p", b);
  sprintf(str2, "%p", c);
  sprintf(str3, "%p", l);
  ck_assert_int_eq(sscanf(str1, format, &def[0]),
                   s21_sscanf(str1, format, &s21[0]));
  ck_assert_int_eq(sscanf(str2, format, &def[1]),
                   s21_sscanf(str2, format, &s21[1]));
  ck_assert_int_eq(sscanf(str3, format, &def[2]),
                   s21_sscanf(str3, format, &s21[2]));
  for (int i = 0; i < n; i++) {
    ck_assert_ptr_eq(def[i], s21[i]);
  }
}
END_TEST

START_TEST(sscanf_flag_n) {
  const char format[] = "%d%n%s%n%s%n%i%n";
  printf("SSCANF_FLAG_n\n");
  int n = 4;
  int def[n];
  int s21[n];
  int a, s21_a;
  char str_first[MAX_LENTH];
  char s21_str_first[MAX_LENTH];
  char str_second[MAX_LENTH];
  char s21_str_second[MAX_LENTH];
  int b, s21_b;
  const char str[] = "99999 fdf ddf  0xAAAA";
  ck_assert_int_eq(
      sscanf(str, format, &a, &def[0], str_first, &def[1], str_second, &def[2],
             &b, &def[3]),
      s21_sscanf(str, format, &s21_a, &s21[0], s21_str_first, &s21[1],
                 s21_str_second, &s21[2], &s21_b, &s21[3]));
  for (int i = 0; i < n; i++) {
    ck_assert_int_eq(def[i], s21[i]);
  }
  ck_assert_int_eq(a, s21_a);
  ck_assert_int_eq(b, s21_b);
  ck_assert_str_eq(str_first, s21_str_first);
  ck_assert_str_eq(str_second, s21_str_second);
}
END_TEST

START_TEST(sscanf_flag_wigth) {
  const char format[] = "%15s%5s%s%1s";
  printf("SSCANF_FLAG_wight\n");
  int n = 4;
  char def[n][MAX_LENTH];
  char s21[n][MAX_LENTH];
  const char str[] = "abcdabncddfsdfsfdsgfdg sfsg gfr defw 15 1.6e-4";
  ck_assert_int_eq(sscanf(str, format, def[0], def[1], def[2], def[3]),
                   s21_sscanf(str, format, s21[0], s21[1], s21[2], s21[3]));
  for (int i = 0; i < n; i++) {
    ck_assert_str_eq(def[i], s21[i]);
  }
}
END_TEST

START_TEST(sscanf_flag_star) {
  const char format[] = "%15s%300s%*s%1s";
  printf("SSCANF_FLAG_star\n");
  int n = 3;
  char def[n][MAX_LENTH];
  char s21[n][MAX_LENTH];
  const char str[] = "abcdabncddfsdfsfdsgfdg sfsg gfr defw 15 1.6e-4";
  ck_assert_int_eq(sscanf(str, format, def[0], def[1], def[2]),
                   s21_sscanf(str, format, s21[0], s21[1], s21[2]));
  for (int i = 0; i < n; i++) {
    ck_assert_str_eq(def[i], s21[i]);
  }
}
END_TEST

START_TEST(sscanf_flag_lenght) {
  const char format[] = "%hd %hi %ho %hu %hx %hX";
  printf("SSCANF_FLAG_length_short\n");
  int n = 6;
  short def[n];
  short s21[n];
  const char str[] = "32767 -32767 01111 +32132 0xAAAA 0xFFFF";
  ck_assert_int_eq(
      sscanf(str, format, &def[0], &def[1], &def[2], &def[3], &def[4], &def[5]),
      s21_sscanf(str, format, &s21[0], &s21[1], &s21[2], &s21[3], &s21[4],
                 &s21[5]));
  for (int i = 0; i < n; i++) {
    ck_assert_uint_eq(def[i], s21[i]);
  }
}
END_TEST

START_TEST(sscanf_flag_lenght_long) {
  const char format[] = "%ld %li %lo %lu %lx %lX %lc %ls";
  printf("SSCANF_FLAG_length_long\n");
  int n = 6;
  long def[n];
  long s21[n];
  wchar_t c, s21_c;
  wchar_t str_def[MAX_LENTH], s21_str[MAX_LENTH];
  const char str[] =
      "3276343434327 -32764324327 01113234241 32132 0xAAAA 0xFFFF a ABCCCCCC";
  ck_assert_int_eq(sscanf(str, format, &def[0], &def[1], &def[2], &def[3],
                          &def[4], &def[5], &c, str_def),
                   s21_sscanf(str, format, &s21[0], &s21[1], &s21[2], &s21[3],
                              &s21[4], &s21[5], &s21_c, s21_str));
  for (int i = 0; i < n; i++) {
    ck_assert_uint_eq(def[i], s21[i]);
  }
  ck_assert_int_eq(c, s21_c);
}
END_TEST

START_TEST(sscanf_flag_lenght_long_double) {
  const char format[] = "%Le %LE %Lf %Lg %LG";
  printf("SSCANF_FLAG_length_long_double\n");
  int n = 5;
  long double def[n];
  long double s21[n];
  const char str[] =
      "32763437.43223234 11132341.31312e15 32132 2131231231231.e-9 1";
  ck_assert_int_eq(
      sscanf(str, format, &def[0], &def[1], &def[2], &def[3], &def[4]),
      s21_sscanf(str, format, &s21[0], &s21[1], &s21[2], &s21[3], &s21[4]));
  ck_assert_double_eq(def[0], s21[0]);
  ck_assert_double_eq(def[1], s21[1]);
  ck_assert_double_eq(def[2], s21[2]);
  ck_assert_double_eq(def[3], s21[3]);
  ck_assert_double_eq(def[4], s21[4]);
}
END_TEST

START_TEST(sscanf_advance) {
  const char format[] = "%6s %c%*c %Lf %x %5o %3hd %d";
  printf("SSCANF_Advance\n");
  char str_def[MAX_LENTH];
  char s21_str[MAX_LENTH];
  char c, s21_c;
  long double d, s21_d;
  unsigned x_16, s21_16;
  unsigned o_8, s21_8;
  short i, s21_i;
  int int_def, s21_int;
  const char str[] = "Hello a 1666.6666e-3 0xFFFF 01232 455555 -11111";
  ck_assert_int_eq(
      sscanf(str, format, str_def, &c, &d, &x_16, &o_8, &i, &int_def),
      s21_sscanf(str, format, s21_str, &s21_c, &s21_d, &s21_16, &s21_8, &s21_i,
                 &s21_int));
  ck_assert_double_eq(d, s21_d);
  ck_assert_int_eq(c, s21_c);
  ck_assert_int_eq(x_16, s21_16);
  ck_assert_int_eq(o_8, s21_8);
  ck_assert_int_eq(i, s21_i);
  ck_assert_int_eq(int_def, s21_int);
  ck_assert_str_eq(str_def, s21_str);
}
END_TEST

// to_lower

START_TEST(lower) {
  printf("TEST : to_lower\n");
  char s1[] = "SCHOOL_21";
  char s2[] = "Dima_Shiro_GOOD";
  char s3[] = "MATVEY is so fucking BADDDD Pir";
  char s4[] = "aloHOWmushisIt";
  char s5[] = "AREyouR E A D Y???";
  char s6[] = "i Am StudenT of Gubkin University";
  char *res1 = s21_to_lower(s1);
  char *res2 = s21_to_lower(s2);
  char *res3 = s21_to_lower(s3);
  char *res4 = s21_to_lower(s4);
  char *res5 = s21_to_lower(s5);
  char *res6 = s21_to_lower(s6);
  ck_assert_msg(!strcmp(res1, "school_21"), "1 - Failed");
  ck_assert_msg(!strcmp(res2, "dima_shiro_good"), "2 - Failed");
  ck_assert_msg(!strcmp(res3, "matvey is so fucking badddd pir"), "3 - Failed");
  ck_assert_msg(!strcmp(res4, "alohowmushisit"), "4 - Failed");
  ck_assert_msg(!strcmp(res5, "areyour e a d y???"), "5 - Failed");
  ck_assert_msg(!strcmp(res6, "i am student of gubkin university"),
                "6 - Failed");
  free(res1);
  free(res2);
  free(res3);
  free(res4);
  free(res5);
  free(res6);
}
END_TEST

START_TEST(upper) {
  printf("TEST : to_upper\n");
  char s1[] = "SCHOOL_21";
  char s2[] = "Dima_Shiro_GOOD";
  char s3[] = "MATVEY is so fucking BADDDD Pir";
  char s4[] = "aloHOWmushisIt";
  char s5[] = "AREyouR E A D Y???";
  char s6[] = "i Am StudenT of Gubkin University";
  char *res1 = s21_to_upper(s1);
  char *res2 = s21_to_upper(s2);
  char *res3 = s21_to_upper(s3);
  char *res4 = s21_to_upper(s4);
  char *res5 = s21_to_upper(s5);
  char *res6 = s21_to_upper(s6);
  ck_assert_msg(!strcmp(res1, "SCHOOL_21"), "1 - Failed");
  ck_assert_msg(!strcmp(res2, "DIMA_SHIRO_GOOD"), "2 - Failed");
  ck_assert_msg(!strcmp(res3, "MATVEY IS SO FUCKING BADDDD PIR"), "3 - Failed");
  ck_assert_msg(!strcmp(res4, "ALOHOWMUSHISIT"), "4 - Failed");
  ck_assert_msg(!strcmp(res5, "AREYOUR E A D Y???"), "5 - Failed");
  ck_assert_msg(!strcmp(res6, "I AM STUDENT OF GUBKIN UNIVERSITY"),
                "6 - Failed");
  free(res1);
  free(res2);
  free(res3);
  free(res4);
  free(res5);
  free(res6);
}
END_TEST

// insert

START_TEST(insert) {
  printf("TEST : insert\n");
  char s1[] = "SCHOOL_21";
  char s2[] = "I live in ";
  char s3[] = " is the best place in the world";
  char s4[] = "_MAtvey_";
  char s5[] = "ccccccccc";
  char s6[] = "elpfulme";
  char s7[] = "ooomegood";
  char s8[] = "ooshit";
  char s9[] = "loss";
  char s10[] = "- is earth ";
  char s11[] = " - 2 is you ";
  char s12[] = " -  1 is my";
  char *res1 = s21_insert(s1, s2, 0);
  char *res2 = s21_insert(s1, s3, 9);
  char *res3 = s21_insert(s1, s4, 1);
  char *res4 = s21_insert(s1, s5, 2);
  char *res5 = s21_insert(s1, s6, 3);
  char *res6 = s21_insert(s1, s7, 4);
  char *res7 = s21_insert(s1, s8, 5);
  char *res8 = s21_insert(s1, s9, 6);
  char *res9 = s21_insert(s1, s10, 7);
  char *res10 = s21_insert(s1, s11, 8);
  char *res11 = s21_insert(s1, s12, 9);
  char *res12 = s21_insert(s1, s1, 9);
  char *res13 = s21_insert(s1, s1, -1);
  char *res14 = s21_insert(s1, s1, 100);
  ck_assert_msg(!strcmp(res1, "I live in SCHOOL_21"), "1 - Failed");
  ck_assert_msg(!strcmp(res2, "SCHOOL_21 is the best place in the world"),
                "2 - Failed");
  ck_assert_msg(!strcmp(res3, "S_MAtvey_CHOOL_21"), "3 - Failed");
  ck_assert_msg(!strcmp(res4, "SCcccccccccHOOL_21"), "4 - Failed");
  ck_assert_msg(!strcmp(res5, "SCHelpfulmeOOL_21"), "5 - Failed");
  ck_assert_msg(!strcmp(res6, "SCHOooomegoodOL_21"), "6 - Failed");
  ck_assert_msg(!strcmp(res7, "SCHOOooshitL_21"), "7 - Failed");
  ck_assert_msg(!strcmp(res8, "SCHOOLloss_21"), "8 - Failed");
  ck_assert_msg(!strcmp(res9, "SCHOOL_- is earth 21"), "9 - Failed");
  ck_assert_msg(!strcmp(res10, "SCHOOL_2 - 2 is you 1"), "10 - Failed");
  ck_assert_msg(!strcmp(res11, "SCHOOL_21 -  1 is my"), "11 - Failed");
  ck_assert_msg(!strcmp(res12, "SCHOOL_21SCHOOL_21"), "12 - Failed");
  ck_assert_msg(res13 == NULL, "13 - Failed");
  ck_assert_msg(res14 == NULL, "14 - Failed");
  free(res1);
  free(res2);
  free(res3);
  free(res4);
  free(res5);
  free(res6);
  free(res7);
  free(res8);
  free(res9);
  free(res10);
  free(res11);
  free(res12);
  free(res13);
  free(res14);
}
END_TEST

START_TEST(trim) {
  printf("TEST : trim\n");
  char s1[] = "-------++++++++VECTOR_________+++++++>>>><<<<<<<<";
  char s2[] = "--------------+><_";
  char s3[] = "VECTOR";
  char s4[] = "-";
  char s5[] = "+";
  char s6[] = ">";
  char s7[] = "<";
  char s8[] = "R_";
  char s9[] = "MAYVEY";
  char s10[] = "";
  char s11[] = "vector";
  char s12[] = "a u confidend?";
  char s13[] = "a";
  char s14[] = " ";
  char s15[] = "a ?";
  char s16[] = "M y n a m e i s I v a n H o W a b o u t y o u?";
  char s17[] = " ?";
  char *res1 = s21_trim(s1, s2);
  char *res2 = s21_trim(s1, s3);
  char *res3 = s21_trim(s1, s4);
  char *res4 = s21_trim(s1, s5);
  char *res5 = s21_trim(s1, s6);
  char *res6 = s21_trim(s1, s7);
  char *res7 = s21_trim(s1, s8);
  char *res8 = s21_trim(s1, s9);
  char *res9 = s21_trim(s1, s10);
  char *res10 = s21_trim(s1, s11);
  char *res11 = s21_trim(s12, s13);
  char *res12 = s21_trim(s12, s14);
  char *res13 = s21_trim(s12, s15);
  char *res14 = s21_trim(s12, s10);
  char *res15 = s21_trim(s16, s14);
  char *res16 = s21_trim(s16, s17);
  char *res18 = s21_trim(s1, s1);
  ck_assert_msg(!strcmp(res1, "VECTOR"), "1 - Failed");
  ck_assert_msg(
      !strcmp(res2, "-------++++++++VECTOR_________+++++++>>>><<<<<<<<"),
      "2 - Failed");
  ck_assert_msg(!strcmp(res3, "++++++++VECTOR_________+++++++>>>><<<<<<<<"),
                "3 - Failed");
  ck_assert_msg(
      !strcmp(res4, "-------++++++++VECTOR_________+++++++>>>><<<<<<<<"),
      "4 - Failed");
  ck_assert_msg(
      !strcmp(res5, "-------++++++++VECTOR_________+++++++>>>><<<<<<<<"),
      "5 - Failed");
  ck_assert_msg(!strcmp(res6, "-------++++++++VECTOR_________+++++++>>>>"),
                "6 - Failed");
  ck_assert_msg(
      !strcmp(res7, "-------++++++++VECTOR_________+++++++>>>><<<<<<<<"),
      "7 - Failed");
  ck_assert_msg(
      !strcmp(res8, "-------++++++++VECTOR_________+++++++>>>><<<<<<<<"),
      "8 - Failed");
  ck_assert_msg(
      !strcmp(res9, "-------++++++++VECTOR_________+++++++>>>><<<<<<<<"),
      "9 - Failed");
  ck_assert_msg(
      !strcmp(res10, "-------++++++++VECTOR_________+++++++>>>><<<<<<<<"),
      "10 - Failed");
  ck_assert_msg(!strcmp(res11, " u confidend?"), "11 - Failed");
  ck_assert_msg(!strcmp(res12, "a u confidend?"), "12 - Failed");
  ck_assert_msg(!strcmp(res13, "u confidend"), "13 - Failed");
  ck_assert_msg(!strcmp(res14, "a u confidend?"), "14 - Failed");
  ck_assert_msg(
      !strcmp(res15, "M y n a m e i s I v a n H o W a b o u t y o u?"),
      "15 - Failed");
  ck_assert_msg(!strcmp(res16, "M y n a m e i s I v a n H o W a b o u t y o u"),
                "16 - Failed");
  ck_assert_msg(!strcmp(res18, ""), "18 - Failed");
  free(res1);
  free(res2);
  free(res3);
  free(res4);
  free(res5);
  free(res6);
  free(res7);
  free(res8);
  free(res9);
  free(res10);
  free(res11);
  free(res12);
  free(res13);
  free(res14);
  free(res15);
  free(res16);
  free(res18);
}
END_TEST

// sprintf
#define NMAX 1024
#define AMOUNT 10

#define BUFF_SIZE 4096
// %[flags][width][.precision][length]specifier

START_TEST(test_default) {
  printf("TEST : sprintf_1\n");
  char result[20];
  char assert[20];
  s21_sprintf(result, "Count: %c", 'a');
  sprintf(assert, "Count: %c", 'a');
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default2) {
  printf("TEST : sprintf_2\n");
  char result[20];
  char assert[20];
  char c = 'b';
  s21_sprintf(result, "Count: %c", c);
  sprintf(assert, "Count: %c", c);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default3) {
  printf("TEST : sprintf_3\n");
  char result[20];
  char assert[20];
  char c = 'b';
  int a = s21_sprintf(result, "Count: %5c", c);
  int b = sprintf(assert, "Count: %5c", c);
  ck_assert_str_eq(result, assert);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_default4) {
  printf("TEST : sprintf_4\n");
  char result[20];
  char assert[20];
  char c = 'b';
  int a = s21_sprintf(result, "Count: %-5c", c);
  int b = sprintf(assert, "Count: %-5c", c);
  ck_assert_str_eq(result, assert);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_default5) {
  printf("TEST : sprintf_5\n");
  char result[20] = {'\0'};
  char assert[20] = {'\0'};
  char c = 'z';
  s21_sprintf(result, "Count: %lc", c);
  sprintf(assert, "Count: %lc", c);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default6) {
  printf("TEST : sprintf_6\n");
  char result[20];
  char assert[20];
  char c = 'a';
  s21_sprintf(result, "Count: %-3c", c);
  sprintf(assert, "Count: %-3c", c);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default7) {  // need to fix '*'
  printf("TEST : sprintf_7\n");
  char result[20];
  char assert[20];
  char c = 'a';
  s21_sprintf(result, "Count: %*c", 4, c);
  sprintf(assert, "Count: %*c", 4, c);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default8) {
  printf("TEST : sprintf_8\n");
  char result[20];
  char assert[20];
  long long d = 5717984;
  s21_sprintf(result, "Count: %Li 1", d);
  sprintf(assert, "Count: %Li 1", d);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default10) {
  printf("TEST : sprintf_9\n");
  char result[20];
  char assert[20];
  int d = 57;
  s21_sprintf(result, "Count: %d abc", d);
  sprintf(assert, "Count: %d abc", d);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default9) {
  printf("TEST : sprintf_10\n");
  char result[20];
  char assert[20];
  int d = 190;
  s21_sprintf(result, "Count: %5d", d);
  sprintf(assert, "Count: %5d", d);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default_multy) {
  printf("TEST : sprintf_11\n");
  char result[20];
  char assert[20];
  s21_sprintf(result, "Count: %d%d%d%d", -4, 8, 15, 16);
  sprintf(assert, "Count: %d%d%d%d", -4, 8, 15, 16);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_format_d) {
  printf("TEST : sprintf_12\n");
  char result[20];
  char assert[20];
  s21_sprintf(result, "Count: %1.1d", 69);
  sprintf(assert, "Count: %1.1d", 69);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_no_args) {
  printf("TEST : sprintf_13\n");
  char result[20];
  char assert[20];
  s21_sprintf(result, "Hello, world!");
  sprintf(assert, "Hello, world!");
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_flag_minus) {  // TO FIX
  printf("TEST : sprintf_14\n");
  char result[20];
  char assert[20];
  s21_sprintf(result, "Count: %-5d", 69);
  sprintf(assert, "Count: %-5d", 69);
  ck_assert_str_eq(result, assert);
}
END_TEST

// START_TEST(str_to_int_test) {
//     char s[10] = "123\0";
//     int result = str_to_int(s);
//     ck_assert_int_eq(result, 123);
// }
// END_TEST

START_TEST(test_char_default) {
  printf("TEST : sprintf_15\n");
  char c = 'B';
  char result[20];
  char assert[20];
  s21_sprintf(result, "Char: %c", c);
  sprintf(assert, "Char: %c", c);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_char_multy) {
  printf("TEST : sprintf_15\n");
  char c = 'B';
  char result[20];
  char assert[20];
  s21_sprintf(result, "Char: %c%c%c", c, c, c);
  sprintf(assert, "Char: %c%c%c", c, c, c);
  ck_assert_str_eq(result, assert);
}
END_TEST

// START_TEST(test_buffer_overflow) {
//     char result[20];
//     char assert[20];
//     s21_sprintf(result, "%d", 3000000000);
//     sprintf(assert, "%d", 3000000000);
//     ck_assert_str_eq(result, assert);
// }
// END_TEST

START_TEST(test_default11) {
  printf("TEST : sprintf_16\n");
  char result[20];
  char assert[20];
  int d = 571212;
  s21_sprintf(result, "Count: %.5d abc", d);
  sprintf(assert, "Count: %.5d abc", d);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default12) {
  printf("TEST : sprintf_17\n");
  char result[20];
  char assert[20];
  int d = 5312112;
  s21_sprintf(result, "Count: %-.5d abc", d);
  sprintf(assert, "Count: %-.5d abc", d);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default13) {
  printf("TEST : sprintf_18\n");
  char result[20];
  char assert[20];
  int d = 0;
  s21_sprintf(result, "Count: %d abc", d);
  sprintf(assert, "Count: %d abc", d);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default14) {
  char result[20];
  char assert[20];
  int d = 0;
  s21_sprintf(result, "Count: %d abc", d);
  sprintf(assert, "Count: %d abc", d);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default15) {
  char result[20];
  char assert[20];
  int d = 1;
  s21_sprintf(result, "Count: % d abc", d);
  sprintf(assert, "Count: % d abc", d);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default16) {
  char result[20];
  char assert[20];
  int d = -1;
  s21_sprintf(result, "Count: % d abc", d);
  sprintf(assert, "Count: % d abc", d);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default17) {
  char result[20];
  char assert[20];
  int d = -0;
  s21_sprintf(result, "Count: % d abc", d);
  sprintf(assert, "Count: % d abc", d);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default18) {
  char result[40];
  char assert[40];
  int d = 2147483647;
  s21_sprintf(result, "Count: % d abc", d);
  sprintf(assert, "Count: % d abc", d);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default19) {
  char result[40];
  char assert[40];
  int d = -2147483648;
  s21_sprintf(result, "Count: % d abc", d);
  sprintf(assert, "Count: % d abc", d);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default20) {
  char result[40];
  char assert[40];
  long int d = 214748364912;
  s21_sprintf(result, "Count: % ld abc", d);
  sprintf(assert, "Count: % ld abc", d);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default21) {
  char result[40];
  char assert[40];
  long int d = -9223372036854775807;
  s21_sprintf(result, "Count: % ld abc", d);
  sprintf(assert, "Count: % ld abc", d);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default22) {
  char result[40];
  char assert[40];
  long int d = 9223372036854775807;
  s21_sprintf(result, "Count: %ld abc", d);
  sprintf(assert, "Count: %ld abc", d);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default23) {
  char result[40];
  char assert[40];
  short int d = 32767;
  s21_sprintf(result, "Count: %hd abc", d);
  sprintf(assert, "Count: %hd abc", d);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default24) {
  char result[40];
  char assert[40];
  short int d = 32770;
  s21_sprintf(result, "Count: %hd end", d);
  sprintf(assert, "Count: %hd end", d);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default25) {
  char result[40];
  char assert[40];
  int d = 327710;
  s21_sprintf(result, "Count: %11.10d end", d);
  sprintf(assert, "Count: %11.10d end", d);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default26) {
  char result[20];
  char assert[20];
  int i = 57;
  s21_sprintf(result, "Count: %i 1", i);
  sprintf(assert, "Count: %i 1", i);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default27) {
  char result[20];
  char assert[20];
  int i = 57;
  s21_sprintf(result, "Count: %i abc", i);
  sprintf(assert, "Count: %i abc", i);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default28) {
  char result[20];
  char assert[20];
  int i = 190;
  s21_sprintf(result, "Count: %5i", i);
  sprintf(assert, "Count: %5i", i);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default29) {
  char result[20];
  char assert[20];
  s21_sprintf(result, "Count: %i%i%i%i", -4, 8, 15, 16);
  sprintf(assert, "Count: %i%i%i%i", -4, 8, 15, 16);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default30) {
  char result[20];
  char assert[20];
  s21_sprintf(result, "Count: %1.1i", 69);
  sprintf(assert, "Count: %1.1i", 69);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default31) {
  char result[20];
  char assert[20];
  int i = 571212;
  s21_sprintf(result, "Count: %.5i abc", i);
  sprintf(assert, "Count: %.5i abc", i);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default32) {
  char result[20];
  char assert[20];
  int i = 5312112;
  s21_sprintf(result, "Count: %-.5i abc", i);
  sprintf(assert, "Count: %-.5i abc", i);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default33) {
  char result[20];
  char assert[20];
  int i = 0;
  s21_sprintf(result, "Count: %i abc", i);
  sprintf(assert, "Count: %i abc", i);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default34) {
  char result[20];
  char assert[20];
  int i = 0;
  s21_sprintf(result, "Count: %i abc", i);
  sprintf(assert, "Count: %i abc", i);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default35) {
  char result[20];
  char assert[20];
  int i = 1;
  s21_sprintf(result, "Count: % i abc", i);
  sprintf(assert, "Count: % i abc", i);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default36) {
  char result[20];
  char assert[20];
  int i = -1;
  s21_sprintf(result, "Count: % i abc", i);
  sprintf(assert, "Count: % i abc", i);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default37) {
  char result[20];
  char assert[20];
  int i = -0;
  s21_sprintf(result, "Count: % i abc", i);
  sprintf(assert, "Count: % i abc", i);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default38) {
  char result[40];
  char assert[40];
  int i = 2147483647;
  s21_sprintf(result, "Count: % i abc", i);
  sprintf(assert, "Count: % i abc", i);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default39) {
  char result[40];
  char assert[40];
  int i = -2147483648;
  s21_sprintf(result, "Count: % i abc", i);
  sprintf(assert, "Count: % i abc", i);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default40) {
  char result[40];
  char assert[40];
  long int i = 214748364912;
  s21_sprintf(result, "Count: % li abc", i);
  sprintf(assert, "Count: % li abc", i);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default41) {
  char result[40];
  char assert[40];
  long int i = -9223372036854775807;
  s21_sprintf(result, "Count: % li abc", i);
  sprintf(assert, "Count: % li abc", i);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default42) {
  char result[40];
  char assert[40];
  long int i = 9223372036854775807;
  s21_sprintf(result, "Count: %li abc", i);
  sprintf(assert, "Count: %li abc", i);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default43) {
  char result[40];
  char assert[40];
  short int i = 32767;
  s21_sprintf(result, "Count: %hi abc", i);
  sprintf(assert, "Count: %hi abc", i);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default44) {
  char result[40];
  char assert[40];
  short int i = 32770;
  s21_sprintf(result, "Count: %hi end", i);
  sprintf(assert, "Count: %hi end", i);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default45) {
  char result[40];
  char assert[40];
  int i = 327710;
  s21_sprintf(result, "Count: %5.10i end", i);
  sprintf(assert, "Count: %5.10i end", i);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default46) {
  char result[40];
  char assert[40];
  int i = 327710;
  s21_sprintf(result, "Count: %-+10.5i end", i);
  sprintf(assert, "Count: %-+10.5i end", i);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default47) {
  char result[40];
  char assert[40];
  int i = 327710;
  s21_sprintf(result, "Count: %+10.5i end", i + 1);
  sprintf(assert, "Count: %+10.5i end", i + 1);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default48) {
  char result[40];
  char assert[40];
  float f = -14.537;
  s21_sprintf(result, "Count: %.6f end", f);
  sprintf(assert, "Count: %.6f end", f);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default49) {
  char result[40];
  char assert[40];
  float f = 14.537;
  s21_sprintf(result, "Count: %2.2f end", f);
  sprintf(assert, "Count: %2.2f end", f);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default50) {
  char result[40];
  char assert[40];
  float f = 1.0010021;
  s21_sprintf(result, "Count: %f end", f);
  sprintf(assert, "Count: %f end", f);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default51) {
  char result[40];
  char assert[40];
  float f = 0;
  s21_sprintf(result, "Count: %f end", f);
  sprintf(assert, "Count: %f end", f);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default52) {
  char result[40];
  char assert[40];
  float f = 0.;
  s21_sprintf(result, "Count: %f end", f);
  sprintf(assert, "Count: %f end", f);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default53) {
  char result[40];
  char assert[40];
  float f = -123.321;
  s21_sprintf(result, "Count: %f end", f);
  sprintf(assert, "Count: %f end", f);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default54) {
  char result[40];
  char assert[40];
  float f = 1.1234;
  s21_sprintf(result, "Count: %.*f end", 3, f);
  sprintf(assert, "Count: %.*f end", 3, f);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default55) {
  char result[40];
  char assert[40];
  float f = -.0000001;
  s21_sprintf(result, "Count: %f end", f);
  sprintf(assert, "Count: %f end", f);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default56) {
  char result[40];
  char assert[40];
  float f = -.0000001;
  s21_sprintf(result, "Count: %10f end", f);
  sprintf(assert, "Count: %10f end", f);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default57) {
  char result[40];
  char assert[40];
  double f = -.0000001;
  s21_sprintf(result, "Count: %3.5lf end", f);
  sprintf(assert, "Count: %3.5lf end", f);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(float_precision) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%Lf";
  long double val = 513515.131513515151351;
  int a = s21_sprintf(str1, format, val);
  int b = sprintf(str2, format, val);

  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(a, b);
}
END_TEST
START_TEST(float_width) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%10Lf";
  long double val = 15.35;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(float_precision_zero) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.0Lf";
  long double val = 15.35;
  s21_sprintf(str1, format, val);
  sprintf(str2, format, val);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(float_precision_empty) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.Lf";
  long double val = 15.35;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(float_huge) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%Lf";
  long double val = 72537572375.1431341;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(float_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "% f";
  float val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(float_many) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "% .0f %.lf %.5Lf %f %lf %Lf";
  float val = 0;
  double val1 = 0;
  long double val2 = 3515315.153151;
  float val3 = 5.5;
  double val4 = 9851.51351;
  long double val5 = 95919539159.53151351131;
  ck_assert_int_eq(s21_sprintf(str1, format, val, val1, val2, val3, val4, val5),
                   sprintf(str2, format, val, val1, val2, val3, val4, val5));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_float) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%f", 0.0001),
                   sprintf(str2, "%f", 0.0001));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_float) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(
      s21_sprintf(str1, "%f%f%f%f", -999.666, 0.0001, 666.999, -100.001),
      sprintf(str2, "%f%f%f%f", -999.666, 0.0001, 666.999, -100.001));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_default58) {
  char result[40];
  char assert[40];
  float f = 14.537;
  s21_sprintf(result, "%+0.2f", f);
  sprintf(assert, "%+0.2f", f);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default59) {
  char result[40];
  char assert[40];
  char *s = "none";
  s21_sprintf(result, "Count: %s abc", s);
  sprintf(assert, "Count: %s abc", s);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default60) {
  char result[40];
  char assert[40];
  char *s = "none";
  s21_sprintf(result, "Count: %.3s abc", s);
  sprintf(assert, "Count: %.3s abc", s);
  ck_assert_str_eq(result, assert);
}
END_TEST

// START_TEST(test_default61) {
//   char result[40];
//   char assert[40];
//   char *s = "none";
//   s21_sprintf(result, "%.6s", s);
//   sprintf(assert, "%.6s", s);
//   ck_assert_str_eq(result, assert);
// }
// END_TEST

START_TEST(test_default62) {
  char result[40];
  char assert[40];
  char *s = "stroka s probelom";
  s21_sprintf(result, "%5.6s", s);
  sprintf(assert, "%5.6s", s);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default63) {
  char result[40];
  char assert[40];
  char *s = "stroka s probelom";
  s21_sprintf(result, "%-5.6s", s);
  sprintf(assert, "%-5.6s", s);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default64) {
  char result[40];
  char assert[40];
  wchar_t s[] = L"wide chars: ";
  s21_sprintf(result, "%-5.6ls", s);
  sprintf(assert, "%-5.6ls", s);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(string) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%s";
  char *val = "21R DSADA SDHASDOAMDSA sdas8d7nasd 111";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(string_precision) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%.15s";
  char *val = "21R DSADA SDHASDOAMDSA sdas8d7nasd 111";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(string_width) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%15s";
  char *val = "21R DSADA SDHASDOAMDSA sdas8d7nasd 111";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(string_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-15.9s";
  char *val = "21R DSADA SDHASDOAMDSA sdas8d7nasd 111";
  s21_sprintf(str1, format, val), sprintf(str2, format, val);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(string_long) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%s";
  char *val = "ADibsy8 ndASN) dun8AWn dA 9sDNsa NAID saDYBU DSnaJ Sd";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(string_many) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%s%s%s%s";
  char *val = "ADibsy8 ndASN) dun8AWn dA 9sDNsa NAID saDYBU DSnaJ Sd";
  char *s1 = "";
  char *s2 = "87418347813748913749871389480913";
  char *s3 = "HAHAABOBASUCKER";
  ck_assert_int_eq(s21_sprintf(str1, format, val, s1, s2, s3),
                   sprintf(str2, format, val, s1, s2, s3));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(string_width_huge) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *val = "kjafdiuhfjahfjdahf";
  char *format = "%120s";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_string) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%s", "DASdw D sadw ASD"),
                   sprintf(str2, "%s", "DASdw D sadw ASD"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_string) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(
      s21_sprintf(str1, "%s%s%s%s%s", "DASdw", " ", "sadw", " ", "ASD"),
      sprintf(str2, "%s%s%s%s%s", "DASdw", " ", "sadw", " ", "ASD"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(wstr2) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "wchar: %120hs ABOBA";
  wchar_t w[] = L"森我爱菠萝";
  int a = s21_sprintf(str1, format, w);
  int b = sprintf(str2, format, w);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(wchr) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};

  char *format = "wchar: %lc";
  wchar_t w = L'1';
  int a = s21_sprintf(str1, format, w);
  int b = sprintf(str2, format, w);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(width_char) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "wchar: %5c";
  char w = 'c';
  int a = s21_sprintf(str1, format, w);
  int b = sprintf(str2, format, w);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(a, b);
}
START_TEST(minus_wchr) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};

  char *format = "wchar: %-5lc";
  unsigned long w = L'~';
  int a = s21_sprintf(str1, format, w);
  int b = sprintf(str2, format, w);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_default65) {
  char result[20];
  char assert[20];
  unsigned int u = 571212;
  s21_sprintf(result, "Count: %.5u abc", u);
  sprintf(assert, "Count: %.5u abc", u);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default66) {
  char result[20];
  char assert[20];
  unsigned int u = 5312112;
  s21_sprintf(result, "Count: %-.5u abc", u);
  sprintf(assert, "Count: %-.5u abc", u);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default67) {
  char result[20];
  char assert[20];
  unsigned int u = 0;
  s21_sprintf(result, "Count: %u abc", u);
  sprintf(assert, "Count: %u abc", u);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default68) {
  char result[20];
  char assert[20];
  unsigned int u = 0;
  s21_sprintf(result, "Count: %u abc", u);
  sprintf(assert, "Count: %u abc", u);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default69) {
  char result[20];
  char assert[20];
  unsigned int u = 1;
  s21_sprintf(result, "Count: %u abc", u);
  sprintf(assert, "Count: %u abc", u);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default70) {
  char result[20];
  char assert[20];
  unsigned int u = 1;
  s21_sprintf(result, "Count: %u abc", u);
  sprintf(assert, "Count: %u abc", u);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default71) {
  char result[20];
  char assert[20];
  unsigned int u = -0;
  s21_sprintf(result, "Count: %u abc", u);
  sprintf(assert, "Count: %u abc", u);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default72) {
  char result[40];
  char assert[40];
  unsigned int u = 2147483647;
  s21_sprintf(result, "Count: %u abc", u);
  sprintf(assert, "Count: %u abc", u);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default73) {
  char result[40];
  char assert[40];
  unsigned int u = -2147483648;
  s21_sprintf(result, "Count: %u abc", u);
  sprintf(assert, "Count: %u abc", u);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default74) {
  char result[40];
  char assert[40];
  unsigned long int u = 214748364912;
  s21_sprintf(result, "Count: %lu abc", u);
  sprintf(assert, "Count: %lu abc", u);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default75) {
  char result[40];
  char assert[40];
  unsigned long int u = -9223372036854775807;
  s21_sprintf(result, "Count: %lu abc", u);
  sprintf(assert, "Count: %lu abc", u);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default76) {
  char result[40];
  char assert[40];
  unsigned long int u = 9223372036854775807;
  s21_sprintf(result, "Count: %lu abc", u);
  sprintf(assert, "Count: %lu abc", u);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default77) {
  char result[40];
  char assert[40];
  unsigned short int u = 32767;
  s21_sprintf(result, "Count: %hu abc", u);
  sprintf(assert, "Count: %hu abc", u);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default78) {
  char result[40];
  char assert[40];
  unsigned short int u = 32770;
  s21_sprintf(result, "Count: %hu end", u);
  sprintf(assert, "Count: %hu end", u);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default79) {
  char result[40];
  char assert[40];
  unsigned int u = 327710;
  s21_sprintf(result, "Count: %11.10u end", u);
  sprintf(assert, "Count: %11.10u end", u);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default80) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%g";
  double hex = 0.50300;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_default81) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%g";
  double hex = 5131.43;
  s21_sprintf(str1, format, hex);
  sprintf(str2, format, hex);

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_default82) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%g";
  double hex = 0.1;
  s21_sprintf(str1, format, hex);
  sprintf(str2, format, hex);

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_default83) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%.5g";
  double hex = 0.55555;
  s21_sprintf(str1, format, hex);
  sprintf(str2, format, hex);

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_default84) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%.0g";
  double hex = 0.4;
  s21_sprintf(str1, format, hex);
  sprintf(str2, format, hex);

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_default85) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%.g";
  double hex = 5;
  s21_sprintf(str1, format, hex);
  sprintf(str2, format, hex);

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_default86) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%.g";
  double hex = 0.0004;
  s21_sprintf(str1, format, hex);
  sprintf(str2, format, hex);

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_default87) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%g";
  double hex = 0;
  s21_sprintf(str1, format, hex);
  sprintf(str2, format, hex);

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_default88) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%.5g";
  double hex = 0;
  s21_sprintf(str1, format, hex);
  sprintf(str2, format, hex);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_default89) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%5g";
  double hex = 0.0000005;
  s21_sprintf(str1, format, hex);
  sprintf(str2, format, hex);

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_default90) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%5.8g";
  double hex = 0.0000005;
  s21_sprintf(str1, format, hex);
  sprintf(str2, format, hex);

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_default91) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%g";
  double hex = 0.005;
  s21_sprintf(str1, format, hex);
  sprintf(str2, format, hex);

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_default92) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};
  char format[] = "%LG";
  long double hex = 0.000005;
  s21_sprintf(str1, format, hex);
  sprintf(str2, format, hex);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_default93) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};
  char format[] = "%LG %g %G %Lg %.5g";
  long double hex = 0.000005;
  double hex1 = 41.1341;
  long double hex3 = 0.0843;
  double hex4 = 0.0005;
  double hex5 = 0.8481481;
  s21_sprintf(str1, format, hex, hex1, hex3, hex4, hex5);
  sprintf(str2, format, hex, hex1, hex3, hex4, hex5);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_default94) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.16Le";
  long double val = 15.35;
  s21_sprintf(str1, format, val);
  sprintf(str2, format, val);

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_default95) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.0Le";
  long double val = 15.35;
  s21_sprintf(str1, format, val);
  sprintf(str2, format, val);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_default96) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.Le";
  long double val = 15.000009121;
  s21_sprintf(str1, format, val);
  sprintf(str2, format, val);

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_default97) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.15Le";
  long double val = 0.000000000000000123;
  s21_sprintf(str1, format, val);
  sprintf(str2, format, val);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_default98) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.15Le";
  long double val = -15.35581134;
  s21_sprintf(str1, format, val);
  sprintf(str2, format, val);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_default99) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%Le";
  long double val = 72537572375.1431341;
  s21_sprintf(str1, format, val);
  sprintf(str2, format, val);

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_default100) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};
  char *format = "%015E";
  float val = 0;
  s21_sprintf(str1, format, val);
  sprintf(str2, format, val);

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_default101) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%15e";
  float val = 0;
  s21_sprintf(str1, format, val);
  sprintf(str2, format, val);

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_default102) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "% .0e %.le %Le %e %le %Le";
  float val = 0;
  double val1 = 0;
  long double val2 = 3515315.153151;
  float val3 = 5.5;
  double val4 = 0.094913941;
  long double val5 = 95919539159.53151351131;
  s21_sprintf(str1, format, val, val1, val2, val3, val4, val5);
  sprintf(str2, format, val, val1, val2, val3, val4, val5);

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_default103) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};
  char *format = "%.17LE";
  long double val = 4134121;
  s21_sprintf(str1, format, val);
  sprintf(str2, format, val);

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_default104) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  ck_assert_int_eq(s21_sprintf(str1, "abc"), sprintf(str2, "abc"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_default105) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "abc"), sprintf(str2, "abc"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_default106) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%15o";
  int val = 14140;
  s21_sprintf(str1, format, val);
  sprintf(str2, format, val);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_default107) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-16o";
  int val = 14140;
  s21_sprintf(str1, format, val);
  sprintf(str2, format, val);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_default108) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%.51o";
  int val = 14140;
  s21_sprintf(str1, format, val);
  sprintf(str2, format, val);

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_default109) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-5.51o";
  int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_default110) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%o";
  ck_assert_int_eq(s21_sprintf(str1, format, 0), sprintf(str2, format, 0));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_default111) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#o";
  int val = 57175;
  s21_sprintf(str1, format, val);
  sprintf(str2, format, val);

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_default112) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%hd";
  short int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_default113) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%lo";
  long int val = 949149114140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

// START_TEST(test_default114) {
//   char str1[BUFF_SIZE];
//   char str2[BUFF_SIZE];

//   char *format = "%lo, %o, %ho, %.5o, %5.o";
//   long int val = 949149114140;
//   ck_assert_int_eq(
//       s21_sprintf(str1, format, val, 14, 1441, 14414, 9681),
//       sprintf(str2, format, val, (unsigned)14, (unsigned short)1441,
//               (unsigned)14414, (unsigned)9681));

//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

START_TEST(test_default115) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%lo";
  long int val = 84518;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_default116) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#o";
  int val = -57175;
  s21_sprintf(str1, format, val);
  sprintf(str2, format, val);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_default117) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#- 10o";
  int val = -573375;
  s21_sprintf(str1, format, val);
  sprintf(str2, format, val);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_default118) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%5x";
  unsigned val = 858158158;
  s21_sprintf(str1, format, val);
  sprintf(str2, format, val);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_default119) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#-10x";
  unsigned val = 858158158;
  s21_sprintf(str1, format, val);
  sprintf(str2, format, val);

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_default120) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%.15x";
  unsigned val = 858158158;
  s21_sprintf(str1, format, val);
  sprintf(str2, format, val);

  ck_assert_str_eq(str1, str2);
}
END_TEST
// START_TEST(test_default121) {
//   char str1[BUFF_SIZE];
//   char str2[BUFF_SIZE];

//   char *format = "%#-10x %x %X %#x %#X %5.5x";
//   unsigned val = 858158158;
//   s21_sprintf(str1, format, val, val, val, val, val, val);
//   sprintf(str2, format, val, val, val, val, val, val);

//   ck_assert_str_eq(str1, str2);
// }
// END_TEST
START_TEST(test_default122) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#-5.10x";
  unsigned val = 858158158;
  s21_sprintf(str1, format, val);
  sprintf(str2, format, val);

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_default123) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#x";
  unsigned val = 0;
  s21_sprintf(str1, format, val);
  sprintf(str2, format, val);

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_default124) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#x";
  unsigned val = 18571;
  s21_sprintf(str1, format, val);
  sprintf(str2, format, val);

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_default125) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#hx";
  unsigned short val = 12352;
  s21_sprintf(str1, format, val);
  sprintf(str2, format, val);

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_default126) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#lx";
  unsigned long val = 18571757371571;
  s21_sprintf(str1, format, val);
  sprintf(str2, format, val);

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_default127) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#2x";
  unsigned val = 1;
  s21_sprintf(str1, format, val);
  sprintf(str2, format, val);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_default128) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#30x";
  unsigned val = 1;
  s21_sprintf(str1, format, val);
  sprintf(str2, format, val);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_default129) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%p";
  s21_sprintf(str1, format, format);
  sprintf(str2, format, format);

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_default130) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%15p";
  s21_sprintf(str1, format, format);
  sprintf(str2, format, format);

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_default131) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%.5p";
  s21_sprintf(str1, format, format);
  sprintf(str2, format, format);

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_default132) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%p";
  char *ptr = "(nil)";
  s21_sprintf(str1, format, ptr);
  sprintf(str2, format, ptr);

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_default133) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  int ret = 0;
  char *format = "How many chars written before n %n";
  s21_sprintf(str1, format, &ret);
  sprintf(str2, format, &ret);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_default134) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  int n1;
  int n2;
  s21_sprintf(str1, "%d%n", 123, &n1);
  sprintf(str2, "%d%n", 123, &n2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_default135) {
  char result[512];
  char assert[512];
  char *d = "2147";
  s21_sprintf(result, "%101s", d);
  sprintf(assert, "%101s", d);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default136) {
  char result[512];
  char assert[512];
  char c = 'z';
  s21_sprintf(result, "Count: %12lc", c);
  sprintf(assert, "Count: %12lc", c);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default137) {
  char result[20] = {'\0'};
  char assert[20] = {'\0'};
  char c = 'z';
  s21_sprintf(result, "Count: %-12lc", c);
  sprintf(assert, "Count: %-12lc", c);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default138) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};

  char *format = "wchar: %lc";
  wchar_t w = L'A';
  int a = s21_sprintf(str1, format, w);
  int b = sprintf(str2, format, w);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(a, b);
}
END_TEST

char c[255] = {}, d[255] = {}, x1 = 't';
int n = 2100, n1 = 0, n2 = -21;
short sh = 123, sh1 = -123;
float f = 21.21, f1 = -21.21;
long int lg = 12345678912345, lg1 = -12345678912345;

START_TEST(sprintf_percent) {
  s21_sprintf(c, "%% %d", n);
  sprintf(d, "%% %d", n);
  ck_assert_str_eq(c, d);
}
END_TEST

START_TEST(sprintf_d) {
  s21_sprintf(c, "%d %d %d %hd %hd %ld %ld %10ld", n, n1, n2, sh, sh1, lg, lg1,
              lg1);
  sprintf(d, "%d %d %d %hd %hd %ld %ld %10ld", n, n1, n2, sh, sh1, lg, lg1,
          lg1);
  ck_assert_str_eq(c, d);

  s21_sprintf(c, "%-10d %10d %10d %*d %2d", 21, n2, n, 10, n, n2);
  sprintf(d, "%-10d %10d %10d %*d %2d", 21, n2, n, 10, n, n2);
  ck_assert_str_eq(c, d);

  s21_sprintf(
      c, "%.*d %3.10d %.2d %-+.5d %-+10.5d %.10d %.10d %2.2d %.1d % d %.2d", 10,
      n, n2, 42, 21, 10, n, n2, -21, x1, 21, -42);
  sprintf(d, "%.*d %3.10d %.2d %-+.5d %-+10.5d %.10d %.10d %2.2d %.1d % d %.2d",
          10, n, n2, 42, 21, 10, n, n2, -21, x1, 21, -42);
  ck_assert_str_eq(c, d);
}
END_TEST

START_TEST(sprintf_c) {
  s21_sprintf(c, "%c %10c %-10c", '!', 'a', 'b');
  sprintf(d, "%c %10c %-10c", '!', 'a', 'b');
  ck_assert_str_eq(c, d);

  s21_sprintf(c, "%c %c %c", CHAR_MAX, CHAR_MIN, UCHAR_MAX);
  sprintf(d, "%c %c %c", CHAR_MAX, CHAR_MIN, UCHAR_MAX);
  ck_assert_str_eq(c, d);
}
END_TEST

// START_TEST(sprintf_s) {
//   s21_sprintf(c, "%s %10s %-10s %-3s %.s %.3s %.10s", "hello", "hello",
//   "hello",
//               "hello", "hello", "hello", "hello");
//   sprintf(d, "%s %10s %-10s %-3s %.s %.3s %.10s", "hello", "hello", "hello",
//           "hello", "hello", "hello", "hello");
//   ck_assert_str_eq(c, d);
// }
// END_TEST

// Implement Suite
Suite *core_suite(void) {
  Suite *suite = suite_create("Core");
  TCase *tcase = tcase_create("Core");

  // Add test to test case
  tcase_add_test(tcase, test_s21_strlen);
  tcase_add_test(tcase, test_s21_memset);
  tcase_add_test(tcase, test_s21_memchr);
  tcase_add_test(tcase, test_s21_memcmp);
  tcase_add_test(tcase, test_s21_memmove);
  tcase_add_test(tcase, test_s21_memcpy);
  tcase_add_test(tcase, test_s21_strcat);
  tcase_add_test(tcase, test_s21_strncat);
  tcase_add_test(tcase, test_s21_strchr);
  tcase_add_test(tcase, test_s21_strcmp);
  tcase_add_test(tcase, test_s21_strncmp);
  tcase_add_test(tcase, test_s21_strcpy);
  tcase_add_test(tcase, test_s21_strncpy);
  tcase_add_test(tcase, test_s21_strrchr);
  tcase_add_test(tcase, test_s21_strspn);
  tcase_add_test(tcase, test_s21_strstr);
  tcase_add_test(tcase, test_s21_strcspn);
  tcase_add_test(tcase, test_s21_strtok);
  tcase_add_test(tcase, test_s21_strpbrk);
  tcase_add_test(tcase, sscanf_flag_c_one);
  tcase_add_test(tcase, sscanf_flag_c_two);
  tcase_add_test(tcase, sscanf_flag_c_three);
  tcase_add_test(tcase, sscanf_flag_d);
  tcase_add_test(tcase, sscanf_flag_i);
  tcase_add_test(tcase, sscanf_flag_e);
  tcase_add_test(tcase, sscanf_flag_E);
  tcase_add_test(tcase, sscanf_flag_f);
  tcase_add_test(tcase, sscanf_flag_g);
  tcase_add_test(tcase, sscanf_flag_G);
  tcase_add_test(tcase, sscanf_flag_o);
  tcase_add_test(tcase, sscanf_flag_s);
  tcase_add_test(tcase, sscanf_flag_u);
  tcase_add_test(tcase, sscanf_flag_x);
  tcase_add_test(tcase, sscanf_flag_X);
  tcase_add_test(tcase, sscanf_flag_p);
  tcase_add_test(tcase, sscanf_flag_n);
  tcase_add_test(tcase, sscanf_flag_wigth);
  tcase_add_test(tcase, sscanf_flag_star);
  tcase_add_test(tcase, sscanf_flag_lenght);
  tcase_add_test(tcase, sscanf_flag_lenght_long);
  tcase_add_test(tcase, sscanf_flag_lenght_long_double);
  tcase_add_test(tcase, sscanf_advance);
  tcase_add_test(tcase, lower);
  tcase_add_test(tcase, upper);
  tcase_add_test(tcase, insert);
  tcase_add_test(tcase, trim);
  tcase_add_test(tcase, test_default);
  tcase_add_test(tcase, test_default2);
  tcase_add_test(tcase, test_default3);
  tcase_add_test(tcase, test_default4);
  tcase_add_test(tcase, test_default5);
  tcase_add_test(tcase, test_default6);
  tcase_add_test(tcase, test_default7);
  tcase_add_test(tcase, test_default8);
  tcase_add_test(tcase, test_default9);
  tcase_add_test(tcase, test_default10);
  tcase_add_test(tcase, test_default11);
  tcase_add_test(tcase, test_default12);
  tcase_add_test(tcase, test_default13);
  tcase_add_test(tcase, test_default14);
  tcase_add_test(tcase, test_default15);
  tcase_add_test(tcase, test_default16);
  tcase_add_test(tcase, test_default17);
  tcase_add_test(tcase, test_default18);
  tcase_add_test(tcase, test_default19);
  tcase_add_test(tcase, test_default20);
  tcase_add_test(tcase, test_default21);
  tcase_add_test(tcase, test_default22);
  tcase_add_test(tcase, test_default23);
  tcase_add_test(tcase, test_default24);
  tcase_add_test(tcase, test_default25);
  tcase_add_test(tcase, test_default26);
  tcase_add_test(tcase, test_default27);
  tcase_add_test(tcase, test_default28);
  tcase_add_test(tcase, test_default29);
  tcase_add_test(tcase, test_default30);
  tcase_add_test(tcase, test_default31);
  tcase_add_test(tcase, test_default32);
  tcase_add_test(tcase, test_default33);
  tcase_add_test(tcase, test_default34);
  tcase_add_test(tcase, test_default35);
  tcase_add_test(tcase, test_default36);
  tcase_add_test(tcase, test_default37);
  tcase_add_test(tcase, test_default38);
  tcase_add_test(tcase, test_default39);
  tcase_add_test(tcase, test_default40);
  tcase_add_test(tcase, test_default41);
  tcase_add_test(tcase, test_default42);
  tcase_add_test(tcase, test_default43);
  tcase_add_test(tcase, test_default44);
  tcase_add_test(tcase, test_default45);
  tcase_add_test(tcase, test_default46);
  tcase_add_test(tcase, test_default47);
  tcase_add_test(tcase, test_default48);
  tcase_add_test(tcase, test_default49);
  tcase_add_test(tcase, test_default50);
  tcase_add_test(tcase, test_default51);
  tcase_add_test(tcase, test_default52);
  tcase_add_test(tcase, test_default53);
  tcase_add_test(tcase, test_default54);
  tcase_add_test(tcase, test_default55);
  tcase_add_test(tcase, test_default56);
  tcase_add_test(tcase, test_default57);
  tcase_add_test(tcase, test_default58);
  tcase_add_test(tcase, test_default59);
  tcase_add_test(tcase, test_default60);
  // tcase_add_test(tcase, test_default61);
  tcase_add_test(tcase, test_default62);
  tcase_add_test(tcase, test_default63);
  tcase_add_test(tcase, test_default64);
  tcase_add_test(tcase, test_default65);
  tcase_add_test(tcase, test_default66);
  tcase_add_test(tcase, test_default67);
  tcase_add_test(tcase, test_default68);
  tcase_add_test(tcase, test_default69);
  tcase_add_test(tcase, test_default70);
  tcase_add_test(tcase, test_default71);
  tcase_add_test(tcase, test_default72);
  tcase_add_test(tcase, test_default73);
  tcase_add_test(tcase, test_default74);
  tcase_add_test(tcase, test_default75);
  tcase_add_test(tcase, test_default76);
  tcase_add_test(tcase, test_default77);
  tcase_add_test(tcase, test_default78);
  tcase_add_test(tcase, test_default79);
  tcase_add_test(tcase, test_default80);
  tcase_add_test(tcase, test_default81);
  tcase_add_test(tcase, test_default82);
  tcase_add_test(tcase, test_default83);
  tcase_add_test(tcase, test_default84);
  tcase_add_test(tcase, test_default85);
  tcase_add_test(tcase, test_default86);
  tcase_add_test(tcase, test_default87);
  tcase_add_test(tcase, test_default88);
  tcase_add_test(tcase, test_default89);
  tcase_add_test(tcase, test_default90);
  tcase_add_test(tcase, test_default91);
  tcase_add_test(tcase, test_default92);
  tcase_add_test(tcase, test_default93);
  tcase_add_test(tcase, test_default94);
  tcase_add_test(tcase, test_default95);
  tcase_add_test(tcase, test_default96);
  tcase_add_test(tcase, test_default97);
  tcase_add_test(tcase, test_default98);
  tcase_add_test(tcase, test_default99);
  tcase_add_test(tcase, test_default100);
  tcase_add_test(tcase, test_default101);
  tcase_add_test(tcase, test_default102);
  tcase_add_test(tcase, test_default103);
  tcase_add_test(tcase, test_default104);
  tcase_add_test(tcase, test_default105);
  tcase_add_test(tcase, test_default106);
  tcase_add_test(tcase, test_default107);
  tcase_add_test(tcase, test_default108);
  tcase_add_test(tcase, test_default109);
  tcase_add_test(tcase, test_default110);
  tcase_add_test(tcase, test_default111);
  tcase_add_test(tcase, test_default112);
  tcase_add_test(tcase, test_default113);
  tcase_add_test(tcase, test_default115);
  tcase_add_test(tcase, test_default116);
  tcase_add_test(tcase, test_default117);
  tcase_add_test(tcase, test_default118);
  tcase_add_test(tcase, test_default119);
  tcase_add_test(tcase, test_default120);
  tcase_add_test(tcase, test_default122);
  tcase_add_test(tcase, test_default123);
  tcase_add_test(tcase, test_default124);
  tcase_add_test(tcase, test_default125);
  tcase_add_test(tcase, test_default126);
  tcase_add_test(tcase, test_default127);
  tcase_add_test(tcase, test_default128);
  tcase_add_test(tcase, test_default129);
  tcase_add_test(tcase, test_default130);
  tcase_add_test(tcase, test_default131);
  tcase_add_test(tcase, test_default132);
  tcase_add_test(tcase, test_default133);
  tcase_add_test(tcase, test_default134);
  tcase_add_test(tcase, test_default135);
  tcase_add_test(tcase, test_default136);
  tcase_add_test(tcase, test_default137);
  tcase_add_test(tcase, test_default138);
  tcase_add_test(tcase, sprintf_percent);
  tcase_add_test(tcase, sprintf_d);
  tcase_add_test(tcase, sprintf_c);
  // tcase_add_test(tcase, sprintf_s);
  tcase_add_test(tcase, test_char_default);
  tcase_add_test(tcase, test_char_multy);
  tcase_add_test(tcase, string);
  tcase_add_test(tcase, string_precision);
  tcase_add_test(tcase, string_width);
  tcase_add_test(tcase, string_flags);
  tcase_add_test(tcase, string_long);
  tcase_add_test(tcase, string_many);
  tcase_add_test(tcase, string_width_huge);
  tcase_add_test(tcase, test_one_string);
  tcase_add_test(tcase, test_many_string);
  tcase_add_test(tcase, wstr2);
  tcase_add_test(tcase, wchr);
  tcase_add_test(tcase, width_char);
  tcase_add_test(tcase, minus_wchr);
  tcase_add_test(tcase, float_precision);
  tcase_add_test(tcase, float_width);
  tcase_add_test(tcase, float_precision_zero);
  tcase_add_test(tcase, float_precision_empty);
  tcase_add_test(tcase, float_huge);
  tcase_add_test(tcase, float_flags);
  tcase_add_test(tcase, float_many);
  tcase_add_test(tcase, test_one_float);
  tcase_add_test(tcase, test_many_float);
  tcase_add_test(tcase, test_default_multy);
  tcase_add_test(tcase, test_no_args);
  tcase_add_test(tcase, test_format_d);
  tcase_add_test(tcase, test_flag_minus);
  // Add case to suite
  suite_add_tcase(suite, tcase);

  return suite;
};
