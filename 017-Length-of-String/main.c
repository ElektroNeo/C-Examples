/*
017 - Prints length of a given string.
Version: 1.0
*/
#include <stdio.h>

int main()
{
    // Variable definitions
    int c, charCount = 0;

    printf("Write something. On Windows press Enter then Ctrl+Z"); 
    printf("\nand then Enter, on Linux press Ctrl+D to end...\n\n");

    // Read data, process it and save to data array untill EOF
    while ((c = getchar()) != EOF)
    {
        // If newline character appears
        if (c == '\n')
        {
            // Print the length of a string
            printf("Length of a given string is: %d\n\n", charCount);

            // Set character counter to 0
            charCount = 0;
        }

        // Increase the counter
        charCount++;
    }

    return 0;
}