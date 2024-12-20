#include <check.h>

#include "s21_string.h"

START_TEST(memchrTest) {
  char test0_ar[] = "school21";
  char test0_s = 'h';
  char test1_ar[] = "ararat";
  char test1_s = 'a';
  char test2_ar[] = "123456789";
  char test2_s = '&';
  char test3_ar[] = "Hello, World!";
  char test3_s = '\0';
  char test4_ar[] = "privet privet";
  char test4_s = ' ';
  char test5_ar[] = "hi4";
  char test5_s = '4';
  char test6_ar[] = "123554";
  char test6_s = '5';
  char test7_ar[] = "1234";
  char test7_s = '3';
  char test8_ar[] = "/.?<,|>#$^&*(#@!;)";
  char test8_s = '$';
  char test9_ar[] = "verterPlsLetPass";
  char test9_s = 'P';

  ck_assert_uint_eq((unsigned long)s21_memchr(test0_ar, test0_s, 8),
                    (unsigned long)memchr(test0_ar, test0_s, 8));
  ck_assert_uint_eq((unsigned long)s21_memchr(test1_ar, test1_s, 6),
                    (unsigned long)memchr(test1_ar, test1_s, 6));
  ck_assert_uint_eq((unsigned long)s21_memchr(test2_ar, test2_s, 9),
                    (unsigned long)memchr(test2_ar, test2_s, 9));
  ck_assert_uint_eq((unsigned long)s21_memchr(test3_ar, test3_s, 13),
                    (unsigned long)memchr(test3_ar, test3_s, 13));
  ck_assert_uint_eq((unsigned long)s21_memchr(test4_ar, test4_s, 13),
                    (unsigned long)memchr(test4_ar, test4_s, 13));
  ck_assert_uint_eq((unsigned long)s21_memchr(test5_ar, test5_s, 2),
                    (unsigned long)memchr(test5_ar, test5_s, 2));
  ck_assert_uint_eq((unsigned long)s21_memchr(test6_ar, test6_s, 1),
                    (unsigned long)memchr(test6_ar, test6_s, 1));
  ck_assert_uint_eq((unsigned long)s21_memchr(test7_ar, test7_s, 4),
                    (unsigned long)memchr(test7_ar, test7_s, 4));
  ck_assert_uint_eq((unsigned long)s21_memchr(test8_ar, test8_s, 18),
                    (unsigned long)memchr(test8_ar, test8_s, 18));
  ck_assert_uint_eq((unsigned long)s21_memchr(test9_ar, test9_s, 16),
                    (unsigned long)memchr(test9_ar, test9_s, 16));
}
END_TEST

START_TEST(memsetTest) {
  char test0_ar[22] = "GOGOGOschool21!GOGOGO";
  char test1_ar[22] = "PLSverterPlsLetPassPLS";
  char test0_ar_copy[22];
  char test1_ar_copy[22];

  strcpy(test0_ar_copy, test0_ar);
  strcpy(test1_ar_copy, test1_ar);

  ck_assert_str_eq(s21_memset(test0_ar, '-', 8), memset(test0_ar_copy, '-', 8));
  ck_assert_str_eq(s21_memset(test0_ar, ' ', 6), memset(test0_ar_copy, ' ', 6));
  ck_assert_str_eq(s21_memset(test0_ar, '\0', 9),
                   memset(test0_ar_copy, '\0', 9));
  ck_assert_str_eq(s21_memset(test0_ar, '!', 13),
                   memset(test0_ar_copy, '!', 13));
  ck_assert_str_eq(s21_memset(test0_ar, '%', 13),
                   memset(test0_ar_copy, '%', 13));
  ck_assert_str_eq(s21_memset(test1_ar, '@', 2), memset(test1_ar_copy, '@', 2));
  ck_assert_str_eq(s21_memset(test1_ar, '>', 1), memset(test1_ar_copy, '>', 1));
  ck_assert_str_eq(s21_memset(test1_ar, '6', 4), memset(test1_ar_copy, '6', 4));
  ck_assert_str_eq(s21_memset(test1_ar, '[', 18),
                   memset(test1_ar_copy, '[', 18));
  ck_assert_str_eq(s21_memset(test1_ar, '?', 16),
                   memset(test1_ar_copy, '?', 16));
}
END_TEST

START_TEST(memcpyTest) {
  char *test0_src = "!GOGOGO";
  char test0_dst[30] = "GOGOGOschool21";
  char *test0_srcO = "!GOGOGO";
  char test0_dstO[30] = "GOGOGOschool21";
  char *test1_src = "";
  char test1_dst[30] = "";
  char *test1_srcO = "";
  char test1_dstO[30] = "";
  char *test2_src = "Privet";
  char test2_dst[30] = "\0";
  char *test2_srcO = "Privet";
  char test2_dstO[30] = "\0";
  char *test3_src = "1234567890";
  char test3_dst[30] = "";
  char *test3_srcO = "1234567890";
  char test3_dstO[30] = "";
  char *test4_src = "verterPLS";
  char test4_dst[30] = "letPass";
  char *test4_srcO = "verterPLS";
  char test4_dstO[30] = "letPass";

  ck_assert_str_eq(s21_memcpy(test0_dst, test0_src, strlen(test0_src) + 1),
                   memcpy(test0_dstO, test0_srcO, strlen(test0_src) + 1));
  ck_assert_str_eq(s21_memcpy(test1_dst, test1_src, strlen(test1_src) + 1),
                   memcpy(test1_dstO, test1_srcO, strlen(test1_src) + 1));
  ck_assert_str_eq(s21_memcpy(test2_dst, test2_src, strlen(test2_src) + 1),
                   memcpy(test2_dstO, test2_srcO, strlen(test2_src) + 1));
  ck_assert_str_eq(s21_memcpy(test3_dst, test3_src, strlen(test3_src) + 1),
                   memcpy(test3_dstO, test3_srcO, strlen(test3_src) + 1));
  ck_assert_str_eq(s21_memcpy(test4_dst, test4_src, strlen(test4_src) + 1),
                   memcpy(test4_dstO, test4_srcO, strlen(test4_src) + 1));
}
END_TEST

START_TEST(memcmpTest) {
  char test0src[] = "GOGOGOschool";
  char test0[] = "GOGOGOschool";
  char test1src[] = "school21";
  char test1[] = "schol21";
  char test2src[] = "\0";
  char test2[] = "\0";
  char test3src[] = "Verter\0 pls";
  char test3[] = "Verter\0 pls";
  char test4src[] = "";
  char test4[] = "";
  char test5src[] = "\0priv";
  char test5[] = "\0";
  char test6src[] = "priv";
  char test6[] = "\0";
  char test7src[] = "1234";
  char test7[] = "123";
  char test8src[] = "123";
  char test8[] = "1234";
  char test9src[] = "123dsf";
  char test9[] = "123asu";
  ck_assert_int_eq(s21_memcmp(test0src, test0, strlen(test0src)), memcmp(test0src, test0, strlen(test0src)));
  ck_assert_int_eq(s21_memcmp(test1src, test1,s21_strlen(test1src)), memcmp(test1src, test1,s21_strlen(test1src)));
  ck_assert_int_eq(s21_memcmp(test2src, test2,s21_strlen(test2src)), memcmp(test2src, test2,s21_strlen(test2src)));
  ck_assert_int_eq(s21_memcmp(test3src, test3,s21_strlen(test3src)), memcmp(test3src, test3,s21_strlen(test3src)));
  ck_assert_int_eq(s21_memcmp(test4src, test4,s21_strlen(test4src)), memcmp(test4src, test4,s21_strlen(test4src)));
  ck_assert_int_eq(s21_memcmp(test5src, test5,s21_strlen(test5src)), memcmp(test5src, test5,s21_strlen(test5src)));
  ck_assert_int_eq(s21_memcmp(test6src, test6,s21_strlen(test6src)), memcmp(test6src, test6,s21_strlen(test6src)));
  ck_assert_int_eq(s21_memcmp(test7src, test7,s21_strlen(test7src)), memcmp(test7src, test7,s21_strlen(test7src)));
  ck_assert_int_eq(s21_memcmp(test8src, test8,s21_strlen(test8src)), memcmp(test8src, test8,s21_strlen(test8src)));
  ck_assert_int_eq(s21_memcmp(test9src, test9,s21_strlen(test9src)), memcmp(test9src, test9,s21_strlen(test9src)));
}
END_TEST

START_TEST(strlenTest) {
  char test0[] = "SCHOOL21";
  char test1[] = "VERTER LET PASS PLS)))";
  char test2[] = ".!.\0";
  char test3[] = "(>-<)";
  char test4[] = "1bgf\045dsf";
  char test5[] = "qqq\\\0";
  char test6[] = "";
  char test7[] = "1234";
  char test8[] = "qqq\\\0";
  char test9[] = "1657/343kfljf3;l14\'";

  ck_assert_int_eq(s21_strlen(test0), strlen(test0));
  ck_assert_int_eq(s21_strlen(test1), strlen(test1));
  ck_assert_int_eq(s21_strlen(test2), strlen(test2));
  ck_assert_int_eq(s21_strlen(test3), strlen(test3));
  ck_assert_int_eq(s21_strlen(test4), strlen(test4));
  ck_assert_int_eq(s21_strlen(test5), strlen(test5));
  ck_assert_int_eq(s21_strlen(test6), strlen(test6));
  ck_assert_int_eq(s21_strlen(test7), strlen(test7));
  ck_assert_int_eq(s21_strlen(test8), strlen(test8));
  ck_assert_int_eq(s21_strlen(test9), strlen(test9));
}
END_TEST

START_TEST(strncmpTest) {
  char test0_0[] = "SCHOOL21";
  char test0_1[] = "SC3OOL21";
  char test1_0[] = "VERTER LET PASS PLS)))";
  char test1_1[] = "VERTER LET PASS PLS)))";
  char test2_0[] = ".!.\0";
  char test2_1[] = ".!.\0";
  char test3_0[] = "(>-<)";
  char test3_1[] = "(>-<)";
  char test4_0[] = "1bgf\045dsf";
  char test4_1[] = "1bgf\045dsf";
  char test5_0[] = "qqq\\\0";
  char test5_1[] = "qqq\\\0";
  char test6_0[] = "";
  char test6_1[] = "";
  char test7_0[] = "1234";
  char test7_1[] = "1234";
  char test8_0[] = "qqq\\\0";
  char test8_1[] = "qqq\\\0";
  char test9_0[] = "1657/343kfljf3;l14\'";
  char test9_1[] = "1657/343kfljf3;l14\'";

  ck_assert_int_eq(s21_strncmp(test0_0, test0_1, s21_strlen(test0_0)),
                   strncmp(test0_0, test0_1, s21_strlen(test0_0)));
  ck_assert_int_eq(s21_strncmp(test1_0, test1_1, s21_strlen(test1_0)),
                   strncmp(test1_0, test1_1, s21_strlen(test1_0)));
  ck_assert_int_eq(s21_strncmp(test2_0, test2_1, s21_strlen(test2_0)),
                   strncmp(test2_0, test2_1, s21_strlen(test2_0)));
  ck_assert_int_eq(s21_strncmp(test3_0, test3_1, s21_strlen(test3_0)),
                   strncmp(test3_0, test3_1, s21_strlen(test3_0)));
  ck_assert_int_eq(s21_strncmp(test4_0, test4_1, s21_strlen(test4_0)),
                   strncmp(test4_0, test4_1, s21_strlen(test4_0)));
  ck_assert_int_eq(s21_strncmp(test5_0, test5_1, s21_strlen(test5_0)),
                   strncmp(test5_0, test5_1, s21_strlen(test5_0)));
  ck_assert_int_eq(s21_strncmp(test6_0, test6_1, s21_strlen(test6_0)),
                   strncmp(test6_0, test6_1, s21_strlen(test6_0)));
  ck_assert_int_eq(s21_strncmp(test7_0, test7_1, s21_strlen(test7_0)),
                   strncmp(test7_0, test7_1, s21_strlen(test7_0)));
  ck_assert_int_eq(s21_strncmp(test8_0, test8_1, s21_strlen(test8_0)),
                   strncmp(test8_0, test8_1, s21_strlen(test8_0)));
  ck_assert_int_eq(s21_strncmp(test9_0, test9_1, s21_strlen(test9_0)),
                   strncmp(test9_0, test9_1, s21_strlen(test9_0)));
}
END_TEST

START_TEST(strchrTest) {
  char str0_0[] = "SCHOOL21";
  int symb0_0 = '2';
  char str0_1[] = "SCHOOL21";
  int symb0_1 = '2';
  char str1_0[] = "hello verteeeer";
  int symb1_0 = ' ';
  char str1_1[] = "hello verteeeer";
  int symb1_1 = ' ';
  char str2_0[] = "1bgf\045dsf";
  int symb2_0 = '\0';
  char str2_1[] = "1bgf\045dsf";
  int symb2_1 = '\0';
  char str3_0[] = "VERTER LET PASS PLS";
  int symb3_0 = 'V';
  char str3_1[] = "VERTER LET PASS PLS";
  int symb3_1 = 'V';
  char str4_0[] = "jhsdfakjfhq2kljhsdkjnb123";
  int symb4_0 = 'j';
  char str4_1[] = "jhsdfakjfhq2kljhsdkjnb123";
  int symb4_1 = 'j';
  ck_assert_str_eq(s21_strchr(str0_0, symb0_0), strchr(str0_1, symb0_1));
  ck_assert_str_eq(s21_strchr(str1_0, symb1_0), strchr(str1_1, symb1_1));
  ck_assert_str_eq(s21_strchr(str2_0, symb2_0), strchr(str2_1, symb2_1));
  ck_assert_str_eq(s21_strchr(str3_0, symb3_0), strchr(str3_1, symb3_1));
  ck_assert_str_eq(s21_strchr(str4_0, symb4_0), strchr(str4_1, symb4_1));
}
END_TEST

START_TEST(strncatTest) {
  char str0_0[] = "SCHOOL21";
  char src0_0[] = "GOGOGO";
  char str0_1[] = "SCHOOL21";
  char src0_1[] = "GOGOGO";
  char str1_0[] = "if we can";
  char src1_0[] = " we doooo";
  char str1_1[] = "if we can";
  char src1_1[] = " we doooo";
  char str2_0[] = "1bgasdff\045dsasfasdff";
  char src2_0[] = "\0";
  char str2_1[] = "1bgasdff\045dsasfasdff";
  char src2_1[] = "\0";
  char str3_0[] = "sakldjfaslbvasadf";
  char src3_0[] = "\0V";
  char str3_1[] = "sakldjfaslbvasadf";
  char src3_1[] = "\0V";
  char str4_0[] = "sdfsadfsdfakcjnael;tdjka;lck";
  char src4_0[] = "jsdafklsdjf;klasdfj ;lasnf;askdjfn";
  char str4_1[] = "sdfsadfsdfakcjnael;tdjka;lck";
  char src4_1[] = "jsdafklsdjf;klasdfj ;lasnf;askdjfn";
  ck_assert_str_eq(s21_strncat(str0_0, src0_0, s21_strlen(str0_0)),
                   strncat(str0_1, src0_1, s21_strlen(str0_1)));
  ck_assert_str_eq(s21_strncat(str1_0, src1_0, s21_strlen(str1_0)),
                   strncat(str1_1, src1_1, s21_strlen(str1_1)));
  ck_assert_str_eq(s21_strncat(str2_0, src2_0, s21_strlen(str2_0)),
                   strncat(str2_1, src2_1, s21_strlen(str2_1)));
  ck_assert_str_eq(s21_strncat(str3_0, src3_0, s21_strlen(str3_0)),
                   strncat(str3_1, src3_1, s21_strlen(str3_1)));
  ck_assert_str_eq(s21_strncat(str4_0, src4_0, s21_strlen(str4_0)),
                   strncat(str4_1, src4_1, s21_strlen(str4_1)));
}
END_TEST

int main(void) {
  Suite *sc = suite_create("s21_string");
  TCase *testCase = tcase_create("s21_string");
  SRunner *sr = srunner_create(sc);
  int countOfMissedTests;
  suite_add_tcase(sc, testCase);

  tcase_add_test(testCase, memchrTest);
  tcase_add_test(testCase, memsetTest);
  tcase_add_test(testCase, memcpyTest);
  tcase_add_test(testCase, memcmpTest);
  tcase_add_test(testCase, strlenTest);
  tcase_add_test(testCase, strncmpTest);
  tcase_add_test(testCase, strchrTest);
  tcase_add_test(testCase, strncatTest);

  srunner_run_all(sr, CK_ENV);
  countOfMissedTests = srunner_ntests_failed(sr);

  srunner_free(sr);
  if (countOfMissedTests == 0) {
    printf("All tests passed!\n");
  } else {
    printf("Some tests failed!\n");
  }
  return countOfMissedTests == 0 ? 0 : 1;
}