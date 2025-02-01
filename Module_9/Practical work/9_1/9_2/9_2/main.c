#include <stdio.h>
#include <stdlib.h>

int seed;

void recRand(int *ar, int size){
    if (size==0) *ar = rand()%127;
    else{
        *(ar+size)=rand()%127;
        recNull(ar,size-1);
    }
}

void recNull(int *arr, int size){
    if (size==0) *arr = 0;
    else{
        *(arr+size)=0;
        recNull(arr,size-1);
    }

}

int main(){

    int sizeArr = 5;
    int fullSizeArr = sizeArr*sizeArr;
    int val;
    int arrVar[sizeArr][sizeArr];
    int arrGuess[sizeArr][sizeArr];
    printf("Enter a seed to generate random array values: ");
    scanf("%d", &seed);
    srand(seed);
    /*for (int i=0;i<sizeArr;i++){
        for(int j=0;j<sizeArr;j++){
            arrVar[i][j]=rand()%127;
        }
    }*/
    recRand(arrVar, fullSizeArr);
    recNull(arrGuess, fullSizeArr);
    for (int i=0;i<sizeArr;i++){
    for(int j=0;j<sizeArr;j++){
         printf("%d\t", arrVar[i][j]);
        }
        puts("\n");
    }
    /*for (int i=0;i<sizeArr;i++){
        for(int j=0;j<sizeArr;j++){
            arrGuess[i][j]=0;
        }
    }*/
   /* while(1){
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
    }*/
    return 0;
}
