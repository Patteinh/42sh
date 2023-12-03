/*
** EPITECH PROJECT, 2022
** my_str_to_array.c
** File description:
** str to array with delim
*/

#include <stdlib.h>
#include <stddef.h>

static int no_delim(const char c, const char *d)
{
    for (int i = 0; d[i]; i++)
        if (c == d[i])
            return (1);
    return (0);
}

static int its_delim(const char *str, int i, const char *d)
{
    if (no_delim(str[i], d)) {
        for (; no_delim(str[i], d); i++);
        i--;
    }
    return (i);
}

static int count_word(const char *str, const char *d)
{
    int w = 1;

    if (!str)
        return (0);
    for (int i = 0; str[i]; i++, w++)
        i = its_delim(str, i, d);
    return (w);
}

static int len_w(const char *str, int i, const char *d)
{
    int len = 0;

    for (; !no_delim(str[i], d) && str[i]; len++, i++);
    return (len);
}

char **my_str_to_array(char *str, const char *d)
{
    int nb_words = count_word(str, d);
    char **array = malloc(sizeof(char *) * (nb_words + 1));
    int i = 0;
    int line = 0;

    if (!str || !array || !nb_words) {
        free(array);
        return (NULL);
    }
    for (int c = 0; str[i]; c = 0, line++) {
        for (; no_delim(str[i], d) && str[i]; i++);
        array[line] = malloc(sizeof(char) * (len_w(str, i, d) + 1));
        for (; !no_delim(str[i], d) && str[i]; i++ , c++)
            array[line][c] = str[i];
        array[line][c] = '\0';
        for (; no_delim(str[i], d) && str[i]; i++);
    }
    array[line] = NULL;
    return (array);
}
