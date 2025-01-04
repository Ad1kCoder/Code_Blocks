#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x1 = 25+35; //60
    int x2 = (int)(12.78+18.22); //31
    float x3 = 21.35+15; //36.35
    int x4 = 17-6; //11
    int x5 = 25-42; //-17
    float x6 = 21-13.54; //7.46
    int x7 = 65*3; //195
    float x8 = 3.14*2.71; //8.5094
    float x9 = 9.8*4; //39.2
    int x10 = 32>>1; //16
    float x11 = (float)35/2; //17.5
    float x12 = 16.8/4; //4.2
    float x13 = 20/2.5; //8
    int x14 = 12%4;//0
    int x15 = 15%4;//3
    int x16 = 27%3;//0
    float x17 = 21.4-(int)(21.4/4)*4;//1.4

    printf("x1 = %d\n",x1);
    printf("x2 = %d\n",x2);
    printf("x3 = %.*f\n", 2, x3);
    printf("x4 = %d\n",x4);
    printf("x5 = %d\n",x5);
    printf("x6 = %.*f\n", 2, x6);
    printf("x7 = %d\n",x7);
    printf("x8 = %.*f\n", 4, x8);
    printf("x9 = %.*f\n", 1, x9);
    printf("x10 = %d\n",x10);
    printf("x11 = %.*f\n", 1, x11);
    printf("x12 = %.*f\n", 1, x12);
    printf("x13 = %.*f\n", 0, x13);
    printf("x14 = %d\n",x14);
    printf("x15 = %d\n",x15);
    printf("x16 = %d\n",x16);
    printf("x17 = %.*f\n", 1, x17);

    return 0;
}
