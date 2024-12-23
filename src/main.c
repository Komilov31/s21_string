
#include "s21_string.h"

int main(void) {
    char str0_5[] = "VERTER LET PASS PLS";
    char str5_0[] = " ";

    char *result = s21_strtok(s21_NULL, str5_0);
    char *result1 = s21_strtok(s21_NULL, str5_0);
    if (result == s21_NULL && result1 == s21_NULL) {
        printf("Yes\n");
    }
    return 0;
}