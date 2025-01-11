#include <stdio.h>
#include <stdlib.h>

int main()
{
    int sizeArr = 10;
    int A[sizeArr];
    int max = 0;
    int indx = 0;
    printf("Enter %d numbers:\n", sizeArr);
    for (int i=0;i<sizeArr;i++){
        scanf("%d", &A[i]);
    }
    printf("\nInput array:\t");
    for (int i=0;i<sizeArr;i++){
        printf("%d\t", A[i]);
    }
    max = A[0];
    for (int i=1;i<sizeArr;i++){
        if (A[i]>max){
            max = A[i];
            indx = i;
        }
    }
    printf("\nMaximum value in array: %d\nIndex of maximum value in array: %d\n",max,indx);
    return 0;
}
