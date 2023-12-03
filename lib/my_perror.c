/*
** EPITECH PROJECT, 2022
** my_putstr_e
** File description:
** display string on error exit
*/

#include <unistd.h>

void my_perror(const char *str)
{
    for (; *str; str++)
        write(2, &(*str), 1);
}
