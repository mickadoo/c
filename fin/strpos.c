#include <stdio.h>
#include <stdlib.h>

int strpos(char s1[], char s2[]);

int main()
{
    char s1[] = "potatoes";
    char s2[] = "zpf"; // should return 6

    printf("%d\n", strpos(s1, s2));
}

int strpos(char s1[], char s2[])
{
    int x, y;

    for (x = 0; s1[x] != '\0'; x++) 
       for (y = 0; s2[y] != '\0'; y++) 
           if (s1[x] == s2[y])
               return x;

    return -1;
}
