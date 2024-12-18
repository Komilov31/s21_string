CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11 
CHECKFLAGS = -lcheck -lsubunit -lm -lrt -lpthread
SOURCES = s21_sprintf.c test.c
OBJECTS = $(SOURCES:.c=.o)
VALGRIND = valgrind --tool=memcheck --leak-check=yes --leak-check=full --show-leak-kinds=all -s

all: s21_sprintf

s21_sprintf: $(OBJECTS)
	$(CC) $(CFLAGS) -o s21_sprintf $^ $(CHECKFLAGS)
	$(VALGRIND) ./s21_sprintf

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean: 
	rm -rf $(OBJECTS) s21_sprintf *.gcno *.gcda *.gcov *.info report

gcov_report: $(SOURCES)
	gcc -fprofile-arcs -ftest-coverage $(SOURCES) -o test $(CHECKFLAGS)
	./test
	lcov --rc lcov_branch_coverage=1 -t "stest" -o s21_test.info -c -d .
	genhtml --rc lcov_branch_coverage=1 -o report s21_test.info --output-directory report --exclude test.c
	xdg-open report/index.html

clang:
	clang-format -i --style=Google *.c *.h

rebuild: clean all
