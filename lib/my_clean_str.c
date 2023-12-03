/*
** EPITECH PROJECT, 2022
** my_clean_str.c
** File description:
** remove unwanted letters from string
*/

#include <stdlib.h>
#include <stddef.h>

static int no_delim(char c, const char *d)
{
    for (int i = 0; d[i]; i++)
        if (c == d[i])
            return (1);
    return (0);
}

static int count_letter(char *str, const char *d)
{
    int len = 0;

    if (!str)
        return (-1);
    for (int i = 0; str[i]; i++)
        if (!no_delim(str[i], d))
            len++;
    return (len);
}

char *my_clean_str(char *str, const char *d)
{
    int len = count_letter(str, d);
    char *new = malloc(sizeof(char) * (len + 1));
    int i = 0;
    int j = 0;

    if (!str || !new || len == -1) {
        free(new);
        return (NULL);
    }
    while (str[i]) {
        for (; str[i] && no_delim(str[i], d); i++);
        for (; str[i] && !no_delim(str[i], d); i++, j++)
            new[j] = str[i];
    }
    new[j] = '\0';
    return (new);
}
