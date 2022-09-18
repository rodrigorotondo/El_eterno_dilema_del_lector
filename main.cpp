#include "Menu.h"
#include "Validaciones.h"
#include "Constantes.h"
#include "Manejo_de_archivos.h"
#include <iostream>



int main() {

    Biblioteca biblioteca{};

    inicializar_biblioteca(biblioteca,CANTIDAD_MAXIMA_DE_LIBROS_INICIAL);
    llenar_biblioteca(biblioteca);

    int opcion_elegida;

    bool seguir = true;

    while(seguir) {
        bool opcion_valida = false;
        mostrar_menu();
        while (!opcion_valida) {
            cout<<"Por favor, elija una opcion: ";
            obtener_valor(opcion_elegida);
            opcion_valida = es_rango_valido(opcion_elegida,VALOR_MINIMO_ACEPTADO,VALOR_MAXIMO_ACEPTADO);
            procesar_opcion_elegida(biblioteca,opcion_elegida,seguir);

        }
    }

    /*Biblioteca *biblioteca = new Biblioteca;
    inicializar_biblioteca(biblioteca,2);
    agregar_libro(crear_libro("juan de la rodilla",'a',80),biblioteca);
    agregar_libro(crear_libro("bovedas de acero",'p',90),biblioteca);
    agregar_libro(crear_libro("el sabueso de los baskerville",'p',100),biblioteca);

    imprimir_libros(biblioteca);
    liberar_memoria_dinamica(biblioteca);*/



    return 0;
}
