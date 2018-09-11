#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    /*char cadena1[5];
    char cadena2 [100]="Hola como estas?";

    strncpy(cadena1, cadena2, 20); //strncpy funciona para poner dos cadenas y para poder poder un limite de caracteres

    puts(cadena1);
    return 0;*/

    char nombre [20];
    char apellido [20];
    char nombreCompleto [41]=""; //darle espacios suficientes para memoria de nombre y apellido.-
    char buffer [1024];
    printf("Ingrese nombre: ");
    fflush(stdin);
    gets(buffer);

    int i;

    while(strlen(buffer)>19)
    {
    printf("Error. Reingrese nombre: ");
    fflush(stdin);
    gets(buffer);

    }
    strcpy(nombre, buffer);

    printf("Ingrese apellido: ");
    fflush(stdin);
    gets(buffer);

    while(strlen(buffer)>19)
    {
    printf("Error. Reingrese apellido: ");
    fflush(stdin);
    gets(buffer);
    }
    strcpy(apellido, buffer);

    /*puts(nombre);
    puts(apellido);*/


    strcpy(nombreCompleto, apellido);
    strcat(nombreCompleto, ", ");
    strcat (nombreCompleto, nombre);
    strlwr (nombreCompleto);

    nombreCompleto[0]=toupper(nombreCompleto[0]);

    for (i=0; i<strlen(nombreCompleto) ; i++)
    {
        if (nombreCompleto[i]==' ')
        {
            nombreCompleto[i+1]=toupper(nombreCompleto[i+1]);
        }
    }

    /* for (i=0; i<strlen(nombreCompleto) ; i++)
    {
        if (nombreCompleto[i]==' ')
        {
            nombreCompleto[i+1]=toupper(nombreCompleto[i+1]);
        }*/

puts(nombreCompleto);

    return 0;

}
