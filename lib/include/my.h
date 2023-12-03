/*
** EPITECH PROJECT, 2022
** lib.h
** File description:
** lib.h
*/

#ifndef _MY_H_
    #define _MY_H_

typedef struct list_s {
    char *line;
    struct list_s *next;
} list_t;

void my_putchar(char c);
void my_putstr(const char *str);
void my_perror(const char *str);
int  my_strlen(const char *str);
int  my_lenarray(char **array);
int  my_atoi(char const *str);
int  my_strlen(const char *str);
char *my_strcat(const char *left, const char *right);
char *my_strcpy(char *dest, const char *src);
char *my_strdup(const char *src);
int  my_strcmp(char const *s1, const char *s2);
int  my_strncmp(char const *s1, char const *s2, int n);
void my_printf(char *str, ...);
char *my_clean_str(char *str, const char *d);
int  my_str_isalpha(char *str);
char **my_str_to_array(char *str, const char *d);
void my_parray(char **array);
void my_free_array(char **array);
void my_fill_list(list_t **l, char **var);
void add_node(list_t **l, char *var);
void my_print_list(list_t *l);
void my_free_list(list_t *l);

#endif
