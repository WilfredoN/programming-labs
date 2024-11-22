#include "lib.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

int sum_lower_triangle(int **matrix, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            sum = sum + matrix[i][j];
        }
    }
    return sum;
}

void reverse_columns(int **matrix, int rows, int cols)
{
    for (int j = 0; j < cols; j++)
    {
        for (int i = 0; i < rows / 2; i++)
        {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[rows - 1 - i][j];
            matrix[rows - 1 - i][j] = temp;
        }
    }
}

int count_even_numbers(int **matrix, int rows, int cols)
{
    int count = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] % 2 == 0)
            {
                count++;
            }
        }
    }
    return count;
}

double calculate_variance(int *array, int size)
{
    double mean = 0.0, variance = 0.0;
    for (int i = 0; i < size; i++)
    {
        mean += array[i];
    }
    mean = mean / size;
    for (int i = 0; i < size; i++)
    {
        variance = variance + (array[i] - mean) * (array[i] - mean);
    }
    int result = variance / size;
    return result;
}

int **generate_and_print_array(int rows, int cols)
{
    int **array = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++)
    {
        array[i] = (int *)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++)
        {
            array[i][j] = rand() % 100;
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
    return array;
}