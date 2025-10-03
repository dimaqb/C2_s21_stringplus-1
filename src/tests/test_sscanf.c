#include "test.h"

START_TEST(test_s21_sscanf_1) {
  const char str[] = "aboba,\tpopa\n";
  const char *pattern = "aboba,\t%s\n";

  char res_str1[10] = {0};
  char res_str2[10] = {0};
  int res1 = 0;
  int res2 = 0;

  res1 = s21_sscanf(str, pattern, res_str1);
  res2 = sscanf(str, pattern, res_str2);

  ck_assert_str_eq(res_str1, res_str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sscanf_2) {
  const char str[] = "abobik, \nmy age\t   is 228";
  const char *pattern = "abobik, \nmy age\t   is %d";

  int res_str1;
  int res_str2;
  int res1 = 0;
  int res2 = 0;

  res1 = s21_sscanf(str, pattern, &res_str1);
  res2 = sscanf(str, pattern, &res_str2);

  ck_assert_int_eq(res_str1, res_str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sscanf_3) {
  const char str[] = "abobik, \nmy age\t   is -228";
  const char *pattern = "abobik, \nmy age\t   is %d";

  int res_str1;
  int res_str2;
  int res1 = 0;
  int res2 = 0;

  res1 = s21_sscanf(str, pattern, &res_str1);
  res2 = sscanf(str, pattern, &res_str2);

  ck_assert_int_eq(res_str1, res_str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sscanf_4) {
  const char str[] = "abobik, privet,\nya veshy\t   is 66.6";
  const char *pattern = "abobik, privet,\nya veshy\t   is %d";

  float res_str1;
  float res_str2;
  int res1 = 0;
  int res2 = 0;

  res1 = s21_sscanf(str, pattern, &res_str1);
  res2 = sscanf(str, pattern, &res_str2);

  ck_assert_float_eq_tol(res_str1, res_str2, 1e-5);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sscanf_5) {
  const char str[] = "abobik, privet,\nya veshy\t is 0xF";
  const char *pattern = "abobik, privet,\nya veshy\t is %i";

  int res_str1;
  int res_str2;
  int res1 = 0;
  int res2 = 0;

  res1 = s21_sscanf(str, pattern, &res_str1);
  res2 = sscanf(str, pattern, &res_str2);

  ck_assert_int_eq(res_str1, res_str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sscanf_6) {
  const char str[] = "abobus, kyky,\nmy age\t   is -0xFED";
  const char *pattern = "abobus, kyky,\nmy age\t   is %i";

  int res_str1;
  int res_str2;
  int res1 = 0;
  int res2 = 0;

  res1 = s21_sscanf(str, pattern, &res_str1);
  res2 = sscanf(str, pattern, &res_str2);

  ck_assert_int_eq(res_str1, res_str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sscanf_7) {
  const char str[] = "abobus, kyky,\nmy age\t   is +15";
  const char *pattern = "abobus, kyky,\nmy age\t   is %i";

  int res_str1;
  int res_str2;
  int res1 = 0;
  int res2 = 0;

  res1 = s21_sscanf(str, pattern, &res_str1);
  res2 = sscanf(str, pattern, &res_str2);

  ck_assert_int_eq(res_str1, res_str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sscanf_8) {
  const char str[] = "abobus, kyky,\nmy age\t   is 61.1e-5";
  const char *pattern = "abobus, kyky,\nmy age\t   is %e";

  float res_str1;
  float res_str2;
  int res1 = 0;
  int res2 = 0;

  res1 = s21_sscanf(str, pattern, &res_str1);
  res2 = sscanf(str, pattern, &res_str2);

  ck_assert_float_eq_tol(res_str1, res_str2, 1e-5);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sscanf_9) {
  const char str[] = "abobikus, kakashin,\nmy age\t   is 61.1e+5";
  const char *pattern = "abobikus, kakashin,\nmy age\t   is %hE";

  float res_str1 = 0;
  float res_str2 = 0;
  int res1 = s21_sscanf(str, pattern, &res_str1);
  int res2 = sscanf(str, pattern, &res_str2);

  ck_assert_float_eq_tol(res_str1, res_str2, 1e-5);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sscanf_10) {
  const char str[] = "abobkin, pupkin,\nmy age\t   is 61.1e-5";
  const char *pattern = "abobkin, pupkin,\nmy age\t   is %hf";

  float res_str1;
  float res_str2;
  int res1 = 0;
  int res2 = 0;

  res1 = s21_sscanf(str, pattern, &res_str1);
  res2 = sscanf(str, pattern, &res_str2);

  ck_assert_float_eq_tol(res_str1, res_str2, 1e-5);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sscanf_11) {
  const char str[] = "abobuz, arbyzov,\nmy age\t   is 61.1e-5";
  const char *pattern = "abobuz, arbyzov,\nmy age\t   is %hg";

  float res_str1;
  float res_str2;
  int res1 = 0;
  int res2 = 0;

  res1 = s21_sscanf(str, pattern, &res_str1);
  res2 = sscanf(str, pattern, &res_str2);

  ck_assert_float_eq_tol(res_str1, res_str2, 1e-5);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sscanf_12) {
  const char str[] = "bublik, macdonalds,\nmy age\t   is 6";
  const char *pattern = "bublik, macdonalds,\nmy age\t   is %o";

  int res_str1;
  int res_str2;
  int res1 = 0;
  int res2 = 0;

  res1 = s21_sscanf(str, pattern, &res_str1);
  res2 = sscanf(str, pattern, &res_str2);

  ck_assert_int_eq(res_str1, res_str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sscanf_13) {
  const char str[] = "bobik, popik,\nmy age\t   is -6";
  const char *pattern = "bobik, popik,\nmy age\t   is %o";

  int res_str1;
  int res_str2;
  int res1 = 0;
  int res2 = 0;

  res1 = s21_sscanf(str, pattern, &res_str1);
  res2 = sscanf(str, pattern, &res_str2);

  ck_assert_int_eq(res_str1, res_str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sscanf_14) {
  const char str[] = "abobusik, \nmy age\t   is -7";
  const char *pattern = "abobusik, \nmy age\t   is %u";

  unsigned int res_str1;
  unsigned int res_str2;
  int res1 = 0;
  int res2 = 0;

  res1 = s21_sscanf(str, pattern, &res_str1);
  res2 = sscanf(str, pattern, &res_str2);

  ck_assert_uint_eq(res_str1, res_str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sscanf_15) {
  const char str[] = "abobusik, \nmy age\t   is 77";
  const char *pattern = "abobusik, \nmy age\t   is %u";

  unsigned int res_str1;
  unsigned int res_str2;
  int res1 = 0;
  int res2 = 0;

  res1 = s21_sscanf(str, pattern, &res_str1);
  res2 = sscanf(str, pattern, &res_str2);

  ck_assert_uint_eq(res_str1, res_str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sscanf_16) {
  const char str[] = "abobusik, \nmy age\t   is 0xfbc";
  const char *pattern = "abobusik, \nmy age\t   is %x";

  unsigned int res_str1;
  unsigned int res_str2;
  int res1 = 0;
  int res2 = 0;

  res1 = s21_sscanf(str, pattern, &res_str1);
  res2 = sscanf(str, pattern, &res_str2);

  ck_assert_uint_eq(res_str1, res_str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sscanf_17) {
  const char str[] = "abobusik, \nmy age\t  is -0xFF";
  const char *pattern = "abobusik, \nmy age\t  is %x";

  unsigned int res_str1;
  unsigned int res_str2;
  int res1 = 0;
  int res2 = 0;

  res1 = s21_sscanf(str, pattern, &res_str1);
  res2 = sscanf(str, pattern, &res_str2);

  ck_assert_uint_eq(res_str1, res_str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sscanf_18) {
  const char str[] = "abobusik, \nmy age\t   is 0xAA";
  const char *pattern = "abobusik, \nmy age\t   is %X";

  unsigned int res_str1;
  unsigned int res_str2;
  int res1 = 0;
  int res2 = 0;

  res1 = s21_sscanf(str, pattern, &res_str1);
  res2 = sscanf(str, pattern, &res_str2);

  ck_assert_uint_eq(res_str1, res_str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sscanf_19) {
  const char str[] = "abobusik, \nmy age\t   is -0xAA";
  const char *pattern = "abobusik, \nmy age\t   is %X";

  unsigned int res_str1 = 0;
  unsigned int res_str2 = 0;
  int res1 = 0;
  int res2 = 0;

  res1 = s21_sscanf(str, pattern, &res_str1);
  res2 = sscanf(str, pattern, &res_str2);

  ck_assert_uint_eq(res_str1, res_str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sscanf_20) {
  const char str[] = "Hello, abobus,\nmy age\t   is 0x, my name   is BEBRA";
  const char *pattern = "Hello, abobus,\nmy age\t   is %p, my name   is BEBRA";

  void *res_str1 = S21_NULL;
  void *res_str2 = S21_NULL;
  int res1 = 0;
  int res2 = 0;

  res1 = s21_sscanf(str, pattern, &res_str1);
  res2 = sscanf(str, pattern, &res_str2);

  ck_assert_ptr_eq(res_str1, res_str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sscanf_21) {
  const char str[] = "Hello, abobus,\nmy age\t   is 0, my name   is BEBRA";
  const char *pattern = "Hello, abobus,\nmy age\t   is %n, my name   is BEBRA";
  int res_str1;
  int res_str2;
  int res1 = 0;
  int res2 = 0;

  res1 = s21_sscanf(str, pattern, &res_str1);
  res2 = sscanf(str, pattern, &res_str2);

  ck_assert_int_eq(res_str1, res_str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sscanf_22) {
  const char str[] = "Hello, abobus,\nmy age\t   is 0, my name   is BEBRA";
  const char *pattern = "%n";

  int res_str1;
  int res_str2;
  int res1 = 0;
  int res2 = 0;

  res1 = s21_sscanf(str, pattern, &res_str1);
  res2 = sscanf(str, pattern, &res_str2);

  ck_assert_int_eq(res_str1, res_str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sscanf_23) {
  const char str[] = "Hello, abobus,\nmy age\t   is 0, my name   is BEBRA";
  const char *pattern = "asggaasfghsd%nasd";

  int res_str1 = 0;
  int res_str2 = 0;
  int res1 = 0;
  int res2 = 0;

  res1 = s21_sscanf(str, pattern, &res_str1);
  res2 = sscanf(str, pattern, &res_str2);

  ck_assert_int_eq(res_str1, res_str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sscanf_24) {
  const char str[] = "Hello, abobik\t popik\n eshkere, 666%, antihype";
  const char *pattern = "Hello, abobik\t popik\n eshkere, %d%%, antihype";
  char d_res1 = 0;
  char d_res2 = 0;
  int res1;
  int res2 = 0;

  res1 = s21_sscanf(str, pattern, &d_res1);
  res2 = sscanf(str, pattern, &d_res2);

  ck_assert_int_eq(d_res1, d_res2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sscanf_25) {
  const char str[] = "Hello, abobik\t popik\n eshkere, 666, antihype";
  const char *pattern = "Hello, abobik\t popik\n eshkere, %10d, antihype";

  int res_str1;
  int res_str2;
  int res1 = 0;
  int res2 = 0;

  res1 = s21_sscanf(str, pattern, &res_str1);
  res2 = sscanf(str, pattern, &res_str2);

  ck_assert_int_eq(res_str1, res_str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sscanf_26) {
  const char str[] = "Hello, abobik\t popik\n eshkere, 666, antihype";
  const char *pattern = "Hello, abobik\t popik\n eshkere, %2d, antihype";

  int res_str1;
  int res_str2;
  int res1 = 0;
  int res2 = 0;

  res1 = s21_sscanf(str, pattern, &res_str1);
  res2 = sscanf(str, pattern, &res_str2);

  ck_assert_int_eq(res_str1, res_str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sscanf_27) {
  const char str[] = "Hello, abobik\t popik\n eshkere, 666, antihype";
  const char *pattern = "Hello, abobik\t popik\n %6s, 666, antihype";

  char res_str1[10] = {0};
  char res_str2[10] = {0};
  int res1 = 0;
  int res2 = 0;

  res1 = s21_sscanf(str, pattern, res_str1);
  res2 = sscanf(str, pattern, res_str2);

  ck_assert_str_eq(res_str1, res_str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sscanf_28) {
  const char str[] = "Hello, abobik bobik, 666, eshkere eeee booyyyy";
  const char *pattern = "Hello, %*s bobik, 666, eshkere %s booyyyy";

  char res_str1[10] = {0};
  char res_str2[10] = {0};
  int res1 = 0;
  int res2 = 0;

  res1 = s21_sscanf(str, pattern, res_str1);
  res2 = sscanf(str, pattern, res_str2);

  ck_assert_str_eq(res_str1, res_str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sscanf_29) {
  const char str[] = "Hello, abobik bobik, 666, eshkere eeee booyyyy";
  const char *pattern = "Hello, abobik bobik, %hd, eshkere eeee booyyyy";

  short int res_str1;
  short int res_str2;
  int res1 = 0;
  int res2 = 0;

  res1 = s21_sscanf(str, pattern, &res_str1);
  res2 = sscanf(str, pattern, &res_str2);

  ck_assert_uint_eq(res_str1, res_str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sscanf_30) {
  const char str[] = "Hello, abobik bobik, 666, eshkere eeee booyyyy";
  const char *pattern = "Hello, abobik bobik, %ld, eshkere eeee booyyyy";

  long int res_str1;
  long int res_str2;
  int res1 = 0;
  int res2 = 0;

  res1 = s21_sscanf(str, pattern, &res_str1);
  res2 = sscanf(str, pattern, &res_str2);

  ck_assert_int_eq(res_str1, res_str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sscanf_31) {
  const char str[] = "Hello, abobik bobik, 66.6, eshkere eeee booyyyy";
  const char *pattern = "Hello, abobik bobik, %Lf, eshkere eeee booyyyy";

  long double res_str1 = 0;
  long double res_str2 = 0;
  int res1 = 0;
  int res2 = 0;

  res1 = s21_sscanf(str, pattern, &res_str1);
  res2 = sscanf(str, pattern, &res_str2);

  ck_assert_ldouble_eq_tol(res_str1, res_str2, 1e-5);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sscanf_32) {
  const char str[] = "Hello, abobik bobik, 07654, eshkere eeee booyyyy";
  const char *pattern = "Hello, abobik bobik, %i, eshkere eeee booyyyy";
  int res_str1 = 0;
  int res_str2 = 0;
  int res1 = 0;
  int res2 = 0;

  res1 = s21_sscanf(str, pattern, &res_str1);
  res2 = sscanf(str, pattern, &res_str2);

  ck_assert_int_eq(res_str1, res_str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sscanf_33) {
  const char str[] = "Hello, abobik bobik, 173893, eshkere eeee booyyyy";
  const char *pattern = "Hello, abobik bobik, %lu, eshkere eeee booyyyy";

  unsigned long res_str1 = 0;
  unsigned long res_str2 = 0;
  int res1 = 0;
  int res2 = 0;

  res1 = s21_sscanf(str, pattern, &res_str1);
  res2 = sscanf(str, pattern, &res_str2);

  ck_assert_uint_eq(res_str1, res_str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sscanf_34) {
  const char str[] = "Hello, abobik bobik, 17345, eshkere eeee booyyyy";
  const char *pattern = "Hello, abobik bobik, %hu, eshkere eeee booyyyy";

  unsigned short res_str1 = 0;
  unsigned short res_str2 = 0;
  int res1 = s21_sscanf(str, pattern, &res_str1);
  int res2 = sscanf(str, pattern, &res_str2);

  ck_assert_uint_eq(res_str1, res_str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sscanf_35) {
  const char str[] = "Hello, abobik,\nmne vot\t   stoka let 6996.1e-3";
  const char *pattern = "Hello, abobik,\nmne vot\t   stoka let %3e";

  double res_s21 = 0;
  double res = 0;
  int res1 = 0;
  int res2 = 0;

  res1 = s21_sscanf(str, pattern, &res_s21);
  res2 = sscanf(str, pattern, &res);

  ck_assert_float_eq_tol(res_s21, res, 1e-5);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sscanf_36) {
  const char str[] = "Hello, abobik,\nmne vot\t   stoka let 47e+3";
  const char *pattern = "Hello, abobik,\nmne vot\t   stoka let %e";

  float res_str1 = 0;
  float res_str2 = 0;
  int res1 = 0;
  int res2 = 0;

  res1 = s21_sscanf(str, pattern, &res_str1);
  res2 = sscanf(str, pattern, &res_str2);

  ck_assert_float_eq_tol(res_str1, res_str2, 1e-5);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sscanf_37) {
  const char str[] = "Hello, abobik, 124045.4556979, konfetki!";
  const char *pattern = "Hello, abobik, %lf, konfetki!";

  double res_str1 = 0;
  double res_str2 = 0;
  int res1 = 0;
  int res2 = 0;

  res1 = s21_sscanf(str, pattern, &res_str1);
  res2 = sscanf(str, pattern, &res_str2);

  ck_assert_ldouble_eq_tol(res_str1, res_str2, 1e-5);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sscanf_38) {
  const char str[] = "Hello, abobik, -47238.56345, konfetki!";
  const char *pattern = "Hello, abobik, %lf, konfetki!";

  double res_str1 = 0;
  double res_str2 = 0;
  int res1 = 0;
  int res2 = 0;

  res1 = s21_sscanf(str, pattern, &res_str1);
  res2 = sscanf(str, pattern, &res_str2);

  ck_assert_ldouble_eq_tol(res_str1, res_str2, 1e-5);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sscanf_39) {
  const char str[] = "Hello, abobik, -95434, konfetki!";
  const char *pattern = "Hello, abobik, %hu, konfetki!";

  unsigned short res_str1 = 0;
  unsigned short res_str2 = 0;
  int res1 = s21_sscanf(str, pattern, &res_str1);
  int res2 = sscanf(str, pattern, &res_str2);

  ck_assert_uint_eq(res_str1, res_str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sscanf_40) {
  const char input_str[] = "ZHOPAA, 100-200-300.400";
  const char *format_pattern = "ZHOPAA, %d%c%u%c%f";

  int result_int1 = 0;
  int expected_int1 = 0;
  char result_char1 = 0;
  char expected_char1 = 0;
  unsigned int result_uint1 = 0;
  unsigned int expected_uint1 = 0;
  char result_char2 = 0;
  char expected_char2 = 0;
  float result_float1 = 0;
  float expected_float1 = 0;

  int res_s21 = 0;
  int res = 0;

  res_s21 = s21_sscanf(input_str, format_pattern, &result_int1, &result_char1,
                       &result_uint1, &result_char2, &result_float1);
  res = sscanf(input_str, format_pattern, &expected_int1, &expected_char1,
               &expected_uint1, &expected_char2, &expected_float1);

  ck_assert_int_eq(result_int1, expected_int1);
  ck_assert_int_eq(res_s21, res);
  ck_assert_int_eq(result_char1, expected_char1);
  ck_assert_uint_eq(result_uint1, expected_uint1);
  ck_assert_int_eq(result_char2, expected_char2);
  ck_assert_float_eq_tol(result_float1, expected_float1, 1e-5);
}
END_TEST

START_TEST(test_s21_sscanf_41) {
  const char input_str[] = "int: 178353, char: Z, int int 19/34";
  const char *format_pattern = "int: %d, char: %c, int int %d%*c%d";

  int result_int1 = 0;
  char result_char1 = 0;
  int result_int2 = 0;
  int result_int3 = 0;

  int expected_int1 = 0;
  char expected_char1 = 0;
  int expected_int2 = 0;
  int expected_int3 = 0;

  int res1 = s21_sscanf(input_str, format_pattern, &result_int1, &result_char1,
                        &result_int2, &result_int3);
  int res2 = sscanf(input_str, format_pattern, &expected_int1, &expected_char1,
                    &expected_int2, &expected_int3);

  ck_assert_int_eq(result_int1, expected_int1);
  ck_assert_int_eq(result_char1, expected_char1);
  ck_assert_int_eq(result_int2, expected_int2);
  ck_assert_int_eq(result_int3, expected_int3);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sscanf_42) {
  const char input_str[] = "int: 1615, short: 24, long -8534632";
  const char *format_pattern = "int: %o, short: %hd, long %ld";

  unsigned int result_uint = 0;
  short result_short = 0;
  long result_long = 0;

  unsigned int expected_uint = 0;
  short expected_short = 0;
  long expected_long = 0;

  int res1 = s21_sscanf(input_str, format_pattern, &result_uint, &result_short,
                        &result_long);
  int res2 = sscanf(input_str, format_pattern, &expected_uint, &expected_short,
                    &expected_long);

  ck_assert_int_eq(result_uint, expected_uint);
  ck_assert_int_eq(result_short, expected_short);
  ck_assert_int_eq(result_long, expected_long);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sscanf_43) {
  const char input_str[] = "long: -627226, short: 0X4A3F unsigned 1616136";
  const char *format_pattern = "long: %li, short: %hX unsigned %u";

  long result_long = 0;
  unsigned short result_ushort = 0;
  unsigned int result_uint = 0;

  long expected_long = 0;
  unsigned short expected_ushort = 0;
  unsigned int expected_uint = 0;

  int res1 = s21_sscanf(input_str, format_pattern, &result_long, &result_ushort,
                        &result_uint);
  int res2 = sscanf(input_str, format_pattern, &expected_long, &expected_ushort,
                    &expected_uint);

  ck_assert_int_eq(result_long, expected_long);
  ck_assert_uint_eq(result_ushort, expected_ushort);
  ck_assert_uint_eq(result_uint, expected_uint);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sscanf_44) {
  const char input_str[] = "long: -742363, short: 0X1A2F unsigned 2211417";
  const char *format_pattern = "long: %lX, short: %li unsigned %u";

  unsigned long result_ulong = 0;
  long result_long = 0;
  unsigned int result_uint = 0;

  unsigned long expected_ulong = 0;
  long expected_long = 0;
  unsigned int expected_uint = 0;

  int res1 = s21_sscanf(input_str, format_pattern, &result_ulong, &result_long,
                        &result_uint);
  int res2 = sscanf(input_str, format_pattern, &expected_ulong, &expected_long,
                    &expected_uint);

  ck_assert_uint_eq(result_ulong, expected_ulong);
  ck_assert_int_eq(result_long, expected_long);
  ck_assert_uint_eq(result_uint, expected_uint);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sscanf_45) {
  const char input_str[] = "long: 0148774036, short: 0xcd1f, long 01296961056";
  const char *format_pattern = "long: %lo, short: %hi, long %lo";

  unsigned long result_ulong1 = 0;
  unsigned long result_ulong2 = 0;
  short result_short = 0;
  long result_long = 0;

  unsigned long expected_ulong1 = 0;
  unsigned long expected_ulong2 = 0;
  short expected_short = 0;
  long expected_long = 0;

  int res1 = s21_sscanf(input_str, format_pattern, &result_ulong1,
                        &result_ulong2, &result_short, &result_long);
  int res2 = sscanf(input_str, format_pattern, &expected_ulong1,
                    &expected_ulong2, &expected_short, &expected_long);

  ck_assert_uint_eq(result_ulong1, expected_ulong1);
  ck_assert_uint_eq(result_ulong2, expected_ulong2);
  ck_assert_int_eq(result_short, expected_short);
  ck_assert_uint_eq(result_long, expected_long);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sscanf_46) {
  const char str[] = "abobik,\nmy big number  13371488228666";
  const char *pattern = "abobik,\nmy big number  %ld";

  long res_str1 = 0;
  long res_str2 = 0;
  int res1 = 0;
  int res2 = 0;

  res1 = s21_sscanf(str, pattern, &res_str1);
  res2 = sscanf(str, pattern, &res_str2);

  ck_assert_int_eq(res_str1, res_str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sscanf_47) {
  const char str[] = "float: -0.123, int: -456";
  const char *pattern = "float: %f, int: %d";

  float res_float1 = 0;
  float res_float2 = 0;
  int res_int1 = 0;
  int res_int2 = 0;

  int res1 = s21_sscanf(str, pattern, &res_float1, &res_int1);
  int res2 = sscanf(str, pattern, &res_float2, &res_int2);

  ck_assert_float_eq_tol(res_float1, res_float2, 1e-5);
  ck_assert_int_eq(res_int1, res_int2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sscanf_48) {
  const char str[] = "123abc";
  const char *pattern = "%3d%3s";

  int res_int1 = 0;
  int res_int2 = 0;
  char res_str1[4] = {0};
  char res_str2[4] = {0};

  int res1 = s21_sscanf(str, pattern, &res_int1, res_str1);
  int res2 = sscanf(str, pattern, &res_int2, res_str2);

  ck_assert_int_eq(res_int1, res_int2);
  ck_assert_str_eq(res_str1, res_str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sscanf_49) {
  const char str[] = "0x1A3F";
  const char *pattern = "%x";

  unsigned int res_uint1 = 0;
  unsigned int res_uint2 = 0;

  int res1 = s21_sscanf(str, pattern, &res_uint1);
  int res2 = sscanf(str, pattern, &res_uint2);

  ck_assert_uint_eq(res_uint1, res_uint2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sscanf_50) {
  const char str[] = "3.14e-2";
  const char *pattern = "%e";

  float res_float1 = 0;
  float res_float2 = 0;

  int res1 = s21_sscanf(str, pattern, &res_float1);
  int res2 = sscanf(str, pattern, &res_float2);

  ck_assert_float_eq_tol(res_float1, res_float2, 1e-5);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sscanf_51) {
  const char str[] = "lox 47";
  const char *pattern = "%*s %d";

  int res_int1 = 0;
  int res_int2 = 0;

  int res1 = s21_sscanf(str, pattern, &res_int1);
  int res2 = sscanf(str, pattern, &res_int2);

  ck_assert_int_eq(res_int1, res_int2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sscanf_52) {
  const char str[] = "int: 101, float: 5.75";
  const char *pattern = "int: %d, float: %f";

  int res_int1 = 0;
  int res_int2 = 0;
  float res_float1 = 0;
  float res_float2 = 0;

  int res1 = s21_sscanf(str, pattern, &res_int1, &res_float1);
  int res2 = sscanf(str, pattern, &res_int2, &res_float2);

  ck_assert_int_eq(res_int1, res_int2);
  ck_assert_float_eq_tol(res_float1, res_float2, 1e-5);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sscanf_53) {
  const char str[] = "octal: 012345, decimal: 6789";
  const char *pattern = "octal: %o, decimal: %d";

  unsigned int res_octal1 = 0;
  unsigned int res_octal2 = 0;
  int res_decimal1 = 0;
  int res_decimal2 = 0;

  int res1 = s21_sscanf(str, pattern, &res_octal1, &res_decimal1);
  int res2 = sscanf(str, pattern, &res_octal2, &res_decimal2);

  ck_assert_uint_eq(res_octal1, res_octal2);
  ck_assert_int_eq(res_decimal1, res_decimal2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sscanf_54) {
  const char str[] = "str1=abc, str2=def";
  const char *pattern = "str1=%3s, str2=%3s";

  char res_str1[4] = {0};
  char res_str2[4] = {0};
  char exp_str1[4] = {0};
  char exp_str2[4] = {0};

  int res1 = s21_sscanf(str, pattern, res_str1, res_str2);
  int res2 = sscanf(str, pattern, exp_str1, exp_str2);

  ck_assert_str_eq(res_str1, exp_str1);
  ck_assert_str_eq(res_str2, exp_str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sscanf_55) {
  const char str[] = "hex: 0x1A3F, oct: 0777";
  const char *pattern = "hex: %x, oct: %o";

  unsigned int res_hex1 = 0;
  unsigned int res_hex2 = 0;
  unsigned int res_oct1 = 0;
  unsigned int res_oct2 = 0;

  int res1 = s21_sscanf(str, pattern, &res_hex1, &res_oct1);
  int res2 = sscanf(str, pattern, &res_hex2, &res_oct2);

  ck_assert_uint_eq(res_hex1, res_hex2);
  ck_assert_uint_eq(res_oct1, res_oct2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sscanf_56) {
  const char str[] = "hex: 0x1adeBC, oct: 0777";
  const char *pattern = "hex: %x, oct: %o";

  unsigned int res_hex1 = 0;
  unsigned int res_hex2 = 0;
  unsigned int res_oct1 = 0;
  unsigned int res_oct2 = 0;

  int res1 = s21_sscanf(str, pattern, &res_hex1, &res_oct1);
  int res2 = sscanf(str, pattern, &res_hex2, &res_oct2);

  ck_assert_uint_eq(res_hex1, res_hex2);
  ck_assert_uint_eq(res_oct1, res_oct2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sscanf_57) {
  const char str[] = "aboba,\t+10\n";
  const char *pattern = "aboba,\t%d\n";

  int actual = 0;
  int expected = 0;
  int res1 = 0;
  int res2 = 0;

  res1 = s21_sscanf(str, pattern, &actual);
  res2 = sscanf(str, pattern, &expected);

  ck_assert_int_eq(actual, expected);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sscanf_58) {
  const char str[] = "abo3ba,\t+010\n";
  const char *pattern = "abo3ba,\t%u\n";

  unsigned actual = 0;
  unsigned expected = 0;
  int res1 = 0;
  int res2 = 0;

  res1 = s21_sscanf(str, pattern, &actual);
  res2 = sscanf(str, pattern, &expected);

  ck_assert_uint_eq(actual, expected);
  ck_assert_uint_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sscanf_59) {
  const char str[] = "abo3ba,\t-010\n";
  const char *pattern = "abo3ba,\t%u\n";

  unsigned actual = 0;
  unsigned expected = 0;
  int res1 = 0;
  int res2 = 0;

  res1 = s21_sscanf(str, pattern, &actual);
  res2 = sscanf(str, pattern, &expected);

  ck_assert_uint_eq(actual, expected);
  ck_assert_uint_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sscanf_60) {
  const char str[] = "abo3ba,\t-110\n";
  const char *pattern = "abo3ba,\t%o\n";

  unsigned actual = 0;
  unsigned expected = 0;
  int res1 = 0;
  int res2 = 0;

  res1 = s21_sscanf(str, pattern, &actual);
  res2 = sscanf(str, pattern, &expected);

  ck_assert_uint_eq(actual, expected);
  ck_assert_uint_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sscanf_61) {
  const char str[] = "abo3ba,\t-0X110\n";
  const char *pattern = "abo3ba,\t%x\n";

  unsigned actual = 0;
  unsigned expected = 0;
  int res1 = 0;
  int res2 = 0;

  res1 = s21_sscanf(str, pattern, &actual);
  res2 = sscanf(str, pattern, &expected);

  ck_assert_uint_eq(actual, expected);
  ck_assert_uint_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sscanf_62) {
  const char str[] = "abo3ba,\t-10\n";
  const char *pattern = "abo3ba,\t%i\n";

  int actual = 0;
  int expected = 0;
  int res1 = 0;
  int res2 = 0;

  res1 = s21_sscanf(str, pattern, &actual);
  res2 = sscanf(str, pattern, &expected);

  ck_assert_int_eq(actual, expected);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sscanf_63) {
  const char str[] = "abo3ba,\t-070\n";
  const char *pattern = "abo3ba,\t%i\n";

  int actual = 0;
  int expected = 0;
  int res1 = 0;
  int res2 = 0;

  res1 = s21_sscanf(str, pattern, &actual);
  res2 = sscanf(str, pattern, &expected);

  ck_assert_int_eq(actual, expected);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sscanf_64) {
  const char str[] = "abo3ba,\t-0x10\n";
  const char *pattern = "abo3ba,\t%i\n";

  int actual = 0;
  int expected = 0;
  int res1 = 0;
  int res2 = 0;

  res1 = s21_sscanf(str, pattern, &actual);
  res2 = sscanf(str, pattern, &expected);

  ck_assert_int_eq(actual, expected);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sscanf_65) {
  const char str[] = "";
  const char *pattern = "%i";

  int actual = 0;
  int expected = 0;
  int res1 = 0;
  int res2 = 0;

  res1 = s21_sscanf(str, pattern, &actual);
  res2 = sscanf(str, pattern, &expected);

  ck_assert_int_eq(actual, expected);
  ck_assert_int_eq(res1, res2);
}

START_TEST(test_s21_sscanf_66) {
  const char str[] = " ";
  const char *pattern = "%i";

  int actual = 0;
  int expected = 0;
  int res1 = 0;
  int res2 = 0;

  res1 = s21_sscanf(str, pattern, &actual);
  res2 = sscanf(str, pattern, &expected);

  ck_assert_int_eq(actual, expected);
  ck_assert_int_eq(res1, res2);
}

START_TEST(test_s21_sscanf_67) {
  const char str[] = "abo3ba,\t+010\n";
  const char *pattern = "abo3ba,\t%u\n";

  unsigned actual = 0;
  unsigned expected = 0;
  int res1 = 0;
  int res2 = 0;

  res1 = s21_sscanf(str, pattern, &actual);
  res2 = sscanf(str, pattern, &expected);

  ck_assert_uint_eq(actual, expected);
  ck_assert_uint_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sscanf_68) {
  const char str[] = "int: 101, float: -5.75";
  const char *pattern = "int: %d, float: %f";

  int res_int1 = 0;
  int res_int2 = 0;
  float res_float1 = 0;
  float res_float2 = 0;

  int res1 = s21_sscanf(str, pattern, &res_int1, &res_float1);
  int res2 = sscanf(str, pattern, &res_int2, &res_float2);

  ck_assert_int_eq(res_int1, res_int2);
  ck_assert_float_eq_tol(res_float1, res_float2, 1e-5);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sscanf_69) {
  const char str[] = "int: 101, float: .75";
  const char *pattern = "int: %d, float: %f";

  int res_int1 = 0;
  int res_int2 = 0;
  float res_float1 = 0;
  float res_float2 = 0;

  int res1 = s21_sscanf(str, pattern, &res_int1, &res_float1);
  int res2 = sscanf(str, pattern, &res_int2, &res_float2);

  ck_assert_int_eq(res_int1, res_int2);
  ck_assert_float_eq_tol(res_float1, res_float2, 1e-5);
  ck_assert_int_eq(res1, res2);
}
END_TEST

Suite *s21_sscanf_suite(void) {
  Suite *suite;
  TCase *tcase_s21_sscanf;

  suite = suite_create("quest4");
  tcase_s21_sscanf = tcase_create("s21_sscanf");

  tcase_add_test(tcase_s21_sscanf, test_s21_sscanf_1);
  tcase_add_test(tcase_s21_sscanf, test_s21_sscanf_2);
  tcase_add_test(tcase_s21_sscanf, test_s21_sscanf_3);
  tcase_add_test(tcase_s21_sscanf, test_s21_sscanf_4);
  tcase_add_test(tcase_s21_sscanf, test_s21_sscanf_5);
  tcase_add_test(tcase_s21_sscanf, test_s21_sscanf_6);
  tcase_add_test(tcase_s21_sscanf, test_s21_sscanf_7);
  tcase_add_test(tcase_s21_sscanf, test_s21_sscanf_8);
  tcase_add_test(tcase_s21_sscanf, test_s21_sscanf_9);
  tcase_add_test(tcase_s21_sscanf, test_s21_sscanf_10);
  tcase_add_test(tcase_s21_sscanf, test_s21_sscanf_11);
  tcase_add_test(tcase_s21_sscanf, test_s21_sscanf_12);
  tcase_add_test(tcase_s21_sscanf, test_s21_sscanf_13);
  tcase_add_test(tcase_s21_sscanf, test_s21_sscanf_14);
  tcase_add_test(tcase_s21_sscanf, test_s21_sscanf_15);
  tcase_add_test(tcase_s21_sscanf, test_s21_sscanf_16);
  tcase_add_test(tcase_s21_sscanf, test_s21_sscanf_17);
  tcase_add_test(tcase_s21_sscanf, test_s21_sscanf_18);
  tcase_add_test(tcase_s21_sscanf, test_s21_sscanf_19);
  tcase_add_test(tcase_s21_sscanf, test_s21_sscanf_20);
  tcase_add_test(tcase_s21_sscanf, test_s21_sscanf_21);
  tcase_add_test(tcase_s21_sscanf, test_s21_sscanf_22);
  tcase_add_test(tcase_s21_sscanf, test_s21_sscanf_23);
  tcase_add_test(tcase_s21_sscanf, test_s21_sscanf_24);
  tcase_add_test(tcase_s21_sscanf, test_s21_sscanf_25);
  tcase_add_test(tcase_s21_sscanf, test_s21_sscanf_26);
  tcase_add_test(tcase_s21_sscanf, test_s21_sscanf_27);
  tcase_add_test(tcase_s21_sscanf, test_s21_sscanf_28);
  tcase_add_test(tcase_s21_sscanf, test_s21_sscanf_29);
  tcase_add_test(tcase_s21_sscanf, test_s21_sscanf_30);
  tcase_add_test(tcase_s21_sscanf, test_s21_sscanf_31);
  tcase_add_test(tcase_s21_sscanf, test_s21_sscanf_32);
  tcase_add_test(tcase_s21_sscanf, test_s21_sscanf_33);
  tcase_add_test(tcase_s21_sscanf, test_s21_sscanf_34);
  tcase_add_test(tcase_s21_sscanf, test_s21_sscanf_35);
  tcase_add_test(tcase_s21_sscanf, test_s21_sscanf_36);
  tcase_add_test(tcase_s21_sscanf, test_s21_sscanf_37);
  tcase_add_test(tcase_s21_sscanf, test_s21_sscanf_38);
  tcase_add_test(tcase_s21_sscanf, test_s21_sscanf_39);
  tcase_add_test(tcase_s21_sscanf, test_s21_sscanf_40);
  tcase_add_test(tcase_s21_sscanf, test_s21_sscanf_41);
  tcase_add_test(tcase_s21_sscanf, test_s21_sscanf_42);
  tcase_add_test(tcase_s21_sscanf, test_s21_sscanf_43);
  tcase_add_test(tcase_s21_sscanf, test_s21_sscanf_44);
  tcase_add_test(tcase_s21_sscanf, test_s21_sscanf_45);
  tcase_add_test(tcase_s21_sscanf, test_s21_sscanf_46);
  tcase_add_test(tcase_s21_sscanf, test_s21_sscanf_47);
  tcase_add_test(tcase_s21_sscanf, test_s21_sscanf_48);
  tcase_add_test(tcase_s21_sscanf, test_s21_sscanf_49);
  tcase_add_test(tcase_s21_sscanf, test_s21_sscanf_50);
  tcase_add_test(tcase_s21_sscanf, test_s21_sscanf_51);
  tcase_add_test(tcase_s21_sscanf, test_s21_sscanf_52);
  tcase_add_test(tcase_s21_sscanf, test_s21_sscanf_53);
  tcase_add_test(tcase_s21_sscanf, test_s21_sscanf_54);
  tcase_add_test(tcase_s21_sscanf, test_s21_sscanf_55);
  tcase_add_test(tcase_s21_sscanf, test_s21_sscanf_56);
  tcase_add_test(tcase_s21_sscanf, test_s21_sscanf_57);
  tcase_add_test(tcase_s21_sscanf, test_s21_sscanf_58);
  tcase_add_test(tcase_s21_sscanf, test_s21_sscanf_59);
  tcase_add_test(tcase_s21_sscanf, test_s21_sscanf_60);
  tcase_add_test(tcase_s21_sscanf, test_s21_sscanf_61);
  tcase_add_test(tcase_s21_sscanf, test_s21_sscanf_62);
  tcase_add_test(tcase_s21_sscanf, test_s21_sscanf_63);
  tcase_add_test(tcase_s21_sscanf, test_s21_sscanf_64);
  tcase_add_test(tcase_s21_sscanf, test_s21_sscanf_65);
  tcase_add_test(tcase_s21_sscanf, test_s21_sscanf_66);
  tcase_add_test(tcase_s21_sscanf, test_s21_sscanf_67);
  tcase_add_test(tcase_s21_sscanf, test_s21_sscanf_68);
  tcase_add_test(tcase_s21_sscanf, test_s21_sscanf_69);
  suite_add_tcase(suite, tcase_s21_sscanf);

  return suite;
}

int test_sscanf() {
  int no_failed = 0;
  Suite *suite = s21_sscanf_suite();
  SRunner *suite_runner = srunner_create(suite);

  srunner_set_fork_status(suite_runner, CK_NOFORK);
  srunner_run_all(suite_runner, CK_NORMAL);
  no_failed = srunner_ntests_failed(suite_runner);
  srunner_free(suite_runner);

  return no_failed;
}