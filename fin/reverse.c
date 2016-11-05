#include <stdio.h>

#define MAX_LENGTH 120

int readline(char line[], int max_length);

int main()
{
    char original[MAX_LENGTH];
    int length, i;

    while ((length = readline(original, MAX_LENGTH)) > 0) {
        for (i = (length - 1); i >= 0; --i)
            putchar(original[i]);
        printf("\n");
    }
}

int readline(char buffer[], int max_length)
{
    int c, i;
    i = 0;

    while ((c = getchar()) != EOF && c != '\n') {
        if (i < max_length) // no overflow. ignore past max
            buffer[i] = c;

        ++i;
    }

    return i;
}
