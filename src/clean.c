/*
** EPITECH PROJECT, 2024
** MY_NAVY
** File description:
** Func to clean everything
*/

#include <stdlib.h>
#include "navy_func.h"

void clean_2d_array(char **array)
{
    int size = my_strstrlen(array);

    for (int i = 0; i < size; i++)
        free(array[i]);
    free(array);
}
