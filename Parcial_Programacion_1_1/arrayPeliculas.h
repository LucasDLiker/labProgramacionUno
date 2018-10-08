
#define ILOGIC -1
#define EMPTY 0
#define FULL 1
#define MAX 1000


#ifndef arrayPeliculas

    typedef struct
    {
        int idPelicula;
        char nombrePelicula[51];
        char directorPelicula[51];
        char nacionalidadPelicula[51];
        int isEmpty;
        int anoPelicula;


    }sPeliculas;

#endif //arrayPeliculas

int menuOptions();

int initPelicula(sPeliculas* arrayPeliculas, int capacidad);

int buscarLibre(sPeliculas* arrayPeliculas, int capacidad);

int buscarPeliculaPorID(sPeliculas* arrayPeliculas, int capacidad, int id);

int addPelicula(sPeliculas* arrayPeliculas, int capacidad, int auxIdPelicula, char auxNombrePelicula[], char auxDirectorPelicula[], char auxNacionalidadPelicula[], int auxAnoPelicula);

void modificarPelicula(sPeliculas* arrayPeliculas, int capacidad);

int mostrarPelicula(sPeliculas* arrayPeliculas, int cantidad);

int bajaPelicula(sPeliculas* arrayPeliculas, int capacidad, int id);

int menuOptions();

int subMenu();
