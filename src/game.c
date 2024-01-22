/*
** EPITECH PROJECT, 2023
** B-PSU-100-PAR-1-1-navy-enzo.fokwen-rocher
** File description:
** game.c
*/

#include <stdio.h>
#include "../include/navy_func.h"
#include "../include/signal_codes.h"

static void wait_for_attack(void)
{
    return;
}

static int get_row(char *buffer)
{
    int row = buffer[1] + '0';

    if (row > 0 && row < 9)
        return int_to_bin(row);
}

static int get_col(char *buffer)
{
    switch (buffer[1]) {
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
            return 84;
    }
}

static void attack(int pid)
{
    char *user_input;
    size_t bufsize = 0;
    int col;
    int row;
    int state;

    my_putstr("attack: ");
    getline(&user_input, &bufsize, stdin);
    if (my_strlen(user_input) > 2 && get_col(user_input) != ERROR &&
        get_row(user_input) != ERROR) {
        send_message(pid, get_col(user_input));
        send_message(pid, get_row(user_input));
    } else {
        my_putstr("wrong position\n");
        attack(pid);
    }
    my_putstr("result: ");
    my_putstr(user_input);
    if (sig & HIT)
        my_putstr(":hit\n");
    else
        my_putstr(":missed\n");
}

void launch_host_game(char **map, int host_pid, int guest_pid)
{
    char **enemy_map = create_map();

    while (lose(map)) {
        sig = 0;
        my_putstr("my navy:\n");
        display_map(map);
        my_putstr("\nenemy map:\n");
        display_map(enemy_map);
        attack(guest_pid);
        wait_for_attack();
    }
}

void launch_guest_game(char **map, int host_pid, int guest_pid)
{
    char **enemy_map = create_map();

    while (lose(map)) {
        wait_for_attack();
        my_putstr("my navy:\n");
        display_map(map);
        my_putstr("\nenemy map:\n");
        display_map(enemy_map);
        attack(host_pid);
    }
}
