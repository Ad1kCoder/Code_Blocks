#include <stdio.h>

float a1 = 2.78;
int b1 = 651;
char c1 = 22;
char d1 = 57;
int e1 = 518;
float f1 = 43.15432;

void printVar(void){
    float a2 = 1.32;
    char b2 = 15;
    float c2 = 0.1567;
    char d2 = 22;
    int e2 = 518;
    float f2 = 287.154;
    printf("%.*f\n", 2, a2);
    printf("%d\n", b2);
    printf("%.*f\n", 4, c2);
    printf("%d\n", d2);
    printf("%i\n", e2);
    printf("%.*f\n", 3, f2);
}

void printVar2(void){
    for (int i=0;i<5;i++){
        static short cnt = 5;
        cnt++;
        printf("Counter: %d\n", cnt);
    }
}

void printVar3(void){ // Выводит в консоль тот же результат, что и  printVar2, но без исп. static
    short cnt = 5;
    for (int i=0;i<5;i++){
        static cnt = 5;
        cnt++;
        printf("Counter: %d\n", cnt);
    }
}


int main(){
    printf("%.*f\t", 2, a1);
    printf("%i\t", b1);
    printf("%d\t", c1);
    printf("%d\t", d1);
    printf("%i\t", e1);
    printf("%.*f\t", 5, f1);
    printf("\n");
    printf("\n");
    printVar();
    printf("\n");
    printVar2();
    printf("\n");
    printVar3();
    return 0;
}
