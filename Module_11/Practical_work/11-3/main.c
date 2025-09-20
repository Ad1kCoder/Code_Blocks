#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "NameGen.h"
#define RND(min, max) rand()%((max)-(min))+(min)

#define WIHTOUT_GENDER_BIAS 0   // Вывод данных для всей компании
#define GENDER_BIAS   1   //  Вывод данных с делением по полу

#define MODE GENDER_BIAS

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
void averAge(Employee *stf);
void medAge (Employee *stf);
int compAge (const void *a, const void *b);
void averAgeGend(Employee *stf);
void medAgeGend(Employee *stf);

int main(){
    printf("Enter seed for random generation: ");
    scanf("%u", &seed);
    set_namegen_seed(seed);
    Employee staff[NUM_EMPLS];
    fillStaff (staff);
    printStaff (staff);
#if MODE == WIHTOUT_GENDER_BIAS
    averAge (staff);
    medAge (staff);
#elif MODE == GENDER_BIAS
    averAgeGend (staff);
    medAgeGend(staff);
#endif // MODE
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
        stf[i].age = RND (48-2*i,58-2*i);
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
    puts("");
}

void averAge (Employee *stf){
    int sum = 0;
    for (int i=0; i < NUM_EMPLS; i++) sum += stf[i].age;
    printf("The average age in the company is %.2f years old\n", (float)sum/NUM_EMPLS);
}

void medAge (Employee *stf){
    qsort(stf,NUM_EMPLS, sizeof(*stf), compAge);
    printf("The median age in the company is %d years old\n", stf[NUM_EMPLS/2].age);
}

int compAge (const void *a, const void *b){
        const Employee *employeeA = (const Employee*)a;
        const Employee *employeeB = (const Employee*)b;
        return ((employeeB ->age) - (employeeA ->age));
}


void averAgeGend(Employee *stf){
    int sumM=0, sumF=0, nM=0, nF=0;
    for (int i=0; i < NUM_EMPLS; i++){
        if (stf[i].gender == MALE){
            sumM+=stf[i].age;
            nM++;
        }else {
        sumF+=stf[i].age;
        nF++;
        }
    }
    printf("The average age of men in the company is %.2f years old\n", (float)sumM/nM);
    printf("The average age of woman in the company is %.2f years old\n", (float)sumF/nF);
}
void medAgeGend(Employee *stf){
    int nM=0, nF=0;
    int* arrM[NUM_EMPLS];
    int* arrF[NUM_EMPLS];
    qsort(stf,NUM_EMPLS, sizeof(*stf), compAge);
    for (int i=0; i < NUM_EMPLS; i++){
        if (stf[i].gender == MALE){
            arrM[nM]= &stf[i].age;
            nM++;
        }else {
        arrF[nF]= &stf[i].age;
        nF++;
        }
    }
    if (nM%2==0){
        float sr = ((float)*arrM[nM/2]+(float)*arrM[nM/2-1])/2;
        printf("The median age of men in the company is %.2f years old\n", sr );
    } else printf("The median age of men in the company is %d years old\n", *arrM[nM/2] );
    if (nF%2==0){
        float sr = ((float)*arrF[nF/2]+(float)*arrF[nF/2-1])/2;
        printf("The median age of women in the company is %.2f years old\n", sr );
    } else printf("The median age of women in the company is %d years old\n", *arrF[nF/2] );
}
