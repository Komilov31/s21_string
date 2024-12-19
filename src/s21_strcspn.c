#include "s21_string.h"

size_t s21_strcspn(const char *str1, const char *str2) {

    size_t counter = 0;
    int flag = 0;
    for (int i = 0; str1[i] != '\0'; i++) {
        flag = does_contain(str2, str1[i]);
        if (flag == 1) {
            counter = i;
            break;
        }   
    }

    if (counter == 0 && flag == 0) {
        counter = strlen(str1); // change
    }

    return counter;
}
