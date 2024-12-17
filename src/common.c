#include "s21_string.h"

int does_contain(const char *input, char char_to_find) {
    int flag = 0;
    for (int i = 0; input[i] != '\0'; i++){
        if (input[i] == char_to_find) {
            flag = 1;
        }
    }
    return flag;
}