#include "s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  const unsigned char *ptr = str;
  void *result = S21_NULL;
  for (s21_size_t i = 0; i < n; i++) {
    if (*ptr == (unsigned char)c) {
      result = (void *)ptr;
      break;
    }
    ptr++;
  }
  return result;
}

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  const unsigned char *str1_p = str1, *str2_p = str2;
  int result = 0;
  for (s21_size_t i = 0; i < n; i++) {
    if (*str1_p != *str2_p) {
      result = *str1_p - *str2_p;
      break;
    }
    str1_p++;
    str2_p++;
  }
  return result;
}

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  unsigned char *dest_p = (unsigned char *)dest;
  const unsigned char *src_p = (const unsigned char *)src;

  for (s21_size_t i = 0; i < n; i++) {
    *dest_p++ = *src_p++;
  }
  return dest;
}

void *s21_memset(void *str, int c, s21_size_t n) {
  unsigned char *str_p = str;
  for (s21_size_t i = 0; i < n; i++) {
    *str_p++ = (unsigned char)c;
  }
  return str_p;
}

s21_size_t s21_strnlen(const char *str, s21_size_t n) {
  const char *first_null = s21_memchr(str, '\0', n);
  return first_null ? (s21_size_t)(first_null - str) : n;
}

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  s21_size_t len = s21_strnlen(src, n);
  return s21_memset(s21_memcpy(dest, src, len) + len, 0, n - len) - len;
}