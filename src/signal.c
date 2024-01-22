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

void show_bytes(unsigned value) { 
  for (unsigned i = 0; i < sizeof(int); i++) { 
    const unsigned char byte = value % UCHAR_MAX; 
    value /= UCHAR_MAX; 
    printf("%u ", byte); 
  } 
}

void wait_for_signal(int pid)
{
    while (!sig.value);
}

void send_message(int pid, char *message)
{   
    sig.value = 0;
    printf("message : %s", message);
    printf("\n");
    for (int i = 0; i != 32; i++) {
        if (message[i] == '1') {
            printf("sending SIGUSR1\n");
            kill(pid, SIGUSR1);
        }
        if (message[i] == '0') {
            printf("sending SIGUSR2\n");
            kill(pid, SIGUSR2);
        }
        usleep(10);
    }
}