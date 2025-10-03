#include "s21_string.h"

char *s21_strcat(char *dest, const char *src) {
  s21_size_t len = s21_strlen(dest);
  for (s21_size_t i = 0; src[i] != '\0'; i++) {
    dest[len + i] = src[i];
  }
  dest[len + s21_strlen(src)] = '\0';
  return dest;
}

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  s21_size_t dest_len = s21_strlen(dest);
  s21_size_t i = 0;
  for (; src[i] != '\0' && i < n; i++) {
    dest[dest_len + i] = src[i];
  }
  dest[dest_len + i] = '\0';
  return dest;
}

char *s21_strchr(const char *dest, int target) {
  char *result = S21_NULL;
  while (*dest != target && *dest != '\0') {
    dest++;
  }
  if (*dest == target) {
    result = (char *)dest;
  }
  return result;
}

int s21_strcmp(const char *str1, const char *str2) {
  int result = 0;
  while (*str1 == *str2 && *str1 != '\0') {
    str1++;
    str2++;
  }
  if (*str1 != *str2) {
    result = *str1 - *str2;
  }
  return result;
}

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  int result = 0;
  if (str1 && str2 && n > 0) {
    for (s21_size_t i = 0; i < n; i++) {
      if (str1[i] == '\0' || str1[i] != str2[i]) {
        result = str1[i] - str2[i];
        break;
      }
    }
  }
  return result;
}

char *s21_strcpy(char *dest, const char *src) {
  char *current = dest;
  while (*src != '\0') {
    *current = *src;
    current++;
    src++;
  }
  *current = '\0';
  return dest;
}

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t result = 0;
  while (str1[result] && !s21_strchr(str2, str1[result])) {
    result++;
  }
  return result;
}

s21_size_t s21_strlen(const char *str) {
  s21_size_t result = 0;
  const char *pointer = str;
  while (*pointer != '\0') {
    pointer++;
  }
  result = (s21_size_t)(pointer - str);
  return result;
}

char *s21_strpbrk(const char *str1, const char *str2) {
  char *result = S21_NULL;
  while (*str1 && result == S21_NULL) {
    if (s21_strchr(str2, *str1)) {
      result = (char *)str1;
    } else {
      str1++;
    }
  }
  return result;
}

char *s21_strrchr(const char *str, int c) {
  char *result = S21_NULL;
  while (*str != '\0') {
    if (*str == c) {
      result = (char *)str;
    }
    str++;
  }
  return result;
}

s21_size_t s21_strspn(const char *str1, const char *str2) {
  char *runner = (char *)str1;
  s21_size_t result = 0;
  while (*runner && s21_strchr(str2, *runner) != S21_NULL) {
    runner++;
    result++;
  }
  return result;
}

char *s21_strstr(const char *dest, const char *target) {
  char *result = S21_NULL;
  if (s21_strlen(target) == 0) {
    result = (char *)dest;
  } else {
    while (*dest != '\0') {
      if ((*dest == *target) && s21_strcmp(dest, target) == 0) {
        result = (char *)dest;
        break;
      }
      dest++;
    }
  }
  return result;
}

char *s21_strtok(char *src, const char *delim) {
  static char *buff;
  int is_finished = 0;
  char *result = S21_NULL;
  if (!src) {
    src = buff;
  }
  if (!src) {
    is_finished = 1;
  }
  while (!is_finished) {
    if (s21_strchr((char *)delim, *src)) {
      src++;
      continue;
    }
    if (*src == '\0') {
      is_finished = 1;
    }
    break;
  }
  if (!is_finished) {
    result = src;
    while (!is_finished) {
      if (*src == '\0') {
        buff = src;
        is_finished = 1;
      }
      if (s21_strchr((char *)delim, *src) && !is_finished) {
        *src = '\0';
        buff = src + 1;
        is_finished = 1;
      }
      if (!is_finished) {
        src++;
      }
    }
  }
  return result;
}
