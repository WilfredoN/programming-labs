#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

void fillTwoDimension(int **array, int rows, int cols);
void fill(int *array, int size);
void print(int **array, int rows, int cols);
int main()
{
    int row, col;

    printf("Enter number of rows: ");
    scanf("%d", &row);
    printf("Enter number of columns: ");
    scanf("%d", &col);

    if (row <= 0 || col <= 0)
    {
        printf("Invalid row or column\n");
        return 0;
    }

    int **arr = (int **)malloc(row * sizeof(int *));

    for (int i = 0; i < row; i++)
    {
        arr[i] = (int *)malloc(col * sizeof(int));
    }

    fillTwoDimension(arr, row, col);
    print(arr, row, col);
    printf("Sum of lower triangle: %d\n", sum_lower_triangle(arr, row, col));

    reverse_columns(arr, row, col);
    printf("Reversed columns:\n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    int even_count = count_even_numbers(arr, row, col);
    printf("Count of even numbers: %d\n", even_count);

    int size;
    printf("Enter size of 1D array: ");
    scanf("%d", &size);
    if (size <= 0)
    {
        printf("Invalid size\n");
        return 0;
    }

    int *array = (int *)malloc(size * sizeof(int));
    fill(array, size);

    double variance = calculate_variance(array, size);
    printf("Variance: %.2f\n", variance);
    free(array);

    for (int i = 0; i < row; i++)
    {
        free(arr[i]);
    }
    free(arr);

    return 0;
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