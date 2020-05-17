/*
003 - Counts the words, lines, and characters of the input.
Version: 1.0
*/
#include <stdio.h>

#define IN 1
#define OUT 0

int main()
{
    // Variable definitions
    int c, wc = 1, lc = 0, cc = 0, state = IN;

    printf("Write something. Press Ctrl+C, Ctrl+D or Ctrl+Z to end...\n");
    printf("Write at least one line with character befor end...\n\n");

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
