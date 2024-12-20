#include "s21_string.h"


char *s21_strrchr(const char *str, int c) {
    char *return_value = s21_NULL;
    s21_size_t len = s21_strlen(str);
    for (int i = len; i >= 0; i--) {
        if (c == str[i]) {
            return_value = (char *) (str + i);
            break;
        }
    }
    return return_value;
}