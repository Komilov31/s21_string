#include "s21_string.h"

#include <check.h>

START_TEST(s21_to_upper_test) {
  char str1[] = "test string";
  char str2[] = "this1";
  char str3[] = "";
  char str4[] = "a";

  char *str = s21_to_upper(str1);

  if (str) {
    ck_assert_str_eq(str, "TEST STRING");
    free(str);
  }
  str = s21_to_upper(str2);
  if (str) {
    ck_assert_str_eq(str, "THIS1");
    free(str);
  }
  str = s21_to_upper(str3);
  if (str) {
    ck_assert_str_eq(str, "");
    free(str);
  }
  str = s21_to_upper(str4);
  if (str) {
    ck_assert_str_eq(str, "A");
    free(str);
  }
}
END_TEST

START_TEST(s21_to_lower_test) {
  char str1[] = "TEST STRING";
  char str2[] = "THIS1";
  char str3[] = "";
  char str4[] = "A";

  char *str = s21_to_lower(str1);

  if (str) {
    ck_assert_str_eq(str, "test string");
    free(str);
  }
  str = s21_to_lower(str2);
  if (str) {
    ck_assert_str_eq(str, "this1");
    free(str);
  }
  str = s21_to_lower(str3);
  if (str) {
    ck_assert_str_eq(str, "");
    free(str);
  }
  str = s21_to_lower(str4);
  if (str) {
    ck_assert_str_eq(str, "a");
    free(str);
  }
}
END_TEST

START_TEST(s21_insert_test) {
  char *src = "TEST STRING";
  char *str = "THIS1 ";
  // char *new_str = {0};

  char *new_str = s21_insert(src, str, 5);

  if (new_str) {
    ck_assert_str_eq(new_str, "TEST THIS1 STRING");
    free(new_str);
  }

  new_str = s21_insert(src, "", 13);
  ck_assert_str_eq(new_str, NULL);

  new_str = s21_insert(src, str, 45);
  if (new_str) {
    ck_assert_str_eq(new_str, NULL);
  }

  new_str = s21_insert("", "", 0);
  if (new_str) {
    ck_assert_str_eq(new_str, "");
    free(new_str);
  }
  new_str = s21_insert("2", "2", 1);
  if (new_str) {
    ck_assert_str_eq(new_str, "22");
    free(new_str);
  }
}
END_TEST

START_TEST(s21_trim_test) {
  char *result;
  char *test = "\n ! **'\' let's test ** '\' * !'\n' ";

  result = s21_trim(test, " !\n*'\'");
  if (result) {
    ck_assert_str_eq(result, "let's test");
    free(result);
  }
  result = s21_trim(test, "");
  if (result) {
    ck_assert_str_eq(result, "\n ! **'\' let's test ** '\' * !'\n' ");
    free(result);
  }

  char *test2 = "";
  result = s21_trim(test2, NULL);
  if (result) {
    ck_assert_str_eq(result, "");
    free(result);
  }

  char *test3 = "";
  result = s21_trim(NULL, test3);
  if (result) {
    ck_assert_str_eq(result, NULL);
  }

  result = s21_trim(test3, "\n\0");
  if (result) {
    ck_assert_str_eq(result, "");
    free(result);
  }

  char *test4 = "test \n";
  result = s21_trim(test4, "\n");
  if (result) {
    ck_assert_str_eq(result, "test ");
    free(result);
  }
}
END_TEST

int main(void) {
  Suite *s1 = suite_create("s21_string");
  TCase *test_case_1 = tcase_create("s21_string");
  SRunner *sr = srunner_create(s1);
  suite_add_tcase(s1, test_case_1);
  tcase_add_test(test_case_1, s21_to_upper_test);
  tcase_add_test(test_case_1, s21_to_lower_test);
  tcase_add_test(test_case_1, s21_insert_test);
  tcase_add_test(test_case_1, s21_trim_test);
  srunner_run_all(sr, CK_ENV);

  int error = srunner_ntests_failed(sr);
  srunner_free(sr);
  return error == 0 ? 0 : 1;
}