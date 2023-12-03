/*
** EPITECH PROJECT, 2022
** setenv.c
** File description:
** my setenv cmd
*/

#include <stdlib.h>
#include <stddef.h>
#include "shell.h"

static int error_gestion_setenv(char **cmd)
{
    int len = my_lenarray(cmd);
    int check = 0;

    len > 3 ? my_perror(SETENV_TO_ARGS_ERROR), check++ : 0;
    my_str_isalpha(cmd[1]) ? my_perror(SETENV_ALPHANUM_ERROR), check++ : 0;
    return ((check != VALID) ? (INVALID) : (VALID));
}

static void add_exist(list_t **ms, char *add, char *index)
{
    list_t *tmp;

    tmp = (*ms);
    for (;tmp; tmp = tmp->next)
        if (!my_strncmp(tmp->line, index, my_strlen(index))) {
            free(tmp->line);
            tmp->line = NULL;
            add != NULL ? tmp->line = my_strcat(index, add) : 0;
            add == NULL ? tmp->line = my_strdup(index) : 0;
    }
}

static void add_not_exist(list_t **ms, char *add, char *index)
{
    list_t *tmp2 = (*ms);
    list_t *tmp = malloc(sizeof(list_t));

    add != NULL ? tmp->line = my_strcat(index, add) : 0;
    add == NULL ? tmp->line = my_strdup(index) : 0;
    tmp->next = NULL;
    for (;tmp2->next; tmp2 = tmp2->next);
    tmp2->next = tmp;
    tmp2->next->next = NULL;
}

static int add_env(list_t **ms, char *add, char *index, int exist)
{
    index = my_strcat(index, "=");

    (exist == 0) ? add_exist(ms, add, index) : add_not_exist(ms, add, index);
    free(index);
    return (VALID);
}

int my_setenv(char **cmd, list_t **ms)
{
    if (error_gestion_setenv(cmd))
        return (VALID);
    if (cmd[1])
        return (add_env(ms, cmd[2], cmd[1], is_cmd_exist(cmd[1], ms)));
    return (my_env(cmd, ms));
}
