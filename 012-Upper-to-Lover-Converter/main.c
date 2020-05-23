/*
012 - Converts upper character to lower character.
Version: 1.0
*/
#include <stdio.h>
// Maximum lengths definitions
#define MAX_LINE_LENGTH 1000
#define MAX_CHAR_LENGTH 1000

// Upper to lower function
void toLower(int *c) {
    if (*c >= 'A' && *c <= 'Z')
    {
        *c = *c+32;
    }
}

int main()
{
    // Variable definitions
    int c, count = 0, line = 0;
    char data[MAX_LINE_LENGTH][MAX_CHAR_LENGTH];

    printf("Write something. On Windows press Enter then Ctrl+Z");
    printf("\nand then Enter, on Linux press Ctrl+D to end...\n\n");
    
    // Read data, process it and save to data array untill EOF
    while ((c = getchar()) != EOF)
    {
        // Check for newline character
        if (c == '\n')
        {
            // If newline appears then, set last char to null
            data[line++][count] = '\0';
            // Reset counter
            count = 0;
        }
        // If character is between A and Z then convert it to lower case
        else if (c >= 'A' && c <= 'Z')
        {
            // Send character to toLower function
            toLower(&c);
            // Save converted character
            data[line][count++] = c;
        }
        else
        {
            // Save character without any change
            data[line][count++] = c;
        }
    }

    printf("\n!!! Upper to Lower Converted Data !!!\n\n");

    // Print all lines
    for (int i = 0; i < line; i++)
    {
        // Print characters
        for (int j = 0; data[i][j] != '\0'; j++)
        {
            printf("%c", data[i][j]);
        }
        
        printf("\n");
    }

    return 0;
}
