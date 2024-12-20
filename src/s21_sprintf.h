#ifndef S21_SPRINTF_H_
#define S21_SPRINTF_H_

#include "s21_string.h"

struct Params {
  int minus;
  int plus;
  int hash;
  int zero;
  int space;
  int width;
  int accuracy;
  char length;
  int number_system;
  int flag_to_size;  //?
  int dot;
  int upper_case;  //?
  int g;
  int e;
};

int read_params(struct Params *params, const char *format, va_list *args);
void set_flags(struct Params *params, const char *format, int *size);
void set_width(int *width, const char *format, int *size, va_list *args);
void set_accuracy(struct Params *params, const char *format, int *size,
                  va_list *args);
void set_length(struct Params *params, const char *format, int *size);
char *input_with_params(char *str, char *start, const char *format,
                        struct Params *params, va_list *args);

char *input_num(char *str, struct Params *params, va_list *args, char form);
char *input_double(char *str, struct Params *params, va_list *args, char form);
s21_size_t size_num_with_params(struct Params *params, long int number,
                                char form);
char *num_to_str(struct Params *params, long int number, char *buff_d, int *pos,
                 char form);
char *input_symbols(char *str, struct Params *params, va_list *args, char form);
char *p_null(char *str, struct Params *params, int *pos);
char *double_to_str(struct Params *params, long double number, char *buff_d,
                    int *pos, char form);
void output_e(struct Params *params, char *buff_d, int *pos, char form);
s21_size_t size_double_with_params(struct Params *params, long double *number,
                                   char form);
int shorter(struct Params *params, long double *number, int e);
int num_power(long double *number, int e);
void output_d(struct Params *params, long double *decimal);
void output_decimal(struct Params *params, char *buff_d, int *pos, int num_null,
                    long double decimal, long double number, char form);
void symvols_decimal(struct Params *params, long int number, char *buff_d,
                     int *pos);

#endif