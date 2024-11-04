#include "unity.h"

#include <limits.h>
#include "lib.h"

void setUp() {}

void tearDown() {}

void test_calculate_fun1() {
    TEST_ASSERT_FLOAT_WITHIN(0.000001, 2.570329, calculate_fun1(4, 2, 3, 1));
    TEST_ASSERT_FLOAT_WITHIN(0.000001, 3.0, calculate_fun1(9, 1, 1, 0)); // sqrt(9) + (log(2) / 1) * tan(0)
    TEST_ASSERT_FLOAT_WITHIN(0.000001, 1.0, calculate_fun1(1, 0, 1, 0)); // sqrt(1) + (log(1) / 1) * tan(0)
    TEST_ASSERT_FLOAT_WITHIN(0.000001, 0.0, calculate_fun1(0, 0, 1, 0)); // sqrt(0) + (log(1) / 1) * tan(0)

    TEST_ASSERT_FLOAT_IS_NAN(calculate_fun1(0, 0, 0, 0)); // sqrt(0) + (log(0) / 0) * tan(0)
}

void test_calculate_fun2() {
    TEST_ASSERT_FLOAT_WITHIN(0.001, 63.357, calculate_fun2(4, 0, 1, 1, 1)); // (pow(4, 3) + sin(0)) - ((1 * sqrt(1)) / tan(1))
    TEST_ASSERT_FLOAT_WITHIN(0.01, -0.64, calculate_fun2(0, 0, 1, 1, 1)); // (pow(0, 3) + sin(0)) - ((1 * sqrt(1)) / tan(1))
    TEST_ASSERT_FLOAT_IS_NAN(calculate_fun2(0, 0, 0, 0, 0)); // (pow(0, 3) + sin(0)) - ((0 * sqrt(0)) / tan(0))

    TEST_ASSERT_FLOAT_IS_NAN(calculate_fun2(0, 0, 0, 0, 0)); // (pow(0, 3) + sin(0)) - ((0 * sqrt(0)) / tan(0))
}

void test_calculate_fun3() {
    TEST_ASSERT_FLOAT_WITHIN(0.000001, 1.0, calculate_fun3(0, 0, 1, 0)); // (0 + cos(0)) * (sqrt(1) - log(1))
    TEST_ASSERT_FLOAT_WITHIN(0.000001, 2.0, calculate_fun3(1, 0, 1, 0)); // (1 + cos(0)) * (sqrt(1) - log(1))
    TEST_ASSERT_FLOAT_WITHIN(0.000001, 3.0, calculate_fun3(2, 0, 1, 0)); // (2 + cos(0)) * (sqrt(1) - log(1))

    TEST_ASSERT_FLOAT_WITHIN(0, 0, calculate_fun3(0, 0, 0, 0)); // (0 + cos(0)) * (sqrt(0) - log(0))
}

void test_calculate_fun4() {
    TEST_ASSERT_FLOAT_WITHIN(0.000001, 0.0, calculate_fun4(0, 0, 0, 0)); // (0 + log(1)) * cos(0) - sqrt(0)
    TEST_ASSERT_FLOAT_WITHIN(0.000001, 1.0, calculate_fun4(1, 0, 0, 0)); // (1 + log(1)) * cos(0) - sqrt(0)
    TEST_ASSERT_FLOAT_WITHIN(0.000001, 2.0, calculate_fun4(2, 0, 0, 0)); // (2 + log(1)) * cos(0) - sqrt(0)

    TEST_ASSERT_FLOAT_WITHIN(0, 0, calculate_fun4(0, 0, 0, 0)); // (0 + log(0)) * cos(0) - sqrt(0)
}