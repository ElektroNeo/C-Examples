/*
018 - Converts binary string to decimal number.
Version: 1.0
*/
#include <stdio.h>
// Maximum lengths definitions
#define MAX_CHAR_LENGTH 1000

int main()
{
    // Variable definitions
    int num = 0, len = 0, two = 1;
    char s[MAX_CHAR_LENGTH] = { 0 };

    // Get binary number
    printf("Write binary number and press Enter: ");
    scanf("%s", s);

    // Get string length
    for(; s[len] != '\0'; len++);

    // Convert binary to decimal
    for(int i = len-1; i >= 0; i--) {
        num += (s[i] - '0') * two;
        two *= 2;
    }

    // Print converted number
    printf("The decimal of given binary is: %d", num);

    return 0;
}