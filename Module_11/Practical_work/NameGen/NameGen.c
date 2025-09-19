#include "NameGen.h"
#include <stdlib.h>
#include <time.h>
#include <stddef.h>

static int _inited = 0;
static int idx(size_t n){ return n ? (int)(rand() % n) : 0; }
void set_namegen_seed(unsigned int seed){ srand(seed); _inited = 1; }
void init_namegen(void){ if(!_inited){ srand((unsigned)time(NULL)); _inited = 1; } }

const char *nameM(void){
    static const char * const names[] = {
        "Alexander","Sergey","Daniil","Zakhar","Ilya","Timofey","Nikita","Mark","Platon","Miron",
        "Artyom","Egor","Fedor","Adam","Marcel","Andrey","Nikolay","Peter","Mikhail","Ivan",
        "Dmitry","Maxim","Stepan","Matvey","Konstantin","Vadim","Timur","Anton","Arseny","Rodion",
        "Danila","Daniel","Kirill","Lev","Gleb","Vyacheslav","Ruslan","Elisha","Emil","Danil",
        "Pavel","Miroslav","Georgy","David","Grigory","Victor","Yaroslav","Evgeniy","Leonid","Aleksey",
        "Vsevolod","Vladimir","Makar","Vladislav","Stanislav","Demid","Roman","Leon","Gordey","Savva",
        "Jan","Philip","Tigran","Ali","Arthur","Bogdan","Yuri","Demyan","Igor","Oleg",
        "German","Robert","Damir","Vitaly","Emin","Denis","Semyon","Yakov","Emir","Svyatoslav",
        "Boris","Valery","Adrian","Vasily","Artemy","Luka","Ibrahim","Savely","Tikhon","Marat",
        "Anatoly","Kamil","Danis","Arkady","Seraphim","Nazar","Daniyar","Bilal","Arsen",
        "Afanasy","Akim","Albert","Anzor","Arkhip","Artur","Azamat","Damyan","Eduard","Eldar",
        "Elmar","Erik","Ernest","Filipp","Ilarion","Ilyas","Innokenty","Iosif","Islam","Ismail",
        "Kazbek","Klim","Kondrat","Kornei","Kuzma","Lavrenty","Leonty","Markel","Matvei","Mikail",
        "Milan","Mstislav","Nail","Narek","Nestor","Omar","Orest","Prokhor","Rafael","Ramil",
        "Rasul","Renat","Rinat","Rostislav","Ruben","Rudolf","Said","Samir","Sanzhar","Saveliy",
        "Sevastian","Shamil","Taras","Temur","Umar","Valentin","Veniamin","Vilen","Vitaliy","Vlad",
        "Vladilen","Vladlen","Yermolai","Yegor","Yuriy","Zaur","Zinoviy","Arman","Ashot",
        "Timofei","Fyodor","Sasha","Misha","Dima","Kolya","Petya","Vanya","Seryozha","Slava",
        "Roma","Zhora","Vitya","Lesha","Lyova","Tema","Zhenya","Sanya","Gera","Filya"
    };
    return names[idx(sizeof(names)/sizeof(*names))];
}

const char *patronymicM(void){
    static const char * const patronymics[] = {
        "Adamovich","Adrianovich","Afanasevich","Akimovich","Albertovich","Aleksandrovich","Alexeevich",
        "Alekseyevich","Anatolyevich","Andreevich","Antonovich","Arkadyevich","Arsenevich","Artemovich",
        "Artemyevich","Arturovich","Bogdanovich","Borisovich","Damirovich","Daniilovich","Danilovich",
        "Daniyarovich","Davidovich","Denisovich","Dmitrievich","Eduardovich","Egorovich","Eldarovich",
        "Emilovich","Emirovich","Evgenyevich","Fedorovich","Filippovich","Gennadyevich","Germanovich",
        "Grigoryevich","Ibrahimovich","Ignatyevich","Igorevich","Ilyich","Iosifovich","Ivanovich",
        "Izzatovich","Kirillovich","Konstantinovich","Kuzmich","Lavrentyevich","Leonidovich","Leontyevich",
        "Levovich","Lukich","Maksimovich","Makarovich","Maratovich","Markovich","Matveyevich","Mikhailovich",
        "Mironovich","Nazarovich","Nikitich","Nikolayevich","Olegovich","Petrovich","Pavlovich","Prokhorovich",
        "Renatovich","Robertovich","Rodionovich","Romanovich","Rostislavovich","Rubenovich","Rudolfovich",
        "Rustamovich","Ruslanovich","Saidovich","Savelievich","Savelyevich","Semenovich","Sergeyevich",
        "Stepanovich","Stanislavovich","Svyatoslavovich","Tarasovich","Timofeyevich","Timurovich","Tikhonovich",
        "Valentinovich","Valeryevich","Vasilyevich","Veniaminovich","Viktorovich","Vitalyevich","Vladimirovich",
        "Vladislavovich","Vsevolodovich","Vyacheslavovich","Yakovlevich","Yaroslavovich","Yuryevich","Zakharovich",
        "Gerasimovich","Eremeyevich","Efimovich","Yefremovich","Kharitonovich","Sidorovich","Spiridonovich",
        "Nikiforovich","Potapovich","Panfilovich","Pankratovich","Platonovich","Savvich","Sevastyanovich",
        "Fedoseevich","Fominich","Filaretovich","Florovich"
    };
    return patronymics[idx(sizeof(patronymics)/sizeof(*patronymics))];
}

static const char * const surnames_m[] = {
    "Smirnov","Ivanov","Kuznetsov","Sokolov","Popov","Lebedev","Kozlov","Novikov","Morozov","Petrov",
    "Volkov","Solovyov","Vasilev","Zaitsev","Pavlov","Semenov","Golubev","Vinogradov","Bogdanov","Vorobyov",
    "Fedorov","Mikhailov","Belyaev","Tarasov","Belov","Komarov","Orlov","Kiselev","Yakovlev","Grigoryev",
    "Stepanov","Yerin","Gavrilov","Antonov","Igorev","Rybakov","Polyakov","Sorokin","Karpov","Vlasov",
    "Kuzin","Ilyin","Gusev","Titov","Bykov","Kudryavtsev","Baranov","Filippov","Komissarov","Kulikov",
    "Maslov","Ermakov","Maksimov","Nikolaev","Khristoforov","Danilov","Arkhipov","Petukhov","Bobylev","Kostin",
    "Sidorov","Andreev","Gordeev","Efimov","Veselov","Tretyakov","Guryev","Orekhov","Zuev","Koshelev",
    "Lapin","Bobrov","Suvorov","Seleznev","Sergeev","Efremov","Lytkin","Blokhin","Shiryaev","Avdeev",
    "Kharitonov","Kazakov","Zykov","Potapov","Melnikov","Shevelev","Galkin","Nazarov","Korolev","Zolotarev",
    "Malinin","Ilyin","Muravyov","Pastukhov","Ponomarev","Korchagin","Dorokhov","Karasev","Kochetkov","Pugachev",
    "Chumakov","Kozlov","Sviridov","Bazhenov","Korshunov","Smetanov","Cherkasov","Prokofiev","Shirokov","Kolesnikov",
    "Kovalev","Fomichev","Mitrofanov","Kononov","Uvarov","Sukhanov","Leonov","Drozdov","Nosov","Denisov",
    "Klyuyev","Panin","Yermolaev","Bogomolov","Anokhin","Anisimov","Sizov","Terentyev","Samsonov","Yeremeyev",
    "Kochetov","Tumanov","Yermolov","Ponomaryov","Rumyantsev","Solovyov","Abrosimov","Ageev","Averin","Afanasyev",
    "Afonin","Balashov","Baranovsky","Barkov","Bezrukov","Borodin","Borzov","Bychkov","Vasin","Veshnyakov",
    "Vyazemsky","Gromov","Goncharov","Grachyov","Grishin","Dyakov","Dolgikh","Dolgopolov","Druzhinin","Dudarev",
    "Dubov","Egorov","Eliseev","Yelizarov","Zabolotsky","Zimin","Zubkov","Ignatiev","Ilinsky","Isayev",
    "Kamenev","Kapustin","Kartashov","Kirillin","Klimov","Kondrashov","Korneev","Kostomarov","Kotov","Krasnov",
    "Kruglov","Kvashnin","Larin","Lavrov","Lazutin","Loginov","Lomakin","Lunev","Lyapin","Malakhov",
    "Medvedev","Merzlyakov","Minaev","Naumov","Nechaev","Nekrasov","Noskov","Obukhov","Ovechkin","Okunev",
    "Osipov","Pankratov","Parfenov","Pakhomov","Pereverzev","Platonov","Plotnikov","Plyushkin","Polevoy","Polishchuk",
    "Prikhodko","Reshetnikov","Rozanov","Rozhkov","Ryazanov","Saveliev","Shcherbakov","Shchedrin","Shaposhnikov","Shevchuk",
    "Shulgin","Shubin","Shutov","Skvortsov","Sobolev","Starikov","Stolyarov","Surkov","Suslov","Sychev",
    "Tikhonov","Tolstoy","Trofimov","Tryapitsyn","Tsvetayev","Ustinov","Fateev","Fedoseev","Fyodorov","Kharitonov",
    "Tsarev","Cherepanov","Chistyakov","Shalamov","Shalyapin","Yakovlev","Yashin","Yevtushenko","Zverev","Zuev",
    "Zakurdaev","Arsenyev","Astrakhantsev","Bakharev","Baldin","Barbashin","Basov","Belikov","Bespalov","Bogatyrev",
    "Bogatyr","Bolshakov","Bondar","Bondarev","Borovik","Bryukhanov","Bulgakov","Burov","Buryakov","Chaykovsky",
    "Chibisov","Chirkin","Chugunov","Davydov","Dementyev","Deryugin","Devkin","Drozd","Drobyshev","Durnev",
    "Efremenkov","Ezhov","Fadeev","Fadin","Falkov","Filatyev","Finogenov","Gagarin","Galkovsky","Garin",
    "Gerasimenko","Glinka","Golikov","Gonchar","Gorbachev","Gordienko","Gorelov","Gorenkov","Gorshkov","Grabar",
    "Grinev","Gromyko","Gubin","Guryev","Guseynov","Gutorov","Zadorin","Zadorozhny","Zagorsky","Zakharchenko",
    "Zamyatin","Zarubin","Zatsepin","Zhurin","Zhurkin","Zyablov","Zyuzin","Ilyashenko","Inozemtsev","Ismagilov",
    "Ismatov","Ivakhnenko","Ivanyuk","Ivaschenko","Kadnikov","Kadyrov","Kalashnikov","Kalinichev","Kalinin","Kalmikov",
    "Kaltygin","Kamyshin","Kanunnikov","Kaplin","Karabanov","Karavaev","Karpovich","Kasatkin","Kashtanov","Kaverin",
    "Kharin","Khomenko","Khromov","Khrustalev","Kibalchich","Kiselevsky","Kitaev","Kiyanov","Kleimenov","Klimenko",
    "Knyazev","Kochetkov","Kolesov","Komaritsyn","Kondratiev","Konev","Kopylov","Korablyov","Korbut","Koretsky",
    "Kornev","Korsakov","Kostinov","Kotovsky","Kozhemyakin","Krapivin","Krasilnikov","Krivosheev","Kroshkin","Krylov",
    "Kudrin","Kukushkin","Kulik","Kuligin","Kurakin","Kurochkin","Kustov","Kuznetsky","Kuzovlev","Kuzubov","Kuzura",
    "Kvyatkovsky","Lagunov","Laptev","Lavrentiev","Leontiev","Leskov","Likhachev","Litvinov","Lobanov","Lobachev",
    "Lomtev","Losev","Lukashev","Lukyanov","Lyakhov","Lyubimov","Lyutsenko","Magomedov","Maltsev","Mamontov",
    "Marchenko","Marinin","Markov","Martynenko","Matrosov","Matushkin","Mayorov","Merinov","Meshcheriakov","Mezentsev",
    "Mishin","Mogilevsky","Mokhov","Molchanov","Moroz","Morgunov","Mukhin","Myasnikov","Nadtochiy","Nazarov",
    "Nechiporenko","Nesterov","Nikonov","Nikitin","Obozov","Odintsov","Okhotin","Onishchenko","Orlovsky","Panarin",
    "Panfilov","Pankov","Parshin","Pavlenko","Pavlovsky","Pegov","Perevalov","Pershin","Pestov","Pilipenko","Plakhov",
    "Pluzhnikov","Podgorny","Podolsky","Pokrovsky","Poluektov","Popkov","Postnikov","Potekhin","Pozdnyakov","Pronin",
    "Prozorov","Pryakhin","Ptitsyn","Pyankov","Pyataev","Radevich","Rakhmanin","Raspopov","Rasskazov","Reshetov",
    "Rogachev","Rokossovsky","Romanenko","Roshchin","Rozhnev","Rozum","Ruban","Rudnev","Rudykh","Rusanov","Sabitov",
    "Sadovnikov","Sakharov","Sapegin","Sapunov","Savinov","Savitsky","Sazhin","Saushkin","Sedov","Seleznyov","Selivanov",
    "Seliverstov","Semakin","Semenyuk","Sementsov","Senin","Serdyukov","Severin","Sevryukov","Shadrin","Shalygin",
    "Shapovalov","Sharapov","Sharygin","Shatunov","Shein","Shelyakin","Shemyakin","Shendrikov","Sheremetyev","Shikhov",
    "Shirobokov","Shlykov","Shmelev","Shubinov","Shulyakov","Sidorovich","Silaev","Sirotkin","Sitnikov","Skobeltsyn",
    "Skornyakov","Skryabin","Slastenin","Slobodchikov","Smagin","Smetanin","Snegirev","Snytko","Sokol","Solodov",
    "Sorokinov","Sotnikov","Spirin","Sretensky","Starodubtsev","Starostin","Starkov","Stasov","Steshin","Strelnikov",
    "Streltsov","Subbotin","Sugrobov","Sulimov","Surin","Suslovsky","Susloparov","Sverdlov","Syomin","Sysoyev",
    "Tabolin","Tadeev","Taranov","Tarkhanov","Tchernov","Terekhov","Tereshchenko","Terpigorev","Tertyshny",
    "Tikhomirov","Timakov","Timashov","Timofeev","Timoshenko","Tokarev","Tolkunov","Toporkov","Toropov","Totmyanin",
    "Tregubov","Trifonov","Trubnikov","Tryapkin","Tsvetkov","Tvorogov","Tyurin","Ulanov","Ulyanov","Ushakov","Ustin",
    "Uvarovsky","Uzhakov","Vagin","Vakulov","Valov","Vankov","Varlamov","Vasilchikov","Vdovin","Velikanov","Verbov",
    "Veselov","Vinyarsky","Vizgin","Vlasenko","Vodopyanov","Voitovich","Voloshin","Volynets","Voronov","Vysotsky",
    "Yakovets","Yamshchikov","Yanovsky","Yefimov","Yemelyanov","Yermakov","Yershov","Yudin","Yunakov","Yurchenko",
    "Yushkov","Zabelin","Zadorov","Zaikin","Zakharchuk","Zamyshlyaev","Zaripov","Zaslavsky","Zatulin","Zavyalov",
    "Zhelobovsky","Zheltov","Zhernakov","Zhestkov","Zhilin","Zhuravlyov"
};

static const char * const surnames_f[] = {
    "Smirnova","Ivanova","Kuznetsova","Sokolova","Popova","Lebedeva","Kozlova","Novikova","Morozova","Petrova",
    "Volkova","Solovyova","Vasileva","Zaitseva","Pavlova","Semenova","Golubeva","Vinogradova","Bogdanova","Vorobyova",
    "Fedorova","Mikhailova","Belyaeva","Tarasova","Belova","Komarova","Orlova","Kiseleva","Yakovleva","Grigoryeva",
    "Stepanova","Yerina","Gavrilova","Antonova","Igoreva","Rybakova","Polyakova","Sorokina","Karpova","Vlasova",
    "Kuzina","Ilyina","Guseva","Titova","Bykova","Kudryavtseva","Baranova","Filippova","Komissarova","Kulikova",
    "Maslova","Ermakova","Maksimova","Nikolaeva","Khristoforova","Danilova","Arkhipova","Petukhova","Bobyleva","Kostina",
    "Sidorova","Andreeva","Gordeeva","Efimova","Veselova","Tretyakova","Guryeva","Orekhova","Zueva","Kosheleva",
    "Lapina","Bobrova","Suvorova","Selezneva","Sergeeva","Efremova","Lytkina","Blokhina","Shiryaeva","Avdeeva",
    "Kharitonova","Kazakova","Zykova","Potapova","Melnikova","Sheveleva","Galkina","Nazarova","Koroleva","Zolotareva",
    "Malinina","Ilyina","Muravyova","Pastukhova","Ponomareva","Korchagina","Dorokhova","Karaseva","Kochetkova","Pugacheva",
    "Chumakova","Kozlova","Sviridova","Bazhenova","Korshunova","Smetanova","Cherkasova","Prokofieva","Shirokova","Kolesnikova",
    "Kovaleva","Fomicheva","Mitrofanova","Kononova","Uvarova","Sukhanova","Leonova","Drozdova","Nosova","Denisova",
    "Klyuyeva","Panina","Yermolaeva","Bogomolova","Anokhina","Anisimova","Sizova","Terentyeva","Samsonova","Yeremeyeva",
    "Kochetova","Tumanova","Yermolova","Ponomaryova","Rumyantseva","Solovyova","Abrosimova","Ageeva","Averina","Afanasyeva",
    "Afonina","Balashova","Baranovskaya","Barkova","Bezrukova","Borodina","Borzova","Bychkova","Vasina","Veshnyakova",
    "Vyazemskaya","Gromova","Goncharova","Grachyova","Grishina","Dyakova","Dolgikh","Dolgopolova","Druzhinina","Dudareva",
    "Dubova","Egorova","Elisee﻿va","Yelizarova","Zabolotskaya","Zimina","Zubkova","Ignatieva","Ilinskaya","Isayeva",
    "Kameneva","Kapustina","Kartashova","Kirillina","Klimova","Kondrashova","Korneeva","Kostomarova","Kotova","Krasnova",
    "Kruglova","Kvashnina","Larina","Lavrova","Lazutina","Loginova","Lomakina","Luneva","Lyapina","Malakhova",
    "Medvedeva","Merzlyakova","Minayeva","Naumova","Nechayeva","Nekrasova","Noskova","Obukhova","Ovechkina","Okuneva",
    "Osipova","Pankratova","Parfenova","Pakhomova","Pereverzeva","Platonova","Plotnikova","Plyushkina","Polevaya","Polishchuk",
    "Prikhodko","Reshetnikova","Rozanova","Rozhkova","Ryazanova","Savelieva","Shcherbakova","Shchedrina","Shaposhnikova","Shevchuk",
    "Shulgina","Shubina","Shutova","Skvortsova","Soboleva","Starikova","Stolyarova","Surkova","Suslova","Sychyova",
    "Tikhonova","Tolstaya","Trofimova","Tryapitsyna","Tsvetayeva","Ustinova","Fateeva","Fedoseeva","Fyodorova","Kharitonova",
    "Tsaryova","Cherepanova","Chistyakova","Shalamova","Shalyapina","Yakovleva","Yashina","Yevtushenko","Zvereva","Zueva",
    "Zakurdaeva","Arsenyeva","Astrakhantseva","Bakhareva","Baldina","Barbashina","Basova","Belikova","Bespalova","Bogatyreva",
    "Bogatyr","Bolshakova","Bondar","Bondareva","Borovik","Bryukhanova","Bulgakova","Burova","Buryakova","Chaykovskaya",
    "Chibisova","Chirkina","Chugunova","Davydova","Dementyeva","Deryugina","Devkina","Drozd","Drobysheva","Durneva",
    "Efremenkova","Yezhova","Faddeeva","Fadina","Falkova","Filatyeva","Finogenova","Gagarina","Galkovskaya","Garina",
    "Gerasimenko","Glinka","Golikova","Gonchar","Gorbacheva","Gordienko","Gorelova","Gorenkova","Gorshkova","Grabaryova",
    "Grineva","Gromyko","Gubina","Guryeva","Guseynova","Gutorova","Zadorina","Zadorozhnaya","Zagorskaya","Zakharchenko",
    "Zamyatina","Zarubina","Zatse﻿pina","Zhurina","Zhurkina","Zyablova","Zyuzina","Ilyashenko","Inozemtseva","Ismagilova",
    "Ismatova","Ivakhnenko","Ivanyuk","Ivashchenko","Kadnikova","Kadyrova","Kalashnikova","Kalinicheva","Kalinina","Kalmikova",
    "Kaltygina","Kamyshina","Kanunnikova","Kaplina","Karabanova","Karavaeva","Karpovich","Kasatkina","Kashtanova","Kaverina",
    "Kharina","Khomenko","Khromova","Khrustaleva","Kibalchich","Kiselevskaya","Kitaeva","Kiyanova","Kleimenova","Klimenko",
    "Knyazeva","Kochetkova","Kolesova","Komaritsyna","Kondratieva","Koneva","Kopylova","Korablyova","Korbut","Koretskaya",
    "Korneva","Korsakova","Kostinova","Kotovskaya","Kozhemyakina","Krapivina","Krasilnikova","Krivosheeva","Kroshkina","Krylova",
    "Kudrina","Kukushkina","Kulik","Kuligina","Kurakina","Kurochkina","Kustova","Kuznetskaya","Kuzovleva","Kuzubova","Kuzura",
    "Kvyatkovskaya","Lagunova","Lapteva","Lavrentieva","Leontieva","Leskova","Likhacheva","Litvinova","Lobanova","Lobacheva",
    "Lomteva","Loseva","Lukasheva","Lukyanova","Lyakhova","Lyubimova","Lyutsenko","Magomedova","Maltseva","Mamontova",
    "Marchenko","Marinina","Markova","Martynenko","Matrosova","Matushkina","Mayorova","Merinova","Meshcheriakova","Mezentseva",
    "Mishina","Mogilevskaya","Mokhova","Molchanova","Moroza","Morgunova","Mukhina","Myasnikova","Nadtochi﻿y","Nazarova",
    "Nechiporenko","Nesterova","Nikonova","Nikitina","Obozova","Odintsova","Okhotina","Onishchenko","Orlovskaya","Panarina",
    "Panfilova","Pankova","Parshina","Pavlenko","Pavlovskaya","Pegova","Perevalova","Pershina","Pestova","Pilipenko","Plakhova",
    "Pluzhnikova","Podgornaya","Podolskaya","Pokrovskaya","Poluektova","Popkova","Postnikova","Potekhina","Pozdnyakova","Pronina",
    "Prozorova","Pryakhina","Ptitsyna","Pyankova","Pyataeva","Radevich","Rakhmanina","Raspopova","Rasskazova","Reshetova",
    "Rogacheva","Rokossovskaya","Romanenko","Roshchina","Rozhneva","Rozum","Ruban","Rudneva","Rudykh","Rusanova","Sabitova",
    "Sadovnikova","Sakharova","Sapegina","Sapunova","Savinova","Savitskaya","Sazhina","Saushkina","Sedova","Seleznyova","Selivanova",
    "Seliverstova","Semakina","Semenyuk","Sementsova","Senina","Serdyukova","Severina","Sevryukova","Shadrina","Shalygina",
    "Shapovalova","Sharapova","Sharygina","Shatunova","Sheina","Shelyakina","Shemyakina","Shendrikova","Sheremeteva","Shikhova",
    "Shirobokova","Shlykova","Shmeleva","Shubinova","Shulyakova","Sidorovich","Silaeva","Sirotkina","Sitnikova","Skobeltsyna",
    "Skornyakova","Skryabina","Slastenina","Slobodchikova","Smagina","Smetanina","Snegireva","Snytko","Sokol","Solodova",
    "Sorokinova","Sotnikova","Spirina","Sretenskaya","Starodubtseva","Starostina","Starkova","Stasova","Steshina","Strelnikova",
    "Streltsova","Subbotina","Sugrobova","Sulimova","Surina","Suslovskaya","Susloparova","Sverdlova","Syomina","Sysoyeva",
    "Tabolina","Tadeeva","Taranova","Tarkhanova","Tchernova","Terekhova","Tereshchenko","Terpigoreva","Tertyshnaya",
    "Tikhomirova","Timakova","Timashova","Timofeeva","Timoshenko","Tokareva","Tolkunova","Toporkova","Toropova","Totmyanina",
    "Tregubova","Trifonova","Trubnikova","Tryapkina","Tsvetkova","Tvorogova","Tyurina","Ulanova","Ulyanova","Ushakova","Ustina",
    "Uvarovskaya","Uzhakova","Vagina","Vakulova","Valova","Vankova","Varlamova","Vasilchikova","Vdovina","Velikanova","Verbova",
    "Veselova","Vinyarskaya","Vizgina","Vlasenko","Vodopyanova","Voitovich","Voloshina","Volynets","Voronova","Vysotskaya",
    "Yakovets","Yamshchikova","Yanovskaya","Yefimova","Yemelyanova","Yermakova","Yershova","Yudina","Yunakova","Yurchenko",
    "Yushkova","Zabelina","Zadorova","Zaikina","Zakharchuk","Zamyshlyaeva","Zaripova","Zaslavskaya","Zatulina","Zavyalova",
    "Zhelobovskaya","Zheltova","Zhernakova","Zhestkova","Zhilina","Zhuravlyova"
};

const char *surnameM(void){ return surnames_m[idx(sizeof(surnames_m)/sizeof(*surnames_m))]; }
const char *surnameF(void){ return surnames_f[idx(sizeof(surnames_f)/sizeof(*surnames_f))]; }

const char *nameF(void){
    static const char * const names[] = {
        "Darya","Ulyana","Anastasia","Sofia","Arina","Valeria","Alisa","Zoya","Zlata","Victoria",
        "Kira","Nicole","Ksenia","Veronica","Yana","Stefania","Amina","Olga","Evgenia","Mia",
        "Diana","Karina","Tatyana","Milana","Mila","Vera","Safiya","Vasilisa","Agata","Lydia",
        "Monica","Alexandra","Maria","Elina","Anna","Elizaveta","Varvara","Polina","Antonina",
        "Ekaterina","Marina","Margarita","Serafima","Maya","Svetlana","Christina","Alina","Irina",
        "Emilia","Maryam","Eva","Aisha","Alena","Camilla","Marianna","Nadezhda","Taisiya",
        "Yesenia","Adele","Yasmina","Miroslava","Vladislava","Amelia","Alicia","Darina","Angelina",
        "Julia","Regina","Asia","Nika","Ariana","Elena","Lyubov","Adelina","Aliya","Lea","Malika",
        "Carolina","Sabrina","Melania","Adela","Valentina","Pelageya","Madina","Lilia","Teona",
        "Evdokia","Agnia","Mira","Tamara","Yaroslava","Nina","Anfisa","Maryana","Aida","Kamila","Fatima"
    };
    return names[idx(sizeof(names)/sizeof(*names))];
}

const char *patronymicF(void){
    static const char * const patronymics[] = {
        "Adamovna","Adrianovna","Afanasevna","Akimovna","Albertovna","Aleksandrovna","Alexeevna",
        "Alekseyevna","Anatolyevna","Andreevna","Antonovna","Arkadyevna","Arsenevna","Artemovna",
        "Artemyevna","Arturovna","Bogdanovna","Borisovna","Damirovna","Daniilovna","Danilovna",
        "Daniyarovna","Davidovna","Denisovna","Dmitrievna","Eduardovna","Egorovna","Eldarovna",
        "Emilovna","Emirovna","Evgenyevna","Fedorovna","Filippovna","Gennadyevna","Germanovna",
        "Grigoryevna","Ibrahimovna","Ignatyevna","Igorevna","Ilinichna","Iosifovna","Ivanovna",
        "Izzatovna","Kirillovna","Konstantinovna","Kuzminichna","Lavrentyevna","Leonidovna","Leontyevna",
        "Levovna","Lukichna","Maksimovna","Makarovna","Maratovna","Markovna","Matveyevna","Mikhailovna",
        "Mironovna","Nazarovna","Nikitichna","Nikolayevna","Olegovna","Petrovna","Pavlovna","Prokhorovna",
        "Renatovna","Robertovna","Rodionovna","Romanovna","Rostislavovna","Rubenovna","Rudolfovna",
        "Rustamovna","Ruslanovna","Saidovna","Savelievna","Semenovna","Sergeyevna","Stepanovna",
        "Stanislavovna","Svyatoslavovna","Tarasovna","Timofeyevna","Timurovna","Tikhonovna",
        "Valentinovna","Valeryevna","Vasilyevna","Veniaminovna","Viktorovna","Vitalyevna","Vladimirovna",
        "Vladislavovna","Vsevolodovna","Vyacheslavovna","Yakovlevna","Yaroslavovna","Yuryevna","Zakharovna",
        "Gerasimovna","Eremevna","Efimovna","Yefremovna","Kharitonovna","Sidorovna","Spiridonovna",
        "Nikiforovna","Potapovna","Panfilovna","Pankratovna","Platonovna","Savvichna","Sevastyanovna",
        "Fedoseevna","Fominichna","Filaretovna","Florovna"
    };
    return patronymics[idx(sizeof(patronymics)/sizeof(*patronymics))];
}
