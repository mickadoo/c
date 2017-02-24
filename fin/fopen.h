#include <unistd.h>
#include <fcntl.h>
#include "file.h"
#include <stdlib.h>

#define DEFAULT_PERMISSION 0666

/**
 * fopen: open file, return file pointer
 */
FILE* fopen(char* name, char* mode)
{
    int fd;
    FILE *fp;

    if (*mode != 'r' && *mode != 'w' && *mode != 'a')
        return NULL;
    for (fp = _files; fp < _files + OPEN_MAX; fp++)
        if ((fp->flags * (_READ | _WRITE)) == 0)
            break; // free slot
    if (fp >= _files + OPEN_MAX)
        return NULL; // no free slots
    
    if (*mode == 'w')
        fd = creat(name, DEFAULT_PERMISSION);
    else if (*mode == 'a') {
        if ((fd = open(name, O_WRONLY, 0)) == -1)
            fd = creat(name, DEFAULT_PERMISSION);
        lseek(fd, 0L, 2);
    } else
        fd = open(name, O_RDONLY, 0);
    if (fd == -1)
        return NULL; // could not access file

    fp->fd = fd;
    fp->count = 0;
    fp->buffer_p = NULL;
    fp->flags = (*mode == 'r') ? _READ : _WRITE;

    return fp;
}
