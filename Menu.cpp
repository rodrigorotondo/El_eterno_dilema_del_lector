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
    if(buscar_libro(titulo,biblioteca) == EL_LIBRO_NO_EXISTE){

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
    cout << GENERO_AVENTURA << ") Aventura" << endl;
    cout << GENERO_CIENCIA_FICCION << ") Ciencia ficcion" << endl;
    cout << GENERO_DIDACTICA << ") Didactica" << endl;
    cout << GENERO_POLICIACA << ") Policiaca" << endl;
    cout << GENERO_ROMANCE << ") Romance" << endl;
    cout << GENERO_TERROR << ") Terror" << endl;
    imprimir_linea_separadora();
}






void editar_puntaje(Biblioteca &biblioteca){
    string titulo;
    int indice_del_libro_a_editar;
    int nuevo_puntaje;
    cout<<"Por favor, ingrese el titulo del libro cuyo puntaje va a editar:"<<endl;
    obtener_titulo(titulo);
    indice_del_libro_a_editar = buscar_libro(titulo,biblioteca);
    if(indice_del_libro_a_editar != EL_LIBRO_NO_EXISTE){
        cout<<"Por favor, ingrese el nuevo puntaje: ";
        obtener_valor(nuevo_puntaje);
        if(!es_rango_valido(nuevo_puntaje,PUNTAJE_MINIMO,PUNTAJE_MAXIMO)){
            reingresar_puntaje(nuevo_puntaje);
        }
        biblioteca.libros[indice_del_libro_a_editar]->puntaje = nuevo_puntaje;
    }
    else{
        cout<<"El titulo del libro ingresado no esta registrado"<<endl;

    }
}




void mostrar_libro_favorito(Biblioteca biblioteca){
    Biblioteca libros_favoritos{};
    inicializar_biblioteca(libros_favoritos,1);
    libros_favoritos.libros[0] = biblioteca.libros[0];
    cargar_libros_favoritos(biblioteca, libros_favoritos);
    imprimir_linea_separadora();
    if(libros_favoritos.indice_del_proximo_libro != 0) {
        if (libros_favoritos.indice_del_proximo_libro == 1) {
            cout << "El libro con mayor puntaje es: " << libros_favoritos.libros[0]->titulo << " ";
            imprimir_genero(libros_favoritos.libros[0]->genero);


        } else {
            cout << "Los libros con mayor puntaje son: " << endl;
            for (int i = 0; i <= libros_favoritos.indice_del_proximo_libro-1; i++) {
                cout << libros_favoritos.libros[i]->titulo << " ";
                imprimir_genero(libros_favoritos.libros[i]->genero);
            }

        }
        cout << "Con un puntaje de: "<<libros_favoritos.libros[0]->puntaje<<endl;
    }
    else{
        cout<<"No se registraron libros"<<endl;
    }
    delete [] libros_favoritos.libros;
    imprimir_linea_separadora();

}

void cargar_libros_favoritos(Biblioteca biblioteca, Biblioteca &libros_favoritos){
    for(int i = 1; i<=biblioteca.indice_del_proximo_libro-1;i++){
        if(biblioteca.libros[i]->puntaje > libros_favoritos.libros[0]->puntaje){
            reemplazar_libros_favoritos_con_menor_puntaje(biblioteca , libros_favoritos , i);

        }
        else if(libros_favoritos.libros[0]->puntaje == biblioteca.libros[i]->puntaje){
            agregar_libro_favorito(biblioteca,libros_favoritos,i);

        }
    }
}






void mostrar_libros_con_menor_puntaje(){
    cout<<"a";
}
void mostrar_genero_mas_leido(Biblioteca biblioteca){
    Generos_mas_leidos generos {};

    for(int i = 0; i <biblioteca.indice_del_proximo_libro; i++){
        switch(biblioteca.libros[i]->genero){
            case GENERO_AVENTURA:
                generos.aventura++;
                break;
            case GENERO_CIENCIA_FICCION:
                generos.ciencia_ficcion++;
                break;
            case GENERO_DIDACTICA:
                generos.didactica++;
                break;
            case GENERO_POLICIACA:
                generos.policiaca++;
                break;
            case GENERO_ROMANCE:
                generos.romance++;
                break;
            case GENERO_TERROR:
                generos.terror++;
                break;
        }
    }
    int array_generos[] = {generos.aventura, generos.ciencia_ficcion, generos.didactica,
                             generos.policiaca, generos.romance, generos.terror};
    generos.mayor_mayor_cantidad_de_libros_leidos = array_generos[INDICE_AVENTURA];
    for(int i = 1; i<CANTIDAD_DE_GENEROS; i++){
        if(generos.mayor_mayor_cantidad_de_libros_leidos < array_generos[i]){
            generos.mayor_mayor_cantidad_de_libros_leidos = array_generos[i];
        }
    }

    cout<<"Los generos mas leidos son: "<<endl;

    for(int i = 0; i<CANTIDAD_DE_GENEROS; i++){
        if(array_generos[i] == generos.mayor_mayor_cantidad_de_libros_leidos){
            imprimir_genero(convertir_indice_en_genero(i));
        }
    }
    imprimir_linea_separadora();


}

char convertir_indice_en_genero(int indice){
    char genero;
    switch(indice){
        case INDICE_AVENTURA:
            genero = GENERO_AVENTURA;
            break;
        case INDICE_CIENCIA_FICCION:
            genero = GENERO_CIENCIA_FICCION;
            break;
        case INDICE_DIDACTICA:
            genero = GENERO_DIDACTICA;
            break;
        case INDICE_POLICIACA:
            genero = GENERO_POLICIACA;
            break;
        case INDICE_ROMANCE:
            genero = GENERO_ROMANCE;
            break;
        case INDICE_TERROR:
            genero = GENERO_TERROR;
            break;
    }
    return genero;
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

        case MOSTRAR_LIBRO_FAVORITO:
            mostrar_libro_favorito(biblioteca);
            break;
        case MOSTRAR_GENERO_MAS_LEIDO:
            mostrar_genero_mas_leido(biblioteca);
            break;
        case GUARDAR_Y_SALIR:
            guardar_y_salir(biblioteca,seguir);
            break;

    }



}



