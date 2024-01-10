/*
** EPITECH PROJECT, 2023
** MY_NAVY
** File description:
** Functions for the my_navy project
*/

#ifndef NAVY_FUNC_H
    #define NAVY_FUNC_H
    #include "my.h"
    #include "navy_struct.h"

//---> constant values
    #define ERROR 84
    #define SHIP_NB 4
    #define MAP_SIZE 8
    #define HIT 1
    #define MISS 0

//--> main
int my_navy(int, char **);

//--> init
char **get_map(char *filepath);
char *get_coord(char *line);
int is_num(char c);

//--> error handling
int err_handling(int ac, char **av);
int get_size(char const *filepath);

//--> cleaning func
void clean_2d_array(char **array);

//-->signal handling
char *get_new_move(int signal, int pid_to_send);

//--> display
int display_map(char **map);
int display_flag_h(void);

//--> game
int check_hit(char **map, char *coords);

#endif
