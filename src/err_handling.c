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

static int get_size(char const *filePath)
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

static int check_num(char *str)
{
    for (int i = 0; str[i]; i++) {
        if (!(str[i] >= '1' && str[i] <= '9'))
            return ERROR;
    }
    return 0;
}

static int check_buffer(char *buffer)
{
    (void)buffer;
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
