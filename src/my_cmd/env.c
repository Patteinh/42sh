/*
** EPITECH PROJECT, 2022
** env.c
** File description:
** my env cmd
*/

#include <stddef.h>
#include <stddef.h>
#include "shell.h"

int my_env(char **cmd, list_t **s)
{
    cmd[1] ? my_putstr(ENV_ERROR) : my_print_list(*s);
    return (VALID);
}
