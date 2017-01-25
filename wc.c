#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "head/getword.h"

#define MAXWORD 100

struct node *addtree(struct node *, char *);
void treeprint(struct node *);
int getword(char *, int);
struct node *talloc(void);

struct node {
    char *word;
    int count;
    struct node *left;
    struct node *right;
};

/**
 * word frequency count
 */
int main()
{
    struct node *root;
    char word[MAXWORD];

    root = NULL;
    while (getword(word, MAXWORD) != EOF)
        if (isalpha(word[0]))
            root = addtree(root, word);

    treeprint(root);
    return 0;
}

/**
 * add a node with word, at or below parent
 */
struct node * addtree(struct node *parent, char *word)
{
    int cond;

    if (parent == NULL) { // a new word
        parent = talloc();
        parent->word = strdup(word);
        parent->count = 1;
        parent->left = parent->right = NULL;
    } else if ((cond = strcmp(word, parent->word)) == 0)
        parent->count++;
    else if (cond < 0)
        parent->left = addtree(parent->left, word);
    else
        parent->right = addtree(parent->right, word);

    return parent;
}

/**
 * print tree of words in order
 */
void treeprint(struct node *p)
{
    if (p != NULL) {
        treeprint(p->left);
        printf("%4d %s\n", p->count, p->word);
        treeprint(p->right);
    }
}


struct node * talloc(void)
{
    return (struct node *) malloc(sizeof(struct node));
}

