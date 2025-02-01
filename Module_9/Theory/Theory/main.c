#include <stdio.h>
#include <stdlib.h>


typedef struct{

    char *str;
}myType_t;


void myPrint(myType_t *s){

    printf("%s\n", s->str);
}







int main()
{

    myType_t myStruct;
    myStruct.str = "Good Struct";


    myPrint(&myStruct);

    return 0;
}
