#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void *trim(const char *src, const char *trim_chars);


int main(){
    const char *test_str = "   Hello, World!   ";
    const char *trim_chars = " ";
    char *trimmed_str = trim(test_str, trim_chars);
    
    if (trimmed_str) {
        printf("Original: '%s'\n", test_str);
        printf("Trimmed: '%s'\n", trimmed_str);
        free(trimmed_str);
            } else {
        printf("Memory allocation failed.\n");
    }

    return 0;

    return 0;
}

int str_beginning_check(const char *src, const char *trim_chars, int index){
 int res = 0;
 for(size_t i = 0; i < strlen(src); i++){
    if(src[index]  == trim_chars[i]){
        res = 1;
    }
 }
 return res;
}

int str_ending_check(const char *src, const char *trim_chars, int index){
 int res = 0;
 if(index > 0){
 index--;
 }
 for(size_t i = 0; i < strlen(src); i++){
    if(src[index]  == trim_chars[i]){
        res = 1;
    }
 }
 return res;
}

void *trim(const char *src, const char *trim_chars){
    char *trimmed_str = NULL;
    if(src){
        if(trim_chars && trim_chars[0]){
            trimmed_str = malloc((strlen(src) + 1) * sizeof(char));
            size_t str_beginning = 0, str_ending = strlen(src);
            while(str_beginning_check(src, trim_chars, str_beginning)){
                str_beginning++;
            }
            if(str_beginning != str_ending){
                while(str_ending_check(src, trim_chars, str_ending)){
                    str_ending--;
                }
            }else{
                trimmed_str[0] ='\0';
            }
            size_t i = 0;

            for(; str_beginning < str_ending; i++, str_beginning++){
                trimmed_str[i] = src[str_beginning];
            }
            trimmed_str[i] = '\0';
        } else{
            trimmed_str = trim(src, "\t\n ");
        }
        }
        return (void *)trimmed_str;
    }