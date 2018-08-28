#include <stdio.h>
#include <stdlib.h>

/*
1- declarar la función.-
2- llamada a la función.-
3- desarrollo de la funcion.-

// (queDevuelve; comoSeLlama; queRecibe) pensamiento para la funcion.


*/
void sumar1 ();
//prototipo de funcion que recibe pero no devuelve.
void sumar2 (int, int);
//no recibe pero devuelve:
int sumar3 (void);
//retorna y recibe
int sumar4 (int, int);

int main()
{
    /*int suma;
    suma=sumar3 ();
    printf("La suma es: %d", suma);*/


    //sumar1();
    //sumar2 (numeroUno, numeroDos);

    int numeroUno;
    int numeroDos;
    int suma;

    printf("Ingrese el primer numero: ");
    scanf("%d", &numeroUno);
    fflush(stdin);
    printf("Ingrese el segundo numero: ");
    scanf("%d", &numeroDos);


    suma=sumar4 (numeroUno, numeroDos);
    printf("%d", suma);

    return 0;
}

int sumar4 (int numeroUno, int numeroDos)
{

    int suma;
    suma = numeroUno+numeroDos;
        return suma;
}
/*void sumar2 (int n1, int n2)

{
    int suma=n1+n2;

    printf("%d", suma);
}*/

/*int sumar3 (void)
{
    int numeroUno;
    int numeroDos;
    int suma;

    printf("Ingrese el primer numero: ");
    scanf("%d", &numeroUno);
    fflush(stdin);
    printf("Ingrese el segundo numero: ");
    scanf("%d", &numeroDos);

    suma= numeroDos+numeroUno;
    return suma;

}*/











/*void sumar1 (void)
{

    //int suma;



    suma=numeroUno+numeroDos;

    printf("%d", suma);


}*/
