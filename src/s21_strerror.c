#include "s21_string.h"

char *s21_strerror(int errnum) {
  char *errors[] = s21_error;
  return (char *)errors[errnum - 1];
}