#include <stdio.h>
#include <stdlib.h>

#define CHOICE 1 //0-Фибоначи; 1 - Матрица


#define maxF 2584
#define sizeArr 5
#define PRINT(a) printf("%d ", a)
#define SQR(x) (x)*(x)
#define RND(min, max) rand()%((max)-(min))+(min)

int F = 0;

int Fibonacci (int n){

    if (n==0) return 0;
    if (n==1) return 1;
    return (Fibonacci(n-1)+Fibonacci(n-2));
}

void recRand(int *ar, int size){
    if (size==0) *ar = RND(0, 127);
    else{
        *(ar+size)=RND(0, 127);
        recRand(ar,size-1);
    }
}

void recNull(int *ar, int size){
    if (size==0) *ar = 0;
    else{
        *(ar+size)=0;
        recNull(ar,size-1);
    }

}

int main()
{
#if CHOICE==0
    while(F<maxF){
        static n = 0;
        F = Fibonacci(n);
        PRINT(F);
        n++;
    }
#endif // CHOICE
#if CHOICE==1
    int fullSizeArr = SQR(sizeArr);
    int val, seed;
    int arrVar[sizeArr][sizeArr];
    int arrGuess[sizeArr][sizeArr];
    printf("Enter a seed to generate random array values: ");
    scanf("%d", &seed);
    srand(seed);
    recRand(arrVar, fullSizeArr);
    recNull(arrGuess, fullSizeArr);
    printf("Enter a value: ");
    scanf("%d", &val);
    puts("");
    for (int i=0;i<sizeArr;i++){
        for(int j=0;j<sizeArr;j++){
            if (val==arrVar[i][j])arrGuess[i][j]=1;
        }
    }
    for (int i=0;i<sizeArr;i++){
        for(int j=0;j<sizeArr;j++){
            if(arrGuess[i][j]==0) printf("x\t");
            else printf("%d\t", arrVar[i][j]);
        }
        puts("\n");
    }
#endif // CHOICE

}
