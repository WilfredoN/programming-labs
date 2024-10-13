#include <cmath>
#include <iostream>

float calculate_float(float a, float b, float c, float d, float e, float f) {
  return (float)(std::powf(a, 2.0) + b * c - d) * (e - (b / c) + a * f) -
         (c + a * d) + ((b * e) / (c - d * f));
}

int calculate_integer(int a, int b, int c, int d, int e, int f) {
  return (int)(std::pow(a, 2) + b * c - d) * (e - (b / c) + a * f) -
         (c + a * d) + ((b * e) / (c - d * f));
}

int main() {
  int int_a1 = 2, int_b1 = 3, int_c1 = 4, int_d1 = 1, int_e1 = 6, int_f1 = 2;
  int int_a2 = 5, int_b2 = 7, int_c2 = 8, int_d2 = 3, int_e2 = 4, int_f2 = 1;

  std::cout << "Integer Calculation 1: "
            << calculate_integer(int_a1, int_b1, int_c1, int_d1, int_e1, int_f1)
            << std::endl;
  std::cout << "Integer Calculation 2: "
            << calculate_integer(int_a2, int_b2, int_c2, int_d2, int_e2, int_f2)
            << std::endl;

  float float_a1 = 1.0f, float_b1 = 2.0f, float_c1 = 3.0f, float_d1 = 4.0f,
        float_e1 = 5.0f, float_f1 = 6.0f;
  float float_a2 = 3.1f, float_b2 = 2.4f, float_c2 = 5.3f, float_d2 = 8.6f,
        float_e2 = 4.2f, float_f2 = 2.5f;

  std::cout << "Float Calculation 1: "
            << calculate_float(float_a1, float_b1, float_c1, float_d1, float_e1,
                               float_f1)
            << std::endl;
  std::cout << "Float Calculation 2: "
            << calculate_float(float_a2, float_b2, float_c2, float_d2, float_e2,
                               float_f2)
            << std::endl;
  return 0;
}
