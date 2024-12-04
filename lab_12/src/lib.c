#include <lib.h>

char *strconcat(char *str1, char *str2)
{
    char *result = str1;

    // While no endline
    while (*str1 != '\0')
    {
        str1++;
    }

    // While no endline copy str2 to str1
    while (*str2 != '\0')
    {
        *str1 = *str2;
        str1++;
        str2++;
    }

    // Add endline to terminate the string
    *str1 = '\0';
    return result;
}