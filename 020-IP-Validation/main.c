/* Return 1 is addr is a valid IP address, return 0 otherwise */
/*
020 - Checks IP Address. If it is valid returns 1, otherwise returns 0.
Version: 1.0
*/
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int is_valid_ip(const char *addr)
{
    int counter = 0, dotCounter = 0, num;
    char numStr[4];

    while (*addr != '\0')
    {
        /* Get the number */
        if (*addr != '.')
        {
            /* If character is not a number */
            if (((*addr - '0') > 9) || ((*addr - '0') < 0))
            {
                return 0;
            }
            numStr[counter] = *addr;

            /* Increase and check a counter */
            counter++;
            if (counter > 3)
            {
                return 0;
            }
        }
        /* If dot character appears */
        else
        {
            numStr[counter] = '\0';
            num = atoi(numStr);

            /* Check 0 front of the number */
            if ((num < 100 && counter > 2) || (num < 10 && counter > 1))
            {
                return 0;
            }
            /* Check limit of the number */
            if (num > 255)
            {
                return 0;
            }

            dotCounter++;

            /* Check for the blank number */
            if (counter == 0)
            {
                return 0;
            }

            /* Reset counter */
            counter = 0;
        }

        /* Increase address */
        addr++;
    }
    /* If dot count is true */
    if (dotCounter == 3)
    {
        return 1;
    }
    /* Return false in other situations */
    return 0;
}

int main()
{
    const char *ip = "12.255.56.1";

    if (is_valid_ip(ip))
    {
        printf("Valid IP!");
    }
    else
    {
        printf("Invalid IP!");
    }

    return 0;
}