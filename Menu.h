
#ifndef EL_ETERNO_DILEMA_DEL_LECTOR_MENU_H
#define EL_ETERNO_DILEMA_DEL_LECTOR_MENU_H
#include <string>

using namespace std;

//constantes
const int CANTIDAD_MAXIMA_DE_LIBROS_INICIAL = 10;

const int ERROR = -1;
const int VALOR_MINIMO_ACEPTADO = 1;
const int VALOR_MAXIMO_ACEPTADO = 8;

const int LISTAR_LIBROS = 1;
const int AGREGAR_LIBRO = 2;
const int EDITAR_PUNTAJE = 3;
const int MOSTRAR_LIBRO_FAVORITO = 4;
const int MOSTRAR_LIBROS_CON_MENOR_PUNTAJE = 5;
const int MOSTRAR_GENERO_MAS_LEIDO = 6;
const int MOSTRAR_GENERO_FAVORITO = 7;
const int GUARDAR_Y_SALIR = 8;

const string PATH = "libros.csv";

//funciones para el funcionamiento del menu
void mostrar_menu();
void obtener_opcion(int &opcion_elegida);
void es_opcion_valida(int opcion_elegida,bool &opcion_valida);
void procesar_opcion_elegida(int opcion_elegida, bool &seguir);


//funciones fundamentales del programa
void listar_libros();
void agregar_libro();
void editar_puntaje();
void mostrar_libro_favorito();
void mostrar_libros_con_menor_puntaje();
void mostrar_genero_mas_leido();
void mostrar_genero_favorito();
void guardar_y_salir(bool &seguir);

#endif //EL_ETERNO_DILEMA_DEL_LECTOR_MENU_H
