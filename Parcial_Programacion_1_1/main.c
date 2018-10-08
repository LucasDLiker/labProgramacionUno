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
    char auxNombreDirector[51];
    char auxPaisDirector[51];
    int auxIdDirector;
    int auxFechaDirector;
    int auxId;
    int auxAno;
    int menuOption;
    int opcion;
    int freeSlot;
    int freeSlotDirector;
    int validar=0;
    int validarDirector=0;


    sPeliculas arrayPeliculas[MAX];
    initPelicula(arrayPeliculas, MAX);
    sDirectores arrayDirectores[MAXB];
    initDirector(arrayDirectores, MAXB);


    if(validar==0)
    {
    addPelicula(arrayPeliculas, MAX, auxId, "Lucas", "Liker", "Argentina", 2010);
    addPelicula(arrayPeliculas, MAX, auxId, "Pepito", "Pepin", "Venezuela", 1995);
    validar++;
      }
    while(menuOption != 7)
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
            freeSlotDirector=buscarLibreDirector(arrayDirectores, MAXB);
            validarDirector++;
            if(freeSlotDirector != ILOGIC)
            {
                getValidString("\n Ingrese el nombre del director: ", "\nError. Solo se permiten letras, vuelva a ingresar el nombre: \n", auxNombreDirector);
                getValidString("\n ingrese su pais de origen: ", "\nError, Solo se permiten letras, vuelva a ingresar el apellido: \n", auxPaisDirector);
                auxFechaDirector=getValidInt("\n Ingrese el año de nacimiento (1900 - 2018): ", "\nError, el dato es invalido\n", 1900, 2018);
            }
            else
            {
                 printf("\n No hay mas espacio para ingresar datos.- \n");
                 system("pause");
                 system("cls");
            }
            addDirector(arrayDirectores, MAXB, auxIdDirector, auxNombreDirector, auxPaisDirector, auxFechaDirector);
            break;
            case 5:
            if(validarDirector > 0)
            {
                bajaDirector(arrayDirectores, MAXB, auxIdDirector);
            }
            else{
                printf("No hay datos para eliminar");
            }
            break;
            case 6:
            if(validar > 0 || validarDirector > 0)
            {
                opcion= subMenu();
                switch(opcion)
                {
                case 1:
                 mostrarPelicula(arrayPeliculas, MAX);
                 system("pause");
                 system("cls");
                 break;
                case 2:
                mostrarDirector(arrayDirectores, MAXB);
                system("pause");
                system("cls");
                break;
                }

            }
            else
            {
                printf("No hay datos para mostrar");
                system("pause");
                system("cls");
            }
            break;
            case 7:
            printf("auf wiedersehen/Hasta Pronto...");
            break;
            default:
            printf("\n Error. Ingrese una opcion valida del 1 al 4 y 5 para salir. \n");
        }



    }

    return 0;
}
