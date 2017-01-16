#include "head/getword.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100
#define NKEYS (sizeof keytab / sizeof(struct key))

struct key {
    char *word;
    int count;
} keytab[] = {
    {"auto", 0},
    {"break", 0},
    {"case", 0},
    {"char", 0},
    {"const", 0},
    {"continue", 0},
    {"default", 0},
    {"do", 0},
    {"unsigned", 0},
    {"void", 0},
    {"volatile", 0},
    {"while", 0},
};

int getword(char *, int);
struct key *array_search(char *, struct key *, int);

int main()
{
    char word[MAXWORD];
    struct key *key_p;

    while (getword(word, MAXWORD) != EOF)
        if (isalpha(word[0]))
            if ((key_p=array_search(word, keytab, NKEYS)) != NULL)
                key_p->count++;

    for (key_p = keytab; key_p < keytab + NKEYS; key_p++)
        if (key_p->count > 0)
            printf("%4d %s\n", key_p->count, key_p->word);

    return 0;
}

struct key *array_search(char *needle, struct key *haystack, int n)
{
    int cond;
    struct key *low = &haystack[0];
    struct key *high = &haystack[n];
    struct key *mid;

    while (low < high) {
        mid = low + (high - low) / 2;
        if ((cond = strcmp(needle, mid->word)) < 0)
            high = mid;
        else if (cond > 0)
            low = mid + 1;
        else
            return mid;
    }

    return NULL;
}
