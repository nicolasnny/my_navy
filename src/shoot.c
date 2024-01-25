/*
** EPITECH PROJECT, 2024
** MY_NAVY
** File description:
** Functions related to map change after oponent shooting
*/

#include <stdbool.h>
#include "signal_codes.h"
#include "navy_func.h"

int check_hit(char **map, int *coords)
{
    int col = coords[0] * 2;
    int line = coords[1];

    if (is_num(map[line][col])) {
        map[line][col] = 'x';
        return true;
    }
    if (map[line][col] != 'x')
        map[line][col] = 'o';
    return false;
}

void fill_empty_map(char **map, int *coords, int state)
{
    int col = coords[0] * 2;
    int line = coords[1] - 1;

    if (state == HIT)
        map[line][col] = 'x';
    if (map[line][col] != 'x')
        map[line][col] = 'o';
}
