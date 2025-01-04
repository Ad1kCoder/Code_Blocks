#include <stdio.h>
#include <stdlib.h>

int main()
{

    char p1 = 12|5; //13
    char p2 = 8|7; //15
    char p3 = 24|64; //88
    char p4 = 27&3; //3
    char p5 = 16&0; //0
    char p6 = 32&1; //0
    char p7 = 5^6; //3
    char p8 = 5^5; //0
    char p9 = 8^0; //8
    char p10 = 6!=1; //1
    char p11 = 1!=1; //0
    char p12 = 0!=0; //0


    printf("p1 = %d\n",p1);
    printf("p2 = %d\n",p2);
    printf("p3 = %d\n",p3);
    printf("p4 = %d\n",p4);
    printf("p5 = %d\n",p5);
    printf("p6 = %d\n",p6);
    printf("p7 = %d\n",p7);
    printf("p8 = %d\n",p8);
    printf("p9 = %d\n",p9);
    printf("p10 = %d\n",p10);
    printf("p11 = %d\n",p11);
    printf("p12 = %d\n",p12);


    return 0;
}
