#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <string.h>
#include "arrayPeliculas.h"
#include "arrayDirectores.h"
#include "funciones.h"

 int initDirector(sDirectores* arrayDirectores, int capacidad)
    {
    int ret = ILOGIC;
    int i;
    if(arrayDirectores != NULL && capacidad!= 0)
    {
        ret = EMPTY;
        for(i=0; i<capacidad; i++)
        {
            arrayDirectores[i].isEmptyDirector = FULL;
        }
    }
    return ret;
    }

   /**Generar Nuevo ID**/

    static int nuevoIdDirector()
    {
    static int nuevoIdDirector=MAXB;

    nuevoIdDirector ++;

    return nuevoIdDirector;
    }

    /** buscar director**/

    int buscarLibreDirector(sDirectores* arrayDirectores, int capacidad)
    {
    int ret = ILOGIC;
    int i;
    if(capacidad > 0 && arrayDirectores != NULL)
    {
        for(i=0; i<capacidad; i++)
        {
            if(arrayDirectores[i].isEmptyDirector == FULL)
            {
                ret = i;
                break;
            }
        }
    }
    return ret;
    }

    /** buscar director por id **/

    int buscarDirectorPorID(sDirectores* arrayDirectores, int capacidad, int idDirector)
    {
    int i;
    for(i=0; i<capacidad; i++)
    {
        if(arrayDirectores[i].idDirector == idDirector && arrayDirectores[i].isEmptyDirector == 0)
        {
            return i;
            break;
        }
    }
    return ILOGIC;
    }

    /** añadir director **/

    int addDirector(sDirectores* arrayDirectores, int capacidad, int auxIdDirector, char auxNombreDirector[], char auxPaisOrigen[], int auxFechaNacimiento)
    {
    int idDirector=MAXB;
    int ret = ILOGIC;
    int indexDirector = buscarLibreDirector(arrayDirectores,capacidad);
    int j = buscarDirectorPorID(arrayDirectores, MAXB, indexDirector);

    if(capacidad > 0 && arrayDirectores != NULL)
    {
        if(indexDirector != ILOGIC)
        {
            if(arrayDirectores[j].isEmptyDirector==0)
            {
                idDirector = nuevoIdDirector();
            }
            arrayDirectores[indexDirector].idDirector = nuevoIdDirector();
            strcpy(arrayDirectores[indexDirector].nombreDirector, auxNombreDirector);
            strcpy(arrayDirectores[indexDirector].paisOrigen, auxPaisOrigen);
            arrayDirectores[indexDirector].fechaNacimiento = auxFechaNacimiento;
            arrayDirectores[indexDirector].isEmptyDirector = EMPTY;

            ret = EMPTY;

            printf("Director registrado exitosamente.- \n");
            system("pause");
            system("cls");
        }
    }
    return ret;
    }

    /** baja de director **/

    int bajaDirector(sDirectores* arrayDirectores, int capacidad, int id)
    {
    int ret = ILOGIC;
    int auxId;
    char opcion;

    printf("\n Ingrese el ID del director a dar de baja \n");
    scanf("%d", &auxId);
    int idDirector=buscarDirectorPorID(arrayDirectores, MAXB, auxId);
    if (idDirector>=0)
    {
        printf("\n Confirmar baja de director: s/n (s si, n no)\n");
        opcion=getChar("");
        switch(opcion)
        {
        case 's':
            arrayDirectores[idDirector].isEmptyDirector = FULL;
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

    /** Mostrar director **/

    int mostrarDirector(sDirectores* arrayDirectores, int cantidad)

    {
    int ret = ILOGIC;
    int i;
    printf("\n%3s %11s %10s %15s \n", "ID","NOMBRE","NACIONALIDAD","NACIMIENTO");
    for(i = 0; i < cantidad; i++)
    {
        if(arrayDirectores[i].isEmptyDirector == 0)
        {
            printf("%3d %10s %10s %12d\n", arrayDirectores[i].idDirector, arrayDirectores[i].nombreDirector, arrayDirectores[i].paisOrigen, arrayDirectores[i].fechaNacimiento);
        }
    }
    ret = EMPTY;
    return ret;
}

