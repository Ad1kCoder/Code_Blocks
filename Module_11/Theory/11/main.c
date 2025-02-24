#include <stdio.h>
#include <stdlib.h>


struct sqr_t{

    int a;
    int b;
    int s;
};

typedef struct{

    int a;
    int b;
    float h;
    int s;
    float v;

}volume_t;

void volume(volume_t * vl){

    vl->s = vl->a * vl->b;
    vl->v = (float)(vl->s)*vl->h;
}

void sqr (struct sqr_t * sq){

    sq->s = sq->a * sq->b;
}

void printVolume (volume_t * v){

    printf("Square %d\n", v->s);
    printf("Volume %f\n",v->v);

}



int main()
{
    volume_t vol;
    vol.a = 2;
    vol.b = 5;
    vol.h = 3.14;
    volume(&vol);
    printVolume(&vol);

    return 0;
}
