#include <stdio.h>

/**
 * count the number of 1-bits in x
 * stupidly puts all the loop on one line just as a test
 */
int main()
{
    int x = 7, count = 0;
    
    while (x != 0)
        x &= (x - (++count > 0));
        
    printf("%d\n", count);
}
