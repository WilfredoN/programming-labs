
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define SIZE 8

// Compare function for qsort
int compare(const void *a, const void *b);

// Generate an array of random integers
int *generate();

// Print the array
void print(int *array);

// Count even numbers in the array
int countEven(int *array);

// Find the first negative number in the array
int firstNegative(int *array);

// Rotate the array to the left
void rotateLeft(int *array);

// Sort the array by absolute values
void sortByAbsolute(int *array);

// Find the median of the array
float findMedian(int *array);