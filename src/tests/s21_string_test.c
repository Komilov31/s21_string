#include <stdio.h>
#include <check.h>
#include <../s21_string_nijikael.h>

START_TEST(s21_to_upper_test){
    char str1[] = "test string";
    char str2[] = "this1";
    char str3[] = "";
    char str4[] = "a";
    
    char *str = s21_to_upper(str1);

    if(str){
        ck_assert_str_eq(str, "TEST STRING");
        free(str);
    }
    str = s21_to_upper(str2);
    if(str){
        ck_assert_str_eq(str, "THIS1");
        free(str);
    }
    str = s21_to_upper(str3);
    if(str){
        ck_assert_str_eq(str, "");
        free(str);
    }
    str = s21_to_upper(str4);
    if(str){
        ck_assert_str_eq(str, "A");
        free(str);
    }
}
END_TEST


START_TEST(s21_to_lower_test){
    char str1[] = "TEST STRING";
    char str2[] = "THIS1";
    char str3[] = "";
    char str4[] = "A";
    
    char *str = s21_to_lower(str1);

    if(str){
        ck_assert_str_eq(str, "test string");
        free(str);
    }
    str = s21_to_lower(str2);
    if(str){
        ck_assert_str_eq(str, "this1");
        free(str);
    }
    str = s21_to_lower(str3);
    if(str){
        ck_assert_str_eq(str, "");
        free(str);
    }
    str = s21_to_lower(str4);
    if(str){
        ck_assert_str_eq(str, "a");
        free(str);
    }
}
END_TEST

START_TEST(s21_insert_test){
    char *src = "TEST STRING";
    char *str = "THIS1 ";
    char *new_str = {0};
    
    char *new_str = s21_insert(src, str, 5);

    if(new_str){
        ck_assert_str_eq(new_str, "TEST THIS1 STRING");
        free(new_str);
    }

    new_str = s21_insert(src, "", 13);
    ck_assert_str_eq(new_str, NULL);
    

    new_str = s21_insert(src, str, 45);
    if(new_str){
    ck_assert_str_eq(new_str, NULL);
    
    }

    new_str = s21_insert("", "", 0);
    if(new_str){
        ck_assert_str_eq(new_str, "");
        free(new_str);
    }
    new_str = s21_insert("2", "2", 1);
    if(new_str){
        ck_assert_str_eq(new_str, "22");
        free(new_str);
    }
}
END_TEST

START_TEST(s21_trim_test){
char *result;
char *test = "\n ! **'\' let's test ** '\' * !'\n' ";
result = s21_trim(test, " !\n*'\'");


}END_TEST

