#include "lib.h"
#include <math.h>

double calculate(double x, double y, double z, double w) {
    return sqrt(x) + (log(y + 1) / z) * tan(w);
}