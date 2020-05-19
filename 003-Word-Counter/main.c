/*
003 - Counts the words, lines, and characters of the input.
Version: 1.1
*/
#include <stdio.h>

#define IN 1
#define OUT 0

int main()
{
    // Variable definitions
    int c, wc = 1, lc = 0, cc = 0, state = IN;

    printf("Write something and press enter. On Windows press Enter then Ctrl+Z"); 
    printf("\nand then Enter, on Linux press Ctrl+D to end...\n\n");

    // Count loop
    while ((c = getchar()) != EOF)
    {
        // Counts just chars
        if (c != ' ' && c != '\t' && c != '\n')
        {
            cc++; // Character counter
        }

        // If input is white character then make state to OUT
        if (c == ' ' || c == '\t' || c == '\n')
        {
            state = OUT;
        }
        // If input is character and state is OUT then increase word counter
        else if (state == OUT)
        {
            ++wc; // Word counter
            state = IN;
        }

        if (c == '\n')
        {
            lc++; // Line counter
        }
    }

    // Print counter values.
    printf("\nThere are %d words, %d characters and %d lines.", wc, cc, lc);

    return 0;
}
