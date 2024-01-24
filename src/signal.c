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
#include <stdbool.h>
#include "../include/signal_codes.h"
#include "../include/my.h"

void print_bits(unsigned int value)
{
    int numBits = sizeof(value) * 8;
    unsigned int bit;

    for (int i = numBits - 1; i >= 0; i--) {
        bit = (value >> i) & 1;
        printf("%u", bit);
    }
    printf("\n");
}

static void send_bit(int pid, int bit)
{
    if (bit)
        kill(pid, SIGUSR1);
    else
        kill(pid, SIGUSR2);
    usleep(10);
}

void add_one(int value)
{
    sig = sig << 1;
    sig |= 1;
}

void add_zero(int value)
{
    sig = sig << 1;
}

static void send_end_sequence(int pid)
{
    int bit;

    for (int i = 32; i > 25; --i) {
        bit = (END_OF_MSG >> i)&1;
        send_bit(pid, bit);
    }
}

bool message_finished(void)
{
    print_bits(sig);
    if ((sig << 24) == END_OF_MSG) {
        printf("message finished\n");
        sig &= 0xFF;
        return true;
    }
    return false;
}

void send_message(int pid, char *message)
{
    sig = 0;
    for (int i = 0; i != my_strlen(message); i++) {
        if (message[i] == '1')
            send_bit(pid, 1);
        if (message[i] == '0')
            send_bit(pid, 0);
        usleep(10);
    }
    send_end_sequence(pid);
    printf("final sig value = ");
    print_bits(sig);
}
