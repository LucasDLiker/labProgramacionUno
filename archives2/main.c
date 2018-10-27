#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct
{
    int entero;
    char caracter;

}eSomething;

int main()
{
    FILE* pArchivo;
    //int x= 7;
    //int y;
    eSomething pSomething={1, 'c'};


   /** pArchivo=fopen("archivo.bin", "wb");
    //fwrite(*void, sig, sigc, *FILE);
    //       DATO, TAMAÑO, CANTIDAD, ARCHIVO--
    //      &x, sizeof(int). |, parchivo

    y = fwrite(&x, sizeof(int), 1, pArchivo);
    fclose(pArchivo);
    printf("dato: %d", y);**/



/**______________________________________________**/

    pArchivo = fopen("archivo.bin", "rw");
    fread(&pSomething, sizeof (eSomething), 1, pArchivo);
    fclose(pArchivo);
    printf("\ndato: %d", );

    getch();
    return 0;
}
