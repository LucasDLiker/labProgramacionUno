 #include "arrayPeliculas.h"

 /** Menu principal **/
 int menuOptions()
    {
        int menuOption;
        fflush(stdin);
        //printf("\n\n***MENU***\n\n -1 Dar de Alta Pelicula: \n -2 Modificar pelicula: \n -3 Dar de Baja pelicula: \n -4 Dar de alta director \n -5 Presione (5) para salir: \n");
        printf("\n  1- Dar de alta Pelicula \n");
        printf("\n  2- Modificar Pelicula \n");
        printf("\n  3- Dar de Baja Pelicula \n");
       // printf("\n  4- Hardcodear Datos \n");
        printf("\n  4- Listar \n");
        printf("\n  7- Ordenar peliculas por fecha \n");
        printf("\n  8- Ordenar actores por nacionalidad \n");
        printf("\n  9- Salir \n");

        fflush(stdin);
        scanf("%d", &menuOption);
        return menuOption;
    }

/** Generador de ID **/

static int nuevoIdPelicula()
    {
    static int idPelicula=MAX;

    idPelicula ++;

    return idPelicula;
    }

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

/** Buscar espacio libre **/

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
/** Buscar pelicula por ID **/

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
/** Cargar Pelicula **/

int addPelicula(sPeliculas* arrayPeliculas, int capacidad, int auxIdPelicula, char auxNombrePelicula[], char auxActorPelicula[], int auxFechaPelicula, char auxNacionalidadActor[])
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
            strcpy(arrayPeliculas[index].actorPelicula, auxActorPelicula);
            arrayPeliculas[index].fechaPelicula = auxFechaPelicula;
            strcpy(arrayPeliculas[index].nacionalidadActor, auxNacionalidadActor);
            arrayPeliculas[index].isEmpty = EMPTY;

            ret = EMPTY;

            //printf("Pelicula Registrada con Exito.- \n");
            //system("pause");
            system("cls");
        }
    }
    return ret;
    }//FIN DE AÑADIR PELICULAS

     /** Mostrar Peliculas **/

    int mostrarPelicula(sPeliculas* arrayPeliculas, int cantidad)
{
    int ret = ILOGIC;
    int i;
    printf("\n%3s %10s %15s %20s %25s \n", "ID","NOMBRE","ACTOR","FECHA", "NACIONALIDAD ACTOR");
    for(i = 0; i < cantidad; i++)
    {
        if(arrayPeliculas[i].isEmpty == 0)
        {
            printf("%d %10s %13s %15d %20s\n", arrayPeliculas[i].idPelicula, arrayPeliculas[i].nombrePelicula, arrayPeliculas[i].actorPelicula, arrayPeliculas[i].fechaPelicula, arrayPeliculas[i].nacionalidadActor);
        }
    }
    ret = EMPTY;
    return ret;
}

/**MODIFICAR PELICULA **/

void modificarPelicula(sPeliculas* arrayPeliculas, int capacidad)
    {
    char auxNombrePelicula[51];
    char auxActorPelicula[51];
    char auxNacionalidadActor[51];
    int auxFechaPelicula;
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
        printf("\n Ingrese  actor: \n");
        scanf("%s", auxActorPelicula);
        printf("\n Ingrese fecha: \n");
        scanf("%d", &auxFechaPelicula);
        printf("\n Ingrese nacionalidad del actor: \n");
        scanf("%s", auxNacionalidadActor);
        printf("\n Confirmar Cambios: s/n (s si, n no)\n");
        opcion=getChar("");
        switch(opcion)
        {
        case 's':
            strcpy(arrayPeliculas[idPelicula].nombrePelicula, auxNombrePelicula);
            strcpy(arrayPeliculas[idPelicula].actorPelicula, auxActorPelicula);
            arrayPeliculas[idPelicula].fechaPelicula = auxFechaPelicula;
            strcpy(arrayPeliculas[idPelicula].nacionalidadActor, auxNacionalidadActor);
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

/** BAJA DE PELICULA **/

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
}//fin de baja

/** Ordenar peliculas por fecha **/

void peliculasPorFecha (sPeliculas* arrayPeliculas, int len)

{

    int j;
    sPeliculas aux;
    int flagNoEstaOrdenado = 1;
    system("cls");
    printf("  ***  PELICULAS ***\n\n");

    while (flagNoEstaOrdenado==1)
    {
        flagNoEstaOrdenado = 0;
        for (j = 1; j < len; j++)
        {
            if (arrayPeliculas[j].fechaPelicula > arrayPeliculas[j - 1].fechaPelicula)
            {
                aux = arrayPeliculas[j];
                arrayPeliculas[j] = arrayPeliculas[j - 1];
                arrayPeliculas[j - 1] = aux;
                flagNoEstaOrdenado = 1;
            }
        }
    }
    mostrarPelicula(arrayPeliculas, len);
}//Fin de ordenamiento de fecha

/** Ordenar por Nacionalidad **/





