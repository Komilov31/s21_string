#include <stdio.h>
#include <string.h>

#include "s21_string.h"

int main() {
    char s[] = "Islam ,is,the way.";
    char d[] = " ";

    char *result = s21_strtok(s, d);
    char *result1 = s21_strtok(s, d);

    printf("%s\n", result1);

}

char *s21_strtok(char *str, const char *delim) {

    char *token = s21_NULL;
    static int flag = 0;

    static char *s = str;

    if (str == s21_NULL) {
      str = s;
    } else {
        flag = 0;
    }

    if (flag == 0) {
        fill_with_terminate(str, delim, &flag);
    }

    if (flag == 1 && *(str + 1) != '\0') {
        token = str;
    }

    while (*str != '\0') {
        str++;
    }
    
    return token;

}

void fill_with_terminate(char *str, const char *delim, int *flag) {
    for (int i = 0; delim[i] != '\0'; i++) {
        for (int j = 0; str[j] != '\0'; j++) {
            if (delim[i] == str[j]) {
                str[j] = '\0';
                *flag = 1;
            }
        }
    }
}