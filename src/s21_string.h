#include <limits.h>
#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef SRC_S21_STRING_H_
#define SRC_S21_STRING_H_

#define s21_size_t unsigned long long
#define s21_NULL (void *)0
#define MESSAGE_S "ERROR test %i ('%s'), we expected '%s', but got      '%s'"
#define MESSAGE_D "ERROR test %i, we expected '%i', but got      '%i'"

#ifdef __APPLE__
#define ERROR_LIMIT 107
#else
#define ERROR_LIMIT 134
#endif

typedef struct {
  int special_letter;
  int minus;
  int plus;
  int space;
  int width;
  int point;
  int precision;
  int length_mod;
  int grid;
  int zero;
  int star;
} parsing;

void *s21_memchr(const void *str, int c, s21_size_t n);
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);
void *s21_memcpy(void *dest, const void *src, s21_size_t n);
void *s21_memmove(void *dest, const void *src, s21_size_t n);
void *s21_memset(void *str, int c, s21_size_t n);
char *s21_strcat(char *dest, const char *src);
char *s21_strncat(char *dest, const char *src, s21_size_t n);
char *s21_strchr(const char *str, int c);
int s21_strcmp(const char *str1, const char *str2);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
char *s21_strcpy(char *dest, const char *src);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
unsigned int s21_strcspn(const char *str1, const char *str2);
void int_to_char(char *result, int number);
char *s21_strerror(int errnum);
s21_size_t s21_strlen(const char *str);
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strrchr(const char *str, int c);
s21_size_t s21_strspn(const char *str1, const char *str2);
char *s21_strstr(const char *haystack, const char *needle);
char *s21_strtok(char *str, const char *delim);
void *s21_to_upper(const char *str);
void *s21_to_lower(const char *str);
void *s21_insert(const char *src, const char *str, s21_size_t start_index);
void *s21_trim(const char *src, const char *trim_chars);
int s21_sprintf(char *str, const char *format, ...);
int form_number(const char *str, int *len);
int def_number(char c);
int length_mod(char c);
int specifiers(char c);
void calling_function(parsing pars, va_list args, int *len_buf, char *str_add,
                      int length);
void c_or_percent_func(parsing pars, va_list args, int *len_buf, char *str);
void d_or_i_func(parsing pars, va_list args, int *len_buf, char *str);
char sign_func_whole(long int *number, int *plus, int *space);
int form_number_d(parsing pars, long int number, char *str);
int consider_precision_d(parsing pars, int i, char sign, char *str,
                         int *precision);
void format_d(parsing pars, int len, char *str, char sign, int *len_buf);
void f_func(parsing pars, int *len_buf, char *str, long double number,
            int from_g_grid);
char sign_func_subst(long double *number, int *plus, int *space);
int whole_part(long double number, int *buff);
void fraction_part(int shortage, long double number, int *buff, int whole);
void round_number(int *buff, int len, int *buff1, int *whole);
int str_form(parsing pars, const int *buff1, int whole, char c, char *str,
             int *len_str);
char consider_g(char *str, int *len_str, int *len, int from_g_grid);
void format_f(parsing pars, int len1, int len, char c, char *str, int *len_buf);
void s_func(parsing pars, va_list args, int *len_buf, char *str);
void u_func(parsing pars, va_list args, int *len_buf, char *str);
void g_or_G_func(parsing pars, int *len_buf, char *str, long double number);
int form_power(int power, char e, char *str, int *len_buf);
int e_or_E_func(parsing pars, int *len_buf, char *str, long double number,
                int from_g_grid);
int x_or_X_func(parsing pars, va_list args, int *len_buf, char *str);
int convert(parsing pars, long unsigned num, long unsigned divider, char *data,
            char spec);
char convert_big_letters(int value);
char convert_small_letters(int value);
int consider_precision_x(parsing pars, int i, int *precision, char *str);
void format_x(parsing pars, int len, char *str, int *len_buf);
int o_func(parsing pars, va_list args, int *len_buf, char *str);
void n_func(va_list args, int length);
void p_func(parsing pars, va_list args, int *len_buf, char *str);
int s21_test(int sg);

#endif  // SRC_S21_STRING_H_
