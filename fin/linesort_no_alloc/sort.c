#include <stdio.h>
#include <string.h>
#include "readlines.c"
#include "qsort.c"

#define MAXLINES 5000

char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines, char *linestore);
void writelines(char *lineptr[], int nlines);

void qsort(char *lineptr[], int left, int right);

int main()
{
    int nlines, i = 0;
    char linestore[MAXLINES * 1000];

    if ((nlines = readlines(lineptr, MAXLINES, linestore)) >= 0) {
        qsort(lineptr, 0, nlines - 1);
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("error: input too big to sort\n");
        return 1;
    }
}

