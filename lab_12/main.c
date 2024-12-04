#include <lib.h>
#include <stdio.h>
#include <string.h>

#define OUT_FILE_NAME_REVERSE "output_reverse.txt"
#define OUT_FILE_NAME_UPPERCASE "output_uppercase.txt"
#define IN_FILE_NAME "input.txt"

int main()
{
    char str1[100];
    char str2[100];

    printf("Enter the first string: ");
    scanf("%s", str1);

    printf("Enter the second string: ");
    scanf("%s", str2);

    char *concatenated = strconcat(str1, str2);
    printf("The concatenated string is: %s\n", concatenated);

    // TASK 2
    FILE *in_file = fopen(IN_FILE_NAME, "r");

    if (!in_file)
    {
        printf("Cannot open input file\n");
        return EXIT_FAILURE;
    }

    FILE *out_file_reverse = fopen(OUT_FILE_NAME_REVERSE, "w");
    FILE *out_file_uppercase = fopen(OUT_FILE_NAME_UPPERCASE, "w");

    if (!out_file_reverse || !out_file_uppercase)
    {
        printf("Cannot open output file\n");
        return EXIT_FAILURE;
    }

    char buffer[256];
    while (fgets(buffer, sizeof(buffer), in_file) != NULL)
    {
        char reversed_line[256];
        strcpy(reversed_line, buffer);
        char *reversed = str_reverse(reversed_line);
        fprintf(out_file_reverse, "%s", reversed);

        char lowercased_line[256];
        strcpy(lowercased_line, buffer);
        char *lowercased = str_to_lowercase(lowercased_line);
        fprintf(out_file_uppercase, "%s", lowercased);
    }

    fclose(in_file);
    fclose(out_file_reverse);
    fclose(out_file_uppercase);

    return EXIT_SUCCESS;
}