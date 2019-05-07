#include "structUno.h"
#include "toolbox.h"
#define T 10

int main()
{
    eStructOne lista[T];

    initSomething(lista, T);

   int opcion;

   do
   {
        opcion=menuOptions();

        switch(opcion)
        {
        case 1:
        loadSomething(lista, T);
        break;
        case 2:

        break;
        case 3:

        break;
        case 4:
        mostrarListaAlgo(lista, T);
        break;
        case 5:

        break;
        case 9:
           printf("Tienes que aprobarme pipo, por mi, por maginer.");
        break;
        }

   }while(opcion != 9);





    return 0;
}
