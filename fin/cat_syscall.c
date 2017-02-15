#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

#define BUFSIZE 2

int main(int argc, char* argv[])
{
    int file_desc;
    char buffer[BUFSIZ] = "";
    int i = 1;
    int n;

    if (argc < 2) {
        write(2, "usage: cat <file> [file2]..\n", 30);
        return 1;
    }

    do {
        file_desc = open(argv[i++], O_RDONLY, 0);
        while ((n = read(file_desc, buffer, BUFSIZE - 1)) > 0) {
            write(1, buffer, n);
        }
        write(1, "\n", 1);
        close(file_desc);
    } while (i+1 < argc);
}
