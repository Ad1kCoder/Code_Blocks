#include <stdio.h>
#include <stdlib.h>

int main()
{
    int sizeArr = 5;
    int A[sizeArr];
    int sum=0;
    printf("Enter five numbers:\n");
    for (int i=0;i<sizeArr;i++){
        scanf("%d", &A[i]);
    }
    printf("\nInput array:\t");
    for (int i=0;i<sizeArr;i++){
        printf("%d\t", A[i]);
        sum+=A[i];
    }
    float av = (float)sum/sizeArr;
    printf("\nAverage value of the input array: %f\n", av);

    return 0;
}
