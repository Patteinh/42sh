/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** my_printf > printf
*/

#include <stdarg.h>
#include "my.h"

static void my_flags(const char *str, va_list args, int i)
{
    str[i] == 'c' ? my_putchar(va_arg(args, int)) : 0;
    str[i] == 's' ? my_putstr(va_arg(args, const char *)) : 0;
    str[i] == 'e' ? my_perror(va_arg(args, const char *)) : 0;
}

static int my_putspace(const char *str, int i)
{
    int stock = i;

    for (;str[i] == ' '; i++);
    stock < i ? my_putchar(' ') : 0;
    return (i);
}

void my_printf(char *str, ...)
{
    va_list args;
    va_start(args, str);
    int i = 0;

    while (str[i]) {
        if (str[i] == '%') {
            i++;
            i = my_putspace(str, i);
            my_flags(str, args, i);
        } else
            my_putchar(str[i]);
        i++;
    }
    va_end(args);
}
