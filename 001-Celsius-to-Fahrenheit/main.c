/*
001 - Celsius to fahrenfeit converter.
Version: 1.0
*/
#include <stdio.h>

int main()
{
    // Variable definitions
    int celsius, fahrenheit = 0;

    // Get Celsius
	printf("Celsius: \n");
    scanf("%d", &celsius);

    // Convert Censius to Fahrenheit
    fahrenheit = (celsius*9)/5 + 32;

    // Print converted value
    printf("\n%d Celsius = %d Fahrenheit", celsius, fahrenheit);

	return 0;
}
