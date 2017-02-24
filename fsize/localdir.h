#define DIRSIZ 14

struct direct
{
    ino_t d_ino;
    char d_name[DIRSIZ];
};
