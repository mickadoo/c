#include <stdio.h>

int main()
{
    int i;
    char original[5];

    original[0] = 'h';
    original[1] = 'e';
    original[2] = 'l';
    original[3] = 'l';
    original[4] = 'o';

    
    for (i = 0; i < 5; i++)
        printf("%c", original[i] + i);

    printf("\n");

    return 0;
}
