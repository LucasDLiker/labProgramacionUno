#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <string.h>

#ifndef arrayActores
typedef struct
{
    int idActor;
    char nombre[20];
    char apellido[20];
    char nacionalidad[20];
    int isEmpty;

}sActor;
#endif

int initActor(sActor* arrayActores, int capacidad);
int buscarLibreActor(sActor* arrayActores, int capacidad);
int buscarActorPorID(sActor* arrayActores, int capacidad, int id);
int addActor(sActor* arrayActores, int capacidad, int auxIDActor, char nombreActor[], char apellidoActor[],  char nacionalidadActor[]);
int mostrarActor(sActor* arrayActores, int cantidad);
void actoresPorNacionalidad(sActor arrayActores[], int len);
