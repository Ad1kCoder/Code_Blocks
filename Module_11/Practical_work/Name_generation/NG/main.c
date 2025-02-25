#include <stdio.h>
#include <stdlib.h>
#include "NameGen.h"



int main()
{
    srand(1);
    for(int i=1;i<=5;i++)
        printf("%d %s\n", i, nameM());
    return 0;
}


