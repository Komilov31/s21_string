#include "s21_string.h"

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  char *arrSrc = (char *)src;
  char *arrDest = (char *)dest;
  for (s21_size_t i = 0; i < n; i++) {
    arrDest[i] = arrSrc[i];
  }
  return arrDest;
}