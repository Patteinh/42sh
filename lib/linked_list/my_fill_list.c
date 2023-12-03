/*
** EPITECH PROJECT, 2022
** fill_linked_list.c
** File description:
** fill linked list
*/

#include <stdlib.h>
#include "my.h"

static void add_first_node(list_t **l, char *var)
{
    (*l) = malloc(sizeof(list_t));
    (*l)->line = my_strdup(var);
    (*l)->next = NULL;
}

static void add_end_node(list_t **l, char *var)
{
    list_t *tmp = (*l);

    for (; tmp->next; tmp = tmp->next);
    tmp->next = malloc(sizeof(list_t));
    tmp->next->line = my_strdup(var);
    tmp->next->next = NULL;
}

void add_node(list_t **l, char *var)
{
    (!(*l)) ? add_first_node(l, var) : add_end_node(l, var);
}

void my_fill_list(list_t **l, char **var)
{
    (*l) = NULL;

    for (int i = 0; var[i]; i++)
        add_node(l, var[i]);
}
