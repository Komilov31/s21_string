#include "s21_string.h"

char *s21_strrchr(const char *str, int c) {
    int flag = 0;
    char *return_value = s21_NULL;
    s21_size_t len = s21_strlen(str);
    for (int i = len; i >= 0; i--) {
        if (c == str[i]) {
            if (flag == 0) {
                return_value = (char *) (str + i);
                flag = 1;
            }
        }
    }

  return return_value;
}