#ifndef SRC_S21_SPRINTF_H
#define SRC_S21_SPRINTF_H

#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#define LEN_STR 5024
#define LEN_STR_TYPE 1024
#define LEN_STR_FOR_LU 1024
#define LEN_STR_FOR_LD 5120

struct Spec_Format {
  short int flag_plus;
  short int flag_zero;
  short int flag_left;
  short int flag_space;
  short int flag_reshetka;

  long int width;
  long int accuracy;
  char length;
  char specifecator;
};

// Стандартный проходчик копируем, обрабатываем, находим  %,%%,\0
//,останавливаемся при %
void copy_while_not_find_mark_format_start_or_end(char **str,
                                                  const char **format,
                                                  long int *stchetchik,
                                                  short int *stop);
// Сборщик флагов и спецификаций
short int get_options(const char **format, char *str_to_add_from_param,
                      va_list *param, struct Spec_Format *spec_format);
// Функции обработки флагов и спцификаций
short int is_it_the_flag_in_format(const char **format,
                                   struct Spec_Format *spec_format);
short int is_it_the_width_in_format(const char **format,
                                    char **str_to_add_from_param,
                                    va_list *param,
                                    struct Spec_Format *spec_format);
short int is_it_the_accuracy_in_format(const char **format,
                                       char **str_to_add_from_param,
                                       va_list *param,
                                       struct Spec_Format *spec_format);
short int is_it_the_length_in_format(const char **format,
                                     struct Spec_Format *spec_format);
short int is_it_the_specifacators_in_format(const char **format,
                                            struct Spec_Format *spec_format);
char *add_flag_spec(char *str_to_add_from_param_start,
                    struct Spec_Format *spec_format);

// взятие и обработка аргумента в строку-------------------------------
long int get_str_from_value_global(va_list *param,
                                   struct Spec_Format spec_format,
                                   char *str_to_add_from_param,
                                   long int schetchik_otvet);

// взятие и обработка аргумента в строку для d
short int get_value_from_arg_and_format_for_d(va_list *param,
                                              struct Spec_Format spec_format,
                                              char *str_to_add_from_param);
short int get_value_from_arg_and_format_for_u(va_list *param,
                                              struct Spec_Format spec_format,
                                              char *str_to_add_from_param);
short int formating_string_by_format_for_d(char *str_to_add_from_param,
                                           char *str_from_int,
                                           struct Spec_Format spec_format,
                                           short int sign_minus);
// взятие и обработка аргумента в строку для s
long int get_value_from_arg_and_format_for_s(va_list *param,
                                             struct Spec_Format spec_format,
                                             char *str_to_add_from_param);
long int formating_string_by_format_for_ls(char *str_to_add_from_param,
                                           wchar_t *array_wchar_t,
                                           struct Spec_Format spec_format);
long int convert_wchar_to_char(char *tmp_char_array, wchar_t *array_wchar_t,
                               struct Spec_Format spec_format);
long int formating_string_by_format_for_s(char *str_to_add_from_param,
                                          char *array_char,
                                          struct Spec_Format spec_format);
// взятие и обработка аргумента в строку для c
long int get_value_from_arg_and_format_for_c(va_list *param,
                                             struct Spec_Format spec_format,
                                             char *str_to_add_from_param);
long int formating_string_by_format_for_c(char *str_to_add_from_param,
                                          wchar_t value_wchar_t,
                                          struct Spec_Format spec_format);
long int format_by_width_c(char *str_to_add_from_param,
                           struct Spec_Format spec_format,
                           wchar_t wchar_t_from);
// взятие и обработка аргумента в строку для f
long int get_value_from_arg_and_format_for_f(va_list *param,
                                             struct Spec_Format spec_format,
                                             char *str_to_add_from_param);
void get_two_string_from_double(char *number_One, char *number_Two,
                                long double long_number);
long int formating_two_string_for_f(char *str_to_add_from_param,
                                    struct Spec_Format spec_format,
                                    char *number_One, char *number_Two,
                                    short int sign_minus, int exp);
int get_c_of_ciphra_in_number_before_dot(double x);
long double change_double_for_int(long double long_number,
                                  int multiply_ont_ten);
void format_double_by_accuracy(char *number_One, char *number_Two,
                               long int accuracy);
short int is_chetnoe(char ch);
short int add_perenos_to_str(char *number_Two, short int perenos);
short int add_inter_perenos_to_str(char *number_One, short int perenos);
void concat_two_str(char *number_One, char *number_Two,
                    struct Spec_Format spec_format, int exp);
int get_sign_of_long_double(long double src);
int rebalnced_double_number(char *number_One, char *number_Two);
void reduce_zero(char *number_Two);

// взятие и обработка аргумента в строку для n
short int get_value_from_arg_and_format_for_n(va_list *param,
                                              char *str_to_add_from_param,
                                              long int schetchik_otvet);

short int represent_int_to_x(char *str_to_add_from_param,
                             unsigned long long int value_d, int flag_x);
// добавляем знак к перевернутой строке
char *add_sign(struct Spec_Format spec_format, char *str_from_int_tmp,
               short int sign_minus);
// форматирование по ширине
long int format_by_width(char *str_to_add_from_param,
                         struct Spec_Format spec_format, char *str_from_int);
// unsigned long long int -> string в перевернутом виде
short int represent_int_to_str(char *str_to_add_from_param,
                               unsigned long long int value_u);
// переворачивает строку
char *revers_string(char *dst, char *revers);
// long int -> string в нормальном виде с минусом если есть для обработки *
char *int_to_str_simple(char *str_from_arg, long long int value_from_arg);

#endif