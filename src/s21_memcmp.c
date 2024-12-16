#include "s21_string.h"

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  const char *memcmpStr1 = (const char *)str1;
  const char *memcmpStr2 = (const char *)str2;
  int check = 0;
  for (s21_size_t i = 0; i < n; i++) {
    if (check == 1) break;
    check = memcmpStr1[i] - memcmpStr2[i];
  }
  return check;
}