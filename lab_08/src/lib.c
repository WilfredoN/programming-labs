#include "lib.h"

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int *generate()
{
    int *array = malloc(sizeof(int) * SIZE);
    srand(time(NULL));
    for (int i = 0; i < SIZE; i++)
    {
        array[i] = rand() % 49 - 10;
    }
    return array;
}

void print(int *array)
{
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ", array[i]);
    }
}

int countEven(int *array)
{
    int count = 0;
    for (int i = 0; i < SIZE; i++)
    {
        if (array[i] % 2 == 0)
        {
            count++;
        }
    }
    return count;
}

int firstNegative(int *array)
{
    for (int i = 0; i < SIZE; i++)
    {
        if (array[i] < 0)
        {
            return array[i];
        }
    }
    return -1;
}

void rotateLeft(int *array)
{
    int temp = array[0];

    for (int i = 0; i < SIZE - 1; i++)
    {
        array[i] = array[i + 1];
    }
    array[SIZE - 1] = temp;

    print(array);
}

void sortByAbsolute(int *array)
{
    int temp;
    for (int i = 0; i < SIZE - 1; i++)
    {
        for (int j = 0; j < SIZE - i - 1; j++)
            if (abs(array[j]) > abs(array[j + 1]))
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
    }
    print(array);
}

float findMedian(int *array)
{
    qsort(array, SIZE, sizeof(int), compare);
    if (SIZE % 2 != 0)
    {
        return array[SIZE / 2];
    }

    return (array[SIZE / 2 - 1] + array[SIZE / 2]) / 2.0;
}