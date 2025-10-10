#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[5] = {1,2,3,4,5};
    int *p = a;
    int (*q)[5] = &a;


    printf("%d, %d\n", sizeof p, sizeof a);
    return 0;
}
