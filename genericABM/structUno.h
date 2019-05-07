#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#define MAX 1000
#include "toolbox.h"
#define LIBRE 0
#define OCUPADO 1
#define ILOGICO -1

typedef struct
{

    int datoint;
    char datoString[20];
    char datoChar;
    float datoFloat;
    int estado;
    int id;


}eStructOne;


int menuOptions();
int buscarLibre (eStructOne[], int);
void initSomething(eStructOne[], int);
void loadSomething (eStructOne[], int);
void mostrarAlgo(eStructOne);
void mostrarListaAlgo(eStructOne[], int);

