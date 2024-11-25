#include "lib.h"

int main()
{
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int *array = generate(size);
    printf("Generated array:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\nCount of even numbers in array: %d", countEven(array, size));
    printf("\nFirst negative element in array: %d", firstNegative(array, size));
    printf("\nArray rotated to the left:\n");
    rotateLeft(array, size);
    printf("\nSorted array by absolute value:\n");
    sortByAbsolute(array, size);
    printf("\nMedian of the sorted array: %.2f\n", findMedian(array, size));

    free(array);

    return 0;
}