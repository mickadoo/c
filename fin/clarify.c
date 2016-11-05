#include <stdio.h>

int main()
{
    int c;

    while ((c = getchar()) != EOF) {
        switch (c) {
            case ' ':
                printf("\\s"); 
                break;
            case '\t':
                printf("\\t");
                break;
            case '\n':
                printf("\\n\n");
                break;
            default:
                putchar(c);
        }
    }
}
