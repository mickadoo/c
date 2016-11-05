#include <stdio.h>

int main()
{
    int current, empty_last;

    while ((current = getchar()) != EOF) {
        if (current == ' ' || current == '\t')
            current = '\n';

        if (empty_last && current == '\n')
            continue;

        putchar(current);
        empty_last = (current == '\n');
    }
}

