#include <stdio.h>
#include "m_alloc.h"

int main()
{
  char* foo = m_alloc(sizeof(char) * 1);
  *foo = 'a';
  *(foo+1) = 'b';
  *(foo+2) = 'c';
  *(foo+3) = '\0';

  printf("val %s\n", foo);

  return 0;
}
