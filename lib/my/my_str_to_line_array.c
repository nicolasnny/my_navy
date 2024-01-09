/*
** EPITECH PROJECT, 2023
** SETTING_UP
** File description:
** Return an array of lines extracted for the array given as an argument
*/

#include <stdlib.h>
#include "my.h"

static int get_nb_of_line(char *array)
{
    int nb = 0;
    int i = 0;

    while (array[i]) {
        if (array[i] == '\n')
            nb++;
        i++;
    }
    return nb;
}

static char *add_line(char *array, int i, int debut)
{
    char *newline = malloc(sizeof(char) * ((i - debut) + 1));
    int nb_cpy = 0;

    while (debut <= i) {
        newline[nb_cpy] = array[debut];
        nb_cpy++;
        debut++;
    }
    newline[i + 1] = '\0';
    return newline;
}

char **my_str_to_line_array(char *array)
{
    int nb_of_line = get_nb_of_line(array);
    char **rep = malloc(sizeof(char *) * (nb_of_line + 1));
    int i = 0;
    int debut = 0;
    int line = 0;

    while (i < my_strlen(array)) {
        if (array[i] == '\n') {
            rep[line] = malloc(sizeof(char) * (i - debut));
            rep[line] = add_line(array, i, debut);
            debut = i + 1;
            line ++;
        }
        i++;
    }
    rep[line] = 0;
    return rep;
}
