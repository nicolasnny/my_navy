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

Test(unit_test, wrong_arg_number)
{
    char *args[] = {"./my_navy"};
    char *args2[] = {"./my_navy", "1234", "figh", "feogho"};

    cr_assert_eq(err_handling(1, args), ERROR);
    cr_assert_eq(err_handling(4,  args2), ERROR);
}

Test(unit_test, wrong_file)
{
    char *args[] = {"./my_navy", "pop"};
    char *args2[] = {"./my_navy", "4586", "not_a_file"};

    cr_assert_eq(err_handling(2, args), ERROR);
    cr_assert_eq(err_handling(3, args2), ERROR);
}

/*Test(unit_test, good_file)
{
    char *args[] = {"./my_navy", "pos1"};
    char *args2[] = {"./my_navy", "4586", "pos1"};

    cr_assert_eq(err_handling(2, args), 0);
    cr_assert_eq(err_handling(3, args2), 0);
}*/

Test(unit_test, losing_condition)
{
    char *map[] = {"......XXX.", "....XXX.", NULL};

    cr_assert_eq(lose(map), 1);
}

Test(unit_test, losing_condition_2)
{
    char *map[] = {"...4..", "...4..", NULL};

    cr_assert_eq(lose(map), 0);
}

Test(unit_test, get_coords_from_line)
{
    char line[] = "A6:E3";

    cr_assert_str_eq(get_coord(line), "A6");
    cr_assert_str_eq(get_coord(line + 3), "E3");
}

/*----- FUNCTIONNAL TEST ----*/

Test(functionnal_test, err_handling)
{
    char *args[] = {"./my_navy"};

    cr_assert_eq(my_navy(1, args), ERROR);
}
