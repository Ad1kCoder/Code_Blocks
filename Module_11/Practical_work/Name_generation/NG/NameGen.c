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

    return names[RND(0,sizeof(names)/sizeof(*names))];
}


char *patronymicM(void){
    char *patronymics[] ={"Markovich", "Stepanovich", "Artemovich", "Ivanovich", "Maksimovich", "Konstantinovich", "Rodionovich",\
     "Demidovich", "Denisovich", "Mikhailovich", "Glebovich", "Davidovich", "Matveevich", "Maksimovich", "Artemovich", "Maksimovich",\
      "Saveliych", "Mikhailovich","Artemovich", "Dmitrievich", "Ivanovich", "Timofeevich", "Mikhailovich", "Ilyich", "Yakovlevich",\
       "Artemovich", "Andreevich", "Davidovich","Maksimovich", "Romanovich", "Lvovich", "Andreevich", "Leonovich", "Artemyevich",\
        "Fedorovich", "Mikhailovich", "Olegovich", "Georgievich","Dmitrievich", "Markovich", "Sergeevich", "Zakharovich", "Denisovich",\
         "Makarovich", "Savelievich", "Grigorievich", "Ivanovich", "Tikhonovich","Romanovich", "Zakharovich", "Borisovich",\
          "Mikhailovich", "Egorovich", "Egorovich", "Zakharovich"};

    return patronymics[RND(0,sizeof(patronymics)/sizeof(*patronymics))];
}


char *surnameM(void){
    char *surnames[] ={"Gromov", "Mikheev", "Tsvetkov", "Alekseev", "Bragin", "Evdokimov", "Burov", "Rogov",\
     "Makarov", "Lazarev","Filatov", "Shestakov", "Vasiliev", "Zhuravlev", "Gushchin", "Zhukov", "Gusev", "Molchanov",\
      "Ustinov", "Mishin", "Sysoev", "Savin", "Ignatov",  "Artemyev", "Biryukov", "Shilov","Morozovsky","Ustinovsky", "Mishinsky", "Sysoevsky",\
       "Ryabov", "Mamontov", "Fedotov", "Panov", "Dyachkov", "Strelkov", "Morozov","Fedotovsky", "Panovsky", "Dyachkovsky", "Strelkovsky",\
        "Bogdanov", "Stepanko", "Danilov", "Arkhipov", "Belyaev", "Petukhov", "Bobylev", "Komissarov","Kostin", "Sidorov",\
         "Ermakov", "Andreev", "Zaitsev", "Fedorov", "Sorokin", "Afanasyev", "Kryukov", "Frolov", "Panfilovsky","Ermakovsky", "Andreevsky", "Zaitsevsky",\
         "Ivanov", "Strepenov", "Gordeev", "Efimov", "Veselov", "Tretyakov", "Guryev", "Orekhov", "Zuev", "Koshelev", "Lapin",\
          "Bobrov", "Suvorov","Rybakov", "Seleznev", "Sergeev", "Efremov", "Lytkin", "Filippov", "Blokhin", "Vazarev", "Shiryaev",\
           "Nikolaev", "Avdeev", "Maksimov", "Kharitonov","Corokin", "Kazakov", "Zykov", "Potapov", "Sokolov", "Melnikov",\
            "Shevelev", "Vorobyov", "Rugovoy", "Ermolaev", "Bogomolov", "Anodeev", "Anisimov", "Sizov", "Kudryavtsev", "Terentyev", "Minikheev",\
             "Samsonov", "Erdokimov", "Kochetov", "Tumanov", "Ermolov", "Masilienev", "Fonomarev", "Rumyantsev", "Soloviev", "Prokofiev",\
              "Shirokov", "Kolesnikov", "Kovalev", "Fomichev", "Mitrofanov", "Kononov", "Uvarov", "Sukhanov", "Leonov", "Novikov", "Drozdov",\
               "Nosov", "Denisov", "Kulikov", "Ponomarenko", "Svetko", "Tsvetko", "Kozlevich", "Osipov", "Ionov", "Emimov", "Volkov", "Shcheglov",\
                "Borisov", "Zakharov", "Klimov", "Chernov", "Lapshin", "Lebedev", "Klyuev", "Panin", "Gavrilov", "Korchagin", "Dorokhov",\
                 "Mikhailko", "Karasev", "Kochetkov", "Pugachev", "Chumakov", "Kozlov", "Selageev", "Sviridov", "Bazhenov", "Korshunov", "Smetanov",\
                  "Cherkasov", "Golubev", "Tarasov", "Eremov", "Morozko", "Pedorov", "Kuznetsov", "Twoetyakov", "Titov", "Galkin", "Nazarov",\
                   "Korolev", "Zolotarev", "Slevanov", "Malinin", "Ioanov", "Avreev", "Stepanov", "Kasyanov", "Dilatovsky", "Ilyin", "Mikhailov",\
                    "Muravyov", "Pastukhov", "Orlov", "Ponomarev", "Vasilevsky"};

    return surnames[RND(0,sizeof(surnames)/sizeof(*surnames))];
}

char *nameF (void){

    char *names[] ={};

    return names[RND(0,sizeof(names)/sizeof(*names))];
}


char *patronymicF(void){
    char *patronymics[] ={};

    return patronymics[RND(0,sizeof(patronymics)/sizeof(*patronymics))];
}


char *surnameF(void){
    char *surnames[] ={};

    return surnames[RND(0,sizeof(surnames)/sizeof(*surnames))];
}
