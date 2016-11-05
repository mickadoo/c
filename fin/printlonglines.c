#include <stdio.h>
#define MAXLINE 80 // maximum input line size

int readline(char line[]);

/*
 * print longest line
 */
int main()
{
    int len; // current length
    int linenum = 1; // current line
    char line[MAXLINE];

    while ((len = readline(line)) > 0) {
        if (len > MAXLINE) {
            printf("%d exceeds by %d chars\n%s\n", linenum, len - MAXLINE, line);
        }
        ++linenum;
    }

    return 0;
}

/*
 * read a line into s[], return length
 */
int readline(char s[])
{
    int c, i;

    for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i)
        if (i < MAXLINE - 2) // we dont want to overflow array but we do want to read to end of line
            s[i] = c;

    if (c == '\n') { // count the new line character
        s[i] = c;
        ++i;
    }
    s[i] = '\0';

    return i;
}
