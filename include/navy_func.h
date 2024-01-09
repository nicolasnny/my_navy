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

//--> main
int my_navy(int, char **);

//--> init
char **get_map(char *filepath);
char *get_coord(char *line);

//--> error handling
int err_handling(int ac, char **av);
int get_size(char const *filepath);

//--> cleaning func
void clean_2d_array(char **array);

#endif
