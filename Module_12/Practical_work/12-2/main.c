#include <stdio.h>

#define STOCK_SIZE 64

typedef unsigned char BYTE;

BYTE Stock[STOCK_SIZE];
BYTE shift = 0;

void *stock_alloc(BYTE bytes);
void stock_reset(void);

int main(){
    int n;
    printf("Enter the length of the array: ");
    scanf("%d", &n);
    int *parr = stock_alloc(n*sizeof(int));
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
    else return 0;
    stock_reset();
    printf("The array you entered after freeing the memory: ");
    for(int i = 0; i < n; i++){
        printf("%d", *(parr+i));
        printf("\t");
    }
    return 0;
}

void *stock_alloc(BYTE bytes){
    BYTE *offset =  Stock + shift;
    if (shift + bytes > STOCK_SIZE) return NULL;
    shift += bytes;
    return offset;
}

void stock_reset(void){
    shift = 0;
    for (int i = 0; i < STOCK_SIZE; i++){
        *(Stock + i) = 0;
    }
}
