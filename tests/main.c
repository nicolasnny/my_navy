/*
** EPITECH PROJECT, 2023
** MY_RADAR
** File description:
** Main of the my_radar project
*/

#include <signal.h>
#include "../include/navy_func.h"

int main(int ac, char **av)
{
    int check = err_handling(ac, av);

    signal(SIGUSR1, add_one);
    signal(SIGUSR2, add_zero);
    if (check == ERROR)
        return ERROR;
    if (ac == 2)
        return host_connect(av[1]);
    if (ac == 3)
        return guest_connect(av[1], av[2]);
    return 84;
}
