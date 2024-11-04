#include "unity.h"

void test_calculate_fun1();
void test_calculate_fun2();
void test_calculate_fun3();
void test_calculate_fun4();

int main() {
    UNITY_BEGIN();
    RUN_TEST(test_calculate_fun1);
    RUN_TEST(test_calculate_fun2);
    RUN_TEST(test_calculate_fun3);
    RUN_TEST(test_calculate_fun4);
    return UNITY_END();
}