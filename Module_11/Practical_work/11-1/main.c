#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define RND(min, max) rand()%((max)-(min))+(min)


#define CHOICE 0

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
char rndSubject[50];

Gender randomGender(void);
int compSurname (const void *x, const void *y);
float averageMark (Student *gr, int size);
char *subject(void);
int compMark (const void *a, const void *b);
int whoIsSmart(Student *gr, int size);







int main()
{
    printf("Enter seed for random generation: ");
    scanf("%u", &seed);
    srand(seed);
    int sizeGroup = RND(15,37);
    int rndGradeLevel = RND (5,12);
    strcpy(rndSubject, subject());
    Student group[sizeGroup];
    fillGroup (group, sizeGroup);
    qsort(group,sizeGroup, sizeof(*group), compSurname); // Сортировка по алфавиту
    printGroup(group, sizeGroup, rndSubject, rndGradeLevel);
    printf("\nAverage mark of group: %f\n", averageMark (group, sizeGroup));
    qsort(group,sizeGroup, sizeof(*group), compMark);   // Сортировка по успеваемости
    printGroup(group, sizeGroup, rndSubject, rndGradeLevel);
    whoIsSmart(group, sizeGroup);

    return 0;
}

Gender randomGender(void) {
    return RND(0, 2) == 0 ? MALE : FEMALE;
}

int printGroup (Student *gr, int size, char *sbj, int gradeLevel){
    printf ("\nSubject: %s\t Grade: %dA\n\n", sbj, gradeLevel);
    printf("%-15s %-15s %-13s %-8s %-5s\n", "Surname", "Name", "Patronymic", "Gender", "Mark");
    printf("-------------------------------------------------------------\n");
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
            strcpy(gr[i].surname, surnameM());
            strcpy(gr[i].name, nameM());
            strcpy(gr[i].patronymic, patronymicM());
            gr[i].gender = MALE;
        } else {
            strcpy(gr[i].surname, surnameF());
            strcpy(gr[i].name, nameF());
            strcpy(gr[i].patronymic, patronymicF());
            gr[i].gender = FEMALE;
        }
        gr[i].mark = RND (3,11);
    }
}

int compSurname (const void *x, const void *y){
    const Student *studentX = (const Student*)x;
    const Student *studentY = (const Student*)y;
    return strcmp(studentX ->surname, studentY ->surname);
}

float averageMark (Student *gr, int size){
    int sum=0;
    for (int i=0; i < size; i++){
        sum+=gr[i].mark;
    }
    return ((float)sum/size);
}

char *subject(void){
    char *subjects[] ={"Russian Language","Literature","Foreign Language","Mathematics","History","Social Studies",\
    "Geography","Biology","Physical Education","Art","Music","Technology", "Life Safety" };

    return subjects[RND(0,sizeof(subjects)/sizeof(subjects[0]))];
}


int compMark (const void *a, const void *b){
        const Student *studentA = (const Student*)a;
        const Student *studentB = (const Student*)b;
        return ((studentB ->mark) - (studentA ->mark));
}

int whoIsSmart(Student *gr, int size){
    int markM=0, markF=0, nM=0, nF=0;
    for (int i=0; i < size; i++){
        if (gr[i].gender == MALE){
            markM+=gr[i].mark;
            nM++;
        }else {
        markF+=gr[i].mark;
        nF++;
        }
    }
    if (((float)markM/nM)>((float)markF/nF)) printf("\nGuys are %f times smarter than girls\n",(((float)markM/nM)/((float)markF/nF)));
    else printf("\nGirls are %f times smarter than guys \n",(((float)markF/nF)/((float)markM/nM)));
}




