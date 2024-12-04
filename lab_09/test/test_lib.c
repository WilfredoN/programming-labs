#include "unity.h"

#include <limits.h>
#include "lib.h"
#include <stdlib.h>

void setUp() {}
void tearDown() {}

void test_sum_lower_triangle()
{
    int *arr1[] = {
        (int[]){1, 0, 0},
        (int[]){2, 3, 0},
        (int[]){4, 5, 6}};

    TEST_ASSERT_EQUAL_INT(21, sum_lower_triangle(arr1, 3, 3));
}

void test_reverse_columns()
{
    int *arr2[] = {
        (int[]){1, 2, 3},
        (int[]){4, 5, 6},
        (int[]){7, 8, 9}};

    reverse_columns(arr2, 3, 3);

    int *arr_expected[] = {
        (int[]){7, 8, 9},
        (int[]){4, 5, 6},
        (int[]){1, 2, 3}};

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            TEST_ASSERT_EQUAL_INT(arr_expected[i][j], arr2[i][j]);
        }
    }
}

void test_count_even_numbers()
{
    int *arr3[] = {
        (int[]){1, 2, 3},
        (int[]){4, 5, 6},
        (int[]){7, 8, 9}};

    TEST_ASSERT_EQUAL_INT(4, count_even_numbers(arr3, 3, 3));
}

void test_calculate_variance()
{
    int arr[] = {1, 2, 3, 4, 5};

    TEST_ASSERT_FLOAT_WITHIN(0.000001, 2.0, calculate_variance(arr, 5));
}