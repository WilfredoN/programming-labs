#include <lib.h>
#include <string.h>
#include <stdio.h>

#include <stdlib.h>
#include <time.h>

void generate(int arr[100][100][100])
{
    srand(time(NULL));
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            for (int k = 0; k < 100; k++)
            {
                arr[i][j][k] = rand() % 100;
            }
        }
    }
}

void free_dynamic(int ***dynamic_arr, int a, int b)
{
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            free(dynamic_arr[i][j]);
        }
        free(dynamic_arr[i]);
    }
    free(dynamic_arr);
}

int write_to(const char *filename, int arr[100][100][100])
{
    FILE *file = fopen(filename, "w");
    if (file == NULL)
    {
        printf("Failed to open file\n");
        return -1;
    }
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            for (int k = 0; k < 100; k++)
            {
                fprintf(file, "%d ", arr[i][j][k]);
            }
            fprintf(file, "\n");
        }
        fprintf(file, "\n");
    }

    fclose(file);
    return 0;
}

int ***read_from(const char *filename, int *dimension_1, int *dimension_2, int *dimension_3)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Failed to open file\n");
        return NULL;
    }

    if (fscanf(file, "%d %d %d", dimension_1, dimension_2, dimension_3) != 3)
    {
        printf("Failed to read dimensions\n");
        fclose(file);
        return NULL;
    }

    int ***arr = malloc(*dimension_1 * sizeof(int **));

    if (arr == NULL)
    {
        printf("Failed to allocate memory.\n");
        fclose(file);
        return NULL;
    }

    for (int i = 0; i < *dimension_1; i++)
    {
        arr[i] = malloc(*dimension_2 * sizeof(int *));
        if (arr[i] == NULL)
        {
            free_dynamic(arr, i, 0);
            fclose(file);
            return NULL;
        }
        for (int j = 0; j < *dimension_2; j++)
        {
            arr[i][j] = malloc(*dimension_3 * sizeof(int));
            if (arr[i][j] == NULL)
            {
                free_dynamic(arr, i, j);
                fclose(file);
                return NULL;
            }
            for (int k = 0; k < *dimension_3; k++)
            {
                if (fscanf(file, "%d", &arr[i][j][k]) != 1)
                {
                    printf("Failed to read element\n");
                    free_dynamic(arr, i, j);
                    fclose(file);
                    return NULL;
                }
            }
        }
    }

    fclose(file);
    return arr;
}

long sum_ar(int ***ar, int dimension_1, int dimension_2, int dimension_3)
{
    long sum = 0;
    for (int i = 0; i < dimension_1; i++)
    {
        for (int j = 0; j < dimension_2; j++)
        {
            for (int k = 0; k < dimension_3; k++)
            {
                sum += ar[i][j][k];
            }
        }
    }
    return sum;
}