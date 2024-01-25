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
#include "../include/signal_codes.h"
#include "../lib/my/my.h"

int sig;

static void guest_pid(int value, siginfo_t *info, void *context)
{
    (void)context;
    (void)value;
    sig = info->si_pid;
}

static int get_guest_pid(void)
{
    struct sigaction s;
    int sigset_array_size = (1024 / (8 * sizeof(unsigned long int)));
    sigset_t sigset;

    for (int i = 0; i != sigset_array_size; i++)
        sigset.__val[i] = 0;
    s.sa_handler = NULL;
    s.sa_mask = sigset;
    s.sa_restorer = NULL;
    s.sa_sigaction = &guest_pid;
    s.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &s, NULL);
    while (!sig);
    return sig;
}

int host_connect(char *pos)
{
    char **map;
    int guest_pid;
    int host_pid = getpid();

    mini_printf("my_pid: %d\n", host_pid);
    mini_printf("\nwaiting for enemy...\n");
    guest_pid = get_guest_pid();
    signal(SIGUSR1, add_one);
    signal(SIGUSR2, add_zero);
    mini_printf("\nenemy connected\n");
    guest_pid = sig;
    map = get_map(pos);
    if (!launch_host_game(map, guest_pid)) {
        mini_printf("\nenemy won\n");
        return 0;
    }
    mini_printf("\nI won\n");
    return 1;
}

int guest_connect(char *pid, char *pos)
{
    char **map;
    int host_pid = my_getnbr(pid);

    mini_printf("my_pid: %d\n", getpid());
    signal(SIGUSR1, add_one);
    signal(SIGUSR2, add_zero);
    kill(host_pid, SIGUSR1);
    mini_printf("\nsuccessfully connected to enemy\n");
    map = get_map(pos);
    if (!launch_guest_game(map, host_pid)) {
        mini_printf("\nenemy won\n");
        return 0;
    }
    mini_printf("\nI won\n");
    return 1;
}

int my_navy(int ac, char **av)
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
