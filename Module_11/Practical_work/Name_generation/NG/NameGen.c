#include <stdio.h>
#include "NameGen.h"

void printHello(int i)
{
    for (int j=0;j<i;j++){
        printf("Hello world!\n");
    }
}


char *nameM (void){

    char *names[] ={"Philip", "Roman", "Vladislav", "Artyom", "Gleb", "Konstantin", "Egor",\
     "Ivan", "German", "Timofey", "Maxim", "Georgy", "Bogdan", "Igor", "Andrey", "Alexander", "Daniil",\
     "Oleg", "Yaroslav", "Ruslan", "Savely", "Daniel", "Nazar", "Stanislav", "Danila", "Timur", "Matvey",\
     "Mikhail", "Nikita", "Arseny", "Grigory", "Arsen", "Evgeny", "Stepan", "Mark", "Dmitry", "Victor", "David", "Makar", "Kirill"};
    //int r = rand()%5;
    return names[rand()%40];

}
