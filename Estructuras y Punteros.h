
#ifndef EL_ETERNO_DILEMA_DEL_LECTOR_ESTRUCTURAS_Y_PUNTEROS_H
#define EL_ETERNO_DILEMA_DEL_LECTOR_ESTRUCTURAS_Y_PUNTEROS_H
#include "string"
#include "Menu.h"

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

//funciones de Libro:
Libro* crear_libro(string titulo, char genero, int puntaje);

void agregar_libro(Libro *libro, Biblioteca *biblioteca);

void imprimir_libros(Biblioteca *biblioteca);

//funciones de biblioteca
void inicializar_biblioteca( Biblioteca *biblioteca , int cantidad_maxima_de_libros);

void agrandar_biblioteca(Biblioteca *biblioteca);

void liberar_memoria_dinamica(Biblioteca *biblioteca);


#endif //EL_ETERNO_DILEMA_DEL_LECTOR_ESTRUCTURAS_Y_PUNTEROS_H
