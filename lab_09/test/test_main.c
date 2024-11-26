#include "unity.h"

void test_sum_lower_triangle();
void test_reverse_columns();
void test_count_even_numbers();
void test_calculate_variance();

int main()
{
    UNITY_BEGIN();
    RUN_TEST(test_sum_lower_triangle);
    RUN_TEST(test_reverse_columns);
    RUN_TEST(test_count_even_numbers);
    RUN_TEST(test_calculate_variance);
    return UNITY_END();
}