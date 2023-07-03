#include "../s21_string.h"
#define BUFF_SIZE 512

#include <check.h>
#include <string.h>
/*-----------------SSCANF------------------*/
START_TEST(s21_sscanf_test_16_o_option) {
  int a = 0;
  int b = 0;

  int c = 0;
  int d = 0;

  int result1 = s21_sscanf("12345 36", "%o %o", &a, &b);
  int result_origin1 = sscanf("12345 36", "%o %o", &c, &d);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, c);
  ck_assert_int_eq(b, d);

  a = 0;
  b = 0;

  result1 = s21_sscanf("12345", "%o", &a);
  result_origin1 = sscanf("12345", "%o", &b);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, b);

  a = 0;
  b = 0;

  result1 = s21_sscanf("-12345", "%o", &a);
  result_origin1 = sscanf("-12345", "%o", &b);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, b);

  a = 10;
  b = 10;

  result1 = s21_sscanf("0", "%o", &a);
  result_origin1 = sscanf("0", "%o", &b);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, b);

  a = 0;
  b = 0;
  const char *format_str = "-2345";

  result1 = s21_sscanf(format_str, "%o", &a);
  result_origin1 = sscanf(format_str, "%o", &b);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, b);

  a = 0;
  b = 0;
  const char *format_str1 = "-2345 6789";

  result1 = s21_sscanf(format_str1, "%o %o", &a, &c);
  result_origin1 = sscanf(format_str1, "%o %o", &b, &d);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, b);
  ck_assert_int_eq(c, d);

  short int g, h, j, k;
  result1 = s21_sscanf(format_str1, "%ho %ho", &g, &h);
  result_origin1 = sscanf(format_str1, "%ho %ho", &j, &k);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(g, j);
  ck_assert_int_eq(h, k);

  long int u, i, o, p;
  result1 = s21_sscanf(format_str1, "%3lo %lo", &u, &i);
  result_origin1 = sscanf(format_str1, "%3lo %lo", &o, &p);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(u, o);
  ck_assert_int_eq(i, p);

  int x = 0;
  int y = 0;
  const char *format_str2 = "-2345 677 5555";

  result1 = s21_sscanf(format_str2, "%o %o %o", &a, &c, &x);
  result_origin1 = sscanf(format_str2, "%o %o %o", &b, &d, &y);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, b);
  ck_assert_int_eq(c, d);
  ck_assert_int_eq(x, y);

  result1 = s21_sscanf(format_str1, "%o %*o", &a);
  result_origin1 = sscanf(format_str1, "%o %*o", &b);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, b);

  result1 = s21_sscanf(format_str1, "%*o %o", &a);
  result_origin1 = sscanf(format_str1, "%*o %o", &b);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, b);

  result1 = s21_sscanf(format_str2, "%*o %o %o", &a, &c);
  result_origin1 = sscanf(format_str2, "%*o %o %o", &b, &d);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, b);
  ck_assert_int_eq(c, d);

  result1 = s21_sscanf(format_str2, "%o %*o %o", &a, &c);
  result_origin1 = sscanf(format_str2, "%o %*o %o", &b, &d);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, b);
  ck_assert_int_eq(c, d);

  result1 = s21_sscanf(format_str2, "%o %o %*o", &a, &c);
  result_origin1 = sscanf(format_str2, "%o %o %*o", &b, &d);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, b);
  ck_assert_int_eq(c, d);

  result1 = s21_sscanf(format_str2, "%o %*o %*o", &a);
  result_origin1 = sscanf(format_str2, "%o %*o %*o", &b);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, b);

  result1 = s21_sscanf(format_str2, "%*o %o %*o", &a);
  result_origin1 = sscanf(format_str2, "%*o %o %*o", &b);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, b);

  result1 = s21_sscanf(format_str2, "%*o %*o %o", &a);
  result_origin1 = sscanf(format_str2, "%*o %*o %o", &b);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, b);
}
END_TEST
START_TEST(s21_sscanf_test_17_o_option) {
  uint32_t a1, a2;
  const char str[] = "          \n             \n     5";
  const char fstr[] = "%o";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}

END_TEST
START_TEST(s21_sscanf_test_18_o_option) {
  uint16_t a1, a2;
  const char str[] = "12";
  const char fstr[] = "%ho";
  uint16_t res1 = s21_sscanf(str, fstr, &a1);
  uint16_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(s21_sscanf_test_17_d_option) {
  int a = 0;
  int b = 0;
  int c = 0;
  int d = 0;

  int result1 = s21_sscanf("12345 36", "%d %d", &a, &b);
  int result_origin1 = sscanf("12345 36", "%d %d", &c, &d);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, c);
  ck_assert_int_eq(b, d);

  short int g = 0;
  short int h = 0;
  short int j = 0;
  short int k = 0;

  result1 = s21_sscanf("12345 36", "%hd %hd", &g, &h);
  result_origin1 = sscanf("12345 36", "%hd %hd", &j, &k);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(g, j);
  ck_assert_int_eq(h, k);

  result1 = s21_sscanf("0 0", "%d %d", &a, &b);
  result_origin1 = sscanf("0 0", "%d %d", &c, &d);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, c);
  ck_assert_int_eq(b, d);

  result1 = s21_sscanf("-123445 -123", "%d %d", &a, &b);
  result_origin1 = sscanf("-123445 -123", "%d %d", &c, &d);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, c);
  ck_assert_int_eq(b, d);

  const char *format_str1 = "123 456";

  result1 = s21_sscanf(format_str1, "%d %d", &a, &b);
  result_origin1 = sscanf(format_str1, "%d %d", &c, &d);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, c);
  ck_assert_int_eq(b, d);

  const char *format_str2 = "-123 -456";

  result1 = s21_sscanf(format_str2, "%d %d", &a, &b);
  result_origin1 = sscanf(format_str2, "%d %d", &c, &d);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, c);
  ck_assert_int_eq(b, d);

  const char *format_str3 = "0 0";

  result1 = s21_sscanf(format_str3, "%d %d", &a, &b);
  result_origin1 = sscanf(format_str3, "%d %d", &c, &d);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, c);
  ck_assert_int_eq(b, d);

  const char *format_str4 = "123 456";

  result1 = s21_sscanf(format_str4, "%10d %10d", &a, &b);
  result_origin1 = sscanf(format_str4, "%10d %10d", &c, &d);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, c);
  ck_assert_int_eq(b, d);

  const char *format_str5 = "-123 -456";

  result1 = s21_sscanf(format_str5, "%2d %4d", &a, &b);
  result_origin1 = sscanf(format_str5, "%2d %4d", &c, &d);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, c);
  ck_assert_int_eq(b, d);

  const char *format_str6 = "0 0";

  result1 = s21_sscanf(format_str6, "%5d %5d", &a, &b);
  result_origin1 = sscanf(format_str6, "%5d %5d", &c, &d);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, c);
  ck_assert_int_eq(b, d);

  const char *format_str7 = "2147483647 -2147483648";

  result1 = s21_sscanf(format_str7, "%5d %5d", &a, &b);
  result_origin1 = sscanf(format_str7, "%5d %5d", &c, &d);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, c);
  ck_assert_int_eq(b, d);

  long z1 = 0, z2 = 0, x1 = 0, x2 = 0, y1 = 0, y2 = 0, d1 = 0, d2 = 0;
  const char fstr[] = "%ld %ld %ld %ld";
  const char str[] = "123 456 789 111";

  int res1 = s21_sscanf(str, fstr, &z1, &x1, &y1, &d1);
  int res2 = sscanf(str, fstr, &z2, &x2, &y2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(z1, z2);
  ck_assert_int_eq(x1, x2);
  ck_assert_int_eq(y1, y2);
  ck_assert_int_eq(d1, d2);

  z1 = 0, z2 = 0, x1 = 0, x2 = 0, y1 = 0, y2 = 0, d1 = 0, d2 = 0;
  const char fstr2[] = "%1ld %1ld %1ld %1ld";

  res1 = s21_sscanf(str, fstr2, &z1, &x1, &y1, &d1);
  res2 = sscanf(str, fstr2, &z2, &x2, &y2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(z1, z2);
  ck_assert_int_eq(x1, x2);
  ck_assert_int_eq(y1, y2);
  ck_assert_int_eq(d1, d2);

  z1 = 0, z2 = 0, x1 = 0, x2 = 0, y1 = 0, y2 = 0, d1 = 0, d2 = 0;
  const char fstr3[BUFF_SIZE] = "%3ld %3ld %3ld %3ld";

  res1 = s21_sscanf(str, fstr3, &z1, &x1, &y1, &d1);
  res2 = sscanf(str, fstr3, &z2, &x2, &y2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(z1, z2);
  ck_assert_int_eq(x1, x2);
  ck_assert_int_eq(y1, y2);
  ck_assert_int_eq(d1, d2);

  z1 = 0, z2 = 0, x1 = 0, x2 = 0, y1 = 0, y2 = 0, d1 = 0, d2 = 0;
  const char fstr4[BUFF_SIZE] = "%5ld %5ld %5ld %5ld";

  res1 = s21_sscanf(str, fstr4, &z1, &x1, &y1, &d1);
  res2 = sscanf(str, fstr4, &z2, &x2, &y2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(z1, z2);
  ck_assert_int_eq(x1, x2);
  ck_assert_int_eq(y1, y2);
  ck_assert_int_eq(d1, d2);

  const char *fstr5 = "123 456";

  result1 = s21_sscanf(fstr5, "%d %*d", &a);
  result_origin1 = sscanf(fstr5, "%d %*d", &d);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, d);

  result1 = s21_sscanf(fstr5, "%*d %d", &a);
  result_origin1 = sscanf(fstr5, "%*d %d", &d);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, d);

  const char *fstr6 = "-123 -456";

  result1 = s21_sscanf(fstr6, "%d %*d", &a);
  result_origin1 = sscanf(fstr6, "%d %*d", &d);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, d);

  result1 = s21_sscanf(fstr6, "%*d %d", &a);
  result_origin1 = sscanf(fstr6, "%*d %d", &d);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, d);

  const char *fstr7 = "0 0";

  result1 = s21_sscanf(fstr7, "%d %*d", &a);
  result_origin1 = sscanf(fstr7, "%d %*d", &d);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, d);

  result1 = s21_sscanf(fstr7, "%*d %d", &a);
  result_origin1 = sscanf(fstr7, "%*d %d", &d);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, d);
}

END_TEST

START_TEST(s21_sscanf_test_19_u_option) {
  unsigned short a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "-1337 +21 -5008 3000";
  const char fstr[] = "%hu %hu %hu %hu";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(s21_sscanf_test_18_u_option) {
  unsigned short a = 0;
  unsigned short b = 0;
  unsigned short c = 0;
  unsigned short d = 0;

  int result1 = s21_sscanf("65535 36", "%hu %hu", &a, &b);
  int result_origin1 = sscanf("65535 36", "%hu %hu", &c, &d);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, c);
  ck_assert_int_eq(b, d);

  result1 = s21_sscanf("0 0", "%hu %hu", &a, &b);
  result_origin1 = sscanf("0 0", "%hu %hu", &c, &d);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, c);
  ck_assert_int_eq(b, d);

  result1 = s21_sscanf("123 123", "%hu %hu", &a, &b);
  result_origin1 = sscanf("123 123", "%hu %hu", &c, &d);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, c);
  ck_assert_int_eq(b, d);

  const char *format_str1 = "123 456";

  result1 = s21_sscanf(format_str1, "%hu %hu", &a, &b);
  result_origin1 = sscanf(format_str1, "%hu %hu", &c, &d);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, c);
  ck_assert_int_eq(b, d);

  const char *format_str2 = "1233 1456";

  result1 = s21_sscanf(format_str2, "%hu %hu", &a, &b);
  result_origin1 = sscanf(format_str2, "%hu %hu", &c, &d);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, c);
  ck_assert_int_eq(b, d);

  const char *format_str3 = "0 0";

  result1 = s21_sscanf(format_str3, "%hu %hu", &a, &b);
  result_origin1 = sscanf(format_str3, "%hu %hu", &c, &d);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, c);
  ck_assert_int_eq(b, d);

  const char *format_str4 = "123 456";

  result1 = s21_sscanf(format_str4, "%10hu %10hu", &a, &b);
  result_origin1 = sscanf(format_str4, "%10hu %10hu", &c, &d);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, c);
  ck_assert_int_eq(b, d);

  const char *format_str5 = "123 456";

  result1 = s21_sscanf(format_str5, "%2hu %4hu", &a, &b);
  result_origin1 = sscanf(format_str5, "%2hu %4hu", &c, &d);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, c);
  ck_assert_int_eq(b, d);

  const char *format_str6 = "0 0";

  result1 = s21_sscanf(format_str6, "%5hu %5hu", &a, &b);
  result_origin1 = sscanf(format_str6, "%5hu %5hu", &c, &d);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, c);
  ck_assert_int_eq(b, d);

  const char *format_str7 = "65535 65535";

  result1 = s21_sscanf(format_str7, "%5hu %5hu", &a, &b);
  result_origin1 = sscanf(format_str7, "%5hu %5hu", &c, &d);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, c);
  ck_assert_int_eq(b, d);

  long int z1 = 0, z2 = 0, x1 = 0, x2 = 0, y1 = 0, y2 = 0, d1 = 0, d2 = 0;
  const char fstr4[] = "%lu %lu %lu %lu";
  const char str[] = "123 456 789 111";

  int res1 = s21_sscanf(str, fstr4, &z1, &x1, &y1, &d1);
  int res2 = sscanf(str, fstr4, &z2, &x2, &y2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(z1, z2);
  ck_assert_int_eq(x1, x2);
  ck_assert_int_eq(y1, y2);
  ck_assert_int_eq(d1, d2);

  z1 = 0, z2 = 0, x1 = 0, x2 = 0, y1 = 0, y2 = 0, d1 = 0, d2 = 0;
  const char fstr3[] = "%1lu %1lu %1lu %1lu";

  res1 = s21_sscanf(str, fstr3, &z1, &x1, &y1, &d1);
  res2 = sscanf(str, fstr3, &z2, &x2, &y2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(z1, z2);
  ck_assert_int_eq(x1, x2);
  ck_assert_int_eq(y1, y2);
  ck_assert_int_eq(d1, d2);

  z1 = 0, z2 = 0, x1 = 0, x2 = 0, y1 = 0, y2 = 0, d1 = 0, d2 = 0;
  const char fstr1[] = "%2lu %2lu %2lu %2lu";

  res1 = s21_sscanf(str, fstr1, &z1, &x1, &y1, &d1);
  res2 = sscanf(str, fstr1, &z2, &x2, &y2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(z1, z2);
  ck_assert_int_eq(x1, x2);
  ck_assert_int_eq(y1, y2);
  ck_assert_int_eq(d1, d2);

  z1 = 0, z2 = 0, x1 = 0, x2 = 0, y1 = 0, y2 = 0, d1 = 0, d2 = 0;
  const char fstr2[] = "%5lu %5lu %5lu %5lu";

  res1 = s21_sscanf(str, fstr2, &z1, &x1, &y1, &d1);
  res2 = sscanf(str, fstr2, &z2, &x2, &y2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(z1, z2);
  ck_assert_int_eq(x1, x2);
  ck_assert_int_eq(y1, y2);
  ck_assert_int_eq(d1, d2);

  unsigned int aa = 0;
  unsigned int bb = 0;
  unsigned int cc = 0;
  unsigned int dd = 0;

  result1 = s21_sscanf("65535 36", "%u %u", &aa, &bb);
  result_origin1 = sscanf("65535 36", "%u %u", &cc, &dd);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(aa, cc);
  ck_assert_int_eq(bb, dd);

  result1 = s21_sscanf("0 0", "%u %u", &aa, &bb);
  result_origin1 = sscanf("0 0", "%u %u", &cc, &dd);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(aa, cc);
  ck_assert_int_eq(bb, dd);

  result1 = s21_sscanf("123 123", "%u %u", &aa, &bb);
  result_origin1 = sscanf("123 123", "%u %u", &cc, &dd);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(aa, cc);
  ck_assert_int_eq(bb, dd);

  const char *format_str10 = "123 456";

  result1 = s21_sscanf(format_str10, "%u %u", &aa, &bb);
  result_origin1 = sscanf(format_str10, "%u %u", &cc, &dd);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(aa, cc);
  ck_assert_int_eq(bb, dd);

  const char *format_str11 = "1233 1456";

  result1 = s21_sscanf(format_str11, "%u %u", &aa, &bb);
  result_origin1 = sscanf(format_str11, "%u %u", &cc, &dd);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(aa, cc);
  ck_assert_int_eq(bb, dd);

  const char *format_str12 = "0 0";

  result1 = s21_sscanf(format_str12, "%u %u", &aa, &bb);
  result_origin1 = sscanf(format_str12, "%u %u", &cc, &dd);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(aa, cc);
  ck_assert_int_eq(bb, dd);

  const char *format_str13 = "123 456";

  result1 = s21_sscanf(format_str13, "%10u %10u", &aa, &bb);
  result_origin1 = sscanf(format_str13, "%10u %10u", &cc, &dd);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(aa, cc);
  ck_assert_int_eq(bb, dd);

  const char *format_str14 = "123 456";

  result1 = s21_sscanf(format_str14, "%2u %4u", &aa, &bb);
  result_origin1 = sscanf(format_str14, "%2u %4u", &cc, &dd);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(aa, cc);
  ck_assert_int_eq(bb, dd);

  const char *format_str15 = "0 0";

  result1 = s21_sscanf(format_str15, "%5u %5u", &aa, &bb);
  result_origin1 = sscanf(format_str15, "%5u %5u", &cc, &dd);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(aa, cc);
  ck_assert_int_eq(bb, dd);

  const char *format_str16 = "65535 65535";

  result1 = s21_sscanf(format_str16, "%5u %5u", &aa, &bb);
  result_origin1 = sscanf(format_str16, "%5u %5u", &cc, &dd);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(aa, cc);
  ck_assert_int_eq(bb, dd);

  const char *format_str17 = "0 0";

  result1 = s21_sscanf(format_str17, "%u %*u", &aa);
  result_origin1 = sscanf(format_str17, "%u %*u", &cc);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(aa, cc);

  const char *format_str18 = "0 0";

  result1 = s21_sscanf(format_str18, "%*u %u", &aa);
  result_origin1 = sscanf(format_str18, "%*u %u", &cc);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(aa, cc);

  const char *format_str19 = "1233 1456";

  result1 = s21_sscanf(format_str19, "%hu %*u", &a);
  result_origin1 = sscanf(format_str19, "%hu %*u", &c);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, c);

  const char *format_str20 = "1233 1456";

  result1 = s21_sscanf(format_str20, "%*u %hu", &a);
  result_origin1 = sscanf(format_str20, "%*u %hu", &c);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, c);
}

END_TEST

START_TEST(s21_sscanf_test_19_c_option) {
  char a = 0;
  char b = 0;
  char c = 0;
  char d = 0;

  int result1 = s21_sscanf("a b", "%c %c", &a, &b);
  int result_origin1 = sscanf("a b", "%c %c", &c, &d);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, c);
  ck_assert_int_eq(b, d);

  result1 = s21_sscanf(" A B", "%c %c", &a, &b);
  result_origin1 = sscanf(" A B", "%c %c", &c, &d);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, c);
  ck_assert_int_eq(b, d);

  result1 = s21_sscanf("- -", "%c %c", &a, &b);
  result_origin1 = sscanf("- -", "%c %c", &c, &d);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, c);
  ck_assert_int_eq(b, d);

  const char *format_str1 = "123  150";

  result1 = s21_sscanf(format_str1, "%c %c", &a, &b);
  result_origin1 = sscanf(format_str1, "%c %c", &c, &d);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, c);
  ck_assert_int_eq(b, d);

  const char *format_str2 = "1 10";

  result1 = s21_sscanf(format_str2, "%c %c", &a, &b);
  result_origin1 = sscanf(format_str2, "%c %c", &c, &d);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, c);
  ck_assert_int_eq(b, d);

  const char *format_str3 = "0 0";

  result1 = s21_sscanf(format_str3, "%c %c", &a, &b);
  result_origin1 = sscanf(format_str3, "%c %c", &c, &d);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, c);
  ck_assert_int_eq(b, d);

  const char *format_str4 = "";

  result1 = s21_sscanf(format_str4, "%*c %c %c", &a, &b);
  result_origin1 = sscanf(format_str4, "%*c %c %c", &c, &d);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, c);
  ck_assert_int_eq(b, d);

  const char *format_str5 = "qwe 1";
  result1 = s21_sscanf(format_str5, "%Lc %c", &a, &b);

  const char *format_str6 = "qwerty";

  result1 = s21_sscanf(format_str6, "%1c %c", &a, &b);
  result_origin1 = sscanf(format_str6, "%1c %c", &c, &d);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, c);
  ck_assert_int_eq(b, d);

  wchar_t a_w = 0;
  wchar_t b_w = 0;
  wchar_t c_w = 0;
  wchar_t d_w = 0;
  result1 = s21_sscanf("A B", "%lc %lc", &a_w, &b_w);
  result_origin1 = sscanf("A B", "%lc %lc", &c_w, &d_w);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a_w, c_w);
  ck_assert_int_eq(b_w, d_w);
}

END_TEST

START_TEST(s21_sscanf_test_20_s_option) {
  char array[BUFF_SIZE] = {0};
  char array_origin[BUFF_SIZE] = {0};

  int result = s21_sscanf("12345 36", "%s", array);
  int result_origin = sscanf("12345 36", "%s", array_origin);
  ck_assert_int_eq(result, result_origin);
  ck_assert_str_eq(array, array_origin);

  char array1[BUFF_SIZE] = {0};
  char array_origin1[BUFF_SIZE] = {0};

  result = s21_sscanf("Hello Dotan", "%s", array1);
  result_origin = sscanf("Hello Dotan", "%s", array_origin1);
  ck_assert_int_eq(result, result_origin);
  ck_assert_str_eq(array1, array_origin1);

  char array2[BUFF_SIZE] = {0};
  char array_origin2[BUFF_SIZE] = {0};

  result = s21_sscanf("", "%s", array2);
  result_origin = sscanf("", "%s", array_origin2);
  ck_assert_int_eq(result, result_origin);
  ck_assert_str_eq(array2, array_origin2);

  char array3[BUFF_SIZE] = {0};
  char array_origin3[BUFF_SIZE] = {0};

  result = s21_sscanf("", "%s", array3);
  result_origin = sscanf("", "%s", array_origin3);
  ck_assert_int_eq(result, result_origin);
  ck_assert_str_eq(array3, array_origin3);

  wchar_t array_t_1[999] = {0};
  wchar_t array_t_2[999] = {0};
  wchar_t array_t_3[999] = {0};
  wchar_t array_t_4[999] = {0};

  result = s21_sscanf("qwerty", "%4ls%ls", array_t_1, array_t_3);
  result_origin = sscanf("qwerty", "%4ls%ls", array_t_2, array_t_4);
  ck_assert_str_eq((char *)array_t_1, (char *)array_t_2);
  ck_assert_str_eq((char *)array_t_3, (char *)array_t_4);
  ck_assert_int_eq(result, result_origin);
}

END_TEST

START_TEST(s21_sscanf_test_21_i_option) {
  int a = 0;
  int b = 0;
  int result = s21_sscanf("0x1E240", "%i", &a);
  int result_origin = sscanf("0x1E240", "%i", &b);
  ck_assert_int_eq(result, result_origin);
  ck_assert_int_eq(a, b);

  a = 0;
  b = 0;
  result = s21_sscanf("0xABCZ", "%i", &a);
  result_origin = sscanf("0xABCZ", "%i", &b);
  ck_assert_int_eq(result, result_origin);
  ck_assert_int_eq(a, b);

  a = 0;
  b = 0;
  result = s21_sscanf("0361100", "%i", &a);
  result_origin = sscanf("0361100", "%i", &b);
  ck_assert_int_eq(result, result_origin);
  ck_assert_int_eq(a, b);

  a = 0;
  b = 0;
  result = s21_sscanf("4147483648", "%i", &a);
  result_origin = sscanf("4147483648", "%i", &b);
  ck_assert_int_eq(result, result_origin);
  ck_assert_int_eq(a, b);

  a = 0;
  b = 0;
  result = s21_sscanf("04147483648", "%i", &a);
  result_origin = sscanf("04147483648", "%i", &b);
  ck_assert_int_eq(result, result_origin);
  ck_assert_int_eq(a, b);

  a = 0;
  b = 0;
  result = s21_sscanf("0x4147483648", "%i", &a);
  result_origin = sscanf("0x4147483648", "%i", &b);
  ck_assert_int_eq(result, result_origin);
  ck_assert_int_eq(a, b);

  a = 0;
  b = 0;
  result = s21_sscanf("0X83648", "%i", &a);
  result_origin = sscanf("0X83648", "%i", &b);
  ck_assert_int_eq(result, result_origin);
  ck_assert_int_eq(a, b);

  a = 0;
  b = 0;
  result = s21_sscanf("-123456", "%i", &a);
  result_origin = sscanf("-123456", "%i", &b);
  ck_assert_int_eq(result, result_origin);
  ck_assert_int_eq(a, b);

  a = 0;
  b = 0;
  result = s21_sscanf("+123456", "%i", &a);
  result_origin = sscanf("+123456", "%i", &b);
  ck_assert_int_eq(result, result_origin);
  ck_assert_int_eq(a, b);

  a = 10;
  b = 10;
  result = s21_sscanf("0", "%i", &a);
  result_origin = sscanf("0", "%i", &b);
  ck_assert_int_eq(result, result_origin);
  ck_assert_int_eq(a, b);

  a = 10;
  b = 10;
  result = s21_sscanf("0", "%i", &a);
  result_origin = sscanf("0", "%i", &b);
  ck_assert_int_eq(result, result_origin);
  ck_assert_int_eq(a, b);

  a = 10;
  b = 10;
  result = s21_sscanf("123456", "%4i", &a);
  result_origin = sscanf("123456", "%4i", &b);
  ck_assert_int_eq(result, result_origin);
  ck_assert_int_eq(a, b);

  a = 10;
  b = 10;
  result = s21_sscanf("-123456", "%4i", &a);
  result_origin = sscanf("-123456", "%4i", &b);
  ck_assert_int_eq(result, result_origin);
  ck_assert_int_eq(a, b);

  short int ah = 10;
  short int bh = 10;
  result = s21_sscanf("32767", "%hi", &ah);
  result_origin = sscanf("32767", "%hi", &bh);
  ck_assert_int_eq(result, result_origin);
  ck_assert_int_eq(ah, bh);

  ah = 10;
  bh = 10;
  result = s21_sscanf("52767", "%hi", &ah);
  result_origin = sscanf("52767", "%hi", &bh);
  ck_assert_int_eq(result, result_origin);
  ck_assert_int_eq(ah, bh);

  ah = 10;
  bh = 10;
  result = s21_sscanf("-32767", "%hi", &ah);
  result_origin = sscanf("-32767", "%hi", &bh);
  ck_assert_int_eq(result, result_origin);
  ck_assert_int_eq(ah, bh);

  ah = 10;
  bh = 10;
  result = s21_sscanf("-52767", "%hi", &ah);
  result_origin = sscanf("-52767", "%hi", &bh);
  ck_assert_int_eq(result, result_origin);
  ck_assert_int_eq(ah, bh);

  ah = 10;
  bh = 10;
  result = s21_sscanf("-52767", "%hi", &ah);
  result_origin = sscanf("-52767", "%hi", &bh);
  ck_assert_int_eq(result, result_origin);
  ck_assert_int_eq(ah, bh);

  ah = 10;
  bh = 10;
  result = s21_sscanf("-52767", "%hi", &ah);
  result_origin = sscanf("-52767", "%hi", &bh);
  ck_assert_int_eq(result, result_origin);
  ck_assert_int_eq(ah, bh);

  long int al = 0;
  long int bl = 0;
  result = s21_sscanf("9223372036854775807", "%li", &al);
  result_origin = sscanf("9223372036854775807", "%li", &bl);
  ck_assert_int_eq(result, result_origin);
  ck_assert_int_eq(al, bl);

  al = 0;
  bl = 0;
  result = s21_sscanf("9223372036854775806", "%li", &al);
  result_origin = sscanf("9223372036854775806", "%li", &bl);
  ck_assert_int_eq(result, result_origin);
  ck_assert_int_eq(al, bl);

  al = 0;
  bl = 0;
  result = s21_sscanf("-9223372036854775807", "%li", &al);
  result_origin = sscanf("-9223372036854775807", "%li", &bl);
  ck_assert_int_eq(result, result_origin);
  ck_assert_int_eq(al, bl);
}

END_TEST

START_TEST(s21_sscanf_test_21_f_option) {
  float a = 0;
  float b = 0;
  float c = 0;
  float d = 0;

  int result = s21_sscanf("0.1234 123", "%f %f", &a, &b);
  int result_origin = sscanf("0.1234 123", "%f %f", &c, &d);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);
  ck_assert_float_eq(b, d);

  a = 0;
  b = 0;
  c = 0;
  d = 0;

  result = s21_sscanf(".1234 123.123456789", "%f %f", &a, &b);
  result_origin = sscanf(".1234 123.123456789", "%f %f", &c, &d);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);
  ck_assert_float_eq(b, d);

  a = 0;
  b = 0;
  c = 0;
  d = 0;

  result = s21_sscanf(".1234 -123.123456789", "%f %f", &a, &b);
  result_origin = sscanf(".1234 -123.123456789", "%f %f", &c, &d);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);
  ck_assert_float_eq(b, d);

  a = 0;
  b = 0;
  c = 0;
  d = 0;

  result = s21_sscanf(".1234 -123.123456789", "%f %6f", &a, &b);
  result_origin = sscanf(".1234 -123.123456789", "%f %6f", &c, &d);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);
  ck_assert_float_eq(b, d);

  a = 0;
  b = 0;
  c = 0;
  d = 0;

  result = s21_sscanf("3.402823466E+38", "%f", &a);
  result_origin = sscanf("3.402823466E+38", "%f", &c);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);

  a = 0;
  b = 0;
  c = 0;
  d = 0;

  result = s21_sscanf("10.402823466E+38", "%f", &a);
  result_origin = sscanf("10.402823466E+38", "%f", &c);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);

  a = 0;
  b = 0;
  c = 0;
  d = 0;

  result = s21_sscanf("1.175494351E–38", "%f", &a);
  result_origin = sscanf("1.175494351E–38", "%f", &c);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);

  a = 0;
  b = 0;
  c = 0;
  d = 0;

  result = s21_sscanf("10.175494351E–38", "%f", &a);
  result_origin = sscanf("10.175494351E–38", "%f", &c);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);

  long double al = 0;
  long double cl = 0;

  result = s21_sscanf("3.4E-4932", "%Lf", &al);
  result_origin = sscanf("3.4E-4932", "%Lf", &cl);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(al, cl);

  al = 0;
  cl = 0;

  result = s21_sscanf("30.4E-4932", "%Lf", &al);
  result_origin = sscanf("30.4E-4932", "%Lf", &cl);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(al, cl);

  al = 0;
  cl = 0;

  result = s21_sscanf("3.4E+4932", "%Lf", &al);
  result_origin = sscanf("3.4E+4932", "%Lf", &cl);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(al, cl);

  al = 0;
  cl = 0;

  result = s21_sscanf("30.4E+4932", "%Lf", &al);
  result_origin = sscanf("30.4E+4932", "%Lf", &cl);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(al, cl);
}

END_TEST

START_TEST(s21_sscanf_test_21_g_option) {
  float a = 0;
  float b = 0;
  float c = 0;
  float d = 0;

  int result = s21_sscanf("0.12 123", "%g %g", &a, &b);
  int result_origin = sscanf("0.12 123", "%g %g", &c, &d);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);
  ck_assert_float_eq(b, d);

  a = 0;
  b = 0;
  c = 0;
  d = 0;

  result = s21_sscanf(".1234 123.123456789", "%g %g", &a, &b);
  result_origin = sscanf(".1234 123.123456789", "%g %g", &c, &d);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);
  ck_assert_float_eq(b, d);

  a = 0;
  b = 0;
  c = 0;
  d = 0;

  result = s21_sscanf(".1234 -123.123456789", "%g %6g", &a, &b);
  result_origin = sscanf(".1234 -123.123456789", "%g %6g", &c, &d);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);
  ck_assert_float_eq(b, d);

  a = 0;
  b = 0;
  c = 0;
  d = 0;

  result = s21_sscanf(".1234 -123.12E+2", "%g %g", &a, &b);
  result_origin = sscanf(".1234 -123.12E+2", "%g %g", &c, &d);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);
  ck_assert_float_eq(b, d);

  a = 0;
  b = 0;
  c = 0;
  d = 0;

  result = s21_sscanf("1.175494351E–38", "%g", &a);
  result_origin = sscanf("1.175494351E–38", "%g", &c);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);

  a = 0;
  b = 0;
  c = 0;
  d = 0;

  result = s21_sscanf("10.175494351E–38", "%g", &a);
  result_origin = sscanf("10.175494351E–38", "%g", &c);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);

  a = 0;
  b = 0;
  c = 0;
  d = 0;

  result = s21_sscanf("3.402823466E+38", "%g", &a);
  result_origin = sscanf("3.402823466E+38", "%g", &c);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);

  a = 0;
  b = 0;
  c = 0;
  d = 0;

  result = s21_sscanf("30.402823466E+38", "%g", &a);
  result_origin = sscanf("30.402823466E+38", "%g", &c);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);

  long double al = 0;
  long double cl = 0;

  result = s21_sscanf("3.4E-4932", "%Lg", &al);
  result_origin = sscanf("3.4E-4932", "%Lg", &cl);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(al, cl);

  al = 0;
  cl = 0;

  result = s21_sscanf("30.4E-4932", "%Lg", &al);
  result_origin = sscanf("30.4E-4932", "%Lg", &cl);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(al, cl);

  al = 0;
  cl = 0;

  result = s21_sscanf("3.4E+4932", "%Lg", &al);
  result_origin = sscanf("3.4E+4932", "%Lg", &cl);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(al, cl);

  al = 0;
  cl = 0;

  result = s21_sscanf("30.4E+4932", "%Lg", &al);
  result_origin = sscanf("30.4E+4932", "%Lg", &cl);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(al, cl);
}

END_TEST

START_TEST(s21_sscanf_test_21_G_option) {
  float a = 0;
  float b = 0;
  float c = 0;
  float d = 0;

  int result = s21_sscanf("0.12 123", "%G %G", &a, &b);
  int result_origin = sscanf("0.12 123", "%G %G", &c, &d);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);
  ck_assert_float_eq(b, d);

  a = 0;
  b = 0;
  c = 0;
  d = 0;

  result = s21_sscanf(".1234 123.123456789", "%G %G", &a, &b);
  result_origin = sscanf(".1234 123.123456789", "%G %G", &c, &d);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);
  ck_assert_float_eq(b, d);

  a = 0;
  b = 0;
  c = 0;
  d = 0;

  result = s21_sscanf(".1234 -123.123456789", "%G %6G", &a, &b);
  result_origin = sscanf(".1234 -123.123456789", "%G %6G", &c, &d);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);
  ck_assert_float_eq(b, d);

  a = 0;
  b = 0;
  c = 0;
  d = 0;

  result = s21_sscanf(".1234 -123.12E+2", "%G %G", &a, &b);
  result_origin = sscanf(".1234 -123.12E+2", "%G %G", &c, &d);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);
  ck_assert_float_eq(b, d);

  a = 0;
  b = 0;
  c = 0;
  d = 0;

  result = s21_sscanf("1.175494351E–38", "%G", &a);
  result_origin = sscanf("1.175494351E–38", "%G", &c);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);

  a = 0;
  b = 0;
  c = 0;
  d = 0;

  result = s21_sscanf("10.175494351E–38", "%G", &a);
  result_origin = sscanf("10.175494351E–38", "%G", &c);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);

  a = 0;
  b = 0;
  c = 0;
  d = 0;

  result = s21_sscanf("3.402823466E+38", "%G", &a);
  result_origin = sscanf("3.402823466E+38", "%G", &c);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);

  a = 0;
  b = 0;
  c = 0;
  d = 0;

  result = s21_sscanf("30.402823466E+38", "%G", &a);
  result_origin = sscanf("30.402823466E+38", "%G", &c);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);

  long double al = 0;
  long double cl = 0;

  result = s21_sscanf("3.4E-4932", "%LG", &al);
  result_origin = sscanf("3.4E-4932", "%LG", &cl);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(al, cl);

  al = 0;
  cl = 0;

  result = s21_sscanf("30.4E-4932", "%LG", &al);
  result_origin = sscanf("30.4E-4932", "%LG", &cl);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(al, cl);

  al = 0;
  cl = 0;

  result = s21_sscanf("3.4E+4932", "%LG", &al);
  result_origin = sscanf("3.4E+4932", "%LG", &cl);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(al, cl);

  al = 0;
  cl = 0;

  result = s21_sscanf("30.4E+4932", "%LG", &al);
  result_origin = sscanf("30.4E+4932", "%LG", &cl);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(al, cl);
}

END_TEST

START_TEST(s21_sscanf_test_21_e_option) {
  float a = 0;
  float b = 0;
  float c = 0;
  float d = 0;

  int result = s21_sscanf("0.12 123", "%e %e", &a, &b);
  int result_origin = sscanf("0.12 123", "%e %e", &c, &d);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);
  ck_assert_float_eq(b, d);

  a = 0;
  b = 0;
  c = 0;
  d = 0;

  result = s21_sscanf(".1234 -123.123456789", "%e %6e", &a, &b);
  result_origin = sscanf(".1234 -123.123456789", "%e %6e", &c, &d);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);
  ck_assert_float_eq(b, d);

  a = 0;
  b = 0;
  c = 0;
  d = 0;

  result = s21_sscanf(".1234 123.123456789e+5", "%e %e", &a, &b);
  result_origin = sscanf(".1234 123.123456789e+5", "%e %e", &c, &d);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);
  ck_assert_float_eq(b, d);

  a = 0;
  b = 0;
  c = 0;
  d = 0;

  result = s21_sscanf(".1234 -123.12E+2", "%e %e", &a, &b);
  result_origin = sscanf(".1234 -123.12E+2", "%e %e", &c, &d);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);
  ck_assert_float_eq(b, d);

  a = 0;
  b = 0;
  c = 0;
  d = 0;

  result = s21_sscanf("1.175494351E–38", "%e", &a);
  result_origin = sscanf("1.175494351E–38", "%e", &c);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);

  a = 0;
  b = 0;
  c = 0;
  d = 0;

  result = s21_sscanf("10.175494351E–38", "%e", &a);
  result_origin = sscanf("10.175494351E–38", "%e", &c);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);

  a = 0;
  b = 0;
  c = 0;
  d = 0;

  result = s21_sscanf("3.402823466E+38", "%e", &a);
  result_origin = sscanf("3.402823466E+38", "%e", &c);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);

  a = 0;
  b = 0;
  c = 0;
  d = 0;

  result = s21_sscanf("30.402823466E+38", "%e", &a);
  result_origin = sscanf("30.402823466E+38", "%e", &c);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);

  long double al = 0;
  long double cl = 0;

  result = s21_sscanf("3.4E-4932", "%Le", &al);
  result_origin = sscanf("3.4E-4932", "%Le", &cl);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(al, cl);

  al = 0;
  cl = 0;

  result = s21_sscanf("30.4E-4932", "%Le", &al);
  result_origin = sscanf("30.4E-4932", "%Le", &cl);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(al, cl);

  al = 0;
  cl = 0;

  result = s21_sscanf("3.4E+4932", "%Le", &al);
  result_origin = sscanf("3.4E+4932", "%Le", &cl);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(al, cl);

  al = 0;
  cl = 0;

  result = s21_sscanf("30.4E+4932", "%Le", &al);
  result_origin = sscanf("30.4E+4932", "%Le", &cl);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(al, cl);
}

END_TEST

START_TEST(s21_sscanf_test_21_E_option) {
  float a = 0;
  float b = 0;
  float c = 0;
  float d = 0;

  int result = s21_sscanf("0.12 123", "%E %E", &a, &b);
  int result_origin = sscanf("0.12 123", "%E %E", &c, &d);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);
  ck_assert_float_eq(b, d);

  a = 0;
  b = 0;
  c = 0;
  d = 0;

  result = s21_sscanf(".1234 -123.123456789", "%E %6E", &a, &b);
  result_origin = sscanf(".1234 -123.123456789", "%E %6E", &c, &d);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);
  ck_assert_float_eq(b, d);

  a = 0;
  b = 0;
  c = 0;
  d = 0;

  result = s21_sscanf(".1234 123.123456789E+5", "%E %E", &a, &b);
  result_origin = sscanf(".1234 123.123456789E+5", "%E %E", &c, &d);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);
  ck_assert_float_eq(b, d);

  a = 0;
  b = 0;
  c = 0;
  d = 0;

  result = s21_sscanf(".1234 -123.12E+2", "%E %E", &a, &b);
  result_origin = sscanf(".1234 -123.12E+2", "%E %E", &c, &d);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);
  ck_assert_float_eq(b, d);

  a = 0;
  b = 0;
  c = 0;
  d = 0;

  result = s21_sscanf("1.175494351E–38", "%E", &a);
  result_origin = sscanf("1.175494351E–38", "%E", &c);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);

  a = 0;
  b = 0;
  c = 0;
  d = 0;

  result = s21_sscanf("10.175494351E–38", "%E", &a);
  result_origin = sscanf("10.175494351E–38", "%E", &c);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);

  a = 0;
  b = 0;
  c = 0;
  d = 0;

  result = s21_sscanf("3.402823466E+38", "%E", &a);
  result_origin = sscanf("3.402823466E+38", "%E", &c);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);

  a = 0;
  b = 0;
  c = 0;
  d = 0;

  result = s21_sscanf("30.402823466E+38", "%E", &a);
  result_origin = sscanf("30.402823466E+38", "%E", &c);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);

  long double al = 0;
  long double cl = 0;

  result = s21_sscanf("3.4E-4932", "%LE", &al);
  result_origin = sscanf("3.4E-4932", "%LE", &cl);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(al, cl);

  al = 0;
  cl = 0;

  result = s21_sscanf("30.4E-4932", "%LE", &al);
  result_origin = sscanf("30.4E-4932", "%LE", &cl);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(al, cl);

  al = 0;
  cl = 0;

  result = s21_sscanf("3.4E+4932", "%LE", &al);
  result_origin = sscanf("3.4E+4932", "%LE", &cl);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(al, cl);

  al = 0;
  cl = 0;

  result = s21_sscanf("30.4E+4932", "%LE", &al);
  result_origin = sscanf("30.4E+4932", "%LE", &cl);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(al, cl);
}

END_TEST

START_TEST(s21_sscanf_test_21_percent_option) {
  float a = 0;
  float b = 0;
  float c = 0;
  float d = 0;

  int result = s21_sscanf("1.55 % 2", "%f %% %f", &a, &b);
  int result_origin = sscanf("1.55 % 2", "%f %% %f", &c, &d);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);
  ck_assert_float_eq(b, d);

  a = 0;
  b = 0;
  c = 0;
  d = 0;

  result = s21_sscanf("1.55 2", "%f %f", &a, &b);
  result_origin = sscanf("1.55 2", "%f %f", &c, &d);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);
  ck_assert_float_eq(b, d);

  a = 0;
  b = 0;
  c = 0;
  d = 0;

  result = s21_sscanf("1.55 2", "%f %f", &a, &b);
  result_origin = sscanf("1.55 2", "%f %f", &c, &d);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);
  ck_assert_float_eq(b, d);

  a = 0;
  b = 0;
  c = 0;
  d = 0;

  result = s21_sscanf("% 1.55 2", "%%%f %f", &a, &b);
  result_origin = sscanf("% 1.55 2", "%%%f %f", &c, &d);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);
  ck_assert_float_eq(b, d);
}

END_TEST

START_TEST(s21_sscanf_test_21_star_option) {
  float a = 0;
  float c = 0;

  int result = s21_sscanf(".1234 123.123456789e-5", "%*E %E", &a);
  int result_origin = sscanf(".1234 123.123456789e-5", "%*E %E", &c);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);

  a = 0;
  c = 0;

  result = s21_sscanf(".1234 123.123456789E-5", "%*e %e", &a);
  result_origin = sscanf(".1234 123.123456789E-5", "%*e %e", &c);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);

  a = 0;
  c = 0;

  result = s21_sscanf(".1234 123.123456789", "%*G %G", &a);
  result_origin = sscanf(".1234 123.123456789", "%*G %G", &c);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);

  a = 0;
  c = 0;

  result = s21_sscanf(".1234 123.123456789", "%*g %g", &a);
  result_origin = sscanf(".1234 123.123456789", "%*g %g", &c);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);

  a = 0;
  c = 0;

  result = s21_sscanf(".1234 123.123456789", "%*f %f", &a);
  result_origin = sscanf(".1234 123.123456789", "%*f %f", &c);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);

  int ai = 0;
  int bi = 0;
  result = s21_sscanf("0x1234 442", "%*i %i", &ai);
  result_origin = sscanf("0x1234 442", "%*i %i", &bi);
  ck_assert_int_eq(result, result_origin);
  ck_assert_int_eq(ai, bi);

  char array3[BUFF_SIZE] = {0};
  char array_origin3[BUFF_SIZE] = {0};

  result = s21_sscanf("1234.5 442", "%*s %s", array3);
  result_origin = sscanf("1234.5 442", "%*s %s", array_origin3);
  ck_assert_int_eq(result, result_origin);
  ck_assert_str_eq(array3, array_origin3);

  char a_char = 0;
  char b_char = 0;
  char c_char = 0;
  char d_char = 0;
  const char *format_str4 = "";

  result = s21_sscanf(format_str4, "%*c %c %c", &a_char, &b_char);
  result_origin = sscanf(format_str4, "%*c %c %c", &c_char, &d_char);
  ck_assert_int_eq(result, result_origin);
  ck_assert_int_eq(a_char, c_char);
  ck_assert_int_eq(b_char, d_char);
}

END_TEST
START_TEST(s21_sscanf_test_16_xX_option) {
  int a = 0;
  int b = 0;

  int c = 0;
  int d = 0;

  int result1 = s21_sscanf("1E240 12D687", "%x %X", &a, &b);
  int result_origin1 = sscanf("1E240 12D687", "%x %X", &c, &d);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, c);
  ck_assert_int_eq(b, d);

  a = 0;
  b = 0;

  result1 = s21_sscanf("1E240", "%x", &a);
  result_origin1 = sscanf("1E240", "%x", &b);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, b);

  a = 0;
  b = 0;

  result1 = s21_sscanf("1E240", "%X", &a);
  result_origin1 = sscanf("1E240", "%X", &b);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, b);

  a = 0;
  b = 0;

  result1 = s21_sscanf("-12D687", "%X", &a);
  result_origin1 = sscanf("-12D687", "%X", &b);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, b);

  a = 10;
  b = 10;

  result1 = s21_sscanf("-12D687", "%x", &a);
  result_origin1 = sscanf("-12D687", "%x", &b);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, b);

  a = 10;
  b = 10;

  result1 = s21_sscanf("3039", "%x", &a);
  result_origin1 = sscanf("3039", "%x", &b);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, b);

  a = 10;
  b = 10;

  result1 = s21_sscanf("3039", "%X", &a);
  result_origin1 = sscanf("3039", "%X", &b);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, b);
  a = 0;
  b = 0;
  const char *for_str = "-929";

  result1 = s21_sscanf(for_str, "%X", &a);
  result_origin1 = sscanf(for_str, "%X", &b);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, b);

  const char *for_str3 = "-929";

  result1 = s21_sscanf(for_str3, "%x", &a);
  result_origin1 = sscanf(for_str3, "%x", &b);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, b);

  a = 0;
  b = 0;
  const char *for_str1 = "-929 1A85";

  result1 = s21_sscanf(for_str1, "%x %X", &a, &c);
  result_origin1 = sscanf(for_str1, "%x %X", &b, &d);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, b);
  ck_assert_int_eq(c, d);

  int x = 0;
  int y = 0;
  const char *format_str2 = "7FFFFFFF -80000000 -1";

  result1 = s21_sscanf(format_str2, "%X %X %X", &a, &c, &x);
  result_origin1 = sscanf(format_str2, "%X %X %X", &b, &d, &y);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, b);
  ck_assert_int_eq(c, d);
  ck_assert_int_eq(x, y);

  a = 0;
  b = 0;
  const char *format_str3 = "-929 1A85";

  result1 = s21_sscanf(format_str3, "%*x %X", &a);
  result_origin1 = sscanf(format_str3, "%*x %X", &b);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, b);

  a = 0;
  b = 0;
  result1 = s21_sscanf("1E240 12D687", "%x %*X", &a);
  result_origin1 = sscanf("1E240 12D687", "%x %*X", &b);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, b);

  const char *format_str4 = "7FFFFFFF -80000000 -1";

  result1 = s21_sscanf(format_str4, "%X %X %*X", &a, &c);
  result_origin1 = sscanf(format_str4, "%X %X %*X", &b, &d);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, b);
  ck_assert_int_eq(c, d);

  const char *format_str5 = "-1 7FFFFFFF -80000000";

  result1 = s21_sscanf(format_str5, "%x %x %*x", &a, &c);
  result_origin1 = sscanf(format_str5, "%x %x %*x", &b, &d);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, b);
  ck_assert_int_eq(c, d);
}
END_TEST
START_TEST(s21_sscanf_test_24_p_option) {
  int *a1 = 0, *a2 = 0, *b1 = 0, *b2 = 0, *c1 = 0, *c2 = 0, *d1 = 0, *d2 = 0;
  const char str[] = "0xFFFF 0xAAAA 0x7123 0xBBC1FF";
  const char fstr[] = "%p %p %p %p";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(a1, a2);
  ck_assert_ptr_eq(b1, b2);
  ck_assert_ptr_eq(c1, c2);
  ck_assert_ptr_eq(d1, d2);
}
END_TEST
START_TEST(s21_sscanf_test_24_p2_option) {
  int *a1 = 0, *a2 = 0, *b1 = 0, *b2 = 0, *c1 = 0, *c2 = 0, *d1 = 0, *d2 = 0;
  const char str[] = "0xFFFF 0xAAAA 0x7123 0xBBC1FF";
  const char fstr[] = "%p %p %p %p";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(a1, a2);
  ck_assert_ptr_eq(b1, b2);
  ck_assert_ptr_eq(c1, c2);
  ck_assert_ptr_eq(d1, d2);
}
END_TEST
START_TEST(s21_sscanf_test_24_p3_option) {
  int *a1 = 0, *a2 = 0, *b1 = 0, *b2 = 0, *c1 = 0, *c2 = 0, *d1 = 0, *d2 = 0;
  const char str[] = "0xFFFF 0xAAAA 0x7123 0xBBC1FF";
  const char fstr[] = "%p %p %p %p";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(a1, a2);
  ck_assert_ptr_eq(b1, b2);
  ck_assert_ptr_eq(c1, c2);
  ck_assert_ptr_eq(d1, d2);
}
END_TEST
END_TEST
START_TEST(s21_sscanf_test_24_p4_option) {
  int *a1 = 0, *a2 = 0, *b1 = 0, *b2 = 0, *c1 = 0, *c2 = 0, *d1 = 0, *d2 = 0;
  const char str[] = "0xFFFF 0xAAAA 0x7123 0xBBC1FF";
  const char fstr[] = "%p %p %p %p";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(a1, a2);
  ck_assert_ptr_eq(b1, b2);
  ck_assert_ptr_eq(c1, c2);
  ck_assert_ptr_eq(d1, d2);
}
END_TEST
START_TEST(s21_sscanf_test_23_together_option) {
  int a = 0, b = 0, c = 0, d = 0, g = 0, f = 0;
  unsigned short aa = 0, bb = 0, cc = 0, dd = 0;
  char z = 0, q = 0;
  char array1[BUFF_SIZE] = {0};
  char array_origin1[BUFF_SIZE] = {0};
  int result1 =
      s21_sscanf("1E240 12D687 65535 0 ! Mask 0x1E240",
                 "%x %X %hu %hu %c %s %i", &a, &b, &aa, &cc, &z, array1, &f);
  int result_origin1 =
      sscanf("1E240 12D687 65535 0 ! Mask 0x1E240", "%x %X %hu %hu %c %s %i",
             &c, &d, &bb, &dd, &q, array_origin1, &g);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, c);
  ck_assert_int_eq(b, d);
  ck_assert_int_eq(aa, bb);
  ck_assert_int_eq(cc, dd);
  ck_assert_int_eq(z, q);
  ck_assert_str_eq(array1, array_origin1);
  ck_assert_int_eq(f, g);

  //   a = 0, b = 0, c = 0, d = 0, g = 0, f = 0;
  //   aa = 0, bb = 0, cc = 0, dd = 0;
  //   z = 0, q = 0;
  //   char array2[BUFF_SIZE] = {0};
  //   char array_origin2[BUFF_SIZE] = {0};
  //   int result2 = s21_sscanf(
  //       "Mask 1E240 D687 65535 0 ! 0361100",
  //       "%s %x %*i %X %hu %hu %c %i", array2, &a, &b, &aa, &cc, &z, &f);
  //   int result_origin2 = sscanf(
  //       "Mask 1E240 D687 65535 0 ! 0361100",
  //       "%s %x %*i %X %hu %hu %c %i", array_origin2, &c, &d, &bb, &dd, &q,
  //       &g);
  //   ck_assert_int_eq(result2, result_origin2);
  //   ck_assert_int_eq(a, c);
  //   ck_assert_int_eq(b, d);
  //   ck_assert_int_eq(aa, bb);
  //   ck_assert_int_eq(cc, dd);
  //   ck_assert_int_eq(z, q);
  //   ck_assert_str_eq(array2, array_origin2);
  //   ck_assert_int_eq(f, g);
  //   a = 0, b = 0, c = 0, d = 0, g = 0, f = 0;
  //   aa = 0, bb = 0, cc = 0, dd = 0;
  //   z = 0, q = 0;
  //   char array3[BUFF_SIZE] = {0};
  //   char array_origin3[BUFF_SIZE] = {0};
  //   int result3 = s21_sscanf(
  //       "Mask and Trump\0 are friends 1E240 12D687 65535 0 ! 0361100",
  //       "%s %x %*i %X %hu %hu %c %i", array3, &a, &b, &aa, &cc, &z, &f);
  //   int result_origin3 = sscanf(
  //       "Mask and Trump\0 are friends 1E240 12D687 65535 0 ! 0361100",
  //       "%s %x %*i %X %hu %hu %c %i", array_origin3, &c, &d, &bb, &dd, &q,
  //       &g);
  //   ck_assert_int_eq(result3, result_origin3);
  //   ck_assert_int_eq(a, c);
  //   ck_assert_int_eq(b, d);
  //   ck_assert_int_eq(aa, bb);
  //   ck_assert_int_eq(cc, dd);
  //   ck_assert_int_eq(z, q);
  //   ck_assert_str_eq(array3, array_origin3);
  //   ck_assert_int_eq(f, g);
  //   a = 0, b = 0, c = 0, d = 0, g = 0, f = 0;
  //   aa = 0, bb = 0, cc = 0, dd = 0;
  //   z = 0, q = 0;
  //   char array4[BUFF_SIZE] = {0};
  //   char array_origin4[BUFF_SIZE] = {0};
  //   int result4 = s21_sscanf(
  //       "Mask and\0 Trump\0 are friends 1E240 12D687 65535\0 0 ! 0361100",
  //       "%s %x %*i %X %hu %hu %c %i", array4, &a, &b, &aa, &cc, &z, &f);
  //   int result_origin4 = sscanf(
  //       "Mask and\0 Trump\0 are friends 1E240 12D687 65535\0 0 ! 0361100",
  //       "%s %x %*i %X %hu %hu %c %i", array_origin4, &c, &d, &bb, &dd, &q,
  //       &g);
  //   ck_assert_int_eq(result4, result_origin4);
  //   ck_assert_int_eq(a, c);
  //   ck_assert_int_eq(b, d);
  //   ck_assert_int_eq(aa, bb);
  //   ck_assert_int_eq(cc, dd);
  //   ck_assert_int_eq(z, q);
  //   ck_assert_str_eq(array4, array_origin4);
  //   ck_assert_int_eq(f, g);

  //   a = 0, b = 0, c = 0, d = 0, g = 0, f = 0;
  //   aa = 0, bb = 0, cc = 0, dd = 0;
  //   z = 0, q = 0;
  //   char array5[BUFF_SIZE] = {0};
  //   char array_origin5[BUFF_SIZE] = {0};
  //   int result5 = s21_sscanf(
  //       "Mask and Trump are friends 1E240 12D687 65535 0 ! 0361100",
  //       "%s %*x %x %X %*x %hu %*u %hu %c %i", array5, &a, &b, &aa, &cc, &z,
  //       &f);
  //   int result_origin5 =
  //       sscanf("Mask and Trump are friends 1E240 12D687 65535 0 ! 0361100",
  //              "%s %*x %x %X %*x %hu %*u %hu %c %i", array_origin5, &c, &d,
  //              &bb, &dd, &q, &g);
  //   ck_assert_int_eq(result5, result_origin5);
  //   ck_assert_int_eq(a, c);
  //   ck_assert_int_eq(b, d);
  //   ck_assert_int_eq(aa, bb);
  //   ck_assert_int_eq(cc, dd);
  //   ck_assert_int_eq(z, q);
  //   ck_assert_str_eq(array5, array_origin5);
  //   ck_assert_int_eq(f, g);
}
END_TEST
START_TEST(s21_sscanf_test_26_hard_option) {
  int a1 = 0, a2 = 0, a3 = 0, a4 = 0;
  int32_t n1 = 0, n2 = 0;

  const char str[] = "1 2";
  const char fstr[] = "%d %d %n";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &a3, &n1);
  int16_t res2 = sscanf(str, fstr, &a2, &a4, &n2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(a3, a4);
  ck_assert_int_eq(n1, n2);
}
END_TEST
START_TEST(s21_sscanf_test_27_hard_option) {
  int32_t a1, a2;
  int32_t b1 = 0, b2 = 0;
  const char str[] = "32 32";
  const char fstr[] = "%d %d";
  int32_t res1 = s21_sscanf(str, fstr, &a1, &b1);
  int32_t res2 = sscanf(str, fstr, &a2, &b2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
}
END_TEST

START_TEST(s21_sscanf_test_23_n_option) {
  int a = 0;
  int b = 0;
  int c = 0;
  int d = 0;
  int n1 = 0;
  int n2 = 0;
  int result1 = s21_sscanf("10     20", "%d %n%d", &a, &n1, &b);
  int result2 = sscanf("10     20", "%d %n%d", &c, &n2, &d);
  ck_assert_int_eq(a, c);
  ck_assert_int_eq(b, d);
  ck_assert_int_eq(result1, result2);

  a = 0;
  b = 0;
  c = 0;
  d = 0;
  n1 = 0;
  n2 = 0;
  result1 = s21_sscanf("10     20", "%d%n%d", &a, &n1, &b);
  result2 = sscanf("10     20", "%d%n%d", &c, &n2, &d);
  ck_assert_int_eq(a, c);
  ck_assert_int_eq(b, d);
  ck_assert_int_eq(result1, result2);

  a = 0;
  b = 0;
  c = 0;
  d = 0;
  n1 = 0;
  n2 = 0;
  result1 = s21_sscanf("10     20", "%n%d%d", &a, &n1, &b);
  result2 = sscanf("10     20", "%n%d%d", &c, &n2, &d);
  ck_assert_int_eq(a, c);
  ck_assert_int_eq(b, d);
  ck_assert_int_eq(result1, result2);

  a = 0;
  b = 0;
  c = 0;
  d = 0;
  n1 = 0;
  n2 = 0;
  result1 = s21_sscanf("  10     20", "%n%d%d", &a, &n1, &b);
  result2 = sscanf("  10     20", "%n%d%d", &c, &n2, &d);
  ck_assert_int_eq(a, c);
  ck_assert_int_eq(b, d);
  ck_assert_int_eq(result1, result2);

  a = 0;
  b = 0;
  c = 0;
  d = 0;
  n1 = 0;
  n2 = 0;
  result1 = s21_sscanf("10     20  ", "%d%d%n", &a, &n1, &b);
  result2 = sscanf("10     20  ", "%d%d%n", &c, &n2, &d);
  ck_assert_int_eq(a, c);
  ck_assert_int_eq(b, d);
  ck_assert_int_eq(result1, result2);

  a = 0;
  b = 0;
  c = 0;
  d = 0;
  n1 = 0;
  n2 = 0;
  result1 = s21_sscanf("10     20", "%d%d %n", &a, &n1, &b);
  result2 = sscanf("10     20", "%d%d %n", &c, &n2, &d);
  ck_assert_int_eq(a, c);
  ck_assert_int_eq(b, d);
  ck_assert_int_eq(result1, result2);

  a = 0;
  b = 0;
  c = 0;
  d = 0;
  n1 = 0;
  n2 = 0;
  result1 = s21_sscanf("10     20  ", "%d%d", &a, &b);
  result2 = s21_sscanf("10     20  ", "%d%d", &c, &d);
  ck_assert_int_eq(a, c);
  ck_assert_int_eq(b, d);
  ck_assert_int_eq(result1, result2);
}

END_TEST
// START_TEST(s21_sscanf_test_28_hard_option) {
//   int32_t a1 = 0, a2 = 0;
//   int32_t b1 = 0, b2 = 0;
//   const char str[] = "12keppa12";
//   const char fstr[] = "I will break your function%d %d";
//   int32_t res1 = s21_sscanf(str, fstr, &a1, &b1);
//   int32_t res2 = sscanf(str, fstr, &a2, &b2);

//   ck_assert_int_eq(res1, res2);
//   ck_assert_int_eq(a1, a2);
//   ck_assert_int_eq(b1, b2);
// }
// END_TEST
// START_TEST(s21_sscanf_test_29_hard_option) {
//   int32_t a1 = 0, a2 = 0;
//   int32_t b1 = 0, b2 = 0;
//   const char str[] = "12keppa12";
//   const char fstr[] = "%d I will break your function%d";
//   int32_t res1 = s21_sscanf(str, fstr, &a1, &b1);
//   int32_t res2 = sscanf(str, fstr, &a2, &b2);

//   ck_assert_int_eq(res1, res2);
//   ck_assert_int_eq(a1, a2);
//   ck_assert_int_eq(b1, b2);
// }
// END_TEST
// START_TEST(s21_sscanf_test_30_hard_option) {
//   int32_t a1 = 0, a2 = 0;
//   int32_t b1 = 0, b2 = 0;
//   const char str[] = "+12keppa12";
//   const char fstr[] = "%d uti puti daniil%d";
//   int32_t res1 = s21_sscanf(str, fstr, &a1, &b1);
//   int32_t res2 = sscanf(str, fstr, &a2, &b2);

//   ck_assert_int_eq(res1, res2);
//   ck_assert_int_eq(a1, a2);
//   ck_assert_int_eq(b1, b2);
// }
// END_TEST
// START_TEST(s21_sscanf_test_23_error_option) {
//   float error1 = 0;
//   float error2 = 0;

//   int result1 = s21_sscanf("10     20", "%z", &error1);
//   int result2 = 0;
//   ck_assert_float_eq(error1, error2);
//   ck_assert_int_eq(result1, result2);

//   error1 = 0;
//   error2 = 0;

//   result1 = s21_sscanf("10     20", "%100f", &error1);
//   result2 = sscanf("10     20", "%100f", &error2);
//   ck_assert_float_eq(error1, error2);
//   ck_assert_int_eq(result1, result2);
// }

// END_TEST

// START_TEST(EOF1) {
//   char fstr[] = "%d";
//   char str[] = "        ";

//   int16_t res1 = s21_sscanf(str, fstr, 0);
//   int16_t res2 = sscanf(str, fstr, 100);
//   ck_assert_int_eq(res1, res2);
// }
// END_TEST

// START_TEST(EOF2) {
//   char fstr[] = "%d ";
//   char str[] = "               ";
//   int16_t a1 = 0, a2 = 0;

//   int16_t res1 = s21_sscanf(str, fstr, &a1);
//   int16_t res2 = sscanf(str, fstr, &a2);
//   ck_assert_int_eq(res1, res2);
// }
// END_TEST

// START_TEST(EOF3) {
//   char fstr[] = "%d ";
//   char str[] = "  ";
//   int16_t a1 = 0, a2 = 0;

//   int16_t res1 = s21_sscanf(str, fstr, &a1);
//   int16_t res2 = sscanf(str, fstr, &a2);
//   ck_assert_int_eq(res1, res2);
// }
// END_TEST

START_TEST(only_chars1) {
  char fstr[] = "%c%c %c %c";
  char str[] = "   a b c d";
  int16_t a1 = 0, a2 = 5, b1 = 0, b2 = 5, c1 = 0, c2 = 5, d1 = 0, d2 = 5;

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);

  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(only_chars2) {
  char fstr[] = "%c%c%c%c";
  char str[] = "abcd";
  int16_t a1 = 0, a2 = 5, b1 = 0, b2 = 5, c1 = 0, c2 = 5, d1 = 0, d2 = 5;

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);

  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(only_chars3) {
  char fstr[] = "%c %c %c      %c";
  char str[] = "1 a 3 c           ";
  int16_t a1 = 0, a2 = 5, b1 = 0, b2 = 5, c1 = 0, c2 = 5, d1 = 0, d2 = 5;

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(only_chars4) {
  char fstr[] = "%c %c %c %c";
  char str[] = " 000 0    ";
  int16_t a1 = 0, a2 = 5, b1 = 0, b2 = 5, c1 = 0, c2 = 5, d1 = 0, d2 = 5;

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);

  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(only_chars5) {
  char fstr[] = "%c %c %c %c";
  char str[] = "tttt";
  int16_t a1 = 0, a2 = 5, b1 = 0, b2 = 5, c1 = 0, c2 = 5, d1 = 0, d2 = 5;

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);

  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(special_symbols_as_chars1) {
  char fstr[] = "%c%c%c%c";
  char str[] = "\\\n\t\t\t";
  int16_t a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(special_symbols_as_chars2) {
  char fstr[] = "%c %c %c %c";
  char str[] = "z ' ' /";
  int16_t a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(special_symbols_as_chars3) {
  char fstr[] = "%c%*c%c%c";
  char str[] = "ABCD";
  int16_t a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0;

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1);

  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
}
END_TEST

START_TEST(chars_flags1) {
  char fstr[] = "%c %c %c %c";
  char str[] = "z *'@";
  int16_t a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(chars_flags2) {
  char fstr[] = "%1c %c %c %0c";
  char str[] = "z *'@";
  int16_t a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(chars_flags3) {
  char fstr[] = "%c %c %c %c";
  char str[] = "z *'@";
  int16_t a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(chars_flags4) {
  char fstr[] = "%c %c %c %c";
  char str[] = "z *'@";
  int16_t a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(chars_flags5) {
  char fstr[] = "%*c%*c%*c%c";
  char str[] = "abcde";
  int16_t a1 = 0, a2 = 0;

  int16_t res1 = s21_sscanf(str, fstr, &a1);
  int16_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(chars_aster1) {
  char fstr[] = "%*c%*c%*c%*c";
  char str[] = "   c ";
  int16_t a1 = 0, a2 = 0;

  int16_t res1 = s21_sscanf(str, fstr, &a1);
  int16_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(chars_aster2) {
  char fstr[] = "%*c%*c%*c%c";
  char str[] = "abcd ";
  int16_t a1 = 0, a2 = 0;

  int16_t res1 = s21_sscanf(str, fstr, &a1);
  int16_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(only_ints1) {
  long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char fstr[] = "%ld %ld %ld %ld";
  const char str[] = "555 666 777 888";

  int32_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int32_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(only_ints2) {
  int16_t a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "1337 21 5008 3000";
  const char fstr[] = "%hd %hd %hd %hd";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(only_ints3) {
  int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "1337 21 5008 300004";
  const char fstr[] = "%d %d %d %d";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(ints_nwidth1) {
  long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "1337 21 5008 300004";
  const char fstr[] = "%1ld %3ld %1ld %4ld";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(ints_nwidth2) {
  long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "1337";
  const char fstr[] = "%1ld %1ld %1ld %1ld";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

// START_TEST(ints_nwidth3) {
//   long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
//   const char str[] = "100000000000000005";
//   const char fstr[] = "%3ld%ld%1ld%5ld";

//   int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
//   int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

//   ck_assert_int_eq(res1, res2);
//   ck_assert_int_eq(a1, a2);
//   ck_assert_int_eq(b1, b2);
//   ck_assert_int_eq(c1, c2);
//   ck_assert_int_eq(d1, d2);
// }
// END_TEST

// START_TEST(ints_nwidth4) {
//   long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
//   const char str[] = "1337";
//   const char fstr[] = "%15ld %1ld %1ld %1ld";

//   int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
//   int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

//   ck_assert_int_eq(res1, res2);
//   ck_assert_int_eq(a1, a2);
//   ck_assert_int_eq(b1, b2);
//   ck_assert_int_eq(c1, c2);
//   ck_assert_int_eq(d1, d2);
// }
// END_TEST

START_TEST(ints_astwidth1) {
  long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0;
  const char str[] = "1337123123 1 123412341234 1 999999 0";
  const char fstr[] = "%*d %ld %*d %ld %*d %ld";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
}
END_TEST

// START_TEST(ints_astwidth2) {
//   long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
//   const char str[] = "1337";
//   const char fstr[] = "%15ld %1ld %1ld %1ld";

//   int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
//   int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

//   ck_assert_int_eq(res1, res2);
//   ck_assert_int_eq(a1, a2);
//   ck_assert_int_eq(b1, b2);
//   ck_assert_int_eq(c1, c2);
//   ck_assert_int_eq(d1, d2);
// }
// END_TEST

// START_TEST(ints_astwidth3) {
//   long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
//   const char str[] = "1337";
//   const char fstr[] = "%15ld %1ld %1ld %1ld";

//   int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
//   int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

//   ck_assert_int_eq(res1, res2);
//   ck_assert_int_eq(a1, a2);
//   ck_assert_int_eq(b1, b2);
//   ck_assert_int_eq(c1, c2);
//   ck_assert_int_eq(d1, d2);
// }
// END_TEST

// START_TEST(ints_astwidth4) {
//   long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
//   const char str[] = "1337";
//   const char fstr[] = "%15ld %1ld %1ld %1ld";

//   int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
//   int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

//   ck_assert_int_eq(res1, res2);
//   ck_assert_int_eq(a1, a2);
//   ck_assert_int_eq(b1, b2);
//   ck_assert_int_eq(c1, c2);
//   ck_assert_int_eq(d1, d2);
// }
// END_TEST

START_TEST(signed_ints1) {
  long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "11337 +3 -5 -4";
  const char fstr[] = "%ld %ld %ld %ld";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(signed_ints2) {
  long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "-1337 +1 -1 -1";
  const char fstr[] = "%3ld %1ld %1ld %5ld";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(signed_ints3) {
  long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "-0 +0 +0 -0";
  const char fstr[] = "%2ld %2ld %2ld %2ld";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(signed_ints4) {
  long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "1 01 10 0";
  const char fstr[] = "%ld %ld %ld %ld";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(spec_i_int1) {
  long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "300 500 -600 +700";
  const char fstr[] = "%li %li %li %li";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(spec_i_int2) {
  long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "300500-600+700 111";
  const char fstr[] = "%li %ld %ld %li";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(spec_i_int3) {
  long a1 = 0, a2 = 0, c1 = 0, c2 = 0;
  char b1 = 0, b2 = 0, d1 = 0, d2 = 0;
  const char str[] = "300500-600+700+400";
  const char fstr[] = "%li%c%li%c";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

// START_TEST(spec_i_int4) {
//   long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
//   const char str[] = "  55555 f f f5555555 ddd   4    3    1 ";
//   const char fstr[] = "%li %ld %ld %li";

//   int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
//   int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

//   ck_assert_int_eq(res1, res2);
//   ck_assert_int_eq(a1, a2);
//   ck_assert_int_eq(b1, b2);
//   ck_assert_int_eq(c1, c2);
//   ck_assert_int_eq(d1, d2);
// }
// END_TEST

// START_TEST(spec_i_hex1) {
//   long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
//   const char str[] = "0xFFF 0xA123123 0x123123 0x0";
//   const char fstr[] = "%li %ld %ld %li";

//   int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
//   int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

//   ck_assert_int_eq(res1, res2);
//   ck_assert_int_eq(a1, a2);
//   ck_assert_int_eq(b1, b2);
//   ck_assert_int_eq(c1, c2);
//   ck_assert_int_eq(d1, d2);
// }
// END_TEST

// START_TEST(spec_i_hex2) {
//   long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
//   const char str[] = " 0xFFFF 0xf 0xf 0xf5555555 ddd   4    3    1 ";
//   const char fstr[] = "%li %ld %ld %li";

//   int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
//   int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

//   ck_assert_int_eq(res1, res2);
//   ck_assert_int_eq(a1, a2);
//   ck_assert_int_eq(b1, b2);
//   ck_assert_int_eq(c1, c2);
//   ck_assert_int_eq(d1, d2);
// }
// END_TEST

// START_TEST(spec_i_oct1) {
//   long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
//   const char str[] = "  055555 0f 0f 0f5555555 0ddd   4    3    1 ";
//   const char fstr[] = "%li %ld %ld %li";

//   int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
//   int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

//   ck_assert_int_eq(res1, res2);
//   ck_assert_int_eq(a1, a2);
//   ck_assert_int_eq(b1, b2);
//   ck_assert_int_eq(c1, c2);
//   ck_assert_int_eq(d1, d2);
// }
// END_TEST

// START_TEST(spec_i_oct2) {
//   long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
//   const char str[] = "  055555 0f 0f 0f5555555 0ddd   4    3    1 ";
//   const char fstr[] = "%li %ld %ld %li";

//   int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
//   int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

//   ck_assert_int_eq(res1, res2);
//   ck_assert_int_eq(a1, a2);
//   ck_assert_int_eq(b1, b2);
//   ck_assert_int_eq(c1, c2);
//   ck_assert_int_eq(d1, d2);
// }
// END_TEST

/* [%s] */

START_TEST(strings1) {
  char s1[BUFF_SIZE] = {'\0'};
  char s2[BUFF_SIZE] = {'\0'};
  char s3[BUFF_SIZE] = {'\0'};
  char s4[BUFF_SIZE] = {'\0'};

  char s5[BUFF_SIZE] = {'\0'};
  char s6[BUFF_SIZE] = {'\0'};
  char s7[BUFF_SIZE] = {'\0'};
  char s8[BUFF_SIZE] = {'\0'};

  const char str[] = "Aboba Floppa Keppa Shleppa Anuroba";
  const char fstr[] = "%s %s %s %s";

  int16_t res1 = s21_sscanf(str, fstr, s1, s2, s3, s4);
  int16_t res2 = sscanf(str, fstr, s5, s6, s7, s8);

  ck_assert_int_eq(res1, res2);

  ck_assert_str_eq(s1, s5);
  ck_assert_str_eq(s2, s6);
  ck_assert_str_eq(s3, s7);
  ck_assert_str_eq(s4, s8);
}
END_TEST

START_TEST(strings_mixed3) {
  char s1[BUFF_SIZE] = {'\0'};
  char s2[BUFF_SIZE] = {'\0'};
  char s3[BUFF_SIZE] = {'\0'};
  char s4[BUFF_SIZE] = {'\0'};

  char s5[BUFF_SIZE] = {'\0'};
  char s6[BUFF_SIZE] = {'\0'};
  char s7[BUFF_SIZE] = {'\0'};
  char s8[BUFF_SIZE] = {'\0'};

  long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

  const char str[] = "Aboba 123 Floppa -3 Keppa 4444Shleppa 333Anuroba 3";
  const char fstr[] = "%s%ld%s%d%s%d%s";

  int16_t res1 = s21_sscanf(str, fstr, s1, &a1, s2, &b1, s3, &c1, s4, &d1);
  int16_t res2 = s21_sscanf(str, fstr, s5, &a2, s6, &b2, s7, &c2, s8, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);

  ck_assert_str_eq(s1, s5);
  ck_assert_str_eq(s2, s6);
  ck_assert_str_eq(s3, s7);
  ck_assert_str_eq(s4, s8);
}
END_TEST

START_TEST(strings2) {
  char s1[BUFF_SIZE] = {'\0'};
  char s2[BUFF_SIZE] = {'\0'};
  char s3[BUFF_SIZE] = {'\0'};
  char s4[BUFF_SIZE] = {'\0'};

  char s5[BUFF_SIZE] = {'\0'};
  char s6[BUFF_SIZE] = {'\0'};
  char s7[BUFF_SIZE] = {'\0'};
  char s8[BUFF_SIZE] = {'\0'};

  const char str[] = "aboba\tshlepa\tasdfasdf\tasdfasdf";
  const char fstr[] = "%s%s%s%s";

  int16_t res1 = s21_sscanf(str, fstr, s1, s2, s3, s4);
  int16_t res2 = sscanf(str, fstr, s5, s6, s7, s8);

  ck_assert_int_eq(res1, res2);

  ck_assert_str_eq(s1, s5);
  ck_assert_str_eq(s2, s6);
  ck_assert_str_eq(s3, s7);
  ck_assert_str_eq(s4, s8);
}
END_TEST

START_TEST(strings3) {
  char s1[BUFF_SIZE] = {'\0'};
  char s2[BUFF_SIZE] = {'\0'};
  char s3[BUFF_SIZE] = {'\0'};
  char s4[BUFF_SIZE] = {'\0'};

  char s5[BUFF_SIZE] = {'\0'};
  char s6[BUFF_SIZE] = {'\0'};
  char s7[BUFF_SIZE] = {'\0'};
  char s8[BUFF_SIZE] = {'\0'};

  const char str[] = "aboba\tkepaboba floppa shleppa koooppa ap p p p p";
  const char fstr[] = "%*s%*s%*s%*s";

  int16_t res1 = s21_sscanf(str, fstr);
  int16_t res2 = sscanf(str, fstr);

  ck_assert_int_eq(res1, res2);

  ck_assert_str_eq(s1, s5);
  ck_assert_str_eq(s2, s6);
  ck_assert_str_eq(s3, s7);
  ck_assert_str_eq(s4, s8);
}
END_TEST

START_TEST(strings4) {
  char s1[BUFF_SIZE] = {'\0'};
  char s2[BUFF_SIZE] = {'\0'};
  char s3[BUFF_SIZE] = {'\0'};
  char s4[BUFF_SIZE] = {'\0'};

  char s5[BUFF_SIZE] = {'\0'};
  char s6[BUFF_SIZE] = {'\0'};
  char s7[BUFF_SIZE] = {'\0'};
  char s8[BUFF_SIZE] = {'\0'};

  const char str[] = "aboba\tshlepa\tasdfasdf\tasdfasdf";
  const char fstr[] = "%1s%1s%1s%1s";

  int16_t res1 = s21_sscanf(str, fstr, s1, s2, s3, s4);
  int16_t res2 = sscanf(str, fstr, s5, s6, s7, s8);

  ck_assert_int_eq(res1, res2);

  ck_assert_str_eq(s1, s5);
  ck_assert_str_eq(s2, s6);
  ck_assert_str_eq(s3, s7);
  ck_assert_str_eq(s4, s8);
}
END_TEST

START_TEST(strings5) {
  char s1[BUFF_SIZE] = {'\0'};
  char s2[BUFF_SIZE] = {'\0'};
  char s3[BUFF_SIZE] = {'\0'};
  char s4[BUFF_SIZE] = {'\0'};

  char s5[BUFF_SIZE] = {'\0'};
  char s6[BUFF_SIZE] = {'\0'};
  char s7[BUFF_SIZE] = {'\0'};
  char s8[BUFF_SIZE] = {'\0'};

  const char str[] = "aboba\tshlepa\tasdfasdf\tasdfasdf";
  const char fstr[] = "%3s%3s%3s%3s";

  int16_t res1 = s21_sscanf(str, fstr, s1, s2, s3, s4);
  int16_t res2 = sscanf(str, fstr, s5, s6, s7, s8);

  ck_assert_int_eq(res1, res2);

  ck_assert_str_eq(s1, s5);
  ck_assert_str_eq(s2, s6);
  ck_assert_str_eq(s3, s7);
  ck_assert_str_eq(s4, s8);
}
END_TEST

START_TEST(strings6) {
  char s1[BUFF_SIZE] = {'\0'};
  char s2[BUFF_SIZE] = {'\0'};
  char s3[BUFF_SIZE] = {'\0'};
  char s4[BUFF_SIZE] = {'\0'};

  char s5[BUFF_SIZE] = {'\0'};
  char s6[BUFF_SIZE] = {'\0'};
  char s7[BUFF_SIZE] = {'\0'};
  char s8[BUFF_SIZE] = {'\0'};

  const char str[] = "aboba\tshlepa\tasdfasdf\tasdfasdf";
  const char fstr[] = "%150s%1s%1s\t%3s";

  int16_t res1 = s21_sscanf(str, fstr, s1, s2, s3, s4);
  int16_t res2 = sscanf(str, fstr, s5, s6, s7, s8);

  ck_assert_int_eq(res1, res2);

  ck_assert_str_eq(s1, s5);
  ck_assert_str_eq(s2, s6);
  ck_assert_str_eq(s3, s7);
  ck_assert_str_eq(s4, s8);
}
END_TEST

// strings_mixed1

// START_TEST(strings_mixed1) {
//   unsigned long int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0;
//   long d1 = 0, d2 = 0;
//   long double e1 = 0, e2 = 0;

//   const char str[] =
//       "4444444"
//       "eeeeeee\teeeeeee";
//   const char fstr[] = "%5s %1s %*s %*s %lu %s %lu %lu %ld %Lf %33s";

//   char s1[BUFF_SIZE] = {'\0'};
//   char s2[BUFF_SIZE] = {'\0'};
//   char s3[BUFF_SIZE] = {'\0'};
//   char s4[BUFF_SIZE] = {'\0'};
//   char s5[BUFF_SIZE] = {'\0'};
//   char s6[BUFF_SIZE] = {'\0'};
//   char s7[BUFF_SIZE] = {'\0'};
//   char s8[BUFF_SIZE] = {'\0'};
//   char s9[BUFF_SIZE] = {'\0'};
//   char s10[BUFF_SIZE] = {'\0'};

//   int16_t res1 = s21_sscanf(str, fstr, s7, s9, &a1, s5, &b1, &c1, &d1, &e1,
//   s1); int16_t res2 = sscanf(str, fstr, s8, s10, &a2, s6, &b2, &c2, &d2, &e2,
//   s2);

//   ck_assert_int_eq(res1, res2);
//   ck_assert_str_eq(s1, s2);
//   ck_assert_str_eq(s3, s4);
//   ck_assert_str_eq(s5, s6);
//   ck_assert_int_eq(a1, a2);
//   ck_assert_int_eq(b1, b2);
//   ck_assert_int_eq(c1, c2);
//   ck_assert_int_eq(d1, d2);
// }
// END_TEST

// START_TEST(strings_mixed2) {
//   int d1 = 0, d2 = 0, b1 = 0, b2 = 0, a1 = 0, a2 = 0;
//   long v1, v2;

//   const char str[] = "1 1 1 1 1 -1";
//   const char fstr[] = "%1s %5d %1s %1s %d %ld %d";

//   char s1[BUFF_SIZE] = {'\0'};
//   char s2[BUFF_SIZE] = {'\0'};
//   char s3[BUFF_SIZE] = {'\0'};
//   char s4[BUFF_SIZE] = {'\0'};
//   char s5[BUFF_SIZE] = {'\0'};
//   char s6[BUFF_SIZE] = {'\0'};

//   int16_t res1 = s21_sscanf(str, fstr, s1, &a1, s2, s3, &b1, &v1, &d1);
//   int16_t res2 = sscanf(str, fstr, s4, &a2, s5, s6, &b2, &v2, &d2);

//   ck_assert_int_eq(res1, res2);
//   ck_assert_str_eq(s1, s2);
//   ck_assert_str_eq(s3, s4);
//   ck_assert_str_eq(s5, s6);
//   ck_assert_int_eq(a1, a2);
//   ck_assert_int_eq(b1, b2);
//   ck_assert_int_eq(d1, d2);
// }
// END_TEST

/* [%n] */

START_TEST(n1) {
  long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  int32_t n1 = 0, n2 = 5;

  const char str[BUFF_SIZE] = "50 160 70 80";
  const char fstr[BUFF_SIZE] = "%li %li%n %li %li";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &n1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &n2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(n2) {
  int n1 = 1, n2 = 5;

  char s1[BUFF_SIZE] = {'\0'};
  char s2[BUFF_SIZE] = {'\0'};
  char s3[BUFF_SIZE] = {'\0'};
  char s5[BUFF_SIZE] = {'\0'};
  char s6[BUFF_SIZE] = {'\0'};
  char s7[BUFF_SIZE] = {'\0'};

  const char str[] = "cbobErobM fl? asdfasdflkasdf asdfasdf asdfasdf 88888";
  const char fstr[] = "%s %s%n %s";

  int32_t res1 = s21_sscanf(str, fstr, s1, s2, &n1, s3);
  int32_t res2 = sscanf(str, fstr, s5, s6, &n2, s7);

  ck_assert_int_eq(res1, res2);

  ck_assert_int_eq(n1, n2);
  ck_assert_str_eq(s1, s5);
  ck_assert_str_eq(s2, s6);
  ck_assert_str_eq(s3, s7);
}
END_TEST

START_TEST(n3) {
  int n1 = 0, n2 = 5;

  const char str[BUFF_SIZE] = "50 60 70 80";
  const char fstr[BUFF_SIZE] = "%n";

  int16_t res1 = s21_sscanf(str, fstr, &n1);
  int16_t res2 = sscanf(str, fstr, &n2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(n4) {
  long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  int32_t n1 = 0, n2 = 5;

  const char str[] = "50 60 70 80";
  const char fstr[] = "%li %li%n %li %li";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &n1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &n2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(n5) {
  long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  int n1 = 0, n2 = 5;

  const char str[] = "50 60 70 80";
  const char fstr[] = "%li %li%n %li %li";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &n1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &n2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

/* [%f] / [%g] / %[%G] */

START_TEST(floats1) {
  long double a1 = 1, a2 = 0, b1 = 1, b2 = 0, c1 = 1, c2 = 0, d1 = 1, d2 = 0;

  const char str[] = "53.1 -4.1135 41.3333 +2.0001";
  const char fstr[] = "%Lf %Lf %Lf %Lf";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_double_eq(a1, a2);
  ck_assert_double_eq(b1, b2);
  ck_assert_double_eq(c1, c2);
  ck_assert_double_eq(d1, d2);
}
END_TEST

START_TEST(floats2) {
  float a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

  const char str[] = "0.00001 -4123123 4.";
  const char fstr[] = "%f %f %f";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(a1, a2);
  ck_assert_float_eq(b1, b2);
  ck_assert_float_eq(c1, c2);
  ck_assert_float_eq(d1, d2);
}
END_TEST

START_TEST(floats3) {
  float a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

  const char str[] = "4 3 2 1";
  const char fstr[] = "%f %f %f %f";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_double_eq(a1, a2);
  ck_assert_double_eq(b1, b2);
  ck_assert_double_eq(c1, c2);
  ck_assert_double_eq(d1, d2);
}
END_TEST

START_TEST(floats4) {
  long double a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

  const char str[] = "513.41 -4.14135 414.3333 +112.0001";
  const char fstr[] = "%Lf %Lf %Lf %Lf";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_double_eq(a1, a2);
  ck_assert_double_eq(b1, b2);
  ck_assert_double_eq(c1, c2);
  ck_assert_double_eq(d1, d2);
}
END_TEST

START_TEST(floats5) {
  float a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0;

  const char str[] = "53.1 -4.1135 411231.333 +2.0001";
  const char fstr[] = "%*f %f %f %f";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2);

  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(a1, a2);
  ck_assert_float_eq(b1, b2);
  ck_assert_float_eq(c1, c2);
}
END_TEST

START_TEST(floats_sci1) {
  float a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

  const char str[] = "1.4441 1.31e+4 -3.31e-4 0.444e-5";
  const char fstr[] = "%G %G %G %G";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_double_eq(a1, a2);
  ck_assert_double_eq(b1, b2);
  ck_assert_double_eq(c1, c2);
  ck_assert_double_eq(d1, d2);
}
END_TEST

// START_TEST(floats_sci2) {
//   float a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

//   const char str[] = "inf 1.31e+4 NaN 0.444e-5";
//   const char fstr[] = "%G %G %G %G";

//   int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
//   int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

//   ck_assert_int_eq(res1, res2);
//   ck_assert_ldouble_eq(a1, a2);
//   // Unfortunately, assertions for inf do not work correctly in libcheck
//   // ck_assert_ldouble_infinite(a1);
//   // ck_assert_ldouble_infinite(a2);
//   ck_assert_double_eq(b1, b2);
//   ck_assert_float_nan(c1);
//   ck_assert_float_nan(c2);
//   ck_assert_double_eq(d1, d2);
// }
// END_TEST

// START_TEST(floats_sci3) {
//   float a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

//   const char str[] = "inF InF inF INF";
//   const char fstr[] = "%G %G %G %G";

//   int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
//   int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

//   ck_assert_int_eq(res1, res2);
//   ck_assert_ldouble_eq(a1, a2);
//   ck_assert_double_eq(b1, b2);
//   ck_assert_double_eq(c1, c2);
//   ck_assert_double_eq(d1, d2);
// }
// END_TEST

// START_TEST(floats_sci4) {
//   float a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

//   const char str[] = "Nan NAN 0.0000 0";
//   const char fstr[] = "%G %G %G %G";

//   int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
//   int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

//   ck_assert_int_eq(res1, res2);
//   ck_assert_float_nan(a1);
//   ck_assert_float_nan(a2);
//   ck_assert_float_nan(b1);
//   ck_assert_float_nan(b2);
//   ck_assert_ldouble_eq(c1, c2);
//   ck_assert_ldouble_eq(d1, d2);
// }
// END_TEST

// START_TEST(floats_sci5) {
//   float a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

//   const char str[] =
//       "nAN           INF                   -0.1111         1e-10";
//   const char fstr[] = "%G %G %G %G";

//   int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
//   int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

//   ck_assert_int_eq(res1, res2);
//   ck_assert_float_nan(a1);
//   ck_assert_float_nan(a2);
//   ck_assert_ldouble_eq(b1, b2);
//   ck_assert_ldouble_eq(c1, c2);
//   ck_assert_ldouble_eq(d1, d2);
// }
// END_TEST

/* [%u] */

START_TEST(uint1) {
  unsigned short a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "-1337 +21 -5008 3000";
  const char fstr[] = "%hu %hu %hu %hu";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_uint_eq(res1, res2);
  ck_assert_uint_eq(a1, a2);
  ck_assert_uint_eq(b1, b2);
  ck_assert_uint_eq(c1, c2);
  ck_assert_uint_eq(d1, d2);
}
END_TEST

START_TEST(uint2) {
  unsigned long int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0,
                    d2 = 0;
  const char str[] = "-1337 233333331 5008 3000";
  const char fstr[] = "%lu %lu %lu %4lu";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

// START_TEST(uint3) {
//   unsigned long int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0;
//   long d1 = 0, d2 = 0;
//   long double v1, v2;

//   const char str[] =
//       "\t\t\t\t\t\n 3      adsfdfa%$$$$`adfasdfasdfaszcvzcxvcv -1337 "
//       "anurobich+ 21 -5008 -33000 0.3333";
//   const char fstr[] = "%*s %*s %lu %s %lu %lu %ld %Lf";

//   char s1[BUFF_SIZE] = {'\0'};
//   char s2[BUFF_SIZE] = {'\0'};

//   int16_t res1 = s21_sscanf(str, fstr, &a1, s1, &b1, &c1, &d1, &v1);
//   int16_t res2 = sscanf(str, fstr, &a2, s2, &b2, &c2, &d2, &v2);

//   ck_assert_uint_eq(res1, res2);
//   ck_assert_str_eq(s1, s2);
//   ck_assert_uint_eq(a1, a2);
//   ck_assert_uint_eq(b1, b2);
//   ck_assert_uint_eq(c1, c2);
//   ck_assert_uint_eq(d1, d2);
//   ck_assert_ldouble_eq_tol(v1, v2, 0.0001);
// }
// END_TEST

START_TEST(uint4) {
  unsigned short a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "-1337 +21 -5008 3000";
  const char fstr[] = "%hu %hu %hu %hu";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(uint5) {
  unsigned short a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "-1337 +21 -5008 3000";
  const char fstr[] = "%hu %hu %hu %hu";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(uint6) {
  unsigned short a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "-1337 +21 -5008 3000";
  const char fstr[] = "%hu %hu %hu %hu";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(upeer_hex_base_version) {
  uint32_t a1, a2;
  const char str[] = "F";
  const char fstr[] = "%X";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(upeer_hex_overflow) {
  uint32_t a1, a2;
  const char str[] = "0xFFFFFFFF";
  const char fstr[] = "%X";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(upeer_hex_0x) {
  uint32_t a1, a2;
  const char str[] = "0x";
  const char fstr[] = "%X";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(upeer_hex_0X) {
  uint32_t a1, a2;
  const char str[] = "0X";
  const char fstr[] = "%X";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(upeer_hex_empty) {
  uint32_t a1, a2;
  const char str[] = "";
  const char fstr[] = "%X";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
}
END_TEST

// START_TEST(upeer_hex_fail) {
//   uint32_t a1, a2;
//   const char str[] = "qF";
//   const char fstr[] = "%X";
//   uint32_t res1 = s21_sscanf(str, fstr, &a1);
//   uint32_t res2 = sscanf(str, fstr, &a2);

//   ck_assert_int_eq(res1, res2);
// }
// END_TEST

START_TEST(upeer_hex_spaces_tabs_sns) {
  uint32_t a1, a2;
  const char str[] = "          \n             \n     F";
  const char fstr[] = "%X";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(upeer_hex_short) {
  uint16_t a1, a2;
  const char str[] = "F";
  const char fstr[] = "%hX";
  uint16_t res1 = s21_sscanf(str, fstr, &a1);
  uint16_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(upeer_hex_long) {
  unsigned long int a1, a2;
  const char str[] = "F";
  const char fstr[] = "%lX";
  uint16_t res1 = s21_sscanf(str, fstr, &a1);
  uint16_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

// START_TEST(upeer_hex_2x) {
//   uint32_t a1, a2;
//   const char str[] = "0xFF0x0xFFF 0xFFxFF";
//   const char fstr[] = "%X";
//   uint32_t res1 = s21_sscanf(str, fstr, &a1);
//   uint32_t res2 = sscanf(str, fstr, &a2);

//   ck_assert_int_eq(res1, res2);
//   ck_assert_int_eq(a1, a2);
// }
// END_TEST

START_TEST(upeer_hex_star) {
  const char str[] = "0xFF0x0xFFF 0xFFxFF";
  const char fstr[] = "%*X";
  uint32_t res1 = s21_sscanf(str, fstr);
  uint32_t res2 = sscanf(str, fstr);

  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(upper_hex_len) {
  uint32_t a1, a2;
  const char str[] = "123531FFF";
  const char fstr[] = "%2X";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(lower_hex_len) {
  uint32_t a1, a2;
  const char str[] = "123531FFF";
  const char fstr[] = "%2x";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(octal_base_version) {
  uint32_t a1, a2;
  const char str[] = "777";
  const char fstr[] = "%o";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(octal_overflow) {
  uint32_t a1, a2;
  const char str[] = "0x7777777777777777777777";
  const char fstr[] = "%o";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(octal_0x) {
  uint32_t a1, a2;
  const char str[] = "0x";
  const char fstr[] = "%o";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(octal_0X) {
  uint32_t a1, a2;
  const char str[] = "0X";
  const char fstr[] = "%o";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(octal_empty) {
  uint32_t a1, a2;
  const char str[] = "";
  const char fstr[] = "%o";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(octal_spaces_tabs_sns) {
  uint32_t a1, a2;
  const char str[] = "          \n             \n     5";
  const char fstr[] = "%o";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(octal_short) {
  uint16_t a1, a2;
  const char str[] = "12";
  const char fstr[] = "%ho";
  uint16_t res1 = s21_sscanf(str, fstr, &a1);
  uint16_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(octal_long) {
  unsigned long int a1, a2;
  const char str[] = "57234";
  const char fstr[] = "%lo";
  uint16_t res1 = s21_sscanf(str, fstr, &a1);
  uint16_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(octal_2x) {
  uint32_t a1, a2;
  const char str[] = "0x12320x213x123213";
  const char fstr[] = "%o";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(octal_star) {
  const char str[] = "521561612";
  const char fstr[] = "%*o";
  uint32_t res1 = s21_sscanf(str, fstr);
  uint32_t res2 = sscanf(str, fstr);

  ck_assert_int_eq(res1, res2);
}
END_TEST

// START_TEST(octal_lower) {
//   uint32_t a1, a2;
//   const char str[] = "1234567";
//   const char fstr[] = "%o";
//   uint32_t res1 = s21_sscanf(str, fstr, &a1);
//   uint32_t res2 = sscanf(str, fstr, &a2);

//   ck_assert_int_eq(res1, res2);
//   ck_assert_int_eq(a1, a2);
// }
// END_TEST

START_TEST(octal_sign) {
  uint32_t a1, a2;
  const char str[] = "-66";
  const char fstr[] = "%o";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(octal_len) {
  uint32_t a1, a2;
  const char str[] = "123531";
  const char fstr[] = "%2o";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(pointer1) {
  int *a1 = 0, *a2 = 0, *b1 = 0, *b2 = 0, *c1 = 0, *c2 = 0, *d1 = 0, *d2 = 0;
  const char str[] = "0xFFFF 0xAAAA 0x7123 0xBBC1FF";
  const char fstr[] = "%p %p %p %p";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(a1, a2);
  ck_assert_ptr_eq(b1, b2);
  ck_assert_ptr_eq(c1, c2);
  ck_assert_ptr_eq(d1, d2);
}
END_TEST

START_TEST(pointer2) {
  int *a1 = 0, *a2 = 0, *b1 = 0, *b2 = 0, *c1 = 0, *c2 = 0, *d1 = 0, *d2 = 0;
  const char str[] = "0xFFFF 0xAAAA 0x7123 0xBBC1FF";
  const char fstr[] = "%p %p %p %p";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(a1, a2);
  ck_assert_ptr_eq(b1, b2);
  ck_assert_ptr_eq(c1, c2);
  ck_assert_ptr_eq(d1, d2);
}
END_TEST

START_TEST(pointer3) {
  int *a1 = 0, *a2 = 0, *b1 = 0, *b2 = 0, *c1 = 0, *c2 = 0, *d1 = 0, *d2 = 0;
  const char str[] = "0xFFFF 0xAAAA 0x7123 0xBBC1FF";
  const char fstr[] = "%p %p %p %p";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(a1, a2);
  ck_assert_ptr_eq(b1, b2);
  ck_assert_ptr_eq(c1, c2);
  ck_assert_ptr_eq(d1, d2);
}
END_TEST

START_TEST(pointer4) {
  int *a1 = 0, *a2 = 0, *b1 = 0, *b2 = 0, *c1 = 0, *c2 = 0, *d1 = 0, *d2 = 0;
  const char str[] = "0xFFFF 0xAAAA 0x7123 0xBBC1FF";
  const char fstr[] = "%p %p %p %p";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(a1, a2);
  ck_assert_ptr_eq(b1, b2);
  ck_assert_ptr_eq(c1, c2);
  ck_assert_ptr_eq(d1, d2);
}
END_TEST

Suite *suite_sscanf(void) {
  Suite *s1 = suite_create("s21_string_sscanf");
  TCase *test_case_1 = tcase_create("s21_sscanf");
  // suite_add_tcase(s1, test_case_1);
  /*--------------------------SSCANF----------------------*/

  tcase_add_test(test_case_1, s21_sscanf_test_19_c_option);
  tcase_add_test(test_case_1, s21_sscanf_test_20_s_option);
  tcase_add_test(test_case_1, s21_sscanf_test_21_i_option);
  tcase_add_test(test_case_1, s21_sscanf_test_21_e_option);
  tcase_add_test(test_case_1, s21_sscanf_test_21_E_option);
  tcase_add_test(test_case_1, s21_sscanf_test_21_percent_option);
  tcase_add_test(test_case_1, s21_sscanf_test_21_star_option);
  tcase_add_test(test_case_1, s21_sscanf_test_21_f_option);
  tcase_add_test(test_case_1, s21_sscanf_test_21_g_option);
  tcase_add_test(test_case_1, s21_sscanf_test_21_G_option);
  tcase_add_test(test_case_1, s21_sscanf_test_23_n_option);
  //   tcase_add_test(test_case_1, s21_sscanf_test_23_error_option);

  tcase_add_test(test_case_1, s21_sscanf_test_16_o_option);
  tcase_add_test(test_case_1, s21_sscanf_test_17_o_option);
  tcase_add_test(test_case_1, s21_sscanf_test_18_o_option);
  tcase_add_test(test_case_1, s21_sscanf_test_17_d_option);
  tcase_add_test(test_case_1, s21_sscanf_test_18_u_option);
  tcase_add_test(test_case_1, s21_sscanf_test_19_u_option);
  tcase_add_test(test_case_1, s21_sscanf_test_16_xX_option);
  tcase_add_test(test_case_1, s21_sscanf_test_24_p_option);
  tcase_add_test(test_case_1, s21_sscanf_test_24_p2_option);
  tcase_add_test(test_case_1, s21_sscanf_test_24_p3_option);
  tcase_add_test(test_case_1, s21_sscanf_test_24_p4_option);

  tcase_add_test(test_case_1, s21_sscanf_test_23_together_option);
  tcase_add_test(test_case_1, s21_sscanf_test_26_hard_option);
  tcase_add_test(test_case_1, s21_sscanf_test_27_hard_option);
  // tcase_add_test(test_case_1, s21_sscanf_test_28_hard_option);
  // tcase_add_test(test_case_1, s21_sscanf_test_29_hard_option);
  // tcase_add_test(test_case_1, s21_sscanf_test_30_hard_option);

  //   tcase_add_test(test_case_1, EOF1);
  //   tcase_add_test(test_case_1, EOF2);
  //   tcase_add_test(test_case_1, EOF3);
  //

  // [%c]
  // Flags:
  // [Width] - N: 0, 1 - Do nothing; N > 1 - Undefined beh.
  //          * - skips chars
  // [Precision] - Any precision flag immediately stops sscanf (error)
  // [Length] - Does nothing

  tcase_add_test(test_case_1, only_chars1);
  tcase_add_test(test_case_1, only_chars2);
  tcase_add_test(test_case_1, only_chars3);
  tcase_add_test(test_case_1, only_chars4);
  tcase_add_test(test_case_1, only_chars5);
  tcase_add_test(test_case_1, special_symbols_as_chars1);
  tcase_add_test(test_case_1, special_symbols_as_chars2);
  tcase_add_test(test_case_1, special_symbols_as_chars3);

  tcase_add_test(test_case_1, chars_flags1);  // Precision flags lead to fail
  tcase_add_test(test_case_1,
                 chars_flags2);  // Width flags do nothing (if <= 1)
  tcase_add_test(test_case_1, chars_flags3);
  tcase_add_test(test_case_1, chars_flags4);  // Length flags do nothing
  tcase_add_test(test_case_1, chars_flags5);  // * flags - ignores char
  tcase_add_test(test_case_1, chars_aster1);
  tcase_add_test(test_case_1, chars_aster2);

  // [%d]/[%i]
  // [Width]: * - skip token, (N) - read N chars as a number
  // [Precision]: Not applicable to int, considered as UB

  // Length (h, l, ll)
  tcase_add_test(test_case_1, only_ints1);
  tcase_add_test(test_case_1, only_ints2);
  tcase_add_test(test_case_1, only_ints3);
  // // Width (N)
  tcase_add_test(test_case_1, ints_nwidth1);
  tcase_add_test(test_case_1, ints_nwidth2);
  // tcase_add_test(test_case_1, ints_nwidth3);
  // tcase_add_test(test_case_1, ints_nwidth4);
  // // Width (*)
  tcase_add_test(test_case_1, ints_astwidth1);
  // tcase_add_test(test_case_1, ints_astwidth2);
  // tcase_add_test(test_case_1, ints_astwidth3);
  // tcase_add_test(test_case_1, ints_astwidth4);
  // // Negative & positive ints
  tcase_add_test(test_case_1, signed_ints1);
  tcase_add_test(test_case_1, signed_ints2);
  tcase_add_test(test_case_1, signed_ints3);
  tcase_add_test(test_case_1, signed_ints4);

  // // [%i] Specifier. It may be INT, OCT, HEX

  tcase_add_test(test_case_1, spec_i_int1);
  tcase_add_test(test_case_1, spec_i_int2);
  // // Mixed with chars & ints
  tcase_add_test(test_case_1, spec_i_int3);
  // tcase_add_test(test_case_1, spec_i_int4);

  // tcase_add_test(test_case_1, spec_i_oct1);
  // tcase_add_test(test_case_1, spec_i_oct2);
  // tcase_add_test(test_case_1, spec_i_hex1);
  // tcase_add_test(test_case_1, spec_i_hex2);

  // [%s]
  // Width: (N) - parses N chars, (*) - пропустить строку
  // OUT: res = 4 (корректно парсит все в разные строки)
  // int res = sscanf("abobashlepafloppakoppa", "%5s %6s %6s %4s", s1, s2, s3,
  // s4); Precision, length - not applicable

  tcase_add_test(test_case_1, strings1);
  tcase_add_test(test_case_1, strings2);
  tcase_add_test(test_case_1, strings3);
  tcase_add_test(test_case_1, strings4);
  tcase_add_test(test_case_1, strings5);
  tcase_add_test(test_case_1, strings6);
  tcase_add_test(test_case_1, uint1);
  tcase_add_test(test_case_1, uint2);
  // tcase_add_test(test_case_1, uint3);
  tcase_add_test(test_case_1, uint4);
  tcase_add_test(test_case_1, uint5);
  tcase_add_test(test_case_1, uint6);
  // tcase_add_test(test_case_1, strings_mixed1);
  // tcase_add_test(test_case_1, strings_mixed2);
  tcase_add_test(test_case_1, strings_mixed3);

  // [%f] [%g] [%G]
  // Width: (N) - parses N chars, (*) - пропустить строку
  // Precision: take it into account while parsing AFTER (.)
  // Length - l - long

  tcase_add_test(test_case_1, floats1);
  tcase_add_test(test_case_1, floats2);
  tcase_add_test(test_case_1, floats3);
  tcase_add_test(test_case_1, floats4);
  tcase_add_test(test_case_1, floats5);

  tcase_add_test(test_case_1, floats_sci1);
  // tcase_add_test(test_case_1, floats_sci2);
  // tcase_add_test(test_case_1, floats_sci3);
  // tcase_add_test(test_case_1, floats_sci4);
  //  tcase_add_test(test_case_1, floats_sci5);

  // [%n] specifier

  tcase_add_test(test_case_1, n1);

  tcase_add_test(test_case_1, n2);
  tcase_add_test(test_case_1, n3);
  tcase_add_test(test_case_1, n4);
  tcase_add_test(test_case_1, n5);

  tcase_add_test(test_case_1, n2);
  tcase_add_test(test_case_1, n3);
  tcase_add_test(test_case_1, n4);
  tcase_add_test(test_case_1, n5);

  tcase_add_test(test_case_1, upeer_hex_base_version);
  tcase_add_test(test_case_1, upeer_hex_overflow);
  tcase_add_test(test_case_1, upeer_hex_0x);
  tcase_add_test(test_case_1, upeer_hex_0X);
  tcase_add_test(test_case_1, upeer_hex_empty);
  // tcase_add_test(test_case_1, upeer_hex_fail);
  //
  tcase_add_test(test_case_1, upeer_hex_spaces_tabs_sns);
  //
  tcase_add_test(test_case_1, upeer_hex_short);
  tcase_add_test(test_case_1, upeer_hex_long);
  // tcase_add_test(test_case_1, upeer_hex_2x);
  tcase_add_test(test_case_1, upeer_hex_star);
  tcase_add_test(test_case_1, upper_hex_len);

  tcase_add_test(test_case_1, lower_hex_len);

  tcase_add_test(test_case_1, octal_base_version);
  tcase_add_test(test_case_1, octal_overflow);
  tcase_add_test(test_case_1, octal_0x);
  tcase_add_test(test_case_1, octal_0X);
  tcase_add_test(test_case_1, octal_empty);
  //

  //
  tcase_add_test(test_case_1, octal_spaces_tabs_sns);
  tcase_add_test(test_case_1, octal_short);
  tcase_add_test(test_case_1, octal_long);
  tcase_add_test(test_case_1, octal_2x);
  tcase_add_test(test_case_1, octal_star);
  //

  //

  tcase_add_test(test_case_1, octal_sign);
  tcase_add_test(test_case_1, octal_len);

  tcase_add_test(test_case_1, pointer1);
  tcase_add_test(test_case_1, pointer2);
  tcase_add_test(test_case_1, pointer3);
  tcase_add_test(test_case_1, pointer4);
  suite_add_tcase(s1, test_case_1);
  return s1;
}