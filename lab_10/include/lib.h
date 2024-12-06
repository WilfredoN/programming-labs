#ifndef LIB_H
#define LIB_H

// Generate
void generate(int arr[100][100][100]);

// Free
void free_dynamic(int ***arr, int a, int b);

// Write
int write_to(const char *filename, int arr[100][100][100]);
int ***read_from(const char *filename, int *dimension_1, int *dimension_2, int *dimension_3);
long sum_ar(int ***arr, int dimension_1, int dimension_2, int dimension_3);

#endif // LIB_H