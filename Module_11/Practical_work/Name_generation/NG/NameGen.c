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
     "Platon", "Miron", "Artyom", "Egor", "Fedor", "Adam", "Marcel", "Andrey", "Nikolay", "Peter", "Mikhail",\
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


char *patronymicM(void){
    char *patronymics[] ={"Markovich", "Stepanovich", "Artemovich", "Ivanovich", "Maksimovich", "Konstantinovich", "Rodionovich",\
     "Demidovich", "Denisovich", "Mikhailovich", "Glebovich", "Davidovich", "Matveevich", "Maksimovich", "Artemovich", "Maksimovich",\
      "Saveliych", "Mikhailovich","Artemovich", "Dmitrievich", "Ivanovich", "Timofeevich", "Mikhailovich", "Ilyich", "Yakovlevich",\
       "Artemovich", "Andreevich", "Davidovich","Maksimovich", "Romanovich", "Lvovich", "Andreevich", "Leonovich", "Artemyevich",\
        "Fedorovich", "Mikhailovich", "Olegovich", "Georgievich","Dmitrievich", "Markovich", "Sergeevich", "Zakharovich", "Denisovich",\
         "Makarovich", "Savelievich", "Grigorievich", "Ivanovich", "Tikhonovich","Romanovich", "Zakharovich", "Borisovich",\
          "Mikhailovich", "Egorovich", "Egorovich", "Zakharovich"};

    return patronymics[rand()%55];
}


char *surnameM(void){
    char *surnames[] ={"Gromov", "Kulikov", "Mikheev", "Shiryaev", "Tsvetkov", "Alekseev", "Bragin", "Evdokimov", "Burov", "Rogov", "Makarov", "Lazarev",\
     "Filatov", "Shestakov", "Vasiliev", "Zhuravlev", "Gushchin", "Zhukov", "Gusev", "Molchanov", "Terentyev", "Ustinov", "Mishin", "Sysoev", "Orlov", "Savin",\
      "Kononov", "Ignatov", "Anisimov", "Artemyev", "Zuev", "Biryukov", "Shilov", "Ryabov", "Kryukov", "Mamontov", "Borisov", "Fedotov", "Panov", "Dyachkov",\
       "Novikov", "Strelkov", "Morozov", "Koshelev", "Bogdanov", "Stepanov", "Danilov", "Zuev", "Arkhipov", "Belyaev", "Petukhov", "Bobylev", "Komissarov",\
        "Kostin", "Sidorov", "Koshelev", "Ermakov", "Andreev", "Zaitsev", "Fedorov", "Sorokin", "Afanasyev", "Kryukov", "Koshelev", "Frolov", "Panfilov",\
         "Ivanov", "Stepanov", "Gordeev", "Efimov", "Zhukov", "Veselov", "Tretyakov", "Guryev", "Orekhov", "Zuev", "Koshelev", "Lapin", "Bobrov", "Suvorov",\
          "Rybakov", "Seleznev", "Sergeev", "Efremov", "Lytkin", "Filippov", "Blokhin", "Lazarev", "Shiryaev", "Novikov", "Nikolaev", "Avdeev", "Maksimov",\
           "Kharitonov"};

    return surnames[rand()%100];
}
