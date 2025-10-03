#include "test.h"

START_TEST(test_s21_to_upper_1) {
  char *res = s21_to_upper("AbCdEfG");
  ck_assert_pstr_eq(res, "ABCDEFG");
  if (res) free(res);
}
END_TEST

START_TEST(test_s21_to_upper_2) {
  char *res = s21_to_upper("Testing code\n\0");
  ck_assert_pstr_eq(res, "TESTING CODE\n\0");
  if (res) free(res);
}
END_TEST

START_TEST(test_s21_to_upper_3) {
  char *res = s21_to_upper("a\n\0");
  ck_assert_pstr_eq(res, "A\n\0");
  if (res) free(res);
}
END_TEST

START_TEST(test_s21_to_upper_4) {
  char *res = s21_to_upper(" \n\0");
  ck_assert_pstr_eq(res, " \n\0");
  if (res) free(res);
}
END_TEST

START_TEST(test_s21_to_upper_5) {
  char *res = s21_to_upper("\0");
  ck_assert_pstr_eq(res, "\0");
  if (res) free(res);
}
END_TEST

START_TEST(test_s21_to_lower_1) {
  char *res = s21_to_lower("AbCdEfG");
  ck_assert_pstr_eq(res, "abcdefg");
  if (res) free(res);
}
END_TEST

START_TEST(test_s21_to_lower_2) {
  char *res = s21_to_lower("Testing code\n\0");
  ck_assert_pstr_eq(res, "testing code\n\0");
  if (res) free(res);
}
END_TEST

START_TEST(test_s21_to_lower_3) {
  char *res = s21_to_lower("a\n\0");
  ck_assert_pstr_eq(res, "a\n\0");
  if (res) free(res);
}
END_TEST

START_TEST(test_s21_to_lower_4) {
  char *res = s21_to_lower(" \n\0");
  ck_assert_pstr_eq(res, " \n\0");
  if (res) free(res);
}
END_TEST

START_TEST(test_s21_to_lower_5) {
  char *res = s21_to_lower("\0");
  ck_assert_pstr_eq(res, "\0");
  if (res) free(res);
}
END_TEST

START_TEST(test_s21_insert_1) {
  char *test01 = s21_insert("Hello", "Man", 2);
  ck_assert_pstr_eq(test01, "HeManllo");
  if (test01) free(test01);
}
END_TEST

START_TEST(test_s21_insert_2) {
  char *test02 = s21_insert("Hello\n\0", "Man\n\0", 1);
  ck_assert_pstr_eq(test02, "HMan\nello\n\0");
  if (test02) free(test02);
}
END_TEST

START_TEST(test_s21_insert_3) {
  char *test03 = s21_insert("a\0", "man\0", 1);
  ck_assert_pstr_eq(test03, "aman");
  if (test03) free(test03);
}
END_TEST

START_TEST(test_s21_insert_4) {
  char *test04 = s21_insert(" s\0", " s\0", 1);
  ck_assert_pstr_eq(test04, "  ss");
  if (test04) free(test04);
}
END_TEST

START_TEST(test_s21_insert_5) {
  char *test05 = s21_insert("\n\0", "\n\0", 1);
  ck_assert_pstr_eq(test05, "\n\n");
  if (test05) free(test05);
}
END_TEST

START_TEST(test_s21_trim_1) {
  char *test01 = s21_trim("-=Hello=-", "-");
  ck_assert_pstr_eq(test01, "=Hello=\0");
  if (test01) free(test01);
}
END_TEST

START_TEST(test_s21_trim_2) {
  char *test02 = s21_trim("-Hello\n\0", "-");
  ck_assert_pstr_eq(test02, "Hello\n");
  if (test02) free(test02);
}
END_TEST

START_TEST(test_s21_trim_3) {
  char *test03 = s21_trim("aa", "a");
  ck_assert_pstr_eq(test03, "");
  if (test03) free(test03);
}
END_TEST

START_TEST(test_s21_trim_4) {
  char *test04 = s21_trim(" \n ", "\n");
  ck_assert_pstr_eq(test04, " \n ");
  if (test04) free(test04);
}
END_TEST

START_TEST(test_s21_trim_5) {
  char *res = s21_trim("testc", "c");
  ck_assert_str_eq(res, "test");
  if (res) free(res);
}
END_TEST

Suite *csharp_suite_create(void) {
  Suite *suite;
  TCase *tcase_to_upper, *tcase_to_lower, *tcase_insert, *tcase_trim;

  suite = suite_create("5 quest");

  tcase_to_upper = tcase_create("to_upper");
  tcase_add_test(tcase_to_upper, test_s21_to_upper_1);
  tcase_add_test(tcase_to_upper, test_s21_to_upper_2);
  tcase_add_test(tcase_to_upper, test_s21_to_upper_3);
  tcase_add_test(tcase_to_upper, test_s21_to_upper_4);
  tcase_add_test(tcase_to_upper, test_s21_to_upper_5);
  suite_add_tcase(suite, tcase_to_upper);

  tcase_to_lower = tcase_create("to_lower");
  tcase_add_test(tcase_to_lower, test_s21_to_lower_1);
  tcase_add_test(tcase_to_lower, test_s21_to_lower_2);
  tcase_add_test(tcase_to_lower, test_s21_to_lower_3);
  tcase_add_test(tcase_to_lower, test_s21_to_lower_4);
  tcase_add_test(tcase_to_lower, test_s21_to_lower_5);
  suite_add_tcase(suite, tcase_to_lower);

  tcase_insert = tcase_create("insert");
  tcase_add_test(tcase_insert, test_s21_insert_1);
  tcase_add_test(tcase_insert, test_s21_insert_2);
  tcase_add_test(tcase_insert, test_s21_insert_3);
  tcase_add_test(tcase_insert, test_s21_insert_4);
  tcase_add_test(tcase_insert, test_s21_insert_5);
  suite_add_tcase(suite, tcase_insert);

  tcase_trim = tcase_create("trim");
  tcase_add_test(tcase_trim, test_s21_trim_1);
  tcase_add_test(tcase_trim, test_s21_trim_2);
  tcase_add_test(tcase_trim, test_s21_trim_3);
  tcase_add_test(tcase_trim, test_s21_trim_4);
  tcase_add_test(tcase_trim, test_s21_trim_5);
  suite_add_tcase(suite, tcase_trim);

  return suite;
}
int test_csharp() {
  int no_failed = 0;
  Suite *suite = csharp_suite_create();
  SRunner *suite_runner = srunner_create(suite);

  srunner_set_fork_status(suite_runner, CK_NOFORK);
  srunner_run_all(suite_runner, CK_NORMAL);
  no_failed = srunner_ntests_failed(suite_runner);
  srunner_free(suite_runner);

  return no_failed;
}
