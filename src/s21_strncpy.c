#include "s21_string.h"


char *s21_strncpy(char *dest, const char *src, size_t n) {
    size_t size = s21_strlen(src);
    dest = (char *) s21_memcpy(dest, src, n);
    if (size > n) {
        for (int i = n; i < size; i++){
            dest[i] = '\0';
        }
    }
    return dest;
}