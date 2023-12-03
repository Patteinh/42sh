/*
** EPITECH PROJECT, 2022
** my_print_list.c
** File description:
** print linked list
*/

#include "my.h"

void my_print_list(list_t *l)
{
    for (; l->next; l = l->next) {
        my_putstr(l->line);
        my_putchar('\n');
    }
}
