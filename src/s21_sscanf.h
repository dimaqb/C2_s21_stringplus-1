#ifndef S21_SSCANF_H
#define S21_SSCANF_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

// %[*][ширина][длина]спецификатор
/**
 * @param suppress '*' if this option is present, the function does not assign
 * the result of the conversion to any receiving argument
 * @param width integer number that specifies maximum field width
 * @param length length modifier that specifies the size of the receiving
 * argument
 * @param spec conversion format specifier
 */
typedef struct {
  int suppress;
  int width;
  char lenght;
  char spec;
} format_token;

// Спецификаторы:
// c Символ
// d Знаковое десятичное целое число
// i Знаковое целое число
// (может быть десятичным, восьмеричным или шестнадцатеричным)
// e Десятичное число с плавающей точкой
// или научная нотация (мантисса/экспонента)
// E Десятичное число с плавающей точкой
// или научная нотация (мантисса/экспонента)
// f Десятичное число с плавающей точкой
// или научная нотация (мантисса/экспонента)
// g Десятичное число с плавающей точкой
// или научная нотация (мантисса/экспонента)
// G Десятичное число с плавающей точкой
// или научная нотация (мантисса/экспонента)
// o Беззнаковое восьмеричное число
// s Строка символов
// u Беззнаковое десятичное целое число
// x Беззнаковое шестнадцатеричное целое число (любые буквы)
// X Беззнаковое шестнадцатеричное целое число (любые буквы)
// p Адрес указателя n Количество символов,
// считаных до появления %n % Символ %

// Width
// (число)	Минимальное количество печатаемых символов.
// Если выводимое значение короче этого числа, результат дополняется пробелами.
// Значение не усекается, даже если результат больше.

// Length
// length modifier that specifies the size of the receiving argument, that is,
// the actual destination type. This affects the conversion accuracy and
// overflow rules. The default destination type is different for each conversion
// type (see table below).

int tokenizer(char *str, char *format, va_list ap);
format_token format_token_parse(char **str, char **format, int *error,
                                int *is_finished);

void parse_format_suppress(char **format, format_token *token);
int parse_format_width(char **format, format_token *token);
void parse_format_length(char **format, format_token *token);
void parse_format_spec(char **format, format_token *token);

int write_token(char **needle_str, format_token token, char *start, va_list ap);

int write_char_into_arg(char **needle_str, format_token token, va_list ap);
int write_string_into_arg(char **needle_str, format_token token, va_list ap,
                          char *(*parse)(char **, int, int *));

int write_signed_into_arg(char **needle_str, format_token token, va_list ap,
                          long (*parse)(char **, int, int *));

int write_unsigned_into_arg(char **needle_str, format_token token, va_list ap,
                            unsigned long (*parse)(char **, int, int *));
int write_unsigned_8_into_arg(char **needle_str, format_token token,
                              va_list ap);
int write_unsigned_16_into_arg(char **needle_str, format_token token,
                               va_list ap);

int write_unspec_into_arg(char **needle_str, format_token token, va_list ap);
int write_float_to_arg(char **needle_str, format_token token, va_list ap,
                       long double (*parse)(char **, int, int *));
int write_adress_of_pointer_into_arg(char **needle_str, format_token token,
                                     va_list ap);

#endif