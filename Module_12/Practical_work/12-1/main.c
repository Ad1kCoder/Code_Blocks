#include <stdio.h>
#include <stdlib.h>

int n;


int main(){
    printf("Enter the length of the array: ");
    scanf("%d", &n);
    int *parr = malloc(n*sizeof(int));
    if (parr != NULL){
        printf("Enter an array:\n");
        for(int i = 0; i < n; i++){
            scanf("%d", parr+i);
        }
        printf("\n\n");
        printf("The array you entered: ");
        for(int i = 0; i < n; i++){
            printf("%d", *(parr+i));
            printf("\t");
        }
        printf("\n\n");

    }
    free(parr);
    printf("The array you entered after freeing the memory: ");
    for(int i = 0; i < n; i++){
        printf("%d", *(parr+i));
        printf("\t");
    }

    return 0;

}
