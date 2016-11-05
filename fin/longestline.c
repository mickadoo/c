#include <stdio.h>

#define MAXLINE 1000 // maximum input line size

// externals
int max; // max so far
char line[MAXLINE]; // current line
char longest[MAXLINE]; // longest so far

// prototypes
int readline(void);
void set_current_to_longest(void);

/*
 * print longest line
 */
int main()
{
    int len; // current length
    extern int max; // max so far
    extern char longest[];

    max = 0;
    while ((len = readline()) > 0) {
        if (len > max) {
            max = len;
            set_current_to_longest();
        }
    }

    if (max > 0)
        printf("\n%s\n", longest);

    return 0;
}

/*
 * read a line into s[], return length
 */
int readline()
{
    int c, i;
    extern char line[];

    for (i = 0; i < (MAXLINE - 1) && (c = getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;
    if (c == '\n') { // count the new line character
        line[i] = c;
        ++i;
    }
    line[i] = '\0';

    return i;
}

/*
 * copies the current line[] into longest[]
 */
void set_current_to_longest()
{
    int i = 0;
    extern char line[], longest[];

    while ((longest[i] = line[i]) != '\0')
        ++i;
}

