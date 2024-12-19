#include "s21_string.h"

char *s21_strpbrk(const char *str1, const char *str2) {
  char *result = s21_NULL;
  int shift_value = s21_strcspn(str1, str2);

  if (shift_value != strlen(str1)) {  // change
    result = (char *)(str1 + shift_value);
  }

  return result;
}