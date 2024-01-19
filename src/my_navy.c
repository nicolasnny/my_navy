/*
** EPITECH PROJECT, 2024
** MY_NAVY
** File description:
** my_navy
*/

#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../include/navy_func.h"

char *host_move;
char *guest_move;

void host_action(int value)
{
    (void)value;
    printf("is host_action\n");
    host_move = malloc(sizeof(char) * 2);
    printf("attack : ");
    scanf("%s", host_move);
    printf("you've attacked on : %s\n", host_move);
}

void guest_action(int value)
{
    (void)value;
    printf("in guest action\n");
    guest_move = malloc(sizeof(char) * 2);
    printf("attack: ");
    scanf("%s", guest_move);
    printf("you've attacked on : %s\n", guest_move);
}

int my_navy(int ac, char **av)
{
    int check = err_handling(ac, av);
    //int pid = getpid();
    char **map;
    /*int host_pid;
    bool connected = false;
    struct sigaction host_act;
    struct sigaction guest_act;

    host_act.sa_handler = &host_action;
    guest_act.sa_handler = &guest_action;
    sigaction(SIGUSR1, &host_act, NULL);
    sigaction(SIGUSR2, &guest_act, NULL);*/
    if (check == ERROR)
        return ERROR;
    if (check)
        return 0;
    /*if (ac == 3)
        host_pid = my_getnbr(av[1]);
    if (ac == 2)
        host_pid = getpid();
    printf("pid : %d\n", getpid());
    while(1) {
        if (connected)
            host_move = get_new_move(SIGUSR1, host_pid);
        if (pid != host_pid) {
            guest_move = get_new_move(SIGUSR2, pid);
            connected = true;
        }
        }*/
    (void)map;
    map = get_map(av[ac - 1]);
    if (map == NULL)
        return ERROR;
    display_map(map);
    check_hit(map, "H8");
    display_map(map);
    printf("checking loose: %d\n", lose(map));
    return 0;
}
