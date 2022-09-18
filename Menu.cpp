#include "Menu.h"
#include "Manejo_de_archivos.h"
#include "Validaciones.h"
#include <iostream>
#include "Constantes.h"

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




using namespace std;

void listar_libros(Biblioteca biblioteca){

    for(int i = 0;i<biblioteca.indice_del_proximo_libro;i++){
        cout<<"------------------------------------------------------------------------------------------------"<<endl;
        cout<<"Titulo: "<<biblioteca.libros[i]->titulo<<endl;
        imprimir_genero(biblioteca.libros[i]->genero);
        cout<<"Puntaje: "<<biblioteca.libros[i]->puntaje<<endl;
        cout<<"------------------------------------------------------------------------------------------------"<<endl;
    }
}

void imprimir_genero(char genero){
    switch(genero){
        case 'A':
            cout<<"Genero: Aventura"<<endl;
            break;

        case 'C':
            cout<<"Genero: Ciencia ficcion"<<endl;
            break;

        case 'D':
            cout<<"Genero: Didactica"<<endl;
            break;

        case 'P':
            cout<<"Genero: Policiaca"<<endl;
            break;

        case 'R':
            cout<<"Genero: Romance"<<endl;
            break;

        case 'T':
            cout<<"Genero: Terror"<<endl;
            break;

        default:
            cout<<"El genero es desconocido"<<endl;

    }
}
void agregar_libro(Biblioteca &biblioteca){
    string titulo;
    char genero;
    int puntaje;

    cout<<"Ingrese el Titulo del libro: "<<endl;
    getline(cin>>ws,titulo);
    if(!es_titulo_valido(titulo)){
        reingresar_titulo(titulo);
    }

    obtener_genero(genero);
    if(!es_genero_valido(genero)){
        reingresar_genero(genero);
    }


    cout<<"Ingrese el puntaje: ";
    obtener_valor(puntaje);
    if(!es_rango_valido(puntaje,PUNTAJE_MINIMO,PUNTAJE_MAXIMO)){
        reingresar_puntaje(puntaje);
    }

    agregar_libro(crear_libro(titulo,genero,puntaje), biblioteca);
}
void imprimir_lista_generos(){
    cout<<AVENTURA<<") Aventura"<<endl;
    cout<<CIENCIA_FICCION<<") Ciencia ficcion"<<endl;
    cout<<DIDACTICA<<") Didactica"<<endl;
    cout<<POLICIACA<<") Policiaca"<<endl;
    cout<<ROMANCE<<") Romance"<<endl;
    cout<<TERROR<<") Terror"<<endl<<endl;
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
        case AGREGAR_LIBRO:
            agregar_libro(biblioteca);
            break;
        case GUARDAR_Y_SALIR:
            guardar_y_salir(biblioteca,seguir);
            break;

    }



}



