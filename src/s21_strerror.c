#include "s21_string.h"

int main(void) {
    char *first = "7";
    char *second = "01273456789";
    
    char *first_result = strpbrk(first, second);
    char *second_result = s21_strpbrk(first, second);
    

    if (first_result != NULL && s21_strpbrk(first, second) != NULL) {
        printf("%s\n", first_result);
        printf("%s\n", second_result);
    }
}