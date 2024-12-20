#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *s21_to_lower(const char *str);

int main(){
    char str[] = "i like it";
    char *lower_str = to_lower(str);
    if(lower_str){
    printf("%s", lower_str);
    free(lower_str);
    } else{
        printf("Memory allocation failed or input is NULL");
    }

    return 0;
}


void *s21_to_lower(const char *str){
    char *str_to_lower = NULL;
    if(str){
    str_to_lower = malloc((strlen(str) + 1)* sizeof(char));
    if(str_to_lower){
    strncpy(str_to_lower, str, strlen(str) + 1);
    for(size_t i = 0;  i < strlen(str_to_lower); i++){
        if( str_to_lower[i] > 64 &&  str_to_lower[i] < 91){
             str_to_lower[i] += 32;
        }
    }
    }
    }
    return (void *)str_to_lower;
}
