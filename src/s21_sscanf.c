#include "s21_sscanf.h"

#include <stdio.h>
#include <stdlib.h>

#include "s21_string.h"
#include "s21_utils.h"

// %[*][ширина][длина]спецификатор
int s21_sscanf(const char *str, const char *format, ...) {
  int error = 0, count = 0, is_finished = 0;
  va_list ap;
  char *needle_str = (char *)str;
  char *start = needle_str;
  char *needle_format = (char *)format;

  va_start(ap, format);
  while (!is_finished) {
    format_token token = {0};
    token =
        format_token_parse(&needle_str, &needle_format, &error, &is_finished);
    if (!is_finished) {
      error = write_token(&needle_str, token, start, ap);
      if (!error) {
        if (token.spec != 'n' && token.suppress != 1) {
          count++;
        }
      } else {
        is_finished = 1;
      }
    }
  }
  va_end(ap);
  if (error && count == 0) count = EOF;
  return count;
}

format_token format_token_parse(char **str, char **format, int *error,
                                int *is_finished) {
  int i = 0;
  int len = s21_strlen(*format);

  format_token token = {0};
  while (i < len && **format && **format != '%') {
    while (i < len && **format == **str) {
      (*format)++;
      (*str)++;
      i++;
    }
    while (i < len && is_space(**format)) {
      (*format)++;
      i++;
    }
    if (i < len && **format == '%') {
      break;
    }
    if (i >= len || **format != **str) {
      *is_finished = 1;
      break;
    }
  }
  if (!(*is_finished) && **format == '%') {
    (*format)++;
    parse_format_suppress(format, &token);
    *error = parse_format_width(format, &token);
    parse_format_length(format, &token);
    parse_format_spec(format, &token);
  } else {
    *is_finished = 1;
  }
  if (!token.spec) *is_finished = 1;
  return token;
}

void parse_format_suppress(char **format, format_token *token) {
  if ((char)**format == '*') {
    token->suppress = 1;
    (*format)++;
  }
}
int parse_format_width(char **format, format_token *token) {
  int error = 0;
  if (is_decimal(**format)) {
    int width = (int)parse_decimal(format, 0, &error);
    if (width > 0) {
      token->width = width;
    } else {
      error = 1;
    }
  }
  return error;
}
void parse_format_length(char **format, format_token *token) {
  switch (**format) {
    case 'h':
      token->lenght = 'h';
      (*format)++;
      break;
    case 'l':
      token->lenght = 'l';
      (*format)++;
      break;
    case 'L':
      token->lenght = 'L';
      (*format)++;
      break;
    default:
      break;
  }
}
void parse_format_spec(char **format, format_token *token) {
  while (**format && is_space(**format)) {
    (*format)++;
  }
  token->spec = (**format);
  (*format)++;
}

int write_token(char **needle_str, format_token token, char *start,
                va_list ap) {
  int error = 0;
  switch (token.spec) {
    case 'c':
      error = write_char_into_arg(needle_str, token, ap);
      break;
    case 's':
      error = write_string_into_arg(needle_str, token, ap, &parse_string);
      break;
    case 'd':
      error = write_signed_into_arg(needle_str, token, ap, &parse_decimal);
      break;
    case 'i':
      error = write_signed_into_arg(needle_str, token, ap, &parse_unspec);
      break;
    case 'u':
      error = write_unsigned_into_arg(needle_str, token, ap,
                                      &parse_unsigned_decimal);
      break;
    case 'o':
      error =
          write_unsigned_into_arg(needle_str, token, ap, &parse_unsigned_octal);
      break;
    case 'x':
      error = write_unsigned_into_arg(needle_str, token, ap,
                                      &parse_unsigned_hexadecimal);
      break;
    case 'X':
      error = write_unsigned_into_arg(needle_str, token, ap,
                                      &parse_unsigned_hexadecimal);
      break;
    case 'p':
      error = write_unsigned_into_arg(needle_str, token, ap,
                                      &parse_unsigned_hexadecimal);
      break;
    case 'e':
      error = write_float_to_arg(needle_str, token, ap, &parse_double);
      break;
    case 'E':
      error = write_float_to_arg(needle_str, token, ap, &parse_double);
      break;
    case 'f':
      error = write_float_to_arg(needle_str, token, ap, &parse_double);
      break;
    case 'g':
      error = write_float_to_arg(needle_str, token, ap, &parse_double);
      break;
    case 'G':
      error = write_float_to_arg(needle_str, token, ap, &parse_double);
      break;
    case 'n':
      *va_arg(ap, int *) = *needle_str - start;
      break;
    default:
      error = 1;
      break;
  }
  return error;
}

int write_char_into_arg(char **needle_str, format_token token, va_list ap) {
  int error = 0;
  if (**needle_str) {
    if (!token.suppress) *va_arg(ap, char *) = (**needle_str);
    (*needle_str)++;
  } else {
    error = 1;
  }
  return error;
}

int write_string_into_arg(char **needle_str, format_token token, va_list ap,
                          char *(*parse)(char **, int, int *)) {
  int error = 0;
  int width = token.width;

  while (**needle_str && **needle_str == ' ') {
    (*needle_str)++;
  }
  if (**needle_str) {
    if (!token.suppress) {
      switch (token.lenght) {
        default: {
          char *result = parse(needle_str, width, &error);
          s21_strcpy(va_arg(ap, char *), result);
          free(result);
          break;
        }
      }
    } else {
      char *result = parse(needle_str, width, &error);
      free(result);
    }
  } else {
    error = 1;
  }
  return error;
}

int write_signed_into_arg(char **needle_str, format_token token, va_list ap,
                          long (*parse)(char **, int, int *)) {
  int error = 0;
  int width = token.width;

  while (**needle_str && **needle_str == ' ') {
    (*needle_str)++;
  }
  if (**needle_str) {
    if (!token.suppress) {
      switch (token.lenght) {
        case 'h': {
          *va_arg(ap, short *) = (short)parse(needle_str, width, &error);
          break;
        }
        case 'l': {
          *va_arg(ap, long int *) = (long int)parse(needle_str, width, &error);
          break;
        }
        default: {
          *va_arg(ap, int *) = (int)parse(needle_str, width, &error);
          break;
        }
      }
    } else {
      parse(needle_str, width, &error);
    }
  } else {
    error = 1;
  }
  return error;
}

int write_unsigned_into_arg(char **needle_str, format_token token, va_list ap,
                            unsigned long (*parse)(char **, int, int *)) {
  int error = 0;
  int width = token.width;

  while (**needle_str && **needle_str == ' ') {
    (*needle_str)++;
  }
  if (**needle_str) {
    if (!token.suppress) {
      switch (token.lenght) {
        case 'h': {
          *va_arg(ap, unsigned short *) =
              (unsigned short)parse(needle_str, width, &error);
          break;
        }
        case 'l': {
          *va_arg(ap, unsigned long int *) =
              (unsigned long)parse(needle_str, width, &error);
          break;
        }
        default: {
          *va_arg(ap, unsigned int *) =
              (unsigned int)parse(needle_str, width, &error);
          break;
        }
      }
    } else {
      parse(needle_str, width, &error);
    }
  } else {
    error = 1;
  }
  return error;
}

int write_float_to_arg(char **needle_str, format_token token, va_list ap,
                       long double (*parse)(char **, int, int *)) {
  int error = 0;
  int width = token.width;

  while (**needle_str && **needle_str == ' ') {
    (*needle_str)++;
  }
  if (**needle_str) {
    if (!token.suppress) {
      switch (token.lenght) {
        case 'l': {
          *va_arg(ap, double *) = (double)parse(needle_str, width, &error);
          break;
        }
        case 'L': {
          *va_arg(ap, long double *) =
              (long double)parse(needle_str, width, &error);
          break;
        }
        default: {
          *va_arg(ap, float *) = (float)parse(needle_str, width, &error);
          break;
        }
      }
    } else {
      parse(needle_str, width, &error);
    }
  } else {
    error = 1;
  }
  return error;
}
