#include <stdio.h>
#include <string.h>

int tolower(int c);
int toupper(int c);

int main(int argc, char* argv[])
{
    int (*func)(int c);
    int c;

    if (strcmp(argv[0], "lower"))
        func = tolower; 
    else
        func = toupper;

    while ((c = getchar()) != EOF)
        putchar(func(c));
}
