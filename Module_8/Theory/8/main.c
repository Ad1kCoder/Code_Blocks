#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[]={7,8,9};
    int *p;
    p = &a;
    printf("Var %d\n", a[1]);
    printf("Add %p\n", (void*)p);

   /* *p = 9;
    a = 9;

    printf("Var %d\n", a);
    printf("Add %p\n", (void*)p);*/

    return 0;
}
