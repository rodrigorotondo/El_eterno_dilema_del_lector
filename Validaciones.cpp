#include "Validaciones.h"
#include "Constantes.h"
#include <iostream>

#include "Menu.h"



void obtener_valor(int &valor_elegido){


    cin >> valor_elegido;
    if(cin.fail()){ //cin.fail() detecta que el tipo ingresado concuerde con el valor en donde se almacena
        cin.clear(); //cin.clear() "limpia" el error producido en el caso de que se ingrese un tipo incorrecto
        cin.sync(); //cin.sync() "borra" los caracteres leidos por cin y deja la variable en 0
        valor_elegido = ERROR;
    }
}



bool es_rango_valido(int valor_elegido, int valor_minimo, int valor_maximo){
    bool opcion_valida;
    if(valor_elegido <= valor_maximo && valor_elegido >= valor_minimo){
        opcion_valida = true;
    }
    else{
        opcion_valida = false;
        cout<<"El valor elegido es invalido, ingrese una opcion entre "<<valor_minimo<<"-"<<valor_maximo<<endl;
    }
    return opcion_valida;
}

void obtener_titulo(string &titulo){
    cout<<"Ingrese el Titulo del libro: "<<endl;
    getline(cin>>ws,titulo);
    if(!es_titulo_valido(titulo)){
        reingresar_titulo(titulo);
    }

}

bool es_titulo_valido(string titulo){
    int i = 0;
    bool titulo_valido = true;
    while(titulo[i] != '\0' && titulo_valido ){
        if(titulo[i] == ','){
            titulo_valido = false;
        }
        i++;
    }
    return titulo_valido;
}

bool existe_libro(string titulo, Biblioteca biblioteca){
    bool el_libro_existe = false;
    int i = 0;
    while(!el_libro_existe && i!=biblioteca.indice_del_proximo_libro){
        if(titulo == biblioteca.libros[i]->titulo){
            el_libro_existe = true;
        }
        i++;
    }
    return el_libro_existe;
}

bool existe_libro_plus(string titulo, Biblioteca biblioteca, int &indice_del_libro){
    bool el_libro_existe = false;
    int i = 0;
    while(!el_libro_existe && i!=biblioteca.indice_del_proximo_libro){
        if(titulo == biblioteca.libros[i]->titulo){
            el_libro_existe = true;
            indice_del_libro = i;
        }
        i++;
    }
    return el_libro_existe;

}

void reingresar_titulo(string &titulo) {
    bool titulo_valido = false;
    while (!titulo_valido) {
        cout << "El titulo ingeresado no es valido, por favor ingrese un titulo sin comas" << endl;
        getline(cin >> ws, titulo);
        titulo_valido = es_titulo_valido(titulo);

    }

}
void obtener_genero(char &genero){
    //el genero se obtiene utilizando getline debido a que si se utiliza cin, suele entrar en un loop infinito
    //dificil de solucionar
    string entrada_genero;
    cout<<"Ingrese un genero de la lista (solo se tomara la primer letra): "<<endl;
    imprimir_lista_generos();
    getline(cin>>ws,entrada_genero);
    genero =entrada_genero[0];
    genero = toupper(genero);

    if(!es_genero_valido(genero)){
        reingresar_genero(genero);
    }
}

bool es_genero_valido(char genero){
    char generos[] = {AVENTURA,CIENCIA_FICCION,DIDACTICA,POLICIACA,ROMANCE,TERROR};
    int i = 0;
    bool genero_valido = false;
    while(!genero_valido && i<CANTIDAD_DE_GENEROS){
        if(genero == generos[i]){
            genero_valido = true;
        }
        i++;
    }

    return genero_valido;
}

void reingresar_genero(char &genero){
    bool genero_valido = false;
    while (!genero_valido) {
        cout << "El genero ingeresado no es valido, por favor ingrese un genero admitido en la lista: " << endl;

        obtener_genero(genero);
        genero_valido = es_genero_valido(genero);

    }

}

void reingresar_puntaje(int &puntaje){
    bool puntaje_valido = false;
    while(!puntaje_valido) {
        cout << "Ingrese el puntaje: ";
        cin >> puntaje;
        puntaje_valido = es_rango_valido(puntaje,PUNTAJE_MINIMO,PUNTAJE_MAXIMO);
    }
}