#include "stdio.h"
int Arr1[]= {23,56,73,22};
int Arr2[]= {443,345,21,78};
float Arr3[]= {1.27,2.71,3.14,9.81};
float Arr4[]= {6.62,1.6,7.81,5.68};
char Arr5[]={'S','k','i','l','l'};
char Arr6[]={'B','o','x'};

int main (){
    for (int i=0;i<(sizeof(Arr1) / sizeof(int));i++){
        printf("%i \t",Arr1[i]);
    }
    printf("\n\n");
    for (int i=0;i<(sizeof(Arr2) / sizeof(int));i++){
        printf("%i \n",Arr2[i]);
    }
    printf("\n");
    for (int i=0;i<(sizeof(Arr3) / sizeof(float));i++){
        printf("%f \t",Arr3[i]);
    }
    printf("\n\n");
    for (int i=0;i<(sizeof(Arr4) / sizeof(float));i++){
        printf("%f \n",Arr4[i]);
    }
    printf("\n");
    for (int i=0;i<(sizeof(Arr5) / sizeof(char));i++){
        printf("%c",Arr5[i]);
    }
    printf("\n\n");
    for (int i=0;i<(sizeof(Arr6) / sizeof(char));i++){
        printf("%c \n",Arr6[i]);
    }

}



