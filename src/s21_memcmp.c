#include "s21_string.h"

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  const char *bufStr1 = (const char *)str1;
  const char *bufStr2 = (const char *)str2;
  int check = 0;
  s21_size_t i = 0;
  while (check == 0 && i < n) {
    if (bufStr1[i] != bufStr2[i]) check = bufStr1[i] - bufStr2[i];
    i++;
  }
  return check;
}