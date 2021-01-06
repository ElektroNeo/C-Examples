/*
015 - Basically encrypt and decrypt the string.
Version: 1.0
*/
#include <stdio.h>
// Maximum lengths definitions
#define MAX_CHAR_LENGTH 1000

// Encrypt function
void encryp(char *string, int key) {
    // Variable definitions
    int length = 0;

    // Get last digit of key
    key = key%10;
    
    // Get string length
    for (; string[length] != '\0'; length++);

    // Encrypt the string
    for (int i = 0; i < length; i++)
    {
        string[i] = string[i] + key;
    }

    // Make last char to null
    string[length] = '\0';
}

// Decrypt function
void decryp(char *string, int key) {
    // Variable definitions
    int length = 0;

    // Get last digit of key
    key = key%10;
    
    // Get string length
    for (; string[length] != '\0'; length++);

    // Encrypt the string
    for (int i = 0; i < length; i++)
    {
        string[i] = string[i] - key;
    }

    // Make last char to null
    string[length] = '\0';
}

int main()
{
    // Variable definitions
    int c, charCount = 0, key;
    char data[MAX_CHAR_LENGTH]; 

    printf("Write something press Enter...\n\n");

    // Read data, process it and save to data array untill new line
    while ((c = getchar()) != '\n')
    {
        // Save readed character
        data[charCount++] = c;
    }
    // Set last char to null
    data[charCount] = '\0';

    printf("Write key number: \n");
    scanf("%d", &key);

    encryp(data, key);
    printf("Encrypted string: %s\n", data);

    decryp(data, key);
    printf("Decrypted string: %s\n", data);

    return 0;
}