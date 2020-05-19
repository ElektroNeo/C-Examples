/*
007 - Removes multiple spaces, blank lines and tabs or multiple tabs (replace with space).
Version: 1.0
*/
#include <stdio.h>
// Maximum lengths definitions
#define MAX_LINE_LENGTH 100
#define MAX_CHAR_LENGTH 1000
// TRUE and FALSE definitions
#define TRUE    1
#define FALSE   0

int main()
{
    // Variable definitions
    int c, lastChar = -1, lineCount = 0, charCount = 0, checkMultiSpaceTab = FALSE, checkTab = FALSE;
    int data[MAX_LINE_LENGTH][MAX_CHAR_LENGTH]; 

    printf("Write something. On Windows press Enter then Ctrl+Z"); 
    printf("\nand then Enter, on Linux press Ctrl+D to end...\n\n");

    // Read data, process it and save to data array untill EOF
    while ((c = getchar()) != EOF)
    {
        // If newline character appears
        if (c == '\n')
        {
            // Check for multiple lines
            if (charCount != 0)
            {
                // Save last char to null
                data[lineCount][charCount++] = '\0';
                // Increase line counter
                lineCount++;
                // Set character counter to 0
                charCount = 0;
            }
        }
        else
        {
            // Check for tab character
            if (c == '\t') 
            {
                checkTab = TRUE;
            }

            // Check for multiple space and tab characters
            // Checks any configurations 
            // (space to space, tab to tab, space to tab and tab to space)
            if ((c == ' ' && lastChar == ' ') || (c == '\t' && lastChar == '\t') ||
                (c == ' ' && lastChar == '\t') || (c == '\t' && lastChar == ' '))
            {
                checkMultiSpaceTab = TRUE;
            }
            
            // Save last character
            lastChar = c;
            
            // If multispace and tabs not appears then, save character
            if (checkMultiSpaceTab == FALSE && checkTab == FALSE)
            {
                data[lineCount][charCount++] = c;
            }
            // If multispace or multitab appears then, do not save character
            else if (checkMultiSpaceTab == TRUE)
            {
                checkMultiSpaceTab = FALSE;
            }
            // If tab char appears then, save space character
            else if (checkTab == TRUE)
            {
                data[lineCount][charCount++] = ' ';
                checkTab = FALSE;
            }
        }
        
    }
    
    printf("\n!!! Processed Data !!!\n\n");

    // Print all lines
    for (int i = 0; i < lineCount; i++)
    {
        // Print characters
        for (int j = 0; data[i][j] != '\0'; j++)
        {
            printf("%c", data[i][j]);
        }
        // Print newline character
        printf("\n");
    }

    return 0;
}

