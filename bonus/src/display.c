/*
** EPITECH PROJECT, 2024
** MY_NAVY
** File description:
** Dislay everything related to my_navy project
*/

#include <ncurses.h>
#include "navy_func.h"

int display_map(char **map)
{
    int size = my_strstrlen(map);

    if (size != MAP_SIZE)
        return ERROR;
    move(line + 3, 0);
    printw(" |A B C D E F G H\n");
    move(line + 4, 0);
    printw("-+---------------\n");
    for (int line = 0; line < MAP_SIZE; line++)
        printw("%d|%s\n", line + 1, map[line]);
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
