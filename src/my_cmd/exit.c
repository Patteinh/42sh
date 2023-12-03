/*
** EPITECH PROJECT, 2022
** exit.c
** File description:
** my exit cmd
*/

#include "shell.h"

int my_exit(char **cmd, list_t **s)
{
    (void)cmd;
    (void)s;
    my_putstr("exit\n");
    return (EXIT);
}
