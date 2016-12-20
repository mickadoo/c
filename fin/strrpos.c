#include <stdio.h>
#include <string.h>

int strrpos(char str[], char search[]);

int main()
{
    char string[] = "a string to search rightmost ring";
    char search[] = "ring";

    printf("expect %d %d\n", strlen(string) - 4, strrpos(string, search));

    return 0;
}

int strrpos(char str[], char search[])
{
    int x, y, z;

    for (x = strlen(str); x > 0; x--) {
        for (y = x, z = 0; str[y] == search[z] && search[z] != '\0'; y++, z++)
            ;
        if (z > 0 && search[z] == '\0')
            return x;
    }

    return -1;
}
