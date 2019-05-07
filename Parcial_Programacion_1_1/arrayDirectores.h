#define ILOGIC -1
#define EMPTY 0
#define FULL 1
#define MAXB 500


#ifndef arrayDirectores

    typedef struct
    {
        int idDirector;
        char nombreDirector[51];
        char paisOrigen[51];
        int isEmptyDirector;
        int fechaNacimiento;


    }sDirectores;

#endif //arrayDirectores

int menuOptions();

int initDirector(sDirectores* arrayDirectores, int capacidad);

int buscarLibreDirector(sDirectores* arrayDirectores, int capacidad);

int buscarDirectorPorID(sDirectores* arrayDirectores, int capacidad, int idDirector);

int addDirector(sDirectores* arrayDirectores, int capacidad, int auxIdDirector, char auxNombreDirector[], char auxPaisOrigen[], int auxFechaNacimiento);

int mostrarDirector(sDirectores* arrayDirectores, int cantidad);

int bajaDirector(sDirectores* arrayDirectores, int capacidad, int id);


