#include <stdio.h>
#include <stdlib.h>

int maxF = 2584;
int F = 0;

int Fibonacci (int n){

    if (n==0) return 0;
    if (n==1) return 1;
    return (Fibonacci(n-1)+Fibonacci(n-2));
}

int main()
{
    while(F<maxF){
        static n = 0;
        F = Fibonacci(n);
        printf("%d ", F);
        n++;
    }
    return 0;
}
