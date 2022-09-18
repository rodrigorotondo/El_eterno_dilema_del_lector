#ifndef EL_ETERNO_DILEMA_DEL_LECTOR_VALIDACIONES_H
#define EL_ETERNO_DILEMA_DEL_LECTOR_VALIDACIONES_H
#include <string>
using namespace std;
void obtener_valor(int &valor_elegido);
bool es_rango_valido(int valor_elegido, int valor_minimo, int valor_maximo);

//validaciones del titulo
bool es_titulo_valido(string titulo);
void reingresar_titulo(string &titulo);

//validaciones del genero
void obtener_genero(char &genero);
bool es_genero_valido(char genero);
void reingresar_genero(char &genero);

//validaciones puntaje
void reingresar_puntaje(int &puntaje);


#endif //EL_ETERNO_DILEMA_DEL_LECTOR_VALIDACIONES_H
