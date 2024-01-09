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

    if (check == ERROR)
        return ERROR;
    return 0;
}
