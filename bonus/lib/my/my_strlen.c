/*
** EPITECH PROJECT, 2023
** MY_STRLEN
** File description:
** count char of string
*/

#include "my.h"

int my_strlen(char const *str)
{
    int i;

    i = 0;
    while (str[i] != '\0') {
        i = i + 1;
    }
    return i;
}
