#include "Menu.h"
#include "Manejo_de_archivos.h"
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
using namespace std;

void listar_libros(Biblioteca biblioteca){

    for(int i = 0;i<biblioteca.indice_del_proximo_libro;i++){
        cout<<"titulo: "<<biblioteca.libros[i]->titulo<<" Genero: "<<biblioteca.libros[i]->genero<<" puntaje: "<<biblioteca.libros[i]->puntaje<<endl;
    }
}
void agregar_libro(){
    cout<<"a";
}
void editar_puntaje(){
    cout<<"a";
}
void mostrar_libro_favorito(){
    cout<<"a";
}
void mostrar_libros_con_menor_puntaje(){
    cout<<"a";
}
void mostrar_genero_mas_leido(){
    cout<<"a";
}
void mostrar_genero_favorito(){
    cout<<"a";
}
void guardar_y_salir(Biblioteca biblioteca, bool &seguir){
    liberar_memoria_dinamica(biblioteca);
    seguir = false;
}

void procesar_opcion_elegida(Biblioteca &biblioteca, int opcion_elegida , bool &seguir){
    switch(opcion_elegida){
        case LISTAR_LIBROS:
            listar_libros(biblioteca);
            break;
        case GUARDAR_Y_SALIR:
            guardar_y_salir(biblioteca,seguir);

    }



}



