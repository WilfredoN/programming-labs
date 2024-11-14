#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define SIZE 8

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

int main()
{
    int *array = generate();
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
    printf("Count of even numbers in array: %d", countEven(array));
    printf("\n");
    printf("First negative element in array: %d", firstNegative(array));
    printf("\n");
    printf("Array rotated to the left: \n");
    rotateLeft(array);
    printf("\n");
    printf("Sorted array by absolute value: \n");
    sortByAbsolute(array);
    printf("\n");
    printf("Median of the sorted array: %.2f", findMedian(array));
    return 0;
}