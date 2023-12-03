/*
** EPITECH PROJECT, 2022
** my_unsetenv;c
** File description:
** my unsetenv cmd
*/

#include <stdlib.h>
#include <stddef.h>
#include "shell.h"

static int remove_last(list_t **ms, list_t *tmp, char *i)
{
    tmp = (*ms);

    for (; tmp->next->next; tmp = tmp->next)
        if (!my_strncmp(tmp->next->next->line, i, my_strlen(i))) {
            list_t *last = tmp->next->next;
            tmp->next->next = NULL;
            free(last->line);
            free(last);
            return (SUCCESS);
        }
    return (ERROR);
}

static int remove_in_list(list_t *tmp)
{
    list_t *tmp2 = NULL;

    if (tmp->next == NULL)
        return (ERROR);
    tmp2 = tmp->next;
    free(tmp->next->line);
    tmp->next = tmp2->next;
    free(tmp2);
    return (SUCCESS);
}

static int remove_node(list_t *tmp, list_t **ms, char *i)
{
    for (; tmp->next; tmp = tmp->next)
        if (!my_strncmp(tmp->next->line, i, my_strlen(i)) && tmp->next->next)
            return (remove_in_list(tmp));
    return (remove_last(ms, tmp, i));
}

static void remove_env(list_t **ms, char *index)
{
    list_t *tmp = (*ms);

    if (!my_strncmp(tmp->line, index, my_strlen(index))) {
        (*ms) = (*ms)->next;
        free(tmp->line);
        free(tmp);
    } else
        remove_node(tmp, ms, index);
}

int my_unsetenv(char **cmd, list_t **ms)
{
    (cmd[1]) ? remove_env(ms, cmd[1]) : my_putstr(UNSETENV_ERROR);
    return (VALID);
}
