GCC=gcc
FLAGS = -Wall -Werror -Wextra
CHECKFLAGS = -lcheck -lrt -lpthread

s21_test:
	$(GCC) -o tests tests.c s21_memchr.c s21_memset.c s21_memcpy.c s21_memcmp.c s21_strlen.c s21_strncmp.c s21_strchr.c s21_strncat.c $(CHECKFLAGS) $(FLAGS)

clean:
	rm tests

rebuild: clean s21_test

clang: clangCp
	clang-format -n *.c *.h
	clang-format -i *.c *.h
	rm .clang-format

clangCp:
	cp ../materials/linters/.clang-format .clang-format