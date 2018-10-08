#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <string.h>
#include "arrayPeliculas.h"
#include "arrayDirectores.h"
#include "funciones.h"

    /**Inicializar Pelicula **/

    int initPelicula(sPeliculas* arrayPeliculas, int capacidad)
    {
    int ret = ILOGIC;
    int i;
    if(arrayPeliculas != NULL && capacidad!= 0)
    {
        ret = EMPTY;
        for(i=0; i<capacidad; i++)
        {
            arrayPeliculas[i].isEmpty = FULL;
        }
    }
    return ret;
    }

   /**Generar Nuevo ID**/

    static int nuevoIdPelicula()
    {
    static int idPelicula=MAX;

    idPelicula ++;

    return idPelicula;
    }

    /** Buscar Libre **/

    int buscarLibre(sPeliculas* arrayPeliculas, int capacidad)
    {
    int ret = ILOGIC;
    int i;
    if(capacidad > 0 && arrayPeliculas != NULL)
    {
        for(i=0; i<capacidad; i++)
        {
            if(arrayPeliculas[i].isEmpty == FULL)
            {
                ret = i;
                break;
            }
        }
    }
    return ret;
    }

    /** Buscar Pelicula por ID **/

    int buscarPeliculaPorID(sPeliculas* arrayPeliculas, int capacidad, int idMovie)
    {
    int i;
    for(i=0; i<capacidad; i++)
    {
        if(arrayPeliculas[i].idPelicula == idMovie && arrayPeliculas[i].isEmpty == 0)
        {
            return i;
            break;
        }
    }
    return ILOGIC;
    }

    /** Añadir Peliculas **/

    int addPelicula(sPeliculas* arrayPeliculas, int capacidad, int auxIdPelicula, char auxNombrePelicula[], char auxDirectorPelicula[], char auxNacionalidadPelicula[], int auxAnoPelicula)
    {
    int idPelicula=MAX;
    int ret = ILOGIC;
    int index = buscarLibre(arrayPeliculas,capacidad);
    int j = buscarPeliculaPorID(arrayPeliculas, MAX, index);

    if(capacidad > 0 && arrayPeliculas != NULL)
    {
        if(index != ILOGIC)
        {
            if(arrayPeliculas[j].isEmpty==0)
            {
                idPelicula = nuevoIdPelicula();
            }
            arrayPeliculas[index].idPelicula = nuevoIdPelicula();
            strcpy(arrayPeliculas[index].nombrePelicula, auxNombrePelicula);
            strcpy(arrayPeliculas[index].directorPelicula, auxDirectorPelicula);
            strcpy(arrayPeliculas[index].nacionalidadPelicula, auxNacionalidadPelicula);
            arrayPeliculas[index].anoPelicula = auxAnoPelicula;
            arrayPeliculas[index].isEmpty = EMPTY;

            ret = EMPTY;

            printf("Pelicula Registrada con Exito.- \n");
            system("pause");
            system("cls");
        }
    }
    return ret;
    }//FIN DE AÑADIR PELICULAS

    /** Modificar Peliculas **/

    void modificarPelicula(sPeliculas* arrayPeliculas, int capacidad)
    {
    char auxNombrePelicula[51];
    char auxDirectorPelicula[51];
    char auxNacionalidadPelicula[51];
    int auxAnoPelicula;
    char opcion;
    int auxId;

     printf("\n Ingrese el ID de la pelicula a dar de baja \n");
    scanf("%d", &auxId);
    int idPelicula=buscarPeliculaPorID(arrayPeliculas, MAX, auxId);
    if (idPelicula>=0)
    {
        printf("\n Se ha encontrado el ID, modifique a continuacion: \n");

        printf("\n Ingrese nombre: \n");
        scanf("%s", auxNombrePelicula);
        printf("\n Ingrese  apellido: \n");
        scanf("%s", auxDirectorPelicula);

        printf("\n Ingrese nacionalidad: \n");
        scanf("%s", auxNacionalidadPelicula);

        printf("\n Ingrese año: \n");
        scanf("%d", &auxAnoPelicula);
        printf("\n Confirmar Cambios: s/n (s si, n no)\n");
        opcion=getChar("");
        switch(opcion)
        {
        case 's':
            strcpy(arrayPeliculas[idPelicula].nombrePelicula, auxNombrePelicula);
            strcpy(arrayPeliculas[idPelicula].directorPelicula, auxDirectorPelicula);
            strcpy(arrayPeliculas[idPelicula].nacionalidadPelicula, auxNacionalidadPelicula);
            arrayPeliculas[idPelicula].anoPelicula = auxAnoPelicula;
            printf("\n La modificacion se ha realizado con exito.\n");
            system("pause");
            system("cls");
            break;
        case 'n':
            printf("\n Se ha cancelado el proceso.\n");
            system("pause");
            system("cls");
            break;
        default:
            printf("\n Error. Ingrese una opcion valida.\n");
            break;
        }
    }
    else
    {
        printf ("\n Error. ID no existente.- \n");
        system ("pause");
        system("cls");
    }
}//FIN DE MODIFICAR PELICUALS

    /** Dar de baja una pelicula **/

    int bajaPelicula(sPeliculas* arrayPeliculas, int capacidad, int id)
    {
    int ret = ILOGIC;
    int auxId;
    char opcion;

    printf("\n Ingrese el ID de la pelicula a dar de baja \n");
    scanf("%d", &auxId);
    int idPelicula=buscarPeliculaPorID(arrayPeliculas, MAX, auxId);
    if (idPelicula>=0)
    {
        printf("\n Confirmar baja de pelicula: s/n (s si, n no)\n");
        opcion=getChar("");
        switch(opcion)
        {
        case 's':
            arrayPeliculas[idPelicula].isEmpty = FULL;
            printf("\n La baja se ha realizado satisfactoriamente.\n");
            system("pause");
            system("cls");
            break;
        case 'n':
            printf("\n Se ha cancelado la funcion de baja. \n");
            system("pause");
            system("cls");
            break;
        default:
            printf("\n Error. La opcion ingresada es invalida.\n");
            break;
        }
    }
    else
    {
        printf ("\n El ID ingresado es invalido.\n");
        system ("pause");
        system("cls");
    }

    return ret;
}

    /** Mostrar Peliculas **/

    int mostrarPelicula(sPeliculas* arrayPeliculas, int cantidad)
{
    int ret = ILOGIC;
    int i;
    printf("\n%3s %11s %10s %15s %15s \n", "ID","NOMBRE","DIRECTOR","NACIONALIDAD","FECHA");
    for(i = 0; i < cantidad; i++)
    {
        if(arrayPeliculas[i].isEmpty == 0)
        {
            printf("%3d %10s %10s %15s %12d\n", arrayPeliculas[i].idPelicula, arrayPeliculas[i].nombrePelicula, arrayPeliculas[i].directorPelicula, arrayPeliculas[i].nacionalidadPelicula, arrayPeliculas[i].anoPelicula);
        }
    }
    ret = EMPTY;
    return ret;
}

    int menuOptions()
    {
        int menuOption;
        fflush(stdin);
        //printf("\n\n***MENU***\n\n -1 Dar de Alta Pelicula: \n -2 Modificar pelicula: \n -3 Dar de Baja pelicula: \n -4 Dar de alta director \n -5 Presione (5) para salir: \n");
        printf("\n  1- Dar de alta Pelicula \n");
        printf("\n  2- Modificar Pelicula \n");
        printf("\n  3- Dar de Baja Pelicula \n");
        printf("\n  4- Dar de Alta Director \n");
        printf("\n  5- Dar de Baja Director \n");
        printf("\n  6- Listar \n");
        printf("\n  7- Salir \n");

        fflush(stdin);
        scanf("%d", &menuOption);
        return menuOption;
    }

    int subMenu()
    {
    int opcion;
    fflush(stdin);
    printf("1. Mostrar lista peliculas\n"
           "2. Mostrar lista directores\n"
           "Ingrese una opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    while(opcion < 0 || opcion > 2)
    {
        printf("Por favor, ingrese una opcion valida\n");
        system("pause");
        system("cls");
        fflush(stdin);
        printf( "1. Mostrar lista peliculas\n"
                "2. Mostrar lista directores\n"
                "Ingrese una opcion: ");
        fflush(stdin);
        scanf("%d", &opcion);
    }
    return opcion;
}
