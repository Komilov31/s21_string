#include "s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
    int flag = 0;
    char *return_value = NULL;
    s21_size_t size = s21_strlen(needle);

    for (int i = 0; haystack[i] != '\0'; i++) {
        if (s21_memcmp(haystack + i, needle, size) == 0) {
            if (flag == 0) {
                return_value = (char *)(haystack + i);
                flag = 1;
            }
        }
    }

    return return_value;
}
