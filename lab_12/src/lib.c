#include <lib.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char *strconcat(char *str1, char *str2)
{
    if (str1 == NULL)
        str1 = "";
    if (str2 == NULL)
        str2 = "";

    int len1 = 0;
    int len2 = 0;

    while (str1[len1] != '\0')
    {
        len1++;
    }

    while (str2[len2] != '\0')
    {
        len2++;
    }

    char *result = malloc(len1 + len2 + 1);

    if (result == NULL)
    {
        return NULL;
    }

    for (int i = 0; i < len1; i++)
    {
        result[i] = str1[i];
    }

    for (int i = 0; i < len2; i++)
    {
        result[len1 + i] = str2[i];
    }

    result[len1 + len2] = '\0';

    return result;
}

char *str_reverse(char *str)
{
    if (str == NULL)
    {
        return NULL;
    }

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
    if (str == NULL)
        return NULL;

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (!isalpha(str[i]))
            continue;

        if (isupper(str[i]))
            str[i] = tolower(str[i]);
    }
    return str;
}