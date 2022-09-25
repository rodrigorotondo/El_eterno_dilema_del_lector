
#ifndef EL_ETERNO_DILEMA_DEL_LECTOR_ESTRUCTURAS_Y_PUNTEROS_H
#define EL_ETERNO_DILEMA_DEL_LECTOR_ESTRUCTURAS_Y_PUNTEROS_H
#include "string"


using namespace std;

//structs
struct Libro{
    string titulo;
    char genero;
    int puntaje;

};


struct Biblioteca{
    Libro** libros;
    int indice_del_proximo_libro;
    int cantidad_maxima_de_libros;
};

struct Generos{
    //cantidad de libros de cada genero
    int aventura = 0;
    int ciencia_ficcion = 0;
    int didactica = 0;
    int policiaca = 0;
    int romance = 0;
    int terror = 0;
    int mayor_cantidad_de_libros_leidos;

    //suma de puntajes de los libros de cada genero
    int puntaje_aventura = 0;
    int puntaje_ciencia_ficcion = 0;
    int puntaje_didactica = 0;
    int puntaje_policiaca = 0;
    int puntaje_romance = 0;
    int puntaje_terror = 0;
    int promedio_mas_alto;

};

//funciones de Libro:
Libro* crear_libro(string titulo, char genero, int puntaje);

void agregar_libro(Libro *libro, Biblioteca &biblioteca);


//funciones de biblioteca
void inicializar_biblioteca( Biblioteca &biblioteca , int cantidad_maxima_de_libros);

void agrandar_biblioteca(Biblioteca &biblioteca);

void liberar_memoria_dinamica(Biblioteca &biblioteca);

//funciones libros favoritos
void reemplazar_libros_favoritos_con_menor_puntaje(Biblioteca biblioteca, Biblioteca &libros_favoritos, int indice);
void agregar_libro_favorito(Biblioteca biblioteca , Biblioteca &libros_favoritos,int indice);


#endif //EL_ETERNO_DILEMA_DEL_LECTOR_ESTRUCTURAS_Y_PUNTEROS_H
