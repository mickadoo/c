#include <stdio.h>

void concat(char *base, char *new);
int strend(char *string, char end);

char main()
{
    char ames[] = "hello";
    concat(ames, " sam");
    printf("should be 'hello sam' :: %s\n", ames);
    printf("should be 1 :: %d\n", strend("foo", 'o'));
    printf("should be 0 :: %d\n", strend("foo", 'r'));
}

/**
 * adds new to end of base
 */
void concat(char *base, char *new)
{
    while (*++base) // find end of base
        ;

    while (*base++ = *new++) // append
        ;
}

/**
 * returns 1 if end char is last char of string, 0 otherwise
 */
int strend(char *string, char end)
{
    while (*++string)
        ;

    return *(string-1)  == end;
}
