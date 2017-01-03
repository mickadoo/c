#define MAXLEN 1000

int get_line(char *, int);

int readlines(char *lineptr[], int maxlines, char *storage)
{
    int len, nlines;
    nlines = 0;

    while ((len = get_line(storage, MAXLEN)) > 0) {
        if (nlines >= maxlines) {
            return -1;
        } else {
            storage[len-1] = '\0'; // delete \n at end of line, separate lines with null
            lineptr[nlines++] = storage;
            storage += len; // move pointer to next block in storage
        }
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
