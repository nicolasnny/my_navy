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
    my_putstr("-+---------------\n");
    for (int line = 0; line < 8; line++) {
        my_put_nbr(line + 1);
        my_putchar('|');
        my_putstr(map[line]);
        my_putchar('\n');
    }
    return 0;
}

int display_flag_h(void)
{
    my_putstr("USAGE\n");
    my_putstr("\t./my_navy [first_player_pid] navy_positions\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("\tfirst_player_pid: only for the 2nd player.");
    my_putstr("pid of the first player.\n");
    my_putstr("\tnavy_positions: file representing the postitions");
    my_putstr("of the ships.\n");
    return 1;
}
