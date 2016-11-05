#include <stdio.h>
#include <stdlib.h>

#define SINGLELINE 0
#define MULTILINE 1
#define SEQ_LEN 3
#define TRUE 1
#define FALSE 0

char sequence[SEQ_LEN];
char buffer[SEQ_LEN];

void ignore(int type);
void set_sequence(int type);
int equal(char first[], char second[]);
void push();
void init_buffer();

/**
 * remove all comments from a c source file
 */
int main() {

    int current, last, ignored;

    while ((current = getchar()) != EOF) {
        if (current == '/' && last == '/') {
            ignore(SINGLELINE);
            last = 0;
            continue;
        } else if ( current == '*' && last == '/') {
            ignore(MULTILINE);
            last = 0;
            continue;
        }

        // if not ignored then output
        putchar(last);
        last = current;
    }

    putchar(last); // that final one

    return 0;
}
    
/**
 * ignore (do not output) all characters up to a certain sequence
 */
void ignore(int type) {

    extern char sequence[];
    extern char buffer[];

    init_buffer();
    set_sequence(type);

    while (equal(sequence, buffer) == FALSE) {
        push();
    }
}

/**
 * checks if two arrays are equal up until first \0 of the first
 */
int equal(char first[], char second[]) {
    
    int i;

    for (i = 0; i < SEQ_LEN; i++) {
        
        if (first[i] == '\0') {
            return TRUE;
        }
 
        if (first[i] != second[i]) {
            return FALSE;
        }
   }

    // should never get here. array might end with non \0
    exit(1);
}

/**
 * pushes a character from getchar() to first position on an array of characters
 */
void push() {

    extern char buffer[];
    int next, prev, i;
    next = getchar();

    if (next == EOF) {
       exit(1); // encountered unclosed comment
    }            
   
    for (i = 0; i < SEQ_LEN; i++) {
        prev = buffer[i];
        buffer[i] = next;
        next = prev; 
    }
}

/**
 * sets the buffer to empty array
 */
void init_buffer()
{
    extern char buffer[];
    int i = SEQ_LEN - 1;

    while (i >= 0) {
        buffer[i] = '\0';
        --i;
    }
}

/**
 * sets the ending sequence for a comment
 * the sequence is reversed as it is pushed into a character array
 */
void set_sequence(int type) {

    extern char sequence[];

    switch (type) {
        case SINGLELINE:
            sequence[0] = '\n';
            sequence[1] = '\0';
            sequence[2] = '\0';
            break;
        case MULTILINE:
            sequence[0] = '/';
            sequence[1] = '*';
            sequence[2] = '\0';
    } 
}
