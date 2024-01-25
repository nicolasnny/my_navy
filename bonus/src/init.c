/*
** EPITECH PROJECT, 2024
** MY_NAVY
** File description:
** Function to create the map and get the config information
*/

#include <stdlib.h>
#include <unistd.h>
#include "navy_func.h"

int is_num(char c)
{
    return (c >= '0' && c <= '9');
}

char **create_map(void)
{
    char **map = malloc(sizeof(char *) * (MAP_SIZE + 1));
    int line = 0;

    while (line < MAP_SIZE) {
        map[line] = malloc(sizeof(char) * (MAP_SIZE * 2 + 1));
        for (int i = 0; i < MAP_SIZE * 2; i += 2) {
            map[line][i] = '.';
            map[line][i + 1] = ' ';
        }
        map[line][MAP_SIZE * 2] = '\0';
        line++;
    }
    map[0][0] = '+';
    map[line] = NULL;
    return map;
}

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
        coord_nb++;
        line_nb++;
    }
    res[coord_nb] = NULL;
    free(buffer);
    return res;
}

static int put_ship_line(char **map, int num, char *coord1, char *coord2)
{
    int line = coord2[1] - '0' - 1;
    int col1 = (coord1[0] - 'A') * 2;
    int col2 = (coord2[0] - 'A') * 2;

    while (col1 <= col2) {
        if (is_num(map[line][col1]))
            return ERROR;
        map[line][col1] = num + '0';
        col1 += 2;
    }
    return 0;
}

static int put_ship_col(char **map, int num, char *coord1, char *coord2)
{
    int line1 = coord1[1] - '0' - 1;
    int line2 = coord2[1] - '0';
    int col = (coord1[0] - 'A') * 2;

    while (line1 < line2) {
        if (is_num(map[line1][col]))
            return ERROR;
        map[line1][col] = num + '0';
        line1++;
    }
    return 0;
}

//static int put_ship(char **map, )
static int put_ships(char **map, int num, char *coord1, char *coord2)
{
    if (coord1[1] == coord2[1])
        return put_ship_line(map, num, coord1, coord2);
    return put_ship_col(map, num, coord1, coord2);
}

char **get_map(char *filepath)
{
    char **map = create_map();
    char **coords = get_coords(filepath);
    int coord_nb = 0;
    int ret = 0;

    map[0][0] = '+';
    for (int i = 0; i < SHIP_NB && ret == 0; i++) {
        ret = put_ships(map, i + 2, coords[coord_nb], coords[coord_nb + 1]);
        coord_nb += 2;
    }
    clean_2d_array(coords);
    if (ret == ERROR) {
        my_putstr_err("Error: couldn't place the ships correctly\n");
        clean_2d_array(map);
        return NULL;
    }
    return map;
}
