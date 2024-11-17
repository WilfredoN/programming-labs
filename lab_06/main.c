#include <stdio.h>
#include "lib.h"

int main() {
    double x = 4.0, y = 2.0, z = 3.0, w = 1.0;

    printf("Library execution...\n");

    double result = calculate_fun1(x, y, z, w);
    printf("Result: %lf\n", result);

    return 0;
}