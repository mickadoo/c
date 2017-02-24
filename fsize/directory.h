#include <stdlib.h>
#include <unistd.h>
#include "localdir.h"

#define NAME_MAX 14
#define MAX_PATH 1024

typedef struct {
    long inode_num;
    char name[NAME_MAX + 1];
} DirEnt;

typedef struct {
    int fd;
    DirEnt de;
} DIR;

DIR* open_dir(char* dir_name);
DirEnt* read_dir(DIR* dir);
void close_dir(DIR* dir);
int fstat(int fd, struct stat *);

DIR* open_dir(char* dirname)
{
    int fd;
    struct stat stbuf;
    DIR* dp;

    if (
        (fd = open(dirname, O_RDONLY, 0)) == -1
        || fstat(fd, &stbuf) == -1
        || (stbuf.st_mode & S_IFMT) != S_IFDIR
        || (dp = (DIR*) malloc(sizeof(DIR))) == NULL
    )
        return NULL;
    dp->fd = fd;
    return dp;
}

void close_dir(DIR* dp)
{
    if (dp) {
        close(dp->fd);
        free(dp);
    }
}

DirEnt* read_dir(DIR *dp)
{
    struct direct dirbuf;
    static DirEnt d;

    while (read(dp->fd, (char*) &dirbuf, sizeof(dirbuf)) == sizeof(dirbuf)) {
        if (dirbuf.d_ino == 0) // not in use
            continue;
        d.inode_num = dirbuf.d_ino;
        strncpy(d.name, dirbuf.d_name, DIRSIZ);
        d.name[DIRSIZ] = '\0';
        return &d;
    }
    return NULL;
}
