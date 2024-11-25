#include "lib.h"

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int *generate(int size)
{
    int *array = malloc(sizeof(int) * size);
    srand(time(NULL));

    for (int i = 0; i < size; i++)
    {
        array[i] = rand() % 49 - 10;
    }
    return array;
}

void print(int *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
}

int countEven(int *array, int size)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (array[i] % 2 == 0)
        {
            count++;
        }
    }
    return count;
}

int firstNegative(int *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (array[i] < 0)
        {
            return array[i];
        }
    }
    return -1;
}

void rotateLeft(int *array, int size)
{
    if (size <= 0)
        return;

    int temp = array[0];
    for (int i = 0; i < size - 1; i++)
    {
        array[i] = array[i + 1];
    }
    array[size - 1] = temp;

    print(array, size);
}

void sortByAbsolute(int *array, int size)
{
    int temp;
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (abs(array[j]) > abs(array[j + 1]))
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
    print(array, size);
}

float findMedian(int *array, int size)
{
    if (size == 0)
        return 0.0f;

    qsort(array, size, sizeof(int), compare);
    if (size % 2 != 0)
    {
        return array[size / 2];
    }

    return (array[size / 2 - 1] + array[size / 2]) / 2.0f;
}