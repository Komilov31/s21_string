#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *to_lower(const char *str);

int main(){
    char str[] = "i like it";
    printf("%s", to_lower(str));

    return 0;
}


char *to_lower(const char *str){
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
    return str_to_lower;
}
