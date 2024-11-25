#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// Compare function for qsort
int compare(const void *a, const void *b);

// Generate an array of random integers
int *generate(int size);

// Print the array
void print(int *array, int size);

// Count even numbers in the array
int countEven(int *array, int size);

// Find the first negative number in the array
int firstNegative(int *array, int size);

// Rotate the array to the left
void rotateLeft(int *array, int size);

// Sort the array by absolute values
void sortByAbsolute(int *array, int size);

// Find the median of the array
float findMedian(int *array, int size);