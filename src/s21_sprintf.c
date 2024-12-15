#include "s21_sprintf.h"

#include <string.h>

//(str, "asd %-+d %+0lf", 123, 5)
int s21_sprintf(char* str, const char* format, ...) {
  char* start = str;
  va_list args;
  va_start(args, format);

  while (*format) {
    if (*format != '%') {
      *str = *format;
      str++;
    } else {
      struct Params params = {0};
      params.number_system = 10;
      format++;
      format += read_params(&params, format, &args);
      // printflags(&params);
      str = input_with_params(str, start, format, &params, &args);
      // printflags(&params);
    }
    format++;
  }
  *str = '\0';
  va_end(args);

  return (str - start);
}

int read_params(struct Params* params, const char* format, va_list* args) {
  int size = 0;
  set_flags(params, format, &size);
  set_width(&(params->width), format + size, &size, args);
  set_accuracy(params, format + size, &size, args);
  set_length(params, format + size, &size);
  return size;
}

void set_flags(struct Params* params, const char* format, int* size) {
  int flags = 1;
  while (flags) {
    if (*format == '+') {
      params->plus = 1;
      (*size)++;
    } else if (*format == '-') {
      params->minus = 1;
      (*size)++;
    } else if (*format == '#') {
      params->hash = 1;
      (*size)++;
    } else if (*format == ' ') {
      params->space = 1;
      (*size)++;
    } else if (*format == '0') {
      params->zero = 1;
      (*size)++;
    } else {
      flags = 0;
    }
    if (flags) format++;
  }
  if (params->space && params->plus) params->space = 0;
  if (params->zero && params->minus) params->zero = 0;
}

void set_width(int* width, const char* format, int* size, va_list* args) {
  // здесь возможна ошибка потому что sprintf(str, "hello %*12d", 5, 123);
  // выведет %512d и ошибку хз короче
  if (*format == '*') {
    *width = va_arg(*args, int);
    (*size)++;
  } else {
    while ('0' <= *format && *format <= '9') {
      *width *= 10;
      *width += (int)(*format - 48);
      format++;
      (*size)++;
    }
  }
}

void set_accuracy(struct Params* params, const char* format, int* size,
                  va_list* args) {
  if (*format == '.') {
    params->dot = 1;
    params->zero = 0;  ///////////
    format++;
    (*size)++;
    set_width(&(params->accuracy), format, size, args);
  }
}

void set_length(struct Params* params, const char* format, int* size) {
  if (*format == 'L')
    params->length = 'L';
  else if (*format == 'l')
    params->length = 'l';
  else if (*format == 'h')
    params->length = 'h';
  if (params->length) (*size)++;
}

char* input_with_params(char* str, char* start, const char* format,
                        struct Params* params, va_list* args) {
  if (*format == 'd' || *format == 'i') {
    str = input_num(str, params, args, *format);
  } else if (*format == 'o' || *format == 'x' || *format == 'X' ||
             *format == 'u') {
    str = input_num(str, params, args, *format);
  }

  return str;
}

char* input_num(char* str, struct Params* params, va_list* args, char form) {
  long int number;
  if (params->length == 'h') {
    if (form == 'd' || form == 'i')
      number = (short)va_arg(*args, int);
    else
      number = (short)va_arg(*args, unsigned int);
  } else if (params->length == 'l') {
    if (form == 'd' || form == 'i')
      number = (long int)va_arg(*args, long int);
    else
      number = (int)va_arg(*args, unsigned long int);
  } else {
    if (form == 'd' || form == 'i')
      number = (int)va_arg(*args, int);
    else
      number = (int)va_arg(*args, unsigned int);
  }

  if (form == 'd' || form == 'i' || form == 'u') params->number_system = 10;
  if (form == 'x' || form == 'X') params->number_system = 16;
  if (form == 'o') params->number_system = 8;
  // sprintf(str, "Hello!! %d %f", 2^32-123, 5);
  s21_size_t size = size_num_with_params(params, number, form);
  char* buff_d = calloc(size, sizeof(char));

  int pos = 0;
  buff_d = num_to_str(params, number, buff_d, size, &pos, form);
  for (int i = strlen(buff_d) - 1; i >= 0;
       i--) {  //!!!!!!!!!!!!!!!!!!!!!!!!!!s21_strlen
    *str = buff_d[i];
    str++;
  }
  while (params->width > pos && params->minus) {
    *str = ' ';
    str++;
    pos++;
  }
  free(buff_d);
  return str;
}
// sprintf(str, "Hello!! %d", 123);
s21_size_t size_num_with_params(struct Params* params, long int number,
                                char form) {
  int size = 0;
  if (number == 0 && !((params->dot) && (params->accuracy == 0))) size++;
  while (number != 0) {
    size++;
    number /= params->number_system;
  }
  if (((form == 'd' || form == 'i') &&
       (number < 0 || params->space || params->plus)) ||
      (form == 'o' && params->hash))
    size++;
  if ((form == 'x' || form == 'X') && params->hash) size += 2;
  if (params->width > size) size = params->width;
  if (params->accuracy > size) size = params->accuracy;

  return size;
}

char* num_to_str(struct Params* params, long int number, char* buff_d,
                 s21_size_t size, int* pos, char form) {
  //*pos=0;
  int b;
  if (number == 0 && !((params->dot) && (params->accuracy == 0))) {
    buff_d[*pos] = '0';
    (*pos)++;
  }
  long int new_number = number;
  if (new_number < 0) new_number = -new_number;
  while (new_number != 0) {
    if (new_number % params->number_system > 9 && form != 'X')
      b = 87;
    else if (new_number % params->number_system > 9)
      b = 55;
    else
      b = 48;

    buff_d[*pos] = (char)(new_number % params->number_system + b);
    (*pos)++;
    new_number /= params->number_system;
  }
  //"321"
  while ((params->accuracy > *pos) ||
         (params->width > *pos && !params->minus && params->zero)) {
    buff_d[*pos] = '0';
    (*pos)++;
  }
  //"32100"
  if ((form == 'd' || form == 'i') && number < 0) {
    buff_d[*pos] = '-';
    (*pos)++;
  } else if ((form == 'd' || form == 'i') && params->plus) {
    buff_d[*pos] = '+';
    (*pos)++;
  } else if ((form == 'd' || form == 'i') && params->space) {
    buff_d[*pos] = ' ';
    (*pos)++;
  } else if (params->hash && (form == 'X' || form == 'x')) {
    buff_d[*pos] = form;
    (*pos)++;
    buff_d[*pos] = '0';
    (*pos)++;
  } else if (params->hash && form == 'o') {
    buff_d[*pos] = '0';
    (*pos)++;
  }
  if (((form == 'd' || form == 'i') && params->hash) ||
      ((form != 'd' || form != 'i') && (params->space || params->plus)))
    fprintf(stderr, "Params error: \n");
  //"32100+"
  while (params->width > *pos && !params->minus) {
    buff_d[*pos] = ' ';
    (*pos)++;
  }
  return buff_d;
  //"32100+  "
}

// char *dig_to_char(long int digit){
// 	if (digit >=0 && digit=<9){

// 	}
// }

void printflags(struct Params* params) {
  printf("\n|%d\n", params->accuracy);
  printf("%d\n", params->width);
  printf("%d|\n", params->dot);
}