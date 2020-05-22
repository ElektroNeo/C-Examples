/*
009 - Divide long lines to two or more lines.
Version: 1.0
*/
#include <stdio.h>
// Maximum lengths definitions
#define MAX_LINE_CHAR_LENGTH 30
#define MAX_LINE_CHAR_LIMIT (MAX_LINE_CHAR_LENGTH + 5)
#define MAX_CHAR_LENGTH 1000

int main()
{
    // Variable definitions
    int c, charCount = 0, count = 0;
    char data[MAX_CHAR_LENGTH];

    printf("Write something. On Windows press Enter then Ctrl+Z");
    printf("\nand then Enter, on Linux press Ctrl+D to end...\n\n");
    
    // Read data, process it and save to data array untill EOF
    while ((c = getchar()) != EOF)
    {
        // If newline character appears
        if (c == '\n')
        {
            // Print processed data
            for (int i = 0; i < count; i++)
            {
                printf("%c", data[i]);
            }
            // Print newline
            printf("\n");

            // Set counters to 0
            count = 0;
            charCount = 0;
        }
        else
        {
            // Save readed character
            data[count++] = c;
            // Increase line character counter
            charCount++;
            
            // Check if space appears and line is full
            if ((c == ' ' || c == '\t') && (charCount >= MAX_LINE_CHAR_LENGTH))
            {
                // Set next character to newline
                data[count++] = '\n';
                // Reset line character counter
                charCount = 0;
            }
            // Check if line exceeds the limit
            else if (charCount >= MAX_LINE_CHAR_LIMIT)
            {
                // Split word with '-' character
                data[count++] = '-';
                // Set next character to newline
                data[count++] = '\n';
                // Reset line character counter
                charCount = 0;
            }
            // Check if word not split correctly
            else if (charCount == 1 && (c == ' ' || c == '\t'))
            {
                data[count-3] = ' ';
                count--;
            }
        }
    }

    return 0;
}
