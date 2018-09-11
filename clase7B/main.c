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

 *ordenar por nombre alfabeticamente.-
 *muestre los alumnos aprobados cuando la nota es mayor a 6.-
 *qe muestre los alumnos que se llaman juan
 *que muestre los alumnos cuyo nombre comienzan con P.-
 * el alumno con mas nota (sabiendo que puede ser mas de uno).-
 * el mas mediocre: legajo 100, nota 5, se llama pepe y mide 1.75.-
 *ingresar un legajo y permitir la modificacion de la nota.
 *tramspfr,ar ña carga de datps em ima carga aleatoria.-

*/

//prototipos

void cargarAlumnos (int[], char [][21], int notas [], float alturas []);
int main()
{

    int legajos[T];
    char nombres[T][21];
    int notas[T];
    float alturas[T];
    char mail [T] [50];
    int i;

    cargarAlumnos(legajos, nombres, notas, alturas, T);





    return 0;
}

void cargarAlumnos (int[], char [][21], int notas [], float alturas [])
{

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

    printf("%4d", "%20s", "%2d", "%5f",  "legajo",   "nombre",   "nota",   "altura");

    for (i=0; i<T; i++)
    {
        printf("%4d %20s %2d %5f \n", legajos[i], nombres[i] , notas[i] , alturas[i]);
    }


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
