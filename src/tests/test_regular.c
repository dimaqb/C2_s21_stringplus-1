#include "test.h"

START_TEST(test_s21_memchr_1) {
  const char str[] = "1234567890";
  ck_assert_ptr_eq(s21_memchr(str, '4', 10), memchr(str, '4', 10));
}
END_TEST

START_TEST(test_s21_memchr_2) {
  const char str[] = "1234567890";
  ck_assert_ptr_eq(s21_memchr(str, '1', 5), memchr(str, '1', 5));
}
END_TEST

START_TEST(test_s21_memchr_3) {
  const char str[] = "1234567890";
  ck_assert_ptr_eq(s21_memchr(str, '0', 5), memchr(str, '0', 5));
}
END_TEST

START_TEST(test_s21_memchr_4) {
  char str[] = "Abobik";
  int ch = '9';
  s21_size_t len = strlen(str);
  ck_assert_ptr_eq(memchr(str, ch, len), s21_memchr(str, ch, len));
}
END_TEST

START_TEST(test_s21_memchr_5) {
  char str[] = "Abobik";
  int ch = 'A';
  s21_size_t len = strlen(str);
  ck_assert_ptr_eq(memchr(str, ch, len), s21_memchr(str, ch, len));
}
END_TEST

START_TEST(test_s21_memchr_6) {
  const char str[] = "1234567890";
  ck_assert_ptr_eq(s21_memchr(str, '0', 0), memchr(str, '0', 0));
}
END_TEST

START_TEST(test_s21_memcmp_1) {
  char str[] = "Abobik";
  char str2[] = "Abobik";
  s21_size_t len = strlen(str2);
  int expected = memcmp(str, str2, len);
  int actual = s21_memcmp(str, str2, len);
  ck_assert(!((actual * expected == 0) && (actual - expected != 0)));
  ck_assert_int_ge(expected * actual, 0);
}
END_TEST

START_TEST(test_s21_memcmp_2) {
  char str[] = "Abobik";
  char str2[] = "a";
  s21_size_t len = strlen(str2);
  int expected = memcmp(str, str2, len);
  int actual = s21_memcmp(str, str2, len);
  ck_assert(!((actual * expected == 0) && (actual - expected != 0)));
  ck_assert_int_ge(expected * actual, 0);
}
END_TEST

START_TEST(test_s21_memcmp_3) {
  char str[] = "12345";
  char str2[] = "12345";
  s21_size_t len = strlen(str2);
  int expected = memcmp(str, str2, len);
  int actual = s21_memcmp(str, str2, len);
  ck_assert(!((actual * expected == 0) && (actual - expected != 0)));
  ck_assert_int_ge(expected * actual, 0);
}
END_TEST

START_TEST(test_s21_memcmp_4) {
  char str[] = "0";
  char str2[] = "Abobik";
  s21_size_t len = strlen(str2);
  int expected = memcmp(str, str2, len);
  int actual = s21_memcmp(str, str2, len);
  ck_assert(!((actual * expected == 0) && (actual - expected != 0)));
  ck_assert_int_ge(expected * actual, 0);
}
END_TEST

START_TEST(test_s21_memcmp_5) {
  char str[] = "";
  char str2[] = "00";
  s21_size_t len = strlen(str2);
  int expected = memcmp(str, str2, len);
  int actual = s21_memcmp(str, str2, len);
  ck_assert(!((actual * expected == 0) && (actual - expected != 0)));
  ck_assert_int_ge(expected * actual, 0);
}
END_TEST

START_TEST(test_s21_memcmp_6) {
  char str[] = "Abobik";
  char str2[] = "Abobik";
  int expected = memcmp(str, str2, 0);
  int actual = s21_memcmp(str, str2, 0);
  ck_assert(!((actual * expected == 0) && (actual - expected != 0)));
  ck_assert_int_ge(expected * actual, 0);
}
END_TEST

START_TEST(test_s21_memcpy_1) {
  char str[18] = "Abobik";
  char str2[] = "aboba";
  ck_assert_ptr_eq(memcpy(str, str2, 6), s21_memcpy(str, str2, 6));
}
END_TEST

START_TEST(test_s21_memcpy_2) {
  char str[100] = "Hello, world!";
  char str2[] = "world!";
  ck_assert_ptr_eq(memcpy(str, str2, 4), s21_memcpy(str, str2, 4));
}
END_TEST

START_TEST(test_s21_memcpy_3) {
  char str[] = "Hello, world!";
  char str2[] = "Hello, world!";
  ck_assert_ptr_eq(memcpy(str, str2, 0), s21_memcpy(str, str2, 0));
}
END_TEST

START_TEST(test_s21_memcpy_4) {
  char str[100] = "Hello, world!";
  char str2[11] = "cle world!";
  ck_assert_ptr_eq(memcpy(str, str2, 11), s21_memcpy(str, str2, 11));
}
END_TEST

START_TEST(test_s21_memcpy_5) {
  char str[25] = "Abobik";
  char str2[] = "bobik";
  ck_assert_ptr_eq(memcpy(str, str2, 6), s21_memcpy(str, str2, 6));
}
END_TEST

START_TEST(test_s21_memcpy_6) {
  char str[100] = "1234567890";
  char str2[11] = "Abobik";
  ck_assert_ptr_eq(memcpy(str, str2, 11), s21_memcpy(str, str2, 11));
}
END_TEST

START_TEST(test_s21_memset_1) {
  char str[100] = "1234567890";
  char str2[100] = "1234567890";
  memset(str, '1', 50);
  s21_memset(str2, '1', 50);
  ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(test_s21_memset_2) {
  char str[100] = "";
  char str2[100] = "";
  memset(str, '1', 50);
  s21_memset(str2, '1', 50);
  ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(test_s21_memset_3) {
  char str[100] = "516134141";
  char str2[100] = "516134141";
  memset(str, '0', 2);
  s21_memset(str2, '0', 2);
  ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(test_s21_memset_4) {
  char str[100] = "123122551261";
  char str2[100] = "123122551261";
  memset(str, '1', 1);
  s21_memset(str2, '1', 1);
  ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(test_s21_memset_5) {
  char str[100] = "hdfhdvdsvdsfvcsacxsacsac";
  char str2[100] = "xcbcvbmcvxc";
  memset(str, '1', 50);
  s21_memset(str2, '1', 50);
  ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(test_s21_memset_6) {
  char str[6] = "12345";
  char str2[6] = "12345";
  s21_memset(str, 'o', 5);
  memset(str2, 'o', 5);
  ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(test_s21_strchr_1) {
  char str[] = "Abobik";
  ck_assert_ptr_eq(strchr(str, 'b'), s21_strchr(str, 'b'));
}
END_TEST

START_TEST(test_s21_strchr_2) {
  char str[] = "Abobik";
  ck_assert_ptr_eq(strchr(str, 'u'), s21_strchr(str, 'u'));
}
END_TEST

START_TEST(test_s21_strchr_3) {
  char str[] = "";
  ck_assert_ptr_eq(strchr(str, 'u'), s21_strchr(str, 'u'));
}
END_TEST

START_TEST(test_s21_strchr_4) {
  char str[100] = " ";
  ck_assert_ptr_eq(strchr(str, ' '), s21_strchr(str, ' '));
}
END_TEST

START_TEST(test_s21_strchr_5) {
  char str[] = "Abobik";
  ck_assert_ptr_eq(strchr(str, '5'), s21_strchr(str, '5'));
}
END_TEST

START_TEST(test_s21_strchr_6) {
  char str[] = "Abobik\0bobik";
  ck_assert_ptr_eq(strchr(str, '!'), s21_strchr(str, '!'));
}
END_TEST

START_TEST(test_s21_strcspn_1) {
  ck_assert_int_eq(s21_strcspn("Hello world\n\0", "world\n\0"),
                   strcspn("Hello world\n\0", "world\n\0"));
}
END_TEST

START_TEST(test_s21_strcspn_2) {
  ck_assert_int_eq(s21_strcspn("", "\0"), strcspn("", "\0"));
}
END_TEST

START_TEST(test_s21_strcspn_3) {
  ck_assert_int_eq(s21_strcspn("a\n\0", "a\n\0"), strcspn("a\n\0", "a\n\0"));
}
END_TEST

START_TEST(test_s21_strcspn_4) {
  ck_assert_int_eq(s21_strcspn("\n\0", "\0"), strcspn("\n\0", "\0"));
}
END_TEST

START_TEST(test_s21_strcspn_5) {
  ck_assert_int_eq(s21_strcspn("\0", ""), strcspn("\0", ""));
}
END_TEST

START_TEST(test_s21_strlen_1) {
  char str[] = "12515123\0 73454345 ";
  ck_assert_int_eq(s21_strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(test_s21_strlen_2) {
  char str[] = " ";
  ck_assert_int_eq(s21_strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(test_s21_strlen_3) {
  char str[] = "";
  ck_assert_int_eq(s21_strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(test_s21_strlen_4) {
  char str[] = "\n";
  ck_assert_int_eq(s21_strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(test_s21_strlen_5) {
  char str[] = " ";
  ck_assert_int_eq(s21_strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(test_s21_strlen_6) {
  char str[] = "0";
  ck_assert_int_eq(s21_strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(test_s21_strcat_1) {
  char str[10] = "0\0 00";
  char str2[10] = "0\0 00";
  char app[10] = "12345";
  strcat(str2, app);
  s21_strcat(str, app);
  ck_assert_str_eq(str2, str);
}
END_TEST

START_TEST(test_s21_strcat_2) {
  char str[10] = "";
  char str2[10] = "";
  char app[10] = "12345";
  strcat(str2, app);
  s21_strcat(str, app);
  ck_assert_str_eq(str2, str);
}
END_TEST

START_TEST(test_s21_strcat_3) {
  char str[10] = "000";
  char str2[10] = "000";
  char app[10] = "000";
  strcat(str2, app);
  s21_strcat(str, app);
  ck_assert_str_eq(str2, str);
}
END_TEST

START_TEST(test_s21_strcat_4) {
  char str[10] = "000";
  char str2[10] = "000";
  char app[10] = " ";
  strcat(str2, app);
  s21_strcat(str, app);
  ck_assert_str_eq(str2, str);
}
END_TEST

START_TEST(test_s21_strcat_5) {
  char str[20] = "000";
  char str2[20] = "000";
  char app[10] = "12345";
  strcat(str2, app);
  s21_strcat(str, app);
  ck_assert_str_eq(str2, str);
}
END_TEST

START_TEST(test_s21_strcat_6) {
  char str[20] = "000";
  char str2[20] = "000";
  char app[10] = "12\nfds5";
  strcat(str2, app);
  s21_strcat(str, app);
  ck_assert_str_eq(str2, str);
}
END_TEST

START_TEST(test_s21_strncat_1) {
  char str[10] = "0\0 00";
  char str2[10] = "0\0 00";
  char app[10] = "12345";
  strncat(str2, app, 5);
  s21_strncat(str, app, 5);
  ck_assert_str_eq(str2, str);
}
END_TEST

START_TEST(test_s21_strncat_2) {
  char str[10] = "";
  char str2[10] = "";
  char app[10] = "12345";
  strncat(str2, app, 5);
  s21_strncat(str, app, 5);
  ck_assert_str_eq(str2, str);
}
END_TEST

START_TEST(test_s21_strncat_3) {
  char str[10] = "000";
  char str2[10] = "000";
  char app[10] = "000";
  strncat(str2, app, 5);
  s21_strncat(str, app, 5);
  ck_assert_str_eq(str2, str);
}
END_TEST

START_TEST(test_s21_strncat_4) {
  char str[10] = "000";
  char str2[10] = "000";
  char app[10] = " ";
  strncat(str2, app, 5);
  s21_strncat(str, app, 5);
  ck_assert_str_eq(str2, str);
}
END_TEST

START_TEST(test_s21_strncat_5) {
  char str[20] = "000";
  char str2[20] = "000";
  char app[10] = "12345";
  strncat(str2, app, 10);
  s21_strncat(str, app, 10);
  ck_assert_str_eq(str2, str);
}
END_TEST

START_TEST(test_s21_strncat_6) {
  char str[20] = "000";
  char str2[20] = "000";
  char app[10] = "12\nfds5";
  strncat(str2, app, 5);
  s21_strncat(str, app, 5);
  ck_assert_str_eq(str2, str);
}
END_TEST

START_TEST(test_s21_strerror_1) {
  int i = 0;
  ck_assert_str_eq(strerror(i), s21_strerror(i));
}
END_TEST

START_TEST(test_s21_strerror_2) {
  int i = 1;
  ck_assert_str_eq(strerror(i), s21_strerror(i));
}
END_TEST

START_TEST(test_s21_strerror_3) {
  int i = 2;
  ck_assert_str_eq(strerror(i), s21_strerror(i));
}
END_TEST

START_TEST(test_s21_strerror_4) {
  int i = 3;
  ck_assert_str_eq(strerror(i), s21_strerror(i));
}
END_TEST

START_TEST(test_s21_strerror_5) {
  int i = 4;
  ck_assert_str_eq(strerror(i), s21_strerror(i));
}
END_TEST

START_TEST(test_s21_strerror_6) {
  int i = 5;
  ck_assert_str_eq(strerror(i), s21_strerror(i));
}
END_TEST

START_TEST(test_s21_strerror_7) {
  int i = 6;
  ck_assert_str_eq(strerror(i), s21_strerror(i));
}
END_TEST

START_TEST(test_s21_strerror_8) {
  int i = 7;
  ck_assert_str_eq(strerror(i), s21_strerror(i));
}
END_TEST

START_TEST(test_s21_strerror_9) {
  int i = 8;
  ck_assert_str_eq(strerror(i), s21_strerror(i));
}
END_TEST

START_TEST(test_s21_strerror_10) {
  int i = 9;
  ck_assert_str_eq(strerror(i), s21_strerror(i));
}
END_TEST

START_TEST(test_s21_strerror_11) {
  int i = -2;
  ck_assert_str_eq(strerror(i), s21_strerror(i));
}
END_TEST

START_TEST(test_s21_strerror_12) {
  int i = 108;
  ck_assert_str_eq(strerror(i), s21_strerror(i));
}
END_TEST

START_TEST(test_s21_strncmp_1) {
  char str[] = "Hello world\n\0";
  char str2[] = "Hello world\n\0";
  s21_size_t len = 12;
  int expected = strncmp(str, str2, len);
  int actual = s21_strncmp(str, str2, len);
  ck_assert(!((actual * expected == 0) && (actual - expected != 0)));
  ck_assert_int_ge(expected * actual, 0);
}
END_TEST

START_TEST(test_s21_strncmp_2) {
  char str[] = "a\n\0";
  char str2[] = "a\n\0";
  s21_size_t len = 2;
  int expected = strncmp(str, str2, len);
  int actual = s21_strncmp(str, str2, len);
  ck_assert(!((actual * expected == 0) && (actual - expected != 0)));
  ck_assert_int_ge(expected * actual, 0);
}
END_TEST

START_TEST(test_s21_strncmp_3) {
  char str[] = " \n\0";
  char str2[] = " \n\0";
  s21_size_t len = 2;
  int expected = strncmp(str, str2, len);
  int actual = s21_strncmp(str, str2, len);
  ck_assert(!((actual * expected == 0) && (actual - expected != 0)));
  ck_assert_int_ge(expected * actual, 0);
}
END_TEST

START_TEST(test_s21_strncmp_4) {
  char str[] = "\n\0";
  char str2[] = "\n\0";
  s21_size_t len = 1;
  int expected = strncmp(str, str2, len);
  int actual = s21_strncmp(str, str2, len);
  ck_assert(!((actual * expected == 0) && (actual - expected != 0)));
  ck_assert_int_ge(expected * actual, 0);
}
END_TEST
START_TEST(test_s21_strncmp_5) {
  char str[] = "1224567890";
  char str2[] = "1234567890";
  s21_size_t len = 5;
  int expected = strncmp(str, str2, len);
  int actual = s21_strncmp(str, str2, len);
  ck_assert(!((actual * expected == 0) && (actual - expected != 0)));
  ck_assert_int_ge(expected * actual, 0);
}
END_TEST

START_TEST(test_s21_strncpy_1) {
  char str[20] = "1111111111";
  char str2[20] = "1111111111";
  char dst[10] = "12345\0006789";
  strncpy(str, dst, 7);
  s21_strncpy(str2, dst, 7);
  ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(test_s21_strncpy_2) {
  char str[20] = "1111111111";
  char str2[20] = "1111111111";
  char dst[10] = "\0\0\0\0\0";
  strncpy(str, dst, 3);
  s21_strncpy(str2, dst, 3);
  ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(test_s21_strncpy_3) {
  char str[20] = "1111111111";
  char str2[20] = "1111111111";
  char dst[10] = "12345\0006789";
  strncpy(str, dst, 7);
  s21_strncpy(str2, dst, 7);
  ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(test_s21_strncpy_4) {
  char str[20] = "1111111111";
  char str2[20] = "1111111111";
  char dst[10] = "1234567";
  strncpy(str, dst, 1);
  s21_strncpy(str2, dst, 1);
  ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(test_s21_strncpy_5) {
  char str[20] = "1111111111";
  char str2[20] = "1111111111";
  char dst[10] = "";
  strncpy(str, dst, 5);
  s21_strncpy(str2, dst, 5);
  ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(test_s21_strncpy_6) {
  char str[20] = "1111111111";
  char str2[20] = "1111111111";
  char dst[10] = "         ";
  strncpy(str, dst, 4);
  s21_strncpy(str2, dst, 4);
  ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(test_s21_strtok_1) {
  char str1[] = "abc";
  char str3[] = "abc";
  char str2[] = "c";
  strtok(str1, str2);
  s21_strtok(str3, str2);
  ck_assert_str_eq(str1, str3);
}
END_TEST

START_TEST(test_s21_strtok_2) {
  char str1[] = "abc";
  char str3[] = "abc";
  char str2[] = "b";
  ck_assert_str_eq(strtok(str1, str2), s21_strtok(str3, str2));
}
END_TEST

START_TEST(test_s21_strtok_3) {
  char str1[] = "abc";
  char str3[] = "abc";
  char str2[] = "a";
  ck_assert_str_eq(strtok(str1, str2), s21_strtok(str3, str2));
}
END_TEST

START_TEST(test_s21_strtok_4) {
  char str1[] = "abb";
  char str3[] = "abb";
  char str2[] = "b";
  ck_assert_str_eq(strtok(str1, str2), s21_strtok(str3, str2));
}
END_TEST

START_TEST(test_s21_strtok_5) {
  char str1[] = "abc";
  char str3[] = "abc";
  char str2[] = "c";
  ck_assert_str_eq(strtok(str1, str2), s21_strtok(str3, str2));
}
END_TEST

START_TEST(test_s21_strtok_6) {
  char str1[] = "bbc";
  char str3[] = "bbc";
  char str2[] = "b";
  ck_assert_str_eq(strtok(str1, str2), s21_strtok(str3, str2));
}
END_TEST

START_TEST(test_s21_strtok_7) {
  char str1[] = "aaabbcc";
  char str3[] = "aaabbcc";
  char str2[] = "c";
  ck_assert_str_eq(strtok(str1, str2), s21_strtok(str3, str2));
}
END_TEST

START_TEST(test_s21_strpbrk_1) {
  char str[20] = "1111111111";
  char str2[20] = "1111111111";
  ck_assert_ptr_eq(strpbrk(str, str2), s21_strpbrk(str, str2));
}
END_TEST

START_TEST(test_s21_strpbrk_2) {
  char str[20] = "1111111111";
  char str2[20] = "3333";
  ck_assert_ptr_eq(strpbrk(str, str2), s21_strpbrk(str, str2));
}
END_TEST

START_TEST(test_s21_strpbrk_3) {
  char str[20] = "1234567890";
  char str2[20] = "9566";
  ck_assert_ptr_eq(strpbrk(str, str2), s21_strpbrk(str, str2));
}
END_TEST

START_TEST(test_s21_strpbrk_4) {
  char str[20] = "fghjkuoip;lk";
  char str2[20] = ";1233";
  ck_assert_ptr_eq(strpbrk(str, str2), s21_strpbrk(str, str2));
}
END_TEST

START_TEST(test_s21_strpbrk_5) {
  char str[20] = "dsf    gfd";
  char str2[20] = "112345 542";
  ck_assert_ptr_eq(strpbrk(str, str2), s21_strpbrk(str, str2));
}
END_TEST

START_TEST(test_s21_strpbrk_6) {
  char str[20] = "hgfh\0gfdgd";
  char str2[20] = "1213\0mmmm";
  ck_assert_ptr_eq(strpbrk(str, str2), s21_strpbrk(str, str2));
}
END_TEST

START_TEST(test_s21_strspn_1) {
  char str[20] = "31hgfh\0gfdgd";
  char str2[20] = "121356\0mmmm";
  ck_assert_int_eq(s21_strspn(str, str2), strspn(str, str2));
}
END_TEST

START_TEST(test_s21_strspn_2) {
  char str[20] = "hgfh\0gfdgd";
  char str2[20] = "121356\0mmmm";
  ck_assert_int_eq(s21_strspn(str, str2), strspn(str, str2));
}
END_TEST

START_TEST(test_s21_strspn_3) {
  char str[20] = "";
  char str2[20] = "121356\0mmmm";
  ck_assert_int_eq(s21_strspn(str, str2), strspn(str, str2));
}
END_TEST

START_TEST(test_s21_strspn_4) {
  char str[20] = "31hgfh\0gfdgd";
  char str2[20] = "";
  ck_assert_int_eq(s21_strspn(str, str2), strspn(str, str2));
}
END_TEST

START_TEST(test_s21_strspn_5) {
  char str[20] = "312561\0gfdgd";
  char str2[20] = "121356\0mmmm";
  ck_assert_int_eq(s21_strspn(str, str2), strspn(str, str2));
}
END_TEST

START_TEST(test_s21_strspn_6) {
  char str[20] = "-31hgfh\0gfdgd";
  char str2[20] = "121356\0mmmm";
  ck_assert_int_eq(s21_strspn(str, str2), strspn(str, str2));
}
END_TEST

START_TEST(test_s21_strrchr_1) {
  char str[20] = "hgfh\0gfdgd";
  ck_assert_ptr_eq(strrchr(str, 'f'), s21_strrchr(str, 'f'));
}
END_TEST

START_TEST(test_s21_strrchr_2) {
  char str[20] = "hgfh\0gfdgd";
  ck_assert_ptr_eq(strrchr(str, '4'), s21_strrchr(str, '4'));
}
END_TEST

START_TEST(test_s21_strrchr_3) {
  char str[20] = "111111111111";
  ck_assert_ptr_eq(strrchr(str, '1'), s21_strrchr(str, '1'));
}
END_TEST

START_TEST(test_s21_strrchr_4) {
  char str[20] = "";
  ck_assert_ptr_eq(strrchr(str, 'f'), s21_strrchr(str, 'f'));
}
END_TEST

START_TEST(test_s21_strrchr_5) {
  char str[20] = "1 234567  89 0";
  ck_assert_ptr_eq(strrchr(str, ' '), s21_strrchr(str, ' '));
}
END_TEST

START_TEST(test_s21_strrchr_6) {
  char str[20] = "12345567789";
  ck_assert_ptr_eq(strrchr(str, '7'), s21_strrchr(str, '7'));
}
END_TEST

START_TEST(test_s21_strstr_1) {
  char haystack[20] = "hgfh\0gfdgd";
  char needle[20] = "1213\0mmmm";
  ck_assert_ptr_eq(strstr(haystack, needle), s21_strstr(haystack, needle));
}
END_TEST

START_TEST(test_s21_strstr_2) {
  char haystack[20] = "1234567890";
  char needle[20] = "890";
  ck_assert_ptr_eq(strstr(haystack, needle), s21_strstr(haystack, needle));
}
END_TEST

START_TEST(test_s21_strstr_3) {
  char haystack[20] = "12345\0 67890";
  char needle[20] = "45\0 67";
  ck_assert_ptr_eq(strstr(haystack, needle), s21_strstr(haystack, needle));
}
END_TEST

START_TEST(test_s21_strstr_4) {
  char haystack[20] = "1234567890";
  char needle[20] = "1234567890";
  ck_assert_ptr_eq(strstr(haystack, needle), s21_strstr(haystack, needle));
}
END_TEST

START_TEST(test_s21_strstr_5) {
  char haystack[20] = "";
  char needle[20] = "121";
  ck_assert_ptr_eq(strstr(haystack, needle), s21_strstr(haystack, needle));
}
END_TEST

START_TEST(test_s21_strstr_6) {
  char haystack[20] = " ";
  char needle[20] = " ";
  ck_assert_ptr_eq(strstr(haystack, needle), s21_strstr(haystack, needle));
}
END_TEST

Suite *s21_regular_suite_create(void) {
  Suite *suite = suite_create("regular string functions");
  TCase *tcase_memchr, *tcase_memcmp, *tcase_memcpy, *tcase_memset,
      *tcase_strchr, *tcase_strcspn, *tcase_strlen, *tcase_strcat,
      *tcase_strncat, *tcase_strncmp, *tcase_strncpy, *tcase_strpbrk,
      *tcase_strspn, *tcase_strrchr, *tcase_strstr, *tcase_strerror,
      *tcase_strtok;

  tcase_memchr = tcase_create("memchr");
  tcase_add_test(tcase_memchr, test_s21_memchr_1);
  tcase_add_test(tcase_memchr, test_s21_memchr_2);
  tcase_add_test(tcase_memchr, test_s21_memchr_3);
  tcase_add_test(tcase_memchr, test_s21_memchr_4);
  tcase_add_test(tcase_memchr, test_s21_memchr_5);
  tcase_add_test(tcase_memchr, test_s21_memchr_6);
  suite_add_tcase(suite, tcase_memchr);

  tcase_memcmp = tcase_create("memcmp");
  tcase_add_test(tcase_memcmp, test_s21_memcmp_1);
  tcase_add_test(tcase_memcmp, test_s21_memcmp_2);
  tcase_add_test(tcase_memcmp, test_s21_memcmp_3);
  tcase_add_test(tcase_memcmp, test_s21_memcmp_4);
  tcase_add_test(tcase_memcmp, test_s21_memcmp_5);
  tcase_add_test(tcase_memcmp, test_s21_memcmp_6);
  suite_add_tcase(suite, tcase_memcmp);

  tcase_memcpy = tcase_create("memcpy");
  tcase_add_test(tcase_memcpy, test_s21_memcpy_1);
  tcase_add_test(tcase_memcpy, test_s21_memcpy_2);
  tcase_add_test(tcase_memcpy, test_s21_memcpy_3);
  tcase_add_test(tcase_memcpy, test_s21_memcpy_4);
  tcase_add_test(tcase_memcpy, test_s21_memcpy_5);
  tcase_add_test(tcase_memcpy, test_s21_memcpy_6);
  suite_add_tcase(suite, tcase_memcpy);

  tcase_memset = tcase_create("memset");
  tcase_add_test(tcase_memset, test_s21_memset_1);
  tcase_add_test(tcase_memset, test_s21_memset_2);
  tcase_add_test(tcase_memset, test_s21_memset_3);
  tcase_add_test(tcase_memset, test_s21_memset_4);
  tcase_add_test(tcase_memset, test_s21_memset_5);
  tcase_add_test(tcase_memset, test_s21_memset_6);
  suite_add_tcase(suite, tcase_memset);

  tcase_strchr = tcase_create("strchr");
  tcase_add_test(tcase_strchr, test_s21_strchr_1);
  tcase_add_test(tcase_strchr, test_s21_strchr_2);
  tcase_add_test(tcase_strchr, test_s21_strchr_3);
  tcase_add_test(tcase_strchr, test_s21_strchr_4);
  tcase_add_test(tcase_strchr, test_s21_strchr_5);
  tcase_add_test(tcase_strchr, test_s21_strchr_6);
  suite_add_tcase(suite, tcase_strchr);

  tcase_strcspn = tcase_create("strcspn");
  tcase_add_test(tcase_strcspn, test_s21_strcspn_1);
  tcase_add_test(tcase_strcspn, test_s21_strcspn_2);
  tcase_add_test(tcase_strcspn, test_s21_strcspn_3);
  tcase_add_test(tcase_strcspn, test_s21_strcspn_4);
  tcase_add_test(tcase_strcspn, test_s21_strcspn_5);
  suite_add_tcase(suite, tcase_strcspn);

  tcase_strlen = tcase_create("strlen");
  tcase_add_test(tcase_strlen, test_s21_strlen_1);
  tcase_add_test(tcase_strlen, test_s21_strlen_2);
  tcase_add_test(tcase_strlen, test_s21_strlen_3);
  tcase_add_test(tcase_strlen, test_s21_strlen_4);
  tcase_add_test(tcase_strlen, test_s21_strlen_5);
  tcase_add_test(tcase_strlen, test_s21_strlen_6);
  suite_add_tcase(suite, tcase_strlen);

  tcase_strcat = tcase_create("strcat");
  tcase_add_test(tcase_strcat, test_s21_strcat_1);
  tcase_add_test(tcase_strcat, test_s21_strcat_2);
  tcase_add_test(tcase_strcat, test_s21_strcat_3);
  tcase_add_test(tcase_strcat, test_s21_strcat_4);
  tcase_add_test(tcase_strcat, test_s21_strcat_5);
  tcase_add_test(tcase_strcat, test_s21_strcat_6);
  suite_add_tcase(suite, tcase_strcat);

  tcase_strncat = tcase_create("strncat");
  tcase_add_test(tcase_strncat, test_s21_strncat_1);
  tcase_add_test(tcase_strncat, test_s21_strncat_2);
  tcase_add_test(tcase_strncat, test_s21_strncat_3);
  tcase_add_test(tcase_strncat, test_s21_strncat_4);
  tcase_add_test(tcase_strncat, test_s21_strncat_5);
  tcase_add_test(tcase_strncat, test_s21_strncat_6);
  suite_add_tcase(suite, tcase_strncat);

  tcase_strncmp = tcase_create("strncmp");
  tcase_add_test(tcase_strncmp, test_s21_strncmp_1);
  tcase_add_test(tcase_strncmp, test_s21_strncmp_2);
  tcase_add_test(tcase_strncmp, test_s21_strncmp_3);
  tcase_add_test(tcase_strncmp, test_s21_strncmp_4);
  tcase_add_test(tcase_strncmp, test_s21_strncmp_5);
  suite_add_tcase(suite, tcase_strncmp);

  tcase_strncpy = tcase_create("strncpy");
  tcase_add_test(tcase_strncpy, test_s21_strncpy_1);
  tcase_add_test(tcase_strncpy, test_s21_strncpy_2);
  tcase_add_test(tcase_strncpy, test_s21_strncpy_3);
  tcase_add_test(tcase_strncpy, test_s21_strncpy_4);
  tcase_add_test(tcase_strncpy, test_s21_strncpy_5);
  tcase_add_test(tcase_strncpy, test_s21_strncpy_6);
  suite_add_tcase(suite, tcase_strncpy);

  tcase_strpbrk = tcase_create("strpbrk");
  tcase_add_test(tcase_strpbrk, test_s21_strpbrk_1);
  tcase_add_test(tcase_strpbrk, test_s21_strpbrk_2);
  tcase_add_test(tcase_strpbrk, test_s21_strpbrk_3);
  tcase_add_test(tcase_strpbrk, test_s21_strpbrk_4);
  tcase_add_test(tcase_strpbrk, test_s21_strpbrk_5);
  tcase_add_test(tcase_strpbrk, test_s21_strpbrk_6);
  suite_add_tcase(suite, tcase_strpbrk);

  tcase_strspn = tcase_create("strpbrk");
  tcase_add_test(tcase_strspn, test_s21_strspn_1);
  tcase_add_test(tcase_strspn, test_s21_strspn_2);
  tcase_add_test(tcase_strspn, test_s21_strspn_3);
  tcase_add_test(tcase_strspn, test_s21_strspn_4);
  tcase_add_test(tcase_strspn, test_s21_strspn_5);
  tcase_add_test(tcase_strspn, test_s21_strspn_6);
  suite_add_tcase(suite, tcase_strspn);

  tcase_strerror = tcase_create("strerror");
  tcase_add_test(tcase_strerror, test_s21_strerror_1);
  tcase_add_test(tcase_strerror, test_s21_strerror_2);
  tcase_add_test(tcase_strerror, test_s21_strerror_3);
  tcase_add_test(tcase_strerror, test_s21_strerror_4);
  tcase_add_test(tcase_strerror, test_s21_strerror_5);
  tcase_add_test(tcase_strerror, test_s21_strerror_6);
  tcase_add_test(tcase_strerror, test_s21_strerror_7);
  tcase_add_test(tcase_strerror, test_s21_strerror_8);
  tcase_add_test(tcase_strerror, test_s21_strerror_9);
  tcase_add_test(tcase_strerror, test_s21_strerror_10);
  tcase_add_test(tcase_strerror, test_s21_strerror_11);
  tcase_add_test(tcase_strerror, test_s21_strerror_12);
  suite_add_tcase(suite, tcase_strerror);

  tcase_strtok = tcase_create("strtok");
  tcase_add_test(tcase_strtok, test_s21_strtok_1);
  tcase_add_test(tcase_strtok, test_s21_strtok_2);
  tcase_add_test(tcase_strtok, test_s21_strtok_3);
  tcase_add_test(tcase_strtok, test_s21_strtok_4);
  tcase_add_test(tcase_strtok, test_s21_strtok_5);
  tcase_add_test(tcase_strtok, test_s21_strtok_6);
  tcase_add_test(tcase_strtok, test_s21_strtok_7);
  suite_add_tcase(suite, tcase_strtok);

  tcase_strrchr = tcase_create("strrchr");
  tcase_add_test(tcase_strrchr, test_s21_strrchr_1);
  tcase_add_test(tcase_strrchr, test_s21_strrchr_2);
  tcase_add_test(tcase_strrchr, test_s21_strrchr_3);
  tcase_add_test(tcase_strrchr, test_s21_strrchr_4);
  tcase_add_test(tcase_strrchr, test_s21_strrchr_5);
  tcase_add_test(tcase_strrchr, test_s21_strrchr_6);
  suite_add_tcase(suite, tcase_strrchr);

  tcase_strstr = tcase_create("strstr");
  tcase_add_test(tcase_strstr, test_s21_strstr_1);
  tcase_add_test(tcase_strstr, test_s21_strstr_2);
  tcase_add_test(tcase_strstr, test_s21_strstr_3);
  tcase_add_test(tcase_strstr, test_s21_strstr_4);
  tcase_add_test(tcase_strstr, test_s21_strstr_5);
  tcase_add_test(tcase_strstr, test_s21_strstr_6);
  suite_add_tcase(suite, tcase_strstr);

  return suite;
}

int test_regular(void) {
  int no_failed = 0;

  Suite *suite = s21_regular_suite_create();
  SRunner *suite_runner = srunner_create(suite);

  srunner_set_fork_status(suite_runner, CK_NOFORK);
  srunner_run_all(suite_runner, CK_NORMAL);
  no_failed = srunner_ntests_failed(suite_runner);
  srunner_free(suite_runner);

  return no_failed;
}