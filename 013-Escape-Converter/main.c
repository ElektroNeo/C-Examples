/*
013 - Converts escape character to visible escape sequence character.
Version: 1.0
*/
#include <stdio.h>

/* 
 * This function converts characters like newline and tab 
 * in s string into visible escape sequences like \n and 
 * \t as it copies the string s to t. 
 */
void escape(char *s, char *t) {
    int i, j;
    // Loop until s[i] character will null
    for (i = 0, j = 0; s[i] != '\0'; i++)
    {
        switch (s[i])
        {
        // If newline character appears
        case '\n':
            // Replace it with \ and n character
            t[j++] = '\\';
            t[j++] = 'n';
            break;
        // If tab character appears
        case '\t':
            // // Replace it with \ and t character
            t[j++] = '\\';
            t[j++] = 't';
            break;
        // If character is not escape character
        default:
            // Save scaracter without any change
            t[j++] = s[i];
            break;
        }
    }
    // Set last character ro null
    t[j] = '\0';
}

int main()
{
    // Variable definitions
    int c, count = 0, line = 0;
    char s[30] = "Tab: \t newline: \n";
    char t[30];

    // Print raw string
    printf("Raw String\n");
    printf("%s\n\n", s);

    // Process string
    escape(s, t);

    // Print processed string
    printf("Processed String\n");
    printf("%s\n\n", t);
    
    return 0;
}
