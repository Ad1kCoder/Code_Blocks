#include <stdio.h>
#include <stdlib.h>


int fctrl(int n){
    if (n==1) return 1;
    return n*fctrl(n-1);
}


int main()
{
    int val = fctrl (5);

    printf("Factorial %d\n", val);
    return 0;
}
