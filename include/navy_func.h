/*
** EPITECH PROJECT, 2023
** MY_NAVY
** File description:
** Functions for the my_navy project
*/

#ifndef NAVY_FUNC_H
    #define NAVY_FUNC_H
    #include <stdbool.h>
    #include "my.h"
    #include "navy_struct.h"

//---> constant values
    #define ERROR 84
    #define SHIP_NB 4
    #define MAP_SIZE 8

//--> main
int guest_connect(char *pid, char *pos);
int host_connect(char *pos);
int my_navy(int ac, char **av);

//--> users
int guest_connect(char *pid, char *pos);
int host_connect(char *pos);

//--> init
char **get_map(char *filepath);
char *get_coord(char *line);
int is_num(char c);
char **create_map(void);

//--> error handling
int err_handling(int ac, char **av);
int get_size(char const *filepath);

//--> cleaning func
void clean_2d_array(char **array);

//-->signal handling
void send_message(int pid, char *message);
void add_zero(int value);
void add_one(int value);
bool message_finished(void);
void send_result(int pid, int *coords, char **filled_map);


//--> display
int display_map(char **map);
int display_flag_h(void);

//--> game
int check_hit(char **map, int *coords);
int lose(char **map);
int launch_host_game(char **map, int guest_pid);
int launch_guest_game(char **map, int host_pid);
void fill_empty_map(char **map, int *coords, int state);

//--> convert
char *int_to_bin(int nb);

#endif
