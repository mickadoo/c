#include "hashmap.h"
#include <stdio.h>

int main()
{
    install("car", "vroom");
    install("man", "hello");
    printf("%s\n", lookup("car")->defn);
    printf("%s\n", lookup("man")->defn);
    undef("car");
    printf("%s\n", (NULL == lookup("car")) ? "null" : "not null");
}
