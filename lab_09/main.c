#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

int main()
{
    int *arr1[] = {
        (int[]){1, 0, 0},
        (int[]){2, 3, 0},
        (int[]){4, 5, 6}};

    printf("Sum of lower triangle: %d\n", sum_lower_triangle(arr1, 3));
    int *arr2[] = {
        (int[]){1, 2, 3},
        (int[]){4, 5, 6},
        (int[]){7, 8, 9}};

    reverse_columns(arr2, 3, 3);

    printf("Reversed columns:\n");

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", arr2[i][j]);
        }
        printf("\n");
    }

    int *arr3[] = {
        (int[]){1, 2, 3},
        (int[]){4, 5, 6},
        (int[]){7, 8, 9}};
    printf("Count of even numbers: %d\n", count_even_numbers(arr3, 3, 3));

    int array[] = {1, 2, 3, 4, 5};
    printf("Variance: %lf\n", calculate_variance(array, 5));

    int rows = 3, cols = 3;
    printf("Generated array:\n");
    int **generated_array = generate_and_print_array(rows, cols);

    for (int i = 0; i < rows; i++)
    {
        free(generated_array[i]);
    }
    free(generated_array);

    return 0;
}
