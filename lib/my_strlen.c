/*
** EPITECH PROJECT, 2022
** my_strlen.c
** File description:
** count char in string
*/

int my_strlen(const char *str)
{
    int size = 0;

    for (; str[size]; size++);
    return (size);
}
