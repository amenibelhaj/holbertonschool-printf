#include "main.h"

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
else if (*ptr == '%')
{
count += write(1, "%", 1);
count += write(1, ptr, 1);
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
