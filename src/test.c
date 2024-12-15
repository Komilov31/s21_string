#include "s21_sprintf.c"

int main() {
  char str1[512];
  char str2[512];
  // s21_sprintf(str1, "Hello #%10.7d# and #%+1.1d#", 0, 123);
  // s21_sprintf(str1, "Positive: %+d, Negative: %+d", 42, -42);
  s21_sprintf(str1, "Space: |%-#12.7X|", 0xf2f);
  // sprintf(str2, "Space: |%+#12.7X|", 0xf2f);
  // sprintf(str2, "Hello #%10.7d# and #%+1.1d#", 0, 123);
  printf("|%s|\n|%s|\n", str1, str2);
  return 0;
}

//"%-+5d", 123
//"%5.5d", 123

//% +d должна быть ошибка