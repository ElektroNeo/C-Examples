/*
010 - Removes one line, inline and multiline comments in C code.
Version: 1.0
*/
#include <stdio.h>
// Maximum lengths definitions
#define MAX_LINE_LENGTH 1000
#define MAX_CHAR_LENGTH 1000

// Comment state definitions
#define NO_COMMENT          0
#define LINE_COMMENT        1
#define IN_LINE_COMMENT     2
#define MULTI_LINE_COMMENT  3

int main()
{
    // Variable definitions
    int c, charCount = 0, count = 0, line = 0, lastChar = -1, commentState = NO_COMMENT;
    char data[MAX_LINE_LENGTH][MAX_CHAR_LENGTH];

    printf("Write something. On Windows press Enter then Ctrl+Z");
    printf("\nand then Enter, on Linux press Ctrl+D to end...\n\n");
    
    // Read data, process it and save to data array untill EOF
    while ((c = getchar()) != EOF)
    {
        // Increase charCounter (nonspace characters) when there is no comment
        // This will use for check one line comments
        if ((c != ' ' && c != '\t') && commentState == NO_COMMENT)
        {
            charCount++;
        }
        // Check if one line comment appears. This will delete this line
        if (c == '/' && lastChar == '/' && charCount == 2 && commentState == NO_COMMENT)
        {
            // Set state and resets counter
            // After this program will wait for newline character
            commentState = LINE_COMMENT;
            count = 0;
            charCount = 0;
        }
        // Check if comment appears after some chars. This will delete just comment
        else if (c == '/' && lastChar == '/' && charCount > 2 && commentState == NO_COMMENT)
        {
            // Set state
            commentState = IN_LINE_COMMENT;
            // Seve null char before comment starts to delete comment
            data[line++][count-1] = '\0';
            // Reset counters
            count = 0;
            charCount = 0;
        }
        // Check if multiline comment appears
        else if (c == '*' && lastChar == '/' && commentState == NO_COMMENT)
        {
            // Set state and decrease count to remove / char
            commentState = MULTI_LINE_COMMENT;
            count--;
        }
        // Check for any non comment char and save it
        else if (c != '\n' && commentState == NO_COMMENT)
        {
            // Save readed character
            data[line][count++] = c;
            // Set last char to check comments
            lastChar = c;
        }
        // Check if noncomment newline char appears
        else if (c == '\n' && commentState == NO_COMMENT)
        {
            // Set last char to null and reset counters
            data[line++][count] = '\0';
            count = 0;
            charCount = 0;
        }
        // These two else if statements resets comment states
        else if (commentState == LINE_COMMENT && c == '\n')
        {
            commentState = NO_COMMENT;
        }
        else if (commentState == IN_LINE_COMMENT && c == '\n')
        {
            commentState = NO_COMMENT;
        }
        // If comment is multiline
        else if (commentState == MULTI_LINE_COMMENT)
        {
            // Check for multiline comment end
            if (c == '/' && lastChar == '*')
            {
                // Reset comment state
                commentState = NO_COMMENT;
            }
            // // Set last char to check comments
            lastChar = c;
        }
    }

    printf("\n!!! Comment Deleted Code !!!\n\n");

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
