#ifndef S21_STRING_H_
#define S21_STRING_H_

#include <stdio.h>
#include <stdarg.h>
#include <math.h>
#include <stdlib.h>

typedef unsigned long s21_size_t;
#define s21_NULL (void*)0


int s21_sprintf(char *str, const char *format, ...);

#endif