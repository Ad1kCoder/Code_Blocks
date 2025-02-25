#include <stdio.h>
#include "NameGen.h"

void printHello(int i)
{
    for (int j=0;j<i;j++){
        printf("Hello world!\n");
    }
}


char *nameM (void){

    char *names[] ={"Alexander", "Sergey", "Daniil", "Zakhar", "Ilya", "Timofey", "Nikita", "Mark",\
     "Plato", "Miron", "Artyom", "Egor", "Fedor", "Adam", "Marcel", "Andrey", "Nikolay", "Peter", "Mikhail",\
     "Ivan", "Dmitry", "Maxim", "Stepan", "Matvey", "Konstantin", "Vadim", "Timur", "Anton", "Arseny", "Rodion",\
      "Danila", "Daniel", "Kirill", "Lev", "Gleb", "Vyacheslav", "Ruslan", "Elisha", "Emil", "Danil", "Pavel", "Miroslav",\
       "Georgy", "David", "Grigory", "Victor", "Yaroslav", "Evgeniy", "Leonid", "Aleksey", "Vsevolod", "Vladimir",\
        "Makar", "Vladislav", "Stanislav", "Demid", "Roman", "Leon", "Gordey", "Savva", "Jan", "Philip", "Tigran", "Ali",\
         "Arthur", "Bogdan", "Yuri", "Demyan", "Igor", "Oleg", "German", "Robert", "Damir", "Vitaly", "Emin", "Denis", "Semyon",\
          "Yakov", "Emir", "Svyatoslav", "Boris", "Valery", "Adrian", "Vasily", "Artemy", "Luka", "Ibrahim", "Savely", "Tikhon",\
           "Marat", "Anatoly", "Kamil", "Danil", "Danis", "Arkady", "Seraphim", "Nazar", "Daniyar", "Bilal", "Arsen"};
    //int r = rand()%5;
    return names[rand()%100];
}


char *surnameM(void){
    char *surnames[] ={"Markovich", "Stepanovich", "Artemovich", "Ivanovich", "Maksimovich", "Konstantinovich", "Rodionovich",\
     "Demidovich", "Denisovich", "Mikhailovich", "Glebovich", "Davidovich", "Matveevich", "Maksimovich", "Artemovich", "Maksimovich",\
      "Saveliy", "Mikhailovich","Artemovich", "Dmitrievich", "Ivanovich", "Timofeevich", "Mikhailovich", "Ilyich", "Yakovlevich",\
       "Artemovich", "Andreevich", "Davidovich","Maksimovich", "Romanovich", "Lvovich", "Andreevich", "Leonovich", "Artemyevich",\
        "Fedorovich", "Mikhailovich", "Olegovich", "Georgievich","Dmitrievich", "Markovich", "Sergeevich", "Zakharovich", "Denisovich",\
         "Makarovich", "Savelievich", "Grigorievich", "Ivanovich", "Tikhonovich","Romanovich", "Zakharovich", "Borisovich",\
          "Mikhailovich", "Egorovich", "Egorovich", "Zakharovich"};

    return surnames[rand()%55];
}
