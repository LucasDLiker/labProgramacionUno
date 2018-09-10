#include <stdio.h>
#include <stdlib.h>

int main()
{
   //strlen, strcpy, stricmp/strcmp
  //char cadena[20]={'h','o','l','a'};
  char cadena[20]="perro";
  char cadena2[20]="gato";
  strcpy (cadena2, "gato");
  /*int cantidad;
  cantidad = strlen (cadena);*/
  printf("%s \n", cadena);
  printf("%s \n", cadena2);

  /*
  int estado;
  estado=stricmp (cadena2, "gato");
  printf("%d", estado);
  */


//puts(); - Muestra una varialbe por consola.-

//pedir 3 nombres, 20 caracteres cada uno. (y apellido).
/*guardar el nombre y el apellido en una variable con una coma y un espacio entre el nombre y el apellido por ejemplo "juan, perez"
y que cada letra delantera este en mayuscula.- */






return 0;
}

/*
  printf("Ingrese nombre: ");
  fflush(stdin);
  //scanf("%s", &cadena);
  gets(cadena);
  printf("Su nombre es: %s", cadena);
*/
