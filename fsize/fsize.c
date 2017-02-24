#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "directory.h"

void dirwalk(char *, void (*fcn)(char*));
int stat(const char*, struct stat *);
void fsize(char *);

int main(int argc, char** argv)
{
    if (argc == 1)
        fsize(".");
    else
        while (--argv > 0)
            fsize(*++argv);
    
    return 0;
}

void fsize(char* name)
{
    struct stat stbuf;

    if (stat(name, &stbuf) == -1) {
        fprintf(stderr, "fsize: can't access %s\n", name);
        return;
    }
    if ((stbuf.st_mode & S_IFMT) == S_IFDIR)
        dirwalk(name, fsize);
    printf("%8ld %s\n", stbuf.st_size, name);
}

void dirwalk(char* dir, void (*fcn)(char*))
{
    char name[MAX_PATH];
    DirEnt* dp;
    DIR *dfd;

    if ((dfd = open_dir(dir)) == NULL) {
        fprintf(stderr, "dirwalk can't open %s\n", dir);
        return;
    }

    while ((dp = read_dir(dfd)) != NULL) {
        if (strcmp(dp->name, ".") == 0 || strcmp(dp->name, "..") == 0)
            continue;
        if (strlen(dir) + strlen(dp->name) + 2 > sizeof(name))
            fprintf(stderr, "dirwalk: name %s/%s too long\n", dir, dp->name);
        else {
            sprintf(name, "%s/%s", dir, dp->name);
            (*fcn)(name);
        }
    }
    close_dir(dfd);
}
