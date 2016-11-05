#include <stdio.h>

#define IN 1
#define OUT 0

int main()
{
    int num_lines, num_chars, num_spaces, num_words, c, state;
    num_lines = num_chars = num_spaces = num_words = 0;

    while ((c = getchar()) != EOF) {
       switch (c){
            case '\n':
                num_lines++;
                state = OUT;
                break;
            case ' ':
                num_spaces++;
                state = OUT;
                break;
            case '\t':
                state = OUT;
                break;
            default:
                if (state != IN) {
                    num_words++;
                    state = IN;
                }

        }
        num_chars++;
    }

    printf("lines: %d\n", num_lines);
    printf("chars: %d\n", num_chars);
    printf("spaces: %d\n", num_spaces);
    printf("words: %d\n", num_words);
}
