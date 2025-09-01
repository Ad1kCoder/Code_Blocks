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
    int rndGradeLevel = RND (5,12);
    Student group[sizeGroup];
    fillGroup (group, sizeGroup);
    printGroup(group, sizeGroup);
    return 0;
}

Gender randomGender(void) {
    return RND(0, 2) == 0 ? MALE : FEMALE;
}

int printGroup (Student *gr, int size){
    for (int i=0; i < size; i++){
        printf("%-15.15s\t", gr[i].surname);
        printf("%-15.15s\t", gr[i].name);
        printf("%-15.15s\t", gr[i].patronymic);
        gr[i].gender == MALE ? printf("M\t"):printf("F\t");
        printf("%d\n", gr[i].mark);
    }
    return 0;
}

int fillGroup (Student *gr, int size){
    for (int i=0; i < size; i++){
        if (randomGender() == MALE){
            strcpy(gr[i].name, nameM());
            strcpy(gr[i].patronymic, patronymicM());
            strcpy(gr[i].surname, surnameM());
            gr[i].gender = MALE;
        } else {
            strcpy(gr[i].name, nameF());
            strcpy(gr[i].patronymic, patronymicF());
            strcpy(gr[i].surname, surnameF());
            gr[i].gender = FEMALE;
        }
        gr[i].mark = RND (3,11);
    }
}
