/*
** EPITECH PROJECT, 2022
** my_strcpy.c
** File description:
** copy string to another
*/

char *my_strcpy(char *dest, const char *src)
{
    int i;

    for (i = 0; src[i]; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return (dest);
}
