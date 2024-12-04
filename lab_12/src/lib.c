#include <lib.h>
#include <stdio.h>

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

char *str_reverse(char *str)
{
    int length = 0;

    while (str[length] != '\0')
    {
        length++;
    }

    for (int i = 0; i < length / 2; i++)
    {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }

    return str;
}

char *str_to_lowercase(char *str)
{
    int i = 0;

    // We use ASCII to make opposite strimg case for [A-Z]
    while (str[i] != '\0')
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 32;
        i++;
    }
    return str;
}