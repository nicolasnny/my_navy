/*
** EPITECH PROJECT, 2024
** MY_NAVY
** File description:
** Functions to determine if the player lost the game
*/

#include <stddef.h>
#include "navy_func.h"

int lose(char **map)
{
    int found = 0;

    for (int line = 0; map[line] != NULL; line++) {
        for (int col = 0; map[line][col] && !found; col++)
            found = is_num(map[line][col]);
        if (found)
            return 0;
    }
    return 1;
}
