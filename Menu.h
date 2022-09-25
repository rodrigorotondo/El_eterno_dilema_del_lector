
#ifndef EL_ETERNO_DILEMA_DEL_LECTOR_MENU_H
#define EL_ETERNO_DILEMA_DEL_LECTOR_MENU_H
#include "Validaciones.h"
#include "Constantes.h"
#include <string>
#include "Estructuras_y_Punteros.h"

using namespace std;

// -------------------------------funciones para el funcionamiento del menu--------------------------------------

//precondiciones:  -
//postcondiciones: imprime el menu
void mostrar_menu();

//precondiciones: -
//postcondiciones: imprime los generos existentes
void imprimir_lista_generos();

//precondiciones: la opcion elegida debe estar entre los rangos esperados (1 - 8)
//postcondiciones: invoca a la funcion pertinente y le pasa los parametros necesarios
void procesar_opcion_elegida(Biblioteca &biblioteca,int opcion_elegida, bool &seguir);

//precondiciones: -
//postcondiciones: carga el/los libros con mayor puntaje en la biblioteca de libros favoritos
void cargar_libros_favoritos(Biblioteca biblioteca, Biblioteca &libros_favoritos);

//precondiciones: el indice debe pertenecer a un array que haga referencia a los generos en el orden correcto
// orden correcto: 0) cantidad_libros_aventura 1) ciencia ficcion 2) cantidad_libros_didactica 3) cantidad_libros_policiaca 4) cantidad_libros_romance 5) cantidad_libros_terror
//postcondiciones: devuelve un char indicando el genero dependiendo del indice
char convertir_indice_en_genero(int indice);

//precondiciones: debe recibir un indice perteneciente a la biblioteca
//postcondiciones: le suma un libro dependiendo el genero del item de la biblioteca al struct generos ingresado
void sumar_libros_por_genero(Biblioteca biblioteca, Generos &generos, int indice);

//precondiciones: debe recibir un indice perteneciente a la biblioteca
//postcondiciones: suma el valor del puntaje al contador de generos dependiendo el item de la biblioteca
void sumar_puntajes(Biblioteca biblioteca, Generos &generos, int indice);

//precondiciones: -
//postcondiciones: devuelve un int dependiendo de si el titulo_1 es mas grande, mas chico o igual alfabeticamente
int comparar_strings(string titulo_1, string titulo_2);

//precondiciones: -
//postcondiciones: devuelve un promedio calculado en double entre la suma de puntajes y la cantidad de libros
double devolver_promedios(int suma_puntaje, int cantidad_libros);

//------------------------------------funciones fundamentales del programa-------------------------------------------
//precondiciones: -
//postcondiciones:Imprime por consola los libros de la biblioteca
void listar_libros(Biblioteca biblioteca);

//precondiciones: -
//postcondiciones: Imprime el genero al que correspone el char que se pasa
void imprimir_genero(char genero);

//precondiciones: -
//postcondiciones: agrega un libro con las caracteristicas ingresadas por consola a la biblioteca que recibe por parametro
void agregar_libro(Biblioteca &biblioteca);

//precondiciones: -
//postcondiciones: en caso de que se ingrese un titulo registrado en la biblioteca se le puede editar el puntaje
void editar_puntaje(Biblioteca &biblioteca);

//precondiciones: -
//postcondiciones: muestra el libro con mayor puntaje en la biblioteca
void mostrar_libro_favorito(Biblioteca biblioteca);

//precondiciones: -
//postcondiciones: muestra los 3 libros con menor puntaje, en caso de que tengan iguales puntajes, ordena alfabeticamente
void mostrar_libros_con_menor_puntaje(Biblioteca biblioteca);

//precondiciones: -
//postcondiciones: Muestra el genero que mas se leyo en la biblioteca y cuantos libros se leyeron
void mostrar_genero_mas_leido(Biblioteca biblioteca);

//precondiciones: -
//postcondiciones: se muestra el genero con mayor promedio y se imprime el promedio calculado
void mostrar_genero_favorito(Biblioteca biblioteca);

//precondiciones: -
//postcondiciones:se graban los datos de la biblioteca en un archivo de libros, se libera la memoria dinamica
// y se modifica la variable booleana seguir
void guardar_y_salir(Biblioteca biblioteca, bool &seguir);


#endif //EL_ETERNO_DILEMA_DEL_LECTOR_MENU_H
