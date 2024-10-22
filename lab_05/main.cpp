#include <cmath>
#include <cstdio>

int main() {
  // Set 1:
  double a = 5.0, b = 15.0, c = 2.0, d = 1.0;
  double y = (atan(a) / exp(b * cos(c))) + pow(log2(d + 1), 1.0 / 3.0);
  printf("%f\n", y);
  return 0;
}
