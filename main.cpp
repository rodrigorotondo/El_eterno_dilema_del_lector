#include "util.h"
#include <iostream>
using namespace std;
int main() {
    mostrar_menu();
    int opcion_elegida;
    bool opcion_valida = false;


    while(!opcion_valida){
        obtener_opcion(opcion_elegida);
        es_opcion_valida(opcion_elegida,opcion_valida);

    }
    cout<<"llegue"<<endl;

    return 0;
}
