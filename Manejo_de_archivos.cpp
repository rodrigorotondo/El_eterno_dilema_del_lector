#include "Menu.h"
#include "Manejo_de_archivos.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

void llenar_biblioteca(Biblioteca &biblioteca){
    stringstream linea_stringstream;
    string linea_archivo;
    string titulo;
    string genero_sin_convertir;
    char genero;
    string puntaje_sin_convertir;
    int puntaje;

    fstream archivo_libros(PATH,ios::in);

    if(!archivo_libros.is_open()){
        cout<<"El archivo no existe, se creara"<<endl;
        archivo_libros.open(PATH,ios::out);
        archivo_libros.close();
        archivo_libros.open(PATH,ios::in);
    }

    while(getline(archivo_libros,linea_archivo)){
        linea_stringstream << linea_archivo;
        while (getline(linea_stringstream,titulo,',')){
            getline(linea_stringstream,genero_sin_convertir,',');
            genero = genero_sin_convertir[0];
            getline(linea_stringstream,puntaje_sin_convertir,',');
            puntaje = stoi(puntaje_sin_convertir);
            agregar_libro(crear_libro(titulo,genero,puntaje),biblioteca);
        }
        linea_stringstream.clear();

    }

    archivo_libros.close();


}

void escribir_biblioteca_en_csv(Biblioteca biblioteca){
    ofstream archivo_libros(PATH,ios::out);
    for(int i = 0; i < biblioteca.indice_del_proximo_libro; i++){
        archivo_libros << biblioteca.libros[i]->titulo << ',' << biblioteca.libros[i]->genero << ','
        << biblioteca.libros[i]->puntaje << "\n";
    }

    archivo_libros.close();
}
