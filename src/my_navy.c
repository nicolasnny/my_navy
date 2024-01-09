/*
** EPITECH PROJECT, 2024
** MY_NAVY
** File description:
** my_navy
*/

#include "navy_func.h"

int my_navy(int ac, char **av)
{
    int check = err_handling(ac, av);
    char **map;

    if (check == ERROR)
        return ERROR;
    map = get_map(av[ac - 1]);
    return 0;
}
