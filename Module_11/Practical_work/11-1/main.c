#include <stdio.h>
#include <stdlib.h>
#define RND(min, max) rand()%((max)-(min))+(min)

unsigned int seed;

typedef enum {MALE, FEMALE} Gender;

typedef struct {
    char name[50];
    char patronymic[50];
    char surname[50];
    Gender gender;
    int gradeLevel; //Класс обучения
    char subject [50];
    int mark; // Оценка за урок, по 10-балльной системе (Белорусский стандарт)
} Student;

Gender randomGender(void);







int main()
{
    printf("Enter seed for random generation: ");
    scanf("%u", &seed);
    srand(seed);
    int sizeGroup = RND(15,37);
    int rndGradeLevel = RND (5,11);
    Student group[sizeGroup];

    for (int i=0; i < sizeGroup; i++){
        if (randomGender() == MALE){
            strcpy(group[i].name, nameM());
            strcpy(group[i].patronymic, patronymicM());
            strcpy(group[i].surname, surnameM());
            group[i].gender = MALE;
        } else {
            strcpy(group[i].name, nameF());
            strcpy(group[i].patronymic, patronymicF());
            strcpy(group[i].surname, surnameF());
            group[i].gender = FEMALE;
        }
        group[i].mark = RND (3,10);
    }

    for (int i=0; i < sizeGroup; i++){
        printf("%s\t\t\t", group[i].surname);
        printf("%s\t\t\t", group[i].name);
        printf("%s\t\t\t", group[i].patronymic);
        if (group[i].gender == MALE) printf("M\t");
        else printf("F\t");
        printf("%d\n", group[i].mark);
    }
    /*char lol[50];
    strcpy(lol, nameM());
    printf("%s\n", lol);*/
    return 0;
}

Gender randomGender(void) {
    return RND(0, 2) == 0 ? MALE : FEMALE;
}
