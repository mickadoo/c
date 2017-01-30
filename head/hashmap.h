#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASHSIZE 101

// define structs
struct nlist {
    struct nlist* next;
    char *name;
    char *defn;
};

// function declarations
struct nlist* lookup(char* s);
struct nlist* install(char* name, char* defn);
unsigned hash(char *s);
void undef(char* s);

// static variables
static struct nlist* hashtab[HASHSIZE];

/**
 * installs a new value to the hashmap
 */
struct nlist* install(char* name, char* defn)
{
    struct nlist* np;
    unsigned hashval;

    if ((np = lookup(name)) == NULL) { // not found
        np = (struct nlist*) malloc(sizeof(*np));
        if (np == NULL) // malloc failed
            return NULL;
        np->name = strdup(name);
        if (np->name == NULL) // strdup failed or name is null
            return NULL;
        hashval = hash(name);
        np->next = hashtab[hashval]; // link existing first element
        hashtab[hashval] = np; // replace first element
    } else
        free((void*) np->defn); // unset previous defn

    if ((np->defn = strdup(defn)) == NULL)
        return NULL; // strdup failed

    return np;
}

/**
 * unsets an entry in the hashmap
 */
void undef(char* s)
{
    struct nlist* np;
    struct nlist* prev;

    for (np = hashtab[hash(s)]; np != NULL; prev = np, np = np->next)
        if (strcmp(s, np->name) == 0) {
            if (prev != NULL && np->next != NULL)
                prev->next = np->next; // fill in missing link
            free((void*) np->defn);
            free((void*) np->name);
            free((void*) np->next);
        }
    
}

/**
 * returns nlist with name s or NULL
 */
struct nlist* lookup(char* s)
{
    struct nlist* np;

    for (np = hashtab[hash(s)]; np != NULL; np = np->next)
        if (strcmp(s, np->name) == 0)
            return np; // found
    return NULL;
}

/**
 * create simple hash for storing and lookup
 */
unsigned hash(char *s)
{
    unsigned hashval;

    for (hashval = 0; *s != '\0'; s++)
        hashval = *s + 31 * hashval;
    
    return hashval % HASHSIZE;
}
