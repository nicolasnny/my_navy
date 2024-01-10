/*
** EPITECH PROJECT, 2024
** MY_NAVY
** File description:
** Dislay everything related to my_navy project
*/

#include "navy_func.h"

int display_map(char **map)
{
    int size = my_strstrlen(map);

    if (size != MAP_SIZE)
        return ERROR;
    my_putstr(" |A B C D E F G H\n");
    my_putstr("-+----------------\n");
    for (int line = 0; line < 8; line++) {
        my_put_nbr(line + 1);
        my_putchar('|');
        my_putstr(map[line]);
        my_putchar('\n');
    }
    return 0;
}
