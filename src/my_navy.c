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
    sig = info->si_pid;
}

static int get_guest_pid(void)
{
    int r;
    struct sigaction s;

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

    printf("my_pid: %d\n", host_pid);
    printf("waiting for connection...\n");
    guest_pid = get_guest_pid();
    printf("connected\n");
    guest_pid = sig;
    map = get_map(pos);
    printf("before launching game\n");
    launch_host_game(map, host_pid, guest_pid);
}

int guest_connect(char *pid, char *pos)
{
    char **map;
    int guest_pid = getpid();
    int host_pid = my_getnbr(pid);

    printf("my_pid: %d\n", getpid());
    kill(host_pid, SIGUSR1);
    send_message(host_pid, int_to_bin(getpid()));
    map = get_map(pos);
    printf("before launching game\n");
    launch_guest_game(map, host_pid, guest_pid);
    return 0;
}
