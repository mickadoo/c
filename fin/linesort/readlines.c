#include "alloc.c"

#define MAXLEN 1000

int get_line(char *, int);

int readlines(char *lineptr[], int maxlines)
{
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while ((len = get_line(line, MAXLEN)) > 0)
        if (nlines >= maxlines || (p = alloc(len)) == NULL)
            return -1;
        else {
            line[len-1] = '\0'; // delete \n at end of line
            strcpy(p, line);
            lineptr[nlines++] = p;
        }

    return nlines;
}

void writelines(char *lineptr[], int nlines)
{
    int i;

    for (i = 0; i < nlines; i++)
        printf("%s\n", lineptr[i]);

}

int get_line(char string[], int to)
{
    int i, c;

    for (i = 0; i < to-1 && (c = getchar()) != EOF && c != '\n'; ++i) 
        string[i] = c;

    if (c == '\n') 
        string[i++] = c;

    string[i] = '\0';

    return i;
}
