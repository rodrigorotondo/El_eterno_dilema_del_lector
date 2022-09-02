#include "util.h"
#include <iostream>
using namespace std;

void mostrar_menu(){
    cout<<"Menu:"<<endl<<endl<<endl
    <<"1) Listar libros leidos"<<endl
    <<"2) Agregar libro"<<endl
    <<"3) Editar puntaje de un libro por titulo"<<endl
    <<"4) Mostrar libro favorito"<<endl
    <<"5) Mostrar los 3 libros con menor puntaje"<<endl
    <<"6) Mostrar genero mas leido"<<endl
    <<"7) Mostrar genero favorito"<<endl
    <<"8) Guardar y salir"<<endl;
}

void obtener_opcion(int &opcion_elegida){

    cout<<"Por favor, elija una opcion: ";
    cin>>opcion_elegida;
    if(cin.fail()){
        cin.clear();
        cin.sync();
        opcion_elegida = ERROR;
    }
}

void es_opcion_valida(int opcion_elegida , bool &opcion_valida){
    if(opcion_elegida <= VALOR_MAXIMO_ACEPTADO && opcion_elegida >= VALOR_MINIMO_ACEPTADO){
        opcion_valida = true;
    }
    else{
        cout<<"La opcion elegida es invalida, ingrese una opcion entre los valores 1 - 8"<<endl;
    }
}

