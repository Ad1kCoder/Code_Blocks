#include <stdio.h>
#include <stdlib.h>

#define maxF 2584
#define PRINT(a) printf("%d ", a)

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
        PRINT(F);
        n++;
    }
    return 0;
}
