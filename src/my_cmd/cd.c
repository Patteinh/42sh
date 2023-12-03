/*
** EPITECH PROJECT, 2022
** my_cd.c
** File description:
** my cd cmd
*/

#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include "shell.h"

static void change(list_t **s, char *new, char *index)
{
    list_t *tmp = (*s);

    if (!new)
        return;
    for (; tmp; tmp = tmp->next)
        if (!my_strncmp(tmp->line, index, my_strlen(index))) {
            free(tmp->line);
            tmp->line = NULL;
            tmp->line = my_strdup(new);
        }
    free(new);
}

static int error_gestion_cd(list_t **s, char *path, char **old)
{
    int len = my_strlen(search_index(s, "PWD=")) + my_strlen("PWD=");
    (*old) = malloc(sizeof(char) * (len + 1));

    if (access(path, F_OK) == -1) {
        my_printf("%e: %e\n", path, NO_F);
        free(path);
        return (INVALID);
    }
    getcwd(*old, len);
    if (search_index(s, "OLDPWD="))
        change(s, my_strcat("OLDPWD=", (*old)), "OLDPWD=");
    free(*old);
    if (chdir(path)) {
        my_printf("%e: %e\n", path, NO_DIR);
        free(path);
        return (INVALID);
    }
    free(path);
    return (VALID);
}

static int change_env_cd(list_t **s)
{
    int len_pwd = my_strlen(search_index(s, "PWD=")) + my_strlen("PWD=");
    char *buffer = malloc(sizeof(char) * (len_pwd + 1));


    if (getcwd(buffer, len_pwd) == NULL)
        my_putstr("error");
    if (search_index(s, "PWD="))
        change(s, my_strcat("PWD=", buffer), "PWD=");
    free(buffer);
    return (VALID);
}

static int check_opt(char *cmd, char **path, list_t **s)
{
    if (!cmd || !my_strcmp(cmd, "~"))
        (*path) = my_strdup(search_index(s, "HOME="));
    else if (!my_strcmp(cmd, "-"))
        (*path) = my_strdup(search_index(s, "OLDPWD="));
    else
        (*path) = my_strdup(cmd);
    return (!(*path) ? (ERROR) : (SUCCESS));
}

int my_cd(char **cmd, list_t **s)
{
    char *path = NULL;
    char *old = NULL;

    if (check_opt(cmd[1], &path, s))
        return (INVALID);
    if (error_gestion_cd(s, path, &old))
        return (VALID);
    return (change_env_cd(s));
}
