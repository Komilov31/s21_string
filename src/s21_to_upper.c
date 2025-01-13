#include "s21_string.h"
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// void *s21_to_upper(const char *str);

// int main(){
//     char str[] = "i like it";
//     char *upper_str = to_upper(str);
//     if(upper_str){
//     printf("%s", upper_str);
//     free(upper_str);
//     } else{
//      printf("Memory allocation failed or input is s21_NULL");
//     }
//     return 0;
// }

void *s21_to_upper(const char *str) {
  char *str_to_upper = s21_NULL;
  if (str) {
    str_to_upper = malloc((s21_strlen(str) + 1) * sizeof(char));
    if (str_to_upper) {
      s21_strncpy(str_to_upper, str, s21_strlen(str) + 1);
      for (s21_size_t i = 0; i < s21_strlen(str_to_upper); i++) {
        if (str_to_upper[i] > 96 && str_to_upper[i] < 123) {
          str_to_upper[i] -= 32;
        }
      }
    }
  }
  return (void *)str_to_upper;
}
