#include <stdio.h>

#define USAGE "usage: ed FILENAME"

int main(int argc, char* argv[])
{
    if (argc != 2) {
        printf("%s\n", USAGE);
        return 1;
    }

    char* filename = argv[1];
    char c;
    FILE* output = fopen(filename, "a");

    while ((c = getchar()) != EOF)
        putc(c, output); 

    return 0;
}
