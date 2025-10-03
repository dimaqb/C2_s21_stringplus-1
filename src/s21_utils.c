#include "s21_utils.h"

#include <stdio.h>
#include <stdlib.h>

#include "s21_string.h"

int is_space(char ch) { return (ch == ' '); }
int is_point(char ch) { return (ch == '.'); }
int is_char(char ch) { return (ch != EOF && ch != '\0' && ch != ' '); }
int is_sign(char ch) { return (ch == '+' || ch == '-'); }

int is_decimal(char ch) { return (ch >= '0' && ch <= '9'); }
int is_octal(char ch) { return (ch >= '0' && ch <= '7'); }
int is_hex(char ch) {
  return ((ch >= 'a' && ch <= 'f') || (ch >= 'A' && ch <= 'F') || ch == 'x' ||
          ch == 'X');
}
int is_hexadecimal(char ch) { return (is_decimal(ch) || is_hex(ch)); }

int is_exponent(char ch) { return (ch == 'e' || ch == 'E'); }
int hexadecimal_to_int(char ch) {
  int result = 0;
  if (is_hex(ch)) {
    result = hex_to_int(ch);
  }
  if (is_decimal(ch)) {
    result = ch - '0';
  }
  return result;
}
int hex_to_int(char ch) {
  int result = 0;
  switch (ch) {
    case 'a':
      result = 10;
      break;
    case 'b':
      result = 11;
      break;
    case 'c':
      result = 12;
      break;
    case 'd':
      result = 13;
      break;
    case 'e':
      result = 14;
      break;
    case 'f':
      result = 15;
      break;
    case 'A':
      result = 10;
      break;
    case 'B':
      result = 11;
      break;
    case 'C':
      result = 12;
      break;
    case 'D':
      result = 13;
      break;
    case 'E':
      result = 14;
      break;
    case 'F':
      result = 15;
      break;
    default:
      break;
  }
  return result;
}

int read_token_from_string(char **buffer, char **string, int width,
                           int (*is_correct_char)(char)) {
  int error = 0;
  int is_read = 0;
  int length = 0;

  init_buffer(buffer, 0, &error);

  if (!error && **string && is_sign(**string)) {
    length++;
    write_to_buffer(buffer, length, **string, &error);
    if (!error) {
      (*string)++;
      is_read = 1;
    }
  }
  if (!error) {
    while (is_within_borders(length, width) && is_correct_char(**string)) {
      length++;
      write_to_buffer(buffer, length, **string, &error);
      if (!error) {
        (*string)++;
        is_read = 1;
      }
    }
  }
  if (is_read == 0) {
    error = 1;
    free(buffer);
  }
  if (!error) {
    write_to_buffer(buffer, length + 1, '\0', &error);
  }
  return error;
}

char *parse_string(char **string, int width, int *error) {
  char *buffer = S21_NULL;
  *error = read_token_from_string(&buffer, string, width, &is_char);
  if (buffer == S21_NULL) {
    *error = 1;
  } else {
    int len = s21_strlen(buffer);
    if (buffer[len - 1] == EOF || buffer[len - 1] == '\n') {
      buffer[len - 1] = '\0';
    }
  }
  return buffer;
}
long int parse_decimal(char **string, int width, int *error) {
  long result = 0;
  char *buffer = S21_NULL;
  *error = read_token_from_string(&buffer, string, width, &is_decimal);
  if (buffer != S21_NULL) {
    result = s21_atoi(buffer, error);
    free(buffer);
  } else {
    *error = 1;
  }
  return result;
}
long int s21_atoi(const char *str, int *error) {
  long int value = 0;
  int sign = 1;
  const char *runner = str;
  if (runner != S21_NULL) {
    if (*runner == '-') {
      sign = -1;
      runner++;
    } else if (*runner == '+') {
      sign = 1;
      runner++;
    }
    if (!is_decimal(*runner)) {
      *error = 1;
    }
    while (is_decimal(*runner)) {
      value = 10 * value + *runner - 48;
      runner++;
    }
  }
  return value * sign;
}

unsigned long int parse_unsigned_decimal(char **string, int width, int *error) {
  unsigned long int result = 0;
  char *buffer = S21_NULL;
  *error = read_token_from_string(&buffer, string, width, &is_decimal);
  if (buffer != S21_NULL) {
    result = s21_unsigned_atoi(buffer, error);
    free(buffer);
  } else {
    *error = 1;
  }
  return result;
}
unsigned long int s21_unsigned_atoi(const char *str, int *error) {
  unsigned long int value = 0;
  int invert = 0;
  const char *runner = str;
  if (*runner == '-') {
    invert = 1;
    runner++;
  } else if (*runner == '+') {
    runner++;
  }
  if (!is_decimal(*runner)) {
    *error = 1;
  }
  while (is_decimal(*runner)) {
    value = 10 * value + *runner - 48;
    runner++;
  }
  if (invert) {
    value = 0 - value;
  }
  return value;
}

unsigned long int parse_unsigned_octal(char **string, int width, int *error) {
  unsigned long int result = 0;
  char *buffer = S21_NULL;
  *error = read_token_from_string(&buffer, string, width, &is_octal);
  if (buffer != S21_NULL) {
    result = s21_unsigned_octal_atoi(buffer, error);
    free(buffer);
  } else {
    *error = 1;
  }
  return result;
}
unsigned long int s21_unsigned_octal_atoi(const char *str, int *error) {
  unsigned long int value = 0;
  int invert = 0;
  const char *runner = str;
  if (*runner == '-') {
    invert = 1;
    runner++;
  } else if (*runner == '+') {
    runner++;
  }
  if (!is_octal(*runner)) {
    *error = 1;
  }
  while (is_octal(*runner)) {
    value = 8 * value + *runner - 48;
    runner++;
  }
  if (invert) {
    value = 0 - value;
  }
  return value;
}

unsigned long int parse_unsigned_hexadecimal(char **string, int width,
                                             int *error) {
  unsigned long int result = 0;
  char *buffer = S21_NULL;
  *error = read_token_from_string(&buffer, string, width, &is_hexadecimal);
  if (buffer != S21_NULL) {
    result = s21_unsigned_hexadecimal_atoi(buffer, error);

    free(buffer);
  } else {
    *error = 1;
  }
  return result;
}
unsigned long int s21_unsigned_hexadecimal_atoi(const char *str, int *error) {
  unsigned long int value = 0;
  int is_number = 0;
  int invert = 0;
  const char *runner = str;
  if (*runner == '-') {
    invert = 1;
    runner++;
  } else if (*runner == '+') {
    runner++;
  }
  if (*runner == '0') {
    is_number = 1;
    runner++;
  }
  if (*runner == 'x' || *runner == 'X') {
    runner++;
  }
  if (!is_hexadecimal(*runner) && !is_number) {
    *error = 1;
  }
  while ((is_hexadecimal(*runner))) {
    value = 16 * value + (unsigned long)hexadecimal_to_int(*runner);
    runner++;
  }
  if (invert) {
    value = 0 - value;
  }
  return value;
}

long parse_unspec(char **string, int width, int *error) {
  char *buffer = S21_NULL;
  long int result = 0;
  long int sign = 1;

  if (**string == '-') {
    sign = -1;
    (*string)++;
  } else if (**string == '+') {
    (*string)++;
  }
  if (**string == '0') {
    (*string)++;
    if (**string == 'x' || **string == 'X') {
      (*string)++;
      *error = read_token_from_string(&buffer, string, width, &is_hexadecimal);
      if (buffer != S21_NULL) {
        result = s21_hexadecimal_atoi(buffer, error);
        free(buffer);
      } else {
        *error = 1;
      }
    } else {
      *error = read_token_from_string(&buffer, string, width, &is_decimal);
      if (buffer != S21_NULL) {
        result = s21_octal_atoi(buffer, error);
        free(buffer);
      } else {
        *error = 1;
      }
    }
  } else if (is_decimal(**string)) {
    *error = read_token_from_string(&buffer, string, width, &is_octal);
    if (buffer != S21_NULL) {
      result = s21_atoi(buffer, error);
      free(buffer);
    } else {
      *error = 1;
    }
  } else {
    *error = 1;
  }
  return result * sign;
}
long int s21_octal_atoi(const char *str, int *error) {
  long int value = 0;
  int sign = 1;
  const char *runner = str;
  if (!is_octal(*runner)) {
    *error = 1;
  }
  while (is_octal(*runner)) {
    value = 8 * value + *runner - 48;
    runner++;
  }
  return value * sign;
}

long int s21_hexadecimal_atoi(const char *str, int *error) {
  long int value = 0;
  int sign = 1;
  int is_number = 0;
  const char *runner = str;
  if (!is_hexadecimal(*runner) && !is_number) {
    *error = 1;
  }
  while (is_hexadecimal(*runner)) {
    value = 16 * value + hexadecimal_to_int(*runner);
    runner++;
  }
  return value * sign;
}

long double parse_double(char **string, int width, int *error) {
  long double result = 0;
  char *buffer = S21_NULL;
  *error = read_double_from_string(&buffer, string, width);
  if (buffer != S21_NULL) {
    result = s21_atof(buffer);
    free(buffer);
  } else {
    *error = 1;
  }
  return result;
}

int read_double_from_string(char **buffer, char **string, int width) {
  int error = 0;
  int length = 0;
  int is_finished = 0;
  init_buffer(buffer, 0, &error);

  // Reading sign of mantissa
  if (is_within_borders(length, width) && is_sign(**string)) {
    length++;
    write_to_buffer(buffer, length, **string, &error);
    if (!error) (*string)++;
  }

  // Reading mantissa
  while (!error && is_within_borders(length, width) && **string &&
         (is_point(**string) || is_decimal(**string))) {
    if (is_point(**string)) {
      if (is_finished == 1) {
        break;
      } else {
        is_finished = 1;
      }
    }
    length++;
    write_to_buffer(buffer, length, **string, &error);
    if (!error) {
      (*string)++;
    } else {
      break;
    }
  }
  // Reading exponent
  if (!error && is_within_borders(length, width) && **string &&
      (**string == 'e' || **string == 'E')) {
    length++;
    write_to_buffer(buffer, length, **string, &error);
    if (!error) {
      (*string)++;
    } else {
      error = 1;
    }
  }
  // Reading sign of exponent
  if (!error && is_within_borders(length, width) && **string &&
      is_sign(**string)) {
    length++;
    write_to_buffer(buffer, length, **string, &error);
    if (!error) {
      (*string)++;
    } else {
      error = 1;
    }
  }
  // Reading exponent
  while (!error && is_within_borders(length, width) && **string &&
         is_decimal(**string)) {
    length++;
    write_to_buffer(buffer, length, **string, &error);
    if (!error) {
      (*string)++;
    } else {
      error = 1;
      break;
    }
  }
  // Null terminator
  if (!error) write_to_buffer(buffer, length + 1, '\0', &error);
  return error;
}

/* 1 bit sign || 11 bit exponent || 52 bit fraction || = 64 bit */
/**
 * "-I.FE-X" where I is the integer part of the mantissa, F is the fractional
 * part of the mantissa, and X is the exponent.
 */
double s21_atof(const char *string) {
  int sign = 1, exponent_sign = 1;
  int is_finished = 0;
  double fraction = 0;
  int exp_power = 0;
  int frac_exp_power = 0;
  int mantissa_size;
  int max_exponent = 511;
  int digits_before_decimal_point;
  const char *runner = string;
  const char *pointer_exponent;
  double powersOf10[] = {10.,    100.,   1.0e4,   1.0e8,  1.0e16,
                         1.0e32, 1.0e64, 1.0e128, 1.0e256};

  while (is_space(*runner)) {
    runner++;
  }
  if (*runner == '-') {
    sign = -1;
    runner++;
  } else {
    if (*runner == '+') {
      sign = 1;
      runner++;
    }
  }

  digits_before_decimal_point = -1;
  for (mantissa_size = 0;; mantissa_size++) {
    if (!is_decimal(*runner)) {
      if ((!is_point(*runner)) || (digits_before_decimal_point >= 0)) {
        break;
      }
      digits_before_decimal_point = mantissa_size;
    }
    runner++;
  }

  pointer_exponent = runner;
  runner -= mantissa_size;
  if (digits_before_decimal_point < 0) {
    digits_before_decimal_point = mantissa_size;
  } else {
    mantissa_size -= 1;
  }
  if (mantissa_size > 18) {
    frac_exp_power = digits_before_decimal_point - 18;
    mantissa_size = 18;
  } else {
    frac_exp_power = digits_before_decimal_point - mantissa_size;
  }
  if (mantissa_size == 0) {
    fraction = 0.0;
    runner = string;
    is_finished = 1;
  } else {
    for (; mantissa_size > 0; mantissa_size -= 1) {
      if (is_point(*runner)) {
        runner++;
      }
      fraction = 10 * fraction + (*runner - '0');
      runner++;
    }
  }
  if (!is_finished) {
    runner = pointer_exponent;
    if (is_exponent(*runner)) {
      runner++;
      if (*runner == '-') {
        exponent_sign = -1;
        runner++;
      } else {
        if (*runner == '+') {
          exponent_sign = 1;
          runner++;
        }
      }
      while (is_decimal(*runner)) {
        exp_power = exp_power * 10 + (*runner - '0');
        runner++;
      }
    }
    if (exponent_sign == -1) {
      exp_power = frac_exp_power - exp_power;
    } else {
      exp_power = frac_exp_power + exp_power;
    }

    if (exp_power < 0) {
      exponent_sign = -1;
      exp_power = -exp_power;
    } else {
      exponent_sign = 1;
    }
    if (exp_power > max_exponent) {
      exp_power = max_exponent;
      perror("Out of range\n");
    }

    double value_exponent = 1.0;
    for (double *iterator = powersOf10; exp_power != 0;
         exp_power >>= 1, iterator++) {
      if (exp_power & 01) {
        value_exponent *= *iterator;
      }
    }
    if (exponent_sign == -1) {
      fraction /= value_exponent;
    } else {
      fraction *= value_exponent;
    }
  }
  if (sign == -1) {
    return -fraction;
  }
  return fraction;
}

void init_buffer(char **buffer, int len, int *error) {
  char *tmp = calloc(len, sizeof(char));
  if (tmp != S21_NULL) {
    (*buffer) = tmp;
  } else {
    perror("Failed to allocate memory\n");
    *error = 1;
  }
}
void write_to_buffer(char **buffer, int length, char ch, int *error) {
  char *tmp = realloc((*buffer), length * sizeof(char));
  if (tmp != S21_NULL) {
    (*buffer) = tmp;
    (*buffer)[length - 1] = ch;
  } else {
    free(buffer);
    perror("Failed to allocate memory\n");
    *error = 1;
  }
}

int is_within_borders(int runner, int border) {
  int result = 0;
  if (border == 0) {
    result = 1;
  } else {
    result = (runner < border);
  }
  return result;
}