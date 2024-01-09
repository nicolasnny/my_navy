/*
** EPITECH PROJECT, 2024
** MY_NAVY
** File description:
** Function to create the map and get the config information
*/

#include <stdlib.h>
#include <unistd.h>
#include "navy_func.h"

static char *get_file_content(char *filepath)
{
    int fd = fs_open_file(filepath);
    int size = get_size(filepath);
    char *buffer = malloc(sizeof(char) * (size + 1));

    read(fd, buffer, size);
    buffer[size] = '\0';
    return buffer;
}

static char **get_coords(char *filepath)
{
    char *buffer = get_file_content(filepath);
    char **file_content = my_str_to_line_array(buffer);
    char **res = malloc(sizeof(char *) * (SHIP_NB * 2 + 1));
    char *line;
    int coord_nb = 0;
    int line_nb = 0;

    while (line_nb < SHIP_NB && coord_nb < SHIP_NB * 2) {
        line = file_content[line_nb];
        res[coord_nb] = get_coord(line + 2);
        coord_nb++;
        res[coord_nb] = get_coord(line + 5);
        line_nb++;
    }
    res[coord_nb] = NULL;
    free(buffer);
    return res;
}

char **get_map(char *filepath)
{
    char **coords = get_coords(filepath);

    return NULL;
}
