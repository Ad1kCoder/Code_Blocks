#include <stdio.h>
#include <stdlib.h>
#include "NameGen.h"



int main()
{
    srand(0);
    for(int i=1;i<=24;i++){
        if (rand()%2) printf("%d\t%s %s %s\n", i,surnameM(), nameM(), patronymicM());
        else printf("%d\t%s %s %s\n", i,surnameF(), nameF(), patronymicF());
    }
    return 0;
}


