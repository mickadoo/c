#include <stdio.h>
#include <stdlib.h>

int dec2hex(int dec);
int int2literal(int i);

/**
 * converts a decimal number to hexidecimal
 * currently only hardcoded input
 */
int main()
{
    int remainder, quotient, order;
    char result[10];

    remainder = 216; 
    order = 0;

    do {
        quotient = remainder / 16;
        result[order] = dec2hex(remainder % 16);
        order++;
        remainder = quotient;
    } while (quotient > 0);

    for (order; order > 0; order--)
        printf("%c", result[order - 1]);

    printf("\n");

    return 0;
}

/**
 * returns hexidecimal character for int < 16
 */
int dec2hex(int dec)
{
    if (dec < 10)
        return int2literal(dec);

    switch (dec) {
        case 10:
            return 'A';
        case 11:
            return 'B';
        case 12:
            return 'C';
        case 13:
            return 'D';
        case 14:
            return 'E';
        case 15:
            return 'F';
        default:
            exit(1);
    }
}

/**
 * changes an integer to a string literal
 */
int int2literal(int i)
{
    char result[2];
    sprintf(result, "%d", i);

    return result[0];
}
