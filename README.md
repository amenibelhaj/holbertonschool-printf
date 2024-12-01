# printf Implementation
# Description


This project provides a custom implementation of the printf function, called _printf, which mimics the standard printf function in C. It can handle different format specifiers and outputs the formatted string to the standard output (console).

The function supports:

%c for characters.
%s for strings.
%d and %i for integers.
%% for printing a literal percentage symbol.
Additionally, it includes a helper function, print_integer, that is used to handle the printing of integer values.

# Files 

main.h: Header file containing function prototypes and necessary library includes.
_printf.c: Contains the implementation of the _printf function.
print_integer.c: Contains the implementation of the helper function print_integer that handles printing integers.

# Functionality : 

<h3> int _printf(const char *format, ...);</h3>

This is the main function that performs formatted output. It takes a format string and an unspecified number of arguments (using ...) and prints the output to the console based on the format specifiers in the format string.

Arguments:
format: A string that contains text and format specifiers.
Return:
The function returns the number of characters printed (excluding the null byte).
The function supports the following format specifiers:

%c: Print a character.
%s: Print a string.
%d / %i: Print an integer.
%%: Print a literal '%' character.
If an invalid format specifier is provided, the function simply prints the % character and moves on.


# print_integer:

<h3> int print_integer(int num);</h3>

This is a helper function that prints an integer to the console. It handles both positive and negative numbers and outputs the appropriate string of digits.

Arguments:

num: The integer to be printed.
Return:

The function returns the number of characters printed.
The function also ensures that the - sign is correctly printed for negative integers.





# Compilation

gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-format *.c


# Usage : 

To use the _printf function, you can call it just like the standard printf function.

# Error Handling :

If the format string is NULL, _printf will return -1 to indicate an error.
If a format specifier is incomplete or invalid (e.g., % without a specifier), _printf will return -1.

## README file
# !{flowchart} (![alt text](16448F0B-32C3-4AF7-B526-C4636C71F970.jpeg))