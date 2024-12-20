#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *s21_insert(const char *src, const char *str, size_t start_index);
void *s21_to_lower(const char *str);
void *s21_to_upper(const char *str);
void *s21_trim(const char *src, const char *trim_chars);
int str_ending_check(const char *src, const char *trim_chars, int index);
int str_beginning_check(const char *src, const char *trim_chars, int index);


void *s21_insert(const char *src, const char *str, size_t start_index){
    char *string_with_insertion = NULL;
    if(src && str && start_index <= strlen(src)){
        string_with_insertion = (char *)malloc((strlen(src) + strlen(str) + 1) * sizeof(char));
    size_t i = 0;
    for(; i < start_index; i++){
            string_with_insertion[i] = src[i];
        }
    size_t end_of_src = i;
    for(size_t j = 0; j < strlen(str); i++, j++){
        string_with_insertion[i] = str[j];
    }
    for(; end_of_src < strlen(src); end_of_src++, i++){
        string_with_insertion[i] = src[end_of_src];
    }
    string_with_insertion[strlen(string_with_insertion)] = '\0';
    }
    return (void *)string_with_insertion;
}

void *s21_to_lower(const char *str){
    char *str_to_lower = NULL;
    if(str){
    str_to_lower = (char *)malloc((strlen(str) + 1)* sizeof(char));
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

void *s21_to_upper(const char *str){
    char *str_to_upper = NULL;
    if(str){
    str_to_upper = (char *)malloc((strlen(str) + 1)* sizeof(char));
    if(str_to_upper){
    strncpy(str_to_upper, str, strlen(str) + 1);
    for(size_t i = 0;  i < strlen(str_to_upper); i++){
        if( str_to_upper[i] > 96 &&  str_to_upper[i] < 123){
             str_to_upper[i] -= 32;
        }
    }
    }
    }
    return (void *)str_to_upper;
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

void *s21_trim(const char *src, const char *trim_chars){
    char *trimmed_str = NULL;
    if(src){
        if(trim_chars && trim_chars[0]){
            trimmed_str = (char *)malloc((strlen(src) + 1) * sizeof(char));
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
            trimmed_str = (char *)s21_trim(src, "\t\n ");
        }
        }
        return (void *)trimmed_str;
    }