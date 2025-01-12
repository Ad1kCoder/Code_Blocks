#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a= 256;
    int *pa;
    pa = &a;
    printf("Var %d\n", a);
    printf("Adr %p\n\n", (void*)pa);

    *pa = 1024;


    printf("Var %d\n", a);
    printf("Adr %p\n", (void*)pa);

    return 0;
}
