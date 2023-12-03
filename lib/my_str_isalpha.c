/*
** EPITECH PROJECT, 2022
** is alpha
** File description:
** is alpha
*/

int my_str_isalpha(char *str)
{
    for (int i = 0; str[i]; i++) {
        if ((str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122))
            continue;
        return (1);
    }
    return (0);
}
