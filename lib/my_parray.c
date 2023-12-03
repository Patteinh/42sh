/*
** EPITECH PROJECT, 2022
** my_putstr_array
** File description:
** print line array
*/

#include <unistd.h>
#include "my.h"

void my_parray(char **array)
{
    for (; *array; array++) {
        write(1, (*array), my_strlen(*array));
        write(1, &("\n"), 1);
    }
}
