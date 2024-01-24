/*
** EPITECH PROJECT, 2024
** MY_NAVY
** File description:
** Functions related to map change after oponent shooting
*/

#include <stdbool.h>
#include "navy_func.h"

int check_hit(char **map, int *coords)
{
    int col = coords[0] * 2;
    int line = coords[1];

    if (is_num(map[line][col])) {
        map[line][col] = 'x';
        return true;
    }
    map[line][col] = 'o';
    return false;
}
