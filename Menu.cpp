#include "Menu.h"
#include "Manejo_de_archivos.h"
#include "Validaciones.h"
#include <iostream>
#include "Constantes.h"

using namespace std;

void imprimir_linea_separadora(){
    cout<<"------------------------------------------------------------------------------------------------"<<endl;
}

void mostrar_menu(){
    imprimir_linea_separadora();
    cout<<"Menu:"<<endl<<endl
    <<"1) Listar libros leidos"<<endl
    <<"2) Agregar libro"<<endl
    <<"3) Editar puntaje de un libro por titulo"<<endl
    <<"4) Mostrar libro favorito"<<endl
    <<"5) Mostrar los 3 libros con menor puntaje"<<endl
    <<"6) Mostrar genero mas leido"<<endl
    <<"7) Mostrar genero favorito"<<endl
    <<"8) Guardar y salir"<<endl;
    imprimir_linea_separadora();
}




void listar_libros(Biblioteca biblioteca){

    for(int i = 0;i<biblioteca.indice_del_proximo_libro;i++){
        imprimir_linea_separadora();
        cout<<"Titulo: "<<biblioteca.libros[i]->titulo<<endl;
        imprimir_genero(biblioteca.libros[i]->genero);
        cout<<"Puntaje: "<<biblioteca.libros[i]->puntaje<<endl;
        imprimir_linea_separadora();
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

    obtener_titulo(titulo);
    if(!existe_libro(titulo,biblioteca)){

        obtener_genero(genero);

        cout<<"Ingrese el puntaje: ";
        obtener_valor(puntaje);
        if(!es_rango_valido(puntaje,PUNTAJE_MINIMO,PUNTAJE_MAXIMO)){
            reingresar_puntaje(puntaje);
        }

        agregar_libro(crear_libro(titulo,genero,puntaje), biblioteca);
    }
    else{
        cout<<"El libro ya existe y no puede ser agregado nuevamente."<<endl;
    }
}

void imprimir_lista_generos(){
    imprimir_linea_separadora();
    cout<<AVENTURA<<") Aventura"<<endl;
    cout<<CIENCIA_FICCION<<") Ciencia ficcion"<<endl;
    cout<<DIDACTICA<<") Didactica"<<endl;
    cout<<POLICIACA<<") Policiaca"<<endl;
    cout<<ROMANCE<<") Romance"<<endl;
    cout<<TERROR<<") Terror"<<endl;
    imprimir_linea_separadora();
}






void editar_puntaje(Biblioteca &biblioteca){
    string titulo;
    int indice_del_libro_a_editar;
    int nuevo_puntaje;
    cout<<"Por favor, ingrese el titulo del libro cuyo puntaje va a editar:"<<endl;
    obtener_titulo(titulo);

    if(existe_libro_plus(titulo, biblioteca, indice_del_libro_a_editar)){
        cout<<"Por favor, ingrese el nuevo puntaje: ";
        obtener_valor(nuevo_puntaje);
        if(!es_rango_valido(nuevo_puntaje,PUNTAJE_MINIMO,PUNTAJE_MAXIMO)){
            reingresar_puntaje(nuevo_puntaje);
        }
        biblioteca.libros[indice_del_libro_a_editar]->puntaje = nuevo_puntaje;
    }
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

        case EDITAR_PUNTAJE:
            editar_puntaje(biblioteca);
            break;

        case AGREGAR_LIBRO:
            agregar_libro(biblioteca);
            break;

        case GUARDAR_Y_SALIR:
            guardar_y_salir(biblioteca,seguir);
            break;

    }



}



