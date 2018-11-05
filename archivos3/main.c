#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

/*int saveTxt (array, size, name)
{
    FILE* pFile;
    pFile=fopen("enteros.txt", "w");
}*/


int main()
{
    FILE* pFile;

    int arrayInt[10]={1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    char readInt[10][10];
    int i=0;

    pFile = fopen("enteros.txt", "w");

    for (i=0; i<10; i++)
    {
        fprintf(pFile, "%d\n", arrayInt[i]);
    }
    fclose(pFile);

    pFile=fopen("enteros.txt", "r");


    while (!feof(pFile))
    {
    fgets(pFile, "%s", readInt[i]);
    i++;
    }
    fclose(pFile);
    for(i=0;i<10;i++)
    {
        printf("%s\n", readInt[i]);
    }
    getch();
    return 0;
}
