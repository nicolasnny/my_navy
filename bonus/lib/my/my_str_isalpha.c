/*
** EPITECH PROJECT, 2023
** MY_STR_ISALPHA
** File description:
** Write a function that returns 1 if the string passed
** as parameter only contains alphabetical characters
*/

static int check_alpha(char const *str, int i, int isalpha)
{
    if (str[i] > 64 && str[i] < 91) {
        i++;
    } else if (str[i] > 96 && str[i] < 123) {
        i++;
    } else {
        isalpha = 0;
    }
    return isalpha;
}

int my_str_isalpha(char const *str)
{
    int i = 0;
    int isalpha = 1;

    while (str[i] != '\0') {
        isalpha = check_alpha(str, i, isalpha);
        i++;
    }
    return isalpha;
}
