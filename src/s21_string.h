#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

char *s21_strncpy(char *dest, const char *src, size_t n);
size_t s21_strcspn(const char *str1, const char *str2);
int does_contain(const char *input, char char_to_find);
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strrchr(const char *str, int c);
char *s21_strstr(const char *haystack, const char *needle);
char *s21_strerror(int errnum);
char *some(const char *haystack, const char *needle);
