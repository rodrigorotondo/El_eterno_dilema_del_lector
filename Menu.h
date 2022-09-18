
#ifndef EL_ETERNO_DILEMA_DEL_LECTOR_MENU_H
#define EL_ETERNO_DILEMA_DEL_LECTOR_MENU_H
#include "Validaciones.h"
#include "Constantes.h"
#include <string>
#include "Estructuras y Punteros.h"

using namespace std;

//funciones para el funcionamiento del menu
void mostrar_menu();
void imprimir_lista_generos();
void procesar_opcion_elegida(Biblioteca &biblioteca,int opcion_elegida, bool &seguir);


//funciones fundamentales del programa
void listar_libros(Biblioteca *biblioteca);
void imprimir_genero(char genero);
void agregar_libro(Biblioteca &biblioteca);
/*void editar_puntaje();
void mostrar_libro_favorito();
void mostrar_libros_con_menor_puntaje();
void mostrar_genero_mas_leido();
void mostrar_genero_favorito();
void guardar_y_salir(Biblioteca *biblioteca, bool &seguir);*/


#endif //EL_ETERNO_DILEMA_DEL_LECTOR_MENU_H
