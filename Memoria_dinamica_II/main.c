#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#define T 5

typedef struct
{
    char name[21];
    int id;
    int age;

}ePerson;

ePerson* newPerson();

void showPerson(ePerson* onePerson);

int main()
{
  ePerson* lilPerson;
  lilPerson = newPerson();
  if(lilPerson!=NULL)
  {
      showPerson(lilPerson);
  }


    return 0;
}

ePerson* newPerson()
{
    ePerson* myPerson;
    myPerson = (ePerson*) malloc(sizeof (ePerson));
    if(myPerson!=NULL)
    {
        strcpy(myPerson->name, "Lucas")
        myPerson->id = 107999;
        myPerson->age = 23;
    }
    return myPerson;
}

void showPerson(ePerson* onePerson)
{
    printf("%s   %d   %d", onePerson->name, onePerson->id, onePerson->age);
}
