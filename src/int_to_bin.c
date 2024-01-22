/*
** EPITECH PROJECT, 2024
** MY_NAVY
** File description:
** convert
*/

#include <stdlib.h>
#include "../include/my.h"

static int get_bin_str(char *str, int nb)
{
    int i;

    for (i = 0; nb > 0; i++) {
        str[i] = '0' + nb % 2;
        nb = nb / 2;
    }
    return i;
}

char *int_to_bin(int nb)
{
    char *str = malloc(sizeof(char) * (32 + 1));
    int index = get_bin_str(str, nb);

    while (index < 32) {
        str[index] = '0';
        index++;
    }
    str[32] = '\0';
    str = my_revstr(str);
    return str;
}
