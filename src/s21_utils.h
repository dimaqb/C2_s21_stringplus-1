#ifndef S21_UTILS_H
#define S21_UTILS_H

int is_space(char ch);
int is_point(char ch);
int is_sign(char ch);

int is_decimal(char ch);
int is_octal(char ch);
int is_hex(char ch);
int is_hexadecimal(char ch);

int is_exponent(char ch);

int hex_to_int(char ch);
int hexadecimal_to_int(char ch);

// Reading from string
int read_token_from_string(char **buffer, char **string, int width,
                           int (*is_correct_char)(char));
int read_double_from_string(char **buffer, char **string, int width);

void init_buffer(char **buffer, int len, int *error);
void write_to_buffer(char **buffer, int length, char ch, int *error);
int is_within_borders(int runner, int border);

// Parsing string
char *parse_string(char **format, int width, int *error);
// Parsing decimal number
long parse_decimal(char **format, int width, int *error);
long s21_atoi(const char *str, int *error);

// Parsing decimal number
unsigned long int parse_unsigned_decimal(char **format, int width, int *error);
int is_decimal(char ch);
unsigned long int s21_unsigned_atoi(const char *str, int *error);

// Parsing unsigned octal number
unsigned long int parse_unsigned_octal(char **format, int width, int *error);
int is_octal(char ch);
unsigned long int s21_unsigned_octal_atoi(const char *str, int *error);

// Prasing unsigned hexadecimal number
unsigned long int parse_unsigned_hexadecimal(char **string, int width,
                                             int *error);
int is_hexadecimal(char ch);
unsigned long int s21_unsigned_hexadecimal_atoi(const char *str, int *error);

// Parsing unspec number
long parse_unspec(char **string, int width, int *error);
long int s21_octal_atoi(const char *str, int *error);
long int s21_hexadecimal_atoi(const char *str, int *error);

// Prasing double number
long double parse_double(char **string, int width, int *error);
double s21_atof(const char *string);

#endif
