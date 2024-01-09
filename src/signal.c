/*
** EPITECH PROJECT, 2023
** B-PSU-100-PAR-1-1-navy-enzo.fokwen-rocher
** File description:
** signal.c
*/

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include "../include/navy_func.h"

char *get_new_move(int signal, int pid_to_send)
{
    if (signal == SIGUSR1) {
        kill(pid_to_send, SIGUSR1);
    }
    if (signal == SIGUSR2) {
        kill(pid_to_send, SIGUSR2);
    }
    
}