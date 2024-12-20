#include "s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
    char *return_value = s21_NULL;
    size_t size = s21_strlen(needle);

    for (int i = 0; haystack[i] != '\0'; i++) {
        if (s21_memcmp(haystack + i, needle, size) == 0) {
            return_value = (char *)(haystack + i);
            break;
        }
    }

    return return_value;
}
