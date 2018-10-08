#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <string.h>
#include "arrayPeliculas.h"
#include "arrayDirectores.h"
#include "funciones.h"
#define ILOGIC -1
#define EMPTY 0
#define FULL 1
#define INACTIVE 0
#define MAX 1000

int main()
{
    char auxNombre[51];
    char auxDirector[51];
    char auxNacionalidad[51];
    int auxId;
    int auxAno;
    int menuOption;
    int freeSlot;
    int validar=0;


    sPeliculas arrayPeliculas[MAX];
    initPelicula(arrayPeliculas, MAX);


    while(menuOption != 5)
    {
        menuOption = menuOptions();
        switch(menuOption)
        {
            case 1:
            freeSlot=buscarLibre(arrayPeliculas, MAX);
            validar++;
            if(freeSlot != ILOGIC)
            {
                getValidString("\n Ingrese nombre de la pelicula: ", "\nError. Solo se permiten letras, vuelva a ingresar el nombre: \n", auxNombre);
                getValidString("\n Ingrese el nombre del director: ", "\nError, Solo se permiten letras, vuelva a ingresar el apellido: \n", auxDirector);
                getValidString("\n Ingrese la nacionalidad: ", "\nError, Solo se permiten letras, vuelva a ingresar el apellido: \n", auxNacionalidad);
                auxAno=getValidInt("\n Ingrese el anio: ", "\nError, el dato es invalido\n", 0, 2018);
            }
            else
            {
                 printf("\n No hay mas espacio para ingresar datos.- \n");
                 system("pause");
                 system("cls");
            }
            addPelicula(arrayPeliculas, MAX, auxId, auxNombre, auxDirector, auxNacionalidad, auxAno);
            break;
            case 2:
            if (validar > 0)
            {
                modificarPelicula(arrayPeliculas, MAX);
                break;
            }
            else
            {
                printf("No hay datos para modificar");
            }
            break;
            case 3:
            if(validar > 0)
            {
                bajaPelicula(arrayPeliculas, MAX, auxId);
            }
            else{
                printf("No hay datos para eliminar");
            }
            break;
            case 4:
            if(validar > 0)
            {
                mostrarPelicula(arrayPeliculas, MAX);
                system("pause");
                system("cls");
            }
            else
            {
                printf("No hay datos para mostrar");
            }
            break;
            case 5:
            printf("auf wiedersehen/Hasta Pronto...");
            break;
            default:
            printf("\n Error. Ingrese una opcion valida del 1 al 4 y 5 para salir. \n");
        }



    }

    return 0;
}
