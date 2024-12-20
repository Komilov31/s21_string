#include "s21_string.h"

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  unsigned int length = 0;
  int check = 0;
  for (s21_size_t i = 0; i < n; i++) {
    if ((str1[i] == '\0' && str2[i] == '\0') || check == 1) break;
    if (str1[i] != str2[i]) {
      length = str1[i] - str2[i];
      check = 1;
    }
  }
  return length;
}