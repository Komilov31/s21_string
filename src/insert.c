#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *insert(const char *src, const char *str, size_t start_index);

int main() {
  char src[] = "testing string";
  char str[] = "this ";
  char *with_insertion = insert(src, str, 8);
  printf("%s", with_insertion);
  free(with_insertion);
  return 0;
}

void *insert(const char *src, const char *str, size_t start_index) {
  char *string_with_insertion = NULL;
  if (src && str && start_index <= strlen(src)) {
    string_with_insertion =
        malloc((strlen(src) + strlen(str) + 1) * sizeof(char));
    size_t i = 0;
    for (; i < start_index; i++) {
      string_with_insertion[i] = src[i];
    }
    size_t end_of_src = i;
    for (size_t j = 0; j < strlen(str); i++, j++) {
      string_with_insertion[i] = str[j];
    }
    for (; end_of_src < strlen(src); end_of_src++, i++) {
      string_with_insertion[i] = src[end_of_src];
    }
    string_with_insertion[strlen(string_with_insertion)] = '\0';
  }
  return (void *)string_with_insertion;
}