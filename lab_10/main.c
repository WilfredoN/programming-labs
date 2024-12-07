#include <stdio.h>
#include <lib.h>

int main()
{
    int arr[100][100][100];
    generate(arr);

    if (write_to("output.txt", arr) != 0)
    {
        printf("Failed to write to file\n");
        return 0;
    }

    int dimension_1, dimension_2, dimension_3;
    int ***dynamic_arr = read_from("output.txt", &dimension_1, &dimension_2, &dimension_3);
    if (dynamic_arr == NULL)
    {
        printf("Failed to read from file\n");
        return 0;
    }

    long sum = sum_ar(dynamic_arr, dimension_1, dimension_2, dimension_3);
    printf("Sum: %ld\n", sum);

    free_dynamic(dynamic_arr, dimension_1, dimension_2);

    return 0;
}