#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <string.h>
#define ILOGIC -1
#define EMPTY 0
#define FULL 1
#define MAX 1000

#ifndef arrayPeliculas

    typedef struct
    {
        int idPelicula;
        char nombrePelicula[51];
        char actorPelicula[51];
        int isEmpty;
        int fechaPelicula;
        char nacionalidadActor[20];


    }sPeliculas;

#endif //arrayPeliculas

int menuOptions();
int initPelicula(sPeliculas* arrayPeliculas, int capacidad);
int buscarLibre(sPeliculas* arrayPeliculas, int capacidad);
int buscarPeliculaPorID(sPeliculas* arrayPeliculas, int capacidad, int id);
int addPelicula(sPeliculas* arrayPeliculas, int capacidad, int auxIdPelicula, char auxNombrePelicula[], char auxActorPelicula[], int auxFechaPelicula, char auxNacionalidadActor[]);
int mostrarPelicula(sPeliculas* arrayPeliculas, int cantidad);
void modificarPelicula(sPeliculas* arrayPeliculas, int capacidad);
int bajaPelicula(sPeliculas* arrayPeliculas, int capacidad, int id);
void peliculasPorFecha (sPeliculas* arrayPeliculas, int len);


