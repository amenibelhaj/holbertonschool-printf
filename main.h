#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

int print_integer(int num);
int _printf(const char *format, ...);
int print_char(va_list args);
int print_string(va_list args);
void _putchar(char c);

#endif
