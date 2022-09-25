#ifndef EL_ETERNO_DILEMA_DEL_LECTOR_VALIDACIONES_H
#define EL_ETERNO_DILEMA_DEL_LECTOR_VALIDACIONES_H
#include <string>
#include "Estructuras_y_Punteros.h"
using namespace std;
//precondiciones: precisa un valor a modificar de tipo int
//postcondiciones: modifica un valor int en caso de que el usuario ingrese un numero, si la conversion es imposible
//modifica el valor a uno de error
void obtener_valor(int &valor_elegido);

//precondiciones: el valor minimo y maximo deben ser coherentes, el valor minimo debe ser menor al valor maximo
//postcondiciones: devuelve un booleano dependiendo de si el valor elegido esta entre el valor minimo y maximo
bool es_rango_valido(int valor_elegido, int valor_minimo, int valor_maximo);





//precondiciones:recibe un valor de tipo string titulo a modificar
//postcondiciones: modifica el valor del titulo ingresado
void obtener_titulo(string &titulo);

//precondiciones: -
//postcondiciones: confirma que el titulo no este compuesto por comas
bool es_titulo_valido(string titulo);

//precondiciones: -
//postcondiciones: pide que el titulo sea reingresado hasta ser valido y lo modifica
void reingresar_titulo(string &titulo);





//precondiciones: -
//postcondiciones: devuelvem en caso de que exista el indice del libro en la biblioteca,
// caso contrario devuelve un codigo que significa que no fue encontrado
int buscar_libro(string titulo, Biblioteca biblioteca);






//precondiciones: recibe un valor genero de tipo char a modificar
//postcondiciones: modifica el valor genero
void obtener_genero(char &genero);

//precondiciones:-
//postcondiciones: devuelve un booleano dependiendo de que el valor ingresado sea correspondiente con uno de
// los generos existentes
bool es_genero_valido(char genero);

//precondiciones: -
//postcondiciones: pide que el genero sea reingresado hasta ser valido y lo modifica
void reingresar_genero(char &genero);

//precondiciones: -
//postcondiciones: pide que el genero sea reingresado hasta ser valido y lo modifica
void reingresar_puntaje(int &puntaje);


#endif //EL_ETERNO_DILEMA_DEL_LECTOR_VALIDACIONES_H
