#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

/*typedef struct
{
  int a;
  char b;

}eDato;

eDato* function(int x, char y);*/

/** pedir un dato y guardarlo con puntero**/

int main()
{
    /*eDato datito = {10, 'c'};
    eDato* pDato;
    pDato= &datito;

    int x;

    x = (*pDato).a;
    printf("%d", x);*/


    /*eDato datito[2] = {{1, 'c'} , {2, 'b'}};
    eDato* pDato;
    pDato= &datito;
    int i;

    for(i=0;i<2;i++)
    {
       printf("HARD MODE \n\n");
       printf("%d", (*(pDato+i)).a);
       printf("%c\n", (*(pDato+i)).b);

       printf("OPERADOR FLECHA \n\n");
       printf("%d", (pDato+i)->a);
       printf("%c\n", (pDato+i)->b);
    }*/


    /*eDato* p;
    p = function(1, 'c');
    printf("%d - %c", p->a, p->b);

    eDato* q;
    q = function(2, 'b');
    printf("\n%d - %c", p->a, p->b);*/

    //malloc

    int* pEntero;
    pEntero = (int*)malloc(sizeof(int)*5);//esto esta bien
    // pEntero= &var; -- esto esta muy mal. Esto hace que la pila guarde mucha data.
    //La pila no tiene que guardar data.

    if(pEntero != NULL)
    {
       /* *pEntero= 9;
        printf("\nMalloc: %d", *pEntero); */
        int i;

        for (i=0;i<5;i++)
        {
            printf("Ingresar valor: \n");
            scanf("%d", pEntero+i);
        }
        for(i=0;i<5;i++)
        {
            printf("\n%d \n", *(pEntero+i));
        }
        realloc(pEntero, sizeof(int)*10);
    }

    getch();
    return 0;
}

/*eDato* function(int x, char y)
{
    eDato datito;
    eDato* pDato;
    pDato= &datito;
    pDato->a=x;
    pDato->b=y;
    return pDato;
}*/
