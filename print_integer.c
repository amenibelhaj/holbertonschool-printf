#include "main.h"
/**
 * print_integer - Helper function to print an integer.
 * @num: The integer to print.
 * Return: The number of characters printed.
 */
int print_integer(int num)
{
int count = 0;
unsigned int n;
if (num < 0)
{
if (num == -2147483648)
{
count += write(1, "-2147483648", 11);
return (count);
}
count += write(1, "-", 1);
n = -num;
}
else
{
n = num;
}
if (n == 0)
{
count += write(1, "0", 1);
}
else
{
char digits[10];
int i = 0;
while (n > 0)
{
digits[i] = (n % 10) + '0';
n /= 10;
i++;
}
while (--i >= 0)
{
count += write(1, &digits[i], 1);
}}
return (count);
}
