#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int a = 16;
    const float u = 230.2;
    for (int i = 0;i < 200; i++){
       float b = u*sin(0.3*i);
        printf("%f\n", b);

    }




    return 0;
}
