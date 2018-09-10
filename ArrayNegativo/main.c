#include <stdio.h>
#include <stdlib.h>


void iniciarVector (int vector[],int cantidad, int valorInicio);
void mostrarVector (int vector[],int cantidad, int valorInicio);

int main()
{
    int cantidad=5;
    int vectorMain[cantidad];
    int vectorNumerico[cantidad];
    int valorInicio=-1;

    iniciarVector(vectorNumerico, cantidad, valorInicio);
    mostrarVector(vectorNumerico, cantidad, valorInicio);


    return 0;
}

void iniciarVector (int vectorNumerico[], int cantidad, int valorInicio)
{
    for (; cantidad>0 ; cantidad--)
    {
        vectorNumerico[cantidad]=valorInicio++;
    }

void mostrarVector (int vectorNumerico[], int cantidad, int valorInicio);
{
    printf("%d\n", vectorNumerico[cantidad]);
}

}
