/*
** EPITECH PROJECT, 2023
** MY_NAVY
** File description:
** unit tests
*/

#include <criterion/criterion.h>
#include "../include/navy_func.h"
#include "../include/signal_codes.h"
#include <criterion/redirect.h>

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

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(unit_test, wrong_arg_number, .init=redirect_all_stdout)
{
    char *args[] = {"./my_navy"};
    char *args2[] = {"./my_navy", "1234", "figh", "feogho"};

    cr_assert_eq(err_handling(1, args), ERROR);
    cr_assert_eq(err_handling(4,  args2), ERROR);
}

Test(unit_test, wrong_file, .init=redirect_all_stdout)
{
    char *args[] = {"./my_navy", "pop"};
    char *args2[] = {"./my_navy", "4586", "not_a_file"};

    cr_assert_eq(err_handling(2, args), ERROR);
    cr_assert_eq(err_handling(3, args2), ERROR);
}

Test(unit_test, good_file, .init=redirect_all_stdout)
{
    char *args[] = {"./my_navy", "tests/pos1"};
    char *args2[] = {"./my_navy", "4586", "tests/pos1"};

    cr_assert_eq(err_handling(2, args), SUCCESS);
    cr_assert_eq(err_handling(3, args2), SUCCESS);
}

Test(unit_test, losing_condition, .init=redirect_all_stdout)
{
    char *map[] = {"......XXX.", "....XXX.", NULL};

    cr_assert_eq(lose(map), 1);
}

Test(unit_test, losing_condition_2, .init=redirect_all_stdout)
{
    char *map[] = {"...4..", "...4..", NULL};

    cr_assert_eq(lose(map), 0);
}

Test(unit_test, get_coords_from_line, .init=redirect_all_stdout)
{
    char line[] = "A6:E3";

    cr_assert_str_eq(get_coord(line), "A6");
    cr_assert_str_eq(get_coord(line + 3), "E3");
}

Test(unit_test, int_to_str_bin, .init=redirect_all_stdout)
{
    int nb1 = 0;
    int nb2 = 789;

    cr_assert_str_eq(int_to_bin(nb1), "10000000000000000000000000000000");
    cr_assert_str_eq(int_to_bin(nb2), "10000000000000000000001100010101");
}

Test(unit_test, map_init, .init=redirect_all_stdout)
{
    char **map = get_map("tests/pos1");

    cr_assert(map);
    free(map);
}

Test(unit_test, check_hit, .init=redirect_all_stdout)
{
    char **map = get_map("tests/pos1");
    int coord[] = {2, 1};

    cr_assert_eq(check_hit(map, coord), true);
    cr_assert_eq(check_hit(map, coord), false);
    coord[0] = 4;
    cr_assert_eq(check_hit(map, coord), false);
    free(map);
}

Test(unit_test, fill_ennemy_map, .init=redirect_all_stdout)
{
    char **map = create_map();
    int coord[] = {2, 1};

    fill_empty_map(map, coord, HIT);
    cr_assert_eq(map[coord[1] - 1][coord[0] * 2], 'x');
    coord[1] = 4;
    fill_empty_map(map, coord, MISS);
    cr_assert_eq(map[coord[1] - 1][coord[0] * 2], 'o');
}

/*----- FUNCTIONNAL TEST ----*/

Test(functionnal_test, err_handling, .init=redirect_all_stdout)
{
    char *args[] = {"./my_navy"};
    char *args3[] = {"./my_navy", "pop"};
    char *args2[] = {"./my_navy", "4586", "not_a_file"};
    char *args4[] = {"./my_navy", "1234", "figh", "feogho"};

    cr_assert_eq(my_navy(2, args3), ERROR);
    cr_assert_eq(my_navy(3, args2), ERROR);
    cr_assert_eq(my_navy(1, args), ERROR);
    cr_assert_eq(err_handling(4,  args2), ERROR);
}
