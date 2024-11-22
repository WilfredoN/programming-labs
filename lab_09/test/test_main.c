#include "unity.h"

void test_sum_lower_triangle();
void test_reverse_columns();
void test_count_even_numbers();
void test_calculate_variance();
void test_generate_and_print_array();

int main()
{
    UNITY_BEGIN();
    RUN_TEST(test_sum_lower_triangle);
    RUN_TEST(test_reverse_columns);
    RUN_TEST(test_count_even_numbers);
    RUN_TEST(test_calculate_variance);
    RUN_TEST(test_generate_and_print_array);
    return UNITY_END();
}