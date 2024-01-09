/*
** EPITECH PROJECT, 2023
** MY_RADAR
** File description:
** unit tests
*/

#include <criterion/criterion.h>
#include <SFML/Graphics.h>
#include "../include/radar_func.h"

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

Test(point_collision_test, plane_collision)
{
    sfRectangleShape *rect = init_rect(0.0, 0.0, 50.0, 50.0);

    cr_assert_eq(my_rect_contains(rect, 10.0, 10.0), 1);
    cr_assert_eq(my_rect_contains(rect, 10.0, 55.0), 0);
    cr_assert_eq(my_rect_contains(rect, 600.0, 65.6), 0);
}

Test(rect_collision_test, plane_collision)
{
    sfRectangleShape *rect = init_rect(0.0, 540.0, 960.0, 540.0);
    sfRectangleShape *rect2 = init_rect(395.0, 717.0, 20.0, 20.0);

    cr_assert_eq(my_rect_intersects(rect, rect2), 1);
    rect = init_rect(0.0, 0.0, 1000.0, 1000.0);
    cr_assert_eq(my_rect_intersects(rect, rect2), 1);
}

Test(detection, point_in_circle)
{
    sfCircleShape *circ = create_circle((sfVector2f) {48.0, 48.0}, 48);

    cr_assert_eq(my_circ_contains(circ, (sfVector2f) {10.0, 10.0}), 0);
    cr_assert_eq(my_circ_contains(circ, (sfVector2f) {48.0, 55.0}), 1);
}
