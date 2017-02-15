#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 1000 

void open_file(char* name, FILE** fp);
char* readline(char* line, FILE* fp);

int main(int argc, char* argv[])
{
    if (argc != 3) {
        printf("Usage: %s <file1> <file2>\n", argv[0]);
        exit(1);
    }

    FILE* file1;
    FILE* file2;
    char line1[MAXLINE] = "";
    char line2[MAXLINE] = "";
    int line_num = 1;
    short int first_end;
    short int second_end;

    open_file(argv[1], &file1);
    open_file(argv[2], &file2);

     // continues until either / both files reach end or line is different.
     // mask condition (will fail if either is 0) is used to ensure it always reads from both each time 
    while ((readline(line1, file1) != NULL) & (readline(line2, file2) != NULL) && strcmp(line1, line2) == 0)
        line_num++;

    // avoid recalculation
    first_end = feof(file1);
    second_end = feof(file2);

    if (!first_end && second_end)
        printf("file %s has more lines\n", argv[1]);
    else if (first_end && !second_end)
        printf("file %s has more lines\n", argv[2]);
    else if (strcmp(line1, line2) != 0)
        printf("difference on line %d\n%s---vs---\n%s", line_num, line1, line2);
    else
        return 0;

    return 1;
}

void open_file(char* name, FILE** fp)
{
    *fp = fopen(name, "r");

    if (*fp == NULL) {
        printf("could not open %s for reading\n", name);
        exit(1);
    }
}

char* readline(char* line, FILE* fp)
{
    return fgets(line, MAXLINE, fp);
}
