#include <stdio.h>
#include <stdlib.h>

int main()
{
    int rowSize = 4;
    int colSize = 5;
    int seed;
    int A[rowSize][colSize];
    int B[rowSize];
    printf("Enter a seed to generate random array values: ");
    scanf("%d", &seed);
    srand(seed);
    for (int i=0;i<rowSize;i++){
        for(int j=0;j<colSize;j++){
            A[i][j]=rand()%1000-500;
        }
    }
    printf("\nGenerated two-dimensional array:\n");
    for (int i=0;i<rowSize;i++){
        for(int j=0;j<colSize;j++) printf("%d\t", A[i][j]);
        printf("\n\n");
    }
    for (int i=0; i<rowSize;i++){
        if (A[i][0]>=0){
            int max = A[i][0];
            for(int j=1;j<colSize;j++){
                if (A[i][j]>max) max=A[i][j];
            }
            B[i]=max;
        }
        else{
           int min = A[i][0];
           for(int j=1;j<colSize;j++){
                if (A[i][j]<min) min=A[i][j];
            }
            B[i]=min;
        }
    }
    printf("An array whose values were defined:\t");
    for (int i=0;i<rowSize;i++) printf("%d\t", B[i]);
    printf("\n");

    return 0;
}
