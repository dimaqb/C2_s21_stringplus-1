#include "s21_strerror.h"

#include "s21_string.h"

char *s21_strerror(int errnum) {
  static char buffer[100];
  if (errnum < 0 || errnum > MAX_ERROR_NUM) {
    s21_sprintf(buffer, "%s %d", UNKNOWN_ERROR, errnum);
  } else {
    s21_strcpy(buffer, errors_text[errnum]);
  }
  return buffer;
}