#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

//fopen(path, mode);
//fopen devuelve un puntero a file.
/*
1- abrir
2- usar
3- cerrar. Siepre es necesario PORQUE pç
1- podria peder inforacion o corromperla
2- queda abierto en memoria

*/
int main()
{
    FILE* pArchivo;



    /** ESCRITURA DE TXT **/

    /*char chain[20]="LORDBAUS";
    pArchivo = fopen("saludo.txt", "w");
    //si no existe se crea y si existe lo sobreescribe.-
    //fprintf(pArchivo, chain);
    fprintf(pArchivo, "Hello, alighty %s How are you doing sir?\n And arduinito?", chain);
    //fprintf(pArchivo, "Hello bonds");
    fclose(pArchivo);



    /**____________CONSOLA______________**/
   /* char text[51];
    char textOne[51];


    pArchivo = fopen("saludo.txt", "r");
    fgets(text, 51, pArchivo);
    fgets(textOne, 51, pArchivo);
    fclose(pArchivo);
    puts(text);
    puts(textOne);

    /**_____________LEERVARIOS___________**/

    pArchivo = fopen("saludo.txt", "w");
    fprintf(pArchivo, " OLA\n KE\n ASE");
    fclose(pArchivo);


    char texts[3][50];
    int i=0;
    pArchivo = fopen("saludo.txt", "r");

    while (!feof(pArchivo))
    {
        fgets(texts[i], 50, pArchivo);
        i++;
    }
    for (i=0; i<3; i++)
    {
        puts(texts[i]);
    }
    fclose(pArchivo);

    getch();
    return 0;
}
