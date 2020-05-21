/*
008 - Reverse input line string and print it.
Version: 1.0
*/
#include <stdio.h>
// Maximum lengths definitions
#define MAX_CHAR_LENGTH 1000

// Reverse function
void reverse(char *string) {
    // Variable definitions
    int length;
    char strCopy[MAX_CHAR_LENGTH];
    // Get string length
    for (length = 0; string[length] != '\0'; length++);
    // Copy string to strCopy array
    for (int i = 0; i <= length; i++)
    {
        strCopy[i] = string[i];
    }
    // Make string as reverse of it
    for (int i = 0; i < length; i++)
    {
        string[i] = strCopy[length-i-1];
    }
    // Make last char to null
    string[length] = '\0';
}

int main()
{
    // Variable definitions
    int c, charCount = 0;
    char data[MAX_CHAR_LENGTH]; 

    printf("Write something. On Windows press Enter then Ctrl+Z"); 
    printf("\nand then Enter, on Linux press Ctrl+D to end...\n\n");

    // Read data, process it and save to data array untill EOF
    while ((c = getchar()) != EOF)
    {
        // If newline character appears
        if (c == '\n')
        {
            // Save last char to null
            data[charCount++] = '\0';
            // Set character counter to 0
            charCount = 0;

            // Reverse input
            reverse(data);

            // Print reversed data
            printf("%s\n", data);
        }
        else
        {
            // Save readed character
            data[charCount++] = c;
        }
    }

    return 0;
}

