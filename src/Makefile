CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11 
CHECKFLAGS = -lcheck -lsubunit -lm -lrt -lpthread
SOURCES = s21_sprintf.c tests.c s21_memchr.c s21_memset.c s21_memcpy.c s21_memcmp.c s21_strlen.c s21_strncmp.c s21_strchr.c s21_strncat.c s21_strcspn.c s21_strerror.c s21_strncpy.c s21_strpbrk.c s21_strrchr.c s21_strstr.c s21_strtok.c
OBJECTS = $(SOURCES:.c=.o)
VALGRIND = valgrind --tool=memcheck --leak-check=yes 

all: s21_sprintf

s21_sprintf: $(OBJECTS)
	$(CC) $(CFLAGS) -o s21_sprintf $^ $(CHECKFLAGS)
	$(VALGRIND) ./s21_sprintf

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean: 
	rm -rf $(OBJECTS) s21_sprintf *.gcno *.gcda *.gcov *.info report tests.out

gcov_report: $(SOURCES)
	gcc -fprofile-arcs -ftest-coverage $(SOURCES) -o tests.out $(CHECKFLAGS)
	./tests.out
	lcov --rc lcov_branch_coverage=1 -t "stest" -o s21_test.info -c -d .
	genhtml --rc lcov_branch_coverage=1 -o report s21_test.info --output-directory report
	xdg-open report/index.html

clang:
	clang-format -i --style=Google *.c *.h

rebuild: clean all
