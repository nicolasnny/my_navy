/*
** EPITECH PROJECT, 2024
** MY_NAVY
** File description:
** File with err handling funcs
*/

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "navy_func.h"

int get_size(char const *filePath)
{
    int fd = open(filePath, O_RDONLY);
    int size = 0;
    int r = 1;
    char buffer[20];

    if (fd == -1) {
        my_putstr_err("Error: couldn't open the file\n");
        return 0;
    }
    while (r != 0) {
        r = read(fd, buffer, 20);
        size += r;
    }
    return size;
}

static int get_size_w_coord(char *coord1, char *coord2)
{
    if (coord1[0] != coord2[0] && coord1[1] != coord2[1])
        return ERROR;
    if (coord1[0] == coord2[0])
        return coord2[1] - coord1[1] + 1;
    return coord2[0] - coord1[0] + 1;
}

static int analyse_coord(char *coord)
{
    int i = 0;

    while (coord[i]) {
        if (!(coord[i] >= '1' && coord[i] <= '8') &&
            !(coord[i] >= 'A' && coord[i] <= 'H'))
            return ERROR;
        i++;
    }
    if (i > 2)
        return ERROR;
    return 0;
}

char *get_coord(char *line)
{
    int i = 0;
    char *coord;

    while (line[i] && line[i] != '\n' && line[i] != ':')
        i++;
    if (i == 0)
        return NULL;
    coord = malloc(sizeof(char) * (i + 1));
    my_strncpy(coord, line, i);
    return coord;
}

static int check_line(char *line)
{
    int check = 0;
    int db_point_nb = 0;
    int i = 0;

    while (line[i] && line[i] != '\n') {
        if (line[i] == ':') {
            check = analyse_coord(get_coord(line + i + 1));
            db_point_nb++;
        }
        if (check == ERROR)
            return ERROR;
        i++;
    }
    if (db_point_nb != 2)
        return ERROR;
    if (my_getnbr(line) != get_size_w_coord
        (get_coord(line + 2), get_coord(line + 5)))
        return ERROR;
    return 0;
}

static int check_num(char *str)
{
    for (int i = 0; str[i]; i++) {
        if (!(str[i] >= '0' && str[i] <= '9'))
            return ERROR;
    }
    return 0;
}

static int check_buffer(char *buffer)
{
    char **lines = my_str_to_line_array(buffer);
    int nb_lines = my_strstrlen(lines);

    if (nb_lines != 4) {
        my_putstr_err("Error: expected 4 ships in the configuration file\n");
        return ERROR;
    }
    for (int i = 0; i < 4; i++) {
        if (my_getnbr(lines[i]) != i + 2)
            return ERROR;
        if (check_line(lines[i]) == ERROR) {
            clean_2d_array(lines);
            my_putstr_err("Error: in line ");
            my_put_nbr(i + 1);
            my_putstr_err(" of the config file\n");
            return ERROR;
        }
    }
    clean_2d_array(lines);
    return 0;
}

static int check_file(char *filePath)
{
    int fd;
    char *buffer;
    int r = get_size(filePath);

    if (r == 0)
        return ERROR;
    fd = fs_open_file(filePath);
    if (fd < 0)
        return ERROR;
    buffer = malloc(sizeof(char) * (r + 1));
    read(fd, buffer, r);
    buffer[r] = '\0';
    if (check_buffer(buffer) == ERROR) {
        free(buffer);
        return ERROR;
    }
    free(buffer);
    close(fd);
    return 0;
}

int err_handling(int ac, char **av)
{
    if (ac != 2 && ac != 3) {
        my_putstr_err("Error: expected 2 or 3 arguments\n");
        return ERROR;
    }
    if (ac == 2)
        return check_file(av[1]);
    if (check_num(av[1]) == ERROR) {
        my_putstr_err("Error in arguments: type \"./my_navy -h\" for help\n");
        return ERROR;
    }
    return check_file(av[2]);
}
