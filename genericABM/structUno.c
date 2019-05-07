#include "structUno.h"
#include "toolbox.h"

int menuOptions()
    {
        int menuOption;
        fflush(stdin);

        printf("\n  1- Dar de alta Algo \n");
        printf("\n  2- Modificar Algo \n");
        printf("\n  3- Dar de Baja Algo \n");
        printf("\n  4- Listar \n");
        printf("\n  9- Salir \n");

        fflush(stdin);
        scanf("%d", &menuOption);
        return menuOption;
}

/** BUSCAR LIBRE **/

int buscarLibre(eStructOne lista[], int tam)
{
    int i;
    int index=-1;
    for(i=0; i<tam; i++)
    {
        if(lista[i].estado==LIBRE)
        {
            index = i;
            break;
        }
    }
    return index;
}

/** INICIALIZAR ALGO **/

void initSomething(eStructOne lista[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        lista[i].estado = LIBRE;
    }
}

/** GENERADOR DE ID **/

/*static int nuevoID()
{
    static int newID = 0;
    newID++;
    return newID;
}*/

/** CARGAR ALGO **/

void loadSomething (eStructOne lista[], int tam)
{
    int i;

    i = buscarLibre(lista, tam);
    if(i!=-1)
    {
        printf("Ingrese datoInt: ");
        scanf("%d", &lista[i].datoint);
        printf("Ingrese datoString: ");
        fflush(stdin);
        gets(lista[i].datoString);
        printf("Ingrese datoChar: ");
        fflush(stdin);
        scanf("%c", &lista[i].datoChar);
        fflush(stdin);
        printf("Ingrese dato Float: ");
        scanf("%f", &lista[i].datoFloat);

        //lista[i].sueldoNeto =lista[i].sueldoBruto*0.85;

        lista[i].estado = OCUPADO;
    }
    else
    {
        printf("No hay espacio");
    }//Fin de If y Else
}


/** Mostrar Algo **/

void mostrarAlgo(eStructOne unAlgo)
{
    printf("%d-%s-%c-%f\n", unAlgo.datoint, unAlgo.datoString, unAlgo.datoChar, unAlgo.datoFloat);
}
/**Mostrar algo en lista **/

void mostrarListaAlgo(eStructOne lista[], int tam)
{

    int i;
    for(i=0; i<tam; i++)
    {
        if(lista[i].estado == OCUPADO);
        {
            mostrarAlgo(lista[i]);
        }
    }
}

