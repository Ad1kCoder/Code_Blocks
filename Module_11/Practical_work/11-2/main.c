#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define RND(min, max) rand()%((max)-(min))+(min)


#define PRINT_ALL        0   // печать всего списка (отладка)
#define SEARCH_BY_WORD   1   // выполнять задание: поиск по ключевому слову


#ifndef MODE
#define MODE SEARCH_BY_WORD
#endif


#define ISBN_P 1 //1 - выводить ISBN при печати, 0 - не выводить

#define LIB_SIZE 10




typedef struct {
    char author[3][50];
    char title[50];
    char ISBN[50];
    int year;
} Book;

Book library[LIB_SIZE];
void printBook(Book *lib, int index);
void wordToLover(char *s);


int main(){

#if MODE == SEARCH_BY_WORD
    char keyword[50];
    int notFound = 1;
    printf("Enter a keyword to search: ");
    scanf("%s", &keyword);
    wordToLover(keyword);
    for (int i = 0; i < LIB_SIZE; ++i){
        char tcopy[50];
        strcpy(tcopy, library[i].title);
        wordToLover(tcopy);
        if (strstr(tcopy, keyword) != NULL) {
        printBook(library, i);
        notFound = 0;
        }
    }
    if (notFound) printf ("\nKeyword not found\n");
#elif MODE == PRINT_ALL
    for(int i = 0;i < LIB_SIZE; ++i) printBook(library, i);
#endif
    return 0;
}

void wordToLover(char *s){
    for(int i = 0; s[i]; ++i) s[i]=tolower(s[i]);
}

void printBook(Book *lib, int index){
    printf ("Authors: ");
    for(int i=0; i<3; ++i){
        if(lib[index].author[i]!='\0') printf ("%s\t", lib[index].author[i]);
    }
    printf("\n");
    printf ("Title: %s\n", lib[index].title);
#if ISBN_P == 1
    printf ("ISBN: %s\n", lib[index].ISBN);
#endif // ISBN
    printf ("Year: %d\n\n", lib[index].year);

}




Book library[LIB_SIZE] = {
    { { "George Orwell", "", "" },
      "Nineteen Eighty-Four",
      "978-0-452-28423-4",
      1949 },

    { { "Aldous Huxley", "", "" },
      "Brave New World",
      "978-0-06-085052-4",
      1932 },

    { { "J. K. Rowling", "", "" },
      "Harry Potter and the Philosopher's Stone",
      "978-0-7475-3269-9",
      1997 },

    { { "Arthur Conan Doyle", "", "" },
      "The Adventure of the Speckled Band",
      "978-1-85326-033-2",
      1892 },

    { { "H. G. Wells", "", "" },
      "The Lost World",
      "978-0-14-043372-1",
      1912 },

    { { "Cory Doctorow", "Charles Stross", "" },
      "The Lost Stars",
      "978-1-234-56789-7",
      2010 },

    { { "Carlos Ruiz Zafon", "", "" },
      "The Shadow of the Wind",
      "978-0-375-50703-3",
      2001 },

    { { "Neil Gaiman", "Terry Pratchett", "Michael Reaves" },
      "Night Watch",
      "978-0-06-123456-7",
      2002 },

    { { "Isaac Asimov", "", "" },
      "Nightfall",
      "978-0-394-52340-0",
      1941 },

    { { "Ann Cleeves", "Peter May", "" },
      "In the Shadow of the Mountain",
      "978-1-86197-876-5",
      2015 }
};
