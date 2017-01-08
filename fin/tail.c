#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_COUNT 1000
#define USAGE "usage: tail -numlines file"

int main(int argc, char *argv[])
{
    FILE *fp;
    char *linebuffer = NULL;
    size_t len = 0;
    ssize_t chars_read;
    char *linep;

    // defaults
    int line_count = 10;
    fp = stdin;

    int current_line = 0;
    int i;

    // check for arguments
    while (argc-- > 1) {
        switch (*argv[argc]) {
            case '-':
                // set line count
                line_count = atoi(++argv[argc]);
                break;
            default:
                // replace stdin with filename
                fp = fopen(argv[argc], "r");
                break;
            }
    }

    // cannot be initialized before count is known
    char *stored_lines[line_count];

    if (fp == NULL) {
        printf("could not open file for reading\n");
        exit(1);
    }

    // init storage
    for (i = 0; i < line_count; i++)
        stored_lines[i] = '\0';

    while ((chars_read = getline(&linebuffer, &len, fp)) != -1) {
        // copy new line to storage
        linep = malloc(chars_read); 
        linebuffer[chars_read - 1] = '\0'; // remove \n at eol
        strcpy(linep, linebuffer);
        stored_lines[current_line++ % line_count] = linep;
    }

    // print last n stored lines
    for (i = 0; i < line_count; i++) {
        linebuffer = stored_lines[(current_line + i) % line_count];
        if (linebuffer) // ignore if empty
            printf("%s\n", linebuffer);
    }

    free(linebuffer);
    fclose(fp);
    exit(0);
}

