#include "s21_string.h"


char *s21_strncpy(char *dest, const char *src, size_t n) {
    size_t size = strlen(src); // change
    dest = (char *) memcpy(dest, src, n); // change
    if (size > n) {
        for (int i = n; i < size; i++){
            dest[i] = '\0';
        }
    }
    return dest;
}