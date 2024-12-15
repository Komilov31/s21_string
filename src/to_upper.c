#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *to_upper(const char *str);

int main(){
    char str[] = "i like it";
    char *upper_str = to_upper(str);
    if(upper_str){
    printf("%s", upper_str);
    free(upper_str);
    } else{
     printf("Memory allocation failed or input is NULL");
    }
    return 0;
}


char *to_upper(const char *str){
    char *str_to_upper = NULL;
    if(str){
    str_to_upper = malloc((strlen(str) + 1)* sizeof(char));
    if(str_to_upper){
    strncpy(str_to_upper, str, strlen(str) + 1);
    for(size_t i = 0;  i < strlen(str_to_upper); i++){
        if( str_to_upper[i] > 96 &&  str_to_upper[i] < 123){
             str_to_upper[i] -= 32;
        }
    }
    }
    }
    return str_to_upper;
}
