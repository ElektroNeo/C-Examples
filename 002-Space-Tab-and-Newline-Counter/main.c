/*
002 - Space, tab and newline counter.
Version: 1.0
*/
#include <stdio.h>

int main()
{
    // Variable definitions
    int c, sc = 0, tc = 0, nc = 0;

	printf("Write something. Press Ctrl+C, Ctrl+D or Ctrl+Z to end...\n\n");

    // Count loop
    while ((c = getchar()) != EOF)
    {
        if (c == ' ')
        {
            sc++;   // Space counter
        } else if(c == '\t')
        {
            tc++;   // Tab counter
        } else if(c == '\n')
        {
            nc++;   // Newline counter
        }
    }
    
    // Print counter values.
    printf("\nThere are %d of spaces, %d of tabs and %d of newlines.", sc, tc, nc);

	return 0;
}
