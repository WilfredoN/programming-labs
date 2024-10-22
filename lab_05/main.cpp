#include <cmath>
#include <cstdio>

int main() {
  // Set 1:
  double a = 2.0, b = 3.0, c = 4.0, d = 5.0;
  // Set 2:
  // double a = 3.0, b = 2.0, c = 1.0, d = 4.0;
  // Set 3:
  // double a = 5.0, b = 15.0, c = 2.0, d = 1.0;
  double y = (atan(a) / exp(b * cos(c))) + pow(log2(d + 1), 1.0 / 3.0);
  printf("%f\n", y);
  return 0;
}
