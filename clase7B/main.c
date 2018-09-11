#include <stdio.h>
#include <stdlib.h>
#define T 2

/*
*Marca
*Precio
*Vencimiento
*dimensiones
*tipo
*codigo

Vectores Paralelos

son vectores que se corresponden entre si en donde cada elemento de un vector tiene relacion
 A B C
 en donde el elemento 0 del vector A corresponde al elemento 0 de B y C
 por ejemplo el legajo de alumno el nombre y la nota si estan en la posicion 0 corresponden a esa misma persona

 trabajar con los 3 datos: Legajo, Alumno y Nota

*/
int main()
{

    int legajos[T];
    char nombres[T][21];
    int notas[T];
    float alturas[T];
    int i;

    for(i=0 ;i<T;i++)
    {
        printf("Ingrese legajo: ");
        scanf("%d", &legajos[i]);
        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(nombres[i]);
        printf("Ingrese nota: ");
        scanf("%d", &notas);
        printf("Ingrese altura: ");
        scanf("%f", &alturas);

    }

    printf("%4d","  "legajo",   "nombre",   "nota",   "altura");

    for (i=0; i<T; i++)
    {
        printf("%4d %20s %2d %5f \n", legajos[i], nombres[i] , notas[i] , alturas[i]);
    }




    return 0;
}



 /*int i;
    int j;
    int temp;
    for (i=1 ; i<len ; i++)
    {
        temp = data [i];
        j=i-1;
        while (j>=0 && tem<data[j]) //temp<data
        {
            data [j+1] = data [j];
            j--;
        }
         data [j+1]=temp;*/


         /*int vector[5]={3, 5, 1, 2};
         int i;
         inser*/
