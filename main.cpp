#include "Menu.h"
#include "Estructuras y Punteros.h"

int main() {
   /* int opcion_elegida;
    bool opcion_valida = false;
    bool seguir = true;

    while(seguir) {
        mostrar_menu();
        while (!opcion_valida) {
            obtener_opcion(opcion_elegida);
            es_opcion_valida(opcion_elegida, opcion_valida);
            procesar_opcion_elegida(opcion_elegida,seguir);
        }
    }*/

    Biblioteca *biblioteca = new Biblioteca;
    inicializar_biblioteca(biblioteca,2);
    agregar_libro(crear_libro("juan de la rodilla",'a',80),biblioteca);
    agregar_libro(crear_libro("bovedas de acero",'p',90),biblioteca);
    agregar_libro(crear_libro("el sabueso de los baskerville",'p',100),biblioteca);

    imprimir_libros(biblioteca);
    eliminar_punteros(biblioteca);



    return 0;
}
