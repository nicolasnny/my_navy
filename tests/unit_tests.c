/*
** EPITECH PROJECT, 2023
** MY_RADAR
** File description:
** unit tests
*/

#include <criterion/criterion.h>
#include <SFML/Graphics.h>
#include "../include/navy_func.h"

/*
// Passes if Expression is true
cr_assert ( Expression , FormatString , ...) ;
// Passes if Expression is false
cr_assert_not ( Expression , FormatString , ...) ;
// Passes if Actual == Expected
cr_assert_eq ( Actual , Expected , FormatString , ...) ;
// Passes if Actual != Expected
cr_assert_neq ( Actual , Expected , FormatString , ...) ;
*/

Test(err_handling, error_pop)
{
    char *args[] = {"./my_navy", "pop"};

    cr_assert_eq(err_handling(2, args), ERROR);
}

/*Test(bin_to_int, convertion)
{
    int nb = 32;

    cr_assert_str_eq(int_to_bin(nb), "00000000000000000000000000010000");
    }*/

Test(adding_pattern, pattern_add)
{
    unsigned int nb = 32;

    nb = add_pattern(nb);
    cr_assert_eq(nb, 704643105);
}
