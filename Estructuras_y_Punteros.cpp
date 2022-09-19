#include "Estructuras_y_Punteros.h"
#include <string>


using namespace std;

//funciones de Biblioteca
void inicializar_biblioteca( Biblioteca &biblioteca , int cantidad_maxima_de_libros){
    biblioteca.indice_del_proximo_libro = 0;
    biblioteca.cantidad_maxima_de_libros = cantidad_maxima_de_libros;
    biblioteca.libros = new Libro*[biblioteca.cantidad_maxima_de_libros];
}



void agrandar_biblioteca(Biblioteca &biblioteca){
    int nuevo_tamanio = biblioteca.cantidad_maxima_de_libros*2;
    Libro ** biblioteca_agrandada = new Libro *[nuevo_tamanio];

    for(int i = 0; i<=biblioteca.indice_del_proximo_libro-1; i++){
        biblioteca_agrandada[i] = biblioteca.libros[i];
    }

    delete [] biblioteca.libros;

    biblioteca.libros = biblioteca_agrandada;
    biblioteca.cantidad_maxima_de_libros = nuevo_tamanio;

}

//funciones de Libro
Libro* crear_libro(string titulo, char genero, int puntaje){
    Libro *libro = new Libro;
    libro->titulo = titulo;
    libro->genero = genero;
    libro->puntaje = puntaje;

    return libro;
}

void agregar_libro(Libro *libro, Biblioteca &biblioteca){
    if(biblioteca.cantidad_maxima_de_libros == (biblioteca.indice_del_proximo_libro)){
        agrandar_biblioteca(biblioteca);
    }
    biblioteca.libros[biblioteca.indice_del_proximo_libro] = libro;
    biblioteca.indice_del_proximo_libro = biblioteca.indice_del_proximo_libro + 1;


}



void liberar_memoria_dinamica(Biblioteca &biblioteca){
    for(int i = 0; i<biblioteca.indice_del_proximo_libro;i++){
        delete biblioteca.libros[i];
    }
    delete [] biblioteca.libros;

}

