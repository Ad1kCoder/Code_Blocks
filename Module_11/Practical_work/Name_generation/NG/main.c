#include <stdio.h>
#include <stdlib.h>
#include "NameGen.h"

char *nameM (void);


int main()
{
    printf("%s\n", nameM());
    return 0;
}


char *nameM (void){

    char *names[] ={"Ilya", "Alexander", "Ivan", "Svyatoslav", "Gleb"};
    int r = rand()%5;
    return names[r];

}
