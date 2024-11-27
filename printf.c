#include "main.h"

/**
 * _printf - Produces output based on a format string
 * @format: The format string containing the characters and format specifiers
 *
 * Return: The total number of characters printed (excluding the null byte)
 */

int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;
    char c, *str;
    int i;

    va_start(args, format);  /* Start processing variable arguments */
    
    for (i = 0; format && format[i] != '\0'; i++)
    {
        if (format[i] == '%')  /* If a format specifier is found */
        {
            i++;  /* Skip the '%' character */
            
            if (format[i] == 'c')  /* Handle %c (character) */
            {
                c = va_arg(args, int);  /* Get the character argument */
                write(1, &c, 1);
                count++;
            }
            else
            {
                if (format[i] == 's')  /* Handle %s (string) */
                {
                    str = va_arg(args, char *);  /* Get the string argument */
                    while (*str)
                    {
                        write(1, str++, 1);
                        count++;
                    }
                }
                else
                {
                    if (format[i] == '%')  /* Handle %% (literal %) */
                    {
                        write(1, "%", 1);
                        count++;
                    }
                }
            }
        }
        else  /* If it's just a normal character, print it */
        {
            write(1, &format[i], 1);
            count++;
        }
    }

    va_end(args);  /* Clean up the va_list */
    return (count);  /* Return the number of characters printed */
}