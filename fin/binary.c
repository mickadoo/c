#include <stdio.h>

/**
 * prints an integer up to 256 in binary
 */
int main(void)
{  
    char i, input = 255;

    for (i = 7; i >= 0; i--) {
        printf("%d", (input & (1 << i)) != 0);
    }
    printf("\n");

    return 0;
}

