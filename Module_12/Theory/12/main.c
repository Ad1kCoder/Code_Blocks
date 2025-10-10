#include <stdio.h>
#include <stdlib.h>

int main()
{
   char *p = calloc(5,1);
   char *str = "Hello";
   stpcpy(p, str);
   printf("%s\n", p);
   free(p);
   printf("%s\n", p);
   return 0;
}
