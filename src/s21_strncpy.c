#include "s21_string.h"


char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
    s21_size_t size = s21_strlen(src);
    dest = (char *) s21_memcpy(dest, src, n);
    if (size > n) {
        for (s21_size_t i = n; i < size; i++){
            dest[i] = '\0';
        }
    }
    return dest;
}