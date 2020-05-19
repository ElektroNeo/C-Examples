/*
006 - Prints horizontal histogram for every chars.
Version: 1.0
*/
#include <stdio.h>

int main()
{
    // Variable definitions
    int c;
    int chars[96]; // chars[0] is space and chars[95] is ~

    // Reset array values
    for (int count = 0; count < 96; count++)
    {
        chars[count] = 0;
    }
    

    printf("Write something. On Windows press Enter then Ctrl+Z"); 
    printf("\nand then Enter, on Linux press Ctrl+D to end...\n\n");

    // Read all characters
    while ((c = getchar()) != EOF)
    {
        // If character is visible increase it
        if (c > 31 && c < 127)
        {
            chars[c-32]++;
        }
    }
    
    printf("!!! Histogram of Charactes !!!\n");
    printf("Char: Histogram\n\n");

    // Print visible characters
    for (int i = 0; i < 96; i++)
    {
        // Print if character is used
        if (chars[i] != 0)
        {
            // Print character
            printf("%c: ", i+32);
            // Print histogram
            for (int j = 0; j < chars[i]; j++)
                {
                    printf("|");
                }
                printf("\n");
        }
    }
    

    return 0;
}

