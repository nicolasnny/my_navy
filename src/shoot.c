/*
** EPITECH PROJECT, 2024
** MY_NAVY
** File description:
** Functions related to map change after oponent shooting
*/

#include "navy_func.h"

int check_hit(char **map, char *coords)
{
    int col = 2 * (coords[0] - 'A');
    int line = coords[1] - '0' - 1;

    if (is_num(map[line][col])) {
        map[line][col] = 'x';
        return HIT;
    }
    map[line][col] = 'o';
    return MISS;
}
