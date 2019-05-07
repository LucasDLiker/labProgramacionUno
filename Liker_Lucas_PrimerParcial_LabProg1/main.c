#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <string.h>
#include "arrayPeliculas.h"
#include "funciones.h"
#include "actores.h"


int main()
{
    sPeliculas arrayPeliculas [MAX];
    initPelicula(arrayPeliculas, MAX);
    sActor arrayActores [MAX];
    initActor(arrayActores, MAX);

    int opcion;
    int espacioLibre;

    int auxID;
    int auxIDActor;
    int auxFecha;
    char auxNombrePelicula[20];
    char auxNombreActor[20];
    char auxNacionalidadActor [20];

    int flag=0;

    /** hardcodeo **/

    if (flag == 0)
    {
    addPelicula(arrayPeliculas, MAX, auxID, "Avengers", "RobertDowneJR",  2019, "EEUU");
    addPelicula(arrayPeliculas, MAX, auxID, "Venom", "Hardy",  2018, "EEUU");
    addPelicula(arrayPeliculas, MAX, auxID, "SherlockHolmes", "robertoyunior",  2008, "Inglaterra");
    addPelicula(arrayPeliculas, MAX, auxID, "MenInBlack3", "WillSmith",  2011, "EEUU");
    addPelicula(arrayPeliculas, MAX, auxID, "TheHangover", "WillSmith",  2009, "EEUU");
    addPelicula(arrayPeliculas, MAX, auxID, "ElSecretoDeSusOjos", "Darin",  2013, "ARG");
    addPelicula(arrayPeliculas, MAX, auxID, "Titanic", "DiCaprio",  1995, "Inglaterra");
    addPelicula(arrayPeliculas, MAX, auxID, "Narcos", "Escobar",  1990, "Colombia");

    addActor(arrayActores, MAX,auxIDActor, "Robert", "DowneyJR", "EEUU" );
    addActor(arrayActores, MAX,auxIDActor, "Samuel", "LJackson", "EEUU" );
    addActor(arrayActores, MAX,auxIDActor, "Ricardo", "Darin", "ARG" );
    addActor(arrayActores, MAX,auxIDActor, "Will", "Smith", "Inglaterra" );
    addActor(arrayActores, MAX,auxIDActor, "Pablo", "Escobar", "Colombia" );
    addActor(arrayActores, MAX,auxIDActor, "Thor", "Bjornsonn", "Dinamarca" );




    flag = flag+8;
    }

    do
    {
        opcion=menuOptions();
        switch(opcion)
        {
    case 1:
    espacioLibre=buscarLibre(arrayPeliculas, MAX);
    if (espacioLibre != ILOGIC)
    {
        getValidString("\n Ingrese nombre de la pelicula: ", "\nError. Solo se permiten letras, vuelva a ingresar el nombre: \n", auxNombrePelicula);
        getValidString("\n Ingrese el nombre del Actor: ", "\nError, Solo se permiten letras, vuelva a ingresar el nombre: \n", auxNombreActor);
        auxFecha=getValidInt("\n Ingrese la fecha de estreno: ", "\nError, el dato es invalido\n", 0, 2019);
        getValidString("\n Ingrese la nacionalidad del actor: ", "\nError, Solo se permiten letras, vuelva a ingresar: \n", auxNacionalidadActor);
        printf("Pelicula añadida con exito.");
    }
    else
            {
                 printf("\n No hay mas espacio para ingresar datos.- \n");
                 system("pause");
                 system("cls");
            }
    addPelicula(arrayPeliculas, MAX, auxID, auxNombrePelicula, auxNombreActor, auxFecha, auxNacionalidadActor);
    flag++;

    break;
    case 2:
        if (flag>0)
        {
            mostrarPelicula(arrayPeliculas, MAX);
            modificarPelicula(arrayPeliculas, MAX);
        }
        else
        {
            printf("No existen datos para modificar.-");
        }
    break;
    case 3:
         if(flag > 0)
            {
                mostrarPelicula(arrayPeliculas, MAX);
                bajaPelicula(arrayPeliculas, MAX, auxID);
                flag--;
            }
            else{
                printf("No hay datos para eliminar");
            }
    break;
    case 4:
if (flag > 0)
        {
           mostrarPelicula(arrayPeliculas, MAX);
                 system("pause");
                 system("cls");
        }
        else
        {
            printf("No se han cargado datos.");
        }
    break;
    case 5:
    break;
    case 6:
        mostrarActor(arrayActores, MAX);
    break;
    case 7:
    peliculasPorFecha(arrayPeliculas, MAX);
    break;
    case 8:
    actoresPorNacionalidad(arrayActores, MAX);
    break;
    case 9:
    printf("Te quiero German aprobame <3");
    break;
        }//Fin del switch
    }while(opcion != 9);


    return 0;
}
