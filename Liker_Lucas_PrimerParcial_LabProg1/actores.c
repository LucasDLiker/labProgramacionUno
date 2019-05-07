#include "actores.h"



/** Generador de ID **/

static int nuevoIDActor()
    {
    static int idActor=0;

    idActor ++;

    return idActor;
    }

/** inicializar actor **/

int initActor(sActor* arrayActores, int capacidad)
    {
    int ret = -1;
    int i;
    if(arrayActores != NULL && capacidad!= 0)
    {
        ret = 0;
        for(i=0; i<capacidad; i++)
        {
            arrayActores[i].isEmpty = 1;
        }
    }
    return ret;
    }

int buscarLibreActor(sActor* arrayActores, int capacidad)
{
    int ret = -1;
    int i;
    if(capacidad > 0 && arrayActores != NULL)
    {
        for(i=0; i<capacidad; i++)
        {
            if(arrayActores[i].isEmpty == 1)
            {
                ret = i;
                break;
            }
        }
    }
    return ret;
    }
int buscarActorPorID(sActor* arrayActores, int capacidad, int id)
    {
    int i;
    for(i=0; i<capacidad; i++)
    {
        if(arrayActores[i].idActor == id && arrayActores[i].isEmpty == 0)
        {
            return i;
            break;
        }
    }
    return -1;
    }
int addActor(sActor* arrayActores, int capacidad, int auxIDActor, char nombreActor[], char apellidoActor[],  char nacionalidadActor[])
{
    int idActor=1000;
    int ret = -1;
    int index = buscarLibreActor(arrayActores,capacidad);
    int j = buscarPeliculaPorID(arrayActores, 1000, index);


    if(capacidad > 0 && arrayActores != NULL)
    {
        if(index != -1)
        {
            if(arrayActores[j].isEmpty==0)
            {
                idActor = nuevoIDActor();
            }
            arrayActores[index].idActor = nuevoIDActor();
            strcpy(arrayActores[index].nombre, nombreActor);
            strcpy(arrayActores[index].apellido, apellidoActor);
            strcpy(arrayActores[index].nacionalidad, nacionalidadActor);
            arrayActores[index].isEmpty = 0;

            ret = 0;

            system("cls");
        }
    }
    return ret;
    }

    /**mostrar actor **/

    int mostrarActor(sActor* arrayActores, int cantidad)
{
    int ret = -1;
    int i;
    printf("\n%3s %11s %15s \n", "NOMBRE", "ACTOR", "NACIONALIDAD");
    for(i = 0; i < cantidad; i++)
    {
        if(arrayActores[i].isEmpty == 0)
        {
            printf(" %3s %11s %15s \n",arrayActores[i].nombre, arrayActores[i].apellido, arrayActores[i].nacionalidad);
        }
    }
    ret = 0;
    return ret;
}


void actoresPorNacionalidad(sActor arrayActores[], int len)
{
    sActor auxActor;
    int i,j;

    for(i=1; i<len; i++)
    {
        auxActor = arrayActores[i];
        j=i-1;

        while(strcmp(arrayActores[j].nacionalidad, auxActor.nacionalidad)>0 && j>=0)
        {
            arrayActores[j+1] = arrayActores[j];
            j--;
        }
        arrayActores[j+1]=auxActor;
    }
    mostrarActor(arrayActores, len);
}
