#include <stdio.h>
#include <stdlib.h>

float average (int *ar, int size);

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
    puts("\n");

    printf("Average value: %f\n", average(arr,sizeArr));
    printf("Median value: %d\n", median(arr,sizeArr));
    printf("Maximum value: %d\n", max(arr,sizeArr));
    printf("Minimum value: %d\n", min(arr,sizeArr));

    return 0;
}

int median(int *ar, int size){
    int b=0;
    int m=0;
    for (int i=0;i<size;i++){
        int n = *(ar+i);
        for (int j=0;j<size;j++){
            if (n!=*(ar+j)){
                n>*(ar+j)?b++:m++;
            }
        }
        if (b==m&&b!=0&&m!=0) return n;
        else{
            b=0;
            m=0;
        }
    }
}
float average (int *ar, int size){
    int sum=0;
    for (int i=0;i<size;i++) sum+=*(ar+i);
    float avr =(float)sum/size;
    return avr;
}


int max(int *ar, int size){
    int var=*ar;
    for (int i=0;i<size;i++){
        if(var<*(ar+i)) var = *(ar+i);
    }
    return var;
}

int min(int *ar, int size){
    int var=*ar;
    for (int i=0;i<size;i++){
        if(var>*(ar+i)) var = *(ar+i);
    }
    return var;
}
