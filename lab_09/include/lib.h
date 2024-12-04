#ifndef LIB_H
#define LIB_H

int sum_lower_triangle(int **array, int rows, int cols);
void reverse_columns(int **array, int rows, int cols);
int count_even_numbers(int **array, int rows, int cols);
double calculate_variance(int *array, int size);
int **generate_and_print_array(int rows, int cols);

void fillTwoDimension(int **array, int rows, int cols);
void fill(int *array, int size);
void print(int **array, int rows, int cols);

#endif // LIB_H