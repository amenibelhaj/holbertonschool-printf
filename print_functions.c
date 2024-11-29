#include "main.h"

int print_char(va_list args) {
    char c = va_arg(args, int);
    return write(1, &c, 1);
}

int print_string(va_list args) {
    char *str = va_arg(args, char*);
    int count = 0;
    if (!str) str = "(null)";
    while (*str) {
        count += write(1, str++, 1);
    }
    return count;
}
