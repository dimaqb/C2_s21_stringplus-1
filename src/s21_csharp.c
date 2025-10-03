#include "s21_string.h"

void *s21_to_upper(const char *str) {
  char *result = S21_NULL;
  s21_size_t len = s21_strlen(str);
  result = malloc((len + 1) * sizeof(char));

  if (result) {
    for (s21_size_t i = 0; i < len; i++) {
      if (str[i] >= 'a' && str[i] <= 'z') {
        result[i] = (char)(str[i] - 32);
      } else {
        result[i] = str[i];
      }
    }
    result[len] = '\0';
  }
  return result;
}
void *s21_to_lower(const char *str) {
  char *result = S21_NULL;
  s21_size_t len = s21_strlen(str);
  result = malloc((len + 1) * sizeof(char));

  if (result) {
    for (s21_size_t i = 0; i < len; i++) {
      if (str[i] >= 'A' && str[i] <= 'Z') {
        result[i] = (char)(str[i] + 32);
      } else {
        result[i] = str[i];
      }
    }
    result[len] = '\0';
  }
  return result;
}

void *s21_insert(const char *src, const char *str, size_t start_index) {
  s21_size_t len_src = s21_strlen(src);
  s21_size_t len_str = s21_strlen(str);
  char *result = S21_NULL;
  int error = 0;

  if (start_index > len_src) {
    error = 1;
  }
  if (!error) {
    result = calloc((len_src + len_str + 1), sizeof(char));
    if (result == S21_NULL) {
      error = 1;
    } else {
      s21_memcpy(result, src, start_index);
      s21_memcpy(result + start_index, str, len_str);
      s21_memcpy(result + start_index + len_str, src + start_index,
                 len_src - start_index);
    }
  }
  return result;
}

void *s21_trim(const char *src, const char *trim_chars) {
  char *left = (char *)s21_trim_left(src, trim_chars);
  void *result;
  if (left != S21_NULL) {
    result = (char *)s21_trim_right(left, trim_chars);
  } else {
    result = S21_NULL;
  }
  return result;
}

void *s21_trim_left(const char *src, const char *trim_chars) {
  char *result = (char *)src;
  char *src_end = (char *)src + s21_strlen(src);
  if (result) {
    if (trim_chars == S21_NULL) {
      trim_chars = " ";
    }
    while (s21_strchr(trim_chars, *result) && (result != src_end)) {
      result++;
    }
  }
  if (*result == *src_end) {
    result = "\0";
  }
  return result;
}

void *s21_trim_right(const char *src, const char *trim_chars) {
  char *result = S21_NULL;
  char *src_start = (char *)src;
  char *runner = (char *)src + s21_strlen(src) - 1;

  if (runner) {
    if (trim_chars == S21_NULL) {
      trim_chars = " ";
    }
    while (s21_strchr(trim_chars, *runner) && s21_strcmp(runner, src_start)) {
      runner--;
    }
  }
  if (s21_strcmp(runner, src_start) == 0) {
    result = calloc(1, sizeof(char));
    result[0] = '\0';
  } else {
    result = calloc(runner - src_start + 2, sizeof(char));
    if (result) {
      s21_strncpy(result, src_start, runner - src_start + 1);
    } else {
      result = S21_NULL;
    }
  }
  return result;
}
