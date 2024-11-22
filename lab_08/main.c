#include "lib.h"

int main()
{
    int *array = generate();
    printf("Generated array:\n");
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\nCount of even numbers in array: %d", countEven(array));
    printf("\nFirst negative element in array: %d", firstNegative(array));
    printf("\nArray rotated to the left:\n");
    rotateLeft(array);
    printf("\nSorted array by absolute value:\n");
    sortByAbsolute(array);
    printf("\nMedian of the sorted array: %.2f\n", findMedian(array));

    free(array);

    return 0;
}