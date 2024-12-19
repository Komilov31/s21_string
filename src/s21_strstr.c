#include "s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
    char *return_value = s21_NULL;
    size_t size = strlen(needle); // change

    for (int i = 0; haystack[i] != '\0'; i++) {
        if (memcmp(haystack + i, needle, size) == 0) { // change 
            return_value = (char *)(haystack + i);
            break;
        }
    }

    return return_value;
}
