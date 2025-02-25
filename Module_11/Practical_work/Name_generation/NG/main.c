#include <stdio.h>
#include <stdlib.h>
#include "NameGen.h"

char *nameMale (void);


int main()
{
   /* char *names[] ={"Ilya", "Alexander", "Ivan", "Svyatoslav", "Gleb"};
    int r = rand()%5;*/
    printf("%s\n", nameMale());
    return 0;
}


char *nameMale (void){

    char *names[] ={"Ilya", "Alexander", "Ivan", "Svyatoslav", "Gleb"};
    int r = rand()%5;
    return names[r];

}
