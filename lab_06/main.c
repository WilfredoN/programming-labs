#include <stdio.h>
#include "lib.h"

int main() {
    printf("Library execution...\n");
    double x = 4.0, y = 2.0, z = 3.0, w = 1.0;
    double result = calculate(x, y, z, w);
    printf("Result: %lf\n", result);
    return 0;
}