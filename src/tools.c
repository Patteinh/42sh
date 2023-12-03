/*
** EPITECH PROJECT, 2022
** set_create.c
** File description:
** set and create tools
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "shell.h"

int is_cmd_exist(char *index, list_t **s)
{
    list_t *tmp = (*s);

    for (; tmp; tmp = tmp->next)
        if (!my_strncmp(tmp->line, index, my_strlen(index)))
            return (EXIST);
    return (NOT_EXIST);
}

char *search_index(list_t **s, char *index)
{
    list_t *tmp = (*s);

    for (; tmp; tmp = tmp->next)
        if (!my_strncmp(tmp->line, index, my_strlen(index)))
            return (&tmp->line[my_strlen(index)]);
    return (NULL);
}

void free_ex(exec_t *ex)
{
    my_free_array(ex->cmd);
    free(ex);
}
