#include <stdio.h>
#include <stdlib.h>
#include "NameGen.h"



int main()
{
    srand(256);
    for(int i=1;i<=5;i++)
        printf("%d %s\t %s\n", i, nameM(),patronymicM());
    return 0;
}


