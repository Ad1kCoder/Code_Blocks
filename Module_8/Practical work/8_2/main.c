#include <stdio.h>
#include <stdlib.h>

int main()
{
    int sizeArr = 5;
    int arr[sizeArr];
    int seed;
    printf("Enter a seed to generate random array values: ");
    scanf("%d", &seed);
    srand(seed);
    for (int i=0;i<sizeArr;i++) *(arr+i)=rand()%100-50;
    printf("\nGenerated array:\t");
    for (int i=0;i<sizeArr;i++) printf("%d\t", *(arr+i));

    for (int i=0;i<sizeArr;i++){
        for (int j=0;j<sizeArr-i;j++){
            if(*(arr+j)>*(arr+j+1)){
                int k = *(arr+j);
                *(arr+j)=*(arr+j+1);
                *(arr+j+1)=k;
            }
        }
    }
    printf("\nProcessing array:\t");
    for (int i=0;i<sizeArr;i++) printf("%d\t", *(arr+i));
    puts("");
    return 0;
}
