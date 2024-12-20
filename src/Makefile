GCC=gcc
FLAGS = -Wall -Werror -Wextra
CHECKFLAGS = -lcheck -lrt -lpthread
FILES = tests.c s21_memchr.c s21_memset.c s21_memcpy.c \
s21_memcmp.c s21_strlen.c s21_strncmp.c s21_strchr.c s21_strncat.c \
s21_strcspn.c s21_strerror.c s21_strncpy.c s21_strpbrk.c s21_strrchr.c \
s21_strstr.c s21_strtok.c

s21_test:
	$(GCC) -o tests  $(CHECKFLAGS) $(FLAGS)

clean:
	rm tests

rebuild: clean s21_test

clang: clangCp
	clang-format -n *.c *.h
	clang-format -i *.c *.h
	rm .clang-format

clangCp:
	cp ../materials/linters/.clang-format .clang-format