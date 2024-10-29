#include <cmath>
#include <iostream>

float calculate_float(float a, float b, float c, float d, float e, float f)
{
  return (std::powf(a, 2.0) + b * c - d) * (e - (b / c) + a * f) -
         (c + a * d) + ((b * e) / (c - d * f));
}

int calculate_integer(int a, int b, int c, int d, int e, int f)
{
  return (std::pow(a, 2) + b * c - d) * (e - (b / c) + a * f) -
         (c + a * d) + ((b * e) / (c - d * f));
}

int main()
{
  // first set of values
  int int_a1 = 2;
  int int_b1 = 3;
  int int_c1 = 4;
  int int_d1 = 1;
  int int_e1 = 6;
  int int_f1 = 2;
  // second set of values
  int int_a2 = 5;
  int int_b2 = 7;
  int int_c2 = 8;
  int int_d2 = 3;
  int int_e2 = 4;
  int int_f2 = 1;

  printf("Integer Calculation 1: %d\n", calculate_integer(int_a1, int_b1, int_c1, int_d1, int_e1, int_f1));
  printf("Integer Calculation 2: %d\n", calculate_integer(int_a2, int_b2, int_c2, int_d2, int_e2, int_f2));

  // first set of values
  float float_a1 = 1.0f;
  float float_b1 = 2.0f;
  float float_c1 = 3.0f;
  float float_d1 = 4.0f;
  float float_e1 = 5.0f;
  float float_f1 = 6.0f;
  // second set of values
  float float_a2 = 3.1f;
  float float_b2 = 2.4f;
  float float_c2 = 5.3f;
  float float_d2 = 8.6f;
  float float_e2 = 4.2f;
  float float_f2 = 2.5f;

  printf("Float Calculation 1: %f\n", calculate_float(float_a1, float_b1, float_c1, float_d1, float_e1, float_f1));
  printf("Float Calculation 2: %f\n", calculate_float(float_a2, float_b2, float_c2, float_d2, float_e2, float_f2));

  return 0;
}
