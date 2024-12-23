#include "s21_string.h"

s21_size_t s21_strcspn(const char *str1, const char *str2) {

    s21_size_t counter = 0;
    int flag = 0;
    int flag1 = 0;
    for (int i = 0; str1[i] != '\0'; i++) {
        flag = does_contain(str2, str1[i]);
        if (flag == 1) {
            if (flag1 == 0){
                counter = i;
                flag1 = 1;
            }
        }   
    }

    if (counter == 0 && flag == 0) {
        counter = s21_strlen(str1); 
    }

    return counter;
}


int does_contain(const char *input, char char_to_find) {
    int flag = 0;
    for (int i = 0; input[i] != '\0'; i++){
        if (input[i] == char_to_find) {
            flag = 1;
        }
    }
    return flag;
}