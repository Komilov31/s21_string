#include <check.h>
#include <string.h>
// #include <float.h>
#include "s21_sprintf.h"  // Подключите ваш заголовочный файл

#define TEST_SPRINTF(format, ...)                                    \
  do {                                                               \
    char str1[512] = {0};                                            \
    char str2[512] = {0};                                            \
    int len1 = sprintf(str1, format, ##__VA_ARGS__);                 \
    int len2 = s21_sprintf(str2, format, ##__VA_ARGS__);             \
    printf(                                                          \
        "format: |%s|\nlen1 = |%d| str1 = |%s|\nlen2 = |%d| str2 = " \
        "|%s|\n==============================\n",                    \
        format, len1, str1, len2, str2);                             \
  } while (0)

int main() {
  // const char *formats[] = {
  //       "%d", "%+7.7d", "% d", "%-10d", "%010d", "%10.5d", "%-+10.5d",
  //       "%0+10d", "%.0d"
  //   };
  //   int values[] = {0, 42, -42};

  // const char *formats[] = {
  //     "%o", "%#o", "%-10o", "%0#10o", "%10.5o", "%#10.5o"
  // };
  // unsigned int values[] = {0, 077, 123};

  // const char *formats[] = {
  //     "%x", "%#x", "%-10x", "%010x", "%10.5x", "%#.12x", "%X", "%#X",
  //     "%-10lX", "%010X"
  // };
  // unsigned int values[] = {0, 0x1A, 0x7FFFFFFF};
	// char str1[512];
	// char str2[512];
  // s21_sprintf(str1, "Space: |%-*.*ld|", 12, 4, 10);
  // sprintf(str2, "Space: |%-*.*d|", 12, , 10);
	
  // printf("%s\n%s\n", str1, str2);

 const char *formats[] = {"% .2Lg", "% 2g", "%- 30.15Lg"};
  long double values[] = {0.000034342, 135.23, 2453.2322434};


// const char *formats[] = {"%s", "%10s", "%-10s", "%.5s", "%10.5s", "%-10.5s"};
//   const char *values[] = {"Hello", "",
//                           "A very long string for testing purposes", ""};
													
  for (size_t i = 0; i < sizeof(formats) / sizeof(formats[0]); i++) {
    for (size_t j = 0; j < sizeof(values) / sizeof(values[0]); j++) {
      TEST_SPRINTF(formats[i], values[j], 4, 10);
    }
  }
  return 0;
}