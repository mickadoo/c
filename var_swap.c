#include <stdio.h>


int main(void)
{  
    int a, b;

    a = 6;
    b = 9;
    
    a = a ^ b;
    b = a ^ b; 
    a = a ^ b; 

    printf("a %d\n", a);
    printf("b %d\n", b);
}

