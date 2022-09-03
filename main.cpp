#include "util.h"


int main() {
    int opcion_elegida;
    bool opcion_valida = false;
    bool seguir = true;

    while(seguir) {
        mostrar_menu();
        while (!opcion_valida) {
            obtener_opcion(opcion_elegida);
            es_opcion_valida(opcion_elegida, opcion_valida);
            procesar_opcion_elegida(opcion_elegida,seguir);
        }
    }


    return 0;
}
