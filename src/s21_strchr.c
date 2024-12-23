#include "s21_string.h"

char *s21_strchr(const char *str, int c) {
  const char *chrs = s21_NULL;
  int flag = 0;
  for (s21_size_t i = 0; i < s21_strlen(str) + 1; i++) {
    if (str[i] == c) {
      if (flag == 0) {  
        chrs = (str + i);
        flag = 1;
      }
    }
  }
  return (char *)chrs;
}