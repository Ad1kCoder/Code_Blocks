#include <stdio.h>
#include <stdlib.h>

int main(){
    int mode;
    printf("Выберите подпрограмму:\n 1.Числа в столбик\n 2.Таблица Пифагора\n 3.Сортировка\n\n");
    scanf("%d", &mode);
    printf("\n");
    switch(mode){
        case 1:
            printf("Числа в столбик\n");
            counter();
        break;
        case 2:
            printf("Таблица Пифагора\n");
            Pythagoras();
        break;
        case 3:
            printf("Сортировка\n");
            inSortOut();
        break;
        default:
            printf("Введено неверное значение, попробуйте еще раз\n\n");
        }
    return 0;
}

int counter (voit){
    int x=10;
    while (x>0){
        x--;
        printf("%d\n",x);
    }
}

int Pythagoras (void){
    for (int a=1;a<10;a++){
        for(int b=1;b<10;b++){
            int c=a*b;
            printf("%d\t",c);
        }
        printf("\n\n");
    }
}

inSortOut(void){
    int arr[10];
    printf("Введите десять чисел:\n");
    for(int i=0;i<10;i++){
        scanf("%d", &arr[i]);
        }
    printf("\n");
    printf("Несортированный массив: ");
    for(int i=0;i<10;i++){
        printf("%d\t", arr[i]);
    }
    printf("\n");
    for(int i=0;i<10;i++){
        for(int j=0;j<10-i;j++){
            if (arr[j]>arr[j+1]){
                int k = arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=k;
            }
        }
    }
    printf("\n");
    printf("Отсортированный массив: ");
    for(int i=0;i<10;i++){
        printf("%d\t", arr[i]);
    }
    printf("\n");
}
