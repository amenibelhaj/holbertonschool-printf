#include "main.h"

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
return (count);
}
for (i = digits - 1; i >= 0; i--)
{
divisor = 1;
for (j = 1; j < digits; j++)
divisor *= 10;
digit = (num / divisor) +'0';
count += write(1, &digit, 1);
num %= divisor;
digits--;
}
return (count);
}
