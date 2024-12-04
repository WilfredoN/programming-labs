#include <lib.h>
#include <stdio.h>

int main()
{
    char str1[100];
    char str2[100];

    printf("Enter the first string: ");
    scanf("%s", str1);

    printf("Enter the second string: ");
    scanf("%s", str2);

    printf("The concatenated string is: %s\n", strconcat(str1, str2));
}