
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
    int cantidad_libros_aventura = 0;
    int cantidad_libros_ciencia_ficcion = 0;
    int cantidad_libros_didactica = 0;
    int cantidad_libros_policiaca = 0;
    int cantidad_libros_romance = 0;
    int cantidad_libros_terror = 0;
    int mayor_cantidad_de_libros_leidos;

    //suma de puntajes de los libros de cada genero
    int puntaje_aventura = 0;
    int puntaje_ciencia_ficcion = 0;
    int puntaje_didactica = 0;
    int puntaje_policiaca = 0;
    int puntaje_romance = 0;
    int puntaje_terror = 0;


};

//funciones de Libro:
//precondiciones: el titulo no debe tener comas, el genero debe ser correcto, el puntaje debe estar en los rangos esperados
//postcondiciones: devuelve un puntero a un libro
Libro* crear_libro(string titulo, char genero, int puntaje);

//precondiciones:los libros y bibliotecas deben ser del tipo correcto (generados por el programa)
//postcondiciones: agrega un libro a la biblioteca
void agregar_libro(Libro *libro, Biblioteca &biblioteca);


//funciones de biblioteca
//precondiciones: -
//postcondiciones: da condiciones iniciales a la biblioteca
void inicializar_biblioteca( Biblioteca &biblioteca , int cantidad_maxima_de_libros);

//precondiciones: -
//postcondiciones: agranda la capacidad maxima de la biblioteca al doble de tamaño conservando libros
void agrandar_biblioteca(Biblioteca &biblioteca);

//precondiciones: -
//postcondiciones: libera los libros de la memoria dinamica y luego el array que lo contenia
void liberar_memoria_dinamica(Biblioteca &biblioteca);

//funciones libros favoritos

//precondiciones: precisa el indice de la biblioteca del libro que ocupara el lugar del anterior,
// se espera que el libro nuevo tenga un puntaje mayor que el anterior y que el indice exista
//postcondiciones: el array que antes contenia libros con menor puntaje, ahora contiene un libro con un puntaje mayor a los anteriores
void reemplazar_libros_favoritos_con_menor_puntaje(Biblioteca biblioteca, Biblioteca &libros_favoritos, int indice);

//precondiciones: nececista que el indice del libro exista en la biblioteca
//postcondiciones: agrega el libro a la biblioteca de libros favoritos
void agregar_libro_favorito(Biblioteca biblioteca , Biblioteca &libros_favoritos,int indice);


#endif //EL_ETERNO_DILEMA_DEL_LECTOR_ESTRUCTURAS_Y_PUNTEROS_H
