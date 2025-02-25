#include <stdio.h>
#include <stdlib.h>
#include "NameGen.h"



int main()
{
    srand(1);
    for(int i=0;i<5;i++)
        printf("%s\n", nameM());
    return 0;
}


