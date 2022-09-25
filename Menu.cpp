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




void mostrar_libro_favorito(Biblioteca biblioteca) {
    Biblioteca libros_favoritos{};
    inicializar_biblioteca(libros_favoritos, 1);
    if (biblioteca.indice_del_proximo_libro != 0) {
        libros_favoritos.libros[0] = biblioteca.libros[0];
        libros_favoritos.indice_del_proximo_libro++;
    }
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






void mostrar_libros_con_menor_puntaje(Biblioteca biblioteca){
    int indice_primer_libro = 0;
    int indice_segundo_libro = 1;
    int indice_tercer_libro = 2;
    int indice_auxiliar;
    if(biblioteca.indice_del_proximo_libro > 2) {
        if (biblioteca.libros[indice_segundo_libro]->puntaje <= biblioteca.libros[indice_primer_libro]->puntaje) {
            if (biblioteca.libros[indice_segundo_libro]->puntaje < biblioteca.libros[indice_primer_libro]->puntaje ||
                comparar_strings(biblioteca.libros[indice_segundo_libro]->titulo,
                                 biblioteca.libros[indice_primer_libro]->titulo) == ALFABETICAMENTE_MENOR) {
                indice_auxiliar = indice_segundo_libro;
                indice_segundo_libro = indice_primer_libro;
                indice_primer_libro = indice_auxiliar;
            }
        }
        if(biblioteca.libros[indice_tercer_libro]->puntaje <= biblioteca.libros[indice_primer_libro]->puntaje){
            if(biblioteca.libros[indice_tercer_libro]->puntaje < biblioteca.libros[indice_primer_libro]->puntaje ||
               comparar_strings(biblioteca.libros[indice_tercer_libro]->titulo,
                                biblioteca.libros[indice_primer_libro]->titulo) == ALFABETICAMENTE_MENOR){
                indice_auxiliar = indice_tercer_libro;
                indice_tercer_libro = indice_segundo_libro;
                indice_segundo_libro = indice_primer_libro;
                indice_primer_libro = indice_auxiliar;
            }
            else if(biblioteca.libros[indice_tercer_libro]->puntaje < biblioteca.libros[indice_segundo_libro]->puntaje || comparar_strings(biblioteca.libros[indice_tercer_libro]->titulo,
                                     biblioteca.libros[indice_segundo_libro]->titulo) == ALFABETICAMENTE_MENOR){
                indice_auxiliar = indice_tercer_libro;
                indice_tercer_libro = indice_segundo_libro;
                indice_segundo_libro = indice_auxiliar;
            }
        }
        else if(biblioteca.libros[indice_tercer_libro]->puntaje <= biblioteca.libros[indice_segundo_libro]->puntaje){
            if(biblioteca.libros[indice_tercer_libro]->puntaje < biblioteca.libros[indice_segundo_libro]->puntaje ||
               comparar_strings(biblioteca.libros[indice_tercer_libro]->titulo,
                                biblioteca.libros[indice_segundo_libro]->titulo) == ALFABETICAMENTE_MENOR){
                indice_auxiliar = indice_tercer_libro;
                indice_tercer_libro = indice_segundo_libro;
                indice_segundo_libro = indice_auxiliar;
            }
        }


        for (int i = 3; i < biblioteca.indice_del_proximo_libro; i++) {
            if (biblioteca.libros[i]->puntaje <= biblioteca.libros[indice_primer_libro]->puntaje) {
                if (biblioteca.libros[i]->puntaje < biblioteca.libros[indice_primer_libro]->puntaje ||
                    comparar_strings(biblioteca.libros[i]->titulo, biblioteca.libros[indice_primer_libro]->titulo) ==
                    ALFABETICAMENTE_MENOR) {
                    indice_tercer_libro = indice_segundo_libro;
                    indice_segundo_libro = indice_primer_libro;
                    indice_primer_libro = i;
                } else if (comparar_strings(biblioteca.libros[i]->titulo,
                                            biblioteca.libros[indice_segundo_libro]->titulo) == ALFABETICAMENTE_MENOR) {
                    indice_tercer_libro = indice_segundo_libro;
                    indice_segundo_libro = i;
                } else if (comparar_strings(biblioteca.libros[i]->titulo,
                                            biblioteca.libros[indice_tercer_libro]->titulo) == ALFABETICAMENTE_MENOR) {
                    indice_tercer_libro = i;
                }
            } else if ((biblioteca.libros[i]->puntaje <=
                        biblioteca.libros[indice_segundo_libro]->puntaje)) {//&& (biblioteca.libros[i]->puntaje > biblioteca.libros[indice_tercer_libro]->puntaje)
                if (biblioteca.libros[i]->puntaje < biblioteca.libros[indice_segundo_libro]->puntaje ||
                    comparar_strings(biblioteca.libros[i]->titulo, biblioteca.libros[indice_segundo_libro]->titulo) ==
                    ALFABETICAMENTE_MENOR) {
                    indice_tercer_libro = indice_segundo_libro;
                    indice_segundo_libro = i;
                } else if (comparar_strings(biblioteca.libros[i]->titulo,
                                            biblioteca.libros[indice_tercer_libro]->titulo) == ALFABETICAMENTE_MENOR) {
                    indice_tercer_libro = i;
                }
            } else if (biblioteca.libros[i]->puntaje <= biblioteca.libros[indice_tercer_libro]->puntaje) {
                if (biblioteca.libros[i]->puntaje < biblioteca.libros[indice_tercer_libro]->puntaje ||
                    comparar_strings(biblioteca.libros[i]->titulo, biblioteca.libros[indice_tercer_libro]->titulo) ==
                    ALFABETICAMENTE_MENOR) {
                    indice_tercer_libro = i;
                }
            }


        }
        cout << "Los peores 3 libros son: " << endl << "1)" << endl;
        cout << "Titulo: " << biblioteca.libros[indice_primer_libro]->titulo << endl;
        imprimir_genero(biblioteca.libros[indice_primer_libro]->genero);
        cout << "Puntaje: " << biblioteca.libros[indice_primer_libro]->puntaje << endl;
        imprimir_linea_separadora();
        cout << "2)" << endl;
        cout << "Titulo: " << biblioteca.libros[indice_segundo_libro]->titulo << endl;
        imprimir_genero(biblioteca.libros[indice_segundo_libro]->genero);
        cout << "Puntaje: " << biblioteca.libros[indice_segundo_libro]->puntaje << endl;
        imprimir_linea_separadora();
        cout << "3)" << endl;
        cout << "Titulo: " << biblioteca.libros[indice_tercer_libro]->titulo << endl;
        imprimir_genero(biblioteca.libros[indice_tercer_libro]->genero);
        cout << "Puntaje: " << biblioteca.libros[indice_tercer_libro]->puntaje << endl;

    }
    else{
        cout<<"Hay menos de 3 libros en la biblioteca, por favor ingrese al menos 3 libros para continuar"<<endl;
    }
    imprimir_linea_separadora();
}

int comparar_strings(string titulo_1, string titulo_2){
    int orden_alfabetico;
    if(titulo_1.compare(titulo_2) < 0){
        orden_alfabetico = ALFABETICAMENTE_MENOR;
    }
    else if(titulo_1.compare(titulo_2) > 0){
        orden_alfabetico = ALFABETICAMENTE_MAYOR;
    }
    else{
        orden_alfabetico = ALFABETICAMENTE_IGUAL;
    }
    return orden_alfabetico;
}







void mostrar_genero_mas_leido(Biblioteca biblioteca){
    Generos generos {};

    for(int i = 0; i <biblioteca.indice_del_proximo_libro; i++){
        sumar_generos(biblioteca, generos, i);
    }
    int array_generos[] = {generos.aventura,
                           generos.ciencia_ficcion,
                           generos.didactica,
                           generos.policiaca,
                           generos.romance,
                           generos.terror};
    generos.mayor_cantidad_de_libros_leidos = array_generos[INDICE_AVENTURA];
    for(int i = 1; i<CANTIDAD_DE_GENEROS; i++){
        if(generos.mayor_cantidad_de_libros_leidos < array_generos[i]){
            generos.mayor_cantidad_de_libros_leidos = array_generos[i];
        }
    }

    cout<<"Los generos mas leidos son: "<<endl;

    for(int i = 0; i<CANTIDAD_DE_GENEROS; i++){
        if(array_generos[i] == generos.mayor_cantidad_de_libros_leidos){
            imprimir_genero(convertir_indice_en_genero(i));
        }
    }
    cout << "Con " << generos.mayor_cantidad_de_libros_leidos << " libros leidos" <<endl;
    imprimir_linea_separadora();


}

void sumar_generos(Biblioteca biblioteca, Generos &generos, int indice){
    switch(biblioteca.libros[indice]->genero){
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
void mostrar_genero_favorito(Biblioteca biblioteca){
    Generos generos {};

    for(int i = 0; i <biblioteca.indice_del_proximo_libro; i++){
        sumar_generos(biblioteca, generos, i);
        sumar_puntajes(biblioteca,generos,i);
    }

    double promedios_por_genero [] = {devolver_promedios(generos.puntaje_aventura, generos.aventura),
                                     devolver_promedios(generos.puntaje_ciencia_ficcion, generos.ciencia_ficcion),
                                     devolver_promedios(generos.puntaje_didactica, generos.didactica),
                                     devolver_promedios(generos.puntaje_policiaca, generos.policiaca),
                                      devolver_promedios(generos.puntaje_romance, generos.romance),
                                      devolver_promedios(generos.puntaje_terror, generos.terror)};

    double promedio_mas_alto = promedios_por_genero[INDICE_AVENTURA];

    for(int i = 1; i<CANTIDAD_DE_GENEROS; i++){

        if(promedio_mas_alto < promedios_por_genero[i] ){
            promedio_mas_alto = promedios_por_genero[i];
        }
    }

    cout<<"Generos favoritos: "<<endl;
    for(int i = 0; i<CANTIDAD_DE_GENEROS; i++){
        if(promedio_mas_alto == promedios_por_genero[i]){
            imprimir_genero(convertir_indice_en_genero(i));
        }
    }
    cout<<"con un promedio de: " << promedio_mas_alto<<endl;
    imprimir_linea_separadora();
}
double devolver_promedios(int suma_puntaje, int cantidad_libros){
    double promedio;
    if(cantidad_libros == 0){
        promedio = 0;
    }
    else{
        promedio = (double)suma_puntaje/cantidad_libros;
    }

    return promedio;
}

void sumar_puntajes(Biblioteca biblioteca, Generos &generos, int indice){
    switch(biblioteca.libros[indice]->genero){
        case GENERO_AVENTURA:
            generos.puntaje_aventura += biblioteca.libros[indice]->puntaje ;
            break;
        case GENERO_CIENCIA_FICCION:
            generos.puntaje_ciencia_ficcion += biblioteca.libros[indice]->puntaje;
            break;
        case GENERO_DIDACTICA:
            generos.puntaje_didactica += biblioteca.libros[indice]->puntaje;
            break;
        case GENERO_POLICIACA:
            generos.puntaje_policiaca += biblioteca.libros[indice]->puntaje;
            break;
        case GENERO_ROMANCE:
            generos.puntaje_romance += biblioteca.libros[indice]->puntaje;
            break;
        case GENERO_TERROR:
            generos.puntaje_terror += biblioteca.libros[indice]->puntaje;
            break;
    }

}
void guardar_y_salir(Biblioteca biblioteca, bool &seguir){
    escribir_biblioteca_en_csv(biblioteca);
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

        case MOSTRAR_LIBROS_CON_MENOR_PUNTAJE:
            mostrar_libros_con_menor_puntaje(biblioteca);
            break;

        case MOSTRAR_GENERO_MAS_LEIDO:
            mostrar_genero_mas_leido(biblioteca);
            break;

        case MOSTRAR_GENERO_FAVORITO:
            mostrar_genero_favorito(biblioteca);
            break;

        case GUARDAR_Y_SALIR:
            guardar_y_salir(biblioteca,seguir);
            break;

    }



}



