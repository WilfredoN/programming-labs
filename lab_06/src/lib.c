#include "lib.h"
#include <math.h>

double calculate_fun1(double x, double y, double z, double w) {
    return sqrt(x) + (log(y + 1) / z) * tan(w);
}

double calculate_fun2(double x, double y, double z, double w, double v) {
    return (pow(x, 3) + sin(y)) - ((z * sqrt(w)) / tan(v));
}

double calculate_fun3(double x, double y, double z, double w) {
    return (x + cos(y)) * (sqrt(z) - log(w + 1));
}

double calculate_fun4(double x, double y, double z, double w) {
    return (x + log(y + 1)) * cos(z) - sqrt(w);
}