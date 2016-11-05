#include <stdio.h>

#define MAX_LEN 10 

int main()
{
    int lengths[MAX_LEN];
    int i, y, c, word_len, total;
    float percentage;

    word_len = total = 0;

    // init all lengths to 0
    for (i = 0; i < MAX_LEN; i++)
        lengths[i] = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            // words longer than max fit in top category
            if (word_len >= MAX_LEN)
                word_len = MAX_LEN - 1;

            printf("found word of length %d\n", word_len);
            lengths[word_len]++;
            word_len = 0;
        } else {
            word_len++;
        }
    }

    // calculate total
    for (i = 0; i < MAX_LEN; i++)
        total += lengths[i];

    printf("total %d\n\n", total);

    for (i = 0; i < MAX_LEN; i++) {
        printf("%4d :", i);
        percentage = (lengths[i] * 100.0) / total;
        for (y = 0; y < percentage; y++)
            printf("=");
        
        printf("> %.2f\n", percentage);
    }
}

