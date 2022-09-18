

#ifndef EL_ETERNO_DILEMA_DEL_LECTOR_CONSTANTES_H
#define EL_ETERNO_DILEMA_DEL_LECTOR_CONSTANTES_H
#include <string>

using namespace std;
const int CANTIDAD_MAXIMA_DE_LIBROS_INICIAL = 10;

const int ERROR = -1;

const int VALOR_MINIMO_ACEPTADO = 1;
const int VALOR_MAXIMO_ACEPTADO = 8;

const char AVENTURA = 'A';
const char CIENCIA_FICCION = 'C';
const char DIDACTICA = 'D';
const char POLICIACA = 'P';
const char ROMANCE = 'R';
const char TERROR = 'T';
const int CANTIDAD_DE_GENEROS = 6;
const int PUNTAJE_MINIMO = 0;
const int PUNTAJE_MAXIMO = 100;
const char ERROR_GENERO = 'E';

const int LISTAR_LIBROS = 1;
const int AGREGAR_LIBRO = 2;
const int EDITAR_PUNTAJE = 3;
const int MOSTRAR_LIBRO_FAVORITO = 4;
const int MOSTRAR_LIBROS_CON_MENOR_PUNTAJE = 5;
const int MOSTRAR_GENERO_MAS_LEIDO = 6;
const int MOSTRAR_GENERO_FAVORITO = 7;
const int GUARDAR_Y_SALIR = 8;

const string PATH = "libros.csv";

#endif //EL_ETERNO_DILEMA_DEL_LECTOR_CONSTANTES_H
