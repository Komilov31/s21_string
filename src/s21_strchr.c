#include "s21_string.h"

char *s21_strchr(const char *str, int c) {
  const char *chrs = s21_NULL;
  for (s21_size_t i = 0; i < s21_strlen(str) + 1; i++) {
    if (str[i] == c) {
      chrs = (str + i);
      break;
    }
  }
  return (char *)chrs;
}