/*
** EPITECH PROJECT, 2024
** MY_NAVY
** File description:
** Patterns needed to get the end of a msg
*/

#include "navy_func.h"

static int add_one_to_bin(unsigned int nb)
{
    nb = nb << 1;
    nb |= 1;
    return nb;
}

static int add_zero_to_bin(unsigned int nb)
{
    nb = nb << 1;
    return nb;
}

int add_pattern(unsigned int nb)
{
    unsigned int pattern = 0;

    pattern = add_zero_to_bin(pattern);
    pattern = add_zero_to_bin(pattern);
    pattern = add_one_to_bin(pattern);
    pattern = add_zero_to_bin(pattern);
    pattern = add_one_to_bin(pattern);
    pattern = add_zero_to_bin(pattern);
    pattern = add_one_to_bin(pattern);
    pattern = add_zero_to_bin(pattern);
    for (int j = 0; j < 24; j++)
        pattern = add_zero_to_bin(pattern);
    print_bits(pattern | nb);
    return pattern | nb;
}
