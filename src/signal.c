/*
** EPITECH PROJECT, 2023
** B-PSU-100-PAR-1-1-navy-enzo.fokwen-rocher
** File description:
** signal.c
*/

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "../include/signal_codes.h"

void add_one(int value)
{
    sig = sig << 1;
    sig |= sig | 1;
}

void add_zero(int value)
{
    sig = sig << 1;
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
