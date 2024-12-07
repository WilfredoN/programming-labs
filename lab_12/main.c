#include <lib.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define OUT_FILE_NAME_REVERSE "output_reverse.txt"
#define OUT_FILE_NAME_UPPERCASE "output_uppercase.txt"
#define IN_FILE_NAME "input.txt"

#define MAX_INPUT_SIZE 100
#define MAX_BUFFER_SIZE 256

int main()
{
    char str1[MAX_INPUT_SIZE];
    char str2[MAX_INPUT_SIZE];

    printf("Enter the first string: ");
    if (fgets(str1, sizeof(str1), stdin) == NULL || strlen(str1) <= 1)
    {
        printf("Invalid input for first string\n");
        return EXIT_FAILURE;
    }
    str1[strcspn(str1, "\n")] = '\0';

    printf("Enter the second string: ");
    if (fgets(str2, sizeof(str2), stdin) == NULL || strlen(str2) <= 1)
    {
        printf("Invalid input for second string\n");
        return EXIT_FAILURE;
    }
    str2[strcspn(str2, "\n")] = '\0';

    char *concatenated = strconcat(str1, str2);
    if (concatenated == NULL)
    {
        printf("Concatenation failed\n");
        return EXIT_FAILURE;
    }
    printf("The concatenated string is: %s\n", concatenated);

    // TASK 2
    FILE *in_file = fopen(IN_FILE_NAME, "r");

    if (!in_file)
    {
        printf("Cannot open input file\n");
        free(concatenated);
        return EXIT_FAILURE;
    }

    FILE *out_file_reverse = fopen(OUT_FILE_NAME_REVERSE, "w");
    FILE *out_file_uppercase = fopen(OUT_FILE_NAME_UPPERCASE, "w");

    if (!out_file_reverse || !out_file_uppercase)
    {
        printf("Cannot open output file\n");
        fclose(in_file);
        if (out_file_reverse)
            fclose(out_file_reverse);
        if (out_file_uppercase)
            fclose(out_file_uppercase);
        free(concatenated);
        return EXIT_FAILURE;
    }

    char buffer[MAX_BUFFER_SIZE];
    while (fgets(buffer, sizeof(buffer), in_file) != NULL)
    {
        char reversed_line[MAX_BUFFER_SIZE];
        strncpy(reversed_line, buffer, sizeof(reversed_line) - 1);
        reversed_line[sizeof(reversed_line) - 1] = '\0';
        char *reversed = str_reverse(reversed_line);
        if (reversed != NULL)
        {
            fprintf(out_file_reverse, "%s", reversed);
        }
        else
        {
            fprintf(out_file_reverse, "Error reversing string\n");
        }

        char lowercased_line[MAX_BUFFER_SIZE];
        strncpy(lowercased_line, buffer, sizeof(lowercased_line) - 1);
        lowercased_line[sizeof(lowercased_line) - 1] = '\0';
        char *lowercased = str_to_lowercase(lowercased_line);
        if (lowercased != NULL)
        {
            fprintf(out_file_uppercase, "%s", lowercased);
        }
        else
        {
            fprintf(out_file_uppercase, "Invalid characters in string\n");
        }
    }

    fclose(in_file);
    fclose(out_file_reverse);
    fclose(out_file_uppercase);
    free(concatenated);

    return EXIT_SUCCESS;
}