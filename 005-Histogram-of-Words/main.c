/*
005 - Prints horizontal histogram for every words.
Version: 1.1
*/
#include <stdio.h>

// Max. length of words in one line
#define MAX_WORD_LENGTH 50
#define IN  1
#define OUT 0


int main()
{
    // Variable definitions
    int c, cc = 0, i = 0, wordCounter = 1, state = OUT;
    int word[MAX_WORD_LENGTH];

    printf("Write something and press enter. On Windows press Enter then Ctrl+Z"); 
    printf("\nand then Enter, on Linux press Ctrl+D to end...\n\n");

    // Count loop
    while ((c = getchar()) != EOF)
    {
        // Count chars
        if (c != ' ' && c != '\t' && c != '\n')
        {
            // State IN means that curser is in the word
            state = IN;
            cc++; // Character counter
        }

        // If input is whitespace character then;
        if (c == ' ' || c == '\t' || c == '\n')
        {
            // Checks that multiple whitespaces not occured
            if (state == IN)
            {
                // State OUT means that curser is out of the word
                state = OUT;
                // Get character counter to word array
                word[i++] = cc;
                // Clear character counter
                cc = 0;
            }
            
        }

        // If new line appears then print histogram
        if (c == '\n')
        {
            for (int j = 0; j < i; j++)
            {
                printf("%d: ", wordCounter++);
                for (int k = 0; k < word[j]; k++)
                {
                    printf("|");
                }
                printf("\n");
            }
            printf("\n");
            i = 0;
        }
    }

    return 0;
}

