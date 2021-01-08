/*
016 - Prints ASCII value of a given character.
Version: 1.0
*/
#include <stdio.h>

int main()
{
    // Variable definitions
    char c;

    // Get the character
    printf("Write a character and press Enter: ");
    scanf("%c", &c);

    // Print the character in 3 different number format
    printf("\nASCII value of a character is: \n");
    printf("Decimal: %d \nHexadecimal: %X \nOctal: %o", c, c, c);

    return 0;
}