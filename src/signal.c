/*
** EPITECH PROJECT, 2023
** B-PSU-100-PAR-1-1-navy-enzo.fokwen-rocher
** File description:
** signal.c
*/

#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include "../include/navy_func.h"
#include "../include/signal_codes.h"
#include "../include/my.h"

void add_one(int value)
{
    (void)value;
    sig = sig << 1;
    sig |= 1;
}

void add_zero(int value)
{
    (void)value;
    sig = sig << 1;
}

bool message_finished(void)
{
    int temp = sig;

    if (((temp >> 31) & 1) == 1) {
        sig ^= 0b10000000000000000000000000000000;
        return true;
    }
    return false;
}

void send_result(int pid, int *coords, char **filled_map)
{
    if (check_hit(filled_map, coords)) {
        send_message(pid, int_to_bin(HIT));
    } else {
        send_message(pid, int_to_bin(MISS));
    }
}

void send_message(int pid, char *message)
{
    sig = 0;
    for (int i = 0; i != 32; i++) {
        if (message[i] == '1')
            kill(pid, SIGUSR1);
        if (message[i] == '0')
            kill(pid, SIGUSR2);
        usleep(10);
    }
}
