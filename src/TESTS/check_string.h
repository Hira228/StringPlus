#ifndef SRC_UNIT_TESTS_S21
#define SRC_UNIT_TESTS_S21

#include <check.h>
#include <time.h>
#include <unistd.h>

#include "../s21_string.h"

Suite *suite_sscanf(void);
Suite *core_suite(void);
Suite *suite_all_test(void);
void run_tests(void);
void run_testcase(Suite *testcase);
double get_rand(double min, double max);

#endif