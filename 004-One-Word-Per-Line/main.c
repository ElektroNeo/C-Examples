/*
004 - Prints one word per line after write somethng and press Enter.
Version: 1.1
*/
#include <stdio.h>

#define IN  1
#define OUT 0

int main()
{
    // Variable declerations
    int c, wc = 0, state = OUT;

    printf("Write something and press enter. On Windows press Enter then Ctrl+Z"); 
    printf("\nand then Enter, on Linux press Ctrl+D to end...\n\n");

    while ((c = getchar()) != EOF)
    {
        // If next character is a whitespace
        if (c == ' ' || c == '\n' || c == '\t')
        { 
            // Ignores multiple whitespaces
            if (state == IN)
            {
                state = OUT;
                putchar('\n');
            }
        }
        else
        {
            // If reading new word
            if (state == OUT)
            {
                state = IN;
                ++wc;   // Increase word counter
            }
            // Print character
            putchar(c);
        }
    }

    // Print word counter
    printf("\nNumber of words: %d\n", wc);

    return 0;
}