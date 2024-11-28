#include "main.h"
#include <unistd.h>
#include <stdarg.h>

/**
 * _printf - Produces output based on a format string.
 * @format: The format string containing characters and format specifiers.
 * Return: The total number of characters printed (excluding the null byte).
 */
int _printf(const char *format, ...)
{
va_list args;
int count = 0;
const char *ptr = format;
if (format == NULL)
return (-1);
va_start(args, format);
while (*ptr)
{
if (*ptr == '%' && *(ptr + 1) == '\0')
return (-1);
if (*ptr == '%' && *(ptr + 1))
{
ptr++;
if (*ptr == 'c')
{
char c = va_arg(args, int);
count += write(1, &c, 1);
}
else if (*ptr == 's')
{
char *str = va_arg(args, char*);
if (!str)
str = "(null)";
while (*str)
count += write(1, str++, 1);
}
else if (*ptr == 'd' || *ptr == 'i')
{
int num = va_arg(args, int);
count += print_integer(num);
}
else if (*ptr == '%')
{
count += write(1, "%", 1);
}}
else
{
count += write(1, ptr, 1);
}
ptr++;
}
va_end(args);
return (count);
}


/**
 * print_integer - Helper function to print an integer.
 * @num: The integer to print.
 * Return: The number of characters printed.
 */
int print_integer(int num)
{
int count = 0;
int temp = num;
int digits = 0;
int i;
int j;
int divisor;
char digit;
if (num < 0)
{
count += write(1, "-", 1);
num = -num;
}
temp = num;
while (temp != 0)
{
digits++;
temp /= 10;
}
if (num == 0)
{
count += write(1, "0", 1);
return count;
}
for (i = digits - 1; i >= 0; i--)
{
divisor = 1;
for (j = 1; j < digits; j++)
divisor *= 10;
digit = (num / divisor) + '0';
count += write(1, &digit, 1);
num %= divisor;
digits--;
}
return (count);
}
