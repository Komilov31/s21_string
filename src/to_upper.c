#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *to_upper(const char *str);

int main(){
    char str[] = "i like it";
    printf("%s", to_upper(str));

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
