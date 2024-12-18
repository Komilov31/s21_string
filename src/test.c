#include <check.h>
#include <string.h>
// #include <float.h>
#include "s21_sprintf.h"

#define TEST_SPRINTF(format, ...)                        \
  do {                                                   \
    char str1[512] = {0};                                \
    char str2[512] = {0};                                \
    int len1 = sprintf(str1, format, ##__VA_ARGS__);     \
    int len2 = s21_sprintf(str2, format, ##__VA_ARGS__); \
    ck_assert_int_eq(len1, len2);                        \
    ck_assert_str_eq(str2, str1);                        \
  } while (0)

// Тесты для спецификатора %d и %i
START_TEST(test_specifier_d_i) {
  const char *formats[] = {"%d",     "%+i",      "% -li",    "%-10hd", "%010ld",
                           "%10.5d", "%-+10.5d", "%0+10hd", "%.0i"};
  int values[] = {0, 42, -42};

  for (size_t i = 0; i < sizeof(formats) / sizeof(formats[0]); i++) {
    for (size_t j = 0; j < sizeof(values) / sizeof(values[0]); j++) {
      TEST_SPRINTF(formats[i], values[j]);
    }
  }
}
END_TEST

// Тесты для спецификатора %u
START_TEST(test_specifier_u) {
  const char *formats[] = {"%u", "%-10lu", "%010hu", "%10.5u", "%- 10.5u"};
  unsigned int values[] = {0, 12345};

  for (size_t i = 0; i < sizeof(formats) / sizeof(formats[0]); i++) {
    for (size_t j = 0; j < sizeof(values) / sizeof(values[0]); j++) {
      TEST_SPRINTF(formats[i], values[j]);
    }
  }
}
END_TEST

// Тесты для спецификатора %o
START_TEST(test_specifier_o) {
  const char *formats[] = {"%o", "%#o", "%-10ho", "%010lo", "%10.5o", "%#10.5o"};
  unsigned int values[] = {0, 077, 123};

  for (size_t i = 0; i < sizeof(formats) / sizeof(formats[0]); i++) {
    for (size_t j = 0; j < sizeof(values) / sizeof(values[0]); j++) {
      TEST_SPRINTF(formats[i], values[j]);
    }
  }
}
END_TEST

// Тесты для спецификатора %x и %X
START_TEST(test_specifier_x_X) {
  const char *formats[] = {"%x",      "%#x", "%-10x", "%010lx", "%10.5x",
                           "%#10.5x", "%X",  "%#X",   "%-10lX", "%010X", "%-#10.5x"};
  unsigned int values[] = {0, 0x1A, 0xDEADBEE, 231};

  for (size_t i = 0; i < sizeof(formats) / sizeof(formats[0]); i++) {
    for (size_t j = 0; j < sizeof(values) / sizeof(values[0]); j++) {
      TEST_SPRINTF(formats[i], values[j]);
    }
  }
}
END_TEST

// Тесты для спецификатора %c
START_TEST(test_specifier_c) {
  const char *formats[] = {"%c", "%-5c", "%5c"};
  char values[] = {'A', 'Z', '0', ' ', '\n'};

  for (size_t i = 0; i < sizeof(formats) / sizeof(formats[0]); i++) {
    for (size_t j = 0; j < sizeof(values) / sizeof(values[0]); j++) {
      TEST_SPRINTF(formats[i], values[j]);
    }
  }
}
END_TEST

// Тесты для спецификатора %s
START_TEST(test_specifier_s) {
  const char *formats[] = {"%s", "%10s", "%-10s", "%.5s", "%10.5s", "%-10.5s"};
  const char *values[] = {"Hello", "",
                          "A very long string for testing purposes", ""};

  for (size_t i = 0; i < sizeof(formats) / sizeof(formats[0]); i++) {
    for (size_t j = 0; j < sizeof(values) / sizeof(values[0]); j++) {
      TEST_SPRINTF(formats[i], values[j]);
    }
  }
}
END_TEST

// Тесты для спецификатора %p
START_TEST(test_specifier_p) {
  const char *formats[] = {"%p", "%20p", "%-20p"};
  void *values[] = {(void *)0xDEADBEE, s21_NULL, (void *)0x0};

  for (size_t i = 0; i < sizeof(formats) / sizeof(formats[0]); i++) {
    for (size_t j = 0; j < sizeof(values) / sizeof(values[0]); j++) {
      TEST_SPRINTF(formats[i], values[j]);
    }
  }
}
END_TEST

// Тесты для %%
START_TEST(test_specifier_percent) {
  const char *formats[] = {"%%", "%%10", "%-10%"};

  for (size_t i = 0; i < sizeof(formats) / sizeof(formats[0]); i++) {
    TEST_SPRINTF(formats[i], '%');
  }
}
END_TEST

// Тесты для *.*
START_TEST(test_widacc) {
  const char *formats[] = {"%*.*d",     "%+*.*i",      "% -*.*li"};
  int values[] = {0, 42, -42};
  for (size_t i = 0; i < sizeof(formats) / sizeof(formats[0]); i++) {
    for (size_t j = 0; j < sizeof(values) / sizeof(values[0]); j++) {
      TEST_SPRINTF(formats[i], 4, 10,values[j]);
    }
  }
}
END_TEST

// Тесты для %n
START_TEST(test_spec_n) {
  const char *formats[] = {"privit %n",     "Hi %n",      "Hello %n"};
  for (size_t i = 0; i < sizeof(formats) / sizeof(formats[0]); i++) {
    int n1=0;
		int n2=0;
		char str1[512] = {0};                                
    char str2[512] = {0};                                
    int len1 = sprintf(str1, formats[i],&n1);     
    int len2 = s21_sprintf(str2, formats[i], &n2); 
    ck_assert_int_eq(len1, len2);                        
    ck_assert_int_eq(n2, n1);
  }
}
END_TEST

// Основная функция для добавления тестов
Suite *sprintf_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("s21_sprintf");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_specifier_d_i);
  tcase_add_test(tc_core, test_specifier_u);
  tcase_add_test(tc_core, test_specifier_o);
  tcase_add_test(tc_core, test_specifier_x_X);
  tcase_add_test(tc_core, test_specifier_c);
  tcase_add_test(tc_core, test_specifier_s);
  tcase_add_test(tc_core, test_specifier_p);
  tcase_add_test(tc_core, test_specifier_percent);
	tcase_add_test(tc_core, test_widacc);
	tcase_add_test(tc_core, test_spec_n);
  suite_add_tcase(s, tc_core);

  return s;
}

int main(void) {
  int number_failed;
  Suite *s;
  SRunner *sr;

  s = sprintf_suite();
  sr = srunner_create(s);

  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  return (number_failed == 0) ? 0 : 1;
}
