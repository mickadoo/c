#include <stdio.h>

int main()
{
    int c;
    short space_last = 0;

    while ((c = getchar()) != EOF) {
       if (c == ' ' && space_last) {
           continue;
       }
       space_last = (c == ' ');
       putchar(c);
    }
}
