#include "lib.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

int sum_lower_triangle(int **arr, int rows, int cols)
{
    int sum = 0;
    for (int i = 0; i < rows && i < cols; i++)
    {
        for (int j = 0; j <= i && j < cols; j++)
        {
            sum = sum + arr[i][j];
        }
    }
    return sum;
}

void reverse_columns(int **arr, int rows, int cols)
{
    for (int j = 0; j < cols; j++)
    {
        for (int i = 0; i < rows / 2; i++)
        {
            int temp = arr[i][j];
            arr[i][j] = arr[rows - 1 - i][j];
            arr[rows - 1 - i][j] = temp;
        }
    }
}

int count_even_numbers(int **arr, int rows, int cols)
{
    int count = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (arr[i][j] % 2 == 0)
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

void fillTwoDimension(int **array, int rows, int cols)
{
    printf("Enter elements for the %dx%d array:\n", rows, cols);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &array[i][j]);
        }
    }
}
void fill(int *array, int size)
{
    printf("Enter elements for the array:\n");
    for (int i = 0; i < size; i++)
    {
        printf("Element [%d]: ", i + 1);
        scanf("%d", &array[i]);
    }
}
void print(int **array, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
}