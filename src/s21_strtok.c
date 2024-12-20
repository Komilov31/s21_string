#include "s21_string.h"

char *s21_strtok(char *str, const char *delim) {
  
    static char *last = s21_NULL;
    char *start = s21_NULL;
    
    if (str != s21_NULL) {
        last = str;
    }

    if (last == s21_NULL) {
        start = s21_NULL;
    } 

    while (*last != '\0' && s21_strchr(delim, *last) != s21_NULL) {
        last++;
    }

    if (*last == '\0') {
        last = s21_NULL;
        start = s21_NULL;
    }
    start = last;

    while (*last != '\0' && s21_strchr(delim, *last) == s21_NULL) {
        last++;
    }

    if (*last != '\0') {
        *last = '\0';
        last++;
    }

    return start;
}