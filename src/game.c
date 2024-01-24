/*
** EPITECH PROJECT, 2023
** B-PSU-100-PAR-1-1-navy-enzo.fokwen-rocher
** File description:
** game.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "../include/navy_func.h"
#include "../include/signal_codes.h"
#include "navy_func.h"

static int *wait_for_attack(int *coords)
{
    sig = 0;
    mini_printf("\nwaiting for enemy's attack...\n");
    while (!message_finished());
    coords[0] = sig;
    sig = 0;
    while (!message_finished());
    coords[1] = sig;
    sig = 0;
    return coords;
}

static char *get_row(char *buffer)
{
    int row = buffer[1] - '0';

    if (row > 0 && row < 9)
        return int_to_bin(row - 1);
    return NULL;
}

static char *get_col(char *buffer)
{
    switch (buffer[0]) {
        case 'A':
            return int_to_bin(0);
        case 'B':
            return int_to_bin(1);
        case 'C':
            return int_to_bin(2);
        case 'D':
            return int_to_bin(3);
        case 'E':
            return int_to_bin(4);
        case 'F':
            return int_to_bin(5);
        case 'G':
            return int_to_bin(6);
        case 'H':
            return int_to_bin(7);
        default:
            return NULL;
    }
}

static ssize_t get_user_move(char **user_input, size_t *bufsize)
{
    ssize_t line_size = 0;

    line_size = getline(user_input, bufsize, stdin);
    if (line_size != 0)
        user_input[line_size - 1] = '\0';
    if (line_size == -1 && my_strlen(*user_input) == 0)
        return 0;
    if (!get_row(*user_input)) {
        my_putstr("\nwrong position\n");
        return 0;
    }
    if (!get_col(*user_input)) {
        my_putstr("\nwrong position\n");
        return 0;
    }
    return 1;
}

static void attack(int pid)
{
    char *user_input = NULL;
    size_t bufsize = 0;
    ssize_t line_size = 0;

    while (line_size == 0) {
        mini_printf("attack: ");
        line_size = get_user_move(&user_input, &bufsize);
    }
    send_message(pid, get_col(user_input));
    send_message(pid, get_row(user_input));
    mini_printf("result: ");
    my_putstr_no_break(user_input);
    while(!message_finished());
    if (sig == HIT) {
        my_putstr(":hit\n");
    }
    else
        my_putstr(":missed\n");
}

void launch_host_game(char **map, int guest_pid)
{
    char **enemy_map = create_map();
    int *coords = malloc(sizeof(int) * 2);

    while (!lose(map)) {
        sig = 0;
        my_putstr("my navy:\n");
        display_map(map);
        my_putstr("\nenemy map:\n");
        display_map(enemy_map);
        attack(guest_pid);
        coords = wait_for_attack(coords);
        // send_result(guest_pid, coords, map);
    }
}

void launch_guest_game(char **map, int host_pid)
{
    char **enemy_map = create_map();
    int *coords = malloc(sizeof(int) * 2);
    // printf("host pid = %d\n", host_pid);

    while (!lose(map)) {
        sig = 0;
        my_putstr("my navy:\n");
        display_map(map);
        my_putstr("\nenemy map:\n");
        display_map(enemy_map);
        coords = wait_for_attack(coords);
        send_result(host_pid, coords, map);
        attack(host_pid);
    }
}
