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
    if(cin.fail()){ //cin.fail() detecta que el tipo ingresado concuerde con el valor en donde se almacena
        cin.clear(); //cin.clear() "limpia" el error producido en el caso de que se ingrese un tipo incorrecto
        cin.sync(); //cin.sync() "borra" los caracteres leidos por cin y deja la variable en 0
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

void procesar_opcion_elegida(int opcion_elegida, bool &seguir){

    switch(opcion_elegida){ // NOLINT(hicpp-multiway-paths-covered)

        case LISTAR_LIBROS:
            listar_libros();
            break;

        case AGREGAR_LIBRO:
            agregar_libro();
            break;

        case EDITAR_PUNTAJE:
            editar_puntaje();
            break;

        case MOSTRAR_LIBRO_FAVORITO:
            mostrar_libro_favorito();
            break;

        case MOSTRAR_LIBROS_CON_MENOR_PUNTAJE:
            mostrar_libros_con_menor_puntaje();
            break;

        case MOSTRAR_GENERO_MAS_LEIDO:
            mostrar_genero_mas_leido();
            break;

        case MOSTRAR_GENERO_FAVORITO:
            mostrar_genero_favorito();
            break;

        case GUARDAR_Y_SALIR:
            guardar_y_salir(seguir);
            break;


    }

}



