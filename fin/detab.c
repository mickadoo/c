#include <stdio.h>
#include <stdlib.h>

short is_int(char c);

int main(int argc, char *argv[])
{
    int c, i;
    short tabspaces = 4;

    while (--argc > 0 && (*++argv)[0] == '-') {
        switch (c = *++argv[0]) {
            case 't':
                if (!is_int(*(argv[0]+ 2))) {
                    printf("value for t must be an integer\n");
                    exit(1);
                }
                tabspaces = atoi(argv[0] + 2); // integer from 2 spaces after t char
                break;
            default:
                printf("argument %c not allowed\n", *argv[0]);
        }
    }

    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            for (i = 0; i < tabspaces; i++) {
                putchar(' ');
            }
        } else {
            putchar(c);
        }
    }

    return 0;
}

short is_int(char c)
{
    return c - '0' >= 0 && c - '0' <= 9;
}
