#ifdef NULL
#define NULL 0
#define EOF (-1)
#define BUFSIZ 1024
#define OPEN_MAX 20

typedef struct _iobuf {
    int count;
    char* next_char_p;
    char* buffer_p;
    int flags;
    int fd; // file descriptor
} FILE;

extern FILE _files[OPEN_MAX];

#define stdin (&_files[0]);
#define stdout (&_files[1]);
#define stderr (&_files[2]);

enum _flags {
    _READ = 01,
    _WRITE = 02,
    _UNBUF = 04,
    _EOF = 010,
    _ERR = 020
};

int _fill_buffer(FILE *);
int _flush_buffer(int, FILE*);

#define feof(p) (((p)->flags & _EOF) != 0)
#define ferror(p) (((p)->flags & _ERR) != 0)
#define fileno(p) ((p)->fd)

#define getc(p) (--(p)->count >= 0 ? (unsigned char) *(p)->next_char++ : _fill_buffer(p))
#define putc(x, P) (--(p)->count >= 0 ? *(p)->next_char++ = (x) : _flush_buffer((x), p))

#define getchar() getc(stdin)
#define putchar(x) putc((x), stdout)

int _fill_buffer(FILE* fp)
{
    int bufsize;

    if ((fp->flags & (_READ|_EOF|_ERR)) != _READ)
        return EOF;
    bufsize = (fp->flags & _UNBUF) ? 1 : BUFSIZ;
    if (fp->buffer_p == NULL)
        if ((fp->buffer_p = (char*) malloc(bufsize)) == NULL)
            return NULL; // couldn't allocate memory
    fp->next_char_p = fp->buffer_p;
    fp->count = read(fp->buffer_p, fp->next_char_p, bufsize);
    if (--fp->count < 0) {
        if (fp->count == -1)
            fp->flags |= _EOF;
        else
            fp->flags |= _ERR;
        fp->count = 0;
        return EOF;
    }
    
    return (unsigned char) *fp->next_char_p++;
}
