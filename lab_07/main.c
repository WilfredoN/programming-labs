#include <stdio.h>
#include <time.h>
// Variant 4

// Recursive Calculation Task
int findMinRecursive(int n)
{
    if (n < 10)
    {
        return n;
    }
    return n % 10 < findMinRecursive(n / 10) ? n % 10 : findMinRecursive(n / 10);
}

// Iterative Calculation Task
int findMinIterative(int n)
{
    if (n < 10)
    {
        return n;
    }

    int min = 9;
    int temp = n;
    while (n > 0)
    {
        temp = n % 10;
        if (temp < min)
        {
            min = temp;
        }
        n = n / 10;
    }
    return min;
}

// Recursive Symbol Drawing Task
void drawRecursively(int n)
{
    if (n == 0)
    {
        return;
    }
    drawRecursively(n - 1);
    for (int i = 0; i < n; i++)
    {
        printf("#");
    }
    printf("\n");
}

// Iterative Symbol Drawing Task
void drawIteratively(int n)
{
    if (n == 0)
    {
        return;
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}

int main()
{
    clock_t t;
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    // Timer start
    t = clock();

    printf("\n\t\tRECURSIVELY\n\nThe smallest digit in %d is %d\n", n, findMinRecursive(n));
    // Timer stop
    t = clock() - t;

    printf("Execution time for recursive - %fs\n", ((double)t) / CLOCKS_PER_SEC);
    // Timer start
    t = clock();

    printf("\n\t\tITERATIVE\n\nThe smallest digit in %d is %d\n\n", n, findMinIterative(n));
    // Timer stop
    t = clock() - t;

    printf("Execution time for iterative - %fs\n", ((double)t) / CLOCKS_PER_SEC);
    printf("Enter a number: ");
    scanf("%d", &n);
    // Timer start
    t = clock();

    printf("\n\t\tRECURSIVELY\n\nDrawing a triangle of height %d:\n", n);
    drawRecursively(n);
    // Timer stop
    t = clock() - t;

    printf("Execution time for recursive - %fs\n", ((double)t) / CLOCKS_PER_SEC);
    // Timer start
    t = clock();
    printf("\n\t\tITERATIVELY\n\nDrawing a triangle of height %d:\n", n);
    drawIteratively(n);
    // Timer stop
    t = clock() - t;

    printf("Execution time for iterative - %fs\n", ((double)t) / CLOCKS_PER_SEC);
    return 0;
}