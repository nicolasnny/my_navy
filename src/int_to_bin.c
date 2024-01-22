/*
** EPITECH PROJECT, 2024
** MY_NAVY
** File description:
** convert
*/

#include <stdlib.h>

static int get_bin_size(int nb)
{
    int size = 0;

    while (nb > 0) {
        nb /= 2;
        size++;
    }
    return size;
}

static void get_bin_str(char *str, int nb, int i)
{
    if (nb / 2 > 0)
        get_bin_str(str, nb / 2, i + 1);
    str[i] = '0' + nb % 2;
}

char *int_to_bin(int nb)
{
    char *str = malloc(sizeof(char) * (32 + 1));
    int i = 32 - get_bin_size(nb);

    get_bin_str(str, nb, i);
    for (int index = 0; index < 32  && str[index] != '1'; index++)
        str[index] = '0';
    str[32] = '\0';
    printf("converted bin = %s\n", str);
    return str;
}
