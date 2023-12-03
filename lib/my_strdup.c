/*
** EPITECH PROJECT, 2022
** my_strdup
** File description:
** malloc copy string
*/

#include <stdlib.h>
#include "my.h"

char *my_strdup(const char *src)
{
    char *dest = malloc(sizeof(char) * (my_strlen(src) + 1));

    if (!src || !dest)
        return (NULL);
    dest = my_strcpy(dest, src);
    return (dest);
}
