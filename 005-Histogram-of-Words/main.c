/*
005 - Prints horizontal histogram for every words.
Version: 1.0
*/
#include <stdio.h>

// Max. length of words in one line
#define MAX_WORD_LENGTH 50

int main()
{
    // Variable definitions
    int c, cc = 0, i = 0, wordCounter = 1;
    int word[MAX_WORD_LENGTH];

    printf("Write something and press Enter.");
    printf("Press Ctrl+C, Ctrl+D or Ctrl+Z to end...\n\n");

    // Count loop
    while ((c = getchar()) != EOF)
    {
        // Count chars
        if (c != ' ' && c != '\t' && c != '\n')
        {
            cc++; // Character counter
        }

        // If input is white character then;
        if (c == ' ' || c == '\t' || c == '\n')
        {
            // Get character counter to word array
            word[i++] = cc;
            // Clear character counter
            cc = 0;
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
            printf("\n\n");
            i = 0;
        }
    }

    return 0;
}

