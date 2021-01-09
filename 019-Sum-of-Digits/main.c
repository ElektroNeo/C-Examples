/*
019 - Prints sum of digit for a given number.
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

    // Get number
    printf("Write some number and press Enter: ");
    scanf("%s", s);

    // Calculate sum of digit
    for(int i = 0; s[i] != '\0'; i++) {
        num += s[i] - '0';
    }

    // Print sum of digit
    printf("The sum of digit for a given number is: %d", num);

    return 0;
}