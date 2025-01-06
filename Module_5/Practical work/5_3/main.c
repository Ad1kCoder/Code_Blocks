#include <stdio.h>
#include <stdlib.h>

int main()
{
    float n1 = 72.45;
    float k1 = 84.32;
    int a1 = (int)(n1+k1); //156

    float n2 = 44.32;
    float k2 = 51.54;
    float a2 = n2+k2; //95.86

    int n3 = 53;
    float k3 = 2.54;
    float a3 = (int)n3+k3; //55.54

    int n4 = 12;
    int k4 = 22;
    float a4 = (float)(n4+k4); //34.00

    float n5 = 64.2154;
    int a5 = (int)n5; //64

    int n6 = 42;
    float a6 = (float)n6; //42.00

    printf("a1 = %d\n",a1);
    printf("a2 = %.*f\n", 2, a2);
    printf("a3 = %.*f\n", 2, a3);
    printf("a4 = %.*f\n", 2, a4);
    printf("a5 = %d\n",a5);
    printf("a6 = %.*f\n", 2, a6);

    return 0;
}
