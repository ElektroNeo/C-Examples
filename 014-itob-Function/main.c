/*
014 - Converts 10 base number to b base number.
Version: 1.0
*/
#include <stdio.h>

/* 
 * This function converts 10 base (n) number to (b) base
 * number whic characters represented in (*s) string
 * and then save it to (*baseN) string.
 */
void itob(int n, char *s, int b, char *baseN) {
    // Variable definitions
    int i;
    // Used for reverse string
    char copy[256];
    // Convert 10 base number to b base number
    // with reverse order
    for (i = 0; n != 0; ++i)
    {
        copy[i] = s[n%b];
        n /= b;
    }
    // Save last char to null
    baseN[i--] = '\0';
    
    // Reverse copy string and save it to baseN string
    for (int j = 0; j <= i; ++j)
    {
        baseN[j] = copy[i-j];
    }
}

int main()
{
    // Variable definitions
    char baseNum[256];

    // Convert number
    itob(15247, "01234567", 8, baseNum);

    // Print converted number
    printf("%s", baseNum);
    
    return 0;
}
