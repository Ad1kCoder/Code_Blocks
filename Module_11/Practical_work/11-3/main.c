#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "NameGen.h"
#define RND(min, max) rand()%((max)-(min))+(min)

#define NUM_EMPLS 15 //Количество сотрудников


unsigned int seed;

typedef enum {MALE, FEMALE} Gender;


typedef struct {
    char name[50];
    char patronymic[50];
    char surname[50];
    int age;
    Gender gender;
    char post[50];
} Employee;

Gender randomGender(void);
void fillStaff (Employee *stf);
void printStaff (Employee *stf);

int main(){
    printf("Enter seed for random generation: ");
    scanf("%u", &seed);
    set_namegen_seed(seed);
    Employee staff[NUM_EMPLS];
    fillStaff (staff);
    printStaff (staff);

    return 0;
}


Gender randomGender(void) {
    return RND(0, 2) == 0 ? MALE : FEMALE;
}

void fillStaff (Employee *stf){
    const char* positions[] = {
    "Chief Executive Officer (CEO)",
    "Chief Operating Officer (COO)",
    "Chief Technology Officer (CTO)",
    "Chief Financial Officer (CFO)",
    "Vice President of Engineering",
    "Vice President of Operations",
    "Director of Finance",
    "Director of Human Resources",
    "Engineering Manager",
    "Sales Manager",
    "Team Lead (Software)",
    "Senior Software Engineer",
    "Data Analyst",
    "HR Specialist",
    "Office Administrator"
};
    for (int i=0; i < NUM_EMPLS; i++){
        if (randomGender() == MALE){
            strcpy(stf[i].surname, surnameM());
            strcpy(stf[i].name, nameM());
            strcpy(stf[i].patronymic, patronymicM());
            stf[i].gender = MALE;
        } else {
            strcpy(stf[i].surname, surnameF());
            strcpy(stf[i].name, nameF());
            strcpy(stf[i].patronymic, patronymicF());
            stf[i].gender = FEMALE;
        }
        strcpy(stf[i].post, positions[i]);
        stf[i].age = RND (48-2*i,68-2*i);
    }
}

void printStaff (Employee *stf){
    printf ("\nLoop & Break LLC\n\n");
    printf("%-31s %-15s %-15s %-14s %-5s %-5s\n","Positions", "Surname", "Name", "Patronymic", "Age", "Gender");
    printf("-------------------------------------------------------------------------------------------\n");
    for (int i=0; i < NUM_EMPLS; i++){
        printf("%-30.30s\t", stf[i].post);
        printf("%-15.15s\t", stf[i].surname);
        printf("%-15.15s\t", stf[i].name);
        printf("%-15.15s\t", stf[i].patronymic);
        printf("%d\t", stf[i].age);
        stf[i].gender == MALE ? printf("M\n"):printf("F\n");
    }
}

