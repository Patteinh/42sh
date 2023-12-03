/*
** EPITECH PROJECT, 2022
** shell.h
** File description:
** shell.h
*/

#include "my.h"

#ifndef _SHELL_H_
    #define _SHELL_H_

static const char PROMPT[] = ">";
static const char NO_F[] = "No such file or directory.";
static const char NO_DIR[] = "Not a directory.";
static const char ENV_ERROR[] = "env : Too many arguments\n";
static const char UNSETENV_ERROR[] = "unsetenv: Too few arguments.\n";
static const char SETENV_TO_ARGS_ERROR[] = "setenv: Too many arguments.\n";
static const char SETENV_ALPHANUM_ERROR[] =
"setenv: Variable name must contain alphanumeric characters.\n";
static const char SEGFAULT[] = "Segmentation fault\n";
static const char SEGFAULTD[] = "Segmentation fault (core dumped)\n";
static const char FLOATING[] = "Floating exception\n";
static const char FLOATINGD[] = "Floating exception (core dumped)\n";
static const char *const ALL_CMD[] =
{"exit", "cd", "env", "unsetenv", "setenv"};

static const int LENPATH = 1000;
static const int NB_CMD = 5;
static const int EXIST = 0;
static const int NOT_EXIST = 1;
static const int SUCCESS = 0;
static const int ERROR = 1;
static const int EXIT_ERROR = 84;
static const int VALID = 0;
static const int INVALID = 1;
static const int EXIT = 2;

typedef struct exec_s {
    char *ipath;
    char *execp;
    char *execp2;
    char **paths;
    char **cmd;
} exec_t;

int  is_cmd_exist(char *index, list_t **s);
char *search_index(list_t **s, char *index);
int  choice_cmd(char *buffer, list_t **s);
int  my_cmd(char *cmd_tmp, list_t **s);
int  bin_cmd(char *cmd_tmp, list_t **s);
int  my_exit(char **cmd, list_t **s);
int  my_cd(char **cmd, list_t **s);
int  my_env(char **cmd, list_t **s);
int  my_unsetenv(char **cmd, list_t **s);
int  my_setenv(char **cmd, list_t **s);
void free_ex(exec_t *ex);

static int (*const MY_CMD[])(char **cmd, list_t **s) =
{my_exit, my_cd, my_env, my_unsetenv, my_setenv};

#endif
