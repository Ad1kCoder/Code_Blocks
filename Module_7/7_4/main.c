#include <stdio.h>
#include <stdlib.h>

int main()
{
    int sizeArr = 10;
    int X[sizeArr];
    int Y[sizeArr];
    printf("Enter %d values for the array X:\n", sizeArr);
    for (int i=0;i<sizeArr;i++)scanf("%d", &X[i]);
    printf("\nEnter %d values for the array Y:\n", sizeArr);
    for (int i=0;i<sizeArr;i++)scanf("%d", &Y[i]);
    printf("\nInput array X:\t");
    for (int i=0;i<sizeArr;i++)printf("%d\t", X[i]);
    printf("\nInput array Y:\t");
    for (int i=0;i<sizeArr;i++)printf("%d\t", Y[i]);

    if (order(X,sizeArr)){
        for (int i=0;i<sizeArr;i++){
            if (X[i]>0) X[i]=0;
        }
    }
    if (order(Y,sizeArr)){
        for (int i=0;i<sizeArr;i++){
            if (Y[i]>0) Y[i]=0;
        }
    }
    printf("\n\nProcessing array X:\t");
    for (int i=0;i<sizeArr;i++)printf("%d\t", X[i]);
    printf("\nProcessing array Y:\t");
    for (int i=0;i<sizeArr;i++)printf("%d\t", Y[i]);
    return 0;
}

 int order (int arr[],int arrSize){
     int cnt=0;
     for (int i=0;i<arrSize;i++){
        if (arr[i]<arr[i+1]) cnt++;
     }
     if (cnt == arrSize) return 1;
     else return 0;

 }
