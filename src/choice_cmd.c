/*
** EPITECH PROJECT, 2022
** cmd.c
** File description:
** commands for 42sh
*/

#include <stdlib.h>
#include <stddef.h>
#include "shell.h"

static void free_all(char **all_cmd, char *line)
{
    my_free_array(all_cmd);
    free(line);
}

int choice_cmd(char *buffer, list_t **s)
{
    int ret = 0;
    char *line = my_clean_str(buffer, "\n");
    char **all_cmd = my_str_to_array(line, ";|&");

    if (!all_cmd)
        return (VALID);
    for (int i = 0; all_cmd[i]; i++) {
        ret = my_cmd(all_cmd[i], s);
        ret == INVALID ? bin_cmd(all_cmd[i], s) : 0;
        if (ret == EXIT)
            break;
    }
    free_all(all_cmd, line);
    return (ret);
}
