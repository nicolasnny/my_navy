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

sig_val sig;

void add_one(int value)
{
    sig.value = sig.value << 1;
	sig.value |= sig.value | 1;
    sig.index++;
    usleep(100);
}

void add_zero(int value)
{
    sig.value = sig.value << 1;
    sig.index++;
    usleep(100);
}

int my_navy(int ac, char **av)
{
    int check = err_handling(ac, av);
    char **map;
    int guest_pid;
    int host_pid;
    bool connected = false;
    signal(SIGUSR1, add_one);
    signal(SIGUSR2, add_zero);

    if (check == ERROR)
        return ERROR;
    if (ac == 3) {
        host_pid = my_getnbr(av[1]);
        printf("guest pid : %d\n", getpid());
        send_message(host_pid, int_to_bin(getpid()));
        while (sig.index != 32);
    }
    if (ac == 2) {
        host_pid = getpid();
        printf("waiting for connection...\n");
        printf("host pid = %d\n", host_pid);
        wait_for_signal(host_pid);
    }
    guest_pid = sig.value;
    printf("value = %d\n", sig.value);
    printf("index = %d\n", sig.index);

    while(1);
    map = get_map(av[ac - 1]);
    return 0;
}
